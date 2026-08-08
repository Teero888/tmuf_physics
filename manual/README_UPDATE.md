# Physics Integration Update

The current implementation/parity audit is tracked in
[`PARITY_STATUS.md`](PARITY_STATUS.md).

The TrackMania physics engine reconstruction has been successfully updated to load and integrate `.obj` files into the core C++ simulation loop.

## Changes:
1. **GmSurfMesh Implementation**: Added `LoadFromObj` in `GmSurfMesh.cpp` to parse vertex and index data from `vehicle_mesh.obj`. We also automatically compute `planeNormal` and `planeDist` for each triangle since `ClipSegment` relies on these for rapid plane distance checks. Clamped index boundaries to prevent segmentation faults during parsing of broken OBJ files.
2. **Track Mesh Instantiation**: Modified `main.cpp` to use the parsed OBJ file as a track block template. We iterate over `challenge->blocks` to populate `worldMesh` with scaled and translated vertices.
3. **CFastArray Optimization**: The initial test crashed / hung due to `CFastArray::Add` using an $O(N^2)$ reallocation approach. Added `SetCount()` pre-allocation in `main.cpp`, bringing mesh compilation time from infinity to 20ms for 480,000 triangles.
4. **Collision Logic**: Successfully removed the hardcoded `[0,1.0,0]` planes and instead perform downward raycasts strictly via `worldMesh->ClipSegment()`.
5. **Friction Forces**: `ApplyFrictionForces` parameters in `CSceneVehicleCar.cpp` have been set and evaluated. We use local coordinate projections on the car yaw to compute `lateralSlip` and apply counter-forces.
