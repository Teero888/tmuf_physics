import re

with open('main.cpp', 'r') as f:
    content = f.read()

# We want to replace the part in main() where it loads the test mesh
# with our map loader.
# But first we need to make sure we include the necessary headers.

header_patch = """
extern "C" {
#include "gbx_map/gbx_map.h"
}
#include "Gm/GmBlockMap.hpp"
#include <map>
#include <cmath>

GmSurfMesh* BuildGlobalMapMesh(const char* mapPath) {
    gbx_map_challenge_t* map = nullptr;
    if (gbx_map_parse_challenge(mapPath, &map) != 0 || !map) {
        printf("Failed to parse map\\n");
        return nullptr;
    }
    
    GmSurfMesh* globalMesh = new GmSurfMesh();
    std::map<std::string, GmSurfMesh*> meshCache;
    
    for (size_t i = 0; i < map->num_blocks; ++i) {
        auto& b = map->blocks[i];
        std::string blockName = b.name;
        
        if (g_blockMap.find(blockName) == g_blockMap.end()) {
            continue; // Not found
        }
        
        auto& paths = g_blockMap[blockName];
        std::string selectedPath = "";
        
        // Find the right one based on Y
        std::string target = (b.position.y == 8) ? "Ground.Solid.Gbx" : "Air.Solid.Gbx";
        for (auto& p : paths) {
            if (p.find(target) != std::string::npos) {
                selectedPath = p;
                break;
            }
        }
        if (selectedPath.empty() && !paths.empty()) {
            selectedPath = paths[0]; // fallback
        }
        if (selectedPath.empty()) continue;
        
        if (meshCache.find(selectedPath) == meshCache.end()) {
            std::string fullPath = "Stadium_Extract/" + selectedPath;
            CPlugSurfaceGeom* geom = CPlugSurfaceGeom::LoadFromGbx(fullPath.c_str());
            if (geom && geom->m_mesh) {
                meshCache[selectedPath] = geom->m_mesh;
            } else {
                meshCache[selectedPath] = nullptr;
            }
        }
        
        GmSurfMesh* localMesh = meshCache[selectedPath];
        if (!localMesh) continue;
        
        // Compute transform
        // Rotations: 0=0, 1=90, 2=180, 3=270 degrees around Y.
        // In TM, rotation 1 is usually -PI/2 (CW) or +PI/2 (CCW). Let's assume +PI/2 CCW for now.
        // Wait, standard TM rotation is CW or CCW? 
        // We'll use: float angle = -b.rotation * (M_PI / 2.0f);
        float angle = -b.rotation * (M_PI / 2.0f);
        GmIso4 blockTransform;
        blockTransform.Identity();
        
        // Origin is at minimum coordinate. Center of block is (+16, 0, +16).
        // Rotate around center:
        // Translate -16, 0, -16
        // Rotate Y
        // Translate +16, 0, +16
        // Translate to Grid pos: X * 32, Y * 8, Z * 32
        
        GmIso4 rotMatrix;
        rotMatrix.Identity();
        rotMatrix.XX = cos(angle); rotMatrix.XZ = sin(angle);
        rotMatrix.ZX = -sin(angle); rotMatrix.ZZ = cos(angle);
        
        // Applying the transformations:
        // T_grid * T_center * R * T_-center * v
        float tx = b.position.x * 32.0f;
        float ty = b.position.y * 8.0f;
        float tz = b.position.z * 32.0f;
        
        // Wait! In TM, `rot` defines the block orientation.
        // Let's just do it point by point
        int startVert = globalMesh->m_vertices.size();
        for (auto& v : localMesh->m_vertices) {
            float vx = v.x - 16.0f;
            float vy = v.y;
            float vz = v.z - 16.0f;
            
            float rvx = vx * cos(angle) + vz * sin(angle);
            float rvz = -vx * sin(angle) + vz * cos(angle);
            
            GmVec3 finalPos;
            finalPos.x = rvx + 16.0f + tx;
            finalPos.y = vy + ty;
            finalPos.z = rvz + 16.0f + tz;
            
            globalMesh->m_vertices.push_back(finalPos);
        }
        
        for (auto& tri : localMesh->m_triangles) {
            GmTriangle newTri = tri;
            newTri.v1 += startVert;
            newTri.v2 += startVert;
            newTri.v3 += startVert;
            globalMesh->m_triangles.push_back(newTri);
        }
    }
    
    gbx_map_challenge_free(map);
    return globalMesh;
}
"""

content = content.replace('#include "Mw/CMwEngineManager.hpp"', '#include "Mw/CMwEngineManager.hpp"\n' + header_patch)

# Replace the loading code inside main()
main_loader = """
    // CPlugSurfaceGeom* geom = CPlugSurfaceGeom::LoadFromGbx("solid_decompressed.bin");
    // if (!geom || !geom->m_mesh) {
    //     printf("Failed to load mesh\\n");
    //     return 1;
    // }
    // GmSurfMesh* mesh = geom->m_mesh;

    GmSurfMesh* mesh = BuildGlobalMapMesh("../steamdata/GameData/Tracks/Campaigns/Nations/Black/E05-Endurance.Challenge.Gbx");
    if (!mesh) {
        printf("Failed to build global mesh\\n");
        return 1;
    }
    printf("Built global mesh with %zu vertices, %zu triangles\\n", mesh->m_vertices.size(), mesh->m_triangles.size());
"""

# I will use regex to find the mesh loading part and replace it.
content = re.sub(r'CPlugSurfaceGeom\* geom = CPlugSurfaceGeom::LoadFromGbx.*?GmSurfMesh\* mesh = geom->m_mesh;', main_loader, content, flags=re.DOTALL)

with open('main.cpp', 'w') as f:
    f.write(content)

