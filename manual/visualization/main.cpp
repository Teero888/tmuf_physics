#include <SDL.h>

#include "../../TuningData.hpp"
#include "Classic/CClassicArchive.hpp"
#include "Game/CGameCtnReplayRecord.hpp"
#include "CHmsCorpus.hpp"
#include "Gm/GmSurf.hpp"
#include "Hms/CHmsCollisionManager.hpp"
#include "Hms/CHmsDyna.hpp"
#include "Hms/CHmsItem.hpp"
#include "Hms/CHmsZoneDynamic.hpp"
#include "Hms/CHmsForceFieldUniform.hpp"
#include "Plug/CPlugPhysicalObject.hpp"
#include "Plug/CPlugSolid.hpp"
#include "Plug/CPlugSurface.hpp"
#include "Plug/CPlugSurfaceGeom.hpp"
#include "Plug/CPlugTree.hpp"
#include "Scene/CCallbackSceneVehicleCarComputeForces.hpp"
#include "Scene/CCallbackSceneVehicleCarAfterContacts.hpp"
#include "Scene/CSceneMobilAbsorbContact.hpp"
#include "Scene/CSceneVehicleCar.hpp"
#include "Scene/CSceneVehicleCarTuning.hpp"
#include "Scene/TmForeverPhysicsConstants.hpp"
#include "Scene/VehicleGroundSupport.hpp"
#include "Track/TrackMapLoader.hpp"
#include "Track/VehicleAssetLoader.hpp"
#include "VehicleTrackSimulation.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

extern CSceneVehicleCarTuning* g_tuning;

namespace {

constexpr float kPhysicsDt = 0.01f;
constexpr int kMaxCatchUpSteps = 5;
constexpr float kPi = 3.14159265358979323846f;
constexpr GmVec3 kDefaultStart{171.199997f, 90.209999f, 688.0f};
constexpr float kDefaultYaw = kPi * 0.5f;

// Wireframe draws mesh edges; Solid draws shaded faces with a painter's
// depth sort. See the rendering section below.
enum class RenderStyle {
    Wireframe,
    Solid,
};

struct Options {
    std::string mapPath;
    std::string packsDirectory;
    std::string extractorProject;
    std::string cacheDirectory;
    std::string screenshotPath;
    std::string replayPath;
    GmVec3 start = kDefaultStart;
    float yaw = kDefaultYaw;
    float automaticGas = 0.0f;
    float automaticBrake = 0.0f;
    float automaticSteer = 0.0f;
    int frameLimit = -1;
    int simulationStepLimit = -1;
    int traceEvery = 0;
    int screenshotFrame = 1;
    float topDownZoom = 7.0f;
    float chaseDistance = 13.0f;
    RenderStyle style = RenderStyle::Solid;
    bool topDown = false;
    bool forceCacheRebuild = false;
    bool useReplayInputs = false;
};

struct ViewState {
    bool topDown = false;
    RenderStyle style = RenderStyle::Solid;
    // Solid mode only. Off shows both sides of every surface, which is the
    // honest view of a collision mesh; on halves the work and removes the
    // painter's-algorithm artefacts you get from drawing hidden backfaces.
    bool cullBackFaces = true;
    float topDownZoom = 7.0f;
    float chaseDistance = 13.0f;
};

struct Camera {
    GmVec3 position;
    GmVec3 right;
    GmVec3 up;
    GmVec3 forward;
    float focalLength = 1.0f;
    float nearPlane = 0.15f;
    int width = 1;
    int height = 1;
};

float LengthSquared(const GmVec3& value) {
    return GmVec3::Dot(value, value);
}

GmVec3 Normalized(GmVec3 value) {
    if (LengthSquared(value) > 1.0e-10f) value.Normalize();
    return value;
}

// ---------------------------------------------------------------------------
// Batched scene rendering
//
// The straightforward version of this viewer walked every collision triangle
// each frame and issued three SDL_RenderDrawLineF calls per triangle, with a
// draw-colour change in between. On A01 that is ~290k triangles, so roughly
// 870k SDL calls per frame, and the interactive view spent essentially all of
// its time there.
//
// Instead each mesh is preprocessed once into a deduplicated edge list and a
// face list, both indexed by a uniform grid over the XZ plane. Per frame we
// visit only the cells near the car, project every vertex at most once, and
// push everything through a single batched SDL_RenderGeometryRaw call.
//
// Two view styles are available. Wireframe draws mesh edges as thin quads.
// Solid draws shaded faces with a painter's-algorithm depth sort, which is
// what SDL's 2D renderer allows without a depth buffer.
// ---------------------------------------------------------------------------

// Half the on-screen thickness of a wireframe segment. Segments are emitted as
// quads, so they also get extended by this much at each end; that keeps very
// short segments covering at least one pixel centre, the way GL_LINES does.
constexpr float kLineHalfWidth = 0.55f;
// Segments smaller than this in both axes are dropped; see AddProjectedSegment.
constexpr float kMinSegmentPixels = 0.9f;

class LineBatch {
public:
    void Begin(SDL_Renderer* target) {
        renderer = target;
        positions.clear();
        colors.clear();
        indices.clear();
        segments = 0;
    }

    void Add(float ax, float ay, float bx, float by, const SDL_Color& color) {
        float dx = bx - ax;
        float dy = by - ay;
        float length = std::sqrt(dx * dx + dy * dy);
        if (!(length > 1.0e-4f)) {
            dx = 1.0f;
            dy = 0.0f;
            length = 1.0f;
        }
        const float scale = kLineHalfWidth / length;
        const float widthX = -dy * scale;
        const float widthY = dx * scale;
        const float capX = dx * scale;
        const float capY = dy * scale;
        const int base = static_cast<int>(positions.size() / 2u);
        Push(ax - capX + widthX, ay - capY + widthY, color);
        Push(ax - capX - widthX, ay - capY - widthY, color);
        Push(bx + capX + widthX, by + capY + widthY, color);
        Push(bx + capX - widthX, by + capY - widthY, color);
        static constexpr int kQuad[6] = {0, 1, 2, 2, 1, 3};
        for (const int corner : kQuad) indices.push_back(base + corner);
        ++segments;
        if (positions.size() >= kFlushVertexFloats) Flush();
    }

    void Flush() {
        if (renderer == nullptr || indices.empty()) return;
        SDL_RenderGeometryRaw(
            renderer, nullptr,
            positions.data(), static_cast<int>(sizeof(float) * 2u),
            colors.data(), static_cast<int>(sizeof(SDL_Color)),
            nullptr, 0,
            static_cast<int>(positions.size() / 2u),
            indices.data(), static_cast<int>(indices.size()),
            static_cast<int>(sizeof(int)));
        positions.clear();
        colors.clear();
        indices.clear();
    }

    int SegmentCount() const { return segments; }

private:
    // 64k vertices per draw call keeps the transient buffers small without
    // meaningfully increasing the draw-call count for any view we produce.
    static constexpr size_t kFlushVertexFloats = 128000u;

    void Push(float x, float y, const SDL_Color& color) {
        positions.push_back(x);
        positions.push_back(y);
        colors.push_back(color);
    }

    SDL_Renderer* renderer = nullptr;
    std::vector<float> positions;
    std::vector<SDL_Color> colors;
    std::vector<int> indices;
    int segments = 0;
};

// Collects flat-shaded screen-space triangles for one frame, then emits them
// back to front. SDL's renderer has no depth buffer, so ordering is the only
// thing standing between us and a scrambled image. Sorting is a counting sort
// over quantised depth: exact ordering does not matter within a bucket, and a
// comparison sort of ~100k faces would cost more than the draw itself.
class SurfaceBatch {
public:
    void Begin(SDL_Renderer* target) {
        renderer = target;
        positions.clear();
        colors.clear();
        depths.clear();
        vertices.clear();
        vertexColors.clear();
        indices.clear();
        minDepth = std::numeric_limits<float>::max();
        maxDepth = -std::numeric_limits<float>::max();
    }

    // `sortDepth` increases with distance from the viewer.
    void Add(
        float ax, float ay, float bx, float by, float cx, float cy,
        float sortDepth, const SDL_Color& color) {
        positions.push_back(ax);
        positions.push_back(ay);
        positions.push_back(bx);
        positions.push_back(by);
        positions.push_back(cx);
        positions.push_back(cy);
        colors.push_back(color);
        depths.push_back(sortDepth);
        minDepth = std::min(minDepth, sortDepth);
        maxDepth = std::max(maxDepth, sortDepth);
    }

    void Flush() {
        const size_t faceCount = depths.size();
        if (renderer == nullptr || faceCount == 0u) return;

        // Counting sort, farthest bucket first.
        const float span = std::max(maxDepth - minDepth, 1.0e-3f);
        const float scale = (kDepthBuckets - 1) / span;
        bucketCounts.assign(kDepthBuckets + 1u, 0u);
        bucketOf.resize(faceCount);
        for (size_t face = 0; face < faceCount; ++face) {
            const int bucket = std::clamp(
                static_cast<int>((depths[face] - minDepth) * scale),
                0, kDepthBuckets - 1);
            // Reverse so that bucket 0 holds the farthest faces.
            const uint32_t slot = kDepthBuckets - 1 - bucket;
            bucketOf[face] = slot;
            ++bucketCounts[slot + 1u];
        }
        for (int bucket = 0; bucket < kDepthBuckets; ++bucket) {
            bucketCounts[bucket + 1u] += bucketCounts[bucket];
        }
        order.resize(faceCount);
        for (size_t face = 0; face < faceCount; ++face) {
            order[bucketCounts[bucketOf[face]]++] = static_cast<uint32_t>(face);
        }

        vertices.clear();
        vertexColors.clear();
        indices.clear();
        vertices.reserve(faceCount * 6u);
        vertexColors.reserve(faceCount * 3u);
        indices.reserve(faceCount * 3u);
        for (const uint32_t face : order) {
            const float* xy = &positions[static_cast<size_t>(face) * 6u];
            const int base = static_cast<int>(vertexColors.size());
            for (int corner = 0; corner < 3; ++corner) {
                vertices.push_back(xy[corner * 2]);
                vertices.push_back(xy[corner * 2 + 1]);
                vertexColors.push_back(colors[face]);
                indices.push_back(base + corner);
            }
            if (vertexColors.size() >= kFlushVertices) Emit();
        }
        Emit();

        positions.clear();
        colors.clear();
        depths.clear();
        minDepth = std::numeric_limits<float>::max();
        maxDepth = -std::numeric_limits<float>::max();
    }

    int FaceCount() const { return static_cast<int>(depths.size()); }

private:
    static constexpr int kDepthBuckets = 4096;
    static constexpr size_t kFlushVertices = 60000u;

    void Emit() {
        if (indices.empty()) return;
        SDL_RenderGeometryRaw(
            renderer, nullptr,
            vertices.data(), static_cast<int>(sizeof(float) * 2u),
            vertexColors.data(), static_cast<int>(sizeof(SDL_Color)),
            nullptr, 0,
            static_cast<int>(vertexColors.size()),
            indices.data(), static_cast<int>(indices.size()),
            static_cast<int>(sizeof(int)));
        vertices.clear();
        vertexColors.clear();
        indices.clear();
    }

