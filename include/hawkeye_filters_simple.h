#ifndef HAWKEYE_FILTERS_SIMPLE_H
#define HAWKEYE_FILTERS_SIMPLE_H

#include "scr_hawkeye.h"

// simple online low-pass filter
uint8_t HWK_FILT_lowPass(float raw, float* filtered, const float alpha);

#endif
