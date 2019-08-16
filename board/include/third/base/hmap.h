
#ifndef __HMAP_H__
#define __HMAP_H__

#include <assert.h>
#include <string.h>
#include <string>
#include "hdefines.h"

namespace HDSOFT
{

template<class ARG_KEY>
#if !defined(_WIN32)
unsigned long HashKey(ARG_KEY key) 
#else 
unsigned long __stdcall HashKey(ARG_KEY key)
#endif
{
	return ((unsigned long)(void*)(unsigned long)key) >> 4;
}

template<> 
#if !defined(_WIN32)
unsigned long HashKey<const char *> (const char * key);
#else
unsigned long __stdcall HashKey<const char *> (const char * key);
#endif

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
class CHMap  
{
public:
	struct HashElement
	{
		HashElement	*next;
		unsigned long index;  
		KEY key;
		VALUE value;
	};
public:
	CHMap(unsigned long hashsize=17);
	virtual ~CHMap();

	int							GetCount() const					{ return m_count; }
	bool						IsEmpty() const						{ return (m_count==0)?true:false; }

	bool						Lookup(ARG_KEY key, VALUE& value) const;
	VALUE&						operator[](ARG_KEY key);
	void						SetAt(KEY key, ARG_VALUE value)		{ (*this)[key] = value; }
	
	bool						RemoveKey(ARG_KEY key);
	void						RemoveAll();

	VALUE&						GetCurrentElement() const			{ return m_curelem->value; }
	bool						HasCurrentElement() const			{ return (m_curelem==0)?false:true; }
	void						GotoFirstElement();
	void						GotoNextElement();
	void						GotoElement(ARG_KEY key);

	HANDLE						GetStartPosition() const			{ return (m_count==0)?NULL:(HANDLE)-1L; }
	void						GetNextElement(HANDLE & pos,KEY& key,VALUE& value) const;

	void						InitHashTable(unsigned long hashsize,bool allocnow=true);
	unsigned long				GetHashTableSize() const			{ return m_hashsize; }
	
private:
	CHMap(const CHMap& src);
	const CHMap& operator=(const CHMap& src);
protected:
	struct HashElement *		GetElementAt(ARG_KEY key,unsigned long & index) const;

protected:
	struct HashElement **		m_table;
	struct HashElement *		m_curelem;
	unsigned long				m_hashsize;
	int							m_count;
};

class CHMapStringToPtr  
{
public:
	struct HashElement
	{
		HashElement	*next;
		unsigned long index;  
		std::string key;
		void* value;
	};

	CHMapStringToPtr(unsigned long hashsize=17);
	virtual ~CHMapStringToPtr();

	int							GetCount() const					{ return m_count; }
	bool						IsEmpty() const						{ return (m_count==0)?true:false; }

	bool						Lookup(const char * key, void*& value) const;
	void*&						operator[](const char * key);
	void						SetAt(const char * key, void* value)		{ (*this)[key] = value; }

	bool						RemoveKey(const char * key);
	void						RemoveAll();

	unsigned long				HashKey(const char * key) const;

	void*&						GetCurrentElement() const			{ return m_curelem->value; }
	bool						HasCurrentElement() const			{ return (m_curelem==0)?false:true; }
	void						GotoFirstElement();
	void						GotoNextElement();
	void						GotoElement(const char * key);

	HANDLE						GetStartPosition() const			{ return (m_count==0)?NULL:(HANDLE)-1L; }
	void						GetNextElement(HANDLE & pos,std::string & key,void *&value) const;

	void						InitHashTable(unsigned long hashsize,bool allocnow=true);
	unsigned long				GetHashTableSize() const			{ return m_hashsize; }
	
private:
	CHMapStringToPtr(const CHMapStringToPtr& src);
	const CHMapStringToPtr& operator=(const CHMapStringToPtr& src);
protected:
	struct HashElement *		GetElementAt(const char * key,unsigned long & index) const;

protected:
	struct HashElement **		m_table;
	struct HashElement *		m_curelem;
	unsigned long				m_hashsize;
	int							m_count;
};

class CHMapStringToString  
{
public:
	struct HashElement
	{
		HashElement	*next;
		unsigned long index;  
		std::string key;
		std::string value;
	};

