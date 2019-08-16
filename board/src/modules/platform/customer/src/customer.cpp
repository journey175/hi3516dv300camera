
#include "customer.h"

/////////////////////////////////////////////////////
//
CCustomerLib::CCustomerLib()
{
}

CCustomerLib::~CCustomerLib()
{	

}

int CCustomerLib::InitLib(M_INTERFACE * lpInterface)
{
	if(lpInterface==NULL)
		return -1;

    //必须执行该语句， 之后CCustomerLib可以使用中间接口
	_Copy(lpInterface);
	
    printf("Customer Platform: CCustomerLib::InitLib\n");
	return 0;
}

void CCustomerLib::UnInitLib()
{
    printf("Customer Platform: CCustomerLib::UnInitLib\n");
}

CCustomerLib & CCustomerLib::GetInstance()
{
	static CCustomerLib s_obj;
	return s_obj;
}

/////////////////////////////////
//
extern "C"
{
int PLATFORM_GetVersion()
{
    //如果版本和nsd版本不同， 则不会加载该动态库
	return CORE_VERSION;
}

int PLATFORM_GetType()
{
    //必须返回该值
	return PTTYPE_CUSTOMER;
}

int PLATFORM_InitLib(M_INTERFACE *lpInterface)
{
    //初始化该库， nsd在启动的时候会调用该接口， lpInterface为中间接口层指针
    if(NULL==lpInterface)
		return -1;

	return CCustomerLib::GetInstance().InitLib(lpInterface);
}

int PLATFORM_ChangeParam(NSD_CONFIG_TYPE_E nParamType, void * lpParam,unsigned long nCh,unsigned long nRsvd)
{
    //参数变化时会调用该接口
	if(nParamType==NSDCFG_PLATFORM && nRsvd==PTTYPE_CUSTOMER)
    {
        printf("Customer Platform: PLATFORM_ChangeParam\n");
    }
	return 0;
}

void PLATFORM_DispatchAlarm(NSD_ALARM_OUTPUT_STATUS_S & aos)
{
    //有报警触发或消除时会调用该接口
}

int PLATFORM_UnInitLib()
{
    //nsd退出时会调用该接口
	return 0;
}

int PLATFORM_OnHttpData(const char * szBuf,char * szOutBuf,int nOutBufSize)
{
    //不会调用该接口， 忽略该接口
	return 0;
}

int	PLATFORM_OnSDCardStatusChange(unsigned int nStatus)
{
    //SD卡开始格式化， 和格式化完成时会调用该接口
	return 0;
}

int PLATFORM_OnNetworkReady(int nNetworkType)
{
    //网络参数变化后需要重启网络时会调用到该接口
	return 0;
}

}