/* fmath_check: the optimized backend's fmath against the reference's, bit for
   bit: every float for the one-argument functions, 2^31 random pairs for
   atan2 (tools/dev/fmath_check.sh builds and runs it). */
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
float tmuf_sinf(float), tmuf_cosf(float), tmuf_tanf(float), tmuf_atanf(float), tmuf_expf(float), tmuf_asinf(float),
    tmuf_acosf(float), tmuf_atan2f(float, float);
float r_sinf(float), r_cosf(float), r_tanf(float), r_atanf(float), r_expf(float), r_asinf(float), r_acosf(float),
    r_atan2f(float, float);
typedef float (*f1)(float);
static f1 A[] = {tmuf_sinf, tmuf_cosf, tmuf_tanf, tmuf_atanf, tmuf_expf, tmuf_asinf, tmuf_acosf};
static f1 B[] = {r_sinf, r_cosf, r_tanf, r_atanf, r_expf, r_asinf, r_acosf};
static const char *N[] = {"sin", "cos", "tan", "atan", "exp", "asin", "acos"};
#define T 7
static unsigned long long bad[T][8];
static unsigned long long bad2[8];
static uint32_t fb(float f) { uint32_t u; memcpy(&u, &f, 4); return u; }
static void *run(void *arg) {
  int id = (int)(intptr_t)arg;
  for (uint64_t u = (uint64_t)id; u < (1ull << 32); u += T) {
    float x; uint32_t v = (uint32_t)u; memcpy(&x, &v, 4);
    for (int f = 0; f < 7; f++) {
      float a = A[f](x), b = B[f](x);
      if (fb(a) != fb(b)) {
        if (bad[id][f]++ < 3) fprintf(stderr, "%s(%a): %a vs %a\n", N[f], (double)x, (double)a, (double)b);
      }
    }
  }
  /* atan2: random pairs */
  uint64_t s = 0x9e3779b97f4a7c15ull * (uint64_t)(id + 1);
  for (uint64_t i = 0; i < (1ull << 31) / T; i++) {
    s ^= s << 13; s ^= s >> 7; s ^= s << 17;
    uint32_t yb = (uint32_t)s, xb = (uint32_t)(s >> 32);
    if (i & 1) { xb = (xb & 0x807fffffu) | ((yb & 0x7f800000u) + (((uint32_t)(s >> 20) & 0x3u) << 23)); }
    float y, x; memcpy(&y, &yb, 4); memcpy(&x, &xb, 4);
    float a = tmuf_atan2f(y, x), b = r_atan2f(y, x);
    if (fb(a) != fb(b) && bad2[id]++ < 3) fprintf(stderr, "atan2(%a, %a): %a vs %a\n", (double)y, (double)x, (double)a, (double)b);
  }
  return NULL;
}
int main(void) {
  pthread_t th[T];
  for (int i = 0; i < T; i++) pthread_create(&th[i], NULL, run, (void *)(intptr_t)i);
  for (int i = 0; i < T; i++) pthread_join(th[i], NULL);
  unsigned long long tot = 0;
  for (int f = 0; f < 7; f++) { unsigned long long n = 0; for (int i = 0; i < T; i++) n += bad[i][f]; printf("%s: %llu mismatches over 2^32\n", N[f], n); tot += n; }
  unsigned long long n2 = 0; for (int i = 0; i < T; i++) n2 += bad2[i];
  printf("atan2: %llu mismatches over %llu pairs\n", n2, (1ull << 31) / T * T);
  return tot || n2;
}
