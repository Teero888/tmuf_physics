#include "GmSurf.hpp"
#include "GmCollision.hpp"
#include "TmForeverPhysicsConstants.hpp"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

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

bool AddSphereTriangleCollision(
    const GmVec3& sphereCenter,
    float sphereRadius,
    uint16_t sphereFlags,
    const GmVec3& first,
    const GmVec3& second,
    const GmVec3& third,
    const GmVec3& faceNormal,
    uint16_t materialId,
    const GmIso4& meshLocation,
    CGmCollisionBuffer& buffer) {
    const float planeDistance =
        GmVec3::Dot(sphereCenter - first, faceNormal);

    // Native mesh contacts are one-sided. A sphere whose center is behind
    // the face, or farther than its radius in front, cannot collide.
    if (planeDistance < 0.0f || planeDistance > sphereRadius) return false;

    const float crossSectionSquared =
        sphereRadius * sphereRadius - planeDistance * planeDistance;
    const float crossSectionRadius = std::sqrt(
        std::max(0.0f, crossSectionSquared));
    const GmVec3 projected =
        sphereCenter - faceNormal * planeDistance;
    const GmVec3* vertices[3] = {&first, &second, &third};

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
        if (outsideDistance > crossSectionRadius) return false;
        if (outsideDistance <= 0.0f) continue;

        const float distanceFromStart =
            GmVec3::Dot(projected - edgeStart, edgeDirection);
        const float distanceFromEnd =
            GmVec3::Dot(projected - edgeEnd, edgeDirection);
        GmVec3 closestPoint;
        float squaredDistanceEpsilon;
        if (distanceFromStart >= 0.0f && distanceFromEnd <= 0.0f) {
            closestPoint = projected - outsideNormal * outsideDistance;
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

        return AddSphereMeshEdgeCollision(
            sphereCenter, sphereRadius, sphereFlags, faceNormal, materialId,
            closestPoint, squaredDistanceEpsilon, meshLocation, buffer);
    }

    if (planeDistance <= 0.0f) return false;

    GmCollision* collision = buffer.AddCollision();
    collision->m_vec1 = faceNormal * (planeDistance - sphereRadius);
    collision->m_vec2 = faceNormal;
    collision->m_vec3 = projected;
    collision->m_id1 = sphereFlags;
    collision->m_id2 = materialId;
    SetCollisionFeatureFlag(*collision, 1u);
    collision->m_vec4 = faceNormal;
    TransformMeshCollisionToWorld(*collision, meshLocation);
    return true;
}

bool TriangleProjectionOverlapsCenteredBox(
    const GmVec3& axis,
    const GmVec3& first,
    const GmVec3& second,
    const GmVec3& third,
    const GmVec3& boxExtents) {
    const float firstProjection = GmVec3::Dot(axis, first);
    const float secondProjection = GmVec3::Dot(axis, second);
    const float thirdProjection = GmVec3::Dot(axis, third);
    const float minimumProjection = std::min(
        firstProjection, std::min(secondProjection, thirdProjection));
    const float maximumProjection = std::max(
        firstProjection, std::max(secondProjection, thirdProjection));
    const float boxRadius =
        std::fabs(axis.x) * boxExtents.x +
        std::fabs(axis.y) * boxExtents.y +
        std::fabs(axis.z) * boxExtents.z;
    return minimumProjection <= boxRadius &&
           -boxRadius <= maximumProjection;
}

bool TriangleIntersectsCenteredBox(
    const GmVec3& first,
    const GmVec3& second,
    const GmVec3& third,
    const GmVec3& boxExtents) {
    const GmVec3 boxAxes[3] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 1.0f, 0.0f},
        {0.0f, 0.0f, 1.0f},
    };
    for (const GmVec3& axis : boxAxes) {
        if (!TriangleProjectionOverlapsCenteredBox(
                axis, first, second, third, boxExtents)) {
            return false;
        }
    }

    const GmVec3 edges[3] = {
        second - first,
        third - second,
        first - third,
    };
    const GmVec3 triangleNormal = GmVec3::Cross(edges[0], edges[1]);
    if (!TriangleProjectionOverlapsCenteredBox(
            triangleNormal, first, second, third, boxExtents)) {
        return false;
    }

    for (const GmVec3& edge : edges) {
        for (const GmVec3& boxAxis : boxAxes) {
            if (!TriangleProjectionOverlapsCenteredBox(
                    GmVec3::Cross(edge, boxAxis),
                    first, second, third, boxExtents)) {
                return false;
            }
        }
    }
    return true;
}

float VectorComponent(const GmVec3& vector, uint32_t component) {
    return (&vector.x)[component];
}

bool CoplanarEdgeIntersects(
    const GmVec3& firstStart,
    const GmVec3& firstEnd,
    const GmVec3& secondStart,
    const GmVec3& secondEnd,
    uint32_t firstComponent,
    uint32_t secondComponent) {
    const float firstX =
        VectorComponent(firstEnd, firstComponent) -
        VectorComponent(firstStart, firstComponent);
    const float firstY =
        VectorComponent(firstEnd, secondComponent) -
        VectorComponent(firstStart, secondComponent);
    const float secondX =
        VectorComponent(secondStart, firstComponent) -
        VectorComponent(secondEnd, firstComponent);
    const float secondY =
        VectorComponent(secondStart, secondComponent) -
        VectorComponent(secondEnd, secondComponent);
    const float offsetX =
        VectorComponent(firstStart, firstComponent) -
        VectorComponent(secondStart, firstComponent);
    const float offsetY =
        VectorComponent(firstStart, secondComponent) -
        VectorComponent(secondStart, secondComponent);
    const float denominator = firstY * secondX - firstX * secondY;
    const float firstNumerator = secondY * offsetX - secondX * offsetY;

    if ((denominator > 0.0f &&
         firstNumerator >= 0.0f && firstNumerator <= denominator) ||
        (denominator < 0.0f &&
         firstNumerator <= 0.0f && firstNumerator >= denominator)) {
        const float secondNumerator =
            firstX * offsetY - firstY * offsetX;
        if ((denominator > 0.0f &&
             secondNumerator >= 0.0f && secondNumerator <= denominator) ||
            (denominator < 0.0f &&
             secondNumerator <= 0.0f && secondNumerator >= denominator)) {
            return true;
        }
    }
    return false;
}

