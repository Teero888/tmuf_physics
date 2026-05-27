#include "GmIso3.hpp"

// =================================================
// Function: GmIso3::ArchiveGmIso3
// =================================================
void GmIso3::ArchiveGmIso3(CClassicArchive& archive) {
    // Serializes the 6 core floats. 
    // We pass '1' as the count parameter to match DoReal.
    archive.DoReal(&this->m00, 1);
    archive.DoReal(&this->m01, 1);
    archive.DoReal(&this->m10, 1);
    archive.DoReal(&this->m11, 1);
    archive.DoReal(&this->tX, 1);
    archive.DoReal(&this->tY, 1);
}

// =================================================
// Function: GmIso3::Set
// =================================================
void GmIso3::Set(const GmIso3& other) {
    this->m00 = other.m00;
    this->m01 = other.m01;
    this->m10 = other.m10;
    this->m11 = other.m11;
    this->tX  = other.tX;
    this->tY  = other.tY;
}

// =================================================
// Function: GmIso3::SetIdentity
// =================================================
void GmIso3::SetIdentity() {
    this->rot.SetIdentity();
    this->tX = 0.0f;
    this->tY = 0.0f;
}

// =================================================
// Function: GmIso3::SetInverse
// =================================================
void GmIso3::SetInverse(const GmIso3& other) {
    // For orthogonal transformation matrices (Isometries), Inverse == Transpose
    this->rot.SetTranspose(other.rot);
    
    // Invert the translation: T_inv = -T * M^T
    this->tX = -other.tX;
    this->tY = -other.tY;
    
    float oldTx = this->tX;
    this->tX = (oldTx * this->m00) + (this->tY * this->m01);
    this->tY = (oldTx * this->m10) + (this->tY * this->m11);
}

// =================================================
// Function: GmIso3::SetMult
// =================================================
void GmIso3::SetMult(const GmIso3& a, const GmIso3& b) {
    this->rot.SetMult(a.rot, b.rot);
    
    // Transform A's translation by B's rotation, then add B's translation
    this->tX = (a.tX * b.m00) + (a.tY * b.m01);
    this->tY = (a.tX * b.m10) + (a.tY * b.m11);
    
    this->tX += b.tX;
    this->tY += b.tY;
}

// =================================================
// Function: GmIso3::Mult
// =================================================
void GmIso3::Mult(const GmIso3& other) {
    this->rot.Mult(other.rot);
    
    // Apply other's transformation to current translation vector
    float oldTx = this->tX;
    this->tX = (oldTx * other.m00) + (this->tY * other.m01);
    this->tY = (oldTx * other.m10) + (this->tY * other.m11);
    
    this->tX += other.tX;
    this->tY += other.tY;
}

// =================================================
// Function: GmIso3::MultInverse
// =================================================
void GmIso3::MultInverse(const GmIso3& other) {
    GmIso3 tempInv;
    tempInv.SetInverse(other);
    this->Mult(tempInv);
}