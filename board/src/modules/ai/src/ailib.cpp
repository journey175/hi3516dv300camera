#include "ailib.h"
#include "aidefines.h"
#include <unistd.h>
#include <stdio.h>


#include "sample_comm_ive.h"
#include "sample_nnie.h"
#include "sample_comm_nnie.h"

#define NORMALIZATION_X 300
#define NORMALIZATION_Y 300

static IVE_IMAGE_S stImg[1] = {0};
static SAMPLE_SVP_NNIE_RECT_ARRAY_S rect_result_array = {0};
static HI_FLOAT af32ScoreThr[SAMPLE_SVP_NNIE_MAX_CLASS_NUM] = {0};

static void convert_type_frame_to_image(VIDEO_FRAME_INFO_S * src, IVE_IMAGE_S * dest)
{
	IVE_IMAGE_S * tmp = (IVE_IMAGE_S * )dest;
	
	tmp->u32Width   = src->stVFrame.u32Width;
	tmp->u32Height  = src->stVFrame.u32Height;
	tmp->enType = IVE_IMAGE_TYPE_YUV420SP;
	
	for(int i=0; i<3; i++){
		tmp->au64PhyAddr[i] = src->stVFrame.u64PhyAddr[i];
		tmp->au64VirAddr[i] = src->stVFrame.u64VirAddr[i];
		tmp->au32Stride[i]  = src->stVFrame.u32Stride[i];
	}
}

static HI_S32 convert_check_result(SAMPLE_SVP_NNIE_RECT_ARRAY_S * pstRect, YUVAnalyzeResult *result)
{

	if (0 == pstRect->u32TotalNum)
    {
        return -1;
    }
    result->resultNumber = pstRect->u32TotalNum;
	 for (HI_U32 i = 0, k = 0; i < pstRect->u32ClsNum; ++i)
	 {
		  	for (HI_U32 j = 0; j < pstRect->au32RoiNum[i]; ++j)
			{

				result->faceResult[k].resultPosition.u16X = pstRect->astRect[i][j].astPoint[0].s32X; 
				result->faceResult[k].resultPosition.u16Y = pstRect->astRect[i][j].astPoint[0].s32Y;

				result->faceResult[k].resultPosition.u16Width = \
				pstRect->astRect[i][j].astPoint[2].s32X - pstRect->astRect[i][j].astPoint[0].s32X; 

				result->faceResult[k].resultPosition.u16Height = \
				pstRect->astRect[i][j].astPoint[2].s32Y - pstRect->astRect[i][j].astPoint[0].s32Y; 

				result->faceResult[k].u32Color = 0x0000ff00; //green
				result->faceResult[k].u8NeedPrintOsd = 1; 
				strcpy(result->faceResult[0].szInfo, "face");
				++k;
			}
	 }

	 return HI_SUCCESS;

}

