#include "reference/collide.h"

#include <stdlib.h>
#include <string.h>

static const float COLLISION_DISTANCE = 1.0e-5f;
static const float DIR_EPS2 = 1.0e-5f * 1.0e-5f;
static const float SPHERE_NORMAL_ALIGNMENT = 0.8660254f;

/* ---- buffers ---- */

ref_collision *ref_cbuf_add(ref_cbuf *b) {
  if (b->count == b->cap) {
    uint32_t cap = b->cap ? b->cap * 2 : 64;
    ref_collision *p = realloc(b->items, sizeof *p * cap);
    if (!p)
      abort();
    b->items = p;
    b->cap = cap;
  }
  ref_collision *c = &b->items[b->count++];
  memset(c, 0, sizeof *c);
  return c;
}

void ref_cbuf_clear(ref_cbuf *b) { b->count = 0; }

void ref_cbuf_free(ref_cbuf *b) {
  free(b->items);
  memset(b, 0, sizeof *b);
}

static void cbuf_push(ref_cbuf *b, const ref_collision *c) { *ref_cbuf_add(b) = *c; }

/* ---- vector helpers ---- */

/* GmVec3::NormalizeForCollision */
static gm_vec3 normalize_eps(gm_vec3 v, float eps2) {
  float len2 = v3_dot(v, v);
  if (eps2 < len2)
    v = v3_scale(v, 1.0f / tmuf_sqrtf(len2));
  return v;
}

/* ---- mesh records ---- */

typedef struct mesh_tri {
  gm_vec3 normal;
  uint32_t idx[3];
  uint16_t material;
} mesh_tri;

static mesh_tri read_tri(const ref_surf *s, uint32_t i) {
  const uint8_t *r = s->triangles + (size_t)i * 32;
  mesh_tri t;
  float n[3];
  memcpy(n, r, 12);
  t.normal = v3(n[0], n[1], n[2]);
  memcpy(t.idx, r + 16, 12);
  memcpy(&t.material, r + 28, 2);
  return t;
}

typedef struct mesh_cell {
  uint32_t subtree;
  gm_box bounds;
  int32_t tri;
} mesh_cell;

static mesh_cell read_cell(const ref_surf *s, uint32_t i) {
  const uint8_t *r = s->cells + (size_t)i * 32;
  mesh_cell c;
  float f[6];
  memcpy(&c.subtree, r, 4);
  memcpy(f, r + 4, 24);
  memcpy(&c.tri, r + 28, 4);
  c.bounds.center = v3(f[0], f[1], f[2]);
  c.bounds.half = v3(f[3], f[4], f[5]);
  return c;
}

/* ---- SSphereMeshCollide ---- */

typedef struct sphere_tri {
  ref_cbuf *out;
  gm_vec3 center;
  float radius;
  uint16_t mat_a;
  gm_vec3 tri_normal;
  uint16_t tri_mat;
} sphere_tri;

static void fill_mesh_collision(ref_collision *c, const sphere_tri *s) {
  c->local_mat_a = s->mat_a;
  c->local_mat_b = s->tri_mat;
  c->extra_negated = s->tri_normal;
}

static int emit_feature(sphere_tri *s, gm_vec3 feature, float min_d2, int require_radius) {
  gm_vec3 d = v3_sub(s->center, feature);
  float d2 = v3_dot(d, d);
  if ((require_radius && s->radius * s->radius < d2) || !(min_d2 < d2))
    return 0;
  float dist = tmuf_sqrtf(d2);
  float inv = 1.0f / dist;
  gm_vec3 normal = v3(d.x * inv, d.y * inv, d.z * inv);
  float pscale = (dist - s->radius) * inv;
  gm_vec3 pen = v3(d.x * pscale, d.y * pscale, d.z * pscale);
  float along = v3_dot(pen, s->tri_normal);
  ref_collision *c = ref_cbuf_add(s->out);
  c->normal = normal;
  c->separation = v3_scale(s->tri_normal, along);
  c->point = feature;
  fill_mesh_collision(c, s);
  c->sphere_merge_primary = 0;
  return 1;
}

