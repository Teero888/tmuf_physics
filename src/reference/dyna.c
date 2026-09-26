#include "reference/dyna.h"

#include <string.h>

static const float VECTOR_EPS2 = 1.0e-10f;
static const float REPLACEMENT_EPS = 0.01f;

void quat_normalize(gm_quat *q) {
  float xy = q->x * q->x + q->w * q->w;
  float len2 = (xy + q->y * q->y) + q->z * q->z;
  float inv = 1.0f / tmuf_sqrtf(len2);
  q->w *= inv;
  q->x *= inv;
  q->y *= inv;
  q->z *= inv;
}

/* GmQuat::Set(const GmMat3 &) */
void quat_from_mat3(gm_quat *q, const gm_mat3 *m) {
  float trace = (m->m[0][0] + m->m[1][1]) + m->m[2][2];
  if (trace > 0.0f) {
    float root = tmuf_sqrtf(trace + 1.0f);
    float scale = 0.5f / root;
    q->w = root * 0.5f;
    q->x = (m->m[2][1] - m->m[1][2]) * scale;
    q->y = (m->m[0][2] - m->m[2][0]) * scale;
    q->z = (m->m[1][0] - m->m[0][1]) * scale;
    return;
  }
  static const int NEXT[3] = {1, 2, 0};
  int i = 0;
  if (m->m[0][0] < m->m[1][1])
    i = 1;
  if (m->m[i][i] < m->m[2][2])
    i = 2;
  int j = NEXT[i], k = NEXT[j];
  float arg = (m->m[i][i] - (m->m[k][k] + m->m[j][j])) + 1.0f;
  float root = tmuf_sqrtf(arg);
  float scale = 0.5f / root;
  float v[3];
  v[i] = root * 0.5f;
  q->w = (m->m[k][j] - m->m[j][k]) * scale;
  v[j] = (m->m[i][j] + m->m[j][i]) * scale;
  v[k] = (m->m[i][k] + m->m[k][i]) * scale;
  q->x = v[0];
  q->y = v[1];
  q->z = v[2];
}

/* SetLocation's inverseInertiaWorld: SetMult(rotation, body) (apply the
   rotation, then the body inertia) then MultTranspose(rotation). */
static void world_inertia(gm_mat3 *out, const gm_mat3 *rot, const gm_mat3 *body) {
  gm_mat3 a = mat3_compose(rot, body);
  *out = mat3_mul_transpose(&a, rot);
}

/* CHmsDyna::SetLocation: write and current state */
void dyna_set_location(dyna *d, const gm_iso4 *loc) {
  dyna_state *w = &d->write;
  quat_from_mat3(&w->quat, &loc->r);
  w->rot = loc->r;
  w->pos = loc->t;
  world_inertia(&w->inv_inertia_world, &w->rot, &d->params.inv_inertia_local);
  dyna_state *s = &d->state;
  s->quat = w->quat;
  s->rot = loc->r;
  s->pos = loc->t;
  s->inv_inertia_world = w->inv_inertia_world;
}

