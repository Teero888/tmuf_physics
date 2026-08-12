#include "CClassicArchive.hpp"

// Nadeo Engine global state mocks
static char g_TextLineBuffer[4096];
static uint32_t g_TextLineCursor = 0;

// External LZO decompression mocks assumed in engine. The length parameters
// must be size_t: minilzo's lzo_uint is defined to match size_t, and the
// callee writes the whole width back through dst_len. Declaring it as
// uint32_t* smashes four bytes of the caller's stack on LP64 targets.
extern "C" {
    void lzo1x_1_compress(const void* src, size_t src_len, void* dst, size_t* dst_len, void* wrkmem);
    int lzo1x_decompress_safe(const void* src, size_t src_len, void* dst, size_t* dst_len, void* wrkmem);
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

CClassicArchive* CClassicArchive::LoadFromGbx(const char* filepath) {
    FILE* fp = fopen(filepath, "rb");
    if (!fp) return nullptr;

    fseek(fp, 0, SEEK_END);
    uint32_t file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    uint8_t* file_buffer = new uint8_t[file_size];
    if (fread(file_buffer, 1, file_size, fp) != file_size) {
        delete[] file_buffer;
        fclose(fp);
        return nullptr;
    }
    fclose(fp);

    uint32_t cursor = 0;
    if (file_size < 3 || std::memcmp(file_buffer, "GBX", 3) != 0) {
        delete[] file_buffer;
        return nullptr;
    }
    cursor += 3;

    uint16_t version = *reinterpret_cast<uint16_t*>(file_buffer + cursor);
    cursor += 2;

    if (version < 3) {
        delete[] file_buffer;
        return nullptr;
    }

    uint8_t format = file_buffer[cursor++];
    uint8_t compression = file_buffer[cursor++];
    uint8_t body_compression = file_buffer[cursor++];

    if (version >= 4) cursor += 1;

    uint32_t class_id = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
    cursor += 4;

    if (version >= 6) {
        uint32_t user_data_size = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
        cursor += 4;
        cursor += user_data_size;
    }

    uint32_t num_nodes = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
    cursor += 4;

    uint32_t num_ext_nodes = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
    cursor += 4;

    uint32_t data_size = 0;
    uint8_t* decompressed_data = nullptr;

    if (body_compression == 'C') {
        data_size = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
        cursor += 4;
        uint32_t compressed_size = *reinterpret_cast<uint32_t*>(file_buffer + cursor);
        cursor += 4;

        decompressed_data = new uint8_t[data_size];
        size_t decompressed_len = data_size;
        int r = lzo1x_decompress_safe(file_buffer + cursor, compressed_size, decompressed_data, &decompressed_len, nullptr);

        if (r != 0 || decompressed_len != data_size) {
            delete[] decompressed_data;
            delete[] file_buffer;
            return nullptr;
        }
    } else {
        data_size = file_size - cursor;
        decompressed_data = new uint8_t[data_size];
        std::memcpy(decompressed_data, file_buffer + cursor, data_size);
    }

    delete[] file_buffer;

    CClassicBufferMemory* memBuf = new CClassicBufferMemory();
    memBuf->Attach(decompressed_data, data_size);
    memBuf->m_chunkSize = 0; // Means we take ownership and delete it later? wait, Attach sets chunkSize=0x20 + 0x0... so destructor will delete it

    CClassicBufferRef* bufRef = new CClassicBufferRef();
    delete bufRef->m_memory;
    bufRef->m_memory = memBuf;

    CClassicArchive* archive = new CClassicArchive();
    archive->m_buffer = bufRef;
    archive->m_isWriting = false;
    archive->m_isTextMode = (format == 'T');
    archive->m_ownsBuffer = true;

    return archive;
}

CClassicBuffer* CClassicArchive::DetachBuffer() {
    CClassicBuffer* buf = m_buffer;
    m_buffer = nullptr;
    return buf;
}

bool CClassicArchive::ScanForChunk(uint32_t chunkId) {
    if (!m_buffer) return false;
    CClassicBufferRef* ref = static_cast<CClassicBufferRef*>(m_buffer);
    if (!ref->m_memory) return false;
    
    uint8_t* data = ref->m_memory->m_data;
    uint32_t size = ref->m_memory->m_size;
    uint32_t pos = ref->m_memory->m_cursor;
    
    for (uint32_t i = pos; i <= size - 4; ++i) {
        uint32_t val;
        std::memcpy(&val, data + i, 4);
        if (val == chunkId) {
            ref->m_memory->m_cursor = i + 4; // Set cursor right after chunk ID
            return true;
        }
    }
    return false;
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
void CClassicArchive::DoBool(int* values, uint32_t count) {
    if (m_isWriting) WriteBool(values, count);
    else ReadBool(values, count);
}

void CClassicArchive::DoNat8(uint8_t* values, uint32_t count, bool asHex) {
    if (m_isWriting) WriteNat8(values, count, asHex);
    else ReadNat8(values, count, asHex);
}

void CClassicArchive::DoNat16(uint16_t* values, uint32_t count, bool asHex) {
    if (m_isWriting) WriteNat16(values, count, asHex);
    else ReadNat16(values, count, asHex);
}

void CClassicArchive::DoNatural(uint32_t* values, uint32_t count, bool asHex) {
    if (m_isWriting) WriteNatural(values, count, asHex);
    else ReadNatural(values, count, asHex);
}

void CClassicArchive::DoReal(float* values, uint32_t count) {
    if (m_isWriting) WriteReal(values, count);
    else ReadReal(values, count);
}

void CClassicArchive::ReadNat8(uint8_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->ReadAll(values, count); return; }
    for (uint32_t i = 0; i < count; ++i) { ReadLine(); sscanf(g_TextLineBuffer, asHex ? "%hhx" : "%hhu", &values[i]); }
}

void CClassicArchive::WriteNat8(const uint8_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->WriteAll(values, count); return; }
    for (uint32_t i = 0; i < count; ++i) { g_TextLineCursor = sprintf(g_TextLineBuffer, asHex ? "%x" : "%u", values[i]); WriteLine(); }
}

void CClassicArchive::ReadNat16(uint16_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->ReadAll(values, count * 2); return; }
    for (uint32_t i = 0; i < count; ++i) { ReadLine(); sscanf(g_TextLineBuffer, asHex ? "%hx" : "%hu", &values[i]); }
}

void CClassicArchive::WriteNat16(const uint16_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->WriteAll(values, count * 2); return; }
    for (uint32_t i = 0; i < count; ++i) { g_TextLineCursor = sprintf(g_TextLineBuffer, asHex ? "%x" : "%u", values[i]); WriteLine(); }
}

void CClassicArchive::ReadNatural(uint32_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->ReadAll(values, count * 4); return; }
    for (uint32_t i = 0; i < count; ++i) { ReadLine(); sscanf(g_TextLineBuffer, asHex ? "%x" : "%u", &values[i]); }
}

void CClassicArchive::WriteNatural(const uint32_t* values, uint32_t count, bool asHex) {
    if (!m_isTextMode) { m_buffer->WriteAll(values, count * 4); return; }
    for (uint32_t i = 0; i < count; ++i) { g_TextLineCursor = sprintf(g_TextLineBuffer, asHex ? "%x" : "%u", values[i]); WriteLine(); }
}

void CClassicArchive::ReadString(CFastStringInt* str) {}
void CClassicArchive::WriteString(CFastStringInt* str) {}
void CClassicArchive::ReadMask(uint32_t* mask) { ReadNatural(mask, 1); }
void CClassicArchive::WriteMask(const uint32_t* mask) { WriteNatural(mask, 1); }