/* The game's endpoint-B case takes a second square root. */
static int emit_endpoint_b(sphere_tri *s, gm_vec3 feature, float min_d) {
  gm_vec3 d = v3_sub(s->center, feature);
  float d2 = v3_dot(d, d);
  float dist = tmuf_sqrtf(d2);
  if (s->radius * s->radius < dist || !(min_d < dist))
    return 0;
  float ed = tmuf_sqrtf(dist);
  float inv = 1.0f / ed;
  gm_vec3 normal = v3(d.x * inv, d.y * inv, d.z * inv);
  float pscale = (ed - s->radius) * inv;
  gm_vec3 pen = v3(d.x * pscale, d.y * pscale, d.z * pscale);
  float along = v3_dot(pen, s->tri_normal);
  ref_collision *c = ref_cbuf_add(s->out);
  c->normal = normal;
  c->separation = v3_scale(s->tri_normal, along);
  c->point = feature;
  fill_mesh_collision(c, s);
  c->sphere_merge_primary = 0;
  return 1;
}

static int sphere_triangle(sphere_tri *s, const gm_vec3 v[3]) {
  float plane = v3_dot(v3_sub(s->center, v[0]), s->tri_normal);
  if (s->radius < plane || plane < 0.0f)
    return 0;
  float reach = tmuf_sqrtf(s->radius * s->radius - plane * plane);
  gm_vec3 proj = v3_add(s->center, v3_scale(s->tri_normal, -plane));
  for (int e = 0; e < 3; e++) {
    gm_vec3 a = v[e], b = v[e == 2 ? 0 : e + 1];
    gm_vec3 dir = normalize_eps(v3_sub(b, a), DIR_EPS2);
    gm_vec3 en = v3_cross(dir, s->tri_normal);
    float ed = v3_dot(v3_sub(proj, a), en);
    if (reach < ed)
      return 0;
    if (ed > 0.0f) {
      float from_start = v3_dot(v3_sub(proj, a), dir);
      if (from_start < 0.0f)
        return emit_feature(s, a, DIR_EPS2, 1);
      float from_end = v3_dot(v3_sub(proj, b), dir);
      if (!(0.0f < from_end))
        return emit_feature(s, v3_add(proj, v3_scale(en, -ed)), COLLISION_DISTANCE, 0);
      return emit_endpoint_b(s, b, DIR_EPS2);
    }
  }
  if (plane > 0.0f) {
    ref_collision *c = ref_cbuf_add(s->out);
    c->normal = s->tri_normal;
    c->separation = v3_scale(s->tri_normal, plane - s->radius);
    c->point = proj;
    fill_mesh_collision(c, s);
    c->sphere_merge_primary = 1;
    return 1;
  }
  return 0;
}

/* ---- shape pairs ---- */

static float sphere_radius(const ref_surf *s) { return s->params[0]; }
static gm_vec3 ellipsoid_radii(const ref_surf *s) { return v3(s->params[0], s->params[1], s->params[2]); }

static float ellipsoid_bound_radius(const ref_surf *s) {
  float r = s->params[0];
  if (!(s->params[1] <= r))
    r = s->params[1];
  if (!(s->params[2] <= r))
    r = s->params[2];
  return r;
}

static int sphere_sphere(const ref_surf *a, const gm_iso4 *ia, const ref_surf *b, const gm_iso4 *ib, ref_cbuf *out) {
  gm_vec3 ca = ia->t, cb = ib->t;
  gm_vec3 d = v3_sub(cb, ca);
  float ra = sphere_radius(a), rb = sphere_radius(b), rs = ra + rb;
  float d2 = v3_dot(d, d);
  if (!(d2 < rs * rs))
    return 0;
  ref_collision *c = ref_cbuf_add(out);
  float dist = tmuf_sqrtf(d2);
  if (!(COLLISION_DISTANCE < dist)) {
    c->normal = v3(0.0f, -1.0f, 0.0f);
    c->separation = v3(0.0f, rb, 0.0f);
    c->point = ca;
  } else {
    gm_vec3 u = v3_scale(d, 1.0f / dist);
    c->normal = v3_scale(u, -1.0f);
    c->separation = v3_scale(u, rs - dist);
    c->point = v3(ca.x + ra * u.x, ca.y + ra * u.y, ca.z + ra * u.z);
  }
  c->local_mat_a = a->material;
  c->local_mat_b = b->material;
  return 1;
}

