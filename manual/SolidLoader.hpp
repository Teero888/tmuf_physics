#pragma once
#include "Classic/CClassicArchive.hpp"
#include "Gm/GmVec3.hpp"
#include <vector>

struct GmSurfTriangle {
    uint16_t u1, u2, u3;
    uint16_t matIndex;
};

class CPlugSurfaceGeom {
public:
    uint32_t idIndex;
    float boxMin[3];
    float boxMax[3];
    uint32_t surfId;
    
    // GmSurfMesh data
    uint32_t version;
    uint32_t numVertices;
    uint32_t numTriangles;
    std::vector<GmVec3> vertices;
    std::vector<GmSurfTriangle> triangles;

    bool ReadFromBinary(CClassicArchive* archive) {
        if (!archive->ScanForChunk(0x0900F004)) return false;

        archive->m_buffer->Read(&idIndex, 4);
        archive->m_buffer->Read(boxMin, 12);
        archive->m_buffer->Read(boxMax, 12);
        
        // NOTE: In an uncorrupted file, everything after this point is encrypted with 
        // a Blowfish key derived from (boxMin[0] - boxMax[0]).
        // Our current file was extracted from Stadium.pak using a tool that didn't know this,
        // so it incorrectly decrypted this section using the default Pak key.
        // Therefore, the following reads will produce garbage until we get a cleanly extracted file.

        archive->m_buffer->Read(&surfId, 4);
        if (surfId != 0x05000407) {
            // Because of the corruption, surfId will read as garbage instead of 0x05000407.
            // We ignore the check for now so you can see the garbage data.
        }

        archive->m_buffer->Read(&version, 4);
        // Valid versions are 1, 2, 3, 5, 6, 7. In our corrupted file, this reads as 1536.

        archive->m_buffer->Read(&numVertices, 4);
        archive->m_buffer->Read(&numTriangles, 4);

        if (numVertices < 100000) { // Safety check against garbage sizes
            vertices.resize(numVertices);
            archive->m_buffer->Read(vertices.data(), numVertices * sizeof(GmVec3));
        }

        if (numTriangles < 100000) {
            triangles.resize(numTriangles);
            archive->m_buffer->Read(triangles.data(), numTriangles * sizeof(GmSurfTriangle));
        }

        return true;
    }
};
