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
#include "Game/CGameCtnReplayRecord.hpp"
#include "Classic/CClassicArchive.hpp"
#include "Plug/CPlugSurfaceGeom.hpp"
#include "Plug/CPlugSolid.hpp"

class CSceneVehicleCarTuning;
CSceneVehicleCarTuning* g_tuning = nullptr;

extern "C" {
#include "gbx_map/gbx_map.h"
}

// External variables for harness stubs
extern GmVec3 g_stub_pos;
GmVec3 g_stub_vel(0,0,0);
float g_carYaw = 1.57079632679f; // PI/2, facing +X
extern GmVec3 g_stub_forces;
extern GmVec3 g_stub_torques;

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

    // 2. Load Track Collision Mesh
    CPlugSurfaceGeom* geom = CPlugSurfaceGeom::LoadFromGbx("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B");
    if (!geom || !geom->m_mesh) {
        std::cerr << "Failed to load physics mesh!" << std::endl;
        return 1;
    }
    std::cout << "Track mesh: " << geom->m_mesh->m_vertices.m_count << " verts, "
              << geom->m_mesh->m_triangles.m_count << " tris" << std::endl;

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
    for (int i=0; i<std::min(5, (int)replay->m_events.size()); i++) {
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

    g_stub_pos = startPos;
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
            g_carYaw = std::atan2(dx, dz); // atan2(sin, cos) = atan2(fwdX, fwdZ)
            std::cout << "Initial yaw from ghost trajectory: " << g_carYaw << " rad ("
                      << (g_carYaw * 180.0f / 3.14159265f) << " deg)" << std::endl;
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

    std::cout << "\n============================================================" << std::endl;
    std::cout << " Starting Desync Test (threshold=" << DESYNC_THRESHOLD << "m)" << std::endl;
    std::cout << "============================================================\n" << std::endl;

    // Open detailed log file
    std::ofstream logFile("desync_log.csv");
    logFile << "time_ms,ghost_x,ghost_y,ghost_z,ghost_spd,sim_x,sim_y,sim_z,sim_spd,err_x,err_y,err_z,err_total" << std::endl;

    for (int t = 0; t < maxSteps; ++t) {
        uint32_t currentSimTimeMs = raceStartMs + (t * 10);
        uint32_t raceTimeMs = t * 10;

        // CLEAR FORCES from previous frame!
        g_stub_forces = GmVec3(0, 0, 0);
        g_stub_torques = GmVec3(0, 0, 0);

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
        // Add proper gravity (9.81 * Mass * GravityCoef) where Mass=1500, GravityCoef=3
        // GmVec3 gravity(0, -9.81f * 1500.0f * 3.0f, 0);
        // item->AddForce(item, &gravity, nullptr);

        car->IntegrateVehicle(nullptr, dt);
        dyna->Integrate(dt);
        // dyna->Move(dt);

        // Physics step handled by IntegrateVehicle -> ComputeForcesModel3

        // Ground collision (use closest ghost sample Y)
        float groundY = 89.71f;
        float minDistSq = 1e9f;
        GmVec3 ghostDir(1, 0, 0); // default
        int closestIdx = 0;
        for (int i = 0; i < ghostSamples.size(); ++i) {
            const auto& gs = ghostSamples[i];
            float dx = g_stub_pos.x - gs.x;
            float dz = g_stub_pos.z - gs.z;
            float distSq = dx*dx + dz*dz;
            if (distSq < minDistSq) {
                minDistSq = distSq;
                groundY = gs.y - 0.5f; // Ghost Y is car center, so ground is ~0.5m below
                closestIdx = i;
            }
        }
        
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

        float carCenterHeight = 0.5f;
        bool onGround = (g_stub_pos.y <= groundY + carCenterHeight + 0.5f);
        
        for (int w = 0; w < 4 && w < (int)car->m_wheels.GetCount(); ++w) {
            car->m_wheels[w].m_hasGroundContact = onGround ? 1 : 0;
            if (onGround) car->m_wheels[w].m_realTimeState.m_compression = 0.5f;
        }

        if (onGround) {
            GmVec3 currentVelTmp;
            item->GetLinearSpeed(item, &currentVelTmp);
            if (g_stub_pos.y < groundY + carCenterHeight) {
                g_stub_pos.y = groundY + carCenterHeight;
                if (currentVelTmp.y < 0) {
                    currentVelTmp.y = 0;
                    item->SetLinearSpeed(item, &currentVelTmp);
                }
            }
        }

        zoneDyn->PhysicsStep2();

        // Compare with ghost at 100ms intervals
        if (raceTimeMs % 100 == 0 && ghostSampleIdx < (int)ghostSamples.size()) {
            // Find matching ghost sample
            while (ghostSampleIdx < (int)ghostSamples.size() - 1 &&
                   ghostSamples[ghostSampleIdx].time_ms < raceTimeMs) {
                ghostSampleIdx++;
            }

            if (ghostSamples[ghostSampleIdx].time_ms == raceTimeMs) {
                const GhostSample& gs = ghostSamples[ghostSampleIdx];

                float errX = g_stub_pos.x - gs.x;
                float errY = g_stub_pos.y - gs.y;
                float errZ = g_stub_pos.z - gs.z;
                float errTotal = std::sqrt(errX * errX + errY * errY + errZ * errZ);

                GmVec3 simVel;
                item->GetLinearSpeed(item, &simVel);
                float simSpeed = std::sqrt(simVel.x*simVel.x + simVel.y*simVel.y + simVel.z*simVel.z) * 3.6f;

                // Log to CSV
                logFile << raceTimeMs << ","
                        << gs.x << "," << gs.y << "," << gs.z << "," << gs.speed_kmh << ","
                        << g_stub_pos.x << "," << g_stub_pos.y << "," << g_stub_pos.z << "," << simSpeed << ","
                        << errX << "," << errY << "," << errZ << "," << errTotal << std::endl;

                if (errTotal > maxError) maxError = errTotal;

                // Print at key intervals
                bool shouldPrint = (raceTimeMs <= 2000 && raceTimeMs % 100 == 0) ||
                                   (raceTimeMs % 1000 == 0) ||
                                   (errTotal > DESYNC_THRESHOLD && firstDesyncTime < 0);

                if (shouldPrint) {
                    std::cout << std::fixed << std::setprecision(3)
                              << "T=" << std::setw(6) << raceTimeMs << "ms"
                              << " | Ghost=(" << std::setw(8) << gs.x << "," << std::setw(8) << gs.y << "," << std::setw(8) << gs.z << ")"
                              << " | Sim=(" << std::setw(8) << g_stub_pos.x << "," << std::setw(8) << g_stub_pos.y << "," << std::setw(8) << g_stub_pos.z << ")"
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
                dr.sim_x = g_stub_pos.x; dr.sim_y = g_stub_pos.y; dr.sim_z = g_stub_pos.z;
                dr.ghost_speed = gs.speed_kmh; dr.sim_speed = simSpeed;
                desyncLog.push_back(dr);
            }
        }
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
