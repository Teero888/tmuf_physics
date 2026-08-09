#include <SDL.h>

#include "../../TuningData.hpp"
#include "CHmsCorpus.hpp"
#include "Gm/GmSurf.hpp"
#include "Hms/CHmsDyna.hpp"
#include "Hms/CHmsItem.hpp"
#include "Hms/CHmsZoneDynamic.hpp"
#include "Hms/CHmsForceFieldUniform.hpp"
#include "Plug/CPlugPhysicalObject.hpp"
#include "Scene/CCallbackSceneVehicleCarComputeForces.hpp"
#include "Scene/CSceneMobilAbsorbContact.hpp"
#include "Scene/CSceneVehicleCar.hpp"
#include "Scene/CSceneVehicleCarTuning.hpp"
#include "Scene/TmForeverPhysicsConstants.hpp"
#include "Scene/VehicleGroundSupport.hpp"
#include "Track/TrackMapLoader.hpp"
#include "VehicleTrackSimulation.hpp"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>

extern CSceneVehicleCarTuning* g_tuning;

namespace {

constexpr float kPhysicsDt = 0.01f;
constexpr float kPi = 3.14159265358979323846f;
constexpr GmVec3 kDefaultStart{171.199997f, 90.209999f, 688.0f};
constexpr float kDefaultYaw = kPi * 0.5f;

struct Options {
    std::string mapPath;
    std::string packsDirectory;
    std::string extractorProject;
    std::string cacheDirectory;
    std::string screenshotPath;
    GmVec3 start = kDefaultStart;
    float yaw = kDefaultYaw;
    int frameLimit = -1;
    bool topDown = false;
    bool forceCacheRebuild = false;
};

struct ViewState {
    bool topDown = false;
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

struct CameraPoint {
    float x;
    float y;
    float z;
};

float LengthSquared(const GmVec3& value) {
    return GmVec3::Dot(value, value);
}

GmVec3 Normalized(GmVec3 value) {
    if (LengthSquared(value) > 1.0e-10f) value.Normalize();
    return value;
}

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
        << "  --frames N           Exit after N rendered frames (smoke tests)\n"
        << "  --screenshot PATH    Save the first rendered frame as a BMP\n";
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
                mesh, options.mapPath, loadOptions, &loadResult)) {
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

        car = new CSceneVehicleCar();
        item = new CHmsItem();
        corpus = new CHmsCorpus();
        dyna = new CHmsDyna();
        zone = new CHmsZoneDynamic();

        car->m_hmsItem = item;
        item->m_sceneMobil = car;
        item->CallbackSet(
            CB_PHYSICS,
            CCallbackSceneVehicleCarComputeForces::Instance());
        item->CallbackSet(
            CB_ABSORB_CONTACT,
            CSceneMobilAbsorbContact::Instance());
        item->m_corpuses.Add(corpus);
        corpus->m_dyna = dyna;
        corpus->m_item = item;
        zone->m_dynamicCorpuses.Add(corpus);
        car->m_simulationFlags = 7;

        InitTuningData(&tuning);
        g_tuning = &tuning;
        physicalObject.m_mass = tuning.m_mass;
        physicalObject.m_forceFieldCoef = tuning.m_gravityCoef;
        physicalObject.SetInertiaMatrixBox(
            tuning.m_inertiaMass,
            GmVec3(tuning.m_inertiaHalfDiagX,
                   tuning.m_inertiaHalfDiagY,
                   tuning.m_inertiaHalfDiagZ));
        dyna->m_field_0x108 = &physicalObject;
        dyna->m_dynamicType = 1;
        dyna->UpdateWorldInverseInertia();
        item->m_flags1 = (item->m_flags1 & ~0x1800u) | (2u << 11u);
        uniformGravity.m_isActive = 1;
        zone->AddForceField(&uniformGravity);
        Reset();

        std::cout << "Loaded " << mesh.m_vertices.m_count << " vertices and "
                  << mesh.m_triangles.m_count << " collision triangles.\n";
        return true;
    }

    void Reset() {
        dyna->Position() = startPosition;
        dyna->SetYaw(startYaw);
        GmVec3 zero(0.0f, 0.0f, 0.0f);
        item->SetLinearSpeed(item, &zero);
        item->SetAngularSpeed(item, &zero);
        item->SetForce(item, &zero);
        item->SetTorque(item, &zero);
        car->m_inputGas = 0.0f;
        car->m_inputBrake = 0.0f;
        car->m_inputSteer = 0.0f;
        car->m_smoothedSteer = 0.0f;
        car->m_chassisUp = GmVec3(0.0f, 1.0f, 0.0f);
        car->m_engine.Reset();
        for (uint32_t i = 0; i < car->m_wheels.GetCount(); ++i) {
            auto& wheel = car->m_wheels[i];
            wheel.m_hasGroundContact = 0;
            wheel.m_groundMaterial = 0xffff;
            wheel.m_isSlipping = 0;
            wheel.m_realTimeState.m_angularVelocity = 0.0f;
            wheel.m_realTimeState.m_rotationAngle = 0.0f;
            wheel.m_realTimeState.m_velocity = 0.0f;
            wheel.m_realTimeState.m_compression = 0.0f;
            wheel.m_realTimeState.m_absorbDelta = 0.0f;
        }
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

    GmSurfMesh mesh;
    CSceneVehicleCar* car = nullptr;
    CHmsItem* item = nullptr;
    CHmsCorpus* corpus = nullptr;
    CHmsDyna* dyna = nullptr;
    CHmsZoneDynamic* zone = nullptr;
    CSceneVehicleCarTuning tuning;
    CPlugPhysicalObject physicalObject;
    CHmsForceFieldUniform uniformGravity;
    VehicleTrackStepDiagnostics lastDiagnostics;
    std::deque<GmVec3> trail;
    GmVec3 startPosition = kDefaultStart;
    float startYaw = kDefaultYaw;
    double simulatedSeconds = 0.0;
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
    camera.right = Normalized(GmVec3::Cross(
        GmVec3(0.0f, 1.0f, 0.0f), camera.forward));
    if (LengthSquared(camera.right) <= 1.0e-10f) {
        camera.right = GmVec3(1.0f, 0.0f, 0.0f);
    }
    camera.up = Normalized(GmVec3::Cross(camera.forward, camera.right));
    camera.focalLength = static_cast<float>(camera.height) * 0.86f;
    return camera;
}

