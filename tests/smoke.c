#include <stdio.h>
#include <tmuf_physics/tmuf_physics.h>

int main(void) {
  printf("tmuf_physics %s, backend %d\n", tmuf_version_string(), (int)tmuf_backend_id());
  return 0;
}
