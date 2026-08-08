#include <iostream>
#include <iomanip>
#include "../TuningData.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <limits>
#include "Scene/CSceneVehicleCar.hpp"

#include "CHmsCorpus.hpp"
#include "CHmsDyna.hpp"
#include "CHmsZoneDynamic.hpp"
#include "SHmsPhysicalCollision.hpp"
#include "Hms/CHmsItem.hpp"
#include "Gm/GmVec3.hpp"
#include "Gm/GmIso4.hpp"
#include "Gm/GmSurf.hpp"
#include "Scene/CSceneVehicleCarTuning.hpp"
#include "Scene/TmForeverPhysicsConstants.hpp"
#include "Scene/VehicleGroundSupport.hpp"
#include "Track/TrackMapLoader.hpp"
#include "Game/CGameCtnReplayRecord.hpp"
#include "Classic/CClassicArchive.hpp"
#include "Plug/CPlugSolid.hpp"

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

extern "C" {
#include "gbx_map/gbx_map.h"
}

// External variables for harness stubs
// =================================================================
// Ghost Sample for ground truth comparison
// =================================================================
struct GhostSample {
    uint32_t time_ms;
    float x, y, z;
    float speed_kmh;
};

std::vector<GhostSample> LoadGhostSamples(const char* csvPath) {
    std::vector<GhostSample> samples;
    std::ifstream file(csvPath);
    if (!file.is_open()) {
        std::cerr << "ERROR: Cannot open ghost CSV: " << csvPath << std::endl;
        return samples;
    }
    std::string line;
    std::getline(file, line); // Skip header
    while (std::getline(file, line)) {
        GhostSample s;
        char comma;
        std::istringstream iss(line);
        iss >> s.time_ms >> comma >> s.x >> comma >> s.y >> comma >> s.z >> comma >> s.speed_kmh;
        samples.push_back(s);
    }
    return samples;
}

// =================================================================
// Desync Testing Framework
// =================================================================
struct DesyncResult {
    uint32_t time_ms;
    float error_x, error_y, error_z;
    float error_total;
    float ghost_x, ghost_y, ghost_z;
    float sim_x, sim_y, sim_z;
    float ghost_speed, sim_speed;
};

