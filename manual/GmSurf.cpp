#include "GmSurf.hpp"
#include "GmCollision.hpp"
#include <cmath>

// Collision Dispatch Matrix (9x9)
typedef int (*GmCollisionFunc)(LocatedGmSurf*, LocatedGmSurf*, CGmCollisionBuffer*);
GmCollisionFunc g_GmCollisionMatrix[9][9];

// Extracted Engine Constants
const float EPSILON_RAY = 1.0f; // _DAT_00b313b8
const float MAX_T = 1.0f;       // _DAT_00b313ac

// =================================================
// Base Class: GmSurf
// =================================================

GmSurf::GmSurf() {
    m_type = 0xFF;
    m_flags = 0;
}

// External collision function prototypes
extern int GmCollision_Sphere_Sphere(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Polygon(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Sphere_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Ellipsoid(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Polygon(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Ellipsoid_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Box_Box(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Box_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);
extern int GmCollision_Mesh_Mesh(LocatedGmSurf* a, LocatedGmSurf* b, CGmCollisionBuffer* buf);

void GmSurf::StaticInit() {
    // 1. Initialize entire matrix to a safe null/error handler
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            g_GmCollisionMatrix[i][j] = nullptr; // Or CSystemFile_testerror
        }
    }

    // 2. Populate the matrix (Symmetry: Matrix[i][j] = Matrix[j][i])
    // Index mapping: 0=Sphere, 1=Ellipsoid, 5=Polygon, 6=Box, 7=Mesh
    
    // Sphere pairs
    g_GmCollisionMatrix[0][0] = GmCollision_Sphere_Sphere;
    g_GmCollisionMatrix[0][1] = g_GmCollisionMatrix[1][0] = GmCollision_Sphere_Ellipsoid;
    g_GmCollisionMatrix[0][5] = g_GmCollisionMatrix[5][0] = GmCollision_Sphere_Polygon;
    g_GmCollisionMatrix[0][6] = g_GmCollisionMatrix[6][0] = GmCollision_Sphere_Box;
    g_GmCollisionMatrix[0][7] = g_GmCollisionMatrix[7][0] = GmCollision_Sphere_Mesh;

    // Ellipsoid pairs
    g_GmCollisionMatrix[1][1] = GmCollision_Ellipsoid_Ellipsoid;
    g_GmCollisionMatrix[1][5] = g_GmCollisionMatrix[5][1] = GmCollision_Ellipsoid_Polygon;
    g_GmCollisionMatrix[1][6] = g_GmCollisionMatrix[6][1] = GmCollision_Ellipsoid_Box;
    g_GmCollisionMatrix[1][7] = g_GmCollisionMatrix[7][1] = GmCollision_Ellipsoid_Mesh;

    // Box pairs
    g_GmCollisionMatrix[6][6] = GmCollision_Box_Box;
    g_GmCollisionMatrix[6][7] = g_GmCollisionMatrix[7][6] = GmCollision_Box_Mesh;

    // Mesh pairs
    g_GmCollisionMatrix[7][7] = GmCollision_Mesh_Mesh;
}

int GmSurf::ComputeCollision(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    // Ensure symmetric dispatch (Lowest ID first)
    if (locA->m_surf->m_type <= locB->m_surf->m_type) {
        return g_GmCollisionMatrix[locA->m_surf->m_type][locB->m_surf->m_type](locA, locB, buf);
    }
    
    // If swapped, calculate collision backwards...
    unsigned int initialCount = buf->GetCount();
    int result = g_GmCollisionMatrix[locB->m_surf->m_type][locA->m_surf->m_type](locB, locA, buf);
    
    if (result == 0) return 0;
    
    unsigned int finalCount = buf->GetCount();
    
    // ...and invert all generated contact normals and swap material IDs
    for (unsigned int i = initialCount; i < finalCount; ++i) {
        // Direct pointer math matching the assembly mapping to GmCollision layout
        float* colData = (float*)buf->GetCollision(i);
        
        // Invert Normals
        colData[3] = -colData[3];
        colData[4] = -colData[4];
        colData[5] = -colData[5];
        
        // Swap Material IDs (16-bit values at offset 0x24 and 0x26)
        uint16_t* matIds = (uint16_t*)((char*)colData + 0x24);
        uint16_t temp = matIds[0];
        matIds[0] = matIds[1];
        matIds[1] = temp;
        
        // Invert Contact Points
        colData[0] = -colData[0];
        colData[1] = -colData[1];
        colData[2] = -colData[2];
        
        // Invert secondary vectors
        colData[11] = -colData[11]; // 0x2C
        colData[12] = -colData[12]; // 0x30
        colData[13] = -colData[13]; // 0x34
    }
    return 1;
}

void GmSurf::GetBoundingBox(GmBoxAligned& outBox) const {
    switch(m_type) {
        case 0: ((GmSurfSphere*)this)->GetSphereBoundingBox(outBox); break;
        case 1: ((GmSurfEllipsoid*)this)->GetEllipsoidBoundingBox(outBox); break;
        case 6: 
            outBox.center = {0.0f, 0.0f, 0.0f};
            outBox.extents = ((GmSurfBox*)this)->m_extents;
            break;
        case 7: ((GmSurfMesh*)this)->GetMeshBoundingBox(outBox); break;
    }
}

int GmSurf::ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, GmVec3& outNormal) {
    if (m_type == 0) {
        // Pass the translation part of the matrix (tX, tY, tZ) as the sphere center
        return ((GmSurfSphere*)this)->ClipSegment(rayPos, rayDir, GmVec3{transform.tX, transform.tY, transform.tZ}, outT);
    }
    if (m_type == 7) {
        // Transform ray into local space for mesh traversal
        GmVec3 localPos = rayPos - GmVec3{transform.tX, transform.tY, transform.tZ};
        localPos.SetMultTranspose(localPos, transform.rot); 
        GmVec3 localDir = rayDir;
        localDir.SetMultTranspose(rayDir, transform.rot);
        
        return ((GmSurfMesh*)this)->ClipSegment(localPos, localDir, transform, outT);
    }
    return 0;
}

// =================================================
// GmSurfSphere (Type 0)
// =================================================

GmSurfSphere::GmSurfSphere() {
    m_type = 0;
}

void GmSurfSphere::GetSphereBoundingBox(GmBoxAligned& outBox) const {
    outBox.center = {0.0f, 0.0f, 0.0f};
    outBox.extents = {m_radius, m_radius, m_radius};
}

int GmSurfSphere::ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& center, float& outT) {
    // Standard Quadratic Ray-Sphere Intersection
    GmVec3 diff = rayPos - center;
    
    float b = diff.x * rayDir.x + diff.y * rayDir.y + diff.z * rayDir.z;
    float a = rayDir.x * rayDir.x + rayDir.y * rayDir.y + rayDir.z * rayDir.z;
    float c = (diff.x * diff.x + diff.y * diff.y + diff.z * diff.z) - (m_radius * m_radius);
    
    // Discriminant check
    float discriminant = b * b - c * a;
    if (discriminant >= 0.0f) {
        // func_0x009c1b40 is inverse square root
        float t = (-b - std::sqrt(discriminant)) / a;
        if (t >= 0.0f && t <= 1.0f) {
            outT = t;
            return 1;
        }
    }
    return 0;
}

