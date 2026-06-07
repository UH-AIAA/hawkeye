// TODO: add licence header
#include <cmocka.h>
#include <hawkeye_filters_simple.h>

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

void FILT_Welford(void **state)
{
    (void)state;

    float testInput[4] = {1.0, 2.0, 3.0, 6.0};
    float means[4] = {1.0, 1.5, 2, 3};
    float variances[4] = {0.0, 0.5, 1, 4.666667};

    float mean = 0;
    float variance = 0;
    float mediaryUnit = 0;
    uint32_t n = 0;

    // test nullptr variations
    FILT_Err_t status = FILT_SUCCESS;

    status = HWK_FILT_Welford(0, NULL, &variance, &mediaryUnit, &n);
    assert_int_equal(status, FILT_ERR_NULLPTR);

    status = HWK_FILT_Welford(0, &mean, NULL, &mediaryUnit, &n);
    assert_int_equal(status, FILT_ERR_NULLPTR);

    status = HWK_FILT_Welford(0, &mean, &variance, NULL, &n);
    assert_int_equal(status, FILT_ERR_NULLPTR);

    status = HWK_FILT_Welford(0, &mean, &variance, &mediaryUnit, NULL);
    assert_int_equal(status, FILT_ERR_NULLPTR);

    // run nominal test
    for(int i = 0; i < 4; i++)
    {
        status = HWK_FILT_Welford(testInput[i], &mean, &variance, &mediaryUnit, &n);
        assert_int_equal(status, FILT_SUCCESS);
        assert_int_equal(n, i + 1);
        assert_float_equal(means[i], mean, 1E-6);
        assert_float_equal(variances[i], variance, 1E-6);
    }
}
