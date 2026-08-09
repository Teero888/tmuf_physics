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
- Sphere/sphere, sphere/ellipsoid, sphere/polygon, sphere/oriented-box,
  sphere/mesh, ellipsoid/polygon, ellipsoid/mesh, box/box, and box/mesh
  and mesh/mesh collision generation plus
  `CHmsCollisionBuffer` are translated from the native routines and covered by
  regression tests. The ellipsoid/polygon tests preserve the executable's
  unusual polygon-local output frame. Sphere/mesh, ellipsoid/mesh, and box/mesh
  currently scan faces in buffer order, while mesh/mesh scans triangle pairs
  in buffer order, because the standalone octree is not yet the game's
  broadphase structure. Their translated narrowphase and contact payloads are
  independent of that acceleration structure; first-hit selection can differ
  when more than one candidate collides.
- Native affine point/vector transforms, `GmMat3` composition/line access, and
  the typed `GmIso4` inverse/composition/blend operations have focused tests.
- `GmSurfMesh::TransformByNOMat` now follows the native vertex transform,
  reflection winding/plane rebuild, and conditional broadphase rebuild path.
- Native surface defaults and sphere/ellipsoid/box/mesh bounding-box dispatch
  are connected, including the executable's `-1.0f` empty-box convention.
- `CHmsCollisionManager` now owns typed zones/groups rather than guessed
  native-offset padding. Zone add/remove, corpus registration, the five native
  group-pair records, squared-speed preparation (including the executable's
  `1e-5f` threshold), pair filtering, and a typed located-surface-to-physical-
  contact path have focused coverage. This standalone path deliberately stops
  before the native `CPlugTree` and static-collision-octree recursion.

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

- Every pair handler registered by the native `GmSurf` dispatch matrix now has
  a translated narrowphase and contact path. Native octree traversal order is
  still substituted with deterministic face-buffer order for mesh candidates.
- The native 9x9 registration matrix is now covered exhaustively. In
  particular, the executable does not register ellipsoid/ellipsoid or
  ellipsoid/box handlers; earlier manual declarations for those inferred pairs
  have been removed from the C++ dispatch path.
- `Gm/GmCollision.cpp` contains older approximate handlers with C linkage.
  They are intentionally not connected to the C++ dispatch table and should be
  replaced with native translations, not enabled as parity implementations.
- Corpus-to-corpus detection works for typed located surfaces, but native
  `CPlugTree` surface extraction, static-collision-octree construction and
  traversal, tree/root collision recursion, and every manager segment query
  remain empty.
- The current raycast uses a custom spatial side table rather than the original
  octree traversal and still has approximate epsilon tests.

The manager's `SGroup`/`SZone` ownership and dynamic pair tables are now typed,
but `CHmsCorpus`, `CPlugTree`, and static octree leaves still need equivalent
typed collision views. The next useful slice is extracting located surfaces
from a corpus tree and building the static broadphase, then replacing the
current explicit surface registration with that native traversal.

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
- Other empty transforms include `GmLocVal` and `GmLocFreeVal` operations.
  `GmIso4` uniform/non-uniform scale construction and inverse paths now follow
  their native routines and have focused composition coverage.
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
