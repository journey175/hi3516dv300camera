
#ifndef __HTIMER_THREAD_H_
#define __HTIMER_THREAD_H_

#include "base/hthread.h"
#include "base/hdelay.h"

namespace HDSOFT
{

#define _H_MAX_THREAD_TIMER				8

class CHTimer : public CHDelay
{
public:
	CHTimer(bool threadsafe=true);
	virtual ~CHTimer();

	//---------------------------------------
	//timerinterval maximum value 0x7FFFFFFF
	//---------------------------------------
	void				SetTimer(unsigned long timerinterval,bool immediately);
	void				KillTimer();
	bool				IsPluse(unsigned long gain);
	void				AdjustReferTick(long span);
};


class CHTimerThread : public CHThread
{
public:
	CHTimerThread();
	virtual ~CHTimerThread();

	//---------------------------------------
	//Set the gain (granularity) of the timer and detect it in the period of gain. 
	//---------------------------------------
	void				SetGain(unsigned long gain);
	//---------------------------------------
	//interval maximum value 0x7FFFFFFF
	//---------------------------------------
	int					SetTimer(unsigned long eventid,unsigned long interval,bool immediately);
	int					KillTimer(unsigned long eventid);

	//---------------------------------------
	//The absolute value of the span will be automatically restricted to the delay-gain 
	//---------------------------------------
	void				AdjustReferTick(unsigned long eventid,long span);
protected:
	virtual	int			OnTimer(unsigned long eventid);					
	int					OnRun(void * param);
	CHTimer				m_timerlist[_H_MAX_THREAD_TIMER];			//Most support _H_MAX_THREAD_TIMER(8)
	unsigned long		m_gain;
};

}//namespace HDSOFT
#endif
