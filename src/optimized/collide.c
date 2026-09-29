#include "optimized/collide.h"

#if defined(__SSE2__)
#include <emmintrin.h>
#endif

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

static inline float ld_f32(const uint8_t *p) {
  float f;
  memcpy(&f, p, 4);
  return f;
}

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
  gm_iso4 to_mesh = iso4_mult_inverse(ia, im);
  gm_vec3 zero = v3(0.0f, 0.0f, 0.0f);
  gm_box eb = {zero, radii};
  eb = box_transform(&eb, &to_mesh);
  /* the transforms below only matter once a triangle is tested / hit:
     built on first use (same values as building them up front) */
  gm_vec3 inv;
  gm_iso4 mesh_to_ell, mesh_to_unit, contact_to_world, normal_to_world;
  int have_unit = 0, have_world = 0;
  int hit = 0;
  /* the cell walk with the cell fields read in place and the query box in
     registers: box_test_inter(&eb, cell) axis by axis */
  const float qcx = eb.center.x, qcy = eb.center.y, qcz = eb.center.z;
  const float qhx = eb.half.x, qhy = eb.half.y, qhz = eb.half.z;
  const uint8_t *cells = m->cells;
  for (uint32_t ci = 0; ci < m->cell_count;) {
    const uint8_t *r = cells + (size_t)ci * 32;
    /* cell: +4 center x y z, +16 half x y z */
    if (box_axis_overlap(qcz, qhz, ld_f32(r + 12), ld_f32(r + 24)) == 0 ||
        box_axis_overlap(qcy, qhy, ld_f32(r + 8), ld_f32(r + 20)) == 0 ||
        box_axis_overlap(qcx, qhx, ld_f32(r + 4), ld_f32(r + 16)) == 0) {
      uint32_t subtree;
      memcpy(&subtree, r, 4);
      ci += subtree;
      continue;
    }
    mesh_cell cell;
    memcpy(&cell.tri, r + 28, 4);
    if (cell.tri >= 0 && (uint32_t)cell.tri < m->triangle_count) {
      if (!have_unit) {
        inv = v3(1.0f / radii.x, 1.0f / radii.y, 1.0f / radii.z);
        mesh_to_ell = iso4_inverse(&to_mesh);
        mesh_to_unit = mesh_to_ell;
        scale_rows(&mesh_to_unit, inv);
        have_unit = 1;
      }
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
          if (!have_world) {
            contact_to_world = iso4_scale_trans(radii, zero);
            contact_to_world = iso4_mult_inverse(&contact_to_world, &mesh_to_ell);
            contact_to_world = iso4_mult(&contact_to_world, im);
            normal_to_world = iso4_scale_trans(inv, zero);
            normal_to_world = iso4_mult_inverse(&normal_to_world, &mesh_to_ell);
            normal_to_world = iso4_mult(&normal_to_world, im);
            have_world = 1;
          }
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

/* ---- all the moving trees at once ----

   ref_detect_static walks the static tree once per moving tree, and each
   ellipsoid walks the mesh of every record it reaches. The car's trees are
   close together, so here each tree is walked once for all of them: every
   cell tested against every tree still inside it (four trees per SSE test,
   the same operations as box_test_inter), which gives each tree exactly the
   cells its own walk reaches. The collisions are then made in the
   reference's order: tree by tree (post-order), records in cell order,
   triangles in mesh order. */

enum { AT_TREES = 16, AT_RECS = 48, AT_TRIS = 8192, AT_STACK = 96 };

typedef struct at_tree {
  ref_mtree *tree;
  gm_iso4 local;
  gm_box mbox;
} at_tree;

typedef struct at_boxes {
  float c[3][AT_TREES], h[3][AT_TREES];
} at_boxes;

static uint32_t at_gather(ref_mtree *tree, const gm_iso4 *moving_iso, at_tree *out, uint32_t n) {
  if (!(tree->flags & 0x80u))
    return n;
  gm_iso4 local = (tree->flags & 4u) ? iso4_mult(&tree->local, moving_iso) : *moving_iso;
  for (uint32_t i = 0; i < tree->child_count; i++)
    n = at_gather(tree->children[i], &local, out, n);
  if (!tree->surf)
    return n;
  if (n < AT_TREES) {
    out[n].tree = tree;
    out[n].local = local;
    out[n].mbox = box_transform(&tree->box, moving_iso);
  }
  return n + 1;
}

static void at_set(at_boxes *q, uint32_t lane, const gm_box *b) {
  q->c[0][lane] = b->center.x, q->c[1][lane] = b->center.y, q->c[2][lane] = b->center.z;
  q->h[0][lane] = b->half.x, q->h[1][lane] = b->half.y, q->h[2][lane] = b->half.z;
}

/* bit t: box_test_inter(query t, cell) for the lanes in `lanes` */
static inline uint32_t at_test(const at_boxes *q, uint32_t groups, float cx, float cy, float cz, float hx, float hy,
                               float hz) {
  uint32_t pass = 0;
#if defined(__SSE2__)
  const __m128 sign = _mm_set1_ps(-0.0f);
  const __m128 bc[3] = {_mm_set1_ps(cx), _mm_set1_ps(cy), _mm_set1_ps(cz)};
  const __m128 bh[3] = {_mm_set1_ps(hx), _mm_set1_ps(hy), _mm_set1_ps(hz)};
  for (uint32_t g = 0; g < groups; g++) {
    __m128 fail = _mm_setzero_ps();
    for (int k = 0; k < 3; k++) {
      /* box_axis_overlap(query c, query h, cell c, cell h) */
      __m128 dist = _mm_andnot_ps(sign, _mm_sub_ps(bc[k], _mm_loadu_ps(&q->c[k][g * 4])));
      __m128 sum = _mm_add_ps(bh[k], _mm_loadu_ps(&q->h[k][g * 4]));
      fail = _mm_or_ps(fail, _mm_cmplt_ps(sum, dist));
    }
    pass |= ((uint32_t)(~_mm_movemask_ps(fail)) & 15u) << (g * 4);
  }
#else
  for (uint32_t t = 0; t < groups * 4; t++)
    if (box_axis_overlap(q->c[2][t], q->h[2][t], cz, hz) && box_axis_overlap(q->c[1][t], q->h[1][t], cy, hy) &&
        box_axis_overlap(q->c[0][t], q->h[0][t], cx, hx))
      pass |= 1u << t;
#endif
  return pass;
}

#if defined(__x86_64__) || defined(__i386__)
#define AT_HAVE_AVX 1
#include <immintrin.h>
/* at_test for up to eight trees in one 256-bit test (same per-lane
   operations) */
__attribute__((target("avx"))) static inline uint32_t at_test_avx(const at_boxes *q, uint32_t groups, float cx,
                                                                   float cy, float cz, float hx, float hy, float hz) {
  const __m256 sign = _mm256_set1_ps(-0.0f);
  const __m256 bc[3] = {_mm256_set1_ps(cx), _mm256_set1_ps(cy), _mm256_set1_ps(cz)};
  const __m256 bh[3] = {_mm256_set1_ps(hx), _mm256_set1_ps(hy), _mm256_set1_ps(hz)};
  uint32_t pass = 0;
  for (uint32_t g = 0; g < groups; g += 2) {
    __m256 fail = _mm256_setzero_ps();
    for (int k = 0; k < 3; k++) {
      __m256 dist = _mm256_andnot_ps(sign, _mm256_sub_ps(bc[k], _mm256_loadu_ps(&q->c[k][g * 4])));
      __m256 sum = _mm256_add_ps(bh[k], _mm256_loadu_ps(&q->h[k][g * 4]));
      fail = _mm256_or_ps(fail, _mm256_cmp_ps(sum, dist, _CMP_LT_OQ));
    }
    pass |= ((uint32_t)(~_mm256_movemask_ps(fail)) & 255u) << (g * 4);
  }
  return pass;
}
#endif

/* Decides, without roots or divisions, that sphere_triangle on the unit
   sphere at the origin returns 0 for the triangle v with unnormalized normal
   n (the float cross product). Exact values in double; the float test is
   within a few dozen ulp of them, so a decision is taken only with a margin
   far above that, otherwise the float test runs.
   - plane: the centre's distance -v0 . n / |n| below 0 or above 1. The float
     one is within 8 ulp * S / |n| (S = sum |v0_i n_i|) plus underflow.
   - edges, in the test's order: the edge distance ed = (proj - a) . (dir x n)
     is exactly -a . ((b - a) x n) / (|b - a| |n|) (proj - a = -n D / |n|^2 - a
     and n . ((b - a) x n) = 0), the reach r = sqrt(1 - plane^2). The float
     ed is within ~40 ulp * (V + 2) of it (V: largest vertex L1 norm), the
     float r^2 within ~20 ulp * (V + 1) of r^2. An edge with ed clearly <= 0
     passes on to the next; the first other edge decides: clearly ed > r
     rejects, anything else is left to the float test. */
static inline int tri_rejects(const gm_vec3 v[3], float nx, float ny, float nz) {
  const double n0 = (double)nx, n1 = (double)ny, n2 = (double)nz;
  const double tx = -(double)v[0].x * n0, ty = -(double)v[0].y * n1, tz = -(double)v[0].z * n2;
  const double d = (tx + ty) + tz;
  const double nn = (n0 * n0 + n1 * n1) + n2 * n2;
  const double m = 9.5367431640625e-07 /* 2^-20 */ * ((fabs(tx) + fabs(ty)) + fabs(tz)) + 7.346839692639297e-40 /* 2^-130 */ * (nn > 1.0 ? nn : 1.0);
  if (d + m < 0.0)
    return 1;
  const double l = d - m;
  if (l > 0.0 && l * l > nn * (1.0 + 9.5367431640625e-07 /* 2^-20 */))
    return 1;
  double p[3][3], vmax = 0.0;
  for (int k = 0; k < 3; k++) {
    p[k][0] = (double)v[k].x;
    p[k][1] = (double)v[k].y;
    p[k][2] = (double)v[k].z;
    const double a1 = (fabs(p[k][0]) + fabs(p[k][1])) + fabs(p[k][2]);
    vmax = a1 > vmax ? a1 : vmax;
  }
  const double me = 6.103515625e-05 /* 2^-14 */ * (2.0 * vmax + 2.0);
  /* |n|^2 times an upper bound of (r + me)^2 (r <= 1) */
  const double reach = (nn - d * d) * (1.0 + 9.5367431640625e-07 /* 2^-20 */) + (3.0517578125e-05 /* 2^-15 */ * (vmax + 1.0) + 2.1 * me + me * me) * nn;
  const double inside = me * me * nn;
  for (int e = 0; e < 3; e++) {
    const double *a = p[e], *b = p[e == 2 ? 0 : e + 1];
    const double ex = b[0] - a[0], ey = b[1] - a[1], ez = b[2] - a[2];
    const double ll = (ex * ex + ey * ey) + ez * ez;
    if (!(ll > 4.0 * (double)DIR_EPS2))
      return 0;
    const double cx = ey * n2 - ez * n1, cy = ez * n0 - ex * n2, cz = ex * n1 - ey * n0;
    const double g = -((a[0] * cx + a[1] * cy) + a[2] * cz);
    const double g2 = g * g;
    if (g > 0.0 && g2 > reach * ll)
      return 1;
    if (!(g < 0.0 && g2 > inside * ll))
      return 0;
  }
  return 0;
}

/* A triangle that passed the reject tests: the float test and, on contact,
   the contacts to world space (the transforms built on the first). */
typedef struct tri_ctx {
  const ref_surf *a;
  const gm_iso4 *im;
  ref_cbuf *out;
  gm_vec3 radii, inv;
  gm_iso4 mesh_to_ell, mesh_to_unit, contact_to_world, normal_to_world;
  int have_world, hit;
} tri_ctx;

TMUF_ALWAYS_INLINE void tri_test(tri_ctx *x, const gm_vec3 v[3], float nx, float ny,
                                                           float nz, float n2, uint16_t material) {
  const gm_vec3 zero = v3(0.0f, 0.0f, 0.0f);
  float in = 1.0f / tmuf_sqrtf(n2);
  gm_vec3 un = v3(nx * in, ny * in, in * nz);
  ref_cbuf *out = x->out;
  uint32_t first = out->count;
  sphere_tri st = {out, zero, 1.0f, x->a->material, un, material};
  if (!sphere_triangle(&st, v))
    return;
  if (!x->have_world) {
    x->contact_to_world = iso4_scale_trans(x->radii, zero);
    x->contact_to_world = iso4_mult_inverse(&x->contact_to_world, &x->mesh_to_ell);
    x->contact_to_world = iso4_mult(&x->contact_to_world, x->im);
    x->normal_to_world = iso4_scale_trans(x->inv, zero);
    x->normal_to_world = iso4_mult_inverse(&x->normal_to_world, &x->mesh_to_ell);
    x->normal_to_world = iso4_mult(&x->normal_to_world, x->im);
    x->have_world = 1;
  }
  for (uint32_t i = first; i < out->count; i++) {
    ref_collision *c = &out->items[i];
    c->point = iso4_mul_point(&x->contact_to_world, c->point);
    c->normal = normalize_eps(mat3_mul_vec(&x->normal_to_world.r, c->normal), DIR_EPS2);
    c->separation = mat3_mul_vec(&x->contact_to_world.r, c->separation);
  }
  x->hit = 1;
}

TMUF_ALWAYS_INLINE void tri_ctx_init(tri_ctx *x, const ref_surf *a, const gm_iso4 *im,
                                                               const gm_iso4 *to_mesh, ref_cbuf *out) {
  x->a = a;
  x->im = im;
  x->out = out;
  x->radii = ellipsoid_radii(a);
  x->inv = v3(1.0f / x->radii.x, 1.0f / x->radii.y, 1.0f / x->radii.z);
  x->mesh_to_ell = iso4_inverse(to_mesh);
  x->mesh_to_unit = x->mesh_to_ell;
  scale_rows(&x->mesh_to_unit, x->inv);
  x->have_world = x->hit = 0;
  memset(&x->contact_to_world, 0, sizeof x->contact_to_world);
  memset(&x->normal_to_world, 0, sizeof x->normal_to_world);
}

#if defined(TMUF_TRI_CHECK)
#include <stdio.h>
/* development check (-DTMUF_TRI_CHECK): a triangle the reject tests skip
   has no contact in the float test */
static void tri_check_rejected(const gm_vec3 v[3], float nx, float ny, float nz, float n2) {
  static unsigned long long checked;
  ref_cbuf scratch = {0};
  float in = 1.0f / tmuf_sqrtf(n2);
  sphere_tri st = {&scratch, v3(0.0f, 0.0f, 0.0f), 1.0f, 0, v3(nx * in, ny * in, in * nz), 0};
  if (sphere_triangle(&st, v)) {
    fprintf(stderr, "tri_rejects: rejected triangle has a contact: %a %a %a / %a %a %a / %a %a %a\n", (double)v[0].x,
            (double)v[0].y, (double)v[0].z, (double)v[1].x, (double)v[1].y, (double)v[1].z, (double)v[2].x,
            (double)v[2].y, (double)v[2].z);
    abort();
  }
  ref_cbuf_free(&scratch);
  if ((++checked & ((1ull << 24) - 1)) == 0)
    fprintf(stderr, "tri_rejects: %llu rejections checked\n", checked);
}
#endif

/* the triangles an ellipsoid's walk of mesh m uses, with its to_mesh: the
   rest of ellipsoid_mesh */
static int ellipsoid_mesh_tris(const ref_surf *a, const ref_surf *m, const gm_iso4 *im, const gm_iso4 *to_mesh,
                               const uint32_t *tris, uint32_t ntris, ref_cbuf *out) {
  if (ntris == 0)
    return 0;
  tri_ctx x;
  tri_ctx_init(&x, a, im, to_mesh, out);
  for (uint32_t k = 0; k < ntris; k++) {
    mesh_tri t = read_tri(m, tris[k]);
    gm_vec3 v[3];
    for (int j = 0; j < 3; j++)
      v[j] = iso4_mul_point(&x.mesh_to_unit, ref_mesh_vertex(m, t.idx[j]));
    gm_vec3 e1 = v3_sub(v[1], v[0]), e2 = v3_sub(v[2], v[0]);
    float nx = e2.z * e1.y - e2.y * e1.z;
    float ny = e1.z * e2.x - e2.z * e1.x;
    float nz = e1.x * e2.y - e2.x * e1.y;
    float n2 = (ny * ny + nx * nx) + nz * nz;
    if (!(n2 > DIR_EPS2))
      continue;
    if (tri_rejects(v, nx, ny, nz)) {
#if defined(TMUF_TRI_CHECK)
      tri_check_rejected(v, nx, ny, nz, n2);
#endif
      continue;
    }
    tri_test(&x, v, nx, ny, nz, n2, t.material);
  }
  return x.hit;
}

#if defined(AT_HAVE_AVX)
#define TRI_HAVE_AVX 1
/* ellipsoid_mesh_tris four triangles at a time: vertices, normal and
   tri_rejects in vectors (the same operations per lane), the float test on
   the others in order */
__attribute__((target("avx"))) static int ellipsoid_mesh_tris_avx(const ref_surf *a, const ref_surf *m,
                                                                  const gm_iso4 *im, const gm_iso4 *to_mesh,
                                                                  const uint32_t *tris, uint32_t ntris,
                                                                  ref_cbuf *out) {
  if (ntris == 0)
    return 0;
  tri_ctx x;
  tri_ctx_init(&x, a, im, to_mesh, out);
  const gm_mat3 *r = &x.mesh_to_unit.r;
  const __m128 r00 = _mm_set1_ps(r->m[0][0]), r01 = _mm_set1_ps(r->m[0][1]), r02 = _mm_set1_ps(r->m[0][2]);
  const __m128 r10 = _mm_set1_ps(r->m[1][0]), r11 = _mm_set1_ps(r->m[1][1]), r12 = _mm_set1_ps(r->m[1][2]);
  const __m128 r20 = _mm_set1_ps(r->m[2][0]), r21 = _mm_set1_ps(r->m[2][1]), r22 = _mm_set1_ps(r->m[2][2]);
  const __m128 t0 = _mm_set1_ps(x.mesh_to_unit.t.x), t1 = _mm_set1_ps(x.mesh_to_unit.t.y),
               t2 = _mm_set1_ps(x.mesh_to_unit.t.z);
  const __m256d absmask = _mm256_castsi256_pd(_mm256_set1_epi64x(INT64_MAX));
  const __m256d zero = _mm256_setzero_pd(), one = _mm256_set1_pd(1.0);
  for (uint32_t k0 = 0; k0 < ntris; k0 += 4) {
    const uint32_t lanes = ntris - k0 < 4 ? ntris - k0 : 4;
    uint16_t mat[4];
    /* each vertex as (x, y, z, 0) (no read past its 12 bytes), four of them
       transposed into x, y, z vectors */
    __m128 pv[3][4];
    for (uint32_t j = 0; j < 4; j++) {
      const uint32_t ti = tris[k0 + (j < lanes ? j : 0)];
      memcpy(&mat[j], m->triangles + (size_t)ti * 32 + 28, 2);
      const float *p = m->tri_vertices + (size_t)ti * 9;
      pv[0][j] = _mm_loadu_ps(p);     /* x y z (next vertex's x in lane 3, unused) */
      pv[1][j] = _mm_loadu_ps(p + 3);
      pv[2][j] = _mm_movelh_ps(_mm_castpd_ps(_mm_load_sd((const double *)(p + 6))), _mm_load_ss(p + 8));
    }
    __m128 vx[3], vy[3], vz[3];
    for (int k = 0; k < 3; k++) {
      __m128 px = pv[k][0], py = pv[k][1], pz = pv[k][2], pw = pv[k][3];
      _MM_TRANSPOSE4_PS(px, py, pz, pw);
      (void)pw;
      /* ((r0 . p) + t): ((r00 x + r01 y) + r02 z) + t0 */
      vx[k] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(r00, px), _mm_mul_ps(r01, py)), _mm_mul_ps(r02, pz)), t0);
      vy[k] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(r10, px), _mm_mul_ps(r11, py)), _mm_mul_ps(r12, pz)), t1);
      vz[k] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(r20, px), _mm_mul_ps(r21, py)), _mm_mul_ps(r22, pz)), t2);
    }
    const __m128 e1x = _mm_sub_ps(vx[1], vx[0]), e1y = _mm_sub_ps(vy[1], vy[0]), e1z = _mm_sub_ps(vz[1], vz[0]);
    const __m128 e2x = _mm_sub_ps(vx[2], vx[0]), e2y = _mm_sub_ps(vy[2], vy[0]), e2z = _mm_sub_ps(vz[2], vz[0]);
    const __m128 nx = _mm_sub_ps(_mm_mul_ps(e2z, e1y), _mm_mul_ps(e2y, e1z));
    const __m128 ny = _mm_sub_ps(_mm_mul_ps(e1z, e2x), _mm_mul_ps(e2z, e1x));
    const __m128 nz = _mm_sub_ps(_mm_mul_ps(e1x, e2y), _mm_mul_ps(e2x, e1y));
    const __m128 n2 =
        _mm_add_ps(_mm_add_ps(_mm_mul_ps(ny, ny), _mm_mul_ps(nx, nx)), _mm_mul_ps(nz, nz));
    unsigned todo = (unsigned)_mm_movemask_ps(_mm_cmpgt_ps(n2, _mm_set1_ps(DIR_EPS2))) & ((1u << lanes) - 1u);
