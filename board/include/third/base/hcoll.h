
#ifndef __HCOLL_H__
#define __HCOLL_H__

#if defined(_WIN32)
//	#define WIN32_LEAN_AND_MEAN
//	#include <windows.h>
#endif
#include <vector>
#include <stdio.h>
#include "hdefines.h"

namespace HDSOFT
{

///*-------------------------------------
///*CHTree:Tree data structure template class
///*-------------------------------------
template<class T>
class CHTree  
{
public:
	struct TreeElement
	{
		struct TreeElement * parent;
		std::vector<struct TreeElement *>	childs;
		T value;
		unsigned long data;
		unsigned long data2;
		unsigned long data3;
	};
public:
	CHTree();
	virtual ~CHTree();
	
	void						RemoveItem(HANDLE pos);
	void						RemoveAll();
	HANDLE						AddItem(HANDLE parent,T value);
	bool						Append(HANDLE parent,HANDLE newpos,bool copy=true,bool copydata=true);
	static bool					AttachItem(HANDLE parent,HANDLE newpos);
	bool						Attach(HANDLE newpos);
	HANDLE						Detach();
	void						DetachItem(HANDLE pos);
	HANDLE						GetRootItem() const				{ return m_root; }
	int							GetCount()						{ return GetTotleCount(m_root); }

	static T					GetAt(HANDLE pos);
	static void					SetAt(HANDLE pos,T value);
	static unsigned long		GetData(HANDLE pos);
	static void					SetData(HANDLE pos,unsigned long data);
	static unsigned long		GetData2(HANDLE pos);
	static void					SetData2(HANDLE pos,unsigned long data2);
	static unsigned long		GetData3(HANDLE pos);
	static void					SetData3(HANDLE pos,unsigned long data3);
	static int					GetChildCount(HANDLE parent);
	static int					GetTotleCount(HANDLE pos);
	static HANDLE				GetChildItem(HANDLE parent,int index);
	static HANDLE				GetParentItem(HANDLE pos);
	static HANDLE				GetNextSiblingItem(HANDLE pos);
	static HANDLE				GetPrevSiblingItem(HANDLE pos);
protected:
	bool						CopyElement(HANDLE parent,HANDLE srcpos,bool copydata=true);
	virtual void				FreeElement(HANDLE pos);
protected:
	struct TreeElement *		m_root;
};

template<class T>
inline CHTree<T>::CHTree()
{
	m_root	=NULL;
}

template<class T>
inline CHTree<T>::~CHTree()
{
	RemoveItem(m_root);
}

///*-------------------------------------------------------
///*[function]:add a node with 'value' under 'parent' node.
///*[note]:if 'parent' param is NULL,the new node it is the root node.In this case, 
///*when the root node already exists, the function returns NULL. 
///*[return]:a newly added node handle is returned when successful.NULL is means failure.
///*-------------------------------------------------------
template<class T>
HANDLE CHTree<T>::AddItem(HANDLE parent,T value)
{
	struct TreeElement * e = (struct TreeElement *)parent;
	if(e==NULL && m_root)
		return NULL;	//The root element has already existed

	if(e==NULL)
	{
		//as a root element 
		m_root=new struct TreeElement;
		if(m_root==NULL)
			return NULL;
		m_root->parent=NULL;
		m_root->value=value;
		m_root->data=0;
		m_root->data2=0;
		m_root->data3=0;
		return (HANDLE)m_root;
	}

	struct TreeElement * newelem=new struct TreeElement;
	if(newelem==NULL)
		return NULL;
	newelem->parent=e;
	newelem->value=value;
	newelem->data=0;
	newelem->data2=0;
	newelem->data3=0;
	e->childs.push_back(newelem);
	return (HANDLE)newelem;
}

///*-------------------------------------------------------
///*[function]:a node and its descendant nodes are attached to an empty object.
///*[return]:if the object has a node, return failure.
///*-------------------------------------------------------
template<class T>
bool CHTree<T>::Attach(HANDLE newpos)
{
	if(m_root)
		return false;

	m_root=(struct TreeElement *)newpos;
	m_root->parent=NULL;
	return true;
}

///*-------------------------------------------------------
///*[function]:the tree is separated from the object.
///*[return]:root node of the object
///*-------------------------------------------------------
template<class T>
HANDLE CHTree<T>::Detach()
{
	struct TreeElement * e=m_root;
	m_root=NULL;
	return (HANDLE)e;
}

///*-------------------------------------------------------
///*[function]:attach a node and its descendants to a node of the object.
///*[params]:'parent'- the new node acts as a child node of the node,Can't be NULL.
///*	  'newpos'- the new node
///*-------------------------------------------------------
template<class T>
bool CHTree<T>::AttachItem(HANDLE parent,HANDLE newpos)
{
	if(parent==NULL)
		return false;

	if(newpos==NULL)
		return true;

	struct TreeElement * e = (struct TreeElement *)newpos;
	struct TreeElement * eparent=(struct TreeElement *)parent;
	e->parent=eparent;
	eparent->childs.push_back(e);

	return true;
}

///*-------------------------------------------------------
///*[function]:delete all the nodes in the object.
///*-------------------------------------------------------
template<class T>
inline void CHTree<T>::RemoveAll()
{
	RemoveItem(GetRootItem());
}

///*-------------------------------------------------------
///*[function]:delete the specified node in the object.
///*[note]:that all descendant nodes under this node will also be deleted.
///*-------------------------------------------------------
template<class T>
void CHTree<T>::RemoveItem(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return;

	struct TreeElement * eparent=e->parent;
	if(eparent)
	{
		typename std::vector<struct TreeElement *>::iterator it;  
		for(it=eparent->childs.begin();it!=eparent->childs.end();it++)
		{
			if(e==*it)
			{
				eparent->childs.erase(it);		
				break;
			}
		}
	}

	FreeElement(pos);

	if((HANDLE)m_root==pos)
		m_root=NULL;
}

///*-------------------------------------------------------
///*[function]:separating the specified node from the object.
///*[note]:all descendant nodes under this node are also separated from objects.
///*-------------------------------------------------------
template<class T>
void CHTree<T>::DetachItem(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return;

	struct TreeElement * eparent=e->parent;
	if(eparent)
	{
		typename std::vector<struct TreeElement *>::iterator it;  
		for(it=eparent->childs.begin();it!=eparent->childs.end();it++)
		{
			if(e==*it)
			{
				eparent->childs.erase(it);
				break;
			}
		}
		e->parent=NULL;
	}

	if((HANDLE)m_root==pos)
		m_root=NULL;
}

template<class T>
inline T CHTree<T>::GetAt(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	return e->value;
}

template<class T>
inline void CHTree<T>::SetAt(HANDLE pos,T value)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e)
		e->value=value;
}

