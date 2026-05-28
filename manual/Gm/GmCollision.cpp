#include "GmCollision.hpp"
#include "GmSurf.hpp"
#include <cmath>

// =================================================
// Function: GmCollision::Neg
// =================================================
void GmCollision::Neg()
{
    m_vec2.x = -m_vec2.x;
    m_vec2.y = -m_vec2.y;
    m_vec2.z = -m_vec2.z;

    uint16_t temp = m_id1;
    m_id1 = m_id2;
    m_id2 = temp;

    m_vec1.x = -m_vec1.x;
    m_vec1.y = -m_vec1.y;
    m_vec1.z = -m_vec1.z;

    m_vec4.x = -m_vec4.x;
    m_vec4.y = -m_vec4.y;
    m_vec4.z = -m_vec4.z;
}

extern "C" {

int GmCollision_Sphere_Box(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfSphere* sphere = static_cast<GmSurfSphere*>(locA->m_surf);
    GmSurfBox* box = static_cast<GmSurfBox*>(locB->m_surf);

    GmVec3 delta;
    delta.x = locA->m_location.tX - locB->m_location.tX;
    delta.y = locA->m_location.tY - locB->m_location.tY;
    delta.z = locA->m_location.tZ - locB->m_location.tZ;

    GmVec3 localDelta;
    localDelta.SetMultTranspose(delta, locB->m_location.rot);

    GmVec3 minBox;
    minBox.x = box->m_center.x - box->m_extents.x;
    minBox.y = box->m_center.y - box->m_extents.y;
    minBox.z = box->m_center.z - box->m_extents.z;

    GmVec3 maxBox;
    maxBox.x = box->m_center.x + box->m_extents.x;
    maxBox.y = box->m_center.y + box->m_extents.y;
    maxBox.z = box->m_center.z + box->m_extents.z;

    GmVec3 closest = localDelta;
    bool inside = true;

    if (closest.x < minBox.x) { closest.x = minBox.x; inside = false; }
    else if (closest.x > maxBox.x) { closest.x = maxBox.x; inside = false; }
    
    if (closest.y < minBox.y) { closest.y = minBox.y; inside = false; }
    else if (closest.y > maxBox.y) { closest.y = maxBox.y; inside = false; }
    
    if (closest.z < minBox.z) { closest.z = minBox.z; inside = false; }
    else if (closest.z > maxBox.z) { closest.z = maxBox.z; inside = false; }

    if (inside) {
        return 0; // Sphere center inside box (no collision normal generated)
    }

    GmVec3 diff;
    diff.x = localDelta.x - closest.x;
    diff.y = localDelta.y - closest.y;
    diff.z = localDelta.z - closest.z;

    float distSq = diff.x*diff.x + diff.y*diff.y + diff.z*diff.z;
    float radiusSq = sphere->m_radius * sphere->m_radius;

    if (distSq > radiusSq) {
        return 0;
    }

    // Convert closest point back to world space
    GmVec3 worldClosest = closest;
    worldClosest.Mult(locB->m_location); // locB->m_location.rot * closest + locB->m_location.tX, tY, tZ

    // Compute normal and distance
    GmVec3 worldDiff;
    worldDiff.x = locA->m_location.tX - worldClosest.x;
    worldDiff.y = locA->m_location.tY - worldClosest.y;
    worldDiff.z = locA->m_location.tZ - worldClosest.z;

    float dist = std::sqrt(worldDiff.x*worldDiff.x + worldDiff.y*worldDiff.y + worldDiff.z*worldDiff.z);
    float invDist = 1.0f / dist;
    
    GmVec3 normal;
    normal.x = worldDiff.x * invDist;
    normal.y = worldDiff.y * invDist;
    normal.z = worldDiff.z * invDist;

    float penetrationDepth = sphere->m_radius - dist;

    GmCollision* col = buf->AddCollision();
    
    col->m_vec1.x = normal.x * penetrationDepth;
    col->m_vec1.y = normal.y * penetrationDepth;
    col->m_vec1.z = normal.z * penetrationDepth;
    
    col->m_vec2 = normal;
    col->m_vec3 = worldClosest;
    
    col->m_id1 = sphere->m_flags;
    col->m_id2 = box->m_flags;

    return 1;
}

int GmCollision_Sphere_Sphere(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfSphere* sphereA = static_cast<GmSurfSphere*>(locA->m_surf);
    GmSurfSphere* sphereB = static_cast<GmSurfSphere*>(locB->m_surf);

    GmVec3 delta;
    delta.x = locB->m_location.tX - locA->m_location.tX;
    delta.y = locB->m_location.tY - locA->m_location.tY;
    delta.z = locB->m_location.tZ - locA->m_location.tZ;

    float sumRadius = sphereB->m_radius + sphereA->m_radius;
    float distSq = delta.x*delta.x + delta.y*delta.y + delta.z*delta.z;

    if (distSq < sumRadius * sumRadius) {
        float dist = std::sqrt(distSq);
        GmCollision* col = buf->AddCollision();

        if (dist <= 1e-5f) {
            col->m_vec2.x = 0.0f; col->m_vec2.y = 1.0f; col->m_vec2.z = 0.0f; // Normal
            
            col->m_vec1.x = 0.0f; col->m_vec1.y = sphereB->m_radius; col->m_vec1.z = 0.0f; // penetration vector
            
            col->m_vec3.x = locA->m_location.tX;
            col->m_vec3.y = locA->m_location.tY;
            col->m_vec3.z = locA->m_location.tZ; // contact point
        } else {
            float invDist = 1.0f / dist;
            GmVec3 dir;
            dir.x = delta.x * invDist;
            dir.y = delta.y * invDist;
            dir.z = delta.z * invDist;

            col->m_vec2.x = -dir.x; col->m_vec2.y = -dir.y; col->m_vec2.z = -dir.z; // Normal points from B to A

            float penetration = sumRadius - dist;
            col->m_vec1.x = penetration * dir.x;
            col->m_vec1.y = penetration * dir.y;
            col->m_vec1.z = penetration * dir.z; // Vector from A to B scaled by penetration

            col->m_vec3.x = locA->m_location.tX + sphereA->m_radius * dir.x;
            col->m_vec3.y = locA->m_location.tY + sphereA->m_radius * dir.y;
            col->m_vec3.z = locA->m_location.tZ + sphereA->m_radius * dir.z; // Contact point on A's surface
        }

        col->m_id1 = sphereA->m_flags;
        col->m_id2 = sphereB->m_flags;

        return 1;
    }
    return 0;
}

}

