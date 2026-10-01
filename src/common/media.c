#include "common/media.h"

#include <string.h>

#include "common/replay.h"

#define MAX_COUNT 0x10000u /* per list: arrays are allocated before their items are read */
#define COUNT(a) (sizeof(a) / sizeof((a)[0]))

/* Every media block (and CControlEffectSimi) reads into this: its time range
   (GetTimeStart / GetTimeEnd: its start and end, or its first and last key)
   and, for the camera blocks, the camera. */
typedef struct media_block {
  float start, end;
  int is_camera;
  tmuf_clip_camera camera;
} media_block;

typedef struct media_track {
  int keep_playing; /* +0x28, CacheUpdate copies it onto the last block */
  uint32_t block_count;
  const tmuf_gbx_node **blocks;
} media_track;

typedef struct media_clip {
  uint32_t track_count;
  const tmuf_gbx_node **tracks;
} media_clip;

typedef uint32_t media_cell[3];

/* SGameCtnMediaTriggerZone */
typedef struct media_trigger {
  uint32_t condition;
  float value;
  uint32_t cell_count;
  media_cell *cells;
} media_trigger;

typedef struct media_group {
  uint32_t clip_count, trigger_count;
  const tmuf_gbx_node **clips;
  media_trigger *triggers;
} media_group;

static uint32_t count(tmuf_gbx *g, const char *what) {
  const uint32_t n = tmuf_gbx_u32(g);
  if (!g->error && n > MAX_COUNT)
    tmuf_gbx_fail(g, "%s count %u", what, n);
  return g->error ? 0 : n;
}

/* CFastBuffer::ArchiveFastBufferNodRef: buffer version 10, a count, the
   node references */
static const tmuf_gbx_node **node_list(tmuf_gbx *g, uint32_t *n, const char *what) {
  *n = 0;
  if (tmuf_gbx_u32(g) != 10 && !g->error)
    tmuf_gbx_fail(g, "%s list version", what);
  const uint32_t k = count(g, what);
  const tmuf_gbx_node **nodes = TMUF_ARENA_ARRAY(g->arena, const tmuf_gbx_node *, k ? k : 1);
  if (!nodes) {
    tmuf_gbx_fail(g, "out of memory");
    return NULL;
  }
  for (uint32_t i = 0; i < k && !g->error; i++)
    nodes[i] = tmuf_gbx_noderef(g);
  *n = g->error ? 0 : k;
  return nodes;
}

/* CSystemPackDesc */
static void pack_desc(tmuf_gbx *g) {
  const uint8_t version = tmuf_gbx_u8(g);
  if (version >= 3)
    tmuf_gbx_skip(g, 32);
  const char *path = tmuf_gbx_string(g);
  if ((path[0] && version >= 1) || version >= 3)
    tmuf_gbx_string(g);
}

/* CFastBufferKey: a count, keys of `size` bytes, each the time first */
static void keys(tmuf_gbx *g, media_block *b, size_t size) {
  const uint32_t n = count(g, "key");
  for (uint32_t i = 0; i < n && !g->error; i++) {
    const float t = tmuf_gbx_f32(g);
    tmuf_gbx_skip(g, size - 4);
    if (i == 0)
      b->start = t;
    b->end = t;
  }
}

static void start_end(tmuf_gbx *g, media_block *b) {
  b->start = tmuf_gbx_f32(g);
  b->end = tmuf_gbx_f32(g);
}

#define KEYS(name, size)                                                                                               \
  static void name(tmuf_gbx *g, void *node, uint32_t id) {                                                            \
    (void)id;                                                                                                          \
    keys(g, node, (size));                                                                                             \
  }
#define SKIP(name, n)                                                                                                  \
  static void name(tmuf_gbx *g, void *node, uint32_t id) {                                                            \
    (void)node;                                                                                                        \
    (void)id;                                                                                                          \
    tmuf_gbx_skip(g, (n));                                                                                             \
  }

static void c_start_end(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  start_end(g, node);
}

