
#ifndef __COMMON_H_
#define __COMMON_H_

#include <string>
#include "nsddefines.h"
#include "base/hdatetime.h"
using namespace HDSOFT;

int safe_system(const char * cmd);

int safe_system_with_result(const char * cmd, std::string &p_result);

//If reso does not exceed base_reso (width and height are not greater than), return true, otherwise false
bool is_valid_resolution(unsigned int base_reso,unsigned int reso);
unsigned long get_resolution_pixelsize(unsigned int reso);

//Is it a fish eye equipment with hardware correction
bool is_hardware_dewarping_fisheye_machine(const NSD_SYS_INFO_S & sys_info);

//Is it an motorise lens
bool is_motorise_lens_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a deom machine
bool is_dome_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a infrared machine
bool is_ir_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a smart infrared machine
bool is_smart_ir_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a machine with an automatic aperture
bool is_dc_iris_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a panoramic camera
bool is_pano_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a coprocessor AI camera
bool is_coprocessor_ai_machine(const NSD_SYS_INFO_S & sys_info);

//Is it a soft AI camera
bool is_soft_ai_machine(const NSD_SYS_INFO_S & sys_info);

//This kind of machine will store some frame to the cache, in order to draw rectangle to the right frame
bool is_hard_ai_with_cache_machine(const NSD_SYS_INFO_S & sys_info);

bool is_hard_ai_only_draw(const NSD_SYS_INFO_S & sys_info);

//Is it a soft AI camera
bool is_soft_ai_not_draw_on_mainstream_machine(const NSD_SYS_INFO_S & sys_info);

//is_ai_machine=is_coprocessor_ai_machine||is_soft_ai_machine
bool is_ai_machine(const NSD_SYS_INFO_S & sys_info);	

//是否是前置拼接设备
bool is_front_stitching_machine(const NSD_SYS_INFO_S & sys_info);

//前置拼接的标定文件是否存在
bool is_front_stitching_calibration_file_exist();

bool is_front_stitching_brand_machine(const NSD_SYS_INFO_S & sys_info);

bool is_front_stitching_hemisphere_machine(const NSD_SYS_INFO_S & sys_info);

bool is_front_stitching_sphere_machine(const NSD_SYS_INFO_S & sys_info);

bool is_zoom_module_machine(const NSD_SYS_INFO_S & sys_info);

//鹰眼设备
bool is_eagle_eye_machine(const NSD_SYS_INFO_S & sys_info);

//前拼电子哨兵
bool is_fornt_sitching_electronic_sentry(const NSD_SYS_INFO_S & sys_info);

//3516cv500
bool is_platform_hisi3516cv500(const NSD_SYS_INFO_S & sys_info);

//3516d
bool is_platform_hisi3516d(const NSD_SYS_INFO_S & sys_info);

//门禁
bool is_entrance_guard_machine(const NSD_SYS_INFO_S & sys_info);

int NSDTime2HDTime(const NSD_TIME_S & nsdtm,CHDateTime & dt);
int HDTime2NSDTime(const CHDateTime & dt,NSD_TIME_S & nsdtm);

bool ini_getstring(const std::string p_fileName, const std::string p_key, std::string &p_value);
bool ini_getint(const std::string p_fileName, const std::string p_key, int &p_value);

std::string ini_getstring_with_def(const std::string p_fileName, const std::string p_key, const std::string p_default);
int  ini_getint_with_def(const std::string p_fileName, const std::string p_key, int p_default);

#endif