static void *TheThread(void *param)
{
	HI_S32 s32Ret = HI_SUCCESS;
	CAiLib::GetInstance().m_bThreadRunning = true;
	IVE_HANDLE IveHandle;
	IVE_CSC_CTRL_S stCscCtrl = {IVE_CSC_MODE_PIC_BT601_YUV2RGB};
	HI_FLOAT f32PrintResultThresh = 0.8f;
	IVE_IMAGE_S stSrcImage;

	af32ScoreThr[0] = af32ScoreThr[1] = f32PrintResultThresh;

	while (!CAiLib::GetInstance().m_stop_flag)
	{
		AI_VIDEO_FRAME_S *llpVideoFrame=NULL;

		//get yuv data
		if(CAiLib::GetInstance().IF_GetYUVData(0,&llpVideoFrame,200)!=0)
		{
			printf("get yuv data failed\n");
			usleep(40000);
			continue;
		}
		
		if(llpVideoFrame==NULL)
		{
			printf("yuv data error\n");
			usleep(40000);
			continue;
		}

		//int w=llpVideoFrame->nWidth;
		//int h=llpVideoFrame->nHeight;
		//printf("recv data width=%d  height=%d\n",w ,h);
		printf("IF_GetYUVData!\n");
		convert_type_frame_to_image((VIDEO_FRAME_INFO_S *)llpVideoFrame->pInnerUse, &stSrcImage);
		s32Ret=HI_MPI_IVE_CSC(&IveHandle, &stSrcImage,&stImg[0], &stCscCtrl,HI_TRUE);
		if(HI_SUCCESS != s32Ret){
			printf("HI_MPI_IVE_CSC fail,Error(%#x)\n",s32Ret);
			CAiLib::GetInstance().IF_ReleaseYUVData(0,llpVideoFrame);
			continue;
		}
		printf("HI_MPI_IVE_CSC ok!\n");
		s32Ret = SAMPLE_SVP_NNIE_SSD_Check(&stImg[0],&rect_result_array,af32ScoreThr,NORMALIZATION_X,NORMALIZATION_Y,1920,1080);
		if(HI_SUCCESS != s32Ret){
			printf("SAMPLE_SVP_NNIE_SSD_Check fail\n");
			CAiLib::GetInstance().IF_ReleaseYUVData(0,llpVideoFrame);
			continue;
		}
		printf("SAMPLE_SVP_NNIE_SSD_Check ok!\n");
		//nsd will draw rectangle and osd depend on the result 
		///mnt/mtd/code/fixed/sys.def  externtype should be 0x10000(hardware ai) or 0x20000(software ai) or 0x40000(hardware ai with cache)
		
		YUVAnalyzeResult analyzeResult;
		memset(&analyzeResult,0,sizeof(YUVAnalyzeResult));

		analyzeResult.drawLineFlag = 1;
		analyzeResult.analyzeType  = NSD_AI_FACE;
		analyzeResult.normalizationX = 1920;
		analyzeResult.normalizationY = 1080;
		s32Ret = convert_check_result(&rect_result_array,&analyzeResult);
		if(HI_SUCCESS != s32Ret){
			CAiLib::GetInstance().IF_ReleaseYUVData(0,llpVideoFrame);
			continue;
		}
		printf("convert_check_result ok!\n");
		std::map<long, CALLBACK_FUNCTION_WITH_CH>::iterator it = CAiLib::GetInstance().m_callback_list.begin();
		while (it != CAiLib::GetInstance().m_callback_list.end())
		{
			it->second.callback_func(it->second.ch, NSD_AI_FACE, &analyzeResult);
			++it;
		}

		CAiLib::GetInstance().IF_ReleaseYUVData(0,llpVideoFrame);
	}
	
	CAiLib::GetInstance().m_bThreadRunning = false;
	return 0;
}

long CAiLib::m_handle;

CAiLib::CAiLib()
:m_stop_flag(false)
{

}

CAiLib::~CAiLib()
{
	UnInitLib();
}

CAiLib & CAiLib::GetInstance()
{
	static CAiLib s_ailib;
	return s_ailib;
}


int	CAiLib::InitLib(M_INTERFACE * lpInterface)
{
	HI_CHAR *pcModelName = "/mnt/nfs/inst_ssd_face_detect.wk";
	HI_S32 s32Ret;
	if(lpInterface==NULL)
		return NSDERR_FAIL;
	
	//it's necessary, copy the interfaces implement to this module
	_Copy(lpInterface);
	
	m_stop_flag = false;

	//change ai parameters
	NSD_AI_S ai_cfg;
	ai_cfg.u16AiImageWidth  = NORMALIZATION_X;
	ai_cfg.u16AiImageHeight = NORMALIZATION_Y;
	ai_cfg.u8FrameAllocType = 0;
	ai_cfg.u8CacheNumber	= 8;
    ai_cfg.u8CacheNumberForVout = 2;

	ai_cfg.u8PixelFormat = 3;
	IF_SetParam(NSDCFG_AI,&ai_cfg,0,0);

	/*Ssd Load model*/

	if(SAMPLE_SVP_NNIE_SSD_Init(pcModelName) != HI_SUCCESS){
		return NSDERR_FAIL;
	}
	printf("SAMPLE_SVP_NNIE_SSD_Init ok!\n");

	s32Ret = SAMPLE_COMM_IVE_CreateImage(&stImg[0],IVE_IMAGE_TYPE_U8C3_PLANAR,NORMALIZATION_X,NORMALIZATION_Y);
	if(HI_SUCCESS != s32Ret){
		printf("Error(%#x),Create img[0] failed!\n");

		return NSDERR_FAIL;
	}
	printf("SAMPLE_COMM_IVE_CreateImage ok!\n");

	int status = pthread_create(&m_thread_id, NULL, TheThread, (void *)this);
	if (status != 0)
	{
		printf("pthread_create(),failed!\n");
		return status;
	}

	return NSDERR_SUCCESS;
}

