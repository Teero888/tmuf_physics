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
  /* chunk 0x09005012: cells of the lightmap atlas its corpus takes, in a
     row (CPlugSolid+0x70 bits 1..8); 0 when absent */
  uint8_t lightmap_cells;
} tmuf_plug_solid;

typedef struct tmuf_plug_tree {
  const char *name;
  uint32_t flags; /* decoded CPlugTree::SFlags word */
  int has_iso;
  float iso[12]; /* 3x3 rotation (row-major) then translation */
  uint32_t child_count;
  tmuf_gbx_node **children;
  tmuf_gbx_node *visual, *shader, *material, *surface, *generator;
  /* CPlugTreeVisualMip: its levels are children[mip_first ..], each with the
     distance it applies from */
  uint32_t mip_first, mip_count;
  const float *mip_distances;
  /* all its archived levels, the empty ones included (the game keeps them):
     their far Zs (CPlugTreeVisualMip+0xb4) and, per child above, its level */
  uint32_t mip_levels;
  const float *mip_far_z;
  const uint32_t *mip_level_of;
  tmuf_gbx_node *light; /* CPlugTreeLight: its CPlugLight (chunk 0x09062004) */
  /* set by the scene: a decoration tree its decorator doesn't show at the
     highest quality (CPlugDecoratorTree visible condition) */
  uint8_t decorator_hidden;
} tmuf_plug_tree;

/* CPlugLight (0x0901d000): the GxLight it places and its flags */
typedef struct tmuf_plug_light {
  tmuf_gbx_node *light;     /* +0x24 GxLight */
  tmuf_gbx_node *func;      /* +0x14 */
  tmuf_gbx_node *flare;     /* +0x18 BitmapFlare */
  tmuf_gbx_node *projector; /* +0x1c BitmapProjector */
  uint32_t flags;           /* +0x20: bit 0 NightOnly */
} tmuf_plug_light;

/* GxLight and its subclasses (GxLightPoint, GxLightBall, GxLightSpot), as
   archived; offsets are the fields of the game's GxLight* objects */
typedef struct tmuf_gx_light {
  uint32_t chunks;      /* bit 0: 0x04001009, 1: point, 2: ball, 3: spot (0x0400b002), 4: spot (0x0400b000/1) */
  float rgb[3];         /* +0x18 */
  uint32_t flags;       /* +0x14 */
  float intensity;      /* +0x24 */
  float diffuse;        /* +0x28 DiffuseIntensity */
  float specular;       /* +0x58 SpecularIntensity */
  float specular_power; /* +0x54 */
  float f38;            /* +0x38 */
  float flare_intensity; /* +0x50 FlareIntensity */
  float shadow_rgb[3];
  float point[2];       /* GxLightPoint +0x5c FlareSize, +0x60 FlareBiasZ */
  uint32_t ball_flags;  /* GxLightBall +0x64 */
  float radius[4];      /* +0x68 diffuse, +0x6c specular, +0x70, +0x74 flare */
  float ball[6];        /* +0x80, +0x78, +0x7c, +0x84, +0x88, +0x8c (archive order) */
  uint32_t spot_flags;  /* GxLightSpot +0x90 */
  /* GxLightSpot +0x94 inner angle, +0x98 outer angle (degrees, full), +0x9c
     flare angle, +0xa0, +0xa4, +0xa8 falloff */
  float spot[6];
  /* GxLightAmbient (0x04005000): +0x5c HeightMin, +0x60 HeightMax (bit 5 of chunks) */
  float ambient_height[2];
} tmuf_gx_light;

/* CHmsLight (0x0600c000): the GxLight it places (+0x88), its flag bits
   (+0x8c & 3) and its bitmaps: +0x68 (0x0600c002: "BitmapFlare", the
   ambient light's cube), +0x6c (0x0600c003: "BitmapSprite", the ambient
   light's height gradient), +0x70 (0x0600c001, a kind 4 light's) */
