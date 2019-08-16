#ifndef __PRIVY_DEF_H_
#define __PRIVY_DEF_H_

#include "nsddefines.h"
#include "hdefines.h"

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#pragma pack(push)	
#pragma pack(1)						//1 byte alignment

#else
#include <string.h>
typedef unsigned char GUID[16];
#endif


#define CORE_VERSION				19

/***************************
* local socket
***************************/
#define INNER_USER					"@nsd@"
#define INNER_PWD					"#nsd#"
#define LOCAL_FNAME					"/tmp/nsdipc.domain"
#define SYS_INI_FILE                "/mnt/mtd/code/fixed/sysinfo.ini"

/****************************
* other
****************************/
#define MAX_TASK_MUN				32
#define MAX_LOGON_NUM				16
#define MAX_PREVIEW_NUM				16
#define MAX_IPC_MSG_NUM				256
#define PK_MAGIC_FLAG				0x8877

#define MAX_GB28181_SERVER_NUM		2
#define NSD_PRIVATE_BEGIN_PORT		65000

#define NSD_MAX_VIDEO_FRAME_LEN			(1024*1536)			//1.5M
#define NSD_MAX_AUDIO_FRAME_LEN			(4096*4)


#define NSDCFG_SET_PRESET			(NSDCFG_MAX+1)		//Set up a preset
#define NSDCFG_CLE_PRESET			(NSDCFG_MAX+2)		//clear a preset
#define NSDCFG_GET_PRESET_ALL		(NSDCFG_MAX+3)		//Get all preset 
#define NSDCFG_PRESET_ZOOM_POS		(NSDCFG_MAX+4)		//The zoom position corresponding to the preset
#define NSDCFG_TOUR					(NSDCFG_MAX+5)
#define NSDCFG_TOUR_ALL				(NSDCFG_MAX+6)
#define NSDCFG_TRACK				(NSDCFG_MAX+7)
#define NSDCFG_DIGIT_PTZ			(NSDCFG_MAX+8)
#define NSDCFG_GPIO					(NSDCFG_MAX+9)
#define NSDCFG_WORKING				(NSDCFG_MAX+10)		//Operating parameters

#define NSDCFG_GETYUVDATA			(NSDCFG_MAX+11)
#define NSDCFG_RELEASEYUVDATA		(NSDCFG_MAX+12)
#define NSDCFG_ANALYSERESULT		(NSDCFG_MAX+13)
#define NSDCFG_KEEPALIVE			(NSDCFG_MAX+14)

#define NSDCFG_IMG_2A				(NSDCFG_MAX+15)
#define NSDCFG_DFR					(NSDCFG_MAX+16)		//First run after restoring the default value

//Private PTZ command
#define NSDPTZ_GET_PAN_POS			(NSDPTZ_MAX+1)
#define NSDPTZ_GET_TILT_POS			(NSDPTZ_MAX+2)
#define NSDPTZ_QUARY_ALARM			(NSDPTZ_MAX+3)
#define NSDPTZ_DO					(NSDPTZ_MAX+4)		//0x5F
#define NSDPTZ_REP_ICR				(NSDPTZ_MAX+5)		//Color feedback of image 0x65
#define NSDPTZ_REP_ZOOM_POS			(NSDPTZ_MAX+6)		//Core position feedback 0x67
#define NSDPTZ_REP_ZOOM_TYPE		(NSDPTZ_MAX+7)		//Core type feedback 0x39
#define NSDPTZ_IRC_LEVEL			(NSDPTZ_MAX+8)		//Infrared photosensitivity sensitivity
#define NSDPTZ_IRC_MODE				(NSDPTZ_MAX+9)		//The control mode of the infrared lamp (0: photosensitivity, 1:sensor)
#define NSDPTZ_REP_ZOOM_POS2		(NSDPTZ_MAX+10)		//Multiple feedback zoom 0x6D
#define NSDPTZ_IRC_TEST				(NSDPTZ_MAX+11)		//Test and set current photosensitivity (internal use)
#define NSDPTZ_DEFAULT				(NSDPTZ_MAX+12)		//PTZ restore the default value
#define NSDPTZ_POWER_MEMORY			(NSDPTZ_MAX+13)		//Power cut memory switch setting
#define NSDPTZ_POWER_UP_ACTION		(NSDPTZ_MAX+14)		//Power up action
#define NSDPTZ_KEEP_ACTION			(NSDPTZ_MAX+15)		//Guard position
#define NSDPTZ_TRIGGER_ALARM		(NSDPTZ_MAX+16)		//Trigger alarm
#define NSDPTZ_CANCEL_ALARM			(NSDPTZ_MAX+17)		//Cancel the alarm
#define NSDPTZ_FOCUS_ABS_ADD		(NSDPTZ_MAX+18)	    //step add
#define NSDPTZ_FOCUS_ABS_SUB		(NSDPTZ_MAX+19)	    //step sub
#define NSDPTZ_OSD					(NSDPTZ_MAX+20)	    //Switching OSD state (data1:0-off,1-on)


#define	NSD_HW_PLATFORM_HI3516A		1
#define	NSD_HW_PLATFORM_HI3516C		2
#define	NSD_HW_PLATFORM_HI3516D		3
#define	NSD_HW_PLATFORM_HI3518E		4
#define	NSD_HW_PLATFORM_HI3519		5
#define	NSD_HW_PLATFORM_HI3559		6
#define	NSD_HW_PLATFORM_HI3531		7
#define	NSD_HW_PLATFORM_HI3519A		8
#define	NSD_HW_PLATFORM_HI3516DV300	9

#define NSD_HISIV2_PLATFORM (_HW_VER == NSD_HW_PLATFORM_HI3559 || _HW_VER == NSD_HW_PLATFORM_HI3519A || _HW_VER == NSD_HW_PLATFORM_HI3516DV300)
#define NSD_HISI_PLATFORM   (_HW_VER>=NSD_HW_PLATFORM_HI3516A && _HW_VER<=NSD_HW_PLATFORM_HI3516DV300)


