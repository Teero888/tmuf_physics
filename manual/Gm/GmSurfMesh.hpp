#ifndef GMSURFMESH_HPP
#define GMSURFMESH_HPP

#include "GmSurf.hpp"
#include "GmBoxAligned.hpp"
#include "../Fast/CFastArray.hpp"
#include <string>

struct GmSurfTriangle {
    uint32_t indices[3];
    GmVec3 planeNormal;
    float planeDist;
};

class GmSurfMesh : public GmSurf {
public:
    CFastArray<GmVec3> m_vertices;
    CFastArray<GmSurfTriangle> m_triangles;
    GmBoxAligned m_boundingBox;

    GmSurfMesh();
    virtual ~GmSurfMesh();

    bool LoadFromObj(const std::string& filename);
    bool ClipSegment(const GmVec3& start, const GmVec3& dir, const GmIso4& transform, float& outHitT);
    void BuildOctree(); // Stub for spatial partition
};

#endif
