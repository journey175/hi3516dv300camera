
#ifndef __NSD_DEFINES_H
#define __NSD_DEFINES_H

#if defined(_WIN32)
	#define PACKED
	#pragma pack(push)	
	#pragma pack(1)										//1 byte alignment
#else
#define PACKED							__attribute__((packed, aligned(1)))
#endif

////////////////////////////////////////////////
// Constant definition
#define MAX_VIDEO_NUM					32				// The maximum number of video channels
#define MAX_AUDIO_NUM					MAX_VIDEO_NUM	// The maximum number of audio channels
#define MAX_STREAM_NUM					6				// The maximum number of stream
#define MAX_UART_NUM					8				// The maximum number of serial ports
#define MAX_DI_NUM						8				// The maximum number of DI
#define	MAX_DO_NUM						8				// The maximum DO number
#define MAX_USER_NUM					10				// The maximum number of users
#define MAX_USER_GROUP_NUM				3				// The maximum number of user groups
#define MAX_MASK_AREA_NUM				8				// The maximum number of video shields
#define MAX_FISHEYE_WIN_NUM				4				// The maximum number of fisheye correction display window
#define MAX_PRESET_NUM					255				// The maximum number of preset
#define MAX_TOUR_NUM					8				// The maximum number of tour
#define MAX_TOUR_POINT_NUM				32				// The maximum number of tour point
#define MAX_TRACK_NUM					8				// The maximum number of track
#define MAX_TRACK_CMD_COUNT				128				// The maximum number of track record
#define MAX_TRACK_TIMES					(10*60000)		// The maximum track record time (milliseconds)
#define MAX_VOUT_NUM					1				// The maximum number of video out
#define MAX_ISP_PROFILE_NUM				2				
#define MAX_ACTION_NUM					64
#define MAX_SEGMENT_NUM					24				// The maximum number of planned time
#define MAX_ROI_NUM						8
#define MAX_SCHEME_NUM					8				// The maximum number of planned tasks
#define MAX_IP_FILTER_NUM				32				// The maximum number of IP filter
#define MAX_MAC_FILTER_NUM				32				// The maximum number of MAC filter
#define MAX_FTP_NUM						1				
#define MAX_SMTP_NUM					1				
#define MAX_INNER_VI_NUM				16				//最大内部通道数
#define MAX_IRC_NUM						16
#define MAX_USER_CONF_NUM				16
#define MAX_EXTIO_NUM                   10
#define MAX_MODULE_RESPONSE_MSG_SIZE	(64*1024)
#define MAX_JPG_ENCODER_NUM             2

#define NAME_LEN_16						16
#define NAME_LEN_24						24
#define NAME_LEN_32						32
#define NAME_LEN_48						48
#define NAME_LEN_64						64
#define PATH_LEN						128
#define PATH_LEN_200					200
#define LONG_PATH_LEN					256
#define DATA_LEN						512
#define LONG_DATA_LEN					1024

#define MD_ROW_NUM						18				//Motion detection macro block row number
#define MD_COL_NUM						22				//Motion detection macro block column number

#define MAC_ADDR_LEN 					6

#define FE_MAGIC_FLAG					0x7468
#define NSDERR_BASE						0x80008F00
#define SNAP_MAGIC_FLAG					0x7470

#define MAX_AUTO_TRACK_NUM              1
#define MAX_SCREEN_NUM                  1

///////////////////////////////////////////////////////
//Enumeration definition
//error code
typedef enum _NSD_ERRCODE_E
{
	NSDERR_SUCCESS=0,					//Success(0)
	NSDERR_FAIL=NSDERR_BASE+1,			//Execution failed (0x80008F01)
	NSDERR_OUTOFMEM,					//Failed to allocate memory
	NSDERR_NOIMPLEMENT,					//The server is not implemented
	
	NSDERR_CONNECT,						//Connection failed
	NSDERR_SEND,						//Failed to send data
	NSDERR_TIMEOUT,						//Timeout
	NSDERR_TRANS,						//Transmission error

	NSDERR_INVALID_PARAM,				//Invalid parameters
	NSDERR_REFUSE,						//Refusing to request
	NSDERR_MAXTASK,						//Exceed the maximum task
	NSDERR_USER_PWD,					//ERROR Incorrect username or password
	NSDERR_LOW_PRIORITY,				//Lack of access rights
	NSDERR_RESTRICT_ID,					//Access to ID Limited
	NSDERR_EXCEPT,						//Abnormal operation
	NSDERR_PARSE,						//Parsing error
	NSDERR_FILE,						//File open failed
	NSDERR_NOENOUGH_BUF,				//Insufficient buffer
	NSDERR_FILE_READ,					//Read file failure
	NSDERR_FILE_WRITE,					//Write file failure
	NSDERR_FILE_FORMAT,					//File format is incorrect
	
	NSDERR_PROTO=NSDERR_BASE+100,		//Protocol error
	NSDERR_UNKNOW,						//Server unknown error
	NSDERR_NOT_CONNECT,					//Not yet connected
	NSDERR_NOT_LOGON,					//Not yet logged in
	NSDERR_BUSY,						//Server busy
	NSDERR_NOT_SUPPORT,					//System does not support
	NSDERR_INNER,						//Internal error
	NSDERR_OPERATING,					//The same operation is being carried out
	NSDERR_DIR,							//Directory does not exist
	NSDERR_NULLPOINT,					//Empty pointer
	NSDERR_DISCONNECT,					//Connection disconnection

	NSDERR_UPDATE_FORMAT=NSDERR_BASE+200,//Upgrade file format error
	NSDERR_UPDATE_HWPLATFORM,			 //Platform information mismatch
	NSDERR_UPDATE_ODM,					 //ODM information mismatch
	NSDERR_UPDATE_WRITE,				 //Upgrade write failure
	NSDERR_UPDATE_COPY,					 //Upgrade copy failure	
}NSD_ERRCODE_E;

// configuration type
typedef enum _NSD_CONFIG_TYPE_E
{
	NSDCFG_SYS,							// System information
	NSDCFG_DEVICE,						// Device Information
	NSDCFG_TIME,						// Date time
	NSDCFG_VIDEO,						// Video settings
	NSDCFG_AUDIO,						// Audio settings
	NSDCFG_VMOTION,						// Motion detection settings
	NSDCFG_DI,							// Digital input settings
	NSDCFG_NET,							// Network service settings
	NSDCFG_USER,						// User settings
	NSDCFG_UART,						// Serial port settings
	NSDCFG_OSD,							// OSD settings 
	NSDCFG_PTZ,							// PTZ settings
	NSDCFG_PPPOE,						// PPPOE settings
	NSDCFG_DDNS,						// DDNS settings
	NSDCFG_ETH,							// Network settings
	NSDCFG_NTP,							// NTP settings
	NSDCFG_UPNP,						// UPNP settings
	NSDCFG_FTP,							// FTP settings
	NSDCFG_SMTP,						// SMTP settings
	NSDCFG_VMASK,						// Video Mask Settings
	NSDCFG_IMG,							// Image parameter setting
	NSDCFG_DO,							// Digital output settings
	NSDCFG_VOUT,						// Video out settings
	NSDCFG_AWB,							// White balance settings
	NSDCFG_AE,							// Exposure settings
	NSDCFG_AF,							// Focus settings
	NSDCFG_ISP,							// ISP settings
	NSDCFG_PLATFORM,					// Access protocol parameter setting
	NSDCFG_RTSP,						// RTSP settings
	NSDCFG_WIFI,						// WIFI settings
	NSDCFG_ROI,
	NSDCFG_ACTION,						// Linkage action 
	NSDCFG_USERGROUP,					// User group settings
	NSDCFG_SCHEME,						// Scheduled tasks
	NSDCFG_FILTER,						// Blacklist settings
	NSDCFG_FISHEYE,
	NSDCFG_AI_FACE,						// Face detection settings
	NSDCFG_AI_PLATE_NUMBER,				// License plate recognition settings
	NSDCFG_AI_OBJECT,					// Target tracking settings
	NSDCFG_8021X,						// 802.1x settings
	NSDCFG_SNMP,						// SNMP settings
	NSDCFG_RTP,							// RTP settings
	NSDCFG_AI,							// AI module running parameters
	NSDCFG_PANO,						// Pano settings
	NSDCFG_PRIVATE_DATA,				// private data
	NSDCFG_AI_PERIMETER,				// perimeter alarm
	NSDCFG_AI_TRIPWIRE,					// tripwire alarm
	NSDCFG_AVS,							// front pano settings
	NSDCFG_AI_VIDEOLOST,				// video lost detection param
	NSDCFG_AI_FIREDETECT,				// fire detection param
	NSDCFG_AI_OCCLUSION,				// occlusion detection param
	NSDCFG_HEARTBEAT,					// heartbeat param
	NSDCFG_USERCONF,					// user configuration param
    NSDCFG_AUTOTRACK,                   // tiantong auto track param
    NSDCFG_SCREEN,
    NSDCFG_FACEBEHAVIOUR,
    NSDCFG_WIEGAND,
    NSDCFG_HTTP,
    NSDCFG_RELAYDOOR,
	NSDCFG_MAX=0x9000,
}NSD_CONFIG_TYPE_E;

// PTZ control
typedef enum _NSD_PTZCTL_TYPE_E
{
	NSDPTZ_UP 				= 0,	// PTZ top 	(data2: speed)
	NSDPTZ_DOWN,					// PTZ down (data2: speed)
	NSDPTZ_LEFT,					// PTZ left (data1: speed)
	NSDPTZ_RIGHT,					// PTZ right (data1: speed)
	NSDPTZ_LEFT_UP,					// PTZ left (data1, data2: speed)
	NSDPTZ_LEFT_DOWN,				// PTZ left (data1, data2: speed)
	NSDPTZ_RIGHT_UP,				// PTZ top right (data1, data2: speed)
	NSDPTZ_RIGHT_DOWN,				// PTZ right lower (data1, data2: speed)
	NSDPTZ_FOCUSADD,				// focus + (near)
	NSDPTZ_FOCUSSUB,				// Focus - (far)
	NSDPTZ_IRISADD,					// aperture + (open)
	NSDPTZ_IRISSUB,					// aperture - (close)
	NSDPTZ_ZOOMADD,					// Zoom telephoto (tele)
	NSDPTZ_ZOOMSUB,					// Zoom - (wide) wide angle
	NSDPTZ_STOP,					// stop
	NSDPTZ_AUTOOPEN,				// Auto scan on
	NSDPTZ_AUTOCLOSE,				// Auto-scan off
	NSDPTZ_LAMPOPEN,				// light on (Auxiliary bit 1)
	NSDPTZ_LAMPCLOSE,				// light off
	NSDPTZ_BRUSHOPEN,				// Wiper On (Auxiliary Bit 2)
	NSDPTZ_BRUSHCLOSE,				// Wiper Off
	NSDPTZ_WATEROPEN,				// Water is on (Auxiliary Bit 3)
	NSDPTZ_WATERCLOSE,				// Turn off water
	NSDPTZ_SET_PRESET,				// preset x number (data2 preset bit)
	NSDPTZ_CALL_PRESET,				// Call x (data2 preset)
	NSDPTZ_CLEAR_PRESET,			// clear preset (data2 preset)
	NSDPTZ_FLIP,					// flip 180
	NSDPTZ_ZEROPAN,					// Zero self-test
	NSDPTZ_RESET,					// Reset
	NSDPTZ_TOUR_RUN,				// Preset tour (data1 tour number)
	NSDPTZ_TOUR_STOP,				// stop patrol (data1 patrol number)
	NSDPTZ_SET_PT_POSITION,
	NSDPTZ_SET_ZOOM_POSITION,
	NSDPTZ_SET_ZOOM_MULTI,

	NSDPTZ_UP_LIMIT 		= 100, 	// upper limit bit
	NSDPTZ_DOWN_LIMIT,				// lower limit bit
	NSDPTZ_LEFT_LIMIT,				// left limit
	NSDPTZ_RIGHT_LIMIT, 			// right limit
	NSDPTZ_TOUR_INSERT, 			// insert preset to patrol (no use)
	NSDPTZ_TOUR_DELETE, 			// Remove preset from tour (no use)
	NSDPTZ_TRACK_REC,				// start recording track (data1 track number)
	NSDPTZ_TRACK_SAVE,				// stop recording track (data1 track number)
	NSDPTZ_TRACK_RUN,				// Running track (data1 track number)
	NSDPTZ_TRACK_STOP,				// stop track (data1 track number)
	NSDPTZ_SET_PAN_POS,				// value = 110
	NSDPTZ_SET_TILT_POS,

	NSDPTZ_UP_LIMIT_CLEAR,
	NSDPTZ_DOWN_LIMIT_CLEAR,				
	NSDPTZ_LEFT_LIMIT_CLEAR,				
	NSDPTZ_RIGHT_LIMIT_CLEAR,			

	NSDPTZ_MAX,
}NSD_PTZCTL_TYPE_E;

