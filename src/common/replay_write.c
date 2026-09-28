/* tmuf_replay_write: a run as a replay the game plays and validates.

   The layout is the game's own (CGameCtnReplayRecord with one
   CGameCtnGhost), with an uncompressed body. The game's validator replays
   the ghost's inputs and compares the car's position every 100 ms with the
   ghost's samples, and the respawn count with the ghost's; the samples,
   race time, respawns and checkpoint times come from simulating the run. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common/api_common.h"

/* ---- a growing byte buffer ---- */

typedef struct wbuf {
  uint8_t *d;
  size_t n, cap;
  int oom;
} wbuf;

static void wb_put(wbuf *b, const void *p, size_t n) {
  if (b->oom)
    return;
  if (b->n + n > b->cap) {
    size_t cap = b->cap ? b->cap : 4096;
    while (cap < b->n + n)
      cap *= 2;
    uint8_t *d = realloc(b->d, cap);
    if (!d) {
      b->oom = 1;
      return;
    }
    b->d = d;
    b->cap = cap;
  }
  if (n)
    memcpy(b->d + b->n, p, n);
  b->n += n;
}

static void wb_u8(wbuf *b, uint8_t v) { wb_put(b, &v, 1); }
static void wb_u16(wbuf *b, uint16_t v) {
  uint8_t p[2] = {(uint8_t)v, (uint8_t)(v >> 8)};
  wb_put(b, p, 2);
}
static void wb_u32(wbuf *b, uint32_t v) {
  uint8_t p[4] = {(uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24)};
  wb_put(b, p, 4);
}
static void wb_f32(wbuf *b, float f) {
  uint32_t v;
  memcpy(&v, &f, 4);
  wb_u32(b, v);
}
static void wb_str(wbuf *b, const char *s) {
  const size_t n = s ? strlen(s) : 0;
  wb_u32(b, (uint32_t)n);
  wb_put(b, s, n);
}
static void wb_set_u32(wbuf *b, size_t at, uint32_t v) {
  if (b->oom)
    return;
  uint8_t p[4] = {(uint8_t)v, (uint8_t)(v >> 8), (uint8_t)(v >> 16), (uint8_t)(v >> 24)};
  memcpy(b->d + at, p, 4);
}

/* ids (lookback strings): the first id of an archive part carries the
   version; every string is written as a new one */
typedef struct ids {
  int started;
} ids;

static void wb_id(wbuf *b, ids *st, const char *s) {
  if (!st->started) {
    wb_u32(b, 3);
    st->started = 1;
  }
  if (!s || !s[0]) {
    wb_u32(b, 0xffffffffu);
    return;
  }
  wb_u32(b, 0x40000000u);
  wb_str(b, s);
}

/* a skippable chunk: id, "PIKS", size, then the payload written after it */
static size_t skippable_begin(wbuf *b, uint32_t id) {
  wb_u32(b, id);
  wb_put(b, "PIKS", 4);
  wb_u32(b, 0);
  return b->n;
}
static void skippable_end(wbuf *b, size_t start) { wb_set_u32(b, start - 4, (uint32_t)(b->n - start)); }

/* zlib data of stored (uncompressed) deflate blocks */
static void wb_zlib_stored(wbuf *b, const uint8_t *d, size_t n) {
  wb_u8(b, 0x78);
  wb_u8(b, 0x01);
  size_t off = 0;
  do {
    const size_t k = n - off > 65535 ? 65535 : n - off;
    wb_u8(b, off + k == n ? 1 : 0);
    wb_u16(b, (uint16_t)k);
    wb_u16(b, (uint16_t)~k);
    wb_put(b, d + off, k);
    off += k;
  } while (off < n);
  uint32_t s1 = 1, s2 = 0;
  for (size_t i = 0; i < n; i++) {
    s1 = (s1 + d[i]) % 65521u;
    s2 = (s2 + s1) % 65521u;
  }
  const uint32_t adler = s2 << 16 | s1;
  const uint8_t be[4] = {(uint8_t)(adler >> 24), (uint8_t)(adler >> 16), (uint8_t)(adler >> 8), (uint8_t)adler};
  wb_put(b, be, 4);
}

