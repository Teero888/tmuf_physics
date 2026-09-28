/* Public tracks and worlds on the reference backend. */

#include <stdlib.h>
#include <string.h>

#include <tmuf_physics/tmuf_physics.h>

#include "common/api_common.h"
#include "common/controls.h"
#include "reference/sim.h"

tmuf_backend tmuf_backend_id(void) { return TMUF_BACKEND_REFERENCE; }

struct tmuf_track {
  tmuf_track_base base;
  ref_sim tpl; /* the car at time 0; worlds are clones of it */
};

struct tmuf_world_state {
  ref_sim sim;
};

/* ---- tracks ---- */

tmuf_track *tmuf_track_load(const tmuf_packs *packs, const void *map, size_t size, const tmuf_track_options *options,
                            char *err, size_t err_size) {
  tmuf_track *t = calloc(1, sizeof *t);
  if (!t) {
    tmuf_set_error(err, err_size, "out of memory");
    return NULL;
  }
  if (!tmuf_track_base_load(&t->base, packs, map, size, options, err, err_size)) {
    tmuf_track_base_free(&t->base);
    free(t);
    return NULL;
  }
  const tmuf_iso *st = &t->base.scene.start;
  gm_iso4 spawn;
  for (int i = 0; i < 3; i++)
    for (int k = 0; k < 3; k++)
      spawn.r.m[i][k] = st->m[i][k];
  spawn.t = v3(st->t[0], st->t[1], st->t[2]);
  ref_tick first = tmuf_control_tick_at(0, 0.0f, 0.0f, 0.0f, 0);
  char e[512] = "";
  if (!ref_sim_init(&t->tpl, &t->base.scene, &t->base.vehicle, &spawn, options ? options->seed : 0, &first, e,
                    sizeof e)) {
    tmuf_set_error(err, err_size, "simulation: %s", e);
    ref_sim_free(&t->tpl);
    tmuf_track_base_free(&t->base);
    free(t);
    return NULL;
  }
  t->tpl.race.laps = t->base.laps;
  return t;
}

void tmuf_track_free(tmuf_track *t) {
  if (!t)
    return;
  ref_sim_free(&t->tpl);
  tmuf_track_base_free(&t->base);
  free(t);
}

const char *tmuf_track_name(const tmuf_track *t) { return t->base.map.name ? t->base.map.name : ""; }
const char *tmuf_track_environment(const tmuf_track *t) {
  return t->base.scene.collection ? t->base.scene.collection : "";
}
const char *tmuf_track_vehicle(const tmuf_track *t) { return t->base.vehicle_name ? t->base.vehicle_name : ""; }
uint32_t tmuf_track_checkpoints(const tmuf_track *t) { return t->tpl.race.checkpoint_count; }
uint32_t tmuf_track_laps(const tmuf_track *t) { return t->base.laps; }

uint32_t tmuf_track_triangles(const tmuf_track *t, const tmuf_triangle **triangles) {
  if (triangles)
    *triangles = t->base.triangles;
  return t->base.triangle_count;
}

/* ---- worlds ---- */

static void bind(tmuf_world *w) {
  w->body = &w->state->sim.body;
  w->car = &w->state->sim.car;
  w->race = &w->state->sim.race;
}

tmuf_world tmuf_world_empty(void) {
  tmuf_world w;
  memset(&w, 0, sizeof w);
  return w;
}

int tmuf_world_init(tmuf_world *w, const tmuf_track *track) {
  *w = tmuf_world_empty();
  tmuf_world_state *st = calloc(1, sizeof *st);
  if (!st)
    return 0;
  if (!ref_sim_clone(&st->sim, &track->tpl)) {
    free(st);
    return 0;
  }
  w->track = track;
  w->state = st;
  bind(w);
  return 1;
}

int tmuf_world_copy(tmuf_world *to, const tmuf_world *from) {
  if (to == from)
    return 1;
  if (!from->state) {
    tmuf_world_free(to);
    return 1;
  }
  if (!to->state || to->track != from->track) {
    tmuf_world_free(to);
    if (!tmuf_world_init(to, from->track))
      return 0;
  }
  ref_sim_copy_state(&to->state->sim, &from->state->sim);
  to->tick = from->tick;
  to->input = from->input;
  return 1;
}

void tmuf_world_tick(tmuf_world *w) {
  ref_sim *s = &w->state->sim;
  const tmuf_input *in = &w->input;
  ref_tick tk = tmuf_control_tick_at(w->tick, in->accelerate, in->brake, in->steer, in->respawn);
  /* the first tick's controls are installed as the car is created
     (ReplayVehicleSimulation::Start) */
  if (s->first_step)
    car_set_controls(&s->car, tk.gate_a, tk.gate_b, tk.steering);
  ref_sim_step(s, &tk);
  w->tick++;
}

void tmuf_world_free(tmuf_world *w) {
  if (w->state) {
    ref_sim_free(&w->state->sim);
    free(w->state);
  }
  *w = tmuf_world_empty();
}
