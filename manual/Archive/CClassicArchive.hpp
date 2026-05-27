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
class CClassicBufferMemory;

class CClassicBuffer {
public:
    uint32_t m_refCount; // field_0x4
    uint32_t m_flags;    // field_0x8

    CClassicBuffer();
    virtual ~CClassicBuffer();

    // Reconstructed virtual interface based on vftable offsets
    virtual int Read(void* dest, uint32_t size) { return 0; }           // Offset: 0x4
    virtual int Write(const void* src, uint32_t size) { return 0; }     // Offset: 0x8
    virtual void Unk_0x0C() {}                               // Offset: 0xC
    virtual void Unk_0x10() {}                               // Offset: 0x10
    virtual uint32_t GetCursor() { return 0; }                          // Offset: 0x14
    virtual uint32_t GetSize() { return 0; }                            // Offset: 0x18
    virtual bool CanSeek() { return false; }                                // Offset: 0x1C
    virtual void Seek(uint32_t pos) {}                       // Offset: 0x20

    CClassicBufferMemory* CreateUncompressedBlock();
    void AddCompressedBlock(CClassicBufferMemory* mem);
    
    bool IsEqualBuffer(CClassicBufferMemory* b1, CClassicBufferMemory* b2);
    bool ReadAll(void* dest, uint32_t size);
    bool WriteAll(const void* src, uint32_t size);
    uint32_t Skip(uint32_t size);
    void CopyFrom(SParam_Set* set, SParam* param);
};

// =================================================
// CClassicBufferMemory
// =================================================
class CClassicBufferMemory : public CClassicBuffer {
public:
    uint8_t* m_data;      // field_0xc
    uint32_t m_size;      // field_0x10
    uint32_t m_cursor;    // field_0x14
    uint32_t m_capacity;  // field_0x18
    uint32_t m_chunkSize; // field_0x1c

    CClassicBufferMemory();
    virtual ~CClassicBufferMemory();

    bool IsEqualBuffer(CClassicBufferMemory* other);
    void* WriteVoid(uint32_t size);
    void AdvanceOffset(uint32_t size);
    void Attach(uint8_t* buffer, uint32_t size);
    void Empty();
    void PreAlloc(uint32_t size);
    void Reset();
};

// =================================================
// CClassicBufferRef
// =================================================
struct CClassicBufferRef {
    CClassicBufferMemory* m_memory;

    CClassicBufferRef();
    ~CClassicBufferRef();
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

    CClassicBuffer* DetachBuffer();
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