//1. Application definition
typedef enum _NSD_MODULE_TYPE_E
{
	NSDMOD_MAIN,
	NSDMOD_AUDIO,
	NSDMOD_ETH,
	NSDMOD_IO,
	NSDMOD_NET,
	NSDMOD_PAR,
	NSDMOD_PTZ,
	NSDMOD_SNAP,
	NSDMOD_UART,
	NSDMOD_UTIL,
	NSDMOD_VIDEO,				//10
	NSDMOD_WEB,
	NSDMOD_CGI,
	NSDMOD_REC,
	NSDMOD_FTP,
	NSDMOD_SMTP,
	NSDMOD_WIFI,
	NSDMOD_ONVIF,
	NSDMOD_RTMP,
	NSDMOD_SDCARD,
	NSDMOD_MISC,				//20
	NSDMOD_PT_ZENO,
	NSDMOD_TRANSFER,
	NSDMOD_AI,
	NSDMOD_OWSP,
	NSDMOD_GB28181,
	NSDMOD_YNGT,
	NSDMOD_PLUGIN,
	NSDMOD_RTSP,
	NSDMOD_RSC,
	NSDMOD_TJCL408,				//30
	NSDMOD_YC,
	NSDMOD_PLATFORM,
	NSDMOD_AIMGR,
    NSDMOD_HTTP,
    NSDMOD_GB1400,
    NSDMOD_WEBMGR,
	NSDMOD_MAX,
}NSD_MODULE_TYPE_E;

// each module can contain 32 sub modules
typedef enum _NSD_SUB_MODULE_TYPE_E
{
	NSD_SUBMOD_NONE=0,
	NSD_SUBMOD_VIDEO_ENC=1,
	NSD_SUBMOD_VIDEO_OSD,
	NSD_SUBMOD_VIDEO_MASK,
	NSD_SUBMOD_VIDEO_MD,
	NSD_SUBMOD_VIDEO_ROI,
	NSD_SUBMOD_VIDEO_ISP,
	NSD_SUBMOD_VIDEO_VO,

	NSD_SUBMOD_ONVIF_SEARCH=33,		//32+1
	NSD_SUBMOD_ONVIF_DEVICE,
	NSD_SUBMOD_ONVIF_EVENT,
	NSD_SUBMOD_ONVIF_MEDIA,
	NSD_SUBMOD_ONVIF_PTZ,
	NSD_SUBMOD_ONVIF_IMG,
	NSD_SUBMOD_ONVIF_ANALYTICS,
	NSD_SUBMOD_ONVIF_IO,

	NSD_SUBMOD_MAIN_WTD=65,			//64+1
	NSD_SUBMOD_MAIN_IMPL,
}NSD_SUB_MODULE_TYPE_E;

//2. for baseparam
typedef enum _NSD_PAR_TYPE_E
{
	NSDPAR_SYS			=0x00000001,
	NSDPAR_VIDEO		=0x00000002,
	NSDPAR_AUDIO		=0x00000004,
	NSDPAR_MOTION		=0x00000008,
	NSDPAR_IO			=0x00000010,
	NSDPAR_NET			=0x00000020,
	NSDPAR_USER			=0x00000040,
	NSDPAR_UART			=0x00000080,
	NSDPAR_OSD			=0x00000100,
	NSDPAR_PTZ			=0x00000200,
	NSDPAR_FTP			=0x00000400,
	NSDPAR_SMTP			=0x00000800,
	NSDPAR_ETH			=0x00001000,
	NSDPAR_MASK			=0x00002000,
	NSDPAR_IMG			=0x00004000,
	NSDPAR_VOUT			=0x00008000,
	NSDPAR_PLATFORM		=0x00010000,
	NSDPAR_ROI			=0x00020000,
	NSDPAR_ACTION		=0x00040000,
	NSDPAR_SCHEME		=0x00080000,
	NSDPAR_PRESET		=0x00100000,
	NSDPAR_TOUR			=0x00200000,
	NSDPAR_TRACK		=0x00400000,
	NSDPAR_FISHEYE		=0x00800000,
	NSDPAR_AI			=0x01000000,
	NSDPAR_PANO			=0x02000000,
	NSDPAR_PRIVATE		=0x04000000,
	NSDPAR_AVS			=0x08000000,
	NSDPAR_HEARTBEAT	=0x10000000,
	NSDPAR_USERCONF		=0x20000000,
    NSDPAR_AUTOTRACK    =0x40000000,
}NSD_PAR_TYPE_E;

//sensor type
typedef enum _NSD_SENSOR_TYPE_E
{
	NSD_SENSOR_NONE=0,
	NSD_SENSOR_IMX123,
	NSD_SENSOR_IMX178,
	NSD_SENSOR_IMX185,
	NSD_SENSOR_OV4689,
	NSD_SENSOR_OV5658,
	NSD_SENSOR_IMX225,
	NSD_SENSOR_IMX226,
	NSD_SENSOR_IMX238,
	NSD_SENSOR_IMX274,
	NSD_SENSOR_IMX290,
	NSD_SENSOR_IMX291,
	NSD_SENSOR_IMX323,
	NSD_SENSOR_MN34227,
	NSD_SENSOR_NVP6114,
	NSD_SENSOR_CH7500,
	NSD_SENSOR_IMX477,
	NSD_SENSOR_IMX299,
	NSD_SENSOR_IMX307,
	NSD_SENSOR_IMX327,
	NSD_SENSOR_IMX385,
	NSD_SENSOR_IMX334,
	NSD_SENSOR_IMX123_FISHEYE,
    NSD_SENSOR_IMX385_MIPI,
    NSD_SENSOR_IMX327_2L,
    NSD_SENSOR_IMX307_2L,
    NSD_SENSOR_SC2315E,
    NSD_SENSOR_IMX335,

	NSD_SENSOR_BT1120=200,
	NSD_SENSOR_THERMALIMAGE,
	NSD_SENSOR_HDMI_IN,
	NSD_SENSOR_LVDS_FPGA,
	NSD_SENSOR_BT1120_720P_SP422,
	NSD_SENSOR_BT1120_1080P_SP422,
    NSD_SENSOR_CVBS2MIPI,
}NSD_SENSOR_TYPE_E;

typedef enum _NSD_TEST_TYPE_E
{
	NSD_TEST_EMAIL,
	NSD_TEST_SDCARD,
	NSD_TEST_AUDIO,
	NSD_TEST_RESET,
	NSD_TEST_IRIS,
}NSD_TEST_TYPE_E;

