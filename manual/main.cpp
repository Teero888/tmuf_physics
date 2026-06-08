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

extern "C" {
#include "gbx_map/gbx_map.h"
}

int main() {
    std::cout << "TMNF Physics Reconstruction - Full Race Simulation (Real Raycast)" << std::endl;
    std::cout << "===================================================================" << std::endl;

    // 1. Load Map
    const char* mapPath = "../steamdata/GameData/Tracks/Campaigns/Nations/Black/E05-Endurance.Challenge.Gbx";
    gbx_map_challenge_t* challenge = nullptr;
    if (gbx_map_parse_challenge(mapPath, &challenge) != 0) {
        return 1;
    }
    std::cout << "Loaded map: " << challenge->map_name << std::endl;

    // 2. Setup World Collision Mesh (Skeletal Map)
    GmSurfMesh* worldMesh = new GmSurfMesh();
    for (size_t i = 0; i < challenge->num_blocks; ++i) {
        gbx_map_map_block_t& block = challenge->blocks[i];
        float bx = block.position.x * 32.0f;
        float by = block.position.y * 8.0f;
        float bz = block.position.z * 32.0f;
        
        GmVec3 c[4] = {
            GmVec3(bx, by, bz),
            GmVec3(bx + 32.0f, by, bz),
            GmVec3(bx + 32.0f, by, bz + 32.0f),
            GmVec3(bx, by, bz + 32.0f)
        };
        
        uint32_t vIdx = worldMesh->m_vertices.m_count;
        for (int j = 0; j < 4; ++j) worldMesh->m_vertices.Add(c[j]);
        
        GmSurfTriangle t1, t2;
        t1.indices[0] = vIdx + 0; t1.indices[1] = vIdx + 1; t1.indices[2] = vIdx + 2;
        t1.planeNormal = GmVec3(0, 1.0f, 0); t1.planeDist = -by;
        t2.indices[0] = vIdx + 0; t2.indices[1] = vIdx + 2; t2.indices[2] = vIdx + 3;
        t2.planeNormal = GmVec3(0, 1.0f, 0); t2.planeDist = -by;
        
        worldMesh->m_triangles.Add(t1);
        worldMesh->m_triangles.Add(t2);
    }
    std::cout << "Mock World mesh created with " << worldMesh->m_triangles.GetCount() << " blocks." << std::endl;

    // Load Replay
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
    GmVec3 pos(240.0f, 16.35f, 432.0f); // Start slightly above the road
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

    for (int t = 0; t < 2500; ++t) {
        uint32_t currentSimTimeMs = t * 10;
        
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
        
        // Engine Force (Forward)
        GmVec3 engine(0, 0, car->m_engineForce);
        item->AddForce(item, &engine, nullptr);
        
        // Simple Steering (Mock)
        if (car->m_inputSteer != 0.0f) {
            GmVec3 steerTorque(0, car->m_inputSteer * -1500.0f, 0);
            item->AddTorque(item, &steerTorque);
        }

        // 2. We mock the raycast collision detection for now and inject it into zoneDyn collisions
        GmVec3 rayOrigin = g_stub_pos;
        rayOrigin.y += 2.0f;
        GmVec3 rayDir(0, -10.0f, 0); 
        float hitT = 1.0f;
        GmIso4 ident; ident.SetIdentity();
        
        if (worldMesh->ClipSegment(rayOrigin, rayDir, ident, hitT)) {
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
             std::cout << "T: " << (t*dt) << "s | Pos: (" << (int)currentPos.x << ", " << std::fixed << std::setprecision(2) << currentPos.y << ", " << (int)currentPos.z << ") | Spd: " << (int)(currentVel.z * 3.6f) << " km/h | Gas: " << car->m_inputGas << " | EngForce: " << car->m_engineForce << std::endl;
        }
    }

    std::cout << "==================================================" << std::endl;
    std::cout << "Simulation Finished. Total Ground Hits: " << totalHits << std::endl;

    return 0;
}
