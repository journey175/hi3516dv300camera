
#ifndef __CUSTOMER_LIB_H_
#define __CUSTOMER_LIB_H_

#include "m_if.h"

class CCustomerLib : public M_INTERFACE
{
private:
	CCustomerLib();

public:
    static CCustomerLib &		GetInstance();
	virtual ~CCustomerLib();

	int							InitLib(M_INTERFACE * lpInterface);
	void						UnInitLib();
};

#endif
