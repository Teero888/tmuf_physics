#ifndef TMUF_REFERENCE_DYNA_H
#define TMUF_REFERENCE_DYNA_H

/* CHmsDyna: rigid body state and integration. */

#include <stdint.h>

#include "optimized/gm.h"

typedef tmuf_dyna_state dyna_state;
typedef tmuf_dyna_type dyna_type;
#define DYNA_LINEAR_ONLY TMUF_DYNA_LINEAR_ONLY
#define DYNA_FULL TMUF_DYNA_FULL
#define DYNA_FROZEN TMUF_DYNA_FROZEN
typedef tmuf_dyna_params dyna_params;
typedef tmuf_dyna dyna;

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
