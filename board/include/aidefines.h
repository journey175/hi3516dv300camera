#ifndef __AI_DEFINES_H_
#define __AI_DEFINES_H_
#include "nsddefines.h"

#define MAX_POLYGON_NUMBER				8
#define MAX_POLYGON_POINT_NUMBER		8
#define MAX_TRIPWIRE_LINE_NUMBER		8
#define MAX_FACE_ROI_AREA_NUMBER		8
#define MAX_FACE_FILTER_AREA_NUMBER		8

typedef enum _NSD_FACE_SNAP_TYPE_E
{
	NSDFACE_MODE_ENTRY,
	NSDFACE_MODE_LEAVE,
	NSDFACE_MODE_OPTIMAL,
	NSDFACE_MODE_NUMBER,
}NSD_FACE_SNAP_TYPE_E;

typedef enum _NSD_FACE_SCENE_TYPE_E
{
	NSDFACE_SCENE_NORMAL,
	NSDFACE_SCENE_HALL,
	NSDFACE_SCENE_HIGHLIGHT,
}NSD_FACE_SCENE_TYPE_E;

typedef enum _NSD_AUTOTRACK_TYPE_E
{
    NSDAUTO_TRACK_WORKMODE_MANUAL,
    NSDAUTO_TRACK_WORKMODE_AUTO,
    NSDAUTO_TRACK_WORKMODE_SEMIAUTO,
    NSDAUTO_TRACK_WORKMODE_CALIBRATION,
}NSD_AUTOTRACK_TYPE_E;

//polygon
typedef struct _NSD_POLYGON_S
{
	NSD_POINT_S			 point[MAX_POLYGON_POINT_NUMBER];  //The polygon area, -1 represents the illegal point. The value is as wide as a percentage.
}PACKED NSD_POLYGON_S, *LPNSD_POLYGON_S;

//tripwire line
typedef struct _NSD_TRIPWIRE_LINE_S
{
	unsigned char		 u8DoubleDirection;				//0: one-way detection; 1: bi-directional detection
	unsigned char		 rsvd[3];	
	unsigned int		 u32ForbiddenDirection;			//In the case of one-way detection, the detection direction needs to be set.
	NSD_POINT_S			 startPoint;				    //The starting point of a line. The value is as wide as a percentage.
	NSD_POINT_S			 endPoint;						//The end point of a line. The value is as wide as a percentage.
}PACKED NSD_TRIPWIRE_LINE_S, *LPNSD_TRIPWIRE_LINE_S;

//perimeter
typedef struct _NSD_AI_PERIMETER_S
{
	unsigned char		 u8Open;						//1:Enable
	unsigned char		 u8DrawLineFlag;				//0: non - line; 1: line
	unsigned char		 u8Sensitivity;					//Sensitivity(0~100)
	unsigned char		 rsvd2[61];	
	NSD_SEGMENT_S		 segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		 u32ActionId[8];				//Action ID, -1 invalid
	NSD_POLYGON_S		 polygon[MAX_POLYGON_NUMBER];	//polygon
}PACKED NSD_AI_PERIMETER_S,*LPNSD_AI_PERIMETER_S;

//tripwire detection
typedef struct _NSD_AI_TRIPWIRE_S
{
	unsigned char		 u8Open;						//1:Enable
	unsigned char		 u8DrawLineFlag;				//0: non - line; 1: line
	unsigned char		 u8Sensitivity;					//Sensitivity(0~100)
	unsigned char		 rsvd2[61];
	NSD_SEGMENT_S		 segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		 u32ActionId[8];				//Action ID, -1 invalid
	NSD_TRIPWIRE_LINE_S	 line[MAX_TRIPWIRE_LINE_NUMBER];//tripwire line
}PACKED NSD_AI_TRIPWIRE_S,*LPNSD_AI_TRIPWIRE_S;

typedef struct _NSD_AI_S
{
	unsigned short		u16AiImageWidth;
	unsigned short		u16AiImageHeight;
	unsigned char		u8PixelFormat;
	unsigned char		u8FrameAllocType;				//0: 单CPU   1: 多CPU
    unsigned char       u8CacheNumber;                  //缓存数量 2 - 8
    unsigned char       u8CacheNumberForVout;           //缓存数量 2 - 8
	unsigned char		rsvd[124];
}PACKED NSD_AI_S,*LPNSD_AI_S;

