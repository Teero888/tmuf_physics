#ifndef GMISO3_HPP
#define GMISO3_HPP

#include "CClassicArchive.hpp" // Assumed from previous steps
#include "GmMat2.hpp" // For the embedded rotation matrix
#include <cstdint>

// =================================================
// GmIso3 (2D Affine Transformation)
// =================================================
struct GmIso3 {
    union {
        GmMat2 rot; // 0x0 - 0xF
        struct {
            float m00; // field_0x0
            float m01; // field_0x4
            float m10; // field_0x8
            float m11; // field_0xc
        };
    };
    
    float tX; // field_0x10
    float tY; // field_0x14
    
    // Explicit padding to ensure sizeof(GmIso3) == 0x24 (36 bytes)
    float _final_padding[3]; 

    // Member Functions
    void ArchiveGmIso3(CClassicArchive& archive);
    
    void Set(const GmIso3& other);
    void SetIdentity();
    void SetInverse(const GmIso3& other);
    
    void Mult(const GmIso3& other);
    void SetMult(const GmIso3& a, const GmIso3& b);
    void MultInverse(const GmIso3& other);
};

#endif // GMISO3_HPP