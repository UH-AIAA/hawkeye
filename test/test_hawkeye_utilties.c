// TODO: add license header
#include <cmocka.h>
#include "hawkeye_utilities.h"

#include <string.h>

void UTIL_updateRingBuffer(void **state)
{
    (void)state;

    // test setup
    const uint8_t size = 5;
    uint8_t i = 0;
    float buf[5] = {0, 0, 0, 0, 0};
    float singleAddAnswer[5] = {8.28, 0, 0, 0, 0};
    float wrapAroundAnswer[5] = {5, 6, 2, 3, 4};

    // test single add
    HWK_UTIL_updateRingBuffer(buf, size, &i, 8.28);
    assert_int_equal(i, 1);
    assert_memory_equal(buf, singleAddAnswer, sizeof(buf));
    memset(&buf, 0, sizeof(buf));   // teardown
    i = 0;

    // test wraparound adding
    for(int ii = 0; ii < 7; ii++)
    {
        HWK_UTIL_updateRingBuffer(buf, size, &i, ii);
    }

    assert_int_equal(i, 2);
    assert_memory_equal(buf, wrapAroundAnswer, sizeof(buf));
}


void UTIL_unwrapRingBuffer(void **state)
{
    (void)state;

    // setup
    float buf[5] = {10, 11, 12, 13, 9};
    float ans[5] = {9, 10, 11, 12, 13};
    float out[5] = {0};
    const uint8_t size = 5;
    uint8_t head = 4;

    // test unwrap
    HWK_UTIL_unwrapRingBuffer(buf, out, size, head);
    assert_memory_equal(out, ans, sizeof(out));
}
