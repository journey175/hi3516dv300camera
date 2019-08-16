

#ifndef __NSDNETINTERFACE_H_
#define __NSDNETINTERFACE_H_

#include "nsddefines.h"

#ifdef __cplusplus
extern "C" {
#endif


#if (defined(WIN32) || defined(_WIN32_WCE))
	#ifdef NsdNetSDK_EXPORTS
	#define NSDAPI __declspec(dllexport)
	#else
	#define NSDAPI __declspec(dllimport)
	#endif
#else
	#define WINAPI 
	#define NSDAPI

	typedef unsigned int WPARAM;
	typedef long LPARAM;
	typedef double DATE;
	typedef void *	HANDLE;	
	typedef int BOOL;
#endif

#define MAX_EVENT_CALLBACK_NUM		4
typedef enum _NSD_PRESET_CMD_E
{
	NSDPRESET_SET,
	NSDPRESET_CLEAR,
	NSDPRESET_CALL,
}NSD_PRESET_CMD_E;

typedef enum _NSD_TOUR_CMD_E
{
	NSDTOUR_FILL_PRE,		//将预置点加入巡航序列
	NSDTOUR_CLE_PRE,		//将预置点从巡航序列中删除
	NSDTOUR_RUN,			//运行巡航
	NSDTOUR_STOP,			//停止巡航
}NSD_TOUR_CMD_E;

typedef enum _NSD_TRACK_CMD_E
{
	NSDTRACK_REC,			//录制轨迹
	NSDTRACK_SAVE,			//停止录制轨迹
	NSDTRACK_RUN,			//运行轨迹
	NSDTRACK_STOP,			//停止运行轨迹
}NSD_TRACK_CMD_E;

//3、事件类型
typedef enum _NSD_EVENT_TYPE_E
{
	NSDEVENT_CONNECT_SUCCESS,			//中心模式主连接连接成功
	NSDEVENT_CONNECT_CLOSE,				//中心模式主连接关闭
	NSDEVENT_LOGON_OPEN,
	NSDEVENT_LOGON_CLOSE,				//登录连接关闭
	NSDEVENT_PREVIEW_OPEN,
	NSDEVENT_PREVIEW_CLOSE,				//视频连接关闭
	NSDEVENT_TALK_OPEN,
	NSDEVENT_TALK_CLOSE,				//对讲连接关闭
	NSDEVENT_REPLAY_OPEN,
	NSDEVENT_REPLAY_CLOSE,				//远程回放连接关闭
	NSDEVENT_PICTURE_OPEN,
	NSDEVENT_PICTURE_CLOSE,				//抓图连接关闭
	NSDEVENT_SERIAL_OPEN,
	NSDEVENT_SERIAL_CLOSE,				//透明串口连接关闭
	NSDEVENT_DV_OPEN,
	NSDEVENT_DV_CLOSE,					//解码连接关闭

	NSDEVENT_ALARM,						//告警信息
	NSDEVENT_GPS,						//GPS信息
	NSDEVENT_SEARCH_FILE,				//搜索的录像文件信息
	NSDEVENT_SEARCH_DEVICE,				//搜索的设备信息
	NSDEVENT_UPDATE_PROCESS,			//升级进度
	NSDEVENT_MOTION_STATUS,				//移动侦测状态报告
	NSDEVENT_REPLAY_END,
	NSDEVENT_DAY_NIGHT_STATUS,			//日夜切换状态报告
	NSDEVENT_LOCAL_MSG,
}NSD_EVENT_TYPE_E;

//////////////////////////////////////////////////
//事件通知回调
typedef int (WINAPI *EventNotifyCallback)(WPARAM wParam,LPARAM lParam);
//实时音视频数据流回调
typedef int (WINAPI *StreamCallback)(HANDLE hOpenChannel,int nChannelNo,int nSubFlow,const char * pStreamData,unsigned long nDataLen,void * lpChannelContext);
//实时对讲音频数据流回调
typedef int (WINAPI *TalkCallback)(HANDLE hTalk,const char * pTalkData,unsigned long nDataLen,void * lpTalkContext);
//录像回放回调
typedef int (WINAPI *NetReplayCallback)(HANDLE hReplay,int nType,const char * pStreamData,unsigned long nDataLen,void * lpReplayContext,long nPercent);
//抓拍图片回调
typedef int (WINAPI *CapturePictureCallback)(HANDLE hPicture,int nChannelNo,int nSubFlow,int nPictureFormat,const char * pPictureData,unsigned long nDataLen,void * lpPictureContext);
//串口数据回调
typedef int (WINAPI *SerialCallback)(HANDLE hSerial,int nSerialNo,const char * pSerialData,unsigned long nDataLen,void * lpSerialContext);

//==========================================================================
//通道结构
//==========================================================================

//1、打开视频通道
typedef struct _NSD_OPEN_CHANNEL_INFO
{
	unsigned short		nOpenChannelNo;					//打开通道号，base 0
	unsigned char		nSubFlow;						//码流号 ，base 1;
	unsigned char		nSuspend;
	unsigned char		nRecvMDInfo;
	unsigned char		nRecvAudio;
	unsigned char		rsvd[2];
	unsigned short		nTransProtocol;					//通讯协议
	StreamCallback		funcStramCallback;				//音视频流回调函数
	void *				lpChannelContext;				//通道上下文
}NSD_OPEN_CHANNEL_INFO,* LPNSD_OPEN_CHANNEL_INFO;

//2、打开抓图通道
typedef struct _NSD_OPEN_PICTURE_INFO
{
	unsigned short		nOpenChannelNo;					//打开通道号，base 0
	unsigned short		nTransProtocol;					//通讯协议
	unsigned char		rsvd[4];
	CapturePictureCallback funcCapPictureCallback;		//抓图回调
	void *				lpPictureContext;				//抓图上下文
}NSD_OPEN_PICTURE_INFO,* LPNSD_OPEN_PICTURE_INFO;

//3、打开透明数据通道
typedef struct _NSD_OPEN_SERIAL_INFO
{
	unsigned short		nOpenSerialNo;					//串口号
	unsigned short		nTransProtocol;					//通讯协议
	SerialCallback		funcSerialCallback;				//透明数据回调
	unsigned char		nSuspend;
	unsigned char		rsvd[3];
	void *				lpSerialContext;				//透明串口上下文
}NSD_OPEN_SERIAL_INFO,* LPNSD_OPEN_SERIAL_INFO;

//5、打开对讲通道
typedef struct _NSD_OPEN_TALK_INFO
{
	unsigned short		nTransProtocol;					//通讯协议
	unsigned char		nSuspend;
	unsigned char		rsvd;
	TalkCallback		funcTalkCallback;				//对讲数据回调
	void *				lpTalkContext;					//对讲上下文
}NSD_OPEN_TALK_INFO,* LPNSD_OPEN_TALK_INFO;

//6、打开远程回放通道
typedef struct _NSD_OPEN_REPLAY_INFO
{
	unsigned short		nTransProtocol;					//通讯协议
	unsigned short		rsvd;							//保留
	NetReplayCallback	funcNetRePlayCallback;			//录像回放回调函数
	void *				lpReplayContext;				//回放上下文
}NSD_OPEN_REPLAY_INFO,*LPNSD_OPEN_REPLAY_INFO;

//==========================================================================
//事件结构
//==========================================================================

//1、视频通道事件
typedef struct _NSD_EVENT_CHANNEL_INFO
{
	HANDLE				hChannel;						//事件对应的通道句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	unsigned short		nOpenChannelNo;					//通道号，base 0
	unsigned short		nSubFlow;						//0:主码流，1:次码流
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpChannelContext;				//通道上下文
}NSD_EVENT_CHANNEL_INFO,*LPNSD_EVENT_CHANNEL_INFO;

//2、登录通道事件
typedef struct _NSD_EVENT_LOGON_INFO
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpLogonContext;					//登录上下文
}NSD_EVENT_LOGON_INFO,*LPNSD_EVENT_LOGON_INFO;