typedef enum _NSD_VIDEO_SYSTEM_TYPE_E
{
	NSD_VIDEO_PAL			=1,
	NSD_VIDEO_NTSC,
}NSD_VIDEO_SYSTEM_TYPE_E;

typedef enum _NSD_RIGHT_TYPE_E
{
	NSD_RIGHT_PREVIEW		=0x1,
	NSD_RIGHT_PTZ			=0x2,
	NSD_RIGHT_MANAGE		=0x4,
	NSD_RIGHT_CONFIG		=0x8,
}NSD_RIGHT_TYPE_E;

typedef enum _NSD_LANGUAGE_TYPE_E
{
	NSD_LANGUAGE_NONE,
	NSD_LANGUAGE_CHINESE,				// Chinese
	NSD_LANGUAGE_ENGLISH,				// English
	NSD_LANGUAGE_RUSSIAN,				// Russian
	NSD_LANGUAGE_FRENCH,				// French
	NSD_LANGUAGE_JAPANESE,				// Japanese
	NSD_LANGUAGE_GERMAN,				// German
	NSD_LANGUAGE_SPANISH,				// Spanish
	NSD_LANGUAGE_PORTUGUESE,			// Portuguese
	NSD_LANGUAGE_POLISH,				// Polish
	NSD_LANGUAGE_CHINESE_TRADITIONAL, 	// Traditional Chinese 
	NSD_LANGUAGE_PERSIAN,				// Persian
	NSD_LANGUAGE_THAI,					// Thai
	NSD_LANGUAGE_CZECH,					// Czech
	NSD_LANGUAGE_TURKISH,				// Turkish
	NSD_LANGUAGE_ITALIAN,				// Italian
	NSD_LANGUAGE_KOREAN,				// Korean
	NSD_LANGUAGE_VIETNAM,				// Vietnamese
	NSD_LANGUAGE_BULGARIAN,				// Bulgarian
}NSD_LANGUAGE_TYPE_E;

// Ability type
typedef enum _NSD_CAPABILITY_TYPE_E
{
	NSD_CAPABILITY_NONE,

	NSD_CAPABILITY_LIST_VI = 1,			// NSD_CAPABILITY_VI_S
	NSD_CAPABILITY_LIST_VENC,			// NSD_CAPABILITY_VENC_S
	NSD_CAPABILITY_LIST_RESOLUTION,		// NSD_RESOLUTION_S
	NSD_CAPABILITY_LIST_AIN_SAMPLE,		// NSD_FIXED_S
	NSD_CAPABILITY_LIST_AWB,			// NSD_FIXED_S White Balance
	NSD_CAPABILITY_LIST_AE,				// NSD_FIXED_S Exposure mode
	NSD_CAPABILITY_LIST_AENC,			// NSD_FIXED_S 
	NSD_CAPABILITY_LIST_ADEC,			// NSD_FIXED_S
	NSD_CAPABILITY_LIST_AIN_TYPE,		// NSD_FIXED_S
	NSD_CAPABILITY_LIST_SHUTTER,		// NSD_FIXED_S Shutter
	NSD_CAPABILITY_LIST_PHOTOMETRY,		// NSD_FIXED_S Metering mode
	NSD_CAPABILITY_LIST_COLOR,			// NSD_FIXED_S image color
	NSD_CAPABILITY_LIST_WDR,			// NSD_FIXED_S WDR level
	NSD_CAPABILITY_LIST_HDR,			// NSD_FIXED_S Highlight suppression
	NSD_CAPABILITY_LIST_BLC,			// NSD_FIXED_S Backlight compensation
	NSD_CAPABILITY_LIST_STABILIZE,		// NSD_FIXED_S Image is stable
	NSD_CAPABILITY_LIST_NUC_MODE,		// NSD_FIXED_S Blanking mode
	NSD_CAPABILITY_LIST_SLOW_SHUTTER,	// NSD_FIXED_S Slow shutter
	NSD_CAPABILITY_LIST_GAMMA,			// NSD_FIXED_S gamma
	NSD_CAPABILITY_LIST_IMG_PROFILE,	// NSD_FIXED_S
	NSD_CAPABILITY_LIST_ICR_MODE,		// NSD_FIXED_S
	NSD_CAPABILITY_LIST_IRIS_MODE,		// NSD_FIXED_S Auto Iris Mode
	NSD_CAPABILITY_LIST_DIS,			// NSD_FIXED_S
	NSD_CAPABILITY_LIST_LDC,			// NSD_FIXED_S
	NSD_CAPABILITY_LIST_DIGITAL_ZOOM,	// NSD_FIXED_S  
	NSD_CAPABILITY_LIST_AF,				// NSD_FIXED_S  
	NSD_CAPABILITY_LIST_WDR_TYPE,		// NSD_FIXED_S WDR type

	NSD_CAPABILITY_RANGE_VBITRATE=100,	// NSD_RANGE_S
	NSD_CAPABILITY_RANGE_FRAMERATE,		// NSD_RANGE_S
	NSD_CAPABILITY_RANGE_GOV,			// NSD_RANGE_S
	NSD_CAPABILITY_RANGE_QULITY,		// NSD_RANGE_S
	NSD_CAPABILITY_RANGE_GAIN,			// NSD_RANGE_S gain
	NSD_CAPABILITY_RANGE_SATURATION,	// NSD_RANGE_S Saturation
	NSD_CAPABILITY_RANGE_CONTRAST,		// NSD_RANGE_S Contrast
	NSD_CAPABILITY_RANGE_BRIGHTNESS,	// NSD_RANGE_S Brightness
	NSD_CAPABILITY_RANGE_SHARPNESS,		// NSD_RANGE_S Sharpness
	NSD_CAPABILITY_RANGE_NR,			// NSD_RANGE_S Noise reduction
	NSD_CAPABILITY_RANGE_DEFOG,			// NSD_RANGE_S Through fog
	NSD_CAPABILITY_RANGE_HUE,			// NSD_RANGE_S Chroma

	NSD_CAPABILITY_VALUE_MAXRESOLUTION=200,	
	NSD_CAPABILITY_VALUE_MAXPRESET,
	NSD_CAPABILITY_VALUE_MAXSCAN,
	NSD_CAPABILITY_VALUE_MAXTOUR,
	NSD_CAPABILITY_VALUE_MAXTRACK,
	NSD_CAPABILITY_VALUE_MAXGROUP,
	NSD_CAPABILITY_VALUE_MAXVIDEOMASK,
	NSD_CAPABILITY_VALUE_AI,
}NSD_CAPABILITY_TYPE_E;

typedef enum _NSD_FACE_TYPE_E
{
	NSD_FACE_NONE		    =0,
	NSD_FACE_S			    =0x0001,		//cameras
	NSD_FACE_H			    =0x0002,		//hemisphere cameras
	NSD_FACE_B			    =0x0004,		//IP Dome
	NSD_FACE_A			    =0x0008,		//Ball
	NSD_FACE_R			    =0x0010,		//Infrared cameras
	NSD_FACE_SR			    =0x0020,		//Smart infrared cameras
	NSD_FACE_T			    =0x0040,		//Thermal-imaging cameras 
	NSD_FACE_PANO		    =0x0100,		//Panoramic cameras
	NSD_FACE_PRE_PANO	    =0x0400,		//front pano cameras
	NSD_FACE_DC			    =0x1000,		//Auto-iris lens cameras
	NSD_FACE_ZOOMMODULE	    =0x2000,		//
    NSD_FACE_TIANTONG       =0x4000,		//HT eagle eye
    NSD_FACE_ENTRANCEGUARD  =0x8000,        //entrance guard cameras
}NSD_FACE_TYPE_E;

typedef enum _NSD_EXTERNAL_TYPE_E
{
	NSD_EXTERNAL_NONE,
	NSD_EXTERNAL_IVT			=0x000001,			
	NSD_EXTERNAL_HX				=0x000002,			
	NSD_EXTERNAL_SX				=0x000004,
	NSD_EXTERNAL_LK_PANO180		=0x000008,
	NSD_EXTERNAL_TUSHI			=0x000010,	
	NSD_EXTERNAL_BC				=0x000020,
	NSD_EXTERNAL_FPGA_AI		=0x010000,
	NSD_EXTERNAL_SOFT_AI		=0x020000,		
    NSD_EXTERNAL_HARD_AI_CACHE	=0x040000,		
    NSD_EXTERNAL_HARD_AI_ONLYDRAW=0x080000,		
    NSD_EXTERNAL_SOFT_AI_NOT_DRAW_ON_MAINSTREAM=0x100000,
}NSD_EXTERNAL_TYPE_E;

// network protocol type
typedef enum _NSD_PROTOCOL_TYPE_E
{
	NSD_PROTO_NONE=0,
    NSD_PROTO_TCP,							// TCP protocol
	NSD_PROTO_UDP,							// UDP protocol
	NSD_PROTO_MULTI, 						// multicast protocol
	NSD_PROTO_RTP,							// RTP protocol (reserved)
}NSD_PROTOCOL_TYPE_E;

// Record type
typedef enum _NSD_RECORD_TYPE_E
{
	NSD_REC_DI				=0x1,					// DI alarm recording
	NSD_REC_MOTION			=0x2,					// Motion detection alarm recording
	NSD_REC_VILOST			=0x4,					// Video loss alarm recording
	NSD_REC_NETBROKEN		=0x8,					// Network loss alarm recording

	NSD_REC_PLAN			=0x100,					// Plan to record
	NSD_REC_PHOTO			=0x80000000,			// Plan to capture
}NSD_RECORD_TYPE_E;

//storage method
typedef enum _NSD_SAVE_TYPE_E
{
	NSD_SAVE_NONE		= 0,
	NSD_SAVE_SD			= 0x01,				
	NSD_SAVE_FTP		= 0x02,
	NSD_SAVE_EMAIL		= 0x04,
	NSD_SAVE_HOST		= 0x08,			
	NSD_SAVE_YCCLOUD	= 0x10,
}NSD_SAVE_TYPE_E;

typedef enum _NSD_IRIS_MODE_E
{
	NSD_IRIS_MANUAL, 						// Manual
	NSD_IRIS_AUTO, 							// Automatic
} NSD_IRIS_MODE_E;

typedef enum _NSD_ACTION_TYPE_E
{
	NSD_ACTION_NONE,
	NSD_ACTION_SNAP,
	NSD_ACTION_RECORD,
	NSD_ACTION_PTZ,
	NSD_ACTION_DO,
	NSD_ACTION_REBOOT,
}NSD_ACTION_TYPE_E;

typedef enum _NSD_AUDIO_INPUT_TYPE_E
{
	NSD_AIN_TYPE_NONE,
	NSD_AIN_TYPE_MIC,
	NSD_AIN_TYPE_LINE,
}NSD_AUDIO_INPUT_TYPE_E;

