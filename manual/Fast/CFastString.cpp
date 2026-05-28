#include "CFastString.hpp"
#include <string>

// Engine-level empty string static singletons
static char g_EmptyCharStr[4] = {0};
static wchar_t g_EmptyWCharStr[4] = {0};

// =================================================
// CFastStringBase
// =================================================

template <typename T>
CFastStringBase<T>::CFastStringBase() : m_length(0), m_data(nullptr) {
    if constexpr (sizeof(T) == 1) m_data = (T*)g_EmptyCharStr;
    else m_data = (T*)g_EmptyWCharStr;
}

template <typename T>
CFastStringBase<T>::~CFastStringBase() {
    FreeChars(m_data);
}

// Nadeo's Custom In-Place Allocator logic
template <typename T>
T* CFastStringBase<T>::HeapAllocGetChars(uint32_t size) {
    uint32_t byteSize = size * sizeof(T);
    if (byteSize < 0x80) {
        uint8_t* ptr = new uint8_t[byteSize + 2];
        ptr[0] = static_cast<uint8_t>(byteSize) & 0x7F;
        return reinterpret_cast<T*>(ptr + 1);
    } else {
        uint8_t* ptr = new uint8_t[byteSize + 5];
        *reinterpret_cast<uint32_t*>(ptr) = byteSize | 0x80000000;
        return reinterpret_cast<T*>(ptr + 4); // Data starts right after the 4-byte header
    }
}

template <typename T>
void CFastStringBase<T>::FreeChars(T* chars) {
    if (!chars || (void*)chars == g_EmptyCharStr || (void*)chars == g_EmptyWCharStr) return;
    uint8_t* ptr = reinterpret_cast<uint8_t*>(chars) - 1;
    if ((*ptr) & 0x80) {
        ptr -= 3; // Shift back 3 more bytes to get to the start of the 32-bit integer block
    }
    delete[] ptr;
}

template <typename T>
void CFastStringBase<T>::AllocAtLeast(uint32_t reqLength, int keepOldData, void* param_4) {
    if (m_length >= reqLength && m_data != (T*)g_EmptyCharStr && m_data != (T*)g_EmptyWCharStr) return;

    T* newBuf = HeapAllocGetChars(reqLength);
    if (keepOldData && m_length > 0 && m_data) {
        std::memcpy(newBuf, m_data, m_length * sizeof(T));
    }
    
    FreeChars(m_data);
    m_data = newBuf;
}

template <typename T>
void CFastStringBase<T>::Clear(TiXmlNode* node) {
    if (m_length != 0) {
        m_length = 0;
        if (m_data) m_data[0] = 0;
    }
}

template <typename T>
void CFastStringBase<T>::CopyAndClear(CFastStringBase<T>* other) {
    FreeChars(m_data);
    m_length = other->m_length;
    m_data = other->m_data;
    other->m_length = 0;
    other->m_data = (sizeof(T) == 1) ? (T*)g_EmptyCharStr : (T*)g_EmptyWCharStr;
}

template <typename T>
void CFastStringBase<T>::PreAlloc(CClassicBufferMemory* mem, uint32_t size) {
    AllocAtLeast(size, 1);
    if (m_data) m_data[m_length] = 0;
}

template class CFastStringBase<char>;
template class CFastStringBase<wchar_t>;

// =================================================
// CFastString
// =================================================

CFastString::CFastString() : CFastStringBase<char>() {}

CFastString::CFastString(CFastString* other, const char* str) : CFastStringBase<char>() {
    uint32_t len1 = other ? other->m_length : 0;
    uint32_t len2 = str ? std::strlen(str) : 0;
    
    AllocAtLeast(len1 + len2, 0);
    if (len1) std::memcpy(m_data, other->m_data, len1);
    if (len2) std::memcpy(m_data + len1, str, len2);
    m_length = len1 + len2;
    m_data[m_length] = '\0';
}

// this makes no sense lol. fuck ghidra
void CFastString::Compare(SParam_Fids* fids, SParam* param, int* out1, int* out2) {
    const char* str1 = m_data;
    const char* str2 = reinterpret_cast<const char*>(fids);
    if (param != nullptr) {
        std::strncmp(str1, str2, reinterpret_cast<size_t>(param));
    } else {
        std::strcmp(str1, str2);
    }
}

int CFastString::Compare(const char* other) const
{
    return std::strcmp(m_data, other);
}

