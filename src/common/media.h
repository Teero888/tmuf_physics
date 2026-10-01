#ifndef TMUF_COMMON_MEDIA_H
#define TMUF_COMMON_MEDIA_H

/* MediaTracker (CGameCtnMediaClipGroup, CGameCtnMediaClip,
   CGameCtnMediaTrack and the media blocks), as maps store it: every block
   class TMUF writes is read through, the camera blocks are kept. */

#include <stdint.h>

#include <tmuf_physics/tmuf_physics.h>

#include "common/arena.h"
#include "common/gbx.h"

/* the classes a challenge's clips are made of (for the reader's class list) */
extern const tmuf_gbx_class *const TMUF_MEDIA_CLASSES[];
extern const size_t TMUF_MEDIA_CLASS_COUNT;

/* A CGameCtnMediaClipGroup node's clips with their triggers, in the
   arena. 0 if the node is not a clip group. */
int tmuf_media_ingame_clips(const tmuf_gbx_node *group, tmuf_arena *arena, const tmuf_ingame_clip **clips,
                            uint32_t *count);

#endif
