#include "optimized/fmath.h"

#include <math.h>
#include <string.h>

/* Only IEEE double +, -, *, / and sqrt are used below (all correctly
   rounded everywhere; the build disables contraction into fma). */

static const double PI = 3.14159265358979323846;
static const double HALF_PI = 1.57079632679489661923;
static const double QUARTER_PI = 0.78539816339744830962;
static const double TWO_OVER_PI = 0.63661977236758134308;
/* pi/2 split for Cody-Waite reduction: 33 + 33 + 53 bits. */
static const double HALF_PI_1 = 1.57079632673412561417;
static const double HALF_PI_2 = 6.07710050650619224932e-11;
static const double HALF_PI_3 = 2.02226624879595063154e-21;


/* The series below (the reference's) take a division per term. The fast
   versions evaluate the same polynomials by Horner with the coefficients
   rounded once: both are within a few double ulps of the polynomial, far
   below the 2^8 ulps that to_float_near_mid allows, so where the fast result
   is not near a float rounding midpoint both round to the same float. Near
   one (or near the float subnormal range) the reference's series decides. */
static double sin_poly(double r) {
  double r2 = r * r, t = r, s = r;
  for (int i = 1; i <= 11; i++) {
    t = -t * r2 / (double)((2 * i) * (2 * i + 1));
    s += t;
  }
  return s;
}

static double cos_poly(double r) {
  double r2 = r * r, t = 1.0, s = 1.0;
  for (int i = 1; i <= 11; i++) {
    t = -t * r2 / (double)((2 * i - 1) * (2 * i));
    s += t;
  }
  return s;
}

static inline double sin_fast(double r) {
  const double r2 = r * r;
  double p = -3.868170170630684e-23;
  p = p * r2 + 1.9572941063391263e-20;
  p = p * r2 - 8.22063524662433e-18;
  p = p * r2 + 2.8114572543455206e-15;
  p = p * r2 - 7.647163731819816e-13;
  p = p * r2 + 1.6059043836821613e-10;
  p = p * r2 - 2.505210838544172e-08;
  p = p * r2 + 2.7557319223985893e-06;
  p = p * r2 - 0.0001984126984126984;
  p = p * r2 + 0.008333333333333333;
  p = p * r2 - 0.16666666666666666;
  return r + r * r2 * p;
}

static inline double cos_fast(double r) {
  const double r2 = r * r;
  double p = -8.896791392450574e-22;
  p = p * r2 + 4.110317623312165e-19;
  p = p * r2 - 1.5619206968586225e-16;
  p = p * r2 + 4.779477332387385e-14;
  p = p * r2 - 1.1470745597729725e-11;
  p = p * r2 + 2.08767569878681e-09;
  p = p * r2 - 2.755731922398589e-07;
  p = p * r2 + 2.48015873015873e-05;
  p = p * r2 - 0.001388888888888889;
  p = p * r2 + 0.041666666666666664;
  p = p * r2 - 0.5;
  return 1.0 + r2 * p;
}

/* 1 when rounding y to float may depend on the last 2^8 ulps of y: y within
   2^8 ulps of a midpoint between floats, or near the float subnormal range,
   zero, infinity or NaN */
static inline int near_mid(double y) {
  uint64_t b;
  memcpy(&b, &y, 8);
  const uint64_t e = (b >> 52) & 0x7ffu;
  if (e < 1023u - 120u || e > 1023u + 120u)
    return 1;
  const uint64_t low = b & ((UINT64_C(1) << 29) - 1u);
  return low - ((UINT64_C(1) << 28) - 256u) < 512u;
}

/* 2/pi in 32-bit words, most significant first (after the binary point). */
static const uint32_t TWO_OVER_PI_BITS[] = {
    0xa2f9836e, 0x4e441529, 0xfc2757d1, 0xf534ddc0, 0xdb629599, 0x3c439041, 0xfe5163ab, 0xdebbc561,
};