//3. Command code
typedef enum _NSD_CMD_TYPE_E
{
	NSDCMD_SEARCH,						//Search
	NSDCMD_DIRECT_CONFIG,				
	NSDCMD_NOTIFY_CONFIG,				//Notify the local configuration parameter
	NSDCMD_REPORT_CONFIG_RESULT,		//Report local configuration results
	NSDCMD_FEED_DOG,
	NSDCMD_ACT_FTP_UPLOAD,
	NSDCMD_ACT_FTP_DOWNLOAD,
	NSDCMD_ACT_SMTP,
	NSDCMD_SEARCH_2,					

	NSDCMD_CENTER_CONN=100,				//Central mode connection
	NSDCMD_LOGON_CONN,					//Login connection
	NSDCMD_PRIVIEW_CONN,				//Preview connection
	NSDCMD_TALK_CONN,					//Talk connection
	NSDCMD_PICTURE_CONN,				//Snapshot connection
	NSDCMD_SERIAL_CONN,					//Transparent serial port connection
	NSDCMD_REPLAY_CONN,					//Video playback connection

	NSDCMD_CONN_SUSPEND,				//Connection and suspend
	NSDCMD_CONN_RESUME,					//Connection resume
	NSDCMD_DISCONN=199,					//Disconnect

	NSDCMD_PREVIEW_DATA=200,			//Stream data
	NSDCMD_PICTURE_DATA,				//Picture data
	NSDCMD_TALK_DATA,					//Talk data
	NSDCMD_SERIAL_DATA,					//Transparent serial data
	NSDCMD_REPLAY_DATA,					//Video playback data
	NSDCMD_DOWNLOAD_DATA,

	NSDCMD_PREVIEW_CTRL=300,
	NSDCMD_PICTURE_CTRL,
	NSDCMD_TALK_CTRL,
	NSDCMD_SERIAL_CTRL,
	NSDCMD_CHANNEL_CTRL,

	NSDCMD_KEEPALIVE=400,				//keep a live
	NSDCMD_ALARM,						//Alarm info
	NSDCMD_UPDATE_PERCENT,				//Percentage of upgrade
	NSDCMD_UPDATE_FINISH,				//Upgrade end and confirmation
	NSDCMD_GET_CONFIG,					//Get parameters
	NSDCMD_SET_CONFIG,					//Setting parameters
	NSDCMD_IO_CTRL,						//IO control
	NSDCMD_DO_STATUS,					//Relay state
	NSDCMD_GET_CAPABILITY,				//Get the capability
	NSDCMD_QUERY_PRESET,				//Query all preset information		
	NSDCMD_SET_PRESET,					//Set up a preset
	NSDCMD_CLE_PRESET,					//Delete preset
	NSDCMD_SET_TOUR,					//Setting up the tour point (add, delete)
	NSDCMD_QUERY_TOUR,					//Query the tour point 
	NSDCMD_BALL_3D,						//3D positioning of the ball machine
	NSDCMD_MOTION_STATUS,				//Motion detection state
	NSDCMD_GUARD_STATUS,				//Defence or  withdrawal

	
	NSDCMD_LOCAL_MSG=500,				//only for local socket,C->S
	NSDCMD_LOCAL_SERVER_MSG,			//only for local socket,S->C
	NSDCMD_MODULE_MSG,
	NSDCMD_MODULE_SERVER_MSG,

	NSDCMD_REPLAY_SEARCH=600,			//Remote playback search
	NSDCMD_REPLAY_PLAY,					//Remote playback play
	NSDCMD_REPLAY_PAUSE,				//Remote playback pause
	NSDCMD_REPLAY_STOP,					//Remote playback stop
	NSDCMD_REPLAY_SPEED,				//Remote playback speed
	NSDCMD_REPLAY_SEEK,					//Remote playback seek
	NSDCMD_REPLAY_STEP,					//Remote playback step
	NSDCMD_REPLAY_END,					//Remote playback end play
	NSDCMD_REPLAY_QUERY,				//Remote record status query

	NSDCMD_CAPTURE_PICTURE=700,			//Snapshot command
	NSDCMD_REBOOT,						//Reboot
	NSDCMD_DEFAULT_PARAM,				//Factory reset
	NSDCMD_FORCE_KEYFRAME,				//Forced key frame
	NSDCMD_UPDATE,						//Upgrade
	NSDCMD_PTZ_CTRL,					//Ptz control
	NSDCMD_SDCARD_FORMAT,				//Formatting SD card
	NSDCMD_SDCARD_STATUS,				//SD card state
	NSDCMD_MANUFACTURE_TEST,
	NSDCMD_PTZ_GET_POSITION,
	NSDCMD_PTZ_SET_POSITION,
	NSDCMD_LOG_SEARCH,					//Search log
	NSDCMD_KILL_PROCESS,				//Kill main program
	NSDCMD_RELOAD_PARAM,
	NSDCMD_DAY_NIGHT_STATUS,
	NSDCMD_VERIFY_PARAM,
	NSDCMD_INGORE_UPDATE_REBOOT,
	NSDCMD_GET_PANO_BIN,
	NSDCMD_GET_MEDIA_INFO,				//Get the coded SPS and PPS information
	NSDCMD_UPLOAD_FILE,					//Uploading files to the specified directory
	NSDCMD_RESET_AI,
    NSDCMD_SCREEN_LUMA,
}NSD_CMD_TYPE_E;

//4. Log level
typedef enum _NSD_LOG_LEVEL_E
{
	NSDLOG_DEBUG=10,					//Debug information	
	NSDLOG_DEBUG_BLACK,
	NSDLOG_DEBUG_RED,
	NSDLOG_DEBUG_GREEN,
	NSDLOG_DEBUG_YELLOW,
	NSDLOG_DEBUG_BLUE,
	NSDLOG_DEBUG_MAGENTA,
	NSDLOG_DEBUG_CYAN,
	NSDLOG_DEBUG_WHITE,

	NSDLOG_INFO_NORMAL=20,				//Running information
	NSDLOG_INFO_BLACK,					
	NSDLOG_INFO_RED,
	NSDLOG_INFO,
	NSDLOG_INFO_YELLOW,
	NSDLOG_INFO_BLUE,
	NSDLOG_INFO_MAGENTA,
	NSDLOG_INFO_CYAN,
	NSDLOG_INFO_WHITE,

	NSDLOG_WARN_NORMAL=30,				//Warning information
	NSDLOG_WARN_BLACK,
	NSDLOG_WARN_RED,
	NSDLOG_WARN_GREEN,
	NSDLOG_WARN,
	NSDLOG_WARN_BLUE,
	NSDLOG_WARN_MAGENTA,
	NSDLOG_WARN_CYAN,
	NSDLOG_WARN_WHITE,

	NSDLOG_ERROR_NORMAL=40,				//Error information
	NSDLOG_ERROR_BLACK,
	NSDLOG_ERROR,
	NSDLOG_ERROR_GREEN,
	NSDLOG_ERROR_YELLOW,
	NSDLOG_ERROR_BLUE,
	NSDLOG_ERROR_MAGENTA,
	NSDLOG_ERROR_CYAN,
	NSDLOG_ERROR_WHITE,
}NSD_LOG_LEVEL_E;

