cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(tmuf_physics LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

set(TMUF_PHYSICS_BACKEND "reference" CACHE STRING "Physics implementation: reference or optimized")
set_property(CACHE TMUF_PHYSICS_BACKEND PROPERTY STRINGS reference optimized)
option(TMUF_PHYSICS_SHARED "Build tmuf_physics as a shared library" OFF)
option(TMUF_PHYSICS_TOOLS "Build development tools" OFF)

if(NOT TMUF_PHYSICS_BACKEND MATCHES "^(reference|optimized)$")
  message(FATAL_ERROR "TMUF_PHYSICS_BACKEND must be 'reference' or 'optimized', got '${TMUF_PHYSICS_BACKEND}'")
endif()

# Parsing shared by both backends: GBX, packs, replays -> plain data.
set(TMUF_PHYSICS_COMMON_SOURCES
  src/common/api.c
  src/common/api_common.h
  src/common/arena.c
  src/common/arena.h
  src/common/gbx.c
  src/common/gbx.h
  src/common/replay.c
  src/common/replay_write.c
  src/common/segment.c
  src/common/stunts.c
  src/common/stunts.h
  src/common/lightmap.c
  src/common/lightmap.h
  src/common/visuals.c
  src/common/scenery.c
  src/common/scenery.h
  src/common/visuals.h
  src/common/weather.c
  src/common/weather.h
  src/common/replay.h
  src/common/compress.c
  src/common/compress.h
  src/common/crypto.c
  src/common/crypto.h
  src/common/pack.c
  src/common/pack.h
  src/common/pack_classes.c
  src/common/pack_classes.h
  src/common/packset.c
  src/common/packset.h
  src/common/blowfish_tables.h
  src/common/challenge.c
  src/common/media.c
  src/common/media.h
  src/common/challenge_info.c
  src/common/controls.c
  src/common/controls.h
  src/common/challenge.h
  src/common/assets.c
  src/common/assets.h
  src/common/scene.c
  src/common/scene.h
  src/common/scene_ctn.c
  src/common/scene_ctn.h
  src/common/vehicle_tuning.c
  src/common/vehicle_tuning.h
  src/common/vehicle.c
  src/common/vehicle.h
  src/common/version.c
)

# The two backends never share a file. Exactly one is compiled in.
set(TMUF_PHYSICS_REFERENCE_SOURCES
  src/reference/backend.c
  src/reference/fmath.c
  src/reference/fmath.h
  src/reference/gm.h
  src/reference/dyna.c
  src/reference/dyna.h
  src/reference/world.c
  src/reference/world.h
  src/reference/collide.c
  src/reference/collide.h
  src/reference/car.c
  src/reference/car.h
  src/reference/car_util.h
  src/reference/car_forces.c
  src/reference/car_models.c
  src/reference/sim.c
  src/reference/sim.h
)
# the optimized backend compiles as one unit (unity.c includes the others)
set(TMUF_PHYSICS_OPTIMIZED_UNITY
  src/optimized/backend.c
  src/optimized/fmath.c
  src/optimized/dyna.c
  src/optimized/world.c
  src/optimized/collide.c
  src/optimized/car.c
  src/optimized/car_forces.c
  src/optimized/car_models.c
  src/optimized/sim.c
)
set_source_files_properties(${TMUF_PHYSICS_OPTIMIZED_UNITY} PROPERTIES HEADER_FILE_ONLY ON)
set(TMUF_PHYSICS_OPTIMIZED_SOURCES
  src/optimized/unity.c
  ${TMUF_PHYSICS_OPTIMIZED_UNITY}
  src/optimized/fmath.h
  src/optimized/gm.h
  src/optimized/dyna.h
  src/optimized/world.h
  src/optimized/collide.h
  src/optimized/car.h
  src/optimized/car_util.h
  src/optimized/sim.h
)

if(TMUF_PHYSICS_BACKEND STREQUAL "reference")
  set(TMUF_PHYSICS_BACKEND_SOURCES ${TMUF_PHYSICS_REFERENCE_SOURCES})
else()
  set(TMUF_PHYSICS_BACKEND_SOURCES ${TMUF_PHYSICS_OPTIMIZED_SOURCES})
endif()

# zlib 1.2.3 inflate, as linked into the game (see src/common/zlib/README.md).
add_library(tmuf_zlib OBJECT
  src/common/zlib/adler32.c
  src/common/zlib/inffast.c
  src/common/zlib/inflate.c
  src/common/zlib/inftrees.c
  src/common/zlib/zutil.c
)
set_target_properties(tmuf_zlib PROPERTIES POSITION_INDEPENDENT_CODE ON C_STANDARD 99)
target_compile_definitions(tmuf_zlib PRIVATE NO_DUMMY_DECL NO_GZIP)
if(MSVC)
  target_compile_options(tmuf_zlib PRIVATE /w)
else()
  target_compile_options(tmuf_zlib PRIVATE -w)
endif()

if(TMUF_PHYSICS_SHARED)
  set(TMUF_PHYSICS_LIB_TYPE SHARED)
else()
  set(TMUF_PHYSICS_LIB_TYPE STATIC)
endif()

add_library(tmuf_physics ${TMUF_PHYSICS_LIB_TYPE}
  include/tmuf_physics/tmuf_physics.h
  ${TMUF_PHYSICS_COMMON_SOURCES}
  ${TMUF_PHYSICS_BACKEND_SOURCES}
  $<TARGET_OBJECTS:tmuf_zlib>
)
target_include_directories(tmuf_physics PUBLIC include PRIVATE src)

if(TMUF_PHYSICS_SHARED)
  target_compile_definitions(tmuf_physics PRIVATE TMUF_PHYSICS_BUILD_SHARED INTERFACE TMUF_PHYSICS_USE_SHARED)
endif()

# Bit-exact floating point is the whole point of this library. These flags
# must stay: no contraction into FMA, no value-changing optimizations, and no
# x87 excess precision on 32-bit x86.
if(MSVC)
  target_compile_options(tmuf_physics PRIVATE /fp:precise /fp:contract- /W4)
else()
  target_compile_options(tmuf_physics PRIVATE
    -ffp-contract=off
    -fno-fast-math
    -fno-associative-math
    -fno-reciprocal-math
    -fsigned-zeros
    -ftrapping-math
    -Wall -Wextra -Wshadow -Wdouble-promotion -Wno-missing-field-initializers
  )
  if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(i.86|x86)$")
    target_compile_options(tmuf_physics PRIVATE -msse2 -mfpmath=sse)
  endif()
endif()
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND NOT TMUF_PHYSICS_BACKEND STREQUAL "reference")
  # the one-unit optimized backend: let GCC inline the gm.h helpers there
  # as it does in separate files
  set_source_files_properties(src/optimized/unity.c PROPERTIES COMPILE_OPTIONS "--param=inline-unit-growth=100")
