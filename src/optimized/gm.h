#ifndef TMUF_REFERENCE_GM_H
#define TMUF_REFERENCE_GM_H

/* Game math types (Gm*) in the game's memory layout: matrices are stored
   row-major, m[r][c]; a direction d maps to (row 0 . d, row 1 . d, row 2 . d).
   Quaternions are (w, x, y, z).

   Exactness: the game computes with x87 at 24-bit precision, so every
   + - * / sqrt rounds like binary32. Addition and multiplication commute
   exactly; what must match the game is the association of each sum. Helpers
   below document their association; call sites that differ spell it out. */

#include <math.h>
#include <stdint.h>

#include <tmuf_physics/tmuf_physics.h>

#include "optimized/fmath.h"

typedef tmuf_vec3 gm_vec3;
typedef tmuf_quat gm_quat;
typedef tmuf_mat3 gm_mat3;
typedef tmuf_iso4 gm_iso4;
typedef tmuf_box gm_box;

static inline gm_vec3 v3(float x, float y, float z) {
  gm_vec3 v = {x, y, z};
  return v;
}

static inline gm_vec3 v3_add(gm_vec3 a, gm_vec3 b) { return v3(a.x + b.x, a.y + b.y, a.z + b.z); }
static inline gm_vec3 v3_sub(gm_vec3 a, gm_vec3 b) { return v3(a.x - b.x, a.y - b.y, a.z - b.z); }
static inline gm_vec3 v3_scale(gm_vec3 a, float s) { return v3(a.x * s, a.y * s, a.z * s); }
static inline gm_vec3 v3_neg(gm_vec3 a) { return v3(-a.x, -a.y, -a.z); }

/* (a.x b.x + a.y b.y) + a.z b.z */
static inline float v3_dot(gm_vec3 a, gm_vec3 b) {
  float xy = a.x * b.x + a.y * b.y;
  return xy + a.z * b.z;
}

static inline float v3_len2(gm_vec3 a) { return v3_dot(a, a); }