typedef struct tmuf_hms_light {
  uint32_t flags;
  tmuf_gbx_node *light;
  tmuf_gbx_node *bitmaps[3]; /* +0x68, +0x6c, +0x70 */
} tmuf_hms_light;

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
  const uint32_t *tangents, *binormals; /* packed like the normals, NULL if absent */
  uint32_t index_count;
  const uint16_t *indices;
  tmuf_gbx_node *material;
  /* CPlugVisualSprite (0x09010005, 0x09010006) */
  uint32_t sprite_flags;       /* +0xb0 */
  float sprite_axis[3];        /* +0x98 */
  float sprite_offset[2];      /* +0xa4 */
  uint16_t sprite_atlas[2];    /* +0xb4, +0xb6: atlas columns, rows */
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
  tmuf_gbx_node *model; /* material model (device sets of the model) */
  uint32_t device_count;
  uint32_t *device_words;        /* quality | sub-device << 8 | device << 16 */
  tmuf_gbx_node **device_shaders; /* per device set */
} tmuf_plug_material;

/* CPlugMaterialCustom: the bitmaps it substitutes by sampler name */
typedef struct tmuf_plug_material_custom {
  uint32_t bitmap_count;
  const char **bitmap_names;
  tmuf_gbx_node **bitmaps;
} tmuf_plug_material_custom;

/* CPlugShader: archived flag words (+0x1c, +0x20) and, for CPlugShaderApply,
   its bitmap addresses */
typedef struct tmuf_plug_shader {
  int has_flags;
  uint32_t flags[2];
  /* CPlugShaderApply's packed render state (+0x9c, +0xa0): alpha test
     reference in bits 14..21 and function in bits 24..26 of the first */
  int has_apply_state;
  uint32_t apply_state[2];
  uint32_t address_count;
  tmuf_gbx_node **addresses;
  /* chunk 0x0900200e: its passes (CPlugShaderPass, +0x2c) */
  uint32_t pass_count;
  tmuf_gbx_node **passes;
  /* CPlugShaderGeneric's flags +0x8c (the last word of the 0x58-byte
     block of chunks 0x09004001..3): bit 0 ambient lighting, bit 1 ambient
     from the vertex colour, bit 2 diffuse lighting, bit 3 diffuse from
     the vertex colour (SetClassicVertexLighting) */
  int has_generic;
  uint32_t generic_flags;
} tmuf_plug_shader;

/* A GPU program of a CPlugShaderPass (0x0906700a): its file (a
 *.VHlsl.Txt / *.PHlsl.Txt text) and the named constants it loads */
#define TMUF_PASS_MAX_CONSTANTS 16
typedef struct tmuf_plug_gpu_program {
  int enabled;
  tmuf_gbx_node *file;
  uint32_t constant_count;
  const char *constant_names[TMUF_PASS_MAX_CONSTANTS];
  float constants[TMUF_PASS_MAX_CONSTANTS][4];
} tmuf_plug_gpu_program;

typedef struct tmuf_plug_shader_pass {
  tmuf_plug_gpu_program programs[2]; /* vertex, pixel */
} tmuf_plug_shader_pass;

/* CPlugBitmapSampler/Address: sampler name and bitmap */
typedef struct tmuf_plug_bitmap_address {
  const char *sampler;
  tmuf_gbx_node *bitmap;
  int has_address;
  uint32_t address_flags; /* bits 15..19: texcoord set, 31 generated from the position */
  int has_transform;
  float transform[6];
  int has_matrix; /* a GmMat4 texcoord transform (chunk 0x09047007 flag 2) */
  float matrix[16];
} tmuf_plug_bitmap_address;