//3、对讲通道事件
typedef struct _NSD_EVENT_TALK_INFO
{
	HANDLE				hTalk;							//对讲句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpTalkContext;					//对讲上下文
}NSD_EVENT_TALK_INFO,*LPNSD_EVENT_TALK_INFO;

//4、抓图通道事件
typedef struct _NSD_EVENT_PICTURE_INFO
{
	HANDLE				hPicture;						//抓图句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpPictureContext;				//抓图上下文
}NSD_EVENT_PICTURE_INFO,*LPNSD_EVENT_PICTURE_INFO;

//5、透明传输通道事件
typedef struct _NSD_EVENT_SERIAL_INFO
{
	HANDLE				hSerial;						//透明串口句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	unsigned short		nOpenSerialNo;					//串口号，base 0
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpSerialContext;				//串口上下文	
}NSD_EVENT_SERIAL_INFO,*LPNSD_EVENT_SERIAL_INFO;

//6、远程回放通道事件
typedef struct _NSD_EVENT_REPLAY_INFO
{
	HANDLE				hReplay;						//远程回放句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpReplayContext;				//远程回放上下文
}NSD_EVENT_REPLAY_INFO,*LPNSD_EVENT_REPLAY_INFO;

//7、录像搜索事件
typedef struct _NSD_EVENT_RECFILE_INFO
{
	HANDLE				hReplay;						//远程回放句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	unsigned long		nRecType;						//录像类型
	unsigned short		nOpenChannelNo;					//通道号
	unsigned short		nSubFlow; 						//0:主码流，1:次码流
	NSD_TIME_S			tmStart;						//录像的开始时间
	NSD_TIME_S			tmEnd;							//录像的结束时间
	unsigned long		nRecSize;						//录像总字节数		
	char                szFileName[260];				//yyyymmddhhmmss-yyymmddhhmmss
	int					nMark;							//0:未结束，1:最后一条	
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpReplayContext;				//远程回放上下文
}NSD_EVENT_RECFILE_INFO,*LPNSD_EVENT_RECFILE_INFO;