#if defined(TMUF_TRI_CHECK)
    unsigned rejected = 0;
#endif
    if (!todo)
      continue;
    /* tri_rejects per lane */
    {
      const __m256d n0 = _mm256_cvtps_pd(nx), n1 = _mm256_cvtps_pd(ny), nn2 = _mm256_cvtps_pd(nz);
      __m256d px[3], py[3], pz[3];
      for (int k = 0; k < 3; k++) {
        px[k] = _mm256_cvtps_pd(vx[k]);
        py[k] = _mm256_cvtps_pd(vy[k]);
        pz[k] = _mm256_cvtps_pd(vz[k]);
      }
      const __m256d sgn = _mm256_set1_pd(-0.0);
      const __m256d tx = _mm256_mul_pd(_mm256_xor_pd(px[0], sgn), n0);
      const __m256d ty = _mm256_mul_pd(_mm256_xor_pd(py[0], sgn), n1);
      const __m256d tz = _mm256_mul_pd(_mm256_xor_pd(pz[0], sgn), nn2);
      const __m256d d = _mm256_add_pd(_mm256_add_pd(tx, ty), tz);
      const __m256d nn = _mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(n0, n0), _mm256_mul_pd(n1, n1)),
                                       _mm256_mul_pd(nn2, nn2));
      const __m256d sabs = _mm256_add_pd(_mm256_add_pd(_mm256_and_pd(tx, absmask), _mm256_and_pd(ty, absmask)),
                                         _mm256_and_pd(tz, absmask));
      const __m256d mg = _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(9.5367431640625e-07 /* 2^-20 */), sabs),
                                       _mm256_mul_pd(_mm256_set1_pd(7.346839692639297e-40 /* 2^-130 */), _mm256_max_pd(nn, one)));
      const __m256d l = _mm256_sub_pd(d, mg);
      __m256d rej = _mm256_cmp_pd(_mm256_add_pd(d, mg), zero, _CMP_LT_OQ);
      rej = _mm256_or_pd(rej, _mm256_and_pd(_mm256_cmp_pd(l, zero, _CMP_GT_OQ),
                                            _mm256_cmp_pd(_mm256_mul_pd(l, l),
                                                          _mm256_mul_pd(nn, _mm256_set1_pd(1.0 + 9.5367431640625e-07 /* 2^-20 */)),
                                                          _CMP_GT_OQ)));
      __m256d vmax = zero;
      for (int k = 0; k < 3; k++) {
        const __m256d a1 = _mm256_add_pd(
            _mm256_add_pd(_mm256_and_pd(px[k], absmask), _mm256_and_pd(py[k], absmask)),
            _mm256_and_pd(pz[k], absmask));
        vmax = _mm256_max_pd(a1, vmax);
      }
      /* me = 2^-14 (2 vmax + 2) */
      const __m256d me = _mm256_mul_pd(_mm256_set1_pd(6.103515625e-05 /* 2^-14 */),
                                       _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(2.0), vmax), _mm256_set1_pd(2.0)));
      /* (nn - d d)(1 + 2^-20) + (2^-15 (vmax + 1) + 2.1 me + me me) nn */
      const __m256d slack = _mm256_add_pd(
          _mm256_add_pd(_mm256_mul_pd(_mm256_set1_pd(3.0517578125e-05 /* 2^-15 */), _mm256_add_pd(vmax, one)),
                        _mm256_mul_pd(_mm256_set1_pd(2.1), me)),
          _mm256_mul_pd(me, me));
      const __m256d reach =
          _mm256_add_pd(_mm256_mul_pd(_mm256_sub_pd(nn, _mm256_mul_pd(d, d)), _mm256_set1_pd(1.0 + 9.5367431640625e-07 /* 2^-20 */)),
                        _mm256_mul_pd(slack, nn));
      const __m256d inside = _mm256_mul_pd(_mm256_mul_pd(me, me), nn);
      const __m256d lmin = _mm256_set1_pd(4.0 * (double)DIR_EPS2);
      __m256d pass = _mm256_andnot_pd(rej, _mm256_castsi256_pd(_mm256_set1_epi64x(-1)));
      for (int e = 0; e < 3; e++) {
        const int f = e == 2 ? 0 : e + 1;
        const __m256d ex = _mm256_sub_pd(px[f], px[e]), ey = _mm256_sub_pd(py[f], py[e]),
                      ez = _mm256_sub_pd(pz[f], pz[e]);
        const __m256d ll = _mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(ex, ex), _mm256_mul_pd(ey, ey)),
                                         _mm256_mul_pd(ez, ez));
        const __m256d cx = _mm256_sub_pd(_mm256_mul_pd(ey, nn2), _mm256_mul_pd(ez, n1));
        const __m256d cy = _mm256_sub_pd(_mm256_mul_pd(ez, n0), _mm256_mul_pd(ex, nn2));
        const __m256d cz = _mm256_sub_pd(_mm256_mul_pd(ex, n1), _mm256_mul_pd(ey, n0));
        const __m256d g = _mm256_xor_pd(
            _mm256_add_pd(_mm256_add_pd(_mm256_mul_pd(px[e], cx), _mm256_mul_pd(py[e], cy)), _mm256_mul_pd(pz[e], cz)),
            sgn);
        const __m256d g2 = _mm256_mul_pd(g, g);
        const __m256d ok = _mm256_cmp_pd(ll, lmin, _CMP_GT_OQ);
        const __m256d out_e = _mm256_and_pd(_mm256_cmp_pd(g, zero, _CMP_GT_OQ),
                                            _mm256_cmp_pd(g2, _mm256_mul_pd(reach, ll), _CMP_GT_OQ));
        const __m256d in_e = _mm256_and_pd(_mm256_cmp_pd(g, zero, _CMP_LT_OQ),
                                           _mm256_cmp_pd(g2, _mm256_mul_pd(inside, ll), _CMP_GT_OQ));
        rej = _mm256_or_pd(rej, _mm256_and_pd(_mm256_and_pd(pass, ok), out_e));
        pass = _mm256_and_pd(pass, _mm256_and_pd(ok, in_e));
      }
