#include <cmocka.h>


/* define your test function names here */

// hawkeye_mathutil
void vector3_add(void **state);
void vector3_sub(void **state);

// hawkeye_filters_simple
void FILT_lowPass(void **state);

// hawkeye_utilities
void UTIL_updateRingBuffer(void **state);
void UTIL_unwrapRingBuffer(void **state);

// entry point
int main(int argc, char* argv[]) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(vector3_add),
        cmocka_unit_test(vector3_sub),
        cmocka_unit_test(FILT_lowPass),
        cmocka_unit_test(UTIL_updateRingBuffer),
        cmocka_unit_test(UTIL_unwrapRingBuffer),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
