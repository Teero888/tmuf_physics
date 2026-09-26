cmake_minimum_required(VERSION 3.18)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

project(tmnf_physics LANGUAGES C)

include(CTest)

set(TMNF_PHYSICS_BACKEND "reference" CACHE STRING "Physics implementation: reference or optimized")
set_property(CACHE TMNF_PHYSICS_BACKEND PROPERTY STRINGS reference optimized)
option(TMNF_PHYSICS_SHARED "Build tmnf_physics as a shared library" OFF)

if(NOT TMNF_PHYSICS_BACKEND MATCHES "^(reference|optimized)$")
  message(FATAL_ERROR "TMNF_PHYSICS_BACKEND must be 'reference' or 'optimized', got '${TMNF_PHYSICS_BACKEND}'")
endif()

# Parsing shared by both backends: GBX, packs, replays -> plain data.
set(TMNF_PHYSICS_COMMON_SOURCES
  src/common/version.c
)

# The two backends never share a file. Exactly one is compiled in.
set(TMNF_PHYSICS_REFERENCE_SOURCES
  src/reference/backend.c
)
set(TMNF_PHYSICS_OPTIMIZED_SOURCES
  src/optimized/backend.c
)

if(TMNF_PHYSICS_BACKEND STREQUAL "reference")
  set(TMNF_PHYSICS_BACKEND_SOURCES ${TMNF_PHYSICS_REFERENCE_SOURCES})
else()
  set(TMNF_PHYSICS_BACKEND_SOURCES ${TMNF_PHYSICS_OPTIMIZED_SOURCES})
endif()

if(TMNF_PHYSICS_SHARED)
  set(TMNF_PHYSICS_LIB_TYPE SHARED)
else()
  set(TMNF_PHYSICS_LIB_TYPE STATIC)
endif()

add_library(tmnf_physics ${TMNF_PHYSICS_LIB_TYPE}
  include/tmnf_physics/tmnf_physics.h
  ${TMNF_PHYSICS_COMMON_SOURCES}
  ${TMNF_PHYSICS_BACKEND_SOURCES}
)
target_include_directories(tmnf_physics PUBLIC include PRIVATE src)

if(TMNF_PHYSICS_SHARED)
  target_compile_definitions(tmnf_physics PRIVATE TMNF_PHYSICS_BUILD_SHARED INTERFACE TMNF_PHYSICS_USE_SHARED)
endif()

# Bit-exact floating point is the whole point of this library. These flags
# must stay: no contraction into FMA, no value-changing optimizations, and no
# x87 excess precision on 32-bit x86.
if(MSVC)
  target_compile_options(tmnf_physics PRIVATE /fp:precise /fp:contract- /W4)
else()
  target_compile_options(tmnf_physics PRIVATE
    -ffp-contract=off
    -fno-fast-math
    -fno-associative-math
    -fno-reciprocal-math
    -fsigned-zeros
    -ftrapping-math
    -Wall -Wextra -Wshadow -Wdouble-promotion
  )
  if(CMAKE_SYSTEM_PROCESSOR MATCHES "^(i.86|x86)$")
    target_compile_options(tmnf_physics PRIVATE -msse2 -mfpmath=sse)
  endif()
endif()

if(NOT WIN32)
  target_link_libraries(tmnf_physics PRIVATE m)
endif()

if(BUILD_TESTING)
  add_executable(tmnf_physics_smoke tests/smoke.c)
  target_link_libraries(tmnf_physics_smoke PRIVATE tmnf_physics)
  add_test(NAME smoke COMMAND tmnf_physics_smoke)
endif()