/* x = k * pi/2 + r with |r| <= ~pi/4; returns k mod 4. */
static unsigned reduce(float xf, double *r) {
  double x = (double)xf;
  double ax = fabs(x);
  if (ax <= QUARTER_PI) {
    *r = x;
    return 0;
  }
  if (ax < 1048576.0) {
    double k = floor(x * TWO_OVER_PI + 0.5);
    *r = ((x - k * HALF_PI_1) - k * HALF_PI_2) - k * HALF_PI_3;
    return (unsigned)(int64_t)k & 3u;
  }
  /* Payne-Hanek: |x| = m * 2^e with a 24-bit integer m. */
  int e;
  double m = frexp(ax, &e);
  uint64_t mi = (uint64_t)ldexp(m, 24);
  e -= 24; /* ax = mi * 2^e, e >= -4 here */
  /* x * 2/pi = mi * 2^e * sum(bits); we need bits around the binary point:
     integer part mod 4 and 62 fraction bits. Bit j (1-based) of 2/pi has
     weight 2^-j, so after scaling it has weight 2^(e-j). */
  uint64_t frac = 0; /* 64 fraction bits of the product */
  unsigned quadrant = 0;
  /* Accumulate mi * word products into a 128-bit window aligned at 2^-64. */
  uint64_t acc_hi = 0, acc_lo = 0; /* value * 2^64, 2 bits of integer kept mod 4 */
  for (int w = 0; w < 8; w++) {
    int top = e - 32 * w;  /* word w covers weights 2^(top-1) .. 2^(top-32) */
    int shift = top - 32 + 64; /* position of the word's lsb in acc (acc lsb = 2^-64) */
    uint64_t prod = mi * (uint64_t)TWO_OVER_PI_BITS[w]; /* < 2^56 */
    /* add prod << shift into (acc_hi:acc_lo), dropping bits >= 2^2 (mod 4) */
    if (shift >= 128 + 2 || shift <= -64)
      continue;
    uint64_t lo, hi;
    if (shift >= 64) {
      lo = 0;
      hi = shift - 64 < 64 ? prod << (shift - 64) : 0;
    } else if (shift >= 0) {
      lo = prod << shift;
      hi = shift ? prod >> (64 - shift) : 0;
    } else {
      lo = prod >> -shift;
      hi = 0;
    }
    uint64_t old = acc_lo;
    acc_lo += lo;
    acc_hi += hi + (acc_lo < old);
  }
  quadrant = (unsigned)(acc_hi & 3u);
  frac = acc_lo;
  double f = ldexp((double)(frac >> 11), -53); /* [0, 1) */
  if (f > 0.5) {
    f -= 1.0;
    quadrant++;
  }
  double rr = f * HALF_PI;
  if (x < 0) {
    rr = -rr;
    quadrant = 0u - quadrant;
  }
  *r = rr;
  return quadrant & 3u;
}

static float sin_q(unsigned q, double r) {
  switch (q) {
  case 0:
    return (float)sin_poly(r);
  case 1:
    return (float)cos_poly(r);
  case 2:
    return (float)-sin_poly(r);
  default:
    return (float)-cos_poly(r);
  }
}

float tmuf_sinf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  if (x == 0.0f)
    return 0.0f; /* the series gives +0 for both zeros */
  double r;
  unsigned q = reduce(x, &r);
  double y = (q & 1u) ? cos_fast(r) : sin_fast(r);
  if (near_mid(y))
    return sin_q(q, r);
  return (float)((q & 2u) ? -y : y);
}

float tmuf_cosf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  double r;
  unsigned q = reduce(x, &r);
  double y = (q & 1u) ? sin_fast(r) : cos_fast(r);
  if (near_mid(y))
    return sin_q((q + 1u) & 3u, r);
  return (float)(((q + 1u) & 2u) ? -y : y);
}

float tmuf_tanf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  double r;
  unsigned q = reduce(x, &r);
  double sf = sin_fast(r), cf = cos_fast(r);
  double y = (q & 1u) ? -cf / sf : sf / cf;
  if (!near_mid(y))
    return (float)y;
  double s = sin_poly(r), c = cos_poly(r);
  return (float)((q & 1u) ? -c / s : s / c);
}