int CFastString::CompareNoCase(CFastStringInt* other, SStringParam* param, uint32_t length) {
    const char* otherStr = reinterpret_cast<const char*>(other);
    if (!param) return _stricmp(m_data, otherStr);
    return _strnicmp(m_data, otherStr, length);
}

int CFastString::CompareNoCase(const char* other) const
{
    return _stricmp(m_data, other);
}

void CFastString::Concat(CFastStringInt* other, SStringParam* param) {
    uint32_t otherLen = *reinterpret_cast<uint32_t*>(other);
    const char* otherData = reinterpret_cast<const char*>(other) + 4;
    
    AllocAtLeast(m_length + otherLen, 1);
    std::memcpy(m_data + m_length, otherData, otherLen);
    m_length += otherLen;
    m_data[m_length] = '\0';
}

void CFastString::ConcatAndNewLine(CFastString* other, const char* param2, const char* suffix) {
    uint32_t len1 = other->m_length;
    uint32_t len2 = std::strlen(param2);
    uint32_t sufLen = std::strlen(suffix);
    
    AllocAtLeast(m_length + len1 + len2 + sufLen, 1);
    std::memcpy(m_data + m_length, other->m_data, len1);
    std::memcpy(m_data + m_length + len1, param2, len2);
    std::memcpy(m_data + m_length + len1 + len2, suffix, sufLen);
    
    m_length += len1 + len2 + sufLen;
    m_data[m_length] = '\0';
}

void CFastString::ConcatBefore(CFastStringInt* other, SStringParamInt* param) {
    uint32_t otherLen = *reinterpret_cast<uint32_t*>(other);
    const char* otherData = reinterpret_cast<const char*>(other) + 4;
    
    if (otherLen > 0) {
        AllocAtLeast(m_length + otherLen, 1);
        if (m_length > 0) {
            std::memmove(m_data + otherLen, m_data, m_length);
        }
        std::memcpy(m_data, otherData, otherLen);
        m_length += otherLen;
        m_data[m_length] = '\0';
    }
}

void CFastString::ConcatFormat(CFastStringInt* other, const char* format, ...) {
    va_list args;
    va_start(args, format);
    CFastString fmtStr;
    fmtStr.m_data = const_cast<char*>(format);
    InternalVFormat(&fmtStr, nullptr, args);
    va_end(args);
}

int CFastString::FilterStringForPrintableChars() {
    if (!m_data || m_length == 0) return 1;
    
    uint32_t newLen = 0;
    for (uint32_t i = 0; i < m_length; ++i) {
        uint8_t c = m_data[i];
        if (c >= 0x20 && c != 0x7F) {
            m_data[newLen++] = c;
        } else if (c == '\t' || c == '\n' || c == '\r') {
            m_data[newLen++] = c;
        }
    }
    bool changed = (newLen != m_length);
    m_length = newLen;
    m_data[m_length] = '\0';
    return !changed;
}

uint32_t CFastString::FindFirst(CFastStringInt* other, uint32_t startIndex, uint32_t flags) {
    if (flags == 0) {
        // Case insensitive find
        const char* otherStr = reinterpret_cast<const char*>(other) + 4;
        const char* pos = _stristr(m_data + startIndex, otherStr); // MSVC specific
        if (pos) return static_cast<uint32_t>(pos - m_data);
        return 0xFFFFFFFF;
    }
    const char* otherStr = reinterpret_cast<const char*>(other) + 4;
    const char* pos = strstr(m_data + startIndex, otherStr);
    if (pos) return static_cast<uint32_t>(pos - m_data);
    return 0xFFFFFFFF;
}

uint32_t CFastString::FindFirstCharInSet(CFastString* set, SStringParam* param, uint32_t startIndex) {
    uint32_t offset = strcspn(m_data + startIndex, set->m_data);
    if (startIndex + offset >= m_length) return 0xFFFFFFFF;
    return startIndex + offset;
}

CFastString* CFastString::Format(CFastString* formatStr, const char* args, ...) {
    va_list va;
    va_start(va, args);
    InternalVFormat(formatStr, args, va);
    va_end(va);
    return this;
}

int CFastString::GetInteger(int* outVal, uint32_t radix) {
    if (!m_data) {
        if (outVal) *outVal = 0;
        return 0;
    }
    *outVal = static_cast<int>(std::strtol(m_data, nullptr, radix));
    return 1;
}

