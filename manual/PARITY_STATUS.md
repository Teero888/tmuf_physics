# TMNF physics parity status

Last audited: 2026-08-12

The physics library builds all 88 current translation units (the separately
built visualization adds one helper unit), but a successful build is
not yet evidence of a closed physics simulation. The highest-impact remaining
gaps are below in dependency order.

## Verified slices

- Stadium tuning curves and selected Model 6 dispatch/layout facts are checked
  against `exe/TmForeverFixed.exe`.
- Exact gravity, wheel geometry, normalization, plane, and coincident-contact
  constants are checked against their executable bytes.
- `TrackMapLoader` accepts the original `Challenge.Gbx`, parses A01's metadata
  and 397 placed blocks natively, and resolves its Stadium resources into a
  fingerprinted cache. Block rotation now uses the native ground/air footprint
  from `CGameCtnBlockInfo`, rather than a one-cell pivot. The resulting collision
  has 143,845 vertices and 246,803 triangles, including the map-selected
  `Square32.Solid.Gbx` decoration; its 44,182-vertex visual Stadium mesh is also
  loaded by the interactive viewer. The current mesh raycast has focused
  coverage.
- The original Stadium car construction graph is resolved to
  `StadiumCar.Solid.Gbx`. Its 35,199-vertex visual mesh and eight collidable
  ellipsoids are loaded into native-shaped plug trees, with the four wheel
  surface trees retained for contact classification.
- `GmVec4::PolygonClip` now follows the native six-plane, double-precision
  clipping path.
- `GmSurf::ComputeCollision` now applies the native type ordering and reverses
  only newly appended contacts.
- Sphere/sphere, sphere/ellipsoid, sphere/polygon, sphere/oriented-box,
  sphere/mesh, ellipsoid/polygon, ellipsoid/mesh, box/box, and box/mesh
  and mesh/mesh collision generation plus
  `CHmsCollisionBuffer` are translated from the native routines and covered by
  regression tests. The ellipsoid/polygon tests preserve the executable's
  unusual polygon-local output frame. Ellipsoid/mesh now uses a conservative
  XZ-grid candidate side table; sphere/mesh and box/mesh still scan faces in
  buffer order, while mesh/mesh scans triangle pairs in buffer order, because
  the standalone broadphase is not yet the game's octree. Their translated
  narrowphase and contact payloads are independent of that acceleration
  structure; first-hit selection can differ when more than one candidate
  collides.
- Native affine point/vector transforms, `GmMat3` composition/line access, and
  the typed `GmIso4` inverse/composition/blend operations have focused tests.
- `GmSurfMesh::TransformByNOMat` now follows the native vertex transform,
  reflection winding/plane rebuild, and conditional broadphase rebuild path.
- Native surface defaults and sphere/ellipsoid/box/mesh bounding-box dispatch
  are connected, including the executable's `-1.0f` empty-box convention.
- `CHmsCollisionManager` now owns typed zones/groups rather than guessed
  native-offset padding. Zone add/remove, corpus registration, the five native
  group-pair records, squared-speed preparation (including the executable's
  `1e-5f` threshold), and pair filtering have focused coverage.
- The recovered `CPlugSolid`/`CPlugTree`/`CPlugSurface` path is typed through
  root ownership, child traversal, the `+0x5c` local transform, the `0x80`
  collidable flag, the `+0x8c` surface, and `CPlugSurfaceGeom`'s polymorphic
  `GmSurf`. Corpus collision queries now refresh located leaves directly from
  that tree, including nested transform composition and native-style material
  index remapping. Explicit `GmSurf` leaves remain only as a synthetic fallback.
- Fixed corpuses are removed from dynamic pair tables and flattened into typed
  static leaves containing native-equivalent world bounds, transform, surface,
  corpus, and tree references. Static rebuild/move and dynamic-versus-static
  collision behavior are regression-tested. These leaves are scanned linearly;
  the native `GmOctree<SColOctreeCell>` acceleration layout is not yet rebuilt.
