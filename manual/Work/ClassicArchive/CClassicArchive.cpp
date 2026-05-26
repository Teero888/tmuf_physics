#include "CClassicArchive.hpp"

// Nadeo Engine global state mocks
static char g_TextLineBuffer[4096];
static uint32_t g_TextLineCursor = 0;

// External LZO decompression mocks assumed in engine
extern "C" {
    void lzo1x_1_compress(const void* src, uint32_t src_len, void* dst, uint32_t* dst_len, void* wrkmem);
    int lzo1x_decompress_safe(const void* src, uint32_t src_len, void* dst, uint32_t* dst_len, void* wrkmem);
}

// =================================================
// CClassicBufferMemory & Ref
// =================================================
CClassicBufferRef::CClassicBufferRef() {
    m_memory = new CClassicBufferMemory();
}
CClassicBufferRef::~CClassicBufferRef() {
    if (m_memory) delete m_memory;
}

CClassicBufferMemory::CClassicBufferMemory() {
    m_refCount = 3;
    m_flags = 0;
    m_data = nullptr;
    m_cursor = 0;
    m_size = 0;
    m_capacity = 0;
    m_chunkSize = 0x20;
}

CClassicBufferMemory::~CClassicBufferMemory() {
    if (m_chunkSize != 0) { // Indicates buffer wasn't 'Attached' statically
        delete[] m_data;
    }
}

void CClassicBufferMemory::Attach(uint8_t* buffer, uint32_t size) {
    m_data = buffer;
    m_cursor = 0;
    m_capacity = size;
    m_size = size;
    m_chunkSize = (buffer != nullptr ? 0 : 0xFFFFFFE0) + 0x20;
}

void CClassicBufferMemory::PreAlloc(uint32_t size) {
    if (m_capacity < size) {
        uint8_t* newBuf = new uint8_t[size];
        if (m_data) {
            std::memcpy(newBuf, m_data, m_cursor);
            delete[] m_data;
        }
        m_data = newBuf;
        m_capacity = size;
    }
    m_chunkSize = (m_capacity < m_chunkSize) ? m_chunkSize : m_capacity;
}

bool CClassicBufferMemory::IsEqualBuffer(CClassicBufferMemory* other) {
    if (m_size != other->m_size) return false;
    return std::memcmp(m_data, other->m_data, m_size) == 0;
}

void* CClassicBufferMemory::WriteVoid(uint32_t size) {
    if (m_flags != 0) return (void*)size;

    if (m_capacity < m_cursor + size) {
        PreAlloc(((m_cursor + size) / m_chunkSize + 1) * m_chunkSize);
    }
    
    void* ptr = m_data + m_cursor;
    m_cursor += size;
    if (m_size < m_cursor) {
        m_size = m_cursor;
    }
    return ptr;
}

void CClassicBufferMemory::AdvanceOffset(uint32_t size) { m_cursor += size; }
void CClassicBufferMemory::Reset() { m_cursor = 0; }
void CClassicBufferMemory::Empty() {
    Reset();
    m_size = 0;
}

// =================================================
// CClassicBuffer 
// =================================================
CClassicBuffer::CClassicBuffer() : m_refCount(0), m_flags(0) {}
CClassicBuffer::~CClassicBuffer() {}

bool CClassicBuffer::ReadAll(void* dest, uint32_t size) {
    uint8_t* ptr = static_cast<uint8_t*>(dest);
    uint32_t remaining = size;
    while (remaining > 0) {
        int readBytes = Read(ptr, remaining);
        if (readBytes <= 0) return false;
        ptr += readBytes;
        remaining -= readBytes;
    }
    return true;
}

bool CClassicBuffer::WriteAll(const void* src, uint32_t size) {
    const uint8_t* ptr = static_cast<const uint8_t*>(src);
    uint32_t remaining = size;
    while (remaining > 0) {
        int written = Write(ptr, remaining);
        if (written <= 0) return false;
        ptr += written;
        remaining -= written;
    }
    return true;
}

uint32_t CClassicBuffer::Skip(uint32_t size) {
    if (!CanSeek()) {
        uint8_t dump[4096];
        uint32_t remaining = size;
        while (remaining > 0) {
            uint32_t toRead = (remaining > 4096) ? 4096 : remaining;
            int read = Read(dump, toRead);
            if (read <= 0) break;
            remaining -= read;
        }
        return size - remaining;
    } else {
        uint32_t oldPos = GetCursor();
        Seek(oldPos + size);
        return GetCursor() - oldPos;
    }
}

