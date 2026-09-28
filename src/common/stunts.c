/* CTrackManiaRace's stunt figures.

   The game's x87 code runs with 24-bit precision control: every sum,
   product and quotient is rounded to a float, which float arithmetic here
   reproduces (the values stay far from the subnormal range). Constants the
   game keeps as doubles stay doubles; atan2 is the x87 fpatan rounded to a
   float. The game's double constants hold float values (its pi is the float
   pi). */

#include "common/stunts.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/controls.h"

#define NONE UINT32_MAX

static const double PI = 3.1415927410125732;       /* (double)(float)pi */
static const double HALF_PI = 1.5707963705062866;  /* (double)(float)(pi / 2) */
static const double EIGHTH_PI = 0.39269909262657166; /* (double)(float)(pi / 8) */
static const double SIDE_UP = 0.20000000298023224;  /* (double)0.2f */

/* ---- math (GmMat3, GmQuat) ---- */

/* GmMat3::MultTranspose(rhs): this * rhs^T */
static tmuf_mat3 mul_transpose(const tmuf_mat3 *left, const tmuf_mat3 *right) {
  tmuf_mat3 out;
  for (int c = 0; c < 3; c++)
    for (int k = 0; k < 3; k++)
      out.m[k][c] = (right->m[0][k] * left->m[0][c] + right->m[1][k] * left->m[1][c]) + right->m[2][k] * left->m[2][c];
  return out;
}

/* GmQuat::Set(const GmMat3 &) */
static tmuf_quat quat_from_mat3(const tmuf_mat3 *m) {
  tmuf_quat q;
  float trace = (m->m[0][0] + m->m[1][1]) + m->m[2][2];
  if (trace > 0.0f) {
    float root = sqrtf(trace + 1.0f);
    float scale = 0.5f / root;
    q.w = root * 0.5f;
    q.x = (m->m[2][1] - m->m[1][2]) * scale;
    q.y = (m->m[0][2] - m->m[2][0]) * scale;
    q.z = (m->m[1][0] - m->m[0][1]) * scale;
    return q;
  }
  static const int NEXT[3] = {1, 2, 0};
  int i = 0;
  if (m->m[0][0] < m->m[1][1])
    i = 1;
  if (m->m[i][i] < m->m[2][2])
    i = 2;
  int j = NEXT[i], k = NEXT[j];
  float root = sqrtf((m->m[i][i] - (m->m[k][k] + m->m[j][j])) + 1.0f);
  float scale = 0.5f / root;
  float v[3];
  v[i] = root * 0.5f;
  q.w = (m->m[k][j] - m->m[j][k]) * scale;
  v[j] = (m->m[i][j] + m->m[j][i]) * scale;
  v[k] = (m->m[i][k] + m->m[k][i]) * scale;
  q.x = v[0];
  q.y = v[1];
  q.z = v[2];
  return q;
}

/* the x87 fpatan rounded to a float: each backend's fmath (the same results,
   independent of the C library) */
float tmuf_atan2f(float y, float x);
static float atan2_x87(float y, float x) { return tmuf_atan2f(y, x); }

/* GmQuat::GetRotation: angle (radians) and unit axis */
static void quat_rotation(tmuf_quat q, float *angle, tmuf_vec3 *axis) {
  float a[3] = {q.x, q.y, q.z};
  const float len2 = (a[0] * a[0] + a[1] * a[1]) + a[2] * a[2];
  if (!(1e-10f < len2)) {
    *axis = (tmuf_vec3){1.0f, 0.0f, 0.0f};
    *angle = 0.0f;
    return;
  }
  const float inv = 1.0f / sqrtf(len2);
  a[0] *= inv, a[1] *= inv, a[2] *= inv;
  int i = 0;
  if (fabsf(a[0]) < fabsf(a[1]))
    i = 1;
  if (fabsf(a[i]) < fabsf(a[2]))
    i = 2;
  const float qv[3] = {q.x, q.y, q.z};
  const float s = qv[i] / a[i];
  *angle = atan2_x87(s, q.w) * 2.0f;
  *axis = (tmuf_vec3){a[0], a[1], a[2]};
}

