#include "GmSurf.hpp"
#include "GmFunc.hpp"
#include <cmath>
#include <algorithm>

GmSurfMesh::GmSurfMesh() {
    m_type = 7;
}

GmSurfMesh::~GmSurfMesh() {}

int GmSurfMesh::TriangleClipSegmentNearerThanT(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& triNormal, float& outT, SPointInTri& outPoint) {
    // 1. Plane Intersection
    // triNormal is normalized. planeDist is -Dot(triNormal, v0)
    // We need the triangle to have the plane equation stored or passed.
    // In our manual GmSurfTriangle, we have planeNormal and planeDist.
    
    float distOrigin = GmVec3::Dot(triNormal, rayPos);
    float dotDir = GmVec3::Dot(triNormal, rayDir);
    
    if (std::abs(dotDir) < 1e-6f) return 0; // Parallel
    
    // We assume the triangle is in the mesh local space.
    // In our simplified test, we'll find the planeDist here if not set.
    // For now, assume tri.planeDist is correct.
    
    // Find t where (rayPos + t*rayDir) is on plane
    // dot(triNormal, rayPos + t*rayDir) + planeDist = 0
    // t = -(dot(triNormal, rayPos) + planeDist) / dot(triNormal, rayDir)
    
    return 0; // The actual unrolled math from dump is below
}

// Re-translating the exact unrolled math for TriangleClipSegmentNearerThanT
// from tmnf_dump/src/GmSurfMesh.cpp:627
int GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
    const GmVec3& normal, float planeDist, 
    const GmVec3& v0, const GmVec3& v1, const GmVec3& v2,
    const GmVec3& rayPos, const GmVec3& rayDir, float& outT) 
{
    float fVar2 = normal.z * rayPos.z + normal.x * rayPos.x + normal.y * rayPos.y + planeDist;
    if (fVar2 < 0.0f) return 0; // Ray origin is behind plane

    float fVar3 = -(normal.z * (rayPos.z + rayDir.z) + normal.x * (rayPos.x + rayDir.x) + normal.y * (rayPos.y + rayDir.y) + planeDist);
    
    float hitT;
    // GmFunc::Div equivalent
    if (std::abs(fVar2) * 1e-9f < std::abs(fVar3 + fVar2)) {
        hitT = fVar2 / (fVar2 + fVar3);
        if (hitT >= 0.0f && hitT <= outT) {
            // Barycentric check (inside triangle)
            GmVec3 hitPoint = rayPos + rayDir * hitT;
            
            // Project to 2D by dropping most significant axis of normal
            int axis = 0;
            float nx = std::abs(normal.x);
            float ny = std::abs(normal.y);
            float nz = std::abs(normal.z);
            if (ny > nx) { nx = ny; axis = 1; }
            if (nz > nx) axis = 2;
            
            int u = (axis + 1) % 3;
            int v = (axis + 2) % 3;
            
            float hitU = (&hitPoint.x)[u], hitV = (&hitPoint.x)[v];
            float aU = (&v0.x)[u], aV = (&v0.x)[v];
            float bU = (&v1.x)[u], bV = (&v1.x)[v];
            float cU = (&v2.x)[u], cV = (&v2.x)[v];
            
            // Area-based barycentric coords
            float det = (bV - cV)*(aU - cU) + (cU - bU)*(aV - cV);
            if (std::abs(det) < 1e-9f) return 0;
            
            float alpha = ((bV - cV)*(hitU - cU) + (cU - bU)*(hitV - cV)) / det;
            float beta = ((cV - aV)*(hitU - cU) + (aU - cU)*(hitV - cV)) / det;
            float gamma = 1.0f - alpha - beta;
            
            if (alpha >= 0.0f && beta >= 0.0f && gamma >= 0.0f) {
                outT = hitT;
                return 1;
            }
        }
    }
    return 0;
}

int GmSurfMesh::ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT) {
    GmVec3 localPos = transform.UnTransform(rayPos);
    GmVec3 localDir = transform.UnTransformVector(rayDir);
    
    bool hit = false;
    float currentT = outT;
    
    // In our full reconstruction, we use m_octree. 
    // Here we iterate all triangles for the test harness.
    for (uint32_t i = 0; i < m_triangles.m_count; ++i) {
        GmSurfTriangle& tri = m_triangles[i];
        if (GmSurfMesh_TriangleClipSegmentNearerThanT_Real(
            tri.planeNormal, tri.planeDist,
            m_vertices[tri.indices[0]], m_vertices[tri.indices[1]], m_vertices[tri.indices[2]],
            localPos, localDir, currentT)) 
        {
            hit = true;
        }
    }
    
    if (hit) outT = currentT;
    return hit;
}

void GmSurfMesh::GetMeshBoundingBox(GmBoxAligned& outBox) const {
    outBox.InitEmpty();
    for (uint32_t i = 0; i < m_vertices.m_count; ++i) {
        outBox.Union(m_vertices[i]);
    }
}

void GmSurfMesh::BuildOctree() {}
void GmSurfMesh::TransformByNOMat(const GmIso4& transform) {}

#include <fstream>
#include <sstream>

bool GmSurfMesh::LoadFromObj(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;
    
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string type;
        iss >> type;
        
        if (type == "v") {
            float x, y, z;
            iss >> x >> y >> z;
            m_vertices.Add(GmVec3(x, y, z));
        } else if (type == "f") {
            GmSurfTriangle tri;
            for (int i = 0; i < 3; ++i) {
                std::string vertStr;
                iss >> vertStr;
                size_t slashPos = vertStr.find('/');
                if (slashPos != std::string::npos) {
                    vertStr = vertStr.substr(0, slashPos);
                }
                uint32_t idx = std::stoi(vertStr) - 1;
                if (idx >= m_vertices.m_count) idx = m_vertices.m_count - 1;
                tri.indices[i] = idx;
            }
            
            // Compute plane normal
            GmVec3 v0 = m_vertices[tri.indices[0]];
            GmVec3 v1 = m_vertices[tri.indices[1]];
            GmVec3 v2 = m_vertices[tri.indices[2]];
            
            GmVec3 edge1 = v1 - v0;
            GmVec3 edge2 = v2 - v0;
            tri.planeNormal = GmVec3::Cross(edge1, edge2);
            tri.planeNormal.Normalize();
            tri.planeDist = -GmVec3::Dot(tri.planeNormal, v0);
            
            m_triangles.Add(tri);
        }
    }
    
    return true;
}