- The collision manager's basic, normal-returning, and material-ID segment
  queries now cover both non-static plug trees and fixed leaves, choose the
  nearest hit, and recurse with native local-to-parent transform ordering.
  Native ray dispatch is preserved: basic/material queries accept spheres and
  meshes, while the normal-returning query accepts meshes only.
- The recovered four-pointer `SPlugTreeLocatedPair` is typed, and both native
  asymmetric helpers (tree-1 root versus tree-2 subtree, and the reverse) now
  recurse through plug surfaces with the same transform/material boundary as
  flattened corpus traversal.
- `GmArchive` now has executable-recovered golden-byte codecs for compressed
  positions, signed spherical unit vectors, quaternions, and logarithmic
  four-byte vectors. Current dynamic-state quality 0/1 save and restore use
  those codecs with the native 15/26-byte sizes and snapshot selection.
- `CHmsZoneDynamic::ComputeCorpusForces` now validates state before replacing
  the frame accumulators, evaluates spatial force fields with the native
  mass/gravity-coefficient scale, applies linear/angular damping, honors the
  no-force flag, and invokes the typed item physics callback. Uniform and ball
  field evaluation are translated from the executable. The standalone vehicle
  harness is routed through this callback boundary, and zone `+0x140` is
  correctly represented as `CFastBuffer<CHmsCorpus*>`.
- Collision-enabled corpuses are stepped from the collision manager's native
  five groups. Awake bodies use the recovered speed/angular-speed distance
  heuristic, exact `+1` rule, and 1000-step cap; every substep recomputes
  forces, integrates, detects, responds, and applies replacement. Collision
  records are sorted by the executable's nine-float/field38 key before
  response.
- `CHmsItem::SCallbackList` now matches the native six-pointer, no-vtable
  table. The recovered slot indices are wired for absorb-contact (2), force
  computation (3), and after-contacts (4); `PhysicsStep2` invokes slot 4 once
  per registered dynamic corpus after response processing. Vehicle setup now
  installs the native car slot-4 callback, which restores per-pass lifetime for
  wheel/chassis contact counts and their point/normal accumulators instead of
  allowing diagnostic state to grow for the entire run.
- Collision response now constructs both native 0x4C-byte physical-contact
  records with the executable's corpus/data/material ownership, response-
  category local point and normal, signed local relative point speed, and
  group-side callback gates. The final 12 bytes retain the opposite corpus,
  collision data, and material used by vehicle callbacks. Plug-tree identity
  is preserved through collision generation so the car callback can distinguish
  all four wheel surfaces. Each record is now dispatched to its same-side
  corpus, and callback replacement is interpreted in that body's local frame.
  The native pair-mode polarity is preserved:
  `config[2] == 0` dispatches absorb-contact callbacks, while nonzero invokes
  the physical solver.
- `CSceneVehicleCar::SEngine` is now the native standard-layout 0x34-byte
  value (no synthetic vtable), with exact constructor/reset offsets and the
  maximum-RPM field at +0x00. `EngineIntegrate` has its recovered two-float
  ABI and native caller behavior: wheel/suspension/engine ordering,
  freewheeling RPM suppression, and reverse brake-input selection. Both the
  Model-6 state machine and the older weighted-speed engine branch are
  translated, including airborne/shift response, clutch synchronization,
  forward/reverse takeoff windows, burnout state, automatic gear changes,
  timers, and final RPM clamp. Stadium tuning 29's six gear/max/min/wanted-RPM
  arrays, the recovered engine scalars, and native derived RPM-delta loops are typed
  and regression-covered against the GBX and executable. The native
  transmission/RPM state at car `+0x2E4` is now kept separate from the
  burnout force state at `+0x69C`: `EngineIntegrate` reads the latter only to
  select `+0x2E4` state four, while takeoff synchronization and automatic
  shifts write only `+0x2E4`. Exact read/dispatch instruction anchors and
  behavior regressions cover the distinction. This removes the erroneous
  state-two force interval previously produced by a straight launch.