//8、设备搜索事件
typedef struct _NSD_EVENT_DEVICE_INFO
{
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szMachineType[NAME_LEN_48];		//机型
	unsigned long		nSensorType;					//Sensor类型
	unsigned long		nFaceType;						//外观类型
	char				szServerIP[16];					//搜索连接IP地址
	char				szGateWay[16];					//网关
	char				szSubMask[16];					//掩码
	unsigned char		nMacAddr[6];					//MAC地址
	unsigned char		nChannelNum;					//路数
	unsigned char		rsvd;
	unsigned short		nListenPort;
	unsigned short		nHttpPort;
	char				szDeviceName[NAME_LEN_32];		//设备名称
	void *				lpSearchDeviceContext;			//搜索设备上下文
	short				bFinish;						//搜索结束
	unsigned short		nUpdatePort;					//
	char				szDeviceIP[16];					//设备有线网络IP地址
	char				szVersion[NAME_LEN_48];			//版本

	char				szDNSIP1[16];					//DNS的IP1
	char				szDNSIP2[16];					//DNS的IP2
	unsigned char		nDHCP1;							//有线网卡的DHCP开关
	unsigned char		nDHCP2;							//DNS的DHCP开关
	unsigned short		nOldListenPort;
}NSD_EVENT_DEVICE_INFO,*LPNSD_EVENT_DEVICE_INFO;

//9、告警事件
typedef struct _NSD_EVENT_ALARM_INFO
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	NSD_ALARM_OUTPUT_STATUS_S	alarmSatus;				//告警输出状态
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpLogonContext;					//登录上下文	
}NSD_EVENT_ALARM_INFO,*LPNSD_EVENT_ALARM_INFO;

