#ifndef __HDEFINES_H__
#define __HDEFINES_H__


#if defined(_WIN32)
//windows
	#define HDSTDCALL								__stdcall
	#define TYPE_SOCKADDRLEN						int			
	typedef char									TYPE_OPTVAL;
	#define MAXLISTENNUM							SOMAXCONN
	#define __PACKED
	#define	DIR_SEPARATOR_CHAR						'\\'
	#define	DIR_SEPARATOR_STR						"\\"
	typedef void *									HANDLE;	
#else
//linux
	#define HDSTDCALL
	#define TYPE_SOCKADDRLEN						socklen_t			
	typedef void									TYPE_OPTVAL;
	#define MAXLISTENNUM							128
	#define __PACKED								__attribute__((packed, aligned(1)))
	#define	DIR_SEPARATOR_CHAR						'/'
	#define	DIR_SEPARATOR_STR						"/"
	#define SSIZE_T									ssize_t

	typedef int										SOCKET;	
	typedef const char *							LPCTSTR;
	typedef const char *							LPCSTR;
	typedef unsigned int							DWORD;
	typedef int										BOOL;
	typedef unsigned char							BYTE;
	typedef unsigned short							WORD; 
	typedef void *									HANDLE;	
	typedef long long								LONGLONG;
	typedef unsigned long long						ULONGLONG;

	#ifndef FALSE
	#define FALSE									0
	#endif
	#ifndef TRUE
	#define TRUE									1
	#endif

	#define closesocket								close
	#define ioctlsocket								ioctl
	#define INVALID_SOCKET							(-1)
	#define MAX_PATH								260
	#define MAKEWORD(a, b)							((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))
	#define MAKELONG(a, b)							((int)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))
	#define LOWORD(l)								((WORD)(l))
	#define HIWORD(l)								((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
	#define LOBYTE(w)								((BYTE)(w))
	#define HIBYTE(w)								((BYTE)(((WORD)(w) >> 8) & 0xFF))

	#define MAKEENDIAN(a,b)							((BYTE)(((BYTE)(a) & 0x0F) | ((BYTE)(b) & 0x0F)<<4))
	#define LOENDIAN(b)								((BYTE)(b) & 0x0F)
	#define HIENDIAN(b)								((BYTE)(((BYTE)(b) & 0xF0)>>4)) 
#endif

#define H_ROUND_UP(size, align) (((size) + ((align) - 1)) & ~((align) - 1))
#define H_ROUND_DOWN(size, align) ((size) & ~((align) - 1))

#define HDSAFEDELETE(a)	\
do{ \
	try{ \
		if(a) \
			delete a; \
		a=NULL; \
	}catch(...) { } \
}while(0)

#define HDSAFEDELETEMAB(a) \
do{ \
	try{ \
		if(a) \
			delete [] a; \
		a=NULL; \
	}catch(...) { } \
}while(0)

#define HDBILLION									1000000000
#define HMAX(a,b)									(((a) > (b)) ? (a) : (b))
#define HMIN(a,b)									(((a) < (b)) ? (a) : (b))
#define HABS(n)										(((n)<0)?-(n):(n))

#define HIN_RANGE(val,min_val,max_val)	\
do{\
	if(val<min_val) \
		val=min_val; \
	else if(val>max_val) \
		val=max_val; \
}while(0)

#define HIN_RANGE_DEF(val,min_val,max_val,def)	\
do{\
	if(val<min_val) \
		val=def; \
	else if(val>max_val) \
		val=def; \
}while(0)

/////////////////////////////////////////////////////////////////////
//time
#define _H_TIME_MAX_BUFFER_SIZE						1024
#define _H_TIME_MIN_DATE							(-657434L)  // about year 100
#define _H_TIME_MAX_DATE							2958465L    // about year 9999
#define _H_TIME_MAX_DAYS_IN_SPAN					3615897L
#define _H_TIME_HALF_SECOND							(1.0/172800.0) // Half a second, expressed in days
#define _H_TIME_HALF_MILLSECOND						(1.0/172800000.0) // Half a millisecond, expressed in days
#define _H_TIME_ERROR								(-1)
#define _H_TIME_NTPOFFSET							2208988800UL

/////////////////////////////////////////////////////////////////////
//tcp/udp
#define _H_TCP_DEFBUFFER							65536
#define _H_UDP_MAXBUFFER							65535
#define _H_UDP_PULSEINTERVAL						30000
#define _H_UDP_VER									0x0002
#define _H_UDP_STARTCODE							0x4844

#define _H_UDP_DAT									0x01
#define _H_UDP_CMD									0x02
#define _H_UDP_ACK									0x04
#define _H_UDP_BYE									0x08
#define _H_UDP_FRC									0x10
#define _H_UDP_PLE									0x20
#define _H_UDP_DATACK								0x40