/* GmVec3::MultInverse(iso): the point in the iso's frame */
static tmuf_vec3 to_local(tmuf_vec3 p, const tmuf_iso4 *iso) {
  const float d[3] = {p.x - iso->t.x, p.y - iso->t.y, p.z - iso->t.z};
  const tmuf_mat3 *m = &iso->r;
  tmuf_vec3 out;
  out.x = (m->m[0][0] * d[0] + m->m[1][0] * d[1]) + m->m[2][0] * d[2];
  out.y = (m->m[0][1] * d[0] + m->m[1][1] * d[1]) + m->m[2][1] * d[2];
  out.z = (m->m[0][2] * d[0] + m->m[1][2] * d[1]) + m->m[2][2] * d[2];
  return out;
}

/* ---- state ---- */

static const tmuf_mat3 *history_oldest(const tmuf_stunts *st) { return &st->history[st->history_start]; }

static void history_add(tmuf_stunts *st, const tmuf_mat3 *rot) {
  if (st->history_count < TMUF_STUNT_HISTORY) {
    st->history[(st->history_start + st->history_count) % TMUF_STUNT_HISTORY] = *rot;
    st->history_count++;
  } else {
    st->history[st->history_start] = *rot;
    st->history_start = (st->history_start + 1) % TMUF_STUNT_HISTORY;
  }
}

/* CTrackManiaRace::ResetStunts */
static void reset_stunts(tmuf_stunts *st, const tmuf_mat3 *rotation) {
  st->rotation = (tmuf_vec3){0.0f, 0.0f, 0.0f};
  st->in_air = 0;
  st->takeoff_time = st->landing_time = NONE;
  st->crash = 0;
  st->last_rotation = st->history_count ? *history_oldest(st) : *rotation;
}

void tmuf_stunts_reset_player(tmuf_stunts *st, const tmuf_mat3 *rotation) {
  reset_stunts(st, rotation);
  st->previous_landing_time = NONE;
  st->chain = st->chain_window = 0;
  memset(st->figure_points, 0, sizeof st->figure_points);
  st->score = st->frozen_score = 0;
}

void tmuf_stunts_input(tmuf_stunts *st, uint32_t now, int accelerate, int brake, int32_t steer, int event) {
  const uint32_t slot = (now / TMUF_CONTROL_TICK_MS) % 16u;
  const uint32_t prev = st->input_change[(slot + 15u) % 16u];
  const int changed = event || (accelerate != 0) != (st->last_accelerate != 0) ||
                      (brake != 0) != (st->last_brake != 0) || steer != st->last_steer;
  st->input_change[slot] = changed ? now : prev;
  st->last_accelerate = (uint8_t)(accelerate != 0);
  st->last_brake = (uint8_t)(brake != 0);
  st->last_steer = steer;
}

/* CTrackManiaRace::IsMasterJump: no input changed in (from, to] */
static int is_master_jump(const tmuf_stunts *st, uint32_t from, uint32_t to) {
  const uint32_t latest = st->input_change[(to / TMUF_CONTROL_TICK_MS) % 16u];
  return latest <= from;
}

/* CTrackManiaRace::IsStuntTimeOver (the player's race started at the race start) */
static int time_over(const tmuf_race *race, uint32_t now) {
  const uint32_t start = TMUF_CONTROL_RACE_START_MS;
  if (now <= start)
    return 0;
  return race->time_limit < now - start;
}

/* CTrackManiaRace::GetTimePenalty */
static uint32_t time_penalty(uint32_t over_ms) { return over_ms ? (over_ms * 10u) / 1000u : 0u; }

/* CTrackManiaRace::UpdateStuntTime: the rotation since the last update */
static void update_stunt_time(tmuf_stunts *st, const tmuf_mat3 *rot) {
  const tmuf_mat3 rel = mul_transpose(rot, &st->last_rotation);
  float angle;
  tmuf_vec3 axis;
  quat_rotation(quat_from_mat3(&rel), &angle, &axis);
  const float dx = axis.x * angle, dy = axis.y * angle, dz = axis.z * angle;
  st->rotation.x = st->rotation.x + dx;
  st->rotation.y = st->rotation.y + dy;
  st->rotation.z = st->rotation.z + dz;
  st->last_rotation = *rot;
}