int CFastString::GetLineAt(uint32_t lineIndex, CFastString* outLine) {
    const char* ptr = m_data;
    uint32_t curLine = 0;
    while (ptr) {
        const char* nextLine = std::strchr(ptr, '\n');
        if (curLine == lineIndex) {
            uint32_t len = nextLine ? static_cast<uint32_t>(nextLine - ptr) : std::strlen(ptr);
            if (len > 0 && ptr[len - 1] == '\r') len--;
            outLine->AllocAtLeast(len, 0);
            std::memcpy(outLine->m_data, ptr, len);
            outLine->m_length = len;
            outLine->m_data[len] = '\0';
            return 1;
        }
        if (!nextLine) break;
        ptr = nextLine + 1;
        curLine++;
    }
    outLine->Clear();
    return 0;
}

int CFastString::GetNatural(uint32_t* outVal, int param3, uint32_t radix) {
    if (!m_data) {
        if (outVal) *outVal = 0;
        return 0;
    }
    *outVal = static_cast<uint32_t>(std::strtoul(m_data, nullptr, radix));
    return 1;
}

int CFastString::GetNextToken(SFastTokenInt* token) {
    if (token->tokenCount == 0) token->currentOffset = 0;
    if (m_length <= token->currentOffset) return 0;
    
    char* ptr = m_data + token->currentOffset;
    if (*ptr == '\0') return 0;
    
    uint32_t span = std::strcspn(ptr, token->delimitersAscii);
    
    // token->strPtr1 is actually CFastString* outString
    CFastString* outStr = reinterpret_cast<CFastString*>(&token->strPtr1);
    outStr->AllocAtLeast(span, 0);
    std::memcpy(outStr->m_data, ptr, span);
    outStr->m_length = span;
    outStr->m_data[span] = '\0';
    
    token->tokenCount++;
    char c = ptr[span];
    ptr += span;
    
    if ((token->flags & 2) == 0) {
        if (c != '\0' && std::strchr(token->delimitersAscii, c)) ptr++;
    } else {
        while (c != '\0' && std::strchr(token->delimitersAscii, c)) {
            ptr++;
            c = *ptr;
        }
    }
    
    token->currentOffset = static_cast<uint32_t>(ptr - m_data);
    return 1;
}

int CFastString::GetReal(float* outVal) {
    if (!m_data) {
        if (outVal) *outVal = 0.0f;
        return 0;
    }
    *outVal = static_cast<float>(std::atof(m_data));
    return 1;
}

void CFastString::InternalVFormat(CFastString* formatStr, const char* args, va_list va) {
    uint32_t bufSize = 1024;
    char* buf = new char[bufSize];
    
    int result = vsnprintf(buf, bufSize, formatStr->m_data, va);
    while (result < 0 || static_cast<uint32_t>(result) >= bufSize) {
        delete[] buf;
        bufSize += 256;
        buf = new char[bufSize];
        result = vsnprintf(buf, bufSize, formatStr->m_data, va);
    }
    
    AllocAtLeast(result, 0);
    std::memcpy(m_data, buf, result);
    m_length = result;
    m_data[m_length] = '\0';
    delete[] buf;
}

void CFastString::RemoveAllWhiteSpaces(CFastString* whitelistChars, char* replaceChar) {
    if (m_length == 0) return;
    uint32_t newLen = 0;
    for (uint32_t i = 0; i < m_length; ++i) {
        if (!std::strchr(whitelistChars->m_data, m_data[i])) {
            m_data[newLen++] = m_data[i];
        }
    }
    m_length = newLen;
    m_data[m_length] = '\0';
}

int CFastString::ReplaceFirst(CFastString* searchStr, const char* replaceStr, const char* param3, uint32_t param4, uint32_t param5) {
    const char* pos = std::strstr(m_data, searchStr->m_data);
    if (!pos) return 0;
    
    uint32_t offset = static_cast<uint32_t>(pos - m_data);
    uint32_t searchLen = searchStr->m_length;
    uint32_t replaceLen = std::strlen(replaceStr);
    
    uint32_t newLen = m_length - searchLen + replaceLen;
    char* newBuf = HeapAllocGetChars(newLen);
    
    std::memcpy(newBuf, m_data, offset);
    std::memcpy(newBuf + offset, replaceStr, replaceLen);
    std::memcpy(newBuf + offset + replaceLen, m_data + offset + searchLen, m_length - offset - searchLen);
    
    FreeChars(m_data);
    m_data = newBuf;
    m_length = newLen;
    m_data[m_length] = '\0';
    return 1;
}

