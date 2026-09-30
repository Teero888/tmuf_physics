#ifndef TMUF_PHYSICS_H
#define TMUF_PHYSICS_H

/*
 * tmuf_physics: TrackMania United Forever physics with bit-exact parity to
 * the original game.
 *
 * Usage, in the manner of ddnet_physics:
 *
 *   tmuf_packs *packs = tmuf_packs_open("…/Packs", err, sizeof err);
 *   tmuf_track *track = tmuf_track_load(packs, map, map_size, NULL, err, sizeof err);
 *
 *   tmuf_world world = tmuf_world_empty();
 *   tmuf_world_init(&world, track);
 *   world.input = (tmuf_input){.accelerate = 1};
 *   tmuf_world_tick(&world);           // one 10 ms tick
 *   // world.sim.body.state.pos, world.sim.car.wheels[i], world.sim.race.finish_time, ...
 *
 *   tmuf_world copy = tmuf_world_empty();
 *   tmuf_world_copy(&copy, &world);    // cheap: reuses copy's memory
 *
 *   tmuf_world_free(&copy);
 *   tmuf_world_free(&world);
 *   tmuf_track_free(track);
 *   tmuf_packs_close(packs);
 *
 * Threading: no global mutable state. Packs and tracks are immutable once
 * loaded and can be shared by any number of threads; a world belongs to one
 * thread at a time.
 *
 * Time: a world starts at time 0 on the start block, held for the countdown;
 * each tick advances TMUF_TICK_MS and the race starts on the tick that
 * reaches TMUF_RACE_START_MS. Race time = time - TMUF_RACE_START_MS.
 */

#include <stddef.h>
#include <stdint.h>

#if defined(TMUF_PHYSICS_BUILD_SHARED) && defined(_WIN32)
#define TMUF_API __declspec(dllexport)
#elif defined(TMUF_PHYSICS_USE_SHARED) && defined(_WIN32)
#define TMUF_API __declspec(dllimport)
#elif defined(TMUF_PHYSICS_BUILD_SHARED)
#define TMUF_API __attribute__((visibility("default")))
#else
#define TMUF_API
#endif

#include <tmuf_physics/state.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TMUF_PHYSICS_VERSION_MAJOR 0
#define TMUF_PHYSICS_VERSION_MINOR 3

#define TMUF_TICK_MS 10u
#define TMUF_RACE_START_MS 2600u

typedef enum tmuf_backend {
  TMUF_BACKEND_REFERENCE = 0,
  TMUF_BACKEND_OPTIMIZED = 1,
} tmuf_backend;

TMUF_API const char *tmuf_version_string(void);

/* Backend compiled into this build of the library. */
TMUF_API tmuf_backend tmuf_backend_id(void);

/* Functions that can fail take an optional error buffer (err may be NULL)
   and return NULL or 0 on failure. */

/* ---- packs ---- */

typedef struct tmuf_packs tmuf_packs;

/* dir: the game's Packs directory (with packlist.dat). */
TMUF_API tmuf_packs *tmuf_packs_open(const char *dir, char *err, size_t err_size);
TMUF_API void tmuf_packs_close(tmuf_packs *packs);
/* A file inside the packs (decrypted and decompressed), by its plain path
   such as tmuf_visual_texture.pack_file. Returns its bytes (free them with
   tmuf_free) and their count in *size, or NULL. Thread-safe. */
TMUF_API void *tmuf_packs_read(const tmuf_packs *packs, const char *path, size_t *size);

/* ---- tracks: everything about a map that does not change while driving ---- */

typedef struct tmuf_track tmuf_track;

enum {
  /* keep the world-space triangle list for tmuf_track_triangles (large: every
     static triangle of the map, up to gigabytes on maps with 10k+ blocks) */
  TMUF_TRACK_TRIANGLES = 1u << 0,
  /* score stunts on every map (world.sim.race.stunts); by default only on
     Stunts maps, the only mode that uses the score (the game also records
     it in Race mode ghosts, where nothing checks it) */
  TMUF_TRACK_STUNTS = 1u << 1,
  /* keep what the track draws, as the game's files describe it
     (tmuf_track_visuals): meshes, materials and their texture files, and
     where each mesh is placed */
  TMUF_TRACK_VISUALS = 1u << 2,
};

typedef struct tmuf_track_options {
  const char *vehicle; /* vehicle id; NULL: the map's, else the environment's car */
  uint32_t seed;       /* validation seed (tmuf_replay_seed), 0 for none */
  uint32_t laps;       /* laps to race (tmuf_replay_laps), 0: the map's */
  uint32_t flags;      /* TMUF_TRACK_* */
} tmuf_track_options;

/* map: .Challenge.Gbx bytes (copied). options may be NULL. The packs must
   outlive the track. Takes around a second (decoding the blocks). */
TMUF_API tmuf_track *tmuf_track_load(const tmuf_packs *packs, const void *map, size_t size,
                                     const tmuf_track_options *options, char *err, size_t err_size);
TMUF_API void tmuf_track_free(tmuf_track *track);

TMUF_API const char *tmuf_track_name(const tmuf_track *track);
TMUF_API const char *tmuf_track_environment(const tmuf_track *track); /* collection: Stadium, Alpine, ... */
/* the map's decoration: its size and mood, e.g. "Sunset", "Day", "30x30Sunrise" */
TMUF_API const char *tmuf_track_decoration(const tmuf_track *track);
TMUF_API const char *tmuf_track_vehicle(const tmuf_track *track);     /* the car it runs */
TMUF_API uint32_t tmuf_track_checkpoints(const tmuf_track *track);    /* per lap, without the finish */
TMUF_API uint32_t tmuf_track_laps(const tmuf_track *track);

/* Static triangles in world space: every surface of the map's blocks and
   decoration (also ones the car never touches, e.g. editor helpers). Only
   for tracks loaded with TMUF_TRACK_TRIANGLES, else 0. The collision itself
   is tmuf_track_sim(track)->world (records reference shared surfaces). */
typedef struct tmuf_triangle {
  float v[3][3];
  uint32_t block; /* the map block that placed it, or a tag with the top bit set */
} tmuf_triangle;

TMUF_API uint32_t tmuf_track_triangles(const tmuf_track *track, const tmuf_triangle **triangles);

/* ---- scene data for rendering (TMUF_TRACK_VISUALS) ----
   What the game draws, as plain data read from its files: nothing is
   decoded or interpreted beyond that (image files are named, not read). */

#define TMUF_VISUAL_MAX_UV_SETS 8

enum {
  TMUF_VISUAL_NORMAL = 1u << 0, /* vertices carry a packed normal (u32) after the position */
  TMUF_VISUAL_COLOR = 1u << 1,  /* vertices carry a colour (u32, BGRA) after position and normal */
  /* CPlugVisualSprite (only in tmuf_weather's clouds): each vertex is a
     sprite, 24 bytes: centre (3 floats), size (float), atlas index (u32),
     aspect (float); no indices. The game turns every sprite into a quad
     facing the camera each frame (see tmuf_weather_sky_clouds). */
  TMUF_VISUAL_SPRITES = 1u << 2,
};

/* A CPlugVisual3D indexed triangle list, in its own frame. */
typedef struct tmuf_visual_mesh {
  uint32_t vertex_count;
  uint32_t vertex_stride;  /* bytes from one vertex to the next in `vertices` */
  const uint8_t *vertices; /* each starts with its position, 3 floats */
  uint32_t flags;          /* TMUF_VISUAL_* */
  uint32_t uv_set_count;
  const float *uv_sets[TMUF_VISUAL_MAX_UV_SETS]; /* uv_dims[i] floats per vertex */
  uint8_t uv_dims[TMUF_VISUAL_MAX_UV_SETS];
  uint32_t index_count; /* 3 per triangle */
  const uint16_t *indices;
  float bounds[6]; /* centre, half extents */
  /* the tangent and binormal of each vertex (normal-mapped surfaces), packed
     like the normals; NULL when the mesh has none */
  const uint32_t *tangents, *binormals;
  /* TMUF_VISUAL_SPRITES: CPlugVisualSprite's flags (0x40: vertices name an
     atlas cell; 0x08: size scaled with depth; 0x20: turn about sprite_axis;
     0x10: set on the clouds), its atlas grid (columns, rows) and its
     axis and centre offset */
  uint32_t sprite_flags;
  uint16_t sprite_atlas[2];
  float sprite_axis[3], sprite_offset[2];
} tmuf_visual_mesh;