SKIP(skip4, 4)
SKIP(skip8, 8)
SKIP(skip12, 12)
SKIP(skip20, 20)

/* ---- CControlEffectSimi (0x07010000), the motion of a Text or Image ---- */

/* keys: time, position (2), rotation, scale (2); version 1+ opacity, 2+
   depth, 3+ four reals. Then centered; 0x004 a color blend mode and
   continuous, 0x005 and interpolated. */
static void c07010001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  keys(g, node, 28);
  tmuf_gbx_skip(g, 4);
}

static void c07010002(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  keys(g, node, 32);
  tmuf_gbx_skip(g, 4);
}

static void c07010004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  keys(g, node, 48);
  tmuf_gbx_skip(g, 12);
}

static void c07010005(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  keys(g, node, 48);
  tmuf_gbx_skip(g, 16);
}

static const tmuf_gbx_chunk EFFECT_SIMI_CHUNKS[] = {
    {0x07010001, 0, c07010001},
    {0x07010002, 0, c07010002},
    {0x07010004, 0, c07010004},
    {0x07010005, 0, c07010005},
};
static const tmuf_gbx_class EFFECT_SIMI = {
    0x07010000, "CControlEffectSimi", sizeof(media_block), EFFECT_SIMI_CHUNKS, COUNT(EFFECT_SIMI_CHUNKS), NULL,
};

/* an effect's keys give its block's time range */
static void effect(tmuf_gbx *g, media_block *b) {
  const tmuf_gbx_node *n = tmuf_gbx_noderef(g);
  if (g->error || !n)
    return;
  if (n->cls != &EFFECT_SIMI) {
    tmuf_gbx_fail(g, "media effect of class %08x", n->class_id);
    return;
  }
  const media_block *e = n->data;
  b->start = e->start;
  b->end = e->end;
}

/* ---- the media blocks ---- */

/* CGameCtnMediaBlockCameraGame (0x03084000) */

/* 0x000 / 0x001: the camera as an index into the player's camera set (an
   old block: CGameCtnMediaClipPlayer::CompatConvertOldCameraBlocks takes the
   id of that camera, camera 0 if there is none); 0x001 with the entity */
static void camera_game_old(tmuf_gbx *g, media_block *b, int with_entity) {
  start_end(g, b);
  const uint32_t index = tmuf_gbx_u32(g);
  if (with_entity)
    b->camera.entity = (int32_t)tmuf_gbx_u32(g);
  b->is_camera = 1;
  b->camera.kind = TMUF_CLIP_CAMERA_GAME;
  b->camera.cam_index = (int32_t)index;
  /* the ids every vehicle's set has at these indices (Race3 / CameraRally
     "Close", the shared "Internal" camera) */
  b->camera.id = index == 1 ? "Close" : index == 2 ? "Internal" : "";
}

static void c03084000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  camera_game_old(g, node, 0);
}

static void c03084001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  camera_game_old(g, node, 1);
}

static void c03084003(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  media_block *b = node;
  start_end(g, b);
  const char *s = tmuf_gbx_id(g, NULL);
  b->camera.entity = (int32_t)tmuf_gbx_u32(g);
  b->is_camera = 1;
  b->camera.kind = TMUF_CLIP_CAMERA_GAME;
  b->camera.cam_index = -1;
  b->camera.id = s ? s : ""; /* numeric ids name no camera */
}

static const tmuf_gbx_chunk CAMERA_GAME_CHUNKS[] = {
    {0x03084000, 0, c03084000},
    {0x03084001, 0, c03084001},
    {0x03084003, 0, c03084003},
};
static const tmuf_gbx_class CAMERA_GAME = {
    0x03084000, "CGameCtnMediaBlockCameraGame", sizeof(media_block), CAMERA_GAME_CHUNKS, COUNT(CAMERA_GAME_CHUNKS),
    NULL,
};

/* CGameCtnMediaBlockCameraCustom (0x030a2000): the keys of chunk 0x000 +
   version (SKeyVal::Archive): time, interpolation, two naturals, position,
   pitch yaw roll, fov, anchor rotation, anchor (version 4: an id), anchor
   visible, target (version 4: an id), target position; version 1: two
   reals, 2+: the left and right tangents, 3: and a real and a quaternion */
