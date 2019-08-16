
#ifndef __AI_LIB_H_
#define __AI_LIB_H_

#include "m_if.h"
#if 1

class CAiLib : public M_INTERFACE
{
private:
	CAiLib();
public:
	virtual ~CAiLib();

	int							InitLib(M_INTERFACE * lpInterface);
	void						UnInitLib();
	static CAiLib &				GetInstance();

private:
	long						m_handle;
};
#endif //if 0

#endif
