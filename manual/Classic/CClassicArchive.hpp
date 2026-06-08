#include "CClassicBuffer.hpp"
#include "CClassicBufferMemory.hpp"
#ifndef CCLASSICARCHIVE_HPP
#define CCLASSICARCHIVE_HPP

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cstdlib>

// Forward Declarations for Nadeo-specific types
class CFastString;
class CFastStringInt;
struct SStringParam;
struct SParam_Set;
struct SParam;

// =================================================
// CClassicBuffer (Virtual Base)
// =================================================
class CClassicBufferRef : public CClassicBuffer {
public:
    class CClassicBufferMemory* m_memory;
    CClassicBufferRef();
    ~CClassicBufferRef();
    int Read(void* buf, uint32_t len) override;
    int Write(const void* buf, uint32_t len) override;
};

// =================================================
// CClassicArchive
// =================================================
class CClassicArchive {
public:
    CClassicBuffer* m_buffer; // field_0x4
    bool m_isWriting;         // field_0x8
    bool m_isTextMode;        // field_0xc
    bool m_ownsBuffer;        // field_0x14

    CClassicArchive();
    virtual ~CClassicArchive();

    static CClassicArchive* LoadFromGbx(const char* filepath);

    CClassicBuffer* DetachBuffer();
    bool ScanForChunk(uint32_t chunkId);

    void DoData(void* data, uint32_t size);
    bool ReadLine();
    void WriteLine();

    // Type serializers
    void DoBool(int* values, uint32_t count);
    void DoNat8(uint8_t* values, uint32_t count, bool asHex = false);
    void DoNat16(uint16_t* values, uint32_t count, bool asHex = false);
    void DoInteger(int* values, uint32_t count, bool asHex = false);
    void DoNatural(uint32_t* values, uint32_t count, bool asHex = false);
    void DoReal(float* values, uint32_t count);
    void DoString(CFastStringInt* str);

    // Explicit Readers
    void ReadBool(int* values, uint32_t count);
    void ReadData(void* data, uint32_t size);
    void ReadNat8(uint8_t* values, uint32_t count, bool asHex = false);
    void ReadNat16(uint16_t* values, uint32_t count, bool asHex = false);
    void ReadInteger(int* values, uint32_t count, bool asHex = false);
    void ReadNatural(uint32_t* values, uint32_t count, bool asHex = false);
    void ReadReal(float* values, uint32_t count);
    void ReadString(CFastStringInt* str);
    void ReadMask(uint32_t* mask);

    // Explicit Writers
    void WriteBool(const int* values, uint32_t count);
    void WriteData(const void* data, uint32_t size);
    void WriteNat8(const uint8_t* values, uint32_t count, bool asHex = false);
    void WriteNat16(const uint16_t* values, uint32_t count, bool asHex = false);
    void WriteInteger(const int* values, uint32_t count, bool asHex = false);
    void WriteNatural(const uint32_t* values, uint32_t count, bool asHex = false);
    void WriteReal(const float* values, uint32_t count);
    void WriteString(CFastStringInt* str);
    void WriteMask(const uint32_t* mask);
    
    void SkipData(uint32_t size);
};

#endif // CCLASSICARCHIVE_HPP