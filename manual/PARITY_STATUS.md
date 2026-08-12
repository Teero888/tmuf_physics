# TMNF physics parity status

Last audited: 2026-08-12

The physics library builds all 88 current translation units (the separately
built visualization adds one helper unit), but a successful build is
not yet evidence of a closed physics simulation. The highest-impact remaining
gaps are below in dependency order.

## Reverse-engineering sources

`manual/tools/` now carries three sources that supersede guessing against
`scripts/dump.cpp`, documented in `tools/README.md`:

- `tools/symbols.txt`, 55,778 named function addresses recovered from
  `exe/TmForeverFixed.pdb`'s public-symbol stream (`llvm-pdbutil dump
  -publics`; the `pretty` mode needs DIA and fails on Linux). Regenerate with
  `tools/extract_symbols.py`. Class type records in the PDB are forward
  declarations only, so member layouts still have to come from code.
- `tools/disasm.py`, `objdump` disassembly of the PE with call targets named.
  The Ghidra pseudocode in `tmnf_dump` reuses one C variable across unrelated
  stack slots and loses x87 operand order; both have already produced wrong
  readings, so instruction-level claims should be re-derived here.
- `tools/DumpTuning`, a GBX.NET program that prints every property of every
  tuning in `StadiumCar.VehicleTunings.Gbx`, including the gear/RPM arrays and
  the chunk ids actually present. The Stadium car is `tuning[29]`; `tuning[0]`
  is a different car entirely, so an index mistake here silently swaps in the
  wrong physics. All 73 scalar constants and all 26 curves in `TuningData.hpp`
  were diffed against it this session and match exactly. The one field that was
  missing entirely, `GroundSlowDownCoef`, has been added. It also prints each
  curve's `RealInterp` mode, which is what exposed the stepped `AccelCurve`.
- `tools/tuning_chunk_offsets.py`, which recovers
  `CSceneVehicleCarTuning`'s chunk-id to member-offset mapping from the
  archive dispatch at `0x7F5EB0`. Aligning it against GBX.NET's
  `CPlugVehicleCarPhyTuning.chunkl` names each offset, and the reflection table
  `SMwParamInfos_CSceneVehicleCarTuning::s_Params` at `.data 0x00D093C0` stores
  the same offsets independently. This independently confirmed the tuning
  offsets this file already relied on: `+0x2C` MaxSpeed, `+0x30`
  ReverseMaxSpeed, `+0x34` AccelCurve, `+0x40..+0x4C` the brake block,
  `+0x6C/+0x70` SteerRadiusMin/Coef, `+0xA4` SideFriction1, `+0xAC`
  MaxSideFriction, `+0x114..+0x124` the AbsorbingVal block, `+0x160`
  GravityCoef, `+0x1E0/+0x1E4` the M5 slipping accel curve and coefficient,
  `+0x200` M5AccelSlipCoefMax, and `+0x350` ShockModel. It also names two
  fields the force path reads but nothing consumes yet: `+0x60`
  LimitToMaxSpeedForce and `+0x64` SlopeSpeedGainLimit.

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
- The reverse selector at `0x7C5A18..0x7C5B14` is translated as
  `UpdateReverseState`, on ComputeForcesModel6's common path between the
  contacted-wheel consumer and the force branch split. It owns
  `SEngine::m_isReverse` (engine `+0x28`, car `+0x5C4`), which was previously
  written nowhere except `SEngine::Reset` and so was permanently zero: reverse
  was unreachable, `IntegrateVehicle` always handed `EngineIntegrate` the gas
  input instead of selecting brake as the reverse throttle, gear 0 was never
  selected, and the Model-6 negative takeoff window could never open. Braking
  as deceleration was unaffected throughout and still is — full gas reaches
  98.2 km/h in 2 s and full gas with full brake reaches 30.0 km/h, both
  unchanged by this translation.
  The four recovered rules read car `+0x50` gas, car `+0x54` brake, the local
  linear speed's X and Z, engine `+0x30`, the burnout force state `+0x69C`, and
  `+0x600`. Every comparison is ordered, so an unordered speed rejects the
  branch it guards, and the coasting rule's sign test puts a NaN forward speed
  in the reverse result. The thresholds reuse the existing `kInputThreshold`
  (`.rdata 0x00B362C0`) for gas and brake, plus a new `kReverseSpeedThreshold`
  float `2.0f` at `.rdata 0x00B313AC` for lateral and forward speed. The
  ordering matters: the normal-ground subset reads the flag back at `0x7C5BE5`
  for its drive-torque sign. Thresholds, three instruction anchors, and
  thirteen behavior cases including the unordered-speed path are
  regression-covered.
- The Model-6 reverse drive path is translated. `0x7C5FDB` selects the drive
  curve on the flag — forward reads the tuning's `+0x34` acceleration curve
  (`M5GetAccelFromSpeed`), reverse reads the `+0x230` rear-gear curve
  (`M6GetRearGearAccelFromSpeed`) — while the slipping curve is evaluated
  before the branch and used either way. `0x7C623E..0x7C62AA` then builds the
  drive term from both pedals: an `fldz` seeds a brake direction that becomes
  `kNegativeOne` while reversing and stays `0.0f` otherwise, each pedal is
  scaled by the ground material's acceleration coefficient, the two are summed,
  and only then does the acceleration curve apply. Forward therefore reduces to
  the gas term alone, which keeps the A01 trace bit-identical, while reverse
  drives backwards off the brake pedal.
- Reverse engagement now uses its native threshold. The car constructor seeds
  car `+0x5CC` (`SEngine +0x30`, the forward-speed ceiling the selector
  compares against) with the `10.0f` at `.rdata 0x00B36194`, recorded as
  `kDefaultReverseSpeedCeiling`; the field had been left at zero, which
  confined reverse to a car that was already rolling backwards. Holding the
  brake from the A01 spawn now accelerates the car backwards, 0.024 m over the
  first second and 0.337 m over three.
  The selector's `+0x600` rule needs no producer to be correct. `+0x600` is
  written in exactly one place, `ComputeForces`' `car+0x74C == 3` branch, and
  `+0x74C` is itself written exactly once — by the constructor, to `1` — and
  never again anywhere in the executable. That branch is therefore unreachable
  for this vehicle class, `+0x600` stays zero for the whole run, and the rule
  is faithfully translated as a test that never fires. This was previously
  recorded as a blocking dependency; it is not one.
  The consequence is that the native does engage reverse the moment the brake
  is held below 36 km/h, which is why the pinned Model-6 forward-braking
  regression now sets the ceiling to zero for its own case: that assertion was
  authored while `m_isReverse` was permanently zero, so its expected force
  belongs to a forward-only scenario. The suppression keeps its native-derived
  numbers meaningful rather than restating them from the new implementation.
  The reverse-engaged force is exercised end to end instead; a self-contained
  unit case for it still wants writing, because the shared Model-6 fixture
  carries wheel-contact state between assertions.
  The A01 replay cannot exercise any of this: its input chunk declares only
  `_FakeFinishLine`, `SteerRight`, `SteerLeft`, `Accelerate`, and
  `_FakeIsRaceRunning`, with no brake control at all. The ghost trace is
  byte-for-byte unchanged by this translation, which confirms the selector does
  not perturb the existing forward parity but also means closed-loop reverse
  coverage needs a replay that actually brakes.
- IntegrateVehicle's visual steering target at `0x7C399F..0x7C3A76` is
  translated. A steerable wheel's `m_targetSteeringAngle` is
  `-smoothedSteer * kWheelVisualSteeringAngleMax`, where that constant is the
  float 30 degrees at `.rdata 0x00B36198` scaled by `kPi` over the 180.0 at
  `.rdata 0x00B36AB8`, rounded once to single precision through the
  executable's four-byte store. This is a plain scaling of the smoothed input,
  not the speed-dependent processed steer the force model uses.
  `SRealTimeState::Integrate` already walked the visible angle toward the
  target at one radian per second, but nothing had ever written the target, so
  wheel steering state was permanently zero. Nothing in the force path reads
  it, and the A01 trace is unchanged.
- The rest of that wheel loop is now translated too. Real-time state `+0x0C`
  (native wheel `+0xC0`) is typed as `m_steeringFrame`, a `GmMat3` that was
  previously unmodeled padding. `0x7C399A` refreshes it from the surface
  handler's base rotation on every wheel each step, and a steerable wheel is
  then rotated about Y by `-smoothedSteer / steerRadius`, where the radius is
  the shared `SteerRadiusMin + |speed.z| * SteerRadiusCoef` and the divide is
  guarded by `kWheelInputEpsilon`. Note this frame angle uses the small-angle
  form, unlike the target angle's fixed 30 degrees and unlike the force
  model's `AsinSafe` processed steer — three different steering quantities in
  one loop. The native rotates in place, reading each source element before
  overwriting it; `GmMat3::RotateY` writes through `*this`, so the translation
  passes a distinct source copy to stay equivalent. Frame, target, and the
  one-radian-per-second integration are regression-covered, and the A01 trace
  is unchanged.
- World handedness and the steering sign are pinned against the original A01
  replay. Correlating its recorded `SteerRight`/`SteerLeft` events with the
  recorded ghost heading over 41 steering samples gives
  `sum(steer * dYaw) = -1.37`: positive (right) steering *decreases* yaw, where
  yaw is the engine's `forward = (sin yaw, 0, cos yaw)`. An observer facing
  `forward` with `+Y` up therefore has their right hand along
  `Cross(forward, up)`, not `Cross(up, forward)`. The manual simulation
  reproduces this sign: from the A01 spawn at yaw 90 degrees, `--steer 1` curves
  the car toward `+Z`, matching the ghost. Consistently,
  `VehicleChassisBasis::right` is the native car-local `+X` axis, which points
  to the car's *left* — `kStadiumWheelLocalX` places `FLSurf` at `+0.863` and
  `FRSurf` at `-0.863`, so `right * localX` lands the wheels correctly only
  because both carry that convention. Screen-space code must derive its own
  right vector; using this field mirrors the view.
- The extracted A01 collision is confirmed unmirrored against the same ghost:
  193 of 276 recorded samples sit directly over the loaded track surface with a
  mean height error of 0.084 m, while mirroring the trajectory in X, Z, or both
  drops that to 7, 29, and 0 samples respectively.
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
- The ordinary axial tail was re-derived instruction by instruction from
  `tools/disasm.py` and three deviations from the Ghidra-derived translation
  were corrected. The pseudocode's `if (fVar23 != 0.0)` guard before the
  drive-force halving is really `cmp DWORD PTR [esp+0x10],0` at `0x7C6288`,
  and that slot holds the *integer* `ApplyWaterForces` returned at function
  entry (`0x7C3ED4`, also stored to car `+0x5E4`): water contact halves the
  assembled drive term through the `kHalf` double at `.rdata 0x00B313B8`
  (`0x7C62E2`, a QWORD `fmul`). `0x7C6020` cuts the drive curve to zero
  outright while the transmission is mid-shift (`+0x2E4` state one), rather
  than blending it. And braking is subtracted only at `0x7C666D`, after the
  water halving, signed by the raw sign bit of the forward speed
  (`0x7C6645`: `not`/`test`/`jns` on the reloaded float bits, so a negative
  zero selects the reverse sign) — the slot the earlier translation used for
  it is the steering-slowdown term instead. The terminal-speed correction runs
  on the braked force, then axial slope adherence, then the central force.
  All four instruction anchors and the gear-shift behavior are regression-
  covered. The steering-slowdown term itself (`0x7C608F`:
  `SteerSlowDownCoef` at tuning `+0x7C`, times `|car+0x5E8|`, times
  `M5GetSteerSlowDownFromSpeed(speed.z)`, times the reverse sign) is left
  unwired: Stadium's SteerSlowDown curve is zero at every non-negative speed,
  and `car+0x5E8` has no identified counterpart yet.
- The forward brake block at `0x7C638B..0x7C6461` is confirmed correct as
  translated: `(BrakeBase + BrakeCoef * speed.z) * brake * slipModulation`,
  capped by `material.brakeCoef * (BrakeMax | BrakeMaxDynamic)`.
- The backward-rolling brake block at `0x7C64FF..0x7C662F` is now translated as
  `GetModel6BackwardAxialBrakeForce`. `0x7C6325` and `0x7C6463` split the
  braking source on the sign of the forward speed alone, and the two blocks
  join at `0x7C6631`, so the ordinary drive path no longer falls back to
  Model 3 when the car rolls backwards. While rolling backwards the gas pedal
  supplies the braking: `0x7C6590` multiplies by car `+0x50`, `0x7C658E`
  subtracts `BrakeCoef * speed.z` from `BrakeBase` so the term grows with the
  backward speed, and the cap comes from the Model-6 rear pair at tuning
  `+0x248/+0x24C` rather than `+0x48/+0x4C`. The final subtraction is signed by
  the speed, so on a negative speed the braking force adds to the drive term.
  Both the ordinary result and the rear-cap saturation, including its marking
  of every simulation wheel as slipping, are regression-covered. The burnout
  trigger sharing this branch (`0x7C6485..0x7C64F9`, which needs tuning
  `+0x228`/`+0x22C` and the copied block at car `+0x6B4`) is still pending.
- `ComputeForces` re-selects two physical-object properties every step from
  ground contact, which the standalone build had been treating as one-time
  constructor values. `0x7C6AC4..0x7C6B0A` writes the gravity coefficient at
  `CPlugPhysicalObject +0x34` from tuning `+0x160` GravityCoef when grounded
  and `+0x164` GravityCoefAir when airborne (Stadium: 3.0 versus 2.5), and
  `0x7C6B0D..0x7C6B32` writes the linear damping at `+0x28` as zero when
  grounded and tuning `+0x154` LinearFluidFrictionCoef when airborne. This is
  now translated. It also settles what fluid friction is: a damping property of
  the body that only applies in the air, never a force.
- `ApplyFrictionForces` had two defects, both now fixed. `0x7BEE75` reads
  GroundSlowDownCoef at tuning `+0x5C` for the speed-proportional half of the
  coasting slowdown; the translation had been reading LinearFluidFrictionCoef,
  which is a different field and ten times smaller for Stadium (0.3 versus
  0.03). And the throttle test at `0x7BED7A`/`0x7BED88` is the strictly ordered
  `pedal < epsilon`, not `pedal <= epsilon`. The rest of the routine is
  confirmed correct: the Model 4/5 water-without-ground gate, the reverse-aware
  pedal selection, the constant slowdown applied along the unit velocity while
  the linear term is applied to the raw velocity, the free-wheeling suppression
  of the linear term, and both the legacy and the Model-5 timed lateral-contact
  windows.
- `ComputeVehicleGroundMaterialVals` (`0x7C2800`) and the ground-material
  layout are confirmed exactly. The routine averages four floats from
  `CSceneVehicleMaterial +0x14..+0x20` over the contacting wheels, indexing the
  car's material remap at `+0x6C` by the wheel's `+0x128` material id.
  `CSceneVehicleMaterial::Chunk` case `0x0A031005` archives them in the order
  `+0x14, +0x20, +0x18, +0x1C`, which against GBX.NET's chunk `0x005`
  (`Speed, Grip, AccelerationCoef, BrakeCoef`) fixes the runtime
  `SBlendableVals` as `{speed, accelerationCoef, brakeCoef, grip}` — the layout
  `StadiumVehicleMaterials::GroundValues` already asserted.
- `GetSlopeAdherence` (`0x7BEB40`) is confirmed correct, including the
  degenerate-force early return that leaves the caller's defaults of one
  untouched, the `|force.y| / |force|` ratio, the two independent
  minimum/maximum pairs at tuning `+0xD4/+0xD8` and `+0xDC/+0xE0`, the
  below-minimum zero and above-maximum one, and the `1 - cos(t * pi / 2)`
  interior.
- `AddVehicleForce` and `AddVehicleCentralForce` (`0x7BE2C0`, `0x7BE310`) reach
  `CHmsDyna::AddLocalForce`, so every force in the vehicle model is local-frame
  and unscaled by mass; `CHmsDyna::AddForce` merely accumulates. Both also add
  the force into a per-step diagnostic accumulator at car `+0x818..+0x820`
  (impulses into `+0x824..+0x82C`), which `ComputeForces` snapshots and clears
  at entry. Nothing in the physics reads it back, so it is not translated.
- `CFuncKeysReal::GetValue` (`0x586200` through `0x585E70` and
  `CFuncKeys::GetBoundingIndices` at `0x5914C0`) has **two** evaluators,
  selected by the curve's own `RealInterp` mode at `+0x28`: mode 1 steps and
  every other mode interpolates linearly. `EvaluateCurve` now models both; see
  the resolved-deficit section below, which is what this changed. The km/h
  scale `M5GetAccelFromSpeed` applies at `0x7F3E48` is the double 3.6 at
  `.rdata 0x00B3D2A8`.
- `ComputeForces`' `car +0x74C` block at `0x7C6FB8..0x7C7108` is identified and
  deliberately not translated. It is an action dispatch — mode 1 applies an
  impulse of tuning `+0x104` along the negated unit pre-friction force with a
  100 ms cooldown, mode 2 overwrites the body's gravity coefficient with tuning
  `+0x108`, mode 3 raises the turbo flag — and TMUnlimiter's parameter list
  names `+0x104` `JumpImpulseVal`. The whole block is gated at `0x7C6FA4` on
  `car +0x5C` exceeding the wheel-input epsilon, an input stock gameplay leaves
  at zero, so none of it runs in an ordinary race even though `+0x74C` is
  permanently 1.
- `WheelAddForceToVehicle` is confirmed complete against `0x7C1810`: the
  shock-model selector reads tuning `+0x350`, models 1 and 2 produce
  `(AbsorbingValRest - compression) * AbsorbingValKi - AbsorbingValKa *
  velocity`, and the result is applied as a purely vertical local force at the
  wheel contact point. There is no hidden longitudinal term in the wheel loop.
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

- Only partial Stadium Model 3/6 behavior is connected. Native Model 4 and
  Model 5 are absent from the manual implementation; `ComputeAirControl` is
  now translated and connected.
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
  wheel contacts, collision manager, and vehicle callback, and with the stepped
  acceleration curve in place it tracks the original replay closely through the
  launch and the first corner. Sampled against the recorded ghost every 100 ms,
  the mean 3D position error over the first three seconds is **0.116 m**, with a
  maximum of 0.39 m and speed within 0.34 m/s; it had been metres. The gear
  shift now lands in the same 1.8–2.0 s window as the replay's own speed
  plateau. The match holds to about 4.5 s (1.4 m), after which the simulation
  loses speed through the first corner — 47.7 m/s against the replay's 58.3 at
  5 s — and eventually wedges to a stop near 9.5 s.
  That corner is now the frontier. The suspects are the cornering side-force
  path and collision response, not the drive force: a car that stops entirely is
  stuck on geometry, which points at contact generation and impulse handling
  rather than anything in the vehicle model.

## Resolved: the A01 launch acceleration deficit

The launch used to reach 14.81 m/s at 1.0 s against the replay's 15.99, with
the gap growing to roughly 12% by 3 s. The cause was `CFuncKeysReal`'s
interpolation mode, which the standalone build did not model at all.

`CFuncKeysReal::Chunk` archives a natural at `+0x28` immediately after the
value array (`0x5861D7`, GBX chunk `0x0501A001`, GBX.NET's `RealInterp`).
`0x585E70` reads it as its sixth argument and branches on it *before* touching
the keys: mode 1 goes to `0x585EE8`, which loads `values[i0]` for the greatest
key at or below x and stores it unblended, while every other mode falls through
to `0x585EBE` and forms `(1 - t) * values[i0] + t * values[i1]`. Stadium's
`AccelCurve` carries mode 1. It is a **step**, not a ramp: a flat 16 m/s² from
0 to 101 km/h, 11 from 101 to 201, 7 from 201 to 401, 5.5 from 401 to 801.

Beware the name. GBX.NET calls mode 1 "Linear", which is exactly backwards from
what this executable does with it; the disassembly is unambiguous and is what
`tools/DumpTuning` now prints alongside each curve. Of the 26 curves in Stadium
tuning 29, three are mode 1 — `AccelCurve`, `LateralContactSlowDown` and
`SteerSlowDown` — and the rest interpolate.

`EvaluateCurve` also had an exact-key bug this exposed. `GetBoundingIndices`
(`0x5914C0`) collapses both indices onto the same key when x lands on one, so
the lower index is the *greatest* key at or below x, not the first bracket a
forward scan accepts. The two differ precisely at key points, which is
invisible for an interpolated curve (t is zero either way) and wrong by a whole
span for a stepped one.

The A01 replay measurement that pointed here is worth keeping: differentiating
the recorded ghost gives an acceleration of roughly 16 m/s² flat from 19 to
97 km/h and roughly 11 from 125 to 145 km/h — the `AccelCurve` values at keys 0
and 101, which is what a stepped curve produces and no interpolated curve can.


## ComputeAirControl (0x7BF1D0)

`ComputeForces` calls this at `0x7C6F9F` on every step and the manual
implementation had no counterpart, so airborne rotation was entirely
unmodelled. It is now translated. Its four arguments come from the pushes at
`0x7C6F95..0x7C6F9C`: the local angular speed, the tick, the ground-contact
flag, and the wheel-loop flag built at `0x7C6EF0`.

- `0x7BF1E8`: Model 4/5 in water leaves the routine.
- `0x7BF21F`: everything downstream works on the *negated* angular speed, which
  is what makes the tail's torque oppose the rotation.
- `0x7BF239`/`0x7BF264`: on the ground the routine only records state. The
  wheel-flag case also restarts the window at car `+0x614`; the
  `car +0x5D4` case records only the retained angular speed.
- `0x7BF29C`: the window test `tick - car[+0x614] >= AirControlDuration` is an
  unsigned compare, so a tick behind the origin reads as an enormous elapsed
  time and ends air control rather than extending it.
- `0x7BF2C7..0x7BF386`: the steering input at car `+0x58` is classified against
  the retained yaw using `±kWheelInputEpsilon` (the negative one is its own
  float at `.rdata 0x00B574FC`). Steering *with* the rotation always damps and
  refreshes the retained yaw; steering *against* it damps only once
  `|angularSpeed.y|` passes `MaxAngularSpeedYAirControl`, and below that
  ceiling the retained yaw is held — which is what pulls the car back toward
  it. A steering input inside the dead zone refreshes without damping.
- `0x7BF3A9`: Model 4/5 additionally retains roll at car `+0x618`, and braking
  while that retained roll is positive zeroes it instead of following.
- `0x7BF401`: damping scales the drag *direction* by the double 3.0 at
  `.rdata 0x00B3D2C0`, before its magnitude is taken. The quadratic below
  therefore sees three times the angular speed, not three times the torque.
- `0x7BF425`: airborne, the Z component is scaled by the
  `AirControlZCoefFromAngularSpeed` curve at tuning `+0x36C`, evaluated on the
  raw absolute angular speed with no km/h conversion. Stadium's curve is the
  constant 1.
- `0x7BF47B`: `SetVehicleAngularSpeed` with the retained target.
- `0x7BF480..0x7BF569`: airborne only, and on every path including the two that
  merely recorded state, a quadratic angular drag torque of
  `AngularFluidFrictionCoef2 * |w|^2 + AngularFluidFrictionCoef1 * |w|` along
  the normalized negated direction, rejected below the wheel-input epsilon.

Six behavior cases are regression-covered: grounded recording, the plain
quadratic drag, damping with and against the retained yaw, the retained-yaw
hold below the ceiling, and an expired window. The A01 grounded trace is
byte-identical with this connected, which is the expected result — the routine
only acts when no wheel has contact.

One honest gap: the wheel-loop flag at `0x7C6F01` requires a contacting wheel
whose `+0x00` field is also nonzero, and that field has no identified producer
in the standalone build, so the flag is always false today. The consequence is
that the window is measured from the last `VehicleReset` rather than the last
real ground contact. The `car +0x5D4` case still ends air control on any
contact, which keeps behavior right for a normal lap; identifying wheel `+0x00`
would close it properly.


## Static-data recovery rule

For loaded `.text`, `.rdata`, and `.data` in this executable, the relevant file
offset is normally `virtual_address - 0x00400000`. New constants should be read
with their native type, recorded with address and raw bits, and added to
`tests/unit/original_constants_test.cpp`. Values widened from a float to a
double must preserve that exact widened value rather than a rounded decimal.