CameraPoint ToCamera(const Camera& camera, const GmVec3& world) {
    const GmVec3 relative = world - camera.position;
    return {
        GmVec3::Dot(relative, camera.right),
        GmVec3::Dot(relative, camera.up),
        GmVec3::Dot(relative, camera.forward),
    };
}

bool DrawPerspectiveLine(
    SDL_Renderer* renderer, const Camera& camera,
    const GmVec3& worldA, const GmVec3& worldB) {
    CameraPoint a = ToCamera(camera, worldA);
    CameraPoint b = ToCamera(camera, worldB);
    if (a.z < camera.nearPlane && b.z < camera.nearPlane) return false;
    if (a.z < camera.nearPlane) {
        const float amount =
            (camera.nearPlane - a.z) / (b.z - a.z);
        a.x += (b.x - a.x) * amount;
        a.y += (b.y - a.y) * amount;
        a.z = camera.nearPlane;
    } else if (b.z < camera.nearPlane) {
        const float amount =
            (camera.nearPlane - b.z) / (a.z - b.z);
        b.x += (a.x - b.x) * amount;
        b.y += (a.y - b.y) * amount;
        b.z = camera.nearPlane;
    }

    const float ax = camera.width * 0.5f + a.x * camera.focalLength / a.z;
    const float ay = camera.height * 0.5f - a.y * camera.focalLength / a.z;
    const float bx = camera.width * 0.5f + b.x * camera.focalLength / b.z;
    const float by = camera.height * 0.5f - b.y * camera.focalLength / b.z;
    const float margin = 200.0f;
    if ((ax < -margin && bx < -margin) ||
        (ax > camera.width + margin && bx > camera.width + margin) ||
        (ay < -margin && by < -margin) ||
        (ay > camera.height + margin && by > camera.height + margin)) {
        return false;
    }
    SDL_RenderDrawLineF(renderer, ax, ay, bx, by);
    return true;
}

