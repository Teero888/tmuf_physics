/* Segment casts against the track's collision (group 4: the static octree
   and the non-static decoration corpora), as the race camera's ground probe
   asks the zone (CHmsCollisionManager::SZone::IntersectSegment): the first
   point of start + t * seg, t in [0, 1], on a collidable surface (records
   with tree flag 0x80) facing it. Checked against the game's 121 logged
   probe hits on a Stadium replay: all within 5e-7. */

#include "tmuf_physics/tmuf_physics.h"

#include <math.h>
#include <string.h>

typedef struct seg {
  float o[3], d[3];
} seg;

static float dot3(const float a[3], const float b[3]) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }

/* the segment's slab test against a box, within [0, best) */
static int seg_box(const seg *s, const float c[3], const float h[3], float best, float *t_out) {
  float t0 = 0.0f, t1 = best;
  for (int k = 0; k < 3; k++) {
    const float lo = c[k] - h[k], hi = c[k] + h[k];
    if (fabsf(s->d[k]) < 1e-20f) {
      if (s->o[k] < lo || s->o[k] > hi)
        return 0;
      continue;
    }
    float a = (lo - s->o[k]) / s->d[k], b = (hi - s->o[k]) / s->d[k];
    if (a > b) {
      const float x = a;
      a = b;
      b = x;
    }
    if (a > t0)
      t0 = a;
    if (b < t1)
      t1 = b;
    if (t0 > t1)
      return 0;
  }
  if (t_out)
    *t_out = t0;
  return 1;
}

static int box_of(const tmuf_box *b, const seg *s, float best) {
  const float c[3] = {b->center.x, b->center.y, b->center.z}, h[3] = {b->half.x, b->half.y, b->half.z};
  return seg_box(s, c, h, best, NULL);
}

/* Moller-Trumbore, the faces the segment comes at only (the game's probe
   passes through a triangle from behind: its logged hits) */
static int seg_tri(const seg *s, const float *a, const float *b, const float *c, float best, float *t_out) {
  const float e1[3] = {b[0] - a[0], b[1] - a[1], b[2] - a[2]}, e2[3] = {c[0] - a[0], c[1] - a[1], c[2] - a[2]};
  const float p[3] = {s->d[1] * e2[2] - s->d[2] * e2[1], s->d[2] * e2[0] - s->d[0] * e2[2],
                      s->d[0] * e2[1] - s->d[1] * e2[0]};
  const float det = dot3(e1, p);
  if (fabsf(det) < 1e-12f)
    return 0;
  const float n[3] = {e1[1] * e2[2] - e1[2] * e2[1], e1[2] * e2[0] - e1[0] * e2[2], e1[0] * e2[1] - e1[1] * e2[0]};
  if (dot3(n, s->d) > 0.0f)
    return 0;
  const float inv = 1.0f / det;
  const float tv[3] = {s->o[0] - a[0], s->o[1] - a[1], s->o[2] - a[2]};
  const float u = dot3(tv, p) * inv;
  if (u < 0.0f || u > 1.0f)
    return 0;
  const float q[3] = {tv[1] * e1[2] - tv[2] * e1[1], tv[2] * e1[0] - tv[0] * e1[2], tv[0] * e1[1] - tv[1] * e1[0]};
  const float v = dot3(s->d, q) * inv;
  if (v < 0.0f || u + v > 1.0f)
    return 0;
  const float t = dot3(e2, q) * inv;
  if (t < 0.0f || t >= best)
    return 0;
  *t_out = t;
  return 1;
}

