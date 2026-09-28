#ifndef TMUF_COMMON_VEHICLE_TUNING_H
#define TMUF_COMMON_VEHICLE_TUNING_H

/* Vehicle tuning values (CSceneVehicleCarTuning) decoded from the parsed
   tuning chunks: defaults, then each archived chunk in file order. Field
   names follow what the physics code uses them for. */

#include <stddef.h>
#include <stdint.h>

#include <tmuf_physics/tmuf_physics.h>

#include "common/assets.h"
#include "common/pack_classes.h"

#define TMUF_MATERIAL_RUBBER 9u



void tmuf_vehicle_tuning_defaults(tmuf_vehicle_tuning *t);
/* Applies the chunks of a parsed CSceneVehicleCarTuning (asset owns it, for
   resolving curve references). Returns 0 on success. */
int tmuf_vehicle_tuning_decode(tmuf_vehicle_tuning *t, tmuf_assets *assets, tmuf_asset *owner,
                               const tmuf_car_tuning *raw, char *err, size_t err_size);

#endif