	CHMapStringToString(unsigned long hashsize=17);
	virtual ~CHMapStringToString();

	int							GetCount() const					{ return m_count; }
	bool						IsEmpty() const						{ return (m_count==0)?true:false; }

	bool						Lookup(const char * key, std::string& value) const;
	std::string&				operator[](const char * key);
	void						SetAt(const char * key, const char * value)	{ (*this)[key] = value; }

	bool						RemoveKey(const char * key);
	void						RemoveAll();

	unsigned long				HashKey(const char * key) const;

	std::string&				GetCurrentElement() const			{ return m_curelem->value; }
	bool						HasCurrentElement() const			{ return (m_curelem==0)?false:true; }
	void						GotoFirstElement();
	void						GotoNextElement();
	void						GotoElement(const char * key);

	HANDLE						GetStartPosition() const			{ return (m_count==0)?NULL:(HANDLE)-1L; }
	void						GetNextElement(HANDLE & pos,std::string & key,std::string& value) const;

	void						InitHashTable(unsigned long hashsize,bool allocnow=true);
	unsigned long				GetHashTableSize() const			{ return m_hashsize; }
	
private:
	CHMapStringToString(const CHMapStringToString& src);
	const CHMapStringToString& operator=(const CHMapStringToString& src);
protected:
	struct HashElement *		GetElementAt(const char * key,unsigned long & index) const;

protected:
	struct HashElement **		m_table;
	struct HashElement *		m_curelem;
	unsigned long				m_hashsize;
	int							m_count;
};

class CHMapPtrToPtr
{
public:
	struct HashElement
	{
		HashElement	*next;
		unsigned long index;  
		void* key;
		void* value;
	};

	CHMapPtrToPtr(unsigned long hashsize=17);
	virtual ~CHMapPtrToPtr();

	int							GetCount() const					{ return m_count; }
	bool						IsEmpty() const						{ return (m_count==0)?true:false; }

	bool						Lookup(void * key, void*& value) const;
	void*&						operator[](void * key);
	void						SetAt(void * key, void* value)		{ (*this)[key] = value; }

	bool						RemoveKey(void * key);
	void						RemoveAll();

	unsigned long				HashKey(void * key) const;

	void*&						GetCurrentElement() const			{ return m_curelem->value; }
	bool						HasCurrentElement() const			{ return (m_curelem==0)?false:true; }
	void						GotoFirstElement();
	void						GotoNextElement();
	void						GotoElement(void * key);

	HANDLE						GetStartPosition() const			{ return (m_count==0)?NULL:(HANDLE)-1L; }
	void						GetNextElement(HANDLE & pos,void *& key,void *&value) const;

