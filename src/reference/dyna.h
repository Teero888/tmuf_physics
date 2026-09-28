#ifndef TMUF_REFERENCE_DYNA_H
#define TMUF_REFERENCE_DYNA_H

/* CHmsDyna: rigid body state and integration. */

#include <stdint.h>

#include "reference/gm.h"

/* CHmsDyna::CHmsStateDyna, 180 bytes, the game's memory layout (the oracle
   dumps exactly this). */
typedef struct dyna_state {
  gm_quat quat;
  gm_mat3 rot;
  gm_vec3 pos;
  gm_vec3 lin;       /* linear speed */
  gm_vec3 lin_corr;  /* linear correction speed */
  gm_vec3 ang;       /* angular speed */
  gm_vec3 force;
  gm_vec3 torque;
  gm_mat3 inv_inertia_world;
  uint32_t tweaked_valid;
  gm_vec3 tweaked_lin;
} dyna_state;

typedef enum dyna_type { DYNA_LINEAR_ONLY = 0, DYNA_FULL = 1, DYNA_FROZEN = 2 } dyna_type;

typedef struct dyna_params {
  float mass;
  gm_mat3 inv_inertia_local; /* body inverse inertia ("bodyInertiaLike") */
  gm_vec3 com;               /* local center of mass */
  float max_step_distance;
  float linear_damping_scale, angular_damping_scale;
  float force_scale; /* scales the force fields (gravity) */
} dyna_params;


typedef struct dyna {
  dyna_params params;
  dyna_state state; /* currentState: the working state */
  dyna_state write; /* writeState: GetLocation() */
  dyna_state temp;  /* tempState */
  dyna_type type;
  int active;
  int has_max_ang;
  float max_ang;
  uint32_t replacement_count, replacement_cap;
  gm_vec3 *replacements; /* pending collision replacements (grown, freed by dyna_free) */
} dyna;

void dyna_set_location(dyna *d, const gm_iso4 *loc);
void dyna_free(dyna *d);
void dyna_integrate(const dyna *d, const dyna_state *src, dyna_state *dst, float dt);
void dyna_pre_collision(dyna *d, float dt);
void dyna_post_collision(dyna *d);

void dyna_add_force(dyna *d, gm_vec3 f);
void dyna_add_force_at(dyna *d, gm_vec3 f, gm_vec3 point);
void dyna_add_torque(dyna *d, gm_vec3 t);
void dyna_add_impulse(dyna *d, gm_vec3 impulse);
void dyna_add_impulse_at(dyna *d, gm_vec3 impulse, gm_vec3 point);
void dyna_add_replacement(dyna *d, gm_vec3 r);
gm_vec3 dyna_speed_at(const dyna *d, gm_vec3 point);
gm_vec3 dyna_local_dir_to_world(const dyna *d, gm_vec3 local);
gm_vec3 dyna_local_point_to_world(const dyna *d, gm_vec3 local);

void quat_normalize(gm_quat *q);
void quat_from_mat3(gm_quat *q, const gm_mat3 *m);

#endif
