#ifndef CCLASSICBUFFERMEMORY_HPP
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