static void camera_custom(tmuf_gbx *g, media_block *b, uint32_t version) {
  const uint32_t n = count(g, "key");
  tmuf_clip_custom_key *k = TMUF_ARENA_ARRAY(g->arena, tmuf_clip_custom_key, n ? n : 1);
  if (!k) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    tmuf_clip_custom_key *o = &k[i];
    o->time = tmuf_gbx_f32(g);
    o->interp = tmuf_gbx_u32(g);
    tmuf_gbx_skip(g, 8);
    for (int j = 0; j < 3; j++)
      o->pos[j] = tmuf_gbx_f32(g);
    o->pitch = tmuf_gbx_f32(g);
    o->yaw = tmuf_gbx_f32(g);
    o->roll = tmuf_gbx_f32(g);
    o->fov = tmuf_gbx_f32(g);
    o->anchor_rot = tmuf_gbx_u32(g);
    if (version == 4) {
      /* an id: any names the local player's entity */
      const char *s = tmuf_gbx_id(g, NULL);
      o->anchor = s && !s[0] ? -1 : 0;
    } else {
      o->anchor = (int32_t)tmuf_gbx_u32(g);
    }
    o->anchor_vis = tmuf_gbx_u32(g);
    if (version == 4) {
      const char *s = tmuf_gbx_id(g, NULL);
      o->target = s && !s[0] ? -1 : 0;
    } else {
      o->target = (int32_t)tmuf_gbx_u32(g);
    }
    for (int j = 0; j < 3; j++)
      o->target_pos[j] = tmuf_gbx_f32(g);
    if (version == 1)
      tmuf_gbx_skip(g, 8);
    else if (version > 1) {
      for (int j = 0; j < 3; j++)
        o->left_tangent[j] = tmuf_gbx_f32(g);
      for (int j = 0; j < 3; j++)
        o->right_tangent[j] = tmuf_gbx_f32(g);
    }
    if (version == 3)
      tmuf_gbx_skip(g, 20);
  }
  if (g->error)
    return;
  b->is_camera = 1;
  b->camera.kind = TMUF_CLIP_CAMERA_CUSTOM;
  b->camera.cam_index = -1;
  b->camera.id = "";
  b->camera.entity = -1;
  b->camera.key_count = n;
  b->camera.keys = k;
  b->start = n ? k[0].time : 0.0f;
  b->end = n ? k[n - 1].time : 0.0f;
}

static void c030a200x(tmuf_gbx *g, void *node, uint32_t id) {
  camera_custom(g, node, id & 0xfffu);
}

static void c030a2003(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  camera_custom(g, node, 3);
  tmuf_gbx_skip(g, 4);
}

static const tmuf_gbx_chunk CAMERA_CUSTOM_CHUNKS[] = {
    {0x030a2000, 0, c030a200x}, {0x030a2001, 0, c030a200x}, {0x030a2002, 0, c030a200x},
    {0x030a2003, 0, c030a2003}, {0x030a2004, 0, c030a200x}, {0x030a2005, 0, c030a200x},
};
static const tmuf_gbx_class CAMERA_CUSTOM = {
    0x030a2000, "CGameCtnMediaBlockCameraCustom", sizeof(media_block), CAMERA_CUSTOM_CHUNKS,
    COUNT(CAMERA_CUSTOM_CHUNKS), NULL,
};

/* CGameCtnMediaBlockCameraPath (0x030a1000): key time, position, pitch yaw
   roll, fov, anchor rotation, anchor, anchor visible, target, target
   position, weight, a quaternion */
KEYS(c030a100x, 80)
static const tmuf_gbx_chunk CAMERA_PATH_CHUNKS[] = {
    {0x030a1000, 0, c030a100x},
    {0x030a1001, 0, c030a100x},
    {0x030a1002, 0, c030a100x},
};
static const tmuf_gbx_class CAMERA_PATH = {
    0x030a1000, "CGameCtnMediaBlockCameraPath", sizeof(media_block), CAMERA_PATH_CHUNKS, COUNT(CAMERA_PATH_CHUNKS),
    NULL,
};

