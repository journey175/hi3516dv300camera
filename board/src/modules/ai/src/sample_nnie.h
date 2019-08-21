#ifndef _SAMPLE_NNIE_H_
#define _SAMPLE_NNIE_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "hi_type.h"
#include "sample_comm_nnie.h"

HI_S32 SAMPLE_SVP_NNIE_SSD_Init(HI_CHAR *pcModelName);

void SAMPLE_SVP_NNIE_SSD_DeInit(void);

HI_S32 SAMPLE_SVP_NNIE_SSD_Check(IVE_IMAGE_S * src, 
SAMPLE_SVP_NNIE_RECT_ARRAY_S * array,
HI_FLOAT *paf32ScoreThr,
HI_U32 check_w,
HI_U32 check_h,
HI_U32 original_w,
HI_U32 original_h
);




#ifdef __cplusplus
}
#endif

#endif /* _SAMPLE_SVP_USER_KERNEL_H_ */
