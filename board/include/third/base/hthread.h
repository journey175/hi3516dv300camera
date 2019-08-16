
#ifndef __HTHREAD_H__
#define __HTHREAD_H__

#include <string>
#include "base/hmutex.h"
namespace HDSOFT
{

///*---------------------------------------------------
///*CHThread:Thread assistant class.
///*---------------------------------------------------
typedef int (*thread_loop)(void * param);

class CHThread
{
public:
	CHThread();
	virtual ~CHThread();

	bool				IsRunning();

	///*----------------------------------------------------------
	///*start thread. the 'suspend' param is ignore under linux.
	///*----------------------------------------------------------
	int					Start(void * param,bool suspend=false);

	///*----------------------------------------------------------
	///*terminate thread.
	///*----------------------------------------------------------
	int					Kill();

	///*----------------------------------------------------------
	///*stop thread
	///*----------------------------------------------------------
	int					Stop();

	///*----------------------------------------------------------
	///*resume thread. the function is ignore under linux.
	///*----------------------------------------------------------
	unsigned long		Resume();

	///*----------------------------------------------------------
	///*suspend thread. the function is ignore under linux.
	///*----------------------------------------------------------
	unsigned long		Suspend();

	bool				IsNeedStop();

	///*----------------------------------------------------------
	///*Want to end the thread normally 
	///*----------------------------------------------------------
	void				WantStop();

	///*----------------------------------------------------------
	///*Set the maximum waiting time at the end of the thread. 
	///*If the thread can not end naturally in 'waittime' (default is 1000 millisecond) time, 
	///*the thread will be aborted. 
	///*----------------------------------------------------------
	void				SetEndThreadWaitTime(unsigned long waittime);

	///*----------------------------------------------------------
	///*The end of the thread is finished by default when the object is destructed.
	///*----------------------------------------------------------
	void				EnableAutoStop(bool enable=true);
	void				EnableSEH(bool enable);
	void				SetSched(int policy,int priority);
	unsigned int		GetThreadID() const;
	HANDLE				GetThreadHandle() const;

	///*----------------------------------------------------------
	///*if loop callback is set,the OnLoop function is not called.
	///*----------------------------------------------------------
	void				SetLoopCallback(thread_loop fcallback);
	void				SetThreadName(const char * name);
	size_t				m_stacksize;
protected:
	virtual int			OnRun(void * param);
	virtual int			OnLoop(void * param);
	virtual int			OnThreadBegin(void * param);
	virtual void		OnThreadEnd(void * param,unsigned int exitcode);
protected:
	bool				m_enable_seh;				//default:true
	std::string			m_thread_name;				//default:undefine

	bool				m_autostop;
	bool				m_stop;
	bool				m_running;
	unsigned long		m_waittime;
	CHMutex				m_runmutex;
	CHMutex				m_stopmutex;
	
	int					m_policy;					//Thread scheduling policy.  -1:no modify,0~2
	int					m_priority;					//thread priority: default:51 ,range:1~99

	thread_loop			m_fcallback;
	void *				m_param;
#if !defined(_WIN32)
	pthread_t 			m_threadhandle;
	pid_t 				m_threadid;
	pthread_mutex_t		m_muexit;
	pthread_cond_t		m_condexit;
	static bool			m_installsign;
	static void *		_theThread(void * par);
	static void			_thread_clean(void* par);
	static void			InstallSignal();
#else
	unsigned int		m_threadid;
	HANDLE				m_threadhandle;
	static unsigned int WINAPI _theThread(LPVOID lpParam);
#endif
};

}//namespace HDSOFT
#endif

