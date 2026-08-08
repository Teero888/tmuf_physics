#include "../../Fast/CFastBuffer.hpp"
#include "../../Gm/GmCollision.hpp"
#include "../../Gm/GmSurf.hpp"
#include "../../Gm/GmVec4.hpp"
#include "../../Hms/CHmsCollisionBuffer.hpp"

#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

using CollisionFunction = int (*)(LocatedGmSurf*, LocatedGmSurf*, CGmCollisionBuffer*);
extern CollisionFunction g_GmCollisionMatrix[9][9];

namespace {

bool Near(float actual, float expected, float epsilon = 1.0e-6f) {
    return std::fabs(actual - expected) <= epsilon;
}

bool VecNear(const GmVec3& actual,
             const GmVec3& expected,
             float epsilon = 1.0e-6f) {
    return Near(actual.x, expected.x, epsilon) &&
           Near(actual.y, expected.y, epsilon) &&
           Near(actual.z, expected.z, epsilon);
}

uint32_t FeatureFlag(const GmCollision& collision) {
    uint32_t flag = 0;
    std::memcpy(&flag, &collision.m_unknown_0x28, sizeof(flag));
    return flag;
}

void SetPolygon(CFastBuffer<GmVec4>& vertices,
                CFastBuffer<uint32_t>& flags,
                const std::vector<GmVec4>& values) {
    vertices.AllocSetCount(static_cast<uint32_t>(values.size()));
    flags.AllocSetCount(static_cast<uint32_t>(values.size()));
    for (uint32_t index = 0; index < values.size(); ++index) {
        vertices[index] = values[index];
    }
    GmVec4::GetClipFlags(vertices.m_data, flags.m_data, vertices.GetCount());
}

class TestCollisionBuffer final : public CGmCollisionBuffer {
public:
    GmCollision* AddCollision() override {
        collisions.emplace_back(GmCollision{});
        return &collisions.back();
    }

    unsigned int GetCount() const override {
        return static_cast<unsigned int>(collisions.size());
    }

    GmCollision* GetCollision(unsigned int index) override {
        return &collisions[index];
    }

    void Clear() { collisions.clear(); }

