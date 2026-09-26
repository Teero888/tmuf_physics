#ifndef TMUF_REFERENCE_GM_H
#define TMUF_REFERENCE_GM_H

/* Game math types (Gm*) in the game's memory layout: matrices are stored
   row-major, m[r][c]; a direction d maps to (row 0 . d, row 1 . d, row 2 . d).
   Quaternions are (w, x, y, z).

   Exactness: the game computes with x87 at 24-bit precision, so every
   + - * / sqrt rounds like binary32. Addition and multiplication commute
   exactly; what must match the game is the association of each sum. Helpers
   below document their association; call sites that differ spell it out. */

#include <stdint.h>

#include "reference/fmath.h"

typedef struct gm_vec3 {
  float x, y, z;
} gm_vec3;

typedef struct gm_quat {
  float w, x, y, z;
} gm_quat;

typedef struct gm_mat3 {
  float m[3][3];
} gm_mat3;

typedef struct gm_iso4 {
  gm_mat3 r;
  gm_vec3 t;
} gm_iso4;

typedef struct gm_box {
  gm_vec3 center, half;
} gm_box;

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

#endif