SDL_FPoint ToTopDown(
    const GmVec3& world, const GmVec3& origin,
    const VehicleChassisBasis& basis,
    float zoom, int width, int height) {
    const GmVec3 relative = world - origin;
    return {
        width * 0.5f + GmVec3::Dot(relative, basis.right) * zoom,
        height * 0.62f - GmVec3::Dot(relative, basis.forward) * zoom,
    };
}

void SetTrackColor(SDL_Renderer* renderer, const GmSurfTriangle& triangle) {
    const float up = std::abs(triangle.planeNormal.y);
    if (up > 0.72f) {
        SDL_SetRenderDrawColor(renderer, 86, 101, 104, 185);
    } else if (up > 0.25f) {
        SDL_SetRenderDrawColor(renderer, 71, 91, 105, 175);
    } else {
        SDL_SetRenderDrawColor(renderer, 58, 76, 92, 165);
    }
}

int DrawTrackChase(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const Camera& camera) {
    constexpr float radiusSquared = 150.0f * 150.0f;
    int drawn = 0;
    for (uint32_t i = 0; i < simulation.mesh.m_triangles.m_count; ++i) {
        const GmSurfTriangle& triangle = simulation.mesh.m_triangles[i];
        const GmVec3& a = simulation.mesh.m_vertices[triangle.indices[0]];
        const GmVec3& b = simulation.mesh.m_vertices[triangle.indices[1]];
        const GmVec3& c = simulation.mesh.m_vertices[triangle.indices[2]];
        const float centerX =
            (a.x + b.x + c.x) / 3.0f - simulation.dyna->Position().x;
        const float centerZ =
            (a.z + b.z + c.z) / 3.0f - simulation.dyna->Position().z;
        if (centerX * centerX + centerZ * centerZ > radiusSquared) continue;
        SetTrackColor(renderer, triangle);
        bool visible = DrawPerspectiveLine(renderer, camera, a, b);
        visible = DrawPerspectiveLine(renderer, camera, b, c) || visible;
        visible = DrawPerspectiveLine(renderer, camera, c, a) || visible;
        if (visible) ++drawn;
    }
    return drawn;
}

