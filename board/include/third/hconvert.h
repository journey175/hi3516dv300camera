
#ifndef __H_CONVERT_H_
#define __H_CONVERT_H_

#define GetTickCount				__h_get_tick_count
#define __h_format_string			CHString::Format
#define __h_format_string_v			CHString::VFormat
#define __h_split					CHString::Split
#define __h_split_of				CHString::SplitOf
#define __h_str_replace				CHString::Replace
#define __h_stricmp					CHString::stricmp
#define __h_strnicmp				CHString::strnicmp
#define __h_trimleft				CHString::TrimLeft
#define __h_trimright				CHString::TrimRight
#define __h_safe_strncpy			CHString::strncpy
#define __h_long2str				CHString::IntToString
#define __h_ulong2str				CHString::UIntToString
#define __h_float2str				CHString::FloatToString
#define __h_hexstring_2_bytes		CHString::HexStringToByte
#define __h_bytes_2_hexstring		CHString::ByteToHexString

#define __h_convert_to_utf8			CHCharSet::ConvertToUTF8
#define __h_convert_to_gb2312		CHCharSet::ConvertToGB2312
#endif