/* A texture a material's shader samples: the sampler's name (e.g.
   "Diffuse") and its image file (DDS or TGA): on disk under GameData, or
   inside the packs (read it with tmuf_packs_read). Both NULL when the image
   is generated by the game or not found. */
#define TMUF_TEXCOORD_GENERATED 31u

typedef struct tmuf_visual_texture {
  const char *sampler;
  const char *file;      /* path on disk */
  const char *pack_file; /* path inside the packs, when file is NULL */
  /* CPlugBitmapAddress: the mesh's uv set it samples with, or
     TMUF_TEXCOORD_GENERATED for coordinates generated from the vertex
     position; transform: its archived 2x3 texcoord transform (6 floats, as
     stored) when has_transform */
  uint32_t texcoord;
  uint32_t generate; /* EGxUVGenerate: how generated coordinates are made (0: none) */
  int has_transform;
  float transform[6];
  /* a bitmap of the material that no sampler of its shader names: the game's
     shader programs sample it by name (a block's "Lighting": baked light in
     rgb, occlusion in alpha, on the uv set of its "Occlusion"); texcoord,
     generate and transform are then unset */
  int unbound;
  /* CPlugBitmapAddress's 4x4 texcoord matrix (chunk 0x09047007 flag 2, a
     GmMat4 as stored, rows of 4), when has_matrix: the generated
     coordinates are transformed by it (e.g. the Fresnel lookups of the
     PX2 shaders) */
  int has_matrix;
  float matrix[16];
} tmuf_visual_texture;

/* A GPU program of a shader pass: its file (e.g. "Diff X2 2Sided Trans
   PC3.PHlsl.Txt": the family of the material's HLSL) and the constants the
   pass loads into it by name (e.g. SeaTransPC3: BumpScaleUV 0.05,
   RefracPertubPC3 0.1). */
#define TMUF_VISUAL_MAX_CONSTANTS 16

typedef struct tmuf_visual_program {
  const char *file;      /* the file's name as stored, NULL for none */
  const char *pack_file; /* its path inside the packs, NULL when not found */
  uint32_t constant_count;
  const char *constant_names[TMUF_VISUAL_MAX_CONSTANTS];
  float constants[TMUF_VISUAL_MAX_CONSTANTS][4];
} tmuf_visual_program;

typedef struct tmuf_visual_pass {
  tmuf_visual_program vertex, pixel;
} tmuf_visual_pass;

/* The render list a material's surfaces go to (CVisionViewport, by its
   shader's flags) */
enum {
  TMUF_DRAW_OPAQUE = 0,      /* opaque: drawn in the prepass, then the main pass */
  TMUF_DRAW_ALPHA_TEST = 1,  /* alpha tested (draw_flags 0x80): same */
  TMUF_DRAW_BLENDED = 2,     /* alpha blended (draw_flags 0x100): after the opaque ones, sorted, no prepass */
  TMUF_DRAW_SORT_CUSTOM = 3, /* SortCustom (flag 0x40000): its own list by sort_position */
};

/* CPlugShaderApply blend factors (render_state bits 0..4 source, 5..9
   destination): the D3DBLEND the game sets */
enum {
  TMUF_BLEND_ZERO = 0,
  TMUF_BLEND_ONE = 1,
  TMUF_BLEND_SRC_COLOR = 2,
  TMUF_BLEND_INV_SRC_COLOR = 3,
  TMUF_BLEND_SRC_ALPHA = 4,
  TMUF_BLEND_INV_SRC_ALPHA = 5,
  TMUF_BLEND_DST_COLOR = 6,
  TMUF_BLEND_INV_DST_COLOR = 7,
  TMUF_BLEND_DST_ALPHA = 8,
  TMUF_BLEND_INV_DST_ALPHA = 9,
  TMUF_BLEND_SRC_ALPHA_SAT = 10,
};

/* alpha test functions (D3DCMPFUNC) */
enum {
  TMUF_CMP_NEVER = 1,
  TMUF_CMP_LESS = 2,
  TMUF_CMP_EQUAL = 3,
  TMUF_CMP_LESS_EQUAL = 4,
  TMUF_CMP_GREATER = 5,
  TMUF_CMP_NOT_EQUAL = 6,
  TMUF_CMP_GREATER_EQUAL = 7,
  TMUF_CMP_ALWAYS = 8,
};

/* The shader the game draws a surface with (CPlugMaterial's supported
   device set, the material's custom bitmaps substituted). Each device set
   has a day and a night shader: the map's tmuf_weather.is_night (the fid
   parameter IsNight, CPlugMaterial::ApplyFidParameters) picks one when the
   track loads, and everything below describes that one (e.g. the Stadium
   blocks' TOcc shaders become TLight ones at night, which sample the
   "Lighting" map and no PreLightGen). */
typedef struct tmuf_visual_material {
  const char *name;         /* the material's or shader's file, as stored; "" if inline */
  int has_shader_flags;
  uint32_t shader_flags[2]; /* CPlugShader's archived flag words (bit 0x100 of the
                               first: alpha blended) */
  /* CPlugShaderApply's packed render state: alpha test reference in bits
     14..21 and alpha test function in bits 24..26 of the first word
     (function 6: no alpha test) */
  int has_render_state;
  uint32_t render_state[2];
  uint32_t texture_count;
  const tmuf_visual_texture *textures;
  /* the uv set its "PreLightGen" sampler (the lightmap atlas, see
     tmuf_lightmap) reads, UINT32_MAX when it samples none */
  uint32_t lightmap_uv;
  /* the shader's VisibleId word (CPlugShader +0x28): bit 0 VIdReflected,
     1 VIdReflectMirror, 2 VIdRefracted, 3 VIdViewDepBump, 4
     VIdViewDepOcclusion, 5 VIdOnlyRefracted, 6 VIdHideWhenUnderground, 7
     VIdHideWhenOverground, 8 VIdHideAlways, 9 VIdViewDepWindIntens, 10
     VIdBackground, 11 VIdGrassRGB, 12 VIdLightGenP, 13 VIdVehicle, 14
     VIdHideOnlyDirect; 0 when there is no shader */
  uint16_t visible_id;
  /* VIdHideAlways (visible_id bit 8): the game draws nothing with this
     material (CHmsZoneVPacker::AddTree leaves its trees out and their
     textures are never loaded). The shader is Invisible.Shader.Gbx: the
     night-only lamp glows by day (materials on the TAdd Night models,
     whose night shader is TAdd, additive) and the StadiumGrassFence
     terrain modifier materials always */
  int hidden;

  /* ---- how the game draws it ----
     The shader's flags as the game ends up with them at load
     (CPlugShaderApply::ComputeRequireAlphaBlending, for CPlugShaderApply
     and its subclasses; CPlugShaderGeneric keeps the archived ones):
     with op 0 and destination INV_SRC_ALPHA it is blended (0x180) unless
     its alpha texture's bitmap has usage bit 21 (0x200000; not a bump or
     usage 7 bitmap, and not ForceIsAlphaBlend, render_state bit 28), which
     makes it alpha tested (0x80) instead; ONE / ZERO is opaque, alpha
     tested when the apply's alpha test function is not 6 (none); anything
     else is blended. */
  uint32_t shader_class;  /* the shader's class id (0x09004000 CPlugShaderGeneric,
                             0x09026000 CPlugShaderApply, ...), 0 if none */
  uint32_t draw_flags;    /* shader_flags[0] after load: 0x100 blended, 0x80 alpha
                             tested, 0x400 double sided, 0x40000 SortCustom
                             (sort position in bits 26..27), bit 31 Alpha01SoftEdges */
  uint32_t draw_list;     /* TMUF_DRAW_* */
  uint32_t sort_position; /* TMUF_DRAW_SORT_CUSTOM: 0..3 */
  /* in the depth / face normal prepass (and so shadowed by the deferred
     mask and occluded by the SSAO): opaque and alpha tested surfaces and
     SortCustom positions 0 and 1, except shaders with
     ShadowImageSpaceDisable (CVisionViewport's prepass skips them) */
  int prepass;
  /* shader_flags[1] bit 21, ShadowImageSpaceDisable: the shader reads the
     static shadow map itself (one PCF lookup) instead of the deferred
     mask, and has no SSAO (Island's double-sided foliage). The blended
     surfaces, not in the prepass either, do the same in the traces (Bay's
     "Trans" glass) */
  int static_shadow;
  int shadow_caster_disable;   /* shader_flags[1] bit 18: casts no shadow */
  int shadow_depth_bias_extra; /* shader_flags[1] bit 16: pushed 2 m along the light in the caster pass */
  int double_sided;            /* shader_flags[0] bit 10 (0x400): no culling */
  /* the render states CDx9ShaderKeeper::Undirty sets from them:
     - blended: blending (blend_src, blend_dst); alpha test 128 GREATER when
       the alpha texture's bitmap has usage bit 21 (src SRC_ALPHA, dst
       INV_SRC_ALPHA, not forced; the source becomes ONE when the apply has
       no alpha test), else alpha test 0 NOT_EQUAL for sources ZERO /
       SRC_ALPHA and destinations ONE / INV_SRC_ALPHA;
     - not blended: no blending; alpha test GREATER than the viewport's
       reference (128) when the alpha texture's bitmap has usage bit 21
       and the source is SRC_ALPHA;
     - then the apply's own alpha test (render_state bits 14..21 reference,
       24..26 function f: TMUF_CMP f + 2) when f is not 6. */
  int alpha_blend;
  uint32_t blend_src, blend_dst; /* TMUF_BLEND_* */
  uint32_t blend_op;             /* render_state bits 10..12 (0: add) */
  int alpha_test;
  uint32_t alpha_ref;  /* 0..255 */
  uint32_t alpha_func; /* TMUF_CMP_* */
  /* the texture whose alpha it outputs (CPlugShaderApply::
     GetTextureApplyOutputAlpha: the shader's first texture unless its pixel
     program names another), index into textures, UINT32_MAX for none */
  uint32_t alpha_texture;
  uint32_t alpha_texture_usage; /* its bitmap's usage word (+0x4c) */
  /* render_state bit 27, AlphaToCoverage (CPlugShaderApply::OnNodLoaded):
     SRC_ALPHA / INV_SRC_ALPHA, op 0, no BlendFromOpacityMap (bit 22), an
     alpha texture whose bitmap has flag bit 24 (+0x57 bit 0) and whose
     image has 4 bytes per pixel (not checked here). Only used with
     multisampling: then the game turns alpha to coverage on and blending
     off for a surface that is not blended */
  int alpha_to_coverage;
  /* CPlugShaderGeneric's lighting flags (+0x8c): bit 0 ambient, bit 1
     ambient from the vertex colour, bit 2 diffuse, bit 3 diffuse from the
     vertex colour; the prelight bake (tmuf_scenery_prelight) takes the
     cube and gradient only with bit 2 */
  int has_generic_flags;
  uint32_t generic_flags;
  uint32_t pass_count;
  const tmuf_visual_pass *passes;
} tmuf_visual_material;

