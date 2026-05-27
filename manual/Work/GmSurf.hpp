#ifndef GMSURF_HPP
#define GMSURF_HPP

#include "typedefs.h"
#include "GmVec3.hpp"
#include "GmIso4.hpp"
#include "GmBoxAligned.hpp"
#include "GmOctree.hpp" // Contains SMeshOctreeCell

class CCrystal;
class CGmCollisionBuffer;
struct SPointInTri;

// Forward declarations for derived types
class GmSurfSphere;
class GmSurfEllipsoid;
class GmSurfPolygon;
class GmSurfBox;
class GmSurfMesh;

// Wrapper used in the collision dispatch matrix
struct LocatedGmSurf {
    class GmSurf* m_surf; // 0x00
    GmIso4 m_location;    // 0x04
};

// =================================================
// Base Class: GmSurf
// =================================================
class GmSurf {
public:
    virtual ~GmSurf();              // 0x00 - VTable

    unsigned short m_flags;         // 0x04
    unsigned char m_type;           // 0x06 - 0=Sphere, 1=Ellipsoid, 5=Polygon, 6=Box, 7=Mesh
    unsigned char m_pad;            // 0x07

    GmSurf();
    void CreateDefaultData(CCrystal* crystal);
    void GetBoundingBox(GmBoxAligned& outBox) const;

    // Core Raycast Dispatchers
    int ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, GmVec3& outNormal);
    int ClipSegment2(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, GmVec3& outNormal);
    int ClipSegment3(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, unsigned short& outId);

    static int ComputeCollision(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf);
    static void StaticInit();
};

// =================================================
// GmSurfSphere (Type 0)
// =================================================
class GmSurfSphere : public GmSurf {
public:
    float m_radius; // 0x08

    GmSurfSphere();
    int ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& center, float& outT);
    void GetSphereBoundingBox(GmBoxAligned& outBox) const;
};

// =================================================
// GmSurfEllipsoid (Type 1)
// =================================================
class GmSurfEllipsoid : public GmSurf {
public:
    GmVec3 m_radii; // 0x08, 0x0C, 0x10

    GmSurfEllipsoid();
    void CreateEllipsoidDefaultData();
    void GetEllipsoidBoundingBox(GmBoxAligned& outBox) const;
};

// =================================================
// GmSurfPolygon (Type 5)
// =================================================
class GmSurfPolygon : public GmSurf {
public:
    GmVec3 m_vertices[4]; // 0x08 - 0x37
    unsigned char m_numVertices; // 0x38
    unsigned char _pad[3];       // 0x39 - 0x3B
    GmVec3 m_planeNormal;        // 0x3C - 0x47
    int m_unknown_0x48;          // 0x48

    GmSurfPolygon(unsigned char param);
};

// =================================================
// GmSurfBox (Type 6)
// =================================================
class GmSurfBox : public GmSurf {
public:
    GmVec3 m_center;  // 0x08, 0x0C, 0x10
    GmVec3 m_extents; // 0x14, 0x18, 0x1C

    GmSurfBox();
};

// =================================================
// GmSurfMesh (Type 7)
// =================================================
struct GmSurfTriangle {
    // Deduced from TransformByNOMat plane equation cross-products
    GmVec3 planeNormal; 
    float planeDist;
    unsigned short indices[3]; 
    unsigned short materialId;
};

class GmSurfMesh : public GmSurf {
public:
    CFastArray<GmVec3> m_vertices;             // 0x08
    CFastArray<GmSurfTriangle> m_triangles;    // 0x10
    CFastArray<GmVec3> m_normals;              // 0x18
    GmOctree<SMeshOctreeCell> m_octree;        // 0x20

    GmSurfMesh();
    
    int ClipSegment(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT);
    int ClipSegment2(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, GmVec3& outNormal);
    int ClipSegment3(const GmVec3& rayPos, const GmVec3& rayDir, const GmIso4& transform, float& outT, unsigned short& outId);
    
    int TriangleClipSegmentNearerThanT(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& triNormal, float& outT, SPointInTri& outPoint);
    int TriangleClipSegment2NearerThanT(const GmVec3& rayPos, const GmVec3& rayDir, const GmVec3& triNormal, int param, float& outT, GmVec3& outNormal);
    
    void Archive(CFastCrypt<unsigned_long>* crypt, CClassicArchive* archive);
    void BuildOctree();
    void GetMeshBoundingBox(GmBoxAligned& outBox) const;
    void TransformByNOMat(const GmIso4& transform);
};

#endif // GMSURF_HPP