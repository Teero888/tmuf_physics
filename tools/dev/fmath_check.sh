#!/bin/sh
# fmath_check.sh: build tools/dev/fmath_check.c against both backends'
# fmath.c (the reference's symbols renamed) and run it (a few minutes).
set -e
ROOT=$(cd "$(dirname "$0")/../.." && pwd)
T=${TMPDIR:-/tmp}/tmuf_fmath_check
mkdir -p "$T"
FL="-O2 -ffp-contract=off -msse2 -mfpmath=sse -I$ROOT/src -I$ROOT/include"
cc $FL -c "$ROOT/src/optimized/fmath.c" -o "$T/opt.o"
cc $FL -Dtmuf_sinf=r_sinf -Dtmuf_cosf=r_cosf -Dtmuf_tanf=r_tanf -Dtmuf_atanf=r_atanf -Dtmuf_expf=r_expf \
  -Dtmuf_asinf=r_asinf -Dtmuf_acosf=r_acosf -Dtmuf_atan2f=r_atan2f -Dtmuf_sqrtf=r_sqrtf -Dtmuf_mul_fd=r_mul_fd \
  -c "$ROOT/src/reference/fmath.c" -o "$T/ref.o"
cc $FL "$ROOT/tools/dev/fmath_check.c" "$T/opt.o" "$T/ref.o" -o "$T/fmath_check" -lpthread -lm
exec "$T/fmath_check"