#define _H_UDP_NULL_SEQUENCE						0
#define _H_UDP_NULL_ACKSEQUENCE						0
#define _H_UDP_NULL_SECTION							0
#define _H_UDP_NULL_ACKSECTION						0
#define _H_UDP_MARK									1
#define _H_UDP_NO_MARK								0
#define _H_UDP_EMPTY_PT								0
#define _H_UDP_EMPTY_IDENTITY						0
#define _H_UDP_NO_IMPORTANT							0
#define _H_UDP_IMPORTANT							1
#define _H_UDP_NO_OOB								0
#define _H_UDP_OOB									1
#define _H_UDP_ZERO_RSVD1							0
#define _H_UDP_ZERO_RSVD2							0
#define _H_DEFAULT_HASHSIZE							8317

/////////////////////////////////////////////////////////////////////
//errcode
#define _H_ERR_SUCCESS								0
#define _H_ERR_BASE									0x80008000
#define _H_ERR_FAIL									(_H_ERR_BASE+0x1)					
#define _H_ERR_OUTOFMEM								(_H_ERR_BASE+0x2)					//out of memory
#define _H_ERR_NULLPOINT							(_H_ERR_BASE+0x3)					//Empty pointer
#define _H_ERR_EXCEPT								(_H_ERR_BASE+0x4)					//has except
#define _H_ERR_NOIMPLEMENT							(_H_ERR_BASE+0x5)					//no implement
#define _H_ERR_INCOMPLETE							(_H_ERR_BASE+0x6)					//being processed, unfinished
#define _H_ERR_WAIT_TIMEOUT							(_H_ERR_BASE+0x7)					//Processing waiting timeout
#define _H_ERR_INVALID_PARAM						(_H_ERR_BASE+0x8)					//invalid parameter
#define _H_ERR_FILE_OPEN							(_H_ERR_BASE+0x9)					//File open failure
#define _H_ERR_FILE_WRITE							(_H_ERR_BASE+0xA)					//Write file failure 
#define _H_ERR_FILE_READ							(_H_ERR_BASE+0x10)					//Read file failure
#define _H_ERR_FILE_OPER							(_H_ERR_BASE+0x11)					//File operation failure 
#define _H_ERR_NOENOUGH_BUF							(_H_ERR_BASE+0x12)					//out of buffer
#define _H_ERR_VERSION								(_H_ERR_BASE+0x13)					//Version error
#define _H_ERR_VERIFY								(_H_ERR_BASE+0x14)					//Verification failure

#define _H_ERR_OBJ_NOTINIT							(_H_ERR_BASE+0x15)
#define _H_ERR_OBJ_ALREADYINIT						(_H_ERR_BASE+0x16)
#define _H_ERR_OBJ_FAIL								(_H_ERR_BASE+0x17)
#define _H_ERR_ELEMENT_ALREADYEXISTS				(_H_ERR_BASE+0x18)
#define _H_ERR_ELEMENT_NOTFOUND						(_H_ERR_BASE+0x19)
#define _H_ERR_THREAD_ALREADYRUNNING				(_H_ERR_BASE+0x1A)
#define _H_ERR_THREAD_STARTFAIL						(_H_ERR_BASE+0x1B)
#define _H_ERR_THREAD_EXCEPT						(_H_ERR_BASE+0x1C)					//thread except
#define _H_ERR_THREAD_NOTRUN						(_H_ERR_BASE+0x1D)
#define _H_ERR_THREAD_TERMINATE						(_H_ERR_BASE+0x1E)					//Thread is aborted 
#define _H_ERR_THREAD_END							(_H_ERR_BASE+0x1F)					//Thread is required to end
#define _H_ERR_POOL_NOTINIT							(_H_ERR_BASE+0x20)
#define _H_ERR_POOL_ALREADYINIT						(_H_ERR_BASE+0x21)
#define _H_ERR_CYCLE_NOTINIT						(_H_ERR_BASE+0x22)
#define _H_ERR_CYCLE_ALREADYINIT					(_H_ERR_BASE+0x23)
#define _H_ERR_CYCLE_BUFSIZETOOSMALL				(_H_ERR_BASE+0x24)
#define _H_ERR_CYCLE_BUFSIZETOOBIG					(_H_ERR_BASE+0x25)
#define _H_ERR_CYCLE_INDEXNOTFOUND					(_H_ERR_BASE+0x26)