    SDL_Renderer* renderer = nullptr;
    std::vector<float> positions;    // 6 floats per face
    std::vector<SDL_Color> colors;   // 1 per face
    std::vector<float> depths;       // 1 per face
    std::vector<uint32_t> bucketCounts;
    std::vector<uint32_t> bucketOf;
    std::vector<uint32_t> order;
    std::vector<float> vertices;
    std::vector<SDL_Color> vertexColors;
    std::vector<int> indices;
    float minDepth = 0.0f;
    float maxDepth = 0.0f;
};

struct ViewProjection {
    RenderStyle style = RenderStyle::Wireframe;
    bool topDown = false;
    Camera camera;                  // chase view
    GmVec3 origin;                  // top-down view centre
    // Top-down orientation. `screenRight` is derived rather than taken from
    // VehicleChassisBasis::right, which is the native car-local +X axis and so
    // points to the car's *left*; see Scene/VehicleGroundSupport.hpp.
    GmVec3 screenRight;
    GmVec3 screenForward;
    float zoom = 1.0f;
    int width = 1;
    int height = 1;
    float fogStart = 40.0f;
    float fogEnd = 150.0f;
    bool cullBackFaces = false;
};

// Horizontal wedge approximating the chase camera's field of view, used to
// reject whole grid cells before touching their contents. Cells are treated as
// infinite vertical columns, so the test is deliberately loose: it exists to
// throw away everything behind and far to the side of the camera, and the
// per-primitive screen-bounds check handles the rest.
class ViewWedge {
public:
    explicit ViewWedge(const ViewProjection& view) {
        if (view.topDown) return;
        float forwardX = view.camera.forward.x;
        float forwardZ = view.camera.forward.z;
        const float forwardLength =
            std::sqrt(forwardX * forwardX + forwardZ * forwardZ);
        if (forwardLength < 1.0e-3f) return;
        forwardX /= forwardLength;
        forwardZ /= forwardLength;
        // camera.right is built from the world up vector, so it is horizontal.
        m_rightX = view.camera.right.x;
        m_rightZ = view.camera.right.z;
        const float rightLength =
            std::sqrt(m_rightX * m_rightX + m_rightZ * m_rightZ);
        if (rightLength < 1.0e-3f) return;
        m_rightX /= rightLength;
        m_rightZ /= rightLength;
        m_forwardX = forwardX;
        m_forwardZ = forwardZ;
        m_eyeX = view.camera.position.x;
        m_eyeZ = view.camera.position.z;
        // Widen by the off-screen margin the segment/face culls already allow,
        // then by the camera pitch, which spreads the on-screen area out over
        // a wider horizontal angle than the focal length alone implies.
        m_tangent = (view.width * 0.5f + kScreenMargin) /
            view.camera.focalLength / forwardLength;
        m_active = true;
    }

    bool Overlaps(float minX, float minZ, float maxX, float maxZ) const {
        if (!m_active) return true;
        const float centerX = (minX + maxX) * 0.5f - m_eyeX;
        const float centerZ = (minZ + maxZ) * 0.5f - m_eyeZ;
        const float halfX = (maxX - minX) * 0.5f;
        const float halfZ = (maxZ - minZ) * 0.5f;
        const float forwardMax =
            centerX * m_forwardX + centerZ * m_forwardZ +
            std::abs(m_forwardX) * halfX + std::abs(m_forwardZ) * halfZ;
        if (forwardMax < -kDepthSlack) return false;
        const float lateralHalf =
            std::abs(m_rightX) * halfX + std::abs(m_rightZ) * halfZ;
        const float lateralMin = std::max(
            0.0f,
            std::abs(centerX * m_rightX + centerZ * m_rightZ) - lateralHalf);
        return lateralMin <=
            m_tangent * std::max(forwardMax, 0.0f) + kLateralSlack;
    }

private:
    static constexpr float kScreenMargin = 220.0f;
    // Vertical extent that a column may exploit to stay visible despite
    // sitting behind or beside the camera in plan view.
    static constexpr float kDepthSlack = 24.0f;
    static constexpr float kLateralSlack = 24.0f;

    bool m_active = false;
    float m_eyeX = 0.0f;
    float m_eyeZ = 0.0f;
    float m_forwardX = 0.0f;
    float m_forwardZ = 0.0f;
    float m_rightX = 0.0f;
    float m_rightZ = 0.0f;
    float m_tangent = 1.0f;
};

// Camera-space position for the chase view, screen position for the top-down
// view (where z stays 1 so the near-plane clip is a no-op). `depth` always
// grows with distance from the viewer, so it sorts the same way in both.
struct ProjectedVertex {
    float x = 0.0f;
    float y = 0.0f;
    float z = 1.0f;
    float depth = 0.0f;
};

ProjectedVertex ProjectVertex(const ViewProjection& view, const GmVec3& world) {
    if (view.topDown) {
        const GmVec3 relative = world - view.origin;
        return {
            view.width * 0.5f +
                GmVec3::Dot(relative, view.screenRight) * view.zoom,
            view.height * 0.62f -
                GmVec3::Dot(relative, view.screenForward) * view.zoom,
            1.0f,
            -world.y,
        };
    }
    const GmVec3 relative = world - view.camera.position;
    const float cameraZ = GmVec3::Dot(relative, view.camera.forward);
    return {
        GmVec3::Dot(relative, view.camera.right),
        GmVec3::Dot(relative, view.camera.up),
        cameraZ,
        cameraZ,
    };
}

void ToScreen(
    const ViewProjection& view, const ProjectedVertex& vertex,
    float& screenX, float& screenY) {
    if (view.topDown) {
        screenX = vertex.x;
        screenY = vertex.y;
        return;
    }
    const float focalLength = view.camera.focalLength;
    screenX = view.width * 0.5f + vertex.x * focalLength / vertex.z;
    screenY = view.height * 0.5f - vertex.y * focalLength / vertex.z;
}

bool AddProjectedSegment(
    LineBatch& batch, const ViewProjection& view,
    ProjectedVertex a, ProjectedVertex b, const SDL_Color& color) {
    if (!view.topDown) {
        const float nearPlane = view.camera.nearPlane;
        if (a.z < nearPlane && b.z < nearPlane) return false;
        if (a.z < nearPlane) {
            const float amount = (nearPlane - a.z) / (b.z - a.z);
            a.x += (b.x - a.x) * amount;
            a.y += (b.y - a.y) * amount;
            a.z = nearPlane;
        } else if (b.z < nearPlane) {
            const float amount = (nearPlane - b.z) / (a.z - b.z);
            b.x += (a.x - b.x) * amount;
            b.y += (a.y - b.y) * amount;
            b.z = nearPlane;
        }
    }
    float ax = 0.0f;
    float ay = 0.0f;
    float bx = 0.0f;
    float by = 0.0f;
    ToScreen(view, a, ax, ay);
    ToScreen(view, b, bx, by);
    constexpr float margin = 200.0f;
    if ((ax < -margin && bx < -margin) ||
        (ax > view.width + margin && bx > view.width + margin) ||
        (ay < -margin && by < -margin) ||
        (ay > view.height + margin && by > view.height + margin)) {
        return false;
    }
    // Dense meshes project a great many sub-pixel edges that cost a full quad
    // each and land on a pixel some neighbouring edge already covers.
    if (std::abs(bx - ax) < kMinSegmentPixels &&
        std::abs(by - ay) < kMinSegmentPixels) {
        return false;
    }
    batch.Add(ax, ay, bx, by, color);
    return true;
}

bool AddWorldSegment(
    LineBatch& batch, const ViewProjection& view,
    const GmVec3& a, const GmVec3& b, const SDL_Color& color) {
    return AddProjectedSegment(
        batch, view, ProjectVertex(view, a), ProjectVertex(view, b), color);
}

// Sutherland-Hodgman against the single near plane. A triangle clips to at
// most four vertices, which we then fan-triangulate.
int ClipAgainstNearPlane(
    const ProjectedVertex* input, int inputCount, float nearPlane,
    ProjectedVertex* output) {
    int outputCount = 0;
    for (int i = 0; i < inputCount; ++i) {
        const ProjectedVertex& current = input[i];
        const ProjectedVertex& next = input[(i + 1) % inputCount];
        const bool currentInside = current.z >= nearPlane;
        const bool nextInside = next.z >= nearPlane;
        if (currentInside) output[outputCount++] = current;
        if (currentInside != nextInside) {
            const float amount =
                (nearPlane - current.z) / (next.z - current.z);
            output[outputCount].x =
                current.x + (next.x - current.x) * amount;
            output[outputCount].y =
                current.y + (next.y - current.y) * amount;
            output[outputCount].z = nearPlane;
            output[outputCount].depth =
                current.depth + (next.depth - current.depth) * amount;
            ++outputCount;
        }
    }
    return outputCount;
}

// ---------------------------------------------------------------------------
// Shading
// ---------------------------------------------------------------------------

struct SurfaceMaterial {
    float red;
    float green;
    float blue;
};

// Slope-shaded palettes matching the original per-triangle colouring: mostly
// horizontal, sloped, and near-vertical surfaces.
constexpr SDL_Color kTrackWirePalette[3] = {
    {86, 101, 104, 185},
    {71, 91, 105, 175},
    {58, 76, 92, 165},
};
constexpr SurfaceMaterial kTrackSolidPalette[3] = {
    {118.0f, 134.0f, 138.0f},
    {104.0f, 124.0f, 140.0f},
    {88.0f, 106.0f, 124.0f},
};
constexpr SDL_Color kStadiumWireColor{47, 59, 72, 145};
constexpr SurfaceMaterial kStadiumSolidColor{74, 88, 104};
constexpr SDL_Color kCarWireColor{246, 187, 57, 255};
constexpr SurfaceMaterial kCarSolidColor{246, 187, 57};
constexpr SDL_Color kTrailColor{235, 108, 67, 220};
constexpr SDL_Color kWheelGroundedColor{70, 220, 70, 255};
constexpr SDL_Color kWheelAirborneColor{238, 72, 70, 255};
constexpr SDL_Color kChassisUpColor{72, 220, 115, 255};

// Key light roughly over the driver's left shoulder, plus enough ambient that
// faces turned away stay readable.
constexpr float kLightX = 0.40f;
constexpr float kLightY = 0.82f;
constexpr float kLightZ = 0.41f;
constexpr float kAmbient = 0.34f;
// Background colour, also what distant faces fade into.
constexpr float kBackgroundRed = 13.0f;
constexpr float kBackgroundGreen = 17.0f;
constexpr float kBackgroundBlue = 23.0f;

SDL_Color ShadeSurface(
    const ViewProjection& view, const SurfaceMaterial& material,
    const GmVec3& normal, bool faceTowardsViewer, float distance) {
    const float side = faceTowardsViewer ? 1.0f : -1.0f;
    const float lambert = std::max(
        0.0f,
        side * (normal.x * kLightX + normal.y * kLightY + normal.z * kLightZ));
    const float intensity = kAmbient + (1.0f - kAmbient) * lambert;
    float red = material.red * intensity;
    float green = material.green * intensity;
    float blue = material.blue * intensity;
    if (!view.topDown && view.fogEnd > view.fogStart) {
        const float fog = std::clamp(
            (distance - view.fogStart) / (view.fogEnd - view.fogStart),
            0.0f, 1.0f) * 0.88f;
        red += (kBackgroundRed - red) * fog;
        green += (kBackgroundGreen - green) * fog;
        blue += (kBackgroundBlue - blue) * fog;
    }
    return SDL_Color{
        static_cast<uint8_t>(std::clamp(red, 0.0f, 255.0f)),
        static_cast<uint8_t>(std::clamp(green, 0.0f, 255.0f)),
        static_cast<uint8_t>(std::clamp(blue, 0.0f, 255.0f)),
        255,
    };
}

// Projects, clips and emits one shaded triangle. `normal` and `centroid` are
// in world space; lighting is two-sided so meshes with inconsistent winding
// still read correctly.
bool AddProjectedFace(
    SurfaceBatch& batch, const ViewProjection& view,
    const ProjectedVertex& a, const ProjectedVertex& b,
    const ProjectedVertex& c, const GmVec3& normal, const GmVec3& centroid,
    const SurfaceMaterial& material) {
    const bool towardsViewer = view.topDown
        ? normal.y > 0.0f
        : GmVec3::Dot(normal, view.camera.position - centroid) > 0.0f;
    if (view.cullBackFaces && !towardsViewer) return false;

    const ProjectedVertex input[3] = {a, b, c};
    ProjectedVertex clipped[4];
    const int count = view.topDown
        ? (clipped[0] = a, clipped[1] = b, clipped[2] = c, 3)
        : ClipAgainstNearPlane(input, 3, view.camera.nearPlane, clipped);
    if (count < 3) return false;

    float screenX[4];
    float screenY[4];
    float lowX = std::numeric_limits<float>::max();
    float highX = -std::numeric_limits<float>::max();
    float lowY = lowX;
    float highY = highX;
    float depth = 0.0f;
    for (int i = 0; i < count; ++i) {
        ToScreen(view, clipped[i], screenX[i], screenY[i]);
        lowX = std::min(lowX, screenX[i]);
        highX = std::max(highX, screenX[i]);
        lowY = std::min(lowY, screenY[i]);
        highY = std::max(highY, screenY[i]);
        depth += clipped[i].depth;
    }
    if (highX < 0.0f || lowX > view.width ||
        highY < 0.0f || lowY > view.height) {
        return false;
    }
    depth /= static_cast<float>(count);

    const SDL_Color color =
        ShadeSurface(view, material, normal, towardsViewer, depth);
    for (int i = 2; i < count; ++i) {
        batch.Add(
            screenX[0], screenY[0], screenX[i - 1], screenY[i - 1],
            screenX[i], screenY[i], depth, color);
    }
    return true;
}

uint8_t TrackColorIndex(const GmSurfTriangle& triangle) {
    const float up = std::abs(triangle.planeNormal.y);
    if (up > 0.72f) return 0u;
    return up > 0.25f ? 1u : 2u;
}

// Deduplicated triangle edges. Packing the pair into one integer lets us sort
// and unique instead of hashing, which matters at ~740k raw edges.
std::vector<uint64_t> BuildUniqueEdges(GmSurfMesh& mesh, bool slopeColors) {
    const uint32_t vertexCount = mesh.m_vertices.GetCount();
    const uint32_t triangleCount = mesh.m_triangles.GetCount();
    std::vector<uint64_t> edges;
    if (vertexCount == 0u || triangleCount == 0u ||
        vertexCount >= (1u << 24)) {
        return edges;
    }
    edges.reserve(static_cast<size_t>(triangleCount) * 3u);
    for (uint32_t i = 0; i < triangleCount; ++i) {
        const GmSurfTriangle& triangle = mesh.m_triangles[i];
        if (triangle.indices[0] >= vertexCount ||
            triangle.indices[1] >= vertexCount ||
            triangle.indices[2] >= vertexCount) {
            continue;
        }
        const uint64_t color = slopeColors ? TrackColorIndex(triangle) : 0u;
        for (int corner = 0; corner < 3; ++corner) {
            const uint32_t first = triangle.indices[corner];
            const uint32_t second = triangle.indices[(corner + 1) % 3];
            if (first == second) continue;
            const uint64_t low = std::min(first, second);
            const uint64_t high = std::max(first, second);
            edges.push_back((low << 40) | (high << 16) | color);
        }
    }
    std::sort(edges.begin(), edges.end());
    // Sorting by the whole key groups shared edges together and makes the
    // colour of a shared edge deterministic (the flattest of its faces wins).
    edges.erase(
        std::unique(
            edges.begin(), edges.end(),
            [](uint64_t a, uint64_t b) { return (a >> 16) == (b >> 16); }),
        edges.end());
    return edges;
}

// Uniform grid over the XZ plane. Items are bucketed by their bounding box, so
// a query can return the same item from several cells; callers deduplicate
// with a per-frame stamp.
class SpatialGrid {
public:
    // `bounds` yields minX, minZ, maxX, maxZ for an item.
    template <typename BoundsFn>
    void Build(
        size_t itemCount, float minX, float minZ, float maxX, float maxZ,
        BoundsFn&& bounds) {
        m_cellsX = 1;
        m_cellsZ = 1;
        m_cellStart.assign(2u, 0u);
        m_cellItems.clear();
        if (itemCount == 0u) return;

        const float spanX = std::max(maxX - minX, 1.0f);
        const float spanZ = std::max(maxZ - minZ, 1.0f);
        // Roughly one block of track per cell, capped so that a pathological
        // mesh extent cannot blow the grid up.
        m_cellSize = std::max(
            {16.0f, spanX / kMaxCellsPerAxis, spanZ / kMaxCellsPerAxis});
        m_originX = minX;
        m_originZ = minZ;
        m_cellsX = static_cast<int>(spanX / m_cellSize) + 1;
        m_cellsZ = static_cast<int>(spanZ / m_cellSize) + 1;

        const size_t cellCount =
            static_cast<size_t>(m_cellsX) * static_cast<size_t>(m_cellsZ);
        m_cellStart.assign(cellCount + 1u, 0u);
        for (size_t item = 0; item < itemCount; ++item) {
            ForEachCell(bounds, item, [&](size_t cell) {
                ++m_cellStart[cell + 1u];
            });
        }
        for (size_t cell = 0; cell < cellCount; ++cell) {
            m_cellStart[cell + 1u] += m_cellStart[cell];
        }
        m_cellItems.resize(m_cellStart[cellCount]);
        std::vector<uint32_t> cursor(
            m_cellStart.begin(), m_cellStart.end() - 1);
        for (size_t item = 0; item < itemCount; ++item) {
            ForEachCell(bounds, item, [&](size_t cell) {
                m_cellItems[cursor[cell]++] = static_cast<uint32_t>(item);
            });
        }
    }

