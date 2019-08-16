
#ifndef __HLOG_H__
#define __HLOG_H__

#include <stdio.h>
#include <stdarg.h>
#include "base/hmap.h"
#include "base/hmutex.h"
#include "base/hdatetime.h"

#ifdef __FUNCTION__
#define HD_LOG	CHLogLibOut(__FILE__,__FUNCTION__,__LINE__).Out
#else
#define HD_LOG	CHLogLibOut(__FILE__,"",__LINE__).Out
#endif


namespace HDSOFT
{
#define	HLOG_FF_ALWAYS_OPEN			1
#define HLOG_FF_SPLIT_DATE			0x10
#define HLOG_FF_SPLIT_SIZE			0x20

enum 
{ 
	HLOG_LEVEL_DEBUG	=10,
	HLOG_LEVEL_INFO		=20,
	HLOG_LEVEL_WARING	=30,
	HLOG_LEVEL_ERROR	=40,
};

enum
{
	HLOG_OUT_NONE		=0,
	HLOG_OUT_PRINT		=1,
	HLOG_OUT_FILE		=2,
};

class CHLog
{
public:
	CHLog();
	CHLog(unsigned long level,int showmode);
	virtual ~CHLog();

	///*----------------------------------------------------------
	///*Set the prefix and suffix of the log file name, and the actual file will be append "_YYYYMMDD".
	///*----------------------------------------------------------
	void					SetLogFileName(const char * filename,const char * postfix=NULL);
	
	///*----------------------------------------------------------
	///*Write a log. If level<m_level, it will do nothing. 
	///*----------------------------------------------------------
	void					Write(unsigned long level,const char * format,...);
	void					VWrite(unsigned long level,const char * format,va_list ap);
	void					WriteEx(const char * title,unsigned long level,const char * format,...);
	void					VWriteEx(const char * title,unsigned long level,const char * format,va_list ap);

	///*----------------------------------------------------------
	///*When a certain level is added to the blacklist, it will not be processed if it is added to the blacklist, 
	///*even if it is in the whitelist at the same time. 
	///*----------------------------------------------------------
	void					AddtoBlack(unsigned long level);

	///*----------------------------------------------------------
	///*Adding a certain level to the whitelist will always be processed with in the whitelist(not in blacklist).
	///*----------------------------------------------------------
	void					AddtoWhite(unsigned long level);

	///*----------------------------------------------------------
	///*Remove a level from the blacklist. 
	///*----------------------------------------------------------
	void					RemoveBlack(unsigned long level);

	///*----------------------------------------------------------
	///*Remove a level from the whitelist. 
	///*----------------------------------------------------------
	void					RemoveWhite(unsigned long level);

	///*----------------------------------------------------------
	///*Clear the blacklist
	///*----------------------------------------------------------
	void					ClearBlack();

	///*----------------------------------------------------------
	///*Clear the whitelist
	///*----------------------------------------------------------
	void					ClearWhite();

	///*----------------------------------------------------------
	///*Whether the level is on the blacklist.
	///*----------------------------------------------------------
	bool					IsInBlack(unsigned long level);

	///*----------------------------------------------------------
	///*Whether the level is on the whitelist.
	///*----------------------------------------------------------
	bool					IsInWhite(unsigned long level);
protected:
	bool					OpenFile(const CHDateTime & dt,FILE * & fe);
	bool					CompareLevel(unsigned long level);
public:
	unsigned long			m_level;			//log level(default 0):0 means all, -1 means not anyone
	unsigned long			m_writelevel;		//write level(default 0),The first step is to pass m_level and then further compare m_writelevel.
	int						m_showmode;			//show mode(default 1):0-none£¬1-print£¬2-file£¬3-both
	int						m_filemode;			//file mode(default 0x10):0- opens instantly, 1- always opens, 0x10- is divided by date, 0x20- fixed size
	bool					m_affix;			//Output prefix(default true)£ºfalse-no output£¬true-output(date and time information is added before log information)
	bool					m_autolf;			//Automatic transfer (default true)
	unsigned long			m_maxsize;			//max size(defaulr 500k)£¬it is valid when filemode & 0x20
protected:
	std::string				m_filename;
	std::string				m_postfix;			//Suffix
	FILE *					m_fe;
	CHMutex					m_mublack;
	CHMutex					m_muwhite;
	CHMutex					m_muwrite;
	CHDateTime				m_opendt;
	CHMap<unsigned long,unsigned long,unsigned long,unsigned long>	m_black;
	CHMap<unsigned long,unsigned long,unsigned long,unsigned long>	m_white;
};

class CHLogLibOut
{
public:
	CHLogLibOut(const char * srcname,const char * function,int line);
	virtual ~CHLogLibOut();
	void					Out(const char * title,unsigned long level,const char * format,...);

	static void				SetFileAttr(const char * logfilename,const char * logpostfix);
	static void				SetShowAttr(int showmode);
	static void				SetLevel(int level,int writelevel);
protected:
	std::string				m_srcname;
	std::string				m_function;
	int						m_line;
};

}//namespace HDSOFT
#endif