/* ---- ghost samples (CSceneVehicleCar state, version 9: 61 bytes) ---- */

typedef struct sample {
  tmuf_vec3 pos, lin, ang;
  tmuf_quat q;
  float forward, sideward; /* speed in the car's frame */
  uint8_t steer, gas, brake;
} sample;

static const double PI = 3.14159265358979323846;

static int32_t clampi(double v, int32_t lo, int32_t hi) {
  const double r = floor(v + 0.5);
  return r < lo ? lo : r > hi ? hi : (int32_t)r;
}

/* a unit quaternion as half angle (u16, 0..pi) and axis heading/pitch (i16) */
static void wb_quat6(wbuf *b, tmuf_quat q) {
  double w = (double)q.w, x = (double)q.x, y = (double)q.y, z = (double)q.z;
  const double n = sqrt(w * w + x * x + y * y + z * z);
  if (n > 0)
    w /= n, x /= n, y /= n, z /= n;
  if (w > 1)
    w = 1;
  if (w < -1)
    w = -1;
  const double a = acos(w), s = sqrt(x * x + y * y + z * z);
  double heading = 0, pitch = 0;
  if (s > 1e-9) {
    heading = atan2(y / s, x / s);
    pitch = asin(z / s > 1 ? 1 : z / s < -1 ? -1 : z / s);
  }
  wb_u16(b, (uint16_t)clampi(a / PI * 65535.0, 0, 65535));
  wb_u16(b, (uint16_t)(int16_t)clampi(heading / PI * 32767.0, -32767, 32767));
  wb_u16(b, (uint16_t)(int16_t)clampi(pitch / (PI / 2) * 32767.0, -32767, 32767));
}

/* a vector as log magnitude (i16, x1000) and heading/pitch bytes */
static void wb_vec3_4(wbuf *b, tmuf_vec3 v) {
  const double x = (double)v.x, y = (double)v.y, z = (double)v.z, m = sqrt(x * x + y * y + z * z);
  if (!(m > 1e-12)) {
    wb_u32(b, 0x8000u);
    return;
  }
  const double heading = atan2(y, x), pitch = asin(z / m > 1 ? 1 : z / m < -1 ? -1 : z / m);
  const uint32_t mag = (uint16_t)(int16_t)clampi(log(m) * 1000.0, -32767, 32767);
  const uint32_t h = (uint8_t)(int8_t)clampi(heading / PI * 127.0, -127, 127);
  const uint32_t p = (uint8_t)(int8_t)clampi(pitch / (PI / 2) * 127.0, -127, 127);
  wb_u32(b, mag | h << 16 | p << 24);
}

static void wb_sample(wbuf *b, const sample *s) {
  wb_f32(b, s->pos.x);
  wb_f32(b, s->pos.y);
  wb_f32(b, s->pos.z);
  wb_quat6(b, s->q);
  wb_vec3_4(b, s->lin);
  wb_vec3_4(b, s->ang);
  /* CSceneVehicleVis state: speeds, rpm, wheel rotations, controls, then
     neutral dampers and no contacts */
  wb_u16(b, (uint16_t)clampi(((double)s->forward + 1000.0) / 11000.0 * 65535.0, 0, 65535));
  wb_u16(b, (uint16_t)clampi(((double)s->sideward + 1000.0) / 2000.0 * 65535.0, 0, 65535));
  for (int i = 0; i < 5; i++)
    wb_u16(b, 0);
  wb_u8(b, s->steer);
  wb_u8(b, s->gas);
  wb_u8(b, s->brake);
  const uint8_t rest[18] = {0, 0, 0x7f, 0x7f, 0, 0x7f, 0x80, 0, 0x80, 0, 0x80, 0, 0x80, 0, 0, 0, 0, 0};
  wb_put(b, rest, sizeof rest);
}