static int sphere_ellipsoid(const ref_surf *a, const gm_iso4 *ia, const ref_surf *b, const gm_iso4 *ib,
                            ref_cbuf *out) {
  gm_vec3 ca = ia->t, cb = ib->t;
  gm_vec3 d = v3_sub(cb, ca);
  float ra = sphere_radius(a), rb = ellipsoid_bound_radius(b), rs = ra + rb;
  float d2 = v3_dot(d, d);
  if (!(d2 < rs * rs))
    return 0;
  ref_collision *c = ref_cbuf_add(out);
  float dist = tmuf_sqrtf(d2);
  if (!(COLLISION_DISTANCE < dist)) {
    c->normal = v3(0.0f, -1.0f, 0.0f);
    c->separation = v3(0.0f, rs, 0.0f);
    c->point = ca;
  } else {
    gm_vec3 u = v3_scale(d, 1.0f / dist);
    c->normal = v3_scale(u, -1.0f);
    c->separation = v3_scale(u, rs - dist);
    c->point = v3(ca.x + ra * u.x, ca.y + ra * u.y, ca.z + ra * u.z);
  }
  c->local_mat_a = a->material;
  c->local_mat_b = b->material;
  return 1;
}

static float clampf_(float v, float lo, float hi) { return v > hi ? hi : v < lo ? lo : v; }

static int sphere_box(const ref_surf *a, const gm_iso4 *ia, const ref_surf *b, const gm_iso4 *ib, ref_cbuf *out) {
  gm_vec3 sc = ia->t;
  gm_vec3 local = mat3_tmul_vec(&ib->r, v3_sub(sc, ib->t));
  gm_vec3 bc = v3(b->params[0], b->params[1], b->params[2]);
  gm_vec3 bh = v3(b->params[3], b->params[4], b->params[5]);
  gm_vec3 mn = v3_sub(bc, bh), mx = v3(bc.x + bh.x, bc.y + bh.y, bc.z + bh.z);
  if (mn.x <= local.x && local.x <= mx.x && mn.y <= local.y && local.y <= mx.y && mn.z <= local.z &&
      local.z <= mx.z)
    return 0;
  int axis;
  float face;
  if (local.x < mn.x)
    axis = 0, face = mn.x;
  else if (local.x > mx.x)
    axis = 0, face = mx.x;
  else if (local.y < mn.y)
    axis = 1, face = mn.y;
  else if (local.y > mx.y)
    axis = 1, face = mx.y;
  else if (local.z < mn.z)
    axis = 2, face = mn.z;
  else if (local.z > mx.z)
    axis = 2, face = mx.z;
  else
    return 0;
  float r = sphere_radius(a), r2 = r * r;
  float ad = (axis == 0 ? local.x : axis == 1 ? local.y : local.z) - face;
  if (r2 < ad * ad)
    return 0;
  gm_vec3 closest = v3(axis == 0 ? face : clampf_(local.x, mn.x, mx.x), axis == 1 ? face : clampf_(local.y, mn.y, mx.y),
                       axis == 2 ? face : clampf_(local.z, mn.z, mx.z));
  gm_vec3 ld = v3_sub(local, closest);
  if (v3_dot(ld, ld) > r2)
    return 0;
  gm_vec3 cp = iso4_mul_point(ib, closest);
  gm_vec3 cts = v3_sub(sc, cp);
  float dist = tmuf_sqrtf(v3_dot(cts, cts));
  gm_vec3 n = v3_scale(cts, 1.0f / dist);
  float pscale = dist - tmuf_sqrtf(r2);
  ref_collision *c = ref_cbuf_add(out);
  c->point = cp;
  c->normal = n;
  c->separation = v3_scale(n, pscale);
  c->local_mat_a = a->material;
  c->local_mat_b = b->material;
  return 1;
}

