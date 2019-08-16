
#ifndef __M_INTERFACE_H_
#define __M_INTERFACE_H_

#include "privydef.h"
extern "C++" {
	#include "base/hautoptr.h"
}


typedef HDSOFT::CHAutoPtr<PictureData> SPictureData;

typedef void (*OnSerialData)(unsigned short nCh,char * lpData,unsigned long nDataLen);
typedef int	(*record_stream_callback)(const char * framebuf,int framelen,short rectype,double percent,void * pContext);
typedef int (*record_playend_callback)(void * pContext);
typedef int (*ai_analyse_callback)(unsigned short nCh,int analyse_type,YUVAnalyzeResult * result);
typedef int (*video_yuvdata_callback)(unsigned short p_ch, AI_VIDEO_FRAME_S *p_yuv);
typedef int (*ai_yuvresult_callback)(unsigned short p_ch, AI_VIDEO_FRAME_S *p_yuv, YUVAnalyzeResult *result);
typedef int (*get_ptz_position_callback)(unsigned short p_ch, int p_pan, int p_tilt, int p_zoom, int reserve1, int reserve2);
typedef int (*update_percent_callback)(int nPercent,void * pContext1,void * pContext2);
typedef int (*local_msg_callback)(LPNSD_LOCAL_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen,void * pContext);
typedef int (*module_msg_callback)(LPNSD_MODULE_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen,const void *& pResultContent,unsigned int & nResultLen,void * pContext);

static void N_WriteLog(int nModuleType,int nLogLevel,unsigned long nEventType,const char * szFormat,...) {}
static void N_ModPluse(int nModuleType) {}

static int N_GetParam(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }
static int N_SetParam(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }
static int N_GetDefaultParam(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }
static int N_VerifyParam(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned short nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }
static int N_OnParamChanged(NSD_CONFIG_TYPE_E nParamType,void * lpParam,int nParamLength,unsigned long nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }
static int N_UpdateNetworkInfo(int nWorkType,unsigned long nIp, unsigned long nSubMask, unsigned long nGateWay,unsigned long nDns1, unsigned long nDns2) { return NSDERR_NOIMPLEMENT; }
static int N_UpdatePPPOEInfo(unsigned long * lpPppoeAddr,unsigned char * lpStatus,unsigned long * lpPppoeTimes) { return NSDERR_NOIMPLEMENT; }
static int N_UpdateUpnpInfo(unsigned short * lpHttpPort,unsigned short * lpDataPort) { return NSDERR_NOIMPLEMENT; }
static int N_ProcCmd(NSD_CMD_TYPE_E nCmdType,void * lpData,unsigned long nDataLen,unsigned long nCh,unsigned long nRsvd) { return NSDERR_NOIMPLEMENT; }