static inline gm_vec3 v3_cross(gm_vec3 a, gm_vec3 b) {
  return v3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

static inline gm_vec3 mat3_row(const gm_mat3 *m, int r) { return v3(m->m[r][0], m->m[r][1], m->m[r][2]); }
static inline gm_vec3 mat3_col(const gm_mat3 *m, int c) { return v3(m->m[0][c], m->m[1][c], m->m[2][c]); }

static inline void mat3_identity(gm_mat3 *m) {
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      m->m[r][c] = r == c ? 1.0f : 0.0f;
}

/* GmMath::TransformDirection: (row_i . d) */
static inline gm_vec3 mat3_mul_vec(const gm_mat3 *m, gm_vec3 d) {
  return v3(v3_dot(mat3_row(m, 0), d), v3_dot(mat3_row(m, 1), d), v3_dot(mat3_row(m, 2), d));
}

/* GmMath::TransformDirectionTranspose: (col_i . d) */
static inline gm_vec3 mat3_tmul_vec(const gm_mat3 *m, gm_vec3 d) {
  return v3(v3_dot(mat3_col(m, 0), d), v3_dot(mat3_col(m, 1), d), v3_dot(mat3_col(m, 2), d));
}

/* GmMath::TransformPoint */
static inline gm_vec3 iso4_mul_point(const gm_iso4 *iso, gm_vec3 p) { return v3_add(mat3_mul_vec(&iso->r, p), iso->t); }

/* GmMat3 composition, apply `first` then `second` (GmMat3::SetMult(first,
   second)): result column c = second * (first column c). */
static inline gm_mat3 mat3_compose(const gm_mat3 *first, const gm_mat3 *second) {
  gm_mat3 out;
  for (int c = 0; c < 3; c++) {
    gm_vec3 col = mat3_mul_vec(second, mat3_col(first, c));
    out.m[0][c] = col.x;
    out.m[1][c] = col.y;
    out.m[2][c] = col.z;
  }
  return out;
}

/* GmMat3::MultTranspose(rhs): this = this * rhs^T with columns as basis vectors:
   result column c = (rhs col k . this col c) for k = 0..2 as rows. */
static inline gm_mat3 mat3_mul_transpose(const gm_mat3 *left, const gm_mat3 *right) {
  gm_mat3 out;
  for (int c = 0; c < 3; c++) {
    gm_vec3 lc = mat3_col(left, c);
    for (int k = 0; k < 3; k++)
      out.m[k][c] = v3_dot(mat3_col(right, k), lc);
  }
  return out;
}

static inline gm_mat3 mat3_transpose(const gm_mat3 *a) {
  gm_mat3 out;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      out.m[r][c] = a->m[c][r];
  return out;
}

/* GmMat3::Set(GmQuat) */
static inline void mat3_from_quat(gm_mat3 *m, gm_quat q) {
  float tx = q.x * 2.0f, ty = q.y * 2.0f, tz = q.z * 2.0f;
  float xw2 = q.w * tx, yw2 = q.w * ty, zw2 = q.w * tz;
  float xx2 = q.x * tx, xy2 = q.x * ty, xz2 = q.x * tz;
  float yy2 = q.y * ty, yz2 = q.y * tz, zz2 = q.z * tz;
  /* basis x (column 0), y, z */
  m->m[0][0] = (1.0f - yy2) - zz2;
  m->m[1][0] = xy2 + zw2;
  m->m[2][0] = xz2 - yw2;
  m->m[0][1] = xy2 - zw2;
  m->m[1][1] = (1.0f - xx2) - zz2;
  m->m[2][1] = yz2 + xw2;
  m->m[0][2] = xz2 + yw2;
  m->m[1][2] = yz2 - xw2;
  m->m[2][2] = (1.0f - xx2) - yy2;
}

static inline void iso4_identity(gm_iso4 *iso) {
  mat3_identity(&iso->r);
  iso->t = v3(0.0f, 0.0f, 0.0f);
}

/* GmIso4::SetMult(first, second): apply first, then second. */
static inline gm_iso4 iso4_mult(const gm_iso4 *first, const gm_iso4 *second) {
  gm_iso4 out;
  out.r = mat3_compose(&first->r, &second->r);
  out.t = iso4_mul_point(second, first->t);
  return out;
}

/* GmIso4::SetInverse */
static inline gm_iso4 iso4_inverse(const gm_iso4 *a) {
  gm_iso4 out;
  out.r = mat3_transpose(&a->r);
  out.t = mat3_mul_vec(&out.r, v3_neg(a->t));
  return out;
}

/* GmIso4::MultInverse(rhs): this = this * inverse(rhs) (apply this, then
   the inverse of rhs). */
static inline gm_iso4 iso4_mult_inverse(const gm_iso4 *a, const gm_iso4 *rhs) {
  gm_iso4 inv = iso4_inverse(rhs);
  return iso4_mult(a, &inv);
}

/* GmIso4::SetNUScaleTrans */
static inline gm_iso4 iso4_scale_trans(gm_vec3 scale, gm_vec3 t) {
  gm_iso4 out;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      out.r.m[r][c] = 0.0f;
  out.r.m[0][0] = scale.x;
  out.r.m[1][1] = scale.y;
  out.r.m[2][2] = scale.z;
  out.t = t;
  return out;
}

static inline float gm_min(float a, float b) { return b < a ? b : a; } /* std::min */
static inline float gm_max(float a, float b) { return a < b ? b : a; } /* std::max */
static inline float gm_absf(float a) { return a < 0.0f ? -a : (a == 0.0f ? 0.0f : a); }

/* GmBoxAligned::SetMult(box, iso) */
static inline gm_box box_transform(const gm_box *b, const gm_iso4 *iso) {
  gm_box out;
  out.center = iso4_mul_point(iso, b->center);
  gm_mat3 a;
  for (int r = 0; r < 3; r++)
    for (int c = 0; c < 3; c++)
      a.m[r][c] = fabsf(iso->r.m[r][c]);
  out.half = mat3_mul_vec(&a, b->half);
  return out;
}

static inline int box_axis_overlap(float ca, float ea, float cb, float eb) {
  float dist = fabsf(cb - ca);
  float sum = eb + ea;
  return !(sum < dist);
}

/* GmBoxAligned::TestInter: z, then y, then x */
static inline int box_test_inter(const gm_box *a, const gm_box *b) {
  return box_axis_overlap(a->center.z, a->half.z, b->center.z, b->half.z) &&
         box_axis_overlap(a->center.y, a->half.y, b->center.y, b->half.y) &&
         box_axis_overlap(a->center.x, a->half.x, b->center.x, b->half.x);
}

/* GmBoxAligned::SetMinMax */
static inline gm_box box_from_min_max(gm_vec3 mn, gm_vec3 mx) {
  gm_box out;
  out.center = v3_scale(v3_add(mn, mx), 0.5f);
  out.half = v3_scale(v3_sub(mx, mn), 0.5f);
  return out;
}

/* GmBoxAligned::Union */
static inline void box_union(gm_box *a, const gm_box *b) {
  if (!(a->half.x >= 0.0f)) {
    *a = *b;
    return;
  }
  if (!(b->half.x >= 0.0f))
    return;
  gm_vec3 amin = v3_sub(a->center, a->half), bmin = v3_sub(b->center, b->half);
  gm_vec3 amax = v3_add(a->center, a->half), bmax = v3_add(b->center, b->half);
  *a = box_from_min_max(v3(gm_min(amin.x, bmin.x), gm_min(amin.y, bmin.y), gm_min(amin.z, bmin.z)),
                        v3(gm_max(amax.x, bmax.x), gm_max(amax.y, bmax.y), gm_max(amax.z, bmax.z)));
}

static inline float v3_comp(gm_vec3 v, int axis) { return axis == 0 ? v.x : axis == 1 ? v.y : v.z; }

/* GmBoxAligned::LongestAxis */
static inline int box_longest_axis(const gm_box *b) {
  int axis = 0;
  float longest = b->half.x;
  if (b->half.y > longest) {
    axis = 1;
    longest = b->half.y;
  }
  if (b->half.z > longest)
    axis = 2;
  return axis;
}

#endif
