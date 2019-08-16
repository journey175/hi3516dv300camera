
#ifndef __HATOMIC_H__
#define __HATOMIC_H__

#if !defined(_WIN32)
#ifdef NO_ATOMIC
#include "base/hmutex.h"
#endif
#endif

namespace HDSOFT
{

class CHAtomic
{
public:
	CHAtomic();
	virtual ~CHAtomic();

	long					AddRef();
	long					ReleaseRef();
	long					OperateOr(long orval);
	long					OperateAnd(long andval);
	long					OperateXor(long xorval);
	void					ResetRef(long reset_val=0);
	long					GetRef();
	
	static long				atomic_increment(long * append,long increment);
	static long				atomic_decrement(long * append,long decrement);
	static long				atomic_set(long * append,long new_val);
	static long				atomic_or(long * append,long or_val);
	static long				atomic_and(long * append,long and_val);
	static long				atomic_xor(long * append,long xor_val);
protected:
	long					m_ref;
#if !defined(_WIN32)
#ifdef NO_ATOMIC
	CHMutex					m_muref;
#endif
#endif

};

}//namespace HDSOFT
#endif
