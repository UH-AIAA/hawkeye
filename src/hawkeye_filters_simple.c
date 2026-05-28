#include "hawkeye_filters_simple.h"

/**
 * NAME: HWK_FILT_lowPass
 * AUTH: Nathan Samuell
 * DESC: performs low pass filtering on some value
 * RET:  0 on success
 * ARGS: float raw [IN]:           raw input value
 *       float* filtered [IN/OUT]: running total filtered value
 *       const float alpha [IN]:   alpha filter weight
 * NOTES: assumes that the input to filtered is kept track of elsewhere,
 *        this is an "online" algorithm, so the state of the filter is
 *        encapsulated in that variable
 */
FILT_Err_t HWK_FILT_lowPass(float raw, float* filtered, const float alpha)
{
    // null pointer check
    if(filtered == NULL)
    {
        return FILT_ERR_NULLPTR;
    }
    // alpha must be between 0 and 1
    if(alpha < 0 || alpha > 1)
    {
        return FILT_ERR_INVALID_MULT;
    }

    // update lowpass IIR in place
    *filtered = alpha * raw + (1 - alpha) * (*filtered);

    // success
    return FILT_SUCCESS;
}