/* the first hit on a surface, in its own frame */
static int seg_surface(const tmuf_surface *sf, const seg *s, float best, float *t_out) {
  switch (sf->type) {
  case TMUF_SURFACE_BOX:
    return seg_box(s, sf->params, sf->params + 3, best, t_out);
  case TMUF_SURFACE_SPHERE:
  case TMUF_SURFACE_ELLIPSOID: {
    /* scaled into a unit sphere */
    const float r[3] = {sf->params[0], sf->type == TMUF_SURFACE_SPHERE ? sf->params[0] : sf->params[1],
                        sf->type == TMUF_SURFACE_SPHERE ? sf->params[0] : sf->params[2]};
    if (!(r[0] > 0.0f && r[1] > 0.0f && r[2] > 0.0f))
      return 0;
    const float o[3] = {s->o[0] / r[0], s->o[1] / r[1], s->o[2] / r[2]};
    const float d[3] = {s->d[0] / r[0], s->d[1] / r[1], s->d[2] / r[2]};
    const float a = dot3(d, d), b = 2.0f * dot3(o, d), c = dot3(o, o) - 1.0f;
    const float disc = b * b - 4.0f * a * c;
    if (a <= 0.0f || disc < 0.0f)
      return 0;
    float t = (-b - sqrtf(disc)) / (2.0f * a);
    if (t < 0.0f)
      t = c <= 0.0f ? 0.0f : t; /* starting inside */
    if (t < 0.0f || t >= best)
      return 0;
    *t_out = t;
    return 1;
  }
  case TMUF_SURFACE_MESH: {
    int hit = 0;
    for (uint32_t ci = 0; ci < sf->cell_count;) {
      const uint8_t *r = sf->cells + (size_t)ci * 32;
      uint32_t subtree;
      float f[6];
      int32_t tri;
      memcpy(&subtree, r, 4);
      memcpy(f, r + 4, 24);
      memcpy(&tri, r + 28, 4);
      if (!seg_box(s, f, f + 3, best, NULL)) {
        ci += subtree ? subtree : 1;
        continue;
      }
      if (tri >= 0 && (uint32_t)tri < sf->triangle_count) {
        uint32_t idx[3];
        memcpy(idx, sf->triangles + (size_t)tri * 32 + 16, 12);
        if (idx[0] < sf->vertex_count && idx[1] < sf->vertex_count && idx[2] < sf->vertex_count) {
          float t;
          if (seg_tri(s, sf->vertices + 3 * idx[0], sf->vertices + 3 * idx[1], sf->vertices + 3 * idx[2], best, &t)) {
            best = t;
            *t_out = t;
            hit = 1;
          }
        }
      }
      ci++;
    }
    return hit;
  }
  default:
    return 0;
  }
}

static int cast_world(const tmuf_static_world *w, const seg *ws, float *best) {
  int hit = 0;
  for (uint32_t ci = 0; ci < w->cell_count;) {
    const tmuf_static_cell *cell = &w->cells[ci];
    if (!box_of(&cell->bounds, ws, *best)) {
      ci += cell->subtree_count ? cell->subtree_count : 1;
      continue;
    }
    if (cell->record >= 0 && (uint32_t)cell->record < w->record_count) {
      const tmuf_static_record *rec = &w->records[cell->record];
      if ((rec->tree_flags & 0x80u) && rec->surf && box_of(&rec->bounds, ws, *best)) {
        /* into the surface's frame: Rt (p - t), the direction Rt d */
        const tmuf_mat3 *m = &rec->iso.r;
        const float p[3] = {ws->o[0] - rec->iso.t.x, ws->o[1] - rec->iso.t.y, ws->o[2] - rec->iso.t.z};
        seg ls;
        for (int k = 0; k < 3; k++) {
          ls.o[k] = m->m[0][k] * p[0] + m->m[1][k] * p[1] + m->m[2][k] * p[2];
          ls.d[k] = m->m[0][k] * ws->d[0] + m->m[1][k] * ws->d[1] + m->m[2][k] * ws->d[2];
        }
        float t;
        if (seg_surface(rec->surf, &ls, *best, &t)) {
          *best = t;
          hit = 1;
        }
      }
    }
    ci++;
  }
  return hit;
}

int tmuf_track_segment_cast(const tmuf_track *track, const float start[3], const float seg_v[3], float *t_out) {
  const tmuf_sim *sim = track ? tmuf_track_sim(track) : NULL;
  if (!sim)
    return 0;
  const seg ws = {{start[0], start[1], start[2]}, {seg_v[0], seg_v[1], seg_v[2]}};
  float best = 1.0f;
  int hit = cast_world(&sim->world, &ws, &best);
  hit |= cast_world(&sim->nonstatic, &ws, &best);
  if (hit && t_out)
    *t_out = best;
  return hit;
}
