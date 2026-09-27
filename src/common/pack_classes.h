#ifndef TMUF_COMMON_PACK_CLASSES_H
#define TMUF_COMMON_PACK_CLASSES_H

/* Readers for the node classes stored in the game's packs (solids, trees,
   visuals, surfaces, lights, ...) and the data kept from them. */

#include <stddef.h>
#include <stdint.h>

#include "common/gbx.h"

typedef struct tmuf_plug_solid {
  tmuf_gbx_node *tree;
  tmuf_gbx_node *model; /* solid whose tree is used when use_model is set */
  int use_model;
  int has_physics;
  float mass, center_of_mass[3], inertia[9];
  float fluid_friction, response_a, response_b;
} tmuf_plug_solid;

typedef struct tmuf_plug_tree {
  const char *name;
  uint32_t flags; /* decoded CPlugTree::SFlags word */
  int has_iso;
  float iso[12]; /* 3x3 rotation (row-major) then translation */
  uint32_t child_count;
  tmuf_gbx_node **children;
  tmuf_gbx_node *visual, *shader, *material, *surface, *generator;
} tmuf_plug_tree;

#define TMUF_VISUAL_MAX_TEXCOORDS 8

typedef struct tmuf_plug_visual {
  uint32_t flags;
  uint32_t vertex_count;
  uint32_t texcoord_count;
  uint8_t texcoord_dim[TMUF_VISUAL_MAX_TEXCOORDS];
  const float *texcoords[TMUF_VISUAL_MAX_TEXCOORDS];
  float bbox[6]; /* center, half extents */
  uint32_t vertex_stride;
  const uint8_t *vertices; /* position, [normal u32], [color u32], [sprite 8] */
  uint32_t index_count;
  const uint16_t *indices;
  tmuf_gbx_node *material;
} tmuf_plug_visual;

typedef struct tmuf_plug_surface_material {
  tmuf_gbx_node *ref; /* explicit material node, or NULL */
  uint16_t id;        /* default material id when ref is NULL */
} tmuf_plug_surface_material;

typedef struct tmuf_plug_surface {
  tmuf_gbx_node *geom;
  uint32_t material_count;
  tmuf_plug_surface_material *materials;
} tmuf_plug_surface;

enum {
  TMUF_SURF_SPHERE = 0,
  TMUF_SURF_ELLIPSOID = 1,
  TMUF_SURF_BOX = 6,
  TMUF_SURF_MESH = 7,
};

typedef struct tmuf_plug_surface_geom {
  uint32_t type;
  float bbox[6];
  uint16_t material_id;
  float params[6]; /* sphere radius / ellipsoid radii / box */
  uint32_t vertex_count, triangle_count, cell_count;
  const float *vertices;    /* 3 floats each */
  const uint8_t *triangles; /* 32 bytes each */
  const uint8_t *cells;     /* 32 bytes each */
} tmuf_plug_surface_geom;

typedef struct tmuf_plug_material {
  int has_surface;
  uint32_t surface_flags;
  uint8_t surface_id; /* EPlugSurfaceMaterialId (flags & 0xff) */
  tmuf_gbx_node *custom;
} tmuf_plug_material;

typedef struct tmuf_node_list {
  uint32_t count;
  tmuf_gbx_node **nodes;
} tmuf_node_list;

typedef struct tmuf_block_info {
  const char *name;
  const char *collector_ident[3];
  uint8_t base_words[24]; /* 20 + 4 bytes after the name, uninterpreted */
  tmuf_gbx_node *base_ref;
  tmuf_node_list units[2];       /* ground, air */
  uint32_t variant_count[2];     /* ground, air */
  tmuf_node_list *variants[2];   /* per variant: mobils */
  uint8_t extra[9];              /* 004/005/008 payload tail */
  tmuf_gbx_node *road_ref;
  tmuf_gbx_node *pylon_refs[3];
  const char *clip_id;
  uint32_t base_chunk;
  tmuf_gbx_node *helpers[3]; /* helper mobils: ground, air, common */
  uint32_t way_type; /* 0 start, 1 finish, 2 checkpoint, 3 none, 4 start/finish (0x0304e00a/b/e) */
  int has_way_type;
  int has_spawn;
  float spawn[2][12]; /* spawn locations: ground, air (rotation rows, translation) */
} tmuf_block_info;

typedef struct tmuf_block_unit {
  uint32_t junction_mask, helper;
  uint32_t offset[3];
  tmuf_node_list sources;
  const char *surface;
  uint8_t surface_extra[8];
  uint32_t underground;
  tmuf_gbx_node *replacement;
  const char *junction;
  uint8_t junction_extra[8];
  uint32_t helper_mask;
  int has_helper_mask;
  const char *terrain_modifier;
} tmuf_block_unit;

typedef struct tmuf_hms_item {
  tmuf_gbx_node *solid;
  uint32_t physics_flags, rendering_flags;
  uint16_t visibility;
  int has_state;
} tmuf_hms_item;