int main(int argc, char* argv[]) {
    bool traceInputs = false;
    bool traceForces = false;
    std::string mapPath =
        "../steamdata/GameData/Tracks/Campaigns/Nations/White/"
        "A01-Race.Challenge.Gbx";
    TrackMapLoadOptions mapLoadOptions;
    mapLoadOptions.packsDirectory = "../steamdata/Packs";
    mapLoadOptions.extractorProject =
        "TrackCollisionExtractor/TrackCollisionExtractor.csproj";
    for (int i = 1; i < argc; ++i) {
        if (std::strcmp(argv[i], "--trace-inputs") == 0) {
            traceInputs = true;
        } else if (std::strcmp(argv[i], "--trace-forces") == 0) {
            traceForces = true;
        } else if (std::strncmp(argv[i], "--collision=", 12) == 0) {
            mapPath = argv[i] + 12;
        } else if (std::strncmp(argv[i], "--map=", 6) == 0) {
            mapPath = argv[i] + 6;
        } else if (std::strncmp(argv[i], "--packs=", 8) == 0) {
            mapLoadOptions.packsDirectory = argv[i] + 8;
        } else if (std::strncmp(argv[i], "--extractor=", 12) == 0) {
            mapLoadOptions.extractorProject = argv[i] + 12;
        } else if (std::strncmp(argv[i], "--cache-dir=", 12) == 0) {
            mapLoadOptions.cacheDirectory = argv[i] + 12;
        } else if (std::strcmp(argv[i], "--rebuild-map-cache") == 0) {
            mapLoadOptions.forceCacheRebuild = true;
        }
    }

    std::cout << "============================================================" << std::endl;
    std::cout << " TMNF Physics 1:1 Desync Test - A01-Race" << std::endl;
    std::cout << "============================================================" << std::endl;

    // 1. Load Ghost Ground Truth
    std::vector<GhostSample> ghostSamples = LoadGhostSamples("a01_ghost_samples.csv");
    if (ghostSamples.empty()) {
        std::cerr << "Failed to load ghost samples!" << std::endl;
        return 1;
    }
    std::cout << "Loaded " << ghostSamples.size() << " ghost samples (ground truth)" << std::endl;
    std::cout << "Ghost start: (" << ghostSamples[0].x << ", " << ghostSamples[0].y << ", " << ghostSamples[0].z << ")" << std::endl;
    std::cout << "Ghost end:   (" << ghostSamples.back().x << ", " << ghostSamples.back().y << ", " << ghostSamples.back().z << ")" << std::endl;

    // 2. Load the map and exact collision surfaces selected by its block
    // variants. Challenge.Gbx inputs are resolved against Stadium.pak and the
    // derived collision is cached automatically.
    GmSurfMesh worldMesh;
    TrackMapLoadResult mapLoadResult;
    if (!LoadTrackMapCollision(
            worldMesh, mapPath, mapLoadOptions, &mapLoadResult)) {
        std::cerr << "Failed to load A01 map: " << mapPath << '\n'
                  << mapLoadResult.error << std::endl;
        return 1;
    }
    if (mapLoadResult.sourceWasChallengeGbx) {
        std::cout << "Map: " << mapLoadResult.mapName << " by "
                  << mapLoadResult.mapAuthor << ", "
                  << mapLoadResult.blockCount << " placed blocks\n"
                  << "Collision cache: " << mapLoadResult.collisionCachePath
                  << (mapLoadResult.cacheHit ? " [reused]" : " [generated]")
                  << std::endl;
    }
    std::cout << "Track mesh: " << worldMesh.m_vertices.m_count << " verts, "
              << worldMesh.m_triangles.m_count << " tris" << std::endl;

    // 3. Load Replay Inputs
    CClassicArchive* replayArchive = CClassicArchive::LoadFromGbx(
        "../steamdata/GameData/Tracks/Campaigns/Nations/White/A01-Race.Replay.gbx");
    if (!replayArchive) {
        std::cerr << "Failed to load replay!" << std::endl;
        return 1;
    }
    CGameCtnReplayRecord* replay = new CGameCtnReplayRecord();
    if (!replayArchive->ScanForChunk(0x03092019)) {
        std::cerr << "Failed to find input chunk!" << std::endl;
        return 1;
    }
    replay->Chunk(nullptr, replayArchive, 0x03092019);
    std::cout << "Loaded " << replay->m_events.size() << " input events" << std::endl;
    const int eventPreviewCount = traceInputs
        ? static_cast<int>(replay->m_events.size())
        : std::min(5, static_cast<int>(replay->m_events.size()));
    for (int i = 0; i < eventPreviewCount; ++i) {
        printf("Ev[%d] t=%u ctrl=%u val=%u\n", i, replay->m_events[i].time, replay->m_events[i].controlIdx, replay->m_events[i].value);
    }

    // Map control names
    int accelerateIdx = -1, brakeIdx = -1, steerRightIdx = -1, steerLeftIdx = -1, steerIdx = -1;
    for (size_t i = 0; i < replay->m_controlNames.size(); ++i) {
        const std::string& name = replay->m_controlNames[i];
        printf("Control %zu: %s\n", i, name.c_str());
        if (name == "Accelerate" || name == "UnknownId_524288") accelerateIdx = i;
        if (name == "Brake" || name == "UnknownId_524289") brakeIdx = i;
        if (name == "SteerLeft" || name == "UnknownId_524290") steerLeftIdx = i;
        if (name == "SteerRight" || name == "UnknownId_524291") steerRightIdx = i;
        if (name == "Steer" || name == "UnknownId_524292") steerIdx = i;
    }

    // 4. Setup Car at ghost start position
    CSceneVehicleCar* car = new CSceneVehicleCar();
    CHmsItem* item = new CHmsItem();
    CHmsCorpus* corpus = new CHmsCorpus();
    CHmsDyna* dyna = new CHmsDyna();

    car->m_hmsItem = item;
    item->m_corpuses.Add(corpus);
    corpus->m_dyna = dyna;
    corpus->m_item = item;

    // Start at the ghost's initial position
    GmVec3 startPos(ghostSamples[0].x, ghostSamples[0].y, ghostSamples[0].z);
    GmVec3 vel(0.0f, 0.0f, 0.0f);

    dyna->m_position = startPos;
    dyna->m_yaw = 1.57079632679f; // PI/2, facing +X
    item->SetLinearSpeed(item, &vel);
    car->SetTranslation(nullptr, &startPos);

    car->m_simulationFlags = 7;
    car->m_inputGas = 0.0f;
    car->m_inputBrake = 0.0f;
    car->m_inputSteer = 0.0f;

    CSceneVehicleCarTuning* tuning = new CSceneVehicleCarTuning();
    InitTuningData(tuning);
    g_tuning = tuning;

    CHmsZoneDynamic* zoneDyn = new CHmsZoneDynamic();
    zoneDyn->m_dynamicItems.Add(item);

    // Determine initial car orientation from first two ghost samples
    // The car faces from sample[0] to sample[1]
    if (ghostSamples.size() >= 10) {
        float dx = ghostSamples[9].x - ghostSamples[0].x;
        float dz = ghostSamples[9].z - ghostSamples[0].z;
        if (std::abs(dx) > 0.01f || std::abs(dz) > 0.01f) {
            dyna->m_yaw = std::atan2(dx, dz); // atan2(sin, cos) = atan2(fwdX, fwdZ)
            std::cout << "Initial yaw from ghost trajectory: " << dyna->m_yaw << " rad ("
                      << (dyna->m_yaw * 180.0f / 3.14159265f) << " deg)" << std::endl;
        }
    }

    // 5. Simulation Loop
    float dt = 0.01f;
    uint32_t raceStartMs = 100000;
    uint32_t currentEventIdx = 0;

    // Skip pre-race events
    while (currentEventIdx < replay->m_events.size() &&
           replay->m_events[currentEventIdx].time < raceStartMs) {
        currentEventIdx++;
    }

    // Calculate simulation duration from ghost data
    uint32_t ghostDurationMs = ghostSamples.back().time_ms;
    int maxSteps = (ghostDurationMs / 10) + 100; // Run a bit past the ghost

    // Track desync
    std::vector<DesyncResult> desyncLog;
    int ghostSampleIdx = 0;
    float maxError = 0.0f;
    float firstDesyncTime = -1.0f;
    const float DESYNC_THRESHOLD = 1.0f; // 1 meter = definite desync
    GmIso4 worldMeshTransform;
    worldMeshTransform.SetIdentity();

    std::cout << "\n============================================================" << std::endl;
    std::cout << " Starting Desync Test (threshold=" << DESYNC_THRESHOLD << "m)" << std::endl;
    std::cout << "============================================================\n" << std::endl;

    // Open detailed log file
    std::ofstream logFile("desync_log.csv");
    logFile << "time_ms,ghost_x,ghost_y,ghost_z,ghost_spd,sim_x,sim_y,sim_z,sim_spd,err_x,err_y,err_z,err_total" << std::endl;

    auto compareWithGhost = [&](uint32_t raceTimeMs) {
        if (raceTimeMs % 100 != 0 || ghostSampleIdx >= (int)ghostSamples.size()) return;

        while (ghostSampleIdx < (int)ghostSamples.size() - 1 &&
               ghostSamples[ghostSampleIdx].time_ms < raceTimeMs) {
            ghostSampleIdx++;
        }
        if (ghostSamples[ghostSampleIdx].time_ms != raceTimeMs) return;

        const GhostSample& gs = ghostSamples[ghostSampleIdx];
        const float errX = dyna->m_position.x - gs.x;
        const float errY = dyna->m_position.y - gs.y;
        const float errZ = dyna->m_position.z - gs.z;
        const float errTotal = std::sqrt(errX * errX + errY * errY + errZ * errZ);

        GmVec3 simVel;
        item->GetLinearSpeed(item, &simVel);
        const float simSpeed = std::sqrt(
            simVel.x * simVel.x + simVel.y * simVel.y + simVel.z * simVel.z) * 3.6f;

        logFile << raceTimeMs << ","
                << gs.x << "," << gs.y << "," << gs.z << "," << gs.speed_kmh << ","
                << dyna->m_position.x << "," << dyna->m_position.y << "," << dyna->m_position.z << "," << simSpeed << ","
                << errX << "," << errY << "," << errZ << "," << errTotal << std::endl;

        if (errTotal > maxError) maxError = errTotal;

        const bool shouldPrint = (raceTimeMs <= 2000 && raceTimeMs % 100 == 0) ||
                                 (raceTimeMs % 1000 == 0) ||
                                 (errTotal > DESYNC_THRESHOLD && firstDesyncTime < 0);
        if (shouldPrint) {
            std::cout << std::fixed << std::setprecision(3)
                      << "T=" << std::setw(6) << raceTimeMs << "ms"
                      << " | Ghost=(" << std::setw(8) << gs.x << "," << std::setw(8) << gs.y << "," << std::setw(8) << gs.z << ")"
                      << " | Sim=(" << std::setw(8) << dyna->m_position.x << "," << std::setw(8) << dyna->m_position.y << "," << std::setw(8) << dyna->m_position.z << ")"
                      << " | Err=" << std::setw(8) << errTotal << "m"
                      << " | Spd G=" << std::setw(6) << gs.speed_kmh << " S=" << std::setw(6) << simSpeed;

            if (errTotal > DESYNC_THRESHOLD) {
                std::cout << " *** DESYNC ***";
                if (firstDesyncTime < 0) firstDesyncTime = raceTimeMs / 1000.0f;
            }
            std::cout << std::endl;
        }

        DesyncResult dr;
        dr.time_ms = raceTimeMs;
        dr.error_x = errX; dr.error_y = errY; dr.error_z = errZ;
        dr.error_total = errTotal;
        dr.ghost_x = gs.x; dr.ghost_y = gs.y; dr.ghost_z = gs.z;
        dr.sim_x = dyna->m_position.x; dr.sim_y = dyna->m_position.y; dr.sim_z = dyna->m_position.z;
        dr.ghost_speed = gs.speed_kmh; dr.sim_speed = simSpeed;
        desyncLog.push_back(dr);
    };

    for (int t = 0; t < maxSteps; ++t) {
        uint32_t currentSimTimeMs = raceStartMs + (t * 10);
        uint32_t raceTimeMs = t * 10;

        // The state at loop entry is the state at raceTimeMs. Compare before
        // integrating the frame from raceTimeMs to raceTimeMs + 10.
        compareWithGhost(raceTimeMs);

        // CLEAR FORCES from previous frame!
        dyna->m_force = GmVec3(0, 0, 0);
        dyna->m_torque = GmVec3(0, 0, 0);

        // 1. Process Input events
        while (currentEventIdx < replay->m_events.size()) {
            const auto& ev = replay->m_events[currentEventIdx];
            if (ev.time > currentSimTimeMs) break;

            if (ev.controlIdx == accelerateIdx) {
                car->m_inputGas = (ev.value != 0) ? 1.0f : 0.0f;
            } else if (ev.controlIdx == brakeIdx) {
                car->m_inputBrake = (ev.value != 0) ? 1.0f : 0.0f;
            } else if (ev.controlIdx == steerRightIdx) {
                if (ev.value != 0) car->m_inputSteer = 1.0f;
                else if (car->m_inputSteer > 0.0f) car->m_inputSteer = 0.0f;
            } else if (ev.controlIdx == steerLeftIdx) {
                if (ev.value != 0) car->m_inputSteer = -1.0f;
                else if (car->m_inputSteer < 0.0f) car->m_inputSteer = 0.0f;
            } else if (ev.controlIdx == steerIdx) {
                int32_t steerVal = *reinterpret_cast<const int32_t*>(&ev.value);
                car->m_inputSteer = steerVal / 65535.0f;
            }
            currentEventIdx++;
        }

        // Physics step
        GmVec3 zero(0, 0, 0);
        item->SetForce(item, &zero);
        // Query each exact Stadium wheel surface independently. The original
        // contact system works at these solid-node transforms; a center ray
        // incorrectly gave all four wheels the same contact and material.
        const VehicleChassisBasis queryBasis =
            BuildVehicleChassisBasis(car->m_chassisUp, dyna->m_yaw);
        GmVec3 groundNormal(0.0f, 0.0f, 0.0f);
        float supportedRootY = -std::numeric_limits<float>::infinity();
        int groundedWheelCount = 0;
        bool wheelGroundFound[TmForeverPhysicsConstants::kStadiumWheelCount] = {};
        float wheelGroundY[TmForeverPhysicsConstants::kStadiumWheelCount] = {};
        float wheelTireGap[TmForeverPhysicsConstants::kStadiumWheelCount] = {};
        GmVec3 wheelGroundNormals[TmForeverPhysicsConstants::kStadiumWheelCount] = {};
        VehicleWheelGroundSample supportSamples[
            TmForeverPhysicsConstants::kStadiumWheelCount] = {};
        const int wheelCount = std::min(
            static_cast<int>(car->m_wheels.GetCount()),
            TmForeverPhysicsConstants::kStadiumWheelCount);

        for (int w = 0; w < wheelCount; ++w) {
            CSceneVehicleCar::SSimulationWheel& wheel = car->m_wheels[w];
            const float localX = TmForeverPhysicsConstants::kStadiumWheelLocalX[w];
            const float localY = TmForeverPhysicsConstants::kStadiumWheelLocalY[w];
            const float localZ = TmForeverPhysicsConstants::kStadiumWheelLocalZ[w];
            const GmVec3 localWheelCenter(localX, localY, localZ);
            const GmVec3 wheelOffset =
                queryBasis.right * localX + queryBasis.up * localY +
                queryBasis.forward * localZ;
            const GmVec3 wheelCenter = dyna->m_position + wheelOffset;

            const GmVec3 rayPosition = wheelCenter + GmVec3(0.0f, 0.25f, 0.0f);
            const GmVec3 rayDirection(
                0.0f, -(wheel.m_radius + 0.75f), 0.0f);
            float groundHitT = 1.0f;
            GmVec3 wheelGroundNormal(0.0f, 1.0f, 0.0f);
            const bool foundGround = worldMesh.ClipSegment2(
                rayPosition, rayDirection, worldMeshTransform,
                groundHitT, wheelGroundNormal) != 0;
            const float groundY = foundGround
                ? rayPosition.y + rayDirection.y * groundHitT
                : -std::numeric_limits<float>::infinity();
            const float tireGap = wheelCenter.y - wheel.m_radius - groundY;
            const bool wheelOnGround =
                foundGround && tireGap <= 0.02f && tireGap >= -0.5f;
            wheelGroundFound[w] = foundGround;
            wheelGroundY[w] = groundY;
            wheelTireGap[w] = tireGap;
            wheelGroundNormals[w] = wheelGroundNormal;
            supportSamples[w].usable =
                foundGround && tireGap <= tuning->m_absorbingValRest &&
                tireGap >= -0.5f;
            supportSamples[w].groundPoint =
                GmVec3(wheelCenter.x, groundY, wheelCenter.z);
            supportSamples[w].localWheelCenter = localWheelCenter;
            supportSamples[w].radius = wheel.m_radius;

            uint16_t groundMaterial = 0xffff;
            if (foundGround) {
                float materialHitT = 1.0f;
                worldMesh.ClipSegment3(
                    rayPosition, rayDirection, worldMeshTransform,
                    materialHitT, groundMaterial);
            }
            wheel.m_hasGroundContact = wheelOnGround ? 1 : 0;
            wheel.m_groundMaterial = groundMaterial;

            if (wheelOnGround) {
                ++groundedWheelCount;
                groundNormal += wheelGroundNormal;
                supportedRootY = std::max(
                    supportedRootY, groundY + wheel.m_radius - localY);
            }
        }

        const bool onGround = groundedWheelCount != 0;
        if (onGround) groundNormal.Normalize();
        else groundNormal = GmVec3(0.0f, 1.0f, 0.0f);
        const VehicleGroundSupportResult support = ComputeVehicleGroundSupport(
            supportSamples, wheelCount, dyna->m_yaw);
        if (onGround && support.valid) {
            // This semantic support reconstruction lets the chassis pitch and
            // roll across axle transitions while the native ellipsoid-contact
            // impulse path is still being ported. Strict wheel contact flags
            // above continue to drive the original Model6 branches.
            groundNormal = support.basis.up;
            supportedRootY = support.rootY;
        }
        car->m_chassisUp = groundNormal;

        const float mass = tuning->m_mass;
        GmVec3 gravityForce(
            0.0f,
            TmForeverPhysicsConstants::kDefaultUniformGravity *
                tuning->m_gravityCoef * mass,
            0.0f);
        GmVec3 groundReaction(0.0f, 0.0f, 0.0f);
        if (onGround) {
            GmVec3 currentVelTmp;
            item->GetLinearSpeed(item, &currentVelTmp);
            dyna->m_position.y = supportedRootY;
            const GmVec3 resolvedVelocity =
                RemoveInwardSupportVelocity(currentVelTmp, groundNormal);
            if (resolvedVelocity.x != currentVelTmp.x ||
                resolvedVelocity.y != currentVelTmp.y ||
                resolvedVelocity.z != currentVelTmp.z) {
                currentVelTmp = resolvedVelocity;
                item->SetLinearSpeed(item, &currentVelTmp);
            }

            // Keep full gravity visible to the vehicle callback. Native
            // CHmsDyna rotates this force into chassis space before
            // GetSlopeAdherence; the collision reaction is accumulated after
            // the callback so the final net force remains road-tangential.
            const float normalGravity = GmVec3::Dot(gravityForce, groundNormal);
            groundReaction = groundNormal * -normalGravity;
        }
        item->AddForce(item, &gravityForce, nullptr);

        // Contact state and the frame's pre-existing environment force must
        // be available when the vehicle callback runs. ComputeForces in the
        // fixed executable consumes both to select Model6 ground branches and
        // to derive slope adherence; dispatching before this query left every
        // wheel one frame stale in the standalone harness.
        car->IntegrateVehicle(nullptr, dt);
        // PhysicsStep2 performs the frame's single velocity integration and
        // move after all vehicle and environment forces are accumulated.
        // Calling Integrate here used to apply angular fluid damping twice.
        item->AddForce(item, &groundReaction, nullptr);

        if (traceForces && raceTimeMs % 100 == 0) {
            GmVec3 traceVelocity;
            item->GetLinearSpeed(item, &traceVelocity);
            std::cout << "ForceTrace t=" << raceTimeMs
                      << " pos=(" << dyna->m_position.x << ',' << dyna->m_position.y << ',' << dyna->m_position.z << ')'
                      << " vel=(" << traceVelocity.x << ',' << traceVelocity.y << ',' << traceVelocity.z << ')'
                      << " force=(" << dyna->m_force.x << ',' << dyna->m_force.y << ',' << dyna->m_force.z << ')'
                      << " normal=(" << groundNormal.x << ',' << groundNormal.y << ',' << groundNormal.z << ')'
                      << " groundedWheels=" << groundedWheelCount
                      << " materials=[";
            for (int w = 0; w < wheelCount; ++w) {
                if (w != 0) std::cout << ',';
                std::cout << car->m_wheels[w].m_groundMaterial;
            }
            std::cout << "] wheels=[";
            for (int w = 0; w < wheelCount; ++w) {
                if (w != 0) std::cout << ';';
                std::cout << w << ':';
                if (!wheelGroundFound[w]) {
                    std::cout << "miss";
                    continue;
                }
                std::cout << "y=" << wheelGroundY[w]
                          << ",gap=" << wheelTireGap[w]
                          << ",n=(" << wheelGroundNormals[w].x << ','
                          << wheelGroundNormals[w].y << ','
                          << wheelGroundNormals[w].z << ')';
            }
            std::cout << "]\n";
        }

        zoneDyn->PhysicsStep2();
    }

    logFile.close();

    // Summary
    std::cout << "\n============================================================" << std::endl;
    std::cout << " DESYNC TEST RESULTS" << std::endl;
    std::cout << "============================================================" << std::endl;
    std::cout << "Ghost samples compared: " << desyncLog.size() << std::endl;
    std::cout << "Maximum position error: " << std::fixed << std::setprecision(4) << maxError << " m" << std::endl;

    if (firstDesyncTime >= 0) {
        std::cout << "First desync (>" << DESYNC_THRESHOLD << "m) at: " << firstDesyncTime << "s" << std::endl;
    } else {
        std::cout << "No desync detected (all errors < " << DESYNC_THRESHOLD << "m)" << std::endl;
    }

    // Show error histogram
    int buckets[] = {0, 0, 0, 0, 0, 0}; // <0.01, <0.1, <1, <10, <100, >100
    for (const auto& dr : desyncLog) {
        if (dr.error_total < 0.01f) buckets[0]++;
        else if (dr.error_total < 0.1f) buckets[1]++;
        else if (dr.error_total < 1.0f) buckets[2]++;
        else if (dr.error_total < 10.0f) buckets[3]++;
        else if (dr.error_total < 100.0f) buckets[4]++;
        else buckets[5]++;
    }
    std::cout << "\nError distribution:" << std::endl;
    std::cout << "  < 0.01m (perfect):  " << buckets[0] << " samples" << std::endl;
    std::cout << "  < 0.1m  (close):    " << buckets[1] << " samples" << std::endl;
    std::cout << "  < 1m    (minor):    " << buckets[2] << " samples" << std::endl;
    std::cout << "  < 10m   (desync):   " << buckets[3] << " samples" << std::endl;
    std::cout << "  < 100m  (lost):     " << buckets[4] << " samples" << std::endl;
    std::cout << "  > 100m  (broken):   " << buckets[5] << " samples" << std::endl;

    std::cout << "\nDetailed log saved to: desync_log.csv" << std::endl;
    std::cout << "============================================================" << std::endl;

    // Exit with error code if desynced
    return (firstDesyncTime >= 0) ? 1 : 0;
}
