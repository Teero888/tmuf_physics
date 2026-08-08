#include "GmSurf.hpp"
#include "GmCollision.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>

namespace {

GmVec3 TransformVector(const GmIso4& transform, const GmVec3& vector) {
    return {
        transform.m00 * vector.x + transform.m01 * vector.y +
            transform.m02 * vector.z,
        transform.m10 * vector.x + transform.m11 * vector.y +
            transform.m12 * vector.z,
        transform.m20 * vector.x + transform.m21 * vector.y +
            transform.m22 * vector.z,
    };
}

GmVec3 TransformPoint(const GmIso4& transform, const GmVec3& point) {
    GmVec3 result = TransformVector(transform, point);
    result.x += transform.tX;
    result.y += transform.tY;
    result.z += transform.tZ;
    return result;
}

void SetCollisionFeatureFlag(GmCollision& collision, uint32_t flag) {
    static_assert(sizeof(collision.m_unknown_0x28) == sizeof(flag));
    std::memcpy(&collision.m_unknown_0x28, &flag, sizeof(flag));
}

void TransformMeshCollisionToWorld(
    GmCollision& collision, const GmIso4& meshLocation) {
    collision.m_vec1 = TransformVector(meshLocation, collision.m_vec1);
    collision.m_vec2 = TransformVector(meshLocation, collision.m_vec2);
    collision.m_vec3 = TransformPoint(meshLocation, collision.m_vec3);
    collision.m_vec4 = TransformVector(meshLocation, collision.m_vec4);
}

bool AddSphereMeshEdgeCollision(
    const GmVec3& sphereCenter,
    float sphereRadius,
    uint16_t sphereFlags,
    const GmVec3& faceNormal,
    uint16_t materialId,
    const GmVec3& closestPoint,
    float squaredDistanceEpsilon,
    const GmIso4& meshLocation,
    CGmCollisionBuffer& buffer) {
    const GmVec3 delta = sphereCenter - closestPoint;
    const float distanceSquared = GmVec3::Dot(delta, delta);
    if (distanceSquared > sphereRadius * sphereRadius ||
        distanceSquared <= squaredDistanceEpsilon) {
        return false;
    }

    const float distance = std::sqrt(distanceSquared);
    const float inverseDistance = 1.0f / distance;
    const GmVec3 contactNormal = delta * inverseDistance;
    const GmVec3 rawReplacement =
        delta * ((distance - sphereRadius) * inverseDistance);
    const float normalReplacement =
        GmVec3::Dot(rawReplacement, faceNormal);

    GmCollision* collision = buffer.AddCollision();
    collision->m_vec1 = faceNormal * normalReplacement;
    collision->m_vec2 = contactNormal;
    collision->m_vec3 = closestPoint;
    collision->m_id1 = sphereFlags;
    collision->m_id2 = materialId;
    SetCollisionFeatureFlag(*collision, 0u);
    collision->m_vec4 = faceNormal;
    TransformMeshCollisionToWorld(*collision, meshLocation);
    return true;
}

} // namespace

// Collision Dispatch Matrix (9x9)
typedef int (*GmCollisionFunc)(LocatedGmSurf*, LocatedGmSurf*, CGmCollisionBuffer*);
GmCollisionFunc g_GmCollisionMatrix[9][9];

// =================================================
// Base Class: GmSurf
// =================================================

GmSurf::GmSurf() {
    m_type = 0xFF;
    m_flags = 0;
}

GmSurf::~GmSurf() {}