extern "C" {

int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfSphere* sphereA = static_cast<GmSurfSphere*>(locA->m_surf);
    GmSurfEllipsoid* ellipsoidB = static_cast<GmSurfEllipsoid*>(locB->m_surf);

    float maxRadius = std::max(ellipsoidB->m_radii.x, std::max(ellipsoidB->m_radii.y, ellipsoidB->m_radii.z));

    GmVec3 delta;
    delta.x = locB->m_location.tX - locA->m_location.tX;
    delta.y = locB->m_location.tY - locA->m_location.tY;
    delta.z = locB->m_location.tZ - locA->m_location.tZ;

    float sumRadius = maxRadius + sphereA->m_radius;
    float distSq = delta.x*delta.x + delta.y*delta.y + delta.z*delta.z;

    if (distSq < sumRadius * sumRadius) {
        float dist = std::sqrt(distSq);
        GmCollision* col = buf->AddCollision();

        if (dist <= 1e-5f) {
            col->m_vec2.x = 0.0f; col->m_vec2.y = 1.0f; col->m_vec2.z = 0.0f;
            col->m_vec1.x = 0.0f; col->m_vec1.y = maxRadius; col->m_vec1.z = 0.0f;
            col->m_vec3.x = locA->m_location.tX;
            col->m_vec3.y = locA->m_location.tY;
            col->m_vec3.z = locA->m_location.tZ;
        } else {
            float invDist = 1.0f / dist;
            GmVec3 dir;
            dir.x = delta.x * invDist;
            dir.y = delta.y * invDist;
            dir.z = delta.z * invDist;

            col->m_vec2.x = -dir.x; col->m_vec2.y = -dir.y; col->m_vec2.z = -dir.z;

            float penetration = sumRadius - dist;
            col->m_vec1.x = penetration * dir.x;
            col->m_vec1.y = penetration * dir.y;
            col->m_vec1.z = penetration * dir.z;

            col->m_vec3.x = locA->m_location.tX + sphereA->m_radius * dir.x;
            col->m_vec3.y = locA->m_location.tY + sphereA->m_radius * dir.y;
            col->m_vec3.z = locA->m_location.tZ + sphereA->m_radius * dir.z;
        }

        col->m_id1 = sphereA->m_flags;
        col->m_id2 = ellipsoidB->m_flags;
        return 1;
    }
    return 0;
}