/* CGameCtnMediaBlockCameraOrbital (0x030a0000): key time, a byte, radius,
   longitude, latitude, target position, fov, min and max render distance */
KEYS(c030a0000, 41)
static const tmuf_gbx_chunk CAMERA_ORBITAL_CHUNKS[] = {{0x030a0000, 0, c030a0000}};
static const tmuf_gbx_class CAMERA_ORBITAL = {
    0x030a0000, "CGameCtnMediaBlockCameraOrbital", sizeof(media_block), CAMERA_ORBITAL_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockCameraEffectShake (0x030a4000): key time, intensity,
   speed */
KEYS(c030a4000, 12)
static const tmuf_gbx_chunk SHAKE_CHUNKS[] = {{0x030a4000, 0, c030a4000}};
static const tmuf_gbx_class SHAKE = {
    0x030a4000, "CGameCtnMediaBlockCameraEffectShake", sizeof(media_block), SHAKE_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockFxColors (0x03080000): key time, intensity, blend z,
   distance, far distance, then near and far: inverse, hue, saturation,
   brightness, contrast, rgb, four reals */
KEYS(c0308000x, 116)
static const tmuf_gbx_chunk FX_COLORS_CHUNKS[] = {
    {0x03080000, 0, c0308000x},
    {0x03080001, 0, c0308000x},
    {0x03080002, 0, c0308000x},
    {0x03080003, 0, c0308000x},
};
static const tmuf_gbx_class FX_COLORS = {
    0x03080000, "CGameCtnMediaBlockFxColors", sizeof(media_block), FX_COLORS_CHUNKS, COUNT(FX_COLORS_CHUNKS), NULL,
};

/* CGameCtnMediaBlockFxBlurDepth (0x03081000): key time, lens size, force
   focus, focus z */
KEYS(c03081001, 16)
static const tmuf_gbx_chunk FX_BLUR_DEPTH_CHUNKS[] = {{0x03081001, 0, c03081001}};
static const tmuf_gbx_class FX_BLUR_DEPTH = {
    0x03081000, "CGameCtnMediaBlockFxBlurDepth", sizeof(media_block), FX_BLUR_DEPTH_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockFxBlurMotion (0x03082000) */
static const tmuf_gbx_chunk FX_BLUR_MOTION_CHUNKS[] = {{0x03082000, 0, c_start_end}};
static const tmuf_gbx_class FX_BLUR_MOTION = {
    0x03082000, "CGameCtnMediaBlockFxBlurMotion", sizeof(media_block), FX_BLUR_MOTION_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockFxBloom (0x03083000): key time, intensity, sensitivity */
KEYS(c03083001, 12)
static const tmuf_gbx_chunk FX_BLOOM_CHUNKS[] = {{0x03083001, 0, c03083001}};
static const tmuf_gbx_class FX_BLOOM = {
    0x03083000, "CGameCtnMediaBlockFxBloom", sizeof(media_block), FX_BLOOM_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockTime (0x03085000): key time, time value, tangent */
KEYS(c03085000, 12)
static const tmuf_gbx_chunk TIME_CHUNKS[] = {{0x03085000, 0, c03085000}};
static const tmuf_gbx_class TIME = {0x03085000, "CGameCtnMediaBlockTime", sizeof(media_block), TIME_CHUNKS, 1, NULL};

/* CGameCtnMediaBlockImage (0x030a5000): its effect and image */
static void c030a5000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  effect(g, node);
  pack_desc(g);
}

static const tmuf_gbx_chunk IMAGE_CHUNKS[] = {{0x030a5000, 0, c030a5000}, {0x030a5001, 0, skip4}};
static const tmuf_gbx_class IMAGE = {
    0x030a5000, "CGameCtnMediaBlockImage", sizeof(media_block), IMAGE_CHUNKS, COUNT(IMAGE_CHUNKS), NULL,
};

/* CGameCtnMediaBlockMusicEffect (0x030a6000): key time, music volume;
   0x001 and sound volume */
KEYS(c030a6000, 8)
KEYS(c030a6001, 12)
static const tmuf_gbx_chunk MUSIC_EFFECT_CHUNKS[] = {{0x030a6000, 0, c030a6000}, {0x030a6001, 0, c030a6001}};
static const tmuf_gbx_class MUSIC_EFFECT = {
    0x030a6000, "CGameCtnMediaBlockMusicEffect", sizeof(media_block), MUSIC_EFFECT_CHUNKS, COUNT(MUSIC_EFFECT_CHUNKS),
    NULL,
};

/* CGameCtnMediaBlockSound (0x030a7000): key time, volume, pan; version 1+
   a position */
static void c030a7001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  pack_desc(g);
  keys(g, node, 12);
}

static void c030a7003(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  const uint32_t version = tmuf_gbx_u32(g);
  tmuf_gbx_skip(g, 12); /* play count, looping, music */
  if (version >= 1)
    tmuf_gbx_skip(g, 4); /* stop with the clip */
  if (version >= 2)
    tmuf_gbx_skip(g, 8);
}

static void c030a7004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  pack_desc(g);
  const uint32_t version = tmuf_gbx_u32(g);
  keys(g, node, version >= 1 ? 24 : 12);
}

static const tmuf_gbx_chunk SOUND_CHUNKS[] = {
    {0x030a7001, 0, c030a7001},
    {0x030a7002, 0, skip8},
    {0x030a7003, 0, c030a7003},
    {0x030a7004, 0, c030a7004},
};
static const tmuf_gbx_class SOUND = {
    0x030a7000, "CGameCtnMediaBlockSound", sizeof(media_block), SOUND_CHUNKS, COUNT(SOUND_CHUNKS), NULL,
};

/* CGameCtnMediaBlockText (0x030a8000): its text and effect, color */
static void c030a8001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  tmuf_gbx_string(g);
  effect(g, node);
}

static const tmuf_gbx_chunk TEXT_CHUNKS[] = {
    {0x030a8001, 0, c030a8001},
    {0x030a8002, 0, skip12},
    {0x030a8003, 0, skip4},
};
static const tmuf_gbx_class TEXT = {
    0x030a8000, "CGameCtnMediaBlockText", sizeof(media_block), TEXT_CHUNKS, COUNT(TEXT_CHUNKS), NULL,
};

/* CGameCtnMediaBlockTrails (0x030a9000) */
static const tmuf_gbx_chunk TRAILS_CHUNKS[] = {{0x030a9000, 0, c_start_end}};
static const tmuf_gbx_class TRAILS = {
    0x030a9000, "CGameCtnMediaBlockTrails", sizeof(media_block), TRAILS_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockTransitionFade (0x030ab000): key time, opacity; color,
   a real */
static void c030ab000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  keys(g, node, 8);
  tmuf_gbx_skip(g, 16);
}

static const tmuf_gbx_chunk FADE_CHUNKS[] = {{0x030ab000, 0, c030ab000}};
static const tmuf_gbx_class FADE = {
    0x030ab000, "CGameCtnMediaBlockTransitionFade", sizeof(media_block), FADE_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlock3dStereo (0x03024000): key time, up to max, screen
   distance */
KEYS(c03024000, 12)
static const tmuf_gbx_chunk STEREO_CHUNKS[] = {{0x03024000, 0, c03024000}};
static const tmuf_gbx_class STEREO = {
    0x03024000, "CGameCtnMediaBlock3dStereo", sizeof(media_block), STEREO_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockTriangles (0x03029000, read for Triangles2D / 3D): key
   times, per key the vertex positions, the vertices (rgba), the triangles,
   six naturals */
static void c03029001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  media_block *b = node;
  keys(g, b, 4);
  const uint32_t key_count = count(g, "triangle key");
  const uint32_t vertex_count = count(g, "triangle vertex");
  tmuf_gbx_skip(g, (size_t)key_count * vertex_count * 12u);
  tmuf_gbx_skip(g, (size_t)count(g, "triangle vertex") * 16u);
  tmuf_gbx_skip(g, (size_t)count(g, "triangle") * 12u);
  tmuf_gbx_skip(g, 28);
}

static const tmuf_gbx_chunk TRIANGLES_CHUNKS[] = {{0x03029001, 0, c03029001}};
static const tmuf_gbx_class TRIANGLES = {
    0x03029000, "CGameCtnMediaBlockTriangles", sizeof(media_block), TRIANGLES_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockGhost (0x030e5000): start, end, the ghost, its start
   offset */
static void c030e5001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  start_end(g, node);
  tmuf_gbx_noderef(g);
  tmuf_gbx_skip(g, 4);
}

static const tmuf_gbx_chunk GHOST_CHUNKS[] = {{0x030e5001, 0, c030e5001}};
static const tmuf_gbx_class GHOST = {
    0x030e5000, "CGameCtnMediaBlockGhost", sizeof(media_block), GHOST_CHUNKS, 1, NULL,
};

/* CGameCtnMediaBlockUi (0x0307d000), and CCtnMediaBlockUiTMSimpleEvtsDisplay
   (0x24092000): its display flags */
static const tmuf_gbx_chunk UI_CHUNKS[] = {{0x0307d001, 0, c_start_end}};
static const tmuf_gbx_class UI = {0x0307d000, "CGameCtnMediaBlockUi", sizeof(media_block), UI_CHUNKS, 1, NULL};

static const tmuf_gbx_chunk UI_TM_CHUNKS[] = {
    {0x24092000, 0, skip4},
    {0x24092001, 0, skip20},
    {0x24092002, 0, skip4},
};
static const tmuf_gbx_class UI_TM = {
    0x24092000, "CCtnMediaBlockUiTMSimpleEvtsDisplay", sizeof(media_block), UI_TM_CHUNKS, COUNT(UI_TM_CHUNKS), &UI,
};

/* CCtnMediaBlockEventTrackMania (0x2407f000): start, end, a bool, the
   stunts (time, figure, angle, score, factor, straight, three bools, combo,
   total score) */
static void c2407f000(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  start_end(g, node);
  tmuf_gbx_skip(g, 4);
  tmuf_gbx_skip(g, (size_t)count(g, "stunt") * 44u);
}

static const tmuf_gbx_chunk EVENT_TM_CHUNKS[] = {{0x2407f000, 0, c2407f000}};
static const tmuf_gbx_class EVENT_TM = {
    0x2407f000, "CCtnMediaBlockEventTrackMania", sizeof(media_block), EVENT_TM_CHUNKS, 1, NULL,
};

static const tmuf_gbx_class *const BLOCKS[] = {
    &CAMERA_GAME, &CAMERA_CUSTOM, &CAMERA_PATH, &CAMERA_ORBITAL, &SHAKE, &FX_COLORS, &FX_BLUR_DEPTH, &FX_BLUR_MOTION,
    &FX_BLOOM, &TIME, &IMAGE, &MUSIC_EFFECT, &SOUND, &TEXT, &TRAILS, &FADE, &STEREO, &TRIANGLES, &GHOST, &UI, &UI_TM,
    &EVENT_TM,
};

static int is_block(const tmuf_gbx_node *n) {
  for (size_t i = 0; n && n->data && i < COUNT(BLOCKS); i++)
    if (n->cls == BLOCKS[i])
      return 1;
  return 0;
}

/* ---- CGameCtnMediaTrack (0x03078000) ---- */

static void c03078001(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  media_track *t = node;
  tmuf_gbx_string(g);
  t->blocks = node_list(g, &t->block_count, "media block");
  tmuf_gbx_u32(g);
}

static void c03078002(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  ((media_track *)node)->keep_playing = tmuf_gbx_bool(g);
}

static void c03078004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)id;
  ((media_track *)node)->keep_playing = tmuf_gbx_bool(g);
  tmuf_gbx_u32(g); /* read only */
}