typedef enum _NSD_DATESHOW_TYPE_E
{
	NSD_DATE_FORMAT1=1,							//YYYY-MM-DD hh:mm:ss ww
	NSD_DATE_FORMAT2,							//hh:mm:ss YYYY-MM-DD ww
	NSD_DATE_FORMAT3,							//MM/DD/YYYY hh:mm:ss ww
	NSD_DATE_FORMAT4,							//hh:mm:ss MM/DD/YYYY ww
	NSD_DATE_FORMAT5,							//YYYY-MM-DD hh:mm:ss
	NSD_DATE_FORMAT6,							//hh:mm:ss YYYY-MM-DD
	NSD_DATE_FORMAT7,							//MM/DD/YYYY hh:mm:ss
	NSD_DATE_FORMAT8,							//hh:mm:ss MM/DD/YYYY
}NSD_DATESHOW_TYPE_E;

//alarm type
typedef enum _NSD_ALARM_TYPE_E
{
	NSD_ALARM_MD			= 0x00000001, 		// Motion detection alarm
	NSD_ALARM_DI			= 0x00000002, 		// DI alarm
	NSD_ALARM_VILOST		= 0x00000004, 		// Video loss alarm
	NSD_ALARM_NETBROKEN		= 0x00000008, 		// network loss alarm
	NSD_ALARM_RESET			= 0x80000000,
	NSD_ALARM_PERIMETER 	= 0x00000010,		// Perimeter alarm
	NSD_ALARM_TRIPWIRE  	= 0x00000020,		// Tripwire alarm
	NSD_ALARM_FACE			= 0x00000040,		// Face detection  alarm      
	NSD_ALARM_PLATE			= 0x00000080,		// License plate detection alarm      
	NSD_ALARM_OBJECT		= 0x00000100,		// Object tracking alarm
	NSD_ALARM_OCCLUSION		= 0x00000200,		// Video Occlusion
	NSD_ALARM_FIREDETECT	= 0x00000400,		// Fire detection
}NSD_ALARM_TYPE_E;

typedef enum _NSD_VIDEO_PROFILE_E
{
	NSD_VIDEO_PROFILE_NONE,
	NSD_VIDEO_PROFILE_BASELINE,
	NSD_VIDEO_PROFILE_MAIN,
	NSD_VIDEO_PROFILE_HIGH,
}NSD_VIDEO_PROFILE_E;

typedef enum _NSD_FONT_LEVEL_E
{
	NSD_FONT_AUTO,
	NSD_FONT_LARGE,
	NSD_FONT_SMALL,
}NSD_FONT_LEVEL_E;

//video output type
typedef enum _NSD_VOUT_DEV_TYPE_E
{
	NSD_CVBS=1,
	NSD_YPBPR,
	NSD_HDMI,
	NSD_LCD,
    NSD_MIPI
}NSD_VOUT_DEV_TYPE_E;

typedef enum _NSD_VOUT_MODE_E
{
	NSD_YUV_SEMIPLANAR_422	= 0xFFF0,
	NSD_YUV_SEMIPLANAR_420	= 0xFFF1,
	NSD_YUV_420				= 0xFFF2,
	NSD_YUV_422				= 0xFFF3,
}NSD_VOUT_DEV_MODE_E;

typedef enum _NSD_ANTI_FLICKER_TYPE_E
{
	NSD_ANTI_FLICKER_NONE,
	NSD_ANTI_FLICKER_50HZ,
	NSD_ANTI_FLICKER_60HZ,
}NSD_ANTI_FLICKER_TYPE_E;

typedef enum _NSD_AE_MODE_E
{
	NSD_AE_NONE,
	NSD_AE_AUTO,					// Automatic
	NSD_AE_MANUAL,					// Manual
	NSD_AE_SHUTTER,					// shutter priority
	NSD_AE_IRIS,					// aperture priority
	NSD_AE_AGC,						// AGC is preferred
	NSD_AE_PANO,					// Panorama Master mode
}NSD_AE_MODE_E;

typedef enum _NSD_AE_METERING_TYPE_E{
	NSD_AE_METERING_AVERAGE,
	NSD_AE_METERING_CENTER,
	NSD_AE_METERING_SPOT,
	NSD_AE_METERING_CUSTOM,
}NSD_AE_METERING_TYPE_E;

typedef enum _NSD_NUC_MODE_E{
	NSD_NUC_NONE,
	NSD_NUC_AUTO,
	NSD_NUC_MANUAL
}NSD_NUC_MODE_E;

typedef enum _NSD_GAMMA_MODE_E{
	NSD_GAMMA_NONE,
	NSD_GAMMA_NORMAL,
	NSD_GAMMA_1,
	NSD_GAMMA_2,
	NSD_GAMMA_3,
	NSD_GAMMA_4,
}NSD_GAMMA_MODE_E;

typedef enum _NSD_AWB_MODE_E{
	NSD_AWB_NONE,
	NSD_AWB_AUTO,						// Automatic
	NSD_AWB_MANUAL,
	NSD_AWB_SUNNY,						// sunny 6500K
	NSD_AWB_CLOUDY,						// Cloudy 7500K
	NSD_AWB_FLUORESCENT,				// Fluorescence
	NSD_AWB_TUNGSTEN,					// Tungsten wire
	NSD_AWB_ATW,						// auto tracing (2000 to 10000K)
	NSD_AWB_INDOOR,
	NSD_AWB_OUTDOOR,
	NSD_AWB_PANO,						// Panorama master mode
}NSD_AWB_MODE_E;

typedef enum _NSD_WDR_MODE_E{
	NSD_WDR_NONE,						//discarded
	NSD_WDR_CLOSE,						//discarded
	NSD_WDR_OPEN,						//high mode
	NSD_WDR_OPEN_LOW,					//low  mode
	NSD_WDR_OPEN_MID,					//mid  mode
}NSD_WDR_MODE_E;

typedef enum _NSD_WDR_TYPE_E{
	NSD_WDR_TYPE_NONE,
	NSD_WDR_TYPE_DIGITAL,
	NSD_WDR_TYPE_2FRAME,
	NSD_WDR_TYPE_3FRAME,
	NSD_WDR_TYPE_4FRAME,
}NSD_WDR_TYPE_E;

typedef enum _NSD_OFFON_STATUS_E
{
	NSD_OFF=0,
	NSD_ON,
}NSD_OFFON_STATUS_E;

typedef enum _NSD_IMG_PROFILE_E{
	NSD_IMG_PROFILE_AUTO=0,
	NSD_IMG_PROFILE_DAY,							
	NSD_IMG_PROFILE_NIGHT,							
}NSD_IMG_PROFILE_E;

typedef enum _NSD_ICR_MODE_E{
	NSD_ICR_NONE,
	NSD_ICR_ACTIVE,
	NSD_ICR_PASSIVE,
	NSD_ICR_SCHEDULE,
}NSD_ICR_MODE_E;

typedef enum _NSD_COLOR_TYPE_E{
	NSD_COLOR_NONE,
	NSD_COLOR,								// color image
	NSD_BLACKWHITE,							// black and white image
	NSD_PSEUDO_COLOR_WHILTE_HOT,			// pseudo color
	NSD_PSEUDO_COLOR_IRON_RED,
	NSD_PSEUDO_COLOR_GREED_RED,
	NSD_PSEUDO_COLOR_LIGHT_GREEN_RED,
	NSD_PSEUDO_COLOR_BLUE_YELLOW,
	NSD_PSEUDO_COLOR_LIGHT_BLUE_YELLOW,
	NSD_PSEUDO_COLOR_BLUE_GREEN,
	NSD_PSEUDO_COLOR_BLACK_HOT,
}NSD_COLOR_TYPE_E;

typedef enum _NSD_MIRROR_MODE_E{
	NSD_MIRROR_NONE,
	NSD_MIRROR_HORI,
	NSD_MIRROR_VERT,
	NSD_MIRROR_BOTH,
}NSD_MIRROR_MODE_E;

typedef enum _NSD_ROTATE_MODE_E{
	NSD_ROTATE_NONE,
	NSD_ROTATE_90,
	NSD_ROTATE_180,
	NSD_ROTATE_270,
}NSD_ROTATE_MODE_E;

typedef enum _NSD_LENS_TYPE_E{
	NSD_LENS_NONE,
	NSD_LENS_FORECAM_3_10D5,				//forecam 3-10.5
	NSD_LENS_FORECAM_7_22,					//forecam 7-22
	NSD_LENS_YUTONG_2D8_12,					//yutong 2.8-12
	NSD_LENS_FORECAM_2D8_12,
	NSD_LENS_FORECAM_3D3_10D5,
	NSD_LENS_FORECAM_9_22,
	NSD_LENS_2G,
	NSD_LENS_FORECAM_3D6_10,
	NSD_LENS_FORECAM_CHANGLONG_2D8_12,
	NSD_LENS_YUTONG_2D8_8,
	NSD_LENS_YUTONG_3D6_11,
	NSD_LENS_YUTONG_2D7_135,

    NSD_LENS_FORECAM_3_10D5_NOAF = 51,				//forecam 3-10.5
    NSD_LENS_FORECAM_7_22_NOAF,					//forecam 7-22
    NSD_LENS_YUTONG_2D8_12_NOAF,					//yutong 2.8-12
    NSD_LENS_FORECAM_2D8_12_NOAF,
    NSD_LENS_FORECAM_3D3_10D5_NOAF,
    NSD_LENS_FORECAM_9_22_NOAF,
    NSD_LENS_2G_NOAF,
    NSD_LENS_FORECAM_3D6_10_NOAF,
    NSD_LENS_FORECAM_CHANGLONG_2D8_12_NOAF,
    NSD_LENS_YUTONG_2D8_8_NOAF,
    NSD_LENS_YUTONG_3D6_11_NOAF,
    NSD_LENS_YUTONG_2D7_135_NOAF,

	NSD_LENS_FISHEYE=0x80,
}NSD_LENS_TYPE_E;

//day night status
typedef enum _NSD_DAYNIGHT_STATUS_E
{
	NSD_DN_STATUS_NONE,
	NSD_DN_STATUS_DAY,						//daylight
	NSD_DN_STATUS_NIGHT,					//night
}NSD_DAYNIGHT_STATUS_E;

typedef enum _NSD_COLOR_INDEX_E{
	NSD_COLOR_BLACK=1,
	NSD_COLOR_RED,
	NSD_COLOR_GREEN,
	NSD_COLOR_YELLOW,
	NSD_COLOR_BLUE,
	NSD_COLOR_MAGENTA,
	NSD_COLOR_CYAN,
	NSD_COLOR_WHITE,
}NSD_COLOR_INDEX_E;

typedef enum _NSD_SHUTTER_TIME_E
{
	NSD_SHUTTER_TIME1_5 = 1,
	NSD_SHUTTER_TIME1_10 = 2,
	NSD_SHUTTER_TIME1_13 = 3,
	NSD_SHUTTER_TIME1_15 = 4,
	NSD_SHUTTER_TIME1_20 = 5,
	NSD_SHUTTER_TIME1_25 = 6,
	NSD_SHUTTER_TIME1_50 = 7,
	NSD_SHUTTER_TIME1_100 = 8,
	NSD_SHUTTER_TIME1_125 = 9,
	NSD_SHUTTER_TIME1_200 = 10,
	NSD_SHUTTER_TIME1_250 = 11,
	NSD_SHUTTER_TIME1_500 = 12,
	NSD_SHUTTER_TIME1_1000 = 13,
	NSD_SHUTTER_TIME1_2000 = 14,
	NSD_SHUTTER_TIME1_5000 = 15,
	NSD_SHUTTER_TIME1_10000 = 16,
	NSD_SHUTTER_TIME1_20000 = 17,
	NSD_SHUTTER_TIME1_50000 = 18,
}NSD_SHUTTER_TIME_E;


