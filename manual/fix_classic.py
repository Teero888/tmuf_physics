import os

with open("Classic/CClassicBuffer.hpp", "w") as f:
    f.write("""#ifndef CCLASSICBUFFER_HPP
#define CCLASSICBUFFER_HPP

#include <cstdint>

class CClassicBuffer {
public:
    int m_refCount;
    int m_flags;

    CClassicBuffer() : m_refCount(0), m_flags(0) {}
    virtual ~CClassicBuffer() {}

    virtual int Read(void* buf, uint32_t len) = 0;
    virtual int Write(const void* buf, uint32_t len) = 0;
    virtual bool CanSeek() const { return false; }
    virtual uint32_t GetCursor() const { return 0; }
    virtual void Seek(uint32_t pos) {}

    bool ReadAll(void* buf, uint32_t len);
    bool WriteAll(const void* buf, uint32_t len);
    uint32_t Skip(uint32_t size);
};

#endif // CCLASSICBUFFER_HPP
""")

with open("Classic/CClassicBufferMemory.hpp", "w") as f:
    f.write("""#ifndef CCLASSICBUFFERMEMORY_HPP
#define CCLASSICBUFFERMEMORY_HPP

#include "CClassicBuffer.hpp"
#include <cstdint>
#include <cstring>

class CClassicBufferMemory : public CClassicBuffer {
public:
    uint8_t* m_data;
    uint32_t m_size;
    uint32_t m_cursor;
    uint32_t m_capacity;
    uint32_t m_chunkSize;

    CClassicBufferMemory();
    CClassicBufferMemory(uint8_t* data, uint32_t size);
    virtual ~CClassicBufferMemory();

    void Attach(uint8_t* buffer, uint32_t size);
    void PreAlloc(uint32_t size);
    bool IsEqualBuffer(CClassicBufferMemory* other);
    void* WriteVoid(uint32_t size);
    void AdvanceOffset(uint32_t size);
    void Reset();
    void Empty();

    int Read(void* buf, uint32_t len) override;
    int Write(const void* buf, uint32_t len) override;
    bool CanSeek() const override { return true; }
    uint32_t GetCursor() const override { return m_cursor; }
    void Seek(uint32_t pos) override { m_cursor = pos; }
};

#endif // CCLASSICBUFFERMEMORY_HPP
""")

with open("Classic/CClassicArchive.hpp", "r") as f:
    content = f.read()
    content = content.replace("    CClassicBufferRef();\n    ~CClassicBufferRef();\n};", """class CClassicBufferRef : public CClassicBuffer {
public:
    class CClassicBufferMemory* m_memory;
    CClassicBufferRef();
    ~CClassicBufferRef();
    int Read(void* buf, uint32_t len) override;
    int Write(const void* buf, uint32_t len) override;
};""")
with open("Classic/CClassicArchive.hpp", "w") as f:
    f.write(content)

with open("Classic/CClassicArchive.cpp", "r") as f:
    content = f.read()
    content = content.replace("CClassicBufferMemory::~CClassicBufferMemory() {", """
int CClassicBufferRef::Read(void* buf, uint32_t len) { return m_memory ? m_memory->Read(buf, len) : 0; }
int CClassicBufferRef::Write(const void* buf, uint32_t len) { return m_memory ? m_memory->Write(buf, len) : 0; }

int CClassicBufferMemory::Read(void* buf, uint32_t len) {
    if (m_cursor + len > m_size) len = m_size - m_cursor;
    if (len > 0) {
        std::memcpy(buf, m_data + m_cursor, len);
        m_cursor += len;
    }
    return len;
}

int CClassicBufferMemory::Write(const void* buf, uint32_t len) {
    if (m_capacity < m_cursor + len) PreAlloc(m_cursor + len);
    if (m_capacity >= m_cursor + len) {
        std::memcpy(m_data + m_cursor, buf, len);
        m_cursor += len;
        if (m_size < m_cursor) m_size = m_cursor;
        return len;
    }
    return 0;
}

CClassicBufferMemory::~CClassicBufferMemory() {""")
with open("Classic/CClassicArchive.cpp", "w") as f:
    f.write(content)

with open("Gm/GmArchive.cpp", "r") as f:
    content = f.read()
    content = content.replace("buf->Read(", "buf->ReadAll(")
    content = content.replace("buf->Write(", "buf->WriteAll(")
with open("Gm/GmArchive.cpp", "w") as f:
    f.write(content)

with open("Hms/CHmsCorpusLight.hpp", "r") as f:
    content = f.read()
    content = content.replace("public CMwNod {", "public CMwNod {\npublic:\n    class CHmsZone* m_parentZone;")
with open("Hms/CHmsCorpusLight.hpp", "w") as f:
    f.write(content)
