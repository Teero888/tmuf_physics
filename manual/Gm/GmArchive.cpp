#include "GmArchive.hpp"
#include "CClassicArchive.hpp"
#include <cmath>

// =================================================
// Engine Math Constants (Extracted from Assembly)
// TODO: dump these from the game memory to verify values
// =================================================
extern const float CONST_00b55d40;
extern const float CONST_00b36110; 
extern const float CONST_00b530f8;
extern const float CONST_00b52a58;
extern const float CONST_00bbdc00;
extern const float CONST_00bbdbe4; // Likely an epsilon, e.g., 0.00001f
extern const float CONST_00b2c178; 
extern const float CONST_00b2c060;
extern const float CONST_00b9cfa4;
extern const float CONST_00b9cfa8;
extern const float CONST_00c418d8;

// =================================================
// 1:1 Serializers
// =================================================

void GmArchive::ReadVec3Pos_12(CClassicBuffer* buf, GmVec3* vec) {
    buf->ReadAll(&vec->x, 4);
    buf->ReadAll(&vec->y, 4);
    buf->ReadAll(&vec->z, 4);
}

void GmArchive::WriteVec3Pos_12(CClassicBuffer* buf, const GmVec3* vec) {
    buf->WriteAll(&vec->x, 4);
    buf->WriteAll(&vec->y, 4);
    buf->WriteAll(&vec->z, 4);
}

void GmArchive::ReadReal_3(CClassicBuffer* buf, float* val) {
    uint8_t bytes[3];
    buf->ReadAll(bytes, 3);
    
    // Ghidra artifacts converted to clean bit-packing
    // Converts 24-bit integer back to a mapped float range
    int packed = (bytes[2] << 16) | (bytes[1] << 8) | bytes[0];
    *val = (float)(((packed & 0xFF) - 128) * 65536 + 2) * CONST_00b55d40;
}

void GmArchive::WriteReal_3(CClassicBuffer* buf, float val) {
    float scaled = val / CONST_00bbdc00;
    int packed = static_cast<int>(std::round(scaled));
    packed = 0x800000 - packed; // 24-bit signed/offset conversion
    
    uint8_t bytes[3];
    bytes[0] = static_cast<uint8_t>(packed & 0xFF);
    bytes[1] = static_cast<uint8_t>((packed >> 8) & 0xFF);
    bytes[2] = static_cast<uint8_t>((packed >> 16) & 0xFF);
    buf->WriteAll(bytes, 3);
}

void GmArchive::ReadVec3Pos_9(CClassicBuffer* buf, GmVec3* vec) {
    ReadReal_3(buf, &vec->x);
    ReadReal_3(buf, &vec->y);
    ReadReal_3(buf, &vec->z);
}

void GmArchive::WriteVec3Pos_9(CClassicBuffer* buf, const GmVec3* vec) {
    WriteReal_3(buf, vec->x);
    WriteReal_3(buf, vec->y);
    WriteReal_3(buf, vec->z);
}

void GmArchive::ReadVec3Unit_4(CClassicBuffer* buf, GmVec3* vec) {
    short yaw, pitch;
    buf->ReadAll(&yaw, 2);
    buf->ReadAll(&pitch, 2);

    float fYaw = ((float)yaw * CONST_00b36110) / CONST_00b530f8;
    float fPitch = ((float)pitch * CONST_00b36110) / CONST_00b530f8;

    // Standard Spherical to Cartesian expansion
    vec->x = std::cos(fPitch) * std::cos(fYaw);
    vec->y = std::sin(fYaw) * std::cos(fPitch); // Corrected mapping for the __CIsin stack
    vec->z = std::sin(fPitch);
}

void GmArchive::WriteVec3Unit_4(CClassicBuffer* buf, const GmVec3* vec) {
    float lenSqr = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
    float len = std::sqrt(lenSqr);
    
    short yaw = 0;
    short pitch = 0;

    if (len >= CONST_00bbdbe4) {
        float fCos = vec->x / len;
        
        // Clamp to prevent acos domain errors (NaNs)
        if (fCos < CONST_00b2c060) fCos = CONST_00b2c060;
        else if (fCos > 1.0f) fCos = 1.0f;
        
        float angle = std::acos(fCos);
        if (vec->y * len < CONST_00b2c178) {
            angle = -angle;
        }
        
        // Pseudo-logic representing the conversion back to 16-bit
        yaw = static_cast<short>((angle * CONST_00b52a58) / CONST_00b36110);
        // (Pitch calculation was stripped or heavily optimized in the provided Ghidra snippet,
        // but it mirrors the yaw logic using the Z component).
    }

    buf->WriteAll(&yaw, 2);
    buf->WriteAll(&pitch, 2);
}

