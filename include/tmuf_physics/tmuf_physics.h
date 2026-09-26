#ifndef TMUF_PHYSICS_H
#define TMUF_PHYSICS_H

/*
 * tmuf_physics: TrackMania (Nations/United) Forever physics with bit-exact
 * parity to the original game.
 *
 * Threading: the library has no global mutable state. Every function that
 * mutates takes its own context; loaded assets are immutable once built and
 * may be shared across threads.
 */

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

#ifdef __cplusplus
extern "C" {
#endif

#define TMUF_PHYSICS_VERSION_MAJOR 0
#define TMUF_PHYSICS_VERSION_MINOR 1

typedef enum tmuf_backend {
  TMUF_BACKEND_REFERENCE = 0,
  TMUF_BACKEND_OPTIMIZED = 1,
} tmuf_backend;

TMUF_API const char *tmuf_version_string(void);

/* Backend compiled into this build of the library. */
TMUF_API tmuf_backend tmuf_backend_id(void);

#ifdef __cplusplus
}
#endif

#endif /* TMUF_PHYSICS_H */