//人脸识别
typedef struct _NSD_AI_FACE_S
{
	unsigned char		 u8Open;								//启用标识
	unsigned char		 u8DrawLineFlag;						//是否划线 0:不划线  1:划线
	unsigned char		 u8Sensitivity;							//灵敏度(0~100,灵敏度递增)
	unsigned char		 u8CaptureFaceFlag;						//是否抓取人脸 0:不抓取人脸 1:抓取人脸 2:单原图 3:人脸+原图 
	unsigned short		 u16MinFacePixel;						//最小人脸像素
	unsigned char		 u8Blur;								//模糊值，小于该值不抓拍
	unsigned char		 u8Front;								//正脸值，小于该值不抓拍
	unsigned char		 u8SnapMode;							//抓拍模式 NSD_FACE_SNAP_TYPE_E
	unsigned char		 u8SnapNumber;							//抓拍数量， 在模式为NSDFACE_MODE_NUMBER时生效
	unsigned char		 u8MaxFaceNumber;						//最多人脸数
	unsigned char		 u8LeaveInterval;						//离开间隔，超过该值算离开。单位100ms	//u8SceneMode;	//场景模式
	unsigned short		 u16MaxFacePixel;						//最大人脸像素
	unsigned char		 u8FaceAreaCoefficient;					//人脸区域扩展系数
	unsigned char		 u8PictureEncodeQuality;				//抓图编码质量
	unsigned char		 rsvd2[48];	
	NSD_SEGMENT_S		 segment[MAX_SEGMENT_NUM];				//时间段
	unsigned int		 u32ActionId[8];						//联动id,-1无效
	NSD_AREA_S			 roiArea[MAX_FACE_ROI_AREA_NUMBER];		//人脸的检测区域
	NSD_AREA_S			 filterArea[MAX_FACE_FILTER_AREA_NUMBER];	//不检测人脸的区域
	char				 algVersion[NAME_LEN_64];
	char				 swVersion[NAME_LEN_64];
	unsigned char		 rsvd3[64];	
}PACKED NSD_AI_FACE_S,*LPNSD_AI_FACE_S;

typedef struct _NSD_AI_PLATE_NUMBER_S
{
	unsigned char		u8Open;							//开启车牌分析
	unsigned char		rsvd[127];
}PACKED NSD_AI_PLATE_NUMBER_S,*LPNSD_AI_PLATE_NUMBER_S;

typedef struct _NSD_AI_OBJECT_S
{
	unsigned char		u8Open;							//开启目标跟踪
	unsigned char		rsvd[127];
}PACKED NSD_AI_OBJECT_S,*LPNSD_AI_OBJECT_S;

typedef struct _NSD_AI_OCCLUSION_S
{
	unsigned char		u8Open;							//开启遮挡检测
	unsigned char		u8Sensitivity;					//灵敏度
	unsigned char		rsvd[62];
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		u32ActionId[8];					//Action ID, -1 invalid
}PACKED NSD_AI_OCCLUSION_S,*LPNSD_AI_OCCLUSION_S;

typedef struct _NSD_AI_FIRE_DETECT_S
{
	unsigned char		u8Open;							//开启烟火检测
	unsigned char		u8Sensitivity;					//灵敏度
	unsigned char		u8LensType;						//镜头类型
	unsigned char		rsvd[61];
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		u32ActionId[8];					//Action ID, -1 invalid
}PACKED NSD_AI_FIRE_DETECT_S,*LPNSD_AI_FIRE_DETECT_S;

typedef struct _NSD_AI_VIDEO_LOST_S
{
	unsigned char		u8Open;							//开启视频丢失
	unsigned char		u8Sensitivity;					//灵敏度
	unsigned char		rsvd[62];
	NSD_SEGMENT_S		segment[MAX_SEGMENT_NUM];		//Detection time period
	unsigned int		u32ActionId[8];					//Action ID, -1 invalid
}PACKED NSD_AI_VIDEO_LOST_S,*LPNSD_AI_VIDEO_LOST_S;

typedef struct _NSD_AI_AUTO_TRACK_S
{
    unsigned char    u8SettingMask;                     //0x1: 更新NSD_AI_AUTO_TRACK_S  0x2:更新标定参数 0x3:全部更新
    unsigned char    u8AlgmControl;                     //算法灵敏度: 1~5，默认3
    unsigned char    u8NumFramePropa;                   //画面延迟参数:2到12，默认8
    unsigned char    u8MinFollowDuration;               //目标最小跟踪时间:0到目标跟踪时间，默认3
    unsigned int 	 u32FollowDuration;                 //目标跟踪时间:  1到1000秒，默认10秒
    unsigned char    u8MaxTargetSizeX;                  //水平延展参数: 3到30，默认10
    unsigned char    u8MaxTargetSizeY;                  //垂直延展参数: 3~60，默认15
    unsigned char    u8PtzZoomMin;                      //球机允许最小倍数
    unsigned char    u8PtzZoomMax;                      //球机允许最大倍数
    unsigned short   u16IdleTimeout;                    //恢复跟踪时间: 300
    unsigned short   u16PtzHigh;                        //球机安装高度
    double           dbPtzZoomFactor;                   //球机放大系数: 0.2~2，默认0.4
    unsigned char    u8WorkMode;                        //NSD_AUTOTRACK_TYPE_E
    char             rsvd[63];
}PACKED NSD_AI_AUTO_TRACK_S,*LPNSD_AI_AUTO_TRACK_S;

typedef struct _NSD_FACE_BEHAVIOUR_CFG_S
{
    unsigned char    u8LiveDetectEnable;                //活体检测是否开启
    unsigned char    u81_1Matching;                     //1:1比对
    unsigned char    u81_NMatching;                     //1:n比对
    unsigned char    rsvd[129];
}PACKED NSD_FACE_BEHAVIOUR_CFG_S,* LPNSD_FACE_BEHAVIOUR_CFG_S;

#endif //__AI_DEFINES_H_