void CFastString::SetLength(uint32_t newLength, int fillSpace, char fillChar) {
    if (newLength > m_length) {
        AllocAtLeast(newLength, 1);
        if (fillSpace) std::memset(m_data + m_length, fillChar, newLength - m_length);
    }
    m_length = newLength;
    if (m_data) m_data[m_length] = '\0';
}

void CFastString::SetNat64(uint64_t val, int param3, uint32_t param4, int param5, int param6, int param7) {
    char buf[64];
    std::snprintf(buf, sizeof(buf), (param5 ? "0x%llX" : "%llu"), val);
    uint32_t len = std::strlen(buf);
    AllocAtLeast(len, 0);
    std::memcpy(m_data, buf, len + 1);
    m_length = len;
}

void CFastString::SetNatural(uint32_t val, int param3, uint32_t param4, int param5, int param6, int param7) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), (param5 ? "0x%X" : "%u"), val);
    uint32_t len = std::strlen(buf);
    AllocAtLeast(len, 0);
    std::memcpy(m_data, buf, len + 1);
    m_length = len;
}

void CFastString::SetReal(float val, uint32_t precision) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%g", val);
    uint32_t len = std::strlen(buf);
    AllocAtLeast(len, 0);
    std::memcpy(m_data, buf, len + 1);
    m_length = len;
}

void CFastString::SetRealWithoutExponent(float val, uint32_t precision) {
    char buf[32];
    std::snprintf(buf, sizeof(buf), "%f", val);
    uint32_t len = std::strlen(buf);
    AllocAtLeast(len, 0);
    std::memcpy(m_data, buf, len + 1);
    m_length = len;
}

void CFastString::SetString(CFastStringInt* other, SStringParam* param) {
    uint32_t otherLen = *reinterpret_cast<uint32_t*>(other);
    const char* otherData = reinterpret_cast<const char*>(other) + 4;
    
    AllocAtLeast(otherLen, 0);
    std::memcpy(m_data, otherData, otherLen);
    m_length = otherLen;
    m_data[m_length] = '\0';
}

void CFastString::SetString(const char *str) {
    uint32_t len = std::strlen(str);
    AllocAtLeast(len, 0);
    std::memcpy(m_data, str, len + 1);
    m_length = len;
}

void CFastString::TrimLeft(CFastString* trimChars, char* param2) {
    uint32_t offset = std::strspn(m_data, trimChars->m_data);
    TruncBefore(offset);
}

void CFastString::TrimRight(CFastString* trimChars, char* param2) {
    if (m_length == 0) return;
    int i = m_length - 1;
    while (i >= 0 && std::strchr(trimChars->m_data, m_data[i])) {
        i--;
    }
    TruncAfter(i + 1);
}

void CFastString::TruncAfter(uint32_t index) {
    if (index < m_length) {
        m_length = index;
        m_data[m_length] = '\0';
    }
}

int CFastString::TruncAfterChar(char c, int keepChar) {
    char* pos = std::strchr(m_data, c);
    if (!pos) return 0;
    uint32_t idx = static_cast<uint32_t>(pos - m_data);
    TruncAfter(keepChar ? idx + 1 : idx);
    return 1;
}

void CFastString::TruncBefore(uint32_t index) {
    if (index >= m_length) {
        Clear();
        return;
    }
    uint32_t newLen = m_length - index;
    std::memmove(m_data, m_data + index, newLen);
    m_length = newLen;
    m_data[m_length] = '\0';
}

void CFastString::UpCase(uint32_t startIndex, uint32_t length) {
    if (startIndex >= m_length) return;
    uint32_t maxLen = m_length - startIndex;
    if (length > maxLen) length = maxLen;
    for (uint32_t i = 0; i < length; ++i) {
        m_data[startIndex + i] = static_cast<char>(std::toupper(m_data[startIndex + i]));
    }
}

CPlugFileGpuBuilder* CFastString::operator<<(const char* str) {
    uint32_t len = std::strlen(str);
    AllocAtLeast(m_length + len, 1);
    std::memcpy(m_data + m_length, str, len);
    m_length += len;
    m_data[m_length] = '\0';
    return reinterpret_cast<CPlugFileGpuBuilder*>(this);
}

// =================================================
// CFastStringInt
// =================================================

CFastStringInt::CFastStringInt() : CFastStringBase<wchar_t>() {}

CFastStringInt::CFastStringInt(CFastStringInt* other, SStringParam* param) : CFastStringBase<wchar_t>() {
    // Implied constructor logic
}

