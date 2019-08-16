
#ifndef __HOBJECT_H__
#define __HOBJECT_H__

#include "hdefines.h"

namespace HDSOFT
{

#define HRUNTIME_CLASS(class_name) ((CHRuntimeClass*)(&class_name::class##class_name))

#define IMPLEMENT_HOBJ_RUNTIMECLASS(class_name, base_class_name, pfnNew) \
	const CHRuntimeClass class_name::class##class_name = { \
		#class_name, sizeof(class class_name), pfnNew, \
			HRUNTIME_CLASS(base_class_name) }; \
	CHRuntimeClass* class_name::GetRuntimeClass() const \
		{ return HRUNTIME_CLASS(class_name); } \


#define DECLARE_HOBJ(class_name) \
public: \
	static const CHRuntimeClass class##class_name; \
	virtual CHRuntimeClass* GetRuntimeClass() const; \

#define DECLARE_HOBJ_DYNCREATE(class_name) \
	DECLARE_HOBJ(class_name) \
	static CHObject* HDSTDCALL CreateObject();

#define IMPLEMENT_HOBJ(class_name, base_class_name) \
	IMPLEMENT_HOBJ_RUNTIMECLASS(class_name, base_class_name, NULL)

#define IMPLEMENT_HOBJ_DYNCREATE(class_name, base_class_name) \
	CHObject* HDSTDCALL class_name::CreateObject() \
		{ return new class_name; } \
	IMPLEMENT_HOBJ_RUNTIMECLASS(class_name, base_class_name, \
		class_name::CreateObject)

class CHObject;
struct CHRuntimeClass
{
	const char * m_lpszClassName;
	int m_nObjectSize;
	CHObject* (HDSTDCALL * m_pfnCreateObject)();
	CHRuntimeClass * m_pBaseClass;
	CHObject* CreateObject();
	bool IsDerivedFrom(const CHRuntimeClass* pBaseClass) const;
};

class CHObject
{
public:
	virtual CHRuntimeClass* GetRuntimeClass() const;
	virtual ~CHObject();
protected:
	CHObject();

public:
	bool IsKindOf(const CHRuntimeClass* pClass) const;
	static const CHRuntimeClass classCHObject;
};

}//namespace HDSOFT

#endif