typedef enum _NSD_FISHEYE_LAYOUT_MODE_E
{
	NSD_FISHEYE_LAYOUT_ONE				= 0,
	NSD_FISHEYE_LAYOUT_FOUR				= 1,  		//2x2
	NSD_FISHEYE_LAYOUT_FOUR_M1			= 2,  		//left:1;  right:3
	NSD_FISHEYE_LAYOUT_FOUR_M2			= 3,  		//up:1;  down:3
}NSD_FISHEYE_LAYOUT_MODE_E;

typedef enum _NSD_FISHEYE_MOUNT_MODE_E
{
	NSD_FISHEYE_DESKTOP_MOUNT 			= 0, 		// desktop mount mode 
	NSD_FISHEYE_CEILING_MOUNT 			= 1, 		// ceiling mount mode 
	NSD_FISHEYE_WALL_MOUNT 				= 2, 		// wall mount mode 
}NSD_FISHEYE_MOUNT_MODE_E;

typedef enum _NSD_AI_ANALYSE_TYPE_E
{
	NSD_AI_NULL					=0,
	NSD_AI_FACE					=0x1,				//face
	NSD_AI_PLATE_NUMBER			=0x2,				//plate number
	NSD_AI_OBJECT				=0x4,				//object track
	NSD_AI_PERIMETER			=0x8,				//perimeter
	NSD_AI_TRIPWIRE				=0x10,				//tripwire
	NSD_AI_FIREDETECT			=0x20,				//fire detect
}NSD_AI_ANALYSE_TYPE_E;

typedef enum _NSD_LOCAL_MSG_TYPE_E
{
	NSD_MSG_MATCH_RESULT        =0,					//匹配结果
	NSD_MSG_FACE_TABLE_ADD,							//人脸入库
	NSD_MSG_FACE_TABLE_MODIFY,						//人脸库修改
	NSD_MSG_FACE_TABLE_DEL,							//人脸库删除
	NSD_MSG_FACE_QUERY,								//人脸库查询
	NSD_MSG_OPER_QUERY,								//操作库查询
	NSD_MSG_REAL_FACE_JPG,							//实时人脸图
    NSD_MSG_FACE_MAX            =99,

    NSD_MSG_PARAM_CHANGE        =1000,              //参数改变
    NSD_MSG_DAY_NIGHT_SWITCH    =1001,              //日夜切换消息

    NSD_MSG_USER_MSG_BEGIN      =10000,             //用户自定义消息起始值
    NSD_MSG_USER_MSG_END        =20000,             //用户自定义消息结束值
}NSD_LOCAL_MSG_TYPE_E;

typedef enum _NSD_AF_MODE_TYPE_E
{
	NSD_AF_AUTO,									//Automatic
	NSD_AF_MANUAL,									//Manual
	NSD_AF_ONEPUSH,									//one focus
}NSD_AF_MODE_TYPE_E;

typedef enum _NSD_SDCARD_STATUS_TYPE_E
{
	NSD_SDCARD_STATUS_FORMAT_BEGIN,
	NSD_SDCARD_STATUS_FORMAT_END,
}NSD_SDCARD_STATUS_TYPE_E;

//////////////////////////////////////////////////
//structure define
//time
typedef struct _NSD_TIME_S								//sizeof=8
{
	unsigned char		u8Year;							//year(since 1900)
	unsigned char		u8Month;						//month 1~12
	unsigned char		u8Day;							//day 1~31
	unsigned char		u8Week;							//week(1~7) 
	unsigned int		u8Hour:8;						//hour 0~23
	unsigned int		u8Minute:8;						//minute 0~59
	unsigned int		u8Second:6;						//second 0~59
	unsigned int		u8Millisec:10;					//millisec (0~999)
}PACKED NSD_TIME_S, *LPNSD_TIME_S;

typedef struct _NSD_SUMMER_TIME_S
{
	unsigned char		u8Month;						//month 1~12
	unsigned char		u8WeekIndex;					//week index
	unsigned char		u8Week;							//week(1~7)
	unsigned char		u8Hour;							//hour 0~23
	unsigned char		u8Minute;						//second 0~59
}PACKED NSD_SUMMER_TIME_S,*LPNSD_SUMMER_TIME_S;

//time segment
typedef struct _NSD_SEGMENT_S							//sizeof=8
{
	unsigned int		open:1;
	unsigned int		beginday:5;						//if time type is week,1~7,if time type is month 1~31
	unsigned int		beginhour:5;
	unsigned int		beginminute:6;
	unsigned int		beginsecond:6;
	unsigned int		beginmillisec:9;
	unsigned int		endday:5;
	unsigned int		endhour:5;
	unsigned int		endminute:6;
	unsigned int		endsecond:6;
	unsigned int		endmillisec:9;
	unsigned int		type:1;							//0:week,1:month;fixed value 1
}PACKED NSD_SEGMENT_S, *LPNSD_SEGMENT_S;

//size
typedef struct _NSD_SIZE_S
{
	unsigned short		cx;
	unsigned short		cy;
}PACKED NSD_SIZE_S, *LPNSD_SIZE_S;

typedef struct _NSD_RANGE_S
{
	int					min;
	int					max;
}PACKED NSD_RANGE_S,*LPNSD_RANGE_S;

typedef struct _NSD_FIXED_S
{
	int					val;
}PACKED NSD_FIXED_S,*LPNSD_FIXED_S;

typedef struct _NSD_POINT_S
{
	int					x;
	int					y;
}PACKED NSD_POINT_S,*LPNSD_POINT_S;

//area
typedef struct _NSD_AREA_S
{
	unsigned short 		u16X;			// starting x coordinate
	unsigned short 		u16Y;		    // starting point y coordinate
	unsigned short 		u16Width;		// Area width
	unsigned short 		u16Height;		// Area height
}PACKED NSD_AREA_S, *LPNSD_AREA_S;

typedef struct _NSD_CHN_STREAM_S	// sizeof = 4
{
	unsigned short 		u16ChannelNo;		// base 0 index
	unsigned short 		u16StreamNo;		// base 0 index
} PACKED NSD_CHN_STREAM_S, * LPNSD_CHN_STREAM_S;

// resolution
typedef struct _NSD_RESOLUTION_S
{
    unsigned short		width;
    unsigned short		height;
}PACKED NSD_RESOLUTION_S, *LPNSD_RESOLUTION_S;


typedef struct _NSD_ACTION_S	//sizeof=
{
	unsigned char		u8Valid;							//0:invalid;    1:valid
	unsigned char		rsvd1[3];
	char				szActionName[NAME_LEN_16];
	unsigned char		u8ActionType;						//Action Type, see  NSD_ACTION_TYPE_E enumeration
	unsigned char		u8ChannelNo;						//Video channel or DO channel
	unsigned short		u16PreSecond;						//Action preparation time
	unsigned int		u32ActionMillisec;					//Action duration, -1 infinite
	unsigned int		u32SaveType;						//save type, see  NSD_SAVE_TYPE_E  enumeration
	unsigned char		u8FTPID;							//FTP id, -1 means invalid
	unsigned char		u8SMTPID;							//SMTP id, -1 means invalid
	unsigned char		rsvd2[2];
	union
	{
	struct{
	unsigned short		u16SnapNum;							//capture the number of shoot
	unsigned short		u16SnapInterval;					//capture interval (milliseconds)
	};
	unsigned int		u32RecStreamId;						//Reserved, fixed 1
	struct{
	unsigned short		u16PtzCmd;							//PTZ instruction, called for preset position
	unsigned char		u8PtzParam1;
	unsigned char		u8PtzParam2;
	};
	unsigned int		u32DOStatus;						//Reserved, fixed 1						
	};

	unsigned char		rsvd3[32];
}PACKED NSD_ACTION_S,*LPNSD_ACTION_S;

// System information structure definition
typedef struct _NSD_SYS_INFO_S	//sizeof=168
{
	char				szDeviceID[NAME_LEN_16];		// Device ID
	char				szVersion[NAME_LEN_48];			// Software version
	char				szMachineType[NAME_LEN_24];		// Machine model
	char				szSerial[NAME_LEN_24];			// Serial

	unsigned char		u8ChannelNum;					// Number of channels
	unsigned char		u8StreamNum;					// Number of streams
	unsigned char		u8AlarmInputNum;				// Number of digital input
	unsigned char		u8AlarmOutputNum;				// Number of digital output

	unsigned char		u8RS232Num;						// Total number of 232 serial ports <=1
	unsigned char		u8RS485Num;						// Total number of 485 serial ports
	unsigned char		u8AInEnable;					// Enable audio input
	unsigned char		u8TalkEnable;					// Enable audio output

	unsigned char		u8DiskNum;						// Disk number
	unsigned char		u8Language;						// Default language
	unsigned char		u8HardFlip;
	unsigned char		u8LensType;						// Lens type, see NSD_LENS_TYPE_E enumeration

	unsigned short		u16SensorType;					// Sensor type, see NSD_SENSOR_TYPE_E enumeration
	unsigned short		u16FaceType;					// Face type, see NSD_FACE_TYPE_E enumeration

	unsigned int		u32ExternalType;				// External type, see NSD_EXTERNAL_TYPE_E enumeration
	unsigned int		u32ODM;							// ODM ID

	unsigned char		u8HWPlatform;
	unsigned char		u8HWPlatform_child;
	unsigned char		u8HardwareVersion;				//Hardware version, 0: old hardware, 1:ARC hardware, 2: AI  3: zoom module
	unsigned char 		u8VideoOffLineMode;				// 0: online, 1: offline
	unsigned int		u32LanguageList;

	unsigned char		u8InnerVideoIn;					//For hisi3559 useful, represent the actual number of sensor 
    unsigned char       u8WifiVersion;                  //0:not support 1:mt7601u
	unsigned char		rsvd2[22];
}PACKED NSD_SYS_INFO_S,* LPNSD_SYS_INFO_S;

// Device information
typedef struct _NSD_DEVICE_S				// sizeof = 200
{
	char				szDeviceName[NAME_LEN_32];	//device name
	unsigned short		u16OldListenPort;				
	unsigned char 		u8MacAddr[MAC_ADDR_LEN]; 	// MAC address (only read)
	unsigned int 		u32IPAddr;					// IP address (only read)
	unsigned int 		u32SubMask;					// mask (only read)
	unsigned int 		u32GateWay;					// gateway (only read)
	unsigned short 		u16ListenPort;				// listening port (only read)
	unsigned short 		u16HttpPort;				// Webserver port (only read)
	unsigned short 		u16DoStatus;				// Relay status (only read)
	unsigned short 		u16UpdatePort;				// Upgrade port (only read)
	NSD_SYS_INFO_S 		sysinfo;					// (only read)

	unsigned int 		u32DNSIP1;					// IP1 for DNS
	unsigned int 		u32DNSIP2;					// IP2 of DNS
	unsigned char 		u8DHCP1;					// wired network adapter DHCP switch
	unsigned char 		u8DHCP2;					// DNS DHCP switch
	unsigned short 		u16DNStatus;				// day and night state
	unsigned char 		rsvd2[48];					// Reserved
	unsigned int 		u32Inner;					
}PACKED NSD_DEVICE_S,*LPNSD_DEVICE_S;

// user configuration
typedef struct _NSD_USER_CFG_S	//sizeof=116
{
	char 				szName [NAME_LEN_32];				// user name
	char 				szPassword [NAME_LEN_16];			// user password
	unsigned char 		u8GroupId;							// Corresponding user group
	unsigned char 		u8Used;								// Whether to enable
	unsigned char 		rsvd[66];
}PACKED NSD_USER_CFG_S,*LPNSD_USER_CFG_S;

// user group configuration
typedef struct _NSD_USER_GROUP_CFG_S
{
	char 				szName [NAME_LEN_32];				// User group name
	unsigned int		u32Right;							// Authority, see NSD_RIGHT_TYPE_E enumeration
	unsigned char		rsvd[64];	
}PACKED NSD_USER_GROUP_CFG_S,*LPNSD_USER_GROUP_CFG_S;