    // Visits every item index stored in a cell that comes within `radius` of
    // (centerX, centerZ) and survives the view wedge. Indices may repeat.
    template <typename Visitor>
    void ForEachNear(
        float centerX, float centerZ, float radius, const ViewWedge& wedge,
        Visitor&& visit) const {
        if (m_cellItems.empty()) return;
        const float radiusSquared = radius * radius;
        const int lowX = CellX(centerX - radius);
        const int highX = CellX(centerX + radius);
        const int lowZ = CellZ(centerZ - radius);
        const int highZ = CellZ(centerZ + radius);
        for (int cellZ = lowZ; cellZ <= highZ; ++cellZ) {
            for (int cellX = lowX; cellX <= highX; ++cellX) {
                if (!CellReachesCircle(
                        cellX, cellZ, centerX, centerZ, radiusSquared)) {
                    continue;
                }
                const float boxX = m_originX + cellX * m_cellSize;
                const float boxZ = m_originZ + cellZ * m_cellSize;
                if (!wedge.Overlaps(
                        boxX, boxZ, boxX + m_cellSize, boxZ + m_cellSize)) {
                    continue;
                }
                const size_t cell =
                    static_cast<size_t>(cellZ) * m_cellsX + cellX;
                for (uint32_t slot = m_cellStart[cell];
                     slot < m_cellStart[cell + 1u]; ++slot) {
                    visit(m_cellItems[slot]);
                }
            }
        }
    }

private:
    static constexpr float kMaxCellsPerAxis = 1024.0f;
    static constexpr size_t kMaxCellsPerItem = 64u;

    int CellX(float worldX) const {
        return std::clamp(
            static_cast<int>(std::floor((worldX - m_originX) / m_cellSize)),
            0, m_cellsX - 1);
    }

    int CellZ(float worldZ) const {
        return std::clamp(
            static_cast<int>(std::floor((worldZ - m_originZ) / m_cellSize)),
            0, m_cellsZ - 1);
    }

    bool CellReachesCircle(
        int cellX, int cellZ, float centerX, float centerZ,
        float radiusSquared) const {
        const float lowX = m_originX + cellX * m_cellSize;
        const float lowZ = m_originZ + cellZ * m_cellSize;
        const float nearestX = std::clamp(centerX, lowX, lowX + m_cellSize);
        const float nearestZ = std::clamp(centerZ, lowZ, lowZ + m_cellSize);
        const float dx = centerX - nearestX;
        const float dz = centerZ - nearestZ;
        return dx * dx + dz * dz <= radiusSquared;
    }

    // Items whose bounding box would land in an unreasonable number of cells
    // are pinned to their centre cell instead; the meshes we load have none,
    // but a stray degenerate vertex should not cost gigabytes.
    template <typename BoundsFn, typename Visitor>
    void ForEachCell(BoundsFn& bounds, size_t item, Visitor&& visit) const {
        float minX = 0.0f;
        float minZ = 0.0f;
        float maxX = 0.0f;
        float maxZ = 0.0f;
        bounds(item, minX, minZ, maxX, maxZ);
        int lowX = CellX(minX);
        int highX = CellX(maxX);
        int lowZ = CellZ(minZ);
        int highZ = CellZ(maxZ);
        if (static_cast<size_t>(highX - lowX + 1) *
                static_cast<size_t>(highZ - lowZ + 1) > kMaxCellsPerItem) {
            lowX = highX = CellX((minX + maxX) * 0.5f);
            lowZ = highZ = CellZ((minZ + maxZ) * 0.5f);
        }
        for (int cellZ = lowZ; cellZ <= highZ; ++cellZ) {
            for (int cellX = lowX; cellX <= highX; ++cellX) {
                visit(static_cast<size_t>(cellZ) * m_cellsX + cellX);
            }
        }
    }

    float m_cellSize = 16.0f;
    float m_originX = 0.0f;
    float m_originZ = 0.0f;
    int m_cellsX = 1;
    int m_cellsZ = 1;
    std::vector<uint32_t> m_cellStart;
    std::vector<uint32_t> m_cellItems;
};

// A mesh that never moves, flattened into edges and faces with a grid over
// each so that only geometry near the car is touched per frame.
class StaticGeometry {
public:
    void Build(GmSurfMesh& mesh, bool slopeColors) {
        m_slopeColors = slopeColors;
        const uint32_t vertexCount = mesh.m_vertices.GetCount();
        m_vertices.resize(vertexCount);
        for (uint32_t i = 0; i < vertexCount; ++i) {
            m_vertices[i] = mesh.m_vertices[i];
        }

        const uint32_t triangleCount = mesh.m_triangles.GetCount();
        m_faces.reserve(triangleCount);
        for (uint32_t i = 0; i < triangleCount; ++i) {
            const GmSurfTriangle& triangle = mesh.m_triangles[i];
            if (triangle.indices[0] >= vertexCount ||
                triangle.indices[1] >= vertexCount ||
                triangle.indices[2] >= vertexCount) {
                continue;
            }
            m_faces.push_back(triangle);
        }

        for (const uint64_t key : BuildUniqueEdges(mesh, slopeColors)) {
            m_edges.push_back(Edge{
                static_cast<uint32_t>(key >> 40),
                static_cast<uint32_t>((key >> 16) & 0xffffffu),
                static_cast<uint8_t>(key & 0xffu)});
        }

        float minX = 0.0f;
        float minZ = 0.0f;
        float maxX = 0.0f;
        float maxZ = 0.0f;
        if (!m_vertices.empty()) {
            minX = maxX = m_vertices[0].x;
            minZ = maxZ = m_vertices[0].z;
            for (const GmVec3& vertex : m_vertices) {
                minX = std::min(minX, vertex.x);
                maxX = std::max(maxX, vertex.x);
                minZ = std::min(minZ, vertex.z);
                maxZ = std::max(maxZ, vertex.z);
            }
        }
        m_edgeGrid.Build(
            m_edges.size(), minX, minZ, maxX, maxZ,
            [this](size_t index, float& lowX, float& lowZ, float& highX,
                   float& highZ) {
                const GmVec3& a = m_vertices[m_edges[index].a];
                const GmVec3& b = m_vertices[m_edges[index].b];
                lowX = std::min(a.x, b.x);
                highX = std::max(a.x, b.x);
                lowZ = std::min(a.z, b.z);
                highZ = std::max(a.z, b.z);
            });
        m_faceGrid.Build(
            m_faces.size(), minX, minZ, maxX, maxZ,
            [this](size_t index, float& lowX, float& lowZ, float& highX,
                   float& highZ) {
                const GmSurfTriangle& face = m_faces[index];
                const GmVec3& a = m_vertices[face.indices[0]];
                const GmVec3& b = m_vertices[face.indices[1]];
                const GmVec3& c = m_vertices[face.indices[2]];
                lowX = std::min({a.x, b.x, c.x});
                highX = std::max({a.x, b.x, c.x});
                lowZ = std::min({a.z, b.z, c.z});
                highZ = std::max({a.z, b.z, c.z});
            });

        m_projected.resize(m_vertices.size());
        m_vertexStamp.assign(m_vertices.size(), 0u);
        m_edgeStamp.assign(m_edges.size(), 0u);
        m_faceStamp.assign(m_faces.size(), 0u);
    }

