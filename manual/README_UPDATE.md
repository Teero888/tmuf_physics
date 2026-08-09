# Physics Integration Update

The current implementation/parity audit is tracked in
[`PARITY_STATUS.md`](PARITY_STATUS.md).

The TrackMania physics engine reconstruction has been successfully updated to load and integrate `.obj` files into the core C++ simulation loop.

## Changes:
1. **GmSurfMesh Implementation**: Added `LoadFromObj` in `GmSurfMesh.cpp` to parse vertex and index data from `vehicle_mesh.obj`. We also automatically compute `planeNormal` and `planeDist` for each triangle since `ClipSegment` relies on these for rapid plane distance checks. Clamped index boundaries to prevent segmentation faults during parsing of broken OBJ files.
2. **Track Mesh Instantiation**: Modified `main.cpp` to use the parsed OBJ file as a track block template. We iterate over `challenge->blocks` to populate `worldMesh` with scaled and translated vertices.
3. **CFastArray Optimization**: The initial test crashed / hung due to `CFastArray::Add` using an $O(N^2)$ reallocation approach. Added `SetCount()` pre-allocation in `main.cpp`, bringing mesh compilation time from infinity to 20ms for 480,000 triangles.
4. **Collision Logic**: Successfully removed the hardcoded `[0,1.0,0]` planes and instead perform downward raycasts strictly via `worldMesh->ClipSegment()`.
5. **Friction, Contact, Water, and Model-6 Forces**: `ApplyFrictionForces` now uses its recovered one-vector ABI and the native constant/linear, freewheel, water/ground, and timed contact-slowdown branches. The native 0x4C contact record, scene-mobil absorb callback, car wheel lookup, ground/lateral accumulation, opposite-corpus orientation observation, and ShockModel2 wheel/chassis impulses are wired. `ApplyWaterForces` covers the collision mask, strict depth tests, shallow rebound/bump impulse, and continuous water force/torque branches. `ComputeForcesModel6` now has its exact eleven-argument ABI and water-first/per-wheel suspension dispatch. Real collision-zone water-map and vehicle-AABB resource loading, processed-steering preparation, and the remaining Model-6 tire/drive/brake math remain. See `PARITY_STATUS.md` for the broader force-pipeline work.
