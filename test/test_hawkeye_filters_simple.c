// TODO: add licence header
#include <cmocka.h>
#include <hawkeye_filters_simple.h>

#include <stdio.h>

// test implementations!
void FILT_lowPass(void **state)
{
    (void)state;

    // test setup
    // answers calcualted with filtered = (alpha * y(i)) + ((1 - alpha) * y(i-1))
    float rawVals[5] = {9.12398, 234.78, 123.98234, 1.0, -678234};
    float alpha = 0.7;
    float answers[5] = {6.386786, 166.2620358, 136.6662541, 41.69987623, -474751.29};
    float filtered = 0;
    FILT_Err_t retval = -1;

    // first, test bad input
    retval = HWK_FILT_lowPass(rawVals[0], NULL, 0.5);
    assert_int_equal(retval, 1);
    retval = HWK_FILT_lowPass(rawVals[0], &filtered, -5);
    assert_int_equal(retval, 2);
    retval = HWK_FILT_lowPass(rawVals[0], &filtered, 2);
    assert_int_equal(retval, 2);

    // now, test good input
    for(int i = 0; i < 5; i++)
    {
        HWK_FILT_lowPass(rawVals[i], &filtered, alpha);
        // printf("%f, %f\n", filtered, answers[i]);
        assert_float_equal(filtered, answers[i], 1E-12);
    }


}