    size_t EdgeCount() const { return m_edges.size(); }
    size_t FaceCount() const { return m_faces.size(); }

    // Invalidates the cached vertex projections; call once per frame before
    // drawing, since the projection changes with the camera.
    void BeginFrame() {
        if (++m_frame == 0u) {
            std::fill(m_vertexStamp.begin(), m_vertexStamp.end(), 0u);
            std::fill(m_edgeStamp.begin(), m_edgeStamp.end(), 0u);
            std::fill(m_faceStamp.begin(), m_faceStamp.end(), 0u);
            m_frame = 1u;
        }
    }

    int DrawWireframe(
        LineBatch& batch, const ViewProjection& view, const ViewWedge& wedge,
        const GmVec3& center, float radius) {
        if (m_edges.empty()) return 0;
        int drawn = 0;
        m_edgeGrid.ForEachNear(
            center.x, center.z, radius, wedge, [&](uint32_t edgeIndex) {
                if (m_edgeStamp[edgeIndex] == m_frame) return;
                m_edgeStamp[edgeIndex] = m_frame;
                const Edge& edge = m_edges[edgeIndex];
                const SDL_Color& color = m_slopeColors
                    ? kTrackWirePalette[edge.color]
                    : kStadiumWireColor;
                if (AddProjectedSegment(
                        batch, view, Project(view, edge.a),
                        Project(view, edge.b), color)) {
                    ++drawn;
                }
            });
        return drawn;
    }

    int DrawSurfaces(
        SurfaceBatch& batch, const ViewProjection& view, const ViewWedge& wedge,
        const GmVec3& center, float radius) {
        if (m_faces.empty()) return 0;
        int drawn = 0;
        m_faceGrid.ForEachNear(
            center.x, center.z, radius, wedge, [&](uint32_t faceIndex) {
                if (m_faceStamp[faceIndex] == m_frame) return;
                m_faceStamp[faceIndex] = m_frame;
                const GmSurfTriangle& face = m_faces[faceIndex];
                const GmVec3& a = m_vertices[face.indices[0]];
                const GmVec3& b = m_vertices[face.indices[1]];
                const GmVec3& c = m_vertices[face.indices[2]];
                const SurfaceMaterial& material = m_slopeColors
                    ? kTrackSolidPalette[TrackColorIndex(face)]
                    : kStadiumSolidColor;
                if (AddProjectedFace(
                        batch, view, Project(view, face.indices[0]),
                        Project(view, face.indices[1]),
                        Project(view, face.indices[2]), face.planeNormal,
                        (a + b + c) / 3.0f, material)) {
                    ++drawn;
                }
            });
        return drawn;
    }

private:
    struct Edge {
        uint32_t a;
        uint32_t b;
        uint8_t color;
    };

    const ProjectedVertex& Project(
        const ViewProjection& view, uint32_t vertexIndex) {
        if (m_vertexStamp[vertexIndex] != m_frame) {
            m_vertexStamp[vertexIndex] = m_frame;
            m_projected[vertexIndex] =
                ProjectVertex(view, m_vertices[vertexIndex]);
        }
        return m_projected[vertexIndex];
    }

    std::vector<GmVec3> m_vertices;
    std::vector<Edge> m_edges;
    std::vector<GmSurfTriangle> m_faces;
    SpatialGrid m_edgeGrid;
    SpatialGrid m_faceGrid;
    std::vector<ProjectedVertex> m_projected;
    std::vector<uint32_t> m_vertexStamp;
    std::vector<uint32_t> m_edgeStamp;
    std::vector<uint32_t> m_faceStamp;
    uint32_t m_frame = 0u;
    bool m_slopeColors = false;
};

// A rigid mesh that moves every frame, so its vertices are transformed and
// projected once per frame rather than once per triangle corner.
// Per-wheel visual state, taken straight from the simulation's native wheel
// real-time state.
struct WheelPose {
    float steeringAngle = 0.0f;
    float spinAngle = 0.0f;
};

class DynamicGeometry {
public:
    void Build(
        GmSurfMesh& mesh, const SDL_Color& wireColor,
        const SurfaceMaterial& solidColor) {
        m_wireColor = wireColor;
        m_solidColor = solidColor;
        const uint32_t vertexCount = mesh.m_vertices.GetCount();
        m_localVertices.resize(vertexCount);
        for (uint32_t i = 0; i < vertexCount; ++i) {
            m_localVertices[i] = mesh.m_vertices[i];
        }
        const uint32_t triangleCount = mesh.m_triangles.GetCount();
        m_faces.reserve(triangleCount);
        for (uint32_t i = 0; i < triangleCount; ++i) {
            const GmSurfTriangle& triangle = mesh.m_triangles[i];
            if (triangle.indices[0] >= vertexCount ||
                triangle.indices[1] >= vertexCount ||
                triangle.indices[2] >= vertexCount) {
                continue;
            }
            m_faces.push_back(triangle);
        }
        for (const uint64_t key : BuildUniqueEdges(mesh, false)) {
            m_edges.push_back(
                {static_cast<uint32_t>(key >> 40),
                 static_cast<uint32_t>((key >> 16) & 0xffffffu)});
        }
        m_worldVertices.resize(vertexCount);
        m_projected.resize(vertexCount);
        m_vertexWheel.assign(vertexCount, -1);
        m_faceWheel.assign(m_faces.size(), -1);
    }

    // Splits the merged StadiumCar visual mesh into a body and four wheels so
    // that steering and roll can be shown. The mesh arrives as one object, so
    // wheels are recovered geometrically: each is a cylinder about the car's
    // local X axis (the axle) centred on the native attachment point. The
    // radius stops short of the wheel arches, which is what keeps bodywork
    // from rotating along with the tyre.
    void BuildWheelGroups() {
        using namespace TmForeverPhysicsConstants;
        for (int wheel = 0; wheel < kStadiumWheelCount; ++wheel) {
            m_wheelCenters[wheel] = GmVec3(
                kStadiumWheelLocalX[wheel], kStadiumWheelLocalY[wheel],
                kStadiumWheelLocalZ[wheel]);
        }
        for (size_t i = 0; i < m_localVertices.size(); ++i) {
            m_vertexWheel[i] = ClassifyVertex(m_localVertices[i]);
        }
        // A face rotates only when all three of its corners do, so the body
        // never tears away from a wheel it shares vertices with.
        for (size_t i = 0; i < m_faces.size(); ++i) {
            const GmSurfTriangle& face = m_faces[i];
            const int8_t first = m_vertexWheel[face.indices[0]];
            m_faceWheel[i] =
                (first >= 0 && m_vertexWheel[face.indices[1]] == first &&
                 m_vertexWheel[face.indices[2]] == first)
                    ? first
                    : -1;
        }
    }

    int WheelVertexCount(int wheel) const {
        int total = 0;
        for (const int8_t owner : m_vertexWheel) {
            if (owner == wheel) ++total;
        }
        return total;
    }

    size_t EdgeCount() const { return m_edges.size(); }

    int DrawWireframe(
        LineBatch& batch, const ViewProjection& view, const GmIso4& location,
        const WheelPose* poses) {
        if (m_edges.empty()) return 0;
        Transform(view, location, poses);
        int drawn = 0;
        for (const auto& edge : m_edges) {
            if (AddProjectedSegment(
                    batch, view, m_projected[edge.first],
                    m_projected[edge.second], m_wireColor)) {
                ++drawn;
            }
        }
        return drawn;
    }

    int DrawSurfaces(
        SurfaceBatch& batch, const ViewProjection& view,
        const GmIso4& location, const WheelPose* poses) {
        if (m_faces.empty()) return 0;
        Transform(view, location, poses);
        const GmMat3& rotation = location.rot;
        int drawn = 0;
        for (size_t faceIndex = 0; faceIndex < m_faces.size(); ++faceIndex) {
            const GmSurfTriangle& face = m_faces[faceIndex];
            const int8_t wheel = m_faceWheel[faceIndex];
            // A rotated wheel needs its plane normal rotated too, or the
            // shading stays fixed while the geometry turns.
            const GmVec3 local = (wheel >= 0 && poses != nullptr)
                ? RotateIntoWheel(face.planeNormal, poses[wheel])
                : face.planeNormal;
            const GmVec3 normal(
                rotation.m00 * local.x + rotation.m01 * local.y +
                    rotation.m02 * local.z,
                rotation.m10 * local.x + rotation.m11 * local.y +
                    rotation.m12 * local.z,
                rotation.m20 * local.x + rotation.m21 * local.y +
                    rotation.m22 * local.z);
            const GmVec3& a = m_worldVertices[face.indices[0]];
            const GmVec3& b = m_worldVertices[face.indices[1]];
            const GmVec3& c = m_worldVertices[face.indices[2]];
            if (AddProjectedFace(
                    batch, view, m_projected[face.indices[0]],
                    m_projected[face.indices[1]],
                    m_projected[face.indices[2]], normal,
                    (a + b + c) / 3.0f, m_solidColor)) {
                ++drawn;
            }
        }
        return drawn;
    }

private:
    // Half the tyre width and its radius, in car-local metres. The native
    // attachment points sit at |x| ~ 0.87 and the mesh reaches |x| ~ 1.07, so
    // 0.21 spans the tyre; 0.36 stays inside the arch, which begins near 0.37.
    static constexpr float kWheelHalfWidth = 0.21f;
    static constexpr float kWheelRadius = 0.36f;

    int8_t ClassifyVertex(const GmVec3& local) const {
        for (int wheel = 0;
             wheel < TmForeverPhysicsConstants::kStadiumWheelCount; ++wheel) {
            const GmVec3& center = m_wheelCenters[wheel];
            if (std::abs(local.x - center.x) > kWheelHalfWidth) continue;
            const float dy = local.y - center.y;
            const float dz = local.z - center.z;
            if (dy * dy + dz * dz <= kWheelRadius * kWheelRadius) {
                return static_cast<int8_t>(wheel);
            }
        }
        return -1;
    }