/* atan for t in [0, 1]. */
static double atan_unit_with(double t, int fast) {
  /* two argument halvings: atan(t) = 2 atan(t / (1 + sqrt(1 + t^2))) */
  double u = t / (1.0 + sqrt(1.0 + t * t));
  u = u / (1.0 + sqrt(1.0 + u * u));
  double u2 = u * u;
  if (fast) {
    double p = 0.030303030303030304;
    p = p * u2 - 0.03225806451612903;
    p = p * u2 + 0.034482758620689655;
    p = p * u2 - 0.037037037037037035;
    p = p * u2 + 0.04;
    p = p * u2 - 0.043478260869565216;
    p = p * u2 + 0.047619047619047616;
    p = p * u2 - 0.05263157894736842;
    p = p * u2 + 0.058823529411764705;
    p = p * u2 - 0.06666666666666667;
    p = p * u2 + 0.07692307692307693;
    p = p * u2 - 0.09090909090909091;
    p = p * u2 + 0.1111111111111111;
    p = p * u2 - 0.14285714285714285;
    p = p * u2 + 0.2;
    p = p * u2 - 0.3333333333333333;
    return 4.0 * (u + u * u2 * p);
  }
  double p = u, s = u;
  for (int i = 1; i <= 16; i++) {
    p = -p * u2;
    s += p / (double)(2 * i + 1);
  }
  return 4.0 * s;
}

static double atan2_with(double y, double x, int fast) {
  if (isnan(x) || isnan(y))
    return (double)NAN;
  double ay = fabs(y), ax = fabs(x);
  double a;
  if (ay == 0.0) {
    if (signbit(x))
      return signbit(y) ? -PI : PI;
    return y;
  }
  if (ax == 0.0)
    return signbit(y) ? -HALF_PI : HALF_PI;
  if (isinf(ax) || isinf(ay)) {
    if (isinf(ax) && isinf(ay))
      a = QUARTER_PI;
    else
      a = isinf(ay) ? HALF_PI : 0.0;
  } else {
    a = ay <= ax ? atan_unit_with(ay / ax, fast) : HALF_PI - atan_unit_with(ax / ay, fast);
  }
  if (signbit(x))
    a = PI - a;
  return signbit(y) ? -a : a;
}

static float atan2_f(double y, double x) {
  double a = atan2_with(y, x, 1);
  if (!near_mid(a))
    return (float)a;
  return (float)atan2_with(y, x, 0);
}

float tmuf_atan2f(float y, float x) { return atan2_f((double)y, (double)x); }

float tmuf_atanf(float x) { return atan2_f((double)x, 1.0); }

float tmuf_asinf(float x) {
  if (!(x >= -1.0f && x <= 1.0f))
    return NAN;
  float rad = tmuf_sqrtf((1.0f + x) * (1.0f - x));
  return tmuf_atan2f(x, rad);
}

float tmuf_acosf(float x) {
  if (!(x >= -1.0f && x <= 1.0f))
    return NAN;
  float rad = tmuf_sqrtf((1.0f + x) * (1.0f - x));
  return tmuf_atan2f(rad, x);
}

float tmuf_expf(float xf) {
  double x = (double)xf;
  if (isnan(x))
    return xf;
  if (x > 89.0)
    return INFINITY;
  if (x < -104.0)
    return 0.0f;
  static const double LN2_HI = 6.93147180369123816490e-01, LN2_LO = 1.90821492927058770002e-10;
  double k = floor(x * 1.44269504088896340736 + 0.5);
  double r = (x - k * LN2_HI) - k * LN2_LO;
  double p = 4.779477332387385e-14;
  p = p * r + 7.647163731819816e-13;
  p = p * r + 1.1470745597729725e-11;
  p = p * r + 1.6059043836821613e-10;
  p = p * r + 2.08767569878681e-09;
  p = p * r + 2.505210838544172e-08;
  p = p * r + 2.755731922398589e-07;
  p = p * r + 2.7557319223985893e-06;
  p = p * r + 2.48015873015873e-05;
  p = p * r + 0.0001984126984126984;
  p = p * r + 0.001388888888888889;
  p = p * r + 0.008333333333333333;
  p = p * r + 0.041666666666666664;
  p = p * r + 0.16666666666666666;
  p = p * r + 0.5;
  p = p * r + 1.0;
  double y = ldexp(1.0 + r * p, (int)k);
  if (!near_mid(y))
    return (float)y;
  double t = 1.0, s = 1.0;
  for (int i = 1; i <= 16; i++) {
    t = t * r / (double)i;
    s += t;
  }
  return (float)ldexp(s, (int)k);
}

