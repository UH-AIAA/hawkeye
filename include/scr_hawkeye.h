#ifndef SCR_HAWKEYE_H
#define SCR_HAWKEYE_H

#include <stddef.h>
#include <math.h>
#include <stdint.h>

typedef struct {
    double x, y, z;
} hawkeye_vector3_t;

//////////////////////////////////////////////////////////////////
//                        MATH UTILITIES                        //
//////////////////////////////////////////////////////////////////

/////////////
/* VECTORS */
/////////////

// a + b, output stored in pointer r
int hawkeye_mathutil_vector3_add(hawkeye_vector3_t* a, hawkeye_vector3_t* b, hawkeye_vector3_t* r);

// a - b, output stored in pointer r
int hawkeye_mathutil_vector3_sub(hawkeye_vector3_t* a, hawkeye_vector3_t* b, hawkeye_vector3_t* r);

// || a ||, output stored in pointer r
int hawkeye_mathutil_vector3_norm(hawkeye_vector3_t* a, hawkeye_vector3_t* r);

// a ⋅ b, output stored in pointer r
int hawkeye_mathutil_vector3_dotp(hawkeye_vector3_t* a, hawkeye_vector3_t* b, double* r);

// a x b, output stored in pointer r
int hawkeye_mathutil_vector3_xpro(hawkeye_vector3_t* a, hawkeye_vector3_t* b, hawkeye_vector3_t* r);

// angle between vectors (rad), output stored in pointer r
int hawkeye_mathutil_vector3_theta(hawkeye_vector3_t* a, hawkeye_vector3_t* b, double* r);

// TODO: finish this LOL
/**
 * NAME: HWK_MATH_quadInterp
 * DESC: performs quadratic interpolation as a list of points
 * RET: 0 on success, one on error
 * ARGS: float x[] [IN]:           x values of your input points
 *       float y[] [IN]:           y values of your input points
 *       const uint8_t xSize [IN]: size of x value array
 *       const uint8_t ySize [IN]: size of y value array
 *       float* a [OUT]:           a coefficient
 *       float* b [OUT]:           b coefficient
 *       float* c [OUT]:           c coefficient
 *
 * NOTES: assumes y = ax^2 + bx + c
 *        assumes buffers are unwrapped (see HWK_UTIL_ringBuffer*)
 */
int HWK_MATH_quadInterp(float x[],
                               float y[],
                               const uint8_t xSize,
                               const uint8_t ySize,
                               float* a,
                               float* b,
                               float* c);

#endif