    std::vector<GmCollision> collisions;
};

bool TestClipFlags() {
    const GmVec4 values[] = {
        {0.0f, 0.0f, -0.1f, 1.0f},
        {0.0f, 0.0f, 1.1f, 1.0f},
        {0.0f, -1.1f, 0.5f, 1.0f},
        {0.0f, 1.1f, 0.5f, 1.0f},
        {-1.1f, 0.0f, 0.5f, 1.0f},
        {1.1f, 0.0f, 0.5f, 1.0f},
    };
    uint32_t flags[6]{};
    GmVec4::GetClipFlags(values, flags, 6);
    for (uint32_t index = 0; index < 6; ++index) {
        if (flags[index] != (1u << index)) return false;
    }
    return true;
}

bool TestPolygonLeftClip() {
    CFastBuffer<GmVec4> vertices;
    CFastBuffer<uint32_t> flags;
    SetPolygon(vertices, flags, {
        {-2.0f, -0.5f, 0.5f, 1.0f},
        { 0.5f, -0.5f, 0.5f, 1.0f},
        { 0.5f,  0.5f, 0.5f, 1.0f},
        {-2.0f,  0.5f, 0.5f, 1.0f},
    });

    GmVec4::PolygonClip(vertices, flags);
    const GmVec4 expected[] = {
        {-1.0f, -0.5f, 0.5f, 1.0f},
        { 0.5f, -0.5f, 0.5f, 1.0f},
        { 0.5f,  0.5f, 0.5f, 1.0f},
        {-1.0f,  0.5f, 0.5f, 1.0f},
    };
    if (vertices.GetCount() != 4u || flags.GetCount() != 4u) return false;
    for (uint32_t index = 0; index < 4u; ++index) {
        if (!Near(vertices[index].x, expected[index].x) ||
            !Near(vertices[index].y, expected[index].y) ||
            !Near(vertices[index].z, expected[index].z) ||
            !Near(vertices[index].w, expected[index].w) || flags[index] != 0u) {
            return false;
        }
    }
    return true;
}

bool TestPolygonNearClipAndReject() {
    CFastBuffer<GmVec4> vertices;
    CFastBuffer<uint32_t> flags;
    SetPolygon(vertices, flags, {
        {-0.5f,  0.0f, -1.0f, 1.0f},
        { 0.5f, -0.5f,  0.5f, 1.0f},
        { 0.5f,  0.5f,  0.5f, 1.0f},
    });
    GmVec4::PolygonClip(vertices, flags);
    if (vertices.GetCount() != 4u || flags.GetCount() != 4u) return false;
    if (!Near(vertices[0].z, 0.0f) || !Near(vertices[3].z, 0.0f)) return false;
    for (uint32_t index = 0; index < flags.GetCount(); ++index) {
        if (flags[index] != 0u) return false;
    }

    SetPolygon(vertices, flags, {
        {-0.5f, -0.5f, 2.0f, 1.0f},
        { 0.5f, -0.5f, 2.0f, 1.0f},
        { 0.0f,  0.5f, 2.0f, 1.0f},
    });
    GmVec4::PolygonClip(vertices, flags);
    return vertices.GetCount() == 0u && flags.GetCount() == 0u;
}

bool TestNativePlaneThresholds() {
    GmVec4 plane{};
    if (!plane.PlaneEqSetFrom3Pos({0.0f, 0.0f, 0.0f},
                                  {0.01f, 0.0f, 0.0f},
                                  {0.0f, 0.0011f, 0.0f})) {
        return false;
    }
    if (!Near(plane.x, 0.0f) || !Near(plane.y, 0.0f) ||
        !Near(plane.z, 1.0f) || !Near(plane.w, 0.0f)) {
        return false;
    }

    const GmVec4 reference{1.0f, 0.0f, 0.0f, 0.0f};
    const GmVec4 nativeNear{0.995f, 0.0f, 0.0f, 0.05f};
    // The two float parameters exist in the original ABI but the native
    // implementation uses its global 0.99/0.1 thresholds.
    return reference.PlaneEqIsNearlyEqual(nativeNear, 1.0f, 0.0f);
}

bool g_dispatchReceivedNativeOrder = false;

int AddSyntheticCollision(LocatedGmSurf* first,
                          LocatedGmSurf* second,
                          CGmCollisionBuffer* buffer) {
    g_dispatchReceivedNativeOrder = first->m_surf->m_type == 0u &&
                                    second->m_surf->m_type == 6u;
    GmCollision* collision = buffer->AddCollision();
    collision->m_vec1 = {1.0f, 2.0f, 3.0f};
    collision->m_vec2 = {4.0f, 5.0f, 6.0f};
    collision->m_vec4 = {7.0f, 8.0f, 9.0f};
    collision->m_id1 = 11u;
    collision->m_id2 = 22u;
    return 1;
}

bool TestReversedCollisionDispatch() {
    GmSurf::StaticInit();
    g_GmCollisionMatrix[0][6] = AddSyntheticCollision;

    GmSurfSphere sphere;
    GmSurfBox box;
    LocatedGmSurf locatedSphere{};
    LocatedGmSurf locatedBox{};
    locatedSphere.m_surf = &sphere;
    locatedBox.m_surf = &box;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {31.0f, 32.0f, 33.0f};

    g_dispatchReceivedNativeOrder = false;
    if (GmSurf::ComputeCollision(&locatedBox, &locatedSphere, &buffer) != 1 ||
        !g_dispatchReceivedNativeOrder || buffer.GetCount() != 2u) {
        return false;
    }

    const GmCollision& untouched = buffer.collisions[0];
    const GmCollision& reversed = buffer.collisions[1];
    return VecNear(untouched.m_vec1, {31.0f, 32.0f, 33.0f}) &&
           VecNear(reversed.m_vec1, {-1.0f, -2.0f, -3.0f}) &&
           VecNear(reversed.m_vec2, {-4.0f, -5.0f, -6.0f}) &&
           VecNear(reversed.m_vec4, {-7.0f, -8.0f, -9.0f}) &&
           reversed.m_id1 == 22u && reversed.m_id2 == 11u;
}

bool TestSphereSphereCollision() {
    GmSurf::StaticInit();
    GmSurfSphere sphereA;
    GmSurfSphere sphereB;
    sphereA.m_radius = 2.0f;
    sphereB.m_radius = 1.0f;
    sphereA.m_flags = 17u;
    sphereB.m_flags = 23u;

    LocatedGmSurf locatedA{};
    LocatedGmSurf locatedB{};
    locatedA.m_surf = &sphereA;
    locatedB.m_surf = &sphereB;
    locatedA.m_location.SetIdentity();
    locatedB.m_location.SetIdentity();
    locatedA.m_location.tX = 10.0f;
    locatedA.m_location.tY = 20.0f;
    locatedA.m_location.tZ = 30.0f;
    locatedB.m_location.tX = 12.0f;
    locatedB.m_location.tY = 20.0f;
    locatedB.m_location.tZ = 30.0f;

    TestCollisionBuffer buffer;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& collision = buffer.collisions[0];
    if (!VecNear(collision.m_vec1, {1.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {-1.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec3, {12.0f, 20.0f, 30.0f}) ||
        collision.m_id1 != 17u || collision.m_id2 != 23u) {
        return false;
    }

    buffer.Clear();
    locatedB.m_location.tX = 13.0f;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    buffer.Clear();
    locatedB.m_location = locatedA.m_location;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& coincident = buffer.collisions[0];
    return VecNear(coincident.m_vec1, {0.0f, 1.0f, 0.0f}) &&
           VecNear(coincident.m_vec2, {0.0f, -1.0f, 0.0f}) &&
           VecNear(coincident.m_vec3, {10.0f, 20.0f, 30.0f});
}

bool TestAffinePointTransform() {
    GmIso4 transform;
    transform.SetIdentity();
    transform.m00 = 0.0f;
    transform.m01 = -1.0f;
    transform.m10 = 1.0f;
    transform.m11 = 0.0f;
    transform.tX = 10.0f;
    transform.tY = 20.0f;
    transform.tZ = 30.0f;

    GmVec3 point{2.0f, 3.0f, 4.0f};
    point.Mult(transform);
    if (!VecNear(point, {7.0f, 22.0f, 34.0f})) return false;
    point.MultInverse(transform);
    return VecNear(point, {2.0f, 3.0f, 4.0f});
}

bool TestNativeAffineComposition() {
    GmMat3 lines;
    lines.SetIdentity();
    lines.SetLine(0u, {2.0f, 3.0f, 4.0f});
    GmVec3 firstLine;
    lines.GetLine(0u, firstLine);
    if (!VecNear(firstLine, {2.0f, 3.0f, 4.0f}) ||
        !Near(lines.m00, 2.0f) || !Near(lines.m10, 3.0f) ||
        !Near(lines.m20, 4.0f)) {
        return false;
    }

    GmIso4 first;
    first.SetIdentity();
    first.m00 = 0.0f;
    first.m01 = -1.0f;
    first.m10 = 1.0f;
    first.m11 = 0.0f;
    first.tX = 10.0f;
    first.tY = 20.0f;
    first.tZ = 30.0f;

    GmIso4 second;
    second.SetIdentity();
    second.m00 = -1.0f;
    second.m22 = -1.0f;
    second.tX = 5.0f;
    second.tY = -2.0f;
    second.tZ = 7.0f;

    GmIso4 composed;
    composed.SetMult(first, second);
    GmVec3 sequential{2.0f, 3.0f, 4.0f};
    sequential.Mult(first);
    sequential.Mult(second);
    GmVec3 combined{2.0f, 3.0f, 4.0f};
    combined.Mult(composed);
    if (!VecNear(combined, sequential)) return false;

    GmIso4 inverse;
    inverse.SetInverse(composed);
    combined.Mult(inverse);
    if (!VecNear(combined, {2.0f, 3.0f, 4.0f})) return false;

    GmVec4 point{2.0f, 3.0f, 4.0f, 1.0f};
    GmVec4 transformed;
    transformed.SetMult(point, first);
    if (!Near(transformed.x, 7.0f) || !Near(transformed.y, 22.0f) ||
        !Near(transformed.z, 34.0f) || !Near(transformed.w, 1.0f)) {
        return false;
    }
    GmVec4 direction{2.0f, 3.0f, 4.0f, 0.0f};
    transformed.SetMult(direction, first);
    return Near(transformed.x, -3.0f) && Near(transformed.y, 2.0f) &&
           Near(transformed.z, 4.0f) && Near(transformed.w, 0.0f);
}

bool TestSphereBoxCollision() {
    GmSurf::StaticInit();
    GmSurfSphere sphere;
    sphere.m_radius = 1.0f;
    sphere.m_flags = 7u;
    GmSurfBox box;
    box.m_center = {0.0f, 0.0f, 0.0f};
    box.m_extents = {2.0f, 1.0f, 3.0f};
    box.m_flags = 29u;

    LocatedGmSurf locatedSphere{};
    LocatedGmSurf locatedBox{};
    locatedSphere.m_surf = &sphere;
    locatedBox.m_surf = &box;
    locatedSphere.m_location.SetIdentity();
    locatedBox.m_location.SetIdentity();
    locatedBox.m_location.m00 = 0.0f;
    locatedBox.m_location.m01 = -1.0f;
    locatedBox.m_location.m10 = 1.0f;
    locatedBox.m_location.m11 = 0.0f;
    locatedBox.m_location.tX = 10.0f;
    locatedBox.m_location.tY = 5.0f;
    locatedBox.m_location.tZ = -3.0f;
    locatedSphere.m_location.tX = 10.0f;
    locatedSphere.m_location.tY = 7.5f;
    locatedSphere.m_location.tZ = -3.0f;

    TestCollisionBuffer buffer;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedBox, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& face = buffer.collisions[0];
    if (!VecNear(face.m_vec1, {0.0f, -0.5f, 0.0f}) ||
        !VecNear(face.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(face.m_vec3, {10.0f, 7.0f, -3.0f}) ||
        face.m_id1 != 7u || face.m_id2 != 29u) {
        return false;
    }

    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedBox, &locatedSphere, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {0.0f, 0.5f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {0.0f, -1.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {10.0f, 7.0f, -3.0f}) ||
        reversed.m_id1 != 29u || reversed.m_id2 != 7u) {
        return false;
    }

    // Native behavior deliberately rejects a sphere whose center is inside.
    buffer.Clear();
    locatedSphere.m_location.tY = 5.0f;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedBox, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    // Exercise an edge feature with two clamped local coordinates.
    locatedBox.m_location.SetIdentity();
    locatedSphere.m_location.SetIdentity();
    locatedSphere.m_location.tX = 2.6f;
    locatedSphere.m_location.tY = 1.6f;
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedBox, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& edge = buffer.collisions[0];
    const float distance = std::sqrt(0.72f);
    const GmVec3 expectedNormal{0.6f / distance, 0.6f / distance, 0.0f};
    return VecNear(edge.m_vec1,
                   expectedNormal * (distance - 1.0f), 1.0e-5f) &&
           VecNear(edge.m_vec2, expectedNormal, 1.0e-5f) &&
           VecNear(edge.m_vec3, {2.0f, 1.0f, 0.0f});
}

bool TestSphereMeshCollision() {
    GmSurf::StaticInit();
    GmSurfSphere sphere;
    sphere.m_radius = 1.0f;
    sphere.m_flags = 7u;

    GmSurfMesh mesh;
    mesh.m_vertices.Add({-2.0f, 0.0f, -2.0f});
    mesh.m_vertices.Add({ 0.0f, 0.0f,  2.0f});
    mesh.m_vertices.Add({ 2.0f, 0.0f, -2.0f});
    GmSurfTriangle triangle{};
    triangle.planeNormal = {0.0f, 1.0f, 0.0f};
    triangle.planeDist = 0.0f;
    triangle.indices[0] = 0u;
    triangle.indices[1] = 1u;
    triangle.indices[2] = 2u;
    triangle.materialId = 41u;
    mesh.m_triangles.Add(triangle);

    LocatedGmSurf locatedSphere{};
    LocatedGmSurf locatedMesh{};
    locatedSphere.m_surf = &sphere;
    locatedMesh.m_surf = &mesh;
    locatedSphere.m_location.SetIdentity();
    locatedMesh.m_location.SetIdentity();
    locatedMesh.m_location.tX = 10.0f;
    locatedMesh.m_location.tY = 5.0f;
    locatedMesh.m_location.tZ = -3.0f;
    locatedSphere.m_location.tX = 10.0f;
    locatedSphere.m_location.tY = 5.5f;
    locatedSphere.m_location.tZ = -3.0f;

    TestCollisionBuffer buffer;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedMesh, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& face = buffer.collisions[0];
    if (!VecNear(face.m_vec1, {0.0f, -0.5f, 0.0f}) ||
        !VecNear(face.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(face.m_vec3, {10.0f, 5.0f, -3.0f}) ||
        !VecNear(face.m_vec4, {0.0f, 1.0f, 0.0f}) ||
        face.m_id1 != 7u || face.m_id2 != 41u ||
        FeatureFlag(face) != 1u) {
        return false;
    }

    // Reversed dispatch negates only the newly generated geometry and swaps
    // the native sphere/material identifiers.
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedMesh, &locatedSphere, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {0.0f, 0.5f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {0.0f, -1.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {10.0f, 5.0f, -3.0f}) ||
        !VecNear(reversed.m_vec4, {0.0f, -1.0f, 0.0f}) ||
        reversed.m_id1 != 41u || reversed.m_id2 != 7u ||
        FeatureFlag(reversed) != 1u) {
        return false;
    }

    // The native routine rejects triangle back faces.
    buffer.Clear();
    locatedSphere.m_location.tY = 4.5f;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedMesh, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    // Exercise the vertex path and its distinct squared-distance epsilon.
    buffer.Clear();
    locatedMesh.m_location.SetIdentity();
    locatedSphere.m_location.SetIdentity();
    locatedSphere.m_location.tX = 2.4f;
    locatedSphere.m_location.tY = 0.5f;
    locatedSphere.m_location.tZ = -2.0f;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedMesh, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& vertex = buffer.collisions[0];
    const float distance = std::sqrt(0.41f);
    const GmVec3 expectedNormal{0.4f / distance, 0.5f / distance, 0.0f};
    const float expectedReplacementY =
        0.5f * (distance - 1.0f) / distance;
    return VecNear(vertex.m_vec1, {0.0f, expectedReplacementY, 0.0f}, 1.0e-5f) &&
           VecNear(vertex.m_vec2, expectedNormal, 1.0e-5f) &&
           VecNear(vertex.m_vec3, {2.0f, 0.0f, -2.0f}) &&
           VecNear(vertex.m_vec4, {0.0f, 1.0f, 0.0f}) &&
           vertex.m_id1 == 7u && vertex.m_id2 == 41u &&
           FeatureFlag(vertex) == 0u;
}

bool TestHmsCollisionBuffer() {
    CHmsCollisionBuffer buffer;
    if (buffer.GetCount() != 0u || buffer.m_collisions.m_capacity != 50u) {
        return false;
    }

    GmCollision* first = buffer.AddCollision();
    first->m_vec1 = {1.0f, 2.0f, 3.0f};
    first->m_vec2 = {4.0f, 5.0f, 6.0f};
    first->m_id1 = 7u;
    first->m_id2 = 8u;
    if (buffer.GetCount() != 1u || buffer.GetCollision(0u) != first) return false;

    const GmCollision* stored = buffer.GetCollision(0u);
    return VecNear(stored->m_vec1, {1.0f, 2.0f, 3.0f}) &&
           VecNear(stored->m_vec2, {4.0f, 5.0f, 6.0f}) &&
           stored->m_id1 == 7u && stored->m_id2 == 8u;
}

} // namespace

int main() {
    const bool passed = TestClipFlags() &&
                        TestPolygonLeftClip() &&
                        TestPolygonNearClipAndReject() &&
                        TestNativePlaneThresholds() &&
                        TestReversedCollisionDispatch() &&
                        TestSphereSphereCollision() &&
                        TestAffinePointTransform() &&
                        TestNativeAffineComposition() &&
                        TestSphereBoxCollision() &&
                        TestSphereMeshCollision() &&
                        TestHmsCollisionBuffer();
    if (!passed) {
        std::fputs("geometry/collision regression: FAIL\n", stderr);
        return 1;
    }
    std::puts("geometry/collision regression: PASS");
    return 0;
}