/* A mesh placed in the world: world = location.r * p + location.t, with
   location.r.m[row][col]. */
typedef struct tmuf_visual_instance {
  uint32_t mesh;     /* index into tmuf_visuals.meshes */
  uint32_t material; /* index into tmuf_visuals.materials, UINT32_MAX for none */
  tmuf_iso4 location;
  uint32_t block;    /* the map block that placed it, or a tag with the top bit set */
  /* level of detail (CPlugTreeVisualMip): the game draws it while the
     camera is between these distances (0 and FLT_MAX when it has no
     levels); the levels of one mip share their placement. A rough
     guide: the game picks the level per frame from the mip's nearest
     depth, see tmuf_visual_mip */
  float lod_near, lod_far;
  /* the corpus that places it in the lightmap atlas: index into
     tmuf_lightmap.corpora, UINT32_MAX when it has none */
  uint32_t lightmap;
  /* the innermost CPlugTreeVisualMip level it is part of: index into
     tmuf_visuals.mips (UINT32_MAX for none: always drawn) and the level
     (0: the most detailed) */
  uint32_t mip, mip_level;
} tmuf_visual_instance;

/* ---- visual mips: the one level the game draws ----

   A CPlugTreeVisualMip holds levels of detail of the same thing, level 0
   the most detailed, each with a far Z. The game draws exactly one level
   of each placed mip per frame (none of the others), chosen from a depth z:

     level = tmuf_visual_mip_level(mip, z)

   (CPlugTreeVisualMip::SetQualityFromMinZ: z is first scaled by
   GeomLodScaleZ, 1 at the highest quality and without automatic LOD; pass
   z * scale otherwise). The mapping is SetDistributionFromFarZs's: with
   n levels and far Zs F[0..n-1] (F[n-1] is never read)

     n <= 1: level 0
     n == 2: level 0 up to F[0] (+ 1e-5), then 1
     n == 3: level 0 up to F[0] (+ 1e-5 of F[1] - F[0]), 1 up to F[1]
             (- 1e-5 of it), then 2
     n >= 4: t = (z - F[0]) / (F[n-2] - F[0]); t < 1e-5: level 0;
             t > 0.99999: n - 1; else bin i = round_even(5 t - 0.5) (about
             floor(5 t)) and level table[i]: the smallest L >= 1 (at most
             n - 1) with F[L] >= F[0] + i (F[n-2] - F[0]) / 5, i.e. the
             level whose range holds the bin's near edge: the levels
             between the first and the last switch only at fifths of the
             range

   in binary32 with the game's operation order (z0, scale, table below).
   z is the mip's nearest depth (view space, along the camera's forward
   axis, positive in front) times f = (top - bottom) / 2 of the frustum at
   unit depth: tan(fov_y / 2) for a centred perspective (the game's
   GmFrustum +0x14 - +0x08 halved; RenderStaticTrees passes the same
   factor), 1 (tree rule) or 0 (packed rule: every mip then at level 0) for
   an orthographic camera. The depth depends on how the mip is drawn
   (rule):

   TMUF_VISUAL_MIP_TREE (CHmsViewport::RenderTree ->
   CPlugTreeVisualMip::RenderBefore; dynamic solids, and mips inside the
   upper levels of a packed mip): the box (GmBoxAligned::SetMult of the
   mip tree's box into view space; here in world, as the game's box is in
   the parent's frame: the same for the blocks' quarter turns) and its
   smallest z:  z = (c.z - h.z) * f.

   TMUF_VISUAL_MIP_PACKED (the static solids' mips, CHmsZoneVPacker): the
   sphere around the box of the objects of the mip's lowest level (the
   level the packer merges into its cells), centre c and radius r in
   world; with the frustum's near plane, depth d(c) of the centre:
     z = ((d(c) - near) - r) * f
   (CHmsZoneVPacker::CellAreAllMipLow, the world plane of the near clip
   plane: -(plane . c + w) - r). The packer also draws every mip of an
   octree cell at its lowest level when the cell's own sphere (the box of
   all its objects) gives z >= the largest F[n-2] of its mips; that early
   out isn't modelled here (its cells come from the zone's loose octree),
   it only differs from the per-mip rule close to the lowest level's
   distance.

   TMUF_VISUAL_MIP_HIDDEN: the game never draws it (a static one-level
   mip, or a mip inside a packed mip's lowest level).

   The viewport's flags force a level for all (0x04 or 0x100: level 0,
   0x80: the lowest); mips nest: a visual is drawn when its mip's chosen
   level is its mip_level, and its mip's parent's chosen level is the
   mip's parent_level, and so on. */
enum {
  TMUF_VISUAL_MIP_TREE = 0,
  TMUF_VISUAL_MIP_PACKED = 1,
  TMUF_VISUAL_MIP_HIDDEN = 2,
};

typedef struct tmuf_visual_mip {
  uint32_t rule;                 /* TMUF_VISUAL_MIP_* */
  uint32_t parent, parent_level; /* the mip level holding it; UINT32_MAX for none */
  float box[6];                  /* TREE: the mip tree's box in world (centre, half extents) */
  float sphere[4];               /* PACKED: centre and radius in world */
  uint32_t level_count;          /* archived levels, empty ones included */
  const float *far_z;            /* level_count far Zs */
  /* SetDistributionFromFarZs: t = (z - z0) * scale, then the table */
  float z0, scale;
  uint32_t table_count;
  uint32_t table[5];
  uint32_t block; /* as tmuf_visual_instance.block */
} tmuf_visual_mip;

