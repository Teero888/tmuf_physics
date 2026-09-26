#include <stdio.h>
#include <tmnf_physics/tmnf_physics.h>

int main(void) {
  printf("tmnf_physics %s, backend %d\n", tmnf_version_string(), (int)tmnf_backend_id());
  return 0;
}