typedef enum _NSD_IO_TYPE_E
{
	NSDIO_INPUT,
	NSDIO_OUTPUT,
	NSDIO_RESET,
	NSDIO_ICR,
	NSDIO_IR,
	NSDIO_UART,
    NSDIO_EXTIO,
	NSDIO_INNERPTZ=0x80000000,
}NSD_IO_TYPE_E;

typedef enum _NSD_ACTION_FROM_E
{
	NSDFROM_MD				=0x1,
	NSDFROM_DI				=0x2,
	NSDFROM_HOST			=0x4,
	NSDFROM_SCHEDULE		=0x8,
	NSDFROM_ONVIF			=0x10,
	NSDFROM_CGI				=0x20,
	NSDFROM_GB28181			=0x40,
	NSDFROM_NETBROKEN		=0x80,
	NSDFROM_PERIMETER		=0x100,
	NSDFROM_TRIPWIRE		=0x200,
	NSDFROM_FACE			=0x400,
	NSDFROM_OCCLUSION		=0x800,
	NSDFROM_FIREDETECT		=0x1000,
	NSDFROM_VIDEOLOST		=0x2000,
}NSD_ACTION_FROM_E;

typedef enum _NSD_LOG_EVENT_E
{
	NSDLOG_EVENT_RUN,
	NSDLOG_EVENT_USER,					//Change the username and password
	NSDLOG_EVENT_REBOOT,
	NSDLOG_EVENT_DEFAULT,
	NSDLOG_EVENT_UPDATE,
	NSDLOG_EVENT_USER_LOGIN,			//User login
	NSDLOG_EVENT_USER_LOGOUT,			//User cancellation
	NSDLOG_EVENT_NET_ERROR,				//Network failure
	NSDLOG_EVENT_SET_PARAM,				//Modify parameters
}NSD_LOG_EVENT_E;

typedef enum _NSD_PAYLOAD_TYPE_E
{
	NSDPT_BINARY			=0x0,
	NSDPT_XML				=0x1,
	NSDPT_ENCRYPT			=0x10,
	NSDPT_COMPRESS			=0x20,
}NSD_PAYLOAD_TYPE_E;

typedef enum _NSD_CONFIG_RESULT_TYPE_E
{
	NSDCFG_RST_ETH,
	NSDCFG_RST_ETH_STATUS,
	NSDCFG_RST_PPPOE_ADDR,
	NSDCFG_RST_PPPOE_STATUS,
	NSDCFG_RST_PPPOE_CLEAR,
	NSDCFG_RST_PPPOE_ADDTIME,
	NSDCFG_RST_UPNP_WEBPORT,
	NSDCFG_RST_UPNP_DATAPORT,
	NSDCFG_RST_WIFI,
}NSD_CONFIG_RESULT_TYPE_E;


typedef enum _NSD_CACHE_TYPE_E
{
	NSDCACHE_VIDEO=1,
	NSDCACHE_AUDIO,
	NSDCACHE_TALK,
	NSDCACHE_MD,
}NSD_CACHE_TYPE_E;

typedef enum _NSD_REPLAY_CTRL_E
{
	NSD_REPLAY_PLAY=1,
	NSD_REPLAY_PAUSE,
	NSD_REPLAY_SPEED,
	NSD_REPLAY_SEEK,
	NSD_REPLAY_STEP,
}NSD_REPLAY_CTRL_E;

//typedef enum _NSD_COMPANY_E
//{
#define	NSD_COMPANY_NONE				0
#define NSD_COMPANY_UNKNOWN				1
#define NSD_COMPANY_EX					2
#define NSD_COMPANY_YM					3
#define NSD_COMPANY_YC					4
#define NSD_COMPANY_JZ					5
#define NSD_COMPANY_BD					6
#define NSD_COMPANY_CY					7
#define NSD_COMPANY_6D					8
#define NSD_COMPANY_DPX					9
#define NSD_COMPANY_MCV					10
//}NSD_COMPANY_E;

#define	LOCAL_CHANNEL_TYPE_NULL			0
#define	LOCAL_CHANNEL_TYPE_UI			0x01