void* CFastStringInt::_scalar_deleting_destructor_(CPfmHeap* heap, uint32_t flags) {
    if (flags & 1) delete this;
    return this;
}

CFastString CFastStringInt::GetLatin1() {
    CFastString result;
    result.AllocAtLeast(m_length, 0);
    for (uint32_t i = 0; i < m_length; ++i) {
        result.m_data[i] = static_cast<char>(m_data[i] & 0xFF);
    }
    result.m_length = m_length;
    result.m_data[m_length] = '\0';
    return result;
}

int CFastStringInt::FilterTo7bit(CFastString* param1, SStringParam* param2, char replaceChar) {
    param1->AllocAtLeast(m_length, 0);
    for (uint32_t i = 0; i < m_length; ++i) {
        if (m_data[i] > 127) param1->m_data[i] = replaceChar;
        else param1->m_data[i] = static_cast<char>(m_data[i]);
    }
    param1->m_length = m_length;
    param1->m_data[m_length] = '\0';
    return 1;
}

int CFastStringInt::CompareNoCase(CFastStringInt* other, SStringParam* param, uint32_t length) {
    if (!param) return _wcsicmp(m_data, other->m_data);
    return _wcsnicmp(m_data, other->m_data, length);
}

int CFastStringInt::GetNextToken(SFastTokenInt* token) {
    if (token->tokenCount == 0) token->currentOffset = 0;
    if (m_length <= token->currentOffset) return 0;
    
    wchar_t* ptr = m_data + token->currentOffset;
    if (*ptr == L'\0') return 0;
    
    uint32_t span = std::wcscspn(ptr, token->delimitersWide);
    
    CFastStringInt* outStr = reinterpret_cast<CFastStringInt*>(&token->strPtr1);
    outStr->AllocAtLeast(span, 0);
    std::memcpy(outStr->m_data, ptr, span * sizeof(wchar_t));
    outStr->m_length = span;
    outStr->m_data[span] = L'\0';
    
    token->tokenCount++;
    wchar_t c = ptr[span];
    ptr += span;
    
    if ((token->flags & 2) == 0) {
        if (c != L'\0' && std::wcschr(token->delimitersWide, c)) ptr++;
    } else {
        while (c != L'\0' && std::wcschr(token->delimitersWide, c)) {
            ptr++;
            c = *ptr;
        }
    }
    token->currentOffset = static_cast<uint32_t>(ptr - m_data);
    return 1;
}

uint32_t CFastStringInt::FindFirst(CFastStringInt* other, uint32_t startIndex, uint32_t flags) {
    const wchar_t* pos = std::wcsstr(m_data + startIndex, other->m_data);
    if (pos) return static_cast<uint32_t>(pos - m_data);
    return 0xFFFFFFFF;
}

uint32_t CFastStringInt::FindLast(CFastStringInt* other, uint32_t startIndex, uint32_t flags) {
    if (m_length <= startIndex) startIndex = m_length - 1;
    for (int i = static_cast<int>(startIndex); i >= 0; --i) {
        if (std::wcsncmp(m_data + i, other->m_data, other->m_length) == 0) {
            return static_cast<uint32_t>(i);
        }
    }
    return 0xFFFFFFFF;
}

uint32_t CFastStringInt::ReadCharsNext(uint32_t* outChar) {
    if (*outChar >= m_length) return 0;
    uint32_t result = static_cast<uint32_t>(m_data[*outChar]);
    (*outChar)++;
    return result;
}

uint32_t CFastStringInt::ReadCharsStart() {
    return 0; // Starts offset at 0
}

void CFastStringInt::Compare(SParam_Fids* fids, SParam* param, int* out1, int* out2) {
    // Engine specific translation string check
}

void CFastStringInt::Concat(CFastStringInt* other, SStringParam* param) {
    AllocAtLeast(m_length + other->m_length, 1);
    std::memcpy(m_data + m_length, other->m_data, other->m_length * sizeof(wchar_t));
    m_length += other->m_length;
    m_data[m_length] = L'\0';
}

void CFastStringInt::ConcatBefore(CFastStringInt* other, SStringParamInt* param) {
    if (other->m_length > 0) {
        AllocAtLeast(m_length + other->m_length, 1);
        if (m_length > 0) {
            std::memmove(m_data + other->m_length, m_data, m_length * sizeof(wchar_t));
        }
        std::memcpy(m_data, other->m_data, other->m_length * sizeof(wchar_t));
        m_length += other->m_length;
        m_data[m_length] = L'\0';
    }
}

