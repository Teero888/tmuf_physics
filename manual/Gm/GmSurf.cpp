#include "GmSurf.hpp"
#include "GmCollision.hpp"
#include <cmath>

// Collision Dispatch Matrix (9x9)
typedef int (*GmCollisionFunc)(LocatedGmSurf*, LocatedGmSurf*, CGmCollisionBuffer*);
GmCollisionFunc g_GmCollisionMatrix[9][9];

// =================================================
// Base Class: GmSurf
// =================================================

GmSurf::GmSurf() {
    m_type = 0xFF;
    m_flags = 0;
}

GmSurf::~GmSurf() {}

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
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            g_GmCollisionMatrix[i][j] = nullptr; 
        }
    }

    g_GmCollisionMatrix[0][0] = GmCollision_Sphere_Sphere;
    g_GmCollisionMatrix[0][1] = g_GmCollisionMatrix[1][0] = GmCollision_Sphere_Ellipsoid;
    g_GmCollisionMatrix[0][5] = g_GmCollisionMatrix[5][0] = GmCollision_Sphere_Polygon;
    g_GmCollisionMatrix[0][6] = g_GmCollisionMatrix[6][0] = GmCollision_Sphere_Box;
    g_GmCollisionMatrix[0][7] = g_GmCollisionMatrix[7][0] = GmCollision_Sphere_Mesh;

    g_GmCollisionMatrix[1][1] = GmCollision_Ellipsoid_Ellipsoid;
    g_GmCollisionMatrix[1][5] = g_GmCollisionMatrix[5][1] = GmCollision_Ellipsoid_Polygon;
    g_GmCollisionMatrix[1][6] = g_GmCollisionMatrix[6][1] = GmCollision_Ellipsoid_Box;
    g_GmCollisionMatrix[1][7] = g_GmCollisionMatrix[7][1] = GmCollision_Ellipsoid_Mesh;

    g_GmCollisionMatrix[5][5] = nullptr; // Polygon-Polygon handled by higher level
    g_GmCollisionMatrix[5][6] = g_GmCollisionMatrix[6][5] = nullptr;
    g_GmCollisionMatrix[5][7] = g_GmCollisionMatrix[7][5] = nullptr;

    g_GmCollisionMatrix[6][6] = GmCollision_Box_Box;
    g_GmCollisionMatrix[6][7] = g_GmCollisionMatrix[7][6] = GmCollision_Box_Mesh;
    
    g_GmCollisionMatrix[7][7] = GmCollision_Mesh_Mesh;
}

int GmSurf::ComputeCollision(LocatedGmSurf* locA, LocatedGmSurf* locB, CGmCollisionBuffer* buf) {
    if (!locA || !locB || !locA->m_surf || !locB->m_surf) return 0;
    
    uint8_t typeA = locA->m_surf->m_type;
    uint8_t typeB = locB->m_surf->m_type;
    
    if (typeA >= 9 || typeB >= 9) return 0;
    
    GmCollisionFunc func = g_GmCollisionMatrix[typeA][typeB];
    if (func) {
        return func(locA, locB, buf);
    }
    
    return 0;
}

void GmSurf::GetBoundingBox(GmBoxAligned& outBox) const {
    outBox.InitEmpty();
}

// GmSurfBox (Type 6)
GmSurfBox::GmSurfBox() { m_type = 6; }
GmSurfBox::~GmSurfBox() {}

// GmSurfEllipsoid (Type 1)
GmSurfEllipsoid::GmSurfEllipsoid() { m_type = 1; }
GmSurfEllipsoid::~GmSurfEllipsoid() {}

// GmSurfSphere (Type 0)
GmSurfSphere::GmSurfSphere() { m_type = 0; }
GmSurfSphere::~GmSurfSphere() {}

// GmSurfPolygon (Type 5)
GmSurfPolygon::GmSurfPolygon(uint8_t param) { m_type = 5; }
GmSurfPolygon::~GmSurfPolygon() {}

// Stubs for functions not yet implemented
int GmCollision_Sphere_Sphere(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Ellipsoid(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Polygon(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Box(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Sphere_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Ellipsoid(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Polygon(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Box(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Ellipsoid_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Box_Box(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Box_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
int GmCollision_Mesh_Mesh(LocatedGmSurf* p1, LocatedGmSurf* p2, CGmCollisionBuffer* p3) { return 0; }
