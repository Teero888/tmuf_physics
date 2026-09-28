#ifndef TMUF_REFERENCE_FMATH_H
#define TMUF_REFERENCE_FMATH_H

/* Float math with the game's results. The game computes in x87 registers with
   24-bit precision control: +, -, *, /, sqrt round like IEEE binary32, while
   fsin, fcos, fpatan etc. produce extended results that are rounded to
   binary32 when stored. Here transcendental functions are evaluated in double
   with fixed polynomials (no libm, so results are identical on every
   platform) and rounded once to float. */

#include <math.h>
#include <stdint.h>

/* IEEE sqrt in single precision. The same as the reference's
   (float)sqrt((double)x): rounding a square root to double and then to float
   is innocuous (53 >= 2 * 24 + 2 bits), so both are the correctly rounded
   float root; this one is a single instruction, inlined. */
static inline float tmuf_sqrtf(float x) { return sqrtf(x); }
float tmuf_sinf(float x);
float tmuf_cosf(float x);
float tmuf_tanf(float x);
float tmuf_atan2f(float y, float x);
float tmuf_atanf(float x);
float tmuf_asinf(float x);
float tmuf_acosf(float x);
float tmuf_expf(float x);

/* Product of a float and a double constant rounded once to float, as
   fmul qword with 24-bit precision control does. Inline, so the split of a
   constant c folds at compile time (the same IEEE operations). */
static inline float tmuf_mul_fd(float xf, double c) {
  /* exact product = x*ch + x*cl (Dekker split of c; both products exact) */
  double x = (double)xf;
  double big = c * 134217729.0; /* 2^27 + 1 */
  double ch = big - (big - c), cl = c - ch;
  double hi = x * ch, lo = x * cl;
  double s = hi + lo;
  double e = (hi - s) + lo; /* exact error of s (|hi| >= |lo|) */
  float f = (float)s;
  double d = s - (double)f;
  if (d == 0.0 || e == 0.0)
    return f;
  float g = nextafterf(f, d > 0 ? INFINITY : -INFINITY);
  double mid = ((double)f + (double)g) * 0.5;
  if (s != mid)
    return f;
  /* s is exactly halfway; the true product lies on the side of e. */
  return (e > 0) == (d > 0) ? g : f;
}


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