#define RES_NULL						0
#define RES_QCIF						MAKELONG(160,144)	//MAKELONG(176,144)
#define RES_CIF_240						MAKELONG(320,240)	//MAKELONG(352,240)
#define RES_CIF							MAKELONG(320,288)	//MAKELONG(352,288)
#define RES_CIF_43						MAKELONG(352,288)	//MAKELONG(352,288)
#define RES_VGA							MAKELONG(640,480)
#define RES_480P						MAKELONG(720,480)
#define RES_D1							MAKELONG(704,576)	//MAKELONG(704,576)
#define RES_576P						MAKELONG(720,576)
#define RES_640_640						MAKELONG(640,640)
#define RES_960_480						MAKELONG(960,480)
#define RES_SVGA						MAKELONG(800,600)
#define RES_960_576						MAKELONG(960,576)
#define RES_720P						MAKELONG(1280,720)
#define RES_1_2M						MAKELONG(1280,960)
#define RES_UXGA						MAKELONG(1600,1200)
#define RES_1080P						MAKELONG(1920,1080)
#define RES_1760_1760					MAKELONG(1760,1760)
#define RES_1920_1920					MAKELONG(1920,1920)
#define RES_3M_169						MAKELONG(2304,1296)
#define RES_3M							MAKELONG(2048,1536)
#define RES_3M7_169						MAKELONG(2560,1440)
#define RES_4M							MAKELONG(2592,1520)
#define RES_5M_169						MAKELONG(2976,1674)
#define RES_5M							MAKELONG(2592,1944)
#define RES_8M							MAKELONG(3840,2160)
#define RES_3000_3000					MAKELONG(3000,3000)
#define RES_3060_3060					MAKELONG(3060,3060)
#define RES_4000_3000					MAKELONG(4000,3000)
#define RES_4096_2160					MAKELONG(4096,2160)
#define RES_7680_4320					MAKELONG(7680,4320)
#define RES_3840_8640					MAKELONG(3840,8640)
#define RES_7680_3840					MAKELONG(7680,3840)
#define RES_7680_1920					MAKELONG(7680,1920)
#define RES_4608_1920					MAKELONG(4608,1920)
#define RES_1920_480					MAKELONG(1920,480)
#define RES_1152_480					MAKELONG(1152,480)
#define RES_960_240						MAKELONG(960,240)
#define RES_576_240						MAKELONG(576,240)
#define RES_6000_3000					MAKELONG(6000,3000)
#define RES_4000_2000					MAKELONG(4000,2000)
#define RES_1280_640					MAKELONG(1280,640)
#define RES_960_480						MAKELONG(960,480)
#define RES_7680_4320					MAKELONG(7680,4320)
#define RES_7680_1080					MAKELONG(7680,1080)
#define RES_3840_576					MAKELONG(3840,576)
#define RES_1920_288					MAKELONG(1920,288)
#define RES_1080_1080					MAKELONG(1080,1080)
#define RES_1536_1536					MAKELONG(1536,1536)
#define RES_640_360						MAKELONG(640,360)
#define RES_1440_1440					MAKELONG(1440,1440)
#define RES_1280_1280					MAKELONG(1280,1280)
#define RES_2048_2048					MAKELONG(2048,2048)
#define RES_1408_1408					MAKELONG(1408,1408)
#define RES_5120_3840					MAKELONG(5120,3840)
#define RES_6144_1536					MAKELONG(6144,1536)
#define RES_3072_768					MAKELONG(3072,768)
#define RES_1536_384					MAKELONG(1536,384)
#define RES_3840_3840					MAKELONG(3840,3840)
#define RES_3072_3072					MAKELONG(3072,3072)
#define RES_2592_1536					MAKELONG(2592,1536)
#define RES_6144_1080					MAKELONG(6144,1080)
#define RES_3072_576					MAKELONG(3072,576)
#define RES_1536_288					MAKELONG(1536,288)
#define RES_3072_1920					MAKELONG(3072,1920)
#define RES_1536_960				    MAKELONG(1536,960)
#define RES_768_480					    MAKELONG(768,480)

#define PTTYPE_ONVIF					1
#define PTTYPE_RTMP						2
#define PTTYPE_ZENO						3
#define PTTYPE_OWSP						4
#define PTTYPE_GB28181					5
#define PTTYPE_YNGT						6					//云南公投高速公路
#define PTTYPE_TJCL408					7				
#define PTTYPE_YC						8	
#define PTTYPE_CUSTOMER					9
#define PTTYPE_GB1400 					10

typedef struct _NSD_URL_S
{
	char 				szUrl[LONG_PATH_LEN];			
}PACKED NSD_URL_S,*LPNSD_URL_S;

typedef struct _NSD_WORKING_PARAM_S
{
	unsigned char		u8AlwayOpenStream[MAX_STREAM_NUM];
	unsigned char		rsvd[26];
}PACKED NSD_WORKING_PARAM_S,*LPNSD_WORKING_PARAM_S;

//////////////////////////////////////////
//Platform configuration
typedef struct _NSD_PLATFORM_ONVIF_S
{
	unsigned char		u8Enable;							//1:Enable
	unsigned char		u8EnableTalk;						//Whether there is a intercom function
	unsigned char		u8SyncTime;							//Whether synchronization time is allowed
	unsigned char		u8SyncParam;						//Whether synchronization parameters are allowed
	unsigned char		u8Rsvd1[2];
	unsigned char		u8EnableMeta;						//1:Enable
	unsigned char		u8Authorized;
	char				szCompanyName[NAME_LEN_32];			//Company name
	char				szHostName[NAME_LEN_32];			
	char				szLocation[NAME_LEN_48];			//location information
    unsigned int 		u32WlanIPAddr;					    //wlan IP address
	unsigned char		u8Rsvd2[44];
}PACKED NSD_PLATFORM_ONVIF_S,*LPNSD_PLATFORM_ONVIF_S;

typedef struct _NSD_PLATFORM_RTMP_S
{
	unsigned char		u8Enable;
	unsigned char		rsvd[63];		
	NSD_URL_S 			url[MAX_VIDEO_NUM][MAX_STREAM_NUM];			
}PACKED NSD_PLATFORM_RTMP_S,*LPNSD_PLATFORM_RTMP_S;

typedef struct _NSD_PLATFORM_OWSP_S
{
	unsigned char		u8Enable;
	unsigned char		u8SendAlarm;						//send a warning
	unsigned char		rsvd1[2];
	unsigned char		u8UDID[NAME_LEN_32];
	unsigned char		rsvd2[64];	
}PACKED NSD_PLATFORM_OWSP_S,*LPNSD_PLATFORM_OWSP_S;

typedef struct _GB28181_SERVER_S
{
	char				szServerID[NAME_LEN_32];				//server id
	char				szServerUrl[LONG_PATH_LEN];	
	unsigned short		u16ServerPort;
	unsigned short		u16StreamID;							//stream id
	unsigned char		rsvd[32];
}PACKED GB28181_SERVER_S,*LPGB28181_SERVER_S;