typedef struct tmuf_scene_object {
  const char *name;
  tmuf_node_list children;
  int has_item;
  tmuf_hms_item item;
  /* CSceneVehicle / CSceneVehicleCar */
  tmuf_gbx_node *vehicle_tunings, *vehicle_materials, *vehicle_struct;
  int has_physical_params;
  float physical_params[8]; /* 0x0a02b00c: speed cap, reverse speed, water box (center, half) */
} tmuf_scene_object;

/* CSceneVehicleMaterial (0x0a031000) */
typedef struct tmuf_vehicle_material {
  tmuf_gbx_node *fake_bitmap;
  float fake_period_x, fake_period_z;
  float blend[4]; /* x y z w */
  uint32_t natural_id;
  float fake_speed_scale, fake_depth_max;
  float feedback_speed_divisor, feedback_scale;
} tmuf_vehicle_material;

/* Vehicle tuning: chunks kept as raw fields in file order; physics code
   names them by chunk id and field index (see tuning_schema.h). */
typedef struct tmuf_tuning_field {
  char kind; /* R N B O F I */
  uint32_t raw;          /* R N B (float bits for R) */
  tmuf_gbx_node *node;   /* O */
  uint32_t float_count;  /* F */
  const float *floats;   /* F */
  const char *id;        /* I */
} tmuf_tuning_field;

typedef struct tmuf_tuning_chunk {
  uint32_t chunk_id;
  uint32_t field_count;
  tmuf_tuning_field *fields;
} tmuf_tuning_chunk;

typedef struct tmuf_car_tuning {
  const char *name;
  tmuf_gbx_node *base_ref;
  float base_real;
  uint32_t chunk_count, chunk_cap;
  tmuf_tuning_chunk *chunks;
} tmuf_car_tuning;

typedef struct tmuf_vehicle_tunings {
  tmuf_node_list tunings;
  uint32_t selected;
} tmuf_vehicle_tunings;

typedef struct tmuf_func_keys {
  const char *name;
  uint32_t x_count, y_count;
  const float *xs, *ys;
  uint32_t mode;
  float range[2];
  tmuf_gbx_node *skeleton; /* CFuncKeysSkel */
} tmuf_func_keys;

typedef struct tmuf_func_skel {
  uint32_t bone_count;
} tmuf_func_skel;

typedef struct tmuf_vehicle_wheel_def {
  int flags[2];
  const char *name;
} tmuf_vehicle_wheel_def;

typedef struct tmuf_vehicle_struct {
  uint32_t wheel_count;
  tmuf_vehicle_wheel_def *wheels;
  uint32_t visual_vehicle_count;
  int has_visual_vehicle_count;
  tmuf_node_list material_groups, emitters;
  tmuf_gbx_node *feedback_curves[3];
} tmuf_vehicle_struct;

typedef struct tmuf_zone {
  const char *name;
  const char *basic_name;
  uint32_t type;
  uint32_t height, depth;
  int old_zone, has_water;
  tmuf_node_list refs;
  tmuf_gbx_node *block_infos[4]; /* flat: 3 or 4; frontier: 1 */
  const char *frontier_parent, *frontier_child;
} tmuf_zone;

typedef struct tmuf_object_link {
  int is_mobil;
  tmuf_gbx_node *object; /* the linked object, or the mobil's model */
  const char *instance_name;
  tmuf_node_list instance_children;
  float iso[12];
  int active;
  const char *tree_id;
} tmuf_object_link;

typedef struct tmuf_collection {
  const char *name;
  uint32_t zone_tag;
  tmuf_node_list zones;
  tmuf_gbx_node *default_zone;
  float square_size, square_height;
  const char *vehicle[3];
  tmuf_gbx_node *scene_refs[2];
  uint32_t surface_replacement_count;
  float water_surface, water_secondary, water_render_cull;
  int default_water, has_water_heights;
  const char *folders[4]; /* block infos, ?, decorations, menu textures */
  const char *display_name;
} tmuf_collection;

typedef struct tmuf_decoration {
  const char *collector_ident[3];
  tmuf_gbx_node *refs[6]; /* 0x03038011..16: size, audio, mood, ... */
} tmuf_decoration;

/* A mobil created from a model (CSceneMobil::InternalDoMobilPtr). */
typedef struct tmuf_mobil_instance {
  tmuf_gbx_node *model;
  const char *name;
  tmuf_node_list children;
} tmuf_mobil_instance;

typedef struct tmuf_scene_loc {
  tmuf_gbx_node *sector;
  float iso[12]; /* rotation rows, translation */
} tmuf_scene_loc;

typedef struct tmuf_scene3d {
  tmuf_node_list sectors;
  uint32_t mobil_count;
  tmuf_mobil_instance **mobils; /* NULL entries for null pointers */
  uint32_t loc_count;
  tmuf_scene_loc *locs; /* one per mobil */
} tmuf_scene3d;

typedef struct tmuf_decoration_size {
  uint32_t base_height; /* default zone height, in squares */
  uint32_t size[3];
  tmuf_gbx_node *scene; /* CScene3d */
} tmuf_decoration_size;

extern const tmuf_gbx_class *const tmuf_pack_classes[];
extern const size_t tmuf_pack_class_count;

#endif
