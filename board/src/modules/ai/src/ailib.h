
#ifndef __AI_LIB_H_
#define __AI_LIB_H_

#include "m_if.h"
#include <pthread.h>
#include <map>

typedef struct _CALLBACK_FUNCTION_WITH_CH
{
	int					ch;
	ai_analyse_callback callback_func;
} CALLBACK_FUNCTION_WITH_CH;

class CAiLib : public M_INTERFACE
{
private:
	CAiLib();
public:
	virtual ~CAiLib();

	int							InitLib(M_INTERFACE * lpInterface);
	void						UnInitLib();
	static CAiLib &				GetInstance();
	long						AddCallBackFunction(int p_ch, ai_analyse_callback p_callbackfunc);
	void						RemoveCallBackFunction(int p_handle);
	bool						m_stop_flag;
	bool						m_bThreadRunning;
	std::map<long, CALLBACK_FUNCTION_WITH_CH> m_callback_list;

private:
	static long					m_handle;
	pthread_t					m_thread_id;
};

#endif