int GmCollision_Ellipsoid_Ellipsoid(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfEllipsoid* ellipsoidA = static_cast<GmSurfEllipsoid*>(locA->m_surf);
    GmSurfEllipsoid* ellipsoidB = static_cast<GmSurfEllipsoid*>(locB->m_surf);

    float maxRadiusA = std::max(ellipsoidA->m_radii.x, std::max(ellipsoidA->m_radii.y, ellipsoidA->m_radii.z));
    float maxRadiusB = std::max(ellipsoidB->m_radii.x, std::max(ellipsoidB->m_radii.y, ellipsoidB->m_radii.z));

    GmVec3 delta;
    delta.x = locB->m_location.tX - locA->m_location.tX;
    delta.y = locB->m_location.tY - locA->m_location.tY;
    delta.z = locB->m_location.tZ - locA->m_location.tZ;

    float sumRadius = maxRadiusB + maxRadiusA;
    float distSq = delta.x*delta.x + delta.y*delta.y + delta.z*delta.z;

    if (distSq < sumRadius * sumRadius) {
        float dist = std::sqrt(distSq);
        GmCollision* col = buf->AddCollision();

        if (dist <= 1e-5f) {
            col->m_vec2.x = 0.0f; col->m_vec2.y = 1.0f; col->m_vec2.z = 0.0f;
            col->m_vec1.x = 0.0f; col->m_vec1.y = maxRadiusB; col->m_vec1.z = 0.0f;
            col->m_vec3.x = locA->m_location.tX;
            col->m_vec3.y = locA->m_location.tY;
            col->m_vec3.z = locA->m_location.tZ;
        } else {
            float invDist = 1.0f / dist;
            GmVec3 dir;
            dir.x = delta.x * invDist;
            dir.y = delta.y * invDist;
            dir.z = delta.z * invDist;

            col->m_vec2.x = -dir.x; col->m_vec2.y = -dir.y; col->m_vec2.z = -dir.z;

            float penetration = sumRadius - dist;
            col->m_vec1.x = penetration * dir.x;
            col->m_vec1.y = penetration * dir.y;
            col->m_vec1.z = penetration * dir.z;

            col->m_vec3.x = locA->m_location.tX + maxRadiusA * dir.x;
            col->m_vec3.y = locA->m_location.tY + maxRadiusA * dir.y;
            col->m_vec3.z = locA->m_location.tZ + maxRadiusA * dir.z;
        }

        col->m_id1 = ellipsoidA->m_flags;
        col->m_id2 = ellipsoidB->m_flags;
        return 1;
    }
    return 0;
}

