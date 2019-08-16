
#ifndef __PLUGIN_LIB_H_
#define __PLUGIN_LIB_H_

#include "m_if.h"
#include <pthread.h>
#include <map>

class CPluginLib : public M_INTERFACE
{
private:
	CPluginLib();
public:
	virtual ~CPluginLib();

	int							InitLib(M_INTERFACE * lpInterface);
	void						UnInitLib();
	static CPluginLib &			GetInstance();
	bool						m_stop_flag;

private:
	pthread_t					m_thread_id;
};

#endif
