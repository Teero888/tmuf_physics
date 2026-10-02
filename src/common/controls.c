#include "common/controls.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---- control ticks (ReplayControlPlan, input-only validation) ---- */

enum { ACT_NONE, ACT_ACCEL, ACT_GAS, ACT_BRAKE, ACT_STEER, ACT_LEFT, ACT_RIGHT, ACT_RUNNING, ACT_FINISH, ACT_RESPAWN };

static int action_kind(const char *name) {
  static const struct {
    const char *n;
    int k;
  } T[] = {{"Accelerate", ACT_ACCEL}, {"Gas", ACT_GAS},         {"Brake", ACT_BRAKE},
           {"Steer", ACT_STEER},      {"SteerLeft", ACT_LEFT},  {"SteerRight", ACT_RIGHT},
           {"_FakeIsRaceRunning", ACT_RUNNING}, {"_FakeFinishLine", ACT_FINISH}, {"Respawn", ACT_RESPAWN}};
  for (size_t i = 0; i < sizeof T / sizeof T[0]; i++)
    if (name && strcmp(name, T[i].n) == 0)
      return T[i].k;
  return ACT_NONE;
}

static int32_t signed24(uint32_t e) {
  e &= 0x00ffffffu;
  return (e & 0x00800000u) ? (int32_t)(e | 0xff000000u) : (int32_t)e;
}

typedef struct ctl_state {
  int running, accel, brake, left, right;
  int32_t left_t, right_t, steer_t, accel_t, brake_t, gas_t;
  int32_t steer, gas;
} ctl_state;

/* the input the game reads from the events: analog or digital steering and
   gas, whichever changed last */
static void controls_from(const ctl_state *st, tmuf_control_tick *tk) {
  int32_t dt = st->left_t > st->right_t ? st->left_t : st->right_t;
  int analog = st->steer_t > dt || (st->steer_t == dt && !st->left && !st->right && abs(st->steer) > 655);
  tk->steer = analog ? st->steer : st->left ? -65536 : st->right ? 65536 : 0;
  int32_t gt = st->accel_t > st->brake_t ? st->accel_t : st->brake_t;
  int analog_gas = st->gas_t > gt || (st->gas_t == gt && !st->accel && !st->brake);
  if (analog_gas) {
    tk->accelerate = st->gas <= -19661;
    tk->brake = st->gas >= 19661;
  } else {
    tk->accelerate = st->accel != 0;
    tk->brake = st->brake != 0;
  }
  tk->gate_a = tk->accelerate ? 1.0f : 0.0f;
  tk->gate_b = tk->brake ? 1.0f : 0.0f;
  tk->steering = (float)tk->steer / 65536.0f;
}

/* the events' clock: the race starts where _FakeIsRaceRunning turns on
   (100000 in the game's own replays, other values in replays of TAS tools) */
static uint32_t events_base(const tmuf_ghost *g) {
  for (uint32_t i = 0; i < g->event_count; i++)
    if (g->events[i].action < g->action_count && action_kind(g->actions[g->events[i].action]) == ACT_RUNNING &&
        g->events[i].value != 0)
      return g->events[i].time;
  return 100000;
}

uint32_t tmuf_control_horns(const tmuf_ghost *g, uint32_t *ticks, uint32_t max) {
  const uint32_t base = events_base(g), prestart = 2600;
  uint32_t n = 0;
  for (uint32_t i = 0; i < g->event_count; i++) {
    const tmuf_input_event *e = &g->events[i];
    if (e->action >= g->action_count || !g->actions[e->action] || strcmp(g->actions[e->action], "Horn") != 0 ||
        !e->value)
      continue;
    /* the tick whose input reads it: the first t = (n + 1) * 10 ms with
       base - prestart + t >= its time */
    const int64_t t = (int64_t)e->time - base + prestart;
    const int64_t tick = t <= 10 ? 0 : (t + 9) / 10 - 1;
    if (ticks && n < max)
      ticks[n] = (uint32_t)tick;
    n++;
  }
  return n;
}

