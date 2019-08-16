
#ifndef __HCOMM_H__
#define __HCOMM_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string>
#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
#endif
#include "hdefines.h"

namespace HDSOFT
{
int					__h_isdigit(int c);
int					__h_isalpha(int c);
int					__h_isalnum(int c);
int					__h_isxdigit(int c);
int					__h_isspace(int c);
int					__h_isblank(int c);
int					__h_islower(int c);
int					__h_isupper(int c);
int					__h_tolower(int c);
int					__h_toupper(int c);

int					__h_rand(unsigned int * seedp);
unsigned char		__h_random_8();
unsigned short		__h_random_16();
unsigned long		__h_random_32();

void				__h_printf(const char * format,...);
void				__h_usleep(unsigned long microsec);
void				__h_sleep(unsigned long millisec);
unsigned long		__h_get_tick_count();				//Millisecond
ULONGLONG			__h_get_tick_count_64();			//Microsecond
time_t				__h_mktime(struct tm *timeptr);
bool				__h_localtime(const time_t *timep,struct tm *result);
int					__h_parse_date(const char * datestr,int type,struct tm & t);
int					__h_parse_date2(const char * datestr,int type,struct tm & t,int & millsec);

long				__h_to_next_token(std::string & str,const char * buf,unsigned long buflen,char splitchar);
std::string			__h_get_self_module_path();			//Return directory path with no file separator at the end

}//namespace HDSOFT

#endif
