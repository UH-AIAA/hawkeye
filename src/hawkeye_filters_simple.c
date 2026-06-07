#include "hawkeye_filters_simple.h"
#include <float.h>
#include <stdio.h>

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

/**
 * NAME: HWK_FILT_Welford
 * AUTH: Nathan Samuell/Nathan Munischke
 * DESC: performs running average using Welford's online algorithm
 * RET:  see FILT_Err_t
 * ARGS: float measurement [IN]:      new measurement to add
 *       float* mean [IN/OUT]:        current online mean
 *       float* variance [IN/OUT]:    current online variance
 *       float* mediaryUnit [IN/OUT]: used in calculation
 *       uint32_t* n [IN/OUT]:        tracks iterations
 * NOTES: assumes that the input to filter is kept track of elsewhere,
 *        this is an "online" algorithm, so the state of the filter is
 *        encapsulated in the in/out variables
 */
FILT_Err_t HWK_FILT_Welford(float measurement, float* mean, float* variance, float* mediaryUnit, uint32_t* n)
{
    // nullptr check
    if(mean == NULL ||variance == NULL || mediaryUnit == NULL || n == NULL)
    {
        return FILT_ERR_NULLPTR;
    }

    // var init
    float weightingFactor = 0;  // weights our input

    // increment iterations
    *n += 1;

    // calculate new input weight
    weightingFactor = measurement - *mean;

    // online update mean
    *mean += weightingFactor / *n;

    // calculate mediary unit
    *mediaryUnit += weightingFactor * (measurement - *mean);

    // update variance
    if(*n > 1)
    {
        // should never be since this is an int,
        // but why not
        if(*n - 1 < FLT_EPSILON)
        {
            return FILT_ERR_DBZ;
        }

        *variance = *mediaryUnit / (*n - 1);
    }
    else
    {
        // no variance if we've only sampled once
        *variance = 0;
    }

    return FILT_SUCCESS;
}
