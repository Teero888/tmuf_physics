# TMNF physics parity status

Last audited: 2026-08-08

The physics library builds all 83 current translation units (the separately
built visualization adds one helper unit), but a successful build is
not yet evidence of a closed physics simulation. The highest-impact remaining
gaps are below in dependency order.

## Verified slices

- Stadium tuning curves and selected Model 6 dispatch/layout facts are checked
  against `exe/TmForeverFixed.exe`.
- Exact gravity, wheel geometry, normalization, plane, and coincident-contact
  constants are checked against their executable bytes.
- `TrackMapLoader` accepts the original `Challenge.Gbx`, parses A01's metadata
  and 397 placed blocks natively, resolves its Stadium collision into a
  fingerprinted cache, and regression-checks the resulting 98,089 vertices and
  176,184 triangles. The current mesh raycast also has focused coverage.
- `GmVec4::PolygonClip` now follows the native six-plane, double-precision
  clipping path.
- `GmSurf::ComputeCollision` now applies the native type ordering and reverses
  only newly appended contacts.
- Sphere/sphere, sphere/oriented-box, and sphere/mesh collision generation plus
  `CHmsCollisionBuffer` are translated from the native routines and covered by
  regression tests. Sphere/mesh currently scans faces in buffer order because
  the standalone octree is not yet the game's broadphase structure.
- Native affine point/vector transforms, `GmMat3` composition/line access, and
  the typed `GmIso4` inverse/composition/blend operations have focused tests.

## Critical path to a self-contained simulation

### 0. Make Challenge.Gbx collision decoding fully native

- The public C++ loading path now takes a `.Challenge.Gbx` directly and no
  longer requires a manually exported file. However, the cache miss path still
  launches the isolated .NET `TrackCollisionExtractor` because `gbx_map` only
  decodes map metadata and block placements.
- A fully standalone library still needs native `packlist.dat` key handling,
  Stadium PAK decryption/decompression, GBX reference tables, and the required
  `CGameCtnBlockInfo`, `CSceneMobil`, `CPlugSolid`, `CPlugTree`,
  `CPlugSurface`, and `CPlugMaterial` chunks. The extractor documents the exact
  node graph and selection rules to port.

### 1. Finish collision generation and traversal

- Nine `GmSurf` pair handlers are still unconditional no-ops: sphere with
  ellipsoid/polygon, the ellipsoid pairs, box/box, box/mesh, and mesh/mesh.
- `Gm/GmCollision.cpp` contains older approximate handlers with C linkage.
  They are intentionally not connected to the C++ dispatch table and should be
  replaced with native translations, not enabled as parity implementations.
- Almost every `CHmsCollisionManager::SGroup` and `SZone` traversal, broadphase,
  segment query, and corpus detection method is empty.
- `GmSurfMesh::TransformByNOMat` is empty. The current raycast uses a custom
  spatial side table rather than the original octree traversal and still has
  approximate epsilon tests.

The collision-manager declarations first need typed standalone replacements
for the executable's 32-bit `LocatedGmSurf`, `CHmsCorpus`, `SGroup`, and
`SZone` layouts. Their current 64-bit declarations mix guessed padding with
native offsets, so directly translating `SZone::DetectCollisionsCorpus` would
be memory-unsafe. Once those wrappers are corrected, that traversal is the
next useful vertical slice, followed by ellipsoid/mesh contact generation.

### 2. Replace harness-global rigid-body state

- Standalone position, force, torque, angular velocity, and pre-step state are
  now stored per `CHmsDyna`; the old `g_stub_*` and global-yaw path has been
  removed. Force/torque/impulse accessors, reset, and basic location forwarding
  are connected and a two-body isolation regression covers the new boundary.
- The native `CHmsStateDyna` layout is understood at its core offsets, but the
  legacy 64-bit declaration still needs replacement by typed current/previous/
  temporary state objects. State-save/restore, dynamic-type, full orientation,
  inertia-tensor, and prediction/history paths remain incomplete.
- `CHmsZoneDynamic::PhysicsStep2` uses a hard-coded timestep and a simplified
  integrate/detect/respond/move loop. `SolveImpulse` is a ground-snap
  approximation rather than the native two-body solver.
- `CHmsCorpus` still contains native-offset pointer casts and mock virtual calls
  that are unsafe on the current 64-bit build.

### 3. Complete the math layer before translating more large routines

- The typed `GmIso4` inverse/composition/blend operations and `GmMat3::Mult`
  are implemented. Some weakly typed compatibility entry points remain
  intentionally guarded because their reconstructed signatures are not yet
  trustworthy.
- Other empty transforms include `GmLocVal` and `GmLocFreeVal` operations;
  non-uniform-scale inverse paths also still need native validation.
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