#if defined(TMUF_TRI_CHECK)
      rejected = todo & (unsigned)_mm256_movemask_pd(rej);
#endif
      todo &= ~(unsigned)_mm256_movemask_pd(rej);
    }
#if defined(TMUF_TRI_CHECK)
    if (!todo && !rejected)
#else
    if (!todo)
#endif
      continue;
    float fx[3][4], fy[3][4], fz[3][4], fnx[4], fny[4], fnz[4], fn2[4];
    for (int k = 0; k < 3; k++) {
      _mm_storeu_ps(fx[k], vx[k]);
      _mm_storeu_ps(fy[k], vy[k]);
      _mm_storeu_ps(fz[k], vz[k]);
    }
    _mm_storeu_ps(fnx, nx);
    _mm_storeu_ps(fny, ny);
    _mm_storeu_ps(fnz, nz);
    _mm_storeu_ps(fn2, n2);
#if defined(TMUF_TRI_CHECK)
    for (uint32_t j = 0; j < 4; j++)
      if (rejected & (1u << j)) {
        gm_vec3 v[3];
        for (int k = 0; k < 3; k++)
          v[k] = v3(fx[k][j], fy[k][j], fz[k][j]);
        tri_check_rejected(v, fnx[j], fny[j], fnz[j], fn2[j]);
      }
