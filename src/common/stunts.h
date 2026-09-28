#ifndef TMUF_COMMON_STUNTS_H
#define TMUF_COMMON_STUNTS_H

/* CTrackManiaRace's stunt figures (tmuf_stunts in tmuf_physics/state.h):
   plain functions on the public state, called by both backends' step at the
   points the game calls them. */

#include <tmuf_physics/state.h>

/* the car as UpdateStunts reads it (CSceneVehicleCar after the last step) */
typedef struct tmuf_stunt_car {
  const tmuf_mat3 *rotation;
  const tmuf_vec3 *position;
  float forward_speed, side_speed;
  int wheel_contact, body_contact, in_water;
  float body_angle_side, body_angle_length;
} tmuf_stunt_car;

/* CTrackManiaRace::ResetPlayer at the race start */
void tmuf_stunts_reset_player(tmuf_stunts *st, const tmuf_mat3 *rotation);
/* the tick's input (CTrackManiaPlayerInfo::SetInputState), before update */
void tmuf_stunts_input(tmuf_stunts *st, uint32_t now, int accelerate, int brake, int32_t steer, int event);
/* CTrackManiaRace::UpdateStunts, every tick of the race before its respawns */
void tmuf_stunts_update(tmuf_race *race, uint32_t now, const tmuf_stunt_car *car);
/* CTrackManiaRace::RespawnPlayer */
void tmuf_stunts_respawn(tmuf_stunts *st, const tmuf_mat3 *rotation);
/* the Stunts mode time limit after the tick's respawns (InputRace, UpdateAsync) */
void tmuf_stunts_time(tmuf_race *race, uint32_t now);
/* CTrackManiaRace::OnFinishLine: the Stunts mode time penalty at the finish */
void tmuf_stunts_finish(tmuf_race *race);

#endif