static const tmuf_gbx_chunk TRACK_CHUNKS[] = {
    {0x03078001, 0, c03078001},
    {0x03078002, 0, c03078002},
    {0x03078003, 0, skip4},
    {0x03078004, 0, c03078004},
};
static const tmuf_gbx_class TRACK = {
    0x03078000, "CGameCtnMediaTrack", sizeof(media_track), TRACK_CHUNKS, COUNT(TRACK_CHUNKS), NULL,
};

/* ---- CGameCtnMediaClip (0x03079000) ---- */

/* 0x002 / 0x003 / 0x005: the tracks and the name; 0x002 and a bool */
static void c03079003(tmuf_gbx *g, void *node, uint32_t id) {
  media_clip *c = node;
  c->tracks = node_list(g, &c->track_count, "media track");
  tmuf_gbx_string(g);
  if ((id & 0xfffu) == 2)
    tmuf_gbx_u32(g);
}

/* the scene (none in maps) */
static void c03079004(tmuf_gbx *g, void *node, uint32_t id) {
  (void)node;
  (void)id;
  if (tmuf_gbx_noderef(g) && !g->error)
    tmuf_gbx_fail(g, "media clip with a scene");
}

static const tmuf_gbx_chunk CLIP_CHUNKS[] = {
    {0x03079002, 0, c03079003}, {0x03079003, 0, c03079003}, {0x03079004, 0, c03079004},
    {0x03079005, 0, c03079003}, {0x03079007, 0, skip4},
};
static const tmuf_gbx_class CLIP = {
    0x03079000, "CGameCtnMediaClip", sizeof(media_clip), CLIP_CHUNKS, COUNT(CLIP_CHUNKS), NULL,
};