static uint32_t half_turns(float a, int crash) {
  const float q = crash ? (float)((double)a / PI) : (float)((double)(float)((double)a + HALF_PI) / PI);
  return (uint32_t)(int64_t)q;
}

/* CTrackManiaRace::ComputeStunt at a landing */
static void compute_stunt(tmuf_race *race, uint32_t now, const tmuf_stunt_car *car) {
  tmuf_stunts *st = &race->stunts;
  uint32_t air = 0;
  if (st->takeoff_time != NONE) {
    air = (now - st->takeoff_time) / 100u;
    if (air < 5u)
      return;
  }
  const float ax = fabsf(st->rotation.x), ay = fabsf(st->rotation.y), az = fabsf(st->rotation.z);
  const uint32_t ny = half_turns(ay, st->crash), nx = half_turns(ax, st->crash), nz = half_turns(az, st->crash);
  uint32_t fig;
  if (nz) {
    if (nx) {
      if (ny)
        fig = az > ax && az > ay ? 0x10u : ax > az && ax > ay ? 0x0fu : 0x0eu;
      else
        fig = az <= ax ? 0x0bu : 0x0du;
    } else {
      fig = ny ? (az <= ay ? 9u : 0x0cu) : 7u;
    }
  } else if (nx) {
    if (ny)
      fig = ax <= ay ? 8u : 0x0au;
    else
      fig = 0.0f < st->rotation.x ? 2u : 3u;
  } else if (ny) {
    /* a spin: flat, or on the side (wall) at takeoff */
    const float up_y = st->takeoff.r.m[1][1];
    if ((double)fabsf(up_y) > SIDE_UP)
      fig = 4u;
    else {
      const float x = to_local(*car->position, &st->takeoff).x, sy = st->rotation.y;
      fig = (x > 0.0f && sy < 0.0f) || (x < 0.0f && 0.0f < sy) ? 6u : 5u;
    }
  } else {
    fig = 1u;
  }
  if (st->crash)
    fig += 0x11u;
  int reverse = fabsf(st->landing_angle) >= 2.74889374f;
  int straight = (double)fabsf(st->landing_angle) <= EIGHTH_PI;
  int master = 0;
  if (fig - 2u <= 14u) {
    master = is_master_jump(st, st->takeoff_time + 100u, st->landing_time - 100u);
    if (!straight && !reverse)
      master = 0;
  }
  const uint32_t since = st->takeoff_time - st->previous_landing_time;
  if (st->previous_landing_time != NONE && since <= st->chain_window)
    st->chain++;
  else
    st->chain = 0;
  st->previous_landing_time = st->landing_time;
  if (st->crash)
    master = straight = reverse = 0;
  uint32_t base = nx * 15u + air + (ny + nz * 2u) * 10u;
  if (fig == 6u)
    base += 5u;
  else if (fig == 1u)
    base >>= 1;
  if (st->crash)
    base >>= 1;
  float mult = 1.0f;
  if (reverse || straight)
    mult = 1.25f;
  if (master)
    mult = (float)((double)mult + 0.25);
  if (st->chain > 0u)
    mult = 0.2f + mult;
  if (st->chain > 1u)
    mult = 0.15f + mult;
  if (st->chain > 2u)
    mult = 0.1f + mult;
  if (st->chain > 3u)
    mult = 0.05f + mult;
  if (st->chain > 4u)
    mult = (float)(st->chain - 4u) * 0.02f + mult;
  /* repeated figures count less */
  const uint32_t idx = fig < TMUF_STUNT_FIGURES ? fig : TMUF_STUNT_FIGURES - 1u;
  float repeat = (float)((double)((float)st->figure_points[idx] * 0.2f) / 100.0);
  if (0.75f < repeat)
    repeat = 0.75f;
  const float keep = 1.0f - repeat;
  uint32_t points = (uint32_t)(int64_t)(keep * (float)base);
  if (points == 0u)
    points = 1u;
  points = (uint32_t)(int64_t)((float)points * mult);
  if (getenv("TMUF_STUNTS_DEBUG"))
    fprintf(stderr,
            "stunt t=%u fig %u n %u %u %u air %u rot %g %g %g angle %g straight %d reverse %d master %d chain %u "
            "base %u mult %g repeat %g points %u%s score %u\n",
            now, fig, nx, ny, nz, air, (double)st->rotation.x, (double)st->rotation.y, (double)st->rotation.z,
            (double)st->landing_angle, straight, reverse, master, st->chain, base, (double)mult, (double)repeat,
            points, time_over(race, now) ? " (time over)" : "", st->score);
  if (time_over(race, now))
    return;
  st->score += points;
  uint32_t window = 2000u;
  if (st->chain_window && st->chain_window > window + since)
    window = st->chain_window - since;
  st->chain_window = window + points * 20u;
  st->figure_points[idx] += points;
}