// =================================================
// CClassicArchive Serialization Operations
// =================================================
CClassicArchive::CClassicArchive() : m_buffer(nullptr), m_isWriting(false), m_isTextMode(false), m_ownsBuffer(false) {}
CClassicArchive::~CClassicArchive() {
    // Engine callback hook handling stripped for simplicity
}

CClassicBuffer* CClassicArchive::DetachBuffer() {
    CClassicBuffer* buf = m_buffer;
    m_buffer = nullptr;
    return buf;
}

bool CClassicArchive::ReadLine() {
    g_TextLineCursor = 0;
    while (true) {
        char c;
        if (!m_buffer->ReadAll(&c, 1)) return false;
        
        if (c == '|') {
            // Nadeo's multi-line text delimiter handling
            char nextC;
            if (!m_buffer->ReadAll(&nextC, 1)) return false;
            if (nextC == '\r') {
                if (!m_buffer->ReadAll(&nextC, 1)) return false;
                g_TextLineBuffer[g_TextLineCursor] = '\0';
                return true;
            }
        }
        if (c == '\n' && g_TextLineCursor > 0 && g_TextLineBuffer[g_TextLineCursor - 1] == '\r') {
            g_TextLineCursor--; // Strip \r
            break;
        }
        
        if (g_TextLineCursor < 4094) {
            g_TextLineBuffer[g_TextLineCursor++] = c;
        }
    }
    g_TextLineBuffer[g_TextLineCursor] = '\0';
    return true;
}

void CClassicArchive::WriteLine() {
    g_TextLineBuffer[g_TextLineCursor++] = '\r';
    g_TextLineBuffer[g_TextLineCursor++] = '\n';
    m_buffer->WriteAll(g_TextLineBuffer, g_TextLineCursor);
}

// --- Integrals ---
void CClassicArchive::DoInteger(int* values, uint32_t count, bool asHex) {
    if (m_isWriting) WriteInteger(values, count, asHex);
    else ReadInteger(values, count, asHex);
}

void CClassicArchive::ReadInteger(int* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) {
        m_buffer->ReadAll(values, count * sizeof(int));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        ReadLine();
        sscanf(g_TextLineBuffer, asHex ? "%x" : "%d", &values[i]);
    }
}

void CClassicArchive::WriteInteger(const int* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) {
        m_buffer->WriteAll(values, count * sizeof(int));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        g_TextLineCursor = sprintf(g_TextLineBuffer, asHex ? "%x" : "%d", values[i]);
        WriteLine();
    }
}

// --- Booleans ---
void CClassicArchive::ReadBool(int* values, uint32_t count) {
    if (!m_isTextMode) {
        m_buffer->ReadAll(values, count * sizeof(int));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        ReadLine();
        values[i] = (g_TextLineBuffer[0] == 'T') ? 1 : 0; // Looks for "True" vs "False"
    }
}

void CClassicArchive::WriteBool(const int* values, uint32_t count) {
    if (!m_isTextMode) {
        m_buffer->WriteAll(values, count * sizeof(int));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        g_TextLineCursor = sprintf(g_TextLineBuffer, values[i] ? "True" : "False");
        WriteLine();
    }
}

// --- Reals ---
void CClassicArchive::ReadReal(float* values, uint32_t count) {
    if (!m_isTextMode) {
        m_buffer->ReadAll(values, count * sizeof(float));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        ReadLine();
        values[i] = static_cast<float>(atof(g_TextLineBuffer));
    }
}

void CClassicArchive::WriteReal(const float* values, uint32_t count) {
    if (!m_isTextMode) {
        m_buffer->WriteAll(values, count * sizeof(float));
        return;
    }
    for (uint32_t i = 0; i < count; ++i) {
        g_TextLineCursor = sprintf(g_TextLineBuffer, "%f", values[i]);
        WriteLine();
    }
}

void CClassicArchive::DoData(void* data, uint32_t size) {
    if (m_isWriting) WriteData(data, size);
    else ReadData(data, size);
}

void CClassicArchive::ReadData(void* data, uint32_t size) {
    if (data) m_buffer->ReadAll(data, size);
}

void CClassicArchive::WriteData(const void* data, uint32_t size) {
    if (data) m_buffer->WriteAll(data, size);
}

void CClassicArchive::SkipData(uint32_t size) {
    if (!m_isWriting) {
        m_buffer->Skip(size);
    } else {
        // Skip while writing implies writing zeroes
        char zeroes[4096] = {0};
        uint32_t remaining = size;
        while (remaining > 0) {
            uint32_t chunk = (remaining > 4096) ? 4096 : remaining;
            WriteData(zeroes, chunk);
            remaining -= chunk;
        }
    }
}