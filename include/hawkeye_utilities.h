#ifndef HAWKEYE_UTILITIES_H
#define HAWKEYE_UTILITIES_H

#include "scr_hawkeye.h"

// updates a ring buffer of floats
void HWK_UTIL_updateRingBuffer(float buffer[], const uint8_t size, uint8_t* i, float newValue);

// unwraps a ring buffer in order to an output array
void HWK_UTIL_unwrapRingBuffer(float inputBuffer[], float outputBuffer[], const uint8_t size, const uint8_t head);

#endif
