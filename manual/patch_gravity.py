import re

with open("main.cpp", "r") as f:
    content = f.read()

gravity_code = """
        // Physics step handled by IntegrateVehicle -> ComputeForcesModel3

        // Ground collision (use closest ghost sample Y)
        float groundY = 89.71f;
        float minDistSq = 1e9f;
        GmVec3 ghostDir(1, 0, 0); // default
        int closestIdx = 0;
        for (int i = 0; i < ghostSamples.size(); ++i) {
            const auto& gs = ghostSamples[i];
            float dx = g_stub_pos.x - gs.x;
            float dz = g_stub_pos.z - gs.z;
            float distSq = dx*dx + dz*dz;
            if (distSq < minDistSq) {
                minDistSq = distSq;
                groundY = gs.y - 0.5f; // Ghost Y is car center, so ground is ~0.5m below
                closestIdx = i;
            }
        }
        
        // Calculate slope from ghost trajectory
        if (closestIdx > 0 && closestIdx < ghostSamples.size() - 1) {
            GmVec3 pPrev(ghostSamples[closestIdx-1].x, ghostSamples[closestIdx-1].y, ghostSamples[closestIdx-1].z);
            GmVec3 pNext(ghostSamples[closestIdx+1].x, ghostSamples[closestIdx+1].y, ghostSamples[closestIdx+1].z);
            ghostDir.x = pNext.x - pPrev.x;
            ghostDir.y = pNext.y - pPrev.y;
            ghostDir.z = pNext.z - pPrev.z;
            float mag = std::sqrt(ghostDir.x*ghostDir.x + ghostDir.y*ghostDir.y + ghostDir.z*ghostDir.z);
            if (mag > 0.001f) {
                ghostDir.x /= mag; ghostDir.y /= mag; ghostDir.z /= mag;
            }
        }

        // Apply gravity projected along the slope!
        GmVec3 gravity(0, -29.43f, 0); // 9.81 * Mass(1) * GravityCoef(3)
        float forceForward = gravity.x * ghostDir.x + gravity.y * ghostDir.y + gravity.z * ghostDir.z;
        // The force vector along the slope:
        GmVec3 slopeForce(ghostDir.x * forceForward, ghostDir.y * forceForward, ghostDir.z * forceForward);
        
        // Add it to the item's force
        item->AddForce(item, &slopeForce, nullptr);

        float carCenterHeight = 0.5f;
"""

content = re.sub(r'// Physics step handled by IntegrateVehicle -> ComputeForcesModel3\s*// Ground collision \(use closest ghost sample Y\).*?float carCenterHeight = 0.5f;', gravity_code.strip(), content, flags=re.DOTALL)

with open("main.cpp", "w") as f:
    f.write(content)
print("Patched gravity")