// External collision function prototypes
extern int GmCollision_Sphere_Sphere(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Polygon(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Ellipsoid(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Polygon(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Box_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Box_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Mesh_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);

void GmSurf::StaticInit() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            g_GmCollisionMatrix[i][j] = nullptr; 
        }
    }

    g_GmCollisionMatrix[0][0] = GmCollision_Sphere_Sphere;
    g_GmCollisionMatrix[0][1] = g_GmCollisionMatrix[1][0] = GmCollision_Sphere_Ellipsoid;
    g_GmCollisionMatrix[0][5] = g_GmCollisionMatrix[5][0] = GmCollision_Sphere_Polygon;
    g_GmCollisionMatrix[0][6] = g_GmCollisionMatrix[6][0] = GmCollision_Sphere_Box;
    g_GmCollisionMatrix[0][7] = g_GmCollisionMatrix[7][0] = GmCollision_Sphere_Mesh;

    g_GmCollisionMatrix[1][1] = GmCollision_Ellipsoid_Ellipsoid;
    g_GmCollisionMatrix[1][5] = g_GmCollisionMatrix[5][1] = GmCollision_Ellipsoid_Polygon;
    g_GmCollisionMatrix[1][6] = g_GmCollisionMatrix[6][1] = GmCollision_Ellipsoid_Box;
    g_GmCollisionMatrix[1][7] = g_GmCollisionMatrix[7][1] = GmCollision_Ellipsoid_Mesh;

    g_GmCollisionMatrix[5][5] = nullptr; // Polygon-Polygon handled by higher level
    g_GmCollisionMatrix[5][6] = g_GmCollisionMatrix[6][5] = nullptr;
    g_GmCollisionMatrix[5][7] = g_GmCollisionMatrix[7][5] = nullptr;

    g_GmCollisionMatrix[6][6] = GmCollision_Box_Box;
    g_GmCollisionMatrix[6][7] = g_GmCollisionMatrix[7][6] = GmCollision_Box_Mesh;
    
    g_GmCollisionMatrix[7][7] = GmCollision_Mesh_Mesh;
}

int GmSurf::ComputeCollision(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    if (!locA || !locB || !buf || !locA->m_surf || !locB->m_surf) return 0;
    
    uint8_t typeA = locA->m_surf->m_type;
    uint8_t typeB = locB->m_surf->m_type;
    
    if (typeA >= 9 || typeB >= 9) return 0;
    
    if (typeA <= typeB) {
        GmCollisionFunc func = g_GmCollisionMatrix[typeA][typeB];
        return func ? func(locA, locB, buf) : 0;
    }

    // The native dispatcher always invokes pair functions with the lower type
    // first, then reverses only the contacts appended by that invocation.
    const uint32_t firstNewCollision = buf->GetCount();
    GmCollisionFunc func = g_GmCollisionMatrix[typeB][typeA];
    if (!func || func(locB, locA, buf) == 0) return 0;

    const uint32_t collisionCount = buf->GetCount();
    for (uint32_t index = firstNewCollision; index < collisionCount; ++index) {
        buf->GetCollision(index)->Neg();
    }
    return 1;
}

void GmSurf::GetBoundingBox(GmBoxAligned& outBox) const {
    outBox.InitEmpty();
}

// GmSurfBox (Type 6)
GmSurfBox::GmSurfBox() { m_type = 6; }
GmSurfBox::~GmSurfBox() {}

// GmSurfEllipsoid (Type 1)
GmSurfEllipsoid::GmSurfEllipsoid() { m_type = 1; }
GmSurfEllipsoid::~GmSurfEllipsoid() {}

// GmSurfSphere (Type 0)
GmSurfSphere::GmSurfSphere() { m_type = 0; }
GmSurfSphere::~GmSurfSphere() {}

// GmSurfPolygon (Type 5)
GmSurfPolygon::GmSurfPolygon(uint8_t param) { m_type = 5; }
GmSurfPolygon::~GmSurfPolygon() {}

int GmCollision_Sphere_Sphere(LocatedGmSurf* locA,
                              LocatedGmSurf* locB,
                              CGmCollisionBuffer* buffer) {
    GmSurfSphere* sphereA = static_cast<GmSurfSphere*>(locA->m_surf);
    GmSurfSphere* sphereB = static_cast<GmSurfSphere*>(locB->m_surf);

    const float deltaX = locB->m_location.tX - locA->m_location.tX;
    const float deltaY = locB->m_location.tY - locA->m_location.tY;
    const float deltaZ = locB->m_location.tZ - locA->m_location.tZ;
    const float distanceSquared =
        deltaZ * deltaZ + deltaX * deltaX + deltaY * deltaY;
    const float radiusSum = sphereB->m_radius + sphereA->m_radius;

    if (!(distanceSquared < radiusSum * radiusSum)) return 0;

    const float distance = std::sqrt(distanceSquared);
    GmCollision* collision = buffer->AddCollision();
    if (distance <= TmForeverPhysicsConstants::kCoincidentSurfaceEpsilon) {
        collision->m_vec2 = {0.0f, -1.0f, 0.0f};
        collision->m_vec1 = {0.0f, sphereB->m_radius, 0.0f};
        collision->m_vec3 = {locA->m_location.tX,
                             locA->m_location.tY,
                             locA->m_location.tZ};
    } else {
        const float inverseDistance = 1.0f / distance;
        const float directionX = deltaX * inverseDistance;
        const float directionY = deltaY * inverseDistance;
        const float directionZ = deltaZ * inverseDistance;

        collision->m_vec2 = {-directionX, -directionY, -directionZ};
        const float penetration = radiusSum - distance;
        collision->m_vec1 = {penetration * directionX,
                             penetration * directionY,
                             penetration * directionZ};
        collision->m_vec3 = {
            locA->m_location.tX + sphereA->m_radius * directionX,
            locA->m_location.tY + sphereA->m_radius * directionY,
            locA->m_location.tZ + sphereA->m_radius * directionZ};
    }

    collision->m_id1 = sphereA->m_flags;
    collision->m_id2 = sphereB->m_flags;
    return 1;
}