typedef struct tmuf_visuals {
  uint32_t mesh_count, material_count, instance_count;
  const tmuf_visual_mesh *meshes;
  const tmuf_visual_material *materials;
  const tmuf_visual_instance *instances;
  uint32_t mip_count; /* the map's (0 for the vehicle and the clouds) */
  const tmuf_visual_mip *mips;
} tmuf_visuals;

/* CPlugTreeVisualMip::SetQualityFromMinZ: the level the game draws at depth
   z (see above), 0 .. level_count - 1 */
TMUF_API uint32_t tmuf_visual_mip_level(const tmuf_visual_mip *mip, float z);

/* The depth the game feeds tmuf_visual_mip_level for a camera: view_z maps
   a world point to its depth along the camera's forward axis (depth =
   view_z[0] x + view_z[1] y + view_z[2] z + view_z[3]), near_z the near
   plane, f as above. By the mip's rule (the level for HIDDEN is
   meaningless). */
TMUF_API float tmuf_visual_mip_z(const tmuf_visual_mip *mip, const float view_z[4], float near_z, float f);

/* NULL unless the track was loaded with TMUF_TRACK_VISUALS. Owned by the
   track. */
TMUF_API const tmuf_visuals *tmuf_track_visuals(const tmuf_track *track);

/* Baked lighting (Stadium): the game draws lightmapped surfaces with a
   texture atlas, "PreLightGen" (GameData/LightmapsCache/.../LightMap0.dds
   for the maps it ships a cache for). Each lightmapped corpus (a placed
   solid whose shaders sample PreLightGen) takes `cells` cells in a row of
   the atlas's grid (CHmsPackLightMapAlloc); its meshes' lightmap uvs span
   [0, cells] x [0, 1] and map into the atlas by

     atlas uv = scale * uv + offset

   (CorpusToLightGenP), in the picture as the game keeps it: flipped at
   load, row 0 at the bottom of the DDS file. In the file's own row order
   sample (atlas.u, 1 - atlas.v). */
typedef struct tmuf_lightmap_corpus {
  uint32_t block; /* as tmuf_visual_instance.block */
  uint32_t cells; /* CPlugSolid chunk 0x09005012; the Warp: 6 * 10 */
  int whole;      /* the decoration's "Warp" mobil: the atlas's reserved first
                     6 columns of its first 10 rows */
  tmuf_iso4 location;
  float tree_box[6]; /* its tree's bounding box (centre, half extents) in its frame */
  float box[6];      /* the same in the world (GmBoxAligned::SetMult): what the
                        atlas is ordered by (z, y, x of the centre, then of the
                        half extents) */
  /* placement: first cell (column, row), UINT32_MAX when it did not fit */
  uint32_t column, row;
  float scale[2], offset[2];
} tmuf_lightmap_corpus;

typedef struct tmuf_lightmap {
  uint32_t size;          /* atlas width and height in texels */
  uint32_t columns, rows; /* its grid */
  uint32_t corpus_count;
  const tmuf_lightmap_corpus *corpora; /* in the order the game adds them */
} tmuf_lightmap;

/* NULL unless the track was loaded with TMUF_TRACK_VISUALS; placed for the
   2048-texel atlas of the shipped caches. Owned by the track. */
TMUF_API const tmuf_lightmap *tmuf_track_lightmap(const tmuf_track *track);

/* Places a copy of a lightmap's corpora (corpora, lightmap->corpus_count of
   them) for an atlas of `size` texels (2048, 4096, 8192: the game's
   lightmap qualities), filling in their column, row, scale and offset and
   out's grid. out->corpora points at `corpora`. */
TMUF_API void tmuf_lightmap_place(const tmuf_lightmap *lightmap, uint32_t size, tmuf_lightmap_corpus *corpora,
                                  tmuf_lightmap *out);

/* ---- the map's lights (TMUF_TRACK_VISUALS) ----

   Every light a placed block or decoration solid carries (a CPlugTreeLight
   node: CPlugLight -> GxLightSpot / GxLightBall / GxLightPoint), as the game
   has it after loading the map: one CHmsLight per tree light. A light file
   of the same name in the mood's folder replaces the one the solid names
   (the fid parameters: e.g. Stadium Sunset's StadiumspotBig). They light
   the cars (vertex lights, HemiSpec highlights) and draw lens flares; the
   lightmaps have them baked in already.

   Which lights reach an object (CHmsZoneVPacker::AddInteractLights): those
   whose flags include the pass's bit and whose sphere's box (position +-
   the pass's radius on each axis) meets the object's world box.
   - The car's vertex lights (vs Light8Spots/Balls, at most 8 of each):
     flag DIFFUSE, radius [0]; spots only when their outer cone reaches the
     car box's bounding sphere (angle to its centre minus asin(its radius /
     distance) <= outer half angle). This picks exactly the 7 spots of the
     A01 trace. Their constants, positions and directions moved into the car
     part's frame:
       Light8*_Rgb_IRad2      = (diffuse_rgb, 1 / radius[0]^2)
       Light8Spots_Pos_ICosR  = (position, 1 / (cos_inner - cos_outer))
       Light8Spots_Dir_CosOt  = (direction, cos_outer)
       Light8Balls_Pos_Rad2   = (position, radius[0]^2)
   - HemiSpec (the car's highlights): flag SPECULAR, radius [1]; quad
     colour specular_rgb * k, k = (1 - d^2 / radius[1]^2) * spot factor
     (^ falloff), d from the car box's centre.
   - Lens flares: flag LENS_FLARE, within radius [3] of the camera. */

enum {
  TMUF_LIGHT_POINT = 0, /* GxLightPoint */
  TMUF_LIGHT_BALL = 1,  /* GxLightBall: omni within a radius */
  TMUF_LIGHT_SPOT = 2,  /* GxLightSpot: a ball limited to a cone */
  TMUF_LIGHT_OTHER = 3, /* another GxLight (frustum, ...): only the GxLight fields are set */
};

/* GxLight flags (+0x14) */
enum {
  TMUF_LIGHT_FLAG_DIFFUSE = 1u << 0,    /* lights (vertex lighting), radius[0] */
  TMUF_LIGHT_FLAG_RADIUS2 = 1u << 2,    /* radius[2] takes part in its box */
  TMUF_LIGHT_FLAG_SPECULAR = 1u << 3,   /* specular highlights (HemiSpec), radius[1] */
  TMUF_LIGHT_FLAG_LENS_FLARE = 1u << 4, /* HasLensFlare */
};

typedef struct tmuf_light {
  uint32_t kind;  /* TMUF_LIGHT_* */
  /* GxLight flags as the game ends up with them: the archived ones
     (CPlugTreeLight::ApplyFidParameters forces none) */
  uint32_t flags;
  uint32_t archived_flags; /* the flags as stored */
  /* CPlugLight flag bit 0 (NightOnly): on a day map the game drops the
     light (ApplyFidParameters releases its GxLight), so the lists
     (tmuf_track_lights, tmuf_vehicle_visuals.lights) leave it out */
  int night_only;
  uint32_t plug_flags;     /* the CPlugLight's flag word */
  /* where it is: world (map lights), or the frame of the part `block`
     (tmuf_vehicle_visuals.lights); a spot shines along the location's +Z */
  tmuf_iso4 location;
  float position[3], direction[3]; /* location.t and its +Z axis (r column 2) */
  float rgb[3];              /* +0x18 */
  float intensity;           /* +0x24 */
  float diffuse_intensity;   /* +0x28 */
  float specular_intensity;  /* +0x58 */
  float specular_power;      /* +0x54 */
  float diffuse_rgb[3];      /* rgb * intensity * diffuse_intensity */
  float specular_rgb[3];     /* rgb * intensity * specular_intensity (GetSpecularRGB) */
  float flare_intensity;     /* +0x50: lens flare target = flare_intensity * intensity */
  float flare_size;          /* GxLightPoint +0x5c: the flare's half size (m) */
  float flare_bias_z;        /* +0x60: occlusion point moved this far toward the camera */
  /* GxLightBall radii: [0] diffuse, [1] specular, [2] (flag RADIUS2), [3]
     lens flare range */
  float radius[4];
  /* GxLightSpot: full cone angles (degrees) and the cosines of their
     halves (UpdateCosHalfAngles); falloff: the HemiSpec cone exponent */
  float angle_inner, angle_outer, angle_flare;
  float cos_inner, cos_outer, cos_flare;
  float falloff;
  /* GxLightBall: flags (+0x64; 0x38: falloff 1 - (d / r)^2, else
     1 / (1 + k1 d + k2 d^2)), attenuation k1 (+0x78), k2 (+0x7c) and its
     ambient colour (+0x84: added unlit by the prelight bake) */
  uint32_t ball_flags;
  float attenuation[2];
  float ambient_rgb[3];
  /* the lens flare picture (CPlugLight BitmapFlare's image; the renderer's
     default flare when both are NULL) */
  const char *flare_file, *flare_pack_file;
  const char *file;  /* the CPlugLight's file (pack path), "" when inline */
  uint32_t block;    /* as tmuf_visual_instance.block; vehicle lights: the part */
  float lod_near, lod_far; /* camera distances of its tree (visual mips) */
  /* under a decoration tree whose decorator doesn't draw it at the highest
     quality (the Stadium's "Low" stands, whose lamps mostly repeat the
     "High" ones'). Information only: the game keeps these lights (at max
     settings the A01 car is lit by the Low tree's StadiumspotBig lamps) */
  int decorator_hidden;
} tmuf_light;

