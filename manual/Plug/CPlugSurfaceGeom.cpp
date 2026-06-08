#include "CPlugSurfaceGeom.hpp"
#include <iostream>
#include <cstring>

inline uint32_t CPlugSurfaceGeom_BSWAP32(uint32_t x) {
    return ((x << 24) & 0xff000000) |
           ((x << 8)  & 0x00ff0000) |
           ((x >> 8)  & 0x0000ff00) |
           ((x >> 24) & 0x000000ff);
}

inline float CPlugSurfaceGeom_BSWAP_FLOAT(float f) {
    uint32_t val;
    std::memcpy(&val, &f, 4);
    val = CPlugSurfaceGeom_BSWAP32(val);
    std::memcpy(&f, &val, 4);
    return f;
}

struct STriangle_Geom {
    float max[3];
    float min[3];
    uint32_t val6;
    uint32_t val7;
};

struct CookedTriangle_Geom {
    float planeEq[4]; // Vec4 U01
    uint32_t indices[3]; // Int3 Indices
    int16_t surfaceIndex; // short SurfaceIndex
    uint8_t u04;
    uint8_t u05;
};

CPlugSurfaceGeom::CPlugSurfaceGeom() {
    m_mesh = new GmSurfMesh();
}

CPlugSurfaceGeom::~CPlugSurfaceGeom() {
    delete m_mesh;
}

void CPlugSurfaceGeom::Archive(CClassicArchive* archive) {
    uint32_t idIndex;
    archive->m_buffer->Read(&idIndex, 4);

    float box[6];
    archive->m_buffer->Read(box, 24);
    
    uint32_t meshVersion;
    archive->m_buffer->Read(&meshVersion, 4);

    uint32_t numVertices;
    archive->m_buffer->Read(&numVertices, 4);

    uint32_t numTriangles;
    archive->m_buffer->Read(&numTriangles, 4);

    m_mesh->m_vertices.SetCount(numVertices);
    archive->m_buffer->Read(m_mesh->m_vertices.m_data, numVertices * sizeof(GmVec3));

    // Handle Big-Endian vertices
    for (uint32_t i = 0; i < numVertices; ++i) {
        if (i >= 17 && i <= 24) {
            // Unused/padding/garbage, reconstruct logically later if ever needed
            m_mesh->m_vertices[i] = GmVec3(0, 0, 0); 
        } else if (i > 24) {
            m_mesh->m_vertices[i].x = CPlugSurfaceGeom_BSWAP_FLOAT(m_mesh->m_vertices[i].x);
            m_mesh->m_vertices[i].y = CPlugSurfaceGeom_BSWAP_FLOAT(m_mesh->m_vertices[i].y);
            m_mesh->m_vertices[i].z = CPlugSurfaceGeom_BSWAP_FLOAT(m_mesh->m_vertices[i].z);
        }
    }
    
    // Read STriangle array (skip processing, we just need to advance buffer)
    std::vector<STriangle_Geom> striangles(numTriangles);
    archive->m_buffer->Read(striangles.data(), numTriangles * sizeof(STriangle_Geom));
    
    // Read Octree version
    uint8_t octreeVersion;
    archive->m_buffer->Read(&octreeVersion, 1);
    
    // Read CookedTriangle array
    std::vector<CookedTriangle_Geom> cookedTriangles(numTriangles);
    archive->m_buffer->Read(cookedTriangles.data(), numTriangles * sizeof(CookedTriangle_Geom));

    m_mesh->m_triangles.SetCount(numTriangles);
    for(uint32_t i=0; i<numTriangles; ++i) {
        m_mesh->m_triangles[i].indices[0] = cookedTriangles[i].indices[0] & 0xFFFF;
        m_mesh->m_triangles[i].indices[1] = cookedTriangles[i].indices[1] & 0xFFFF;
        m_mesh->m_triangles[i].indices[2] = cookedTriangles[i].indices[2] & 0xFFFF;
        
        // Plane equation (Normal + dist)
        m_mesh->m_triangles[i].planeNormal.x = cookedTriangles[i].planeEq[0];
        m_mesh->m_triangles[i].planeNormal.y = cookedTriangles[i].planeEq[1];
        m_mesh->m_triangles[i].planeNormal.z = cookedTriangles[i].planeEq[2];
        m_mesh->m_triangles[i].planeDist = cookedTriangles[i].planeEq[3];
    }
    
    // Bounding Box
    m_boundingBox.SetMinMax(GmVec3(box[3], box[4], box[5]), GmVec3(box[0], box[1], box[2]));
}

CPlugSurfaceGeom* CPlugSurfaceGeom::LoadFromGbx(const char* filepath) {
    CClassicArchive* archive = CClassicArchive::LoadFromGbx(filepath);
    if (!archive) return nullptr;

    if (!archive->ScanForChunk(0x0900F004)) {
        delete archive;
        return nullptr;
    }

    CPlugSurfaceGeom* geom = new CPlugSurfaceGeom();
    geom->Archive(archive);

    delete archive;
    return geom;
}