endif()

if(NOT WIN32)
  target_link_libraries(tmuf_physics PRIVATE m)
endif()

if(TMUF_PHYSICS_TOOLS)
  add_executable(tmuf_inspect tools/inspect/tmuf_inspect.c)
  target_include_directories(tmuf_inspect PRIVATE src)
  target_link_libraries(tmuf_inspect PRIVATE tmuf_physics)
  add_executable(tmuf_api_check tools/sim/tmuf_api_check.c)
  target_link_libraries(tmuf_api_check PRIVATE tmuf_physics)
  add_executable(tmuf_rewrite tools/sim/tmuf_rewrite.c)
  target_link_libraries(tmuf_rewrite PRIVATE tmuf_physics)
  add_executable(tmuf_visuals tools/sim/tmuf_visuals.c)
  target_link_libraries(tmuf_visuals PRIVATE tmuf_physics)
  add_executable(tmuf_weather tools/sim/tmuf_weather.c)
  target_link_libraries(tmuf_weather PRIVATE tmuf_physics m)
  add_executable(tmuf_lights tools/sim/tmuf_lights.c)
  target_link_libraries(tmuf_lights PRIVATE tmuf_physics m)
  add_executable(tmuf_clips tools/sim/tmuf_clips.c)
  target_link_libraries(tmuf_clips PRIVATE tmuf_physics)
  add_executable(tmuf_bench tools/sim/tmuf_bench.c)
  target_link_libraries(tmuf_bench PRIVATE tmuf_physics)
  if(TMUF_PHYSICS_BACKEND STREQUAL "reference")
    # the oracle harness drives the reference backend's internals
    add_executable(tmuf_sim tools/sim/tmuf_sim.c)
    target_include_directories(tmuf_sim PRIVATE src)
    target_link_libraries(tmuf_sim PRIVATE tmuf_physics)
    add_executable(tmuf_rollout tools/sim/tmuf_rollout.c)
    target_include_directories(tmuf_rollout PRIVATE src)
    target_link_libraries(tmuf_rollout PRIVATE tmuf_physics)
  endif()
endif()

if(BUILD_TESTING)
  add_executable(tmuf_physics_smoke tests/smoke.c)
  target_link_libraries(tmuf_physics_smoke PRIVATE tmuf_physics)
  add_test(NAME smoke COMMAND tmuf_physics_smoke)

  add_executable(tmuf_common_tests tests/common_tests.c)
  target_include_directories(tmuf_common_tests PRIVATE src tests)
  target_link_libraries(tmuf_common_tests PRIVATE tmuf_physics)
  add_test(NAME common COMMAND tmuf_common_tests)
endif()