//10、中心模式事件
typedef struct _NSD_EVENT_CENTER_INFO
{
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szMachineType[NAME_LEN_48];		//机型
	char				szServerIP[16];					//视频服务器IP地址
	unsigned char		nMacAddr[6];					//MAC地址
	unsigned char		nChannelNum;					//路数
	unsigned char		nPtzNum;
	unsigned short		nServerPort;					//视频服务器端口
	unsigned char		nDiNum;
	unsigned char		nDoNum;
	char				szDeviceName[NAME_LEN_32];			//设备名称
}NSD_EVENT_CENTER_INFO,*LPNSD_EVENT_CENTER_INFO;

typedef struct _NSD_EVENT_MOTION_INFO
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	NSD_MOTION_STATUS_S	motionStatus;					//移动侦测状态
	char *				lpData;							//移动侦测数据(内部分配，不要释放)
	unsigned long		nDataLen;						//移动侦测数据长度
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	void *				lpLogonContext;					//登录上下文	
}NSD_EVENT_MOTION_INFO,*LPNSD_EVENT_MOTION_INFO;

typedef struct _NSD_EVENT_UPDATE_INFO
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	void *				lpUpdateContext;				//升级上下文
	int					nPercent;						//安装百分比(nStatus=2)
	unsigned long		nTotleBytes;					//发送总字节(nStatus=1)
	unsigned long		nSendBytes;						//已发送字节(nStatus=1)
	int					nReboot;						//是否会重启(nStatus=0)
	int					nStatus;						//0升级成功，1正在发送(nSendBytes)，2正在安装(nPercent)，-1升级失败, 其它值错误返回码
}NSD_EVENT_UPDATE_INFO,*LPNSD_EVENT_UPDATE_INFO;


typedef struct _NSD_EVENT_DAYNIGHT_STATUS
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	unsigned int		nChannel;
	int					nStatus;						//NSD_DAYNIGHT_STATUS_E	
	void *				lpLogonContext;					//登录上下文	
}NSD_EVENT_DAYNIGHT_STATUS,*LPNSD_EVENT_DAYNIGHT_STATUS;

typedef struct _NSD_EVENT_LOCAL_MSG
{
	HANDLE				hLogon;							//登录句柄
	char				szDeviceID[NAME_LEN_16];		//设备ID
	char				szServerURL[NAME_LEN_64];		//连接的视频服务器IP
	unsigned short		nServerPort;					//连接的视频服务器端口
	
	unsigned int		nMsgType;
	unsigned char		rsvd[36];
	void *				pMsg;
	unsigned int		nMsgLen;

	void *				lpLogonContext;					//登录上下文	
}NSD_EVENT_LOCAL_MSG,*LPNSD_EVENT_LOCAL_MSG;

//==================================================
//设置回调函数
//==================================================
#if (defined(WIN32) || defined(_WIN32_WCE))
NSDAPI int WINAPI NSDNET_SetEventMsg(HWND hNotifyWnd,unsigned long nCommandID);
#endif
NSDAPI int WINAPI NSDNET_SetEventCallback(EventNotifyCallback lpCallback);
NSDAPI int WINAPI NSDNET_SetEventCallbackEx(int nIndex,EventNotifyCallback lpCallback);

