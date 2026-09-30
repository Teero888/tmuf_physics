#ifndef TMUF_COMMON_VEHICLE_H
#define TMUF_COMMON_VEHICLE_H

/* A vehicle as the game loads it: the collector (CGameCtnCollectorVehicle)
   names the mobil (CSceneVehicleCar), which holds the solid, the tunings,
   the vehicle materials and the vehicle struct. */

#include <stddef.h>
#include <stdint.h>

#include "common/assets.h"
#include "common/pack_classes.h"
#include "common/vehicle_tuning.h"

#define TMUF_VEHICLE_MAX_WHEELS 4
#define TMUF_VEHICLE_MAX_MATERIALS 31

typedef struct tmuf_vehicle {
  tmuf_vehicle_tuning tuning;
  /* solid collision tree (root CPlugTree) */
  tmuf_asset *solid_owner;
  tmuf_gbx_node *solid_tree;
  const tmuf_vehicle_struct *visual_struct; /* the visual rig (levels of detail) */
  tmuf_asset *visual_struct_owner;
  uint32_t wheel_count;
  struct {
    int kills_lateral_speed, front;
    const char *surface; /* tree name, e.g. FLSurf */
  } wheels[TMUF_VEHICLE_MAX_WHEELS];
  int has_params;
  float speed_cap, reverse_speed_threshold;
  float water_box[6]; /* center, half extents */
  uint32_t material_count;
  tmuf_vehicle_material materials[TMUF_VEHICLE_MAX_MATERIALS];
  /* fake contact texture (CPlugFileTga of the materials' bitmap), stored
     pixel order */
  uint32_t fake_width, fake_height, fake_bpp;
  const uint8_t *fake_pixels;
} tmuf_vehicle;

/* Loads the vehicle whose collector identifier is `name` (a ghost's
   vehicle id, e.g. "StadiumCar"). Returns 0 and fills err on failure. */
int tmuf_vehicle_load(tmuf_vehicle *v, tmuf_assets *assets, const char *name, char *err, size_t err_size);

#endif