- `ApplyFrictionForces` now has the native one-pointer ABI and is called by
  `ComputeForces`, after `IntegrateVehicle`, with the already acquired local
  linear velocity. Its constant ground slowdown, linear fluid friction,
  freewheel/input selection, Model 4/5 water-without-ground gate, legacy
  signed-forward contact slowdown, and Model 5 normalized 500 ms contact
  window are translated. The three tuning offsets (`+0x58`, `+0x5C`, and
  `+0x1E8`), Stadium values, caller instruction, and both `ret 0x04` exits are
  regression-covered. Native `+0x5DC/+0x5E0/+0x5E4` state has typed standalone
  counterparts and a deterministic millisecond clock. The vehicle absorb-
  contact producer now drives `+0x5DC`.
- `ApplyWaterForces` now has the native one-pointer ABI and its Model-6 call
  path preserves the executable's pre-friction force snapshot. The transformed
  car AABB, collision-zone byte mask/default rules, bottom/surface tests,
  strict half-unit depth gate, shallow airborne rebound/bump split, splash and
  central impulse, continuous linear/angular drag, rotated water gravity, and
  force replacement are translated. `GmMap2<uint8_t>` preserves the native
  x87 truncation and low-32-bit unsigned bounds behavior. The eight tuning
  fields at `+0x204..+0x220`, Stadium curves/defaults, constants, ABI returns,
  caller bytes, map behavior, and both continuous and impulse exits are
  regression-covered. Standalone collision zones expose semantic water mask
  and height fields; loading those fields, and the native car AABB, from real
  collision/vehicle resources is still pending.
- `ComputeForcesModel6` now exposes the executable's exact eleven-argument
  boundary and `ret 0x2C` order: timestep, pre-friction force snapshot, both
  slope-adherence values, local linear/angular speeds, processed steering,
  ground-material presence/values, slipping-wheel output, and axial-brake-force
  output. It calls water first, skips the wheel loop only for engine state 2,
  and dispatches every other wheel through `WheelAddForceToVehicle`; that
  helper retains its native no-contact rejection. The ABI, native water and
  wheel call sites, grounded suspension force, output initialization, and
  engine-state skip are regression-covered. The remaining Model-6 per-wheel
  tire/drive/brake math is still only partially translated.
- The processed-steering producer at `0x7C6CB2..0x7C6D33` is translated before
  Model-6 dispatch. It uses the car-local forward speed and the native
  `SteerRadiusMin`/`SteerRadiusCoef` fields (`+0x6C/+0x70`) to compute
  `-smoothedSteer * AsinSafe(1 / (min + abs(speed) * coef))`. The executable's strict
  ordered epsilon branch—including equality and NaN behavior—constructor
  defaults, Stadium values, field descriptors, and instruction sequence are
  regression-covered.
- The ordinary Model-6 contacted-wheel consumer at
  `0x7C4962..0x7C5018` now constructs the native lateral direction from the
  accumulated ground normal, rotates steerable/front wheels with
  `cos(processedSteer)` and `-sin(processedSteer)`, projects local velocity,
  and applies the resulting side force in that direction. Its normalized
  damper-compression curve (`+0x224`), `AbsorbingValMin/Max`, material grip,
  lateral slope adherence, sliding/braking modulation, `SideFriction1`,
  per-wheel `+0xB4` limit blend, and slipping output are wired. Native field,
  helper, trigonometric call, coefficient, and slip-store bytes plus focused
  behavior are regression-covered.
