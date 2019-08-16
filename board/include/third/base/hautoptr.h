
#ifndef __HAUTO_PTR_H__
#define __HAUTO_PTR_H__

#include <stdio.h>
#include <assert.h>
#include "hdefines.h"
#include "base/hatomic.h"

namespace HDSOFT
{
template<class T>
class CHAutoPtr
{
	class CHCountContainer
	{
	public:
		CHCountContainer()
		{
			m_usr_count.ResetRef(1);
			m_self_count.ResetRef(1);
		}

		virtual ~CHCountContainer()	
		{
		}

		long AddRef()	
		{
			m_self_count.AddRef(); 
			return m_usr_count.AddRef(); 
		}

		long Release()	
		{ 
			long ret=m_usr_count.ReleaseRef();
			long self=m_self_count.ReleaseRef();
			if(self==0)
			{
				delete this;
			}

			return ret;
		}
	private:
		CHAtomic	m_self_count;
		CHAtomic	m_usr_count;
	};
public:
	CHAutoPtr()
	{
		m_cont=new CHCountContainer; 
		assert(m_cont!=NULL);
		m_ptr=NULL;
	}

	explicit CHAutoPtr(T * p)
	{ 
		m_cont=new CHCountContainer;
		assert(m_cont!=NULL);
		m_ptr=p;
	}

	virtual ~CHAutoPtr() 
	{
		_Release();
	}

	CHAutoPtr(const CHAutoPtr & cp):m_cont(cp.m_cont)
	{
		m_cont->AddRef();
		m_ptr=cp.m_ptr;
	}

	CHAutoPtr & operator= (const CHAutoPtr & cp)
	{
		cp.m_cont->AddRef();
		_Release();

		m_cont=cp.m_cont;
		m_ptr=cp.m_ptr;
		return *this;
	}
	
	CHAutoPtr & operator= (T * p)
	{
		if(m_ptr!=p)
		{
			_Release();
			m_cont=new CHCountContainer; 
			assert(m_cont!=NULL);
			m_ptr=p;
		}
		return *this;
	}

	operator T*() const
	{
		return m_ptr;
	}

	operator T&()
	{
		return *m_ptr;
	}

	T * operator->() const
	{
		return m_ptr;
	}

	T& operator*() const
	{
		return *m_ptr;
	}
	
	operator bool() const
	{
		return m_ptr!=NULL;
	}

	bool operator==(T * p)
	{
		return m_ptr==p?true:false;
	}
	
	bool operator!=(T * p)
	{
		return !(operator==(p));
	}

	bool operator==(int null)
	{
		if(null!=0)
			return false;
		return m_ptr==NULL;
	}

	bool operator!=(int null)
	{
		return !(operator==(null));
	}

	T * Detach()
	{
		T* const old=m_ptr;
		m_ptr = NULL;
		return old;
	}
private:
	void _Release()
	{
		long ret=m_cont->Release();
		if(ret<=0)
		{
			if(m_ptr)
			{
				delete m_ptr;
				m_ptr=NULL;
			}
		}
	}

	CHCountContainer * m_cont;
	T *	m_ptr;
};

}//namespace HDSOFT

#endif