/* CPlugBitmap: the render it is updated by (pixel update Render), if any */
typedef struct tmuf_plug_bitmap {
  tmuf_gbx_node *image; /* the image file (external) or an inline CPlugFileGen */
  /* 0x0901101c: texcoord scale u v, offset u v, rotation (degrees), which
     addresses using the bitmap's scale apply (ApplyBitmapTcScale) */
  int has_tc_transform;
  float tc_scale[2], tc_offset[2], tc_rotation;
  /* 0x09011024 (and older): flag word; 0x8000: the bitmap sets how its
     coordinates are generated (EGxUVGenerate in bits 16..23) */
  int has_flags;
  uint32_t flags;
  tmuf_gbx_node *render;
  /* the word at +0x4c (chunks 0x09011014..22): usage in the low byte, the
     pixel update mode in the next; bit 21 (0x200000) makes a src-alpha /
     inv-src-alpha blend an alpha test */
  int has_usage;
  uint32_t usage;
} tmuf_plug_bitmap;

/* CPlugBitmapRender subclasses the car's shaders use */
typedef struct tmuf_plug_bitmap_render {
  int has_hemisphere; /* CPlugBitmapRenderHemisphere (0x09058000) */
  uint32_t hemi_layout;
  float exp_l, exp_a; /* +0x5c, +0x60 */
  int has_light_from_map; /* CPlugBitmapRenderLightFromMap (0x09021000) */
  uint32_t lfm_grid, lfm_grid_max; /* +0x80, +0x84 */
  float lfm[8];      /* +0x88, +0x8c, +0x94, +0x98, +0x9c, +0xa0, +0xa4, +0xa8 */
} tmuf_plug_bitmap_render;

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
  int respawn_current; /* 0x0304e00f */
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
  tmuf_gbx_node *motion; /* 0x0a005003: an animated object's CMotion */
  tmuf_node_list children;
  int has_item;
  tmuf_hms_item item;
  int has_light; /* CSceneLight (0x0a00b000) */
  tmuf_hms_light light;
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

/* CSceneVehicleStruct::SVisualId: a tree of the vehicle's solid by name
   (or a joint of a skinned visual) */
typedef struct tmuf_visual_id {
  const char *name;
  int flag; /* the handler keeps its own location instead of the tree's */
} tmuf_visual_id;

/* SVisualWheel: the trees a simulation wheel moves */
typedef struct tmuf_visual_wheel_def {
  tmuf_visual_id rolling;  /* spins, steers and follows the suspension */
  tmuf_visual_id fixed;    /* not moved */
  tmuf_visual_id bouncing; /* follows the suspension */
  tmuf_visual_id steering; /* steers and follows the suspension */
  uint32_t wheel;          /* simulation wheel index */
  int steers;
} tmuf_visual_wheel_def;

/* SVisualArm: a tree stretched between points of two other trees */
typedef struct tmuf_visual_arm_def {
  tmuf_visual_id arm, from, to;
  int flag0;
  int rolls; /* also turns with the wheel's spin and steering (cardans) */
  uint32_t wheel;
} tmuf_visual_arm_def;

typedef struct tmuf_visual_light_def {
  tmuf_visual_id tree;
  uint32_t kind;
} tmuf_visual_light_def;

/* SVisualVehicle: one level of detail of the vehicle's visual */
typedef struct tmuf_visual_vehicle_def {
  uint32_t quality; /* ESceneMobilQuality it is used for */
  tmuf_visual_id body;       /* SVisualVehicle +0xc: the car's body (CSceneVehicleCar tilts it) */
  tmuf_visual_id pilot_head; /* +4: the driver's head (CSceneVehicle turns it) */
  tmuf_visual_id shadow, extra; /* +0x14 (projected shadow frame), +0x1c */
  uint32_t wheel_count, arm_count, light_count;
  tmuf_visual_wheel_def *wheels;
  tmuf_visual_arm_def *arms;
  tmuf_visual_light_def *lights;
} tmuf_visual_vehicle_def;