/* CHmsDyna::IntegrateStep */
void dyna_integrate(const dyna *d, const dyna_state *src, dyna_state *dst, float dt) {
  if (d->type == DYNA_FROZEN) {
    *dst = *src;
    return;
  }
  float inv_mass = 1.0f / d->params.mass;
  float fmx = src->force.x * inv_mass, fmy = src->force.y * inv_mass, fmz = src->force.z * inv_mass;

  dst->pos.x = src->lin.x * dt + src->pos.x;
  dst->pos.y = src->pos.y + src->lin.y * dt;
  dst->pos.z = src->pos.z + src->lin.z * dt;
  dst->pos.x = dst->pos.x + src->lin_corr.x * dt;
  dst->pos.y = dst->pos.y + src->lin_corr.y * dt;
  dst->pos.z = dst->pos.z + src->lin_corr.z * dt;
  dst->lin_corr = v3(0.0f, 0.0f, 0.0f);

  dst->lin.x = src->lin.x + fmx * dt;
  dst->lin.y = src->lin.y + fmy * dt;
  dst->lin.z = src->lin.z + dt * fmz;

  if (d->type == DYNA_LINEAR_ONLY) {
    dst->rot = src->rot;
    return;
  }

  gm_vec3 ang_accel = mat3_mul_vec(&src->inv_inertia_world, src->torque);

  float ang2 = (src->ang.y * src->ang.y + src->ang.x * src->ang.x) + src->ang.z * src->ang.z;
  if (!(VECTOR_EPS2 < ang2)) {
    dst->rot = src->rot;
    dst->quat = src->quat;
  } else {
    gm_quat q = src->quat;
    gm_vec3 w = src->ang;
    gm_quat dq;
    dq.w = ((-w.x * q.x - w.y * q.y) - q.z * w.z) * 0.5f;
    dq.x = ((q.w * w.x + w.y * q.z) - q.y * w.z) * 0.5f;
    dq.y = ((w.y * q.w - q.z * w.x) + w.z * q.x) * 0.5f;
    dq.z = ((q.y * w.x - w.y * q.x) + q.w * w.z) * 0.5f;
    dst->quat = src->quat;
    dst->quat.w = dq.w * dt + dst->quat.w;
    dst->quat.x = dq.x * dt + dst->quat.x;
    dst->quat.y = dq.y * dt + dst->quat.y;
    dst->quat.z = dt * dq.z + dst->quat.z;
    quat_normalize(&dst->quat);
    mat3_from_quat(&dst->rot, dst->quat);

    gm_vec3 old_com = mat3_mul_vec(&src->rot, d->params.com);
    gm_vec3 new_com = mat3_mul_vec(&dst->rot, d->params.com);
    dst->pos.x = dst->pos.x - (new_com.x - old_com.x);
    dst->pos.y = dst->pos.y - (new_com.y - old_com.y);
    dst->pos.z = dst->pos.z - (new_com.z - old_com.z);
  }

  dst->ang.x = src->ang.x + ang_accel.x * dt;
  dst->ang.y = src->ang.y + ang_accel.y * dt;
  dst->ang.z = src->ang.z + dt * ang_accel.z;

  if (d->has_max_ang) {
    float len2 = (dst->ang.y * dst->ang.y + dst->ang.x * dst->ang.x) + dst->ang.z * dst->ang.z;
    if (d->max_ang * d->max_ang < len2) {
      float scale = d->max_ang / tmuf_sqrtf(len2);
      dst->ang.x = dst->ang.x * scale;
      dst->ang.y = scale * dst->ang.y;
      dst->ang.z = scale * dst->ang.z;
    }
  }

  /* SetTranspose(rotation); Mult(body); Mult(rotation) */
  gm_mat3 t = mat3_transpose(&dst->rot);
  gm_mat3 a = mat3_compose(&t, &d->params.inv_inertia_local);
  dst->inv_inertia_world = mat3_compose(&a, &dst->rot);
}

void dyna_pre_collision(dyna *d, float dt) {
  dyna_state src = d->state;
  dyna_integrate(d, &src, &d->state, dt);
  d->replacement_count = 0;
}

void dyna_add_replacement(dyna *d, gm_vec3 r) {
  d->active = 1;
  if (d->replacement_count < DYNA_MAX_REPLACEMENTS)
    d->replacements[d->replacement_count++] = r;
}

/* CHmsDyna::ComputeSynthetizedReplacement + ApplyReplacement */
void dyna_post_collision(dyna *d) {
  gm_vec3 out = v3(0.0f, 0.0f, 0.0f);
  uint32_t n = d->replacement_count;
  if (n) {
    const gm_vec3 *it = d->replacements;
    float sx = it[0].x, sy = it[0].y, sz = it[0].z;
    for (uint32_t i = 1; i < n; i++) {
      const gm_vec3 *nx = &it[i];
      float wx = sx, wy = sy, wz = sz;
      float proj = (nx->x * sx + sy * nx->y) + sz * nx->z;
      if (proj > 0.0f) {
        float len2 = sz * sz + (sy * sy + wx * wx);
        if (VECTOR_EPS2 < len2) {
          float pc = proj;
          if (len2 < pc)
            pc = len2;
          float scale = pc / len2;
          wx = wx - scale * wx;
          wy = wy - scale * wy;
          wz = wz - scale * wz;
        }
      }
      sx = wx + nx->x;
      sy = wy + nx->y;
      sz = wz + nx->z;
    }
    float len2 = sz * sz + (sy * sy + sx * sx);
    if (REPLACEMENT_EPS * REPLACEMENT_EPS < len2) {
      float inv = 1.0f / tmuf_sqrtf(len2);
      out.x = sx - REPLACEMENT_EPS * (inv * sx);
      out.y = sy - REPLACEMENT_EPS * (inv * sy);
      out.z = sz - REPLACEMENT_EPS * (inv * sz);
    }
  }
  dyna_state *s = &d->state;
  s->pos.x = s->pos.x + out.x;
  s->pos.y = out.y + s->pos.y;
  s->pos.z = out.z + s->pos.z;
}

void dyna_add_force(dyna *d, gm_vec3 f) {
  dyna_state *s = &d->state;
  s->force.x = s->force.x + f.x;
  s->force.y = f.y + s->force.y;
  s->force.z = f.z + s->force.z;
}

void dyna_add_torque(dyna *d, gm_vec3 t) {
  dyna_state *s = &d->state;
  s->torque.x = s->torque.x + t.x;
  s->torque.y = t.y + s->torque.y;
  s->torque.z = t.z + s->torque.z;
}

