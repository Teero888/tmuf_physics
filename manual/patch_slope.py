import re

with open("main.cpp", "r") as f:
    content = f.read()

slope_code = """
        // Calculate slope from ghost trajectory
        // Use a window of +-3 samples to smooth it out and ignore the spawn fall
        if (closestIdx >= 3 && closestIdx < ghostSamples.size() - 3) {
            GmVec3 pPrev(ghostSamples[closestIdx-3].x, ghostSamples[closestIdx-3].y, ghostSamples[closestIdx-3].z);
            GmVec3 pNext(ghostSamples[closestIdx+3].x, ghostSamples[closestIdx+3].y, ghostSamples[closestIdx+3].z);
            ghostDir.x = pNext.x - pPrev.x;
            ghostDir.y = pNext.y - pPrev.y;
            ghostDir.z = pNext.z - pPrev.z;
            float mag = std::sqrt(ghostDir.x*ghostDir.x + ghostDir.y*ghostDir.y + ghostDir.z*ghostDir.z);
            if (mag > 0.001f) {
                ghostDir.x /= mag; ghostDir.y /= mag; ghostDir.z /= mag;
            }
        } else {
            ghostDir = GmVec3(1, 0, 0); // Flat at the very beginning and very end
        }

        // Only apply gravity if we are actually moving and past the drop-in phase (t > 0.3s)
        GmVec3 slopeForce(0, 0, 0);
        if (raceTimeMs > 300) {
            GmVec3 gravity(0, -29.43f, 0); // 9.81 * Mass(1) * GravityCoef(3)
            float forceForward = gravity.x * ghostDir.x + gravity.y * ghostDir.y + gravity.z * ghostDir.z;
            slopeForce = GmVec3(ghostDir.x * forceForward, ghostDir.y * forceForward, ghostDir.z * forceForward);
        }
        
        // Add it to the item's force
        item->AddForce(item, &slopeForce, nullptr);
"""

content = re.sub(r'// Calculate slope from ghost trajectory.*?item->AddForce\(item, &slopeForce, nullptr\);', slope_code.strip(), content, flags=re.DOTALL)

with open("main.cpp", "w") as f:
    f.write(content)
print("Patched slope")
