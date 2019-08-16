#include "ailib.h"
#include "aidefines.h"
#include <unistd.h>
#include <stdio.h>

#define NORMALIZATION_X 1920
#define NORMALIZATION_Y 1080

static void *TheThread(void *param)
{
	static int s_cnt=0;
	FILE *s_yuv_file_handle=NULL;

	CAiLib::GetInstance().m_bThreadRunning = true;
	while (!CAiLib::GetInstance().m_stop_flag)
	{
		if(s_cnt==10)
		{
			//open yuv file, it's just a demo, don't write too much frames, it' s cause the flash full
			//you can mount to virtual machine, and write yuv data to nfs filesystem
			char name[128] = {0};
			strcpy(name, "/mnt/nfs/sample.yuv");
			s_yuv_file_handle=fopen(name, "wb");
			if (s_yuv_file_handle == NULL)
			{
				printf("open file failed filename=%s \n", name);
				break;
			}
			printf("open file success handle=%#x \n", s_yuv_file_handle);
		}

		AI_VIDEO_FRAME_S *llpVideoFrame=NULL;

		//get yuv data
		if(CAiLib::GetInstance().IF_GetYUVData(0,&llpVideoFrame,200)!=0)
		{
			printf("get yuv data failed\n");
			usleep(40000);
			continue;
		}
		
		s_cnt++;

		if(llpVideoFrame==NULL)
		{
			printf("yuv data error\n");
			usleep(40000);
			continue;
		}

		int w=llpVideoFrame->nWidth;
		int h=llpVideoFrame->nHeight;

		printf("recv data width=%d  height=%d\n",w ,h);

		//we only support yuv 4:2:0, so data size is equal to w*h*3/2
		int nSize = w*h*3/2;

		/*
		if (llpVideoFrame->nPixelFormat < 3 )
		llpVideoFrame->pYUV[0]:  y
		llpVideoFrame->pYUV[1]:  u
		llpVideoFrame->pYUV[2]:  v

		if (llpVideoFrame->nPixelFormat >= 3 )
		llpVideoFrame->pYUV[0]:  yuv
		*/
		if (s_yuv_file_handle)
			fwrite(llpVideoFrame->pYUV[0],nSize,1, s_yuv_file_handle);
		
		//Assemble analyse result structure, 
		//nsd will draw rectangle and osd depend on the result 
		///mnt/mtd/code/fixed/sys.def  externtype should be 0x10000(hardware ai) or 0x20000(software ai) or 0x40000(hardware ai with cache)
		YUVAnalyzeResult analyzeResult;
		memset(&analyzeResult,0,sizeof(YUVAnalyzeResult));
		
		analyzeResult.faceResult[0].resultPosition.u16X = 500; //0-NORMALIZATION_X
		analyzeResult.faceResult[0].resultPosition.u16Y = 280; //0-NORMALIZATION_Y
		analyzeResult.faceResult[0].resultPosition.u16Width = 200; //0-NORMALIZATION_X
		analyzeResult.faceResult[0].resultPosition.u16Height = 120; //0-NORMALIZATION_Y
		analyzeResult.faceResult[0].u32Color = 0x00ff0000; //red
		analyzeResult.faceResult[0].u8NeedPrintOsd = 0; //0£ºnot show osd, 1: show osd
		strcpy(analyzeResult.faceResult[0].szInfo, "Test Osd 111");
		
		analyzeResult.faceResult[1].resultPosition.u16X = 1200; //0-NORMALIZATION_X
		analyzeResult.faceResult[1].resultPosition.u16Y = 500; //0-NORMALIZATION_Y
		analyzeResult.faceResult[1].resultPosition.u16Width = 200; //0-NORMALIZATION_X
		analyzeResult.faceResult[1].resultPosition.u16Height = 200; //0-NORMALIZATION_Y
		analyzeResult.faceResult[1].u32Color = 0x0000ff00; //green
		analyzeResult.faceResult[1].u8NeedPrintOsd = 1;
		strcpy(analyzeResult.faceResult[1].szInfo, "Test Osd 222");
		
		analyzeResult.resultNumber = 2;
		analyzeResult.drawLineFlag = 1;
		analyzeResult.analyzeType  = NSD_AI_FACE;
		analyzeResult.normalizationX = NORMALIZATION_X;
		analyzeResult.normalizationY = NORMALIZATION_Y;
		
		std::map<long, CALLBACK_FUNCTION_WITH_CH>::iterator it = CAiLib::GetInstance().m_callback_list.begin();
		while (it != CAiLib::GetInstance().m_callback_list.end())
		{
			it->second.callback_func(it->second.ch, NSD_AI_FACE, &analyzeResult);
			++it;
		}

		//release yuv data
		CAiLib::GetInstance().IF_ReleaseYUVData(0,llpVideoFrame);

		if(s_yuv_file_handle)
		{
			//we write 100 frames as sample
			fclose(s_yuv_file_handle);
			s_yuv_file_handle=NULL;
		}
		usleep(40000);
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
	if(lpInterface==NULL)
		return NSDERR_FAIL;

	//it's necessary, copy the interfaces implement to this module
	_Copy(lpInterface);
	
	m_stop_flag = false;

	//change ai parameters
	NSD_AI_S ai_cfg;
	ai_cfg.u16AiImageWidth  = 640;
	ai_cfg.u16AiImageHeight = 480;
	ai_cfg.u8FrameAllocType = 0;
	ai_cfg.u8CacheNumber	= 8;
    ai_cfg.u8CacheNumberForVout = 2;
	
	/*
			u8PixelFormat:  1:yuv420£¬2:yuv422(not support) 3:yuv420
			
			if (llpVideoFrame->nPixelFormat < 3 )
			llpVideoFrame->pYUV[0]:  y
			llpVideoFrame->pYUV[1]:  u
			llpVideoFrame->pYUV[2]:  v

			if (llpVideoFrame->nPixelFormat >= 3 )
			llpVideoFrame->pYUV[0]:  yuv

			if nPixelFormat is 3, we will transmit the data pointer from hisilicon to libailib directly
			if nPixelFormat is 1, we will convert the format from nv21 to yuv420
	*/
	ai_cfg.u8PixelFormat = 3;
	IF_SetParam(NSDCFG_AI,&ai_cfg,0,0);

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