template<class T>
inline unsigned long CHTree<T>::GetData(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	return e->data;
}

template<class T>
inline void CHTree<T>::SetData(HANDLE pos,unsigned long data)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e)
		e->data=data;
}

template<class T>
inline unsigned long CHTree<T>::GetData2(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	return e->data2;
}

template<class T>
inline void CHTree<T>::SetData2(HANDLE pos,unsigned long data2)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e)
		e->data2=data2;
}

template<class T>
inline unsigned long CHTree<T>::GetData3(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	return e->data3;
}

template<class T>
inline void CHTree<T>::SetData3(HANDLE pos,unsigned long data3)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e)
		e->data3=data3;
}


///*-------------------------------------------------------
///*[function]:get the number of node points under the specified node. 
///*Excluding the number of grandchildren.
///*-------------------------------------------------------
template<class T>
inline int CHTree<T>::GetChildCount(HANDLE parent)
{
	struct TreeElement * e = (struct TreeElement *)parent;
	if(e==NULL)
		return 0;
	return e->childs.size();
}

///*-------------------------------------------------------
///*[function]:Gets the number of all nodes that are started by the specified node. 
///*Including self and descendant nodes. 
///*-------------------------------------------------------
template<class T>
inline int CHTree<T>::GetTotleCount(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return 0;

	int totle=1;
	for(int i=0;i<e->childs.size();i++)
		totle+=GetTotleCount(e->childs[i]);

	return totle;
}