#define _H_ERR_SOCKET_CREATE						(_H_ERR_BASE+0x65)					//create socket fail
#define _H_ERR_SOCKET_FAIL							(_H_ERR_BASE+0x66)					//Failure of socket operation
#define _H_ERR_SOCKET_SENDTIMEOUT					(_H_ERR_BASE+0x67)					//Sending data timeout 
#define _H_ERR_SOCKET_SENDTIMEOUT_FIRST				(_H_ERR_BASE+0x68)					//Sending data timeout (no data is sent) 
#define _H_ERR_SOCKET_SENDFAIL						(_H_ERR_BASE+0x69)					//Failure to send data
#define _H_ERR_SOCKET_CANTBIND						(_H_ERR_BASE+0x6A)					//Bindings failure 
#define _H_ERR_SOCKET_CANTLISTEN					(_H_ERR_BASE+0x6B)					//Fail to Listen

#define _H_ERR_TCP_NOTCONNECT						(_H_ERR_BASE+0x6F)
#define _H_ERR_TCP_ALREADYCONNECTED					(_H_ERR_BASE+0x70)
#define _H_ERR_TCP_CONNECTFAIL						(_H_ERR_BASE+0x71)
#define _H_ERR_TCP_CONNECTTIMEOUT					(_H_ERR_BASE+0x72)
#define _H_ERR_TCP_DISCONNECT						(_H_ERR_BASE+0x73)
#define _H_ERR_TCP_ALREADYSTARTSERVER				(_H_ERR_BASE+0x74)
#define _H_ERR_TCP_SOURCENOTINIT					(_H_ERR_BASE+0x75)
#define _H_ERR_TCP_SOURCEALREADYINIT				(_H_ERR_BASE+0x76)
#define _H_ERR_TCP_NOTSUPPORTKEEPALIVE				(_H_ERR_BASE+0x77)

#define _H_ERR_UDP_TRANS_ALREADYCREATED				(_H_ERR_BASE+0x79)
#define _H_ERR_UDP_TRANS_NOTCREATED					(_H_ERR_BASE+0x7A)
#define _H_ERR_UDP_TRANS_NOTAMULTICASTADDR			(_H_ERR_BASE+0x7B)
#define _H_ERR_UDP_TRANS_COULDNTJOINMULTICASTGROUP	(_H_ERR_BASE+0x7C)
#define _H_ERR_UDP_TRANS_SPECIFIEDSIZETOOSMALL		(_H_ERR_BASE+0x7D)
#define _H_ERR_UDP_TRANS_SPECIFIEDSIZETOOBIG		(_H_ERR_BASE+0x7E)
#define _H_ERR_UDP_SESSION_NOTCREATED				(_H_ERR_BASE+0x7F)
#define _H_ERR_UDP_SESSION_ALREADYCREATED			(_H_ERR_BASE+0x80)
#define _H_ERR_UDP_SESSION_USINGPOLLTHREAD			(_H_ERR_BASE+0x81)
#define _H_ERR_UDP_SOURCE_RESENDOVERFLOW			(_H_ERR_BASE+0x82)

#define _H_ERR_FTP_LOGIN							(_H_ERR_BASE+0x8D)
#define _H_ERR_FTP_USERNAME							(_H_ERR_BASE+0x8E)
#define _H_ERR_FTP_PASSWORD							(_H_ERR_BASE+0x8F)
#define _H_ERR_FTP_FAIL								(_H_ERR_BASE+0x90)

#define _H_ERR_SMTP_FAIL							(_H_ERR_BASE+0x97)
#define _H_ERR_SMTP_CONN							(_H_ERR_BASE+0x98)
#define _H_ERR_SMTP_AUTH							(_H_ERR_BASE+0x99)
#define _H_ERR_SMTP_HEAD							(_H_ERR_BASE+0x9A)
#define _H_ERR_SMTP_BODY							(_H_ERR_BASE+0x9B)
#define _H_ERR_SMTP_SSL								(_H_ERR_BASE+0x9C)

#define _H_ERR_DDNS_FAIL							(_H_ERR_BASE+0xA1)
#define _H_ERR_DDNS_SHUTDOWN						(_H_ERR_BASE+0xA2)

#define _H_ERR_HTTP_FAIL							(_H_ERR_BASE+0xB1)
#define _H_ERR_HTTP_NOTINIT							(_H_ERR_BASE+0xB2)

#define _H_ERR_BUFFER_OVER							(_H_ERR_BASE+0x100)
#define _H_ERR_NOT_ENOUGHRESOURCE					(_H_ERR_BASE+0x101)
#define _H_ERR_STATUS								(_H_ERR_BASE+0x102)
#define _H_ERR_OPERATION							(_H_ERR_BASE+0x103)
#define _H_ERR_FORMAT								(_H_ERR_BASE+0x104)

#define _H_ERR_APP_BASE								(_H_ERR_BASE+0xF00)
#endif

