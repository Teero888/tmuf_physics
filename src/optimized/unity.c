/* The optimized backend as one translation unit: the compiler inlines the
   small helpers across files (the same code; no link-time optimization
   needed from users of the static library). */
#include "optimized/fmath.c"
#include "optimized/dyna.c"
#include "optimized/world.c"
#include "optimized/collide.c"
#include "optimized/car.c"
#include "optimized/car_forces.c"
#include "optimized/car_models.c"
#include "optimized/sim.c"
#include "optimized/backend.c"
