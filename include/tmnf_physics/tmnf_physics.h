#ifndef TMNF_PHYSICS_H
#define TMNF_PHYSICS_H

/*
 * tmnf_physics: TrackMania (Nations/United) Forever physics with bit-exact
 * parity to the original game.
 *
 * Threading: the library has no global mutable state. Every function that
 * mutates takes its own context; loaded assets are immutable once built and
 * may be shared across threads.
 */

#include <stdint.h>

#if defined(TMNF_PHYSICS_BUILD_SHARED) && defined(_WIN32)
#define TMNF_API __declspec(dllexport)
#elif defined(TMNF_PHYSICS_USE_SHARED) && defined(_WIN32)
#define TMNF_API __declspec(dllimport)
#elif defined(TMNF_PHYSICS_BUILD_SHARED)
#define TMNF_API __attribute__((visibility("default")))
#else
#define TMNF_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define TMNF_PHYSICS_VERSION_MAJOR 0
#define TMNF_PHYSICS_VERSION_MINOR 1

typedef enum tmnf_backend {
  TMNF_BACKEND_REFERENCE = 0,
  TMNF_BACKEND_OPTIMIZED = 1,
} tmnf_backend;

TMNF_API const char *tmnf_version_string(void);

/* Backend compiled into this build of the library. */
TMNF_API tmnf_backend tmnf_backend_id(void);

#ifdef __cplusplus
}
#endif

#endif /* TMNF_PHYSICS_H */