typedef struct _NSD_PLATFORM_GB28181_S
{
	unsigned char		u8Enable;
	unsigned char		u8SyncTime;									//Synchronization time
	unsigned char		u8SinglePES;								//0:multiple PES, 1: non - segmentation PES
	unsigned char		rsvd;
	char				szRegisterID[NAME_LEN_32];					//Registration ID
	char				szVideoID[MAX_VIDEO_NUM][NAME_LEN_32];		//Video channel ID
	char				szVideoAlarmID[MAX_VIDEO_NUM][NAME_LEN_32];	//Motion detection alarm ID
	char				szDiAlarmID[MAX_DI_NUM][NAME_LEN_32];		//DI alarm ID
	char				szUsername[NAME_LEN_32];					//Registered username
	char				szPassword[NAME_LEN_32];
	unsigned short		u16SIPPort;
	unsigned short		u16Expire;									//Registration valid time (second), default: 3600
	unsigned short		u16HeartBeat;								//Heartbeat time (second), default: 60
	unsigned short		rsvd2;
	char				szOwner[NAME_LEN_64];						//Device ownership
	char				szCivilCode[NAME_LEN_64];					//Civil code
	char				szBlock[NAME_LEN_64];						
	char				szAddress[NAME_LEN_64];						//Install address
	GB28181_SERVER_S	server[MAX_GB28181_SERVER_NUM];				//Support multiple national standard platforms at the same time
	unsigned char		rsvd3[64];
}PACKED NSD_PLATFORM_GB28181_S,*LPNSD_PLATFORM_GB28181_S;

typedef NSD_PLATFORM_GB28181_S 			NSD_PLATFORM_YNGT_S;
typedef LPNSD_PLATFORM_GB28181_S 		LPNSD_PLATFORM_YNGT_S;


typedef struct _NSD_PLATFORM_TJCL408_S
{
	unsigned char		u8Enable;
	unsigned char		u8CarriageNo;
	unsigned char		u8Position;
	unsigned char		rsvd;
	char				szCompanyName[NAME_LEN_16];
	unsigned short		u16ListenPort;		
	unsigned char		rsvd2[32];
}PACKED NSD_PLATFORM_TJCL408_S,*LPNSD_PLATFORM_TJCL408_S;

typedef struct _NSD_PLATFORM_YC_S
{
	unsigned char		u8Open;							//0: close 1:open
	unsigned char		u8EnableSSL;					//Enable SSL
	unsigned short		u16Port;						//server port
	unsigned char		rsvd[8];
	unsigned int		u32Interval;					//unit:ms
	char				szIdent[NAME_LEN_32];			//device SN
	char				szDomain[NAME_LEN_64];			//server address
	char				szAPIKey[NAME_LEN_64];			//user api key
	char				szSecretKey[NAME_LEN_64];		//user secret key
	char				szAESKey[NAME_LEN_32];			//user aes key
	char				szAuthPath[PATH_LEN];
	char				szKeepalivePath[PATH_LEN];
	char				szFacePath[PATH_LEN];
	char				szTimePath[PATH_LEN];
}PACKED NSD_PLATFORM_YC_S,*LPNSD_PLATFORM_YC_S;

typedef struct _NSD_PLATFORM_GB1400_S
{
	unsigned char		u8Open;							//0: close 1:open
	unsigned char		rsvd[3];
	unsigned short		u16Port;						//server port
	unsigned short		uDevicePort;					//device port
	char				szDomain[NAME_LEN_64];			//server address
	char				szUsername[NAME_LEN_32];
	char				szPassword[NAME_LEN_64];
	char				szDeviceId[NAME_LEN_24];		//20位device ID
	char				szDeviceName[NAME_LEN_64];
	char				szDeviceType[NAME_LEN_64];
	char				szDeviceIP[NAME_LEN_64];
	char				szPlaceCode[NAME_LEN_16];		//行政区DE (000170)
	float				floatLongitude;					//device jindu
	float				floatLatitude;					//device weidu
	unsigned char		rsvd2[256];
}PACKED NSD_PLATFORM_GB1400_S,*LPNSD_PLATFORM_GB1400_S;

typedef struct _NSD_PLATFORM_CUSTOMER_S
{
    unsigned char		u8Open;							//0: close 1:open
    unsigned char		rsvd;
    unsigned short		u16Port;						//server port
    char				szDomain[NAME_LEN_64];			    //server address
    char				szUsername[NAME_LEN_32];		//username
    char				szPassword[NAME_LEN_32];        //password
    char                rsvd2[636];
}PACKED NSD_PLATFORM_CUSTOMER_S,*LPNSD_PLATFORM_CUSTOMER_S;

////////////////////////////////////////////
//Network Package head
typedef struct _PACKET_HEAD_S
{
	_PACKET_HEAD_S()	{ memset(this,0,sizeof(_PACKET_HEAD_S));
							  u32PacketFlag_f = PK_MAGIC_FLAG; }
	unsigned int		u32PacketFlag_f;							//PK_MAGIC_FLAG
	unsigned int		u32PacketSize_ar;							//Data length (excluding the head itself)
	unsigned short		u16Command_f;								//Command code
	unsigned char		u8PayloadType;								//xml or data
	unsigned char		u8Private;									
	unsigned int		u32ErrCode_a;								//error code
	unsigned int		u32Serino;									//serino
	unsigned int		u32Rsvd;									
	bool CheckFlag()
	{
		return (PK_MAGIC_FLAG == u32PacketFlag_f) ? true : false;
	}
}PACKED PACKET_HEAD_S, *LPPACKET_HEAD_S;

typedef struct _PRESET_STATE_S
{
	NSD_PRESET_CFG_S	preset;
	unsigned int		u32ZoomPos;
	unsigned char		u8Used;
	unsigned char		u8Rsvd[3];
}PACKED PRESET_STATE_S,*LPPRESET_STATE_S;

typedef struct _TRACK_POINT_S
{
	unsigned char u8Used;
	unsigned char u8Cmd;
	unsigned short u16Data1;
	unsigned short u16Data2;
	unsigned short u16Interval;
	unsigned int u32Rsvd;
}PACKED TRACK_POINT_S,*LPTRACK_POINT_S;

typedef struct _TRACK_S
{
	unsigned char u8Used;
	unsigned char u8Rsvd[61];
	unsigned short u16Interval;
	unsigned int u32Zoom_pos;
	unsigned int u32Pt_pos;
	TRACK_POINT_S point[MAX_TRACK_CMD_COUNT];
}PACKED TRACK_S,*LPTRACK_S;

typedef struct _QUERY_RECORD_STATE_S
{
	NSD_TIME_S			tmStart;						//Start time
	NSD_TIME_S			tmEnd;							//End time
	unsigned char		u8ChannelNo;
	unsigned char		u8Rsvd;
	unsigned short		u8MediaType;					//1:Record,2:Picture,3:all
	unsigned char		u8Rsvd2[16];
}PACKED QUERY_RECORD_STATE_S,*LPQUERY_RECORD_STATE_S;