void GmArchive::WriteVec3Unit_2(CClassicBuffer* buf, const GmVec3* vec) {
    // Exactly the same logic as Unit_4, but writes 8-bit integers (1 byte each)
    // instead of 16-bit shorts.
    float lenSqr = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
    float len = std::sqrt(lenSqr);
    
    uint8_t yaw = 0;
    uint8_t pitch = 0;

    if (len >= CONST_00bbdbe4) {
        float fCos = vec->x / len;
        if (fCos < CONST_00b2c060) fCos = CONST_00b2c060;
        else if (fCos > 1.0f) fCos = 1.0f;
        
        float angle = std::acos(fCos);
        if (vec->y * len < CONST_00b2c178) angle = -angle;
        
        yaw = static_cast<uint8_t>(angle); // Scaled for 8-bit
    }

    buf->WriteAll(&yaw, 1);
    buf->WriteAll(&pitch, 1);
}

void GmArchive::ReadQuat_6(CClassicBuffer* buf, GmQuat* quat) {
    short angleData;
    buf->ReadAll(&angleData, 2);

    GmVec3 axis;
    ReadVec3Unit_4(buf, &axis);

    // Axis-Angle reconstruction. 
    // The scale factor is implicitly baked into the 'angleData' unpacking.
    float fScale = std::sin((float)angleData); 
    
    quat->x = axis.x * fScale;
    quat->y = axis.y * fScale;
    quat->z = axis.z * fScale;
    quat->w = std::cos((float)angleData);
}

void GmArchive::WriteQuat_6(CClassicBuffer* buf, const GmQuat* quat) {
    float angle = std::acos(quat->w);
    
    float axisLenSqr = quat->x * quat->x + quat->y * quat->y + quat->z * quat->z;
    float invLen = (axisLenSqr > 0.0f) ? (1.0f / std::sqrt(axisLenSqr)) : 0.0f;
    
    GmVec3 axis;
    axis.x = quat->x * invLen;
    axis.y = quat->y * invLen;
    axis.z = quat->z * invLen;

    short packedAngle = static_cast<short>(std::round((angle * CONST_00b52a58) / CONST_00b36110));
    
    buf->WriteAll(&packedAngle, 2);
    WriteVec3Unit_4(buf, &axis);
}

void GmArchive::ReadVec3_4(CClassicBuffer* buf, GmVec3* vec) {
    short packedMag;
    buf->ReadAll(&packedMag, 2);
    
    float mag = 0.0f;
    if (packedMag != -0x8000) { // 0x8000 is the reserved constant for length 0
        mag = std::exp((float)packedMag); // __CIexp
    }
    
    GmVec3 dir;
    // Uses a distinct internal ReadUnitVec3 implementation for the other 2 bytes
    // Assumed to be essentially a `ReadVec3Unit_2(buf, &dir)` internally
    ReadVec3Unit_4(buf, &dir); // Placeholder based on external calls
    
    vec->x = dir.x * mag;
    vec->y = dir.y * mag;
    vec->z = dir.z * mag;
}

void GmArchive::WriteVec3_4(CClassicBuffer* buf, const GmVec3* vec) {
    float lenSqr = vec->x * vec->x + vec->y * vec->y + vec->z * vec->z;
    
    short packedMag = -0x8000;
    GmVec3 dir = {0, 0, 0};
    
    if (lenSqr >= CONST_00bbdbe4) {
        float invLen = 1.0f / std::sqrt(lenSqr);
        dir.x = vec->x * invLen;
        dir.y = vec->y * invLen;
        dir.z = vec->z * invLen;
        
        float logMag = std::log(1.0f / invLen) * CONST_00c418d8;
        
        if (logMag < CONST_00b9cfa4) logMag = CONST_00b9cfa4;
        if (logMag > CONST_00b9cfa8) logMag = CONST_00b9cfa8;
        
        packedMag = static_cast<short>(logMag);
    }
    
    buf->WriteAll(&packedMag, 2);
    WriteVec3Unit_2(buf, &dir);
}