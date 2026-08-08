# TMNF physics parity status

Last audited: 2026-08-08

The project builds all 82 current translation units, but a successful build is
not yet evidence of a closed physics simulation. The highest-impact remaining
gaps are below in dependency order.

## Verified slices

- Stadium tuning curves and selected Model 6 dispatch/layout facts are checked
  against `exe/TmForeverFixed.exe`.
- Exact gravity, wheel geometry, normalization, plane, and coincident-contact
  constants are checked against their executable bytes.
- Track collision extraction/loading and the current mesh raycast have focused
  regression coverage.
- `GmVec4::PolygonClip` now follows the native six-plane, double-precision
  clipping path.
- `GmSurf::ComputeCollision` now applies the native type ordering and reverses
  only newly appended contacts.
- Sphere/sphere collision generation and `CHmsCollisionBuffer` are translated
  from the native routines and covered by regression tests.

## Critical path to a self-contained simulation

### 1. Finish collision generation and traversal

- Eleven `GmSurf` pair handlers are still unconditional no-ops: sphere with
  ellipsoid/polygon/box/mesh, the ellipsoid pairs, box/box, box/mesh, and
  mesh/mesh.
- `Gm/GmCollision.cpp` contains older approximate handlers with C linkage.
  They are intentionally not connected to the C++ dispatch table and should be
  replaced with native translations, not enabled as parity implementations.
- Almost every `CHmsCollisionManager::SGroup` and `SZone` traversal, broadphase,
  segment query, and corpus detection method is empty.
- `GmSurfMesh::TransformByNOMat` is empty. The current raycast uses a custom
  spatial side table rather than the original octree traversal and still has
  approximate epsilon tests.

The next useful vertical slice is sphere/mesh contact generation followed by
the minimal `SZone::DetectCollisionsCorpus` path needed to put those contacts
into `CHmsCollisionBuffer`.

### 2. Replace harness-global rigid-body state

- `CHmsDyna` stores force, torque, position, and angular velocity in global
  `g_stub_*` variables. Multiple bodies therefore cannot simulate correctly.
- Impulse, angular-speed, torque, reset, state-save/restore, dynamic-type, and
  location methods remain empty.
- `CHmsZoneDynamic::PhysicsStep2` uses a hard-coded timestep and a simplified
  integrate/detect/respond/move loop. `SolveImpulse` is a ground-snap
  approximation rather than the native two-body solver.
- `CHmsCorpus` still contains native-offset pointer casts and mock virtual calls
  that are unsafe on the current 64-bit build.

### 3. Complete the math layer before translating more large routines

- Core `GmIso4` multiply/blend entry points are empty, and several callers
  explicitly depend on them.
- Other empty transforms include `GmMat3::Mult`, `GmLocVal`, and
  `GmLocFreeVal` operations.
- The game is 32-bit and relies on x87 evaluation plus 32-bit object layouts.
  The current 64-bit build changes pointer-sized layouts and floating-point
  evaluation. A parity build should either target 32-bit explicitly or remove
  every raw native-offset cast in favor of validated typed layouts.

### 4. Complete the vehicle force pipeline

- Only partial Stadium Model 3/6 behavior is connected. Native Model 4, Model
  5, and `ComputeAirControl` are absent from the manual implementation.
- `IntegrateVehicle`, `WheelIntegrate`, `EngineIntegrate`, friction, suspension,
  and steering still contain harness approximations or reduced logic.
- Closed-loop ghost comparison becomes meaningful only after collision
  traversal, body state, and the fixed-step solver are real; until then it
  mainly measures the scaffolding.

## Static-data recovery rule

For loaded `.text`, `.rdata`, and `.data` in this executable, the relevant file
offset is normally `virtual_address - 0x00400000`. New constants should be read
with their native type, recorded with address and raw bits, and added to
`tests/unit/original_constants_test.cpp`. Values widened from a float to a
double must preserve that exact widened value rather than a rounded decimal.