    // Rolls about the axle (car-local X), then steers about the vertical axis.
    static GmVec3 RotateIntoWheel(const GmVec3& value, const WheelPose& pose) {
        const float spinCos = std::cos(pose.spinAngle);
        const float spinSin = std::sin(pose.spinAngle);
        const float rolledY = value.y * spinCos - value.z * spinSin;
        const float rolledZ = value.y * spinSin + value.z * spinCos;
        const float steerCos = std::cos(pose.steeringAngle);
        const float steerSin = std::sin(pose.steeringAngle);
        return GmVec3(
            value.x * steerCos + rolledZ * steerSin,
            rolledY,
            -value.x * steerSin + rolledZ * steerCos);
    }

    void Transform(
        const ViewProjection& view, const GmIso4& location,
        const WheelPose* poses) {
        for (size_t i = 0; i < m_localVertices.size(); ++i) {
            GmVec3 world = m_localVertices[i];
            const int8_t wheel = m_vertexWheel[i];
            if (wheel >= 0 && poses != nullptr) {
                const GmVec3& center = m_wheelCenters[wheel];
                world = center + RotateIntoWheel(world - center, poses[wheel]);
            }
            world.Mult(location);
            m_worldVertices[i] = world;
            m_projected[i] = ProjectVertex(view, world);
        }
    }

    std::vector<GmVec3> m_localVertices;
    std::vector<GmVec3> m_worldVertices;
    std::vector<std::pair<uint32_t, uint32_t>> m_edges;
    std::vector<GmSurfTriangle> m_faces;
    std::vector<ProjectedVertex> m_projected;
    std::vector<int8_t> m_vertexWheel;
    std::vector<int8_t> m_faceWheel;
    GmVec3 m_wheelCenters[TmForeverPhysicsConstants::kStadiumWheelCount];
    SDL_Color m_wireColor{};
    SurfaceMaterial m_solidColor{};
};

std::string ExecutableDirectory(const char* argv0) {
    const std::string path = argv0 != nullptr ? argv0 : "";
    const std::string::size_type slash = path.find_last_of("/\\");
    return slash == std::string::npos ? "." : path.substr(0, slash);
}

void PrintUsage(const char* executable) {
    std::cout
        << "Usage: " << executable << " [map.Challenge.Gbx|collision.tmnfcol] [options]\n"
        << "  --map PATH           Challenge.Gbx map or TMNFCOL1 cache to load\n"
        << "  --packs PATH         TMNF Packs directory (for Challenge.Gbx)\n"
        << "  --extractor PATH     TrackCollisionExtractor.csproj path\n"
        << "  --cache-dir PATH     Generated collision-cache directory\n"
        << "  --rebuild-map-cache  Regenerate collision even if cached\n"
        << "  --start X Y Z        Respawn position (default: A01 start)\n"
        << "  --yaw DEGREES        Respawn heading (default: 90)\n"
        << "  --top-down           Start with the top-down camera\n"
        << "  --zoom VALUE         Top-down pixels per metre (default 7)\n"
        << "  --chase-distance N   Chase camera distance in metres (default 13)\n"
        << "  --solid              Start in shaded-surface mode (default)\n"
        << "  --wireframe          Start in wireframe mode\n"
        << "  --frames N           Exit after N rendered frames (smoke tests)\n"
        << "  --simulate N         Run N physics steps without opening a window\n"
        << "  --trace-every N      Print every Nth headless physics state\n"
        << "  --replay-inputs      Drive the simulation with A01 replay inputs\n"
        << "  --replay PATH        Drive the simulation with replay inputs\n"
        << "  --gas VALUE          Constant gas input for --simulate or rendering\n"
        << "  --brake VALUE        Constant brake input (0 through 1)\n"
        << "  --steer VALUE        Constant steering input (-1 through 1)\n"
        << "  --screenshot PATH    Save a rendered frame as a BMP\n"
        << "  --screenshot-frame N Frame to capture (default 1)\n"
        << "\n"
        << "Keys (interactive window):\n"
        << "  W / Up               Accelerate\n"
        << "  S / Down             Brake, then reverse once stopped\n"
        << "  A / Left             Steer left\n"
        << "  D / Right            Steer right\n"
        << "  C                    Toggle chase and heading-up top-down camera\n"
        << "  M                    Toggle shaded surfaces and wireframe\n"
        << "  B                    Toggle backface culling (solid mode)\n"
        << "  Mouse wheel          Camera distance, or top-down zoom\n"
        << "  Space                Pause and resume the simulation\n"
        << "  N                    Advance one 10 ms physics step while paused\n"
        << "  R                    Reset to the spawn\n"
        << "  Close window         Quit (Escape is deliberately not bound)\n";
}

bool ParseFloat(const char* text, float& value) {
    char* end = nullptr;
    value = std::strtof(text, &end);
    return end != text && end != nullptr && *end == '\0' &&
        std::isfinite(value);
}

bool ParseInt(const char* text, int& value) {
    char* end = nullptr;
    const long parsed = std::strtol(text, &end, 10);
    if (end == text || end == nullptr || *end != '\0' || parsed < 0 ||
        parsed > 100000000L) {
        return false;
    }
    value = static_cast<int>(parsed);
    return true;
}

bool ParseOptions(int argc, char** argv, Options& options) {
    const std::string executableDirectory = ExecutableDirectory(argv[0]);
    options.mapPath = executableDirectory +
        "/../../steamdata/GameData/Tracks/Campaigns/Nations/White/"
        "A01-Race.Challenge.Gbx";
    options.packsDirectory = executableDirectory + "/../../steamdata/Packs";
    options.extractorProject = executableDirectory +
        "/../TrackCollisionExtractor/TrackCollisionExtractor.csproj";
    options.replayPath = executableDirectory +
        "/../../steamdata/GameData/Tracks/Campaigns/Nations/White/"
        "A01-Race.Replay.gbx";
    for (int i = 1; i < argc; ++i) {
        const std::string argument = argv[i];
        if (argument == "--help" || argument == "-h") {
            PrintUsage(argv[0]);
            std::exit(0);
        }
        if (argument == "--top-down") {
            options.topDown = true;
            continue;
        }
        if (argument == "--wireframe") {
            options.style = RenderStyle::Wireframe;
            continue;
        }
        if (argument == "--solid") {
            options.style = RenderStyle::Solid;
            continue;
        }
        if (argument == "--replay-inputs") {
            options.useReplayInputs = true;
            continue;
        }
        if (argument == "--replay" && i + 1 < argc) {
            options.replayPath = argv[++i];
            options.useReplayInputs = true;
            continue;
        }
        if (argument.rfind("--replay=", 0) == 0) {
            options.replayPath = argument.substr(9);
            options.useReplayInputs = true;
            continue;
        }
        if ((argument == "--map" || argument == "--collision") &&
            i + 1 < argc) {
            options.mapPath = argv[++i];
            continue;
        }
        if (argument.rfind("--map=", 0) == 0) {
            options.mapPath = argument.substr(6);
            continue;
        }
        if (argument.rfind("--collision=", 0) == 0) {
            options.mapPath = argument.substr(12);
            continue;
        }
        if (argument == "--packs" && i + 1 < argc) {
            options.packsDirectory = argv[++i];
            continue;
        }
        if (argument.rfind("--packs=", 0) == 0) {
            options.packsDirectory = argument.substr(8);
            continue;
        }
        if (argument == "--extractor" && i + 1 < argc) {
            options.extractorProject = argv[++i];
            continue;
        }
        if (argument.rfind("--extractor=", 0) == 0) {
            options.extractorProject = argument.substr(12);
            continue;
        }
        if (argument == "--cache-dir" && i + 1 < argc) {
            options.cacheDirectory = argv[++i];
            continue;
        }
        if (argument.rfind("--cache-dir=", 0) == 0) {
            options.cacheDirectory = argument.substr(12);
            continue;
        }
        if (argument == "--rebuild-map-cache") {
            options.forceCacheRebuild = true;
            continue;
        }
        if (argument == "--yaw" && i + 1 < argc) {
            float degrees = 0.0f;
            if (!ParseFloat(argv[++i], degrees)) return false;
            options.yaw = degrees * kPi / 180.0f;
            continue;
        }
        if (argument == "--frames" && i + 1 < argc) {
            if (!ParseInt(argv[++i], options.frameLimit)) return false;
            continue;
        }
        if (argument == "--simulate" && i + 1 < argc) {
            if (!ParseInt(argv[++i], options.simulationStepLimit)) return false;
            continue;
        }
        if (argument.rfind("--simulate=", 0) == 0) {
            if (!ParseInt(argument.c_str() + 11, options.simulationStepLimit))
                return false;
            continue;
        }
        if (argument == "--trace-every" && i + 1 < argc) {
            if (!ParseInt(argv[++i], options.traceEvery) ||
                options.traceEvery == 0) {
                return false;
            }
            continue;
        }
        if (argument == "--gas" && i + 1 < argc) {
            if (!ParseFloat(argv[++i], options.automaticGas)) return false;
            options.automaticGas = std::clamp(options.automaticGas, 0.0f, 1.0f);
            continue;
        }
        if (argument == "--brake" && i + 1 < argc) {
            if (!ParseFloat(argv[++i], options.automaticBrake)) return false;
            options.automaticBrake =
                std::clamp(options.automaticBrake, 0.0f, 1.0f);
            continue;
        }
        if (argument == "--steer" && i + 1 < argc) {
            if (!ParseFloat(argv[++i], options.automaticSteer)) return false;
            options.automaticSteer =
                std::clamp(options.automaticSteer, -1.0f, 1.0f);
            continue;
        }
        if (argument.rfind("--frames=", 0) == 0) {
            if (!ParseInt(argument.c_str() + 9, options.frameLimit)) {
                return false;
            }
            continue;
        }
        if (argument == "--screenshot" && i + 1 < argc) {
            options.screenshotPath = argv[++i];
            continue;
        }
        if (argument == "--screenshot-frame" && i + 1 < argc) {
            if (!ParseInt(argv[++i], options.screenshotFrame)) return false;
            options.screenshotFrame = std::max(options.screenshotFrame, 1);
            continue;
        }
        if (argument == "--zoom" && i + 1 < argc) {
            if (!ParseFloat(argv[++i], options.topDownZoom)) return false;
            options.topDownZoom = std::clamp(options.topDownZoom, 1.5f, 200.0f);
            continue;
        }
        if (argument == "--chase-distance" && i + 1 < argc) {
            if (!ParseFloat(argv[++i], options.chaseDistance)) return false;
            options.chaseDistance =
                std::clamp(options.chaseDistance, 2.0f, 35.0f);
            continue;
        }
        if (argument.rfind("--screenshot=", 0) == 0) {
            options.screenshotPath = argument.substr(13);
            continue;
        }
        if (argument == "--start" && i + 3 < argc) {
            if (!ParseFloat(argv[++i], options.start.x) ||
                !ParseFloat(argv[++i], options.start.y) ||
                !ParseFloat(argv[++i], options.start.z)) {
                return false;
            }
            continue;
        }
        if (!argument.empty() && argument[0] != '-') {
            options.mapPath = argument;
            continue;
        }
        std::cerr << "Unknown or incomplete option: " << argument << '\n';
        return false;
    }
    return true;
}

class InteractiveSimulation {
public:
    bool Initialize(const Options& options) {
        startPosition = options.start;
        startYaw = options.yaw;
        TrackMapLoadOptions loadOptions;
        loadOptions.packsDirectory = options.packsDirectory;
        loadOptions.extractorProject = options.extractorProject;
        loadOptions.cacheDirectory = options.cacheDirectory;
        loadOptions.forceCacheRebuild = options.forceCacheRebuild;
        TrackMapLoadResult loadResult;
        if (!LoadTrackMapCollision(
                mesh, options.mapPath, loadOptions, &loadResult,
                &stadiumVisualMesh)) {
            std::cerr << "Could not load map: " << options.mapPath << '\n'
                      << loadResult.error << '\n';
            return false;
        }

        if (loadResult.sourceWasChallengeGbx) {
            std::cout << "Map: " << loadResult.mapName << " by "
                      << loadResult.mapAuthor << " (" << loadResult.blockCount
                      << " placed blocks)\n"
                      << "Collision cache: " << loadResult.collisionCachePath
                      << (loadResult.cacheHit ? " [reused]\n" : " [generated]\n");
        }

        StadiumVehicleLoadOptions vehicleOptions;
        vehicleOptions.packsDirectory = options.packsDirectory;
        vehicleOptions.extractorProject = options.extractorProject;
        vehicleOptions.cacheDirectory = options.cacheDirectory;
        vehicleOptions.forceCacheRebuild = options.forceCacheRebuild;
        StadiumVehicleLoadResult vehicleResult;
        if (!LoadStadiumVehicleAsset(
                vehicleAsset, vehicleOptions, &vehicleResult)) {
            std::cerr << "Could not load Stadium car assets: "
                      << vehicleResult.error << '\n';
            return false;
        }

        car = new CSceneVehicleCar();
        item = new CHmsItem();
        corpus = new CHmsCorpus();
        dyna = new CHmsDyna();
        zone = new CHmsZoneDynamic();

        car->m_hmsItem = item;
        item->m_sceneMobil = car;
        item->m_solid = vehicleAsset.CollisionSolid();
        item->CallbackSet(
            CB_PHYSICS,
            CCallbackSceneVehicleCarComputeForces::Instance());
        item->CallbackSet(
            CB_ABSORB_CONTACT,
            CSceneMobilAbsorbContact::Instance());
        item->CallbackSet(
            CB_AFTER_CONTACTS,
            CCallbackSceneVehicleCarAfterContacts::Instance());
        item->m_corpuses.Add(corpus);
        corpus->m_dyna = dyna;
        corpus->m_item = item;
        car->m_simulationFlags = 7;
        for (uint32_t wheelIndex = 0u;
             wheelIndex < car->m_wheels.GetCount() && wheelIndex < 4u;
             ++wheelIndex) {
            car->m_wheels[wheelIndex].m_surfaceHandler.Init(
                vehicleAsset.WheelCollisionTree(wheelIndex));
        }

        InitTuningData(&tuning);
        g_tuning = &tuning;
        dyna->m_field_0x108 = &physicalObject;
        car->UpdateParamsFromTuning();
        dyna->m_dynamicType = 1;
        dyna->UpdateWorldInverseInertia();
        item->m_flags1 =
            (item->m_flags1 & ~(0x1e000u | 0x1800u)) |
            (3u << 13u) | (2u << 11u);
        uniformGravity.m_isActive = 1;
        zone->AddForceField(&uniformGravity);

        collisionManager = new CHmsCollisionManager();
        collisionZone = collisionManager->AddZone(1u);
        worldGeometry = new CPlugSurfaceGeom();
        worldSurface = new CPlugSurface();
        worldTree = new CPlugTree();
        worldSolid = new CPlugSolid();
        worldItem = new CHmsItem();
        worldCorpus = new CHmsCorpus();
        worldGeometry->SetGmSurf(&mesh, false);
        worldSurface->m_geometry = worldGeometry;
        worldTree->SetSurface(worldSurface);
        worldTree->SetIsCollidable(true);
        worldSolid->SetTree(worldTree);
        worldItem->m_solid = worldSolid;
        worldItem->m_flags1 =
            (worldItem->m_flags1 & ~0x1e000u) |
            (3u << 13u) | 0x00080000u;
        worldCorpus->m_item = worldItem;
        worldCorpus->m_location.SetIdentity();
        collisionZone->AddCorpus(corpus);
        collisionZone->AddCorpus(worldCorpus);
        collisionManager->UpdateStaticCollisionTrees();
        zone->m_ptr168 = collisionZone;
        zone->m_dynamicCorpuses.Add(corpus);
        GmSurf::StaticInit();
        Reset();

        std::cout << "Loaded " << mesh.m_vertices.m_count << " vertices and "
                  << mesh.m_triangles.m_count << " collision triangles, plus "
                  << vehicleAsset.VisualMesh()->m_vertices.GetCount()
                  << " native Stadium car visual vertices and "
                  << stadiumVisualMesh.m_vertices.GetCount()
                  << " Stadium decoration vertices.\n";
        return true;
    }