int DrawTrackTopDown(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const VehicleChassisBasis& basis, float zoom, int width, int height) {
    const float radius = std::min(
        280.0f, std::max(45.0f, std::max(width, height) / zoom * 0.85f));
    const float radiusSquared = radius * radius;
    int drawn = 0;
    for (uint32_t i = 0; i < simulation.mesh.m_triangles.m_count; ++i) {
        const GmSurfTriangle& triangle = simulation.mesh.m_triangles[i];
        const GmVec3& a = simulation.mesh.m_vertices[triangle.indices[0]];
        const GmVec3& b = simulation.mesh.m_vertices[triangle.indices[1]];
        const GmVec3& c = simulation.mesh.m_vertices[triangle.indices[2]];
        const float centerX =
            (a.x + b.x + c.x) / 3.0f - simulation.dyna->Position().x;
        const float centerZ =
            (a.z + b.z + c.z) / 3.0f - simulation.dyna->Position().z;
        if (centerX * centerX + centerZ * centerZ > radiusSquared) continue;
        const SDL_FPoint pa = ToTopDown(
            a, simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint pb = ToTopDown(
            b, simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint pc = ToTopDown(
            c, simulation.dyna->Position(), basis, zoom, width, height);
        SetTrackColor(renderer, triangle);
        SDL_RenderDrawLineF(renderer, pa.x, pa.y, pb.x, pb.y);
        SDL_RenderDrawLineF(renderer, pb.x, pb.y, pc.x, pc.y);
        SDL_RenderDrawLineF(renderer, pc.x, pc.y, pa.x, pa.y);
        ++drawn;
    }
    return drawn;
}

void DrawCarChase(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const Camera& camera) {
    const VehicleChassisBasis basis = BuildVehicleChassisBasis(
        simulation.car->m_chassisUp, simulation.dyna->GetYaw());
    constexpr float halfWidth = 0.95f;
    constexpr float halfHeight = 0.45f;
    constexpr float halfLength = 1.8f;
    GmVec3 corners[8];
    for (int i = 0; i < 8; ++i) {
        corners[i] = simulation.dyna->Position() +
            basis.right * ((i & 1) ? halfWidth : -halfWidth) +
            basis.up * ((i & 2) ? halfHeight : -halfHeight) +
            basis.forward * ((i & 4) ? halfLength : -halfLength);
    }
    constexpr int edges[12][2] = {
        {0, 1}, {0, 2}, {0, 4}, {1, 3}, {1, 5}, {2, 3},
        {2, 6}, {3, 7}, {4, 5}, {4, 6}, {5, 7}, {6, 7},
    };
    SDL_SetRenderDrawColor(renderer, 246, 187, 57, 255);
    for (const auto& edge : edges) {
        DrawPerspectiveLine(renderer, camera, corners[edge[0]], corners[edge[1]]);
    }

    for (int i = 0; i < simulation.lastDiagnostics.wheelCount; ++i) {
        const GmVec3 wheel = simulation.dyna->Position() +
            basis.right * TmForeverPhysicsConstants::kStadiumWheelLocalX[i] +
            basis.up * TmForeverPhysicsConstants::kStadiumWheelLocalY[i] +
            basis.forward * TmForeverPhysicsConstants::kStadiumWheelLocalZ[i];
        SDL_SetRenderDrawColor(
            renderer,
            simulation.car->m_wheels[i].m_hasGroundContact ? 70 : 238,
            simulation.car->m_wheels[i].m_hasGroundContact ? 220 : 72,
            70, 255);
        DrawPerspectiveLine(
            renderer, camera, wheel - basis.up * 0.25f,
            wheel + basis.up * 0.25f);
    }

    SDL_SetRenderDrawColor(renderer, 72, 220, 115, 255);
    DrawPerspectiveLine(
        renderer, camera, simulation.dyna->Position(),
        simulation.dyna->Position() + simulation.car->m_chassisUp * 2.0f);
}

void DrawCarTopDown(SDL_Renderer* renderer, int width, int height) {
    const float centerX = width * 0.5f;
    const float centerY = height * 0.62f;
    SDL_FPoint outline[5] = {
        {centerX, centerY - 18.0f},
        {centerX + 10.0f, centerY + 13.0f},
        {centerX, centerY + 8.0f},
        {centerX - 10.0f, centerY + 13.0f},
        {centerX, centerY - 18.0f},
    };
    SDL_SetRenderDrawColor(renderer, 246, 187, 57, 255);
    SDL_RenderDrawLinesF(renderer, outline, 5);
}

void DrawTrail(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const ViewState& view, const Camera& camera,
    const VehicleChassisBasis& basis, int width, int height) {
    if (simulation.trail.size() < 2) return;
    SDL_SetRenderDrawColor(renderer, 235, 108, 67, 220);
    auto previous = simulation.trail.begin();
    auto point = previous;
    ++point;
    for (; point != simulation.trail.end(); ++point, ++previous) {
        if (view.topDown) {
            const SDL_FPoint a = ToTopDown(
                *previous, simulation.dyna->Position(), basis,
                view.topDownZoom, width, height);
            const SDL_FPoint b = ToTopDown(
                *point, simulation.dyna->Position(), basis,
                view.topDownZoom, width, height);
            SDL_RenderDrawLineF(renderer, a.x, a.y, b.x, b.y);
        } else {
            DrawPerspectiveLine(renderer, camera, *previous, *point);
        }
    }
}

int Render(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const ViewState& view, int width, int height) {
    SDL_SetRenderDrawColor(renderer, 13, 17, 23, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    const VehicleChassisBasis basis = BuildVehicleChassisBasis(
        simulation.car->m_chassisUp, simulation.dyna->GetYaw());
    const Camera camera = BuildChaseCamera(simulation, view, width, height);
    int trianglesDrawn = 0;
    if (view.topDown) {
        trianglesDrawn = DrawTrackTopDown(
            renderer, simulation, basis, view.topDownZoom, width, height);
    } else {
        trianglesDrawn = DrawTrackChase(renderer, simulation, camera);
    }
    DrawTrail(renderer, simulation, view, camera, basis, width, height);
    if (view.topDown) {
        DrawCarTopDown(renderer, width, height);
    } else {
        DrawCarChase(renderer, simulation, camera);
    }

    SDL_SetRenderDrawColor(renderer, 220, 225, 230, 100);
    SDL_RenderDrawLine(renderer, width / 2 - 6, height / 2,
                      width / 2 + 6, height / 2);
    SDL_RenderDrawLine(renderer, width / 2, height / 2 - 6,
                      width / 2, height / 2 + 6);
    return trianglesDrawn;
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

    std::cout
        << "Controls: W/Up accelerate, S/Down brake/reverse, A/D or arrows steer\n"
        << "          C camera, mouse wheel zoom, Space pause, N single-step, R reset, Esc quit\n";

    ViewState view;
    view.topDown = options.topDown;
    bool running = true;
    bool paused = false;
    bool singleStep = false;
    double accumulator = 0.0;
    const double counterFrequency =
        static_cast<double>(SDL_GetPerformanceFrequency());
    uint64_t previousCounter = SDL_GetPerformanceCounter();
    uint32_t lastTitleUpdate = 0;
    int renderedFrames = 0;
    int trianglesDrawn = 0;
    bool screenshotSaved = false;

    while (running &&
           (options.frameLimit < 0 || renderedFrames < options.frameLimit)) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;
            if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE: running = false; break;
                    case SDLK_c: view.topDown = !view.topDown; break;
                    case SDLK_r: simulation.Reset(); accumulator = 0.0; break;
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
        elapsed = std::min(elapsed, 0.1);

        const Uint8* keys = SDL_GetKeyboardState(nullptr);
        const float gas =
            (keys[SDL_SCANCODE_W] || keys[SDL_SCANCODE_UP]) ? 1.0f : 0.0f;
        const float brake =
            (keys[SDL_SCANCODE_S] || keys[SDL_SCANCODE_DOWN]) ? 1.0f : 0.0f;
        const float steerLeft =
            (keys[SDL_SCANCODE_A] || keys[SDL_SCANCODE_LEFT]) ? 1.0f : 0.0f;
        const float steerRight =
            (keys[SDL_SCANCODE_D] || keys[SDL_SCANCODE_RIGHT]) ? 1.0f : 0.0f;
        simulation.SetInput(gas, brake, steerRight - steerLeft);

        if (!paused) accumulator += elapsed;
        if (singleStep) accumulator = kPhysicsDt;
        int stepCount = 0;
        while (accumulator >= kPhysicsDt && stepCount < 12) {
            simulation.Step();
            accumulator -= kPhysicsDt;
            ++stepCount;
            if (singleStep) break;
        }
        if (stepCount == 12 && accumulator >= kPhysicsDt) accumulator = 0.0;
        singleStep = false;

        int width = 1;
        int height = 1;
        SDL_GetRendererOutputSize(renderer, &width, &height);
        trianglesDrawn = Render(
            renderer, simulation, view, width, height);
        if (!screenshotSaved && !options.screenshotPath.empty()) {
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
        SDL_RenderPresent(renderer);
        ++renderedFrames;

        const uint32_t nowMs = SDL_GetTicks();
        if (nowMs - lastTitleUpdate >= 100 || renderedFrames == 1) {
            char title[512];
            std::snprintf(
                title, sizeof(title),
                "TMNF Physics | %6.1f km/h | t %.2fs | pos %.2f %.2f %.2f | "
                "%d/4 wheels | %s%s | %d tris",
                simulation.SpeedKmh(), simulation.simulatedSeconds,
                simulation.dyna->Position().x,
                simulation.dyna->Position().y,
                simulation.dyna->Position().z,
                simulation.lastDiagnostics.groundedWheelCount,
                view.topDown ? "top" : "chase",
                paused ? " | PAUSED" : "", trianglesDrawn);
            SDL_SetWindowTitle(window, title);
            lastTitleUpdate = nowMs;
        }
        SDL_Delay(1);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Final state: t=" << simulation.simulatedSeconds
              << "s pos=(" << simulation.dyna->Position().x << ", "
              << simulation.dyna->Position().y << ", "
              << simulation.dyna->Position().z << ") speed="
              << simulation.SpeedKmh() << " km/h grounded="
              << simulation.lastDiagnostics.groundedWheelCount << "/4\n";
    return 0;
}
