
#ifndef __HSTRING_H__
#define __HSTRING_H__

#include <vector>
#include <string>
#include <stdarg.h>
#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif
#include "hdefines.h"

namespace HDSOFT
{

class CHString
{
private:
	CHString();
public:
	static std::string			VFormat(const char * lpszFormat, va_list argList);
	static std::string			Format(const char * lpszFormat,...);

	static int					stricmp(const char * s1,const char * s2);
	static int					strnicmp(const char *s1, const char *s2, size_t n);
	static char *				strnstr(const char * str,size_t count,char * needle);
	static char *				strncpy(char *dest, const char *src, size_t count);
	
	static void					Trim(std::string & str);
	static void					TrimLeft(std::string & str);
	static void					TrimRight(std::string & str);
	static std::string			ToLower(const char * str);
	static std::string			ToUpper(const char * str);
	static std::string			Replace(const char * src,const char * oldstr,const char * newstr);
	static void					Split(std::string src,const char * splitchar,std::vector<std::string> & val);
	static void					SplitOf(std::string src,const char * splitchar,std::vector<std::string> & val);


	//------------------------------------
	//String conversion to number
	//[whitespace] [{+ | ¨C}] [0 [{ x | X }]] [digits]
	static int					StringToInt(const char * str,int base=10);
	static unsigned int			StringToUInt(const char * str,int base=10);
	static LONGLONG				StringToInt64(const char * str,int base=10);
	static ULONGLONG			StringToUInt64(const char * str,int base=10);
	static unsigned int			IgnoreLeftZeroStringToUInt(const char * str,size_t len);

	//[whitespace] [sign] [digits] [.digits] [ {d | D | e | E}[sign]digits]
	static float				StringToFloat(const char * str);
	static double				StringToDouble(const char * str);

	//------------------------------------
	//number conversion to string
	static std::string			IntToString(int val);
	static std::string			UIntToString(int val);
	static std::string			UIntToHexString(int val,bool lowercase=true);
	static std::string			Int64ToString(LONGLONG val);
	static std::string			UInt64ToString(ULONGLONG val);
	static std::string			UInt64ToHexString(ULONGLONG val,bool lowercase=true);
	static std::string			FloatToString(float val,unsigned int decimals);
	static std::string			DoubleToString(double val,unsigned int decimals);

	//*----------------------------------
	//*Convert memory into a hex string.
	//*buf     - buffer pointer
	//*bufsize - buffer size
	//*----------------------------------
	static std::string			ByteToHexString(const unsigned char * buf,size_t bufsize,bool lowercase=true);

	//*----------------------------------
	//*Convert the hex string string into memory.
	//*recvbuf    - buffer pointer
	//*maxbufsize - buffer size
	//*return	  - The length of the actual content
	//*----------------------------------
	static size_t				HexStringToByte(const char * str,unsigned char * recvbuf,size_t maxbufsize);		
};

}//namespace HDSOFT

#endif