//==================================================
//登录及控制函数
//==================================================
NSDAPI int WINAPI NSDNET_Login(const char * lpServerIP,unsigned short nServerPort,const char * lpUserName,const char * lpPassword,unsigned long nRsvd,void * lpLogonContext,HANDLE * lpLogin);
NSDAPI int WINAPI NSDNET_LoginEx(const char * lpServerIP,unsigned short nServerPort,const char * lpUserName,const char * lpPassword,unsigned long nRsvd,void * lpLogonContext,HANDLE * lpLogin);
#if !defined(_WIN32)
int WINAPI NSDNET_LoginLocal(const char * lpSunPath,unsigned long nRsvd,void * lpLogonContext,HANDLE * lpLogin);
int WINAPI NSDNET_SendLocalMsg(HANDLE hLogin, NSD_LOCAL_MSG_HEAD_S msgHead,const char * lpMsg,unsigned int nMsgLen);
#endif
NSDAPI int WINAPI NSDNET_Logout(HANDLE hLogin);
NSDAPI int WINAPI NSDNET_GetServerInfo(HANDLE hLogin,NSD_SYS_INFO_S * lpSysInfo);
NSDAPI int WINAPI NSDNET_GetDeviceInfo(HANDLE hLogin,NSD_DEVICE_S * lpDevice);
NSDAPI int WINAPI NSDNET_GetServerConfig(HANDLE hLogin,NSD_CONFIG_TYPE_E nConfigType,char * lpConfigBuf,unsigned long * lpBufferSize,unsigned long nAppend);
NSDAPI int WINAPI NSDNET_SetServerConfig(HANDLE hLogin,NSD_CONFIG_TYPE_E nConfigType,char * lpConfigBuf,unsigned long nBufferSize,unsigned long nAppend);
NSDAPI int WINAPI NSDNET_GetServerMultiConfig(HANDLE hLogin,const char * lpMultiCfgHead,unsigned long nHeadLen,char * lpConfigBuf,unsigned long * lpBufferSize);
NSDAPI int WINAPI NSDNET_SetServerMultiConfig(HANDLE hLogin,char * lpMultiConfigBuf,unsigned long nBufferSize);
NSDAPI int WINAPI NSDNET_PTZControl(HANDLE hLogin,NSD_PTZ_CTRL_S * lpPtzCtrl);
NSDAPI int WINAPI NSDNET_Update(HANDLE hLogin,const char * lpUpdateFileName,void * lpUpdateContext);
NSDAPI int WINAPI NSDNET_IngoreUpdateReboot(HANDLE hLogin);
NSDAPI int WINAPI NSDNET_ToDefaultParam(HANDLE hLogin);
NSDAPI int WINAPI NSDNET_ToDefaultParamEx(HANDLE hLogin,unsigned long nParam, unsigned long nReboot);
NSDAPI int WINAPI NSDNET_Reboot(HANDLE hLogin);
NSDAPI int WINAPI NSDNET_ForceKeyFrame(HANDLE hLogin,unsigned short nChannelNo,unsigned short nSubFlow);
NSDAPI int WINAPI NSDNET_GetServerCapability(HANDLE hLogin,const char * lpCapabiltyHead,unsigned long nHeadLen,char * lpCapabiltyBuf,unsigned long * lpBufferSize);
NSDAPI int WINAPI NSDNET_PTZPreset(HANDLE hLogin,NSD_PRESET_CMD_E nPresetCmd,NSD_PRESET_CFG_S * lpPtzCtrl);
NSDAPI int WINAPI NSDNET_QueryPreset(HANDLE hLogin,char * lpRecvBuf,unsigned long * lpBufferSize,unsigned long nAppend);
NSDAPI int WINAPI NSDNET_PTZTour(HANDLE hLogin,NSD_TOUR_CMD_E nTourCmd,unsigned short nChannelNo,unsigned short nTourNo,unsigned short nPointIndex,LPNSD_TOUR_POINT_S lpTourPoint);
NSDAPI int WINAPI NSDNET_QueryTour(HANDLE hLogin,char * lpRecvBuf,unsigned long * lpBufferSize,unsigned short nChannelNo,unsigned short nTourNo);
NSDAPI int WINAPI NSDNET_PTZTrack(HANDLE hLogin,NSD_TRACK_CMD_E nTrackCmd,unsigned short nChannelNo,unsigned short nTrackNo);
NSDAPI int WINAPI NSDNET_Ball3DCtrl(HANDLE hLogin,NSD_BALL_3D_S * lpBall,unsigned long nRsvd);
NSDAPI void WINAPI NSDNET_RefreshReconn(HANDLE hLogin);
NSDAPI int WINAPI NSDNET_ControlLogin(HANDLE hLogin,BOOL bRecvAlarm);
NSDAPI int WINAPI NSDNET_ManufactureTest(HANDLE hLogin,unsigned long nTestType,unsigned long nChn,unsigned long nParam1,unsigned long nParam2);
NSDAPI int WINAPI NSDNET_SearchLog(HANDLE hLogin, unsigned long nLogType, NSD_TIME_S * lpTmStart, NSD_TIME_S * lpTmEnd, char** lpBuf, unsigned long * lpBufSize);
NSDAPI int WINAPI NSDNET_VerifyParam(HANDLE hLogin,NSD_CONFIG_TYPE_E nConfigType,char * lpParamBuf,unsigned long nBufferSize, unsigned long nAppend);
NSDAPI int WINAPI NSDNET_IOCtrl(HANDLE hLogin,unsigned long nIOType, unsigned long nChn, unsigned long nValue, unsigned long nAppend);