// =================================================
// GmSurfEllipsoid (Type 1)
// =================================================

GmSurfEllipsoid::GmSurfEllipsoid() {
    m_type = 1;
}

void GmSurfEllipsoid::CreateEllipsoidDefaultData() {
    m_radii = {1.0f, 1.0f, 1.0f};
}

void GmSurfEllipsoid::GetEllipsoidBoundingBox(GmBoxAligned& outBox) const {
    outBox.center = {0.0f, 0.0f, 0.0f};
    outBox.extents = m_radii;
}

// =================================================
// GmSurfBox (Type 6)
// =================================================

GmSurfBox::GmSurfBox() {
    m_type = 6;
}

// =================================================
// GmSurfMesh (Type 7)
// =================================================

GmSurfMesh::GmSurfMesh() {
    m_type = 7;
}

void GmSurfMesh::GetMeshBoundingBox(GmBoxAligned& outBox) const {
    if (m_triangles.GetCount() != 0) {
        // Pull bounds from the root octree cell (offset 0x20)
        SMeshOctreeCell* rootCell = m_octree.m_data;
        outBox.center = rootCell->bounds.center;
        outBox.extents = rootCell->bounds.extents;
        return;
    }
    
    // Empty box (usually an extent of 0 or -1 based on constant)
    outBox.center = {0.0f, 0.0f, 0.0f};
    outBox.extents = {0.0f, 0.0f, 0.0f}; // _DAT_00b2c060 equivalent
}

void GmSurfMesh::TransformByNOMat(const GmIso4& transform) {
    // 1. Transform all vertices
    for (unsigned int i = 0; i < m_vertices.GetCount(); ++i) {
        m_vertices[i].Mult(transform);
    }
    
    // 2. If it's a full indirect transform (rotation), recalculate plane equations
    if (transform.rot.IsIndirect()) {
        for (unsigned int i = 0; i < m_triangles.GetCount(); ++i) {
            GmSurfTriangle& tri = m_triangles[i];
            
            // Get transformed vertices
            GmVec3 v0 = m_vertices[tri.indices[0]];
            GmVec3 v1 = m_vertices[tri.indices[1]];
            GmVec3 v2 = m_vertices[tri.indices[2]];
            
            // Calculate edge vectors
            GmVec3 edge1 = v1 - v0;
            GmVec3 edge2 = v2 - v0;
            
            // Cross product normal
            GmVec3 normal;
            normal.x = edge1.y * edge2.z - edge1.z * edge2.y;
            normal.y = edge1.z * edge2.x - edge1.x * edge2.z;
            normal.z = edge1.x * edge2.y - edge1.y * edge2.x;
            
            float sqrLen = normal.x * normal.x + normal.y * normal.y + normal.z * normal.z;
            
            // Normalize and compute plane distance (D)
            if (sqrLen > 0.000001f) {
                float invLen = 1.0f / std::sqrt(sqrLen);
                tri.planeNormal.x = normal.x * invLen;
                tri.planeNormal.y = normal.y * invLen;
                tri.planeNormal.z = normal.z * invLen;
            }
            
            tri.planeDist = -(tri.planeNormal.x * v0.x + tri.planeNormal.y * v0.y + tri.planeNormal.z * v0.z);
        }
    }
    
    // 3. Rebuild Spatial Partitioning Tree with new geometry
    if (m_octree.GetCount() != 0) {
        BuildOctree();
    }
}