int GmCollision_Ellipsoid_Box(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfEllipsoid* ellipsoid = static_cast<GmSurfEllipsoid*>(locA->m_surf);
    GmSurfBox* box = static_cast<GmSurfBox*>(locB->m_surf);

    float maxRadius = std::max(ellipsoid->m_radii.x, std::max(ellipsoid->m_radii.y, ellipsoid->m_radii.z));

    GmVec3 delta;
    delta.x = locA->m_location.tX - locB->m_location.tX;
    delta.y = locA->m_location.tY - locB->m_location.tY;
    delta.z = locA->m_location.tZ - locB->m_location.tZ;

    GmVec3 localDelta;
    localDelta.SetMultTranspose(delta, locB->m_location.rot);

    GmVec3 minBox;
    minBox.x = box->m_center.x - box->m_extents.x;
    minBox.y = box->m_center.y - box->m_extents.y;
    minBox.z = box->m_center.z - box->m_extents.z;

    GmVec3 maxBox;
    maxBox.x = box->m_center.x + box->m_extents.x;
    maxBox.y = box->m_center.y + box->m_extents.y;
    maxBox.z = box->m_center.z + box->m_extents.z;

    GmVec3 closest = localDelta;
    bool inside = true;

    if (closest.x < minBox.x) { closest.x = minBox.x; inside = false; }
    else if (closest.x > maxBox.x) { closest.x = maxBox.x; inside = false; }
    
    if (closest.y < minBox.y) { closest.y = minBox.y; inside = false; }
    else if (closest.y > maxBox.y) { closest.y = maxBox.y; inside = false; }
    
    if (closest.z < minBox.z) { closest.z = minBox.z; inside = false; }
    else if (closest.z > maxBox.z) { closest.z = maxBox.z; inside = false; }

    if (inside) {
        return 0; // Center inside box
    }

    GmVec3 diff;
    diff.x = localDelta.x - closest.x;
    diff.y = localDelta.y - closest.y;
    diff.z = localDelta.z - closest.z;

    float distSq = diff.x*diff.x + diff.y*diff.y + diff.z*diff.z;
    if (distSq > maxRadius * maxRadius) {
        return 0;
    }

    GmVec3 worldClosest = closest;
    worldClosest.Mult(locB->m_location);

    GmVec3 worldDiff;
    worldDiff.x = locA->m_location.tX - worldClosest.x;
    worldDiff.y = locA->m_location.tY - worldClosest.y;
    worldDiff.z = locA->m_location.tZ - worldClosest.z;

    float dist = std::sqrt(worldDiff.x*worldDiff.x + worldDiff.y*worldDiff.y + worldDiff.z*worldDiff.z);
    float invDist = 1.0f / dist;
    
    GmVec3 normal;
    normal.x = worldDiff.x * invDist;
    normal.y = worldDiff.y * invDist;
    normal.z = worldDiff.z * invDist;

    float penetrationDepth = maxRadius - dist;

    GmCollision* col = buf->AddCollision();
    
    col->m_vec1.x = normal.x * penetrationDepth;
    col->m_vec1.y = normal.y * penetrationDepth;
    col->m_vec1.z = normal.z * penetrationDepth;
    
    col->m_vec2 = normal;
    col->m_vec3 = worldClosest;
    
    col->m_id1 = ellipsoid->m_flags;
    col->m_id2 = box->m_flags;

    return 1;
}

}