NSDAPI int WINAPI NSDNET_PTZGetPosition(HANDLE hLogin, NSD_PTZ_POSITION_S* lpPtzPosition);
NSDAPI int WINAPI NSDNET_PTZSetPosition(HANDLE hLogin, NSD_PTZ_POSITION_S* lpPtzPosition);
NSDAPI int WINAPI NSDNET_GetCalibration(HANDLE hLogin, char** lpBuf, unsigned long * lpBufSize);

NSDAPI int WINAPI NSDNET_FormatSDCard(HANDLE hLogin, unsigned long nChn);
//Size Unit: MB
NSDAPI int WINAPI NSDNET_GetSDCardInfo(HANDLE hLogin, unsigned long nChn, unsigned long * lpTotalsize, unsigned long * lpFreesize);

NSDAPI int WINAPI NSDNET_GetVideoMediaInfo(HANDLE hLogin, short nChannelNo, short nSubFlow, char * lpMediaInfoBuf, unsigned long* lpBufferSize, unsigned long nAppend);

NSDAPI int WINAPI NSDNET_UpdateMemory(HANDLE hLogin, const char * lpUpdateBuf, unsigned long nBufferSize, void * lpUpdateContext);
NSDAPI int WINAPI NSDNET_UploadFile(HANDLE hLogin, const char* lpFile, const char* lpDst, unsigned long nAppend);
//==================================================
//预览函数
//==================================================
NSDAPI int WINAPI NSDNET_StartPreview(HANDLE hLogin,NSD_OPEN_CHANNEL_INFO * lpChannelInfo,HANDLE * lpPreview);
NSDAPI int WINAPI NSDNET_StartPreviewEx(HANDLE hLogin,NSD_OPEN_CHANNEL_INFO * lpChannelInfo,HANDLE * lpPreview);
NSDAPI int WINAPI NSDNET_StopPreview(HANDLE hPreview);
NSDAPI int WINAPI NSDNET_ControlPreview(HANDLE hPreview,BOOL bSuspend,BOOL bRecvMDInfo,BOOL bRecvAudio);

//==================================================
//对讲函数
//==================================================
NSDAPI int WINAPI NSDNET_StartTalk(HANDLE hLogin,NSD_OPEN_TALK_INFO * lpTalkInfo,HANDLE * lpTalk);
NSDAPI int WINAPI NSDNET_StartTalkEx(HANDLE hLogin,NSD_OPEN_TALK_INFO * lpTalkInfo,HANDLE * lpTalk);
NSDAPI int WINAPI NSDNET_StopTalk(HANDLE hTalk);
NSDAPI int WINAPI NSDNET_SendTalkData(HANDLE hTalk,const char * lpTalkData,unsigned long nDataLen);
NSDAPI int WINAPI NSDNET_ControlTalk(HANDLE hTalk,BOOL bSuspend);