static tmuf_quat quat_of(const tmuf_mat3 *r) {
  double m[3][3];
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 3; k++)
      m[i][k] = (double)r->m[i][k];
  double w, x, y, z;
  const double tr = m[0][0] + m[1][1] + m[2][2];
  if (tr > 0) {
    const double s = sqrt(tr + 1.0) * 2;
    w = s / 4, x = (m[2][1] - m[1][2]) / s, y = (m[0][2] - m[2][0]) / s, z = (m[1][0] - m[0][1]) / s;
  } else if (m[0][0] > m[1][1] && m[0][0] > m[2][2]) {
    const double s = sqrt(1.0 + m[0][0] - m[1][1] - m[2][2]) * 2;
    w = (m[2][1] - m[1][2]) / s, x = s / 4, y = (m[0][1] + m[1][0]) / s, z = (m[0][2] + m[2][0]) / s;
  } else if (m[1][1] > m[2][2]) {
    const double s = sqrt(1.0 + m[1][1] - m[0][0] - m[2][2]) * 2;
    w = (m[0][2] - m[2][0]) / s, x = (m[0][1] + m[1][0]) / s, y = s / 4, z = (m[1][2] + m[2][1]) / s;
  } else {
    const double s = sqrt(1.0 + m[2][2] - m[0][0] - m[1][1]) * 2;
    w = (m[1][0] - m[0][1]) / s, x = (m[0][2] + m[2][0]) / s, y = (m[1][2] + m[2][1]) / s, z = s / 4;
  }
  tmuf_quat q = {(float)w, (float)x, (float)y, (float)z};
  return q;
}

/* the car as the game samples it after a tick; a respawn in the next tick
   is applied before the sample is taken */
static sample sample_of(const tmuf_world *w, const tmuf_input *next) {
  const tmuf_dyna_state *st = &w->sim.body.state;
  sample s;
  memset(&s, 0, sizeof s);
  if (next && next->respawn && w->sim.race.has_spawn) {
    s.pos = w->sim.race.current.t;
    s.q = quat_of(&w->sim.race.current.r);
    return s;
  }
  s.pos = st->pos;
  s.q = st->quat;
  s.lin = st->lin;
  s.ang = st->ang;
  const float(*m)[3] = st->rot.m;
  s.forward = st->lin.x * m[0][2] + st->lin.y * m[1][2] + st->lin.z * m[2][2];
  s.sideward = st->lin.x * m[0][0] + st->lin.y * m[1][0] + st->lin.z * m[2][0];
  const tmuf_input *in = &w->input;
  s.steer = (uint8_t)clampi(((double)in->steer / 65536.0 + 1.0) / 2.0 * 255.0, 0, 255);
  s.gas = in->accelerate ? 255 : 0;
  s.brake = in->brake ? 255 : 0;
  return s;
}

/* ---- the replay ---- */

enum { RACE_TICK = TMUF_RACE_START_MS / TMUF_TICK_MS - 1 }; /* the first tick of the race (reads the events at 100000) */
enum { ACT_RUNNING, ACT_FINISH, ACT_ACCEL, ACT_BRAKE, ACT_STEER, ACT_RESPAWN, ACT_COUNT };
static const char *const ACTIONS[ACT_COUNT] = {"_FakeIsRaceRunning", "_FakeFinishLine", "Accelerate",
                                               "Brake",              "Steer",           "Respawn"};

static uint32_t event_time(uint32_t tick) { return 100000u + (tick - RACE_TICK) * TMUF_TICK_MS; }

static void wb_event(wbuf *b, uint32_t time, uint8_t action, uint32_t value) {
  wb_u32(b, time);
  wb_u8(b, action);
  wb_u32(b, value);
}

static uint32_t steer_value(int32_t steer) { return (uint32_t)(-steer) & 0x00ffffffu; }