/* The map's lights, NULL/0 unless the track was loaded with
   TMUF_TRACK_VISUALS. Owned by the track. */
TMUF_API uint32_t tmuf_track_lights(const tmuf_track *track, const tmuf_light **lights);

/* CHmsCorpusLight::ComputeBBoxInWorld: the box (centre, half extents, in
   the frame of `location`'s parent) the game files the light under in its
   light octree, for radius `which` (0..3), or, for which >= 4 (what the
   octree uses), the largest radius of its flags (DIFFUSE: [0], SPECULAR:
   [1], RADIUS2: [2]). A ball's box is its sphere's; a spot's the box of its
   outer cone cut at the radius (GmBoxAligned::SetFromConeAndRadius). The
   per-object query itself tests the sphere's box (see above). */
TMUF_API void tmuf_light_box(const tmuf_light *light, uint32_t which, float box[6]);

/* ---- the weather: time of day and the light it gives (TMUF_TRACK_VISUALS) ----

   The map's decoration names a mood (CGameCtnDecorationMood: latitude and
   start time) and its scene the environment's CMotionManagerWeathers, whose
   CFuncWeather holds the pictures the light comes from: each is a ramp over
   the time of day, sampled once (tmuf_picture_sample) at
   (tmuf_day_time.remapped, 0). The mood's skin (CPlugGameSkin) swaps
   pictures and funcs for the files of the same entry name in the mood's
   folder; the files here are the ones the game ends up using.

   Per frame the game's weather (CMotionManagerWeathers::UpdateAsync) sets:
     GbxDayTime            (time, remapped, 0, 1)
     sun or moon           tmuf_day_time_light: direction and which picture
     GbxLightDirRgb0       light_sun (or light_moon) at the time, rgb / 255
     GbxLightDirRgbDblSided0  light_double_sided at the time; the sun picture
                           when there is none
     GbxLightAmbient       light_ambient at the time; w = 1 - (r + g + b) / 3
     GbxCloudsRgbMin/Max   clouds_min / clouds_max at the time
     fog                   tmuf_weather_at; its colour is fog_color's picture
                           at the time when there is one
     light specular        tmuf_weather_at
   The time does not run: the game stops its clock after setting the mood's
   start (CGameCtnDecoration::LoadScene3d). */

/* A file: on disk under GameData (file), or inside the packs (pack_file,
   read with tmuf_packs_read). Both NULL for none. */
typedef struct tmuf_weather_file {
  const char *file;
  const char *pack_file;
} tmuf_weather_file;

/* GxFogGlobal: linear fog on view depth */
typedef struct tmuf_weather_fog {
  float rgb[3];
  float start, end, density;
  uint32_t flags;
} tmuf_weather_fog;

/* CHmsAmbientOcc: the screen-space ambient occlusion's parameters (the
   SSAO's radius and power, its depth-aware blur's texel count and
   GbxAmbientOccMidGray = (mid_gray, 1)) */
typedef struct tmuf_ambient_occlusion {
  /* the mood names a CHmsAmbientOcc (file); else these are the class's
     defaults: 0.024, 3, 15, (0.5, 0.5, 0.5) */
  int from_file;
  tmuf_weather_file file;
  float radius, power;
  uint32_t blur_texels;
  float mid_gray[3];
} tmuf_ambient_occlusion;

/* CGameCtnDecorationMood */
typedef struct tmuf_weather_mood {
  float latitude;                /* degrees: the sun's path (tmuf_day_time) */
  float remapped_start_day_time; /* the start time, as tmuf_day_time_at takes it */
  /* sunrise and sunset (ms of the day) the mood file names; the weather
     does not use them (it keeps 6h and 18h) */
  uint32_t time_sun_rise, time_sun_fall;
  const char *folder; /* e.g. "Stadium\\Media\\Moods\\Sunset\\", its files replace the skin's */
  uint32_t shadow_count_car_human, shadow_count_car_opponent;
  float shadow_car_intensity;
  int shadow_scene, background_is_locally_lighted;
  tmuf_weather_file pack_light_map; /* CHmsPackLightMap settings */
  tmuf_ambient_occlusion ambient_occlusion; /* chunk 0x0303a005 */
} tmuf_weather_mood;

/* An entry of the mood's skin (CPlugGameSkin): the file the environment
   names (default_file) and the one used: the mood folder's
   <name><extension of the default> when it exists, else the default. */
typedef struct tmuf_weather_skin_entry {
  const char *name;  /* e.g. "LightSun", "SkyColor", "Clouds" */
  uint32_t class_id; /* class of the node it replaces */
  tmuf_weather_file default_file, file;
} tmuf_weather_skin_entry;

enum {
  TMUF_DAY_NIGHT = 0,
  TMUF_DAY_SUNRISE = 1,
  TMUF_DAY_DAY = 2,
  TMUF_DAY_SUNSET = 3,
};

/* The time of day, as the game's weather computes it with its roundings. */
typedef struct tmuf_day_time {
  uint32_t ms;        /* the clock: ms of the day (the game's timer) */
  float time;         /* ms / 86400000: GbxDayTime.x */
  float remapped;     /* the day time the pictures are sampled at: GbxDayTime.y;
                         0..0.25 night, ..0.5 sunrise, ..0.75 day, ..1 sunset */
  uint32_t state;     /* TMUF_DAY_* */
  int is_day;         /* state TMUF_DAY_DAY (CMotionDayTime switches on it) */
  float sun_position; /* 0 at sunrise .. 1 at sunset (0 or 1 at night) */
  float night, day;   /* blend weights of the night and day values, day = 1 - night */
  float sun_dir[3];   /* direction the sun's light travels (world) */
  float moon_dir[3];  /* the moon's */
} tmuf_day_time;

/* The 3D clouds in the sky: CFuncClouds' solids, which a CSceneMobilClouds
   lays out in a grid that follows the camera and drifts with the wind
   (tmuf_weather_clouds_place). Each solid is a set of pieces (the child
   trees of its root), placed one by one. */
typedef struct tmuf_weather_cloud_piece {
  uint32_t solid;    /* index of its solid (0 .. solid_count - 1) */
  uint32_t instance; /* its mesh and material: index into sky_clouds.visuals.instances,
                        whose location is the piece's own rotation (no translation) */
  float center[3];   /* its mesh's bounding box centre (the placement's reference point) */
} tmuf_weather_cloud_piece;

typedef struct tmuf_weather_sky_clouds {
  uint32_t solid_count, piece_count; /* 0: no clouds */
  const tmuf_weather_cloud_piece *pieces; /* by solid, in tree order */
  tmuf_visuals visuals;                   /* the pieces' meshes and materials */
  /* CSceneMobilClouds (its defaults: the game sets none of them) */
  float grid_size[2]; /* GridSizeXZ: one grid cell per instance */
  float wind_speed;   /* units per second: CFuncClouds' speed * WindSpeed */
  float wind_dir;     /* WindDir (radians): the clouds move along (-sin, 0, -cos) */
  int view_dependent; /* IsViewDep: the grid wraps around the camera */
  /* CFuncClouds: the pieces' height over the horizontal distance from the
     camera, or from center (x, z) when has_center: from (0, height0)
     through keys (distance, height) to (camera far, height_far),
     extrapolated linearly past the last point */
  int has_center;
  float center[2];
  float height0, height_far;
  uint32_t key_count;
  const float (*keys)[2];
} tmuf_weather_sky_clouds;

