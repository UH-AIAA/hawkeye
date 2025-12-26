// TODO: [NS] add license header
#include <stdio.h>
#include <cmocka.h>

#include "scr_hawkeye.h"
#define HAWKEYE_DBL_EPSILON (1E-12) // some tests hang using standard double epsilon

// function declarations
static void vector3_add(void **state);
static void vector3_sub(void **state);

// global vectors for test
hawkeye_vector3_t a = {
    .x = 4.96756,
    .y = 7.21934,
    .z = 9.12390,
};

hawkeye_vector3_t b = {
    .x = 9.12987,
    .y = 8.12349,
    .z = 1.23895,
};

// entry point
int main(int argc, char* argv[]) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(vector3_add),
        cmocka_unit_test(vector3_sub),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

// test implementations!
static void vector3_add(void **state)
{
    (void)state;

    int retval;
    hawkeye_vector3_t r = {0};

    // test nullpointer cases
    retval = hawkeye_mathutil_vector3_add(NULL, &b, &r);
    assert_int_equal(retval, 1);
    retval = hawkeye_mathutil_vector3_add(&a, NULL, &r);
    assert_int_equal(retval, 1);
    retval = hawkeye_mathutil_vector3_add(&a, &b, NULL);
    assert_int_equal(retval, 1);

    // test nominal add case
    retval = hawkeye_mathutil_vector3_add(&a, &b, &r);
    assert_int_equal(retval, 0);
    assert_double_equal(r.x, 14.09743, HAWKEYE_DBL_EPSILON);
    assert_double_equal(r.y, 15.34283, HAWKEYE_DBL_EPSILON);
    assert_double_equal(r.z, 10.36285, HAWKEYE_DBL_EPSILON);
}

static void vector3_sub(void **state)
{
    (void)state;

    int retval = 0;
    hawkeye_vector3_t r = {0};

    // test nullptr cases
    retval = hawkeye_mathutil_vector3_sub(NULL, &b, &r);
    assert_int_equal(retval, 1);
    retval = hawkeye_mathutil_vector3_sub(&a, NULL, &r);
    assert_int_equal(retval, 1);
    retval = hawkeye_mathutil_vector3_sub(&a, &b, NULL);
    assert_int_equal(retval, 1);

    // test nominal case
    retval = hawkeye_mathutil_vector3_sub(&a, &b, &r);
    assert_int_equal(retval, 0);

    // printf("r.y = %f\n", r.y);
    fflush(stdout);

    assert_double_equal(r.x, -4.16231, HAWKEYE_DBL_EPSILON);
    assert_double_equal(r.y, -0.90415, HAWKEYE_DBL_EPSILON);
    assert_double_equal(r.z, 7.88495, HAWKEYE_DBL_EPSILON);
}
