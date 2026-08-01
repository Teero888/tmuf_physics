#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
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

extern "C" {
#include "gbx_map/gbx_map.h"
}

// External variables for harness stubs
extern GmVec3 g_stub_pos;
float g_carYaw = 1.57079632679f; // PI/2, facing +X

int main() {
    std::cout << "TMNF Physics Reconstruction - Full Race Simulation (Real Raycast)" << std::endl;
    std::cout << "===================================================================" << std::endl;

    // 1. Load Map
    const char* mapPath = "../steamdata/GameData/Tracks/Campaigns/Nations/Black/E05-Endurance.Challenge.Gbx";
    gbx_map_challenge_t* challenge = nullptr;
    // 2. Setup Track Collision Mesh
    CPlugSurfaceGeom* geom = CPlugSurfaceGeom::LoadFromGbx("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B");
    if (!geom || !geom->m_mesh) {
        std::cerr << "Failed to load physics mesh!" << std::endl;
        return 1;
    }
    GmSurfMesh* worldMesh = geom->m_mesh;
    std::cout << "World mesh populated from 0x0900F004 (CPlugSurfaceGeom). Vertices: " 
              << worldMesh->m_vertices.m_count << ", Triangles: " << worldMesh->m_triangles.m_count << std::endl;

    
    std::cout << "World mesh populated with giant floor." << std::endl;


    // Load Replay
    CClassicArchive* solidArchive = CClassicArchive::LoadFromGbx("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B");
    if (!solidArchive) {
        std::cout << "Failed to load Solid GBX! Bypassing..." << std::endl;
    } else {
        if (solidArchive->ScanForChunk(0x0900D002)) {
            std::cout << "Found 0x0900D002!" << std::endl;
        }
        solidArchive->m_buffer->Seek(0);
        if (solidArchive->ScanForChunk(0x0900C000)) {
            std::cout << "Found 0x0900C000!" << std::endl;
        }
        solidArchive->m_buffer->Seek(0);
        CPlugSolid* solid = new CPlugSolid();
        std::cout << "Scanning for Solid Chunk..." << std::endl;
        // We will just let the archive parse it fully using the registered chunks!
        if (solidArchive->ScanForChunk(0x09015000)) {
            std::cout << "Found chunk 0x09015000 (CPlugVisualIndexedTriangles)!" << std::endl;
        } else {
            std::cout << "Chunk 0x09015000 NOT FOUND!" << std::endl;
        }
        
        CClassicBufferRef* ref = (CClassicBufferRef*)solidArchive->m_buffer;
        FILE* dumpFp = fopen("solid_decompressed.bin", "wb");
        if (dumpFp) {
            fwrite(ref->m_memory->m_data, 1, ref->m_memory->m_size, dumpFp);
            fclose(dumpFp);
            std::cout << "Dumped solid_decompressed.bin (" << ref->m_memory->m_size << " bytes)" << std::endl;
        }
    }
    CClassicArchive* replayArchive = CClassicArchive::LoadFromGbx("../steamdata/GameData/Tracks/Campaigns/Nations/Black/E05-Endurance.Replay.Gbx");
    if (!replayArchive) {
        std::cout << "Failed to load Replay GBX!" << std::endl;
        return 1;
    }
    CGameCtnReplayRecord* replay = new CGameCtnReplayRecord();
    if (replayArchive->ScanForChunk(0x03092019)) {
        std::cout << "Found chunk 0x03092019 via scan!" << std::endl;
        replay->Chunk(nullptr, replayArchive, 0x03092019);
    } else {
        std::cout << "Could not find chunk 0x03092019 in replay file." << std::endl;
    }
    uint32_t firstEventTime = replay->m_events.empty() ? 0 : replay->m_events[0].time;
    std::cout << "First Event Time: " << firstEventTime << std::endl;
    std::cout << "Loaded " << replay->m_events.size() << " input events from replay." << std::endl;

    // 3. Setup Car
    CSceneVehicleCar* car = new CSceneVehicleCar();
    CHmsItem* item = new CHmsItem();
    CHmsCorpus* corpus = new CHmsCorpus();
    CHmsDyna* dyna = new CHmsDyna();
    
    car->m_hmsItem = item;
    item->m_corpuses.Add(corpus);
    corpus->m_dyna = dyna;
    corpus->m_item = item;
    
    // Initial State
    GmVec3 pos(483.7f, 73.57f, 80.0f); // Start correctly based on samples.txt
    GmVec3 vel(0.0f, 0.0f, 0.0f);
    
    g_stub_pos = pos;
    item->SetLinearSpeed(item, &vel);
    car->SetTranslation(nullptr, &pos);
    GmVec3 rayOrigin = pos;
    item->SetLinearSpeed(item, &vel);
    
    car->m_simulationFlags = 7; 
    car->m_engine.m_throttle = 1.0f;
    // We need a dummy tuning for ComputeForcesModel3
    CSceneVehicleCarTuning* tuning = new CSceneVehicleCarTuning();
    car->m_field_64 = (uint32_t)(size_t)tuning;
    
    // 4. Simulation Loop
    float dt = 0.01f;
    GmVec3 currentPos = pos;
    GmVec3 currentVel = vel;
    int totalHits = 0;
    
    // We need a zone dynamic for PhysicsStep2
    CHmsZoneDynamic* zoneDyn = new CHmsZoneDynamic();
    zoneDyn->m_dynamicItems.Add(item);
    
    std::cout << "Starting simulation with 1:1 Physics Loop..." << std::endl;
    
    // Convert control names to mapping
    int accelerateIdx = -1;
    int brakeIdx = -1;
    int steerRightIdx = -1;
    int steerLeftIdx = -1;
    int steerIdx = -1;
    for (size_t i = 0; i < replay->m_controlNames.size(); ++i) {
        if (replay->m_controlNames[i] == "UnknownId_524288" || replay->m_controlNames[i] == "Accelerate") accelerateIdx = i;
        if (replay->m_controlNames[i] == "UnknownId_524289" || replay->m_controlNames[i] == "Brake") brakeIdx = i;
        if (replay->m_controlNames[i] == "UnknownId_524290" || replay->m_controlNames[i] == "SteerLeft") steerLeftIdx = i;
        if (replay->m_controlNames[i] == "UnknownId_524291" || replay->m_controlNames[i] == "SteerRight") steerRightIdx = i;
    }
    std::cout << "Control Mappings: Accel=" << accelerateIdx << ", Brake=" << brakeIdx << ", SteerR=" << steerRightIdx << ", SteerL=" << steerLeftIdx << std::endl;
    
    for (int i = 0; i < 10 && i < replay->m_events.size(); ++i) {
        std::cout << "Ev[" << i << "] t=" << replay->m_events[i].time << " ctrl=" << (int)replay->m_events[i].controlIdx << " val=" << replay->m_events[i].value << std::endl;
    }
    
    uint32_t currentEventIdx = 0;

    // Get the first and last event time
    firstEventTime = replay->m_events.empty() ? 0 : replay->m_events[0].time;
    uint32_t lastEventTime = replay->m_events.empty() ? 0 : replay->m_events.back().time;
    uint32_t totalDurationMs = lastEventTime > firstEventTime ? (lastEventTime - firstEventTime) : 0;
    int maxSteps = (totalDurationMs / 10) + 100; // Run slightly past the last input

    std::cout << "Simulating for " << maxSteps << " steps (" << (maxSteps * 0.01f) << "s)..." << std::endl;

    // 4. Emulate the main loop integration step
    for (int t = 0; t < maxSteps; ++t) {
        
        uint32_t currentSimTimeMs = firstEventTime + (t * 10);
        
        // Process inputs
        while (currentEventIdx < replay->m_events.size()) {
            const auto& ev = replay->m_events[currentEventIdx];
            int32_t evTime = (int32_t)ev.time - 100000;
            if (evTime > (int32_t)currentSimTimeMs) break;
            
            if (evTime >= 0) {
                if (ev.controlIdx == accelerateIdx) {
                    car->m_inputGas = (ev.value != 0) ? 1.0f : 0.0f;
                    std::cout << "t=" << currentSimTimeMs << " Gas changed to " << car->m_inputGas << std::endl;
                } else if (ev.controlIdx == brakeIdx) {
                    car->m_inputBrake = (ev.value != 0) ? 1.0f : 0.0f;
                } else if (ev.controlIdx == steerRightIdx) {
                    if (ev.value != 0) car->m_inputSteer = 1.0f;
                    else if (car->m_inputSteer > 0.0f) car->m_inputSteer = 0.0f;
                    std::cout << "t=" << currentSimTimeMs << " SteerR changed to " << car->m_inputSteer << std::endl;
                } else if (ev.controlIdx == steerLeftIdx) {
                    if (ev.value != 0) car->m_inputSteer = -1.0f;
                    else if (car->m_inputSteer < 0.0f) car->m_inputSteer = 0.0f;
                    std::cout << "t=" << currentSimTimeMs << " SteerL changed to " << car->m_inputSteer << std::endl;
                } else if (ev.controlIdx == steerIdx) {
                    // Analog steer value
                    int32_t steerVal = *reinterpret_cast<const int32_t*>(&ev.value);
                    car->m_inputSteer = steerVal / 65535.0f;
                }
            }
            
            currentEventIdx++;
        }
        // Clear forces from last frame
        GmVec3 zero(0,0,0);
        item->SetForce(item, &zero);
        
        // 1. Vehicle adds its engine forces / suspension forces
        car->IntegrateVehicle(nullptr, dt);
        
        // Gravity
        GmVec3 gravity(0, -9.81f * 1500.0f, 0); 
        item->AddForce(item, &gravity, nullptr);
        
        // Simple Steering (Mock)
        if (car->m_inputSteer != 0.0f) {
            g_carYaw += car->m_inputSteer * -1.5f * dt; // Turn rate (negative steer is left)
        }

        // Engine Force (Forward)
        float fwX = std::sin(g_carYaw);
        float fwZ = std::cos(g_carYaw);
        GmVec3 engine(fwX * car->m_engineForce, 0, fwZ * car->m_engineForce);
        item->AddForce(item, &engine, nullptr);

        // 2. We mock the raycast collision detection for now and inject it into zoneDyn collisions
        GmVec3 rayOrigin = g_stub_pos;
        rayOrigin.y += 2.0f;
        GmVec3 rayDir(0, -10.0f, 0); 
        float hitT = 1.0f;
        GmIso4 ident; ident.SetIdentity();
        
        if (worldMesh->ClipSegment(rayOrigin, rayDir, ident, hitT)) {
            car->m_wheels[0].m_hasGroundContact = 1;
            car->m_wheels[0].m_realTimeState.m_compression = 0.5f - (hitT * 10.0f);
            if (t % 100 == 0) { // Print only every 100 steps
                std::cout << "[Step " << t << "] Mesh Raycast HIT at T=" << hitT << " | Z=" << pos.z << std::endl;
            }
            float groundY = rayOrigin.y + rayDir.y * hitT;
            GmVec3 curPos = g_stub_pos;
            
            if (curPos.y <= groundY + 0.35f) {
                // Generate a collision to solve
                SHmsPhysicalCollision col;
                col.m_pos = curPos;
                col.m_pos.y = groundY;
                col.m_normal = GmVec3(0, 1.0f, 0);
                col.m_body1 = corpus;
                col.m_body2 = nullptr;
                col.m_ptr48 = nullptr;
                
                // Add to collisions (this will be picked up by ComputeCollisionResponse)
                zoneDyn->m_collisions.Add(col);
                
                car->m_wheels[0].m_hasGroundContact = 1;
                totalHits++;
            }
        } else {
            car->m_wheels[0].m_hasGroundContact = 0;
        }

        // 3. Step the master physics loop!
        zoneDyn->PhysicsStep2();
        
        currentPos = g_stub_pos;
        item->GetLinearSpeed(item, &currentVel);
        
        if (t % 500 == 0) {
             float mag = sqrt(currentVel.x * currentVel.x + currentVel.z * currentVel.z);
             std::cout << "T: " << (t*dt) << "s | Pos: (" << (int)currentPos.x << ", " << std::fixed << std::setprecision(2) << currentPos.y << ", " << (int)currentPos.z << ") | Spd: " << (int)(mag * 3.6f) << " km/h | Gas: " << car->m_inputGas << " | Steer: " << car->m_inputSteer << std::endl;
        }
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Simulation Finished. Total Ground Hits: " << totalHits << std::endl;

    return 0;
}
