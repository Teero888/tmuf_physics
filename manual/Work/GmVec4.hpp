#ifndef GMVEC4_HPP
#define GMVEC4_HPP

#include "typedefs.h"
#include "GmVec3.hpp"

class GmIso3;
class GmIso4;
class GmLine3;

class GmVec4 {
public:
    float x; // 0x0
    float y; // 0x4
    float z; // 0x8
    float w; // 0xC

    // Basic Operations
    void Add(const GmVec4& v);
    void Sub(const GmVec4& v);
    void Neg();
    void Set(const GmVec4& v);
    void SetSub(const GmVec4& a, const GmVec4& b);
    void SetBlend(const GmVec4& v1, const GmVec4& v2, float t);
    
    // Matrix Multiplication
    void Mult(const GmIso4& m); 
    void SetMult(const GmVec4& v, const GmIso4& m);
    void SetLeftMult(const GmVec4& v, const GmIso4& m);

    // Plane Equations (nx, ny, nz, d)
    bool PlaneEqInterLine(const GmVec3& lineOrigin, const GmVec3& lineDir, float& outT) const;
    bool PlaneEqInterPlane(const GmVec4& otherPlane, GmLine3& outLine) const;
    bool PlaneEqIsNearlyEqual(const GmVec4& other, float dotEpsilon, float distEpsilon) const;
    void PlaneEqMult(const GmIso4& m);
    void PlaneEqSetMult(const GmVec4& plane, const GmIso4& m);
    bool PlaneEqSetFrom3Pos(const GmVec3& p1, const GmVec3& p2, const GmVec3& p3);
    void PlaneEqSetNormPos(const GmVec3& normal, const GmVec3& pos);

    // Clipping (Frustum)
    void GetClipFlag(uint& outFlag) const;
    static void GetClipFlags(const GmVec4* vecs, uint* outFlags, ulong count);
    
    // Renderer Clipping (Highly context-dependent, likely belongs to a renderer class)
    static void PolygonClip(void* param_1, void* param_2); 
};

#endif // GMVEC4_HPP