void tmuf_stunts_update(tmuf_race *race, uint32_t now, const tmuf_stunt_car *car_in) {
  tmuf_stunts *st = &race->stunts;
  /* the car's location (CSceneMobil) lags the body by a step: it is where
     the body was at the previous update; the contacts are the last step's */
  const tmuf_iso4 seen = st->has_seen ? st->seen : (tmuf_iso4){*car_in->rotation, *car_in->position};
  st->seen.r = *car_in->rotation;
  st->seen.t = *car_in->position;
  st->has_seen = 1;
  tmuf_stunt_car carv = *car_in;
  carv.rotation = &seen.r;
  carv.position = &seen.t;
  const tmuf_stunt_car *car = &carv;
  history_add(st, car->rotation);
  if (st->in_air) {
    if (car->in_water)
      reset_stunts(st, car->rotation);
    if (car->wheel_contact || car->body_contact) {
      if (car->body_contact && (0.5f < car->body_angle_side || 0.5f < car->body_angle_length))
        st->crash = 1;
      st->landing_time = now;
      const float f = car->forward_speed, s = car->side_speed;
      const float len = sqrtf(f * f + s * s);
      st->landing_angle = 1e-5f < len ? atan2_x87(s / len, f / len) : 0.0f;
      compute_stunt(race, now, car);
      reset_stunts(st, car->rotation);
      st->in_air = 0;
    } else {
      st->landing_time = NONE;
      update_stunt_time(st, car->rotation);
    }
    if (st->in_air)
      return;
  }
  if (!car->wheel_contact && !car->body_contact && !car->in_water && now > TMUF_CONTROL_RACE_START_MS) {
    reset_stunts(st, car->rotation);
    if (!race->completed) {
      st->takeoff_time = now;
      st->in_air = 1;
      st->takeoff.r = *car->rotation;
      st->takeoff.t = *car->position;
    }
  }
}

void tmuf_stunts_respawn(tmuf_stunts *st, const tmuf_mat3 *rotation) {
  st->score -= st->score < 50u ? st->score : 50u;
  reset_stunts(st, rotation);
}

void tmuf_stunts_time(tmuf_race *race, uint32_t now) {
  tmuf_stunts *st = &race->stunts;
  if (!race->stunts_mode || !time_over(race, now))
    return;
  if (!st->frozen_score && st->score)
    st->frozen_score = st->score;
  if (!st->frozen_score)
    return;
  uint32_t over = 0;
  if (race->completed) {
    if (race->finish_time > race->time_limit)
      over = race->finish_time - race->time_limit;
  } else if (now - TMUF_CONTROL_RACE_START_MS > race->time_limit) {
    over = now - race->time_limit - TMUF_CONTROL_RACE_START_MS;
  }
  const uint32_t pen = time_penalty(over);
  st->score = st->frozen_score > pen ? st->frozen_score - pen : 0u;
}

void tmuf_stunts_finish(tmuf_race *race) {
  tmuf_stunts *st = &race->stunts;
  if (!race->stunts_mode || race->finish_time <= race->time_limit)
    return;
  const uint32_t pen = time_penalty(race->finish_time - race->time_limit);
  if (pen)
    st->score = st->frozen_score > pen ? st->frozen_score - pen : 0u;
}