/* ---- CGameCtnMediaClipGroup (0x0307a000) ---- */

static void cells(tmuf_gbx *g, media_trigger *t) {
  t->cell_count = count(g, "trigger cell");
  t->cells = TMUF_ARENA_ARRAY(g->arena, media_cell, t->cell_count ? t->cell_count : 1);
  if (!t->cells) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < t->cell_count && !g->error; i++)
    for (int j = 0; j < 3; j++)
      t->cells[i][j] = tmuf_gbx_u32(g);
}

/* the clips, then the triggers: 0x000 one cell each, 0x001 cells, 0x002
   cells and the editor reference (cell, direction), 0x003
   (SGameCtnMediaTriggerZone::Archive) the reference, condition, its value,
   cells */
static void c0307a00x(tmuf_gbx *g, void *node, uint32_t id) {
  media_group *gr = node;
  const uint32_t version = id & 0xfffu;
  gr->clips = node_list(g, &gr->clip_count, "media clip");
  const uint32_t n = count(g, "trigger");
  gr->triggers = TMUF_ARENA_ARRAY(g->arena, media_trigger, n ? n : 1);
  if (!gr->triggers) {
    tmuf_gbx_fail(g, "out of memory");
    return;
  }
  for (uint32_t i = 0; i < n && !g->error; i++) {
    media_trigger *t = &gr->triggers[i];
    if (version == 0) {
      t->cell_count = 1;
      t->cells = TMUF_ARENA_ARRAY(g->arena, media_cell, 1);
      if (!t->cells) {
        tmuf_gbx_fail(g, "out of memory");
        return;
      }
      for (int j = 0; j < 3; j++)
        t->cells[0][j] = tmuf_gbx_u32(g);
      continue;
    }
    if (version == 3) {
      tmuf_gbx_skip(g, 16);
      t->condition = tmuf_gbx_u32(g);
      t->value = tmuf_gbx_f32(g);
    }
    cells(g, t);
    if (version == 2)
      tmuf_gbx_skip(g, 16);
  }
  gr->trigger_count = g->error ? 0 : n;
}

