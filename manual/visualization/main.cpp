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
    std::string replayPath;
    GmVec3 start = kDefaultStart;
    float yaw = kDefaultYaw;
    float automaticGas = 0.0f;
    float automaticSteer = 0.0f;
    int frameLimit = -1;
    int simulationStepLimit = -1;
    int traceEvery = 0;
    bool topDown = false;
    bool forceCacheRebuild = false;
    bool useReplayInputs = false;
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
        << "  --simulate N         Run N physics steps without opening a window\n"
        << "  --trace-every N      Print every Nth headless physics state\n"
        << "  --replay-inputs      Drive the simulation with A01 replay inputs\n"
        << "  --replay PATH        Drive the simulation with replay inputs\n"
        << "  --gas VALUE          Constant gas input for --simulate or rendering\n"
        << "  --steer VALUE        Constant steering input (-1 through 1)\n"
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

int DrawStadiumChase(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const Camera& camera) {
    SDL_SetRenderDrawColor(renderer, 47, 59, 72, 145);
    int drawn = 0;
    for (uint32_t i = 0;
         i < simulation.stadiumVisualMesh.m_triangles.GetCount(); ++i) {
        const GmSurfTriangle& triangle =
            simulation.stadiumVisualMesh.m_triangles[i];
        const GmVec3& a =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[0]];
        const GmVec3& b =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[1]];
        const GmVec3& c =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[2]];
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

int DrawStadiumTopDown(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const VehicleChassisBasis& basis, float zoom, int width, int height) {
    SDL_SetRenderDrawColor(renderer, 47, 59, 72, 145);
    int drawn = 0;
    for (uint32_t i = 0;
         i < simulation.stadiumVisualMesh.m_triangles.GetCount(); ++i) {
        const GmSurfTriangle& triangle =
            simulation.stadiumVisualMesh.m_triangles[i];
        const GmVec3& a =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[0]];
        const GmVec3& b =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[1]];
        const GmVec3& c =
            simulation.stadiumVisualMesh.m_vertices[triangle.indices[2]];
        const SDL_FPoint pa = ToTopDown(
            a, simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint pb = ToTopDown(
            b, simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint pc = ToTopDown(
            c, simulation.dyna->Position(), basis, zoom, width, height);
        SDL_RenderDrawLineF(renderer, pa.x, pa.y, pb.x, pb.y);
        SDL_RenderDrawLineF(renderer, pb.x, pb.y, pc.x, pc.y);
        SDL_RenderDrawLineF(renderer, pc.x, pc.y, pa.x, pa.y);
        ++drawn;
    }
    return drawn;
}

GmVec3 VehicleVertexWorld(
    const InteractiveSimulation& simulation, const GmVec3& localVertex) {
    GmIso4 location;
    location.SetIdentity();
    location.rot = simulation.dyna->CurrentState().m_rotationMatrix;
    location.SetTranslation(simulation.dyna->Position());
    GmVec3 worldVertex = localVertex;
    worldVertex.Mult(location);
    return worldVertex;
}

void DrawCarChase(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const Camera& camera) {
    const GmSurfMesh* carMesh = simulation.vehicleAsset.VisualMesh();
    if (carMesh == nullptr) return;
    SDL_SetRenderDrawColor(renderer, 246, 187, 57, 255);
    for (uint32_t index = 0u;
         index < carMesh->m_triangles.GetCount(); ++index) {
        const GmSurfTriangle& triangle = carMesh->m_triangles[index];
        const GmVec3 a = VehicleVertexWorld(
            simulation, carMesh->m_vertices[triangle.indices[0]]);
        const GmVec3 b = VehicleVertexWorld(
            simulation, carMesh->m_vertices[triangle.indices[1]]);
        const GmVec3 c = VehicleVertexWorld(
            simulation, carMesh->m_vertices[triangle.indices[2]]);
        DrawPerspectiveLine(renderer, camera, a, b);
        DrawPerspectiveLine(renderer, camera, b, c);
        DrawPerspectiveLine(renderer, camera, c, a);
    }

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

void DrawCarTopDown(
    SDL_Renderer* renderer, const InteractiveSimulation& simulation,
    const VehicleChassisBasis& basis, float zoom, int width, int height) {
    const GmSurfMesh* carMesh = simulation.vehicleAsset.VisualMesh();
    if (carMesh == nullptr) return;
    SDL_SetRenderDrawColor(renderer, 246, 187, 57, 255);
    for (uint32_t index = 0u;
         index < carMesh->m_triangles.GetCount(); ++index) {
        const GmSurfTriangle& triangle = carMesh->m_triangles[index];
        const SDL_FPoint a = ToTopDown(
            VehicleVertexWorld(simulation,
                carMesh->m_vertices[triangle.indices[0]]),
            simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint b = ToTopDown(
            VehicleVertexWorld(simulation,
                carMesh->m_vertices[triangle.indices[1]]),
            simulation.dyna->Position(), basis, zoom, width, height);
        const SDL_FPoint c = ToTopDown(
            VehicleVertexWorld(simulation,
                carMesh->m_vertices[triangle.indices[2]]),
            simulation.dyna->Position(), basis, zoom, width, height);
        SDL_RenderDrawLineF(renderer, a.x, a.y, b.x, b.y);
        SDL_RenderDrawLineF(renderer, b.x, b.y, c.x, c.y);
        SDL_RenderDrawLineF(renderer, c.x, c.y, a.x, a.y);
    }
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
        trianglesDrawn = DrawStadiumTopDown(
            renderer, simulation, basis, view.topDownZoom, width, height);
        trianglesDrawn += DrawTrackTopDown(
            renderer, simulation, basis, view.topDownZoom, width, height);
    } else {
        trianglesDrawn = DrawStadiumChase(renderer, simulation, camera);
        trianglesDrawn += DrawTrackChase(renderer, simulation, camera);
    }
    DrawTrail(renderer, simulation, view, camera, basis, width, height);
    if (view.topDown) {
        DrawCarTopDown(
            renderer, simulation, basis, view.topDownZoom, width, height);
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

    ReplayInputPlayer replayInputs;
    if (options.useReplayInputs && !replayInputs.Load(options.replayPath)) {
        return 1;
    }

    if (options.simulationStepLimit >= 0) {
        if (!options.useReplayInputs) {
            simulation.SetInput(
                options.automaticGas, 0.0f, options.automaticSteer);
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
                          << simulation.car->m_engineState << '\n';
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
        if (!options.useReplayInputs) {
            simulation.SetInput(
                std::max(gas, options.automaticGas), brake,
                std::clamp(
                    steerRight - steerLeft + options.automaticSteer,
                    -1.0f, 1.0f));
        }

        if (!paused) accumulator += elapsed;
        if (singleStep) accumulator = kPhysicsDt;
        int stepCount = 0;
        while (accumulator >= kPhysicsDt && stepCount < 12) {
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
