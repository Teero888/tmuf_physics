#include "reference/fmath.h"

#include <math.h>

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

float tmuf_sqrtf(float x) { return (float)sqrt((double)x); }

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

float tmuf_sinf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  double r;
  switch (reduce(x, &r)) {
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

float tmuf_cosf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  double r;
  switch (reduce(x, &r)) {
  case 0:
    return (float)cos_poly(r);
  case 1:
    return (float)-sin_poly(r);
  case 2:
    return (float)-cos_poly(r);
  default:
    return (float)sin_poly(r);
  }
}

float tmuf_tanf(float x) {
  if (isnan(x) || isinf(x))
    return NAN;
  double r;
  unsigned q = reduce(x, &r);
  double s = sin_poly(r), c = cos_poly(r);
  return (float)((q & 1u) ? -c / s : s / c);
}

/* atan for t in [0, 1]. */
static double atan_unit(double t) {
  /* two argument halvings: atan(t) = 2 atan(t / (1 + sqrt(1 + t^2))) */
  double u = t / (1.0 + sqrt(1.0 + t * t));
  u = u / (1.0 + sqrt(1.0 + u * u));
  double u2 = u * u, p = u, s = u;
  for (int i = 1; i <= 16; i++) {
    p = -p * u2;
    s += p / (double)(2 * i + 1);
  }
  return 4.0 * s;
}

static double atan2_d(double y, double x) {
  if (isnan(x) || isnan(y))
    return NAN;
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
    a = ay <= ax ? atan_unit(ay / ax) : HALF_PI - atan_unit(ax / ay);
  }
  if (signbit(x))
    a = PI - a;
  return signbit(y) ? -a : a;
}

float tmuf_atan2f(float y, float x) { return (float)atan2_d((double)y, (double)x); }

float tmuf_atanf(float x) { return (float)atan2_d((double)x, 1.0); }

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
  double t = 1.0, s = 1.0;
  for (int i = 1; i <= 16; i++) {
    t = t * r / (double)i;
    s += t;
  }
  return (float)ldexp(s, (int)k);
}

float tmuf_mul_fd(float xf, double c) {
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
