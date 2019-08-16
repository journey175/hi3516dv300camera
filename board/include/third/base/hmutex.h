#ifndef __HMUTEX_H__
#define __HMUTEX_H__

#if !defined(_WIN32)
	#include <pthread.h>
#else
	#define WIN32_LEAN_AND_MEAN
	#if (defined(_WIN32) && (_MSC_VER < 1300))
		#define _WIN32_WINNT 0x0400
	#endif
	#include <windows.h>
#endif
#include "hdefines.h"

namespace HDSOFT
{

class CHMutex
{
public:
	CHMutex(bool init=true,bool recursive=true,bool usecriticalsection=false);
	~CHMutex();
	int					Init(bool recursive=true,bool usecriticalsection=false);
	void				UnInit();
	int 				Lock();
	int					TryLock();
	int					Unlock();
	bool				IsInitialized() const;	
	bool				IsUseCriticalsection() const;
protected:
#if !defined(_WIN32)
	pthread_mutex_t 	m_mutex;
	bool				m_recursive;
#else
	HANDLE				m_mutex;
	CRITICAL_SECTION	m_critical;
	bool				m_usecriticalsection;
#endif
	bool				m_init;
};

class CHMutexAutoLock
{
public:
	CHMutexAutoLock(CHMutex *mu,bool initiallock=true);
	~CHMutexAutoLock();
	bool				Lock();
	bool				TryLock();
	bool				Unlock();

protected:
	CHMutex *			m_mutex;
	bool				m_acquired;	
};

}//namespace HDSOFT
#endif