static void mesh_to_world(ref_cbuf *out, uint32_t first, const gm_iso4 *mesh_iso) {
  for (uint32_t i = first; i < out->count; i++) {
    ref_collision *c = &out->items[i];
    c->normal = mat3_mul_vec(&mesh_iso->r, c->normal);
    c->separation = mat3_mul_vec(&mesh_iso->r, c->separation);
    c->point = iso4_mul_point(mesh_iso, c->point);
  }
}

static int sphere_mesh(const ref_surf *a, const gm_iso4 *ia, const ref_surf *m, const gm_iso4 *im, ref_cbuf *out) {
  float r = sphere_radius(a);
  gm_iso4 to_mesh = iso4_mult_inverse(ia, im);
  uint32_t first = out->count;
  gm_box sb = {v3(0.0f, 0.0f, 0.0f), v3(r, r, r)};
  sb = box_transform(&sb, &to_mesh);
  int hit = 0;
  for (uint32_t ci = 0; ci < m->cell_count;) {
    mesh_cell cell = read_cell(m, ci);
    if (!box_test_inter(&sb, &cell.bounds)) {
      ci += cell.subtree;
      continue;
    }
    if (cell.tri >= 0 && (uint32_t)cell.tri < m->triangle_count) {
      mesh_tri t = read_tri(m, (uint32_t)cell.tri);
      gm_vec3 v[3] = {ref_mesh_vertex(m, t.idx[0]), ref_mesh_vertex(m, t.idx[1]), ref_mesh_vertex(m, t.idx[2])};
      sphere_tri st = {out, to_mesh.t, r, a->material, t.normal, t.material};
      if (sphere_triangle(&st, v))
        hit = 1;
    }
    ci++;
  }
  if (hit)
    mesh_to_world(out, first, im);
  return hit;
}

/* GmIso4::ScaleRowsForGmSurf */
static void scale_rows(gm_iso4 *iso, gm_vec3 s) {
  for (int c = 0; c < 3; c++) {
    iso->r.m[0][c] *= s.x;
    iso->r.m[1][c] *= s.y;
    iso->r.m[2][c] *= s.z;
  }
  iso->t.x *= s.x;
  iso->t.y *= s.y;
  iso->t.z *= s.z;
}

static int ellipsoid_mesh(const ref_surf *a, const gm_iso4 *ia, const ref_surf *m, const gm_iso4 *im,
                          ref_cbuf *out) {
  gm_vec3 radii = ellipsoid_radii(a);
  gm_vec3 inv = v3(1.0f / radii.x, 1.0f / radii.y, 1.0f / radii.z);
  gm_iso4 to_mesh = iso4_mult_inverse(ia, im);
  gm_vec3 zero = v3(0.0f, 0.0f, 0.0f);
  gm_box eb = {zero, radii};
  eb = box_transform(&eb, &to_mesh);
  gm_iso4 mesh_to_ell = iso4_inverse(&to_mesh);
  gm_iso4 mesh_to_unit = mesh_to_ell;
  scale_rows(&mesh_to_unit, inv);
  gm_iso4 contact_to_world = iso4_scale_trans(radii, zero);
  contact_to_world = iso4_mult_inverse(&contact_to_world, &mesh_to_ell);
  contact_to_world = iso4_mult(&contact_to_world, im);
  gm_iso4 normal_to_world = iso4_scale_trans(inv, zero);
  normal_to_world = iso4_mult_inverse(&normal_to_world, &mesh_to_ell);
  normal_to_world = iso4_mult(&normal_to_world, im);
  int hit = 0;
  for (uint32_t ci = 0; ci < m->cell_count;) {
    mesh_cell cell = read_cell(m, ci);
    if (!box_test_inter(&eb, &cell.bounds)) {
      ci += cell.subtree;
      continue;
    }
    if (cell.tri >= 0 && (uint32_t)cell.tri < m->triangle_count) {
      mesh_tri t = read_tri(m, (uint32_t)cell.tri);
      gm_vec3 v[3];
      for (int k = 0; k < 3; k++)
        v[k] = iso4_mul_point(&mesh_to_unit, ref_mesh_vertex(m, t.idx[k]));
      gm_vec3 e1 = v3_sub(v[1], v[0]), e2 = v3_sub(v[2], v[0]);
      float nx = e2.z * e1.y - e2.y * e1.z;
      float ny = e1.z * e2.x - e2.z * e1.x;
      float nz = e1.x * e2.y - e2.x * e1.y;
      float n2 = (ny * ny + nx * nx) + nz * nz;
      if (n2 > DIR_EPS2) {
        float in = 1.0f / tmuf_sqrtf(n2);
        gm_vec3 un = v3(nx * in, ny * in, in * nz);
        uint32_t first = out->count;
        sphere_tri st = {out, zero, 1.0f, a->material, un, t.material};
        if (sphere_triangle(&st, v)) {
          for (uint32_t i = first; i < out->count; i++) {
            ref_collision *c = &out->items[i];
            c->point = iso4_mul_point(&contact_to_world, c->point);
            c->normal = normalize_eps(mat3_mul_vec(&normal_to_world.r, c->normal), DIR_EPS2);
            c->separation = mat3_mul_vec(&contact_to_world.r, c->separation);
          }
          hit = 1;
        }
      }
    }
    ci++;
  }
  return hit;
}

