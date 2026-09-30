#ifndef TMUF_COMMON_LIGHTMAP_H
#define TMUF_COMMON_LIGHTMAP_H

/* The public tmuf_lightmap of a track: the corpora the game bakes into its
   lightmap atlas (CHmsPackLightMap) and where CHmsPackLightMapAlloc puts
   them. */

#include <tmuf_physics/tmuf_physics.h>

#include "common/scene.h"

typedef struct tmuf_lightmap_data {
  tmuf_lightmap view;
  tmuf_lightmap_corpus *corpora;
  uint32_t *of_scene_corpus; /* scene corpus index -> lightmap corpus, UINT32_MAX */
  uint32_t scene_corpus_count;
} tmuf_lightmap_data;

/* Collects the lightmapped corpora of the scene and places them in an
   atlas of `size` texels. */
int tmuf_lightmap_build(tmuf_lightmap_data *out, tmuf_scene *scene, uint32_t size);
void tmuf_lightmap_free(tmuf_lightmap_data *lm);

#endif