// local network configuration
typedef struct _NSD_ETH_CFG_S	//sizeof=96
{   
	unsigned int 		u32IPAddr;					// IP address
	unsigned int 		u32SubMask;					// mask
	unsigned int 		u32GateWay;					// Gateway
	unsigned char 		u8MacAddr [MAC_ADDR_LEN]; 	// MAC address

	unsigned char 		u8DHCP1;					// wired network adapter DHCP switch
	unsigned char 		u8DHCP2;					// DNS DHCP switch
	unsigned char 		u8DHCPStatus;				// dhcp state
	unsigned char 		u8Rsvd[3];

	unsigned int 		u32DNSIP1;					// IP1 for DNS
	unsigned int 		u32DNSIP2;					// IP2 of DNS
	
	char				szIP6[NAME_LEN_48];
	char				szSubMask6[NAME_LEN_48];
	char				szGateWay6[NAME_LEN_48];
	unsigned char       rsvd[128];
}PACKED NSD_ETH_CFG_S, *LPNSD_ETH_CFG_S;

typedef struct _NSD_WIFI_CFG_S
{
	unsigned char 		u8Open;
	unsigned char 		u8AuthType;					// 0: none, 1: wep, 2: wpa, 3: wpa2,4: wpawpa2
    unsigned char       u8WorkMode;                 // 0: STA   1: AP   3:STA and AP
	unsigned char 		u8Rsvd;
	unsigned int 		u32IPAddr;					// IP address
	unsigned int 		u32SubMask;					// mask
	unsigned int 		u32GateWay;					// Gateway

	unsigned char 		u8DHCP1;					// NIC DHCP switch
	unsigned char 		u8DHCP2;					// DNS DHCP switch
	unsigned char 		u8DHCPStatus;				// dhcp state
	unsigned char 		u8Rsvd2;

	unsigned int 		u32DNSIP1;					// IP1 for DNS
	unsigned int 		u32DNSIP2;					// IP2 of DNS

    char				szStaSSID[NAME_LEN_64];
	char				szStaPwd[NAME_LEN_64];
    char				szApSSID[NAME_LEN_64];
    char				szApPwd[NAME_LEN_64];

    unsigned int 		u32ApIPAddr;				// IP address
    unsigned int 		u32ApSubMask;				// mask
    unsigned int 		u32ApGateWay;				// Gateway
    unsigned int 		u32ApDNSIP1;				// IP1 for DNS
    unsigned int 		u32ApDNSIP2;				// IP2 of DNS

    unsigned char       u8STAStatus;                // 0:disconnect  1:connect
    unsigned char 		u8MacAddr[MAC_ADDR_LEN]; 	// MAC address
	unsigned char       rsvd[57];
}PACKED NSD_WIFI_CFG_S,*LPNSD_WIFI_CFG_S;

// network service configuration
typedef struct _NSD_NET_CFG_S	//sizeof=144
{
	unsigned short		u16ListenPort;					//listening port
	unsigned short		u16HttpPort;					//Webserver port

	unsigned int		u32MulticastAddr;				//multicast address
	unsigned short		u16MulticastPort;				//multicast port
	unsigned short		u16UpdatePort;					//Upgrade port

	unsigned char		u8ActionId[8];					//linkage id, -1 is invalid

	unsigned char		u8OpenBrokenDetect;				//0:close broken network detection 1:open broken network detection 2:ping network detection
	unsigned char		rsvd1;
	unsigned short		u16MulticastTTL;

	unsigned short		u16OldListenPort;
	unsigned int		u32BrokenIPAddr;				//u8OpenBrokenDetect = 2 ping address
	unsigned char       rsvd2[46];
}PACKED NSD_NET_CFG_S,*LPNSD_NET_CFG_S;

typedef struct _NSD_HEARTBEAT_CFG_S
{
	unsigned char		u8Open;							//0: close 1:open
	unsigned short		u16Port;						//server port
	unsigned char		rsvd[9];
	unsigned int		u32Interval;					//unit:ms
	char				szDomain[NAME_LEN_64];			//server address
	char				szIdent[NAME_LEN_32];			//in order to recognize the device
}PACKED NSD_HEARTBEAT_CFG_S,*LPNSD_HEARTBEAT_CFG_S;

typedef struct _NSD_HEARTBEAT_S
{
	unsigned int		u32Magic;
	char				szID[NAME_LEN_32];
	unsigned int		u32ExtLen;
}PACKED NSD_HEARTBEAT_S,*LPNSD_HEARTBEAT_S;;

// pppoe setting
typedef struct _NSD_PPPOE_CFG_S					// sizeof = 124
{
	unsigned char		u8PPPOEOpen;					//PPPOE switch
	unsigned char       u8PPPOEStatus;					//pppoe state 0 successful dialing 1. no dialing 2. dialing
	unsigned char		u8Rsvd[2];	
	char				szPPPOEName[NAME_LEN_32];		//user name
	char				szPPPOEPwd[NAME_LEN_16];		//password
	unsigned int		u32PPPOEAddr;					//PPPOE address
	unsigned int		u32PPPOETimes;					//online time
	unsigned char		rsvd[64];	
}PACKED NSD_PPPOE_CFG_S, *LPNSD_PPPOE_CFG_S;

// ddns setting
typedef struct _NSD_DDNS_CFG_S					// sizeof = 140
{
	unsigned char		u8DDNSOpen;						//DDNS switch
	unsigned char		u8DDNSType;						//0-dyndns 1-3322
	unsigned char		u8Rsvd[2];						
	char				szDDNSAccount[NAME_LEN_64];		// DDNS registration name (registered domain name)
	char				szDDNSUsr[NAME_LEN_32];			// user name
	char				szDDNSPwd[NAME_LEN_16];			// password	
	unsigned short		u16DDNSPort;					// DDNS server port
	unsigned short		u16Rsvd2;
	unsigned int		u32DDNSTimes;					// Update time
	unsigned char		rsvd[64];	
}PACKED NSD_DDNS_CFG_S,*LPNSD_DDNS_CFG_S;

// ntp settings
typedef struct _NSD_NTP_CFG_S					// sizeof = 136
{
	unsigned char		u8NtpOpen;						// ntp switch
	unsigned char       u8Resv;
	unsigned char		u8EnableSummer;					// 1: Start daylight saving time 0: Do not start daylight saving time
	unsigned char       u8NtpRefTime;					// NTP datum time (unit: hour)
	float				fTimeZone;						// Time zone (-12~11), for example, 3.5 represents 3:30
	char				szNtpURL[NAME_LEN_64];
	NSD_SUMMER_TIME_S	summerBegin;
	NSD_SUMMER_TIME_S	summerEnd;
	unsigned short		u16SummerAdvanceTime;			// Early summer time, unit: minute
	unsigned short		u16NtpPort;						
	unsigned char		rsvd[60];	
}PACKED NSD_NTP_CFG_S, *LPNSD_NTP_CFG_S;

// upnp settings
typedef struct _NSD_UPNP_CFG_S					// sizeof = 80
{
	unsigned char		u8UpnpOpen;						//upnp switch
	unsigned char		u8UpnpEthNo;					//0 using the native network card mapping 1 using a wireless network card mapping
	unsigned char		u8UpnpModel;					//0 Fixed Map 1 auto map
	unsigned char		u8UpnpRefTime;					//upnp refresh time (in hours)
	unsigned int		u32UpnpSvr;						//upnp server IP
	unsigned short      u16UpnpDataPort;				//fixed mapping mode, the data port of the external network port
	unsigned short      u16UpnpWedPort;					//fixed mapping mode, the Web port of the external network port
	unsigned short      u16UpnpDataPortS;				//Port 0 on behalf of the data port is not mapped or unsuccessful
	unsigned short      u16UpnpWebPortS;				//port of the external port of the Web port 0 is not mapped or unsuccessful
	unsigned char		rsvd[64];	
}PACKED NSD_UPNP_CFG_S, *LPNSD_UPNP_CFG_S;

// ftp settings
typedef struct _NSD_FTP_CFG_S	//sizeof=308
{
	char 				szFtpURL[NAME_LEN_64];			//ftp server URL
	char				szFtpUsr[NAME_LEN_32];			//user name
	char				szFtpPsw[NAME_LEN_16];			//password
	char				szFtpPath[PATH_LEN];			//Ftp upload path
	unsigned short      u16FtpPort;
	unsigned short      u16Rsvd;
	unsigned char       rsvd[64];
}PACKED NSD_FTP_CFG_S, *LPNSD_FTP_CFG_S;

// smtp settings
typedef struct _NSD_SMTP_CFG_S	//sizeof=468
{
	char				szMailHub[NAME_LEN_64];			//smtp server address
	char				szMailAddr[NAME_LEN_64];		//send e-mail address
	char				szMailUsr[NAME_LEN_32];			//send mail account
	char				szMailPsw[NAME_LEN_16];			//send the email password
	char				szMailRctp[PATH_LEN_200];		//Recipient address, multiple; split
	char				szTitle[NAME_LEN_32];			//mail title
	unsigned char		u8EnableSSL;					//Enable SSL
	unsigned char		u8Rsvd;
	unsigned short		u16MailPort;					//smtp server port
	unsigned char       rsvd[64];
}PACKED NSD_SMTP_CFG_S, *LPNSD_SMTP_CFG_S;

typedef struct _NSD_RTSP_CFG_S
{
	unsigned char		u8Authorized;					//Enable identity authentication
	unsigned char		u8Rsvd[1];
	unsigned short		u16RtspPort;					//rstp service listening port, the default 554
	char 				videoFlag[NAME_LEN_32];			
	char 				audioFlag[NAME_LEN_32];			
	char 				audiobackFlag[NAME_LEN_32];		
	unsigned short		u16Mtu;
	unsigned char		rsvd[62];		
}PACKED NSD_RTSP_CFG_S,*LPNSD_RTSP_CFG_S;

typedef struct _NSD_RTP_CFG_S
{
	unsigned char		u8RtpOpen;
	unsigned char		u8StreamId;
	unsigned short		u16RtpPort;						// rtp receive port
	char 				szRtpUrl[NAME_LEN_64];			
	unsigned short		u16Mtu;
	unsigned char		rsvd[62];		
}PACKED NSD_RTP_CFG_S,*LPNSD_RTP_CFG_S;

// image parameter configuration
typedef struct _NSD_ISP_CFG_S		//88
{
	unsigned char		u8ColorMode;					//see NSD_COLOR_TYPE_E enumeration
	unsigned char		u8Noise;						//noise reduction (0 ~ 100)
	unsigned char		u8ImgStabilize;					//Image anti-shake				
	unsigned char		u8WDRMode;						//see NSD_WDR_MODE_E enumeration
		
	unsigned char		u8Brightness;					//Brightness (0~100)
	unsigned char		u8Saturation;					//Saturation (0~100)
	unsigned char		u8Contrast;						//contrast (0~100)
	unsigned char		u8Sharpness;					//Sharpness (0~100)

	unsigned char		u8AutoIris;						//Auto iris (1 auto, 0 manual)
	unsigned char		u8IrisSpeed;					//Iris speed
	unsigned char		u8Defog;						//through fog  (0~100)
	unsigned char		u8GammaMode;

	unsigned char		u8Dis;							//Electronic Image Stabilizer, see NSD_OFFON_STATUS_E enumeration
	unsigned char		u8LDC;							//Lens distortion correction, see NSD_OFFON_STATUS_E enumeration
	unsigned char		u8LDCStrength;					//Intensity (0~100)
	unsigned char		u8DigitalZoom;					//Digital zoom, see  NSD_OFFON_STATUS_E enumeration

	unsigned char		u8WDRType;						//see NSD_WDR_TYPE_E enumeration
	unsigned char		rsvd2[43];
}PACKED NSD_ISP_CFG_S,* LPNSD_ISP_CFG_S;	
	