    void Reset() {
        dyna->Reset(nullptr);
        dyna->SetTranslation(nullptr, &startPosition);
        dyna->SetYaw(startYaw);
        car->VehicleReset();
        simulatedSeconds = 0.0;
        lastDiagnostics = VehicleTrackStepDiagnostics{};
        trail.clear();
        trail.push_back(dyna->Position());
    }

    void SetInput(float gas, float brake, float steer) {
        car->m_inputGas = gas;
        car->m_inputBrake = brake;
        car->m_inputSteer = steer;
    }

    void Step() {
        lastDiagnostics = StepVehicleOnTrack(
            *car, *item, *zone, mesh, tuning, kPhysicsDt);
        simulatedSeconds += kPhysicsDt;
        trail.push_back(dyna->Position());
        if (trail.size() > 6000) trail.pop_front();
    }

    float SpeedKmh() const {
        GmVec3 velocity;
        dyna->GetLinearSpeed(nullptr, &velocity);
        return std::sqrt(LengthSquared(velocity)) * 3.6f;
    }

    // Only needed when a window is opened; headless runs skip the cost.
    void BuildRenderData() {
        trackGeometry.Build(mesh, true);
        stadiumGeometry.Build(stadiumVisualMesh, false);
        if (GmSurfMesh* carMesh = vehicleAsset.VisualMesh()) {
            carGeometry.Build(*carMesh, kCarWireColor, kCarSolidColor);
            carGeometry.BuildWheelGroups();
        }
        std::cout << "Render data: " << trackGeometry.EdgeCount()
                  << " track edges, " << stadiumGeometry.EdgeCount()
                  << " stadium edges, " << carGeometry.EdgeCount()
                  << " car edges; wheel vertices "
                  << carGeometry.WheelVertexCount(0) << '/'
                  << carGeometry.WheelVertexCount(1) << '/'
                  << carGeometry.WheelVertexCount(2) << '/'
                  << carGeometry.WheelVertexCount(3) << '\n';
    }

    GmSurfMesh mesh;
    GmSurfMesh stadiumVisualMesh;
    StadiumVehicleAsset vehicleAsset;
    CSceneVehicleCar* car = nullptr;
    CHmsItem* item = nullptr;
    CHmsCorpus* corpus = nullptr;
    CHmsDyna* dyna = nullptr;
    CHmsZoneDynamic* zone = nullptr;
    CHmsCollisionManager* collisionManager = nullptr;
    CHmsCollisionManager::SZone* collisionZone = nullptr;
    CPlugSurfaceGeom* worldGeometry = nullptr;
    CPlugSurface* worldSurface = nullptr;
    CPlugTree* worldTree = nullptr;
    CPlugSolid* worldSolid = nullptr;
    CHmsItem* worldItem = nullptr;
    CHmsCorpus* worldCorpus = nullptr;
    CSceneVehicleCarTuning tuning;
    CPlugPhysicalObject physicalObject;
    CHmsForceFieldUniform uniformGravity;
    VehicleTrackStepDiagnostics lastDiagnostics;
    StaticGeometry trackGeometry;
    StaticGeometry stadiumGeometry;
    DynamicGeometry carGeometry;
    LineBatch lineBatch;
    SurfaceBatch surfaceBatch;
    std::deque<GmVec3> trail;
    GmVec3 startPosition = kDefaultStart;
    float startYaw = kDefaultYaw;
    double simulatedSeconds = 0.0;
};

class ReplayInputPlayer {
public:
    bool Load(const std::string& path) {
        std::unique_ptr<CClassicArchive> archive(
            CClassicArchive::LoadFromGbx(path.c_str()));
        if (archive == nullptr) {
            std::cerr << "Could not load replay: " << path << '\n';
            return false;
        }
        if (!archive->ScanForChunk(0x03092019u)) {
            std::cerr << "Replay has no input-events chunk: " << path << '\n';
            return false;
        }

        record = std::make_unique<CGameCtnReplayRecord>();
        record->Chunk(nullptr, archive.get(), 0x03092019u);
        if (record->m_events.empty()) {
            std::cerr << "Replay has no input events: " << path << '\n';
            return false;
        }

        for (size_t index = 0; index < record->m_controlNames.size(); ++index) {
            const std::string& name = record->m_controlNames[index];
            if (name == "Accelerate" || name == "UnknownId_524288") {
                accelerateIndex = static_cast<int>(index);
            } else if (name == "Brake" || name == "UnknownId_524289") {
                brakeIndex = static_cast<int>(index);
            } else if (name == "SteerLeft" || name == "UnknownId_524290") {
                steerLeftIndex = static_cast<int>(index);
            } else if (name == "SteerRight" || name == "UnknownId_524291") {
                steerRightIndex = static_cast<int>(index);
            } else if (name == "Steer" || name == "UnknownId_524292") {
                steerIndex = static_cast<int>(index);
            }
        }

        Reset();
        std::cout << "Replay inputs: " << record->m_events.size()
                  << " events from " << path << '\n';
        return true;
    }

    void Reset() {
        nextEvent = 0u;
        gas = 0.0f;
        brake = 0.0f;
        steer = 0.0f;
        if (record == nullptr) return;
        while (nextEvent < record->m_events.size() &&
               record->m_events[nextEvent].time < kRaceStartMs) {
            ++nextEvent;
        }
    }

    void Advance(uint32_t raceTimeMs) {
        if (record == nullptr) return;
        const uint32_t absoluteTimeMs = kRaceStartMs + raceTimeMs;
        while (nextEvent < record->m_events.size()) {
            const SInputEvent& event = record->m_events[nextEvent];
            if (event.time > absoluteTimeMs) break;

            const int controlIndex = static_cast<int>(event.controlIdx);
            if (controlIndex == accelerateIndex) {
                gas = event.value != 0u ? 1.0f : 0.0f;
            } else if (controlIndex == brakeIndex) {
                brake = event.value != 0u ? 1.0f : 0.0f;
            } else if (controlIndex == steerRightIndex) {
                if (event.value != 0u) steer = 1.0f;
                else if (steer > 0.0f) steer = 0.0f;
            } else if (controlIndex == steerLeftIndex) {
                if (event.value != 0u) steer = -1.0f;
                else if (steer < 0.0f) steer = 0.0f;
            } else if (controlIndex == steerIndex) {
                int32_t signedValue = 0;
                static_assert(sizeof(signedValue) == sizeof(event.value));
                std::memcpy(&signedValue, &event.value, sizeof(signedValue));
                steer = std::clamp(
                    static_cast<float>(signedValue) / 65535.0f,
                    -1.0f, 1.0f);
            }
            ++nextEvent;
        }
    }