	void						InitHashTable(unsigned long hashsize,bool allocnow=true);
	unsigned long				GetHashTableSize() const			{ return m_hashsize; }

private:
	CHMapPtrToPtr(const CHMapPtrToPtr & src);
	const CHMapPtrToPtr& operator=(const CHMapPtrToPtr& src);

protected:
	struct HashElement *		GetElementAt(void * key,unsigned long & index) const;

protected:
	struct HashElement **		m_table;
	struct HashElement *		m_curelem;
	unsigned long				m_hashsize;
	int							m_count;
};

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
CHMap<KEY, ARG_KEY,VALUE ,ARG_VALUE>::CHMap(unsigned long hashsize)
{
	m_hashsize		=hashsize;
	m_table			=NULL;
	m_curelem		=NULL;
	m_count			=0;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::~CHMap()
{
	RemoveAll();
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
typename CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::HashElement * 
CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::GetElementAt(ARG_KEY key,unsigned long & index) const
{
	index = HashKey<ARG_KEY>(key) % m_hashsize;

	if(m_table==NULL)
		return NULL;

	struct HashElement *e;
	e = m_table[index];

	while(e)
	{
		if (e->key == key)
			return e;
		else
			e = e->next;
	}

	return NULL;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
VALUE& CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::operator[](ARG_KEY key)
{
	unsigned long index;
	struct HashElement *e;

	if((e=GetElementAt(key,index))==NULL)
	{
		if (m_table == NULL)
			InitHashTable(m_hashsize);

		e=new struct HashElement;
		assert(e!=NULL);
		e->key=key; 
		e->index=index;
		e->next=m_table[index];
		//'e->value' is a constructed object, nothing more
		m_count++;
		m_table[index] = e;
	}

	return e->value;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
bool CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::RemoveKey(ARG_KEY key)
{
	if (m_table==NULL)
		return false;  

	struct HashElement* e;
	struct HashElement** eprev;
	eprev = &m_table[HashKey<ARG_KEY>(key) % m_hashsize];

	for (e = *eprev; e != NULL; e = e->next)
	{
		if (e->key == key)
		{
			*eprev = e->next;
			m_count--;
			delete e;
			return true;
		}
		eprev = &e->next;
	}
	return false;  
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
bool CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::Lookup(ARG_KEY key, VALUE& value) const
{
	unsigned long index;
	struct HashElement* e = GetElementAt(key, index);
	if (e == NULL)
		return false;  

	value = e->value;
	return true;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::RemoveAll()
{
	if (m_table!=NULL)
	{
		for (unsigned long index = 0; index < m_hashsize; index++)
		{
			struct HashElement* e,*etmp;
			e=m_table[index];
			while(e)
			{
				etmp=e;
				e=e->next;
				delete etmp;
			}
		}

		delete [] m_table;
		m_table = NULL;
	}

	m_count = 0;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::GetNextElement(HANDLE & pos,KEY& key,VALUE&value) const
{
	struct HashElement * e = (struct HashElement *)pos;
	if (e == (HANDLE)-1L)
	{
		for(unsigned long index=0;index<m_hashsize;index++)
		{
			if((e=m_table[index])!=NULL)
				break;
		}
	}

	struct HashElement * enext;
	if ((enext = e->next) == NULL)
	{
		// go to next bucket
		for (unsigned long index= e->index + 1; index < m_hashsize; index++)
		{
			if ((enext = m_table[index]) != NULL)
				break;
		}
	}

	pos = (HANDLE) enext;

	key = e->key;
	value = e->value;	
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::InitHashTable(unsigned long hashsize,bool allocnow)
{
/*	if (m_table != NULL)
	{
		delete[] m_table;
		m_table = NULL;
	}*/
	RemoveAll();

	if (allocnow)
	{
		m_table = new struct HashElement * [hashsize];
		assert(m_table!=NULL);
		memset(m_table, 0, sizeof(struct HashElement *) * hashsize);
	}
	m_hashsize = hashsize;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::GotoFirstElement()
{
	m_curelem=NULL;
	if(m_count==0)
		return;

	for(unsigned long index=0;index<m_hashsize;index++)
	{
		if((m_curelem=m_table[index])!=NULL)
			break;
	}
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::GotoNextElement()
{
	if(m_curelem==NULL)
		return;

	struct HashElement * enext;
	if ((enext = m_curelem->next) == NULL)
	{
		for (unsigned long index= m_curelem->index + 1; index < m_hashsize; index++)
		{
			if ((enext = m_table[index]) != NULL)
				break;
		}
	}

	m_curelem=enext;
}

template<class KEY, class ARG_KEY, class VALUE ,class ARG_VALUE>
void CHMap<KEY, ARG_KEY, VALUE ,ARG_VALUE>::GotoElement(ARG_KEY key)
{
	unsigned long index;
	m_curelem = GetElementAt(key, index);
}

}//namespace HDSOFT
#endif