static const tmuf_gbx_chunk GROUP_CHUNKS[] = {
    {0x0307a000, 0, c0307a00x},
    {0x0307a001, 0, c0307a00x},
    {0x0307a002, 0, c0307a00x},
    {0x0307a003, 0, c0307a00x},
};
static const tmuf_gbx_class GROUP = {
    0x0307a000, "CGameCtnMediaClipGroup", sizeof(media_group), GROUP_CHUNKS, COUNT(GROUP_CHUNKS), NULL,
};

/* the clip classes, the blocks', their effects' and ghosts' */
const tmuf_gbx_class *const TMUF_MEDIA_CLASSES[] = {
    &GROUP, &CLIP, &TRACK, &CAMERA_GAME, &CAMERA_CUSTOM, &CAMERA_PATH, &CAMERA_ORBITAL, &SHAKE, &FX_COLORS,
    &FX_BLUR_DEPTH, &FX_BLUR_MOTION, &FX_BLOOM, &TIME, &IMAGE, &MUSIC_EFFECT, &SOUND, &TEXT, &TRAILS, &FADE, &STEREO,
    &TRIANGLES, &GHOST, &UI, &UI_TM, &EVENT_TM, &EFFECT_SIMI, &TMUF_CTN_GHOST,
};
const size_t TMUF_MEDIA_CLASS_COUNT = COUNT(TMUF_MEDIA_CLASSES);