- The bounded ordinary forward axial path at `0x7C5FB8..0x7C6767` now applies
  the acceleration curve, gas and material acceleration coefficient, forward
  brake request/cap, strict `MaxSpeed * material.speed` correction, and final
  axial slope adherence. The brake request uses `BrakeBase/BrakeCoef`, the
  no-prior-slip `BrakeMaxDynamic * material.brakeCoef` cap, publishes the
  separate axial-brake output, and marks every simulation wheel slipping when
  strictly capped. The semantic speed fields (`+0x2C/+0x30/+0x60`), brake
  fields (`+0x40..+0x4C`), Model-6 brake modulation/rear caps
  (`+0x240/+0x248/+0x24C`), constructor and Stadium values, strict helpers,
  native bytes/descriptors, and end-to-end force/slip behavior are
  regression-covered. Pre-existing wheel slip now stays in the Model-6
  forward branch: every slipping wheel contributes the native `+0x240` brake
  modulation product and selects `BrakeMax`; the normal-ground tail aggregates
  over-limit lateral force and interpolates the slipping (`+0x1E0/+0x1E4`) and
  normal acceleration curves using the distinct `M5AccelSlipCoefMax` field at
  `+0x200`. Native transition state `+0x628..+0x634`, strict aggregate gating,
  field descriptors/instructions, curve weights, brake modulation, and timing
  behavior are regression-covered. Timed engine-force states one and three
  now advance through the native `+0x6F4/+0x6F8` millisecond origins and
  `+0x298/+0x2A8` durations. Their sine-shaped `+0x29C/+0x2AC`
  acceleration modulation is applied before braking; state three marks every
  wheel slipping and adds the native cycle-squared `+0x2B8` axial impulse.
  Constructor/Stadium values, property names and descriptors, lifecycle and
  x87 instruction anchors, pure phase helpers, transition boundaries, and
  end-to-end axial forces are regression-covered. Reverse/freewheel, state-two
  burnout/takeoff inertial force and torque, and special-contact branches are
  pending. A two-second A01 trace confirms that state two is not active during
  the initial straight launch once the native `+0x2E4`/`+0x69C` separation is
  preserved.
- The generic `CSceneMobilAbsorbContact` callback and the car's one-contact
  virtual are typed and registered by both executable front ends. Vehicle
  absorb handling now has the recovered material 13/23 veto, surface-tree
  wheel selection, signed impact routing, Model-5 steep-contact replacement,
  chassis accumulators, and common `WheelAbsorbContact` classification. Wheel
  contacts use the native strict `abs(normal.x) < sin(pi/4)` ground test,
  accumulate normals/material, record lateral contacts, and veto the generic
  solver. ShockModel2 now absorbs positive wheel replacement into compression,
  selects the native body/concrete/metal restitution values, and translates
  all direct, adjusted-speed, wheel-surface, lateral-wheel, and friction-limited
  chassis impulse branches. The seven-argument static
  `SDynaMath::ComputeImpulse` effective-mass equation and the two-argument
  local-point `AddVehicleImpulse` path are typed, including local/world
  transforms, linear-speed-squared rejection, angular-Y modulation, and the
  angular-speed clamp. Their executable ABIs, tuning offsets, Stadium values,
  and behavioral results are regression-covered. Wheel contacts also resolve
  the packed 32-bit opposite-corpus reference without unsafe host pointer
  casts, extract that corpus transform's local +Z axis, rotate it into vehicle
  space, and retain both values as native `+0x130..+0x13C` semantic state.
  `IsGroundContactId` exposes the recovered observation through its exact
  three-argument contract. Native extraction offsets, token retention, ABI,
  relative-orientation behavior, and expired-token safety are regression-
  covered.

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
- Decoration selection is currently recovered through the map mood and the
  Stadium construction graph. It should ultimately be driven by the complete
  challenge decoration identifier for every map size and collection. The
  unresolved `StadiumGrassClip` block also still needs its native resource path.

### 1. Finish collision generation and traversal

- Every pair handler registered by the native `GmSurf` dispatch matrix now has
  a translated narrowphase and contact path. Native octree traversal order is
  still substituted with deterministic face-buffer order or the conservative
  XZ-grid side table for mesh candidates.
- The native 9x9 registration matrix is now covered exhaustively. In
  particular, the executable does not register ellipsoid/ellipsoid or
  ellipsoid/box handlers; earlier manual declarations for those inferred pairs
  have been removed from the C++ dispatch path.
- `Gm/GmCollision.cpp` contains older approximate handlers with C linkage.
  They are intentionally not connected to the C++ dispatch table and should be
  replaced with native translations, not enabled as parity implementations.
- Corpus-to-corpus detection now extracts both moving and fixed surfaces from
  native-shaped `CPlugTree` graphs. Moving trees are refreshed per query;
  fixed trees are rebuilt by `UpdateStaticCollisionTrees`. The standalone
  implementation flattens recursive tree leaves and scans static leaves in its
  main collision path rather than reproducing native recursive candidate order.
  The asymmetric native root helpers and the three manager segment-query
  families are translated, but use the same flat/static and mesh side-table
  broadphases as the standalone collision path.