/* GmCollision::Neg */
static void collision_neg(ref_collision *c) {
  c->normal = v3_neg(c->normal);
  uint16_t lm = c->local_mat_a;
  uint8_t m = c->mat_a;
  c->separation = v3_neg(c->separation);
  c->local_mat_a = c->local_mat_b;
  c->local_mat_b = lm;
  c->mat_a = c->mat_b;
  c->mat_b = m;
  c->extra_negated = v3_neg(c->extra_negated);
}

static int dispatch(const ref_surf *a, const gm_iso4 *ia, const ref_surf *b, const gm_iso4 *ib, ref_cbuf *out) {
  if (a->type == SURF_SPHERE) {
    switch (b->type) {
    case SURF_SPHERE: return sphere_sphere(a, ia, b, ib, out);
    case SURF_ELLIPSOID: return sphere_ellipsoid(a, ia, b, ib, out);
    case SURF_BOX: return sphere_box(a, ia, b, ib, out);
    case SURF_MESH: return sphere_mesh(a, ia, b, ib, out);
    default: return 0;
    }
  }
  if (a->type == SURF_ELLIPSOID) {
    if (b->type == SURF_SPHERE) {
      uint32_t first = out->count;
      if (!sphere_ellipsoid(b, ib, a, ia, out))
        return 0;
      for (uint32_t i = first; i < out->count; i++)
        collision_neg(&out->items[i]);
      return 1;
    }
    if (b->type == SURF_MESH)
      return ellipsoid_mesh(a, ia, b, ib, out);
    return 0;
  }
  return 0; /* moving boxes / meshes are not used by vehicles */
}

static uint8_t material_id(const ref_surf *s, uint16_t local) {
  return local < s->material_count ? s->material_ids[local] : 0;
}

int ref_surface_collide(const ref_surf *a, const gm_iso4 *ia, const ref_surf *b, const gm_iso4 *ib, ref_cbuf *out) {
  uint32_t first = out->count;
  if (!dispatch(a, ia, b, ib, out))
    return 0;
  for (uint32_t i = first; i < out->count; i++) {
    out->items[i].mat_a = material_id(a, out->items[i].local_mat_a);
    out->items[i].mat_b = material_id(b, out->items[i].local_mat_b);
  }
  return 1;
}

/* ---- moving trees ---- */

static int uses_sphere_buffer(const ref_surf *s) { return s->type == SURF_SPHERE || s->type == SURF_ELLIPSOID; }