extern "C" {

// Custom helper for SAT Box-Box
static inline bool SAT_Test(float ra, float rb, float tl) {
    return std::abs(tl) <= (ra + rb);
}

int GmCollision_Box_Box(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfBox* boxA = static_cast<GmSurfBox*>(locA->m_surf);
    GmSurfBox* boxB = static_cast<GmSurfBox*>(locB->m_surf);

    // Get world matrices
    GmMat3 rotA = locA->m_location.rot;
    GmMat3 rotB = locB->m_location.rot;

    // Get world centers
    GmVec3 centerA = {
        locA->m_location.tX + (rotA.m00 * boxA->m_center.x + rotA.m01 * boxA->m_center.y + rotA.m02 * boxA->m_center.z),
        locA->m_location.tY + (rotA.m10 * boxA->m_center.x + rotA.m11 * boxA->m_center.y + rotA.m12 * boxA->m_center.z),
        locA->m_location.tZ + (rotA.m20 * boxA->m_center.x + rotA.m21 * boxA->m_center.y + rotA.m22 * boxA->m_center.z)
    };

    GmVec3 centerB = {
        locB->m_location.tX + (rotB.m00 * boxB->m_center.x + rotB.m01 * boxB->m_center.y + rotB.m02 * boxB->m_center.z),
        locB->m_location.tY + (rotB.m10 * boxB->m_center.x + rotB.m11 * boxB->m_center.y + rotB.m12 * boxB->m_center.z),
        locB->m_location.tZ + (rotB.m20 * boxB->m_center.x + rotB.m21 * boxB->m_center.y + rotB.m22 * boxB->m_center.z)
    };

    GmVec3 t = {
        centerB.x - centerA.x,
        centerB.y - centerA.y,
        centerB.z - centerA.z
    };

    GmVec3 aA[3] = {
        {rotA.m00, rotA.m10, rotA.m20},
        {rotA.m01, rotA.m11, rotA.m21},
        {rotA.m02, rotA.m12, rotA.m22}
    };
    GmVec3 aB[3] = {
        {rotB.m00, rotB.m10, rotB.m20},
        {rotB.m01, rotB.m11, rotB.m21},
        {rotB.m02, rotB.m12, rotB.m22}
    };

    float eA[3] = { boxA->m_extents.x, boxA->m_extents.y, boxA->m_extents.z };
    float eB[3] = { boxB->m_extents.x, boxB->m_extents.y, boxB->m_extents.z };

    float R[3][3];
    float AbsR[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            R[i][j] = aA[i].x * aB[j].x + aA[i].y * aB[j].y + aA[i].z * aB[j].z;
            AbsR[i][j] = std::abs(R[i][j]) + 1e-5f;
        }
    }

    float tl[3] = {
        t.x * aA[0].x + t.y * aA[0].y + t.z * aA[0].z,
        t.x * aA[1].x + t.y * aA[1].y + t.z * aA[1].z,
        t.x * aA[2].x + t.y * aA[2].y + t.z * aA[2].z
    };

    // Test axes L = A0, L = A1, L = A2
    for (int i = 0; i < 3; i++) {
        if (!SAT_Test(eA[i], eB[0] * AbsR[i][0] + eB[1] * AbsR[i][1] + eB[2] * AbsR[i][2], tl[i])) return 0;
    }

    // Test axes L = B0, L = B1, L = B2
    for (int i = 0; i < 3; i++) {
        float tlb = t.x * aB[i].x + t.y * aB[i].y + t.z * aB[i].z;
        if (!SAT_Test(eA[0] * AbsR[0][i] + eA[1] * AbsR[1][i] + eA[2] * AbsR[2][i], eB[i], tlb)) return 0;
    }

    // Test axis L = A0 x B0
    if (!SAT_Test(eA[1] * AbsR[2][0] + eA[2] * AbsR[1][0], eB[1] * AbsR[0][2] + eB[2] * AbsR[0][1], tl[2] * R[1][0] - tl[1] * R[2][0])) return 0;
    // Test axis L = A0 x B1
    if (!SAT_Test(eA[1] * AbsR[2][1] + eA[2] * AbsR[1][1], eB[0] * AbsR[0][2] + eB[2] * AbsR[0][0], tl[2] * R[1][1] - tl[1] * R[2][1])) return 0;
    // Test axis L = A0 x B2
    if (!SAT_Test(eA[1] * AbsR[2][2] + eA[2] * AbsR[1][2], eB[0] * AbsR[0][1] + eB[1] * AbsR[0][0], tl[2] * R[1][2] - tl[1] * R[2][2])) return 0;

    // Test axis L = A1 x B0
    if (!SAT_Test(eA[0] * AbsR[2][0] + eA[2] * AbsR[0][0], eB[1] * AbsR[1][2] + eB[2] * AbsR[1][1], tl[0] * R[2][0] - tl[2] * R[0][0])) return 0;
    // Test axis L = A1 x B1
    if (!SAT_Test(eA[0] * AbsR[2][1] + eA[2] * AbsR[0][1], eB[0] * AbsR[1][2] + eB[2] * AbsR[1][0], tl[0] * R[2][1] - tl[2] * R[0][1])) return 0;
    // Test axis L = A1 x B2
    if (!SAT_Test(eA[0] * AbsR[2][2] + eA[2] * AbsR[0][2], eB[0] * AbsR[1][1] + eB[1] * AbsR[1][0], tl[0] * R[2][2] - tl[2] * R[0][2])) return 0;

    // Test axis L = A2 x B0
    if (!SAT_Test(eA[0] * AbsR[1][0] + eA[1] * AbsR[0][0], eB[1] * AbsR[2][2] + eB[2] * AbsR[2][1], tl[1] * R[0][0] - tl[0] * R[1][0])) return 0;
    // Test axis L = A2 x B1
    if (!SAT_Test(eA[0] * AbsR[1][1] + eA[1] * AbsR[0][1], eB[0] * AbsR[2][2] + eB[2] * AbsR[2][0], tl[1] * R[0][1] - tl[0] * R[1][1])) return 0;
    // Test axis L = A2 x B2
    if (!SAT_Test(eA[0] * AbsR[1][2] + eA[1] * AbsR[0][2], eB[0] * AbsR[2][1] + eB[1] * AbsR[2][0], tl[1] * R[0][2] - tl[0] * R[1][2])) return 0;

    GmCollision* col = buf->AddCollision();
    
    col->m_vec1.x = 0.0f;
    col->m_vec1.y = 0.0f;
    col->m_vec1.z = 0.0f;
    
    col->m_vec2.x = 1.0f;
    col->m_vec2.y = 0.0f;
    col->m_vec2.z = 0.0f;
    
    col->m_vec3.x = locA->m_location.tX;
    col->m_vec3.y = locA->m_location.tY;
    col->m_vec3.z = locA->m_location.tZ;
    
    col->m_id1 = boxA->m_flags;
    col->m_id2 = boxB->m_flags;

    return 1;
}

}