typedef struct _NSD_AWB_CFG_S		//76
{
	unsigned char		u8AWBMode;						//White balance mode
	unsigned char		u8RGBSetting;					//1:R,2:GR,4:GB,8:B
	unsigned short		u16SmoothInterval;				//NSD_AWB_PANO valid,Stationary interval, unit:seconds
	unsigned short		u16RGain;						//valid when awb is manual
	unsigned short		u16GRGain;						//valid when awb is manual
	unsigned short		u16GBGain;						//valid when awb is manual
	unsigned short		u16BGain;						//valid when awb is manual
	unsigned char		rsvd2[64];
}PACKED NSD_AWB_CFG_S,*LPNSD_AWB_CFG_S;

// auto exposure
typedef struct _NSD_AE_CFG_S			//76
{
	unsigned char		u8AEMode;						//Exposure mode
	unsigned char		u8Metering;						//see NSD_AE_METERING_TYPE_E enumeration		
	unsigned char		u8AntiFlickerMode;				//see NSD_ANTI_FLICKER_TYPE_E enumeration
	unsigned char		u8FixGainFlag;					//0: using u32FixGain; 1: using	u32FixAGain\u32FixDGain\u32FixISPGain
	unsigned int		u32MaxShutterTime;				//Shutter time,valid when ae is auto
	unsigned int		u32FixShutterTime;				//valid when ae is not auto
	unsigned int		u32MaxGain;						//valid when ae is auto
	unsigned int		u32FixGain;						//valid when ae is not auto
	unsigned char		u8MeterWeight[15*17];			//Manual metering area weight
	unsigned char		rsvd[2];
	unsigned char		u8NUCMode;
	unsigned char		u8BLC;							//Backlight compensation
	unsigned char		u8HL;							//High light suppression
	unsigned short		u16NUCInterval;					//The interval of a block,   unit:seconds
	unsigned short		u16SmoothInterval;				//NSD_AE_PANO valid,Stationary interval, unit:seconds
	unsigned int		u32FixAGain;
	unsigned int		u32FixDGain;
	unsigned int		u32FixISPGain;
	unsigned char		u8SlowShutterMode;				//see NSD_OFFON_STATUS_E enumeration
	unsigned char		rsvd3[35];
}PACKED NSD_AE_CFG_S,*LPNSD_AE_CFG_S;

typedef struct _NSD_AF_CFG_S			//76
{
	unsigned char		u8AFMode;						//see NSD_AF_MODE_TYPE_E enumeration
	unsigned char		u8MoveType;						//see NSD_AF_MOVE_TYPE_E enumeration
	unsigned char		u8Sensitivity;					//0:normal,1:low
	unsigned char		u8IRCorrection;					//0:no,1:ir correction
	unsigned char		rsvd[72];	
}PACKED NSD_AF_CFG_S,*LPNSD_AF_CFG_S;

typedef struct _NSD_IMG_CFG_S
{
	unsigned char		u8ImgProfile;					//0:auto,1:day profile,2:night profile
	unsigned char		u8ICRMode;						//0:initiative,1:Passivity,2:Schedule
	unsigned char		u8DNSensitivity;
	unsigned char		rsvd1;					

	unsigned char		u8D2NThreshold;				
	unsigned char		u8N2DThreshold;
	unsigned char		rsvd2[2];
	unsigned int		u32D2NSec;						//The number of seconds to switch day to night mode 3600*hour+60*min+sec
	unsigned int		u32N2DSec;						//The number of seconds to switch night to day mode 3600*hour+60*min+sec
	unsigned char		rsvd3[32];
}PACKED NSD_IMG_CFG_S,* LPNSD_IMG_CFG_S;	

// Video encoding related structure definition
typedef struct _NSD_VEC_S		//sizeof=56
{
	unsigned int		u32MaxResolution;				//Maximum resolution of support
	unsigned char		u8Qulity;						//Quality
	unsigned char		u8BitrateType;					//stream type, see NSD_BITRATE_TYPE_E enumeration
	unsigned short		u16Rsvd;
	unsigned short		u16EncodeType;					//Encoding type
	unsigned short		u16KeyInterval;					//I frame interval
	unsigned short      u16ImageWidth;					//Resolution: width
	unsigned short		u16ImageHeight;					//Resolution: height
	unsigned int		u32Bitrate;						//Bit rate(kbps)
	unsigned short		u16FRNumerator;					//Frame rate, molecule
	unsigned short		u16FRDenominator;				//Frame rate, denominator
	unsigned char		u8BPInterval;					//BP frame interval, 0-P, 1-BP, 2-BBP
	unsigned char		u8Profiles;						//1:baseline,2:main frofile,3:high frofile
	unsigned char       rsvd[30];
}PACKED NSD_VEC_S, *LPNSD_VEC_S;
 
// video input configuration
typedef struct _NSD_VIDEO_CFG_S	//sizeof=100
{
	unsigned short		u16ViImageWidth;
	unsigned short		u16ViImageHeight;
	unsigned char		u8System;						//see NSD_VIDEO_SYSTEM_TYPE_E enumeration
	unsigned char		u8RotateMode;					//see NSD_ROTATE_MODE_E enumeration
	unsigned char		u8Mirror;						//mirror image		
	unsigned char       rsvd[53];						//
	unsigned int		u32SetMask;						//Parameter settings are valid, 0:set all,0x1:vec[0],0x2:vec[1],0x4:vec[2] eg.
	NSD_VEC_S			vec[MAX_STREAM_NUM];			//stream encoding configuration list
}PACKED NSD_VIDEO_CFG_S, * LPNSD_VIDEO_CFG_S;

 
// video output configuration
typedef struct _NSD_VOUT_CFG_S	//sizeof=72
{
	unsigned char		u8Enable;
	unsigned char		u8VOutDev;						//output device NSD_VOUT_DEV_TYPE_E
    unsigned char       u8SettingMask;                  //0: set all param  1: set alpha and colorkey
	unsigned char		u8Rsvd;
	unsigned int		u32VOutMode;					//NSD_VOUT_DEV_MODE_E
	unsigned char		u8ChangeType;					//0： change with video cfg. 1： change by u8RotateMode and u8Mirror
	unsigned char		u8RotateMode;					//see NSD_ROTATE_MODE_E enumeration
	unsigned char		u8Mirror;						//mirror image	
    unsigned char       u8ScreenType;                   //0:TV080WUM-NH1 1200*1920 1:JD9366 800*1280
    unsigned char       u8Alpha;                        //0:transparency  1:opacity
    unsigned char       u8Rsvd2[2];                     //
    unsigned char       u8ColorKeyEnable;
    unsigned int        u32ColorKey;                    //0xff0000:red  0x00ff00:green  0x0000ff:blue
	unsigned char		rsvd[52];	
}PACKED NSD_VOUT_CFG_S, * LPNSD_VOUT_CFG_S;


typedef struct _NSD_FISHEYE_CFG_S	//sizeof=71
{
	unsigned char		u8EnableFlag;					//1: Enable
	unsigned char		u8MountMode;					//see NSD_FISHEYE_MOUNTMODE_E enumeration
	unsigned char		u8LayoutMode;					//see NSD_FISHEYE_LAYOUT_MODE_E enumeration
	unsigned char		rsvd;
}PACKED NSD_FISHEYE_CFG_S,*LPNSD_FISHEYE_CFG_S;


// video mask configuration
typedef struct _NSD_MASK_CFG_S // sizeof = 76
{
	unsigned char		u8OpenMask;						//1: Enable masking
	unsigned char		u8SetAreaMask;					//Parameter settings are valid, 0:set all,0x1 0x2 0x4 eg.
	unsigned char		u8Rsvd[2];
	NSD_AREA_S			area[MAX_MASK_AREA_NUM];
	unsigned short		u16Pan[MAX_MASK_AREA_NUM];		//0-36000
	unsigned short		u16Tilt[MAX_MASK_AREA_NUM];		//0-18000
	unsigned short		u16Zoom[MAX_MASK_AREA_NUM];		//zoom*100
	unsigned char		rsvd[16];	
}PACKED NSD_MASK_CFG_S,*LPNSD_MASK_CFG_S;

//OSD
typedef struct _NSD_OSD_AREA_S	//sizeof=32
{
	unsigned char		u8Show;							//1: Enable
	unsigned char		u8Bmp;							//0: text,  1: bmp
	unsigned char		rsvd1[2];						
	unsigned int		u32Color;						//OSD text color type
	NSD_AREA_S			area;							//The osd area, independent of the resolution of the image
	unsigned char		rsvd2[16];
}PACKED NSD_OSD_AREA_S,*LPNSD_OSD_AREA_S;

typedef struct _NSD_OSD_CFG_S	//sizeof=620
{
	NSD_OSD_AREA_S		dateOsd;						//Time OSD
	NSD_OSD_AREA_S		titleOsd;						//Title OSD
	NSD_OSD_AREA_S		custom1Osd;						
	NSD_OSD_AREA_S		custom2Osd;						
	NSD_OSD_AREA_S		alarmOsd;						//Alarm OSD
	unsigned int		dateType;						//time format
	char				titleInfo[NAME_LEN_64];
	char				customInfo1[NAME_LEN_64];
	char				customInfo2[NAME_LEN_64];
	unsigned int		u32FontSize;					//font size, see NSD_FONT_LEVEL_E enumeration
	unsigned int		u32Transparency;				//fg transparency
	unsigned int		u32TransparencyBg;				//bg transparency
	unsigned int		u32Rotate;						//rotate flag
	unsigned char		u8Rsvd1[40];    
}PACKED NSD_OSD_CFG_S, *LPNSD_OSD_CFG_S;

typedef struct _NSD_ROI_CFG_S
{
	unsigned char		u8Open;							//1: Enable
	unsigned char		u8SetAreaMask;					//Parameter settings are valid, 0:set all,0x1 0x2 0x4 eg.
	unsigned char		rsvd1[2];						
	NSD_AREA_S			roi[MAX_ROI_NUM];
	unsigned char		u8Rsvd1[32];    
}PACKED NSD_ROI_CFG_S, *LPNSD_ROI_CFG_S;

// motion detection configuration
typedef struct _NSD_MOTION_CFG_S	//sizeof=328
{
	unsigned char		u8OpenDetect;					//1: Enable
	unsigned char		u8Rsvd;
	unsigned char		u8Sensitivity;					//Sensitivity(0~100)
	unsigned char		u8Threshold;					//threshold(0~100)
	unsigned int		u32Persistent;					//Duration (unit: Second)
	unsigned char		u8Block[MD_ROW_NUM*MD_COL_NUM];	//Detection area
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		u32ActionId[8];					//Action ID, -1 invalid
	unsigned char		rsvd[60];	
}PACKED NSD_MOTION_CFG_S,*LPNSD_MOTION_CFG_S;

// Scheduled task configuration
typedef struct _NSD_SCHEME_CFG_S	
{
	unsigned char		u8OpenDetect;					//1: Enable
	unsigned char		u8Type;							//0: continuous action, 1: one-off action
	unsigned char		rsvd1[2];
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//time period
	unsigned int		u32ActionId[8];					//Action ID, -1 invalid
	char				szSchemeName[NAME_LEN_16];
	unsigned char		rsvd2[44];	
}PACKED NSD_SCHEME_CFG_S,*LPNSD_SCHEME_CFG_S;

// blacklist configuration
typedef struct _NSD_FILTER_CFG_S
{   
	unsigned char		u8OpenIPFilter;
	unsigned char		rsvd1[3];	
	char 				ipaddr[MAX_IP_FILTER_NUM][NAME_LEN_32];					
	unsigned char		u8OpenMacFilter;
	unsigned char		rsvd2[3];	
	char				macaddr[MAX_MAC_FILTER_NUM][NAME_LEN_32];	
}PACKED NSD_FILTER_CFG_S, *LPNSD_FILTER_CFG_S;

