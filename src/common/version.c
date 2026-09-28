#include <tmuf_physics/tmuf_physics.h>

#define TMUF_STR2(x) #x
#define TMUF_STR(x) TMUF_STR2(x)

const char *tmuf_version_string(void) {
  return TMUF_STR(TMUF_PHYSICS_VERSION_MAJOR) "." TMUF_STR(TMUF_PHYSICS_VERSION_MINOR);
}
