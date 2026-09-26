cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(tmuf_physics LANGUAGES C)

include(CTest)

set(TMUF_PHYSICS_BACKEND "reference" CACHE STRING "Physics implementation: reference or optimized")
set_property(CACHE TMUF_PHYSICS_BACKEND PROPERTY STRINGS reference optimized)
option(TMUF_PHYSICS_SHARED "Build tmuf_physics as a shared library" OFF)

if(NOT TMUF_PHYSICS_BACKEND MATCHES "^(reference|optimized)$")
  message(FATAL_ERROR "TMUF_PHYSICS_BACKEND must be 'reference' or 'optimized', got '${TMUF_PHYSICS_BACKEND}'")
endif()

# Parsing shared by both backends: GBX, packs, replays -> plain data.
set(TMUF_PHYSICS_COMMON_SOURCES
  src/common/version.c
)

# The two backends never share a file. Exactly one is compiled in.
set(TMUF_PHYSICS_REFERENCE_SOURCES
  src/reference/backend.c
)
set(TMUF_PHYSICS_OPTIMIZED_SOURCES
  src/optimized/backend.c
)

if(TMUF_PHYSICS_BACKEND STREQUAL "reference")
  set(TMUF_PHYSICS_BACKEND_SOURCES ${TMUF_PHYSICS_REFERENCE_SOURCES})
else()
  set(TMUF_PHYSICS_BACKEND_SOURCES ${TMUF_PHYSICS_OPTIMIZED_SOURCES})
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
    -Wall -Wextra -Wshadow -Wdouble-promotion
  )
  if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(i.86|x86)$")
    target_compile_options(tmuf_physics PRIVATE -msse2 -mfpmath=sse)
  endif()
endif()

if(NOT WIN32)
  target_link_libraries(tmuf_physics PRIVATE m)
endif()

if(BUILD_TESTING)
  add_executable(tmuf_physics_smoke tests/smoke.c)
  target_link_libraries(tmuf_physics_smoke PRIVATE tmuf_physics)
  add_test(NAME smoke COMMAND tmuf_physics_smoke)
endif()