// audio configuration
typedef struct _NSD_AUDIO_CFG_S	//sizeof=72
{
	unsigned char		u8Open;							//1: Enable
	unsigned char		u8InputType;					//Audio input mode, see NSD_AUDIO_INPUT_TYPE_E enumeration
	unsigned char		u8EncodeType;					//Encoding type
	unsigned char		u8Bits;							//
	unsigned int		u32Samples;						//Sampling rate
	unsigned char		u8CaptureVolume;				
	unsigned char		u8PlaybackVolume;
	unsigned short		u16PacketLen;					//Per packet sampling length
	unsigned char		u8ChannelNum;					//channels 
	unsigned char		rsvd[59];	
}PACKED NSD_AUDIO_CFG_S, *LPNSD_AUDIO_CFG_S;

//serial configuration
typedef struct _NSD_UART_CFG_S	//sizeof=72
{
	unsigned int		u32BaudRate;					//Serial port baud rate	 300---115200
	unsigned char		u8Databit;						//Serial data bit length 0 = 5 bits 1 = 6 bits 2 = 7 bits 3 = 8 bits Others = 8 bits
	unsigned char		u8Stopbit;						//Stop bits 1 = 1 bit 2 = 2 bits Others = 1 bit
	unsigned char		u8Parity;						//Parity 0 = None 1 = Odd 2 = Even 3 = Constant 1 4 = Constant 0
	unsigned char		u8FlowCtrl; 					
	char				devName[NAME_LEN_64];			//Read only
	unsigned char		u8GpioNo;						//Read only
	unsigned char		u8UsePTZ;						//Using the PTZ instruction
	unsigned char		rsvd[62];	
}PACKED NSD_UART_CFG_S,*LPNSD_UART_CFG_S;

typedef struct _NSD_PTZ_POS_S
{
	unsigned int		u32Pan;							
	unsigned int		u32Tilt;						
	unsigned int		u32Zoom;
	unsigned int		rsvd;
}PACKED NSD_PTZ_POS_S,*LPNSD_PTZ_POS_S;

//PTZ settings
typedef struct _NSD_PTZ_CFG_S	//sizeof=68
{
	unsigned short		u16PTZProtocol;					// PTZ protocol, 0: pelco-d, 1: pelco-p
	unsigned short		u16Addr;						// address bit
	unsigned char		u8UartNo;						// serial port id
	unsigned char		u8WatchEnable;					// Watch bit, 1: enabled, 0: disabled
	unsigned char		u8WatchAction;					// Watch bit action
	unsigned char		u8WatchActionType;				// fixed is 3:preset
	unsigned int		u32WatchTime;					//WatchTime (millisecond)
	unsigned short		u16SensorType;					
	unsigned char		u8PowerActionType;				//0:none,1:tour,2:track,3:preset,4:autoopen,5:memory
	unsigned char		u8PowerAction;					//Power on action
	unsigned int		u32PowerTime;					//Power up time (millisecond, 0 default 10 seconds)
	unsigned int		u32ZoomPos;						//power off zoom location[inner used]
	unsigned short		u16PanPos;						//0~36000(*100)[inner used]
	unsigned short		u16TiltPos;						//0~9000(*100)[inner used]

	unsigned char		u8MemoryOperateType;			//0:none,1:tour,2:track,4:autoopen[inner used]
	unsigned char		u8MemoryOperate;				
	unsigned char		rsvd2[30];	
}PACKED NSD_PTZ_CFG_S,*LPNSD_PTZ_CFG_S;

// PTZ control
typedef struct _NSD_PTZ_CTRL_S	//sizeof=24
{
	unsigned char		u8UartNo;						//Serial port id
	unsigned char		u8ChannelNo;					//channel number
	unsigned char		u8ProtoType;					//fixed value: 0xff
	unsigned char		u8Command;						//command code
	unsigned char		u8Data1;						//When the speed is expressed, the range [0,100]
	unsigned char		u8Data2;						//
	unsigned char		rsvd[18];
}PACKED NSD_PTZ_CTRL_S,*LPNSD_PTZ_CTRL_S;

typedef struct _NSD_PTZ_POSITION_S	
{
	unsigned char		u8ChannelNo;					//channel number
	unsigned char		u8Action;						//set mask:1-p,2-t,4-z
	unsigned short		u16Pan;							//0~36000(*100)
	unsigned short		u16Tilt;						//0~9000(*100)
	unsigned short		u16Zoom;						//100~(*100)
	unsigned char		rsvd[32];
}PACKED NSD_PTZ_POSITION_S,*LPNSD_PTZ_POSITION_S;

typedef struct _NSD_PRESET_CFG_S
{
	char				name[NAME_LEN_32];
	unsigned char		u8UartNo;						//Serial port id
	unsigned char		u8ChannelNo;					//channel number
	unsigned char		u8ProtoType;					//fixed value: 0xff
	unsigned char		u8PresetIndex;					//Preset point number, (1 ~ 100,101 ~ MAX_PRESET_NUM-1 is rsvd)
	unsigned char		u8Rsvd[16];
}PACKED NSD_PRESET_CFG_S,*LPNSD_PRESET_CFG_S;

typedef struct _NSD_BALL_3D_S
{
	NSD_SIZE_S			siNow;							//the current size of the ratio (1 ~ 10000)
	NSD_POINT_S			ptOffset;						//Offset, the center of the left, above the negative (percentage)
	unsigned char		u8Direction;					//0: Zoom in, 1: Zoom out
	unsigned char		u8Rsvd[31];
}PACKED NSD_BALL_3D_S,* LPNSD_BALL_3D_S;

typedef struct _NSD_TOUR_POINT_S
{
	unsigned char		u8Used;							// 0: invalid, 1: valid
	unsigned char		u8PresetIndex;					//preset point
	unsigned short		u16TimeInterval;				//Pause time (millisecond)
	unsigned char		u8Rsvd[4];
}PACKED NSD_TOUR_POINT_S,*LPNSD_TOUR_POINT_S;


typedef struct _NSD_DI_CFG_S		//sizeof=296
{
	unsigned char		u8Type;							//0: normally open, 1: normally closed
	unsigned char		u8OpenDetect;					//1: Enable detection
	unsigned short		u16Rsvd;						
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//time period
	unsigned int		u32ActionId[8];					//Action id, -1 is invalid
	unsigned char		rsvd[64];	
}PACKED NSD_DI_CFG_S,*LPNSD_DI_CFG_S;


typedef struct _NSD_DO_CFG_S		//sizeof=8
{
	unsigned short		u16Status;
	unsigned short		u16Mask;
	unsigned char		rsvd[4];
}PACKED NSD_DO_CFG_S,*LPNSD_DO_CFG_S;


typedef struct _NSD_ALARM_OUTPUT_STATUS_S	//sizeof=40
{
	NSD_TIME_S			tmAlarm;						//alarm generation time
	NSD_ALARM_TYPE_E	alarmType;						//alarm type
	unsigned short		u16AlarmIndex;					//Alarm index value, based on 0. For motion detection video channel, for the DI for the probe number
	unsigned short		u16DoStatus;					//Relay status, bitwise. 1: On 0: Off
	unsigned char		u8Signal;						//alarm generated / eliminated. 1: produce 0: eliminate
	unsigned char		u8Rsvd[7];
	unsigned char		u8AlarmContext[16];				
}PACKED NSD_ALARM_OUTPUT_STATUS_S,*LPNSD_ALARM_OUTPUT_STATUS_S;

//Record file info
typedef struct _NSD_RECORD_FILE_S	//28
{
	unsigned char		u8ChannelNo;					//channel number
	unsigned char		u8StreamId;						
	unsigned short		u8MediaType;					//1: video, 2: picture
	unsigned int		u8RecSize;						//total number of video recording bytes
	unsigned char		u8Mark;							//0: not finished, 1: last one
	unsigned char       u8Rsvd[3];		
	NSD_TIME_S			tmStart;						//start time
	NSD_TIME_S			tmEnd;							//end time
}PACKED NSD_RECORD_FILE_S,* LPNSD_RECORD_FILE_S;


typedef struct _NSD_MULTI_CFG_HEAD_S
{
	unsigned short		u16ConfigType;					
	unsigned short		u16Append;						
}PACKED NSD_MULTI_CFG_HEAD_S,*LPNSD_MULTI_CFG_HEAD_S;


typedef struct _NSD_MOTION_STATUS_S	//sizeof=40
{
	NSD_TIME_S			tmMotion;						//Mobile detection time
	unsigned short		u16EncodeWidth;					//The width of the encoding
	unsigned short		u16EncodeHeight;				//The height of the encoding
	unsigned short		u16BlockWidth;					//The width of the data block
	unsigned short		u16BlockHeight;					//
	unsigned char		u8ChannelNo;					// video channel number
	unsigned char		u8PixelX;						// block contains the horizontal pixels
	unsigned char		u8PixelY;						// block contains the vertical pixels
	unsigned char		u8Rsvd[21];
}PACKED NSD_MOTION_STATUS_S,*LPNSD_MOTION_STATUS_S;

typedef struct _NSD_PANO_S
{
	unsigned int		u32Setting;
	unsigned char		u8MasterSensor;
	unsigned char		u8IRMaster;
	unsigned char		u8OSDMaster;
	unsigned char		rsvd2[241];
	unsigned short		u16PanPos;						
	unsigned short		u16TiltPos;						
	unsigned int		u32IPCBaseIP;
	unsigned short		u16IPCPort;
	unsigned char		rsvd3[2];
}PACKED NSD_PANO_S,*LPNSD_PANO_S;

typedef struct _NSD_8021X_CFG_S
{
	unsigned char 		u8Open;							//0: disalbe  1:enalbe
	unsigned char 		u8EapType;						//0: MD5
	unsigned char 		u8EapVersion; 					//1: version 1.  2: version 2
	unsigned char 		u8Rsvd;
	char		  		szUsr[NAME_LEN_64];
	char		  		szPwd[NAME_LEN_64];
	char		  		rsvd[64];
}PACKED NSD_8021X_CFG_S,*LPNSD_8021X_CFG_S;

typedef struct _NSD_PRIVATE_DATA_CFG_S
{
	unsigned int 		u32DataLen;
	char		 		rsvd[1];
}PACKED NSD_PRIVATE_DATA_CFG_S,*LPNSD_PRIVATE_DATA_CFG_S;

typedef struct _NSD_SNMP_CFG_S
{
	unsigned char   	u8EnableSnmp;					//1:Enable
	unsigned char		u8Rsvd[3];
	unsigned short  	u16SnmpPort;					//SNMP port
	unsigned short  	u16TrapPort;					//Trap port
	unsigned int		u32TrapAddress;					//Trap send address
	char				szReadCommunity[NAME_LEN_64];
	char				szWriteCommunity[NAME_LEN_64];
	char				szTrapCommunity[NAME_LEN_64];
	char				rsvd[64];
}PACKED NSD_SNMP_CFG_S,*LPNSD_SNMP_CFG_S;

// device capabilities query structure
typedef struct _NSD_CAPABILITY_HEAD_S
{
	unsigned short		u16CapabiltyType;
	union{
		struct
		{
		unsigned char	u8ChannelNo;
		unsigned char	u8StreamNo;
		}S_vi_ch;
		unsigned short	u16Append;					
	};
}PACKED NSD_CAPABILITY_HEAD_S,* LPNSD_CAPABILITY_HEAD_S;

typedef struct _NSD_CAPABILITY_VENC_S
{
	unsigned short		u16EncodeType;					//Encoding type
	unsigned char		rsvd1[2];

	unsigned char		listBitrateType[6];				//List of bit rate types, meaning NSD_BITRATE_TYPE_E. NSD_BITRATE_NONE indicates that the value is invalid and is ignored
	unsigned char		listProfile[4];					//Profile list, the value of the meaning of reference NSD_VIDEO_PROFILE_E, NSD_VIDEO_PROFILE_NONE that the value is invalid, is ignored
}PACKED NSD_CAPABILITY_VENC_S,*LPNSD_CAPABILITY_VENC_S;