//cache
static int N_WriteVideoFrameToCache(unsigned short nCh,int nStreamType,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadVideoFrameFromCache(unsigned short nCh,int nStreamType,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long & nRealFrameNo) { return NSDERR_NOIMPLEMENT; }
static int N_WriteAudioFrameToCache(unsigned short nCh,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadAudioFrameFromCache(unsigned short nCh,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long &nRealFrameNo) { return NSDERR_NOIMPLEMENT; }
static int N_WriteTalkFrameToCache(LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static long N_ReadTalkFrameFromCache(unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long & nRealFrameNo) { return NSDERR_NOIMPLEMENT; }
static int N_WriteMDFrameToCache(unsigned short nCh,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static long N_ReadMDFrameFromCache(unsigned short nCh,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedTickCount,unsigned long & nRealTickCount) { return NSDERR_NOIMPLEMENT; }
static void	N_ClearCache(int nCacheType,unsigned short nCh,int nStreamType) {}

//uart
static long	N_AddUartCB(unsigned short nCh,OnSerialData lpCallback) { return 0; }
static int N_RemoveUartCB(unsigned short nCh,long hHandle) { return NSDERR_NOIMPLEMENT; }
static long N_WriteUartData(unsigned short nCh,const char * lpWriteBuf,unsigned long nWriteBufSize) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadUartData(unsigned short nCh,char * lpReadBuf,unsigned long nReadBufSize,int nTimeout) { return NSDERR_NOIMPLEMENT; }
static void	N_UartWaitForSafeWriteTime(unsigned short nCh,unsigned long nMilliSecond) {}

//ptz
static long	N_FindPTZCmd(unsigned short nCh,int nCmd,char * lpReadBuf,unsigned long nReadBufSize,int nTimeout) { return NSDERR_NOIMPLEMENT; }
static long	N_AddGetPTZPosCallback(unsigned short nCh, get_ptz_position_callback pGetPTZCallback) { return 0; }
static int	N_RemoveGetPTZPosCallback(unsigned short nCh,long hHandle) { return NSDERR_NOIMPLEMENT; }

//va
static int N_StartTalk() { return NSDERR_NOIMPLEMENT; }
static int N_StopTalk() { return NSDERR_NOIMPLEMENT; }
static int N_PreviewStreamAddRef(unsigned short nCh,int nStreamType) { return NSDERR_NOIMPLEMENT; }
static int N_PreviewStreamRelease(unsigned short nCh,int nStreamType) { return NSDERR_NOIMPLEMENT; }
static long	N_GetPreviewCount(unsigned short nCh,int nStreamType) { return NSDERR_NOIMPLEMENT; }
static int N_GetVideoMediaInfo(unsigned short nCh,int nStreamType,unsigned char * lpSps,unsigned long & nSpsLen,unsigned char * lpPps,unsigned long & nPpsLen) { return NSDERR_NOIMPLEMENT; }
static int N_RtspReset(unsigned short nCh,int nStreamType,int nAVFlag) { return NSDERR_NOIMPLEMENT; }
static int N_VASync(unsigned short nCh,int nSyncType,unsigned long nSyncParam) { return NSDERR_NOIMPLEMENT; }
static int N_Scale(AI_VIDEO_FRAME_S *p_Frame, AI_VIDEO_FRAME_S *p_OutFrame) { return NSDERR_NOIMPLEMENT; }
static int N_GetZoomPosition(unsigned short nCh) { return 0; }

//record
static int N_StartRecord(int nCh,int nStreamType,int nRecTime,int nRecPreTime) { return NSDERR_NOIMPLEMENT; }
static int N_StopRecord(int nCh) { return NSDERR_NOIMPLEMENT; }
static int N_StartFtpRecord(int nCh,int nStreamType,int nRecTime,int nRecPreTime) { return NSDERR_NOIMPLEMENT; }
static int N_StopFtpRecord(int nCh) { return NSDERR_NOIMPLEMENT; }
static void * N_OpenRecordService() { return NULL; }
static void	N_CloseRecordService(void * hRecService) {}
static int N_QueryRecord(void * hRecService,LPNSD_RECORD_FILE_S lpSearch) { return NSDERR_NOIMPLEMENT; }
static int N_GetRecordInfo(void * hRecService,int nIndex,LPNSD_RECORD_FILE_S lpSearchRet,int & nCount) { return NSDERR_NOIMPLEMENT; }
static int N_OpenReplay(void * hRecService,LPNSD_RECORD_FILE_S lpPlay) { return NSDERR_NOIMPLEMENT; }
static int N_ReplayCtrl(void * hRecService,NSD_REPLAY_CTRL_E nCtrlType,long nParam1,unsigned long nParam2) { return NSDERR_NOIMPLEMENT; }
static int N_CloseReplay(void * hRecService) { return NSDERR_NOIMPLEMENT; }
static int N_RecordSavePicture(unsigned short nCh,unsigned char * lpPicData,unsigned long nDataLen) { return NSDERR_NOIMPLEMENT; }
static int N_SetRecordCallback(void * hRecService,record_stream_callback pStreamCallback,record_playend_callback pEndCallback,void * pContext) { return NSDERR_NOIMPLEMENT; }
static int N_GetRecordMediaInfo(void * hRecService,LPNSD_RECORD_FILE_S lpPlay,NSD_AUDIO_INFO_S & audioinfo,NSD_VIDEO_INFO_S & videoinfo,unsigned char * lpSps,unsigned long & nSpsLen,unsigned char * lpPps,unsigned long & nPpsLen) { return NSDERR_NOIMPLEMENT; }
static int N_GetRecordRange(unsigned short nCh,unsigned short nStreamId,NSD_TIME_S & timeBegin,NSD_TIME_S & timeEnd) { return NSDERR_NOIMPLEMENT; }

//snap
static int N_WritePictureFrame(unsigned short nCh,LPNSD_SNAP_HEAD_S head,const unsigned char * lpFrameBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadPictureFrameByFrom(unsigned short nCh,unsigned long nFromType,SPictureData &lpFrameBuf,unsigned long nNeedTick) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadPictureFrameBySave(unsigned short nCh,unsigned long nSaveType,SPictureData &lpFrameBuf,unsigned long nNeedTick) { return NSDERR_NOIMPLEMENT; }
static long	N_ReadPictureFrameByFromAndSave(unsigned short nCh,unsigned long nFromType,unsigned long nSaveType,SPictureData &lpFrameBuf,unsigned long nNeedTick) { return NSDERR_NOIMPLEMENT; }
static int N_Shoot(unsigned short nCh,NSD_ACTION_FROM_E nFrom,unsigned long nNum, unsigned long nInterval,unsigned long nSaveType,unsigned long nPreSecond,unsigned long nPresistMillisec) { return NSDERR_NOIMPLEMENT; }
static int N_ResetShoot(unsigned short nCh,NSD_ACTION_FROM_E nFrom) { return NSDERR_NOIMPLEMENT; }

//AI
static int  N_GetYUVData(unsigned short nCh,AI_VIDEO_FRAME_S ** llpVideoFrame,unsigned long nTimeoutMilliSec) { return NSDERR_NOIMPLEMENT; }
static int  N_SendYUVToVenc(unsigned short nCh,AI_VIDEO_FRAME_S * lpVideoFrame) { return NSDERR_NOIMPLEMENT; }
static int  N_ReleaseYUVData(unsigned short nCh,AI_VIDEO_FRAME_S * lpVideoFrame) { return NSDERR_NOIMPLEMENT; }
static long	N_AddAIAnalyseCallback(unsigned short nCh,ai_analyse_callback lpCallback) { return 0; }
static int  N_RemoveAIAnalyseCallback(unsigned short nCh,long hHandle) { return NSDERR_NOIMPLEMENT; }
static long	N_AddAIYuvResultCallback(unsigned short nCh,ai_yuvresult_callback lpCallback) { return 0; }
static int  N_RemoveAIYuvResultCallback(unsigned short nCh,long hHandle) { return NSDERR_NOIMPLEMENT; }
static long	N_AddYuvStreamCallback(unsigned short nCh, video_yuvdata_callback lpCallback) { return 0; }
static int	N_RemoveYuvStreamCallback(unsigned short nCh,long hHandle) { return NSDERR_NOIMPLEMENT; }
static int  N_EncodeJpg(int nIndex, AI_VIDEO_FRAME_S *lpVideoFrame, int nQuality, char *&lpJpg, int &nJpgLength) { return NSDERR_NOIMPLEMENT; }

//other
static void	N_Alarm(NSD_ALARM_TYPE_E nAlarmType,bool bAlarm,unsigned short nCh) {}
static void	N_OnDayNightSwitch(unsigned short nCh,int nDNStatus) {}
static long	N_GetIOStatus(int nIOType,int nParam) { return 0; }
static int N_IOCtl(int nIOType,int nValue,int nChn,int nParam) { return NSDERR_NOIMPLEMENT; }
static long	N_GetCapabilty(NSD_CAPABILITY_TYPE_E nCapabiltyType,void * lpRecvBuf,unsigned long nBufLen,unsigned short nCh,unsigned int nAppend) { return NSDERR_NOIMPLEMENT; }
static int N_ValidUserPwd(const char * lpUser,const char * lpPwd,int & nMisc) { return NSDERR_NOIMPLEMENT; }
static int N_OnHttpData(const char * szBuf,char * szOutBuf,int nOutBufSize) { return NSDERR_NOIMPLEMENT; }
static int N_OnCgiData(const char * szBuf,char * szOutBuf,unsigned long nOutBufSize,unsigned long &nRealOutLen) { return NSDERR_NOIMPLEMENT; }
static int N_OnNetworkReady(int nWorkType)	{ return NSDERR_NOIMPLEMENT; }
static int N_GetSDCardInfo(unsigned int & nTotalSize,unsigned int & nFreeSize) { return NSDERR_NOIMPLEMENT; }
static int N_Test(NSD_TEST_TYPE_E nTestType,int param1,void * param2,void * param3) { return NSDERR_NOIMPLEMENT; }
static int N_GetBinData(unsigned char * lpBinData,unsigned long & nDataLen,int rsvd) { return NSDERR_NOIMPLEMENT; }
static int N_IsSDCardExist() { return NSDERR_NOIMPLEMENT; }
static int N_LoadUserConfigure(unsigned short nID) { return NSDERR_NOIMPLEMENT; }
static int N_UpdateSys(const char * lpUpdateContent,unsigned long nContentLen,bool bAllowFreeBuffer,bool & bFreed,bool & bNeedReboot,update_percent_callback lpCallback,void * lpContext1,void * lpContext2) { return NSDERR_NOIMPLEMENT; }
static int N_UpdateChildSys(unsigned short nTarget,unsigned short nTargetCh,const char* lpUpdateBuf,unsigned long nBufSize) { return NSDERR_NOIMPLEMENT; }
static int N_GetPlatformTypeList() { return 0; }
static int N_SendLocalMsg(LPNSD_LOCAL_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen) { return NSDERR_NOIMPLEMENT; }
static long	N_AddLocalMsgCallback(local_msg_callback lpCallback,void * pContext) { return NSDERR_NOIMPLEMENT; }
static int N_RemoveLocalMsgCallback(long hHandle) { return NSDERR_NOIMPLEMENT; }
static int N_SendModuleMsg(LPNSD_MODULE_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen,const void *& pResultContent,unsigned int & nResultLen) { return NSDERR_NOIMPLEMENT; }
static int N_SetModuleMsgCallback(unsigned int nModuleType,module_msg_callback lpCallback,void * pContext) { return NSDERR_NOIMPLEMENT; }
static int N_MmzAlloc(unsigned long long *pu32PhyAddr, void **pVirtAddr, unsigned int nLen){ return NSDERR_NOIMPLEMENT; }
static int N_MmzFree(unsigned long long pu32PhyAddr, void *pVirtAddr){ return NSDERR_NOIMPLEMENT; }

typedef struct _M_INTERFACE
{
	void			(*IF_WriteLog)(int nModuleType,int nLogLevel,unsigned long nEventType,const char * szFormat,...);
	void			(*IF_ModPluse)(int nModuleType);

	int				(*IF_GetParam)(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd);
	int				(*IF_SetParam)(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd);
	int				(*IF_GetDefaultParam)(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned long nCh,unsigned long nRsvd);
	int				(*IF_VerifyParam)(NSD_CONFIG_TYPE_E nParamType,void * lpParam,unsigned short nCh,unsigned long nRsvd);
	int				(*IF_OnParamChanged)(NSD_CONFIG_TYPE_E nParamType,void * lpParam,int nParamLength,unsigned long nCh,unsigned long nRsvd);
	int				(*IF_UpdateNetworkInfo)(int nWorkType,unsigned long nIp, unsigned long nSubMask, unsigned long nGateWay,unsigned long nDns1, unsigned long nDns2);
	int				(*IF_UpdatePPPOEInfo)(unsigned long * lpPppoeAddr,unsigned char * lpStatus,unsigned long * lpPppoeTimes);
	int				(*IF_UpdateUpnpInfo)(unsigned short * lpHttpPort,unsigned short * lpDataPort);
	int				(*IF_ProcCmd)(NSD_CMD_TYPE_E nCmdType,void * lpData,unsigned long nDataLen,unsigned long nCh,unsigned long nRsvd);
	
	//cache
	int				(*IF_WriteVideoFrameToCache)(unsigned short nCh,int nStreamType,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize);
	long			(*IF_ReadVideoFrameFromCache)(unsigned short nCh,int nStreamType,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long & nRealFrameNo);
	int				(*IF_WriteAudioFrameToCache)(unsigned short nCh,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize);
	long			(*IF_ReadAudioFrameFromCache)(unsigned short nCh,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long &nRealFrameNo);
	int				(*IF_WriteTalkFrameToCache)(LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize);
	long			(*IF_ReadTalkFrameFromCache)(unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedFrameNo,unsigned long & nRealFrameNo);
	int				(*IF_WriteMDFrameToCache)(unsigned short nCh,LPNSD_FRAME_HEAD_S lpFrameHead,const unsigned char * lpFrameBuf,unsigned long nBufSize);
	long			(*IF_ReadMDFrameFromCache)(unsigned short nCh,unsigned char * lpFrameBuf,unsigned long & nBufSize,int nFirstFlag,unsigned long nNeedTickCount,unsigned long & nRealTickCount);
	void			(*IF_ClearCache)(int nCacheType,unsigned short nCh,int nStreamType);
	
	//uart
	long			(*IF_AddUartCB)(unsigned short nCh,OnSerialData lpCallback);
	int				(*IF_RemoveUartCB)(unsigned short nCh,long hHandle);
	long			(*IF_WriteUartData)(unsigned short nCh,const char * lpWriteBuf,unsigned long nWriteBufSize);
	long			(*IF_ReadUartData)(unsigned short nCh,char * lpReadBuf,unsigned long nReadBufSize,int nTimeout);
	void			(*IF_UartWaitForSafeWriteTime)(unsigned short nCh,unsigned long nMilliSecond);

	//ptz
	long			(*IF_FindPTZCmd)(unsigned short nCh,int nCmd,char * lpReadBuf,unsigned long nReadBufSize,int nTimeout);
	long			(*IF_AddGetPTZPosCallback)(unsigned short nCh, get_ptz_position_callback pGetPTZCallback);
	int				(*IF_RemoveGetPTZPosCallback)(unsigned short nCh,long hHandle);

	//va
	int				(*IF_StartTalk)();
	int				(*IF_StopTalk)();
	int				(*IF_PreviewStreamAddRef)(unsigned short nCh,int nStreamType);
	int				(*IF_PreviewStreamRelease)(unsigned short nCh,int nStreamType);
	long			(*IF_GetPreviewCount)(unsigned short nCh,int nStreamType);
	int				(*IF_GetVideoMediaInfo)(unsigned short nCh,int nStreamType,unsigned char * lpSps,unsigned long & nSpsLen,unsigned char * lpPps,unsigned long & nPpsLen);
	int				(*IF_RtspReset)(unsigned short nCh,int nStreamType,int nAVFlag);
	int				(*IF_VASync)(unsigned short nCh,int nSyncType,unsigned long nSyncParam);
	int				(*IF_Scale)(AI_VIDEO_FRAME_S *p_Frame, AI_VIDEO_FRAME_S *p_OutFrame);
	int				(*IF_GetZoomPosition)(unsigned short nCh);

	//record
	int				(*IF_StartRecord)(int nCh,int nStreamType,int nRecTime,int nRecPreTime);
	int				(*IF_StopRecord)(int nCh);
	int				(*IF_StartFtpRecord)(int nCh,int nStreamType,int nRecTime,int nRecPreTime);
	int				(*IF_StopFtpRecord)(int nCh);
	void *			(*IF_OpenRecordService)();
	void			(*IF_CloseRecordService)(void * hRecService);
	int				(*IF_QueryRecord)(void * hRecService,LPNSD_RECORD_FILE_S lpSearch);
	int				(*IF_GetRecordInfo)(void * hRecService,int nIndex,LPNSD_RECORD_FILE_S lpSearchRet,int & nCount);
	int				(*IF_OpenReplay)(void * hRecService,LPNSD_RECORD_FILE_S lpPlay);
	int				(*IF_ReplayCtrl)(void * hRecService,NSD_REPLAY_CTRL_E nCtrlType,long nParam1,unsigned long nParam2);
	int				(*IF_CloseReplay)(void * hRecService);
	int				(*IF_RecordSavePicture)(unsigned short nCh,unsigned char * lpPicData,unsigned long nDataLen);
	int				(*IF_SetRecordCallback)(void * hRecService,record_stream_callback pStreamCallback,record_playend_callback pEndCallback,void * pContext);
	int				(*IF_GetRecordMediaInfo)(void * hRecService,LPNSD_RECORD_FILE_S lpPlay,NSD_AUDIO_INFO_S & audioinfo,NSD_VIDEO_INFO_S & videoinfo,unsigned char * lpSps,unsigned long & nSpsLen,unsigned char * lpPps,unsigned long & nPpsLen);
	int				(*IF_GetRecordRange)(unsigned short nCh,unsigned short nStreamId,NSD_TIME_S & timeBegin,NSD_TIME_S & timeEnd);
	
	//snap
	int				(*IF_WritePictureFrame)(unsigned short nCh,LPNSD_SNAP_HEAD_S head,const unsigned char * lpFrameBuf,unsigned long nBufSize);
	long			(*IF_ReadPictureFrameByFrom)(unsigned short nCh,unsigned long nFromType,SPictureData &lpFrameBuf,unsigned long nNeedTick);
	long			(*IF_ReadPictureFrameBySave)(unsigned short nCh,unsigned long nSaveType,SPictureData &lpFrameBuf,unsigned long nNeedTick);
	long			(*IF_ReadPictureFrameByFromAndSave)(unsigned short nCh,unsigned long nFromType,unsigned long nSaveType,SPictureData &lpFrameBuf,unsigned long nNeedTick);
	int				(*IF_Shoot)(unsigned short nCh,NSD_ACTION_FROM_E nFrom,unsigned long nNum, unsigned long nInterval,unsigned long nSaveType,unsigned long nPreSecond,unsigned long nPresistMillisec);
	int				(*IF_ResetShoot)(unsigned short nCh,NSD_ACTION_FROM_E nFrom);

	//AI
	int				(*IF_GetYUVData)(unsigned short nCh,AI_VIDEO_FRAME_S ** llpVideoFrame,unsigned long nTimeoutMilliSec);
	int				(*IF_SendYUVToVenc)(unsigned short nCh,AI_VIDEO_FRAME_S * lpVideoFrame);
	int				(*IF_ReleaseYUVData)(unsigned short nCh,AI_VIDEO_FRAME_S * lpVideoFrame);
	long			(*IF_AddAIAnalyseCallback)(unsigned short nCh,ai_analyse_callback lpCallback);
	int				(*IF_RemoveAIAnalyseCallback)(unsigned short nCh,long hHandle);
	long			(*IF_AddAIYuvResultCallback)(unsigned short nCh,ai_yuvresult_callback lpCallback);
	int				(*IF_RemoveAIYuvResultCallback)(unsigned short nCh,long hHandle);
	
	//other
	void			(*IF_Alarm)(NSD_ALARM_TYPE_E nAlarmType,bool bAlarm,unsigned short nCh);
	void			(*IF_OnDayNightSwitch)(unsigned short nCh,int nDNStatus);
	long			(*IF_GetIOStatus)(int nIOType,int nParam);
	int				(*IF_IOCtl)(int nIOType,int nValue,int nChn,int nParam);
	long			(*IF_GetCapabilty)(NSD_CAPABILITY_TYPE_E nCapabiltyType,void * lpRecvBuf,unsigned long nBufLen,unsigned short nCh,unsigned int nAppend);
	int				(*IF_ValidUserPwd)(const char * lpUser,const char * lpPwd,int & nMisc);
	int				(*IF_OnHttpData)(const char * szBuf,char * szOutBuf,int nOutBufSize);
	int				(*IF_OnCgiData)(const char * szBuf,char * szOutBuf,unsigned long nOutBufSize,unsigned long &nRealOutLen);
	int				(*IF_OnNetworkReady)(int nWorkType);
	int				(*IF_GetSDCardInfo)(unsigned int & nTotalSize,unsigned int & nFreeSize);
	int				(*IF_Test)(NSD_TEST_TYPE_E nTestType,int param1,void * param2,void * param3);
	int				(*IF_GetBinData)(unsigned char * lpBinData,unsigned long & nDataLen,int rsvd);
	int				(*IF_IsSDCardExist)();

	int				(*IF_LoadUserConfigure)(unsigned short nID);
	int				(*IF_UpdateSys)(const char * lpUpdateContent,unsigned long nContentLen,bool bAllowFreeBuffer,bool & bFreed,bool & bNeedReboot,update_percent_callback lpCallback,void * lpContext1,void * lpContext2);
	int				(*IF_UpdateChildSys)(unsigned short nTarget,unsigned short nTargetCh,const char* lpUpdateBuf,unsigned long nBufSize);

    long			(*IF_AddYuvStreamCallback)(unsigned short nCh, video_yuvdata_callback lpCallback);
    int				(*IF_RemoveYuvStreamCallback)(unsigned short nCh,long hHandle);

    int             (*IF_GetPlatformTypeList)();
	int				(*IF_SendLocalMsg)(LPNSD_LOCAL_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen);
	long			(*IF_AddLocalMsgCallback)(local_msg_callback lpCallback,void * pContext);
	int				(*IF_RemoveLocalMsgCallback)(long hHandle);
	int				(*IF_SendModuleMsg)(LPNSD_MODULE_MSG_HEAD_S lpMsgHead,const char * lpMsg,unsigned int nMsgLen,const void *& pResultContent,unsigned int & nResultLen);
	int				(*IF_SetModuleMsgCallback)(unsigned int nModuleType,module_msg_callback lpCallback,void * pContext);

    int             (*IF_EncodeJpg)(int nIndex, AI_VIDEO_FRAME_S *lpVideoFrame, int nQuality, char *&lpJpg, int &nJpgLength);
    int             (*IF_MmzAlloc)(unsigned long long *pu32PhyAddr, void **pVirtAddr, unsigned int nLen);
    int             (*IF_MmzFree)(unsigned long long pu32PhyAddr, void *pVirtAddr);

	void			*rsvd[2];//Ô¤Áô
	_M_INTERFACE()
	{
		IF_WriteLog=N_WriteLog;
		IF_ModPluse=N_ModPluse;
		IF_GetParam=N_GetParam;
		IF_SetParam=N_SetParam;
		IF_GetDefaultParam=N_GetDefaultParam;
		IF_VerifyParam=N_VerifyParam;
		IF_OnParamChanged=N_OnParamChanged;
		IF_UpdateNetworkInfo=N_UpdateNetworkInfo;
		IF_UpdatePPPOEInfo=N_UpdatePPPOEInfo;
		IF_UpdateUpnpInfo=N_UpdateUpnpInfo;
		IF_ProcCmd=N_ProcCmd;

		IF_WriteVideoFrameToCache=N_WriteVideoFrameToCache;
		IF_ReadVideoFrameFromCache=N_ReadVideoFrameFromCache;
		IF_WriteAudioFrameToCache=N_WriteAudioFrameToCache;
		IF_ReadAudioFrameFromCache=N_ReadAudioFrameFromCache;
		IF_WriteTalkFrameToCache=N_WriteTalkFrameToCache;
		IF_ReadTalkFrameFromCache=N_ReadTalkFrameFromCache;
		IF_WriteMDFrameToCache=N_WriteMDFrameToCache;
		IF_ReadMDFrameFromCache=N_ReadMDFrameFromCache;
		IF_ClearCache=N_ClearCache;

		IF_AddUartCB=N_AddUartCB;
		IF_RemoveUartCB=N_RemoveUartCB;
		IF_WriteUartData=N_WriteUartData;
		IF_ReadUartData=N_ReadUartData;
		IF_UartWaitForSafeWriteTime=N_UartWaitForSafeWriteTime;

		IF_FindPTZCmd=N_FindPTZCmd;
		IF_AddGetPTZPosCallback=N_AddGetPTZPosCallback;
		IF_RemoveGetPTZPosCallback=N_RemoveGetPTZPosCallback;

		IF_StartTalk=N_StartTalk;
		IF_StopTalk=N_StopTalk;
		IF_PreviewStreamAddRef=N_PreviewStreamAddRef;
		IF_PreviewStreamRelease=N_PreviewStreamRelease;
		IF_GetPreviewCount=N_GetPreviewCount;
		IF_GetVideoMediaInfo=N_GetVideoMediaInfo;
		IF_RtspReset=N_RtspReset;
		IF_VASync=N_VASync;
		IF_Scale=N_Scale;
		IF_GetZoomPosition=N_GetZoomPosition;
	
		IF_WritePictureFrame=N_WritePictureFrame;
		IF_ReadPictureFrameByFrom=N_ReadPictureFrameByFrom;
		IF_ReadPictureFrameBySave=N_ReadPictureFrameBySave;
		IF_ReadPictureFrameByFromAndSave=N_ReadPictureFrameByFromAndSave;
		IF_Shoot=N_Shoot;
		IF_ResetShoot=N_ResetShoot;

		IF_GetYUVData=N_GetYUVData;
		IF_SendYUVToVenc=N_SendYUVToVenc;
		IF_ReleaseYUVData=N_ReleaseYUVData;
		IF_AddAIAnalyseCallback=N_AddAIAnalyseCallback;
		IF_RemoveAIAnalyseCallback=N_RemoveAIAnalyseCallback;
		IF_AddAIYuvResultCallback=N_AddAIYuvResultCallback;
		IF_RemoveAIYuvResultCallback=N_RemoveAIYuvResultCallback;
        IF_EncodeJpg=N_EncodeJpg;

		IF_Alarm=N_Alarm;
		IF_OnDayNightSwitch=N_OnDayNightSwitch;
		IF_GetIOStatus=N_GetIOStatus;
		IF_IOCtl=N_IOCtl;
		IF_GetCapabilty=N_GetCapabilty;
		IF_ValidUserPwd=N_ValidUserPwd;
		IF_OnHttpData=N_OnHttpData;
		IF_OnCgiData=N_OnCgiData;
		IF_OnNetworkReady=N_OnNetworkReady;
		IF_GetSDCardInfo=N_GetSDCardInfo;
		IF_Test=N_Test;
		IF_GetBinData=N_GetBinData;
		IF_IsSDCardExist=N_IsSDCardExist;
		IF_LoadUserConfigure=N_LoadUserConfigure;
		IF_UpdateSys=N_UpdateSys;
		IF_UpdateChildSys=N_UpdateChildSys;

		IF_StartRecord=N_StartRecord;
		IF_StopRecord=N_StopRecord;
		IF_StartFtpRecord=N_StartFtpRecord;
		IF_StopFtpRecord=N_StopFtpRecord;
		IF_OpenRecordService=N_OpenRecordService;
		IF_CloseRecordService=N_CloseRecordService;
		IF_QueryRecord=N_QueryRecord;
		IF_GetRecordInfo=N_GetRecordInfo;
		IF_OpenReplay=N_OpenReplay;
		IF_ReplayCtrl=N_ReplayCtrl;
		IF_CloseReplay=N_CloseReplay;
		IF_RecordSavePicture=N_RecordSavePicture;
		IF_SetRecordCallback=N_SetRecordCallback;
		IF_GetRecordMediaInfo=N_GetRecordMediaInfo;
		IF_GetRecordRange=N_GetRecordRange;

        IF_AddYuvStreamCallback=N_AddYuvStreamCallback;
        IF_RemoveYuvStreamCallback=N_RemoveYuvStreamCallback;
        IF_GetPlatformTypeList=N_GetPlatformTypeList;
		IF_SendLocalMsg=N_SendLocalMsg;
		IF_AddLocalMsgCallback=N_AddLocalMsgCallback;
		IF_RemoveLocalMsgCallback=N_RemoveLocalMsgCallback;
		IF_SendModuleMsg=N_SendModuleMsg;
		IF_SetModuleMsgCallback=N_SetModuleMsgCallback;

        IF_MmzAlloc=N_MmzAlloc;
        IF_MmzFree=N_MmzFree;
	}

	void _Copy(_M_INTERFACE * lpInterface){
		IF_WriteLog=lpInterface->IF_WriteLog;
		IF_ModPluse=lpInterface->IF_ModPluse;
		IF_GetParam=lpInterface->IF_GetParam;
		IF_SetParam=lpInterface->IF_SetParam;
		IF_GetDefaultParam=lpInterface->IF_GetDefaultParam;
		IF_VerifyParam=lpInterface->IF_VerifyParam;
		IF_OnParamChanged=lpInterface->IF_OnParamChanged;
		IF_UpdateNetworkInfo=lpInterface->IF_UpdateNetworkInfo;
		IF_UpdatePPPOEInfo=lpInterface->IF_UpdatePPPOEInfo;
		IF_UpdateUpnpInfo=lpInterface->IF_UpdateUpnpInfo;
		IF_ProcCmd=lpInterface->IF_ProcCmd;
	
		IF_WriteVideoFrameToCache=lpInterface->IF_WriteVideoFrameToCache;
		IF_ReadVideoFrameFromCache=lpInterface->IF_ReadVideoFrameFromCache;
		IF_WriteAudioFrameToCache=lpInterface->IF_WriteAudioFrameToCache;
		IF_ReadAudioFrameFromCache=lpInterface->IF_ReadAudioFrameFromCache;
		IF_WriteTalkFrameToCache=lpInterface->IF_WriteTalkFrameToCache;
		IF_ReadTalkFrameFromCache=lpInterface->IF_ReadTalkFrameFromCache;
		IF_WriteMDFrameToCache=lpInterface->IF_WriteMDFrameToCache;
		IF_ReadMDFrameFromCache=lpInterface->IF_ReadMDFrameFromCache;
		IF_ClearCache=lpInterface->IF_ClearCache;

		IF_AddUartCB=lpInterface->IF_AddUartCB;
		IF_RemoveUartCB=lpInterface->IF_RemoveUartCB;
		IF_WriteUartData=lpInterface->IF_WriteUartData;
		IF_ReadUartData=lpInterface->IF_ReadUartData;
		IF_UartWaitForSafeWriteTime=lpInterface->IF_UartWaitForSafeWriteTime;

		IF_FindPTZCmd=lpInterface->IF_FindPTZCmd;
		IF_AddGetPTZPosCallback=lpInterface->IF_AddGetPTZPosCallback;
		IF_RemoveGetPTZPosCallback=lpInterface->IF_RemoveGetPTZPosCallback;

		IF_StartTalk=lpInterface->IF_StartTalk;
		IF_StopTalk=lpInterface->IF_StopTalk;
		IF_PreviewStreamAddRef=lpInterface->IF_PreviewStreamAddRef;
		IF_PreviewStreamRelease=lpInterface->IF_PreviewStreamRelease;
		IF_GetPreviewCount=lpInterface->IF_GetPreviewCount;
		IF_GetVideoMediaInfo=lpInterface->IF_GetVideoMediaInfo;
		IF_RtspReset=lpInterface->IF_RtspReset;
		IF_VASync=lpInterface->IF_VASync;
		IF_Scale=lpInterface->IF_Scale;
		IF_GetZoomPosition=lpInterface->IF_GetZoomPosition;

		IF_WritePictureFrame=lpInterface->IF_WritePictureFrame;
		IF_ReadPictureFrameByFrom=lpInterface->IF_ReadPictureFrameByFrom;
		IF_ReadPictureFrameBySave=lpInterface->IF_ReadPictureFrameBySave;
		IF_ReadPictureFrameByFromAndSave=lpInterface->IF_ReadPictureFrameByFromAndSave;
		IF_Shoot=lpInterface->IF_Shoot;
		IF_ResetShoot=lpInterface->IF_ResetShoot;

		IF_GetYUVData=lpInterface->IF_GetYUVData;
		IF_SendYUVToVenc=lpInterface->IF_SendYUVToVenc;
		IF_ReleaseYUVData=lpInterface->IF_ReleaseYUVData;
		IF_AddAIAnalyseCallback=lpInterface->IF_AddAIAnalyseCallback;
		IF_RemoveAIAnalyseCallback=lpInterface->IF_RemoveAIAnalyseCallback;
		IF_AddAIYuvResultCallback=lpInterface->IF_AddAIYuvResultCallback;
		IF_RemoveAIYuvResultCallback=lpInterface->IF_RemoveAIYuvResultCallback;
        IF_EncodeJpg=lpInterface->IF_EncodeJpg;

		IF_Alarm=lpInterface->IF_Alarm;
		IF_OnDayNightSwitch=lpInterface->IF_OnDayNightSwitch;
		IF_GetIOStatus=lpInterface->IF_GetIOStatus;
		IF_IOCtl=lpInterface->IF_IOCtl;
		IF_GetCapabilty=lpInterface->IF_GetCapabilty;
		IF_ValidUserPwd=lpInterface->IF_ValidUserPwd;
		IF_OnHttpData=lpInterface->IF_OnHttpData;
		IF_OnCgiData=lpInterface->IF_OnCgiData;
		IF_OnNetworkReady=lpInterface->IF_OnNetworkReady;
		IF_GetSDCardInfo=lpInterface->IF_GetSDCardInfo;
		IF_Test=lpInterface->IF_Test;
		IF_GetBinData=lpInterface->IF_GetBinData;
		IF_IsSDCardExist=lpInterface->IF_IsSDCardExist;
		IF_LoadUserConfigure=lpInterface->IF_LoadUserConfigure;
		IF_UpdateSys=lpInterface->IF_UpdateSys;
		IF_UpdateChildSys=lpInterface->IF_UpdateChildSys;

		IF_StartRecord=lpInterface->IF_StartRecord;
		IF_StopRecord=lpInterface->IF_StopRecord;
		IF_StartFtpRecord=lpInterface->IF_StartFtpRecord;
		IF_StopFtpRecord=lpInterface->IF_StopFtpRecord;
		IF_OpenRecordService=lpInterface->IF_OpenRecordService;
		IF_CloseRecordService=lpInterface->IF_CloseRecordService;
		IF_QueryRecord=lpInterface->IF_QueryRecord;
		IF_GetRecordInfo=lpInterface->IF_GetRecordInfo;
		IF_OpenReplay=lpInterface->IF_OpenReplay;
		IF_ReplayCtrl=lpInterface->IF_ReplayCtrl;
		IF_CloseReplay=lpInterface->IF_CloseReplay;
		IF_RecordSavePicture=lpInterface->IF_RecordSavePicture;
		IF_SetRecordCallback=lpInterface->IF_SetRecordCallback;
		IF_GetRecordMediaInfo=lpInterface->IF_GetRecordMediaInfo;
		IF_GetRecordRange=lpInterface->IF_GetRecordRange;

        IF_AddYuvStreamCallback=lpInterface->IF_AddYuvStreamCallback;
        IF_RemoveYuvStreamCallback=lpInterface->IF_RemoveYuvStreamCallback;
        IF_GetPlatformTypeList=lpInterface->IF_GetPlatformTypeList;
		IF_SendLocalMsg=lpInterface->IF_SendLocalMsg;
		IF_AddLocalMsgCallback=lpInterface->IF_AddLocalMsgCallback;
		IF_RemoveLocalMsgCallback=lpInterface->IF_RemoveLocalMsgCallback;
		IF_SendModuleMsg=lpInterface->IF_SendModuleMsg;
		IF_SetModuleMsgCallback=lpInterface->IF_SetModuleMsgCallback;

        IF_MmzAlloc=lpInterface->IF_MmzAlloc;
        IF_MmzFree=lpInterface->IF_MmzFree;
	}

}M_INTERFACE;

#endif