// Collision pairs still awaiting native translations.
int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Polygon(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Box(
    LocatedGmSurf* locatedSphere,
    LocatedGmSurf* locatedBox,
    CGmCollisionBuffer* buffer) {
    GmSurfSphere* sphere =
        static_cast<GmSurfSphere*>(locatedSphere->m_surf);
    GmSurfBox* box = static_cast<GmSurfBox*>(locatedBox->m_surf);
    const GmVec3 worldSphereCenter{
        locatedSphere->m_location.tX,
        locatedSphere->m_location.tY,
        locatedSphere->m_location.tZ,
    };
    const GmVec3 sphereCenter =
        locatedBox->m_location.UnTransform(worldSphereCenter);
    const GmVec3 boxMinimum = box->m_center - box->m_extents;
    const GmVec3 boxMaximum = box->m_center + box->m_extents;

    // The executable does not generate an internal contact when the sphere
    // center lies inside the box. It first selects an outside face and then
    // clamps the other two coordinates to obtain the closest feature.
    const bool centerInside =
        sphereCenter.x >= boxMinimum.x && sphereCenter.x <= boxMaximum.x &&
        sphereCenter.y >= boxMinimum.y && sphereCenter.y <= boxMaximum.y &&
        sphereCenter.z >= boxMinimum.z && sphereCenter.z <= boxMaximum.z;
    if (centerInside) return 0;

    const GmVec3 closestPoint{
        std::clamp(sphereCenter.x, boxMinimum.x, boxMaximum.x),
        std::clamp(sphereCenter.y, boxMinimum.y, boxMaximum.y),
        std::clamp(sphereCenter.z, boxMinimum.z, boxMaximum.z),
    };
    const GmVec3 localDelta = sphereCenter - closestPoint;
    const float distanceSquared = GmVec3::Dot(localDelta, localDelta);
    const float radius = sphere->m_radius;
    if (distanceSquared > radius * radius) return 0;

    const GmVec3 worldClosestPoint =
        TransformPoint(locatedBox->m_location, closestPoint);
    const GmVec3 worldDelta = worldSphereCenter - worldClosestPoint;
    const float distance = std::sqrt(GmVec3::Dot(worldDelta, worldDelta));
    if (distance <= 0.0f) return 0;

    const GmVec3 normal = worldDelta * (1.0f / distance);
    GmCollision* collision = buffer->AddCollision();
    collision->m_vec1 = normal * (distance - radius);
    collision->m_vec2 = normal;
    collision->m_vec3 = worldClosestPoint;
    collision->m_id1 = sphere->m_flags;
    collision->m_id2 = box->m_flags;
    return 1;
}
int GmCollision_Sphere_Mesh(
    LocatedGmSurf* locatedSphere,
    LocatedGmSurf* locatedMesh,
    CGmCollisionBuffer* buffer) {
    GmSurfSphere* sphere =
        static_cast<GmSurfSphere*>(locatedSphere->m_surf);
    GmSurfMesh* mesh = static_cast<GmSurfMesh*>(locatedMesh->m_surf);
    const GmVec3 worldSphereCenter{
        locatedSphere->m_location.tX,
        locatedSphere->m_location.tY,
        locatedSphere->m_location.tZ,
    };
    const GmVec3 sphereCenter =
        locatedMesh->m_location.UnTransform(worldSphereCenter);
    const float radius = sphere->m_radius;
    const float radiusSquared = radius * radius;
    bool foundCollision = false;

    // The executable traverses the mesh octree before running this exact
    // triangle test. The standalone mesh's current octree is a temporary
    // vertical-ray index, so visit faces in native buffer order here. This is
    // geometrically equivalent and preserves deterministic contact ordering.
    for (uint32_t triangleIndex = 0;
         triangleIndex < mesh->m_triangles.m_count;
         ++triangleIndex) {
        const GmSurfTriangle& triangle = mesh->m_triangles[triangleIndex];
        if (triangle.indices[0] >= mesh->m_vertices.m_count ||
            triangle.indices[1] >= mesh->m_vertices.m_count ||
            triangle.indices[2] >= mesh->m_vertices.m_count) {
            continue;
        }

        const GmVec3& first = mesh->m_vertices[triangle.indices[0]];
        const GmVec3& second = mesh->m_vertices[triangle.indices[1]];
        const GmVec3& third = mesh->m_vertices[triangle.indices[2]];
        const GmVec3& faceNormal = triangle.planeNormal;
        const float planeDistance =
            GmVec3::Dot(sphereCenter - first, faceNormal);

        // Native mesh contacts are one-sided. A sphere whose center is behind
        // the face, or farther than its radius in front, cannot collide.
        if (planeDistance < 0.0f || planeDistance > radius) continue;

        const float crossSectionSquared =
            radiusSquared - planeDistance * planeDistance;
        const float crossSectionRadius = std::sqrt(
            std::max(0.0f, crossSectionSquared));
        const GmVec3 projected =
            sphereCenter - faceNormal * planeDistance;
        const GmVec3* vertices[3] = {&first, &second, &third};
        bool outsideFace = false;

        for (uint32_t edgeIndex = 0; edgeIndex < 3u; ++edgeIndex) {
            const GmVec3& edgeStart = *vertices[edgeIndex];
            const GmVec3& edgeEnd = *vertices[(edgeIndex + 1u) % 3u];
            GmVec3 edgeDirection = edgeEnd - edgeStart;
            const float edgeLengthSquared =
                GmVec3::Dot(edgeDirection, edgeDirection);
            if (edgeLengthSquared >
                TmForeverPhysicsConstants::kCollisionNormalizeSquaredEpsilon) {
                edgeDirection *= 1.0f / std::sqrt(edgeLengthSquared);
            }

            const GmVec3 outsideNormal =
                GmVec3::Cross(edgeDirection, faceNormal);
            const float outsideDistance =
                GmVec3::Dot(projected - edgeStart, outsideNormal);
            if (outsideDistance > crossSectionRadius) {
                outsideFace = true;
                break;
            }
            if (outsideDistance <= 0.0f) continue;

            outsideFace = true;
            const float distanceFromStart =
                GmVec3::Dot(projected - edgeStart, edgeDirection);
            const float distanceFromEnd =
                GmVec3::Dot(projected - edgeEnd, edgeDirection);
            GmVec3 closestPoint;
            float squaredDistanceEpsilon;
            if (distanceFromStart >= 0.0f && distanceFromEnd <= 0.0f) {
                closestPoint =
                    projected - outsideNormal * outsideDistance;
                squaredDistanceEpsilon =
                    TmForeverPhysicsConstants::
                        kCollisionEdgeSquaredDistanceEpsilon;
            } else if (distanceFromStart < 0.0f) {
                closestPoint = edgeStart;
                squaredDistanceEpsilon =
                    TmForeverPhysicsConstants::
                        kCollisionNormalizeSquaredEpsilon;
            } else {
                closestPoint = edgeEnd;
                squaredDistanceEpsilon =
                    TmForeverPhysicsConstants::
                        kCollisionNormalizeSquaredEpsilon;
            }

            foundCollision = AddSphereMeshEdgeCollision(
                sphereCenter, radius, sphere->m_flags, faceNormal,
                triangle.materialId, closestPoint, squaredDistanceEpsilon,
                locatedMesh->m_location, *buffer) || foundCollision;
            break;
        }

        if (outsideFace || planeDistance <= 0.0f) continue;

        GmCollision* collision = buffer->AddCollision();
        collision->m_vec1 =
            faceNormal * (planeDistance - radius);
        collision->m_vec2 = faceNormal;
        collision->m_vec3 = projected;
        collision->m_id1 = sphere->m_flags;
        collision->m_id2 = triangle.materialId;
        SetCollisionFeatureFlag(*collision, 1u);
        collision->m_vec4 = faceNormal;
        TransformMeshCollisionToWorld(
            *collision, locatedMesh->m_location);
        foundCollision = true;
    }

    return foundCollision ? 1 : 0;
}
int GmCollision_Ellipsoid_Ellipsoid(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Polygon(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Box(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Box_Box(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Box_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Mesh_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