extern "C" {

int GmCollision_Sphere_Polygon(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfSphere* sphere = static_cast<GmSurfSphere*>(locA->m_surf);
    GmSurfPolygon* poly = static_cast<GmSurfPolygon*>(locB->m_surf);

    GmVec3 sphereCenter = locA->m_location.tX == 0 ? GmVec3{0,0,0} : GmVec3{locA->m_location.tX, locA->m_location.tY, locA->m_location.tZ}; // actually just locA trans
    sphereCenter.x = locA->m_location.tX;
    sphereCenter.y = locA->m_location.tY;
    sphereCenter.z = locA->m_location.tZ;

    GmVec3 localCenter = sphereCenter;
    if (locB->m_location.rot.m00 != 1.0f || locB->m_location.tX != 0.0f) { // Simplified check for Identity
        GmVec3 delta = {
            sphereCenter.x - locB->m_location.tX,
            sphereCenter.y - locB->m_location.tY,
            sphereCenter.z - locB->m_location.tZ
        };
        localCenter.SetMultTranspose(delta, locB->m_location.rot);
    } else {
        localCenter.x -= locB->m_location.tX;
        localCenter.y -= locB->m_location.tY;
        localCenter.z -= locB->m_location.tZ;
    }

    // Distance to plane
    // Plane eq: dot(normal, X - V0) = 0 => distance = dot(normal, localCenter - V0)
    GmVec3 v0 = poly->m_vertices[0];
    float distToPlane = poly->m_planeNormal.x * (localCenter.x - v0.x) +
                        poly->m_planeNormal.y * (localCenter.y - v0.y) +
                        poly->m_planeNormal.z * (localCenter.z - v0.z);

    if (distToPlane > sphere->m_radius || (distToPlane < 0.0f && poly->m_unknown_0x48 == 0)) {
        return 0;
    }

    // Project center onto plane
    GmVec3 projCenter = {
        localCenter.x - distToPlane * poly->m_planeNormal.x,
        localCenter.y - distToPlane * poly->m_planeNormal.y,
        localCenter.z - distToPlane * poly->m_planeNormal.z
    };

    // Check if projCenter is inside the polygon
    bool inside = true;
    float minDistSq = 1e30f;
    GmVec3 closestEdgePoint = projCenter;

    for (int i = 0; i < poly->m_numVertices; i++) {
        int next = (i == poly->m_numVertices - 1) ? 0 : i + 1;
        GmVec3 currentV = poly->m_vertices[i];
        GmVec3 nextV = poly->m_vertices[next];

        GmVec3 edge = { nextV.x - currentV.x, nextV.y - currentV.y, nextV.z - currentV.z };
        GmVec3 toProj = { projCenter.x - currentV.x, projCenter.y - currentV.y, projCenter.z - currentV.z };
        
        GmVec3 edgeNormal = {
            poly->m_planeNormal.y * edge.z - poly->m_planeNormal.z * edge.y,
            poly->m_planeNormal.z * edge.x - poly->m_planeNormal.x * edge.z,
            poly->m_planeNormal.x * edge.y - poly->m_planeNormal.y * edge.x
        };

        if (toProj.x * edgeNormal.x + toProj.y * edgeNormal.y + toProj.z * edgeNormal.z > 0.0f) {
            inside = false;
            // Calculate closest point on edge
            float edgeLenSq = edge.x*edge.x + edge.y*edge.y + edge.z*edge.z;
            float t = 0.0f;
            if (edgeLenSq > 1e-5f) {
                t = (toProj.x * edge.x + toProj.y * edge.y + toProj.z * edge.z) / edgeLenSq;
            }
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;

            GmVec3 cp = { currentV.x + t * edge.x, currentV.y + t * edge.y, currentV.z + t * edge.z };
            GmVec3 toCp = { localCenter.x - cp.x, localCenter.y - cp.y, localCenter.z - cp.z };
            float dSq = toCp.x*toCp.x + toCp.y*toCp.y + toCp.z*toCp.z;
            
            if (dSq < minDistSq) {
                minDistSq = dSq;
                closestEdgePoint = cp;
            }
        }
    }

    GmVec3 localClosest;
    GmVec3 localNormal;
    float finalDist;

    if (inside) {
        if (distToPlane < 0.0f) { // If backface allowed
            localNormal.x = -poly->m_planeNormal.x;
            localNormal.y = -poly->m_planeNormal.y;
            localNormal.z = -poly->m_planeNormal.z;
            finalDist = -distToPlane;
        } else {
            localNormal = poly->m_planeNormal;
            finalDist = distToPlane;
        }
        localClosest = projCenter;
    } else {
        if (minDistSq > sphere->m_radius * sphere->m_radius) {
            return 0;
        }
        localClosest = closestEdgePoint;
        finalDist = std::sqrt(minDistSq);
        float invD = 1.0f / finalDist;
        localNormal.x = (localCenter.x - closestEdgePoint.x) * invD;
        localNormal.y = (localCenter.y - closestEdgePoint.y) * invD;
        localNormal.z = (localCenter.z - closestEdgePoint.z) * invD;
    }

    GmVec3 worldClosest = localClosest;
    worldClosest.Mult(locB->m_location);

    GmVec3 worldNormal = {
        locB->m_location.rot.m00 * localNormal.x + locB->m_location.rot.m01 * localNormal.y + locB->m_location.rot.m02 * localNormal.z,
        locB->m_location.rot.m10 * localNormal.x + locB->m_location.rot.m11 * localNormal.y + locB->m_location.rot.m12 * localNormal.z,
        locB->m_location.rot.m20 * localNormal.x + locB->m_location.rot.m21 * localNormal.y + locB->m_location.rot.m22 * localNormal.z
    };

    float penetrationDepth = sphere->m_radius - finalDist;

    GmCollision* col = buf->AddCollision();
    col->m_vec1.x = worldNormal.x * penetrationDepth;
    col->m_vec1.y = worldNormal.y * penetrationDepth;
    col->m_vec1.z = worldNormal.z * penetrationDepth;
    col->m_vec2 = worldNormal;
    col->m_vec3 = worldClosest;
    col->m_id1 = sphere->m_flags;
    col->m_id2 = poly->m_flags;

    return 1;
}

int GmCollision_Ellipsoid_Polygon(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    GmSurfEllipsoid* ellipsoid = static_cast<GmSurfEllipsoid*>(locA->m_surf);
    GmSurfPolygon* poly = static_cast<GmSurfPolygon*>(locB->m_surf);

    float maxRadius = std::max(ellipsoid->m_radii.x, std::max(ellipsoid->m_radii.y, ellipsoid->m_radii.z));

    GmVec3 sphereCenter = {locA->m_location.tX, locA->m_location.tY, locA->m_location.tZ};
    GmVec3 localCenter = sphereCenter;
    if (locB->m_location.rot.m00 != 1.0f || locB->m_location.tX != 0.0f) {
        GmVec3 delta = { sphereCenter.x - locB->m_location.tX, sphereCenter.y - locB->m_location.tY, sphereCenter.z - locB->m_location.tZ };
        localCenter.SetMultTranspose(delta, locB->m_location.rot);
    } else {
        localCenter.x -= locB->m_location.tX;
        localCenter.y -= locB->m_location.tY;
        localCenter.z -= locB->m_location.tZ;
    }

    GmVec3 v0 = poly->m_vertices[0];
    float distToPlane = poly->m_planeNormal.x * (localCenter.x - v0.x) +
                        poly->m_planeNormal.y * (localCenter.y - v0.y) +
                        poly->m_planeNormal.z * (localCenter.z - v0.z);

    if (distToPlane > maxRadius || (distToPlane < 0.0f && poly->m_unknown_0x48 == 0)) {
        return 0;
    }

    GmVec3 projCenter = {
        localCenter.x - distToPlane * poly->m_planeNormal.x,
        localCenter.y - distToPlane * poly->m_planeNormal.y,
        localCenter.z - distToPlane * poly->m_planeNormal.z
    };

    bool inside = true;
    float minDistSq = 1e30f;
    GmVec3 closestEdgePoint = projCenter;

    for (int i = 0; i < poly->m_numVertices; i++) {
        int next = (i == poly->m_numVertices - 1) ? 0 : i + 1;
        GmVec3 currentV = poly->m_vertices[i];
        GmVec3 nextV = poly->m_vertices[next];

        GmVec3 edge = { nextV.x - currentV.x, nextV.y - currentV.y, nextV.z - currentV.z };
        GmVec3 toProj = { projCenter.x - currentV.x, projCenter.y - currentV.y, projCenter.z - currentV.z };
        
        GmVec3 edgeNormal = {
            poly->m_planeNormal.y * edge.z - poly->m_planeNormal.z * edge.y,
            poly->m_planeNormal.z * edge.x - poly->m_planeNormal.x * edge.z,
            poly->m_planeNormal.x * edge.y - poly->m_planeNormal.y * edge.x
        };

        if (toProj.x * edgeNormal.x + toProj.y * edgeNormal.y + toProj.z * edgeNormal.z > 0.0f) {
            inside = false;
            float edgeLenSq = edge.x*edge.x + edge.y*edge.y + edge.z*edge.z;
            float t = 0.0f;
            if (edgeLenSq > 1e-5f) {
                t = (toProj.x * edge.x + toProj.y * edge.y + toProj.z * edge.z) / edgeLenSq;
            }
            if (t < 0.0f) t = 0.0f;
            if (t > 1.0f) t = 1.0f;

            GmVec3 cp = { currentV.x + t * edge.x, currentV.y + t * edge.y, currentV.z + t * edge.z };
            GmVec3 toCp = { localCenter.x - cp.x, localCenter.y - cp.y, localCenter.z - cp.z };
            float dSq = toCp.x*toCp.x + toCp.y*toCp.y + toCp.z*toCp.z;
            
            if (dSq < minDistSq) {
                minDistSq = dSq;
                closestEdgePoint = cp;
            }
        }
    }

    GmVec3 localClosest;
    GmVec3 localNormal;
    float finalDist;

    if (inside) {
        if (distToPlane < 0.0f) {
            localNormal.x = -poly->m_planeNormal.x;
            localNormal.y = -poly->m_planeNormal.y;
            localNormal.z = -poly->m_planeNormal.z;
            finalDist = -distToPlane;
        } else {
            localNormal = poly->m_planeNormal;
            finalDist = distToPlane;
        }
        localClosest = projCenter;
    } else {
        if (minDistSq > maxRadius * maxRadius) {
            return 0;
        }
        localClosest = closestEdgePoint;
        finalDist = std::sqrt(minDistSq);
        float invD = 1.0f / finalDist;
        localNormal.x = (localCenter.x - closestEdgePoint.x) * invD;
        localNormal.y = (localCenter.y - closestEdgePoint.y) * invD;
        localNormal.z = (localCenter.z - closestEdgePoint.z) * invD;
    }

    GmVec3 worldClosest = localClosest;
    worldClosest.Mult(locB->m_location);

    GmVec3 worldNormal = {
        locB->m_location.rot.m00 * localNormal.x + locB->m_location.rot.m01 * localNormal.y + locB->m_location.rot.m02 * localNormal.z,
        locB->m_location.rot.m10 * localNormal.x + locB->m_location.rot.m11 * localNormal.y + locB->m_location.rot.m12 * localNormal.z,
        locB->m_location.rot.m20 * localNormal.x + locB->m_location.rot.m21 * localNormal.y + locB->m_location.rot.m22 * localNormal.z
    };

    float penetrationDepth = maxRadius - finalDist;

    GmCollision* col = buf->AddCollision();
    col->m_vec1.x = worldNormal.x * penetrationDepth;
    col->m_vec1.y = worldNormal.y * penetrationDepth;
    col->m_vec1.z = worldNormal.z * penetrationDepth;
    col->m_vec2 = worldNormal;
    col->m_vec3 = worldClosest;
    col->m_id1 = ellipsoid->m_flags;
    col->m_id2 = poly->m_flags;

    return 1;
}

}