void CFastStringInt::ConcatFormat(CFastStringInt* other, const char* format, ...) {
    // Internal wide formatting omitted for pure functional recreation
}

void CFastStringInt::GetAscii(CFastString* param2) {
    param2->AllocAtLeast(m_length, 0);
    for (uint32_t i = 0; i < m_length; ++i) {
        param2->m_data[i] = (m_data[i] < 128) ? static_cast<char>(m_data[i]) : '_';
    }
    param2->m_length = m_length;
    param2->m_data[m_length] = '\0';
}

void CFastStringInt::GetEscaped(CFastString* param2) {
    // URL Escaping equivalent
}

void CFastStringInt::GetLimitedSizeUtf8OrAscii(CFastString* param2, uint32_t maxSize) {
    GetUtf8OrAscii(param2); // Simplification mapped back
}

void CFastStringInt::GetUtf8(CFastString* param2, int param3) {
    // Converts Wide Char to UTF-8
    size_t requiredSize = std::wcstombs(nullptr, m_data, 0);
    if (requiredSize != static_cast<size_t>(-1)) {
        param2->AllocAtLeast(requiredSize, 0);
        std::wcstombs(param2->m_data, m_data, requiredSize);
        param2->m_length = requiredSize;
        param2->m_data[requiredSize] = '\0';
    }
}

void CFastStringInt::GetUtf8OrAscii(CFastString* param2) {
    GetUtf8(param2, 0);
}

void CFastStringInt::InternalSetCompose(uint32_t param2, wchar_t* param3, char* param4, void* param5) {
    // Localization composition string parser
}

void CFastStringInt::SetCompose(SStringParam* param2, SStringParamInt* param3) {
    // Stub
}

void CFastStringInt::SetEscaped(CFastString* param2) {
    // URL Decoding equivalent
}

void CFastStringInt::SetLatin1OrUtf8(SStringParam* param2) {
    const char* str = reinterpret_cast<const char*>(param2);
    if (str && str[0] == '\xEF' && str[1] == '\xBB' && str[2] == '\xBF') {
        SetUtf8(param2);
        return;
    }
    uint32_t len = std::strlen(str);
    AllocAtLeast(len, 0);
    for (uint32_t i = 0; i < len; ++i) {
        m_data[i] = static_cast<wchar_t>(static_cast<uint8_t>(str[i]));
    }
    m_length = len;
    m_data[m_length] = L'\0';
}

void CFastStringInt::SetLength(uint32_t newLength, int fillSpace, char fillChar) {
    if (newLength > m_length) {
        AllocAtLeast(newLength, 1);
        if (fillSpace) {
            for (uint32_t i = m_length; i < newLength; ++i) m_data[i] = fillChar;
        }
    }
    m_length = newLength;
    if (m_data) m_data[m_length] = L'\0';
}

void CFastStringInt::SetString(CFastStringInt* other, SStringParam* param) {
    AllocAtLeast(other->m_length, 0);
    std::memcpy(m_data, other->m_data, other->m_length * sizeof(wchar_t));
    m_length = other->m_length;
    m_data[m_length] = L'\0';
}

void CFastStringInt::SetString(const char *str) {
    const char* cstr = str ? str : "";
    size_t len = std::mbstowcs(nullptr, cstr, 0);
    if (len != static_cast<size_t>(-1)) {
        AllocAtLeast(len, 0);
        std::mbstowcs(m_data, cstr, len);
        m_length = len;
        m_data[len] = L'\0';
    }
}

void CFastStringInt::SetUtf8(SStringParam* param2) {
    const char* str = reinterpret_cast<const char*>(param2);
    size_t len = std::mbstowcs(nullptr, str, 0);
    if (len != static_cast<size_t>(-1)) {
        AllocAtLeast(len, 0);
        std::mbstowcs(m_data, str, len);
        m_length = len;
        m_data[len] = L'\0';
    }
}

void CFastStringInt::TruncAfterIndex(uint32_t index) {
    if (index < m_length) {
        m_length = index;
        m_data[m_length] = L'\0';
    }
}

void CFastStringInt::TruncBeforeIndex(uint32_t index) {
    if (index >= m_length) {
        Clear();
        return;
    }
    uint32_t newLen = m_length - index;
    std::memmove(m_data, m_data + index, newLen * sizeof(wchar_t));
    m_length = newLen;
    m_data[m_length] = L'\0';
}