typedef struct tmuf_weather {
  tmuf_weather_mood mood;
  const char *manager; /* the CMotionManagerWeathers file (pack path) */
  const char *name;    /* the CFuncWeather's name, e.g. "Sunny" */
  tmuf_weather_fog fogs[2];                /* night, day */
  float spec_intensity[2], spec_power[2]; /* LDirSpecIntens / LDirSpecPower: night, day */
  /* pictures (ramps over the day time, see above) */
  tmuf_weather_file light_ambient, light_sun, light_moon, light_double_sided;
  tmuf_weather_file fog_color, sea_color, sky_gradient;
  tmuf_weather_file flare_sun, flare_moon;
  float flare_size_sun, flare_size_moon; /* angular sizes */
  tmuf_weather_file sky_materials[4];    /* MaterialSky_Night, _SunRise, _Day, _SunFall */
  tmuf_weather_file sea_materials[2];
  /* CFuncClouds: its file (none when inline) and its colours GbxCloudsRgbMin/Max */
  tmuf_weather_file clouds, clouds_min, clouds_max;
  /* the clouds map (the skin's "Clouds" CFuncShaderLayerUV): world position
     p -> uv, with ph = frac(seconds / clouds_period):
       u = clouds_scale[0] * (-p.y + p.z) / sqrt 2      + clouds_offset[0] + ph * clouds_speed[0]
       v = clouds_scale[1] * (2 p.x + p.y - p.z) / sqrt 6 + clouds_offset[1] + ph * clouds_speed[1]
     (EGxUVGenerate Hack1Vertex, then the layer's transform) */
  int has_clouds_layer;
  tmuf_weather_file clouds_layer;
  float clouds_scale[2], clouds_speed[2], clouds_offset[2], clouds_period;
  uint32_t skin_entry_count;
  const tmuf_weather_skin_entry *skin_entries;
  tmuf_day_time start; /* the mood's start time: the one the game shows */
  /* the fid parameter IsNight (CGameCtnDecoration::Init): !(0.25 <
     remapped_start_day_time < 0.75); Stadium's Sunset (0.75) is night. It
     switches the cars' lights on and the maps' night-only lights, and
     picks each material's night shader (tmuf_visual_material) */
  int is_night;
  /* the sun has a lens flare (flare_sun, half angle flare_size_sun): the
     day state is not night and there is a flare picture; the moon never
     has one (CMotionManagerWeathers::UpdateAsync) */
  int sun_flare;
  tmuf_weather_sky_clouds sky_clouds; /* the 3D clouds (CFuncClouds' solids) */
} tmuf_weather;

/* NULL unless the track was loaded with TMUF_TRACK_VISUALS (or its weather
   was not found). Owned by the track. */
TMUF_API const tmuf_weather *tmuf_track_weather(const tmuf_track *track);

/* The time of day of a remapped start time (tmuf_weather_mood's), at a
   latitude: CMotionManagerWeathers::JumpToTimeRemapped then UpdateAsync. */
TMUF_API void tmuf_day_time_at(float remapped_start_day_time, float latitude, tmuf_day_time *out);

/* The fog (colour: the night and day colours blended) and the light's
   specular intensity and power at a time of day. Any output may be NULL. */
TMUF_API void tmuf_weather_at(const tmuf_weather *weather, const tmuf_day_time *time, tmuf_weather_fog *fog,
                              float *spec_intensity, float *spec_power);

/* The directional light: the moon's when its colour (moon picture at the
   time) is at least as bright as the sun's (|rgb|^2), else the sun's.
   Writes its direction to dir (may be NULL); returns 1 for the moon. */
TMUF_API int tmuf_day_time_light(const tmuf_day_time *time, const uint8_t sun_rgb[3], const uint8_t moon_rgb[3],
                                 float dir[3]);

/* CPlugFileImg::FilterWrappedPixel: the colour of a picture at (u, v), as
   the weather samples its ramps: bilinear between texel centres, wrapping
   (at v = 0 the first and last rows mix half and half), each channel
   truncated to a byte. pixels: height rows of width pixels of pixel_bytes
   bytes, in the order the game keeps them (TGA rows as stored in the file,
   whatever its origin bit; DDS flipped). out gets pixel_bytes bytes, in the
   pixels' channel order. */
TMUF_API void tmuf_picture_sample(const uint8_t *pixels, uint32_t width, uint32_t height, uint32_t pixel_bytes,
                                  float u, float v, uint8_t *out);

/* A cloud piece placed for a frame: mesh -> world. */
typedef struct tmuf_cloud_draw {
  uint32_t piece; /* index into sky_clouds.pieces */
  tmuf_iso4 location;
} tmuf_cloud_draw;

/* The clouds where the game draws them for a camera at eye with its far
   distance (the race camera: 50000) at a time of its clock, in ms
   (CSceneMobilClouds::BuildInstances and OnRenderBefore): a grid of
   instances enough to span 2 * far, solids assigned in turn, every other
   instance turned a quarter; each piece moved by the wind, wrapped into the
   grid around the camera and lifted to its height. Writes up to cap draws
   to out (in the game's order: instance by instance, pieces in turn) and
   returns how many there are. The game draws them back to front (distance
   from the eye to the piece's bounding box centre). */
/* A cloud sprite as the game draws it (CLoadGeomDynaSprite::LoadSprite,
   each frame): a quad facing the camera. right and up: the camera's axes
   in the piece mesh's frame (unit vectors). Corners 0..3: bottom left,
   bottom right, top left, top right, half a size up and down and half a
   size times the sprite's aspect left and right; uv the sprite's atlas
   cell, (u0, v0) at the bottom left (v as the game keeps the picture:
   DDS rows flipped at load). Draw both triangles (0, 1, 2), (2, 1, 3)
   without culling. */
TMUF_API void tmuf_cloud_sprite_quad(const tmuf_visual_mesh *mesh, uint32_t sprite, const float right[3],
                                    const float up[3], float corners[4][3], float uv[4][2]);

TMUF_API uint32_t tmuf_weather_clouds_place(const tmuf_weather *weather, const float eye[3], float far_distance,
                                           uint32_t time_ms, tmuf_cloud_draw *out, uint32_t cap);

/* ---- scenery lighting of the vertex-lit environments (TMUF_TRACK_VISUALS) ----

   Island, Coast, Bay, Alpine (Snow), Rally and Speed (Desert) light their
   static scenery by vertex colours the game computes once at load
   (CHmsZoneVPacker, the collection's VertexLighting 1); Stadium bakes
   lightmaps instead (VertexLighting 2, tmuf_lightmap). At the highest
   shader level each prelit vertex carries two colours:
     COLOR1  the mesh's own vertex colour
     COLOR0  the bake: tmuf_scenery_prelight (ambient cube and height
             gradient, plus the lamps; the sun is not baked)
   and the vertex shader (DGbxGenCodePC3_PrelightCV) makes of them
     ModCV = sat(prelight_scale * COLOR1.rgb + prelight_trans)
     C0    = ModCV * COLOR0.a * COLOR0.rgb                 (in shadow)
     C1    = ModCV * COLOR0.a * sat(COLOR0.rgb + sun * max(0, N . -L))   (lit)
   (the double-sided foliage adds GbxLightDirRgbDblSided0 instead of the
   N . L term). */

/* CGameCtnCollection +0x84 (GetShadowEnable): which blocks cast */
enum {
  TMUF_SHADOW_RECEIVE = 0,
  TMUF_SHADOW_ALL_BUT_LANDSCAPE = 1,
  TMUF_SHADOW_ALL_BUT_WATER_OR_UNDERGROUND = 2,
  TMUF_SHADOW_CAST_AND_RECEIVE = 3,
};

