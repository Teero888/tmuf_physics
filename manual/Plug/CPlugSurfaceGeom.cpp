#include "CPlugSurfaceGeom.hpp"
#include <algorithm>
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

CPlugSurfaceGeom::CPlugSurfaceGeom()
    : m_gmSurf(nullptr), m_ownsGmSurf(false) {
    m_boundingBox.InitEmpty();
}

CPlugSurfaceGeom::~CPlugSurfaceGeom() {
    if (m_ownsGmSurf) delete m_gmSurf;
}

GmSurf* CPlugSurfaceGeom::GetGmSurf() const {
    return m_gmSurf;
}

GmSurfMesh* CPlugSurfaceGeom::GetMesh() const {
    return m_gmSurf != nullptr && m_gmSurf->m_type == 7u
        ? static_cast<GmSurfMesh*>(m_gmSurf)
        : nullptr;
}

void CPlugSurfaceGeom::SetGmSurf(GmSurf* surface, bool takeOwnership) {
    if (surface == m_gmSurf) {
        m_ownsGmSurf = takeOwnership;
        return;
    }
    if (m_ownsGmSurf) delete m_gmSurf;
    m_gmSurf = surface;
    m_ownsGmSurf = takeOwnership;
    m_boundingBox.InitEmpty();
    if (surface == nullptr) return;
    surface->GetBoundingBox(m_boundingBox);
    if (surface->m_type == 5u) {
        const GmSurfPolygon* polygon =
            static_cast<const GmSurfPolygon*>(surface);
        if (polygon->m_numVertices != 0u) {
            GmVec3 minimum = polygon->m_vertices[0];
            GmVec3 maximum = polygon->m_vertices[0];
            for (uint32_t index = 1u;
                 index < polygon->m_numVertices && index < 4u; ++index) {
                const GmVec3& vertex = polygon->m_vertices[index];
                minimum.x = std::min(minimum.x, vertex.x);
                minimum.y = std::min(minimum.y, vertex.y);
                minimum.z = std::min(minimum.z, vertex.z);
                maximum.x = std::max(maximum.x, vertex.x);
                maximum.y = std::max(maximum.y, vertex.y);
                maximum.z = std::max(maximum.z, vertex.z);
            }
            m_boundingBox.SetMinMax(minimum, maximum);
        }
    }
}

void CPlugSurfaceGeom::Archive(CClassicArchive* archive) {
    SetGmSurf(new GmSurfMesh(), true);
    GmSurfMesh* mesh = GetMesh();
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

    mesh->m_vertices.SetCount(numVertices);
    archive->m_buffer->Read(mesh->m_vertices.m_data, numVertices * sizeof(GmVec3));

    // Handle Big-Endian vertices
    for (uint32_t i = 0; i < numVertices; ++i) {
        if (i >= 17 && i <= 24) {
            // Unused/padding/garbage, reconstruct logically later if ever needed
            mesh->m_vertices[i] = GmVec3(0, 0, 0);
        } else if (i > 24) {
            mesh->m_vertices[i].x = CPlugSurfaceGeom_BSWAP_FLOAT(mesh->m_vertices[i].x);
            mesh->m_vertices[i].y = CPlugSurfaceGeom_BSWAP_FLOAT(mesh->m_vertices[i].y);
            mesh->m_vertices[i].z = CPlugSurfaceGeom_BSWAP_FLOAT(mesh->m_vertices[i].z);
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

    mesh->m_triangles.SetCount(numTriangles);
    for(uint32_t i=0; i<numTriangles; ++i) {
        mesh->m_triangles[i].indices[0] = cookedTriangles[i].indices[0] & 0xFFFF;
        mesh->m_triangles[i].indices[1] = cookedTriangles[i].indices[1] & 0xFFFF;
        mesh->m_triangles[i].indices[2] = cookedTriangles[i].indices[2] & 0xFFFF;
        
        // Plane equation (Normal + dist)
        mesh->m_triangles[i].planeNormal.x = cookedTriangles[i].planeEq[0];
        mesh->m_triangles[i].planeNormal.y = cookedTriangles[i].planeEq[1];
        mesh->m_triangles[i].planeNormal.z = cookedTriangles[i].planeEq[2];
        mesh->m_triangles[i].planeDist = cookedTriangles[i].planeEq[3];
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
