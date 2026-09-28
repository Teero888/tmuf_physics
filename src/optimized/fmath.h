#ifndef TMUF_REFERENCE_FMATH_H
#define TMUF_REFERENCE_FMATH_H

/* Float math with the game's results. The game computes in x87 registers with
   24-bit precision control: +, -, *, /, sqrt round like IEEE binary32, while
   fsin, fcos, fpatan etc. produce extended results that are rounded to
   binary32 when stored. Here transcendental functions are evaluated in double
   with fixed polynomials (no libm, so results are identical on every
   platform) and rounded once to float. */

#include <stdint.h>

float tmuf_sqrtf(float x);
float tmuf_sinf(float x);
float tmuf_cosf(float x);
float tmuf_tanf(float x);
float tmuf_atan2f(float y, float x);
float tmuf_atanf(float x);
float tmuf_asinf(float x);
float tmuf_acosf(float x);
float tmuf_expf(float x);

/* Product of a float and a double constant rounded once to float, as
   fmul qword with 24-bit precision control does. */
float tmuf_mul_fd(float x, double c);

static inline uint32_t tmuf_f2u(float f) {
  union {
    float f;
    uint32_t u;
  } v;
  v.f = f;
  return v.u;
}

static inline float tmuf_u2f(uint32_t u) {
  union {
    float f;
    uint32_t u;
  } v;
  v.u = u;
  return v.f;
}

#endif
