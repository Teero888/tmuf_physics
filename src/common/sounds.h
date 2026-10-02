#ifndef TMUF_COMMON_SOUNDS_H
#define TMUF_COMMON_SOUNDS_H

/* The game's sound descriptors as the public tmuf_sound (sounds.c). */

#include "tmuf_physics/tmuf_physics.h"

#include "common/arena.h"
#include "common/assets.h"
#include "common/pack_classes.h"
#include "common/scene.h"

/* The sound a node reference of `owner` names (a CPlugSound or subclass),
   NULL if it is none. Allocated in arena. */
const tmuf_sound *tmuf_sound_build(tmuf_assets *assets, tmuf_asset *owner, tmuf_gbx_node *ref, tmuf_arena *arena);

/* The car's sound slots from its mobil's CSceneSoundSource links. */
void tmuf_car_sounds_build(tmuf_car_sound out[TMUF_CAR_SOUND_COUNT], tmuf_assets *assets, tmuf_asset *mobil_owner,
                           const tmuf_scene_object *mobil, tmuf_arena *arena);

#endif
