#ifndef SCR_HAWKEYE_H
#define SCR_HAWKEYE_H

#include <stddef.h>
#include <math.h>

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


#endif
