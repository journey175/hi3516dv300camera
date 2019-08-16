
#ifndef __HEVENT_H__
#define __HEVENT_H__

#include "hdefines.h"

namespace HDSOFT
{

class CHEvent
{
public:
	CHEvent(bool init=true,bool manualreset=false,bool initialsignal=false);
	~CHEvent();

	int					Init(bool manualreset=false,bool initialsignal=false);
	void				UnInit();
	int					WaitForEvent(unsigned long timeout);
	int					SetEvent();
	int					ResetEvent();
	int					PulseEvent();
protected:
	HANDLE				m_event;
	int					m_idx;
	bool				m_init;
};

}

#endif

