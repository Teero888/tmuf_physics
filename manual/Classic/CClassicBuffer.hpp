#ifndef CCLASSICBUFFER_HPP
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