typedef struct _DIGIT_PTZ_S
{
	NSD_PTZ_POS_S		pos[MAX_FISHEYE_WIN_NUM];
}PACKED DIGIT_PTZ_S,*LPDIGIT_PTZ_S;

typedef struct _IO_CTRL_S
{
	unsigned int		u32IOType;
	unsigned short		u16Status;
	unsigned short		u16Mask;
	unsigned int		u32PresistTime;
}PACKED IO_CTRL_S,*LPIO_CTRL_S;
//////////////////////////////////////////
typedef struct _REQ_DIRECT_CFG_S
{
	char				szDeviceID[NAME_LEN_16];		//Device ID
	char				szMachineType[NAME_LEN_48];		//Machine model
	unsigned int		u32GateWay;						//gateway
	unsigned int		u32SubMask;						//mask
	unsigned char		u8MacAddr[6];					//MAC address
	unsigned char		u8ChannelNum;					//Number of channels
	unsigned char		u8Rsvd;
	unsigned short		u16ListenPort;
	unsigned short		u16HttpPort;
	unsigned int		u32LocalIP;
	char				szDeviceName[NAME_LEN_32];		//Device name
	char 				szUserName[NAME_LEN_32];		//user name
	char 				szPassword[NAME_LEN_16];		//user password
	unsigned int		u32DNSIP1;						//IP1 for DNS
	unsigned int		u32DNSIP2;						//IP2 for DNS
	unsigned char		u8DHCP1;						//wired network adapter DHCP switch
	unsigned char		u8DHCP2;						//DNS DHCP switch
	unsigned short		u16UpdatePort;
	
	unsigned short		u16OldListenPort;
	unsigned char		u8Rsvd2[22];
}PACKED REQ_DIRECT_CFG_S, *LPREQ_DIRECT_CFG_S;

typedef struct _CHN_STATUS_CTRL_S
{
	unsigned char		u8Suspend;
	unsigned char		u8Flags[15];
}PACKED CHN_STATUS_CTRL_S,*LPCHN_STATUS_CTRL_S;

typedef struct _REQ_LOGON_S
{
	char				szUserName[NAME_LEN_32];			//user name
	char				szPassword[NAME_LEN_16];			//password
	unsigned short		u16Magic;							//0 or 0x7468
	unsigned short		u16Ver;								//0x1
	unsigned int		u32Flag;							//0: default defense, 1: default withdrawal
	CHN_STATUS_CTRL_S	status_ctrl;
	char				u8Rsvd2[8];
}PACKED REQ_LOGON_S, *LPREQ_LOGON_S;
//preview
typedef struct _REQ_PREVIEW_S
{
	unsigned char 		u8ChannelNo;						//Channel number, base 0 index
	unsigned char		u8StreamId;							//stream, base 1 index
	unsigned char		u8TransProtocal;
	unsigned char		rsvd;						
	unsigned int		u32UdpPort;							//only center mode
	unsigned int		u32UdpIP;							//Multi
	unsigned short		u16Magic;							//0x7468
	unsigned short		u16Ver;								//0x2
	CHN_STATUS_CTRL_S	status_ctrl;
	unsigned int		u32Right;
	char				u8Rsvd2[8];
}PACKED REQ_PREVIEW_S, *LPREQ_PREVIEW_S;

typedef struct _ANS_PREVIEW_S
{
	char				szDeviceID[NAME_LEN_16];			//Device ID
	unsigned char 		u8ChannelNo;						//Channel number
	unsigned char		u8StreamId;							//stream, base 1 index
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd;
	unsigned int		u32Resd;
}PACKED ANS_PREVIEW_S,*LPANS_PREVIEW_S;

//talk
typedef struct _REQ_TALK_S
{
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[3];
	unsigned short		u16Magic;							//0x7468
	unsigned short		u16Ver;								//0x2
	CHN_STATUS_CTRL_S	status_ctrl;
	unsigned int		u32Right;
	char				u8Rsvd2[8];
}PACKED REQ_TALK_S, *LPREQ_TALK_S;

typedef struct _ANS_TALK_S
{
	char				szDeviceID[NAME_LEN_16];			//Device ID
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[3];
	unsigned int		u32Resd;
}PACKED ANS_TALK_S,*LPANS_TALK_S;

//picture
typedef struct _REQ_PICTURE_S
{
	unsigned char 		u8ChannelNo;						//Channel number
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[2];
	unsigned short		u16Magic;							//0x7468
	unsigned short		u16Ver;								//0x2
	CHN_STATUS_CTRL_S	status_ctrl;
	unsigned int		u32Right;
	char				u8Rsvd2[8];
}PACKED REQ_PICTURE_S, *LPREQ_PICTURE_S;

typedef struct _ANS_PICTURE_S
{
	char				szDeviceID[NAME_LEN_16];			//Device ID
	unsigned char 		u8ChannelNo;						//Channel number
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[2];
	unsigned int		u32Resd;
}PACKED ANS_PICTURE_S,*LPANS_PICTURE_S;

//serial
typedef struct _REQ_SERIAL_S
{
	unsigned char		u8ChannelNo;						//Channel number
	unsigned char		u8TransProtocal;
	unsigned char		u8Suspend;							//Stop sending data
	unsigned char		u8Rsvd;
	unsigned short		u16Magic;							//0x7468
	unsigned short		u16Ver;								//0x2
	CHN_STATUS_CTRL_S	status_ctrl;
	unsigned int		u32Right;
	char				u8Rsvd2[8];
}PACKED REQ_SERIAL_S, *LPREQ_SERIAL_S;

typedef struct _ANS_SERIAL_S
{
	char				szDeviceID[NAME_LEN_16];		   
	unsigned char 		u8ChannelNo;				      
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[2];
	unsigned int		u32Resd;
}PACKED ANS_SERIAL_S,*LPANS_SERIAL_S;