    float Gas() const { return gas; }
    float Brake() const { return brake; }
    float Steer() const { return steer; }

private:
    static constexpr uint32_t kRaceStartMs = 100000u;
    std::unique_ptr<CGameCtnReplayRecord> record;
    size_t nextEvent = 0u;
    int accelerateIndex = -1;
    int brakeIndex = -1;
    int steerLeftIndex = -1;
    int steerRightIndex = -1;
    int steerIndex = -1;
    float gas = 0.0f;
    float brake = 0.0f;
    float steer = 0.0f;
};

Camera BuildChaseCamera(
    const InteractiveSimulation& simulation, const ViewState& view,
    int width, int height) {
    const VehicleChassisBasis carBasis = BuildVehicleChassisBasis(
        simulation.car->m_chassisUp, simulation.dyna->GetYaw());
    Camera camera;
    camera.width = std::max(width, 1);
    camera.height = std::max(height, 1);
    camera.position = simulation.dyna->Position() -
        carBasis.forward * view.chaseDistance +
        GmVec3(0.0f, 5.0f, 0.0f);
    const GmVec3 target =
        simulation.dyna->Position() + carBasis.forward * 7.0f +
        GmVec3(0.0f, 0.6f, 0.0f);
    camera.forward = Normalized(target - camera.position);
    // The engine's world is left-handed: with +Y up, an observer facing
    // `forward` has their right hand along Cross(forward, up), not
    // Cross(up, forward). Taking the other order mirrors the whole scene
    // horizontally, which also makes correct steering look inverted.
    camera.right = Normalized(GmVec3::Cross(
        camera.forward, GmVec3(0.0f, 1.0f, 0.0f)));
    if (LengthSquared(camera.right) <= 1.0e-10f) {
        camera.right = GmVec3(1.0f, 0.0f, 0.0f);
    }
    camera.up = Normalized(GmVec3::Cross(camera.right, camera.forward));
    camera.focalLength = static_cast<float>(camera.height) * 0.86f;
    return camera;
}

// Radius used for the track in the chase view. The top-down view derives its
// own radius from the current zoom.
constexpr float kChaseTrackRadius = 150.0f;
// The stadium decoration is a fixed model around the track, so a radius that
// comfortably contains it keeps the view identical while still letting the
// grid skip everything once the car drives away from it.
constexpr float kStadiumRadius = 600.0f;

int DrawTrail(
    LineBatch& batch, const ViewProjection& view,
    const InteractiveSimulation& simulation) {
    if (simulation.trail.size() < 2u) return 0;
    auto point = simulation.trail.begin();
    ProjectedVertex previous = ProjectVertex(view, *point);
    int drawn = 0;
    for (++point; point != simulation.trail.end(); ++point) {
        const ProjectedVertex current = ProjectVertex(view, *point);
        if (AddProjectedSegment(batch, view, previous, current, kTrailColor)) {
            ++drawn;
        }
        previous = current;
    }
    return drawn;
}

// Reads the native per-wheel visual state the simulation maintains:
// m_steeringAngle is walked toward IntegrateVehicle's target at one radian per
// second, and m_rotationAngle accumulates over 256 turns before wrapping, so
// it is folded back into one turn before reaching a trig call.
void CollectWheelPoses(
    const InteractiveSimulation& simulation, WheelPose* poses) {
    const uint32_t count = std::min<uint32_t>(
        simulation.car->m_wheels.GetCount(),
        TmForeverPhysicsConstants::kStadiumWheelCount);
    for (uint32_t i = 0; i < count; ++i) {
        const auto& state = simulation.car->m_wheels[i].m_realTimeState;
        poses[i].steeringAngle = state.m_steeringAngle;
        poses[i].spinAngle = std::fmod(state.m_rotationAngle, 2.0f * kPi);
    }
}

GmIso4 VehicleLocation(const InteractiveSimulation& simulation) {
    GmIso4 location;
    location.SetIdentity();
    location.rot = simulation.dyna->CurrentState().m_rotationMatrix;
    location.SetTranslation(simulation.dyna->Position());
    return location;
}

// Wheel contact markers and the chassis-up vector. These are diagnostics, so
// they stay as lines even in solid mode and are drawn last, on top.
int DrawVehicleMarkers(
    LineBatch& batch, const ViewProjection& view,
    const InteractiveSimulation& simulation) {
    if (view.topDown) return 0;
    int drawn = 0;
    const VehicleChassisBasis basis = BuildVehicleChassisBasis(
        simulation.car->m_chassisUp, simulation.dyna->GetYaw());
    for (int i = 0; i < simulation.lastDiagnostics.wheelCount; ++i) {
        const GmVec3 wheel = simulation.dyna->Position() +
            basis.right * TmForeverPhysicsConstants::kStadiumWheelLocalX[i] +
            basis.up *
                (TmForeverPhysicsConstants::kStadiumWheelLocalY[i] -
                 simulation.car->m_wheels[i]
                     .m_realTimeState.m_compression) +
            basis.forward * TmForeverPhysicsConstants::kStadiumWheelLocalZ[i];
        const SDL_Color color = simulation.car->m_wheels[i].m_hasGroundContact
            ? kWheelGroundedColor
            : kWheelAirborneColor;
        if (AddWorldSegment(
                batch, view, wheel - basis.up * 0.25f,
                wheel + basis.up * 0.25f, color)) {
            ++drawn;
        }
    }
    if (AddWorldSegment(
            batch, view, simulation.dyna->Position(),
            simulation.dyna->Position() + simulation.car->m_chassisUp * 2.0f,
            kChassisUpColor)) {
        ++drawn;
    }
    return drawn;
}

int Render(
    SDL_Renderer* renderer, InteractiveSimulation& simulation,
    const ViewState& view, int width, int height) {
    SDL_SetRenderDrawColor(
        renderer, static_cast<uint8_t>(kBackgroundRed),
        static_cast<uint8_t>(kBackgroundGreen),
        static_cast<uint8_t>(kBackgroundBlue), 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    const float trackRadius = view.topDown
        ? std::min(
              280.0f,
              std::max(
                  45.0f,
                  std::max(width, height) / view.topDownZoom * 0.85f))
        : kChaseTrackRadius;

    ViewProjection projection;
    projection.style = view.style;
    projection.topDown = view.topDown;
    projection.width = std::max(width, 1);
    projection.height = std::max(height, 1);
    projection.camera = BuildChaseCamera(simulation, view, width, height);
    projection.origin = simulation.dyna->Position();
    const VehicleChassisBasis carBasis = BuildVehicleChassisBasis(
        simulation.car->m_chassisUp, simulation.dyna->GetYaw());
    projection.screenForward = carBasis.forward;
    projection.screenRight =
        Normalized(GmVec3::Cross(carBasis.forward, carBasis.up));
    projection.zoom = view.topDownZoom;
    projection.fogStart = trackRadius * 0.28f;
    projection.fogEnd = trackRadius;
    projection.cullBackFaces =
        view.style == RenderStyle::Solid && view.cullBackFaces;

    WheelPose wheelPoses[TmForeverPhysicsConstants::kStadiumWheelCount]{};
    CollectWheelPoses(simulation, wheelPoses);

    const ViewWedge wedge(projection);
    simulation.trackGeometry.BeginFrame();
    simulation.stadiumGeometry.BeginFrame();

    LineBatch& lines = simulation.lineBatch;
    lines.Begin(renderer);
    int primitives = 0;

    if (view.style == RenderStyle::Solid) {
        // Everything shaded goes through one batch so that the car and the
        // track occlude each other correctly.
        SurfaceBatch& surfaces = simulation.surfaceBatch;
        // Shaded faces are opaque, and skipping the blend stage is a
        // measurable saving at this fill rate.
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_NONE);
        surfaces.Begin(renderer);
        primitives += simulation.stadiumGeometry.DrawSurfaces(
            surfaces, projection, wedge, projection.origin, kStadiumRadius);
        primitives += simulation.trackGeometry.DrawSurfaces(
            surfaces, projection, wedge, projection.origin, trackRadius);
        primitives += simulation.carGeometry.DrawSurfaces(
            surfaces, projection, VehicleLocation(simulation), wheelPoses);
        surfaces.Flush();
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    } else {
        primitives += simulation.stadiumGeometry.DrawWireframe(
            lines, projection, wedge, projection.origin, kStadiumRadius);
        primitives += simulation.trackGeometry.DrawWireframe(
            lines, projection, wedge, projection.origin, trackRadius);
        primitives += simulation.carGeometry.DrawWireframe(
            lines, projection, VehicleLocation(simulation), wheelPoses);
    }

    primitives += DrawTrail(lines, projection, simulation);
    primitives += DrawVehicleMarkers(lines, projection, simulation);
    lines.Flush();

    SDL_SetRenderDrawColor(renderer, 220, 225, 230, 100);
    SDL_RenderDrawLine(renderer, width / 2 - 6, height / 2,
                      width / 2 + 6, height / 2);
    SDL_RenderDrawLine(renderer, width / 2, height / 2 - 6,
                      width / 2, height / 2 + 6);
    return primitives;
}

bool SaveScreenshot(
    SDL_Renderer* renderer, int width, int height,
    const std::string& path) {
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(
        0, width, height, 32, SDL_PIXELFORMAT_RGBA32);
    if (surface == nullptr) return false;
    const int readResult = SDL_RenderReadPixels(
        renderer, nullptr, surface->format->format,
        surface->pixels, surface->pitch);
    const int saveResult = readResult == 0
        ? SDL_SaveBMP(surface, path.c_str())
        : -1;
    SDL_FreeSurface(surface);
    return readResult == 0 && saveResult == 0;
}

} // namespace

CSceneVehicleCarTuning* g_tuning = nullptr;