typedef struct tmuf_vehicle_struct {
  uint32_t wheel_count;
  tmuf_vehicle_wheel_def *wheels;
  uint32_t visual_vehicle_count;
  int has_visual_vehicle_count;
  tmuf_visual_vehicle_def *visual_vehicles;
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
  const char **surface_replacements; /* (source, target) surface id pairs */
  uint32_t terrain_modifier_count;
  tmuf_gbx_node **terrain_modifiers; /* CGameCtnDecorationTerrainModifier */
  float water_surface, water_secondary, water_render_cull;
  int default_water, has_water_heights;
  int has_geometry_water, geometry_water_planes; /* 0x03033022: water from block water planes */
  const char *folders[4]; /* block infos, ?, decorations, menu textures */
  const char *display_name;
  /* 0x03033024: shadows (+0x84 enum, +0x90, +0x8c, +0x88) and vertex
     lighting (+0xac mode, +0xb0 ColorVertexMin, +0xb4 ColorVertexMax) */
  int has_lighting;
  uint32_t shadow_mode, shadow_90, shadow_8c;
  float shadow_88;
  uint32_t vertex_lighting;
  float color_vertex_min, color_vertex_max;
} tmuf_collection;

/* CGameCtnDecorationTerrainModifier (0x0303c000): the skin applied to the
   blocks of a terrain-modified column and where its materials live */
typedef struct tmuf_terrain_modifier {
  tmuf_gbx_node *skin; /* CPlugGameSkin */
  const char *folder;  /* replacement material folder */
  const char *name;    /* e.g. Fabric */
} tmuf_terrain_modifier;

/* CPlugGameSkin (0x03031000) remap rules (chunk 0x03031004) */
typedef struct tmuf_skin_rule {
  uint32_t class_id;  /* class of the replaced node (CPlugMaterial 0x09079000) */
  const char *prefix; /* replacement name */
  int has_target;
  tmuf_gbx_node *target; /* replaced node: a material, or a folder when not loadable */
} tmuf_skin_rule;

typedef struct tmuf_game_skin {
  uint32_t rule_count;
  tmuf_skin_rule *rules;
} tmuf_game_skin;

typedef struct tmuf_decoration {
  const char *collector_ident[3];
  tmuf_gbx_node *refs[6]; /* 0x03038011..16: size, audio, mood, ... */
} tmuf_decoration;

/* A mobil created from a model (CSceneMobil::InternalDoMobilPtr). */
/* CPlugDecoratorTree: per-tree decoration settings; conditions are
   quality masks (0 never, 1 q0, 2 q<=1, 3 q1, 4 q1|q2, 5 q2, 6 always) */
typedef struct tmuf_decorator_tree {
  const char *tree_id; /* target tree name ("" or NULL: the root) */
  uint32_t show, visible, caster, collision;
} tmuf_decorator_tree;

/* CPlugDecoratorSolid (a decoration's .DecoSolid.Gbx) */
typedef struct tmuf_decorator_solid {
  tmuf_node_list trees; /* CPlugDecoratorTree */
} tmuf_decorator_solid;

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
  /* its object buffers (CScene::InternalArchiveSceneObjectBuffer) but
     the mobils: [0] the first when it is not the mobils (old versions),
     then the others (lights, sounds, ...) */
  tmuf_node_list objects[6];
} tmuf_scene3d;

typedef struct tmuf_decoration_size {
  uint32_t base_height; /* default zone height, in squares */
  uint32_t size[3];
  tmuf_gbx_node *scene; /* CScene3d */
} tmuf_decoration_size;

/* ---- the weather (time of day) ---- */

/* CGameCtnDecorationMood (0x0303a000): a decoration's time of day */
typedef struct tmuf_mood {
  /* 0x0303a000 */
  float latitude;                        /* +0x14, degrees */
  float real18, real1c;                  /* +0x18, +0x1c */
  uint32_t time_sun_rise, time_sun_fall; /* +0x20, +0x24, ms of the day */
  /* 0x0303a001 */
  float remapped_start_day_time; /* +0x28 */
  tmuf_gbx_node *light_map;      /* +0x2c */
  const char *folder;            /* +0x30, e.g. "Stadium\\Media\\Moods\\Sunset\\" */
  /* 0x0303a002 */
  uint32_t shadow_count_car_human, shadow_count_car_opponent; /* +0x34, +0x38 */
  float shadow_car_intensity;                                 /* +0x3c */
  int shadow_scene, background_is_locally_lighted;            /* +0x40, +0x44 */
  tmuf_gbx_node *pack_light_map;                              /* 0x0303a004: +0x4c */
  tmuf_gbx_node *ambient_occ;                                 /* 0x0303a005: +0x54 CHmsAmbientOcc */
} tmuf_mood;