/* world center of mass: ((m01 c.y + m00 c.x) + m02 c.z) + pos.x */
static gm_vec3 world_com(const dyna *d) {
  const gm_mat3 *r = &d->state.rot;
  const gm_vec3 c = d->params.com;
  const gm_vec3 p = d->state.pos;
  return v3(((r->m[0][1] * c.y + r->m[0][0] * c.x) + r->m[0][2] * c.z) + p.x,
            ((r->m[1][1] * c.y + r->m[1][0] * c.x) + r->m[1][2] * c.z) + p.y,
            ((r->m[2][1] * c.y + r->m[2][0] * c.x) + r->m[2][2] * c.z) + p.z);
}

void dyna_add_force_at(dyna *d, gm_vec3 f, gm_vec3 point) {
  dyna_add_force(d, f);
  gm_vec3 c = world_com(d);
  float rx = point.x - c.x, ry = point.y - c.y, rz = point.z - c.z;
  gm_vec3 t = v3(ry * f.z - rz * f.y, rz * f.x - rx * f.z, rx * f.y - ry * f.x);
  dyna_state *s = &d->state;
  s->torque.x = s->torque.x + t.x;
  s->torque.y = s->torque.y + t.y;
  s->torque.z = s->torque.z + t.z;
}

void dyna_add_impulse(dyna *d, gm_vec3 imp) {
  if (d->type == DYNA_FROZEN)
    return;
  d->active = 1;
  float inv_mass = 1.0f / d->params.mass;
  dyna_state *s = &d->state;
  s->lin.x = imp.x * inv_mass + s->lin.x;
  s->lin.y = s->lin.y + imp.y * inv_mass;
  s->lin.z = imp.z * inv_mass + s->lin.z;
}

void dyna_add_impulse_at(dyna *d, gm_vec3 imp, gm_vec3 point) {
  if (d->type == DYNA_FROZEN)
    return;
  d->active = 1;
  float inv_mass = 1.0f / d->params.mass;
  dyna_state *s = &d->state;
  s->lin.x = s->lin.x + imp.x * inv_mass;
  s->lin.y = s->lin.y + imp.y * inv_mass;
  s->lin.z = imp.z * inv_mass + s->lin.z;
  if (d->type == DYNA_FULL) {
    /* WorldCenterOfMass via GmIso4 point transform */
    gm_iso4 iso = {s->rot, s->pos};
    gm_vec3 c = iso4_mul_point(&iso, d->params.com);
    float rx = point.x - c.x, ry = point.y - c.y, rz = point.z - c.z;
    gm_vec3 a = v3(ry * imp.z - rz * imp.y, rz * imp.x - rx * imp.z, rx * imp.y - ry * imp.x);
    a = mat3_mul_vec(&s->inv_inertia_world, a);
    s->ang.x = s->ang.x + a.x;
    s->ang.y = s->ang.y + a.y;
    s->ang.z = a.z + s->ang.z;
  }
}

gm_vec3 dyna_speed_at(const dyna *d, gm_vec3 point) {
  if (d->type == DYNA_FROZEN)
    return v3(0.0f, 0.0f, 0.0f);
  const dyna_state *s = &d->state;
  gm_vec3 out = s->lin;
  if (d->type == DYNA_FULL) {
    gm_iso4 iso = {s->rot, s->pos};
    gm_vec3 c = iso4_mul_point(&iso, d->params.com);
    float rx = point.x - c.x, ry = point.y - c.y, rz = point.z - c.z;
    out.x = out.x + (rz * s->ang.y - s->ang.z * ry);
    out.y = out.y + (s->ang.z * rx - rz * s->ang.x);
    out.z = out.z + (ry * s->ang.x - rx * s->ang.y);
  }
  return out;
}

gm_vec3 dyna_local_dir_to_world(const dyna *d, gm_vec3 l) {
  const gm_mat3 *r = &d->state.rot;
  return v3((r->m[0][1] * l.y + r->m[0][0] * l.x) + r->m[0][2] * l.z,
            (r->m[1][0] * l.x + r->m[1][1] * l.y) + r->m[1][2] * l.z,
            (r->m[2][0] * l.x + r->m[2][1] * l.y) + r->m[2][2] * l.z);
}

gm_vec3 dyna_local_point_to_world(const dyna *d, gm_vec3 l) {
  const gm_mat3 *r = &d->state.rot;
  const gm_vec3 p = d->state.pos;
  return v3(((r->m[0][1] * l.y + r->m[0][0] * l.x) + r->m[0][2] * l.z) + p.x,
            ((r->m[1][1] * l.y + r->m[1][0] * l.x) + r->m[1][2] * l.z) + p.y,
            ((r->m[2][1] * l.y + r->m[2][0] * l.x) + r->m[2][2] * l.z) + p.z);
}