- The current raycast uses a custom spatial side table rather than the original
  octree traversal and still has approximate epsilon tests.

The manager, corpus location, plug-tree leaves, and fixed-surface records now
have typed collision views, and both collision and segment queries traverse
them. Rebuilding the native static octree remains necessary if exact candidate
order proves observable; collision response can now consume the typed working
`CHmsStateDyna` transform and velocity instead of guessed outer-object words.

### 2. Replace harness-global rigid-body state

- `CHmsStateDyna` is now a non-polymorphic, standard-layout 0xB4-byte value with
  asserted native offsets for quaternion, rotation matrix, position, linear and
  additional speed, angular speed, force, torque, world inverse inertia, saved
  speed, and the final 32-bit owner slot. The async, validated, working, and
  temporary blocks are typed; accessors and the standalone solver no longer use
  the guessed `CHmsDyna +0x3A4/+0x3A8/+0x3AC` words or appended duplicate state.
- Native reset, 0x2D-word current/temporary/validated copies, dual-state
  location writes, explicit-Euler translation, force-to-speed integration,
  full three-axis world-angular quaternion integration, center-of-mass
  preservation, torque integration, angular clamping, and rotated inverse
  inertia are represented and regression-covered. The three native dynamic
  types retain their distinct copy/write behavior. Current-state quality 0/1
  serialization is represented; legacy restore plus prediction/history remain
  incomplete.
- `CHmsZoneDynamic::PhysicsStep2` accepts an explicit timestep and advances all
  registered dynamic corpuses through the recovered force/pre/respond/post
  boundaries. When a collision-manager zone is attached it now prepares the
  manager, iterates its native group corpus buffers, selects speed-dependent
  substeps, detects contacts per corpus, and responds immediately. Native tick
  acquisition is still missing; the end-of-frame slot-4 callback is connected.
  `SolveImpulse`
  follows the native
  two-sided material, replacement-sharing, normal/tangent cancellation,
  restitution, inverse-mass, and point-angular impulse path. Replacement
  vectors are queued, directionally synthesized, reduced by the native 0.01f
  skin, and applied at the pre/post-collision boundaries. The physical-solver
  contacts expose active local replacement and signed relative point speed to
  both absorb-contact callbacks; callback replacement rewrites are transformed
  back to the target body and either callback can veto the shared impulse.
  Pair records now distinguish physical response
  (`config[2] != 0`) from callback-only contacts instead of applying impulses
  to both.
- `CHmsPhysicalContact` is now the exact standard-layout 0x4C-byte native
  value, including its local normal/point, relative speed, replacement, and
  active fields plus the opposite corpus/data/material tail at `+0x40..+0x48`.
  Native pointers are retained as 32-bit tokens on the standalone 64-bit
  build. The item callback dispatcher and both contact construction paths are
  typed and regression-covered.
- `CPlugSurfaceMaterialData` is the native standard-layout eight-byte
  friction/restitution pair. Its exact 31-entry executable default table and
  signed restitution-combination rule are represented, consumed by
  `SolveImpulse`, and regression-covered.
- `CPlugPhysicalObject` is the exact 0x48-byte value embedded at
  `CPlugSolid +0x18`: mass, inverse inertia, four scalar properties, center of
  mass, and its final 32-bit tree token are typed. Native sphere/box inverse-
  inertia construction is represented, and `CHmsDyna +0x108` now consumes the
  whole object to update world inverse inertia and point lever arms. The scalar
  at `+0x30` is also consumed as the native collision-substep distance rather
  than the earlier guessed second angular-damping component.