void CAiLib::UnInitLib()
{
	m_stop_flag = true;
	int nCount = 0;
	printf("UnInitLib...!\n");
	while(m_bThreadRunning)
	{
		if (nCount > 100)
		{
			printf("AI model assert!!");
			break;
		}
		usleep(30000);
		nCount++;
	}
	pthread_cancel(m_thread_id);

	IVE_MMZ_FREE(stImg[0].au64PhyAddr[0], stImg[0].au64VirAddr[0]);
	SAMPLE_SVP_NNIE_SSD_DeInit();
}

long CAiLib::AddCallBackFunction(int p_ch, ai_analyse_callback p_callbackfunc)
{
	long current_handle = m_handle++;
	CALLBACK_FUNCTION_WITH_CH obj;
	obj.ch = p_ch;
	obj.callback_func = p_callbackfunc;
	m_callback_list.insert(std::make_pair(current_handle, obj));
	return current_handle;
}

void CAiLib::RemoveCallBackFunction(int p_handle)
{
	std::map<long, CALLBACK_FUNCTION_WITH_CH>::iterator it = m_callback_list.find(p_handle);
	if (it != m_callback_list.end())
	{
		m_callback_list.erase(it);
	}
}

//////////////////////////////////////////////////////////
//This interfaces must be implemented
extern "C"
{
int AI_GetCoreVersion()
{
    return CORE_VERSION;
}

int	AI_InitLib(M_INTERFACE * lpInterface)
{
	return CAiLib::GetInstance().InitLib(lpInterface); 
}

int	AI_UnInitLib()
{
	CAiLib::GetInstance().UnInitLib();
	return NSDERR_SUCCESS;
}

long AI_AddAnalyseCallback(unsigned short nCh,ai_analyse_callback lpCallback)
{
	//register callback functions in order to dispatch the analyse result
	return CAiLib::GetInstance().AddCallBackFunction(nCh, lpCallback);
}

int	AI_RemoveAnalyseCallback(unsigned short nCh,long hHandle)
{
	CAiLib::GetInstance().RemoveCallBackFunction(hHandle);
	return NSDERR_SUCCESS; 
}

long AI_GetCapability()
{
	//eg.if you support face detect,return NSD_AI_FACE 
	return NSD_AI_FACE;
}

int	AI_ChangeParam(unsigned short nCh,NSD_CONFIG_TYPE_E nParamType,void * lpParam)
{
	switch(nParamType)
	{
	case NSDCFG_AI_FACE:
		{
			//todo ...
		}
		break;
	default:
		return NSDERR_INVALID_PARAM;
		break;
	}
	return NSDERR_SUCCESS;
}

long AI_GetCompany()
{
	return NSD_COMPANY_UNKNOWN;
}

void AI_Reset()
{
}

int	AI_OnSDCardStatusChange(unsigned int nStatus)
{
	//nStatus will be NSD_SDCARD_STATUS_FORMAT_BEGIN or NSD_SDCARD_STATUS_FORMAT_END
	return 0;
}
}