typedef struct tmuf_scenery_light {
  /* the map's collection (chunk 0x03033024) */
  uint32_t vertex_lighting;                 /* 0 none, 1 prelit vertices, 2 lightmaps */
  float color_vertex_min, color_vertex_max; /* +0xb0, +0xb4 */
  /* GbxPrelight_ScaleTrans: (max - min, min), each clamped to [0, 1] */
  float prelight_scale, prelight_trans;
  uint32_t shadow_mode; /* +0x84, TMUF_SHADOW_* */
  /* the chunk's other fields, as stored: +0x88 (1.0 in the game's files),
     +0x8c, +0x90 (0 Island/Coast/Bay, 1 Alpine/Rally/Speed, 2 Stadium) */
  float shadow_88;
  uint32_t shadow_8c, shadow_90;

  /* the decoration scene's ambient light (a CSceneLight's CHmsLight whose
     GxLight is a GxLightAmbient): what the bake starts from */
  int has_ambient;
  float ambient_rgb[3];         /* GxLight rgb */
  float ambient_intensity;      /* GxLight intensity */
  uint32_t ambient_flags;       /* GxLight flags */
  float height_min, height_max; /* GxLightAmbient: the gradient spans these world heights */
  /* its bitmaps' images: the cube (DefaultAmbientCube.dds) and the height
     gradient (DefaultAmbientGrad.dds), or the files the mood's skin swaps
     them for ("AmbCube", "AmbGrad": e.g. Island\Media\Moods\Day\
     AmbCube.dds, a 64^2 cube); none for none */
  tmuf_weather_file ambient_cube, ambient_gradient;
  /* their pixels as the bake reads them (RGB, 3 bytes each; NULL when not
     read: only uncompressed 24 and 32 bit DDS are): the cube's 6 faces
     (+X, -X, +Y, -Y, +Z, -Z) of cube_size^2 texels at mip 0, rows as in the
     file (the game does not flip cube maps); the gradient's row 0 as the
     game keeps the picture (DDS flipped at load: the file's last row) */
  uint32_t cube_size;
  const uint8_t *cube_pixels;
  uint32_t gradient_width;
  const uint8_t *gradient_row;

  /* the world box (centre, half extents) of the zone's static packed
     objects, the map's blocks and terrain (the placed meshes' boxes,
     GmBoxAligned::SetMult), without the decoration: the static shadow
     map's box (CHmsShadowGroup, Shadow_CreateVolumes) */
  float static_box[6];
} tmuf_scenery_light;

/* NULL unless the track was loaded with TMUF_TRACK_VISUALS. Owned by the
   track. */
TMUF_API const tmuf_scenery_light *tmuf_track_scenery_light(const tmuf_track *track);

/* COLOR0 of a scenery vertex (CHmsZoneVPacker::PrecalcLighting): its world
   position and world normal (the mesh normal turned by the placement, not
   renormalised), the shader's generic_flags (tmuf_visual_material):
     bit 2 set:  c = cube(n) * 2 * gradient(t), t = (y - height_min) /
                 (height_max - height_min); cube point sampled at mip 0
                 with D3D's face selection, gradient point sampled at
                 x = trunc(clamp(t, 0, 0.9999) * width) (no cube: 1; no
                 gradient: 0.5)
     bit 2 clear, or neither picture: c = ambient_rgb * ambient_intensity
   then the lamps (lights, light_count: e.g. tmuf_track_lights; those with
   the DIFFUSE flag, balls and spots, count), within radius[0]:
     att = ball_flags & 0x38 ? 1 - (d / r)^2 : 1 / (1 + k1 d + k2 d^2)
     ball, intensity >= 0: c += att * intensity * ambient_rgb + f * diffuse_rgb
     ball, intensity < 0:  a *= sat(1 - att sat(1 - ambient_rgb.r)) sat(1 - f sat(1 - rgb.r))
     spot: att times 0 outside the outer cone, ((cos - cos_outer) /
           (cos_inner - cos_outer))^falloff inside it (1 inside the inner
           one); c += f * diffuse_rgb when att > 1e-4
   with f = att * max(0, n . l) when bit 2 is set, else att. Writes
   trunc(255 sat(c)) and trunc(255 sat(a)) as B, G, R, A (the game's
   D3DCOLOR). */
TMUF_API void tmuf_scenery_prelight(const tmuf_scenery_light *scenery, uint32_t generic_flags, const float position[3], const float normal[3],
                                    const tmuf_light *lights, uint32_t light_count, uint8_t bgra[4]);

/* COLOR0 of every vertex of a placed mesh (tmuf_visual_instance: its
   material's generic_flags; the track's lights but the NightOnly ones on a
   day map, whose light the game drops: CPlugTreeLight::
   ApplyFidParameters' global DAT_00d16c08 is 1 and never written), as
   tmuf_scenery_prelight;
   bgra gets 4 bytes per mesh vertex. Returns the vertex count, 0 when the
   track has no scenery light or the mesh has no normals. */
TMUF_API uint32_t tmuf_track_prelight_instance(const tmuf_track *track, uint32_t instance, uint8_t *bgra);

/* The car as the game draws it: the trees of the vehicle's solid (parts)
   and the rig CSceneVehicleStruct lays over them, one level per visual
   quality. The game shows the parts of one level (the player's car: the
   level of the highest quality) and moves them from the car's state each
   frame: wheels spin, steer and follow the suspension, arms stretch
   between the parts they join, the body pitches with a turbo and the
   pilot's head sways with the feedback springs. */

#define TMUF_VEHICLE_NO_PART UINT32_MAX

typedef struct tmuf_vehicle_part {
  const char *name;   /* the tree's name, e.g. "1FLWheel" */
  uint32_t parent;    /* index of the parent part, TMUF_VEHICLE_NO_PART for the root */
  tmuf_iso4 location; /* in the parent's frame (the root's in the car's) */
} tmuf_vehicle_part;

/* CSceneVehicleStruct::SVisualWheel: the parts a simulation wheel moves */
typedef struct tmuf_vehicle_visual_wheel {
  uint32_t rolling;  /* spins with the wheel, steers (steers set) and follows the suspension */
  uint32_t fixed;    /* not moved */
  uint32_t bouncing; /* follows the suspension */
  uint32_t steering; /* steers (steers set) and follows the suspension */
  uint32_t wheel;    /* index into sim.car.wheels */
  int steers;
} tmuf_vehicle_visual_wheel;

/* SVisualArm: a part aimed from `from` at `to` and stretched to reach it;
   rolls: also turns with the wheel (cardans) */
typedef struct tmuf_vehicle_visual_arm {
  uint32_t arm, from, to;
  int rolls;
  uint32_t wheel;
} tmuf_vehicle_visual_arm;

typedef struct tmuf_vehicle_visual_light {
  uint32_t part;
  uint32_t kind;
} tmuf_vehicle_visual_light;

/* SVisualVehicle: one level of detail */
typedef struct tmuf_vehicle_visual_level {
  uint32_t quality;   /* ESceneMobilQuality it is shown at (higher: more detail) */
  uint32_t root;      /* the group of the level's parts */
  uint32_t body;      /* pitched by the turbo */
  uint32_t pilot_head;
  uint32_t shadow;    /* frame of the projected shadow */
  uint32_t wheel_count, arm_count, light_count;
  const tmuf_vehicle_visual_wheel *wheels;
  const tmuf_vehicle_visual_arm *arms;
  const tmuf_vehicle_visual_light *lights;
} tmuf_vehicle_visual_level;

/* What the car's shaders sample besides its textures, rendered by the game
   each frame (car_light_spec): the HemiSpec sphere map of the lights'
   highlights and the LightFromMap view of the lightmapped ground under the
   car. Values as the car's bitmaps archive them (CPlugBitmapRenderHemisphere,
   CPlugBitmapRenderLightFromMap), the game's defaults where they don't. */