//==================================================
//串口透传函数
//==================================================
NSDAPI int WINAPI NSDNET_StartSerial(HANDLE hLogin,NSD_OPEN_SERIAL_INFO * lpSerialInfo,HANDLE * lpSerial);
NSDAPI int WINAPI NSDNET_StartSerialEx(HANDLE hLogin,NSD_OPEN_SERIAL_INFO * lpSerialInfo,HANDLE * lpSerial);
NSDAPI int WINAPI NSDNET_StopSerial(HANDLE hSerial);
NSDAPI int WINAPI NSDNET_ControlSerial(HANDLE hSerial,BOOL bSuspend);
NSDAPI int WINAPI NSDNET_SendSerialData(HANDLE hSerial,const char * lpSerialData,unsigned long nDataLen);

//==================================================
//抓图函数
//==================================================
NSDAPI int WINAPI NSDNET_StartPicture(HANDLE hLogin,NSD_OPEN_PICTURE_INFO * lpPictureInfo,HANDLE * lpPicture);
NSDAPI int WINAPI NSDNET_StartPictureEx(HANDLE hLogin,NSD_OPEN_PICTURE_INFO * lpPictureInfo,HANDLE * lpPicture);
NSDAPI int WINAPI NSDNET_StopPicture(HANDLE hPicture);
NSDAPI int WINAPI NSDNET_CapturePicture(HANDLE hPicture,short nChannelNo,short nSubFlow);
NSDAPI int WINAPI NSDNET_ControlPicture(HANDLE hPicture,BOOL bSuspend);

//==================================================
//搜索设备函数
//==================================================
NSDAPI int WINAPI NSDNET_SearchAllDevice(unsigned long nTimeOut,void * lpSearchDeviceContext);
NSDAPI int WINAPI NSDNET_SearchAllDeviceEx(const char *szBindIP,unsigned long nTimeOut,void * lpSearchDeviceContext);
NSDAPI int WINAPI NSDNET_ConfigDevice(const char * lpUserName,const char * lpPassword,NSD_EVENT_DEVICE_INFO * lpDeviceInfo);
NSDAPI int WINAPI NSDNET_ConfigDeviceEx(const char * szBindIP,const char * lpUserName,const char * lpPassword,NSD_EVENT_DEVICE_INFO * lpDeviceInfo);

//==================================================
NSDAPI int WINAPI NSDNET_OpenReplay(HANDLE hLogin,NSD_OPEN_REPLAY_INFO * lpReplayInfo,HANDLE * lpReplay);
NSDAPI int WINAPI NSDNET_SearchRecordFile(HANDLE hReplay,int nChannelNo,int nSubFlow,NSD_TIME_S * lpTmStart,NSD_TIME_S * lpTmEnd,int nRecType);
NSDAPI int WINAPI NSDNET_PlayFile(HANDLE hReplay,int nChannelNo,int nSubFlow,NSD_TIME_S * lpTmStart,NSD_TIME_S * lpTmEnd,int nRecType);
NSDAPI int WINAPI NSDNET_SpeedFile(HANDLE hReplay,int nSpeed);
NSDAPI int WINAPI NSDNET_SeekFile(HANDLE hReplay,NSD_TIME_S * lpTmSeek,BOOL bToKeyFrame); 
NSDAPI int WINAPI NSDNET_StepFile(HANDLE hReplay,BOOL bToKeyFrame,BOOL bBack);
NSDAPI int WINAPI NSDNET_PauseFile(HANDLE hReplay,BOOL bPause);
NSDAPI int WINAPI NSDNET_StopFile(HANDLE hReplay);
NSDAPI int WINAPI NSDNET_CloseReplay(HANDLE hReplay);

NSDAPI void WINAPI NSDNET_EnableReconnect(int bEnable,unsigned short nIntervalSec);
NSDAPI void WINAPI NSDNET_SetRunParam(unsigned long nConnectTimeMillSec,unsigned long nOperateTimeMillSec,unsigned long nRsvd);
NSDAPI void WINAPI NSDNET_SetRunParamEx(long nParamType,unsigned long nValue);

NSDAPI void WINAPI NSDNET_FreeBuffer(char* lpBuffer);
NSDAPI void WINAPI NSDNET_FreeAllLogin();
#ifdef __cplusplus
}
#endif
#endif

