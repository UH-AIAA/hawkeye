#ifndef HAWKEYE_FILTERS_SIMPLE_H
#define HAWKEYE_FILTERS_SIMPLE_H

#include "scr_hawkeye.h"

typedef enum {
    FILT_SUCCESS = 0,
    FILT_ERR_NULLPTR = 1,
    FILT_ERR_INVALID_MULT = 2,
    FILT_ERR_DBZ = 3,
} FILT_Err_t;

// simple online low-pass filter
FILT_Err_t HWK_FILT_lowPass(float raw, float* filtered, const float alpha);

// simple online running, unweighted average
FILT_Err_t HWK_FILT_Welford(float measurement, float* mean, float* variance, float* mediaryUnit, uint32_t* n);

#endif