typedef struct tmuf_vehicle_lighting {
  /* the car's box (CPlugTree::UpdateBoundingBox of the vehicle solid's tree:
     centre, half extents) in the car's frame; HemiSpec's reference point is
     its centre, LightFromMap's view is built on it */
  float box[6];
  int has_hemisphere;
  /* HemiSpec: each light adds colour * pow(d, exp_l) to rgb and
     k * pow(d, exp_a) to alpha */
  float hemi_exp_l, hemi_exp_a;
  uint32_t hemi_layout;
  int has_light_from_map;
  /* LightFromMap's atlas: grid cells per side to start with, at most
     (doubled while cells^2 < cars) */
  uint32_t lfm_grid, lfm_grid_max;
  /* its camera (ComputeCamera_DovObjectY): orthographic, from the car's
     origin down its -Y, over box x/z centre +- footprint * box half extents
     (footprint = 1 + 1.5 / 2), depth d (= -y in the car's frame) from
     -cy - hy + 2 hy * lfm_top to -cy + hy + lfm_depth; the lightmap fades
     to white as sat((d - (hy - cy + lfm_white * lfm_depth)) /
     ((1 - lfm_white) * lfm_depth)) */
  float lfm_footprint;
  float lfm_top;   /* +0x88 */
  float lfm_depth; /* +0x8c */
  float lfm_white; /* +0x90 (not archived: 0.5) */
  /* as archived: +0x94, +0x98 (a min, max range: the shaders'
     LightFromMap_ScaleRGB_TransRGB (1, -0) on Stadium comes from this (0, 1)
     one), +0x9c, +0xa0, +0xa4, +0xa8 (two more ranges the game turns into
     scale/translation pairs when the zone has no lightmap) */
  float lfm_values[6];
  float lfm_up_min; /* +0xac (not archived: 0.8): a second, world-down view
                       when the car's up vector's y is below it */
} tmuf_vehicle_lighting;

typedef struct tmuf_vehicle_visuals {
  /* instances: location in the frame of the part `block` */
  tmuf_visuals visuals;
  uint32_t part_count, level_count;
  const tmuf_vehicle_part *parts; /* parents before their children */
  const tmuf_vehicle_visual_level *levels;
  /* the lights its trees carry (CPlugTreeLight parts, e.g. StadiumCar's
     1RRLight): location in the frame of the part `block` (the light's own
     tree: its iso is the part's location). The game sets their intensity
     each frame (CSceneVehicle::VisualUpdateAsync): IsNight ? 0.5 + 0.5 brake
     : 0.5 brake, brake = brake input > 0.3 */
  uint32_t light_count;
  const tmuf_light *lights;
  tmuf_vehicle_lighting lighting;
} tmuf_vehicle_visuals;

/* NULL unless the track was loaded with TMUF_TRACK_VISUALS. Owned by the
   track. */
TMUF_API const tmuf_vehicle_visuals *tmuf_track_vehicle_visuals(const tmuf_track *track);

/* The track's simulation at time 0, which every world starts as a copy of:
   its static collision (world, triggers), water, race tables and the car's
   definition are the ones all worlds on the track share. */
TMUF_API const tmuf_sim *tmuf_track_sim(const tmuf_track *track);

/* ---- worlds: one car driving a track ---- */

/* One tick of input, as the game reads it. */
typedef struct tmuf_input {
  uint8_t accelerate; /* 0 or 1 */
  uint8_t brake;      /* 0 or 1 */
  uint8_t respawn;    /* 1: respawn at the last checkpoint */
  uint8_t input_event; /* 1: a driving key or axis event this tick that left the input as it was
                          (e.g. a second steering key held); a stunt in the air is only a master
                          jump without input events, and a change of the fields above is one */
  int32_t steer;      /* -65536 (full left) .. 65536 (full right); keys steer +-65536 */
} tmuf_input;

typedef struct tmuf_world {
  const tmuf_track *track;
  uint32_t tick;    /* ticks simulated: the time is tick * TMUF_TICK_MS */
  tmuf_input input; /* used by the next tmuf_world_tick */
  tmuf_sim sim;     /* the simulation itself (tmuf_physics/state.h): sim.body is the
                       car's rigid body, sim.car the car, sim.race the race,
                       sim.world and sim.triggers the track's static collision */
} tmuf_world;

TMUF_API tmuf_world tmuf_world_empty(void);
/* The car at time 0 on the track's start. world must be empty or freed. */
TMUF_API int tmuf_world_init(tmuf_world *world, const tmuf_track *track);
/* to becomes an exact copy of from. Cheap when to already holds a world on
   the same track (its memory is reused); to may also be empty. A world holds
   pointers into itself: copy it with this, never by assignment. */
TMUF_API int tmuf_world_copy(tmuf_world *to, const tmuf_world *from);
/* One tick with world->input. */
TMUF_API void tmuf_world_tick(tmuf_world *world);
TMUF_API void tmuf_world_free(tmuf_world *world);

/* ---- replays ---- */

typedef struct tmuf_replay tmuf_replay;

/* Copies what it needs; data may be freed afterwards. */
TMUF_API tmuf_replay *tmuf_replay_load(const void *data, size_t size, char *err, size_t err_size);
TMUF_API void tmuf_replay_free(tmuf_replay *replay);

/* The embedded map (.Challenge.Gbx bytes, owned by the replay). */
TMUF_API const void *tmuf_replay_map(const tmuf_replay *replay, size_t *size);
TMUF_API const char *tmuf_replay_vehicle(const tmuf_replay *replay); /* "" if none */
/* The skin the player's car wears: its pack's path as the game stores it
   (e.g. "Skins\\Vehicles\\StadiumCar\\FRA.zip", relative to GameData or the
   player's documents), "" if none */
TMUF_API const char *tmuf_replay_skin(const tmuf_replay *replay);
/* Laps of the race settings the replay was driven with (0: none; pass it
   as tmuf_track_options.laps: validation races that many laps). */
TMUF_API uint32_t tmuf_replay_laps(const tmuf_replay *replay);
/* Seed that turns the spawn by a tiny yaw in validation runs (0: none). */
TMUF_API uint32_t tmuf_replay_seed(const tmuf_replay *replay);
/* Recorded race time in ms, UINT32_MAX if the ghost did not finish. */
TMUF_API uint32_t tmuf_replay_race_time(const tmuf_replay *replay);
/* The ghost's recorded respawns and stunt score (UINT32_MAX if not recorded). */
TMUF_API uint32_t tmuf_replay_respawns(const tmuf_replay *replay);
TMUF_API uint32_t tmuf_replay_stunt_score(const tmuf_replay *replay);
/* The ghost's recorded checkpoint crossings (finish lines included): race
   time and stunt score at each (arrays owned by the replay). Returns the
   count, 0 if not recorded. */
TMUF_API uint32_t tmuf_replay_checkpoints(const tmuf_replay *replay, const uint32_t **times, const uint32_t **scores);
/* The ghost's input for every tick from time 0: inputs[i] drives tick i.
   Returns the count; the array is owned by the replay. */
TMUF_API uint32_t tmuf_replay_inputs(const tmuf_replay *replay, const tmuf_input **inputs);

/* ---- writing replays ---- */

typedef struct tmuf_replay_write_options {
  const char *login;    /* the ghost's player login; NULL: "tmuf_physics" */
  const char *nickname; /* NULL: the login */
} tmuf_replay_write_options;

/* A .Replay.Gbx of the run inputs[0..count) drive on track (inputs[i] drives
   tick i, as tmuf_replay_inputs gives them), which the game plays and its
   validator accepts. The run is simulated: it ends at the finish or after
   the last input, and the replay records the map, the inputs, the race time
   (none if the run does not finish), respawns, stunt score, checkpoint times
   and the car's samples. The track's seed and laps (tmuf_track_options) are the
   run's validation seed and race settings.
   A replay has no input before the race starts: inputs[i] for
   i < TMUF_RACE_START_MS / TMUF_TICK_MS - 1 are ignored (the car is held
   during the countdown; the run starts with the input of that tick), so
   count must be larger. options may be NULL.
   On Stunts maps the validator also checks the stunt score, which the
   replay records as the run scored it (on other maps 0, unless the track
   was loaded with TMUF_TRACK_STUNTS).
   Returns the file's bytes (free them with tmuf_free) and their count in
   *size, or NULL. */
TMUF_API void *tmuf_replay_write(const tmuf_track *track, const tmuf_input *inputs, uint32_t count,
                                 const tmuf_replay_write_options *options, size_t *size, char *err,
                                 size_t err_size);
/* Frees memory the library returned (tmuf_replay_write). */
TMUF_API void tmuf_free(void *p);

/* A file of a zip archive (the game's skins and lightmap caches), by its
   name inside it (case-insensitive): its bytes (free them with tmuf_free), or
   NULL when it is not there or cannot be read. */
TMUF_API void *tmuf_zip_extract(const void *zip, size_t size, const char *name, size_t *out_size);

#ifdef __cplusplus
}
#endif

#endif /* TMUF_PHYSICS_H */