/* CHmsAmbientOcc (0x06026000) */
typedef struct tmuf_ambient_occ {
  float radius, power;  /* +0x14, +0x18 */
  uint32_t blur_texels; /* +0x1c */
  float mid_gray[3];    /* +0x20 */
} tmuf_ambient_occ;

/* GxFogGlobal as CFuncWeather archives it (28 bytes) */
typedef struct tmuf_fog_global {
  float rgb[3];
  float start, end, density;
  uint32_t flags;
} tmuf_fog_global;

/* CFuncWeather (0x05034000) */
typedef struct tmuf_func_weather {
  tmuf_gbx_node *sky_materials[4]; /* MaterialSky_Night, _SunRise, _Day, _SunFall */
  tmuf_gbx_node *sea_materials[2];
  float vec_e8[2];
  float spec_intensity[2], spec_power[2]; /* LDirSpecIntens, LDirSpecPower: night, day */
  float reals108[6];
  float vec_f0[2], vec_f8[2], vec_100[2];
  tmuf_fog_global fogs[2]; /* night (+0x30), day (+0x4c) */
  const char *name;        /* +0x14, e.g. "Sunny" */
  tmuf_gbx_node *light_ambient, *light_sun, *light_moon; /* ImageLightAmb, ImageLightDirSun, ImageLightDirMoon */
  tmuf_gbx_node *flare_sun, *flare_moon;
  float flare_size_sun, flare_size_moon;
  float reals_c4[3], real_d0;
  tmuf_gbx_node *nodes_bc[2];
  tmuf_gbx_node *light_double_sided; /* ImageLightDirDblSided */
  tmuf_gbx_node *sky_gradient;       /* BitmapSkyGradV */
  tmuf_gbx_node *fog_color;          /* ImageFogColor */
  tmuf_gbx_node *sea_color;          /* ImageSeaColor */
  tmuf_gbx_node *clouds;             /* CFuncClouds */
  tmuf_gbx_node *fog_blender;        /* GxFogBlender */
} tmuf_func_weather;

/* CFuncClouds (0x0503a000) */
typedef struct tmuf_func_clouds {
  tmuf_node_list solids;                /* +0x24 */
  float real3c, real4c, real50;         /* +0x3c, +0x4c, +0x50 */
  tmuf_gbx_node *color_min, *color_max; /* +0x14, +0x1c: pictures sampled at the day time */
  uint32_t nat54;
  uint32_t key_count;
  float (*keys)[2]; /* +0x40: (distance, value) */
  uint32_t nat30;
  float real34, real38;
} tmuf_func_clouds;

/* CMotionManagerWeathers (0x08053000) */
typedef struct tmuf_motion_weathers {
  tmuf_node_list weathers;     /* +0x64: CFuncWeather */
  tmuf_gbx_node *specular_dir; /* +0x60: BitmapSpecularDir */
} tmuf_motion_weathers;

/* CFuncShaderLayerUV (0x05015000) with CFuncPlug's timing */
typedef struct tmuf_func_layer_uv {
  int has_period;
  float period, phase; /* CFuncPlug +0x20, +0x24 (s) */
  const char *layer;   /* +0x44: the shader layer it drives */
  uint32_t signal;     /* +0x4c low byte: 4 = scale + scrolling translation */
  float vec28[2], vec30[2], vec38[2]; /* signal 4: offset, speed, scale */
} tmuf_func_layer_uv;

extern const tmuf_gbx_class *const tmuf_pack_classes[];
extern const size_t tmuf_pack_class_count;

#endif