typedef struct _NSD_AVS_CFG_S
{
	unsigned short		u16FovX;						//1000 - 36000
	unsigned short		u16FovY;						//1000 - 18000
	short				s16Yaw;							//-18000-18000
	short				s16Pitch;						//-18000-18000
	short				s16Roll;						//-18000-18000
	short				s16CentX;						//-10000 - 10000
	short				s16CentY;						//-10000 - 10000
	char				rsvd[6];
}PACKED NSD_AVS_CFG_S,*LPNSD_AVS_CFG_S;

//VI source ability
typedef struct _NSD_CAPABILITY_VI_S
{
	NSD_RESOLUTION_S	viResolution;
	NSD_RANGE_S			framerateRange;
}PACKED NSD_CAPABILITY_VI_S,*LPNSD_CAPABILITY_VI_S;

typedef NSD_RESOLUTION_S	NSD_CAPABILITY_RESOLUTION_S;
typedef NSD_RANGE_S			NSD_CAPABILITY_VIDEO_BITRATE_S;
typedef NSD_RANGE_S			NSD_CAPABILITY_FRAMERATE_S;
typedef NSD_RANGE_S			NSD_CAPABILITY_QULITY_S;
typedef NSD_RANGE_S			NSD_CAPABILITY_GOV_S;
typedef NSD_FIXED_S			NSD_CAPABILITY_AENC_S;			//NSD_CODEC_TYPE_E
typedef NSD_FIXED_S			NSD_CAPABILITY_ADEC_S;			//NSD_CODEC_TYPE_E
typedef NSD_FIXED_S			NSD_CAPABILITY_AUDIO_TYPE_S;	//NSD_AUDIO_INPUT_TYPE_E
typedef NSD_FIXED_S			NSD_CAPABILITY_AUDIO_SAMPLE_S;
typedef NSD_FIXED_S			NSD_CAPABILITY_AWB_S;
typedef NSD_FIXED_S			NSD_CAPABILITY_AE_S;

//////////////////////////////////////////////////
//Audio and video definitions
#ifndef __VA_DEF__
#define __VA_DEF__

//Frame type
typedef enum _NSD_FRAME_TYPE_E
{
	NSD_FRAME_A=0,										//Audio frame
	NSD_FRAME_I=1,										//video I frame
	NSD_FRAME_P=3,										//video P frame
	NSD_FRAME_B=4,										//video B frame
	NSD_FRAME_MD=8,										//motion detection macro block information
	NSD_FRAME_AI=9
}NSD_FRAME_TYPE_E;

//bitrate type
typedef enum _NSD_BITRATE_TYPE_E
{
	NSD_BITRATE_NONE=0,
	NSD_BITRATE_CBR,									//Constant bit stream	
	NSD_BITRATE_VBR,									//Variable bit stream
	NSD_BITRATE_VBR_PLUS,								//vbr+
}NSD_BITRATE_TYPE_E;


//video encode type
typedef enum _NSD_CODEC_TYPE_E
{
	NSD_CODEC_NONE,										
	NSD_CODEC_H264,										//h264
	NSD_CODEC_MJPEG,									//mjpeg
	NSD_CODEC_G711A,
	NSD_CODEC_G711U,
	NSD_CODEC_PCM,
	NSD_CODEC_H265,
	NSD_CODEC_AAC,
}NSD_CODEC_TYPE_E;

//video infomation
typedef struct _NSD_VIDEO_INFO_S
{
	unsigned char		u8EncodeType;					//Video Encode type
	unsigned char		rsvd1;							//
	unsigned short		u16ImageWidth;					//width
	unsigned short		u16ImageHeight;					//height
	unsigned char		u8FrameRate;					//frame rate
	unsigned char		rsvd2;							//
}PACKED NSD_VIDEO_INFO_S,*LPNSD_VIDEO_INFO_S;

//audio infomation
typedef struct _NSD_AUDIO_INFO_S
{
	unsigned char		u8EncodeType;					//Audio encode type
	unsigned char		rsvd1;							//
	unsigned char		u8AudioChannels;				//Audio channel
	unsigned char		u8AudioBits;					//Audio bits
	unsigned int		u32AudioSamples;				//Sampling rate
}PACKED NSD_AUDIO_INFO_S, *LPNSD_AUDIO_INFO_S;

//audio or video frame head infomation
typedef struct _NSD_FRAME_HEAD_S			//size=28
{
	unsigned short		u16FrameFlag;					//0x7468
	unsigned char		u8FrameType:7;					//NSD_FRAME_TYPE
	unsigned char		u8HasChildFrame:1;
	unsigned char		rsvd;
	unsigned int		u32FrameNo;						//Frame number
	unsigned int		u32TimeStamp;					//time stamp
	unsigned int		u32WallClock;					//Clock time (time_t)
	union
	{
		NSD_VIDEO_INFO_S	videoInfo;
		NSD_AUDIO_INFO_S	audioInfo;
	};
	unsigned int		u32FrameSize;					//date len
}PACKED NSD_FRAME_HEAD_S, *LPNSD_FRAME_HEAD_S;
#endif//__VA_DEF__

//note:sizeof(NSD_CHILD_FRAME_HEAD_S) must be equal to sizeof(NSD_FRAME_HEAD_S) 
//In view of the application of panoramic equipment
typedef struct _NSD_CHILD_FRAME_HEAD_S
{
	unsigned short		u16Magic;						//0x5448
	unsigned char		u8ChildFrameType:7;				//NSD_FRAME_TYPE
	unsigned char		u8PanoFlag:1;
	unsigned char		u8ChildChn;
	unsigned int		u32ChildFrameNo;
	unsigned int		u32ChildFrameTimeStamp;
	unsigned int		rsvd;
	union
	{
		NSD_VIDEO_INFO_S	videoInfo;
		NSD_AUDIO_INFO_S	audioInfo;
	};
	unsigned int		u32ChildFrameSize;
}PACKED NSD_CHILD_FRAME_HEAD_S, *LPNSD_CHILD_FRAME_HEAD_S;

typedef struct _NSD_FACE_RESULT_S
{
	unsigned short	    u16FaceId;
	unsigned char		u8Quality;						//0-100
	unsigned char		u8Gender;						//0:unknown 1:male 2:female
	unsigned char		u8Age;		
	unsigned char		u8GroupId;
	unsigned char		u8IsOrigPicture;
	unsigned char		u8NeedPrintOsd;                 //if value is 1, szInfo will be shown 
    unsigned int        u32Color;                       //red:0x00ff0000, green:0x0000ff00, blue:0x000000ff ...
    char                szInfo[32];                     //osd info
	NSD_AREA_S			resultPosition;					//position
	int					n32MatchID;						//valid when u8MatchResult=1
	float				fSimilarity;					//valid when u8MatchResult=1
	unsigned char		u8MatchResult;					//1:match success,0:match fail
    char                rsvd2[55];
}PACKED NSD_FACE_RESULT_S, *LPNSD_FACE_RESULT_S;

typedef struct _NSD_COMMON_RESULT_S
{
	unsigned short      u16Id;
	unsigned char		param1;		
	unsigned char		param2;	
	unsigned char		param3;	
    unsigned char		param4;	
    unsigned char		u8NeedPrintOsd;                 //if value is 1, szInfo will be shown
    unsigned char       rsvd;
    unsigned int        u32Color;                       //red:0x00ff0000, green:0x0000ff00, blue:0x000000ff ...
    char                szInfo[32];                     //osd info
	NSD_AREA_S			resultPosition;					//position
}PACKED NSD_COMMON_RESULT_S, *LPNSD_COMMON_RESULT_S;

typedef struct _NSD_SNAP_HEAD_S
{
	unsigned short		u16Magic;						//0x7470  SNAP_MAGIC_FLAG
	unsigned char		u8TotleNum;						//Total number of sessions
	unsigned char		u8No;							//base 0 index
	unsigned char		u8Type;							//NSD_AI_ANALYSE_TYPE_E
	unsigned char		u8Company;						//NSD_COMPANY_E
	unsigned short		u16MicroTimeStamp;
	unsigned int		u32TimeStamp;

	union
	{
		NSD_FACE_RESULT_S		faceResult;
		NSD_COMMON_RESULT_S		commonResult;
	};
	unsigned int		u32SessionId;					//sessions id
}PACKED NSD_SNAP_HEAD_S, *LPNSD_SNAP_HEAD_S;

typedef struct _NSD_USER_CONF_S
{
	unsigned char		u8Valid;						//0:invalid;    1:valid
	unsigned char		rsvd[15];
	char		  		szConfName[NAME_LEN_64];
}PACKED NSD_USER_CONF_S, *LPNSD_USER_CONF_S;


typedef struct _NSD_LOCAL_MSG_HEAD_S
{
	unsigned int		u32MsgType;						//NSD_LOCAL_MSG_TYPE_E,For others, please use more than 10 
	unsigned char		rsvd[36];
}PACKED NSD_LOCAL_MSG_HEAD_S,* LPNSD_LOCAL_MSG_HEAD_S;

typedef struct _NSD_MODULE_MSG_HEAD_S
{
	unsigned int		u32MsgType;						//NSD_LOCAL_MSG_TYPE_E,For others, please use more than 10 
	unsigned int		u32DestModule;					//NSD_MODULE_TYPE_E
	unsigned char		u8Misc;
	unsigned char		rsvd[31];
}PACKED NSD_MODULE_MSG_HEAD_S,* LPNSD_MODULE_MSG_HEAD_S;

typedef struct _NSD_SCREEN_CFG_S
{
    unsigned char       u8ShowFlag;                     //0: Not show  1: Show
    unsigned char       u8SaveEnergyFlag;               //0: Not save energy  1: save energy
    unsigned char       u8Luma;                         //0-100
    unsigned char       u8Contrast;                     //0-100
    unsigned char       u8Hue;                          //0-100
    unsigned char       u8Saturation;                   //0-100
    unsigned char       u8SaveEnergyBrightness;         //0-100
    unsigned char       u8NormalBrightness;             //0-100
    unsigned char       rsvd[120];
}PACKED NSD_SCREEN_CFG_S, * LPNSD_SCREEN_CFG_S;

typedef struct _NSD_WIEGAND_CFG_S
{
    unsigned char       u8Enable;                       //0: Disable 1:Enable
    unsigned char       u8WiegandType;                  //0: 26bit   1:34bit
    unsigned char       rsvd[2];
    unsigned int        u32Duration;                    //ms
    unsigned char       rsvd2[64];
}PACKED NSD_WIEGAND_CFG_S, * LPNSD_WIEGAND_CFG_S;

typedef struct _NSD_RELAY_CTL_DOOR_S
{
    unsigned char       u8Enable;                       //0: Disable 1:Enable
    unsigned char       u8IOIndex;
    unsigned char       u8ValidLevel;                   //1:NO 0:NC
    unsigned char       rsvd;
    unsigned int        u32Duration;                    //ms
    unsigned char       rsvd2[64];
}NSD_RELAY_CTL_DOOR_S, * LPNSD_RELAY_CTL_DOOR_S;

typedef struct _NSD_HTTP_CFG_S
{
    unsigned char       u8Enable;                       //0: Disable 1:Enable
    unsigned char       u8UploadType;                   //0: Only Picture  1: Whole information
    unsigned short      u16Port;                        
    unsigned int 		u32IPAddr;					
    char                szUrl[NAME_LEN_64];
    char                rsvd[256];
}PACKED NSD_HTTP_CFG_S, * LPNSD_HTTP_CFG_S;

#if defined(_WIN32)
	#pragma pack(pop)	
#endif

#endif