bool CoplanarPointIsInsideTriangle(
    const GmVec3& point,
    const GmVec3& first,
    const GmVec3& second,
    const GmVec3& third,
    uint32_t firstComponent,
    uint32_t secondComponent) {
    const GmVec3* vertices[3] = {&first, &second, &third};
    float side[3];
    for (uint32_t edge = 0; edge < 3u; ++edge) {
        const GmVec3& start = *vertices[edge];
        const GmVec3& end = *vertices[(edge + 1u) % 3u];
        const float a =
            VectorComponent(end, secondComponent) -
            VectorComponent(start, secondComponent);
        const float b = -(
            VectorComponent(end, firstComponent) -
            VectorComponent(start, firstComponent));
        const float c =
            -a * VectorComponent(start, firstComponent) -
            b * VectorComponent(start, secondComponent);
        side[edge] =
            a * VectorComponent(point, firstComponent) +
            b * VectorComponent(point, secondComponent) + c;
    }
    return side[0] * side[1] > 0.0f &&
           side[0] * side[2] > 0.0f;
}

bool CoplanarTrianglesIntersect(
    const GmVec3& normal,
    const GmVec3& firstA,
    const GmVec3& secondA,
    const GmVec3& thirdA,
    const GmVec3& firstB,
    const GmVec3& secondB,
    const GmVec3& thirdB) {
    const float absoluteNormal[3] = {
        std::fabs(normal.x),
        std::fabs(normal.y),
        std::fabs(normal.z),
    };
    uint32_t omittedComponent = 0u;
    if (absoluteNormal[1] > absoluteNormal[omittedComponent]) {
        omittedComponent = 1u;
    }
    if (absoluteNormal[2] > absoluteNormal[omittedComponent]) {
        omittedComponent = 2u;
    }
    const uint32_t firstComponent = (omittedComponent + 1u) % 3u;
    const uint32_t secondComponent = (omittedComponent + 2u) % 3u;
    const GmVec3* verticesA[3] = {&firstA, &secondA, &thirdA};
    const GmVec3* verticesB[3] = {&firstB, &secondB, &thirdB};

    // This is the exact edge/containment scheme used by GmCoplanarTriTri at
    // 0x008ef3d0, including its strict interior point comparisons.
    for (uint32_t edgeA = 0; edgeA < 3u; ++edgeA) {
        for (uint32_t edgeB = 0; edgeB < 3u; ++edgeB) {
            if (CoplanarEdgeIntersects(
                    *verticesA[edgeA], *verticesA[(edgeA + 1u) % 3u],
                    *verticesB[edgeB], *verticesB[(edgeB + 1u) % 3u],
                    firstComponent, secondComponent)) {
                return true;
            }
        }
    }
    return CoplanarPointIsInsideTriangle(
               firstA, firstB, secondB, thirdB,
               firstComponent, secondComponent) ||
           CoplanarPointIsInsideTriangle(
               firstB, firstA, secondA, thirdA,
               firstComponent, secondComponent);
}

struct TriangleIntersectionInterval {
    float a;
    float b;
    float c;
    float x0;
    float x1;
};

bool ComputeTriangleIntersectionInterval(
    float vertex0,
    float vertex1,
    float vertex2,
    float distance0,
    float distance1,
    float distance2,
    float distance0Distance1,
    float distance0Distance2,
    TriangleIntersectionInterval& interval) {
    if (distance0Distance1 > 0.0f) {
        interval.a = vertex2;
        interval.b = (vertex0 - vertex2) * distance2;
        interval.c = (vertex1 - vertex2) * distance2;
        interval.x0 = distance2 - distance0;
        interval.x1 = distance2 - distance1;
    } else if (distance0Distance2 > 0.0f) {
        interval.a = vertex1;
        interval.b = (vertex0 - vertex1) * distance1;
        interval.c = (vertex2 - vertex1) * distance1;
        interval.x0 = distance1 - distance0;
        interval.x1 = distance1 - distance2;
    } else if (distance1 * distance2 > 0.0f || distance0 != 0.0f) {
        interval.a = vertex0;
        interval.b = (vertex1 - vertex0) * distance0;
        interval.c = (vertex2 - vertex0) * distance0;
        interval.x0 = distance0 - distance1;
        interval.x1 = distance0 - distance2;
    } else if (distance1 != 0.0f) {
        interval.a = vertex1;
        interval.b = (vertex0 - vertex1) * distance1;
        interval.c = (vertex2 - vertex1) * distance1;
        interval.x0 = distance1 - distance0;
        interval.x1 = distance1 - distance2;
    } else if (distance2 != 0.0f) {
        interval.a = vertex2;
        interval.b = (vertex0 - vertex2) * distance2;
        interval.c = (vertex1 - vertex2) * distance2;
        interval.x0 = distance2 - distance0;
        interval.x1 = distance2 - distance1;
    } else {
        return false;
    }
    return true;
}