/* ---- the in-game clips ---- */

int tmuf_media_ingame_clips(const tmuf_gbx_node *group, tmuf_arena *arena, const tmuf_ingame_clip **clips,
                            uint32_t *count_out) {
  *clips = NULL;
  *count_out = 0;
  if (!group || group->cls != &GROUP || !group->data)
    return 0;
  const media_group *gr = group->data;
  tmuf_ingame_clip *out = TMUF_ARENA_ARRAY(arena, tmuf_ingame_clip, gr->clip_count ? gr->clip_count : 1);
  if (!out)
    return 0;
  for (uint32_t i = 0; i < gr->clip_count; i++) {
    tmuf_ingame_clip *o = &out[i];
    if (i < gr->trigger_count) {
      const media_trigger *t = &gr->triggers[i];
      o->cell_count = t->cell_count;
      o->cells = (const uint32_t(*)[3])t->cells;
      o->condition = t->condition;
      o->condition_value = t->value;
    }
    const tmuf_gbx_node *cn = gr->clips[i];
    if (!cn)
      continue;
    if (cn->cls != &CLIP || !cn->data)
      return 0;
    const media_clip *c = cn->data;
    uint32_t cameras = 0;
    for (uint32_t j = 0; j < c->track_count; j++) {
      const tmuf_gbx_node *tn = c->tracks[j];
      if (!tn || tn->cls != &TRACK || !tn->data)
        return 0;
      const media_track *t = tn->data;
      for (uint32_t k = 0; k < t->block_count; k++) {
        if (!is_block(t->blocks[k]))
          return 0;
        cameras += ((const media_block *)t->blocks[k]->data)->is_camera ? 1u : 0u;
      }
      /* KeepPlayingGet: any track; GetMediaBlockEndMax: each track's last
         block's end */
      o->keep_playing |= t->keep_playing;
      if (t->block_count) {
        const float end = ((const media_block *)t->blocks[t->block_count - 1]->data)->end;
        if (end > o->end)
          o->end = end;
      }
    }
    tmuf_clip_camera *cam = TMUF_ARENA_ARRAY(arena, tmuf_clip_camera, cameras ? cameras : 1);
    if (!cam)
      return 0;
    for (uint32_t j = 0; j < c->track_count; j++) {
      const media_track *t = c->tracks[j]->data;
      for (uint32_t k = 0; k < t->block_count; k++) {
        const media_block *b = t->blocks[k]->data;
        if (!b->is_camera)
          continue;
        *cam = b->camera;
        cam->start = b->start;
        cam->end = b->end;
        cam->keep = t->keep_playing && k == t->block_count - 1;
        cam++;
        o->camera_count++;
      }
    }
    o->cameras = cam - o->camera_count;
  }
  *clips = out;
  *count_out = gr->clip_count;
  return 1;
}