void tmuf_free(void *p) { free(p); }

void *tmuf_replay_write(const tmuf_track *track, const tmuf_input *inputs, uint32_t count,
                        const tmuf_replay_write_options *options, size_t *size, char *err, size_t err_size) {
  if (size)
    *size = 0;
  if (!track || (!inputs && count)) {
    tmuf_set_error(err, err_size, "no track or inputs");
    return NULL;
  }
  if (count <= RACE_TICK) {
    tmuf_set_error(err, err_size, "%u inputs: the race starts at tick %u", count, (unsigned)RACE_TICK);
    return NULL;
  }
  const tmuf_track_base *base = tmuf_track_base_of(track);
  const char *login = options && options->login && options->login[0] ? options->login : "tmuf_physics";
  const char *nickname = options && options->nickname && options->nickname[0] ? options->nickname : login;

  /* the run: inputs before the race start have no events (the game reads
     none during the countdown) */
  tmuf_world w = tmuf_world_empty();
  if (!tmuf_world_init(&w, track)) {
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  const size_t max_samples = (size_t)count / 10u + 2u;
  sample *samples = malloc(sizeof *samples * max_samples);
  if (!samples) {
    tmuf_world_free(&w);
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  const tmuf_input none = {0, 0, 0, 0};
  uint32_t ticks = 0, nsamples = 0;
  for (uint32_t i = 0; i < count && !w.sim.race.completed; i++) {
    w.input = i < RACE_TICK ? none : inputs[i];
    tmuf_world_tick(&w);
    ticks = i + 1;
    const uint32_t t = ticks * TMUF_TICK_MS;
    if (t >= TMUF_RACE_START_MS - 10u && (t - (TMUF_RACE_START_MS - 10u)) % 100u == 0 && nsamples < max_samples) {
      const tmuf_input *next = i + 1 < count && !w.sim.race.completed ? &inputs[i + 1] : NULL;
      samples[nsamples++] = sample_of(&w, next);
    }
  }
  const int finished = w.sim.race.completed;
  const uint32_t race_time = finished ? w.sim.race.finish_time : UINT32_MAX;
  const uint32_t duration = finished ? race_time : ticks * TMUF_TICK_MS - TMUF_RACE_START_MS;
  const uint32_t respawns = w.sim.race.respawns;

  /* the ghost's samples: every 100 ms from 2590 ms, 3 s past the end (the
     game keeps recording), the last state repeated */
  const uint32_t sample_count = (TMUF_RACE_START_MS + duration - (TMUF_RACE_START_MS - 10u)) / 100u + 1u + 30u;
  wbuf sb = {0};
  for (uint32_t k = 0; k < sample_count; k++)
    wb_sample(&sb, &samples[k < nsamples ? k : nsamples - 1]);
  free(samples);
  wbuf sd = {0}; /* CGameGhost data */
  wb_u32(&sd, 0x0a02b000u); /* CSceneVehicleCar */
  wb_u32(&sd, 1);           /* fixed time step */
  wb_u32(&sd, 0);
  wb_u32(&sd, 100); /* period */
  wb_u32(&sd, 9);   /* sample version */
  wb_u32(&sd, (uint32_t)sb.n);
  wb_put(&sd, sb.d, sb.n);
  wb_u32(&sd, sample_count);
  wb_u32(&sd, 0);  /* first offset */
  wb_u32(&sd, 61); /* sample size */
  free(sb.d);

  /* ---- body ---- */
  wbuf b = {0};
  ids body_ids = {0};
  wb_u32(&b, 0x03093002u); /* the map */
  wb_u32(&b, (uint32_t)base->map_size);
  wb_put(&b, base->map_data, base->map_size);
  size_t c = skippable_begin(&b, 0x03093007u);
  wb_u32(&b, 0xffffffffu);
  skippable_end(&b, c);
  wb_u32(&b, 0x0309300eu);
  wb_u32(&b, 0xffffffffu);
  wb_u32(&b, 0x03093011u);
  wb_u32(&b, 0x03093014u); /* the ghosts */
  wb_u32(&b, 10);
  wb_u32(&b, 1);           /* one ghost */
  wb_u32(&b, 1);           /* node 1 */
  wb_u32(&b, 0x03092000u); /* CGameCtnGhost */

  wb_u32(&b, 0x0303f005u); /* samples */
  wb_u32(&b, (uint32_t)sd.n);
  const size_t packed_at = b.n;
  wb_u32(&b, 0);
  wb_zlib_stored(&b, sd.d, sd.n);
  wb_set_u32(&b, packed_at, (uint32_t)(b.n - packed_at - 4));
  free(sd.d);
  c = skippable_begin(&b, 0x03092005u);
  wb_u32(&b, race_time);
  skippable_end(&b, c);
  c = skippable_begin(&b, 0x03092008u);
  wb_u32(&b, respawns);
  skippable_end(&b, c);
  c = skippable_begin(&b, 0x03092009u); /* light trail color */
  wb_f32(&b, 1.0f);
  wb_f32(&b, 0.0f);
  wb_f32(&b, 0.0f);
  skippable_end(&b, c);
  c = skippable_begin(&b, 0x0309200au); /* stunt score */
  wb_u32(&b, 0);
  skippable_end(&b, c);
  c = skippable_begin(&b, 0x0309200bu); /* checkpoint times (and stunt score) */
  wb_u32(&b, w.sim.race.checkpoint_time_count);
  for (uint32_t i = 0; i < w.sim.race.checkpoint_time_count; i++) {
    wb_u32(&b, w.sim.race.checkpoint_times[i]);
    wb_u32(&b, 0);
  }
  skippable_end(&b, c);
  wb_u32(&b, 0x0309200cu);
  wb_u32(&b, 0);
  wb_u32(&b, 0x0309200eu); /* ghost uid */
  wb_id(&b, &body_ids, NULL);
  wb_u32(&b, 0x0309200fu);
  wb_str(&b, login);
  wb_u32(&b, 0x03092010u); /* validated map uid */
  wb_id(&b, &body_ids, NULL);
  wb_u32(&b, 0x03092012u); /* security key */
  for (int i = 0; i < 5; i++)
    wb_u32(&b, 0);
  c = skippable_begin(&b, 0x03092013u);
  wb_u32(&b, 0);
  wb_u32(&b, 0);
  skippable_end(&b, c);
  c = skippable_begin(&b, 0x03092014u); /* ghost version */
  wb_u32(&b, 7);
  skippable_end(&b, c);
  wb_u32(&b, 0x03092015u);
  wb_id(&b, &body_ids, nickname);
  c = skippable_begin(&b, 0x03092017u); /* skins (none), nickname, avatar */
  wb_u32(&b, 0);
  wb_str(&b, nickname);
  wb_str(&b, "");
  skippable_end(&b, c);
  wb_u32(&b, 0x03092018u); /* the car */
  const int map_car = base->map.vehicle[0] && base->map.vehicle[0][0] &&
                      strcmp(base->map.vehicle[0], base->vehicle_name ? base->vehicle_name : "") == 0;
  wb_id(&b, &body_ids, base->vehicle_name);
  wb_id(&b, &body_ids, map_car ? base->map.vehicle[1] : base->scene.collection);
  wb_id(&b, &body_ids, map_car ? base->map.vehicle[2] : "Nadeo");

  wb_u32(&b, 0x03092019u); /* the inputs */
  wb_u32(&b, duration);
  wb_u32(&b, 0);
  wb_u32(&b, ACT_COUNT);
  for (int i = 0; i < ACT_COUNT; i++)
    wb_id(&b, &body_ids, ACTIONS[i]);
  const size_t count_at = b.n;
  wb_u32(&b, 0);
  wb_u32(&b, 0);
  uint32_t nev = 0;
  tmuf_input prev = none;
  const uint32_t last = ticks; /* inputs of ticks [RACE_TICK, last) */
  for (uint32_t i = RACE_TICK; i < last; i++) {
    const tmuf_input *in = &inputs[i];
    const uint32_t t = event_time(i);
    if (i == RACE_TICK)
      wb_event(&b, t, ACT_RUNNING, 1), nev++;
    if (!!in->accelerate != !!prev.accelerate)
      wb_event(&b, t, ACT_ACCEL, in->accelerate != 0), nev++;
    if (!!in->brake != !!prev.brake)
      wb_event(&b, t, ACT_BRAKE, in->brake != 0), nev++;
    if (in->steer != prev.steer)
      wb_event(&b, t, ACT_STEER, steer_value(in->steer)), nev++;
    if (in->respawn)
      wb_event(&b, t, ACT_RESPAWN, 1), nev++;
    prev = *in;
  }
  if (finished)
    wb_event(&b, 100000u + race_time, ACT_FINISH, 1), nev++;
  wb_set_u32(&b, count_at, nev);
  wb_set_u32(&b, count_at + 4, nev);
  wb_str(&b, "TmForever.2.11.26");
  wb_u32(&b, 0);
  wb_u32(&b, 10);
  wb_u32(&b, 2);
  char settings[96];
  snprintf(settings, sizeof settings, "<id>Unassigned</id><laps>%u</laps><ct>1</ct>", base->laps);
  wb_str(&b, settings);
  wb_u32(&b, base->seed);
  wb_u32(&b, 0xfacade01u); /* end of the ghost */
  wb_u32(&b, 0);
  wb_u32(&b, 0); /* extras */
  wb_u32(&b, 0x03093015u);
  wb_u32(&b, 0xffffffffu);
  wb_u32(&b, 0xfacade01u);

  /* ---- header chunks ---- */
  wbuf h0 = {0}, h1 = {0};
  ids head_ids = {0};
  wb_u32(&h0, 7);
  wb_id(&h0, &head_ids, base->map.map[0]);
  wb_id(&h0, &head_ids, base->map.map[1]);
  wb_id(&h0, &head_ids, base->map.map[2]);
  wb_u32(&h0, race_time);
  wb_str(&h0, nickname);
  wb_str(&h0, login);
  char xml[512];
  snprintf(xml, sizeof xml,
           "<header type=\"replay\" version=\"TMr.7\" exever=\"2.11.26\"><challenge uid=\"%s\"/><times best=\"%d\" "
           "respawns=\"%u\" stuntscore=\"0\" validable=\"1\"/></header>",
           base->map.map[0] ? base->map.map[0] : "", finished ? (int)race_time : -1, respawns);
  wb_str(&h1, xml);

  wbuf f = {0};
  wb_put(&f, "GBX", 3);
  wb_u16(&f, 6);
  wb_put(&f, "BUUR", 4);
  wb_u32(&f, 0x03093000u);
  wb_u32(&f, (uint32_t)(4 + 16 + h0.n + h1.n)); /* user data size */
  wb_u32(&f, 2);
  wb_u32(&f, 0x03093000u);
  wb_u32(&f, (uint32_t)h0.n);
  wb_u32(&f, 0x03093001u);
  wb_u32(&f, (uint32_t)h1.n);
  wb_put(&f, h0.d, h0.n);
  wb_put(&f, h1.d, h1.n);
  wb_u32(&f, 2); /* nodes */
  wb_u32(&f, 0); /* external references */
  wb_put(&f, b.d, b.n);
  const int oom = b.oom || h0.oom || h1.oom || f.oom || sb.oom || sd.oom;
  free(b.d);
  free(h0.d);
  free(h1.d);
  tmuf_world_free(&w);
  if (oom) {
    free(f.d);
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  if (size)
    *size = f.n;
  return f.d;
}