- `CSceneVehicleCar::UpdateParamsFromTuning` now scans the four loaded wheel
  attachment positions like native `0x7BFFA0`, derives the wheel bounding-box
  center/extents and average wheel-bottom height, applies tuning
  `CMAftForce`/`CMDownUp`, and writes the resulting center of mass, mass,
  gravity coefficient, zero linear/angular damping, collision-step distance,
  inverse box inertia, wheelbase, and Model-6 RPM ceiling. Stadium tuning 29's
  exact `0.0f` aft factor and `0.45f` vertical offset come from the extracted
  original `StadiumCar.VehicleTunings.Gbx`; the `0.3f` step-distance bits are
  checked directly at executable `.rdata` `0x00B36144`. The simulation wheel
  is also a plain, trivially copyable record with no synthetic vtable, matching
  its native constructor and making raw `CFastBuffer` relocation valid.
- `CSceneVehicleCar::VehicleReset` now translates the physics-relevant state
  clearing from native `0x7C0320`: controls, steering, engine/freewheel state,
  timers, contacts, impulses, wheel state, and engine state are reset together.
  The interactive reset also rewrites both corpus state copies and registers
  the corpus with the dynamic zone, so the recovered end-of-frame slot-4
  callback actually runs during the viewer simulation.
- The corpus transform itself and its solid refresh pointer are now typed.
  `CHmsCorpus` still contains native-offset casts and mock virtual calls in
  peripheral water/rotation/crash-dump paths that are unsafe on the current
  64-bit build.

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
- `WheelUpdateSpeedFromVehicleSpeed` now has its exact three-argument ABI and
  recovered grounded/airborne drive, brake, freewheel, disable, clamp, and
  decay branches. Its caller passes the native local-speed Z component, and
  the resource-backed grounded override is retained as resolved semantic
  state. The standard-layout `0xA8` wheel real-time state now wraps visual
  rotation, rebuilds its direction frame, and interpolates steering exactly.
  The surface handler's base/applied transforms, all three shock integration
  modes, and their matching grounded suspension-force branches are translated.
  The recovered `IntegrateVehicle` wheel/suspension/engine ordering and full
  `EngineIntegrate` branches are also connected. The friction helper and its
  `ComputeForces` call position are translated, and the absorb-contact callback
  now populates its lateral-contact flag and owns the recovered ShockModel2
  contact impulses and opposite-corpus wheel observation. The native water-
  force producer is connected, including its collision mask and rebound/
  continuous-force branches. Real resource loading for its collision-zone
  mask/heights and car AABB remains pending. The exact eleven-argument Model-6
  boundary and its water-first/per-wheel suspension dispatch are connected;
  processed-steering preparation, the ordinary contacted-wheel side reaction,
  and the ordinary forward terminal-speed correction are connected. The
  ordinary forward brake request/saturation, and the pre-existing-slip
  acceleration/brake blend are connected. The remaining reverse/freewheel and
  special-state pipeline still contains missing logic or harness
  approximations.
- The compile/unit harness is not a behavioral parity oracle. Closed-loop
  comparison is driven by the native replay trajectory and the interactive
  A01 path now that collision traversal, body state, and the fixed-step solver
  are connected; it still cannot certify unimplemented branches. The viewer
  can now decode a replay's input-events chunk directly (`--replay-inputs` or
  `--replay PATH`), including the A01 launch's intentionally idle first 10 ms,
  so its trace uses the recorded controls rather than synthetic constant gas.
- The interactive A01 path now exercises the real track, Stadium, car solid,
  wheel contacts, collision manager, and vehicle callback. With native physical
  initialization and replay-timed inputs, the 0.9-second state is `x=177.135`,
  `vx=13.293 m/s`, and pitch rate `-0.376 rad/s`, compared with the original
  replay's `x=177.365`, `vx=14.192 m/s`, and `-0.381 rad/s`; all four wheels are
  classified as grounded. This removes the generic damping loss and zero-COM
  spin source, but the growing longitudinal/contact discrepancy is still real.
  Ride height, contact depth/order, reverse/freewheel behavior, and special-
  contact branches are the next useful closed-loop targets.

## Static-data recovery rule

For loaded `.text`, `.rdata`, and `.data` in this executable, the relevant file
offset is normally `virtual_address - 0x00400000`. New constants should be read
with their native type, recorded with address and raw bits, and added to
`tests/unit/original_constants_test.cpp`. Values widened from a float to a
double must preserve that exact widened value rather than a rounded decimal.