///*-------------------------------------------------------
///*[function]:Get the child nodes under the specified node.
///*[params]:'parent'- the specified node
///*	  'index'- The index of the child node,starting from 0.
///*[return]:the child node handle
///*-------------------------------------------------------
template<class T>
inline HANDLE CHTree<T>::GetChildItem(HANDLE parent,int index)
{
	struct TreeElement * e = (struct TreeElement *)parent;
	if(e==NULL)
		return NULL;

	if(index>=0 && index< e->childs.size())
		return (HANDLE)e->childs[index];

	return NULL;
}

template<class T>
inline HANDLE CHTree<T>::GetParentItem(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return NULL;

	return (HANDLE)e->parent;
}

template<class T>
inline void CHTree<T>::FreeElement(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return;

	for(int i=0;i<e->childs.size();i++)
		FreeElement(e->childs[i]);

	HDSAFEDELETE(e);
}

template<class T>
bool CHTree<T>::CopyElement(HANDLE parent,HANDLE srcpos,bool copydata)
{
	if(srcpos==NULL)
		return true;

	T value=CHTree::GetAt(srcpos);
	HANDLE decpos=AddItem(parent,value);
	if(decpos==NULL)
		return false;

	if(copydata)
	{
		unsigned long data=CHTree::GetData(srcpos);
		unsigned long data2=CHTree::GetData2(srcpos);
		unsigned long data3=CHTree::GetData3(srcpos);
		CHTree::SetData(decpos,data);
		CHTree::SetData2(decpos,data2);
		CHTree::SetData3(decpos,data3);
	}

	for(int i=0;i<CHTree::GetChildCount(srcpos);i++)
	{
		CopyElement(decpos,CHTree::GetChildItem(srcpos,i),copydata);
	}

	return true;
}

///*-------------------------------------------------------
///*[function]:Add the node and its descendants to the object.
///*[params]:'parent'-add to the node of the object. If it is NULL, it will be the root node of the object.
///*	  'copy'-if it is true£¬add a copy when it add.
///*	  'copydata'- it is valid when 'copy' equal true.
///*-------------------------------------------------------
template<class T>
bool CHTree<T>::Append(HANDLE parent,HANDLE newpos,bool copy,bool copydata)
{
	struct TreeElement * e = (struct TreeElement *)newpos;
	if(e==NULL)
		return true;

	if(parent==NULL && m_root)
		return false;

	if(copy)
		return CopyElement(parent,e,copydata);
	else
	{
		if(parent==NULL)
			m_root=e;
		else
		{
			struct TreeElement * eparent=(struct TreeElement *)parent;
			e->parent=eparent;
			eparent->childs.push_back(e);
		}
	}

	return true;
}

///*-------------------------------------------------------
///*[function]:Get the next brother node of the specified node.
///*[return]:When 'pos' is the last node of this level, it returns NULL. 
///*-------------------------------------------------------
template<class T>
HANDLE CHTree<T>::GetNextSiblingItem(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return NULL;

	bool next=false;
	struct TreeElement * eparent=e->parent;
	if(eparent)
	{
		typename std::vector<struct TreeElement *>::iterator it;  
		for(it=eparent->childs.begin();it!=eparent->childs.end();it++)
		{
			if(next)
				return *it;
			if(e==*it)
				next=true;
		}		
	}

	return NULL;	
}

///*-------------------------------------------------------
///*[function]:The previous brother node of the specified node is obtained. 
///*[return]:When 'pos' is the first node of this level, return to NULL 
///*-------------------------------------------------------
template<class T>
HANDLE CHTree<T>::GetPrevSiblingItem(HANDLE pos)
{
	struct TreeElement * e = (struct TreeElement *)pos;
	if(e==NULL)
		return NULL;

	bool next=false;
	struct TreeElement * eparent=e->parent;
	struct TreeElement * eprev=NULL;
	if(eparent)
	{
		typename std::vector<struct TreeElement *>::iterator it;  
		for(it=eparent->childs.begin();it!=eparent->childs.end();it++)
		{
			if(e==*it)
				return eprev;

			eprev=*it;
		}		
	}

	return NULL;	
}

}//namespace HDSOFT
#endif