#endif
    for (uint32_t j = 0; todo; j++, todo >>= 1) {
      if (!(todo & 1u))
        continue;
      gm_vec3 v[3];
      for (int k = 0; k < 3; k++)
        v[k] = v3(fx[k][j], fy[k][j], fz[k][j]);
      tri_test(&x, v, fnx[j], fny[j], fnz[j], fn2[j], mat[j]);
    }
  }
  return x.hit;
}
#endif

/* one tree's collision with one record, after the fact (as in
   ref_detect_static) */
static void at_finish(ref_detect *d, ref_mtree *tree, const ref_static_record *rec, ref_cbuf *buf, uint32_t first,
                      int hit) {
  if (!hit)
    return;
  for (uint32_t i = first; i < buf->count; i++) {
    buf->items[i].mat_a = material_id(tree->surf, buf->items[i].local_mat_a);
    buf->items[i].mat_b = material_id(rec->surf, buf->items[i].local_mat_b);
  }
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

#if defined(AT_HAVE_AVX)
#define AT_TEST(...) (avx ? at_test_avx(__VA_ARGS__) : at_test(__VA_ARGS__))
#else
#define AT_TEST(...) ((void)avx, at_test(__VA_ARGS__))
#endif

/* one world (d->world) for the gathered trees; any limit reached before a
   collision is made: the reference walk instead */
TMUF_ALWAYS_INLINE void at_walk_world_impl(ref_detect *d, ref_mtree *root,
                                                                      const gm_iso4 *moving_iso, const at_tree *trees,
                                                                      uint32_t nt, const int avx) {
  const ref_world *w = d->world;
  if (w->cell_count <= 1 || nt == 0)
    return;
  uint32_t groups = (nt + 3u) / 4u;
  uint32_t all = nt == 32 ? 0xffffffffu : (1u << nt) - 1u;
  at_boxes q;
  memset(&q, 0, sizeof q);
  for (uint32_t t = 0; t < nt; t++)
    at_set(&q, t, &trees[t].mbox);

  /* 1. the static tree: per tree, the records its walk reaches */
  uint32_t recs[AT_TREES][AT_RECS];
  uint32_t nrec[AT_TREES];
  memset(nrec, 0, sizeof nrec);
  /* each reached record once, with the trees that reach it and its slot in
     each tree's list */
  typedef struct at_reached {
    uint32_t rec, lanes;
    uint8_t slot[AT_TREES];
  } at_reached;
  at_reached reached[AT_TREES * AT_RECS];
  uint32_t nreached = 0;
  {
    uint32_t mask_stack[AT_STACK], end_stack[AT_STACK];
    uint32_t depth = 0, cur = all;
    for (uint32_t ci = 0; ci < w->cell_count;) {
      while (depth && ci >= end_stack[depth - 1])
        cur = mask_stack[--depth];
      const ref_static_cell *cell = &w->cells[ci];
      const gm_box *b = &cell->bounds;
      uint32_t m = cur & AT_TEST(&q, groups, b->center.x, b->center.y, b->center.z, b->half.x, b->half.y, b->half.z);
      if (!m) {
        ci += cell->subtree_count;
        continue;
      }
      if (cell->record >= 0) {
        at_reached *re = &reached[nreached++];
        re->rec = (uint32_t)cell->record;
        re->lanes = m;
        for (uint32_t k = m; k; k &= k - 1u) {
          uint32_t t = tmuf_ctz32(k);
          if (nrec[t] == AT_RECS) {
            ref_detect_static(d, root, moving_iso);
            return;
          }
          re->slot[t] = (uint8_t)nrec[t];
          recs[t][nrec[t]++] = (uint32_t)cell->record;
        }
      }
      if (cell->subtree_count > 1) {
        if (depth == AT_STACK) {
          ref_detect_static(d, root, moving_iso);
          return;
        }
        mask_stack[depth] = cur;
        end_stack[depth++] = ci + cell->subtree_count;
        cur = m;
      }
      ci++;
    }
  }

  /* 2. each mesh record once for the ellipsoids that reach it: per (tree,
     record) its to_mesh and the triangles its walk uses */
  static const uint32_t NONE = UINT32_MAX;
  uint32_t tri_off[AT_TREES][AT_RECS], tri_n[AT_TREES][AT_RECS];
  gm_iso4 to_mesh[AT_TREES][AT_RECS];
  uint32_t tris[AT_TRIS];
  uint32_t ntris = 0;
  for (uint32_t t = 0; t < nt; t++)
    for (uint32_t k = 0; k < nrec[t]; k++)
      tri_off[t][k] = NONE;
  uint32_t ellipsoids = 0;
  for (uint32_t t = 0; t < nt; t++)
    if (trees[t].tree->surf->type == SURF_ELLIPSOID)
      ellipsoids |= 1u << t;
  for (uint32_t ri = 0; ri < nreached; ri++) {
    {
      const at_reached *re = &reached[ri];
      const uint32_t r = re->rec;
      const ref_static_record *rec = &w->records[r];
      const ref_surf *m = rec->surf;
      if (!(re->lanes & ellipsoids) || !(rec->tree_flags & 0x80u) || m->type != SURF_MESH)
        continue;
      /* the ellipsoids that reach r: lane = tree */
      const uint32_t lanes = re->lanes & ellipsoids;
      uint32_t slot[AT_TREES];
      at_boxes e;
      memset(&e, 0, sizeof e);
      for (uint32_t kk = lanes; kk; kk &= kk - 1u) {
        const uint32_t t = tmuf_ctz32(kk);
        const uint32_t k = re->slot[t];
        slot[t] = k;
        to_mesh[t][k] = iso4_mult_inverse(&trees[t].local, &rec->iso);
        gm_box eb = {v3(0.0f, 0.0f, 0.0f), ellipsoid_radii(trees[t].tree->surf)};
        eb = box_transform(&eb, &to_mesh[t][k]);
        at_set(&e, t, &eb);
      }
      /* the mesh walk for all of them; triangles gathered per tree */
      uint32_t lists[AT_TREES][256];
      uint32_t nl[AT_TREES];
      memset(nl, 0, sizeof nl);
      uint32_t mask_stack[AT_STACK], end_stack[AT_STACK];
      uint32_t depth = 0, cur = lanes;
      const uint8_t *cells = m->cells;
      for (uint32_t ci = 0; ci < m->cell_count;) {
        while (depth && ci >= end_stack[depth - 1])
          cur = mask_stack[--depth];
        const uint8_t *cr = cells + (size_t)ci * 32;
        uint32_t subtree;
        memcpy(&subtree, cr, 4);
        uint32_t mm = cur & AT_TEST(&e, groups, ld_f32(cr + 4), ld_f32(cr + 8), ld_f32(cr + 12), ld_f32(cr + 16),
                                    ld_f32(cr + 20), ld_f32(cr + 24));
        if (!mm) {
          ci += subtree;
          continue;
        }
        int32_t tri;
        memcpy(&tri, cr + 28, 4);
        if (tri >= 0 && (uint32_t)tri < m->triangle_count)
          for (uint32_t k = mm; k; k &= k - 1u) {
            uint32_t t = tmuf_ctz32(k);
            if (nl[t] == 256) {
              ref_detect_static(d, root, moving_iso);
              return;
            }
            lists[t][nl[t]++] = (uint32_t)tri;
          }
        if (subtree > 1) {
          if (depth == AT_STACK) {
            ref_detect_static(d, root, moving_iso);
            return;
          }
          mask_stack[depth] = cur;
          end_stack[depth++] = ci + subtree;
          cur = mm;
        }
        ci++;
      }
      for (uint32_t k = lanes; k; k &= k - 1u) {
        uint32_t t = tmuf_ctz32(k);
        if (ntris + nl[t] > AT_TRIS) {
          ref_detect_static(d, root, moving_iso);
          return;
        }
        tri_off[t][slot[t]] = ntris;
        tri_n[t][slot[t]] = nl[t];
        memcpy(tris + ntris, lists[t], sizeof *tris * nl[t]);
        ntris += nl[t];
      }
    }
  }

  /* 3. the collisions, in the reference's order */
  for (uint32_t t = 0; t < nt; t++) {
    ref_mtree *tree = trees[t].tree;
    ref_cbuf *buf = uses_sphere_buffer(tree->surf) ? &tree->sphere : d->out;
    for (uint32_t k = 0; k < nrec[t]; k++) {
      const ref_static_record *rec = &w->records[recs[t][k]];
      if (!(rec->tree_flags & 0x80u))
        continue;
      uint32_t first = buf->count;
      int hit;
      if (tri_off[t][k] != NONE)
#if defined(TRI_HAVE_AVX)
        hit = avx ? ellipsoid_mesh_tris_avx(tree->surf, rec->surf, &rec->iso, &to_mesh[t][k], tris + tri_off[t][k],
                                            tri_n[t][k], buf)
                  : ellipsoid_mesh_tris(tree->surf, rec->surf, &rec->iso, &to_mesh[t][k], tris + tri_off[t][k],
                                        tri_n[t][k], buf);
#else
        hit = ellipsoid_mesh_tris(tree->surf, rec->surf, &rec->iso, &to_mesh[t][k], tris + tri_off[t][k], tri_n[t][k],
                                  buf);
#endif
      else
        hit = dispatch(tree->surf, &trees[t].local, rec->surf, &rec->iso, buf);
      at_finish(d, tree, rec, buf, first, hit);
    }
  }
}

static void at_walk_world(ref_detect *d, ref_mtree *root, const gm_iso4 *moving_iso, const at_tree *trees,
                          uint32_t nt) {
  at_walk_world_impl(d, root, moving_iso, trees, nt, 0);
}

#if defined(AT_HAVE_AVX)
__attribute__((target("avx"))) static void at_walk_world_avx(ref_detect *d, ref_mtree *root,
                                                             const gm_iso4 *moving_iso, const at_tree *trees,
                                                             uint32_t nt) {
  at_walk_world_impl(d, root, moving_iso, trees, nt, 1);
}
#endif

void ref_detect_static_all(ref_detect *d, ref_mtree *root, const gm_iso4 *moving_iso) {
  const ref_world *const worlds[1] = {d->world};
  const uint32_t pairs[1] = {d->group_pair};
  ref_detect_worlds(d, root, moving_iso, worlds, pairs, 1);
}

void ref_detect_worlds(ref_detect *d, ref_mtree *root, const gm_iso4 *moving_iso, const ref_world *const *worlds,
                       const uint32_t *pairs, uint32_t count) {
  /* the trees' locations once for all the worlds */
  at_tree trees[AT_TREES];
  uint32_t nt = at_gather(root, moving_iso, trees, 0);
  for (uint32_t i = 0; i < count; i++) {
    d->world = worlds[i];
    d->group_pair = pairs[i];
    if (worlds[i]->cell_count <= 1)
      continue;
    if (nt > AT_TREES)
      ref_detect_static(d, root, moving_iso);
#if defined(AT_HAVE_AVX)
    else if (nt > 4 && __builtin_cpu_supports("avx"))
      at_walk_world_avx(d, root, moving_iso, trees, nt);
#endif
    else
      at_walk_world(d, root, moving_iso, trees, nt);
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