int ref_mtree_update_box(ref_mtree *t) {
  int has = 0;
  gm_box box = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}};
  if (t->surf && !(t->surf->geom_box.half.x < 0.0f)) {
    box = t->surf->geom_box;
    has = 1;
  }
  for (uint32_t i = 0; i < t->child_count; i++) {
    ref_mtree *c = t->children[i];
    if (ref_mtree_update_box(c) && !(c->box.half.x < 0.0f)) {
      if (!has) {
        box = c->box;
        has = 1;
      } else {
        box_union(&box, &c->box);
      }
    }
  }
  if (!has) {
    t->box.center = v3(0.0f, 0.0f, 0.0f);
    t->box.half = v3(-1.0f, -1.0f, -1.0f);
    return 0;
  }
  t->box = (t->flags & 4u) ? box_transform(&box, &t->local) : box;
  return 1;
}

static void queue_sphere(ref_detect *d, ref_mtree *t) {
  if (!t->queued && d->queued_count < 64) {
    t->queued = 1;
    d->queued[d->queued_count++] = t;
  }
}

void ref_detect_static(ref_detect *d, ref_mtree *tree, const gm_iso4 *moving_iso) {
  if (!(tree->flags & 0x80u))
    return;
  gm_iso4 local = (tree->flags & 4u) ? iso4_mult(&tree->local, moving_iso) : *moving_iso;
  for (uint32_t i = 0; i < tree->child_count; i++)
    ref_detect_static(d, tree->children[i], &local);
  if (!tree->surf)
    return;
  gm_box mbox = box_transform(&tree->box, moving_iso);
  const ref_world *w = d->world;
  if (w->cell_count <= 1)
    return;
  for (uint32_t ci = 0; ci < w->cell_count;) {
    const ref_static_cell *cell = &w->cells[ci];
    if (!box_test_inter(&mbox, &cell->bounds)) {
      ci += cell->subtree_count;
      continue;
    }
    if (cell->record >= 0) {
      const ref_static_record *rec = &w->records[cell->record];
      if (rec->tree_flags & 0x80u) {
        ref_cbuf *buf = uses_sphere_buffer(tree->surf) ? &tree->sphere : d->out;
        uint32_t first = buf->count;
        if (ref_surface_collide(tree->surf, &local, rec->surf, &rec->iso, buf)) {
          if (buf == &tree->sphere)
            queue_sphere(d, tree);
          for (uint32_t i = first; i < buf->count; i++) {
            ref_collision *c = &buf->items[i];
            c->corpus_a = -1;
            c->tree_a = tree;
            c->corpus_b = (int32_t)rec->corpus;
            c->tree_b = rec;
            c->group_pair = d->group_pair;
          }
        }
      }
    }
    ci++;
  }
}

static int nearly_equal(float v, float ref) {
  float tol = fabsf(ref) * 1.0e-5f;
  return ref - tol <= v && v <= ref + tol;
}

static int vec_nearly_equal(gm_vec3 a, gm_vec3 b) {
  return nearly_equal(a.x, b.x) && nearly_equal(a.y, b.y) && nearly_equal(a.z, b.z);
}

/* SHmsSphereBufferContact::MergeAndAddToCollisions for every queued tree */
void ref_detect_merge(ref_detect *d) {
  for (uint32_t q = 0; q < d->queued_count; q++) {
    ref_mtree *t = d->queued[q];
    ref_cbuf *src = &t->sphere, *dst = d->out;
    uint32_t first = dst->count;
    for (uint32_t i = 0; i < src->count; i++)
      if (src->items[i].sphere_merge_primary)
        cbuf_push(dst, &src->items[i]);
    uint32_t flagged = dst->count;
    for (uint32_t i = 0; i < src->count; i++) {
      const ref_collision *c = &src->items[i];
      if (c->sphere_merge_primary)
        continue;
      uint32_t k = first;
      for (; k < flagged; k++) {
        const ref_collision *tc = &dst->items[k];
        if (vec_nearly_equal(c->extra_negated, tc->extra_negated) ||
            SPHERE_NORMAL_ALIGNMENT < v3_dot(c->normal, tc->normal))
          break;
      }
      if (k == flagged)
        cbuf_push(dst, c);
    }
    t->queued = 0;
    src->count = 0;
  }
  d->queued_count = 0;
}
