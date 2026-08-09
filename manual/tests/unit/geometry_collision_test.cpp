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

bool TestSurfaceBoundingBoxesAndDefaults() {
    GmBoxAligned empty;
    empty.InitEmpty();
    if (!VecNear(empty.center, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(empty.extents, {-1.0f, -1.0f, -1.0f}) ||
        !empty.IsNull()) {
        return false;
    }

    GmSurfSphere sphere;
    sphere.CreateDefaultData(nullptr);
    GmBoxAligned bounds;
    bounds.center = {91.0f, 92.0f, 93.0f};
    bounds.extents = {94.0f, 95.0f, 96.0f};
    sphere.GetBoundingBox(bounds);
    if (!Near(sphere.m_radius, 1.0f) ||
        !VecNear(bounds.center, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(bounds.extents, {1.0f, 1.0f, 1.0f})) {
        return false;
    }

    GmSurfEllipsoid ellipsoid;
    ellipsoid.CreateDefaultData(nullptr);
    ellipsoid.GetBoundingBox(bounds);
    if (!VecNear(ellipsoid.m_radii, {1.0f, 1.0f, 1.0f}) ||
        !VecNear(bounds.center, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(bounds.extents, {1.0f, 1.0f, 1.0f})) {
        return false;
    }

    GmSurfBox box;
    box.CreateDefaultData(nullptr);
    box.GetBoundingBox(bounds);
    if (!VecNear(box.m_center, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(box.m_extents, {0.5f, 0.5f, 0.5f}) ||
        !VecNear(bounds.center, box.m_center) ||
        !VecNear(bounds.extents, box.m_extents)) {
        return false;
    }

    // Polygon is not a native GetBoundingBox case and leaves the output as-is.
    GmSurfPolygon polygon(3u);
    bounds.center = {11.0f, 12.0f, 13.0f};
    bounds.extents = {14.0f, 15.0f, 16.0f};
    polygon.GetBoundingBox(bounds);
    if (!VecNear(bounds.center, {11.0f, 12.0f, 13.0f}) ||
        !VecNear(bounds.extents, {14.0f, 15.0f, 16.0f})) {
        return false;
    }

    GmSurfMesh mesh;
    mesh.m_vertices.Add({-2.0f, 1.0f, -4.0f});
    mesh.m_vertices.Add({ 6.0f, 3.0f,  2.0f});
    mesh.m_vertices.Add({ 0.0f, 5.0f,  4.0f});
    mesh.m_vertices.Add({100.0f, 100.0f, 100.0f});
    GmSurfTriangle triangle{};
    triangle.indices[0] = 0u;
    triangle.indices[1] = 1u;
    triangle.indices[2] = 2u;
    mesh.m_triangles.Add(triangle);
    mesh.GetBoundingBox(bounds);
    if (!VecNear(bounds.center, {2.0f, 3.0f, 0.0f}) ||
        !VecNear(bounds.extents, {4.0f, 2.0f, 4.0f})) {
        return false;
    }

    GmSurfMesh noFaces;
    noFaces.m_vertices.Add({5.0f, 6.0f, 7.0f});
    noFaces.GetBoundingBox(bounds);
    return VecNear(bounds.center, {0.0f, 0.0f, 0.0f}) &&
           VecNear(bounds.extents, {-1.0f, -1.0f, -1.0f});
}

bool g_dispatchReceivedNativeOrder = false;

bool TestNativeCollisionDispatchMatrix() {
    GmSurf::StaticInit();
    bool expected[9][9]{};
    expected[0][0] = true;
    expected[0][1] = expected[1][0] = true;
    expected[0][5] = expected[5][0] = true;
    expected[0][6] = expected[6][0] = true;
    expected[0][7] = expected[7][0] = true;
    expected[1][5] = expected[5][1] = true;
    expected[1][7] = expected[7][1] = true;
    expected[6][6] = true;
    expected[6][7] = expected[7][6] = true;
    expected[7][7] = true;

    for (uint32_t first = 0; first < 9u; ++first) {
        for (uint32_t second = 0; second < 9u; ++second) {
            if ((g_GmCollisionMatrix[first][second] != nullptr) !=
                expected[first][second]) {
                return false;
            }
        }
    }
    return true;
}

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

bool TestSphereEllipsoidCollision() {
    GmSurf::StaticInit();
    GmSurfSphere sphere;
    sphere.m_radius = 1.0f;
    sphere.m_flags = 17u;
    GmSurfEllipsoid ellipsoid;
    ellipsoid.m_radii = {1.0f, 3.0f, 2.0f};
    ellipsoid.m_flags = 23u;

    LocatedGmSurf locatedSphere{};
    LocatedGmSurf locatedEllipsoid{};
    locatedSphere.m_surf = &sphere;
    locatedEllipsoid.m_surf = &ellipsoid;
    locatedSphere.m_location.SetIdentity();
    locatedEllipsoid.m_location.SetIdentity();
    locatedEllipsoid.m_location.tX = 3.5f;

    TestCollisionBuffer buffer;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedEllipsoid, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& collision = buffer.collisions[0];
    if (!VecNear(collision.m_vec1, {0.5f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {-1.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec3, {1.0f, 0.0f, 0.0f}) ||
        collision.m_id1 != 17u || collision.m_id2 != 23u) {
        return false;
    }

    buffer.Clear();
    locatedEllipsoid.m_location.tX = 4.0f;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedEllipsoid, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    buffer.Clear();
    locatedEllipsoid.m_location = locatedSphere.m_location;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedEllipsoid, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& coincident = buffer.collisions[0];
    return VecNear(coincident.m_vec1, {0.0f, 0.0f, 0.0f}) &&
           VecNear(coincident.m_vec2, {0.0f, -1.0f, 0.0f}) &&
           VecNear(coincident.m_vec3, {0.0f, 0.0f, 0.0f});
}

void InitSquarePolygon(GmSurfPolygon& polygon) {
    polygon.m_vertices[0] = {-1.0f, 0.0f, -1.0f};
    polygon.m_vertices[1] = {-1.0f, 0.0f,  1.0f};
    polygon.m_vertices[2] = { 1.0f, 0.0f,  1.0f};
    polygon.m_vertices[3] = { 1.0f, 0.0f, -1.0f};
    polygon.m_numVertices = 4u;
    polygon.m_planeNormal = {0.0f, 1.0f, 0.0f};
    polygon.m_unknown_0x48 = 0;
    polygon.m_flags = 31u;
}

bool TestSpherePolygonCollision() {
    GmSurf::StaticInit();
    GmSurfSphere sphere;
    sphere.m_radius = 1.0f;
    sphere.m_flags = 7u;
    GmSurfPolygon polygon(4u);
    InitSquarePolygon(polygon);

    LocatedGmSurf locatedSphere{};
    LocatedGmSurf locatedPolygon{};
    locatedSphere.m_surf = &sphere;
    locatedPolygon.m_surf = &polygon;
    locatedSphere.m_location.SetIdentity();
    locatedPolygon.m_location.SetIdentity();

    // Rotate the polygon around Z so its local +Y normal becomes world -X.
    locatedPolygon.m_location.m00 = 0.0f;
    locatedPolygon.m_location.m01 = -1.0f;
    locatedPolygon.m_location.m10 = 1.0f;
    locatedPolygon.m_location.m11 = 0.0f;
    locatedPolygon.m_location.tX = 10.0f;
    locatedPolygon.m_location.tY = 5.0f;
    locatedPolygon.m_location.tZ = -3.0f;
    locatedSphere.m_location.tX = 9.5f;
    locatedSphere.m_location.tY = 5.0f;
    locatedSphere.m_location.tZ = -3.0f;

    TestCollisionBuffer buffer;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedPolygon, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& face = buffer.collisions[0];
    if (!VecNear(face.m_vec1, {0.5f, 0.0f, 0.0f}) ||
        !VecNear(face.m_vec2, {-1.0f, 0.0f, 0.0f}) ||
        !VecNear(face.m_vec3, {10.0f, 5.0f, -3.0f}) ||
        face.m_id1 != 7u || face.m_id2 != 31u) {
        return false;
    }

    // The native edge branch retains the face normal in vec2 and stores only
    // the face-normal component of the radial replacement in vec1.
    locatedPolygon.m_location.SetIdentity();
    locatedSphere.m_location.SetIdentity();
    locatedSphere.m_location.tX = 1.4f;
    locatedSphere.m_location.tY = 0.5f;
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedPolygon, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& edge = buffer.collisions[0];
    const float edgeDistance = std::sqrt(0.41f);
    const float edgeReplacementY =
        0.5f * (edgeDistance - 1.0f) / edgeDistance;
    if (!VecNear(edge.m_vec1, {0.0f, edgeReplacementY, 0.0f}, 1.0e-5f) ||
        !VecNear(edge.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(edge.m_vec3, {1.0f, 0.0f, 0.0f})) {
        return false;
    }

    // Exercise the vertex selection path.
    locatedSphere.m_location.tZ = 1.4f;
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedPolygon, &buffer) != 1 ||
        buffer.GetCount() != 1u ||
        !VecNear(buffer.collisions[0].m_vec3, {1.0f, 0.0f, 1.0f})) {
        return false;
    }

    // One-sided polygons reject back faces; two-sided polygons use the
    // native full (distance - radius) replacement along the plane normal.
    locatedSphere.m_location.tX = 0.0f;
    locatedSphere.m_location.tY = -0.5f;
    locatedSphere.m_location.tZ = 0.0f;
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedPolygon, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }
    polygon.m_unknown_0x48 = 1;
    if (GmSurf::ComputeCollision(
            &locatedSphere, &locatedPolygon, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& backFace = buffer.collisions[0];
    if (!VecNear(backFace.m_vec1, {0.0f, -1.5f, 0.0f}) ||
        !VecNear(backFace.m_vec2, {0.0f, -1.0f, 0.0f}) ||
        !VecNear(backFace.m_vec3, {0.0f, 0.0f, 0.0f})) {
        return false;
    }

    // At this height the cross-section circle cannot reach the nearest edge.
    polygon.m_unknown_0x48 = 0;
    locatedSphere.m_location.tX = 2.0f;
    locatedSphere.m_location.tY = 0.8f;
    buffer.Clear();
    return GmSurf::ComputeCollision(
               &locatedSphere, &locatedPolygon, &buffer) == 0 &&
           buffer.GetCount() == 0u;
}

bool TestEllipsoidPolygonCollision() {
    GmSurf::StaticInit();
    GmSurfEllipsoid ellipsoid;
    ellipsoid.m_radii = {2.0f, 1.0f, 0.5f};
    ellipsoid.m_flags = 11u;

    GmSurfPolygon polygon(4u);
    polygon.m_vertices[0] = {1.5f, -2.0f, -2.0f};
    polygon.m_vertices[1] = {1.5f, -2.0f,  2.0f};
    polygon.m_vertices[2] = {1.5f,  2.0f,  2.0f};
    polygon.m_vertices[3] = {1.5f,  2.0f, -2.0f};
    polygon.ComputeNormalFromVertices();
    polygon.m_flags = 37u;
    if (polygon.m_numVertices != 4u ||
        !VecNear(polygon.m_planeNormal, {-1.0f, 0.0f, 0.0f})) {
        return false;
    }

    LocatedGmSurf locatedEllipsoid{};
    LocatedGmSurf locatedPolygon{};
    locatedEllipsoid.m_surf = &ellipsoid;
    locatedPolygon.m_surf = &polygon;
    locatedEllipsoid.m_location.SetIdentity();
    locatedPolygon.m_location.SetIdentity();
    locatedEllipsoid.m_location.tX = 10.0f;
    locatedPolygon.m_location.tX = 10.0f;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {91.0f, 92.0f, 93.0f};
    if (GmSurf::ComputeCollision(
            &locatedEllipsoid, &locatedPolygon, &buffer) != 1 ||
        buffer.GetCount() != 2u ||
        !VecNear(buffer.collisions[0].m_vec1, {91.0f, 92.0f, 93.0f})) {
        return false;
    }

    const GmCollision& collision = buffer.collisions[1];
    // 0x008e9fee-0x008ea01a uses inverse(E^-1 * P) after the temporary
    // sphere test. Consequently this native pair returns the point in the
    // polygon's local frame even though both input locations are translated.
    if (!VecNear(collision.m_vec1, {0.5f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {-1.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec3, {1.5f, 0.0f, 0.0f}) ||
        collision.m_id1 != 11u || collision.m_id2 != 37u) {
        return false;
    }

    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedPolygon, &locatedEllipsoid, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {-0.5f, 0.0f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {1.0f, 0.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {1.5f, 0.0f, 0.0f}) ||
        reversed.m_id1 != 37u || reversed.m_id2 != 11u) {
        return false;
    }

    // Degenerate temporary polygons use the native +X normal fallback.
    GmSurfPolygon degenerate(3u);
    degenerate.m_vertices[0] = {1.0f, 2.0f, 3.0f};
    degenerate.m_vertices[1] = {1.0f, 2.0f, 3.0f};
    degenerate.m_vertices[2] = {1.0f, 2.0f, 3.0f};
    degenerate.ComputeNormalFromVertices();
    if (!VecNear(degenerate.m_planeNormal, {1.0f, 0.0f, 0.0f})) {
        return false;
    }

    buffer.Clear();
    locatedEllipsoid.m_location.tX = 7.0f;
    return GmSurf::ComputeCollision(
               &locatedEllipsoid, &locatedPolygon, &buffer) == 0 &&
           buffer.GetCount() == 0u;
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
    if (!Near(transformed.x, -3.0f) || !Near(transformed.y, 2.0f) ||
        !Near(transformed.z, 4.0f) || !Near(transformed.w, 0.0f)) {
        return false;
    }

    GmIso4 scaled;
    scaled.SetNUScaleTrans({2.0f, 3.0f, 4.0f}, {1.0f, 2.0f, 3.0f});
    GmIso4 quarterTurn;
    quarterTurn.SetIdentity();
    quarterTurn.m00 = 0.0f;
    quarterTurn.m01 = -1.0f;
    quarterTurn.m10 = 1.0f;
    quarterTurn.m11 = 0.0f;
    scaled.Mult(quarterTurn);

    GmIso4 nonUniformInverse;
    nonUniformInverse.NUScaleSetInverse(scaled);
    GmVec3 scaledPoint{2.0f, 3.0f, 4.0f};
    scaledPoint.Mult(scaled);
    scaledPoint.Mult(nonUniformInverse);
    return VecNear(scaledPoint, {2.0f, 3.0f, 4.0f});
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

bool TestBoxBoxCollision() {
    GmSurf::StaticInit();
    GmSurfBox boxA;
    boxA.m_center = {1.0f, 0.0f, 0.0f};
    boxA.m_extents = {2.0f, 1.0f, 0.5f};
    boxA.m_flags = 31u;
    GmSurfBox boxB;
    boxB.m_center = {0.0f, 0.0f, 0.0f};
    boxB.m_extents = {0.5f, 0.5f, 0.5f};
    boxB.m_flags = 47u;

    LocatedGmSurf locatedA{};
    LocatedGmSurf locatedB{};
    locatedA.m_surf = &boxA;
    locatedB.m_surf = &boxB;
    locatedA.m_location.SetIdentity();
    locatedB.m_location.SetIdentity();
    locatedA.m_location.tX = 10.0f;
    locatedA.m_location.tY = 2.0f;
    locatedA.m_location.tZ = -3.0f;
    locatedB.m_location.tX = 12.9f;
    locatedB.m_location.tY = 2.0f;
    locatedB.m_location.tZ = -3.0f;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {51.0f, 52.0f, 53.0f};
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 2u ||
        !VecNear(buffer.collisions[0].m_vec1, {51.0f, 52.0f, 53.0f})) {
        return false;
    }
    const GmCollision& collision = buffer.collisions[1];
    if (!VecNear(collision.m_vec1, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {1.0f, 1.0f, 1.0f}) ||
        !VecNear(collision.m_vec3, {10.0f, 2.0f, -3.0f}) ||
        collision.m_id1 != 31u || collision.m_id2 != 47u) {
        return false;
    }

    // Equal-type dispatch preserves the caller's order; the sentinel point
    // and IDs therefore come from the newly first box when arguments swap.
    buffer.Clear();
    if (GmSurf::ComputeCollision(&locatedB, &locatedA, &buffer) != 1 ||
        buffer.GetCount() != 1u ||
        !VecNear(buffer.collisions[0].m_vec3, {12.9f, 2.0f, -3.0f}) ||
        buffer.collisions[0].m_id1 != 47u ||
        buffer.collisions[0].m_id2 != 31u) {
        return false;
    }

    // Exact touching is accepted by every native separating-axis comparison.
    buffer.Clear();
    locatedB.m_location.tX = 13.5f;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }

    buffer.Clear();
    locatedB.m_location.tX = 13.5001f;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    // Exercise non-axis-aligned B axes and the nine cross-product tests.
    locatedB.m_location.SetIdentity();
    const float inverseSqrtTwo = 1.0f / std::sqrt(2.0f);
    locatedB.m_location.m00 = inverseSqrtTwo;
    locatedB.m_location.m01 = -inverseSqrtTwo;
    locatedB.m_location.m10 = inverseSqrtTwo;
    locatedB.m_location.m11 = inverseSqrtTwo;
    locatedB.m_location.tX = 11.0f;
    locatedB.m_location.tY = 3.0f;
    locatedB.m_location.tZ = -3.0f;
    return GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) == 1 &&
           buffer.GetCount() == 1u;
}

bool TestBoxMeshCollision() {
    GmSurf::StaticInit();
    GmSurfBox box;
    box.m_center = {0.5f, 0.0f, 0.0f};
    box.m_extents = {1.0f, 1.0f, 1.0f};
    box.m_flags = 53u;

    GmSurfMesh mesh;
    mesh.m_vertices.Add({-2.0f, 0.5f, -2.0f});
    mesh.m_vertices.Add({ 0.0f, 0.5f,  2.0f});
    mesh.m_vertices.Add({ 2.0f, 0.5f, -2.0f});
    GmSurfTriangle triangle{};
    triangle.planeNormal = {0.0f, 1.0f, 0.0f};
    triangle.indices[0] = 0u;
    triangle.indices[1] = 1u;
    triangle.indices[2] = 2u;
    triangle.materialId = 59u;
    mesh.m_triangles.Add(triangle);

    LocatedGmSurf locatedBox{};
    LocatedGmSurf locatedMesh{};
    locatedBox.m_surf = &box;
    locatedMesh.m_surf = &mesh;
    locatedBox.m_location.SetIdentity();
    locatedMesh.m_location.SetIdentity();
    locatedBox.m_location.tX = 10.0f;
    locatedBox.m_location.tY = 5.0f;
    locatedBox.m_location.tZ = -3.0f;
    locatedMesh.m_location = locatedBox.m_location;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {61.0f, 62.0f, 63.0f};
    if (GmSurf::ComputeCollision(&locatedBox, &locatedMesh, &buffer) != 1 ||
        buffer.GetCount() != 2u ||
        !VecNear(buffer.collisions[0].m_vec1, {61.0f, 62.0f, 63.0f})) {
        return false;
    }
    const GmCollision& collision = buffer.collisions[1];
    if (!VecNear(collision.m_vec1, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(collision.m_vec3, {8.0f, 5.5f, -5.0f}) ||
        collision.m_id1 != 53u || collision.m_id2 != 59u) {
        return false;
    }

    buffer.Clear();
    if (GmSurf::ComputeCollision(&locatedMesh, &locatedBox, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {0.0f, -1.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {8.0f, 5.5f, -5.0f}) ||
        reversed.m_id1 != 59u || reversed.m_id2 != 53u) {
        return false;
    }

    // The complete edge-cross-axis SAT rejects the translated triangle.
    buffer.Clear();
    locatedBox.m_location.tY = 8.0f;
    if (GmSurf::ComputeCollision(&locatedBox, &locatedMesh, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    // Transform the mesh normal and first contact vertex through its location.
    locatedBox.m_location.SetIdentity();
    locatedMesh.m_location.SetIdentity();
    locatedMesh.m_location.m00 = 0.0f;
    locatedMesh.m_location.m01 = -1.0f;
    locatedMesh.m_location.m10 = 1.0f;
    locatedMesh.m_location.m11 = 0.0f;
    buffer.Clear();
    return GmSurf::ComputeCollision(&locatedBox, &locatedMesh, &buffer) == 1 &&
           buffer.GetCount() == 1u &&
           VecNear(buffer.collisions[0].m_vec2, {-1.0f, 0.0f, 0.0f}) &&
           VecNear(buffer.collisions[0].m_vec3, {-0.5f, -2.0f, -2.0f});
}

bool TestMeshMeshCollision() {
    GmSurf::StaticInit();
    GmSurfMesh meshA;
    meshA.m_vertices.Add({-2.0f, 0.0f, -2.0f});
    meshA.m_vertices.Add({ 0.0f, 0.0f,  2.0f});
    meshA.m_vertices.Add({ 2.0f, 0.0f, -2.0f});
    GmSurfTriangle triangleA{};
    triangleA.planeNormal = {0.0f, 1.0f, 0.0f};
    triangleA.indices[0] = 0u;
    triangleA.indices[1] = 1u;
    triangleA.indices[2] = 2u;
    triangleA.materialId = 67u;
    meshA.m_triangles.Add(triangleA);

    GmSurfMesh meshB;
    meshB.m_vertices.Add({0.0f, -1.0f, -1.0f});
    meshB.m_vertices.Add({0.0f,  1.0f, -1.0f});
    meshB.m_vertices.Add({0.0f,  0.0f,  1.0f});
    GmSurfTriangle triangleB{};
    triangleB.planeNormal = {1.0f, 0.0f, 0.0f};
    triangleB.indices[0] = 0u;
    triangleB.indices[1] = 1u;
    triangleB.indices[2] = 2u;
    triangleB.materialId = 73u;
    meshB.m_triangles.Add(triangleB);

    LocatedGmSurf locatedA{};
    LocatedGmSurf locatedB{};
    locatedA.m_surf = &meshA;
    locatedB.m_surf = &meshB;
    locatedA.m_location.SetIdentity();
    locatedA.m_location.tX = 10.0f;
    locatedA.m_location.tY = 5.0f;
    locatedA.m_location.tZ = -3.0f;
    locatedB.m_location = locatedA.m_location;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {81.0f, 82.0f, 83.0f};
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 2u ||
        !VecNear(buffer.collisions[0].m_vec1, {81.0f, 82.0f, 83.0f})) {
        return false;
    }
    const GmCollision& collision = buffer.collisions[1];
    if (!VecNear(collision.m_vec1, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec2, {1.0f, 0.0f, 0.0f}) ||
        !VecNear(collision.m_vec3, {8.0f, 5.0f, -5.0f}) ||
        collision.m_id1 != 67u || collision.m_id2 != 73u) {
        return false;
    }

    // Mesh/mesh is an equal-type dispatch, so caller order is preserved.
    buffer.Clear();
    if (GmSurf::ComputeCollision(&locatedB, &locatedA, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {0.0f, 0.0f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {10.0f, 4.0f, -4.0f}) ||
        reversed.m_id1 != 73u || reversed.m_id2 != 67u) {
        return false;
    }

    buffer.Clear();
    locatedB.m_location.tY = 8.0f;
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 0 ||
        buffer.GetCount() != 0u) {
        return false;
    }

    // The native routine has a distinct projected edge/containment path for
    // coplanar triangles. Place B strictly inside A to exercise containment.
    meshB.m_vertices[0] = {-0.5f, 0.0f, -0.5f};
    meshB.m_vertices[1] = { 0.0f, 0.0f,  0.5f};
    meshB.m_vertices[2] = { 0.5f, 0.0f, -0.5f};
    meshB.m_triangles[0].planeNormal = {0.0f, 1.0f, 0.0f};
    locatedB.m_location = locatedA.m_location;
    buffer.Clear();
    if (GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) != 1 ||
        buffer.GetCount() != 1u ||
        !VecNear(buffer.collisions[0].m_vec2, {0.0f, 1.0f, 0.0f})) {
        return false;
    }

    buffer.Clear();
    locatedB.m_location.tX = 15.0f;
    return GmSurf::ComputeCollision(&locatedA, &locatedB, &buffer) == 0 &&
           buffer.GetCount() == 0u;
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

bool TestEllipsoidMeshCollision() {
    GmSurf::StaticInit();
    GmSurfEllipsoid ellipsoid;
    ellipsoid.m_radii = {2.0f, 1.0f, 0.5f};
    ellipsoid.m_flags = 13u;

    GmSurfMesh mesh;
    mesh.m_vertices.Add({-3.0f, 0.0f, -3.0f});
    mesh.m_vertices.Add({ 0.0f, 0.0f,  3.0f});
    mesh.m_vertices.Add({ 3.0f, 0.0f, -3.0f});
    GmSurfTriangle triangle{};
    triangle.planeNormal = {0.0f, 1.0f, 0.0f};
    triangle.indices[0] = 0u;
    triangle.indices[1] = 1u;
    triangle.indices[2] = 2u;
    triangle.materialId = 43u;
    mesh.m_triangles.Add(triangle);

    LocatedGmSurf locatedEllipsoid{};
    LocatedGmSurf locatedMesh{};
    locatedEllipsoid.m_surf = &ellipsoid;
    locatedMesh.m_surf = &mesh;
    locatedEllipsoid.m_location.SetIdentity();
    locatedMesh.m_location.SetIdentity();
    locatedMesh.m_location.tX = 10.0f;
    locatedMesh.m_location.tY = 5.0f;
    locatedMesh.m_location.tZ = -3.0f;
    locatedEllipsoid.m_location.tX = 10.0f;
    locatedEllipsoid.m_location.tY = 5.5f;
    locatedEllipsoid.m_location.tZ = -3.0f;

    TestCollisionBuffer buffer;
    GmCollision* existing = buffer.AddCollision();
    existing->m_vec1 = {71.0f, 72.0f, 73.0f};
    if (GmSurf::ComputeCollision(
            &locatedEllipsoid, &locatedMesh, &buffer) != 1 ||
        buffer.GetCount() != 2u ||
        !VecNear(buffer.collisions[0].m_vec1, {71.0f, 72.0f, 73.0f})) {
        return false;
    }
    const GmCollision& face = buffer.collisions[1];
    if (!VecNear(face.m_vec1, {0.0f, -0.5f, 0.0f}) ||
        !VecNear(face.m_vec2, {0.0f, 1.0f, 0.0f}) ||
        !VecNear(face.m_vec3, {10.0f, 5.0f, -3.0f}) ||
        !VecNear(face.m_vec4, {0.0f, 1.0f, 0.0f}) ||
        face.m_id1 != 13u || face.m_id2 != 43u ||
        FeatureFlag(face) != 1u) {
        return false;
    }

    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedMesh, &locatedEllipsoid, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& reversed = buffer.collisions[0];
    if (!VecNear(reversed.m_vec1, {0.0f, 0.5f, 0.0f}) ||
        !VecNear(reversed.m_vec2, {0.0f, -1.0f, 0.0f}) ||
        !VecNear(reversed.m_vec3, {10.0f, 5.0f, -3.0f}) ||
        !VecNear(reversed.m_vec4, {0.0f, -1.0f, 0.0f}) ||
        reversed.m_id1 != 43u || reversed.m_id2 != 13u) {
        return false;
    }

    // A slanted face distinguishes the inverse-scale normal transform from
    // the scale transform used for points/replacements. The executable does
    // not transform vec4 back out of the temporary unit-sphere frame.
    GmSurfMesh slantedMesh;
    const float inverseSqrtTwo = 1.0f / std::sqrt(2.0f);
    const GmVec3 planeCenter{-inverseSqrtTwo, -inverseSqrtTwo, 0.0f};
    const GmVec3 planeTangent{inverseSqrtTwo, -inverseSqrtTwo, 0.0f};
    const GmVec3 planeZ{0.0f, 0.0f, 1.0f};
    slantedMesh.m_vertices.Add(planeCenter + planeZ * 4.0f);
    slantedMesh.m_vertices.Add(
        planeCenter + planeTangent * 4.0f - planeZ * 4.0f);
    slantedMesh.m_vertices.Add(
        planeCenter - planeTangent * 4.0f - planeZ * 4.0f);
    GmSurfTriangle slantedTriangle{};
    slantedTriangle.indices[0] = 0u;
    slantedTriangle.indices[1] = 1u;
    slantedTriangle.indices[2] = 2u;
    slantedTriangle.materialId = 47u;
    slantedMesh.m_triangles.Add(slantedTriangle);
    LocatedGmSurf locatedSlantedMesh{};
    locatedSlantedMesh.m_surf = &slantedMesh;
    locatedSlantedMesh.m_location.SetIdentity();
    locatedEllipsoid.m_location.SetIdentity();
    buffer.Clear();
    if (GmSurf::ComputeCollision(
            &locatedEllipsoid, &locatedSlantedMesh, &buffer) != 1 ||
        buffer.GetCount() != 1u) {
        return false;
    }
    const GmCollision& slanted = buffer.collisions[0];
    const float inverseSqrtFive = 1.0f / std::sqrt(5.0f);
    const float unitSphereDistance = std::sqrt(2.0f / 5.0f);
    const float unitSphereReplacement = unitSphereDistance - 1.0f;
    if (!VecNear(slanted.m_vec1,
                 {4.0f * inverseSqrtFive * unitSphereReplacement,
                  inverseSqrtFive * unitSphereReplacement,
                  0.0f}, 1.0e-5f) ||
        !VecNear(slanted.m_vec2,
                 {inverseSqrtTwo, inverseSqrtTwo, 0.0f}, 1.0e-5f) ||
        !VecNear(slanted.m_vec3,
                 {-4.0f * std::sqrt(2.0f) / 5.0f,
                  -std::sqrt(2.0f) / 5.0f,
                  0.0f}, 1.0e-5f) ||
        !VecNear(slanted.m_vec4,
                 {2.0f * inverseSqrtFive, inverseSqrtFive, 0.0f},
                 1.0e-5f) ||
        slanted.m_id2 != 47u) {
        return false;
    }

    buffer.Clear();
    locatedEllipsoid.m_location.tY = 4.5f;
    return GmSurf::ComputeCollision(
               &locatedEllipsoid, &locatedMesh, &buffer) == 0 &&
           buffer.GetCount() == 0u;
}

bool TestMeshTransformByNOMat() {
    GmSurfMesh mesh;
    mesh.m_vertices.Add({0.0f, 0.0f, 0.0f});
    mesh.m_vertices.Add({1.0f, 0.0f, 0.0f});
    mesh.m_vertices.Add({0.0f, 1.0f, 0.0f});
    GmSurfTriangle triangle{};
    triangle.planeNormal = {0.0f, 0.0f, 1.0f};
    triangle.planeDist = 0.0f;
    triangle.indices[0] = 0u;
    triangle.indices[1] = 1u;
    triangle.indices[2] = 2u;
    mesh.m_triangles.Add(triangle);

    GmIso4 reflection;
    reflection.SetIdentity();
    reflection.m00 = -1.0f;
    reflection.tZ = 2.0f;
    mesh.TransformByNOMat(reflection);

    const GmSurfTriangle& reflected = mesh.m_triangles[0];
    if (!VecNear(mesh.m_vertices[0], {0.0f, 0.0f, 2.0f}) ||
        !VecNear(mesh.m_vertices[1], {-1.0f, 0.0f, 2.0f}) ||
        !VecNear(mesh.m_vertices[2], {0.0f, 1.0f, 2.0f}) ||
        reflected.indices[0] != 0u || reflected.indices[1] != 2u ||
        reflected.indices[2] != 1u ||
        !VecNear(reflected.planeNormal, {0.0f, 0.0f, 1.0f}) ||
        !Near(reflected.planeDist, -2.0f)) {
        return false;
    }

    // The standalone side table mirrors the native conditional octree
    // rebuild. A translated vertical ray must find the triangle at its new X.
    GmSurfMesh indexed;
    indexed.m_vertices.Add({-2.0f, 0.0f, -2.0f});
    indexed.m_vertices.Add({ 0.0f, 0.0f,  2.0f});
    indexed.m_vertices.Add({ 2.0f, 0.0f, -2.0f});
    GmSurfTriangle indexedTriangle{};
    indexedTriangle.planeNormal = {0.0f, 1.0f, 0.0f};
    indexedTriangle.planeDist = 0.0f;
    indexedTriangle.indices[0] = 0u;
    indexedTriangle.indices[1] = 1u;
    indexedTriangle.indices[2] = 2u;
    indexed.m_triangles.Add(indexedTriangle);
    indexed.BuildOctree();

    GmIso4 translation;
    translation.SetIdentity();
    translation.tX = 100.0f;
    indexed.TransformByNOMat(translation);
    GmIso4 identity;
    identity.SetIdentity();
    float hitT = 1.0f;
    if (indexed.ClipSegment(
            {100.0f, 1.0f, 0.0f}, {0.0f, -2.0f, 0.0f},
            identity, hitT) != 1 ||
        !Near(hitT, 0.5f)) {
        return false;
    }

    // Direct transforms do not enter the native plane-rebuild branch.
    return VecNear(indexed.m_triangles[0].planeNormal,
                   {0.0f, 1.0f, 0.0f}) &&
           Near(indexed.m_triangles[0].planeDist, 0.0f);
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
                        TestSurfaceBoundingBoxesAndDefaults() &&
                        TestNativeCollisionDispatchMatrix() &&
                        TestReversedCollisionDispatch() &&
                        TestSphereSphereCollision() &&
                        TestSphereEllipsoidCollision() &&
                        TestSpherePolygonCollision() &&
                        TestEllipsoidPolygonCollision() &&
                        TestAffinePointTransform() &&
                        TestNativeAffineComposition() &&
                        TestSphereBoxCollision() &&
                        TestBoxBoxCollision() &&
                        TestBoxMeshCollision() &&
                        TestMeshMeshCollision() &&
                        TestSphereMeshCollision() &&
                        TestEllipsoidMeshCollision() &&
                        TestMeshTransformByNOMat() &&
                        TestHmsCollisionBuffer();
    if (!passed) {
        std::fputs("geometry/collision regression: FAIL\n", stderr);
        return 1;
    }
    std::puts("geometry/collision regression: PASS");
    return 0;
}