//replay
typedef struct _REQ_REPLAY_S
{
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[3];
	unsigned int		u32Serino;
	unsigned short		u16Magic;						//0x7468
	unsigned short		u16Ver;							//0x2
	CHN_STATUS_CTRL_S	status_ctrl;
	unsigned int		u32Right;
	char				u8Rsvd2[8];
}PACKED REQ_REPLAY_S, *LPREQ_REPLAY_S;

typedef struct _ANS_REPLAY_S
{
	char				szDeviceID[NAME_LEN_16];		  
	unsigned char		u8TransProtocal;
	unsigned char		u8Rsvd[3];
	unsigned int		u32Serino;
	unsigned int		u32Resd;
}PACKED ANS_REPLAY_S,*LPANS_REPLAY_S;

//
typedef struct _REQ_CONFIG_S
{
	unsigned short		u16ConfigType;
	unsigned short		u16Append;
}PACKED REQ_CONFIG_S,*LPREQ_CONFIG_S;

typedef struct _REQ_CAPTURE_S
{
	unsigned char		u8ChannelNo;					 
	unsigned char		u8StreamId;						
	unsigned char		u8PicFormat;					//0:JPEG,1:BMP
	unsigned char		u8Rsvd;
}PACKED REQ_CAPTURE_S, *LPREQ_CAPTURE_S;

typedef struct _RP_WIFI_RESULT_S
{
	unsigned int	u32IP;
	unsigned int	u32SubMask;
	unsigned int	u32GateWay;
	unsigned int	u32DNSIP1;
	unsigned int	u32DNSIP2;
}PACKED RP_WIFI_RESULT_S,*LPRP_WIFI_RESULT_S;

typedef struct _DIGIT_PTZ_INFO_S{
	unsigned int	zoompos;
	int				x;
	int				y;
	unsigned int	vi_width;
	unsigned int	vi_height;
	unsigned int	buf_width;
	unsigned int	buf_height;
}PACKED DIGIT_PTZ_INFO_S,*LPDIGIT_PTZ_INFO_S;

typedef struct _GPIO_CONF_S{
	unsigned int	io_input[MAX_DI_NUM];	
	unsigned int	io_output[MAX_DO_NUM];	
	unsigned int	io_uart[MAX_UART_NUM];
	unsigned int	io_reset;
	unsigned int	io_ir;
	unsigned int	io_icr[MAX_IRC_NUM];
    unsigned int    io_ext[MAX_EXTIO_NUM];
}PACKED GPIO_CONF_S,*LPGPIO_CONF_S;

typedef struct _INNER_TEST_S{
	unsigned int	nTestType;
	unsigned int	nChn;
	unsigned int	nTestParam1;
	unsigned int	nTestParam2;
}PACKED INNER_TEST_S,*LPINNER_TEST_S;

typedef struct _REQ_LOG_S
{
	unsigned short		u16Type;
	unsigned char       rsvd1[2];		
	NSD_TIME_S			tmStart;						
	NSD_TIME_S			tmEnd;	
	unsigned char		rsvd2[64];
}PACKED REQ_LOG_S,* LPREQ_LOG_S;

typedef struct _AI_VIDEO_FRAME_S{
	unsigned int	nWidth;						//Image width
	unsigned int	nHeight;					//Image height
	unsigned int	nPixelFormat;				//Pixel format, 1:yuv420, 2:yuv422
	unsigned char *	pYUV[3];					//YUV data, address can not be changed, content can be changed
	unsigned int	nStride[3];					//linesize
	unsigned long	nPts;						//Image time stamp
	void *			pInnerUse;					//Internal use, the user may not modify
}PACKED AI_VIDEO_FRAME_S,*LPAI_VIDEO_FRAME_S;

typedef struct _AE_2A_PARAM_S
{
	unsigned char	u8Mode;
	unsigned char	u8Flag;						//1: parameter value is valid
	unsigned char	rsvd[2];
	unsigned int	u32FixShutterTime;
	unsigned int	u32FixAGain;
	unsigned int	u32FixDGain;
	unsigned int	u32FixISPGain;
	unsigned char	rsvd2[32];
}PACKED AE_2A_PARAM,*LPAE_2A_PARAM;

typedef struct _AWB_2A_PARAM_S
{
	unsigned char	u8Mode;
	unsigned char	u8Flag;						//1: parameter value is valid
	unsigned char	rsvd[2];
	unsigned short	u16RGain;
	unsigned short	u16GRGain;
	unsigned short	u16GBGain;
	unsigned short	u16BGain;
	unsigned char	rsvd2[32];
}PACKED AWB_2A_PARAM,*LPAWB_2A_PARAM;

typedef struct _IMG_2A_PARAM_S{
	AE_2A_PARAM		ae;
	AWB_2A_PARAM	awb;
	unsigned char	rsvd[32];
}PACKED IMG_2A_PARAM_S,*LPIMG_2A_PARAM_S;

typedef struct _YUVAnalyzeResult_S
{
	unsigned int    analyzeType;				//see NSD_AI_ANALYSE_TYPE_E
	unsigned char   resultNumber;				//Number of result
	unsigned char   drawLineFlag;				//1:draw line
	unsigned char   capturePicFlag;				//1:capture
    unsigned short  normalizationX;             //返回结果集的X坐标归一化参数
    unsigned short  normalizationY;             //返回结果集的Y坐标归一化参数
	unsigned char	chn;
	unsigned char	max_area_index;				//inner use,faceResult index
	unsigned char	min_area_index;				//inner use,faceResult index
	unsigned char   rsvd[54];
	unsigned long   timestamp;
	union
	{
		NSD_FACE_RESULT_S		faceResult[128];
		NSD_COMMON_RESULT_S		commonResult[128];
	};
}PACKED YUVAnalyzeResult;

typedef struct _PictureData_S
{
	_PictureData_S()
	{
		m_data				=NULL;
		m_datalen			=0;
		m_savetype			=0;
		m_fromtype			=0;
		m_tick				=0;
		m_createtime		=0;
	}
	~_PictureData_S()
	{
		if(m_data)
			HDSAFEDELETEMAB(m_data);
	}

	unsigned long		m_tick;
	unsigned char *		m_data;
	unsigned long		m_datalen;
	unsigned long		m_savetype;
	unsigned long		m_fromtype;
	double				m_createtime;
	NSD_SNAP_HEAD_S		m_head;
}PACKED PictureData;



#if defined(_WIN32)
#pragma pack(pop)	
#endif

#endif

