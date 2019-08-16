
#ifndef __HCHARSET_H__
#define __HCHARSET_H__

namespace HDSOFT
{

enum{
	H_CHARSET_ASCII,
	H_CHARSET_UTF8,
	H_CHARSET_GB2312,
	H_CHARSET_UNICODE,			//utf16
};

class CHCharSet
{
private:
	CHCharSet();

public:
	//return :H_CHARSET_XXXX
	static unsigned long			GetStringCharSet(const char * str);

	static std::string				ConvertToGB2312(const char * src);
	static std::string				ConvertToUTF8(const char * src);
	static bool						ConvertToGB2312Ex(const char * src,std::string & dst,bool use_replease);
	static bool						ConvertToUTF8Ex(const char * src,std::string & dst,bool use_replease);

};

}//namespace HDSOFT

#endif