uint32_t tmuf_control_ticks(const tmuf_ghost *g, tmuf_control_tick **out) {
  const uint32_t tick_ms = 10, prestart = 2600;
  const uint32_t base = events_base(g);
  *out = NULL;
  int32_t final_target = (int32_t)prestart + (int32_t)g->input_duration;
  uint32_t cap = (uint32_t)(final_target / (int32_t)tick_ms) + 2;
  tmuf_control_tick *ticks = calloc(cap, sizeof *ticks);
  if (!ticks)
    return 0;
  int kinds[256] = {0};
  for (uint32_t i = 0; i < g->action_count && i < 256; i++) {
    kinds[i] = action_kind(g->actions[i]);
    if (getenv("TMUF_SIM_DEBUG"))
      fprintf(stderr, "action %u %s -> %d\n", i, g->actions[i] ? g->actions[i] : "?", kinds[i]);
  }
  ctl_state st;
  memset(&st, 0, sizeof st);
  uint32_t cursor = 0, n = 0;
  int prev_running = 0, reset_done = 0, spawn_done = 0;
  for (int32_t t = (int32_t)tick_ms; t <= final_target; t += (int32_t)tick_ms) {
    uint32_t sample = base - prestart + (uint32_t)t;
    uint32_t respawns = 0;
    int finish = 0, input_event = 0;
    while (cursor < g->event_count && g->events[cursor].time <= sample) {
      const tmuf_input_event *e = &g->events[cursor];
      int k = kinds[e->action];
      int active = e->value != 0;
      int32_t et = (int32_t)e->time;
      if (getenv("TMUF_SIM_EVENTS"))
        fprintf(stderr, "event time %u action %u kind %d value %08x running %d sample %d\n", e->time, e->action, k,
                e->value, st.running, (int)sample);
      if (k == ACT_RESPAWN && getenv("TMUF_SIM_DEBUG"))
        fprintf(stderr, "respawn event time %u value %08x running %d sample %d\n", e->time, e->value, st.running,
                (int)sample);
      if (k == ACT_RESPAWN && st.running && active)
        respawns++;
      if (k == ACT_FINISH && e->value == 1)
        finish = 1;
      if (k == ACT_ACCEL || k == ACT_GAS || k == ACT_BRAKE || k == ACT_STEER || k == ACT_LEFT || k == ACT_RIGHT)
        input_event = 1;
      switch (k) {
      case ACT_ACCEL:
        st.accel = active, st.accel_t = et;
        break;
      case ACT_GAS:
        st.gas = -signed24(e->value), st.gas_t = et;
        break;
      case ACT_BRAKE:
        st.brake = active, st.brake_t = et;
        break;
      case ACT_STEER:
        st.steer = -signed24(e->value), st.steer_t = et;
        break;
      case ACT_LEFT:
        st.left = active, st.left_t = et;
        break;
      case ACT_RIGHT:
        st.right = active, st.right_t = et;
        break;
      case ACT_RUNNING:
        st.running = active;
        break;
      default:
        break;
      }
      cursor++;
    }
    tmuf_control_tick *tk = &ticks[n++];
    tk->period_ms = tick_ms;
    tk->time_ms = (uint32_t)t;
    tk->finish_race = finish;
    tk->input_event = (uint8_t)input_event;
    if (!spawn_done && t >= 0) {
      tk->establish_spawn = 1;
      spawn_done = 1;
    }
    if (t >= (int32_t)prestart) {
      tk->enable_race = 1;
      tk->respawns = respawns;
      if (!reset_done && !prev_running && st.running) {
        tk->reset_at_race_start = 1;
        reset_done = 1;
      }
    }
    prev_running = st.running;
    controls_from(&st, tk);
  }
  /* appendUnobservedTrailingTick (race mode) */
  if (n > 0) {
    ticks[n] = ticks[n - 1];
    ticks[n].time_ms += ticks[n].period_ms;
    ticks[n].establish_spawn = 0;
    ticks[n].reset_at_race_start = 0;
    ticks[n].finish_race = 0;
    ticks[n].respawns = 0;
    ticks[n].input_event = 0;
    n++;
  }
  *out = ticks;
  return n;
}

tmuf_control_tick tmuf_control_tick_at(uint32_t index, int accelerate, int brake, int32_t steer, uint32_t respawns) {
  tmuf_control_tick t;
  memset(&t, 0, sizeof t);
  t.period_ms = TMUF_CONTROL_TICK_MS;
  t.time_ms = (index + 1u) * TMUF_CONTROL_TICK_MS;
  t.establish_spawn = index == 0;
  if (t.time_ms >= TMUF_CONTROL_RACE_START_MS) {
    t.enable_race = 1;
    t.respawns = respawns;
    /* _FakeIsRaceRunning turns on when the race starts */
    t.reset_at_race_start = t.time_ms - TMUF_CONTROL_TICK_MS < TMUF_CONTROL_RACE_START_MS;
  }
  t.accelerate = accelerate != 0;
  t.brake = brake != 0;
  t.steer = steer;
  t.gate_a = t.accelerate ? 1.0f : 0.0f;
  t.gate_b = t.brake ? 1.0f : 0.0f;
  t.steering = (float)steer / 65536.0f;
  return t;
}
