
#ifndef __HDELAY_H__
#define __HDELAY_H__

#include "base/hmutex.h"

namespace HDSOFT
{

class CHDelay
{
public:
	CHDelay(bool threadsafe=true);
	virtual ~CHDelay();

	bool				IsBegin();
	void				BeginTick();

	//---------------------------------------
	//delay the maximum value 0xFFFFFFFF, all XXX_I functions inside their own clock tick. 
	//---------------------------------------
	void				BeginTick_I(unsigned long delay,bool immediately=false);

	//---------------------------------------
	//delay The maximum value is 0x7FFFFFFF, and all XXX functions provide clocks outside.
	//---------------------------------------
	void				BeginTick(unsigned long delay,unsigned long tick);
	void				EndTick();
	void				SetDelay(unsigned long delay);
	void				Reset_I();
	void				Reset(unsigned long tick);
	unsigned long		GetDelay();
	void				PulseTick();

	bool				IsOntime_I();
	bool				IsOntime(unsigned long tick);
protected:
	unsigned long		m_delay;				//default 0
	unsigned long		m_prev_tick;			//default __h_get_tick_count
	bool				m_enable;				//default false
	bool				m_pulse;				//default false
	CHMutex				m_mutex;
};



}//namespace HDSOFT

#endif