int main(int argc, char** argv) {
    Options options;
    if (!ParseOptions(argc, argv, options)) {
        PrintUsage(argv[0]);
        return 2;
    }

    InteractiveSimulation simulation;
    if (!simulation.Initialize(options)) return 1;

    ReplayInputPlayer replayInputs;
    if (options.useReplayInputs && !replayInputs.Load(options.replayPath)) {
        return 1;
    }

    if (options.simulationStepLimit >= 0) {
        if (!options.useReplayInputs) {
            simulation.SetInput(
                options.automaticGas, options.automaticBrake,
                options.automaticSteer);
        }
        for (int step = 0; step < options.simulationStepLimit; ++step)
        {
            if (options.useReplayInputs) {
                replayInputs.Advance(static_cast<uint32_t>(step * 10));
                simulation.SetInput(
                    replayInputs.Gas(), replayInputs.Brake(),
                    replayInputs.Steer());
            }
            simulation.Step();
            if (options.traceEvery > 0 &&
                (step + 1) % options.traceEvery == 0) {
                GmVec3 linearSpeed;
                GmVec3 localLinearSpeed;
                GmVec3 angularSpeed;
                simulation.dyna->GetLinearSpeed(nullptr, &linearSpeed);
                simulation.item->GetLinearSpeed(
                    simulation.item, &localLinearSpeed);
                simulation.dyna->GetAngularSpeed(nullptr, &angularSpeed);
                std::cout << "Trace: t=" << simulation.simulatedSeconds
                          << "s pos=(" << simulation.dyna->Position().x
                          << ", " << simulation.dyna->Position().y
                          << ", " << simulation.dyna->Position().z
                          << ") velocity=(" << linearSpeed.x << ", "
                          << linearSpeed.y << ", " << linearSpeed.z
                          << ") localVelocity=(" << localLinearSpeed.x
                          << ", " << localLinearSpeed.y << ", "
                          << localLinearSpeed.z
                          << ") angular=(" << angularSpeed.x << ", "
                          << angularSpeed.y << ", " << angularSpeed.z
                          << ") force=("
                          << simulation.lastDiagnostics.accumulatedForce.x
                          << ", "
                          << simulation.lastDiagnostics.accumulatedForce.y
                          << ", "
                          << simulation.lastDiagnostics.accumulatedForce.z
                          << ") accel="
                          << simulation.tuning.M5GetAccelFromSpeed(
                                 localLinearSpeed.z)
                          << " input=("
                          << simulation.car->m_inputGas << ", "
                          << simulation.car->m_inputBrake << ", "
                          << simulation.car->m_inputSteer << ")"
                          << " slip=("
                          << simulation.car->m_wheels[0].m_isSlipping
                          << ", "
                          << simulation.car->m_wheels[1].m_isSlipping
                          << ", "
                          << simulation.car->m_wheels[2].m_isSlipping
                          << ", "
                          << simulation.car->m_wheels[3].m_isSlipping
                          << ") engineState="
                          << simulation.car->m_engineState
                          << " smoothedSteer="
                          << simulation.car->m_smoothedSteer
                          << " wheelSteer=("
                          << simulation.car->m_wheels[0]
                                 .m_realTimeState.m_steeringAngle
                          << ", "
                          << simulation.car->m_wheels[1]
                                 .m_realTimeState.m_steeringAngle
                          << ") target="
                          << simulation.car->m_wheels[0]
                                 .m_realTimeState.m_targetSteeringAngle
                          << '\n';
            }
        }
        GmVec3 angularSpeed;
        simulation.dyna->GetAngularSpeed(nullptr, &angularSpeed);
        std::cout << "Final state: t=" << simulation.simulatedSeconds
                  << "s pos=(" << simulation.dyna->Position().x << ", "
                  << simulation.dyna->Position().y << ", "
                  << simulation.dyna->Position().z << ") speed="
                  << simulation.SpeedKmh() << " km/h angular=("
                  << angularSpeed.x << ", " << angularSpeed.y << ", "
                  << angularSpeed.z << ") grounded="
                  << simulation.lastDiagnostics.groundedWheelCount
                  << "/4 force=("
                  << simulation.lastDiagnostics.accumulatedForce.x << ", "
                  << simulation.lastDiagnostics.accumulatedForce.y << ", "
                  << simulation.lastDiagnostics.accumulatedForce.z
                  << ") wheelContacts="
                  << simulation.car->m_lastWheelContactCount
                  << " compression=("
                  << simulation.car->m_wheels[0]
                         .m_realTimeState.m_compression
                  << ", "
                  << simulation.car->m_wheels[1]
                         .m_realTimeState.m_compression
                  << ", "
                  << simulation.car->m_wheels[2]
                         .m_realTimeState.m_compression
                  << ", "
                  << simulation.car->m_wheels[3]
                         .m_realTimeState.m_compression
                  << ") material=("
                  << simulation.lastDiagnostics.wheelMaterial[0] << ", "
                  << simulation.lastDiagnostics.wheelMaterial[1] << ", "
                  << simulation.lastDiagnostics.wheelMaterial[2] << ", "
                  << simulation.lastDiagnostics.wheelMaterial[3]
                  << ") gap=("
                  << simulation.lastDiagnostics.wheelTireGap[0] << ", "
                  << simulation.lastDiagnostics.wheelTireGap[1] << ", "
                  << simulation.lastDiagnostics.wheelTireGap[2] << ", "
                  << simulation.lastDiagnostics.wheelTireGap[3] << ")\n";
        return 0;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << '\n';
        return 1;
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");
    SDL_Window* window = SDL_CreateWindow(
        "TMNF Physics Visual Test",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr) {
        std::cerr << "Could not create SDL window: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    }
    if (renderer == nullptr) {
        std::cerr << "Could not create SDL renderer: " << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    simulation.BuildRenderData();

    std::cout
        << "Controls: W/Up accelerate, S/Down brake/reverse, A/D or arrows steer\n"
        << "          C camera, M solid/wireframe, mouse wheel zoom, Space pause, N single-step, R reset, Esc quit\n";

    ViewState view;
    view.topDown = options.topDown;
    view.style = options.style;
    view.topDownZoom = options.topDownZoom;
    view.chaseDistance = options.chaseDistance;
    bool running = true;
    bool paused = false;
    bool singleStep = false;
    double accumulator = 0.0;
    const double counterFrequency =
        static_cast<double>(SDL_GetPerformanceFrequency());
    uint64_t previousCounter = SDL_GetPerformanceCounter();
    uint32_t lastTitleUpdate = 0;
    int renderedFrames = 0;
    int primitivesDrawn = 0;
    bool screenshotSaved = false;
    uint64_t fpsWindowStart = previousCounter;
    int fpsWindowFrames = 0;
    float framesPerSecond = 0.0f;
    double physicsSeconds = 0.0;
    double renderSeconds = 0.0;
    double presentSeconds = 0.0;
    int physicsSteps = 0;

    while (running &&
           (options.frameLimit < 0 || renderedFrames < options.frameLimit)) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                switch (event.key.keysym.sym) {
                    // case SDLK_ESCAPE: running = false; break;
                    case SDLK_c: view.topDown = !view.topDown; break;
                    case SDLK_m:
                        view.style = view.style == RenderStyle::Solid
                            ? RenderStyle::Wireframe
                            : RenderStyle::Solid;
                        break;
                    case SDLK_b:
                        view.cullBackFaces = !view.cullBackFaces;
                        break;
                    case SDLK_r:
                        simulation.Reset();
                        replayInputs.Reset();
                        accumulator = 0.0;
                        break;
                    case SDLK_SPACE: paused = !paused; accumulator = 0.0; break;
                    case SDLK_n: if (paused) singleStep = true; break;
                    default: break;
                }
            }
            if (event.type == SDL_MOUSEWHEEL) {
                if (view.topDown) {
                    view.topDownZoom = std::clamp(
                        view.topDownZoom * std::pow(
                            1.15f, static_cast<float>(event.wheel.y)),
                        1.5f, 30.0f);
                } else {
                    view.chaseDistance = std::clamp(
                        view.chaseDistance - event.wheel.y * 1.2f,
                        6.0f, 35.0f);
                }
            }
        }

        const uint64_t currentCounter = SDL_GetPerformanceCounter();
        double elapsed =
            static_cast<double>(currentCounter - previousCounter) /
            counterFrequency;
        previousCounter = currentCounter;
        // Cap the catch-up so a hitch (or a slow first frame) cannot queue up
        // more physics than the next frame can absorb, which used to turn a
        // single slow frame into a lasting stall.
        elapsed = std::min(
            elapsed, static_cast<double>(kMaxCatchUpSteps) * kPhysicsDt);

        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        const float gas =
            (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) ? 1.0f : 0.0f;
        const float brake =
            (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) ? 1.0f : 0.0f;
        const float steerLeft =
            (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) ? 1.0f : 0.0f;
        const float steerRight =
            (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) ? 1.0f : 0.0f;
        if (!options.useReplayInputs) {
            simulation.SetInput(
                std::max(gas, options.automaticGas),
                std::max(brake, options.automaticBrake),
                std::clamp(
                    steerRight - steerLeft + options.automaticSteer,
                    -1.0f, 1.0f));
        }

        if (!paused) accumulator += elapsed;
        if (singleStep) accumulator = kPhysicsDt;
        const uint64_t physicsStart = SDL_GetPerformanceCounter();
        int stepCount = 0;
        while (accumulator >= kPhysicsDt && stepCount < kMaxCatchUpSteps) {
            if (options.useReplayInputs) {
                const uint32_t raceTimeMs = static_cast<uint32_t>(
                    std::llround(simulation.simulatedSeconds * 1000.0));
                replayInputs.Advance(raceTimeMs);
                simulation.SetInput(
                    replayInputs.Gas(), replayInputs.Brake(),
                    replayInputs.Steer());
            }
            simulation.Step();
            accumulator -= kPhysicsDt;
            ++stepCount;
            if (singleStep) break;
        }
        if (stepCount == kMaxCatchUpSteps && accumulator >= kPhysicsDt) {
            accumulator = 0.0;
        }
        singleStep = false;
        physicsSteps += stepCount;
        physicsSeconds +=
            static_cast<double>(SDL_GetPerformanceCounter() - physicsStart) /
            counterFrequency;

        int width = 1;
        int height = 1;
        SDL_GetRendererOutputSize(renderer, &width, &height);
        const uint64_t renderStart = SDL_GetPerformanceCounter();
        primitivesDrawn = Render(
            renderer, simulation, view, width, height);
        renderSeconds +=
            static_cast<double>(SDL_GetPerformanceCounter() - renderStart) /
            counterFrequency;
        // renderedFrames still counts completed frames here, so the frame just
        // rendered is renderedFrames + 1.
        if (!screenshotSaved && !options.screenshotPath.empty() &&
            renderedFrames + 1 >= options.screenshotFrame) {
            screenshotSaved = SaveScreenshot(
                renderer, width, height, options.screenshotPath);
            if (screenshotSaved) {
                std::cout << "Saved screenshot: "
                          << options.screenshotPath << '\n';
            } else {
                std::cerr << "Could not save screenshot: "
                          << SDL_GetError() << '\n';
            }
        }
        const uint64_t presentStart = SDL_GetPerformanceCounter();
        SDL_RenderPresent(renderer);
        presentSeconds +=
            static_cast<double>(SDL_GetPerformanceCounter() - presentStart) /
            counterFrequency;
        ++renderedFrames;
        ++fpsWindowFrames;

        const double fpsWindowSeconds =
            static_cast<double>(currentCounter - fpsWindowStart) /
            counterFrequency;
        if (fpsWindowSeconds >= 0.25) {
            framesPerSecond =
                static_cast<float>(fpsWindowFrames / fpsWindowSeconds);
            fpsWindowStart = currentCounter;
            fpsWindowFrames = 0;
        }

        const uint32_t nowMs = SDL_GetTicks();
        if (nowMs - lastTitleUpdate >= 100 || renderedFrames == 1) {
            char title[512];
            std::snprintf(
                title, sizeof(title),
                "TMNF Physics | %6.1f km/h | t %.2fs | pos %.2f %.2f %.2f | "
                "%d/4 wheels | %s | %s%s | %d prims | %.0f fps",
                simulation.SpeedKmh(), simulation.simulatedSeconds,
                simulation.dyna->Position().x,
                simulation.dyna->Position().y,
                simulation.dyna->Position().z,
                simulation.lastDiagnostics.groundedWheelCount,
                view.topDown ? "top" : "chase",
                view.style == RenderStyle::Solid ? "solid" : "wire",
                paused ? " | PAUSED" : "", primitivesDrawn, framesPerSecond);
            SDL_SetWindowTitle(window, title);
            lastTitleUpdate = nowMs;
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    if (renderedFrames > 0) {
        const double frames = static_cast<double>(renderedFrames);
        std::cout << "Frame budget over " << renderedFrames
                  << " frames: physics " << physicsSeconds / frames * 1000.0
                  << " ms (" << physicsSteps << " steps), render "
                  << renderSeconds / frames * 1000.0 << " ms, present "
                  << presentSeconds / frames * 1000.0 << " ms\n";
    }
    GmVec3 angularSpeed;
    simulation.dyna->GetAngularSpeed(nullptr, &angularSpeed);
    std::cout << "Final state: t=" << simulation.simulatedSeconds
              << "s pos=(" << simulation.dyna->Position().x << ", "
              << simulation.dyna->Position().y << ", "
              << simulation.dyna->Position().z << ") speed="
              << simulation.SpeedKmh() << " km/h grounded="
              << simulation.lastDiagnostics.groundedWheelCount << "/4 angular=("
              << angularSpeed.x << ", " << angularSpeed.y << ", "
              << angularSpeed.z << ")\n";
    return 0;
}
