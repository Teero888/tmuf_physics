#include "GmMat2.hpp"

// =================================================
// Function: GmMat2::Mult
// =================================================
void GmMat2::Mult(const GmMat2& other) {
    // We create a temporary copy of this matrix to pass to SetMult, 
    // exactly as the original code pushed `this` to the stack (`stack0xfffffff0`).
    GmMat2 temp = *this;
    this->SetMult(temp, other);
}

// =================================================
// Function: GmMat2::Rotate
// =================================================
void GmMat2::Rotate(float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);
    
    // Apply rotation to the first column
    float old_m00 = this->m00;
    this->m00 = (c * old_m00) - (s * this->m10);
    this->m10 = (c * this->m10) + (s * old_m00);
    
    // Apply rotation to the second column
    float old_m01 = this->m01;
    this->m01 = (old_m01 * c) - (this->m11 * s);
    this->m11 = (old_m01 * s) + (this->m11 * c);
}

// =================================================
// Function: GmMat2::SetIdentity
// =================================================
void GmMat2::SetIdentity() {
    this->m00 = 1.0f; // 0x3f800000
    this->m01 = 0.0f; // 0x00000000
    this->m10 = 0.0f; // 0x00000000
    this->m11 = 1.0f; // 0x3f800000
}

// =================================================
// Function: GmMat2::SetMult
// =================================================
void GmMat2::SetMult(const GmMat2& a, const GmMat2& b) {
    // The original compiled code transposed 'a' into a local stack buffer 
    // to do contiguous memory accesses. Standard C++ matrix multiplication 
    // produces the exact same semantic result and assembly under optimization.
    
    this->m00 = (a.m00 * b.m00) + (a.m01 * b.m10);
    this->m01 = (a.m00 * b.m01) + (a.m01 * b.m11);
    this->m10 = (a.m10 * b.m00) + (a.m11 * b.m10);
    this->m11 = (a.m10 * b.m01) + (a.m11 * b.m11);
}

// =================================================
// Function: GmMat2::SetRotation
// =================================================
void GmMat2::SetRotation(float angle) {
    float s = std::sin(angle);
    float c = std::cos(angle);
    
    this->m00 = c;
    this->m10 = -s;
    this->m01 = s;
    this->m11 = c;
}

// =================================================
// Function: GmMat2::SetTranspose
// =================================================
void GmMat2::SetTranspose(const GmMat2& other) {
    // Ghidra attempted to map this to an inlined GmVec2[] array access,
    // but the underlying memory assignment is a standard transpose.
    
    this->m00 = other.m00;
    this->m01 = other.m10;
    this->m10 = other.m01;
    this->m11 = other.m11;
}