bool TrianglesIntersect(
    const GmVec3& firstA,
    const GmVec3& secondA,
    const GmVec3& thirdA,
    const GmVec3& firstB,
    const GmVec3& secondB,
    const GmVec3& thirdB) {
    const GmVec3 edgeA0 = secondA - firstA;
    const GmVec3 edgeA1 = thirdA - firstA;
    const GmVec3 normalA = GmVec3::Cross(edgeA0, edgeA1);
    const float planeConstantA = -GmVec3::Dot(normalA, firstA);
    const float distanceB0 = GmVec3::Dot(normalA, firstB) + planeConstantA;
    const float distanceB1 = GmVec3::Dot(normalA, secondB) + planeConstantA;
    const float distanceB2 = GmVec3::Dot(normalA, thirdB) + planeConstantA;
    const float distanceB0DistanceB1 = distanceB0 * distanceB1;
    const float distanceB0DistanceB2 = distanceB0 * distanceB2;
    if (distanceB0DistanceB1 > 0.0f &&
        distanceB0DistanceB2 > 0.0f) {
        return false;
    }

    const GmVec3 edgeB0 = secondB - firstB;
    const GmVec3 edgeB1 = thirdB - firstB;
    const GmVec3 normalB = GmVec3::Cross(edgeB0, edgeB1);
    const float planeConstantB = -GmVec3::Dot(normalB, firstB);
    const float distanceA0 = GmVec3::Dot(normalB, firstA) + planeConstantB;
    const float distanceA1 = GmVec3::Dot(normalB, secondA) + planeConstantB;
    const float distanceA2 = GmVec3::Dot(normalB, thirdA) + planeConstantB;
    const float distanceA0DistanceA1 = distanceA0 * distanceA1;
    const float distanceA0DistanceA2 = distanceA0 * distanceA2;
    if (distanceA0DistanceA1 > 0.0f &&
        distanceA0DistanceA2 > 0.0f) {
        return false;
    }

    const GmVec3 intersectionDirection = GmVec3::Cross(normalA, normalB);
    const float absoluteDirection[3] = {
        std::fabs(intersectionDirection.x),
        std::fabs(intersectionDirection.y),
        std::fabs(intersectionDirection.z),
    };
    uint32_t projectionComponent = 0u;
    if (absoluteDirection[1] > absoluteDirection[projectionComponent]) {
        projectionComponent = 1u;
    }
    if (absoluteDirection[2] > absoluteDirection[projectionComponent]) {
        projectionComponent = 2u;
    }

    TriangleIntersectionInterval intervalA{};
    TriangleIntersectionInterval intervalB{};
    if (!ComputeTriangleIntersectionInterval(
            VectorComponent(firstA, projectionComponent),
            VectorComponent(secondA, projectionComponent),
            VectorComponent(thirdA, projectionComponent),
            distanceA0, distanceA1, distanceA2,
            distanceA0DistanceA1, distanceA0DistanceA2, intervalA) ||
        !ComputeTriangleIntersectionInterval(
            VectorComponent(firstB, projectionComponent),
            VectorComponent(secondB, projectionComponent),
            VectorComponent(thirdB, projectionComponent),
            distanceB0, distanceB1, distanceB2,
            distanceB0DistanceB1, distanceB0DistanceB2, intervalB)) {
        return CoplanarTrianglesIntersect(
            normalA, firstA, secondA, thirdA, firstB, secondB, thirdB);
    }

    const float xx = intervalA.x0 * intervalA.x1;
    const float yy = intervalB.x0 * intervalB.x1;
    const float xxyy = xx * yy;
    const float commonA = intervalA.a * xxyy;
    float intersectionA0 =
        commonA + intervalA.b * intervalA.x1 * yy;
    float intersectionA1 =
        commonA + intervalA.c * intervalA.x0 * yy;
    const float commonB = intervalB.a * xxyy;
    float intersectionB0 =
        commonB + intervalB.b * xx * intervalB.x1;
    float intersectionB1 =
        commonB + intervalB.c * xx * intervalB.x0;
    if (intersectionA0 > intersectionA1) {
        std::swap(intersectionA0, intersectionA1);
    }
    if (intersectionB0 > intersectionB1) {
        std::swap(intersectionB0, intersectionB1);
    }
    return intersectionA1 >= intersectionB0 &&
           intersectionB1 >= intersectionA0;
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

int GmSurf::ClipSegment(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmIso4& transform,
    float& outT,
    GmVec3& outNormal) {
    if (m_type == 0u) {
        return static_cast<GmSurfSphere*>(this)->ClipSegment(
            rayPos, rayDir,
            GmVec3(transform.tX, transform.tY, transform.tZ), outT);
    }
    if (m_type == 7u) {
        return static_cast<GmSurfMesh*>(this)->ClipSegment(
            rayPos, rayDir, transform, outT);
    }
    return 0;
}

int GmSurf::ClipSegment2(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmIso4& transform,
    float& outT,
    GmVec3& outNormal) {
    if (m_type != 7u) return 0;
    return static_cast<GmSurfMesh*>(this)->ClipSegment2(
        rayPos, rayDir, transform, outT, outNormal);
}

int GmSurf::ClipSegment3(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmIso4& transform,
    float& outT,
    uint16_t& outId) {
    if (m_type == 0u) {
        outId = m_flags;
        return static_cast<GmSurfSphere*>(this)->ClipSegment(
            rayPos, rayDir,
            GmVec3(transform.tX, transform.tY, transform.tZ), outT);
    }
    if (m_type == 7u) {
        return static_cast<GmSurfMesh*>(this)->ClipSegment3(
            rayPos, rayDir, transform, outT, outId);
    }
    return 0;
}

// External collision function prototypes
extern int GmCollision_Sphere_Sphere(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Polygon(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
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

    g_GmCollisionMatrix[1][5] = g_GmCollisionMatrix[5][1] = GmCollision_Ellipsoid_Polygon;
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
    // Native dispatcher at 0x008e8a70 intentionally leaves the destination
    // untouched for polygon and unsupported surface types.
    switch (m_type) {
    case 0:
        static_cast<const GmSurfSphere*>(this)->GetSphereBoundingBox(outBox);
        return;
    case 1:
        static_cast<const GmSurfEllipsoid*>(this)->GetEllipsoidBoundingBox(outBox);
        return;
    case 6: {
        const GmSurfBox* box = static_cast<const GmSurfBox*>(this);
        outBox.center = box->m_center;
        outBox.extents = box->m_extents;
        return;
    }
    case 7:
        static_cast<const GmSurfMesh*>(this)->GetMeshBoundingBox(outBox);
        return;
    default:
        return;
    }
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

int GmSurfSphere::ClipSegment(
    const GmVec3& rayPos,
    const GmVec3& rayDir,
    const GmVec3& center,
    float& outT) {
    const GmVec3 delta = rayPos - center;
    const float projection = GmVec3::Dot(delta, rayDir);
    const float directionSquared = GmVec3::Dot(rayDir, rayDir);
    const float discriminant =
        projection * projection -
        (GmVec3::Dot(delta, delta) - m_radius * m_radius) *
            directionSquared;
    if (discriminant < 0.0f || directionSquared == 0.0f) return 0;
    const float hitT =
        (-projection - std::sqrt(discriminant)) / directionSquared;
    if (hitT < 0.0f || hitT > 1.0f) return 0;
    outT = hitT;
    return 1;
}

void GmSurfSphere::GetSphereBoundingBox(GmBoxAligned& outBox) const {
    outBox.center = {0.0f, 0.0f, 0.0f};
    outBox.extents = {m_radius, m_radius, m_radius};
}

void GmSurfEllipsoid::CreateEllipsoidDefaultData() {
    m_radii = {1.0f, 1.0f, 1.0f};
}

void GmSurfEllipsoid::GetEllipsoidBoundingBox(GmBoxAligned& outBox) const {
    outBox.center = {0.0f, 0.0f, 0.0f};
    outBox.extents = m_radii;
}

void GmSurf::CreateDefaultData(CCrystal*) {
    switch (m_type) {
    case 0:
        static_cast<GmSurfSphere*>(this)->m_radius = 1.0f;
        return;
    case 1:
        static_cast<GmSurfEllipsoid*>(this)->CreateEllipsoidDefaultData();
        return;
    case 6: {
        GmSurfBox* box = static_cast<GmSurfBox*>(this);
        box->m_center = {0.0f, 0.0f, 0.0f};
        box->m_extents = {
            TmForeverPhysicsConstants::kPlaneSolveAxisThreshold,
            TmForeverPhysicsConstants::kPlaneSolveAxisThreshold,
            TmForeverPhysicsConstants::kPlaneSolveAxisThreshold,
        };
        return;
    }
    default:
        return;
    }
}

// GmSurfPolygon (Type 5)
GmSurfPolygon::GmSurfPolygon(uint8_t param) {
    m_type = 5;
    m_numVertices = param;
    m_unknown_0x48 = 0;
}
GmSurfPolygon::~GmSurfPolygon() {}

void GmSurfPolygon::ComputeNormalFromVertices() {
    const GmVec3 firstEdge = m_vertices[1] - m_vertices[0];
    const GmVec3 secondEdge = m_vertices[2] - m_vertices[0];
    m_planeNormal = GmVec3::Cross(firstEdge, secondEdge);
    const float squaredLength = GmVec3::Dot(m_planeNormal, m_planeNormal);
    if (squaredLength <
        TmForeverPhysicsConstants::kPolygonNormalSquaredEpsilon) {
        m_planeNormal = {1.0f, 0.0f, 0.0f};
        return;
    }
    m_planeNormal *= 1.0f / std::sqrt(squaredLength);
}

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
int GmCollision_Sphere_Ellipsoid(
    LocatedGmSurf* locatedSphere,
    LocatedGmSurf* locatedEllipsoid,
    CGmCollisionBuffer* buffer) {
    GmSurfSphere* sphere =
        static_cast<GmSurfSphere*>(locatedSphere->m_surf);
    GmSurfEllipsoid* ellipsoid =
        static_cast<GmSurfEllipsoid*>(locatedEllipsoid->m_surf);

    // 0x008e9130 constructs a temporary sphere whose radius is the largest
    // ellipsoid radius. Orientation and the two smaller radii deliberately do
    // not participate in this native pair test.
    const float ellipsoidRadius = std::max(
        ellipsoid->m_radii.x,
        std::max(ellipsoid->m_radii.y, ellipsoid->m_radii.z));
    const GmVec3 sphereCenter{
        locatedSphere->m_location.tX,
        locatedSphere->m_location.tY,
        locatedSphere->m_location.tZ,
    };
    const GmVec3 ellipsoidCenter{
        locatedEllipsoid->m_location.tX,
        locatedEllipsoid->m_location.tY,
        locatedEllipsoid->m_location.tZ,
    };
    const GmVec3 delta = ellipsoidCenter - sphereCenter;
    const float distanceSquared = GmVec3::Dot(delta, delta);
    const float radiusSum = sphere->m_radius + ellipsoidRadius;
    if (!(distanceSquared < radiusSum * radiusSum)) return 0;

    const float distance = std::sqrt(distanceSquared);
    GmCollision* collision = buffer->AddCollision();
    if (distance <= TmForeverPhysicsConstants::kCoincidentSurfaceEpsilon) {
        // The native branch multiplies radiusSum by the zero double at
        // 0x00b2c178, leaving the replacement vector at zero.
        collision->m_vec1 = {0.0f, 0.0f, 0.0f};
        collision->m_vec2 = {0.0f, -1.0f, 0.0f};
        collision->m_vec3 = sphereCenter;
    } else {
        const GmVec3 direction = delta * (1.0f / distance);
        collision->m_vec1 = direction * (radiusSum - distance);
        collision->m_vec2 = direction * -1.0f;
        collision->m_vec3 =
            sphereCenter + direction * sphere->m_radius;
    }
    collision->m_id1 = sphere->m_flags;
    collision->m_id2 = ellipsoid->m_flags;
    return 1;
}

int GmCollision_Sphere_Polygon(
    LocatedGmSurf* locatedSphere,
    LocatedGmSurf* locatedPolygon,
    CGmCollisionBuffer* buffer) {
    GmSurfSphere* sphere =
        static_cast<GmSurfSphere*>(locatedSphere->m_surf);
    GmSurfPolygon* polygon =
        static_cast<GmSurfPolygon*>(locatedPolygon->m_surf);
    if (polygon->m_numVertices == 0u) return 0;

    const GmVec3 worldSphereCenter{
        locatedSphere->m_location.tX,
        locatedSphere->m_location.tY,
        locatedSphere->m_location.tZ,
    };
    const GmVec3 sphereCenter =
        locatedPolygon->m_location.UnTransform(worldSphereCenter);
    const GmVec3& faceNormal = polygon->m_planeNormal;
    const float radius = sphere->m_radius;
    const float planeDistance =
        GmVec3::Dot(sphereCenter - polygon->m_vertices[0], faceNormal);

    // The native polygon can optionally collide from behind. Unlike mesh
    // triangles, its back-face response is preserved below when 0x48 is set.
    if (planeDistance > radius ||
        (planeDistance < 0.0f && polygon->m_unknown_0x48 == 0)) {
        return 0;
    }

    const float crossSectionRadius = std::sqrt(
        std::max(0.0f, radius * radius - planeDistance * planeDistance));
    const GmVec3 projected =
        sphereCenter - faceNormal * planeDistance;

    for (uint32_t edgeIndex = 0;
         edgeIndex < polygon->m_numVertices;
         ++edgeIndex) {
        const uint32_t nextIndex =
            edgeIndex + 1u == polygon->m_numVertices ? 0u : edgeIndex + 1u;
        const GmVec3& edgeStart = polygon->m_vertices[edgeIndex];
        const GmVec3& edgeEnd = polygon->m_vertices[nextIndex];
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
        if (outsideDistance > crossSectionRadius) return 0;

        // A back-face collision is generated only through the face interior.
        if (planeDistance < 0.0f && outsideDistance > 0.0f) return 0;
        if (outsideDistance <= 0.0f) continue;

        const float distanceFromStart =
            GmVec3::Dot(projected - edgeStart, edgeDirection);
        const float distanceFromEnd =
            GmVec3::Dot(projected - edgeEnd, edgeDirection);
        GmVec3 closestPoint;
        if (distanceFromStart < 0.0f) {
            closestPoint = edgeStart;
        } else if (distanceFromEnd > 0.0f) {
            closestPoint = edgeEnd;
        } else {
            closestPoint =
                projected - outsideNormal * outsideDistance;
        }

        const GmVec3 delta = sphereCenter - closestPoint;
        const float distance = std::sqrt(GmVec3::Dot(delta, delta));
        if (distance > radius) return 0;

        // 0x008e9792/0x008e9911/0x008e9a56 retain the polygon's plane
        // normal as vec2 even for edge and vertex contacts. Only the normal
        // component of the radial replacement is stored in vec1.
        const GmVec3 rawReplacement =
            delta * ((distance - radius) / distance);
        GmCollision* collision = buffer->AddCollision();
        collision->m_vec1 =
            faceNormal * GmVec3::Dot(rawReplacement, faceNormal);
        collision->m_vec2 = faceNormal;
        collision->m_vec3 = closestPoint;
        collision->m_id1 = sphere->m_flags;
        collision->m_id2 = polygon->m_flags;
        collision->m_vec1 = TransformVector(
            locatedPolygon->m_location, collision->m_vec1);
        collision->m_vec2 = TransformVector(
            locatedPolygon->m_location, collision->m_vec2);
        collision->m_vec3 = TransformPoint(
            locatedPolygon->m_location, collision->m_vec3);
        return 1;
    }

    GmCollision* collision = buffer->AddCollision();
    if (planeDistance <= 0.0f) {
        collision->m_vec2 = faceNormal * -1.0f;
    } else {
        collision->m_vec2 = faceNormal;
    }
    collision->m_vec1 = faceNormal * (planeDistance - radius);
    collision->m_vec3 = projected;
    collision->m_id1 = sphere->m_flags;
    collision->m_id2 = polygon->m_flags;
    collision->m_vec1 = TransformVector(
        locatedPolygon->m_location, collision->m_vec1);
    collision->m_vec2 = TransformVector(
        locatedPolygon->m_location, collision->m_vec2);
    collision->m_vec3 = TransformPoint(
        locatedPolygon->m_location, collision->m_vec3);
    return 1;
}
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
        foundCollision = AddSphereTriangleCollision(
            sphereCenter, radius, sphere->m_flags, first, second, third,
            triangle.planeNormal, triangle.materialId,
            locatedMesh->m_location, *buffer) || foundCollision;
    }

    return foundCollision ? 1 : 0;
}
int GmCollision_Ellipsoid_Polygon(
    LocatedGmSurf* locatedEllipsoid,
    LocatedGmSurf* locatedPolygon,
    CGmCollisionBuffer* buffer) {
    GmSurfEllipsoid* ellipsoid =
        static_cast<GmSurfEllipsoid*>(locatedEllipsoid->m_surf);
    GmSurfPolygon* polygon =
        static_cast<GmSurfPolygon*>(locatedPolygon->m_surf);

    // Native 0x008e9c50 first performs a cheap plane rejection with a sphere
    // using the largest ellipsoid radius, before constructing scaled geometry.
    const GmVec3 ellipsoidCenter{
        locatedEllipsoid->m_location.tX,
        locatedEllipsoid->m_location.tY,
        locatedEllipsoid->m_location.tZ,
    };
    const GmVec3 polygonLocalCenter =
        locatedPolygon->m_location.UnTransform(ellipsoidCenter);
    const float planeDistance = GmVec3::Dot(
        polygonLocalCenter - polygon->m_vertices[0], polygon->m_planeNormal);
    const float maximumRadius = std::max(
        ellipsoid->m_radii.x,
        std::max(ellipsoid->m_radii.y, ellipsoid->m_radii.z));
    if (planeDistance > maximumRadius ||
        (planeDistance < 0.0f && polygon->m_unknown_0x48 == 0)) {
        return 0;
    }

    // Map the original polygon into the unit sphere's coordinates:
    // S^-1 * E^-1 * P, where E and P are the two located transforms.
    GmIso4 relative = locatedPolygon->m_location;
    relative.MultInverse(locatedEllipsoid->m_location);
    GmIso4 sphereSpace = relative;
    const float inverseRadiusX = 1.0f / ellipsoid->m_radii.x;
    const float inverseRadiusY = 1.0f / ellipsoid->m_radii.y;
    const float inverseRadiusZ = 1.0f / ellipsoid->m_radii.z;
    sphereSpace.m00 *= inverseRadiusX;
    sphereSpace.m01 *= inverseRadiusX;
    sphereSpace.m02 *= inverseRadiusX;
    sphereSpace.tX *= inverseRadiusX;
    sphereSpace.m10 *= inverseRadiusY;
    sphereSpace.m11 *= inverseRadiusY;
    sphereSpace.m12 *= inverseRadiusY;
    sphereSpace.tY *= inverseRadiusY;
    sphereSpace.m20 *= inverseRadiusZ;
    sphereSpace.m21 *= inverseRadiusZ;
    sphereSpace.m22 *= inverseRadiusZ;
    sphereSpace.tZ *= inverseRadiusZ;

    GmSurfPolygon scaledPolygon(polygon->m_numVertices);
    for (uint32_t index = 0; index < polygon->m_numVertices; ++index) {
        scaledPolygon.m_vertices[index] =
            TransformPoint(sphereSpace, polygon->m_vertices[index]);
    }
    scaledPolygon.ComputeNormalFromVertices();
    scaledPolygon.m_flags = polygon->m_flags;
    scaledPolygon.m_unknown_0x48 = polygon->m_unknown_0x48;

    GmSurfSphere unitSphere;
    unitSphere.m_radius = 1.0f;
    unitSphere.m_flags = ellipsoid->m_flags;
    LocatedGmSurf locatedUnitSphere{};
    LocatedGmSurf locatedScaledPolygon{};
    locatedUnitSphere.m_surf = &unitSphere;
    locatedScaledPolygon.m_surf = &scaledPolygon;
    locatedUnitSphere.m_location.SetIdentity();
    locatedScaledPolygon.m_location.SetIdentity();

    const uint32_t firstNewCollision = buffer->GetCount();
    const int result = GmCollision_Sphere_Polygon(
        &locatedUnitSphere, &locatedScaledPolygon, buffer);
    if (result == 0) return 0;

    const GmVec3 zero{0.0f, 0.0f, 0.0f};
    GmIso4 positionAndReplacementTransform;
    positionAndReplacementTransform.SetNUScaleTrans(
        ellipsoid->m_radii, zero);
    positionAndReplacementTransform.MultInverse(relative);

    GmIso4 normalTransform;
    normalTransform.SetNUScaleTrans(
        {inverseRadiusX, inverseRadiusY, inverseRadiusZ}, zero);
    normalTransform.MultInverse(relative);

    const uint32_t collisionCount = buffer->GetCount();
    for (uint32_t index = firstNewCollision;
         index < collisionCount;
         ++index) {
        GmCollision* collision = buffer->GetCollision(index);
        collision->m_vec3 = TransformPoint(
            positionAndReplacementTransform, collision->m_vec3);
        collision->m_vec2 = TransformVector(
            normalTransform, collision->m_vec2);
        const float normalSquaredLength =
            GmVec3::Dot(collision->m_vec2, collision->m_vec2);
        if (normalSquaredLength >
            TmForeverPhysicsConstants::kCollisionNormalizeSquaredEpsilon) {
            collision->m_vec2 *= 1.0f / std::sqrt(normalSquaredLength);
        }
        collision->m_vec1 = TransformVector(
            positionAndReplacementTransform, collision->m_vec1);
        collision->m_vec4 = TransformVector(
            normalTransform, collision->m_vec4);
        const float auxiliaryNormalSquaredLength =
            GmVec3::Dot(collision->m_vec4, collision->m_vec4);
        if (auxiliaryNormalSquaredLength >
            TmForeverPhysicsConstants::kCollisionNormalizeSquaredEpsilon) {
            collision->m_vec4 *=
                1.0f / std::sqrt(auxiliaryNormalSquaredLength);
        }
    }
    return result;
}
int GmCollision_Ellipsoid_Mesh(
    LocatedGmSurf* locatedEllipsoid,
    LocatedGmSurf* locatedMesh,
    CGmCollisionBuffer* buffer) {
    GmSurfEllipsoid* ellipsoid =
        static_cast<GmSurfEllipsoid*>(locatedEllipsoid->m_surf);
    GmSurfMesh* mesh = static_cast<GmSurfMesh*>(locatedMesh->m_surf);
    const GmVec3& radii = ellipsoid->m_radii;
    const GmVec3 inverseRadii{
        1.0f / radii.x,
        1.0f / radii.y,
        1.0f / radii.z,
    };

    // 0x008eaf24-0x008eb055 maps each candidate mesh triangle through
    // S^-1 * E^-1 * P and performs the native unit-sphere triangle test.
    GmIso4 meshToEllipsoid = locatedMesh->m_location;
    meshToEllipsoid.MultInverse(locatedEllipsoid->m_location);
    GmIso4 sphereSpace = meshToEllipsoid;
    sphereSpace.m00 *= inverseRadii.x;
    sphereSpace.m01 *= inverseRadii.x;
    sphereSpace.m02 *= inverseRadii.x;
    sphereSpace.tX *= inverseRadii.x;
    sphereSpace.m10 *= inverseRadii.y;
    sphereSpace.m11 *= inverseRadii.y;
    sphereSpace.m12 *= inverseRadii.y;
    sphereSpace.tY *= inverseRadii.y;
    sphereSpace.m20 *= inverseRadii.z;
    sphereSpace.m21 *= inverseRadii.z;
    sphereSpace.m22 *= inverseRadii.z;
    sphereSpace.tZ *= inverseRadii.z;

    GmIso4 identity;
    identity.SetIdentity();
    const GmVec3 unitSphereCenter{0.0f, 0.0f, 0.0f};
    const uint32_t firstNewCollision = buffer->GetCount();
    bool foundCollision = false;

    GmIso4 ellipsoidToMesh = locatedEllipsoid->m_location;
    ellipsoidToMesh.MultInverse(locatedMesh->m_location);
    GmBoxAligned ellipsoidLocalBounds;
    ellipsoid->GetEllipsoidBoundingBox(ellipsoidLocalBounds);
    GmBoxAligned meshLocalQueryBounds;
    meshLocalQueryBounds.SetMult(ellipsoidLocalBounds, ellipsoidToMesh);
    GmVec3 queryMinimum;
    GmVec3 queryMaximum;
    meshLocalQueryBounds.GetMinMax(queryMinimum, queryMaximum);
    std::vector<uint32_t> broadphaseCandidates;
    const bool hasBroadphase = mesh->GetAabbCandidates(
        queryMinimum.x, queryMinimum.z,
        queryMaximum.x, queryMaximum.z,
        broadphaseCandidates);

    // The native routine gets candidates from its mesh octree. The standalone
    // grid returns a conservative subset in deterministic face-buffer order.
    // It changes broadphase cost only; every overlapping XZ cell is included.
    const uint32_t candidateCount = hasBroadphase
        ? static_cast<uint32_t>(broadphaseCandidates.size())
        : mesh->m_triangles.m_count;
    for (uint32_t candidateIndex = 0u;
         candidateIndex < candidateCount; ++candidateIndex) {
        const uint32_t triangleIndex = hasBroadphase
            ? broadphaseCandidates[candidateIndex]
            : candidateIndex;
        const GmSurfTriangle& triangle = mesh->m_triangles[triangleIndex];
        if (triangle.indices[0] >= mesh->m_vertices.m_count ||
            triangle.indices[1] >= mesh->m_vertices.m_count ||
            triangle.indices[2] >= mesh->m_vertices.m_count) {
            continue;
        }

        const GmVec3 first = TransformPoint(
            sphereSpace, mesh->m_vertices[triangle.indices[0]]);
        const GmVec3 second = TransformPoint(
            sphereSpace, mesh->m_vertices[triangle.indices[1]]);
        const GmVec3 third = TransformPoint(
            sphereSpace, mesh->m_vertices[triangle.indices[2]]);
        GmVec3 faceNormal = GmVec3::Cross(second - first, third - first);
        const float normalSquaredLength =
            GmVec3::Dot(faceNormal, faceNormal);
        if (normalSquaredLength <=
            TmForeverPhysicsConstants::kCollisionNormalizeSquaredEpsilon) {
            continue;
        }
        faceNormal *= 1.0f / std::sqrt(normalSquaredLength);

        foundCollision = AddSphereTriangleCollision(
            unitSphereCenter, 1.0f, ellipsoid->m_flags,
            first, second, third, faceNormal, triangle.materialId,
            identity, *buffer) || foundCollision;
    }

    if (!foundCollision) return 0;

    // Native 0x008eb725-0x008eb80e simplifies to E*S for points and
    // replacements, and E*S^-1 for normals. It deliberately leaves vec4 in
    // the temporary sphere-space frame.
    const GmVec3 zero{0.0f, 0.0f, 0.0f};
    GmIso4 positionAndReplacementTransform;
    positionAndReplacementTransform.SetNUScaleTrans(radii, zero);
    positionAndReplacementTransform.Mult(locatedEllipsoid->m_location);
    GmIso4 normalTransform;
    normalTransform.SetNUScaleTrans(inverseRadii, zero);
    normalTransform.Mult(locatedEllipsoid->m_location);

    const uint32_t collisionCount = buffer->GetCount();
    for (uint32_t index = firstNewCollision;
         index < collisionCount;
         ++index) {
        GmCollision* collision = buffer->GetCollision(index);
        collision->m_vec3 = TransformPoint(
            positionAndReplacementTransform, collision->m_vec3);
        collision->m_vec2 = TransformVector(
            normalTransform, collision->m_vec2);
        const float normalSquaredLength =
            GmVec3::Dot(collision->m_vec2, collision->m_vec2);
        if (normalSquaredLength >
            TmForeverPhysicsConstants::kCollisionNormalizeSquaredEpsilon) {
            collision->m_vec2 *= 1.0f / std::sqrt(normalSquaredLength);
        }
        collision->m_vec1 = TransformVector(
            positionAndReplacementTransform, collision->m_vec1);
    }
    return 1;
}
int GmCollision_Box_Box(
    LocatedGmSurf* locatedA,
    LocatedGmSurf* locatedB,
    CGmCollisionBuffer* buffer) {
    GmSurfBox* boxA = static_cast<GmSurfBox*>(locatedA->m_surf);
    GmSurfBox* boxB = static_cast<GmSurfBox*>(locatedB->m_surf);

    // 0x008f4bc0 is the complete 15-axis separating-axis test. The relative
    // matrix maps B-local positions into A-local coordinates.
    GmIso4 relative = locatedB->m_location;
    relative.MultInverse(locatedA->m_location);
    const float rotation[3][3] = {
        {relative.m00, relative.m01, relative.m02},
        {relative.m10, relative.m11, relative.m12},
        {relative.m20, relative.m21, relative.m22},
    };
    float absoluteRotation[3][3];
    for (uint32_t row = 0; row < 3u; ++row) {
        for (uint32_t column = 0; column < 3u; ++column) {
            absoluteRotation[row][column] =
                std::fabs(rotation[row][column]);
        }
    }

    const GmVec3 transformedCenterB =
        TransformPoint(relative, boxB->m_center);
    const GmVec3 centerDelta = transformedCenterB - boxA->m_center;
    const float translation[3] = {
        centerDelta.x, centerDelta.y, centerDelta.z,
    };
    const float extentsA[3] = {
        boxA->m_extents.x, boxA->m_extents.y, boxA->m_extents.z,
    };
    const float extentsB[3] = {
        boxB->m_extents.x, boxB->m_extents.y, boxB->m_extents.z,
    };

    for (uint32_t axis = 0; axis < 3u; ++axis) {
        const float projectedRadiusB =
            absoluteRotation[axis][2] * extentsB[2] +
            absoluteRotation[axis][1] * extentsB[1] +
            absoluteRotation[axis][0] * extentsB[0];
        if (std::fabs(translation[axis]) >
            extentsA[axis] + projectedRadiusB) {
            return 0;
        }
    }

    for (uint32_t axis = 0; axis < 3u; ++axis) {
        const float projectedTranslation =
            rotation[2][axis] * translation[2] +
            rotation[1][axis] * translation[1] +
            rotation[0][axis] * translation[0];
        const float projectedRadiusA =
            absoluteRotation[2][axis] * extentsA[2] +
            absoluteRotation[1][axis] * extentsA[1] +
            absoluteRotation[0][axis] * extentsA[0];
        if (std::fabs(projectedTranslation) >
            extentsB[axis] + projectedRadiusA) {
            return 0;
        }
    }

    for (uint32_t axisA = 0; axisA < 3u; ++axisA) {
        const uint32_t nextA = (axisA + 1u) % 3u;
        const uint32_t lastA = (axisA + 2u) % 3u;
        for (uint32_t axisB = 0; axisB < 3u; ++axisB) {
            const uint32_t nextB = (axisB + 1u) % 3u;
            const uint32_t lastB = (axisB + 2u) % 3u;
            const float projectedTranslation = std::fabs(
                translation[lastA] * rotation[nextA][axisB] -
                translation[nextA] * rotation[lastA][axisB]);
            const float projectedRadiusA =
                extentsA[nextA] * absoluteRotation[lastA][axisB] +
                extentsA[lastA] * absoluteRotation[nextA][axisB];
            const float projectedRadiusB =
                extentsB[nextB] * absoluteRotation[axisA][lastB] +
                extentsB[lastB] * absoluteRotation[axisA][nextB];
            if (projectedTranslation >
                projectedRadiusA + projectedRadiusB) {
                return 0;
            }
        }
    }

    // The native handler reports only an overlap sentinel. It does not derive
    // a penetration axis: replacement is zero, normal is (1,1,1), and the
    // contact point is the first located transform's translation.
    GmCollision* collision = buffer->AddCollision();
    collision->m_vec1 = {0.0f, 0.0f, 0.0f};
    collision->m_vec2 = {1.0f, 1.0f, 1.0f};
    collision->m_vec3 = {
        locatedA->m_location.tX,
        locatedA->m_location.tY,
        locatedA->m_location.tZ,
    };
    collision->m_id1 = boxA->m_flags;
    collision->m_id2 = boxB->m_flags;
    return 1;
}
int GmCollision_Box_Mesh(
    LocatedGmSurf* locatedBox,
    LocatedGmSurf* locatedMesh,
    CGmCollisionBuffer* buffer) {
    GmSurfBox* box = static_cast<GmSurfBox*>(locatedBox->m_surf);
    GmSurfMesh* mesh = static_cast<GmSurfMesh*>(locatedMesh->m_surf);

    GmIso4 meshToBox = locatedMesh->m_location;
    meshToBox.MultInverse(locatedBox->m_location);

    // 0x008f5200 traverses the native mesh octree, then applies the standard
    // 13-axis triangle/AABB test in box-local coordinates. Visit faces in
    // buffer order until the standalone mesh has the native broadphase layout.
    for (uint32_t triangleIndex = 0;
         triangleIndex < mesh->m_triangles.m_count;
         ++triangleIndex) {
        const GmSurfTriangle& triangle = mesh->m_triangles[triangleIndex];
        if (triangle.indices[0] >= mesh->m_vertices.m_count ||
            triangle.indices[1] >= mesh->m_vertices.m_count ||
            triangle.indices[2] >= mesh->m_vertices.m_count) {
            continue;
        }

        const GmVec3 first = TransformPoint(
            meshToBox, mesh->m_vertices[triangle.indices[0]]) - box->m_center;
        const GmVec3 second = TransformPoint(
            meshToBox, mesh->m_vertices[triangle.indices[1]]) - box->m_center;
        const GmVec3 third = TransformPoint(
            meshToBox, mesh->m_vertices[triangle.indices[2]]) - box->m_center;
        if (!TriangleIntersectsCenteredBox(
                first, second, third, box->m_extents)) {
            continue;
        }

        GmCollision* collision = buffer->AddCollision();
        collision->m_vec1 = {0.0f, 0.0f, 0.0f};
        collision->m_vec2 = TransformVector(
            locatedMesh->m_location, triangle.planeNormal);
        collision->m_vec3 = TransformPoint(
            locatedMesh->m_location,
            mesh->m_vertices[triangle.indices[0]]);
        collision->m_id1 = box->m_flags;
        collision->m_id2 = triangle.materialId;
        return 1;
    }
    return 0;
}
int GmCollision_Mesh_Mesh(
    LocatedGmSurf* locatedA,
    LocatedGmSurf* locatedB,
    CGmCollisionBuffer* buffer) {
    GmSurfMesh* meshA = static_cast<GmSurfMesh*>(locatedA->m_surf);
    GmSurfMesh* meshB = static_cast<GmSurfMesh*>(locatedB->m_surf);
    GmIso4 meshBToMeshA = locatedB->m_location;
    meshBToMeshA.MultInverse(locatedA->m_location);

    struct TransformedTriangle {
        GmVec3 vertices[3];
        const GmSurfTriangle* source;
    };
    std::vector<TransformedTriangle> trianglesB;
    trianglesB.reserve(meshB->m_triangles.m_count);
    for (uint32_t triangleIndex = 0;
         triangleIndex < meshB->m_triangles.m_count;
         ++triangleIndex) {
        const GmSurfTriangle& triangle = meshB->m_triangles[triangleIndex];
        if (triangle.indices[0] >= meshB->m_vertices.m_count ||
            triangle.indices[1] >= meshB->m_vertices.m_count ||
            triangle.indices[2] >= meshB->m_vertices.m_count) {
            continue;
        }
        trianglesB.push_back({{
            TransformPoint(
                meshBToMeshA, meshB->m_vertices[triangle.indices[0]]),
            TransformPoint(
                meshBToMeshA, meshB->m_vertices[triangle.indices[1]]),
            TransformPoint(
                meshBToMeshA, meshB->m_vertices[triangle.indices[2]]),
        }, &triangle});
    }

    // 0x008f1b30 asks SMeshMeshCollide to stop at the first hit. The native
    // TreeTree routine determines candidate order from its private octrees;
    // the standalone representation visits the equivalent triangle pairs in
    // face-buffer order and uses the same 0x008f0ac0 no-division test.
    for (uint32_t triangleIndexA = 0;
         triangleIndexA < meshA->m_triangles.m_count;
         ++triangleIndexA) {
        const GmSurfTriangle& triangleA =
            meshA->m_triangles[triangleIndexA];
        if (triangleA.indices[0] >= meshA->m_vertices.m_count ||
            triangleA.indices[1] >= meshA->m_vertices.m_count ||
            triangleA.indices[2] >= meshA->m_vertices.m_count) {
            continue;
        }
        const GmVec3& firstA = meshA->m_vertices[triangleA.indices[0]];
        const GmVec3& secondA = meshA->m_vertices[triangleA.indices[1]];
        const GmVec3& thirdA = meshA->m_vertices[triangleA.indices[2]];

        for (const TransformedTriangle& triangleB : trianglesB) {
            if (!TrianglesIntersect(
                    firstA, secondA, thirdA,
                    triangleB.vertices[0], triangleB.vertices[1],
                    triangleB.vertices[2])) {
                continue;
            }

            GmCollision* collision = buffer->AddCollision();
            collision->m_vec1 = {0.0f, 0.0f, 0.0f};
            const GmVec3 normalInMeshA = TransformVector(
                meshBToMeshA, triangleB.source->planeNormal);
            collision->m_vec2 = TransformVector(
                locatedA->m_location, normalInMeshA);
            collision->m_vec3 = TransformPoint(
                locatedA->m_location, firstA);
            collision->m_id1 = triangleA.materialId;
            collision->m_id2 = triangleB.source->materialId;
            return 1;
        }
    }
    return 0;
}
