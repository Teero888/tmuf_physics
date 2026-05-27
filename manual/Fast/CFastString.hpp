#include <cctype>
#ifndef CFASTSTRING_HPP
#define CFASTSTRING_HPP

#ifdef __linux__
#include <strings.h>
#define _stricmp strcasecmp
#define _strnicmp strncasecmp
#define _wcsicmp wcscasecmp
#define _wcsnicmp wcsncasecmp
static inline const char* _stristr(const char* haystack, const char* needle) {
    if (!*needle) return haystack;
    for (; *haystack; ++haystack) {
        if (toupper(*haystack) == toupper(*needle)) {
            const char *h, *n;
            for (h = haystack, n = needle; *h && *n; ++h, ++n) {
                if (toupper(*h) != toupper(*n)) break;
            }
            if (!*n) return haystack;
        }
    }
    return nullptr;
}
#endif


#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cwchar>
#include <cstdarg>


// =================================================
// Engine Struct Stubs (To ensure 1:1 Compilation)
// =================================================
struct SStringParam {};
struct SStringParamInt {};
struct SParam_Fids {};
struct SParam {};
class CClassicBufferMemory;
class CPlugFileGpuBuilder;
class TiXmlNode;
class CPfmHeap;
template<typename T> class CFastBuffer;
template<typename T> class CFastArray;

// Token parser context used in GetNextToken
struct SFastTokenInt {
    uint32_t flags;         // 0x0
    uint32_t length;        // 0x4
    void* strPtr1;          // 0x8 (CFastString / CFastStringInt embedded)
    void* strPtr2;          // 0xC
    uint32_t tokenCount;    // 0x10
    uint32_t currentOffset; // 0x14
    const char* delimitersAscii; // 0x18 (For CFastString)
    const wchar_t* delimitersWide; // 0x1C (For CFastStringInt)
};

// =================================================
// Base String Template
// =================================================
template <typename T>
class CFastStringBase {
public:
    uint32_t m_length; // Ghidra labeled this 'vftable' (Offset 0x0)
    T* m_data;         // Offset 0x4

    CFastStringBase();
    ~CFastStringBase();

    void AllocAtLeast(uint32_t reqLength, int keepOldData = 1, void* param_4 = nullptr);
    void Clear(TiXmlNode* node = nullptr);
    void PreAlloc(CClassicBufferMemory* mem, uint32_t size);
    void CopyAndClear(CFastStringBase<T>* other);

    static T* HeapAllocGetChars(uint32_t size);
    static void FreeChars(T* chars);
};

// =================================================
// CFastString (ASCII / Latin1)
// =================================================
class CFastStringInt; // Forward declaration

class CFastString : public CFastStringBase<char> {
public:
    CFastString();
    CFastString(CFastString* other, const char* str); // Concat constructor
    
    CFastString* Format(CFastString* formatStr, const char* args, ...);
    CPlugFileGpuBuilder* operator<<(const char* str);
    
    int FilterStringForPrintableChars();
    int CompareNoCase(CFastStringInt* other, SStringParam* param, uint32_t length);
    int CompareNoCase(const char* other) const;
    int GetInteger(int* outVal, uint32_t radix = 10);
    int GetLineAt(uint32_t lineIndex, CFastString* outLine);
    int GetNatural(uint32_t* outVal, int param3, uint32_t radix);
    int GetNextToken(SFastTokenInt* tokenContext);
    int GetReal(float* outVal);
    int ReplaceFirst(CFastString* searchStr, const char* replaceStr, const char* param3, uint32_t param4, uint32_t param5);
    int TruncAfterChar(char c, int keepChar);
    
    uint32_t FindFirst(CFastStringInt* other, uint32_t startIndex, uint32_t flags);
    uint32_t FindFirstCharInSet(CFastString* set, SStringParam* param, uint32_t startIndex);
    
    void Compare(SParam_Fids* fids, SParam* param, int* out1, int* out2);
    void Concat(CFastStringInt* other, SStringParam* param);
    void ConcatAndNewLine(CFastString* other, const char* param2, const char* suffix);
    void ConcatBefore(CFastStringInt* other, SStringParamInt* param);
    void ConcatFormat(CFastStringInt* other, const char* format, ...);
    void InternalVFormat(CFastString* formatStr, const char* args, va_list va);
    void RemoveAllWhiteSpaces(CFastString* whitelistChars, char* replaceChar);
    
    void SetLength(uint32_t newLength, int fillSpace = 0, char fillChar = ' ');
    void SetNat64(uint64_t val, int param3, uint32_t param4, int param5, int param6, int param7);
    void SetNatural(uint32_t val, int param3, uint32_t param4, int param5, int param6, int param7);
    void SetReal(float val, uint32_t precision = 0);
    void SetRealWithoutExponent(float val, uint32_t precision = 0);
    void SetString(CFastStringInt* other, SStringParam* param);
    
    void TrimLeft(CFastString* trimChars, char* param2);
    void TrimRight(CFastString* trimChars, char* param2);
    void TruncAfter(uint32_t index);
    void TruncBefore(uint32_t index);
    void UpCase(uint32_t startIndex, uint32_t length);
};

// =================================================
// CFastStringInt (UTF-16 / Wide)
// =================================================
class CFastStringInt : public CFastStringBase<wchar_t> {
public:
    CFastStringInt();
    CFastStringInt(CFastStringInt* other, SStringParam* param);
    void* _scalar_deleting_destructor_(CPfmHeap* heap, uint32_t flags);

    CFastString GetLatin1();
    int FilterTo7bit(CFastString* param1, SStringParam* param2, char replaceChar);
    int CompareNoCase(CFastStringInt* other, SStringParam* param, uint32_t length);
    int GetNextToken(SFastTokenInt* tokenContext);
    
    uint32_t FindFirst(CFastStringInt* other, uint32_t startIndex, uint32_t flags);
    uint32_t FindLast(CFastStringInt* other, uint32_t startIndex, uint32_t flags);
    uint32_t ReadCharsNext(uint32_t* outChar);
    uint32_t ReadCharsStart();
    
    void Compare(SParam_Fids* fids, SParam* param, int* out1, int* out2);
    void Concat(CFastStringInt* other, SStringParam* param);
    void ConcatBefore(CFastStringInt* other, SStringParamInt* param);
    void ConcatFormat(CFastStringInt* other, const char* format, ...);
    
    void GetAscii(CFastString* param2);
    void GetEscaped(CFastString* param2);
    void GetLimitedSizeUtf8OrAscii(CFastString* param2, uint32_t maxSize);
    void GetUtf8(CFastString* param2, int param3);
    void GetUtf8OrAscii(CFastString* param2);
    
    void InternalSetCompose(uint32_t param2, wchar_t* param3, char* param4, void* param5);
    void SetCompose(SStringParam* param2, SStringParamInt* param3);
    void SetEscaped(CFastString* param2);
    void SetLatin1OrUtf8(SStringParam* param2);
    void SetLength(uint32_t newLength, int fillSpace = 0, char fillChar = ' ');
    void SetString(CFastStringInt* other, SStringParam* param);
    void SetUtf8(SStringParam* param2);
    
    void TruncAfterIndex(uint32_t index);
    void TruncBeforeIndex(uint32_t index);
};

#endif // CFASTSTRING_HPP