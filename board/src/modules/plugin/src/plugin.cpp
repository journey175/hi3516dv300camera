#include "plugin.h"
#include "nsddefines.h"
#include <unistd.h>
#include <stdio.h>

static void *TheThread(void *param)
{
	while (!CPluginLib::GetInstance().m_stop_flag)
	{
		NSD_SYS_INFO_S  stSysInfo={0}; 
		CPluginLib::GetInstance().IF_GetParam(NSDCFG_SYS, &stSysInfo, 0, 0);
		printf("Plugin: version=%s, stream num=%d, rs232=%d, rs485=%d\n",stSysInfo.szVersion ,stSysInfo.u8StreamNum, stSysInfo.u8RS232Num, stSysInfo.u8RS485Num);

		NSD_DEVICE_S  stDevice={0};
		CPluginLib::GetInstance().IF_GetParam(NSDCFG_DEVICE, &stDevice, 0, 0);
		printf("Plugin: mac=%s, ip=%x, httpport=%d\n",stDevice.u8MacAddr, stDevice.u32IPAddr, stDevice.u16HttpPort);

		NSD_TIME_S  stTimeCfg = {0};
		CPluginLib::GetInstance().IF_GetParam(NSDCFG_TIME, &stTimeCfg, 0,0);
		printf("Plugin: %d:%d:%d-%d:%d:%d\n", stTimeCfg.u8Year, stTimeCfg.u8Month, stTimeCfg.u8Day, stTimeCfg.u8Hour, stTimeCfg.u8Minute, stTimeCfg.u8Second);

		NSD_VIDEO_CFG_S  stVideoCfg = {0};
		CPluginLib::GetInstance().IF_GetParam(NSDCFG_VIDEO, &stVideoCfg, 0, 0);
		printf("Plugin: vi width=%d, vi height=%d\n", stVideoCfg.u16ViImageWidth, stVideoCfg.u16ViImageHeight);

		sleep(5);
	}
	
	return 0;
}

CPluginLib::CPluginLib()
:m_stop_flag(false)
{

}

CPluginLib::~CPluginLib()
{
	UnInitLib();
}

CPluginLib & CPluginLib::GetInstance()
{
	static CPluginLib s_ailib;
	return s_ailib;
}

int	CPluginLib::InitLib(M_INTERFACE * lpInterface)
{
	if(lpInterface==NULL)
		return NSDERR_FAIL;

	//it's necessary, copy the interfaces implement to this module
	_Copy(lpInterface);
	
	m_stop_flag = false;

	int status = pthread_create(&m_thread_id, NULL, TheThread, (void *)this);
	if (status != 0)
	{
		printf("pthread_create(),failed!\n");
		return status;
	}

	return NSDERR_SUCCESS;
}

void CPluginLib::UnInitLib()
{
	m_stop_flag = true;

	pthread_cancel(m_thread_id);
}

//////////////////////////////////////////////////////////
//
extern "C"
{
	int	PLUGIN_Start(M_INTERFACE * lpInterface)
	{
		printf("start ................ \n");
		return CPluginLib::GetInstance().InitLib(lpInterface);
	}

	int	PLUGIN_Stop()
	{
		printf("stop ................ \n");
		CPluginLib::GetInstance().UnInitLib();
		return 0;
	}
}
