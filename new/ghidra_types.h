typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long long    uint16;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned int    wchar32;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct _s_UnwindMapEntry _s_UnwindMapEntry, *P_s_UnwindMapEntry;

typedef struct _s_UnwindMapEntry UnwindMapEntry;

typedef int __ehstate_t;

struct _s_UnwindMapEntry {
    __ehstate_t toState;
    void (*action)(void);
};

typedef struct _s_ESTypeList _s_ESTypeList, *P_s_ESTypeList;

typedef struct _s_ESTypeList ESTypeList;

typedef struct _s_HandlerType _s_HandlerType, *P_s_HandlerType;

typedef struct _s_HandlerType HandlerType;

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

typedef int ptrdiff_t;

struct TypeDescriptor {
    void *pVFTable;
    void *spare;
    char name[0];
};

struct _s_HandlerType {
    uint adjectives;
    struct TypeDescriptor *pType;
    ptrdiff_t dispCatchObj;
    void *addressOfHandler;
};

struct _s_ESTypeList {
    int nCount;
    HandlerType *pTypeArray;
};

typedef struct _s__RTTIBaseClassDescriptor _s__RTTIBaseClassDescriptor, *P_s__RTTIBaseClassDescriptor;

typedef struct _s__RTTIBaseClassDescriptor RTTIBaseClassDescriptor;

typedef struct PMD PMD, *PPMD;

typedef struct _s__RTTIClassHierarchyDescriptor _s__RTTIClassHierarchyDescriptor, *P_s__RTTIClassHierarchyDescriptor;

typedef struct _s__RTTIClassHierarchyDescriptor RTTIClassHierarchyDescriptor;

struct PMD {
    ptrdiff_t mdisp;
    ptrdiff_t pdisp;
    ptrdiff_t vdisp;
};

struct _s__RTTIBaseClassDescriptor {
    struct TypeDescriptor *pTypeDescriptor; /* ref to TypeDescriptor (RTTI 0) for class */
    dword numContainedBases; /* count of extended classes in BaseClassArray (RTTI 2) */
    struct PMD where; /* member displacement structure */
    dword attributes; /* bit flags */
    RTTIClassHierarchyDescriptor *pClassHierarchyDescriptor; /* ref to ClassHierarchyDescriptor (RTTI 3) for class */
};

struct _s__RTTIClassHierarchyDescriptor {
    dword signature;
    dword attributes; /* bit flags */
    dword numBaseClasses; /* number of base classes (i.e. rtti1Count) */
    RTTIBaseClassDescriptor **pBaseClassArray; /* ref to BaseClassArray (RTTI 2) */
};

typedef struct _s_TryBlockMapEntry _s_TryBlockMapEntry, *P_s_TryBlockMapEntry;

typedef struct _s_TryBlockMapEntry TryBlockMapEntry;

struct _s_TryBlockMapEntry {
    __ehstate_t tryLow;
    __ehstate_t tryHigh;
    __ehstate_t catchHigh;
    int nCatches;
    HandlerType *pHandlerArray;
};

typedef ushort uint16.conflict;

typedef struct _s__RTTICompleteObjectLocator _s__RTTICompleteObjectLocator, *P_s__RTTICompleteObjectLocator;

struct _s__RTTICompleteObjectLocator {
    dword signature;
    dword offset; /* offset of vbtable within class */
    dword cdOffset; /* constructor displacement offset */
    struct TypeDescriptor *pTypeDescriptor; /* ref to TypeDescriptor (RTTI 0) for class */
    RTTIClassHierarchyDescriptor *pClassDescriptor; /* ref to ClassHierarchyDescriptor (RTTI 3) */
};

typedef byte uint8;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory:31;
    dword DataIsDirectory:1;
};

typedef ulonglong uint64;

typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef longlong int64;

typedef struct _s_FuncInfo _s_FuncInfo, *P_s_FuncInfo;

typedef struct _s_FuncInfo FuncInfo;

struct _s_FuncInfo {
    uint magicNumber_and_bbtFlags;
    __ehstate_t maxState;
    UnwindMapEntry *pUnwindMap;
    uint nTryBlocks;
    TryBlockMapEntry *pTryBlockMap;
    uint nIPMapEntries;
    void *pIPToStateMap;
    ESTypeList *pESTypeList;
    int EHFlags;
};

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

typedef struct _s__RTTICompleteObjectLocator RTTICompleteObjectLocator;

typedef uint16 uint128;

typedef struct _SYSTEM_INFO _SYSTEM_INFO, *P_SYSTEM_INFO;

typedef union _union_530 _union_530, *P_union_530;

typedef ulong DWORD;

typedef void *LPVOID;

typedef ulong ULONG_PTR;

typedef ULONG_PTR DWORD_PTR;

typedef ushort WORD;

typedef struct _struct_531 _struct_531, *P_struct_531;

struct _struct_531 {
    WORD wProcessorArchitecture;
    WORD wReserved;
};

union _union_530 {
    DWORD dwOemId;
    struct _struct_531 s;
};

struct _SYSTEM_INFO {
    union _union_530 u;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
};

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef union _union_518 _union_518, *P_union_518;

typedef void *HANDLE;

typedef struct _struct_519 _struct_519, *P_struct_519;

typedef void *PVOID;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

typedef struct _TIME_ZONE_INFORMATION _TIME_ZONE_INFORMATION, *P_TIME_ZONE_INFORMATION;

typedef long LONG;

typedef wchar_t WCHAR;

typedef struct _SYSTEMTIME SYSTEMTIME;

struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

typedef struct _WIN32_FIND_DATAW _WIN32_FIND_DATAW, *P_WIN32_FIND_DATAW;

typedef struct _WIN32_FIND_DATAW *LPWIN32_FIND_DATAW;

typedef struct _FILETIME _FILETIME, *P_FILETIME;

typedef struct _FILETIME FILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

struct _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD nFileSizeHigh;
    DWORD nFileSizeLow;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[260];
    WCHAR cAlternateFileName[14];
};

typedef struct _MEMORYSTATUS _MEMORYSTATUS, *P_MEMORYSTATUS;

typedef ULONG_PTR SIZE_T;

struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _STARTUPINFOA _STARTUPINFOA, *P_STARTUPINFOA;

typedef char CHAR;

typedef CHAR *LPSTR;

typedef uchar BYTE;

typedef BYTE *LPBYTE;

struct _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

typedef struct _MEMORYSTATUS *LPMEMORYSTATUS;

typedef DWORD (*PTHREAD_START_ROUTINE)(LPVOID);

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef LONG (*PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT *PCONTEXT;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _SYSTEM_INFO *LPSYSTEM_INFO;

typedef struct _MEMORYSTATUSEX _MEMORYSTATUSEX, *P_MEMORYSTATUSEX;

typedef double ULONGLONG;

typedef ULONGLONG DWORDLONG;

struct _MEMORYSTATUSEX {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
};

typedef struct _TIME_ZONE_INFORMATION *LPTIME_ZONE_INFORMATION;

typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct _MEMORYSTATUSEX *LPMEMORYSTATUSEX;

typedef struct _STARTUPINFOA *LPSTARTUPINFOA;

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

typedef struct _LIST_ENTRY LIST_ENTRY;

struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
};

struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
};

struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

typedef void (*LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD, DWORD, LPOVERLAPPED);

typedef struct _SYSTEMTIME *LPSYSTEMTIME;

typedef DWORD ULONG;

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG MSG;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

typedef uint UINT;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef long LONG_PTR;

typedef LONG_PTR LPARAM;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

struct tagPOINT {
    LONG x;
    LONG y;
};

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

struct HWND__ {
    int unused;
};

typedef struct tagMSG *LPMSG;

typedef struct _ICONINFO _ICONINFO, *P_ICONINFO;

typedef struct _ICONINFO ICONINFO;

typedef struct HBITMAP__ HBITMAP__, *PHBITMAP__;

typedef struct HBITMAP__ *HBITMAP;

struct HBITMAP__ {
    int unused;
};

struct _ICONINFO {
    BOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbmMask;
    HBITMAP hbmColor;
};

typedef struct tagWNDCLASSEXW tagWNDCLASSEXW, *PtagWNDCLASSEXW;

typedef struct tagWNDCLASSEXW WNDCLASSEXW;

typedef LONG_PTR LRESULT;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

typedef WCHAR *LPCWSTR;

struct HBRUSH__ {
    int unused;
};

struct HICON__ {
    int unused;
};

struct HINSTANCE__ {
    int unused;
};

struct tagWNDCLASSEXW {
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
    HICON hIconSm;
};

typedef ICONINFO *PICONINFO;

typedef void (*TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);

typedef int INT_PTR;

typedef INT_PTR (*DLGPROC)(HWND, UINT, WPARAM, LPARAM);

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; /* Magic number */
    word e_cblp; /* Bytes of last page */
    word e_cp; /* Pages in file */
    word e_crlc; /* Relocations */
    word e_cparhdr; /* Size of header in paragraphs */
    word e_minalloc; /* Minimum extra paragraphs needed */
    word e_maxalloc; /* Maximum extra paragraphs needed */
    word e_ss; /* Initial (relative) SS value */
    word e_sp; /* Initial SP value */
    word e_csum; /* Checksum */
    word e_ip; /* Initial IP value */
    word e_cs; /* Initial (relative) CS value */
    word e_lfarlc; /* File address of relocation table */
    word e_ovno; /* Overlay number */
    word e_res[4][4]; /* Reserved words */
    word e_oemid; /* OEM identifier (for e_oeminfo) */
    word e_oeminfo; /* OEM information; e_oemid specific */
    word e_res2[10][10]; /* Reserved words */
    dword e_lfanew; /* File address of new exe header */
    byte e_program[64]; /* Actual DOS program */
};

typedef struct timecaps_tag timecaps_tag, *Ptimecaps_tag;

struct timecaps_tag {
    UINT wPeriodMin;
    UINT wPeriodMax;
};

typedef struct _MMCKINFO _MMCKINFO, *P_MMCKINFO;

typedef struct _MMCKINFO MMCKINFO;

typedef DWORD FOURCC;

struct _MMCKINFO {
    FOURCC ckid;
    DWORD cksize;
    FOURCC fccType;
    DWORD dwDataOffset;
    DWORD dwFlags;
};

typedef struct _MMIOINFO _MMIOINFO, *P_MMIOINFO;

typedef struct _MMIOINFO *LPMMIOINFO;

typedef LRESULT (MMIOPROC)(LPSTR, UINT, LPARAM, LPARAM);

typedef MMIOPROC *LPMMIOPROC;

typedef struct HTASK__ HTASK__, *PHTASK__;

typedef struct HTASK__ *HTASK;

typedef char *HPSTR;

typedef struct HMMIO__ HMMIO__, *PHMMIO__;

typedef struct HMMIO__ *HMMIO;

struct HMMIO__ {
    int unused;
};

struct _MMIOINFO {
    DWORD dwFlags;
    FOURCC fccIOProc;
    LPMMIOPROC pIOProc;
    UINT wErrorRet;
    HTASK htask;
    LONG cchBuffer;
    HPSTR pchBuffer;
    HPSTR pchNext;
    HPSTR pchEndRead;
    HPSTR pchEndWrite;
    LONG lBufOffset;
    LONG lDiskOffset;
    DWORD adwInfo[3];
    DWORD dwReserved1;
    DWORD dwReserved2;
    HMMIO hmmio;
};

struct HTASK__ {
    int unused;
};

typedef UINT MMRESULT;

typedef struct _MMCKINFO *LPMMCKINFO;

typedef struct timecaps_tag *LPTIMECAPS;

typedef struct _cpinfo _cpinfo, *P_cpinfo;

struct _cpinfo {
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};

typedef struct _cpinfo *LPCPINFO;

typedef DWORD LCTYPE;

typedef BOOL (*LOCALE_ENUMPROCA)(LPSTR);

typedef struct DotNetPdbInfo DotNetPdbInfo, *PDotNetPdbInfo;

struct DotNetPdbInfo {
    char signature[4];
    GUID guid;
    dword age;
    char pdbpath[5];
};

typedef struct _CONSOLE_READCONSOLE_CONTROL _CONSOLE_READCONSOLE_CONTROL, *P_CONSOLE_READCONSOLE_CONTROL;


/* WARNING! conflicting data type names: /WinDef.h/ULONG - /wtypes.h/ULONG */

struct _CONSOLE_READCONSOLE_CONTROL {
    ULONG nLength;
    ULONG nInitialChars;
    ULONG dwCtrlWakeupMask;
    ULONG dwControlKeyState;
};

typedef struct _CONSOLE_READCONSOLE_CONTROL *PCONSOLE_READCONSOLE_CONTROL;

typedef struct tagOFNW tagOFNW, *PtagOFNW;

typedef WCHAR *LPWSTR;

typedef UINT_PTR (*LPOFNHOOKPROC)(HWND, UINT, WPARAM, LPARAM);

struct tagOFNW {
    DWORD lStructSize;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpstrFilter;
    LPWSTR lpstrCustomFilter;
    DWORD nMaxCustFilter;
    DWORD nFilterIndex;
    LPWSTR lpstrFile;
    DWORD nMaxFile;
    LPWSTR lpstrFileTitle;
    DWORD nMaxFileTitle;
    LPCWSTR lpstrInitialDir;
    LPCWSTR lpstrTitle;
    DWORD Flags;
    WORD nFileOffset;
    WORD nFileExtension;
    LPCWSTR lpstrDefExt;
    LPARAM lCustData;
    LPOFNHOOKPROC lpfnHook;
    LPCWSTR lpTemplateName;
    void *pvReserved;
    DWORD dwReserved;
    DWORD FlagsEx;
};

typedef struct tagOFNW *LPOPENFILENAMEW;

typedef longlong __time64_t;

typedef struct _GUID _GUID, *P_GUID;

struct _GUID {
    ulong Data1;
    ushort Data2;
    ushort Data3;
    uchar Data4[8];
};


/* WARNING! conflicting data type names: /guiddef.h/GUID - /GUID */

typedef GUID IID;

typedef struct tagRGBQUAD tagRGBQUAD, *PtagRGBQUAD;

struct tagRGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
};

typedef struct tagBITMAPINFO tagBITMAPINFO, *PtagBITMAPINFO;

typedef struct tagBITMAPINFOHEADER tagBITMAPINFOHEADER, *PtagBITMAPINFOHEADER;

typedef struct tagBITMAPINFOHEADER BITMAPINFOHEADER;

typedef struct tagRGBQUAD RGBQUAD;

struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

struct tagBITMAPINFO {
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[1];
};

typedef struct tagBITMAPINFO *LPBITMAPINFO;

typedef uchar *RPC_CSTR;

typedef GUID UUID;

typedef long RPC_STATUS;

typedef union _ULARGE_INTEGER _ULARGE_INTEGER, *P_ULARGE_INTEGER;

typedef union _ULARGE_INTEGER ULARGE_INTEGER;

typedef struct _struct_22 _struct_22, *P_struct_22;

typedef struct _struct_23 _struct_23, *P_struct_23;

struct _struct_23 {
    DWORD LowPart;
    DWORD HighPart;
};

struct _struct_22 {
    DWORD LowPart;
    DWORD HighPart;
};

union _ULARGE_INTEGER {
    struct _struct_22 s;
    struct _struct_23 u;
    ULONGLONG QuadPart;
};

typedef PVOID PSECURITY_DESCRIPTOR;

typedef WCHAR *PCNZWCH;

typedef CHAR *LPCSTR;

typedef struct _SID_IDENTIFIER_AUTHORITY _SID_IDENTIFIER_AUTHORITY, *P_SID_IDENTIFIER_AUTHORITY;

typedef struct _SID_IDENTIFIER_AUTHORITY *PSID_IDENTIFIER_AUTHORITY;

struct _SID_IDENTIFIER_AUTHORITY {
    BYTE Value[6];
};

typedef struct _ACL _ACL, *P_ACL;

typedef struct _ACL ACL;

typedef ACL *PACL;

struct _ACL {
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
};

typedef LONG *PLONG;

typedef ULARGE_INTEGER *PULARGE_INTEGER;

typedef struct _OSVERSIONINFOA _OSVERSIONINFOA, *P_OSVERSIONINFOA;

struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[128];
};

typedef struct _OSVERSIONINFOA *LPOSVERSIONINFOA;

typedef DWORD ACCESS_MASK;

typedef PVOID PSID;

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

typedef struct _struct_20 _struct_20, *P_struct_20;

typedef double LONGLONG;

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

struct _struct_19 {
    DWORD LowPart;
    LONG HighPart;
};

union _LARGE_INTEGER {
    struct _struct_19 s;
    struct _struct_20 u;
    LONGLONG QuadPart;
};

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef DWORD SECURITY_INFORMATION;

typedef WCHAR *LPWCH;

typedef long HRESULT;

typedef CHAR *LPCH;

typedef WORD LANGID;

typedef short SHORT;

typedef DWORD LCID;

typedef CHAR *PCNZCH;

typedef struct CGameRemoteBufferDataInfoFinds CGameRemoteBufferDataInfoFinds, *PCGameRemoteBufferDataInfoFinds;

struct CGameRemoteBufferDataInfoFinds {
    undefined field0_0x0;
};

typedef struct GxLightBall GxLightBall, *PGxLightBall;

struct GxLightBall {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s_UnwindMapEntry - /_s_UnwindMapEntry */

typedef struct CGameCtnMediaBlockUi CGameCtnMediaBlockUi, *PCGameCtnMediaBlockUi;

struct CGameCtnMediaBlockUi {
    undefined field0_0x0;
};

typedef struct SDeprecatedChallengeLeagueScore SDeprecatedChallengeLeagueScore, *PSDeprecatedChallengeLeagueScore;

struct SDeprecatedChallengeLeagueScore {
    undefined field0_0x0;
};

typedef struct GxDXT1_Block GxDXT1_Block, *PGxDXT1_Block;

struct GxDXT1_Block {
    undefined field0_0x0;
};

typedef struct SPassDesc SPassDesc, *PSPassDesc;

struct SPassDesc {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat> CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat>, *PCFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat>;

struct CFastBufferCat<struct_CDx9StateBlock::STexStageState,struct_CDx9StateBlock::STexStageCat> {
    undefined field0_0x0;
};

typedef struct CPlugModelTree_ItTree CPlugModelTree_ItTree, *PCPlugModelTree_ItTree;

struct CPlugModelTree_ItTree {
    undefined field0_0x0;
};

typedef struct basic_istream<char,struct_std::char_traits<char>_> basic_istream<char,struct_std::char_traits<char>_>, *Pbasic_istream<char,struct_std::char_traits<char>_>;

struct basic_istream<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct SSmoothingGroup SSmoothingGroup, *PSSmoothingGroup;

struct SSmoothingGroup {
    undefined field0_0x0;
};

typedef struct CPfmPath CPfmPath, *PCPfmPath;

struct CPfmPath {
    undefined field0_0x0;
};

typedef struct CControlEnum CControlEnum, *PCControlEnum;

struct CControlEnum {
    undefined field0_0x0;
};

typedef struct CGameNetServerInfo CGameNetServerInfo, *PCGameNetServerInfo;

struct CGameNetServerInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SRenderTarget> CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>, *PCFastBuffer<struct_CVisionViewportDx9::SRenderTarget>;

struct CFastBuffer<struct_CVisionViewportDx9::SRenderTarget> {
    undefined field0_0x0;
};

typedef struct SScanner SScanner, *PSScanner;

struct SScanner {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CManoeuvre> CMwNodRef<class_CManoeuvre>, *PCMwNodRef<class_CManoeuvre>;

struct CMwNodRef<class_CManoeuvre> {
    undefined field0_0x0;
};

typedef struct SMultiRT SMultiRT, *PSMultiRT;

struct SMultiRT {
    undefined field0_0x0;
};

typedef struct CMwCmdExpClassIdent CMwCmdExpClassIdent, *PCMwCmdExpClassIdent;

struct CMwCmdExpClassIdent {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugMaterialCustom::SGpuFx> CFastArray<struct_CPlugMaterialCustom::SGpuFx>, *PCFastArray<struct_CPlugMaterialCustom::SGpuFx>;

struct CFastArray<struct_CPlugMaterialCustom::SGpuFx> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneFxNod>_> CFastBuffer<class_CMwNodRef<class_CSceneFxNod>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneFxNod>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneFxNod>_> {
    undefined field0_0x0;
};

typedef struct CControlEffect CControlEffect, *PCControlEffect;

struct CControlEffect {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneFxCompo::SBitmap> CFastBuffer<struct_CSceneFxCompo::SBitmap>, *PCFastBuffer<struct_CSceneFxCompo::SBitmap>;

struct CFastBuffer<struct_CSceneFxCompo::SBitmap> {
    undefined field0_0x0;
};

typedef struct CMwFoundationsEngine CMwFoundationsEngine, *PCMwFoundationsEngine;

struct CMwFoundationsEngine {
    undefined field0_0x0;
};

typedef struct SManialinkPage_CustomUi SManialinkPage_CustomUi, *PSManialinkPage_CustomUi;

struct SManialinkPage_CustomUi {
    undefined field0_0x0;
};

typedef struct SFastTokenInt SFastTokenInt, *PSFastTokenInt;

struct SFastTokenInt {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugSolid> CFastBufferRef<class_CPlugSolid>, *PCFastBufferRef<class_CPlugSolid>;

struct CFastBufferRef<class_CPlugSolid> {
    undefined field0_0x0;
};

typedef struct CXmlAttribute CXmlAttribute, *PCXmlAttribute;

struct CXmlAttribute {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlacedBlock> CFastBuffer<struct_SPlacedBlock>, *PCFastBuffer<struct_SPlacedBlock>;

struct CFastBuffer<struct_SPlacedBlock> {
    undefined field0_0x0;
};

typedef struct CFastString CFastString, *PCFastString;

struct CFastString {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint> CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>, *PCFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>;

struct CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_> CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugShaderApply>_> {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoSlope CGameCtnBlockInfoSlope, *PCGameCtnBlockInfoSlope;

struct CGameCtnBlockInfoSlope {
    undefined field0_0x0;
};

typedef struct CPlugVisualLines2D CPlugVisualLines2D, *PCPlugVisualLines2D;

struct CPlugVisualLines2D {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CHmsOcclusion::SClipPlane,struct_SFastCat> CFastBufferCat<struct_CHmsOcclusion::SClipPlane,struct_SFastCat>, *PCFastBufferCat<struct_CHmsOcclusion::SClipPlane,struct_SFastCat>;

struct CFastBufferCat<struct_CHmsOcclusion::SClipPlane,struct_SFastCat> {
    undefined field0_0x0;
};

typedef enum EDynamicType {
} EDynamicType;

typedef enum EMode {
} EMode;

typedef struct CHmsVPackerCell CHmsVPackerCell, *PCHmsVPackerCell;

struct CHmsVPackerCell {
    undefined field0_0x0;
};

typedef struct CDynaSpecular CDynaSpecular, *PCDynaSpecular;

struct CDynaSpecular {
    undefined field0_0x0;
};

typedef struct CLoadGeomVertexGen<671098945> CLoadGeomVertexGen<671098945>, *PCLoadGeomVertexGen<671098945>;

struct CLoadGeomVertexGen<671098945> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlPlayer SMwParamInfos_CGameControlPlayer, *PSMwParamInfos_CGameControlPlayer;

struct SMwParamInfos_CGameControlPlayer {
    undefined field0_0x0;
};

typedef struct SProgress SProgress, *PSProgress;

struct SProgress {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLoadProgress SMwParamInfos_CGameLoadProgress, *PSMwParamInfos_CGameLoadProgress;

struct SMwParamInfos_CGameLoadProgress {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneToyBoat::SSurfacePoint> CFastBuffer<struct_CSceneToyBoat::SSurfacePoint>, *PCFastBuffer<struct_CSceneToyBoat::SSurfacePoint>;

struct CFastBuffer<struct_CSceneToyBoat::SSurfacePoint> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParamEnum CMwCmdAffectParamEnum, *PCMwCmdAffectParamEnum;

struct CMwCmdAffectParamEnum {
    undefined field0_0x0;
};

typedef struct SDelayedVisual SDelayedVisual, *PSDelayedVisual;

struct SDelayedVisual {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockUnitInfo CGameCtnBlockUnitInfo, *PCGameCtnBlockUnitInfo;

struct CGameCtnBlockUnitInfo {
    undefined field0_0x0;
};

typedef struct EHRegistrationNode EHRegistrationNode, *PEHRegistrationNode;

struct EHRegistrationNode {
    undefined field0_0x0;
};

typedef enum ESelectionOp {
} ESelectionOp;

typedef struct CGameCtnMediaBlockCameraEffectShake CGameCtnMediaBlockCameraEffectShake, *PCGameCtnMediaBlockCameraEffectShake;

struct CGameCtnMediaBlockCameraEffectShake {
    undefined field0_0x0;
};

typedef struct CGameApp CGameApp, *PCGameApp;

struct CGameApp {
    undefined field0_0x0;
};

typedef enum _D3DTEXTUREADDRESS {
} _D3DTEXTUREADDRESS;

typedef struct SMwParamInfos_CPlugSoundEngineComponent SMwParamInfos_CPlugSoundEngineComponent, *PSMwParamInfos_CPlugSoundEngineComponent;

struct SMwParamInfos_CPlugSoundEngineComponent {
    undefined field0_0x0;
};

typedef struct SParamStruct SParamStruct, *PSParamStruct;

struct SParamStruct {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCamera CMwClassInfoCGameCtnMediaBlockCamera, *PCMwClassInfoCGameCtnMediaBlockCamera;

struct CMwClassInfoCGameCtnMediaBlockCamera {
    undefined field0_0x0;
};

typedef enum EGxTexOp {
} EGxTexOp;

typedef struct CFastBuffer<class_CMwNodRef<class_CFuncCurvesReal>_> CFastBuffer<class_CMwNodRef<class_CFuncCurvesReal>_>, *PCFastBuffer<class_CMwNodRef<class_CFuncCurvesReal>_>;

struct CFastBuffer<class_CMwNodRef<class_CFuncCurvesReal>_> {
    undefined field0_0x0;
};

typedef struct CFastCrypt<unsigned_long> CFastCrypt<unsigned_long>, *PCFastCrypt<unsigned_long>;

struct CFastCrypt<unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup> CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>, *PCFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup>;

struct CFastBuffer<struct_CHmsCollisionManager::SGroup::SAgainstGroup> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwNodRef<class_CPlugVertexStream>_> CFastArray<class_CMwNodRef<class_CPlugVertexStream>_>, *PCFastArray<class_CMwNodRef<class_CPlugVertexStream>_>;

struct CFastArray<class_CMwNodRef<class_CPlugVertexStream>_> {
    undefined field0_0x0;
};

typedef struct CSysFidNodRef<class_CPlugBitmap> CSysFidNodRef<class_CPlugBitmap>, *PCSysFidNodRef<class_CPlugBitmap>;

struct CSysFidNodRef<class_CPlugBitmap> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTrails CGameCtnMediaBlockTrails, *PCGameCtnMediaBlockTrails;

struct CGameCtnMediaBlockTrails {
    undefined field0_0x0;
};

typedef struct CNodSystem CNodSystem, *PCNodSystem;

struct CNodSystem {
    undefined field0_0x0;
};

typedef enum EStorage {
} EStorage;

typedef struct CMwParamRealRange CMwParamRealRange, *PCMwParamRealRange;

struct CMwParamRealRange {
    undefined field0_0x0;
};

typedef struct CControlEffectMotion CControlEffectMotion, *PCControlEffectMotion;

struct CControlEffectMotion {
    undefined field0_0x0;
};

typedef enum EBillState {
} EBillState;

typedef struct SMwParamInfos_CTrackManiaControlCard SMwParamInfos_CTrackManiaControlCard, *PSMwParamInfos_CTrackManiaControlCard;

struct SMwParamInfos_CTrackManiaControlCard {
    undefined field0_0x0;
};

typedef enum EChallengeGroupAlign {
} EChallengeGroupAlign;

typedef struct CFastArray<class_GxColor> CFastArray<class_GxColor>, *PCFastArray<class_GxColor>;

struct CFastArray<class_GxColor> {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorInterface CTrackManiaEditorInterface, *PCTrackManiaEditorInterface;

struct CTrackManiaEditorInterface {
    undefined field0_0x0;
};

typedef enum ESceneVehicleParticleQuality {
} ESceneVehicleParticleQuality;

typedef struct CFastMapTable<struct_CPlugFontBitmap::SKerning> CFastMapTable<struct_CPlugFontBitmap::SKerning>, *PCFastMapTable<struct_CPlugFontBitmap::SKerning>;

struct CFastMapTable<struct_CPlugFontBitmap::SKerning> {
    undefined field0_0x0;
};

typedef struct SObjectDesc SObjectDesc, *PSObjectDesc;

struct SObjectDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlPlayerNet SMwParamInfos_CGameControlPlayerNet, *PSMwParamInfos_CGameControlPlayerNet;

struct SMwParamInfos_CGameControlPlayerNet {
    undefined field0_0x0;
};

typedef struct CPlugModelMesh CPlugModelMesh, *PCPlugModelMesh;

struct CPlugModelMesh {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockTime::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CGameControlCardManager CGameControlCardManager, *PCGameControlCardManager;

struct CGameControlCardManager {
    undefined field0_0x0;
};

typedef struct CGameCtnDecorationMood CGameCtnDecorationMood, *PCGameCtnDecorationMood;

struct CGameCtnDecorationMood {
    undefined field0_0x0;
};

typedef struct CNetTcpConnectedSocket CNetTcpConnectedSocket, *PCNetTcpConnectedSocket;

struct CNetTcpConnectedSocket {
    undefined field0_0x0;
};

typedef struct CFastArray<float*> CFastArray<float*>, *PCFastArray<float*>;

struct CFastArray<float*> {
    undefined field0_0x0;
};

typedef struct CNetConnectChallengeData CNetConnectChallengeData, *PCNetConnectChallengeData;

struct CNetConnectChallengeData {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMotionManagerParticles::SPart> CFastBuffer<struct_CMotionManagerParticles::SPart>, *PCFastBuffer<struct_CMotionManagerParticles::SPart>;

struct CFastBuffer<struct_CMotionManagerParticles::SPart> {
    undefined field0_0x0;
};

typedef enum EMsgType {
} EMsgType;

typedef struct SItem SItem, *PSItem;

struct SItem {
    undefined field0_0x0;
};

typedef struct CIteratorMaterial CIteratorMaterial, *PCIteratorMaterial;

struct CIteratorMaterial {
    undefined field0_0x0;
};

typedef struct SPlayerInfoToSort SPlayerInfoToSort, *PSPlayerInfoToSort;

struct SPlayerInfoToSort {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarIso4 CMwCmdScriptVarIso4, *PCMwCmdScriptVarIso4;

struct CMwCmdScriptVarIso4 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlGrid::SBBoxBackup> CFastBuffer<struct_CControlGrid::SBBoxBackup>, *PCFastBuffer<struct_CControlGrid::SBBoxBackup>;

struct CFastBuffer<struct_CControlGrid::SBBoxBackup> {
    undefined field0_0x0;
};

typedef struct _xmlrpc_value _xmlrpc_value, *P_xmlrpc_value;

struct _xmlrpc_value {
    undefined field0_0x0;
};

typedef struct CPlugFileVsh CPlugFileVsh, *PCPlugFileVsh;

struct CPlugFileVsh {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct - /IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct */

typedef struct SMwParamInfos_CHmsLight SMwParamInfos_CHmsLight, *PSMwParamInfos_CHmsLight;

struct SMwParamInfos_CHmsLight {
    undefined field0_0x0;
};

typedef struct _D3DCOLORVALUE _D3DCOLORVALUE, *P_D3DCOLORVALUE;

struct _D3DCOLORVALUE {
    undefined field0_0x0;
};

typedef struct SFadingSound SFadingSound, *PSFadingSound;

struct SFadingSound {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Neg CMwCmdExpVec3Neg, *PCMwCmdExpVec3Neg;

struct CMwCmdExpVec3Neg {
    undefined field0_0x0;
};

typedef struct CScenePickerManager CScenePickerManager, *PCScenePickerManager;

struct CScenePickerManager {
    undefined field0_0x0;
};

typedef struct CPlugFileVso CPlugFileVso, *PCPlugFileVso;

struct CPlugFileVso {
    undefined field0_0x0;
};

typedef struct CHdrText CHdrText, *PCHdrText;

struct CHdrText {
    undefined field0_0x0;
};

typedef struct SShaderTweakSampler SShaderTweakSampler, *PSShaderTweakSampler;

struct SShaderTweakSampler {
    undefined field0_0x0;
};

typedef struct CNetFormTimed CNetFormTimed, *PCNetFormTimed;

struct CNetFormTimed {
    undefined field0_0x0;
};

typedef struct CPlugVisualIndexedTriangles2D CPlugVisualIndexedTriangles2D, *PCPlugVisualIndexedTriangles2D;

struct CPlugVisualIndexedTriangles2D {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCampaignPlayerScores>_> CFastBuffer<class_CMwNodRef<class_CGameCampaignPlayerScores>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCampaignPlayerScores>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCampaignPlayerScores>_> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamVec3> CMwParamFastBuffer<class_CMwParamVec3>, *PCMwParamFastBuffer<class_CMwParamVec3>;

struct CMwParamFastBuffer<class_CMwParamVec3> {
    undefined field0_0x0;
};

typedef struct CGameCtnFieldUnit CGameCtnFieldUnit, *PCGameCtnFieldUnit;

struct CGameCtnFieldUnit {
    undefined field0_0x0;
};

typedef struct SMappedAction SMappedAction, *PSMappedAction;

struct SMappedAction {
    undefined field0_0x0;
};

typedef enum _EXCEPTION_DISPOSITION {
} _EXCEPTION_DISPOSITION;

typedef struct CScenePickedItem CScenePickedItem, *PCScenePickedItem;

struct CScenePickedItem {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameMultiLocalProfileHeader*> CFastBuffer<class_CGameMultiLocalProfileHeader*>, *PCFastBuffer<class_CGameMultiLocalProfileHeader*>;

struct CFastBuffer<class_CGameMultiLocalProfileHeader*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFidParameters_const*> CFastBuffer<class_CSystemFidParameters_const*>, *PCFastBuffer<class_CSystemFidParameters_const*>;

struct CFastBuffer<class_CSystemFidParameters_const*> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2Add CMwCmdExpVec2Add, *PCMwCmdExpVec2Add;

struct CMwCmdExpVec2Add {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SChildGen> CFastBuffer<struct_SChildGen>, *PCFastBuffer<struct_SChildGen>;

struct CFastBuffer<struct_SChildGen> {
    undefined field0_0x0;
};

typedef struct CControlListMap2 CControlListMap2, *PCControlListMap2;

struct CControlListMap2 {
    undefined field0_0x0;
};

typedef struct CBlendedBone CBlendedBone, *PCBlendedBone;

struct CBlendedBone {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncKeysReal SMwParamInfos_CFuncKeysReal, *PSMwParamInfos_CFuncKeysReal;

struct SMwParamInfos_CFuncKeysReal {
    undefined field0_0x0;
};

typedef struct CPlugAudioEnvironment CPlugAudioEnvironment, *PCPlugAudioEnvironment;

struct CPlugAudioEnvironment {
    undefined field0_0x0;
};

typedef struct SLineDeform SLineDeform, *PSLineDeform;

struct SLineDeform {
    undefined field0_0x0;
};

typedef struct CBlockVariable CBlockVariable, *PCBlockVariable;

struct CBlockVariable {
    undefined field0_0x0;
};

typedef struct CFastBuffer<char_const*> CFastBuffer<char_const*>, *PCFastBuffer<char_const*>;

struct CFastBuffer<char_const*> {
    undefined field0_0x0;
};

typedef struct CNetFormPing CNetFormPing, *PCNetFormPing;

struct CNetFormPing {
    undefined field0_0x0;
};

typedef struct SFrameLadderRankingsStep SFrameLadderRankingsStep, *PSFrameLadderRankingsStep;

struct SFrameLadderRankingsStep {
    undefined field0_0x0;
};

typedef struct SRenderBefore SRenderBefore, *PSRenderBefore;

struct SRenderBefore {
    undefined field0_0x0;
};

typedef struct SPlacedBlockInGridBuffer SPlacedBlockInGridBuffer, *PSPlacedBlockInGridBuffer;

struct SPlacedBlockInGridBuffer {
    undefined field0_0x0;
};

typedef struct SControlFlags SControlFlags, *PSControlFlags;

struct SControlFlags {
    undefined field0_0x0;
};

typedef struct CSceneFx CSceneFx, *PCSceneFx;

struct CSceneFx {
    undefined field0_0x0;
};

typedef struct CRpcCallInternal CRpcCallInternal, *PCRpcCallInternal;

struct CRpcCallInternal {
    undefined field0_0x0;
};

typedef struct CPlugVisualQuads CPlugVisualQuads, *PCPlugVisualQuads;

struct CPlugVisualQuads {
    undefined field0_0x0;
};

typedef struct SCreatePlayerMobilParams SCreatePlayerMobilParams, *PSCreatePlayerMobilParams;

struct SCreatePlayerMobilParams {
    undefined field0_0x0;
};

typedef struct CCache CCache, *PCCache;

struct CCache {
    undefined field0_0x0;
};

typedef struct CHmsViewport CHmsViewport, *PCHmsViewport;

struct CHmsViewport {
    undefined field0_0x0;
};

typedef struct CStridedArray<class_GmVec2> CStridedArray<class_GmVec2>, *PCStridedArray<class_GmVec2>;

struct CStridedArray<class_GmVec2> {
    undefined field0_0x0;
};

typedef enum _D3DBLEND {
} _D3DBLEND;

typedef struct CGameCtnCollection CGameCtnCollection, *PCGameCtnCollection;

struct CGameCtnCollection {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastStringInt,8,unsigned_long> CFixedArray<class_CFastStringInt,8,unsigned_long>, *PCFixedArray<class_CFastStringInt,8,unsigned_long>;

struct CFixedArray<class_CFastStringInt,8,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneSector> CMwNodRef<class_CSceneSector>, *PCMwNodRef<class_CSceneSector>;

struct CMwNodRef<class_CSceneSector> {
    undefined field0_0x0;
};

typedef struct CStridedArray<class_GmVec3> CStridedArray<class_GmVec3>, *PCStridedArray<class_GmVec3>;

struct CStridedArray<class_GmVec3> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameHighScore> CFastBufferRef<class_CGameHighScore>, *PCFastBufferRef<class_CGameHighScore>;

struct CFastBufferRef<class_CGameHighScore> {
    undefined field0_0x0;
};

typedef struct CCrystalVertex CCrystalVertex, *PCCrystalVertex;

struct CCrystalVertex {
    undefined field0_0x0;
};

typedef struct SPlugPixelDirtyFormat SPlugPixelDirtyFormat, *PSPlugPixelDirtyFormat;

struct SPlugPixelDirtyFormat {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFx CGameCtnMediaBlockFx, *PCGameCtnMediaBlockFx;

struct CGameCtnMediaBlockFx {
    undefined field0_0x0;
};

typedef struct CFuncVisual CFuncVisual, *PCFuncVisual;

struct CFuncVisual {
    undefined field0_0x0;
};

typedef struct CHdrComment CHdrComment, *PCHdrComment;

struct CHdrComment {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetIPAddress> CFastBuffer<struct_CNetIPAddress>, *PCFastBuffer<struct_CNetIPAddress>;

struct CFastBuffer<struct_CNetIPAddress> {
    undefined field0_0x0;
};

typedef struct CMwNod CMwNod, *PCMwNod;

struct CMwNod {
    undefined field0_0x0;
};

typedef struct sockaddr sockaddr, *Psockaddr;

struct sockaddr {
    ushort sa_family;
    char sa_data[14];
};

typedef struct CMwNodRef<class_CGameCtnReplayRecord> CMwNodRef<class_CGameCtnReplayRecord>, *PCMwNodRef<class_CGameCtnReplayRecord>;

struct CMwNodRef<class_CGameCtnReplayRecord> {
    undefined field0_0x0;
};

typedef struct CStridedArray<class_GmVec4> CStridedArray<class_GmVec4>, *PCStridedArray<class_GmVec4>;

struct CStridedArray<class_GmVec4> {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnChapter CGameControlCardCtnChapter, *PCGameControlCardCtnChapter;

struct CGameControlCardCtnChapter {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsShadowGroup SMwParamInfos_CHmsShadowGroup, *PSMwParamInfos_CHmsShadowGroup;

struct SMwParamInfos_CHmsShadowGroup {
    undefined field0_0x0;
};

typedef struct CPlugShader CPlugShader, *PCPlugShader;

struct CPlugShader {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnChallenge> CMwNodRef<class_CGameCtnChallenge>, *PCMwNodRef<class_CGameCtnChallenge>;

struct CMwNodRef<class_CGameCtnChallenge> {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorIconPage CTrackManiaEditorIconPage, *PCTrackManiaEditorIconPage;

struct CTrackManiaEditorIconPage {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaTrack>_> CFastBuffer<class_CMwNodRef<class_CGameCtnMediaTrack>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnMediaTrack>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaTrack>_> {
    undefined field0_0x0;
};

typedef struct CFixedArray<char_const*,29,unsigned_long> CFixedArray<char_const*,29,unsigned_long>, *PCFixedArray<char_const*,29,unsigned_long>;

struct CFixedArray<char_const*,29,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnChallengeInfo SMwParamInfos_CGameControlCardCtnChallengeInfo, *PSMwParamInfos_CGameControlCardCtnChallengeInfo;

struct SMwParamInfos_CGameControlCardCtnChallengeInfo {
    undefined field0_0x0;
};

typedef struct SCampaignUnlocks SCampaignUnlocks, *PSCampaignUnlocks;

struct SCampaignUnlocks {
    undefined field0_0x0;
};

typedef struct SRealTimeState SRealTimeState, *PSRealTimeState;

struct SRealTimeState {
    undefined field0_0x0;
};

typedef struct CMotionManaged CMotionManaged, *PCMotionManaged;

struct CMotionManaged {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos> CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>, *PCFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos>;

struct CFastBuffer<struct_CGameCtnMenus::SMenuLeaguePathStepInfos> {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlPlayerInfoCard CTrackManiaControlPlayerInfoCard, *PCTrackManiaControlPlayerInfoCard;

struct CTrackManiaControlPlayerInfoCard {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockFxBloom CMwClassInfoCGameCtnMediaBlockFxBloom, *PCMwClassInfoCGameCtnMediaBlockFxBloom;

struct CMwClassInfoCGameCtnMediaBlockFxBloom {
    undefined field0_0x0;
};

typedef enum ERadius {
} ERadius;

typedef enum NodeType {
} NodeType;

typedef struct GxLightNotAmbient GxLightNotAmbient, *PGxLightNotAmbient;

struct GxLightNotAmbient {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCampaignPlayerScores::SGameModeScores> CFastBuffer<struct_CGameCampaignPlayerScores::SGameModeScores>, *PCFastBuffer<struct_CGameCampaignPlayerScores::SGameModeScores>;

struct CFastBuffer<struct_CGameCampaignPlayerScores::SGameModeScores> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CCrystalEdge*> CFastBuffer<class_CCrystalEdge*>, *PCFastBuffer<class_CCrystalEdge*>;

struct CFastBuffer<class_CCrystalEdge*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SNat128> CFastBuffer<struct_SNat128>, *PCFastBuffer<struct_SNat128>;

struct CFastBuffer<struct_SNat128> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNot CMwCmdExpNot, *PCMwCmdExpNot;

struct CMwCmdExpNot {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SInputActionDesc_const*> CFastBuffer<struct_SInputActionDesc_const*>, *PCFastBuffer<struct_SInputActionDesc_const*>;

struct CFastBuffer<struct_SInputActionDesc_const*> {
    undefined field0_0x0;
};

typedef struct SSceneToyBoat_SailState SSceneToyBoat_SailState, *PSSceneToyBoat_SailState;

struct SSceneToyBoat_SailState {
    undefined field0_0x0;
};

typedef enum EPlugVDcl {
} EPlugVDcl;

typedef struct SWaitingRequest SWaitingRequest, *PSWaitingRequest;

struct SWaitingRequest {
    undefined field0_0x0;
};

typedef struct CPlugFilePack CPlugFilePack, *PCPlugFilePack;

struct CPlugFilePack {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneExtraFlocking SMwParamInfos_CSceneExtraFlocking, *PSMwParamInfos_CSceneExtraFlocking;

struct SMwParamInfos_CSceneExtraFlocking {
    undefined field0_0x0;
};

typedef struct SIPCRemoteControl_Implem SIPCRemoteControl_Implem, *PSIPCRemoteControl_Implem;

struct SIPCRemoteControl_Implem {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderLightOcc SMwParamInfos_CPlugBitmapRenderLightOcc, *PSMwParamInfos_CPlugBitmapRenderLightOcc;

struct SMwParamInfos_CPlugBitmapRenderLightOcc {
    undefined field0_0x0;
};

typedef struct CPlugFileWav CPlugFileWav, *PCPlugFileWav;

struct CPlugFileWav {
    undefined field0_0x0;
};

typedef struct CGameNetPlayerInfo CGameNetPlayerInfo, *PCGameNetPlayerInfo;

struct CGameNetPlayerInfo {
    undefined field0_0x0;
};

typedef struct NvEdgeInfo NvEdgeInfo, *PNvEdgeInfo;

struct NvEdgeInfo {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SCorpusData> CFastArray<struct_SCorpusData>, *PCFastArray<struct_SCorpusData>;

struct CFastArray<struct_SCorpusData> {
    undefined field0_0x0;
};

typedef struct CControlRadar CControlRadar, *PCControlRadar;

struct CControlRadar {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CPlugTree*,struct_SFastCat> CFastBufferCat<class_CPlugTree*,struct_SFastCat>, *PCFastBufferCat<class_CPlugTree*,struct_SFastCat>;

struct CFastBufferCat<class_CPlugTree*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SVisualWheel SVisualWheel, *PSVisualWheel;

struct SVisualWheel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderPlaneR SMwParamInfos_CPlugBitmapRenderPlaneR, *PSMwParamInfos_CPlugBitmapRenderPlaneR;

struct SMwParamInfos_CPlugBitmapRenderPlaneR {
    undefined field0_0x0;
};

typedef enum EInterfaceSound {
} EInterfaceSound;

typedef struct SFilteredScoresInfos SFilteredScoresInfos, *PSFilteredScoresInfos;

struct SFilteredScoresInfos {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMotionManagerParticles::SPartGroupEmitter> CFastBuffer<struct_CMotionManagerParticles::SPartGroupEmitter>, *PCFastBuffer<struct_CMotionManagerParticles::SPartGroupEmitter>;

struct CFastBuffer<struct_CMotionManagerParticles::SPartGroupEmitter> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CMwCmd*,struct_SFastCat> CFastBufferCat<class_CMwCmd*,struct_SFastCat>, *PCFastBufferCat<class_CMwCmd*,struct_SFastCat>;

struct CFastBufferCat<class_CMwCmd*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SSceneToyBoat_NetState SSceneToyBoat_NetState, *PSSceneToyBoat_NetState;

struct SSceneToyBoat_NetState {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneVehicleMaterialGroup> CMwNodRef<class_CSceneVehicleMaterialGroup>, *PCMwNodRef<class_CSceneVehicleMaterialGroup>;

struct CMwNodRef<class_CSceneVehicleMaterialGroup> {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_CPlugFileGpuBuilder::SInOut,2,unsigned_long> CFixedArray<struct_CPlugFileGpuBuilder::SInOut,2,unsigned_long>, *PCFixedArray<struct_CPlugFileGpuBuilder::SInOut,2,unsigned_long>;

struct CFixedArray<struct_CPlugFileGpuBuilder::SInOut,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CControlContainer CControlContainer, *PCControlContainer;

struct CControlContainer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoRectAsym SMwParamInfos_CGameCtnBlockInfoRectAsym, *PSMwParamInfos_CGameCtnBlockInfoRectAsym;

struct SMwParamInfos_CGameCtnBlockInfoRectAsym {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnChallengeInfo*> CFastBuffer<class_CGameCtnChallengeInfo*>, *PCFastBuffer<class_CGameCtnChallengeInfo*>;

struct CFastBuffer<class_CGameCtnChallengeInfo*> {
    undefined field0_0x0;
};

typedef struct STip STip, *PSTip;

struct STip {
    undefined field0_0x0;
};

typedef struct CMotionEmitterParticles CMotionEmitterParticles, *PCMotionEmitterParticles;

struct CMotionEmitterParticles {
    undefined field0_0x0;
};

typedef struct SInputData SInputData, *PSInputData;

struct SInputData {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamInteger> CMwParamFastBuffer<class_CMwParamInteger>, *PCMwParamFastBuffer<class_CMwParamInteger>;

struct CMwParamFastBuffer<class_CMwParamInteger> {
    undefined field0_0x0;
};

typedef struct CGameConnectChallengeData CGameConnectChallengeData, *PCGameConnectChallengeData;

struct CGameConnectChallengeData {
    undefined field0_0x0;
};

typedef struct CSystemFidsFolder CSystemFidsFolder, *PCSystemFidsFolder;

struct CSystemFidsFolder {
    undefined field0_0x0;
};

typedef struct SPartState SPartState, *PSPartState;

struct SPartState {
    undefined field0_0x0;
};

typedef struct STeamMateWayPoint STeamMateWayPoint, *PSTeamMateWayPoint;

struct STeamMateWayPoint {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameManiaNetResource::SRecipient> CFastBuffer<struct_CGameManiaNetResource::SRecipient>, *PCFastBuffer<struct_CGameManiaNetResource::SRecipient>;

struct CFastBuffer<struct_CGameManiaNetResource::SRecipient> {
    undefined field0_0x0;
};

typedef struct CMwParam CMwParam, *PCMwParam;

struct CMwParam {
    undefined field0_0x0;
};

typedef struct SStage SStage, *PSStage;

struct SStage {
    undefined field0_0x0;
};

typedef struct CGameCtnMenuProfileScene CGameCtnMenuProfileScene, *PCGameCtnMenuProfileScene;

struct CGameCtnMenuProfileScene {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameMenu> CMwNodRef<class_CGameMenu>, *PCMwNodRef<class_CGameMenu>;

struct CMwNodRef<class_CGameMenu> {
    undefined field0_0x0;
};

typedef struct CGmCollisionBuffer CGmCollisionBuffer, *PCGmCollisionBuffer;

struct CGmCollisionBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraMaster SMwParamInfos_CGameControlCameraMaster, *PSMwParamInfos_CGameControlCameraMaster;

struct SMwParamInfos_CGameControlCameraMaster {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockTriangles2D CMwClassInfoCGameCtnMediaBlockTriangles2D, *PCMwClassInfoCGameCtnMediaBlockTriangles2D;

struct CMwClassInfoCGameCtnMediaBlockTriangles2D {
    undefined field0_0x0;
};

typedef struct CMotionEngine CMotionEngine, *PCMotionEngine;

struct CMotionEngine {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMotionSkelBlender::CBlendedBone> CFastBuffer<struct_CMotionSkelBlender::CBlendedBone>, *PCFastBuffer<struct_CMotionSkelBlender::CBlendedBone>;

struct CFastBuffer<struct_CMotionSkelBlender::CBlendedBone> {
    undefined field0_0x0;
};

typedef enum enum_3272 {
    INTRNCVT_OK=0,
    INTRNCVT_OVERFLOW=1,
    INTRNCVT_UNDERFLOW=2
} enum_3272;

typedef struct CFastBuffer<class_CGameLeague*> CFastBuffer<class_CGameLeague*>, *PCFastBuffer<class_CGameLeague*>;

struct CFastBuffer<class_CGameLeague*> {
    undefined field0_0x0;
};

typedef struct SFillValue SFillValue, *PSFillValue;

struct SFillValue {
    undefined field0_0x0;
};

typedef struct CHmsVPackerLevel CHmsVPackerLevel, *PCHmsVPackerLevel;

struct CHmsVPackerLevel {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagBITMAPINFO - /wingdi.h/tagBITMAPINFO */

typedef struct CCameraFxDx9 CCameraFxDx9, *PCCameraFxDx9;

struct CCameraFxDx9 {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockTriangles3D CMwClassInfoCGameCtnMediaBlockTriangles3D, *PCMwClassInfoCGameCtnMediaBlockTriangles3D;

struct CMwClassInfoCGameCtnMediaBlockTriangles3D {
    undefined field0_0x0;
};

typedef struct SCellDesc SCellDesc, *PSCellDesc;

struct SCellDesc {
    undefined field0_0x0;
};

typedef struct CVisionViewportDx9 CVisionViewportDx9, *PCVisionViewportDx9;

struct CVisionViewportDx9 {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderHemisphere CPlugBitmapRenderHemisphere, *PCPlugBitmapRenderHemisphere;

struct CPlugBitmapRenderHemisphere {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamVec3> CMwParamFastBufferCat<class_CMwParamVec3>, *PCMwParamFastBufferCat<class_CMwParamVec3>;

struct CMwParamFastBufferCat<class_CMwParamVec3> {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum_EGxUvSrc,24,unsigned_long> CFixedArray<enum_EGxUvSrc,24,unsigned_long>, *PCFixedArray<enum_EGxUvSrc,24,unsigned_long>;

struct CFixedArray<enum_EGxUvSrc,24,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderLightFromMap SMwParamInfos_CPlugBitmapRenderLightFromMap, *PSMwParamInfos_CPlugBitmapRenderLightFromMap;

struct SMwParamInfos_CPlugBitmapRenderLightFromMap {
    undefined field0_0x0;
};

typedef struct CControlList CControlList, *PCControlList;

struct CControlList {
    undefined field0_0x0;
};

typedef struct GxTexCoord GxTexCoord, *PGxTexCoord;

struct GxTexCoord {
    undefined field0_0x0;
};

typedef struct CControlColorChooser2 CControlColorChooser2, *PCControlColorChooser2;

struct CControlColorChooser2 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnParticleParam SMwParamInfos_CGameCtnParticleParam, *PSMwParamInfos_CGameCtnParticleParam;

struct SMwParamInfos_CGameCtnParticleParam {
    undefined field0_0x0;
};

typedef enum EMoveConstraint {
} EMoveConstraint;

typedef struct CHeaderArchiveKeeper CHeaderArchiveKeeper, *PCHeaderArchiveKeeper;

struct CHeaderArchiveKeeper {
    undefined field0_0x0;
};

typedef struct CMwCmdFastCall CMwCmdFastCall, *PCMwCmdFastCall;

struct CMwCmdFastCall {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsCollisionManager SMwParamInfos_CHmsCollisionManager, *PSMwParamInfos_CHmsCollisionManager;

struct SMwParamInfos_CHmsCollisionManager {
    undefined field0_0x0;
};

typedef struct CMotionPlay CMotionPlay, *PCMotionPlay;

struct CMotionPlay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameAvatar SMwParamInfos_CGameAvatar, *PSMwParamInfos_CGameAvatar;

struct SMwParamInfos_CGameAvatar {
    undefined field0_0x0;
};

typedef struct CFileReadCallback CFileReadCallback, *PCFileReadCallback;

struct CFileReadCallback {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmTransQuat> CFastArray<class_GmTransQuat>, *PCFastArray<class_GmTransQuat>;

struct CFastArray<class_GmTransQuat> {
    undefined field0_0x0;
};

typedef struct hostent hostent, *Phostent;

struct hostent {
    char *h_name;
    char **h_aliases;
    short h_addrtype;
    short h_length;
    char **h_addr_list;
};

typedef enum EGutter {
} EGutter;

typedef struct STriangle STriangle, *PSTriangle;

struct STriangle {
    undefined field0_0x0;
};

typedef struct SParamInfo_CMwNod SParamInfo_CMwNod, *PSParamInfo_CMwNod;

struct SParamInfo_CMwNod {
    undefined field0_0x0;
};

typedef struct CDx9ShaderKeeper CDx9ShaderKeeper, *PCDx9ShaderKeeper;

struct CDx9ShaderKeeper {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CSceneToySubway::SCubeDeform> CFastArray<struct_CSceneToySubway::SCubeDeform>, *PCFastArray<struct_CSceneToySubway::SCubeDeform>;

struct CFastArray<struct_CSceneToySubway::SCubeDeform> {
    undefined field0_0x0;
};

typedef struct SStartParameters SStartParameters, *PSStartParameters;

struct SStartParameters {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<struct_CPlugFileImg::SDesc&,unsigned_char*,unsigned_long> CFastCallback3P<struct_CPlugFileImg::SDesc&,unsigned_char*,unsigned_long>, *PCFastCallback3P<struct_CPlugFileImg::SDesc&,unsigned_char*,unsigned_long>;

struct CFastCallback3P<struct_CPlugFileImg::SDesc&,unsigned_char*,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugMaterial*> CFastBuffer<class_CPlugMaterial*>, *PCFastBuffer<class_CPlugMaterial*>;

struct CFastBuffer<class_CPlugMaterial*> {
    undefined field0_0x0;
};

typedef struct SPolyFlags SPolyFlags, *PSPolyFlags;

struct SPolyFlags {
    undefined field0_0x0;
};

typedef struct CHmsForceFieldBall CHmsForceFieldBall, *PCHmsForceFieldBall;

struct CHmsForceFieldBall {
    undefined field0_0x0;
};

typedef struct SVehicleCarSkinIds SVehicleCarSkinIds, *PSVehicleCarSkinIds;

struct SVehicleCarSkinIds {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdAffectIdent SMwParamInfos_CMwCmdAffectIdent, *PSMwParamInfos_CMwCmdAffectIdent;

struct SMwParamInfos_CMwCmdAffectIdent {
    undefined field0_0x0;
};

typedef struct CMwCmdWhile CMwCmdWhile, *PCMwCmdWhile;

struct CMwCmdWhile {
    undefined field0_0x0;
};

typedef struct CIteratorTree CIteratorTree, *PCIteratorTree;

struct CIteratorTree {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamNatural> CMwParamFastArray<class_CMwParamNatural>, *PCMwParamFastArray<class_CMwParamNatural>;

struct CMwParamFastArray<class_CMwParamNatural> {
    undefined field0_0x0;
};

typedef struct CFastRectTable<int> CFastRectTable<int>, *PCFastRectTable<int>;

struct CFastRectTable<int> {
    undefined field0_0x0;
};

typedef struct SProjectorReceivers SProjectorReceivers, *PSProjectorReceivers;

struct SProjectorReceivers {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugTree*> CFastArray<class_CPlugTree*>, *PCFastArray<class_CPlugTree*>;

struct CFastArray<class_CPlugTree*> {
    undefined field0_0x0;
};

typedef struct CPlugSoundMood CPlugSoundMood, *PCPlugSoundMood;

struct CPlugSoundMood {
    undefined field0_0x0;
};

typedef struct TiXmlVisitor TiXmlVisitor, *PTiXmlVisitor;

struct TiXmlVisitor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCamera SMwParamInfos_CGameCamera, *PSMwParamInfos_CGameCamera;

struct SMwParamInfos_CGameCamera {
    undefined field0_0x0;
};

typedef struct CGameApp_MenuContext CGameApp_MenuContext, *PCGameApp_MenuContext;

struct CGameApp_MenuContext {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlList SMwParamInfos_CControlList, *PSMwParamInfos_CControlList;

struct SMwParamInfos_CControlList {
    undefined field0_0x0;
};

typedef struct SVehicleSimpleState_ReplayAfter170806 SVehicleSimpleState_ReplayAfter170806, *PSVehicleSimpleState_ReplayAfter170806;

struct SVehicleSimpleState_ReplayAfter170806 {
    undefined field0_0x0;
};

typedef struct CSceneInfoMouse CSceneInfoMouse, *PCSceneInfoMouse;

struct CSceneInfoMouse {
    undefined field0_0x0;
};

typedef struct SLodMeshGroup SLodMeshGroup, *PSLodMeshGroup;

struct SLodMeshGroup {
    undefined field0_0x0;
};

typedef struct GxFogGlobal GxFogGlobal, *PGxFogGlobal;

struct GxFogGlobal {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugViewDepLocator SMwParamInfos_CPlugViewDepLocator, *PSMwParamInfos_CPlugViewDepLocator;

struct SMwParamInfos_CPlugViewDepLocator {
    undefined field0_0x0;
};

typedef struct SPixelDirty SPixelDirty, *PSPixelDirty;

struct SPixelDirty {
    undefined field0_0x0;
};

typedef struct CGameControlCardCalendar CGameControlCardCalendar, *PCGameControlCardCalendar;

struct CGameControlCardCalendar {
    undefined field0_0x0;
};

typedef struct CPlugVisualTriangles CPlugVisualTriangles, *PCPlugVisualTriangles;

struct CPlugVisualTriangles {
    undefined field0_0x0;
};

typedef struct SGhostCreationParams SGhostCreationParams, *PSGhostCreationParams;

struct SGhostCreationParams {
    undefined field0_0x0;
};

typedef struct SInputActionDesc SInputActionDesc, *PSInputActionDesc;

struct SInputActionDesc {
    undefined field0_0x0;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
};

typedef struct SFurBendParams SFurBendParams, *PSFurBendParams;

struct SFurBendParams {
    undefined field0_0x0;
};

typedef struct TiXmlElement TiXmlElement, *PTiXmlElement;

struct TiXmlElement {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaClip>_> CFastBuffer<class_CMwNodRef<class_CGameCtnMediaClip>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnMediaClip>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaClip>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLeague SMwParamInfos_CGameLeague, *PSMwParamInfos_CGameLeague;

struct SMwParamInfos_CGameLeague {
    undefined field0_0x0;
};

typedef struct CGameAdvertisingRadial CGameAdvertisingRadial, *PCGameAdvertisingRadial;

struct CGameAdvertisingRadial {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CInputBindingsConfig::SBinding> CFastBuffer<struct_CInputBindingsConfig::SBinding>, *PCFastBuffer<struct_CInputBindingsConfig::SBinding>;

struct CFastBuffer<struct_CInputBindingsConfig::SBinding> {
    undefined field0_0x0;
};

typedef struct GmOctreeLowMem_15b_31b GmOctreeLowMem_15b_31b, *PGmOctreeLowMem_15b_31b;

struct GmOctreeLowMem_15b_31b {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameRemoteBufferDataInfo> CFastBufferRef<class_CGameRemoteBufferDataInfo>, *PCFastBufferRef<class_CGameRemoteBufferDataInfo>;

struct CFastBufferRef<class_CGameRemoteBufferDataInfo> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeFrustum SMwParamInfos_CPlugTreeFrustum, *PSMwParamInfos_CPlugTreeFrustum;

struct SMwParamInfos_CPlugTreeFrustum {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFids*> CFastBuffer<class_CSystemFids*>, *PCFastBuffer<class_CSystemFids*>;

struct CFastBuffer<class_CSystemFids*> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugBlendShapeFrame> CFastArray<class_CPlugBlendShapeFrame>, *PCFastArray<class_CPlugBlendShapeFrame>;

struct CFastArray<class_CPlugBlendShapeFrame> {
    undefined field0_0x0;
};

typedef struct CMwValueStd CMwValueStd, *PCMwValueStd;

struct CMwValueStd {
    undefined field0_0x0;
};

typedef struct CFastBufferKeyBase CFastBufferKeyBase, *PCFastBufferKeyBase;

struct CFastBufferKeyBase {
    undefined field0_0x0;
};

typedef struct SUrlLink SUrlLink, *PSUrlLink;

struct SUrlLink {
    undefined field0_0x0;
};

typedef struct CZoneNode CZoneNode, *PCZoneNode;

struct CZoneNode {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFid*> CFastBuffer<class_CSystemFid*>, *PCFastBuffer<class_CSystemFid*>;

struct CFastBuffer<class_CSystemFid*> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CControlBase> CMwNodRef<class_CControlBase>, *PCMwNodRef<class_CControlBase>;

struct CMwNodRef<class_CControlBase> {
    undefined field0_0x0;
};

typedef enum EDdxInMipMap {
} EDdxInMipMap;

typedef struct CFastArray<class_CFastStringInt> CFastArray<class_CFastStringInt>, *PCFastArray<class_CFastStringInt>;

struct CFastArray<class_CFastStringInt> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_FILETIME - /WinDef.h/_FILETIME */

typedef struct CMotion CMotion, *PCMotion;

struct CMotion {
    undefined field0_0x0;
};

typedef struct CLoadCallback CLoadCallback, *PCLoadCallback;

struct CLoadCallback {
    undefined field0_0x0;
};

typedef struct CMwCmdArrayAdd CMwCmdArrayAdd, *PCMwCmdArrayAdd;

struct CMwCmdArrayAdd {
    undefined field0_0x0;
};

typedef enum EPixelUpdate {
} EPixelUpdate;

typedef enum EActionType {
} EActionType;

typedef struct CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferDataInfo>_> CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferDataInfo>_>, *PCFastBuffer<class_CMwNodRef<class_CGameRemoteBufferDataInfo>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferDataInfo>_> {
    undefined field0_0x0;
};

typedef struct SCtnForcedMods SCtnForcedMods, *PSCtnForcedMods;

struct SCtnForcedMods {
    undefined field0_0x0;
};

typedef struct SVehicleSimpleState_ReplayAfter081205 SVehicleSimpleState_ReplayAfter081205, *PSVehicleSimpleState_ReplayAfter081205;

struct SVehicleSimpleState_ReplayAfter081205 {
    undefined field0_0x0;
};

typedef struct SHMAC_MD5_Data SHMAC_MD5_Data, *PSHMAC_MD5_Data;

struct SHMAC_MD5_Data {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnDecorationAudio SMwParamInfos_CGameCtnDecorationAudio, *PSMwParamInfos_CGameCtnDecorationAudio;

struct SMwParamInfos_CGameCtnDecorationAudio {
    undefined field0_0x0;
};

typedef struct SParam_Fid SParam_Fid, *PSParam_Fid;

struct SParam_Fid {
    undefined field0_0x0;
};

typedef struct CSceneToyBird CSceneToyBird, *PCSceneToyBird;

struct CSceneToyBird {
    undefined field0_0x0;
};

typedef struct SVisualVehicle SVisualVehicle, *PSVisualVehicle;

struct SVisualVehicle {
    undefined field0_0x0;
};

typedef struct CGamePlayerAttributesLiving CGamePlayerAttributesLiving, *PCGamePlayerAttributesLiving;

struct CGamePlayerAttributesLiving {
    undefined field0_0x0;
};

typedef struct CTrackManiaPlayer CTrackManiaPlayer, *PCTrackManiaPlayer;

struct CTrackManiaPlayer {
    undefined field0_0x0;
};

typedef struct SRpcLadderStats SRpcLadderStats, *PSRpcLadderStats;

struct SRpcLadderStats {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameChallengeScores>_> CFastBuffer<class_CMwNodRef<class_CGameChallengeScores>_>, *PCFastBuffer<class_CMwNodRef<class_CGameChallengeScores>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameChallengeScores>_> {
    undefined field0_0x0;
};

typedef struct CFastMapTable<unsigned_char> CFastMapTable<unsigned_char>, *PCFastMapTable<unsigned_char>;

struct CFastMapTable<unsigned_char> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CDx9ShaderKeeper::SContextShader> CFastBuffer<struct_CDx9ShaderKeeper::SContextShader>, *PCFastBuffer<struct_CDx9ShaderKeeper::SContextShader>;

struct CFastBuffer<struct_CDx9ShaderKeeper::SContextShader> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraTrackManiaRace SMwParamInfos_CGameControlCameraTrackManiaRace, *PSMwParamInfos_CGameControlCameraTrackManiaRace;

struct SMwParamInfos_CGameControlCameraTrackManiaRace {
    undefined field0_0x0;
};

typedef enum EGxTexInput {
} EGxTexInput;

typedef struct CControlSlider CControlSlider, *PCControlSlider;

struct CControlSlider {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRender CPlugBitmapRender, *PCPlugBitmapRender;

struct CPlugBitmapRender {
    undefined field0_0x0;
};

typedef struct SCampaignScoresRequest SCampaignScoresRequest, *PSCampaignScoresRequest;

struct SCampaignScoresRequest {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastString,8,unsigned_long> CFixedArray<class_CFastString,8,unsigned_long>, *PCFixedArray<class_CFastString,8,unsigned_long>;

struct CFixedArray<class_CFastString,8,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFuncGroupElem CFuncGroupElem, *PCFuncGroupElem;

struct CFuncGroupElem {
    undefined field0_0x0;
};

typedef struct SPolyVertexWeld SPolyVertexWeld, *PSPolyVertexWeld;

struct SPolyVertexWeld {
    undefined field0_0x0;
};

typedef struct CHmsCorpusLight CHmsCorpusLight, *PCHmsCorpusLight;

struct CHmsCorpusLight {
    undefined field0_0x0;
};

typedef struct CSystemArchiveFile CSystemArchiveFile, *PCSystemArchiveFile;

struct CSystemArchiveFile {
    undefined field0_0x0;
};

typedef struct CInputDevice CInputDevice, *PCInputDevice;

struct CInputDevice {
    undefined field0_0x0;
};

typedef struct CXmlUnknown CXmlUnknown, *PCXmlUnknown;

struct CXmlUnknown {
    undefined field0_0x0;
};

typedef struct CControlLabel CControlLabel, *PCControlLabel;

struct CControlLabel {
    undefined field0_0x0;
};

typedef struct CFastRadixSort CFastRadixSort, *PCFastRadixSort;

struct CFastRadixSort {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CBoatTeamMateActionDesc> CMwNodRef<class_CBoatTeamMateActionDesc>, *PCMwNodRef<class_CBoatTeamMateActionDesc>;

struct CMwNodRef<class_CBoatTeamMateActionDesc> {
    undefined field0_0x0;
};

typedef struct CControlQuad CControlQuad, *PCControlQuad;

struct CControlQuad {
    undefined field0_0x0;
};

typedef struct CMotionTeamActionInfo CMotionTeamActionInfo, *PCMotionTeamActionInfo;

struct CMotionTeamActionInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetSource SMwParamInfos_CNetSource, *PSMwParamInfos_CNetSource;

struct SMwParamInfos_CNetSource {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastBuffer<unsigned_char>,3,unsigned_long> CFixedArray<class_CFastBuffer<unsigned_char>,3,unsigned_long>, *PCFixedArray<class_CFastBuffer<unsigned_char>,3,unsigned_long>;

struct CFixedArray<class_CFastBuffer<unsigned_char>,3,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>::SBuildInput> CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>::SBuildInput>, *PCFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>::SBuildInput>;

struct CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>::SBuildInput> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxs CPlugMaterialFxs, *PCPlugMaterialFxs;

struct CPlugMaterialFxs {
    undefined field0_0x0;
};

typedef struct SBinding SBinding, *PSBinding;

struct SBinding {
    undefined field0_0x0;
};

typedef struct SQuitGameContext SQuitGameContext, *PSQuitGameContext;

struct SQuitGameContext {
    undefined field0_0x0;
};

typedef struct CFuncPuffLull CFuncPuffLull, *PCFuncPuffLull;

struct CFuncPuffLull {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlScores CTrackManiaControlScores, *PCTrackManiaControlScores;

struct CTrackManiaControlScores {
    undefined field0_0x0;
};

typedef enum EShadowQ {
} EShadowQ;

typedef struct CFuncSegment CFuncSegment, *PCFuncSegment;

struct CFuncSegment {
    undefined field0_0x0;
};

typedef struct CMwCmdExpIso4 CMwCmdExpIso4, *PCMwCmdExpIso4;

struct CMwCmdExpIso4 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugRessourceStrings SMwParamInfos_CPlugRessourceStrings, *PSMwParamInfos_CPlugRessourceStrings;

struct SMwParamInfos_CPlugRessourceStrings {
    undefined field0_0x0;
};

typedef enum EKind {
} EKind;

typedef struct CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall> CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>, *PCFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall>;

struct CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsZoneDynamic SMwParamInfos_CHmsZoneDynamic, *PSMwParamInfos_CHmsZoneDynamic;

struct SMwParamInfos_CHmsZoneDynamic {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,64,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,64,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugShaderApply>,64,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,64,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncColorGradient SMwParamInfos_CFuncColorGradient, *PSMwParamInfos_CFuncColorGradient;

struct SMwParamInfos_CFuncColorGradient {
    undefined field0_0x0;
};

typedef struct CCallbackRenderBeforeTree CCallbackRenderBeforeTree, *PCCallbackRenderBeforeTree;

struct CCallbackRenderBeforeTree {
    undefined field0_0x0;
};

typedef struct SSoloChallengesCurrentPage SSoloChallengesCurrentPage, *PSSoloChallengesCurrentPage;

struct SSoloChallengesCurrentPage {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SPlugGpuDefine> CFastArray<struct_SPlugGpuDefine>, *PCFastArray<struct_SPlugGpuDefine>;

struct CFastArray<struct_SPlugGpuDefine> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToySubway SMwParamInfos_CSceneToySubway, *PSMwParamInfos_CSceneToySubway;

struct SMwParamInfos_CSceneToySubway {
    undefined field0_0x0;
};

typedef struct SParam_Set SParam_Set, *PSParam_Set;

struct SParam_Set {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmVec2,struct_SFastCat> CFastBufferCat<class_GmVec2,struct_SFastCat>, *PCFastBufferCat<class_GmVec2,struct_SFastCat>;

struct CFastBufferCat<class_GmVec2,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnCollectorVehicle> CMwNodRef<class_CGameCtnCollectorVehicle>, *PCMwNodRef<class_CGameCtnCollectorVehicle>;

struct CMwNodRef<class_CGameCtnCollectorVehicle> {
    undefined field0_0x0;
};

typedef struct CMwCmdReturn CMwCmdReturn, *PCMwCmdReturn;

struct CMwCmdReturn {
    undefined field0_0x0;
};

typedef struct CFastArray<unsigned_short> CFastArray<unsigned_short>, *PCFastArray<unsigned_short>;

struct CFastArray<unsigned_short> {
    undefined field0_0x0;
};

typedef struct SRumble SRumble, *PSRumble;

struct SRumble {
    undefined field0_0x0;
};

typedef enum EShortcut {
} EShortcut;

typedef struct CMwCmdExpVec3Product CMwCmdExpVec3Product, *PCMwCmdExpVec3Product;

struct CMwCmdExpVec3Product {
    undefined field0_0x0;
};

typedef struct CSceneToyBroomstick CSceneToyBroomstick, *PCSceneToyBroomstick;

struct CSceneToyBroomstick {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmQuat> CFastBuffer<class_GmQuat>, *PCFastBuffer<class_GmQuat>;

struct CFastBuffer<class_GmQuat> {
    undefined field0_0x0;
};

typedef struct vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_>, *Pvector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_>;

struct vector<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGamePlayerProfile*> CFastBuffer<class_CGamePlayerProfile*>, *PCFastBuffer<class_CGamePlayerProfile*>;

struct CFastBuffer<class_CGamePlayerProfile*> {
    undefined field0_0x0;
};

typedef struct CGameCtnZone CGameCtnZone, *PCGameCtnZone;

struct CGameCtnZone {
    undefined field0_0x0;
};

typedef struct CPlugVisualStrip CPlugVisualStrip, *PCPlugVisualStrip;

struct CPlugVisualStrip {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceNetLaps SMwParamInfos_CTrackManiaRaceNetLaps, *PSMwParamInfos_CTrackManiaRaceNetLaps;

struct SMwParamInfos_CTrackManiaRaceNetLaps {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugMaterialCustom::SBitmap> CFastArray<struct_CPlugMaterialCustom::SBitmap>, *PCFastArray<struct_CPlugMaterialCustom::SBitmap>;

struct CFastArray<struct_CPlugMaterialCustom::SBitmap> {
    undefined field0_0x0;
};

typedef struct CScene3d CScene3d, *PCScene3d;

struct CScene3d {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnMediaTrack> CMwNodRef<class_CGameCtnMediaTrack>, *PCMwNodRef<class_CGameCtnMediaTrack>;

struct CMwNodRef<class_CGameCtnMediaTrack> {
    undefined field0_0x0;
};

typedef struct CTrackManiaReplayRecord CTrackManiaReplayRecord, *PCTrackManiaReplayRecord;

struct CTrackManiaReplayRecord {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s__RTTIClassHierarchyDescriptor - /_s__RTTIClassHierarchyDescriptor */

typedef struct CFastBuffer<struct_CSystemManagerFile::SEnumFileFolderInfo> CFastBuffer<struct_CSystemManagerFile::SEnumFileFolderInfo>, *PCFastBuffer<struct_CSystemManagerFile::SEnumFileFolderInfo>;

struct CFastBuffer<struct_CSystemManagerFile::SEnumFileFolderInfo> {
    undefined field0_0x0;
};

typedef struct CFuncKeysNatural CFuncKeysNatural, *PCFuncKeysNatural;

struct CFuncKeysNatural {
    undefined field0_0x0;
};

typedef struct CMwParamAction CMwParamAction, *PCMwParamAction;

struct CMwParamAction {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockSound SMwParamInfos_CGameCtnMediaBlockSound, *PSMwParamInfos_CGameCtnMediaBlockSound;

struct SMwParamInfos_CGameCtnMediaBlockSound {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameHighScore>_> CFastBuffer<class_CMwNodRef<class_CGameHighScore>_>, *PCFastBuffer<class_CMwNodRef<class_CGameHighScore>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameHighScore>_> {
    undefined field0_0x0;
};

typedef struct SPlugFunc SPlugFunc, *PSPlugFunc;

struct SPlugFunc {
    undefined field0_0x0;
};

typedef struct CSceneConfigVision CSceneConfigVision, *PCSceneConfigVision;

struct CSceneConfigVision {
    undefined field0_0x0;
};

typedef struct CMwCmdBlockCast CMwCmdBlockCast, *PCMwCmdBlockCast;

struct CMwCmdBlockCast {
    undefined field0_0x0;
};

typedef struct CGameTournament CGameTournament, *PCGameTournament;

struct CGameTournament {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockUi CMwClassInfoCGameCtnMediaBlockUi, *PCMwClassInfoCGameCtnMediaBlockUi;

struct CMwClassInfoCGameCtnMediaBlockUi {
    undefined field0_0x0;
};

typedef enum EDimension {
} EDimension;

typedef struct CTrackManiaRaceNetTimeAttack CTrackManiaRaceNetTimeAttack, *PCTrackManiaRaceNetTimeAttack;

struct CTrackManiaRaceNetTimeAttack {
    undefined field0_0x0;
};

typedef struct CFuncSkel CFuncSkel, *PCFuncSkel;

struct CFuncSkel {
    undefined field0_0x0;
};

typedef enum EGxTexFilter {
} EGxTexFilter;

typedef struct CFastBuffer<struct_CVisionViewportDx9::SDelayedVisual> CFastBuffer<struct_CVisionViewportDx9::SDelayedVisual>, *PCFastBuffer<struct_CVisionViewportDx9::SDelayedVisual>;

struct CFastBuffer<struct_CVisionViewportDx9::SDelayedVisual> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapPacker CPlugBitmapPacker, *PCPlugBitmapPacker;

struct CPlugBitmapPacker {
    undefined field0_0x0;
};

typedef struct CGameManialinkPage CGameManialinkPage, *PCGameManialinkPage;

struct CGameManialinkPage {
    undefined field0_0x0;
};

typedef struct CIteratorLoadFx CIteratorLoadFx, *PCIteratorLoadFx;

struct CIteratorLoadFx {
    undefined field0_0x0;
};

typedef struct CScene2d CScene2d, *PCScene2d;

struct CScene2d {
    undefined field0_0x0;
};

typedef struct CNetConnectResponseData CNetConnectResponseData, *PCNetConnectResponseData;

struct CNetConnectResponseData {
    undefined field0_0x0;
};

typedef enum EManiaNet_ResourceType {
} EManiaNet_ResourceType;

typedef struct CGameCtnMediaBlockGhost CGameCtnMediaBlockGhost, *PCGameCtnMediaBlockGhost;

struct CGameCtnMediaBlockGhost {
    undefined field0_0x0;
};

typedef struct CMwCmdExpEgal CMwCmdExpEgal, *PCMwCmdExpEgal;

struct CMwCmdExpEgal {
    undefined field0_0x0;
};

typedef struct CSceneToyDisplayHistogram CSceneToyDisplayHistogram, *PCSceneToyDisplayHistogram;

struct CSceneToyDisplayHistogram {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetFileTransfer SMwParamInfos_CNetFileTransfer, *PSMwParamInfos_CNetFileTransfer;

struct SMwParamInfos_CNetFileTransfer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetMasterServer::SRequestInfos> CFastBuffer<struct_CNetMasterServer::SRequestInfos>, *PCFastBuffer<struct_CNetMasterServer::SRequestInfos>;

struct CFastBuffer<struct_CNetMasterServer::SRequestInfos> {
    undefined field0_0x0;
};

typedef struct CTrackManiaNetwork CTrackManiaNetwork, *PCTrackManiaNetwork;

struct CTrackManiaNetwork {
    undefined field0_0x0;
};

typedef struct SThreadInfo SThreadInfo, *PSThreadInfo;

struct SThreadInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_> CFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneObjectLink>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMasterServer SMwParamInfos_CGameCtnMasterServer, *PSMwParamInfos_CGameCtnMasterServer;

struct SMwParamInfos_CGameCtnMasterServer {
    undefined field0_0x0;
};

typedef struct SRenderLightingContext SRenderLightingContext, *PSRenderLightingContext;

struct SRenderLightingContext {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CMotionManager> CMwNodRef<class_CMotionManager>, *PCMwNodRef<class_CMotionManager>;

struct CMwNodRef<class_CMotionManager> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardNetOnlineNews SMwParamInfos_CGameControlCardNetOnlineNews, *PSMwParamInfos_CGameControlCardNetOnlineNews;

struct SMwParamInfos_CGameControlCardNetOnlineNews {
    undefined field0_0x0;
};

typedef struct CCrystal CCrystal, *PCCrystal;

struct CCrystal {
    undefined field0_0x0;
};

typedef struct CSystemDataFolders CSystemDataFolders, *PCSystemDataFolders;

struct CSystemDataFolders {
    undefined field0_0x0;
};

typedef struct SParamEffectMotion SParamEffectMotion, *PSParamEffectMotion;

struct SParamEffectMotion {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlCheckPointList CTrackManiaControlCheckPointList, *PCTrackManiaControlCheckPointList;

struct CTrackManiaControlCheckPointList {
    undefined field0_0x0;
};

typedef struct CPlugFileDds CPlugFileDds, *PCPlugFileDds;

struct CPlugFileDds {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_MMIOINFO - /mmsystem.h/_MMIOINFO */

typedef struct CFastBuffer<class_GmBoxAligned> CFastBuffer<class_GmBoxAligned>, *PCFastBuffer<class_GmBoxAligned>;

struct CFastBuffer<class_GmBoxAligned> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTriangles3D CGameCtnMediaBlockTriangles3D, *PCGameCtnMediaBlockTriangles3D;

struct CGameCtnMediaBlockTriangles3D {
    undefined field0_0x0;
};

typedef struct CGameControlCameraOrbital3d CGameControlCameraOrbital3d, *PCGameControlCameraOrbital3d;

struct CGameControlCameraOrbital3d {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastCrypt<int>_> CFastBuffer<class_CFastCrypt<int>_>, *PCFastBuffer<class_CFastCrypt<int>_>;

struct CFastBuffer<class_CFastCrypt<int>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlOverlay SMwParamInfos_CControlOverlay, *PSMwParamInfos_CControlOverlay;

struct SMwParamInfos_CControlOverlay {
    undefined field0_0x0;
};

typedef struct CMwCmdArrayRemove CMwCmdArrayRemove, *PCMwCmdArrayRemove;

struct CMwCmdArrayRemove {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaTracker CGameCtnMediaTracker, *PCGameCtnMediaTracker;

struct CGameCtnMediaTracker {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameLeague> CMwNodRef<class_CGameLeague>, *PCMwNodRef<class_CGameLeague>;

struct CMwNodRef<class_CGameLeague> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraTrackManiaRace3 SMwParamInfos_CGameControlCameraTrackManiaRace3, *PSMwParamInfos_CGameControlCameraTrackManiaRace3;

struct SMwParamInfos_CGameControlCameraTrackManiaRace3 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraTrackManiaRace2 SMwParamInfos_CGameControlCameraTrackManiaRace2, *PSMwParamInfos_CGameControlCameraTrackManiaRace2;

struct SMwParamInfos_CGameControlCameraTrackManiaRace2 {
    undefined field0_0x0;
};

typedef struct exception exception, *Pexception;

struct exception {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceAnalyzerContext CTrackManiaRaceAnalyzerContext, *PCTrackManiaRaceAnalyzerContext;

struct CTrackManiaRaceAnalyzerContext {
    undefined field0_0x0;
};

typedef struct SInputEventsStoreElem SInputEventsStoreElem, *PSInputEventsStoreElem;

struct SInputEventsStoreElem {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSplitCell> CFastBuffer<struct_SSplitCell>, *PCFastBuffer<struct_SSplitCell>;

struct CFastBuffer<struct_SSplitCell> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SDeprecatedChallengeLeagueScore> CFastArray<struct_SDeprecatedChallengeLeagueScore>, *PCFastArray<struct_SDeprecatedChallengeLeagueScore>;

struct CFastArray<struct_SDeprecatedChallengeLeagueScore> {
    undefined field0_0x0;
};

typedef struct CGameConnectResponseData CGameConnectResponseData, *PCGameConnectResponseData;

struct CGameConnectResponseData {
    undefined field0_0x0;
};

typedef struct CDx9FlareOcc CDx9FlareOcc, *PCDx9FlareOcc;

struct CDx9FlareOcc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPfmNode> CFastBuffer<class_CPfmNode>, *PCFastBuffer<class_CPfmNode>;

struct CFastBuffer<class_CPfmNode> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicle::SVisualLight> CFastBuffer<struct_CSceneVehicle::SVisualLight>, *PCFastBuffer<struct_CSceneVehicle::SVisualLight>;

struct CFastBuffer<struct_CSceneVehicle::SVisualLight> {
    undefined field0_0x0;
};

typedef struct SVehicleSimpleState_ReplayAfter040104 SVehicleSimpleState_ReplayAfter040104, *PSVehicleSimpleState_ReplayAfter040104;

struct SVehicleSimpleState_ReplayAfter040104 {
    undefined field0_0x0;
};

typedef struct SSaveContext SSaveContext, *PSSaveContext;

struct SSaveContext {
    undefined field0_0x0;
};

typedef struct SVehicleProfile SVehicleProfile, *PSVehicleProfile;

struct SVehicleProfile {
    undefined field0_0x0;
};

typedef struct CSceneMotorbikeEnvMaterial CSceneMotorbikeEnvMaterial, *PCSceneMotorbikeEnvMaterial;

struct CSceneMotorbikeEnvMaterial {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SOldShowTime> CFastBuffer<struct_SOldShowTime>, *PCFastBuffer<struct_SOldShowTime>;

struct CFastBuffer<struct_SOldShowTime> {
    undefined field0_0x0;
};

typedef struct _String_const_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_> _String_const_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_>, *P_String_const_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_>;

struct _String_const_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_> {
    undefined field0_0x0;
};

typedef struct CGameLadderRankingPlayer CGameLadderRankingPlayer, *PCGameLadderRankingPlayer;

struct CGameLadderRankingPlayer {
    undefined field0_0x0;
};

typedef struct SUrl SUrl, *PSUrl;

struct SUrl {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugCrystal SMwParamInfos_CPlugCrystal, *PSMwParamInfos_CPlugCrystal;

struct SMwParamInfos_CPlugCrystal {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameControlCamera> CMwNodRef<class_CGameControlCamera>, *PCMwNodRef<class_CGameControlCamera>;

struct CMwNodRef<class_CGameControlCamera> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneLight SMwParamInfos_CSceneLight, *PSMwParamInfos_CSceneLight;

struct SMwParamInfos_CSceneLight {
    undefined field0_0x0;
};

typedef struct CControlUrlLinks CControlUrlLinks, *PCControlUrlLinks;

struct CControlUrlLinks {
    undefined field0_0x0;
};

typedef enum EShadow {
} EShadow;

typedef enum ELightUpdate {
} ELightUpdate;

typedef struct CPlugMaterialFxGenCV CPlugMaterialFxGenCV, *PCPlugMaterialFxGenCV;

struct CPlugMaterialFxGenCV {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaBlock>_> CFastBuffer<class_CMwNodRef<class_CGameCtnMediaBlock>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnMediaBlock>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnMediaBlock>_> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxDynaMobil CPlugMaterialFxDynaMobil, *PCPlugMaterialFxDynaMobil;

struct CPlugMaterialFxDynaMobil {
    undefined field0_0x0;
};

typedef struct CPlugFileFont CPlugFileFont, *PCPlugFileFont;

struct CPlugFileFont {
    undefined field0_0x0;
};

typedef struct CCallbackSceneVehicleCarAfterContacts CCallbackSceneVehicleCarAfterContacts, *PCCallbackSceneVehicleCarAfterContacts;

struct CCallbackSceneVehicleCarAfterContacts {
    undefined field0_0x0;
};

typedef struct _LDBL12 _LDBL12, *P_LDBL12;

struct _LDBL12 {
    uchar ld12[12];
};

typedef struct CFastBuffer<class_GmIso4> CFastBuffer<class_GmIso4>, *PCFastBuffer<class_GmIso4>;

struct CFastBuffer<class_GmIso4> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerAttributesLiving SMwParamInfos_CGamePlayerAttributesLiving, *PSMwParamInfos_CGamePlayerAttributesLiving;

struct SMwParamInfos_CGamePlayerAttributesLiving {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionHmsZone::SCasterCat> CFastBuffer<struct_CVisionHmsZone::SCasterCat>, *PCFastBuffer<struct_CVisionHmsZone::SCasterCat>;

struct CFastBuffer<struct_CVisionHmsZone::SCasterCat> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxGenUvProj CPlugMaterialFxGenUvProj, *PCPlugMaterialFxGenUvProj;

struct CPlugMaterialFxGenUvProj {
    undefined field0_0x0;
};

typedef enum EPlugSurfaceMaterialId {
} EPlugSurfaceMaterialId;

typedef struct CFixedArray<class_CMwNodRef<class_CPlugBitmap>,3,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugBitmap>,3,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugBitmap>,3,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugBitmap>,3,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CBoatSail> CMwNodRef<class_CBoatSail>, *PCMwNodRef<class_CBoatSail>;

struct CMwNodRef<class_CBoatSail> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraEffectShake SMwParamInfos_CGameControlCameraEffectShake, *PSMwParamInfos_CGameControlCameraEffectShake;

struct SMwParamInfos_CGameControlCameraEffectShake {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsZoneVPacker::SLocTreeCorpus> CFastBuffer<struct_CHmsZoneVPacker::SLocTreeCorpus>, *PCFastBuffer<struct_CHmsZoneVPacker::SLocTreeCorpus>;

struct CFastBuffer<struct_CHmsZoneVPacker::SLocTreeCorpus> {
    undefined field0_0x0;
};

typedef struct SMwSchemeTimedProperties SMwSchemeTimedProperties, *PSMwSchemeTimedProperties;

struct SMwSchemeTimedProperties {
    undefined field0_0x0;
};

typedef struct GxLight GxLight, *PGxLight;

struct GxLight {
    undefined field0_0x0;
};

typedef struct CFixedArray<char_const*,17,unsigned_long> CFixedArray<char_const*,17,unsigned_long>, *PCFixedArray<char_const*,17,unsigned_long>;

struct CFixedArray<char_const*,17,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CCrystalQuadRaw CCrystalQuadRaw, *PCCrystalQuadRaw;

struct CCrystalQuadRaw {
    undefined field0_0x0;
};

typedef struct CGameCtnCursor CGameCtnCursor, *PCGameCtnCursor;

struct CGameCtnCursor {
    undefined field0_0x0;
};

typedef struct CIteratorVisual CIteratorVisual, *PCIteratorVisual;

struct CIteratorVisual {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlListMap2::SControlElem> CFastBuffer<struct_CControlListMap2::SControlElem>, *PCFastBuffer<struct_CControlListMap2::SControlElem>;

struct CFastBuffer<struct_CControlListMap2::SControlElem> {
    undefined field0_0x0;
};

typedef struct CPlugBlendShapeFrame CPlugBlendShapeFrame, *PCPlugBlendShapeFrame;

struct CPlugBlendShapeFrame {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncShaderFxFactor SMwParamInfos_CFuncShaderFxFactor, *PSMwParamInfos_CFuncShaderFxFactor;

struct SMwParamInfos_CFuncShaderFxFactor {
    undefined field0_0x0;
};

typedef struct SAlloc SAlloc, *PSAlloc;

struct SAlloc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlLabel SMwParamInfos_CControlLabel, *PSMwParamInfos_CControlLabel;

struct SMwParamInfos_CControlLabel {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockText CMwClassInfoCGameCtnMediaBlockText, *PCMwClassInfoCGameCtnMediaBlockText;

struct CMwClassInfoCGameCtnMediaBlockText {
    undefined field0_0x0;
};

typedef struct basic_ofstream<char,struct_std::char_traits<char>_> basic_ofstream<char,struct_std::char_traits<char>_>, *Pbasic_ofstream<char,struct_std::char_traits<char>_>;

struct basic_ofstream<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct CGameBuddy CGameBuddy, *PCGameBuddy;

struct CGameBuddy {
    undefined field0_0x0;
};

typedef struct SGpuFx SGpuFx, *PSGpuFx;

struct SGpuFx {
    undefined field0_0x0;
};

typedef struct TranslatorGuardRN TranslatorGuardRN, *PTranslatorGuardRN;

struct TranslatorGuardRN {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CScenePath>_> CFastBuffer<class_CMwNodRef<class_CScenePath>_>, *PCFastBuffer<class_CMwNodRef<class_CScenePath>_>;

struct CFastBuffer<class_CMwNodRef<class_CScenePath>_> {
    undefined field0_0x0;
};

typedef struct CGameNetFormTunnel CGameNetFormTunnel, *PCGameNetFormTunnel;

struct CGameNetFormTunnel {
    undefined field0_0x0;
};

typedef struct SControlElem SControlElem, *PSControlElem;

struct SControlElem {
    undefined field0_0x0;
};

typedef struct GmCollision GmCollision, *PGmCollision;

struct GmCollision {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugFileGPU::SShaderQuality> CFastArray<struct_CPlugFileGPU::SShaderQuality>, *PCFastArray<struct_CPlugFileGPU::SShaderQuality>;

struct CFastArray<struct_CPlugFileGPU::SShaderQuality> {
    undefined field0_0x0;
};

typedef struct TiXmlAttributeSet TiXmlAttributeSet, *PTiXmlAttributeSet;

struct TiXmlAttributeSet {
    undefined field0_0x0;
};

typedef struct HDC__ HDC__, *PHDC__;

struct HDC__ {
    int unused;
};

typedef struct SOptimFlags SOptimFlags, *PSOptimFlags;

struct SOptimFlags {
    undefined field0_0x0;
};

typedef struct CPlugVisual CPlugVisual, *PCPlugVisual;

struct CPlugVisual {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CHmsPackLightMapCache> CMwNodRef<class_CHmsPackLightMapCache>, *PCMwNodRef<class_CHmsPackLightMapCache>;

struct CMwNodRef<class_CHmsPackLightMapCache> {
    undefined field0_0x0;
};

typedef struct CControlEntry CControlEntry, *PCControlEntry;

struct CControlEntry {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerProfile::SFavouriteInfo> CFastBuffer<struct_CGamePlayerProfile::SFavouriteInfo>, *PCFastBuffer<struct_CGamePlayerProfile::SFavouriteInfo>;

struct CFastBuffer<struct_CGamePlayerProfile::SFavouriteInfo> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnReplayRecordInfo SMwParamInfos_CGameControlCardCtnReplayRecordInfo, *PSMwParamInfos_CGameControlCardCtnReplayRecordInfo;

struct SMwParamInfos_CGameControlCardCtnReplayRecordInfo {
    undefined field0_0x0;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    uint Characteristics;
    uint TimeDateStamp;
    uint16.conflict MajorVersion;
    uint16.conflict MinorVersion;
    uint Type;
    uint SizeOfData;
    uint AddressOfRawData;
    uint PointerToRawData;
};

typedef enum EShader {
} EShader;

typedef struct CFastArray<struct_SCustomGpuFxOld> CFastArray<struct_SCustomGpuFxOld>, *PCFastArray<struct_SCustomGpuFxOld>;

struct CFastArray<struct_SCustomGpuFxOld> {
    undefined field0_0x0;
};

typedef enum EDialogResult {
} EDialogResult;


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s__RTTIBaseClassDescriptor - /_s__RTTIBaseClassDescriptor */

typedef enum ECpuExt {
} ECpuExt;

typedef struct CFastBuffer<struct_SControlUrlLink> CFastBuffer<struct_SControlUrlLink>, *PCFastBuffer<struct_SControlUrlLink>;

struct CFastBuffer<struct_SControlUrlLink> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CXmlDeclaration SMwParamInfos_CXmlDeclaration, *PSMwParamInfos_CXmlDeclaration;

struct SMwParamInfos_CXmlDeclaration {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockMusicEffect CGameCtnMediaBlockMusicEffect, *PCGameCtnMediaBlockMusicEffect;

struct CGameCtnMediaBlockMusicEffect {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlock CGameCtnMediaBlock, *PCGameCtnMediaBlock;

struct CGameCtnMediaBlock {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockFxBlur CMwClassInfoCGameCtnMediaBlockFxBlur, *PCMwClassInfoCGameCtnMediaBlockFxBlur;

struct CMwClassInfoCGameCtnMediaBlockFxBlur {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaClipPlayer SMwParamInfos_CGameCtnMediaClipPlayer, *PSMwParamInfos_CGameCtnMediaClipPlayer;

struct SMwParamInfos_CGameCtnMediaClipPlayer {
    undefined field0_0x0;
};

typedef enum ESubLocation {
} ESubLocation;

typedef struct CCrystalTexCoord CCrystalTexCoord, *PCCrystalTexCoord;

struct CCrystalTexCoord {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockText CGameCtnMediaBlockText, *PCGameCtnMediaBlockText;

struct CGameCtnMediaBlockText {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCSceneVehicleCar CMwClassInfoCSceneVehicleCar, *PCMwClassInfoCSceneVehicleCar;

struct CMwClassInfoCSceneVehicleCar {
    undefined field0_0x0;
};

typedef struct CTrackManiaEngine CTrackManiaEngine, *PCTrackManiaEngine;

struct CTrackManiaEngine {
    undefined field0_0x0;
};

typedef enum EDecorationMusic {
} EDecorationMusic;

typedef struct CControlEffectMoveFrame CControlEffectMoveFrame, *PCControlEffectMoveFrame;

struct CControlEffectMoveFrame {
    undefined field0_0x0;
};

typedef struct CGameControlPlayerInput CGameControlPlayerInput, *PCGameControlPlayerInput;

struct CGameControlPlayerInput {
    undefined field0_0x0;
};

typedef struct CSceneInfoSelect CSceneInfoSelect, *PCSceneInfoSelect;

struct CSceneInfoSelect {
    undefined field0_0x0;
};

typedef struct CGameCtnChallengeGroup CGameCtnChallengeGroup, *PCGameCtnChallengeGroup;

struct CGameCtnChallengeGroup {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameNetOnlineMessage> CFastBufferRef<class_CGameNetOnlineMessage>, *PCFastBufferRef<class_CGameNetOnlineMessage>;

struct CFastBufferRef<class_CGameNetOnlineMessage> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraPath CMwClassInfoCGameCtnMediaBlockCameraPath, *PCMwClassInfoCGameCtnMediaBlockCameraPath;

struct CMwClassInfoCGameCtnMediaBlockCameraPath {
    undefined field0_0x0;
};

typedef struct SScore SScore, *PSScore;

struct SScore {
    undefined field0_0x0;
};

typedef struct GmSurfSphere GmSurfSphere, *PGmSurfSphere;

struct GmSurfSphere {
    undefined field0_0x0;
};

typedef struct SFastKey<struct_CPlugPointsInSphereOpt::SPack,unsigned_long> SFastKey<struct_CPlugPointsInSphereOpt::SPack,unsigned_long>, *PSFastKey<struct_CPlugPointsInSphereOpt::SPack,unsigned_long>;

struct SFastKey<struct_CPlugPointsInSphereOpt::SPack,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMotionManagerParticles::SPartBirthParams> CFastBuffer<struct_CMotionManagerParticles::SPartBirthParams>, *PCFastBuffer<struct_CMotionManagerParticles::SPartBirthParams>;

struct CFastBuffer<struct_CMotionManagerParticles::SPartBirthParams> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaControlScores2::SList> CFastBuffer<struct_CTrackManiaControlScores2::SList>, *PCFastBuffer<struct_CTrackManiaControlScores2::SList>;

struct CFastBuffer<struct_CTrackManiaControlScores2::SList> {
    undefined field0_0x0;
};

typedef struct CMwCmdBlockMain CMwCmdBlockMain, *PCMwCmdBlockMain;

struct CMwCmdBlockMain {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncPathMeshLocation SMwParamInfos_CFuncPathMeshLocation, *PSMwParamInfos_CFuncPathMeshLocation;

struct SMwParamInfos_CFuncPathMeshLocation {
    undefined field0_0x0;
};

typedef struct CPlugFileModel CPlugFileModel, *PCPlugFileModel;

struct CPlugFileModel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetFileTransferUpload SMwParamInfos_CNetFileTransferUpload, *PSMwParamInfos_CNetFileTransferUpload;

struct SMwParamInfos_CNetFileTransferUpload {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxCameraBlend SMwParamInfos_CSceneFxCameraBlend, *PSMwParamInfos_CSceneFxCameraBlend;

struct SMwParamInfos_CSceneFxCameraBlend {
    undefined field0_0x0;
};

typedef enum EAlignHorizontal {
} EAlignHorizontal;

typedef struct SMwParamInfos_CNetHttpClient SMwParamInfos_CNetHttpClient, *PSMwParamInfos_CNetHttpClient;

struct SMwParamInfos_CNetHttpClient {
    undefined field0_0x0;
};

typedef struct GxImage GxImage, *PGxImage;

struct GxImage {
    undefined field0_0x0;
};

typedef struct CMotionFunc CMotionFunc, *PCMotionFunc;

struct CMotionFunc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCollection SMwParamInfos_CGameCtnCollection, *PSMwParamInfos_CGameCtnCollection;

struct SMwParamInfos_CGameCtnCollection {
    undefined field0_0x0;
};

typedef struct SGameNetworkChatData SGameNetworkChatData, *PSGameNetworkChatData;

struct SGameNetworkChatData {
    undefined field0_0x0;
};

typedef struct SFormat SFormat, *PSFormat;

struct SFormat {
    undefined field0_0x0;
};

typedef struct SDeliveryHandlers SDeliveryHandlers, *PSDeliveryHandlers;

struct SDeliveryHandlers {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamReal> CMwParamFastArray<class_CMwParamReal>, *PCMwParamFastArray<class_CMwParamReal>;

struct CMwParamFastArray<class_CMwParamReal> {
    undefined field0_0x0;
};

typedef enum EBoatTree {
} EBoatTree;

typedef struct CPlugFileFidContainer CPlugFileFidContainer, *PCPlugFileFidContainer;

struct CPlugFileFidContainer {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CSceneToySeaHoule::SHeightFoam,struct_SFastCat> CFastBufferCat<struct_CSceneToySeaHoule::SHeightFoam,struct_SFastCat>, *PCFastBufferCat<struct_CSceneToySeaHoule::SHeightFoam,struct_SFastCat>;

struct CFastBufferCat<struct_CSceneToySeaHoule::SHeightFoam,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SDelayedRender SDelayedRender, *PSDelayedRender;

struct SDelayedRender {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CFastString,struct_SFastCat> CFastBufferCat<class_CFastString,struct_SFastCat>, *PCFastBufferCat<class_CFastString,struct_SFastCat>;

struct CFastBufferCat<class_CFastString,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CNetMasterServerRequest> CMwNodRef<class_CNetMasterServerRequest>, *PCMwNodRef<class_CNetMasterServerRequest>;

struct CMwNodRef<class_CNetMasterServerRequest> {
    undefined field0_0x0;
};

typedef struct GxFogBlender GxFogBlender, *PGxFogBlender;

struct GxFogBlender {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCampaignScores>_> {
    undefined field0_0x0;
};

typedef struct SHmsSphereBufferContact SHmsSphereBufferContact, *PSHmsSphereBufferContact;

struct SHmsSphereBufferContact {
    undefined field0_0x0;
};

typedef struct SSortRemapInfo SSortRemapInfo, *PSSortRemapInfo;

struct SSortRemapInfo {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Param CMwCmdExpVec3Param, *PCMwCmdExpVec3Param;

struct CMwCmdExpVec3Param {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnCampaign CGameControlCardCtnCampaign, *PCGameControlCardCtnCampaign;

struct CGameControlCardCtnCampaign {
    undefined field0_0x0;
};

typedef struct vector<int,class_std::allocator<int>_> vector<int,class_std::allocator<int>_>, *Pvector<int,class_std::allocator<int>_>;

struct vector<int,class_std::allocator<int>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmReal4_64> CFastBuffer<class_GmReal4_64>, *PCFastBuffer<class_GmReal4_64>;

struct CFastBuffer<class_GmReal4_64> {
    undefined field0_0x0;
};

typedef struct CFuncKeysTrans CFuncKeysTrans, *PCFuncKeysTrans;

struct CFuncKeysTrans {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SCtnForcedMods::SEnvMod> CFastBuffer<struct_SCtnForcedMods::SEnvMod>, *PCFastBuffer<struct_SCtnForcedMods::SEnvMod>;

struct CFastBuffer<struct_SCtnForcedMods::SEnvMod> {
    undefined field0_0x0;
};

typedef struct CSceneInfoDrag CSceneInfoDrag, *PCSceneInfoDrag;

struct CSceneInfoDrag {
    undefined field0_0x0;
};

typedef struct CFastBuffer<unsigned_char> CFastBuffer<unsigned_char>, *PCFastBuffer<unsigned_char>;

struct CFastBuffer<unsigned_char> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSubPage> CFastBuffer<struct_SSubPage>, *PCFastBuffer<struct_SSubPage>;

struct CFastBuffer<struct_SSubPage> {
    undefined field0_0x0;
};

typedef struct CControlIconIndex CControlIconIndex, *PCControlIconIndex;

struct CControlIconIndex {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxOverlay SMwParamInfos_CSceneFxOverlay, *PSMwParamInfos_CSceneFxOverlay;

struct SMwParamInfos_CSceneFxOverlay {
    undefined field0_0x0;
};

typedef struct CControlUiDockable CControlUiDockable, *PCControlUiDockable;

struct CControlUiDockable {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneObject> CMwNodRef<class_CSceneObject>, *PCMwNodRef<class_CSceneObject>;

struct CMwNodRef<class_CSceneObject> {
    undefined field0_0x0;
};

typedef struct _xmlrpc_server_info _xmlrpc_server_info, *P_xmlrpc_server_info;

struct _xmlrpc_server_info {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetFileTransferNod SMwParamInfos_CNetFileTransferNod, *PSMwParamInfos_CNetFileTransferNod;

struct SMwParamInfos_CNetFileTransferNod {
    undefined field0_0x0;
};

typedef struct GmLinearSmooth<float> GmLinearSmooth<float>, *PGmLinearSmooth<float>;

struct GmLinearSmooth<float> {
    undefined field0_0x0;
};

typedef struct SRpcGameInfo SRpcGameInfo, *PSRpcGameInfo;

struct SRpcGameInfo {
    undefined field0_0x0;
};

typedef struct SPodiumAddCar SPodiumAddCar, *PSPodiumAddCar;

struct SPodiumAddCar {
    undefined field0_0x0;
};

typedef struct CSceneEngine CSceneEngine, *PCSceneEngine;

struct CSceneEngine {
    undefined field0_0x0;
};

typedef struct CSystemPackDesc CSystemPackDesc, *PCSystemPackDesc;

struct CSystemPackDesc {
    undefined field0_0x0;
};

typedef struct CSceneToySeaHoule CSceneToySeaHoule, *PCSceneToySeaHoule;

struct CSceneToySeaHoule {
    undefined field0_0x0;
};

typedef struct CGameControlCameraEffectShake CGameControlCameraEffectShake, *PCGameControlCameraEffectShake;

struct CGameControlCameraEffectShake {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetwork::SClientBannedInfo*> CFastBuffer<struct_CGameNetwork::SClientBannedInfo*>, *PCFastBuffer<struct_CGameNetwork::SClientBannedInfo*>;

struct CFastBuffer<struct_CGameNetwork::SClientBannedInfo*> {
    undefined field0_0x0;
};

typedef struct CMwCmdParamInterface CMwCmdParamInterface, *PCMwCmdParamInterface;

struct CMwCmdParamInterface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnEditorScenePocLink SMwParamInfos_CGameCtnEditorScenePocLink, *PSMwParamInfos_CGameCtnEditorScenePocLink;

struct SMwParamInfos_CGameCtnEditorScenePocLink {
    undefined field0_0x0;
};

typedef struct CGameSafeFrame CGameSafeFrame, *PCGameSafeFrame;

struct CGameSafeFrame {
    undefined field0_0x0;
};

typedef struct SSimulationVehicle SSimulationVehicle, *PSSimulationVehicle;

struct SSimulationVehicle {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnGhostInfo CGameControlCardCtnGhostInfo, *PCGameControlCardCtnGhostInfo;

struct CGameControlCardCtnGhostInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengesCurrentPage> CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengesCurrentPage>, *PCFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengesCurrentPage>;

struct CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengesCurrentPage> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelTree::SDataLayer> CFastBuffer<struct_CPlugModelTree::SDataLayer>, *PCFastBuffer<struct_CPlugModelTree::SDataLayer>;

struct CFastBuffer<struct_CPlugModelTree::SDataLayer> {
    undefined field0_0x0;
};

typedef struct CFuncColorGradient CFuncColorGradient, *PCFuncColorGradient;

struct CFuncColorGradient {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionFunc SMwParamInfos_CMotionFunc, *PSMwParamInfos_CMotionFunc;

struct SMwParamInfos_CMotionFunc {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CSystemFids*> CFastArray<class_CSystemFids*>, *PCFastArray<class_CSystemFids*>;

struct CFastArray<class_CSystemFids*> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamIso3> CMwParamFastBuffer<class_CMwParamIso3>, *PCMwParamFastBuffer<class_CMwParamIso3>;

struct CMwParamFastBuffer<class_CMwParamIso3> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CScenePath> CFastBufferRef<class_CScenePath>, *PCFastBufferRef<class_CScenePath>;

struct CFastBufferRef<class_CScenePath> {
    undefined field0_0x0;
};

typedef struct CPlugPointsInSphereOpt CPlugPointsInSphereOpt, *PCPlugPointsInSphereOpt;

struct CPlugPointsInSphereOpt {
    undefined field0_0x0;
};

typedef struct CDx9GpuBuilder CDx9GpuBuilder, *PCDx9GpuBuilder;

struct CDx9GpuBuilder {
    undefined field0_0x0;
};

typedef enum EUsage {
} EUsage;

typedef struct CFastBuffer<struct_SHmsVPackerObject> CFastBuffer<struct_SHmsVPackerObject>, *PCFastBuffer<struct_SHmsVPackerObject>;

struct CFastBuffer<struct_SHmsVPackerObject> {
    undefined field0_0x0;
};

typedef struct CAudioSoundEngine_Mixer_Implem<float,2> CAudioSoundEngine_Mixer_Implem<float,2>, *PCAudioSoundEngine_Mixer_Implem<float,2>;

struct CAudioSoundEngine_Mixer_Implem<float,2> {
    undefined field0_0x0;
};

typedef struct SChallengeList_Info SChallengeList_Info, *PSChallengeList_Info;

struct SChallengeList_Info {
    undefined field0_0x0;
};

typedef struct CGameControlGridCtnChallengeGroup CGameControlGridCtnChallengeGroup, *PCGameControlGridCtnChallengeGroup;

struct CGameControlGridCtnChallengeGroup {
    undefined field0_0x0;
};

typedef struct CImpressionCollector CImpressionCollector, *PCImpressionCollector;

struct CImpressionCollector {
    undefined field0_0x0;
};

typedef struct SCharStyle SCharStyle, *PSCharStyle;

struct SCharStyle {
    undefined field0_0x0;
};

typedef struct CFastStringIntList CFastStringIntList, *PCFastStringIntList;

struct CFastStringIntList {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugSurface>_> CFastBuffer<class_CMwNodRef<class_CPlugSurface>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugSurface>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugSurface>_> {
    undefined field0_0x0;
};

typedef struct SPlugVisibleFilter SPlugVisibleFilter, *PSPlugVisibleFilter;

struct SPlugVisibleFilter {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsViewport::SClippingFrustum> CFastBuffer<struct_CHmsViewport::SClippingFrustum>, *PCFastBuffer<struct_CHmsViewport::SClippingFrustum>;

struct CFastBuffer<struct_CHmsViewport::SClippingFrustum> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameBuddy::SCampaignMedals> CFastBuffer<struct_CGameBuddy::SCampaignMedals>, *PCFastBuffer<struct_CGameBuddy::SCampaignMedals>;

struct CFastBuffer<struct_CGameBuddy::SCampaignMedals> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSolid SMwParamInfos_CPlugSolid, *PSMwParamInfos_CPlugSolid;

struct SMwParamInfos_CPlugSolid {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SPlugGpuParamSkipSampler> CFastArray<struct_SPlugGpuParamSkipSampler>, *PCFastArray<struct_SPlugGpuParamSkipSampler>;

struct CFastArray<struct_SPlugGpuParamSkipSampler> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameManialinkFileEntry SMwParamInfos_CGameManialinkFileEntry, *PSMwParamInfos_CGameManialinkFileEntry;

struct SMwParamInfos_CGameManialinkFileEntry {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyBird SMwParamInfos_CSceneToyBird, *PSMwParamInfos_CSceneToyBird;

struct SMwParamInfos_CSceneToyBird {
    undefined field0_0x0;
};

typedef struct SVisualHandler SVisualHandler, *PSVisualHandler;

struct SVisualHandler {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneTrafficGraph::SEdge> CFastBuffer<struct_CSceneTrafficGraph::SEdge>, *PCFastBuffer<struct_CSceneTrafficGraph::SEdge>;

struct CFastBuffer<struct_CSceneTrafficGraph::SEdge> {
    undefined field0_0x0;
};

typedef struct CInputPortDx8 CInputPortDx8, *PCInputPortDx8;

struct CInputPortDx8 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicle::SVisualWheel> CFastBuffer<struct_CSceneVehicle::SVisualWheel>, *PCFastBuffer<struct_CSceneVehicle::SVisualWheel>;

struct CFastBuffer<struct_CSceneVehicle::SVisualWheel> {
    undefined field0_0x0;
};

typedef struct SHeader SHeader, *PSHeader;

struct SHeader {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCalendarEvent> CMwNodRef<class_CGameCalendarEvent>, *PCMwNodRef<class_CGameCalendarEvent>;

struct CMwNodRef<class_CGameCalendarEvent> {
    undefined field0_0x0;
};

typedef struct SAddTreeS SAddTreeS, *PSAddTreeS;

struct SAddTreeS {
    undefined field0_0x0;
};

typedef struct SDeviceMat SDeviceMat, *PSDeviceMat;

struct SDeviceMat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyDisplayProgress SMwParamInfos_CSceneToyDisplayProgress, *PSMwParamInfos_CSceneToyDisplayProgress;

struct SMwParamInfos_CSceneToyDisplayProgress {
    undefined field0_0x0;
};

typedef struct CHdrUnknown CHdrUnknown, *PCHdrUnknown;

struct CHdrUnknown {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod>, *PCFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod>;

struct CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> {
    undefined field0_0x0;
};

typedef struct SNationConfig SNationConfig, *PSNationConfig;

struct SNationConfig {
    undefined field0_0x0;
};

typedef struct CMotionBone CMotionBone, *PCMotionBone;

struct CMotionBone {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugShaderPass*> CFastArray<class_CPlugShaderPass*>, *PCFastArray<class_CPlugShaderPass*>;

struct CFastArray<class_CPlugShaderPass*> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameControlCamera>_> CFastBuffer<class_CMwNodRef<class_CGameControlCamera>_>, *PCFastBuffer<class_CMwNodRef<class_CGameControlCamera>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameControlCamera>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlTimeLine2::STrack::SBlock> CFastBuffer<struct_CControlTimeLine2::STrack::SBlock>, *PCFastBuffer<struct_CControlTimeLine2::STrack::SBlock>;

struct CFastBuffer<struct_CControlTimeLine2::STrack::SBlock> {
    undefined field0_0x0;
};

typedef struct STrackManiaContext STrackManiaContext, *PSTrackManiaContext;

struct STrackManiaContext {
    undefined field0_0x0;
};

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    uint VirtualAddress;
    uint Size;
};

typedef struct SAutoBalancedSound SAutoBalancedSound, *PSAutoBalancedSound;

struct SAutoBalancedSound {
    undefined field0_0x0;
};

typedef struct CMwCmdScript CMwCmdScript, *PCMwCmdScript;

struct CMwCmdScript {
    undefined field0_0x0;
};

typedef struct SField18 SField18, *PSField18;

struct SField18 {
    undefined field0_0x0;
};

typedef struct SLoadResourceTreeRecur SLoadResourceTreeRecur, *PSLoadResourceTreeRecur;

struct SLoadResourceTreeRecur {
    undefined field0_0x0;
};

typedef struct HWINSTA__ HWINSTA__, *PHWINSTA__;

struct HWINSTA__ {
    int unused;
};

typedef struct SDisplayParams SDisplayParams, *PSDisplayParams;

struct SDisplayParams {
    undefined field0_0x0;
};

typedef struct CPlugVisualHeightField CPlugVisualHeightField, *PCPlugVisualHeightField;

struct CPlugVisualHeightField {
    undefined field0_0x0;
};

typedef struct CSceneFxNod CSceneFxNod, *PCSceneFxNod;

struct CSceneFxNod {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnCampaign> CMwNodRef<class_CGameCtnCampaign>, *PCMwNodRef<class_CGameCtnCampaign>;

struct CMwNodRef<class_CGameCtnCampaign> {
    undefined field0_0x0;
};

typedef struct SSplitCell SSplitCell, *PSSplitCell;

struct SSplitCell {
    undefined field0_0x0;
};

typedef enum EEditorType {
} EEditorType;

typedef struct CFastBuffer<struct_CHmsDyna::SHistoryPoint> CFastBuffer<struct_CHmsDyna::SHistoryPoint>, *PCFastBuffer<struct_CHmsDyna::SHistoryPoint>;

struct CFastBuffer<struct_CHmsDyna::SHistoryPoint> {
    undefined field0_0x0;
};

typedef struct SSoloChallengePool SSoloChallengePool, *PSSoloChallengePool;

struct SSoloChallengePool {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringFunction CMwCmdExpStringFunction, *PCMwCmdExpStringFunction;

struct CMwCmdExpStringFunction {
    undefined field0_0x0;
};

typedef struct CGameCtnGhost CGameCtnGhost, *PCGameCtnGhost;

struct CGameCtnGhost {
    undefined field0_0x0;
};

typedef struct SFuncCache SFuncCache, *PSFuncCache;

struct SFuncCache {
    undefined field0_0x0;
};

typedef struct CGameCtnLoadProgress CGameCtnLoadProgress, *PCGameCtnLoadProgress;

struct CGameCtnLoadProgress {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFuncKeysTrans::SParametrizationPoint> CFastBuffer<struct_CFuncKeysTrans::SParametrizationPoint>, *PCFastBuffer<struct_CFuncKeysTrans::SParametrizationPoint>;

struct CFastBuffer<struct_CFuncKeysTrans::SParametrizationPoint> {
    undefined field0_0x0;
};

typedef struct CPlugCrystal CPlugCrystal, *PCPlugCrystal;

struct CPlugCrystal {
    undefined field0_0x0;
};

typedef struct SFlagsOld3To7 SFlagsOld3To7, *PSFlagsOld3To7;

struct SFlagsOld3To7 {
    undefined field0_0x0;
};

typedef struct SRegisterUsage SRegisterUsage, *PSRegisterUsage;

struct SRegisterUsage {
    undefined field0_0x0;
};

typedef struct CNetHttpResult CNetHttpResult, *PCNetHttpResult;

struct CNetHttpResult {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderSub CPlugBitmapRenderSub, *PCPlugBitmapRenderSub;

struct CPlugBitmapRenderSub {
    undefined field0_0x0;
};

typedef struct CAudioPortNull CAudioPortNull, *PCAudioPortNull;

struct CAudioPortNull {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetPlayerInfo SMwParamInfos_CGameNetPlayerInfo, *PSMwParamInfos_CGameNetPlayerInfo;

struct SMwParamInfos_CGameNetPlayerInfo {
    undefined field0_0x0;
};

typedef struct CMwEngine CMwEngine, *PCMwEngine;

struct CMwEngine {
    undefined field0_0x0;
};

typedef struct CAudioSoundEngine_Mixer_Implem<int,2> CAudioSoundEngine_Mixer_Implem<int,2>, *PCAudioSoundEngine_Mixer_Implem<int,2>;

struct CAudioSoundEngine_Mixer_Implem<int,2> {
    undefined field0_0x0;
};

typedef struct CPlugVisual3D CPlugVisual3D, *PCPlugVisual3D;

struct CPlugVisual3D {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmVec3,struct_CSceneFxSuperSample::SMultiLight> CFastBufferCat<class_GmVec3,struct_CSceneFxSuperSample::SMultiLight>, *PCFastBufferCat<class_GmVec3,struct_CSceneFxSuperSample::SMultiLight>;

struct CFastBufferCat<class_GmVec3,struct_CSceneFxSuperSample::SMultiLight> {
    undefined field0_0x0;
};

typedef struct CGameNetFormBuddy CGameNetFormBuddy, *PCGameNetFormBuddy;

struct CGameNetFormBuddy {
    undefined field0_0x0;
};

typedef struct SLetter SLetter, *PSLetter;

struct SLetter {
    undefined field0_0x0;
};

typedef struct CMwCmdExpSub CMwCmdExpSub, *PCMwCmdExpSub;

struct CMwCmdExpSub {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamVec2> CMwParamFastBufferCat<class_CMwParamVec2>, *PCMwParamFastBufferCat<class_CMwParamVec2>;

struct CMwParamFastBufferCat<class_CMwParamVec2> {
    undefined field0_0x0;
};

typedef struct bad_cast bad_cast, *Pbad_cast;

struct bad_cast {
    undefined field0_0x0;
};

typedef enum EIp {
} EIp;

typedef struct SMwParamInfos_GxLightSpot SMwParamInfos_GxLightSpot, *PSMwParamInfos_GxLightSpot;

struct SMwParamInfos_GxLightSpot {
    undefined field0_0x0;
};

typedef struct CMwCmdExpSup CMwCmdExpSup, *PCMwCmdExpSup;

struct CMwCmdExpSup {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CGameMenuFrame*> CFastArray<class_CGameMenuFrame*>, *PCFastArray<class_CGameMenuFrame*>;

struct CFastArray<class_CGameMenuFrame*> {
    undefined field0_0x0;
};

typedef struct CGameCtnZoneTest CGameCtnZoneTest, *PCGameCtnZoneTest;

struct CGameCtnZoneTest {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamIso4> CMwParamFastBufferCat<class_CMwParamIso4>, *PCMwParamFastBufferCat<class_CMwParamIso4>;

struct CMwParamFastBufferCat<class_CMwParamIso4> {
    undefined field0_0x0;
};

typedef struct SRpcSkinInfo SRpcSkinInfo, *PSRpcSkinInfo;

struct SRpcSkinInfo {
    undefined field0_0x0;
};

typedef enum EDisplayMode {
} EDisplayMode;

typedef struct CMwClassInfoCGameCtnMediaBlockTriangles CMwClassInfoCGameCtnMediaBlockTriangles, *PCMwClassInfoCGameCtnMediaBlockTriangles;

struct CMwClassInfoCGameCtnMediaBlockTriangles {
    undefined field0_0x0;
};

typedef struct _D3DXSEMANTIC _D3DXSEMANTIC, *P_D3DXSEMANTIC;

struct _D3DXSEMANTIC {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncKeysPath SMwParamInfos_CFuncKeysPath, *PSMwParamInfos_CFuncKeysPath;

struct SMwParamInfos_CFuncKeysPath {
    undefined field0_0x0;
};

typedef struct codecvt_base codecvt_base, *Pcodecvt_base;

struct codecvt_base {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamStringInt> CMwParamFastBuffer<class_CMwParamStringInt>, *PCMwParamFastBuffer<class_CMwParamStringInt>;

struct CMwParamFastBuffer<class_CMwParamStringInt> {
    undefined field0_0x0;
};

typedef struct SPolyGroup SPolyGroup, *PSPolyGroup;

struct SPolyGroup {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CControlEffectSimi::SKeyVal> CFastBufferKey<struct_CControlEffectSimi::SKeyVal>, *PCFastBufferKey<struct_CControlEffectSimi::SKeyVal>;

struct CFastBufferKey<struct_CControlEffectSimi::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CGameInterface CGameInterface, *PCGameInterface;

struct CGameInterface {
    undefined field0_0x0;
};

typedef enum EPlugVDclTexCoord {
} EPlugVDclTexCoord;

typedef struct SHmsPackLightMapCacheId SHmsPackLightMapCacheId, *PSHmsPackLightMapCacheId;

struct SHmsPackLightMapCacheId {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CControlStyle> CMwNodRef<class_CControlStyle>, *PCMwNodRef<class_CControlStyle>;

struct CMwNodRef<class_CControlStyle> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CHmsShadowGroup*> CFastArray<class_CHmsShadowGroup*>, *PCFastArray<class_CHmsShadowGroup*>;

struct CFastArray<class_CHmsShadowGroup*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneToyBoat::STeamMate> CFastBuffer<struct_CSceneToyBoat::STeamMate>, *PCFastBuffer<struct_CSceneToyBoat::STeamMate>;

struct CFastBuffer<struct_CSceneToyBoat::STeamMate> {
    undefined field0_0x0;
};

typedef struct CReadCallback CReadCallback, *PCReadCallback;

struct CReadCallback {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentClass CMwCmdAffectIdentClass, *PCMwCmdAffectIdentClass;

struct CMwCmdAffectIdentClass {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameAdvertisingNadeo::SImpression> CFastBuffer<struct_CGameAdvertisingNadeo::SImpression>, *PCFastBuffer<struct_CGameAdvertisingNadeo::SImpression>;

struct CFastBuffer<struct_CGameAdvertisingNadeo::SImpression> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderOverlay SMwParamInfos_CPlugBitmapRenderOverlay, *PSMwParamInfos_CPlugBitmapRenderOverlay;

struct SMwParamInfos_CPlugBitmapRenderOverlay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScript SMwParamInfos_CMwCmdScript, *PSMwParamInfos_CMwCmdScript;

struct SMwParamInfos_CMwCmdScript {
    undefined field0_0x0;
};

typedef struct SShadowCameraInter SShadowCameraInter, *PSShadowCameraInter;

struct SShadowCameraInter {
    undefined field0_0x0;
};

typedef struct CFastStringList CFastStringList, *PCFastStringList;

struct CFastStringList {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetOnlineEvent SMwParamInfos_CGameNetOnlineEvent, *PSMwParamInfos_CGameNetOnlineEvent;

struct SMwParamInfos_CGameNetOnlineEvent {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemFidsFolder SMwParamInfos_CSystemFidsFolder, *PSMwParamInfos_CSystemFidsFolder;

struct SMwParamInfos_CSystemFidsFolder {
    undefined field0_0x0;
};

typedef struct CGamePlayerScoresShooter CGamePlayerScoresShooter, *PCGamePlayerScoresShooter;

struct CGamePlayerScoresShooter {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastArray<struct_SCustomGpuFxOld>,2,unsigned_long> CFixedArray<class_CFastArray<struct_SCustomGpuFxOld>,2,unsigned_long>, *PCFixedArray<class_CFastArray<struct_SCustomGpuFxOld>,2,unsigned_long>;

struct CFixedArray<class_CFastArray<struct_SCustomGpuFxOld>,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SSkinInfo SSkinInfo, *PSSkinInfo;

struct SSkinInfo {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaTrackerContext CGameCtnMediaTrackerContext, *PCGameCtnMediaTrackerContext;

struct CGameCtnMediaTrackerContext {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameNetManialinkPage> CMwNodRef<class_CGameNetManialinkPage>, *PCMwNodRef<class_CGameNetManialinkPage>;

struct CMwNodRef<class_CGameNetManialinkPage> {
    undefined field0_0x0;
};

typedef struct CAudioSoundMulti CAudioSoundMulti, *PCAudioSoundMulti;

struct CAudioSoundMulti {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameApp SMwParamInfos_CGameApp, *PSMwParamInfos_CGameApp;

struct SMwParamInfos_CGameApp {
    undefined field0_0x0;
};

typedef struct CLoaderFidContainer CLoaderFidContainer, *PCLoaderFidContainer;

struct CLoaderFidContainer {
    undefined field0_0x0;
};

typedef struct CFastStringForArray CFastStringForArray, *PCFastStringForArray;

struct CFastStringForArray {
    undefined field0_0x0;
};

typedef struct SPlayerMobilInstance_1 SPlayerMobilInstance_1, *PSPlayerMobilInstance_1;

struct SPlayerMobilInstance_1 {
    undefined field0_0x0;
};

typedef struct id id, *Pid;

struct id {
    undefined field0_0x0;
};

typedef struct CPlugSoundSurface CPlugSoundSurface, *PCPlugSoundSurface;

struct CPlugSoundSurface {
    undefined field0_0x0;
};

typedef struct SFilterInfos SFilterInfos, *PSFilterInfos;

struct SFilterInfos {
    undefined field0_0x0;
};

typedef struct CPlugSurfaceGeom CPlugSurfaceGeom, *PCPlugSurfaceGeom;

struct CPlugSurfaceGeom {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToySeaHouleTable SMwParamInfos_CSceneToySeaHouleTable, *PSMwParamInfos_CSceneToySeaHouleTable;

struct SMwParamInfos_CSceneToySeaHouleTable {
    undefined field0_0x0;
};

typedef struct CSceneToySeaHouleFixe CSceneToySeaHouleFixe, *PCSceneToySeaHouleFixe;

struct CSceneToySeaHouleFixe {
    undefined field0_0x0;
};

typedef struct CGameCtnCampaign CGameCtnCampaign, *PCGameCtnCampaign;

struct CGameCtnCampaign {
    undefined field0_0x0;
};

typedef struct CFuncCurvesReal CFuncCurvesReal, *PCFuncCurvesReal;

struct CFuncCurvesReal {
    undefined field0_0x0;
};

typedef struct CPlugShaderPass CPlugShaderPass, *PCPlugShaderPass;

struct CPlugShaderPass {
    undefined field0_0x0;
};

typedef struct CPlugMusic CPlugMusic, *PCPlugMusic;

struct CPlugMusic {
    undefined field0_0x0;
};

typedef struct CSystemCmdExec CSystemCmdExec, *PCSystemCmdExec;

struct CSystemCmdExec {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlCurve SMwParamInfos_CControlCurve, *PSMwParamInfos_CControlCurve;

struct SMwParamInfos_CControlCurve {
    undefined field0_0x0;
};

typedef struct CPlugTree CPlugTree, *PCPlugTree;

struct CPlugTree {
    undefined field0_0x0;
};

typedef struct out_of_range out_of_range, *Pout_of_range;

struct out_of_range {
    undefined field0_0x0;
};

typedef struct SSetting SSetting, *PSSetting;

struct SSetting {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlScores2 CTrackManiaControlScores2, *PCTrackManiaControlScores2;

struct CTrackManiaControlScores2 {
    undefined field0_0x0;
};

typedef struct CSceneVehicleSpeedBoatTuning CSceneVehicleSpeedBoatTuning, *PCSceneVehicleSpeedBoatTuning;

struct CSceneVehicleSpeedBoatTuning {
    undefined field0_0x0;
};

typedef struct SLevelDesc SLevelDesc, *PSLevelDesc;

struct SLevelDesc {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderLightFromMap CPlugBitmapRenderLightFromMap, *PCPlugBitmapRenderLightFromMap;

struct CPlugBitmapRenderLightFromMap {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNod*> CFastBuffer<class_CMwNod*>, *PCFastBuffer<class_CMwNod*>;

struct CFastBuffer<class_CMwNod*> {
    undefined field0_0x0;
};

typedef struct CHmsLight CHmsLight, *PCHmsLight;

struct CHmsLight {
    undefined field0_0x0;
};

typedef struct NvStripStartInfo NvStripStartInfo, *PNvStripStartInfo;

struct NvStripStartInfo {
    undefined field0_0x0;
};

typedef struct CHmsPackLightMapCache CHmsPackLightMapCache, *PCHmsPackLightMapCache;

struct CHmsPackLightMapCache {
    undefined field0_0x0;
};

typedef struct CMotionDayTime CMotionDayTime, *PCMotionDayTime;

struct CMotionDayTime {
    undefined field0_0x0;
};

typedef struct SRenderTarget SRenderTarget, *PSRenderTarget;

struct SRenderTarget {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsForceFieldBall SMwParamInfos_CHmsForceFieldBall, *PSMwParamInfos_CHmsForceFieldBall;

struct SMwParamInfos_CHmsForceFieldBall {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CSceneMobil> CFastBufferRef<class_CSceneMobil>, *PCFastBufferRef<class_CSceneMobil>;

struct CFastBufferRef<class_CSceneMobil> {
    undefined field0_0x0;
};

typedef struct SOldIgs SOldIgs, *PSOldIgs;

struct SOldIgs {
    undefined field0_0x0;
};

typedef struct SContextShader SContextShader, *PSContextShader;

struct SContextShader {
    undefined field0_0x0;
};

typedef struct CGameControlCameraEffectAdaptativeNearZ CGameControlCameraEffectAdaptativeNearZ, *PCGameControlCameraEffectAdaptativeNearZ;

struct CGameControlCameraEffectAdaptativeNearZ {
    undefined field0_0x0;
};

typedef struct CFastMapTable<unsigned_long> CFastMapTable<unsigned_long>, *PCFastMapTable<unsigned_long>;

struct CFastMapTable<unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<class_CPlugFileJpg*,class_CClassicBuffer&,int> CFastCallback3P<class_CPlugFileJpg*,class_CClassicBuffer&,int>, *PCFastCallback3P<class_CPlugFileJpg*,class_CClassicBuffer&,int>;

struct CFastCallback3P<class_CPlugFileJpg*,class_CClassicBuffer&,int> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackMania SMwParamInfos_CTrackMania, *PSMwParamInfos_CTrackMania;

struct SMwParamInfos_CTrackMania {
    undefined field0_0x0;
};

typedef struct CSceneToyStem CSceneToyStem, *PCSceneToyStem;

struct CSceneToyStem {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink> CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink>, *PCFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink>;

struct CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncClouds SMwParamInfos_CFuncClouds, *PSMwParamInfos_CFuncClouds;

struct SMwParamInfos_CFuncClouds {
    undefined field0_0x0;
};

typedef struct SMeshMeshCollide SMeshMeshCollide, *PSMeshMeshCollide;

struct SMeshMeshCollide {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorTerrain CTrackManiaEditorTerrain, *PCTrackManiaEditorTerrain;

struct CTrackManiaEditorTerrain {
    undefined field0_0x0;
};

typedef struct SObjReader SObjReader, *PSObjReader;

struct SObjReader {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<class_CGameMasterServerRequest*&,class_CGameMasterServerRequestParams_const*,enum_ESendRequestResult&> CFastCallback3P<class_CGameMasterServerRequest*&,class_CGameMasterServerRequestParams_const*,enum_ESendRequestResult&>, *PCFastCallback3P<class_CGameMasterServerRequest*&,class_CGameMasterServerRequestParams_const*,enum_ESendRequestResult&>;

struct CFastCallback3P<class_CGameMasterServerRequest*&,class_CGameMasterServerRequestParams_const*,enum_ESendRequestResult&> {
    undefined field0_0x0;
};

typedef struct SBitmap SBitmap, *PSBitmap;

struct SBitmap {
    undefined field0_0x0;
};

typedef struct SPair SPair, *PSPair;

struct SPair {
    undefined field0_0x0;
};

typedef struct CFastStringIntForArray CFastStringIntForArray, *PCFastStringIntForArray;

struct CFastStringIntForArray {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockCameraPath CGameCtnMediaBlockCameraPath, *PCGameCtnMediaBlockCameraPath;

struct CGameCtnMediaBlockCameraPath {
    undefined field0_0x0;
};

typedef struct CMwTimerAdapter CMwTimerAdapter, *PCMwTimerAdapter;

struct CMwTimerAdapter {
    undefined field0_0x0;
};

typedef struct CUrlLinks CUrlLinks, *PCUrlLinks;

struct CUrlLinks {
    undefined field0_0x0;
};

typedef struct CMwEngineInfo CMwEngineInfo, *PCMwEngineInfo;

struct CMwEngineInfo {
    undefined field0_0x0;
};

typedef enum EDx9Vendor {
} EDx9Vendor;

typedef struct vector<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_> vector<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_>, *Pvector<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_>;

struct vector<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_> {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorCatalog CTrackManiaEditorCatalog, *PCTrackManiaEditorCatalog;

struct CTrackManiaEditorCatalog {
    undefined field0_0x0;
};

typedef struct IUnknownVtbl IUnknownVtbl, *PIUnknownVtbl;

typedef struct IUnknown IUnknown, *PIUnknown;

struct IUnknownVtbl {
    long (*QueryInterface)(struct IUnknown *, struct _GUID *, void **);
    ulong (*AddRef)(struct IUnknown *);
    ulong (*Release)(struct IUnknown *);
};

struct IUnknown {
    struct IUnknownVtbl *lpVtbl;
};

typedef struct CBlendedSolidSkelValue CBlendedSolidSkelValue, *PCBlendedSolidSkelValue;

struct CBlendedSolidSkelValue {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameMobil>_> CFastBuffer<class_CMwNodRef<class_CGameMobil>_>, *PCFastBuffer<class_CMwNodRef<class_CGameMobil>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameMobil>_> {
    undefined field0_0x0;
};

typedef struct SMotoState SMotoState, *PSMotoState;

struct SMotoState {
    undefined field0_0x0;
};

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

typedef struct CGameControlEdit CGameControlEdit, *PCGameControlEdit;

struct CGameControlEdit {
    undefined field0_0x0;
};

typedef struct CFastArray<enum_CTrackManiaEditorTerrain::EUpdate> CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>, *PCFastArray<enum_CTrackManiaEditorTerrain::EUpdate>;

struct CFastArray<enum_CTrackManiaEditorTerrain::EUpdate> {
    undefined field0_0x0;
};

typedef struct CTrackManiaNetworkServerInfo CTrackManiaNetworkServerInfo, *PCTrackManiaNetworkServerInfo;

struct CTrackManiaNetworkServerInfo {
    undefined field0_0x0;
};

typedef struct CSystemPackManager CSystemPackManager, *PCSystemPackManager;

struct CSystemPackManager {
    undefined field0_0x0;
};

typedef struct _xmlrpc_env _xmlrpc_env, *P_xmlrpc_env;

struct _xmlrpc_env {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameGeneralScores::SFilteredScoresInfos*> CFastBuffer<struct_CGameGeneralScores::SFilteredScoresInfos*>, *PCFastBuffer<struct_CGameGeneralScores::SFilteredScoresInfos*>;

struct CFastBuffer<struct_CGameGeneralScores::SFilteredScoresInfos*> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlock3dStereo CMwClassInfoCGameCtnMediaBlock3dStereo, *PCMwClassInfoCGameCtnMediaBlock3dStereo;

struct CMwClassInfoCGameCtnMediaBlock3dStereo {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CFuncKeysReal> CMwNodRef<class_CFuncKeysReal>, *PCMwNodRef<class_CFuncKeysReal>;

struct CMwNodRef<class_CFuncKeysReal> {
    undefined field0_0x0;
};

typedef struct failure failure, *Pfailure;

struct failure {
    undefined field0_0x0;
};

typedef enum EShadowCaster {
} EShadowCaster;

typedef struct CFastArray<struct_CDx9StateBlock::SRenderState> CFastArray<struct_CDx9StateBlock::SRenderState>, *PCFastArray<struct_CDx9StateBlock::SRenderState>;

struct CFastArray<struct_CDx9StateBlock::SRenderState> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameControlDataType> CFastBufferRef<class_CGameControlDataType>, *PCFastBufferRef<class_CGameControlDataType>;

struct CFastBufferRef<class_CGameControlDataType> {
    undefined field0_0x0;
};

typedef struct SPlayerScoreToValidate SPlayerScoreToValidate, *PSPlayerScoreToValidate;

struct SPlayerScoreToValidate {
    undefined field0_0x0;
};

typedef struct CControlGrid CControlGrid, *PCControlGrid;

struct CControlGrid {
    undefined field0_0x0;
};

typedef struct CFuncShaders CFuncShaders, *PCFuncShaders;

struct CFuncShaders {
    undefined field0_0x0;
};

typedef struct CRecordsBuffer CRecordsBuffer, *PCRecordsBuffer;

struct CRecordsBuffer {
    undefined field0_0x0;
};

typedef struct CGameSkin CGameSkin, *PCGameSkin;

struct CGameSkin {
    undefined field0_0x0;
};

typedef struct SSceneMoods_Mood SSceneMoods_Mood, *PSSceneMoods_Mood;

struct SSceneMoods_Mood {
    undefined field0_0x0;
};

typedef struct CFixedArray<char_const*,14,unsigned_long> CFixedArray<char_const*,14,unsigned_long>, *PCFixedArray<char_const*,14,unsigned_long>;

struct CFixedArray<char_const*,14,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugFileBink CPlugFileBink, *PCPlugFileBink;

struct CPlugFileBink {
    undefined field0_0x0;
};

typedef struct CBoatTeamActionDesc CBoatTeamActionDesc, *PCBoatTeamActionDesc;

struct CBoatTeamActionDesc {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamNatural> CMwParamFastBufferCat<class_CMwParamNatural>, *PCMwParamFastBufferCat<class_CMwParamNatural>;

struct CMwParamFastBufferCat<class_CMwParamNatural> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnMediaBlock> CMwNodRef<class_CGameCtnMediaBlock>, *PCMwNodRef<class_CGameCtnMediaBlock>;

struct CMwNodRef<class_CGameCtnMediaBlock> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsItemShadow SMwParamInfos_CHmsItemShadow, *PSMwParamInfos_CHmsItemShadow;

struct SMwParamInfos_CHmsItemShadow {
    undefined field0_0x0;
};

typedef enum EVolatileTreeType {
} EVolatileTreeType;

typedef struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>::SKey> CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>::SKey>, *PCFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>::SKey> {
    undefined field0_0x0;
};

typedef struct GmInt3 GmInt3, *PGmInt3;

struct GmInt3 {
    undefined field0_0x0;
};

typedef struct GmInt4 GmInt4, *PGmInt4;

struct GmInt4 {
    undefined field0_0x0;
};

typedef struct GmInt2 GmInt2, *PGmInt2;

struct GmInt2 {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_SOldKeyVal> CFastBufferKey<struct_SOldKeyVal>, *PCFastBufferKey<struct_SOldKeyVal>;

struct CFastBufferKey<struct_SOldKeyVal> {
    undefined field0_0x0;
};

typedef struct CPlugFont CPlugFont, *PCPlugFont;

struct CPlugFont {
    undefined field0_0x0;
};

typedef struct GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>, *PGmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel>;

struct GmLooseOctree<struct_SHmsVPackerObject,class_CHmsVPackerCell,class_CHmsVPackerLevel> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSystemFidParameters::SParam*> CFastBuffer<struct_CSystemFidParameters::SParam*>, *PCFastBuffer<struct_CSystemFidParameters::SParam*>;

struct CFastBuffer<struct_CSystemFidParameters::SParam*> {
    undefined field0_0x0;
};

typedef struct SQuickSaveContext SQuickSaveContext, *PSQuickSaveContext;

struct SQuickSaveContext {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlGrid SMwParamInfos_CGameControlGrid, *PSMwParamInfos_CGameControlGrid;

struct SMwParamInfos_CGameControlGrid {
    undefined field0_0x0;
};

typedef struct GxLightSpot GxLightSpot, *PGxLightSpot;

struct GxLightSpot {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxFlags CPlugMaterialFxFlags, *PCPlugMaterialFxFlags;

struct CPlugMaterialFxFlags {
    undefined field0_0x0;
};

typedef struct TiXmlDocument TiXmlDocument, *PTiXmlDocument;

struct TiXmlDocument {
    undefined field0_0x0;
};

typedef struct SLocationAlloc SLocationAlloc, *PSLocationAlloc;

struct SLocationAlloc {
    undefined field0_0x0;
};

typedef struct CControlMediaItem CControlMediaItem, *PCControlMediaItem;

struct CControlMediaItem {
    undefined field0_0x0;
};

typedef enum EVIBProcess {
} EVIBProcess;

typedef struct type_info type_info, *Ptype_info;

struct type_info {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringIdent CMwCmdExpStringIdent, *PCMwCmdExpStringIdent;

struct CMwCmdExpStringIdent {
    undefined field0_0x0;
};

typedef struct SOutput SOutput, *PSOutput;

struct SOutput {
    undefined field0_0x0;
};

typedef struct CSceneMobilFlockAttractor CSceneMobilFlockAttractor, *PCSceneMobilFlockAttractor;

struct CSceneMobilFlockAttractor {
    undefined field0_0x0;
};

typedef struct SSwitch SSwitch, *PSSwitch;

struct SSwitch {
    undefined field0_0x0;
};

typedef struct SInputPortDx8_FFEffect SInputPortDx8_FFEffect, *PSInputPortDx8_FFEffect;

struct SInputPortDx8_FFEffect {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwClassInfo_const*> CFastBuffer<class_CMwClassInfo_const*>, *PCFastBuffer<class_CMwClassInfo_const*>;

struct CFastBuffer<class_CMwClassInfo_const*> {
    undefined field0_0x0;
};

typedef enum ERenderDelayedSort {
} ERenderDelayedSort;

typedef struct CFastBuffer<class_GmIso3> CFastBuffer<class_GmIso3>, *PCFastBuffer<class_GmIso3>;

struct CFastBuffer<class_GmIso3> {
    undefined field0_0x0;
};

typedef struct CClassicArchive CClassicArchive, *PCClassicArchive;

struct CClassicArchive {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFxBlurMotion CGameCtnMediaBlockFxBlurMotion, *PCGameCtnMediaBlockFxBlurMotion;

struct CGameCtnMediaBlockFxBlurMotion {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CSystemDataFolders::SBrowse> CFastArray<struct_CSystemDataFolders::SBrowse>, *PCFastArray<struct_CSystemDataFolders::SBrowse>;

struct CFastArray<struct_CSystemDataFolders::SBrowse> {
    undefined field0_0x0;
};

typedef struct CBoatSail CBoatSail, *PCBoatSail;

struct CBoatSail {
    undefined field0_0x0;
};

typedef struct SKerning SKerning, *PSKerning;

struct SKerning {
    undefined field0_0x0;
};

typedef struct CMotionPlayer CMotionPlayer, *PCMotionPlayer;

struct CMotionPlayer {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderScene3d CPlugBitmapRenderScene3d, *PCPlugBitmapRenderScene3d;

struct CPlugBitmapRenderScene3d {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CSceneToySea::SThreadInfo> CFastArray<struct_CSceneToySea::SThreadInfo>, *PCFastArray<struct_CSceneToySea::SThreadInfo>;

struct CFastArray<struct_CSceneToySea::SThreadInfo> {
    undefined field0_0x0;
};

typedef struct GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b> GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>, *PGmOctreeLowMem<struct_GmOctreeLowMemCell_i31b>;

struct GmOctreeLowMem<struct_GmOctreeLowMemCell_i31b> {
    undefined field0_0x0;
};

typedef struct CSceneFxDepthOfField CSceneFxDepthOfField, *PCSceneFxDepthOfField;

struct CSceneFxDepthOfField {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRace SMwParamInfos_CTrackManiaRace, *PSMwParamInfos_CTrackManiaRace;

struct SMwParamInfos_CTrackManiaRace {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockEvent CGameCtnMediaBlockEvent, *PCGameCtnMediaBlockEvent;

struct CGameCtnMediaBlockEvent {
    undefined field0_0x0;
};

typedef struct CGameCtnChallenge CGameCtnChallenge, *PCGameCtnChallenge;

struct CGameCtnChallenge {
    undefined field0_0x0;
};

typedef struct CGameControlRotate CGameControlRotate, *PCGameControlRotate;

struct CGameControlRotate {
    undefined field0_0x0;
};

typedef struct CAudioSoundEngine_Mixer_Implem<int,6> CAudioSoundEngine_Mixer_Implem<int,6>, *PCAudioSoundEngine_Mixer_Implem<int,6>;

struct CAudioSoundEngine_Mixer_Implem<int,6> {
    undefined field0_0x0;
};

typedef struct CClassicCrypto_RSA CClassicCrypto_RSA, *PCClassicCrypto_RSA;

struct CClassicCrypto_RSA {
    undefined field0_0x0;
};

typedef struct SSamplerState SSamplerState, *PSSamplerState;

struct SSamplerState {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnReplayRecordInfo CGameControlCardCtnReplayRecordInfo, *PCGameControlCardCtnReplayRecordInfo;

struct CGameControlCardCtnReplayRecordInfo {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraEffectShake CMwClassInfoCGameCtnMediaBlockCameraEffectShake, *PCMwClassInfoCGameCtnMediaBlockCameraEffectShake;

struct CMwClassInfoCGameCtnMediaBlockCameraEffectShake {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>, *PCFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData>;

struct CFastBuffer<struct_CTrackManiaNetwork::SReplayToValidateData> {
    undefined field0_0x0;
};

typedef struct SNetStateSendingInfo SNetStateSendingInfo, *PSNetStateSendingInfo;

struct SNetStateSendingInfo {
    undefined field0_0x0;
};

typedef struct HMENU__ HMENU__, *PHMENU__;

struct HMENU__ {
    int unused;
};

typedef struct _LocaleUpdate _LocaleUpdate, *P_LocaleUpdate;

struct _LocaleUpdate {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagRGBQUAD - /wingdi.h/tagRGBQUAD */

typedef struct CTrackManiaControlRaceScoreCard CTrackManiaControlRaceScoreCard, *PCTrackManiaControlRaceScoreCard;

struct CTrackManiaControlRaceScoreCard {
    undefined field0_0x0;
};

typedef struct TiXmlComment TiXmlComment, *PTiXmlComment;

struct TiXmlComment {
    undefined field0_0x0;
};

typedef struct CImplem CImplem, *PCImplem;

struct CImplem {
    undefined field0_0x0;
};

typedef struct CMwCmdExpIso4Mult CMwCmdExpIso4Mult, *PCMwCmdExpIso4Mult;

struct CMwCmdExpIso4Mult {
    undefined field0_0x0;
};

typedef enum EEditMode {
} EEditMode;

typedef struct SMwParamInfos_CGameRemoteBufferDataInfoFinds SMwParamInfos_CGameRemoteBufferDataInfoFinds, *PSMwParamInfos_CGameRemoteBufferDataInfoFinds;

struct SMwParamInfos_CGameRemoteBufferDataInfoFinds {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CVisionResourceFile SMwParamInfos_CVisionResourceFile, *PSMwParamInfos_CVisionResourceFile;

struct SMwParamInfos_CVisionResourceFile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionCmdBaseParams SMwParamInfos_CMotionCmdBaseParams, *PSMwParamInfos_CMotionCmdBaseParams;

struct SMwParamInfos_CMotionCmdBaseParams {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamClass> CMwParamFastArray<class_CMwParamClass>, *PCMwParamFastArray<class_CMwParamClass>;

struct CMwParamFastArray<class_CMwParamClass> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerCameraSet SMwParamInfos_CGamePlayerCameraSet, *PSMwParamInfos_CGamePlayerCameraSet;

struct SMwParamInfos_CGamePlayerCameraSet {
    undefined field0_0x0;
};

typedef struct SEventEndOfRace SEventEndOfRace, *PSEventEndOfRace;

struct SEventEndOfRace {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CDx9StateBlock::STransformDesc> CFastArray<struct_CDx9StateBlock::STransformDesc>, *PCFastArray<struct_CDx9StateBlock::STransformDesc>;

struct CFastArray<struct_CDx9StateBlock::STransformDesc> {
    undefined field0_0x0;
};

typedef struct SContext SContext, *PSContext;

struct SContext {
    undefined field0_0x0;
};

typedef struct CPlugSound CPlugSound, *PCPlugSound;

struct CPlugSound {
    undefined field0_0x0;
};

typedef struct GmSphereCapCone3 GmSphereCapCone3, *PGmSphereCapCone3;

struct GmSphereCapCone3 {
    undefined field0_0x0;
};

typedef struct GxBGRColor565 GxBGRColor565, *PGxBGRColor565;

struct GxBGRColor565 {
    undefined field0_0x0;
};

typedef struct SStreamContext SStreamContext, *PSStreamContext;

struct SStreamContext {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePopUp::SItem> CFastBuffer<struct_CGamePopUp::SItem>, *PCFastBuffer<struct_CGamePopUp::SItem>;

struct CFastBuffer<struct_CGamePopUp::SItem> {
    undefined field0_0x0;
};

typedef struct CFuncKeys CFuncKeys, *PCFuncKeys;

struct CFuncKeys {
    undefined field0_0x0;
};

typedef struct CFuncTreeSubVisualSequence CFuncTreeSubVisualSequence, *PCFuncTreeSubVisualSequence;

struct CFuncTreeSubVisualSequence {
    undefined field0_0x0;
};

typedef struct CGameMasterServerRequestParams CGameMasterServerRequestParams, *PCGameMasterServerRequestParams;

struct CGameMasterServerRequestParams {
    undefined field0_0x0;
};

typedef struct CSceneToyBoat CSceneToyBoat, *PCSceneToyBoat;

struct CSceneToyBoat {
    undefined field0_0x0;
};

typedef struct SHmsItem_CallbackSortCustom_Elem SHmsItem_CallbackSortCustom_Elem, *PSHmsItem_CallbackSortCustom_Elem;

struct SHmsItem_CallbackSortCustom_Elem {
    undefined field0_0x0;
};

typedef struct SP2PNetworkParams SP2PNetworkParams, *PSP2PNetworkParams;

struct SP2PNetworkParams {
    undefined field0_0x0;
};

typedef struct CBlendedSolid CBlendedSolid, *PCBlendedSolid;

struct CBlendedSolid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameFid*> CFastBuffer<class_CGameFid*>, *PCFastBuffer<class_CGameFid*>;

struct CFastBuffer<class_CGameFid*> {
    undefined field0_0x0;
};

typedef struct CGameCtnDecorationSize CGameCtnDecorationSize, *PCGameCtnDecorationSize;

struct CGameCtnDecorationSize {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsForceFieldUniform SMwParamInfos_CHmsForceFieldUniform, *PSMwParamInfos_CHmsForceFieldUniform;

struct SMwParamInfos_CHmsForceFieldUniform {
    undefined field0_0x0;
};

typedef struct SkinSet SkinSet, *PSkinSet;

struct SkinSet {
    undefined field0_0x0;
};

typedef struct SStackLocation SStackLocation, *PSStackLocation;

struct SStackLocation {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF> CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>, *PCFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>;

struct CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneVehicleTuning> CMwNodRef<class_CSceneVehicleTuning>, *PCMwNodRef<class_CSceneVehicleTuning>;

struct CMwNodRef<class_CSceneVehicleTuning> {
    undefined field0_0x0;
};

typedef struct SParseTreeLight SParseTreeLight, *PSParseTreeLight;

struct SParseTreeLight {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlListMap2 SMwParamInfos_CControlListMap2, *PSMwParamInfos_CControlListMap2;

struct SMwParamInfos_CControlListMap2 {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<struct_CPlugTreeViewDep::SRenderBefore*> CFastCallback1P<struct_CPlugTreeViewDep::SRenderBefore*>, *PCFastCallback1P<struct_CPlugTreeViewDep::SRenderBefore*>;

struct CFastCallback1P<struct_CPlugTreeViewDep::SRenderBefore*> {
    undefined field0_0x0;
};

typedef struct CGameControlEditContext CGameControlEditContext, *PCGameControlEditContext;

struct CGameControlEditContext {
    undefined field0_0x0;
};

typedef struct CGameControlCameraEffect CGameControlCameraEffect, *PCGameControlCameraEffect;

struct CGameControlCameraEffect {
    undefined field0_0x0;
};

typedef struct CNetConnection CNetConnection, *PCNetConnection;

struct CNetConnection {
    undefined field0_0x0;
};

typedef struct SVehicleBallState SVehicleBallState, *PSVehicleBallState;

struct SVehicleBallState {
    undefined field0_0x0;
};

typedef struct _Vector_iterator<unsigned_short,class_std::allocator<unsigned_short>_> _Vector_iterator<unsigned_short,class_std::allocator<unsigned_short>_>, *P_Vector_iterator<unsigned_short,class_std::allocator<unsigned_short>_>;

struct _Vector_iterator<unsigned_short,class_std::allocator<unsigned_short>_> {
    undefined field0_0x0;
};

typedef struct CGameAvatar CGameAvatar, *PCGameAvatar;

struct CGameAvatar {
    undefined field0_0x0;
};

typedef struct GmLensVal GmLensVal, *PGmLensVal;

struct GmLensVal {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugDecoratorSolid SMwParamInfos_CPlugDecoratorSolid, *PSMwParamInfos_CPlugDecoratorSolid;

struct SMwParamInfos_CPlugDecoratorSolid {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugVertexStream SMwParamInfos_CPlugVertexStream, *PSMwParamInfos_CPlugVertexStream;

struct SMwParamInfos_CPlugVertexStream {
    undefined field0_0x0;
};

typedef struct CGameMenuFrame CGameMenuFrame, *PCGameMenuFrame;

struct CGameMenuFrame {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CCrystalVertex*> CFastArray<class_CCrystalVertex*>, *PCFastArray<class_CCrystalVertex*>;

struct CFastArray<class_CCrystalVertex*> {
    undefined field0_0x0;
};

typedef struct CMotionManagerLeaves CMotionManagerLeaves, *PCMotionManagerLeaves;

struct CMotionManagerLeaves {
    undefined field0_0x0;
};

typedef struct CControlBase CControlBase, *PCControlBase;

struct CControlBase {
    undefined field0_0x0;
};

typedef struct CHmsListener CHmsListener, *PCHmsListener;

struct CHmsListener {
    undefined field0_0x0;
};

typedef struct CPlugTreeVisualPlane CPlugTreeVisualPlane, *PCPlugTreeVisualPlane;

struct CPlugTreeVisualPlane {
    undefined field0_0x0;
};

typedef struct CFuncKeysSound CFuncKeysSound, *PCFuncKeysSound;

struct CFuncKeysSound {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,50,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,50,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugShaderApply>,50,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,50,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugSoundVideo CPlugSoundVideo, *PCPlugSoundVideo;

struct CPlugSoundVideo {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnGhostInfo> CMwNodRef<class_CGameCtnGhostInfo>, *PCMwNodRef<class_CGameCtnGhostInfo>;

struct CMwNodRef<class_CGameCtnGhostInfo> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugModelLodMesh> CMwNodRef<class_CPlugModelLodMesh>, *PCMwNodRef<class_CPlugModelLodMesh>;

struct CMwNodRef<class_CPlugModelLodMesh> {
    undefined field0_0x0;
};

typedef struct GxLightDirectional GxLightDirectional, *PGxLightDirectional;

struct GxLightDirectional {
    undefined field0_0x0;
};

typedef enum EMaxFiltering {
} EMaxFiltering;

typedef struct HKEY__ HKEY__, *PHKEY__;

struct HKEY__ {
    int unused;
};

typedef struct CMwCmdAffectIdentBool CMwCmdAffectIdentBool, *PCMwCmdAffectIdentBool;

struct CMwCmdAffectIdentBool {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct SFrameLadderRankingsStepOld SFrameLadderRankingsStepOld, *PSFrameLadderRankingsStepOld;

struct SFrameLadderRankingsStepOld {
    undefined field0_0x0;
};

typedef struct CGameControlPlayer CGameControlPlayer, *PCGameControlPlayer;

struct CGameControlPlayer {
    undefined field0_0x0;
};

typedef enum EChallengePlayMode {
} EChallengePlayMode;

typedef struct SMwParamInfos_CGameMenu SMwParamInfos_CGameMenu, *PSMwParamInfos_CGameMenu;

struct SMwParamInfos_CGameMenu {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CFuncTree>_> CFastBuffer<class_CMwNodRef<class_CFuncTree>_>, *PCFastBuffer<class_CMwNodRef<class_CFuncTree>_>;

struct CFastBuffer<class_CMwNodRef<class_CFuncTree>_> {
    undefined field0_0x0;
};

typedef struct CGameGhost CGameGhost, *PCGameGhost;

struct CGameGhost {
    undefined field0_0x0;
};

typedef struct CSceneMood CSceneMood, *PCSceneMood;

struct CSceneMood {
    undefined field0_0x0;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef struct CCallbackSceneToyCharacterComputeForces CCallbackSceneToyCharacterComputeForces, *PCCallbackSceneToyCharacterComputeForces;

struct CCallbackSceneToyCharacterComputeForces {
    undefined field0_0x0;
};

typedef struct CPlugBitmapHighLevel CPlugBitmapHighLevel, *PCPlugBitmapHighLevel;

struct CPlugBitmapHighLevel {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameMobil> CMwNodRef<class_CGameMobil>, *PCMwNodRef<class_CGameMobil>;

struct CMwNodRef<class_CGameMobil> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCampaignScores::SFilteredMedalsScores*> CFastBuffer<struct_CGameCampaignScores::SFilteredMedalsScores*>, *PCFastBuffer<struct_CGameCampaignScores::SFilteredMedalsScores*>;

struct CFastBuffer<struct_CGameCampaignScores::SFilteredMedalsScores*> {
    undefined field0_0x0;
};

typedef struct CGameOutlineBox CGameOutlineBox, *PCGameOutlineBox;

struct CGameOutlineBox {
    undefined field0_0x0;
};

typedef struct CGameNetConnectedClientUserData CGameNetConnectedClientUserData, *PCGameNetConnectedClientUserData;

struct CGameNetConnectedClientUserData {
    undefined field0_0x0;
};

typedef struct CGameNod CGameNod, *PCGameNod;

struct CGameNod {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewport::SDelayedToSortCustom> CFastBuffer<struct_CVisionViewport::SDelayedToSortCustom>, *PCFastBuffer<struct_CVisionViewport::SDelayedToSortCustom>;

struct CFastBuffer<struct_CVisionViewport::SDelayedToSortCustom> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct__IP_ADAPTER_INFO> CFastBuffer<struct__IP_ADAPTER_INFO>, *PCFastBuffer<struct__IP_ADAPTER_INFO>;

struct CFastBuffer<struct__IP_ADAPTER_INFO> {
    undefined field0_0x0;
};

typedef struct CMwCmdIf CMwCmdIf, *PCMwCmdIf;

struct CMwCmdIf {
    undefined field0_0x0;
};

typedef struct SSysGraphicPerformance SSysGraphicPerformance, *PSSysGraphicPerformance;

struct SSysGraphicPerformance {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugBitmap*> CFastBuffer<class_CPlugBitmap*>, *PCFastBuffer<class_CPlugBitmap*>;

struct CFastBuffer<class_CPlugBitmap*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyBroomstick SMwParamInfos_CSceneToyBroomstick, *PSMwParamInfos_CSceneToyBroomstick;

struct SMwParamInfos_CSceneToyBroomstick {
    undefined field0_0x0;
};

typedef struct CConstructionImage CConstructionImage, *PCConstructionImage;

struct CConstructionImage {
    undefined field0_0x0;
};

typedef struct SFastKey<class_CGameNetPlayerInfo*,unsigned_char> SFastKey<class_CGameNetPlayerInfo*,unsigned_char>, *PSFastKey<class_CGameNetPlayerInfo*,unsigned_char>;

struct SFastKey<class_CGameNetPlayerInfo*,unsigned_char> {
    undefined field0_0x0;
};

typedef struct CGameCtnPainterContext CGameCtnPainterContext, *PCGameCtnPainterContext;

struct CGameCtnPainterContext {
    undefined field0_0x0;
};

typedef struct CPlugShaderTweak CPlugShaderTweak, *PCPlugShaderTweak;

struct CPlugShaderTweak {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameScene SMwParamInfos_CGameScene, *PSMwParamInfos_CGameScene;

struct SMwParamInfos_CGameScene {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockEvent CMwClassInfoCGameCtnMediaBlockEvent, *PCMwClassInfoCGameCtnMediaBlockEvent;

struct CMwClassInfoCGameCtnMediaBlockEvent {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFileImg> CMwNodRef<class_CPlugFileImg>, *PCMwNodRef<class_CPlugFileImg>;

struct CMwNodRef<class_CPlugFileImg> {
    undefined field0_0x0;
};

typedef struct CFunctionEngine CFunctionEngine, *PCFunctionEngine;

struct CFunctionEngine {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnNetwork::SManiaCodeAction*> CFastBuffer<struct_CGameCtnNetwork::SManiaCodeAction*>, *PCFastBuffer<struct_CGameCtnNetwork::SManiaCodeAction*>;

struct CFastBuffer<struct_CGameCtnNetwork::SManiaCodeAction*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardMessage SMwParamInfos_CGameControlCardMessage, *PSMwParamInfos_CGameControlCardMessage;

struct SMwParamInfos_CGameControlCardMessage {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SGameCtnMediaTriggerZone> CFastBuffer<struct_SGameCtnMediaTriggerZone>, *PCFastBuffer<struct_SGameCtnMediaTriggerZone>;

struct CFastBuffer<struct_SGameCtnMediaTriggerZone> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeGenerator SMwParamInfos_CPlugTreeGenerator, *PSMwParamInfos_CPlugTreeGenerator;

struct SMwParamInfos_CPlugTreeGenerator {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetFileTransferUpload::CNetFileTransferDataToSend*> CFastBuffer<class_CNetFileTransferUpload::CNetFileTransferDataToSend*>, *PCFastBuffer<class_CNetFileTransferUpload::CNetFileTransferDataToSend*>;

struct CFastBuffer<class_CNetFileTransferUpload::CNetFileTransferDataToSend*> {
    undefined field0_0x0;
};

typedef enum EAvatarVariant {
} EAvatarVariant;

typedef struct CGameCtnChapter CGameCtnChapter, *PCGameCtnChapter;

struct CGameCtnChapter {
    undefined field0_0x0;
};

typedef struct CMwEngineManager CMwEngineManager, *PCMwEngineManager;

struct CMwEngineManager {
    undefined field0_0x0;
};

typedef struct SFuncCacheKey SFuncCacheKey, *PSFuncCacheKey;

struct SFuncCacheKey {
    undefined field0_0x0;
};

typedef struct CXmlTiDocumentWrapper CXmlTiDocumentWrapper, *PCXmlTiDocumentWrapper;

struct CXmlTiDocumentWrapper {
    undefined field0_0x0;
};

typedef struct CMwCmdBlock CMwCmdBlock, *PCMwCmdBlock;

struct CMwCmdBlock {
    undefined field0_0x0;
};

typedef struct CGameManialinkBrowser CGameManialinkBrowser, *PCGameManialinkBrowser;

struct CGameManialinkBrowser {
    undefined field0_0x0;
};

typedef struct SShaderWrap SShaderWrap, *PSShaderWrap;

struct SShaderWrap {
    undefined field0_0x0;
};

typedef struct SBuildSplit SBuildSplit, *PSBuildSplit;

struct SBuildSplit {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s_HandlerType - /_s_HandlerType */

typedef struct CFastBuffer<struct_CControlDisplayGraph::SGraph> CFastBuffer<struct_CControlDisplayGraph::SGraph>, *PCFastBuffer<struct_CControlDisplayGraph::SGraph>;

struct CFastBuffer<struct_CControlDisplayGraph::SGraph> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CHmsCorpusLight*> CFastBuffer<class_CHmsCorpusLight*>, *PCFastBuffer<class_CHmsCorpusLight*>;

struct CFastBuffer<class_CHmsCorpusLight*> {
    undefined field0_0x0;
};

typedef struct CNetServerInfo CNetServerInfo, *PCNetServerInfo;

struct CNetServerInfo {
    undefined field0_0x0;
};

typedef struct GmVec3 GmVec3, *PGmVec3;

struct GmVec3 {
    undefined field0_0x0;
};

typedef union GxRGBAColor GxRGBAColor, *PGxRGBAColor;

union GxRGBAColor {
};

typedef struct CFastCallback1P<class_CMwNod*> CFastCallback1P<class_CMwNod*>, *PCFastCallback1P<class_CMwNod*>;

struct CFastCallback1P<class_CMwNod*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameMenu*> CFastBuffer<class_CGameMenu*>, *PCFastBuffer<class_CGameMenu*>;

struct CFastBuffer<class_CGameMenu*> {
    undefined field0_0x0;
};

typedef struct CInputEngine CInputEngine, *PCInputEngine;

struct CInputEngine {
    undefined field0_0x0;
};

typedef struct CSceneFxOverlay CSceneFxOverlay, *PCSceneFxOverlay;

struct CSceneFxOverlay {
    undefined field0_0x0;
};

typedef struct CStreamBuf CStreamBuf, *PCStreamBuf;

struct CStreamBuf {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceScore SMwParamInfos_CTrackManiaRaceScore, *PSMwParamInfos_CTrackManiaRaceScore;

struct SMwParamInfos_CTrackManiaRaceScore {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SBlockContext> CFastBuffer<struct_SBlockContext>, *PCFastBuffer<struct_SBlockContext>;

struct CFastBuffer<struct_SBlockContext> {
    undefined field0_0x0;
};

typedef struct SGameCamVal SGameCamVal, *PSGameCamVal;

struct SGameCamVal {
    undefined field0_0x0;
};

typedef struct CSceneFxFlares CSceneFxFlares, *PCSceneFxFlares;

struct CSceneFxFlares {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamColor> CMwParamFastBuffer<class_CMwParamColor>, *PCMwParamFastBuffer<class_CMwParamColor>;

struct CMwParamFastBuffer<class_CMwParamColor> {
    undefined field0_0x0;
};

typedef struct CSystemEngine CSystemEngine, *PCSystemEngine;

struct CSystemEngine {
    undefined field0_0x0;
};

typedef struct SMasterServerNetworkParams SMasterServerNetworkParams, *PSMasterServerNetworkParams;

struct SMasterServerNetworkParams {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting*> CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting*>, *PCFastBuffer<struct_CGameRace::SPlayerInfosForTargetting*>;

struct CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting*> {
    undefined field0_0x0;
};

typedef struct SCollectorStock SCollectorStock, *PSCollectorStock;

struct SCollectorStock {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaClipGroup CGameCtnMediaClipGroup, *PCGameCtnMediaClipGroup;

struct CGameCtnMediaClipGroup {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_STARTUPINFOA - /winbase.h/_STARTUPINFOA */

typedef struct SSphere SSphere, *PSSphere;

struct SSphere {
    undefined field0_0x0;
};

typedef struct GmVec4 GmVec4, *PGmVec4;

struct GmVec4 {
    undefined field0_0x0;
};

typedef struct CMwParamEnum CMwParamEnum, *PCMwParamEnum;

struct CMwParamEnum {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugVisual::SSkinIndexWeight4> CFastBuffer<struct_CPlugVisual::SSkinIndexWeight4>, *PCFastBuffer<struct_CPlugVisual::SSkinIndexWeight4>;

struct CFastBuffer<struct_CPlugVisual::SSkinIndexWeight4> {
    undefined field0_0x0;
};

typedef struct CMwParamStruct CMwParamStruct, *PCMwParamStruct;

struct CMwParamStruct {
    undefined field0_0x0;
};

typedef struct CCrystalQuad CCrystalQuad, *PCCrystalQuad;

struct CCrystalQuad {
    undefined field0_0x0;
};

typedef struct SClientBannedInfo SClientBannedInfo, *PSClientBannedInfo;

struct SClientBannedInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<unsigned_long> CFastBuffer<unsigned_long>, *PCFastBuffer<unsigned_long>;

struct CFastBuffer<unsigned_long> {
    undefined field0_0x0;
};

typedef struct SPlugTreeOptimTravel SPlugTreeOptimTravel, *PSPlugTreeOptimTravel;

struct SPlugTreeOptimTravel {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditor CTrackManiaEditor, *PCTrackManiaEditor;

struct CTrackManiaEditor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSoundMood SMwParamInfos_CPlugSoundMood, *PSMwParamInfos_CPlugSoundMood;

struct SMwParamInfos_CPlugSoundMood {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFont> CMwNodRef<class_CPlugFont>, *PCMwNodRef<class_CPlugFont>;

struct CMwNodRef<class_CPlugFont> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpDiff CMwCmdExpDiff, *PCMwCmdExpDiff;

struct CMwCmdExpDiff {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaEditor SMwParamInfos_CTrackManiaEditor, *PSMwParamInfos_CTrackManiaEditor;

struct SMwParamInfos_CTrackManiaEditor {
    undefined field0_0x0;
};

typedef struct CPfmMesh CPfmMesh, *PCPfmMesh;

struct CPfmMesh {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CFuncTree> CFastBufferRef<class_CFuncTree>, *PCFastBufferRef<class_CFuncTree>;

struct CFastBufferRef<class_CFuncTree> {
    undefined field0_0x0;
};

typedef struct SDicoEntry SDicoEntry, *PSDicoEntry;

struct SDicoEntry {
    undefined field0_0x0;
};

typedef enum _D3DFORMAT {
} _D3DFORMAT;

typedef struct SMwParamInfos_CFuncCurvesReal SMwParamInfos_CFuncCurvesReal, *PSMwParamInfos_CFuncCurvesReal;

struct SMwParamInfos_CFuncCurvesReal {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderPortal CPlugBitmapRenderPortal, *PCPlugBitmapRenderPortal;

struct CPlugBitmapRenderPortal {
    undefined field0_0x0;
};

typedef struct allocator<char> allocator<char>, *Pallocator<char>;

struct allocator<char> {
    undefined field0_0x0;
};

typedef struct CMwCmd CMwCmd, *PCMwCmd;

struct CMwCmd {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumDotProduct3 CMwCmdExpNumDotProduct3, *PCMwCmdExpNumDotProduct3;

struct CMwCmdExpNumDotProduct3 {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumDotProduct2 CMwCmdExpNumDotProduct2, *PCMwCmdExpNumDotProduct2;

struct CMwCmdExpNumDotProduct2 {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_SID_IDENTIFIER_AUTHORITY - /winnt.h/_SID_IDENTIFIER_AUTHORITY */

typedef struct GxClipper GxClipper, *PGxClipper;

struct GxClipper {
    undefined field0_0x0;
};

typedef struct SFilteredMedalsScores SFilteredMedalsScores, *PSFilteredMedalsScores;

struct SFilteredMedalsScores {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CTrackManiaEditorInterface::SIcon*> CFastArray<struct_CTrackManiaEditorInterface::SIcon*>, *PCFastArray<struct_CTrackManiaEditorInterface::SIcon*>;

struct CFastArray<struct_CTrackManiaEditorInterface::SIcon*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdFor SMwParamInfos_CMwCmdFor, *PSMwParamInfos_CMwCmdFor;

struct SMwParamInfos_CMwCmdFor {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnReplayRecordInfo*> CFastBuffer<class_CGameCtnReplayRecordInfo*>, *PCFastBuffer<class_CGameCtnReplayRecordInfo*>;

struct CFastBuffer<class_CGameCtnReplayRecordInfo*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CInputDeviceMouse SMwParamInfos_CInputDeviceMouse, *PSMwParamInfos_CInputDeviceMouse;

struct SMwParamInfos_CInputDeviceMouse {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetwork::SVoteSpecificRatio> CFastBuffer<struct_CGameNetwork::SVoteSpecificRatio>, *PCFastBuffer<struct_CGameNetwork::SVoteSpecificRatio>;

struct CFastBuffer<struct_CGameNetwork::SVoteSpecificRatio> {
    undefined field0_0x0;
};

typedef struct SLight SLight, *PSLight;

struct SLight {
    undefined field0_0x0;
};

typedef struct GmSurf GmSurf, *PGmSurf;

struct GmSurf {
    undefined field0_0x0;
};

typedef struct HACCEL__ HACCEL__, *PHACCEL__;

struct HACCEL__ {
    int unused;
};

typedef struct CGameCtnMediaBlockUiSimpleEvtsDisplay CGameCtnMediaBlockUiSimpleEvtsDisplay, *PCGameCtnMediaBlockUiSimpleEvtsDisplay;

struct CGameCtnMediaBlockUiSimpleEvtsDisplay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameChallengeScores SMwParamInfos_CGameChallengeScores, *PSMwParamInfos_CGameChallengeScores;

struct SMwParamInfos_CGameChallengeScores {
    undefined field0_0x0;
};

typedef struct locale locale, *Plocale;

struct locale {
    undefined field0_0x0;
};

typedef struct CGameControlCardLadderRanking CGameControlCardLadderRanking, *PCGameControlCardLadderRanking;

struct CGameControlCardLadderRanking {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlTimeLine2::STrack> CFastBuffer<struct_CControlTimeLine2::STrack>, *PCFastBuffer<struct_CControlTimeLine2::STrack>;

struct CFastBuffer<struct_CControlTimeLine2::STrack> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMwNod::SManuallyLoadedFid> CFastBuffer<struct_CMwNod::SManuallyLoadedFid>, *PCFastBuffer<struct_CMwNod::SManuallyLoadedFid>;

struct CFastBuffer<struct_CMwNod::SManuallyLoadedFid> {
    undefined field0_0x0;
};

typedef struct CGameCtnPainter CGameCtnPainter, *PCGameCtnPainter;

struct CGameCtnPainter {
    undefined field0_0x0;
};

typedef struct SRecordUnit SRecordUnit, *PSRecordUnit;

struct SRecordUnit {
    undefined field0_0x0;
};

typedef struct CFuncVisualShiver CFuncVisualShiver, *PCFuncVisualShiver;

struct CFuncVisualShiver {
    undefined field0_0x0;
};

typedef struct SBirdData SBirdData, *PSBirdData;

struct SBirdData {
    undefined field0_0x0;
};

typedef struct STangent STangent, *PSTangent;

struct STangent {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockEditor CGameCtnMediaBlockEditor, *PCGameCtnMediaBlockEditor;

struct CGameCtnMediaBlockEditor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionParticleEmitterModel SMwParamInfos_CMotionParticleEmitterModel, *PSMwParamInfos_CMotionParticleEmitterModel;

struct SMwParamInfos_CMotionParticleEmitterModel {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum_EGxBlendFactor,5,unsigned_long> CFixedArray<enum_EGxBlendFactor,5,unsigned_long>, *PCFixedArray<enum_EGxBlendFactor,5,unsigned_long>;

struct CFixedArray<enum_EGxBlendFactor,5,unsigned_long> {
    undefined field0_0x0;
};

typedef struct GmLocFreeVal GmLocFreeVal, *PGmLocFreeVal;

struct GmLocFreeVal {
    undefined field0_0x0;
};

typedef struct SParamColorEffect SParamColorEffect, *PSParamColorEffect;

struct SParamColorEffect {
    undefined field0_0x0;
};

typedef enum CELL_SIDE {
} CELL_SIDE;

typedef struct CGameMenuColorEffect CGameMenuColorEffect, *PCGameMenuColorEffect;

struct CGameMenuColorEffect {
    undefined field0_0x0;
};

typedef struct CMotionTrackMobilRotate CMotionTrackMobilRotate, *PCMotionTrackMobilRotate;

struct CMotionTrackMobilRotate {
    undefined field0_0x0;
};

typedef struct SDisplayMode SDisplayMode, *PSDisplayMode;

struct SDisplayMode {
    undefined field0_0x0;
};

typedef struct CHmsForceFieldUniform CHmsForceFieldUniform, *PCHmsForceFieldUniform;

struct CHmsForceFieldUniform {
    undefined field0_0x0;
};

typedef struct SVisibleCamera SVisibleCamera, *PSVisibleCamera;

struct SVisibleCamera {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s_ESTypeList - /_s_ESTypeList */

typedef struct CFastBuffer<struct_CGameCtnMasterServer::SDownloadedData> CFastBuffer<struct_CGameCtnMasterServer::SDownloadedData>, *PCFastBuffer<struct_CGameCtnMasterServer::SDownloadedData>;

struct CFastBuffer<struct_CGameCtnMasterServer::SDownloadedData> {
    undefined field0_0x0;
};

typedef struct CMwParamRefBuffer CMwParamRefBuffer, *PCMwParamRefBuffer;

struct CMwParamRefBuffer {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockUiSimpleEvtsDisplay CMwClassInfoCGameCtnMediaBlockUiSimpleEvtsDisplay, *PCMwClassInfoCGameCtnMediaBlockUiSimpleEvtsDisplay;

struct CMwClassInfoCGameCtnMediaBlockUiSimpleEvtsDisplay {
    undefined field0_0x0;
};

typedef struct CSceneToy CSceneToy, *PCSceneToy;

struct CSceneToy {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarInt CMwCmdScriptVarInt, *PCMwCmdScriptVarInt;

struct CMwCmdScriptVarInt {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugMusicType SMwParamInfos_CPlugMusicType, *PSMwParamInfos_CPlugMusicType;

struct SMwParamInfos_CPlugMusicType {
    undefined field0_0x0;
};

typedef struct CVisionVideoAvi CVisionVideoAvi, *PCVisionVideoAvi;

struct CVisionVideoAvi {
    undefined field0_0x0;
};

typedef struct CPlugFile CPlugFile, *PCPlugFile;

struct CPlugFile {
    undefined field0_0x0;
};

typedef struct CGameMasterServerRequest CGameMasterServerRequest, *PCGameMasterServerRequest;

struct CGameMasterServerRequest {
    undefined field0_0x0;
};

typedef struct SOccWheel SOccWheel, *PSOccWheel;

struct SOccWheel {
    undefined field0_0x0;
};

typedef struct CPlugDecoratorSolid CPlugDecoratorSolid, *PCPlugDecoratorSolid;

struct CPlugDecoratorSolid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMasterServer::SMedalsInfo> CFastBuffer<struct_CGameCtnMasterServer::SMedalsInfo>, *PCFastBuffer<struct_CGameCtnMasterServer::SMedalsInfo>;

struct CFastBuffer<struct_CGameCtnMasterServer::SMedalsInfo> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameControlDataType>_> CFastBuffer<class_CMwNodRef<class_CGameControlDataType>_>, *PCFastBuffer<class_CMwNodRef<class_CGameControlDataType>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameControlDataType>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemPackDesc SMwParamInfos_CSystemPackDesc, *PSMwParamInfos_CSystemPackDesc;

struct SMwParamInfos_CSystemPackDesc {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_SYSTEM_INFO - /winbase.h/_SYSTEM_INFO */


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_RTL_CRITICAL_SECTION_DEBUG - /winnt.h/_RTL_CRITICAL_SECTION_DEBUG */

typedef struct CGameCtnMediaBlockTriangles2D CGameCtnMediaBlockTriangles2D, *PCGameCtnMediaBlockTriangles2D;

struct CGameCtnMediaBlockTriangles2D {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetFileTransferDownload SMwParamInfos_CNetFileTransferDownload, *PSMwParamInfos_CNetFileTransferDownload;

struct SMwParamInfos_CNetFileTransferDownload {
    undefined field0_0x0;
};

typedef struct CGameNetSearchRequest_Leagues CGameNetSearchRequest_Leagues, *PCGameNetSearchRequest_Leagues;

struct CGameNetSearchRequest_Leagues {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioSoundSurface SMwParamInfos_CAudioSoundSurface, *PSMwParamInfos_CAudioSoundSurface;

struct SMwParamInfos_CAudioSoundSurface {
    undefined field0_0x0;
};

typedef struct SPlugSurfaceLocatedPair SPlugSurfaceLocatedPair, *PSPlugSurfaceLocatedPair;

struct SPlugSurfaceLocatedPair {
    undefined field0_0x0;
};

typedef struct SPlacedBlock SPlacedBlock, *PSPlacedBlock;

struct SPlacedBlock {
    undefined field0_0x0;
};

typedef enum _D3DTEXTUREOP {
} _D3DTEXTUREOP;

typedef struct SPartBirthParams SPartBirthParams, *PSPartBirthParams;

struct SPartBirthParams {
    undefined field0_0x0;
};

typedef struct SStemInfo SStemInfo, *PSStemInfo;

struct SStemInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameSkillScoreComputer SMwParamInfos_CGameSkillScoreComputer, *PSMwParamInfos_CGameSkillScoreComputer;

struct SMwParamInfos_CGameSkillScoreComputer {
    undefined field0_0x0;
};

typedef struct CHmsFogPlane CHmsFogPlane, *PCHmsFogPlane;

struct CHmsFogPlane {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CScene2d> CMwNodRef<class_CScene2d>, *PCMwNodRef<class_CScene2d>;

struct CMwNodRef<class_CScene2d> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugFileGPU::SSkipSampler> CFastArray<struct_CPlugFileGPU::SSkipSampler>, *PCFastArray<struct_CPlugFileGPU::SSkipSampler>;

struct CFastArray<struct_CPlugFileGPU::SSkipSampler> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatTeamMateLocationDesc SMwParamInfos_CBoatTeamMateLocationDesc, *PSMwParamInfos_CBoatTeamMateLocationDesc;

struct SMwParamInfos_CBoatTeamMateLocationDesc {
    undefined field0_0x0;
};

typedef struct SPlayerInfosToSend SPlayerInfosToSend, *PSPlayerInfosToSend;

struct SPlayerInfosToSend {
    undefined field0_0x0;
};

typedef struct CMwCmdExpClassThis CMwCmdExpClassThis, *PCMwCmdExpClassThis;

struct CMwCmdExpClassThis {
    undefined field0_0x0;
};

typedef struct _is_ctype_compatible _is_ctype_compatible, *P_is_ctype_compatible;

struct _is_ctype_compatible {
    ulong id;
    int is_clike;
};

typedef struct SBlockContext SBlockContext, *PSBlockContext;

struct SBlockContext {
    undefined field0_0x0;
};

typedef enum EInstanceCmp {
} EInstanceCmp;

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerRanking> CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerRanking>, *PCFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerRanking>;

struct CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerRanking> {
    undefined field0_0x0;
};

typedef struct CGameCampaignsScoresManager CGameCampaignsScoresManager, *PCGameCampaignsScoresManager;

struct CGameCampaignsScoresManager {
    undefined field0_0x0;
};

typedef enum EMoveEvent {
} EMoveEvent;

typedef struct SRpcChallengeInfo SRpcChallengeInfo, *PSRpcChallengeInfo;

struct SRpcChallengeInfo {
    undefined field0_0x0;
};

typedef struct CInputBindingsConfig CInputBindingsConfig, *PCInputBindingsConfig;

struct CInputBindingsConfig {
    undefined field0_0x0;
};

typedef struct CCrystalFace CCrystalFace, *PCCrystalFace;

struct CCrystalFace {
    undefined field0_0x0;
};

typedef struct SSpriteFlags SSpriteFlags, *PSSpriteFlags;

struct SSpriteFlags {
    undefined field0_0x0;
};

typedef struct CPlugFileTga CPlugFileTga, *PCPlugFileTga;

struct CPlugFileTga {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameAdvertisingElement SMwParamInfos_CGameAdvertisingElement, *PSMwParamInfos_CGameAdvertisingElement;

struct SMwParamInfos_CGameAdvertisingElement {
    undefined field0_0x0;
};

typedef struct CTrackManiaNetForm CTrackManiaNetForm, *PCTrackManiaNetForm;

struct CTrackManiaNetForm {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugFileGPUP*> CFastCallback1P<class_CPlugFileGPUP*>, *PCFastCallback1P<class_CPlugFileGPUP*>;

struct CFastCallback1P<class_CPlugFileGPUP*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SWaitingRequest> CFastBuffer<struct_CGameMasterServer::SWaitingRequest>, *PCFastBuffer<struct_CGameMasterServer::SWaitingRequest>;

struct CFastBuffer<struct_CGameMasterServer::SWaitingRequest> {
    undefined field0_0x0;
};

typedef struct _ParamMoveFrameEffect _ParamMoveFrameEffect, *P_ParamMoveFrameEffect;

struct _ParamMoveFrameEffect {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpEgal SMwParamInfos_CMwCmdExpEgal, *PSMwParamInfos_CMwCmdExpEgal;

struct SMwParamInfos_CMwCmdExpEgal {
    undefined field0_0x0;
};

typedef struct CGameManiaNetResource CGameManiaNetResource, *PCGameManiaNetResource;

struct CGameManiaNetResource {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CDx9StateBlock::STexStageState> CFastBuffer<struct_CDx9StateBlock::STexStageState>, *PCFastBuffer<struct_CDx9StateBlock::STexStageState>;

struct CFastBuffer<struct_CDx9StateBlock::STexStageState> {
    undefined field0_0x0;
};

typedef struct CSceneToyLeash CSceneToyLeash, *PCSceneToyLeash;

struct CSceneToyLeash {
    undefined field0_0x0;
};

typedef struct CGameControlPlayerNet CGameControlPlayerNet, *PCGameControlPlayerNet;

struct CGameControlPlayerNet {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameCtnMediaTrack> CFastBufferRef<class_CGameCtnMediaTrack>, *PCFastBufferRef<class_CGameCtnMediaTrack>;

struct CFastBufferRef<class_CGameCtnMediaTrack> {
    undefined field0_0x0;
};

typedef struct _Mutex _Mutex, *P_Mutex;

struct _Mutex {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileSnd SMwParamInfos_CPlugFileSnd, *PSMwParamInfos_CPlugFileSnd;

struct SMwParamInfos_CPlugFileSnd {
    undefined field0_0x0;
};

typedef enum ESpectatorCameraTarget {
} ESpectatorCameraTarget;

typedef struct SParam_Id SParam_Id, *PSParam_Id;

struct SParam_Id {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlugGpuLoadFx> CFastBuffer<struct_SPlugGpuLoadFx>, *PCFastBuffer<struct_SPlugGpuLoadFx>;

struct CFastBuffer<struct_SPlugGpuLoadFx> {
    undefined field0_0x0;
};

typedef struct CGameMenuContext CGameMenuContext, *PCGameMenuContext;

struct CGameMenuContext {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CMwNod>_> CFastBuffer<class_CMwNodRef<class_CMwNod>_>, *PCFastBuffer<class_CMwNodRef<class_CMwNod>_>;

struct CFastBuffer<class_CMwNodRef<class_CMwNod>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SEllipsoid> CFastBuffer<struct_CPlugModelMesh::SEllipsoid>, *PCFastBuffer<struct_CPlugModelMesh::SEllipsoid>;

struct CFastBuffer<struct_CPlugModelMesh::SEllipsoid> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxMotionBlur SMwParamInfos_CSceneFxMotionBlur, *PSMwParamInfos_CSceneFxMotionBlur;

struct SMwParamInfos_CSceneFxMotionBlur {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnChallengeInfo CGameControlCardCtnChallengeInfo, *PCGameControlCardCtnChallengeInfo;

struct CGameControlCardCtnChallengeInfo {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamQuat> CMwParamFastBufferCat<class_CMwParamQuat>, *PCMwParamFastBufferCat<class_CMwParamQuat>;

struct CMwParamFastBufferCat<class_CMwParamQuat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxFlares SMwParamInfos_CSceneFxFlares, *PSMwParamInfos_CSceneFxFlares;

struct SMwParamInfos_CSceneFxFlares {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SBitmapElemToPack> CFastArray<struct_SBitmapElemToPack>, *PCFastArray<struct_SBitmapElemToPack>;

struct CFastArray<struct_SBitmapElemToPack> {
    undefined field0_0x0;
};

typedef struct SUserData SUserData, *PSUserData;

struct SUserData {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnObjectInfo SMwParamInfos_CGameCtnObjectInfo, *PSMwParamInfos_CGameCtnObjectInfo;

struct SMwParamInfos_CGameCtnObjectInfo {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CBlockVariable> CFastArray<class_CBlockVariable>, *PCFastArray<class_CBlockVariable>;

struct CFastArray<class_CBlockVariable> {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugVertexStream*> CFastCallback1P<class_CPlugVertexStream*>, *PCFastCallback1P<class_CPlugVertexStream*>;

struct CFastCallback1P<class_CPlugVertexStream*> {
    undefined field0_0x0;
};

typedef struct SCullObjects SCullObjects, *PSCullObjects;

struct SCullObjects {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CTrackManiaEditorIcon*> CFastBuffer<class_CTrackManiaEditorIcon*>, *PCFastBuffer<class_CTrackManiaEditorIcon*>;

struct CFastBuffer<class_CTrackManiaEditorIcon*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScenePath SMwParamInfos_CScenePath, *PSMwParamInfos_CScenePath;

struct SMwParamInfos_CScenePath {
    undefined field0_0x0;
};

typedef struct SLadderMatchResult SLadderMatchResult, *PSLadderMatchResult;

struct SLadderMatchResult {
    undefined field0_0x0;
};

typedef struct SLadderOrderInfo SLadderOrderInfo, *PSLadderOrderInfo;

struct SLadderOrderInfo {
    undefined field0_0x0;
};

typedef struct SShaderCacheSea SShaderCacheSea, *PSShaderCacheSea;

struct SShaderCacheSea {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneGate> CMwNodRef<class_CSceneGate>, *PCMwNodRef<class_CSceneGate>;

struct CMwNodRef<class_CSceneGate> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxDynaBump CPlugMaterialFxDynaBump, *PCPlugMaterialFxDynaBump;

struct CPlugMaterialFxDynaBump {
    undefined field0_0x0;
};

typedef struct SNetNodInfo SNetNodInfo, *PSNetNodInfo;

struct SNetNodInfo {
    undefined field0_0x0;
};

typedef struct CScenePoc CScenePoc, *PCScenePoc;

struct CScenePoc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SGameCtnIdentifier> CFastBuffer<struct_SGameCtnIdentifier>, *PCFastBuffer<struct_SGameCtnIdentifier>;

struct CFastBuffer<struct_SGameCtnIdentifier> {
    undefined field0_0x0;
};

typedef struct CGameCtnApp CGameCtnApp, *PCGameCtnApp;

struct CGameCtnApp {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugAudioEnvironment SMwParamInfos_CPlugAudioEnvironment, *PSMwParamInfos_CPlugAudioEnvironment;

struct SMwParamInfos_CPlugAudioEnvironment {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_COalAudioBufferKeeper::SStreamBuffer> CFastBuffer<struct_COalAudioBufferKeeper::SStreamBuffer>, *PCFastBuffer<struct_COalAudioBufferKeeper::SStreamBuffer>;

struct CFastBuffer<struct_COalAudioBufferKeeper::SStreamBuffer> {
    undefined field0_0x0;
};

typedef enum EAfterFx {
} EAfterFx;

typedef struct CFastBuffer<struct_CGameRemoteBuffer::SRemoteDatasPage*> CFastBuffer<struct_CGameRemoteBuffer::SRemoteDatasPage*>, *PCFastBuffer<struct_CGameRemoteBuffer::SRemoteDatasPage*>;

struct CFastBuffer<struct_CGameRemoteBuffer::SRemoteDatasPage*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlIconIndex SMwParamInfos_CControlIconIndex, *PSMwParamInfos_CControlIconIndex;

struct SMwParamInfos_CControlIconIndex {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugShaderApply> CFastBufferRef<class_CPlugShaderApply>, *PCFastBufferRef<class_CPlugShaderApply>;

struct CFastBufferRef<class_CPlugShaderApply> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_> CFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnCampaign>_> {
    undefined field0_0x0;
};

typedef enum ETextureRender {
} ETextureRender;

typedef struct CNetMasterServerInfo CNetMasterServerInfo, *PCNetMasterServerInfo;

struct CNetMasterServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncTreeElevator SMwParamInfos_CFuncTreeElevator, *PSMwParamInfos_CFuncTreeElevator;

struct SMwParamInfos_CFuncTreeElevator {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRace1PGhosts SMwParamInfos_CTrackManiaRace1PGhosts, *PSMwParamInfos_CTrackManiaRace1PGhosts;

struct SMwParamInfos_CTrackManiaRace1PGhosts {
    undefined field0_0x0;
};

typedef struct CGameCtnCatalog CGameCtnCatalog, *PCGameCtnCatalog;

struct CGameCtnCatalog {
    undefined field0_0x0;
};

typedef struct SDesc SDesc, *PSDesc;

struct SDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwStatsValue SMwParamInfos_CMwStatsValue, *PSMwParamInfos_CMwStatsValue;

struct SMwParamInfos_CMwStatsValue {
    undefined field0_0x0;
};

typedef struct GmSurfPolygon GmSurfPolygon, *PGmSurfPolygon;

struct GmSurfPolygon {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetClient::SQueuedNetNod> CFastBuffer<struct_CNetClient::SQueuedNetNod>, *PCFastBuffer<struct_CNetClient::SQueuedNetNod>;

struct CFastBuffer<struct_CNetClient::SQueuedNetNod> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFuncPathMesh::WayPoint> CFastBuffer<struct_CFuncPathMesh::WayPoint>, *PCFastBuffer<struct_CFuncPathMesh::WayPoint>;

struct CFastBuffer<struct_CFuncPathMesh::WayPoint> {
    undefined field0_0x0;
};

typedef struct CGameCtnReplayRecord CGameCtnReplayRecord, *PCGameCtnReplayRecord;

struct CGameCtnReplayRecord {
    undefined field0_0x0;
};

typedef struct SHeaderCommon SHeaderCommon, *PSHeaderCommon;

struct SHeaderCommon {
    undefined field0_0x0;
};

typedef struct CGameLeagueManager CGameLeagueManager, *PCGameLeagueManager;

struct CGameLeagueManager {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_EXCEPTION_RECORD - /excpt.h/_EXCEPTION_RECORD */

typedef struct CMwCmdExpVec2Neg CMwCmdExpVec2Neg, *PCMwCmdExpVec2Neg;

struct CMwCmdExpVec2Neg {
    undefined field0_0x0;
};

typedef struct SParamEffectSimi SParamEffectSimi, *PSParamEffectSimi;

struct SParamEffectSimi {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderCubeMap CPlugBitmapRenderCubeMap, *PCPlugBitmapRenderCubeMap;

struct CPlugBitmapRenderCubeMap {
    undefined field0_0x0;
};

typedef struct CMwParamInteger CMwParamInteger, *PCMwParamInteger;

struct CMwParamInteger {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SAllocInfo> CFastArray<struct_SAllocInfo>, *PCFastArray<struct_SAllocInfo>;

struct CFastArray<struct_SAllocInfo> {
    undefined field0_0x0;
};

typedef struct SRpcBannedPlayer SRpcBannedPlayer, *PSRpcBannedPlayer;

struct SRpcBannedPlayer {
    undefined field0_0x0;
};

typedef struct SCachedValue SCachedValue, *PSCachedValue;

struct SCachedValue {
    undefined field0_0x0;
};

typedef struct CPlugShaderLoadIds CPlugShaderLoadIds, *PCPlugShaderLoadIds;

struct CPlugShaderLoadIds {
    undefined field0_0x0;
};

typedef struct CPlugBitmapAddress CPlugBitmapAddress, *PCPlugBitmapAddress;

struct CPlugBitmapAddress {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncTreeBend SMwParamInfos_CFuncTreeBend, *PSMwParamInfos_CFuncTreeBend;

struct SMwParamInfos_CFuncTreeBend {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SRayReceiver> CFastBuffer<struct_SRayReceiver>, *PCFastBuffer<struct_SRayReceiver>;

struct CFastBuffer<struct_SRayReceiver> {
    undefined field0_0x0;
};

typedef struct CPlugFileSnd CPlugFileSnd, *PCPlugFileSnd;

struct CPlugFileSnd {
    undefined field0_0x0;
};

typedef struct CGameMenu CGameMenu, *PCGameMenu;

struct CGameMenu {
    undefined field0_0x0;
};

typedef struct SPlugModelFurFluff SPlugModelFurFluff, *PSPlugModelFurFluff;

struct SPlugModelFurFluff {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SIdRemapTable::SIdRemap> CFastBuffer<struct_SIdRemapTable::SIdRemap>, *PCFastBuffer<struct_SIdRemapTable::SIdRemap>;

struct CFastBuffer<struct_SIdRemapTable::SIdRemap> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameLeague> CFastBufferRef<class_CGameLeague>, *PCFastBufferRef<class_CGameLeague>;

struct CFastBufferRef<class_CGameLeague> {
    undefined field0_0x0;
};

typedef struct CGameNetManialinkPage CGameNetManialinkPage, *PCGameNetManialinkPage;

struct CGameNetManialinkPage {
    undefined field0_0x0;
};

typedef enum EChallengeKind {
} EChallengeKind;

typedef struct GmVec2 GmVec2, *PGmVec2;

struct GmVec2 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaEditorInterface::SFollowedNode*> CFastBuffer<struct_CTrackManiaEditorInterface::SFollowedNode*>, *PCFastBuffer<struct_CTrackManiaEditorInterface::SFollowedNode*>;

struct CFastBuffer<struct_CTrackManiaEditorInterface::SFollowedNode*> {
    undefined field0_0x0;
};

typedef struct CSceneFxBloomData CSceneFxBloomData, *PCSceneFxBloomData;

struct CSceneFxBloomData {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_> CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>, *PCFastArray<class_CMwNodRef<class_CGameCtnChallenge>_>;

struct CFastArray<class_CMwNodRef<class_CGameCtnChallenge>_> {
    undefined field0_0x0;
};

typedef struct CClassicBufferRef CClassicBufferRef, *PCClassicBufferRef;

struct CClassicBufferRef {
    undefined field0_0x0;
};

typedef struct SLoadedLight SLoadedLight, *PSLoadedLight;

struct SLoadedLight {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey> CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey>, *PCFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_GxFog>_>::SKey> {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,6,unsigned_long> CFixedArray<unsigned_long,6,unsigned_long>, *PCFixedArray<unsigned_long,6,unsigned_long>;

struct CFixedArray<unsigned_long,6,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxGrayAccum SMwParamInfos_CSceneFxGrayAccum, *PSMwParamInfos_CSceneFxGrayAccum;

struct SMwParamInfos_CSceneFxGrayAccum {
    undefined field0_0x0;
};

typedef struct CGameCamera CGameCamera, *PCGameCamera;

struct CGameCamera {
    undefined field0_0x0;
};

typedef struct CGameCampaignPlayerScores CGameCampaignPlayerScores, *PCGameCampaignPlayerScores;

struct CGameCampaignPlayerScores {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceNetRounds SMwParamInfos_CTrackManiaRaceNetRounds, *PSMwParamInfos_CTrackManiaRaceNetRounds;

struct SMwParamInfos_CTrackManiaRaceNetRounds {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlock3dStereo SMwParamInfos_CGameCtnMediaBlock3dStereo, *PSMwParamInfos_CGameCtnMediaBlock3dStereo;

struct SMwParamInfos_CGameCtnMediaBlock3dStereo {
    undefined field0_0x0;
};

typedef union UValue UValue, *PUValue;

union UValue {
};

typedef struct CFastBuffer<float> CFastBuffer<float>, *PCFastBuffer<float>;

struct CFastBuffer<float> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsOcclusion::SPlanesAtPos*> CFastBuffer<struct_CHmsOcclusion::SPlanesAtPos*>, *PCFastBuffer<struct_CHmsOcclusion::SPlanesAtPos*>;

struct CFastBuffer<struct_CHmsOcclusion::SPlanesAtPos*> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumIdent CMwCmdExpNumIdent, *PCMwCmdExpNumIdent;

struct CMwCmdExpNumIdent {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEffectMaster SMwParamInfos_CControlEffectMaster, *PSMwParamInfos_CControlEffectMaster;

struct SMwParamInfos_CControlEffectMaster {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumFunction CMwCmdExpNumFunction, *PCMwCmdExpNumFunction;

struct CMwCmdExpNumFunction {
    undefined field0_0x0;
};

typedef struct GmVector3<int> GmVector3<int>, *PGmVector3<int>;

struct GmVector3<int> {
    undefined field0_0x0;
};

typedef struct CFastStringBase<wchar_t> CFastStringBase<wchar_t>, *PCFastStringBase<wchar_t>;

struct CFastStringBase<wchar_t> {
    undefined field0_0x0;
};

typedef enum _D3DRENDERSTATETYPE {
} _D3DRENDERSTATETYPE;

typedef struct NvFaceInfo NvFaceInfo, *PNvFaceInfo;

struct NvFaceInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CDx9StateBlock::SMaterial> CFastBuffer<struct_CDx9StateBlock::SMaterial>, *PCFastBuffer<struct_CDx9StateBlock::SMaterial>;

struct CFastBuffer<struct_CDx9StateBlock::SMaterial> {
    undefined field0_0x0;
};

typedef struct CGameControlGrid CGameControlGrid, *PCGameControlGrid;

struct CGameControlGrid {
    undefined field0_0x0;
};

typedef struct CMwClassInfo CMwClassInfo, *PCMwClassInfo;

struct CMwClassInfo {
    undefined field0_0x0;
};

typedef struct CDx9VertexBuffer CDx9VertexBuffer, *PCDx9VertexBuffer;

struct CDx9VertexBuffer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugFilePack*> CFastBuffer<class_CPlugFilePack*>, *PCFastBuffer<class_CPlugFilePack*>;

struct CFastBuffer<class_CPlugFilePack*> {
    undefined field0_0x0;
};

typedef struct CGameControlCameraTarget CGameControlCameraTarget, *PCGameControlCameraTarget;

struct CGameControlCameraTarget {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxVisionK SMwParamInfos_CSceneFxVisionK, *PSMwParamInfos_CSceneFxVisionK;

struct SMwParamInfos_CSceneFxVisionK {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaClipViewer CGameCtnMediaClipViewer, *PCGameCtnMediaClipViewer;

struct CGameCtnMediaClipViewer {
    undefined field0_0x0;
};

typedef struct SMwFiberContext SMwFiberContext, *PSMwFiberContext;

struct SMwFiberContext {
    undefined field0_0x0;
};

typedef struct CNetIPSource CNetIPSource, *PCNetIPSource;

struct CNetIPSource {
    undefined field0_0x0;
};

typedef struct CGameCtnBench CGameCtnBench, *PCGameCtnBench;

struct CGameCtnBench {
    undefined field0_0x0;
};

typedef struct CMwCmdExpAdd CMwCmdExpAdd, *PCMwCmdExpAdd;

struct CMwCmdExpAdd {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCatalog SMwParamInfos_CGameCtnCatalog, *PSMwParamInfos_CGameCtnCatalog;

struct SMwParamInfos_CGameCtnCatalog {
    undefined field0_0x0;
};

typedef enum EPreset {
} EPreset;

typedef struct GmCamOrbitVal GmCamOrbitVal, *PGmCamOrbitVal;

struct GmCamOrbitVal {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsListener SMwParamInfos_CHmsListener, *PSMwParamInfos_CHmsListener;

struct SMwParamInfos_CHmsListener {
    undefined field0_0x0;
};

typedef struct SPredictionTypeVector SPredictionTypeVector, *PSPredictionTypeVector;

struct SPredictionTypeVector {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CAudioPort::SFadingSound> CFastBuffer<struct_CAudioPort::SFadingSound>, *PCFastBuffer<struct_CAudioPort::SFadingSound>;

struct CFastBuffer<struct_CAudioPort::SFadingSound> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage> CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>, *PCFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage>;

struct CFastBuffer<struct_CGamePlaygroundInterface::SAvatarMessage> {
    undefined field0_0x0;
};

typedef struct SVehicleSimpleNetState SVehicleSimpleNetState, *PSVehicleSimpleNetState;

struct SVehicleSimpleNetState {
    undefined field0_0x0;
};

typedef struct CCallbackSceneToyBoatSortCustom CCallbackSceneToyBoatSortCustom, *PCCallbackSceneToyBoatSortCustom;

struct CCallbackSceneToyBoatSortCustom {
    undefined field0_0x0;
};

typedef struct SHeaderMenuIconsFolders SHeaderMenuIconsFolders, *PSHeaderMenuIconsFolders;

struct SHeaderMenuIconsFolders {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFurWind SMwParamInfos_CPlugFurWind, *PSMwParamInfos_CPlugFurWind;

struct SMwParamInfos_CPlugFurWind {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SCollectorStock> CFastBuffer<struct_SCollectorStock>, *PCFastBuffer<struct_SCollectorStock>;

struct CFastBuffer<struct_SCollectorStock> {
    undefined field0_0x0;
};

typedef struct CControlListItem CControlListItem, *PCControlListItem;

struct CControlListItem {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CControlCurve CControlCurve, *PCControlCurve;

struct CControlCurve {
    undefined field0_0x0;
};

typedef struct CGameCtnEdControlCamPath CGameCtnEdControlCamPath, *PCGameCtnEdControlCamPath;

struct CGameCtnEdControlCamPath {
    undefined field0_0x0;
};

typedef struct CMwProfiler CMwProfiler, *PCMwProfiler;

struct CMwProfiler {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CMwCmdBlockMain::SMainContext> CFastBuffer<struct_CMwCmdBlockMain::SMainContext>, *PCFastBuffer<struct_CMwCmdBlockMain::SMainContext>;

struct CFastBuffer<struct_CMwCmdBlockMain::SMainContext> {
    undefined field0_0x0;
};

typedef struct CGamePlayerInfo CGamePlayerInfo, *PCGamePlayerInfo;

struct CGamePlayerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_COalAudioBufferKeeper SMwParamInfos_COalAudioBufferKeeper, *PSMwParamInfos_COalAudioBufferKeeper;

struct SMwParamInfos_COalAudioBufferKeeper {
    undefined field0_0x0;
};

typedef struct CControlForm CControlForm, *PCControlForm;

struct CControlForm {
    undefined field0_0x0;
};

typedef struct CControlCredit CControlCredit, *PCControlCredit;

struct CControlCredit {
    undefined field0_0x0;
};

typedef struct SMedalsInfo SMedalsInfo, *PSMedalsInfo;

struct SMedalsInfo {
    undefined field0_0x0;
};

typedef struct CHmsPortalProperty CHmsPortalProperty, *PCHmsPortalProperty;

struct CHmsPortalProperty {
    undefined field0_0x0;
};

typedef struct CPlugTreeViewDep CPlugTreeViewDep, *PCPlugTreeViewDep;

struct CPlugTreeViewDep {
    undefined field0_0x0;
};

typedef struct CFuncTreeTranslate CFuncTreeTranslate, *PCFuncTreeTranslate;

struct CFuncTreeTranslate {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneMood::SLight> CFastBuffer<struct_CSceneMood::SLight>, *PCFastBuffer<struct_CSceneMood::SLight>;

struct CFastBuffer<struct_CSceneMood::SLight> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnMediaBlock*> CFastBuffer<class_CGameCtnMediaBlock*>, *PCFastBuffer<class_CGameCtnMediaBlock*>;

struct CFastBuffer<class_CGameCtnMediaBlock*> {
    undefined field0_0x0;
};

typedef struct CGamePlayerCameraSet CGamePlayerCameraSet, *PCGamePlayerCameraSet;

struct CGamePlayerCameraSet {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncLight SMwParamInfos_CFuncLight, *PSMwParamInfos_CFuncLight;

struct SMwParamInfos_CFuncLight {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGamePlayerTagData>_> CFastBuffer<class_CMwNodRef<class_CGamePlayerTagData>_>, *PCFastBuffer<class_CMwNodRef<class_CGamePlayerTagData>_>;

struct CFastBuffer<class_CMwNodRef<class_CGamePlayerTagData>_> {
    undefined field0_0x0;
};

typedef enum EGxBlendFactor {
} EGxBlendFactor;

typedef struct CMwClassInfoCGameCtnMediaBlockTransitionFade CMwClassInfoCGameCtnMediaBlockTransitionFade, *PCMwClassInfoCGameCtnMediaBlockTransitionFade;

struct CMwClassInfoCGameCtnMediaBlockTransitionFade {
    undefined field0_0x0;
};

typedef struct CNetAnswerData CNetAnswerData, *PCNetAnswerData;

struct CNetAnswerData {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamQuat> CMwParamFastBuffer<class_CMwParamQuat>, *PCMwParamFastBuffer<class_CMwParamQuat>;

struct CMwParamFastBuffer<class_CMwParamQuat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_> CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleTuning>_> {
    undefined field0_0x0;
};

typedef struct WSAData WSAData, *PWSAData;

struct WSAData {
    ushort wVersion;
    ushort wHighVersion;
    char szDescription[257];
    char szSystemStatus[129];
    ushort iMaxSockets;
    ushort iMaxUdpDg;
    char *lpVendorInfo;
};

typedef struct CFastBuffer<struct_SHmsItem_CallbackSortCustom_Elem> CFastBuffer<struct_SHmsItem_CallbackSortCustom_Elem>, *PCFastBuffer<struct_SHmsItem_CallbackSortCustom_Elem>;

struct CFastBuffer<struct_SHmsItem_CallbackSortCustom_Elem> {
    undefined field0_0x0;
};

typedef struct CGameRule CGameRule, *PCGameRule;

struct CGameRule {
    undefined field0_0x0;
};

typedef struct CControlText CControlText, *PCControlText;

struct CControlText {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFidsFolder*> CFastBuffer<class_CSystemFidsFolder*>, *PCFastBuffer<class_CSystemFidsFolder*>;

struct CFastBuffer<class_CSystemFidsFolder*> {
    undefined field0_0x0;
};

typedef struct SGpuConst SGpuConst, *PSGpuConst;

struct SGpuConst {
    undefined field0_0x0;
};

typedef struct CMwCmdExpEnumIdent CMwCmdExpEnumIdent, *PCMwCmdExpEnumIdent;

struct CMwCmdExpEnumIdent {
    undefined field0_0x0;
};

typedef struct STreeMipLocated STreeMipLocated, *PSTreeMipLocated;

struct STreeMipLocated {
    undefined field0_0x0;
};

typedef struct CAudioSoundSurface CAudioSoundSurface, *PCAudioSoundSurface;

struct CAudioSoundSurface {
    undefined field0_0x0;
};

typedef struct CMwCmdExpInfEgal CMwCmdExpInfEgal, *PCMwCmdExpInfEgal;

struct CMwCmdExpInfEgal {
    undefined field0_0x0;
};

typedef struct CXmlDocument CXmlDocument, *PCXmlDocument;

struct CXmlDocument {
    undefined field0_0x0;
};

typedef struct SControlUrlLink SControlUrlLink, *PSControlUrlLink;

struct SControlUrlLink {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CCrystalEdge::SSplineConnect> CFastArray<struct_CCrystalEdge::SSplineConnect>, *PCFastArray<struct_CCrystalEdge::SSplineConnect>;

struct CFastArray<struct_CCrystalEdge::SSplineConnect> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_COalDevice*> CFastBuffer<class_COalDevice*>, *PCFastBuffer<class_COalDevice*>;

struct CFastBuffer<class_COalDevice*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SDeprecatedPlayerCampaignFilteredSkillScore> CFastBuffer<struct_SDeprecatedPlayerCampaignFilteredSkillScore>, *PCFastBuffer<struct_SDeprecatedPlayerCampaignFilteredSkillScore>;

struct CFastBuffer<struct_SDeprecatedPlayerCampaignFilteredSkillScore> {
    undefined field0_0x0;
};

typedef struct codecvt<char,char,int> codecvt<char,char,int>, *Pcodecvt<char,char,int>;

struct codecvt<char,char,int> {
    undefined field0_0x0;
};

typedef struct SFixedVHlsl SFixedVHlsl, *PSFixedVHlsl;

struct SFixedVHlsl {
    undefined field0_0x0;
};

typedef struct SVolatileTreePointer SVolatileTreePointer, *PSVolatileTreePointer;

struct SVolatileTreePointer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle> CFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle>, *PCFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle>;

struct CFastBuffer<struct_CSceneVehicleStruct::SVisualVehicle> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SNodFid> CFastArray<struct_SNodFid>, *PCFastArray<struct_SNodFid>;

struct CFastArray<struct_SNodFid> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CFastBuffer<class_CSceneMobil*>*> CFastArray<class_CFastBuffer<class_CSceneMobil*>*>, *PCFastArray<class_CFastBuffer<class_CSceneMobil*>*>;

struct CFastArray<class_CFastBuffer<class_CSceneMobil*>*> {
    undefined field0_0x0;
};

typedef struct CGameChallengeScores CGameChallengeScores, *PCGameChallengeScores;

struct CGameChallengeScores {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarFloat SMwParamInfos_CMwCmdScriptVarFloat, *PSMwParamInfos_CMwCmdScriptVarFloat;

struct SMwParamInfos_CMwCmdScriptVarFloat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyBoat SMwParamInfos_CSceneToyBoat, *PSMwParamInfos_CSceneToyBoat;

struct SMwParamInfos_CSceneToyBoat {
    undefined field0_0x0;
};

typedef struct CGameNetForm CGameNetForm, *PCGameNetForm;

struct CGameNetForm {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Mult CMwCmdExpVec3Mult, *PCMwCmdExpVec3Mult;

struct CMwCmdExpVec3Mult {
    undefined field0_0x0;
};

typedef struct tagRECT tagRECT, *PtagRECT;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef struct CGameNetOnlineNewsReply CGameNetOnlineNewsReply, *PCGameNetOnlineNewsReply;

struct CGameNetOnlineNewsReply {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SLocalisedMessage> CFastBuffer<struct_SLocalisedMessage>, *PCFastBuffer<struct_SLocalisedMessage>;

struct CFastBuffer<struct_SLocalisedMessage> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGamePlayerTagData> CMwNodRef<class_CGamePlayerTagData>, *PCMwNodRef<class_CGamePlayerTagData>;

struct CMwNodRef<class_CGamePlayerTagData> {
    undefined field0_0x0;
};

typedef struct CGmLooseOctree_Cell<struct_SHmsVPackerObjectBase,struct_SHmsVPackerObject> CGmLooseOctree_Cell<struct_SHmsVPackerObjectBase,struct_SHmsVPackerObject>, *PCGmLooseOctree_Cell<struct_SHmsVPackerObjectBase,struct_SHmsVPackerObject>;

struct CGmLooseOctree_Cell<struct_SHmsVPackerObjectBase,struct_SHmsVPackerObject> {
    undefined field0_0x0;
};

typedef struct CGameRemoteBufferDataInfoSearchs CGameRemoteBufferDataInfoSearchs, *PCGameRemoteBufferDataInfoSearchs;

struct CGameRemoteBufferDataInfoSearchs {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CPlugBitmap*,4,unsigned_long> CFixedArray<class_CPlugBitmap*,4,unsigned_long>, *PCFixedArray<class_CPlugBitmap*,4,unsigned_long>;

struct CFixedArray<class_CPlugBitmap*,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFilePack SMwParamInfos_CPlugFilePack, *PSMwParamInfos_CPlugFilePack;

struct SMwParamInfos_CPlugFilePack {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScenePickerManager SMwParamInfos_CScenePickerManager, *PSMwParamInfos_CScenePickerManager;

struct SMwParamInfos_CScenePickerManager {
    undefined field0_0x0;
};

typedef struct CHmsWaterRegion CHmsWaterRegion, *PCHmsWaterRegion;

struct CHmsWaterRegion {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SIfBlock> CFastBuffer<struct_SIfBlock>, *PCFastBuffer<struct_SIfBlock>;

struct CFastBuffer<struct_SIfBlock> {
    undefined field0_0x0;
};

typedef struct SAllChildTravel SAllChildTravel, *PSAllChildTravel;

struct SAllChildTravel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlText SMwParamInfos_CControlText, *PSMwParamInfos_CControlText;

struct SMwParamInfos_CControlText {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetMasterServer SMwParamInfos_CNetMasterServer, *PSMwParamInfos_CNetMasterServer;

struct SMwParamInfos_CNetMasterServer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugFileSndGen*> CFastBuffer<class_CPlugFileSndGen*>, *PCFastBuffer<class_CPlugFileSndGen*>;

struct CFastBuffer<class_CPlugFileSndGen*> {
    undefined field0_0x0;
};

typedef struct CPlugFileI18n CPlugFileI18n, *PCPlugFileI18n;

struct CPlugFileI18n {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaMenus SMwParamInfos_CTrackManiaMenus, *PSMwParamInfos_CTrackManiaMenus;

struct SMwParamInfos_CTrackManiaMenus {
    undefined field0_0x0;
};

typedef struct SPlayListElem SPlayListElem, *PSPlayListElem;

struct SPlayListElem {
    undefined field0_0x0;
};

typedef struct CFastArray<char> CFastArray<char>, *PCFastArray<char>;

struct CFastArray<char> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_CONTEXT - /excpt.h/_CONTEXT */

typedef struct CFastBuffer<struct_SHmsRenderRect> CFastBuffer<struct_SHmsRenderRect>, *PCFastBuffer<struct_SHmsRenderRect>;

struct CFastBuffer<struct_SHmsRenderRect> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParamNum CMwCmdAffectParamNum, *PCMwCmdAffectParamNum;

struct CMwCmdAffectParamNum {
    undefined field0_0x0;
};

typedef struct CPlugFilePng CPlugFilePng, *PCPlugFilePng;

struct CPlugFilePng {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CControlListItem*> CFastBuffer<class_CControlListItem*>, *PCFastBuffer<class_CControlListItem*>;

struct CFastBuffer<class_CControlListItem*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetIPC SMwParamInfos_CNetIPC, *PSMwParamInfos_CNetIPC;

struct SMwParamInfos_CNetIPC {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoRoad SMwParamInfos_CGameCtnBlockInfoRoad, *PSMwParamInfos_CGameCtnBlockInfoRoad;

struct SMwParamInfos_CGameCtnBlockInfoRoad {
    undefined field0_0x0;
};

typedef struct CPlugVisualQuads2D CPlugVisualQuads2D, *PCPlugVisualQuads2D;

struct CPlugVisualQuads2D {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugShaderPass SMwParamInfos_CPlugShaderPass, *PSMwParamInfos_CPlugShaderPass;

struct SMwParamInfos_CPlugShaderPass {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SMapOld1> CFastBuffer<struct_SMapOld1>, *PCFastBuffer<struct_SMapOld1>;

struct CFastBuffer<struct_SMapOld1> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceNetRounds CTrackManiaRaceNetRounds, *PCTrackManiaRaceNetRounds;

struct CTrackManiaRaceNetRounds {
    undefined field0_0x0;
};

typedef struct CGameCtnObjectInfo CGameCtnObjectInfo, *PCGameCtnObjectInfo;

struct CGameCtnObjectInfo {
    undefined field0_0x0;
};

typedef struct CPlugVisual2D CPlugVisual2D, *PCPlugVisual2D;

struct CPlugVisual2D {
    undefined field0_0x0;
};

typedef struct CLoaderParametrized CLoaderParametrized, *PCLoaderParametrized;

struct CLoaderParametrized {
    undefined field0_0x0;
};

typedef struct CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>, *PCFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>;

struct CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> {
    undefined field0_0x0;
};

typedef enum _D3DRESOURCETYPE {
} _D3DRESOURCETYPE;

typedef struct CMwClassInfoCSceneToyCharacter CMwClassInfoCSceneToyCharacter, *PCMwClassInfoCSceneToyCharacter;

struct CMwClassInfoCSceneToyCharacter {
    undefined field0_0x0;
};

typedef struct CNetNodPool CNetNodPool, *PCNetNodPool;

struct CNetNodPool {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SOldCutKey> CFastBuffer<struct_SOldCutKey>, *PCFastBuffer<struct_SOldCutKey>;

struct CFastBuffer<struct_SOldCutKey> {
    undefined field0_0x0;
};

typedef struct CMwCmdBlockProcedure CMwCmdBlockProcedure, *PCMwCmdBlockProcedure;

struct CMwCmdBlockProcedure {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct__D3DVERTEXELEMENT9> CFastBuffer<struct__D3DVERTEXELEMENT9>, *PCFastBuffer<struct__D3DVERTEXELEMENT9>;

struct CFastBuffer<struct__D3DVERTEXELEMENT9> {
    undefined field0_0x0;
};

typedef struct CClassicCrypto_BlowFish CClassicCrypto_BlowFish, *PCClassicCrypto_BlowFish;

struct CClassicCrypto_BlowFish {
    undefined field0_0x0;
};

typedef struct _xmlrpc_mem_block _xmlrpc_mem_block, *P_xmlrpc_mem_block;

struct _xmlrpc_mem_block {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CNetHttpResult*,struct_SFastCat> CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>, *PCFastBufferCat<class_CNetHttpResult*,struct_SFastCat>;

struct CFastBufferCat<class_CNetHttpResult*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamIso4> CMwParamFastBuffer<class_CMwParamIso4>, *PCMwParamFastBuffer<class_CMwParamIso4>;

struct CMwParamFastBuffer<class_CMwParamIso4> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_FLOATING_SAVE_AREA - /winnt.h/_FLOATING_SAVE_AREA */

typedef struct CMwCmdAffectIdentIso4 CMwCmdAffectIdentIso4, *PCMwCmdAffectIdentIso4;

struct CMwCmdAffectIdentIso4 {
    undefined field0_0x0;
};

typedef struct CFastBufferDep<class_CMwNod> CFastBufferDep<class_CMwNod>, *PCFastBufferDep<class_CMwNod>;

struct CFastBufferDep<class_CMwNod> {
    undefined field0_0x0;
};

typedef enum EPlugVertexTangent {
} EPlugVertexTangent;

typedef struct CMwParamFastBufferCat<class_CMwParamIso3> CMwParamFastBufferCat<class_CMwParamIso3>, *PCMwParamFastBufferCat<class_CMwParamIso3>;

struct CMwParamFastBufferCat<class_CMwParamIso3> {
    undefined field0_0x0;
};

typedef struct CMwCmdProc CMwCmdProc, *PCMwCmdProc;

struct CMwCmdProc {
    undefined field0_0x0;
};

typedef struct CGameCtnDecorationAudio CGameCtnDecorationAudio, *PCGameCtnDecorationAudio;

struct CGameCtnDecorationAudio {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFileGPU::SSampler> CFastBuffer<struct_CPlugFileGPU::SSampler>, *PCFastBuffer<struct_CPlugFileGPU::SSampler>;

struct CFastBuffer<struct_CPlugFileGPU::SSampler> {
    undefined field0_0x0;
};

typedef struct SRecordPerformance SRecordPerformance, *PSRecordPerformance;

struct SRecordPerformance {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugModelMesh> CFastBufferRef<class_CPlugModelMesh>, *PCFastBufferRef<class_CPlugModelMesh>;

struct CFastBufferRef<class_CPlugModelMesh> {
    undefined field0_0x0;
};

typedef struct SSurfaceHandler SSurfaceHandler, *PSSurfaceHandler;

struct SSurfaceHandler {
    undefined field0_0x0;
};

typedef struct SCell SCell, *PSCell;

struct SCell {
    undefined field0_0x0;
};

typedef struct SDeclaration SDeclaration, *PSDeclaration;

struct SDeclaration {
    undefined field0_0x0;
};

typedef struct CPlugFilePsh CPlugFilePsh, *PCPlugFilePsh;

struct CPlugFilePsh {
    undefined field0_0x0;
};

typedef struct CPlugFilePso CPlugFilePso, *PCPlugFilePso;

struct CPlugFilePso {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncShaders SMwParamInfos_CFuncShaders, *PSMwParamInfos_CFuncShaders;

struct SMwParamInfos_CFuncShaders {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlUrlLinks SMwParamInfos_CControlUrlLinks, *PSMwParamInfos_CControlUrlLinks;

struct SMwParamInfos_CControlUrlLinks {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarInt SMwParamInfos_CMwCmdScriptVarInt, *PSMwParamInfos_CMwCmdScriptVarInt;

struct SMwParamInfos_CMwCmdScriptVarInt {
    undefined field0_0x0;
};

typedef struct CGameFid CGameFid, *PCGameFid;

struct CGameFid {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagPOINT - /WinDef.h/tagPOINT */

typedef struct CFastBuffer<struct_CPlugBitmapRenderLightFromMap::SObjectColors> CFastBuffer<struct_CPlugBitmapRenderLightFromMap::SObjectColors>, *PCFastBuffer<struct_CPlugBitmapRenderLightFromMap::SObjectColors>;

struct CFastBuffer<struct_CPlugBitmapRenderLightFromMap::SObjectColors> {
    undefined field0_0x0;
};

typedef union Misc Misc, *PMisc;

union Misc {
    uint PhysicalAddress;
    uint VirtualSize;
};

typedef struct CControlKeyboardInterface CControlKeyboardInterface, *PCControlKeyboardInterface;

struct CControlKeyboardInterface {
    undefined field0_0x0;
};

typedef struct CMotionPlayCmd CMotionPlayCmd, *PCMotionPlayCmd;

struct CMotionPlayCmd {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat> CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat>, *PCFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat>;

struct CFastBufferCat<class_GmVec4,struct_CPlugShaderLoadIds::SFxCat> {
    undefined field0_0x0;
};

typedef struct CHmsPackLightMapAlloc CHmsPackLightMapAlloc, *PCHmsPackLightMapAlloc;

struct CHmsPackLightMapAlloc {
    undefined field0_0x0;
};

typedef enum ERaceState {
} ERaceState;

typedef struct SMwParamInfos_CMwCmdScriptVarString SMwParamInfos_CMwCmdScriptVarString, *PSMwParamInfos_CMwCmdScriptVarString;

struct SMwParamInfos_CMwCmdScriptVarString {
    undefined field0_0x0;
};

typedef struct CFuncShader CFuncShader, *PCFuncShader;

struct CFuncShader {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamString> CMwParamFastBufferCat<class_CMwParamString>, *PCMwParamFastBufferCat<class_CMwParamString>;

struct CMwParamFastBufferCat<class_CMwParamString> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri> CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri>, *PCFastBuffer<struct_CGameCtnMediaBlockTriangles::STri>;

struct CFastBuffer<struct_CGameCtnMediaBlockTriangles::STri> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderWater CPlugBitmapRenderWater, *PCPlugBitmapRenderWater;

struct CPlugBitmapRenderWater {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlSimi2 SMwParamInfos_CControlSimi2, *PSMwParamInfos_CControlSimi2;

struct SMwParamInfos_CControlSimi2 {
    undefined field0_0x0;
};

typedef struct SVisualLight SVisualLight, *PSVisualLight;

struct SVisualLight {
    undefined field0_0x0;
};

typedef struct SVehicleProfile_VehicleParam SVehicleProfile_VehicleParam, *PSVehicleProfile_VehicleParam;

struct SVehicleProfile_VehicleParam {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CControlListItem> CMwNodRef<class_CControlListItem>, *PCMwNodRef<class_CControlListItem>;

struct CMwNodRef<class_CControlListItem> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugDecoratorTree> CMwNodRef<class_CPlugDecoratorTree>, *PCMwNodRef<class_CPlugDecoratorTree>;

struct CMwNodRef<class_CPlugDecoratorTree> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsCamera SMwParamInfos_CHmsCamera, *PSMwParamInfos_CHmsCamera;

struct SMwParamInfos_CHmsCamera {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaPlayerProfile::SChallengeOpponents> CFastBuffer<struct_CTrackManiaPlayerProfile::SChallengeOpponents>, *PCFastBuffer<struct_CTrackManiaPlayerProfile::SChallengeOpponents>;

struct CFastBuffer<struct_CTrackManiaPlayerProfile::SChallengeOpponents> {
    undefined field0_0x0;
};

typedef struct CInputEventsStore CInputEventsStore, *PCInputEventsStore;

struct CInputEventsStore {
    undefined field0_0x0;
};

typedef struct _Container_base _Container_base, *P_Container_base;

struct _Container_base {
    undefined field0_0x0;
};

typedef struct CFastArray<float> CFastArray<float>, *PCFastArray<float>;

struct CFastArray<float> {
    undefined field0_0x0;
};

typedef struct SMasterData SMasterData, *PSMasterData;

struct SMasterData {
    undefined field0_0x0;
};

typedef struct SRequirementOld8_9 SRequirementOld8_9, *PSRequirementOld8_9;

struct SRequirementOld8_9 {
    undefined field0_0x0;
};

typedef struct CSceneVehicle CSceneVehicle, *PCSceneVehicle;

struct CSceneVehicle {
    undefined field0_0x0;
};

typedef struct SVisualWrap SVisualWrap, *PSVisualWrap;

struct SVisualWrap {
    undefined field0_0x0;
};

typedef struct GmCone3 GmCone3, *PGmCone3;

struct GmCone3 {
    undefined field0_0x0;
};

typedef enum EGfxQuality {
} EGfxQuality;

typedef struct CCrystalGroup CCrystalGroup, *PCCrystalGroup;

struct CCrystalGroup {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamBool> CMwParamFastBuffer<class_CMwParamBool>, *PCMwParamFastBuffer<class_CMwParamBool>;

struct CMwParamFastBuffer<class_CMwParamBool> {
    undefined field0_0x0;
};

typedef struct CMwParamColor CMwParamColor, *PCMwParamColor;

struct CMwParamColor {
    undefined field0_0x0;
};

typedef struct SManiaCodeGameAction SManiaCodeGameAction, *PSManiaCodeGameAction;

struct SManiaCodeGameAction {
    undefined field0_0x0;
};

typedef struct CGameControlGridCtnCampaign CGameControlGridCtnCampaign, *PCGameControlGridCtnCampaign;

struct CGameControlGridCtnCampaign {
    undefined field0_0x0;
};

typedef struct SApplyField SApplyField, *PSApplyField;

struct SApplyField {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlPager SMwParamInfos_CControlPager, *PSMwParamInfos_CControlPager;

struct SMwParamInfos_CControlPager {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamBool> CMwParamFastArray<class_CMwParamBool>, *PCMwParamFastArray<class_CMwParamBool>;

struct CMwParamFastArray<class_CMwParamBool> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SPlayListElem> CFastBuffer<struct_CTrackManiaNetwork::SPlayListElem>, *PCFastBuffer<struct_CTrackManiaNetwork::SPlayListElem>;

struct CFastBuffer<struct_CTrackManiaNetwork::SPlayListElem> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapApply CPlugBitmapApply, *PCPlugBitmapApply;

struct CPlugBitmapApply {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SOldLetter> CFastArray<struct_SOldLetter>, *PCFastArray<struct_SOldLetter>;

struct CFastArray<struct_SOldLetter> {
    undefined field0_0x0;
};

typedef struct CFastArray<enum__D3DFORMAT> CFastArray<enum__D3DFORMAT>, *PCFastArray<enum__D3DFORMAT>;

struct CFastArray<enum__D3DFORMAT> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraSimple CMwClassInfoCGameCtnMediaBlockCameraSimple, *PCMwClassInfoCGameCtnMediaBlockCameraSimple;

struct CMwClassInfoCGameCtnMediaBlockCameraSimple {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugVisual3D::SVisualToMerge> CFastBuffer<struct_CPlugVisual3D::SVisualToMerge>, *PCFastBuffer<struct_CPlugVisual3D::SVisualToMerge>;

struct CFastBuffer<struct_CPlugVisual3D::SVisualToMerge> {
    undefined field0_0x0;
};

typedef struct SDico SDico, *PSDico;

struct SDico {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlugTreeOptimGroup*> CFastBuffer<struct_SPlugTreeOptimGroup*>, *PCFastBuffer<struct_SPlugTreeOptimGroup*>;

struct CFastBuffer<struct_SPlugTreeOptimGroup*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CDx9VertexDeclaration::SDeclaration> CFastBuffer<struct_CDx9VertexDeclaration::SDeclaration>, *PCFastBuffer<struct_CDx9VertexDeclaration::SDeclaration>;

struct CFastBuffer<struct_CDx9VertexDeclaration::SDeclaration> {
    undefined field0_0x0;
};

typedef struct SElem SElem, *PSElem;

struct SElem {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockTime CMwClassInfoCGameCtnMediaBlockTime, *PCMwClassInfoCGameCtnMediaBlockTime;

struct CMwClassInfoCGameCtnMediaBlockTime {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<unsigned_long> CFastBufferWheel<unsigned_long>, *PCFastBufferWheel<unsigned_long>;

struct CFastBufferWheel<unsigned_long> {
    undefined field0_0x0;
};

typedef struct CHmsZone CHmsZone, *PCHmsZone;

struct CHmsZone {
    undefined field0_0x0;
};

typedef struct SViewDepShadow SViewDepShadow, *PSViewDepShadow;

struct SViewDepShadow {
    undefined field0_0x0;
};

typedef struct IDirect3DBaseTexture9 IDirect3DBaseTexture9, *PIDirect3DBaseTexture9;

struct IDirect3DBaseTexture9 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMotionPlayer*> CFastBuffer<class_CMotionPlayer*>, *PCFastBuffer<class_CMotionPlayer*>;

struct CFastBuffer<class_CMotionPlayer*> {
    undefined field0_0x0;
};

typedef enum EGameCtnMediaClipGroup {
} EGameCtnMediaClipGroup;

typedef struct CSystemCmdLoadNod CSystemCmdLoadNod, *PCSystemCmdLoadNod;

struct CSystemCmdLoadNod {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockUnit CGameCtnBlockUnit, *PCGameCtnBlockUnit;

struct CGameCtnBlockUnit {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameInterface SMwParamInfos_CGameInterface, *PSMwParamInfos_CGameInterface;

struct SMwParamInfos_CGameInterface {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CBoatSailState>_> CFastBuffer<class_CMwNodRef<class_CBoatSailState>_>, *PCFastBuffer<class_CMwNodRef<class_CBoatSailState>_>;

struct CFastBuffer<class_CMwNodRef<class_CBoatSailState>_> {
    undefined field0_0x0;
};

typedef struct SClipPlane SClipPlane, *PSClipPlane;

struct SClipPlane {
    undefined field0_0x0;
};

typedef struct _Vector_iterator<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> _Vector_iterator<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_>, *P_Vector_iterator<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_>;

struct _Vector_iterator<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderOverlay CPlugBitmapRenderOverlay, *PCPlugBitmapRenderOverlay;

struct CPlugBitmapRenderOverlay {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMenus::SVehicleProfile_VehicleParam> CFastBuffer<struct_CGameCtnMenus::SVehicleProfile_VehicleParam>, *PCFastBuffer<struct_CGameCtnMenus::SVehicleProfile_VehicleParam>;

struct CFastBuffer<struct_CGameCtnMenus::SVehicleProfile_VehicleParam> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockCameraOrbital CGameCtnMediaBlockCameraOrbital, *PCGameCtnMediaBlockCameraOrbital;

struct CGameCtnMediaBlockCameraOrbital {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CBoatSailState> CFastBufferRef<class_CBoatSailState>, *PCFastBufferRef<class_CBoatSailState>;

struct CFastBufferRef<class_CBoatSailState> {
    undefined field0_0x0;
};

typedef struct CPlugVisualSprite CPlugVisualSprite, *PCPlugVisualSprite;

struct CPlugVisualSprite {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetIPCConnectedClient::SQueueElem> CFastBuffer<struct_CNetIPCConnectedClient::SQueueElem>, *PCFastBuffer<struct_CNetIPCConnectedClient::SQueueElem>;

struct CFastBuffer<struct_CNetIPCConnectedClient::SQueueElem> {
    undefined field0_0x0;
};

typedef struct CPlugFilePHlsl CPlugFilePHlsl, *PCPlugFilePHlsl;

struct CPlugFilePHlsl {
    undefined field0_0x0;
};

typedef struct CMotionTrackVisual CMotionTrackVisual, *PCMotionTrackVisual;

struct CMotionTrackVisual {
    undefined field0_0x0;
};

typedef struct CVisionTexturePool CVisionTexturePool, *PCVisionTexturePool;

struct CVisionTexturePool {
    undefined field0_0x0;
};

typedef struct CSceneToyTrain CSceneToyTrain, *PCSceneToyTrain;

struct CSceneToyTrain {
    undefined field0_0x0;
};

typedef struct CLoaderPack CLoaderPack, *PCLoaderPack;

struct CLoaderPack {
    undefined field0_0x0;
};

typedef enum EOrientationMode {
} EOrientationMode;

typedef struct SMwParamInfos_CMotionEmitterLeaves SMwParamInfos_CMotionEmitterLeaves, *PSMwParamInfos_CMotionEmitterLeaves;

struct SMwParamInfos_CMotionEmitterLeaves {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFxBlurDepth CGameCtnMediaBlockFxBlurDepth, *PCGameCtnMediaBlockFxBlurDepth;

struct CGameCtnMediaBlockFxBlurDepth {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagMSG - /winuser.h/tagMSG */

typedef struct SPlugVisibleId SPlugVisibleId, *PSPlugVisibleId;

struct SPlugVisibleId {
    undefined field0_0x0;
};

typedef struct SPlugTreeOptimGroup SPlugTreeOptimGroup, *PSPlugTreeOptimGroup;

struct SPlugTreeOptimGroup {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_> CFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnGhost>_> {
    undefined field0_0x0;
};

typedef struct SPlugVisibleFilterOptim SPlugVisibleFilterOptim, *PSPlugVisibleFilterOptim;

struct SPlugVisibleFilterOptim {
    undefined field0_0x0;
};

typedef struct CPlugBitmapShader CPlugBitmapShader, *PCPlugBitmapShader;

struct CPlugBitmapShader {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/timecaps_tag - /mmsystem.h/timecaps_tag */

typedef struct CFastBuffer<struct_CPlugVisual3D::SMergeForceDecl> CFastBuffer<struct_CPlugVisual3D::SMergeForceDecl>, *PCFastBuffer<struct_CPlugVisual3D::SMergeForceDecl>;

struct CFastBuffer<struct_CPlugVisual3D::SMergeForceDecl> {
    undefined field0_0x0;
};

typedef struct STeamMate STeamMate, *PSTeamMate;

struct STeamMate {
    undefined field0_0x0;
};

typedef struct CPlugVisualIndexedStrip CPlugVisualIndexedStrip, *PCPlugVisualIndexedStrip;

struct CPlugVisualIndexedStrip {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTime CGameCtnMediaBlockTime, *PCGameCtnMediaBlockTime;

struct CGameCtnMediaBlockTime {
    undefined field0_0x0;
};

typedef struct _D3DMATERIAL9 _D3DMATERIAL9, *P_D3DMATERIAL9;

struct _D3DMATERIAL9 {
    undefined field0_0x0;
};

typedef struct SRemoteBufferContext SRemoteBufferContext, *PSRemoteBufferContext;

struct SRemoteBufferContext {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastMap<class_CMwId,unsigned_long>::SPair> CFastBuffer<struct_CFastMap<class_CMwId,unsigned_long>::SPair>, *PCFastBuffer<struct_CFastMap<class_CMwId,unsigned_long>::SPair>;

struct CFastBuffer<struct_CFastMap<class_CMwId,unsigned_long>::SPair> {
    undefined field0_0x0;
};

typedef struct CAudioSoundEngine_Mixer_Implem<float,6> CAudioSoundEngine_Mixer_Implem<float,6>, *PCAudioSoundEngine_Mixer_Implem<float,6>;

struct CAudioSoundEngine_Mixer_Implem<float,6> {
    undefined field0_0x0;
};

typedef struct SCasterCat SCasterCat, *PSCasterCat;

struct SCasterCat {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_SYSTEMTIME - /winbase.h/_SYSTEMTIME */

typedef struct CGameCtnMediaBlockImage CGameCtnMediaBlockImage, *PCGameCtnMediaBlockImage;

struct CGameCtnMediaBlockImage {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastMap<class_CMwId,float>::SPair> CFastBuffer<struct_CFastMap<class_CMwId,float>::SPair>, *PCFastBuffer<struct_CFastMap<class_CMwId,float>::SPair>;

struct CFastBuffer<struct_CFastMap<class_CMwId,float>::SPair> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SMeshOctreeCell> CFastArray<struct_SMeshOctreeCell>, *PCFastArray<struct_SMeshOctreeCell>;

struct CFastArray<struct_SMeshOctreeCell> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerLeaves SMwParamInfos_CMotionManagerLeaves, *PSMwParamInfos_CMotionManagerLeaves;

struct SMwParamInfos_CMotionManagerLeaves {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSceneToyBird*> CFastBuffer<class_CSceneToyBird*>, *PCFastBuffer<class_CSceneToyBird*>;

struct CFastBuffer<class_CSceneToyBird*> {
    undefined field0_0x0;
};

typedef struct CDx9DynamicVB CDx9DynamicVB, *PCDx9DynamicVB;

struct CDx9DynamicVB {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockFxBloom::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockFxBloom::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockFxBloom::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockFxBloom::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CHmsZoneDynamic CHmsZoneDynamic, *PCHmsZoneDynamic;

struct CHmsZoneDynamic {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneCamera SMwParamInfos_CSceneCamera, *PSMwParamInfos_CSceneCamera;

struct SMwParamInfos_CSceneCamera {
    undefined field0_0x0;
};

typedef struct SParam SParam, *PSParam;

struct SParam {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameManialinkBrowser SMwParamInfos_CGameManialinkBrowser, *PSMwParamInfos_CGameManialinkBrowser;

struct SMwParamInfos_CGameManialinkBrowser {
    undefined field0_0x0;
};

typedef struct ID3DXConstantTable ID3DXConstantTable, *PID3DXConstantTable;

struct ID3DXConstantTable {
    undefined field0_0x0;
};

typedef enum EMwSchemeTimedPatterns {
} EMwSchemeTimedPatterns;

typedef struct SMwParamInfos_CTrackManiaEditorInterface SMwParamInfos_CTrackManiaEditorInterface, *PSMwParamInfos_CTrackManiaEditorInterface;

struct SMwParamInfos_CTrackManiaEditorInterface {
    undefined field0_0x0;
};

typedef struct CControlEffectCombined CControlEffectCombined, *PCControlEffectCombined;

struct CControlEffectCombined {
    undefined field0_0x0;
};

typedef struct SUser SUser, *PSUser;

struct SUser {
    undefined field0_0x0;
};

typedef struct GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b> GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>, *PGmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>;

struct GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> {
    undefined field0_0x0;
};

typedef struct CMotionCmdBaseParams CMotionCmdBaseParams, *PCMotionCmdBaseParams;

struct CMotionCmdBaseParams {
    undefined field0_0x0;
};

typedef struct SRenderShaderParam SRenderShaderParam, *PSRenderShaderParam;

struct SRenderShaderParam {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrackMobilRotate SMwParamInfos_CMotionTrackMobilRotate, *PSMwParamInfos_CMotionTrackMobilRotate;

struct SMwParamInfos_CMotionTrackMobilRotate {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SPlayerScoreToValidate> CFastBuffer<struct_CTrackManiaNetwork::SPlayerScoreToValidate>, *PCFastBuffer<struct_CTrackManiaNetwork::SPlayerScoreToValidate>;

struct CFastBuffer<struct_CTrackManiaNetwork::SPlayerScoreToValidate> {
    undefined field0_0x0;
};

typedef enum EMedal {
} EMedal;

typedef struct SSkipSampler SSkipSampler, *PSSkipSampler;

struct SSkipSampler {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SHmsPhysicalCollision> CFastBuffer<struct_SHmsPhysicalCollision>, *PCFastBuffer<struct_SHmsPhysicalCollision>;

struct CFastBuffer<struct_SHmsPhysicalCollision> {
    undefined field0_0x0;
};

typedef struct CPlugFurWind CPlugFurWind, *PCPlugFurWind;

struct CPlugFurWind {
    undefined field0_0x0;
};

typedef struct SHmsCameraProjection SHmsCameraProjection, *PSHmsCameraProjection;

struct SHmsCameraProjection {
    undefined field0_0x0;
};

typedef struct CMwParamNodRef CMwParamNodRef, *PCMwParamNodRef;

struct CMwParamNodRef {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatSail SMwParamInfos_CBoatSail, *PSMwParamInfos_CBoatSail;

struct SMwParamInfos_CBoatSail {
    undefined field0_0x0;
};

typedef struct SRpcServerOptions SRpcServerOptions, *PSRpcServerOptions;

struct SRpcServerOptions {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<float> CFastBufferWheel<float>, *PCFastBufferWheel<float>;

struct CFastBufferWheel<float> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlGridCtnCampaign SMwParamInfos_CGameControlGridCtnCampaign, *PSMwParamInfos_CGameControlGridCtnCampaign;

struct SMwParamInfos_CGameControlGridCtnCampaign {
    undefined field0_0x0;
};

typedef struct CXmlDeclaration CXmlDeclaration, *PCXmlDeclaration;

struct CXmlDeclaration {
    undefined field0_0x0;
};

typedef struct GxVertex GxVertex, *PGxVertex;

struct GxVertex {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameManialinkEntry> CMwNodRef<class_CGameManialinkEntry>, *PCMwNodRef<class_CGameManialinkEntry>;

struct CMwNodRef<class_CGameManialinkEntry> {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlCard CTrackManiaControlCard, *PCTrackManiaControlCard;

struct CTrackManiaControlCard {
    undefined field0_0x0;
};

typedef struct CMwParamStringInt CMwParamStringInt, *PCMwParamStringInt;

struct CMwParamStringInt {
    undefined field0_0x0;
};

typedef struct SEllipsoid SEllipsoid, *PSEllipsoid;

struct SEllipsoid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewport::SDelayedRender> CFastBuffer<struct_CVisionViewport::SDelayedRender>, *PCFastBuffer<struct_CVisionViewport::SDelayedRender>;

struct CFastBuffer<struct_CVisionViewport::SDelayedRender> {
    undefined field0_0x0;
};

typedef struct CFuncKeysPath CFuncKeysPath, *PCFuncKeysPath;

struct CFuncKeysPath {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameManiaNetResource> CMwNodRef<class_CGameManiaNetResource>, *PCMwNodRef<class_CGameManiaNetResource>;

struct CMwNodRef<class_CGameManiaNetResource> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugModelTree SMwParamInfos_CPlugModelTree, *PSMwParamInfos_CPlugModelTree;

struct SMwParamInfos_CPlugModelTree {
    undefined field0_0x0;
};

typedef struct SRpcChallengeQuickInfo SRpcChallengeQuickInfo, *PSRpcChallengeQuickInfo;

struct SRpcChallengeQuickInfo {
    undefined field0_0x0;
};

typedef struct CHmsZoneOverlay CHmsZoneOverlay, *PCHmsZoneOverlay;

struct CHmsZoneOverlay {
    undefined field0_0x0;
};

typedef struct CStridedArray<union_GxBGRAColor> CStridedArray<union_GxBGRAColor>, *PCStridedArray<union_GxBGRAColor>;

struct CStridedArray<union_GxBGRAColor> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRace2PTurnBased CTrackManiaRace2PTurnBased, *PCTrackManiaRace2PTurnBased;

struct CTrackManiaRace2PTurnBased {
    undefined field0_0x0;
};

typedef struct SArrowTopo SArrowTopo, *PSArrowTopo;

struct SArrowTopo {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_OVERLAPPED - /winbase.h/_OVERLAPPED */

typedef struct CSceneVehicleCarTuning CSceneVehicleCarTuning, *PCSceneVehicleCarTuning;

struct CSceneVehicleCarTuning {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdSleep SMwParamInfos_CMwCmdSleep, *PSMwParamInfos_CMwCmdSleep;

struct SMwParamInfos_CMwCmdSleep {
    undefined field0_0x0;
};

typedef struct CSystemManagerFile CSystemManagerFile, *PCSystemManagerFile;

struct CSystemManagerFile {
    undefined field0_0x0;
};

typedef struct CFuncKeysReal CFuncKeysReal, *PCFuncKeysReal;

struct CFuncKeysReal {
    undefined field0_0x0;
};

typedef struct CGmLooseOctree_Level CGmLooseOctree_Level, *PCGmLooseOctree_Level;

struct CGmLooseOctree_Level {
    undefined field0_0x0;
};

typedef enum EEvent {
} EEvent;

typedef struct GmMap2<unsigned_char> GmMap2<unsigned_char>, *PGmMap2<unsigned_char>;

struct GmMap2<unsigned_char> {
    undefined field0_0x0;
};

typedef struct COalAudioBufferKeeper COalAudioBufferKeeper, *PCOalAudioBufferKeeper;

struct COalAudioBufferKeeper {
    undefined field0_0x0;
};

typedef struct SCampaignRecordsState SCampaignRecordsState, *PSCampaignRecordsState;

struct SCampaignRecordsState {
    undefined field0_0x0;
};

typedef struct CClassicCrashDump CClassicCrashDump, *PCClassicCrashDump;

struct CClassicCrashDump {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SOldLetter2> CFastArray<struct_SOldLetter2>, *PCFastArray<struct_SOldLetter2>;

struct CFastArray<struct_SOldLetter2> {
    undefined field0_0x0;
};

typedef enum EMouseWheelAction {
} EMouseWheelAction;

typedef struct SMwParamInfos_CMotionTrackMobilMove SMwParamInfos_CMotionTrackMobilMove, *PSMwParamInfos_CMotionTrackMobilMove;

struct SMwParamInfos_CMotionTrackMobilMove {
    undefined field0_0x0;
};

typedef struct _IMAGE_SECTION_HEADER _IMAGE_SECTION_HEADER, *P_IMAGE_SECTION_HEADER;

typedef union _union_226 _union_226, *P_union_226;

union _union_226 {
    ulong PhysicalAddress;
    ulong VirtualSize;
};

struct _IMAGE_SECTION_HEADER {
    uchar Name[8];
    union _union_226 Misc;
    ulong VirtualAddress;
    ulong SizeOfRawData;
    ulong PointerToRawData;
    ulong PointerToRelocations;
    ulong PointerToLinenumbers;
    ushort NumberOfRelocations;
    ushort NumberOfLinenumbers;
    ulong Characteristics;
};

typedef struct CSceneMobilOnRenderBeforeItem CSceneMobilOnRenderBeforeItem, *PCSceneMobilOnRenderBeforeItem;

struct CSceneMobilOnRenderBeforeItem {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugMaterialFxs SMwParamInfos_CPlugMaterialFxs, *PSMwParamInfos_CPlugMaterialFxs;

struct SMwParamInfos_CPlugMaterialFxs {
    undefined field0_0x0;
};

typedef enum EChallengeCutScene {
} EChallengeCutScene;

typedef struct CFastCallback2P<struct_CPlugFileImg::SDesc&,class_CFastStringInt_const&> CFastCallback2P<struct_CPlugFileImg::SDesc&,class_CFastStringInt_const&>, *PCFastCallback2P<struct_CPlugFileImg::SDesc&,class_CFastStringInt_const&>;

struct CFastCallback2P<struct_CPlugFileImg::SDesc&,class_CFastStringInt_const&> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugShaderPass::SGpuFx> CFastArray<struct_CPlugShaderPass::SGpuFx>, *PCFastArray<struct_CPlugShaderPass::SGpuFx>;

struct CFastArray<struct_CPlugShaderPass::SGpuFx> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwCmdExp*> CFastArray<class_CMwCmdExp*>, *PCFastArray<class_CMwCmdExp*>;

struct CFastArray<class_CMwCmdExp*> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockGhost CMwClassInfoCGameCtnMediaBlockGhost, *PCMwClassInfoCGameCtnMediaBlockGhost;

struct CMwClassInfoCGameCtnMediaBlockGhost {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CFuncCurvesReal> CMwNodRef<class_CFuncCurvesReal>, *PCMwNodRef<class_CFuncCurvesReal>;

struct CMwNodRef<class_CFuncCurvesReal> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamVec2> CMwParamFastBuffer<class_CMwParamVec2>, *PCMwParamFastBuffer<class_CMwParamVec2>;

struct CMwParamFastBuffer<class_CMwParamVec2> {
    undefined field0_0x0;
};

typedef struct CVisionHmsZone CVisionHmsZone, *PCVisionHmsZone;

struct CVisionHmsZone {
    undefined field0_0x0;
};

typedef struct CAudioSound CAudioSound, *PCAudioSound;

struct CAudioSound {
    undefined field0_0x0;
};

typedef struct CMwCmdBreak CMwCmdBreak, *PCMwCmdBreak;

struct CMwCmdBreak {
    undefined field0_0x0;
};

typedef struct CNetFileTransferNod CNetFileTransferNod, *PCNetFileTransferNod;

struct CNetFileTransferNod {
    undefined field0_0x0;
};

typedef struct COalAudioSound COalAudioSound, *PCOalAudioSound;

struct COalAudioSound {
    undefined field0_0x0;
};

typedef struct SHMAC_SHA1_Data SHMAC_SHA1_Data, *PSHMAC_SHA1_Data;

struct SHMAC_SHA1_Data {
    undefined field0_0x0;
};

typedef struct CGameDialogShootVideo CGameDialogShootVideo, *PCGameDialogShootVideo;

struct CGameDialogShootVideo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlListItem SMwParamInfos_CControlListItem, *PSMwParamInfos_CControlListItem;

struct SMwParamInfos_CControlListItem {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnChallengeInfo SMwParamInfos_CGameCtnChallengeInfo, *PSMwParamInfos_CGameCtnChallengeInfo;

struct SMwParamInfos_CGameCtnChallengeInfo {
    undefined field0_0x0;
};

typedef struct CGameControlCameraFollowAboveWater CGameControlCameraFollowAboveWater, *PCGameControlCameraFollowAboveWater;

struct CGameControlCameraFollowAboveWater {
    undefined field0_0x0;
};

typedef struct SGraph SGraph, *PSGraph;

struct SGraph {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SFixedVHlsl> CFastBuffer<struct_SFixedVHlsl>, *PCFastBuffer<struct_SFixedVHlsl>;

struct CFastBuffer<struct_SFixedVHlsl> {
    undefined field0_0x0;
};

typedef struct GxVertex2 GxVertex2, *PGxVertex2;

struct GxVertex2 {
    undefined field0_0x0;
};

typedef struct CHmsEngine CHmsEngine, *PCHmsEngine;

struct CHmsEngine {
    undefined field0_0x0;
};

typedef struct SScoresContext SScoresContext, *PSScoresContext;

struct SScoresContext {
    undefined field0_0x0;
};

typedef struct SState SState, *PSState;

struct SState {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwId> CFastBuffer<class_CMwId>, *PCFastBuffer<class_CMwId>;

struct CFastBuffer<class_CMwId> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<unsigned_short,struct_SFastCat> CFastBufferCat<unsigned_short,struct_SFastCat>, *PCFastBufferCat<unsigned_short,struct_SFastCat>;

struct CFastBufferCat<unsigned_short,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpAnd CMwCmdExpAnd, *PCMwCmdExpAnd;

struct CMwCmdExpAnd {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnArticle CGameControlCardCtnArticle, *PCGameControlCardCtnArticle;

struct CGameControlCardCtnArticle {
    undefined field0_0x0;
};

typedef struct CSceneVehicleEmitter CSceneVehicleEmitter, *PCSceneVehicleEmitter;

struct CSceneVehicleEmitter {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLeagueManager SMwParamInfos_CGameLeagueManager, *PSMwParamInfos_CGameLeagueManager;

struct SMwParamInfos_CGameLeagueManager {
    undefined field0_0x0;
};

typedef struct CSceneListener CSceneListener, *PCSceneListener;

struct CSceneListener {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_ICONINFO - /winuser.h/_ICONINFO */

typedef struct SMwParamInfos_CXmlNod SMwParamInfos_CXmlNod, *PSMwParamInfos_CXmlNod;

struct SMwParamInfos_CXmlNod {
    undefined field0_0x0;
};

typedef struct CSceneVehicleCar CSceneVehicleCar, *PCSceneVehicleCar;

struct CSceneVehicleCar {
    undefined field0_0x0;
};

typedef struct SBlendShape2 SBlendShape2, *PSBlendShape2;

struct SBlendShape2 {
    undefined field0_0x0;
};

typedef struct sentry sentry, *Psentry;

struct sentry {
    undefined field0_0x0;
};

typedef struct SCompressPosition SCompressPosition, *PSCompressPosition;

struct SCompressPosition {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem> CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem>, *PCFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem>;

struct CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem> {
    undefined field0_0x0;
};

typedef struct SItTracksBlock SItTracksBlock, *PSItTracksBlock;

struct SItTracksBlock {
    undefined field0_0x0;
};

typedef enum EMainMenuAction {
} EMainMenuAction;

typedef struct SStat SStat, *PSStat;

struct SStat {
    undefined field0_0x0;
};

typedef struct CMotionSkel CMotionSkel, *PCMotionSkel;

struct CMotionSkel {
    undefined field0_0x0;
};

typedef struct GxFog GxFog, *PGxFog;

struct GxFog {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SSyncGpuQuery> CFastBuffer<struct_CVisionViewportDx9::SSyncGpuQuery>, *PCFastBuffer<struct_CVisionViewportDx9::SSyncGpuQuery>;

struct CFastBuffer<struct_CVisionViewportDx9::SSyncGpuQuery> {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_char,8,unsigned_long> CFixedArray<unsigned_char,8,unsigned_long>, *PCFixedArray<unsigned_char,8,unsigned_long>;

struct CFixedArray<unsigned_char,8,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CBoatTeamMateActionDesc CBoatTeamMateActionDesc, *PCBoatTeamMateActionDesc;

struct CBoatTeamMateActionDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetFileTransferDownload*> CFastBuffer<class_CNetFileTransferDownload*>, *PCFastBuffer<class_CNetFileTransferDownload*>;

struct CFastBuffer<class_CNetFileTransferDownload*> {
    undefined field0_0x0;
};

typedef struct CGameLadderScoresComputer CGameLadderScoresComputer, *PCGameLadderScoresComputer;

struct CGameLadderScoresComputer {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GxTexCoordSet> CFastArray<class_GxTexCoordSet>, *PCFastArray<class_GxTexCoordSet>;

struct CFastArray<class_GxTexCoordSet> {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> CFastBufferWheel<struct_CHmsDyna::SHistoryPoint>, *PCFastBufferWheel<struct_CHmsDyna::SHistoryPoint>;

struct CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRace CTrackManiaRace, *PCTrackManiaRace;

struct CTrackManiaRace {
    undefined field0_0x0;
};

typedef struct IDirectInputDevice8W IDirectInputDevice8W, *PIDirectInputDevice8W;

struct IDirectInputDevice8W {
    undefined field0_0x0;
};

typedef struct SBlock SBlock, *PSBlock;

struct SBlock {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLight SMwParamInfos_GxLight, *PSMwParamInfos_GxLight;

struct SMwParamInfos_GxLight {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SSurface> CFastBuffer<struct_CVisionViewportDx9::SSurface>, *PCFastBuffer<struct_CVisionViewportDx9::SSurface>;

struct CFastBuffer<struct_CVisionViewportDx9::SSurface> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugFileGPU::SSampler> CFastArray<struct_CPlugFileGPU::SSampler>, *PCFastArray<struct_CPlugFileGPU::SSampler>;

struct CFastArray<struct_CPlugFileGPU::SSampler> {
    undefined field0_0x0;
};

typedef struct CFuncClouds CFuncClouds, *PCFuncClouds;

struct CFuncClouds {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_STempBoneBox> CFastArray<struct_STempBoneBox>, *PCFastArray<struct_STempBoneBox>;

struct CFastArray<struct_STempBoneBox> {
    undefined field0_0x0;
};

typedef struct SBBoxBackup SBBoxBackup, *PSBBoxBackup;

struct SBBoxBackup {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnGhost SMwParamInfos_CGameCtnGhost, *PSMwParamInfos_CGameCtnGhost;

struct SMwParamInfos_CGameCtnGhost {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<char,struct_SFastCat> CFastBufferCat<char,struct_SFastCat>, *PCFastBufferCat<char,struct_SFastCat>;

struct CFastBufferCat<char,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CSceneObject> CFastBufferRef<class_CSceneObject>, *PCFastBufferRef<class_CSceneObject>;

struct CFastBufferRef<class_CSceneObject> {
    undefined field0_0x0;
};

typedef struct CPlugShaderSpritePath CPlugShaderSpritePath, *PCPlugShaderSpritePath;

struct CPlugShaderSpritePath {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_> CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>, *PCFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_>;

struct CFastBufferKey<class_CMwNodRef<class_CFuncKeysReal>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugFileGPUV*> CFastBuffer<class_CPlugFileGPUV*>, *PCFastBuffer<class_CPlugFileGPUV*>;

struct CFastBuffer<class_CPlugFileGPUV*> {
    undefined field0_0x0;
};

typedef struct CMwRefBuffer CMwRefBuffer, *PCMwRefBuffer;

struct CMwRefBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlScores2 SMwParamInfos_CTrackManiaControlScores2, *PSMwParamInfos_CTrackManiaControlScores2;

struct SMwParamInfos_CTrackManiaControlScores2 {
    undefined field0_0x0;
};

typedef struct CScenePath CScenePath, *PCScenePath;

struct CScenePath {
    undefined field0_0x0;
};

typedef enum LINE_CLASSIFICATION {
} LINE_CLASSIFICATION;

typedef struct CFastBuffer<struct_SPackModel> CFastBuffer<struct_SPackModel>, *PCFastBuffer<struct_SPackModel>;

struct CFastBuffer<struct_SPackModel> {
    undefined field0_0x0;
};

typedef struct CGameLadderRankingCtnChallengeAchievement CGameLadderRankingCtnChallengeAchievement, *PCGameLadderRankingCtnChallengeAchievement;

struct CGameLadderRankingCtnChallengeAchievement {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVar CMwCmdScriptVar, *PCMwCmdScriptVar;

struct CMwCmdScriptVar {
    undefined field0_0x0;
};

typedef struct CControlFrameStyled CControlFrameStyled, *PCControlFrameStyled;

struct CControlFrameStyled {
    undefined field0_0x0;
};

typedef struct CControlEffectMaster CControlEffectMaster, *PCControlEffectMaster;

struct CControlEffectMaster {
    undefined field0_0x0;
};

typedef struct CConfig CConfig, *PCConfig;

struct CConfig {
    undefined field0_0x0;
};

typedef struct SVertexDataLayer SVertexDataLayer, *PSVertexDataLayer;

struct SVertexDataLayer {
    undefined field0_0x0;
};

typedef struct GmVector2<unsigned_short> GmVector2<unsigned_short>, *PGmVector2<unsigned_short>;

struct GmVector2<unsigned_short> {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugIndexBuffer*> CFastCallback1P<class_CPlugIndexBuffer*>, *PCFastCallback1P<class_CPlugIndexBuffer*>;

struct CFastCallback1P<class_CPlugIndexBuffer*> {
    undefined field0_0x0;
};

typedef struct CGameScene CGameScene, *PCGameScene;

struct CGameScene {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCard SMwParamInfos_CGameControlCard, *PSMwParamInfos_CGameControlCard;

struct SMwParamInfos_CGameControlCard {
    undefined field0_0x0;
};

typedef struct CGameNetFormGameSync CGameNetFormGameSync, *PCGameNetFormGameSync;

struct CGameNetFormGameSync {
    undefined field0_0x0;
};

typedef struct localeinfo_struct localeinfo_struct, *Plocaleinfo_struct;

typedef struct threadlocaleinfostruct threadlocaleinfostruct, *Pthreadlocaleinfostruct;

typedef struct threadmbcinfostruct threadmbcinfostruct, *Pthreadmbcinfostruct;

typedef struct localerefcount localerefcount, *Plocalerefcount;

typedef struct lconv lconv, *Plconv;

typedef struct __lc_time_data __lc_time_data, *P__lc_time_data;

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
    wchar_t *_W_decimal_point;
    wchar_t *_W_thousands_sep;
    wchar_t *_W_int_curr_symbol;
    wchar_t *_W_currency_symbol;
    wchar_t *_W_mon_decimal_point;
    wchar_t *_W_mon_thousands_sep;
    wchar_t *_W_positive_sign;
    wchar_t *_W_negative_sign;
};

struct localerefcount {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
};

struct threadlocaleinfostruct {
    int refcount;
    uint lc_codepage;
    uint lc_collate_cp;
    uint lc_time_cp;
    struct localerefcount lc_category[6];
    int lc_clike;
    int mb_cur_max;
    int *lconv_intl_refcount;
    int *lconv_num_refcount;
    int *lconv_mon_refcount;
    struct lconv *lconv;
    int *ctype1_refcount;
    ushort *ctype1;
    ushort *pctype;
    uchar *pclmap;
    uchar *pcumap;
    struct __lc_time_data *lc_time_curr;
    wchar_t *locale_name[6];
};

struct threadmbcinfostruct {
    int refcount;
    int mbcodepage;
    int ismbcodepage;
    ushort mbulinfo[6];
    uchar mbctype[257];
    uchar mbcasemap[256];
    wchar_t *mblocalename;
};

struct localeinfo_struct {
    struct threadlocaleinfostruct *locinfo;
    struct threadmbcinfostruct *mbcinfo;
};

struct __lc_time_data {
    char *wday_abbr[7];
    char *wday[7];
    char *month_abbr[12];
    char *month[12];
    char *ampm[2];
    char *ww_sdatefmt;
    char *ww_ldatefmt;
    char *ww_timefmt;
    int ww_caltype;
    int refcount;
    wchar_t *_W_wday_abbr[7];
    wchar_t *_W_wday[7];
    wchar_t *_W_month_abbr[12];
    wchar_t *_W_month[12];
    wchar_t *_W_ampm[2];
    wchar_t *_W_ww_sdatefmt;
    wchar_t *_W_ww_ldatefmt;
    wchar_t *_W_ww_timefmt;
    wchar_t *_W_ww_locale_name;
};

typedef struct IDirect3D9 IDirect3D9, *PIDirect3D9;

struct IDirect3D9 {
    undefined field0_0x0;
};

typedef struct SFlags SFlags, *PSFlags;

struct SFlags {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameFid SMwParamInfos_CGameFid, *PSMwParamInfos_CGameFid;

struct SMwParamInfos_CGameFid {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderCamera SMwParamInfos_CPlugBitmapRenderCamera, *PSMwParamInfos_CPlugBitmapRenderCamera;

struct SMwParamInfos_CPlugBitmapRenderCamera {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugMaterialFxGenCV SMwParamInfos_CPlugMaterialFxGenCV, *PSMwParamInfos_CPlugMaterialFxGenCV;

struct SMwParamInfos_CPlugMaterialFxGenCV {
    undefined field0_0x0;
};

typedef struct CNetConnectedClient CNetConnectedClient, *PCNetConnectedClient;

struct CNetConnectedClient {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SOldIgs> CFastBuffer<struct_SOldIgs>, *PCFastBuffer<struct_SOldIgs>;

struct CFastBuffer<struct_SOldIgs> {
    undefined field0_0x0;
};

typedef struct SManiaCodeContext SManiaCodeContext, *PSManiaCodeContext;

struct SManiaCodeContext {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnPainterSetting SMwParamInfos_CGameCtnPainterSetting, *PSMwParamInfos_CGameCtnPainterSetting;

struct SMwParamInfos_CGameCtnPainterSetting {
    undefined field0_0x0;
};

typedef struct SStateSplit SStateSplit, *PSStateSplit;

struct SStateSplit {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerCharacter SMwParamInfos_CMotionManagerCharacter, *PSMwParamInfos_CMotionManagerCharacter;

struct SMwParamInfos_CMotionManagerCharacter {
    undefined field0_0x0;
};

typedef enum ECallback {
} ECallback;

typedef struct CFastCallback1P<class_CPlugShader*> CFastCallback1P<class_CPlugShader*>, *PCFastCallback1P<class_CPlugShader*>;

struct CFastCallback1P<class_CPlugShader*> {
    undefined field0_0x0;
};

typedef struct CGameGeneralScores CGameGeneralScores, *PCGameGeneralScores;

struct CGameGeneralScores {
    undefined field0_0x0;
};

typedef struct STexStageState STexStageState, *PSTexStageState;

struct STexStageState {
    undefined field0_0x0;
};

typedef struct CFastCallback CFastCallback, *PCFastCallback;

struct CFastCallback {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>, *PCFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat>;

struct CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SUrl> CFastBuffer<struct_CGameMasterServer::SUrl>, *PCFastBuffer<struct_CGameMasterServer::SUrl>;

struct CFastBuffer<struct_CGameMasterServer::SUrl> {
    undefined field0_0x0;
};

typedef struct SDownloadedData SDownloadedData, *PSDownloadedData;

struct SDownloadedData {
    undefined field0_0x0;
};

typedef struct CPlugLight CPlugLight, *PCPlugLight;

struct CPlugLight {
    undefined field0_0x0;
};

typedef struct SFilteredScores SFilteredScores, *PSFilteredScores;

struct SFilteredScores {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>, *PCFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>;

struct CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoFlat SMwParamInfos_CGameCtnBlockInfoFlat, *PSMwParamInfos_CGameCtnBlockInfoFlat;

struct SMwParamInfos_CGameCtnBlockInfoFlat {
    undefined field0_0x0;
};

typedef struct SPlugTreeLocatedPair SPlugTreeLocatedPair, *PSPlugTreeLocatedPair;

struct SPlugTreeLocatedPair {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamReal> CMwParamFastBuffer<class_CMwParamReal>, *PCMwParamFastBuffer<class_CMwParamReal>;

struct CMwParamFastBuffer<class_CMwParamReal> {
    undefined field0_0x0;
};

typedef struct CSceneMobilAbsorbContact CSceneMobilAbsorbContact, *PCSceneMobilAbsorbContact;

struct CSceneMobilAbsorbContact {
    undefined field0_0x0;
};

typedef struct SRenderInfoDx9 SRenderInfoDx9, *PSRenderInfoDx9;

struct SRenderInfoDx9 {
    undefined field0_0x0;
};

typedef struct CSystemArchiveNod CSystemArchiveNod, *PCSystemArchiveNod;

struct CSystemArchiveNod {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockMusicEffect SMwParamInfos_CGameCtnMediaBlockMusicEffect, *PSMwParamInfos_CGameCtnMediaBlockMusicEffect;

struct SMwParamInfos_CGameCtnMediaBlockMusicEffect {
    undefined field0_0x0;
};

typedef enum EMessageType {
} EMessageType;

typedef struct CFastBuffer<class_CGameCtnArticle*> CFastBuffer<class_CGameCtnArticle*>, *PCFastBuffer<class_CGameCtnArticle*>;

struct CFastBuffer<class_CGameCtnArticle*> {
    undefined field0_0x0;
};

typedef struct CMotionTrack CMotionTrack, *PCMotionTrack;

struct CMotionTrack {
    undefined field0_0x0;
};

typedef struct GmCamFreeVal GmCamFreeVal, *PGmCamFreeVal;

struct GmCamFreeVal {
    undefined field0_0x0;
};

typedef enum ETrackManiaNetworkGameMode {
} ETrackManiaNetworkGameMode;

typedef struct CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_531 - /winbase.h/_struct_531 */

typedef struct CMwNodRef<class_CGameAvatar> CMwNodRef<class_CGameAvatar>, *PCMwNodRef<class_CGameAvatar>;

struct CMwNodRef<class_CGameAvatar> {
    undefined field0_0x0;
};

typedef struct CPlugMaterial CPlugMaterial, *PCPlugMaterial;

struct CPlugMaterial {
    undefined field0_0x0;
};

typedef struct CGenAudioSoundEngine<class_COalAudioSound> CGenAudioSoundEngine<class_COalAudioSound>, *PCGenAudioSoundEngine<class_COalAudioSound>;

struct CGenAudioSoundEngine<class_COalAudioSound> {
    undefined field0_0x0;
};

typedef struct CNetTransferInfoQueue CNetTransferInfoQueue, *PCNetTransferInfoQueue;

struct CNetTransferInfoQueue {
    undefined field0_0x0;
};

typedef struct CCallbackComputeForces CCallbackComputeForces, *PCCallbackComputeForces;

struct CCallbackComputeForces {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFileGPUP> CMwNodRef<class_CPlugFileGPUP>, *PCMwNodRef<class_CPlugFileGPUP>;

struct CMwNodRef<class_CPlugFileGPUP> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwNodRef<class_CPlugShader>_> CFastArray<class_CMwNodRef<class_CPlugShader>_>, *PCFastArray<class_CMwNodRef<class_CPlugShader>_>;

struct CFastArray<class_CMwNodRef<class_CPlugShader>_> {
    undefined field0_0x0;
};

typedef struct TiXmlText TiXmlText, *PTiXmlText;

struct TiXmlText {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengePool> CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengePool>, *PCFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengePool>;

struct CFastBuffer<struct_CTrackManiaPlayerProfile::SSoloChallengePool> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_519 - /winbase.h/_struct_519 */

typedef struct CFastArray<struct_CSceneMobilSnow::SSnowFlakes> CFastArray<struct_CSceneMobilSnow::SSnowFlakes>, *PCFastArray<struct_CSceneMobilSnow::SSnowFlakes>;

struct CFastArray<struct_CSceneMobilSnow::SSnowFlakes> {
    undefined field0_0x0;
};

typedef struct SAvatarMessage SAvatarMessage, *PSAvatarMessage;

struct SAvatarMessage {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameNetPlayerInfo*> CFastBuffer<class_CGameNetPlayerInfo*>, *PCFastBuffer<class_CGameNetPlayerInfo*>;

struct CFastBuffer<class_CGameNetPlayerInfo*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEffectSwitchStyle SMwParamInfos_CControlEffectSwitchStyle, *PSMwParamInfos_CControlEffectSwitchStyle;

struct SMwParamInfos_CControlEffectSwitchStyle {
    undefined field0_0x0;
};

typedef struct CFastCallbackInstance2P<class_CGameCtnMediaBlockEditorTriangles,enum_CGameControlMove::EMoveEvent,class_GmVec3_const&> CFastCallbackInstance2P<class_CGameCtnMediaBlockEditorTriangles,enum_CGameControlMove::EMoveEvent,class_GmVec3_const&>, *PCFastCallbackInstance2P<class_CGameCtnMediaBlockEditorTriangles,enum_CGameControlMove::EMoveEvent,class_GmVec3_const&>;

struct CFastCallbackInstance2P<class_CGameCtnMediaBlockEditorTriangles,enum_CGameControlMove::EMoveEvent,class_GmVec3_const&> {
    undefined field0_0x0;
};

typedef enum EManiaCodeActionType {
} EManiaCodeActionType;

typedef struct SMwParamInfos_CFuncSkel SMwParamInfos_CFuncSkel, *PSMwParamInfos_CFuncSkel;

struct SMwParamInfos_CFuncSkel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlaygroundInterface SMwParamInfos_CGamePlaygroundInterface, *PSMwParamInfos_CGamePlaygroundInterface;

struct SMwParamInfos_CGamePlaygroundInterface {
    undefined field0_0x0;
};

typedef enum EGxTexAddress {
} EGxTexAddress;

typedef struct CClassicBufferPart CClassicBufferPart, *PCClassicBufferPart;

struct CClassicBufferPart {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlForm SMwParamInfos_CControlForm, *PSMwParamInfos_CControlForm;

struct SMwParamInfos_CControlForm {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat> CFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat>, *PCFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat>;

struct CFastBufferCat<struct_CFuncPuffLull::SPuffLull,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_IDirect3DIndexBuffer9*,2,unsigned_long> CFixedArray<struct_IDirect3DIndexBuffer9*,2,unsigned_long>, *PCFixedArray<struct_IDirect3DIndexBuffer9*,2,unsigned_long>;

struct CFixedArray<struct_IDirect3DIndexBuffer9*,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlCredit::SElement> CFastBuffer<struct_CControlCredit::SElement>, *PCFastBuffer<struct_CControlCredit::SElement>;

struct CFastBuffer<struct_CControlCredit::SElement> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentVec3 CMwCmdAffectIdentVec3, *PCMwCmdAffectIdentVec3;

struct CMwCmdAffectIdentVec3 {
    undefined field0_0x0;
};

typedef struct CGameControlCardChampionship CGameControlCardChampionship, *PCGameControlCardChampionship;

struct CGameControlCardChampionship {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_GmNat2_const&> CFastCallback1P<class_GmNat2_const&>, *PCFastCallback1P<class_GmNat2_const&>;

struct CFastCallback1P<class_GmNat2_const&> {
    undefined field0_0x0;
};

typedef struct CPlugFileVHlsl CPlugFileVHlsl, *PCPlugFileVHlsl;

struct CPlugFileVHlsl {
    undefined field0_0x0;
};

typedef struct STgaHeader STgaHeader, *PSTgaHeader;

struct STgaHeader {
    undefined field0_0x0;
};

typedef struct GmSurfBox GmSurfBox, *PGmSurfBox;

struct GmSurfBox {
    undefined field0_0x0;
};

typedef struct CSceneLight CSceneLight, *PCSceneLight;

struct CSceneLight {
    undefined field0_0x0;
};

typedef struct GmLocVal GmLocVal, *PGmLocVal;

struct GmLocVal {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugModelTree> CFastBufferRef<class_CPlugModelTree>, *PCFastBufferRef<class_CPlugModelTree>;

struct CFastBufferRef<class_CPlugModelTree> {
    undefined field0_0x0;
};

typedef enum EBalanceGroup {
} EBalanceGroup;

typedef struct CMwCmdAffectParamIso4 CMwCmdAffectParamIso4, *PCMwCmdAffectParamIso4;

struct CMwCmdAffectParamIso4 {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugFileSnd*> CFastArray<class_CPlugFileSnd*>, *PCFastArray<class_CPlugFileSnd*>;

struct CFastArray<class_CPlugFileSnd*> {
    undefined field0_0x0;
};

typedef struct CGameCtnBlock CGameCtnBlock, *PCGameCtnBlock;

struct CGameCtnBlock {
    undefined field0_0x0;
};

typedef struct SGetManialinkResourceCmd SGetManialinkResourceCmd, *PSGetManialinkResourceCmd;

struct SGetManialinkResourceCmd {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_SStdGpuMask,29,unsigned_long> CFixedArray<struct_SStdGpuMask,29,unsigned_long>, *PCFixedArray<struct_SStdGpuMask,29,unsigned_long>;

struct CFixedArray<struct_SStdGpuMask,29,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SBitmapSpecular SBitmapSpecular, *PSBitmapSpecular;

struct SBitmapSpecular {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastCrypt<unsigned_long>_> CFastBuffer<class_CFastCrypt<unsigned_long>_>, *PCFastBuffer<class_CFastCrypt<unsigned_long>_>;

struct CFastBuffer<class_CFastCrypt<unsigned_long>_> {
    undefined field0_0x0;
};

typedef struct CSceneToySea CSceneToySea, *PCSceneToySea;

struct CSceneToySea {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_GmSurfMesh::SMeshToMerge> CFastBuffer<struct_GmSurfMesh::SMeshToMerge>, *PCFastBuffer<struct_GmSurfMesh::SMeshToMerge>;

struct CFastBuffer<struct_GmSurfMesh::SMeshToMerge> {
    undefined field0_0x0;
};

typedef struct GmFrustumLocated GmFrustumLocated, *PGmFrustumLocated;

struct GmFrustumLocated {
    undefined field0_0x0;
};

typedef struct SSceneLoc SSceneLoc, *PSSceneLoc;

struct SSceneLoc {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Ident CMwCmdExpVec3Ident, *PCMwCmdExpVec3Ident;

struct CMwCmdExpVec3Ident {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SPlugGpuLoadFx> CFastArray<struct_SPlugGpuLoadFx>, *PCFastArray<struct_SPlugGpuLoadFx>;

struct CFastArray<struct_SPlugGpuLoadFx> {
    undefined field0_0x0;
};

typedef struct CSceneField CSceneField, *PCSceneField;

struct CSceneField {
    undefined field0_0x0;
};

typedef struct CGameNetSearchRequest_Players CGameNetSearchRequest_Players, *PCGameNetSearchRequest_Players;

struct CGameNetSearchRequest_Players {
    undefined field0_0x0;
};

typedef struct CHmsDyna CHmsDyna, *PCHmsDyna;

struct CHmsDyna {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamReal> CMwParamFastBufferCat<class_CMwParamReal>, *PCMwParamFastBufferCat<class_CMwParamReal>;

struct CMwParamFastBufferCat<class_CMwParamReal> {
    undefined field0_0x0;
};

typedef struct SBitToRenderState SBitToRenderState, *PSBitToRenderState;

struct SBitToRenderState {
    undefined field0_0x0;
};

typedef struct SGameModeScores SGameModeScores, *PSGameModeScores;

struct SGameModeScores {
    undefined field0_0x0;
};

typedef struct SColOctreeCell SColOctreeCell, *PSColOctreeCell;

struct SColOctreeCell {
    undefined field0_0x0;
};

typedef struct SNetPlayerProfileHeaderOnlineSupportKey SNetPlayerProfileHeaderOnlineSupportKey, *PSNetPlayerProfileHeaderOnlineSupportKey;

struct SNetPlayerProfileHeaderOnlineSupportKey {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneMobil>_> CFastBuffer<class_CMwNodRef<class_CSceneMobil>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneMobil>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneMobil>_> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockTrails CMwClassInfoCGameCtnMediaBlockTrails, *PCMwClassInfoCGameCtnMediaBlockTrails;

struct CMwClassInfoCGameCtnMediaBlockTrails {
    undefined field0_0x0;
};

typedef struct CMwCmdExpInf CMwCmdExpInf, *PCMwCmdExpInf;

struct CMwCmdExpInf {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerWeathers SMwParamInfos_CMotionManagerWeathers, *PSMwParamInfos_CMotionManagerWeathers;

struct SMwParamInfos_CMotionManagerWeathers {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwRefBuffer SMwParamInfos_CMwRefBuffer, *PSMwParamInfos_CMwRefBuffer;

struct SMwParamInfos_CMwRefBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarBool SMwParamInfos_CMwCmdScriptVarBool, *PSMwParamInfos_CMwCmdScriptVarBool;

struct SMwParamInfos_CMwCmdScriptVarBool {
    undefined field0_0x0;
};

typedef struct CGameLadderRankingLeague CGameLadderRankingLeague, *PCGameLadderRankingLeague;

struct CGameLadderRankingLeague {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdBufferCore SMwParamInfos_CMwCmdBufferCore, *PSMwParamInfos_CMwCmdBufferCore;

struct SMwParamInfos_CMwCmdBufferCore {
    undefined field0_0x0;
};

typedef enum EMotoVersion {
} EMotoVersion;

typedef struct CTrackManiaEditorSimple CTrackManiaEditorSimple, *PCTrackManiaEditorSimple;

struct CTrackManiaEditorSimple {
    undefined field0_0x0;
};

typedef struct SGeomSkinRemap SGeomSkinRemap, *PSGeomSkinRemap;

struct SGeomSkinRemap {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CBlendShapeVertexOld> CFastBuffer<class_CBlendShapeVertexOld>, *PCFastBuffer<class_CBlendShapeVertexOld>;

struct CFastBuffer<class_CBlendShapeVertexOld> {
    undefined field0_0x0;
};

typedef struct CGameRemoteBufferDataInfoRankings CGameRemoteBufferDataInfoRankings, *PCGameRemoteBufferDataInfoRankings;

struct CGameRemoteBufferDataInfoRankings {
    undefined field0_0x0;
};

typedef struct CSceneVehicleEnvironment CSceneVehicleEnvironment, *PCSceneVehicleEnvironment;

struct CSceneVehicleEnvironment {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SMeshGroup> CFastBuffer<struct_SMeshGroup>, *PCFastBuffer<struct_SMeshGroup>;

struct CFastBuffer<struct_SMeshGroup> {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnNetServerInfo CGameControlCardCtnNetServerInfo, *PCGameControlCardCtnNetServerInfo;

struct CGameControlCardCtnNetServerInfo {
    undefined field0_0x0;
};

typedef struct CTeamMateInfo CTeamMateInfo, *PCTeamMateInfo;

struct CTeamMateInfo {
    undefined field0_0x0;
};

typedef struct CGameCtnSlideShow CGameCtnSlideShow, *PCGameCtnSlideShow;

struct CGameCtnSlideShow {
    undefined field0_0x0;
};

typedef struct SMeshOctreeCell SMeshOctreeCell, *PSMeshOctreeCell;

struct SMeshOctreeCell {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnPainter SMwParamInfos_CGameCtnPainter, *PSMwParamInfos_CGameCtnPainter;

struct SMwParamInfos_CGameCtnPainter {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum_EPlugVDclSpace,22,unsigned_long> CFixedArray<enum_EPlugVDclSpace,22,unsigned_long>, *PCFixedArray<enum_EPlugVDclSpace,22,unsigned_long>;

struct CFixedArray<enum_EPlugVDclSpace,22,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParam CMwCmdAffectParam, *PCMwCmdAffectParam;

struct CMwCmdAffectParam {
    undefined field0_0x0;
};

typedef struct CControlPager CControlPager, *PCControlPager;

struct CControlPager {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSurvivalScore*> CFastBuffer<struct_SSurvivalScore*>, *PCFastBuffer<struct_SSurvivalScore*>;

struct CFastBuffer<struct_SSurvivalScore*> {
    undefined field0_0x0;
};

typedef struct CBoatTeamMateLocationDesc CBoatTeamMateLocationDesc, *PCBoatTeamMateLocationDesc;

struct CBoatTeamMateLocationDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnGhost*> CFastBuffer<class_CGameCtnGhost*>, *PCFastBuffer<class_CGameCtnGhost*>;

struct CFastBuffer<class_CGameCtnGhost*> {
    undefined field0_0x0;
};

typedef struct CSceneFxSuperSample CSceneFxSuperSample, *PCSceneFxSuperSample;

struct CSceneFxSuperSample {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaClip CGameCtnMediaClip, *PCGameCtnMediaClip;

struct CGameCtnMediaClip {
    undefined field0_0x0;
};

typedef struct SDeprecatedPlayerCampaignFilteredSkillScore SDeprecatedPlayerCampaignFilteredSkillScore, *PSDeprecatedPlayerCampaignFilteredSkillScore;

struct SDeprecatedPlayerCampaignFilteredSkillScore {
    undefined field0_0x0;
};

typedef struct SStreamDeclComp SStreamDeclComp, *PSStreamDeclComp;

struct SStreamDeclComp {
    undefined field0_0x0;
};

typedef struct SSpriteF SSpriteF, *PSSpriteF;

struct SSpriteF {
    undefined field0_0x0;
};

typedef struct GmQuat GmQuat, *PGmQuat;

struct GmQuat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraGame SMwParamInfos_CGameCtnMediaBlockCameraGame, *PSMwParamInfos_CGameCtnMediaBlockCameraGame;

struct SMwParamInfos_CGameCtnMediaBlockCameraGame {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentString CMwCmdAffectIdentString, *PCMwCmdAffectIdentString;

struct CMwCmdAffectIdentString {
    undefined field0_0x0;
};

typedef struct CPlugVisualPath CPlugVisualPath, *PCPlugVisualPath;

struct CPlugVisualPath {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmIso4> CFastArray<class_GmIso4>, *PCFastArray<class_GmIso4>;

struct CFastArray<class_GmIso4> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<class_CMwNodRef<class_GxFog>_> CFastBufferKey<class_CMwNodRef<class_GxFog>_>, *PCFastBufferKey<class_CMwNodRef<class_GxFog>_>;

struct CFastBufferKey<class_CMwNodRef<class_GxFog>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneGate>_> CFastBuffer<class_CMwNodRef<class_CSceneGate>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneGate>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneGate>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc>, *PCFastBuffer<struct_CHmsVPackerCell::SLightBallLoc>;

struct CFastBuffer<struct_CHmsVPackerCell::SLightBallLoc> {
    undefined field0_0x0;
};

typedef struct CGameAnswerData CGameAnswerData, *PCGameAnswerData;

struct CGameAnswerData {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnApp::STip> CFastBuffer<struct_CGameCtnApp::STip>, *PCFastBuffer<struct_CGameCtnApp::STip>;

struct CFastBuffer<struct_CGameCtnApp::STip> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneSector SMwParamInfos_CSceneSector, *PSMwParamInfos_CSceneSector;

struct SMwParamInfos_CSceneSector {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleMaterial SMwParamInfos_CSceneVehicleMaterial, *PSMwParamInfos_CSceneVehicleMaterial;

struct SMwParamInfos_CSceneVehicleMaterial {
    undefined field0_0x0;
};

typedef struct CControlEffectSwitchStyle CControlEffectSwitchStyle, *PCControlEffectSwitchStyle;

struct CControlEffectSwitchStyle {
    undefined field0_0x0;
};

typedef struct SRpcPlayerNetworkInfo SRpcPlayerNetworkInfo, *PSRpcPlayerNetworkInfo;

struct SRpcPlayerNetworkInfo {
    undefined field0_0x0;
};

typedef struct CSceneFxCompo CSceneFxCompo, *PCSceneFxCompo;

struct CSceneFxCompo {
    undefined field0_0x0;
};

typedef struct CSceneVehicleBallTuning CSceneVehicleBallTuning, *PCSceneVehicleBallTuning;

struct CSceneVehicleBallTuning {
    undefined field0_0x0;
};

typedef struct CFuncKeysReals CFuncKeysReals, *PCFuncKeysReals;

struct CFuncKeysReals {
    undefined field0_0x0;
};

typedef struct CGamePlayerOfficialScores CGamePlayerOfficialScores, *PCGamePlayerOfficialScores;

struct CGamePlayerOfficialScores {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular>, *PCFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular>;

struct CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecular> {
    undefined field0_0x0;
};

typedef struct CGameCtnEditorScenePocLink CGameCtnEditorScenePocLink, *PCGameCtnEditorScenePocLink;

struct CGameCtnEditorScenePocLink {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameCtnGhost> CFastBufferRef<class_CGameCtnGhost>, *PCFastBufferRef<class_CGameCtnGhost>;

struct CFastBufferRef<class_CGameCtnGhost> {
    undefined field0_0x0;
};

typedef struct CControlField2 CControlField2, *PCControlField2;

struct CControlField2 {
    undefined field0_0x0;
};

typedef struct CMwCmdWait CMwCmdWait, *PCMwCmdWait;

struct CMwCmdWait {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SFeature> CFastBuffer<struct_CGameMasterServer::SFeature>, *PCFastBuffer<struct_CGameMasterServer::SFeature>;

struct CFastBuffer<struct_CGameMasterServer::SFeature> {
    undefined field0_0x0;
};

typedef struct CMotionSkelSimple CMotionSkelSimple, *PCMotionSkelSimple;

struct CMotionSkelSimple {
    undefined field0_0x0;
};

typedef struct CSystemFidParameters CSystemFidParameters, *PCSystemFidParameters;

struct CSystemFidParameters {
    undefined field0_0x0;
};

typedef struct SPlayerTagConfig SPlayerTagConfig, *PSPlayerTagConfig;

struct SPlayerTagConfig {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CSysFidNodRef<class_CFuncShader>_> CFastArray<class_CSysFidNodRef<class_CFuncShader>_>, *PCFastArray<class_CSysFidNodRef<class_CFuncShader>_>;

struct CFastArray<class_CSysFidNodRef<class_CFuncShader>_> {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>, *PCFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>;

struct CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> {
    undefined field0_0x0;
};

typedef struct CHmsPrecalcRender CHmsPrecalcRender, *PCHmsPrecalcRender;

struct CHmsPrecalcRender {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnMenus::SGetManialinkResourceCmd> CMwNodRef<class_CGameCtnMenus::SGetManialinkResourceCmd>, *PCMwNodRef<class_CGameCtnMenus::SGetManialinkResourceCmd>;

struct CMwNodRef<class_CGameCtnMenus::SGetManialinkResourceCmd> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugBitmap::SPixCopyDesc> CFastBuffer<struct_CPlugBitmap::SPixCopyDesc>, *PCFastBuffer<struct_CPlugBitmap::SPixCopyDesc>;

struct CFastBuffer<struct_CPlugBitmap::SPixCopyDesc> {
    undefined field0_0x0;
};

typedef struct CSceneToyFilaments CSceneToyFilaments, *PCSceneToyFilaments;

struct CSceneToyFilaments {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>::SKey> CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>::SKey>, *PCFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>::SKey> {
    undefined field0_0x0;
};

typedef struct CMwId CMwId, *PCMwId;

struct CMwId {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFidFile*> CFastBuffer<class_CSystemFidFile*>, *PCFastBuffer<class_CSystemFidFile*>;

struct CFastBuffer<class_CSystemFidFile*> {
    undefined field0_0x0;
};

typedef struct CSystemCmdDuplicateNod CSystemCmdDuplicateNod, *PCSystemCmdDuplicateNod;

struct CSystemCmdDuplicateNod {
    undefined field0_0x0;
};

typedef enum EConvertMethod {
} EConvertMethod;

typedef struct SFilteredPlayerRank SFilteredPlayerRank, *PSFilteredPlayerRank;

struct SFilteredPlayerRank {
    undefined field0_0x0;
};

typedef struct CSceneInfoFocus CSceneInfoFocus, *PCSceneInfoFocus;

struct CSceneInfoFocus {
    undefined field0_0x0;
};

typedef struct STextureConvertRenderToStatic STextureConvertRenderToStatic, *PSTextureConvertRenderToStatic;

struct STextureConvertRenderToStatic {
    undefined field0_0x0;
};

typedef struct CClassicI18n CClassicI18n, *PCClassicI18n;

struct CClassicI18n {
    undefined field0_0x0;
};

typedef struct TiXmlUnknown TiXmlUnknown, *PTiXmlUnknown;

struct TiXmlUnknown {
    undefined field0_0x0;
};

typedef struct CGameNetClient CGameNetClient, *PCGameNetClient;

struct CGameNetClient {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SGameCtnMediaClipTriggerTime> CFastBuffer<struct_SGameCtnMediaClipTriggerTime>, *PCFastBuffer<struct_SGameCtnMediaClipTriggerTime>;

struct CFastBuffer<struct_SGameCtnMediaClipTriggerTime> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFileFidContainer::SFileDesc> CFastBuffer<struct_CPlugFileFidContainer::SFileDesc>, *PCFastBuffer<struct_CPlugFileFidContainer::SFileDesc>;

struct CFastBuffer<struct_CPlugFileFidContainer::SFileDesc> {
    undefined field0_0x0;
};

typedef struct CMwIdStatic CMwIdStatic, *PCMwIdStatic;

struct CMwIdStatic {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrackMobilPitchin SMwParamInfos_CMotionTrackMobilPitchin, *PSMwParamInfos_CMotionTrackMobilPitchin;

struct SMwParamInfos_CMotionTrackMobilPitchin {
    undefined field0_0x0;
};

typedef struct SBlockState SBlockState, *PSBlockState;

struct SBlockState {
    undefined field0_0x0;
};

typedef struct STrack STrack, *PSTrack;

struct STrack {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraGame CMwClassInfoCGameCtnMediaBlockCameraGame, *PCMwClassInfoCGameCtnMediaBlockCameraGame;

struct CMwClassInfoCGameCtnMediaBlockCameraGame {
    undefined field0_0x0;
};

typedef struct CHmsPackLightMap CHmsPackLightMap, *PCHmsPackLightMap;

struct CHmsPackLightMap {
    undefined field0_0x0;
};

typedef struct CPlugVisualVertexs CPlugVisualVertexs, *PCPlugVisualVertexs;

struct CPlugVisualVertexs {
    undefined field0_0x0;
};

typedef struct SLocalisedMessage SLocalisedMessage, *PSLocalisedMessage;

struct SLocalisedMessage {
    undefined field0_0x0;
};

typedef struct CHmsCamera CHmsCamera, *PCHmsCamera;

struct CHmsCamera {
    undefined field0_0x0;
};

typedef struct STexCoordMerge STexCoordMerge, *PSTexCoordMerge;

struct STexCoordMerge {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoClip CGameCtnBlockInfoClip, *PCGameCtnBlockInfoClip;

struct CGameCtnBlockInfoClip {
    undefined field0_0x0;
};

typedef struct SCubeDeform SCubeDeform, *PSCubeDeform;

struct SCubeDeform {
    undefined field0_0x0;
};

typedef struct CSceneFxToneMapping CSceneFxToneMapping, *PCSceneFxToneMapping;

struct CSceneFxToneMapping {
    undefined field0_0x0;
};

typedef enum EDoMobilPtrVersion {
} EDoMobilPtrVersion;

typedef struct SPlugDecl2Dx9 SPlugDecl2Dx9, *PSPlugDecl2Dx9;

struct SPlugDecl2Dx9 {
    undefined field0_0x0;
};

typedef enum EPreLight {
} EPreLight;

typedef struct CGameCtnMediaBlockCameraCustom CGameCtnMediaBlockCameraCustom, *PCGameCtnMediaBlockCameraCustom;

struct CGameCtnMediaBlockCameraCustom {
    undefined field0_0x0;
};

typedef struct CMwCmdExpBoolFunction CMwCmdExpBoolFunction, *PCMwCmdExpBoolFunction;

struct CMwCmdExpBoolFunction {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugSurface> CMwNodRef<class_CPlugSurface>, *PCMwNodRef<class_CPlugSurface>;

struct CMwNodRef<class_CPlugSurface> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugShader::SFxValue> CFastBuffer<struct_CPlugShader::SFxValue>, *PCFastBuffer<struct_CPlugShader::SFxValue>;

struct CFastBuffer<struct_CPlugShader::SFxValue> {
    undefined field0_0x0;
};

typedef struct CVirtualisedBuffer<class_CMwNod*> CVirtualisedBuffer<class_CMwNod*>, *PCVirtualisedBuffer<class_CMwNod*>;

struct CVirtualisedBuffer<class_CMwNod*> {
    undefined field0_0x0;
};

typedef struct SSaveTextureParam SSaveTextureParam, *PSSaveTextureParam;

struct SSaveTextureParam {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTriangles CGameCtnMediaBlockTriangles, *PCGameCtnMediaBlockTriangles;

struct CGameCtnMediaBlockTriangles {
    undefined field0_0x0;
};

typedef struct CGameBulletModel CGameBulletModel, *PCGameBulletModel;

struct CGameBulletModel {
    undefined field0_0x0;
};

typedef struct CMwCmdSleep CMwCmdSleep, *PCMwCmdSleep;

struct CMwCmdSleep {
    undefined field0_0x0;
};

typedef struct CSceneGate CSceneGate, *PCSceneGate;

struct CSceneGate {
    undefined field0_0x0;
};

typedef struct SBuildPageParams SBuildPageParams, *PSBuildPageParams;

struct SBuildPageParams {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SLineColor> CFastBuffer<struct_CPlugModelMesh::SLineColor>, *PCFastBuffer<struct_CPlugModelMesh::SLineColor>;

struct CFastBuffer<struct_CPlugModelMesh::SLineColor> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmMat3> CFastBuffer<class_GmMat3>, *PCFastBuffer<class_GmMat3>;

struct CFastBuffer<class_GmMat3> {
    undefined field0_0x0;
};

typedef struct CFastCallback2P<class_CGameMasterServerRequestParams_const&,unsigned_long&> CFastCallback2P<class_CGameMasterServerRequestParams_const&,unsigned_long&>, *PCFastCallback2P<class_CGameMasterServerRequestParams_const&,unsigned_long&>;

struct CFastCallback2P<class_CGameMasterServerRequestParams_const&,unsigned_long&> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdIf SMwParamInfos_CMwCmdIf, *PSMwParamInfos_CMwCmdIf;

struct SMwParamInfos_CMwCmdIf {
    undefined field0_0x0;
};

typedef struct CClassicLog CClassicLog, *PCClassicLog;

struct CClassicLog {
    undefined field0_0x0;
};

typedef struct CSceneCamera CSceneCamera, *PCSceneCamera;

struct CSceneCamera {
    undefined field0_0x0;
};

typedef struct CPlugAudio CPlugAudio, *PCPlugAudio;

struct CPlugAudio {
    undefined field0_0x0;
};

typedef struct CFuncShaderFxFactor CFuncShaderFxFactor, *PCFuncShaderFxFactor;

struct CFuncShaderFxFactor {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s_FuncInfo - /_s_FuncInfo */

typedef struct CFastBuffer<struct_CPlugModelMesh::SPoly> CFastBuffer<struct_CPlugModelMesh::SPoly>, *PCFastBuffer<struct_CPlugModelMesh::SPoly>;

struct CFastBuffer<struct_CPlugModelMesh::SPoly> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCampaignScores::SFilterInfos*> CFastBuffer<struct_CGameCampaignScores::SFilterInfos*>, *PCFastBuffer<struct_CGameCampaignScores::SFilterInfos*>;

struct CFastBuffer<struct_CGameCampaignScores::SFilterInfos*> {
    undefined field0_0x0;
};

typedef struct CNetTcpUnconnectedServerSocket CNetTcpUnconnectedServerSocket, *PCNetTcpUnconnectedServerSocket;

struct CNetTcpUnconnectedServerSocket {
    undefined field0_0x0;
};

typedef enum EVisualKind {
} EVisualKind;

typedef struct CMwCmdExpVec2Ident CMwCmdExpVec2Ident, *PCMwCmdExpVec2Ident;

struct CMwCmdExpVec2Ident {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetFileTransferDownload::CNetFileTransferDataToWrite*> CFastBuffer<class_CNetFileTransferDownload::CNetFileTransferDataToWrite*>, *PCFastBuffer<class_CNetFileTransferDownload::CNetFileTransferDataToWrite*>;

struct CFastBuffer<class_CNetFileTransferDownload::CNetFileTransferDataToWrite*> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamNatural> CMwParamFastBuffer<class_CMwParamNatural>, *PCMwParamFastBuffer<class_CMwParamNatural>;

struct CMwParamFastBuffer<class_CMwParamNatural> {
    undefined field0_0x0;
};

typedef struct CGameNetOnlineEvent CGameNetOnlineEvent, *PCGameNetOnlineEvent;

struct CGameNetOnlineEvent {
    undefined field0_0x0;
};

typedef enum EBuddyAction {
} EBuddyAction;

typedef struct CPfmPlane CPfmPlane, *PCPfmPlane;

struct CPfmPlane {
    undefined field0_0x0;
};

typedef enum EScoresMode {
} EScoresMode;

typedef struct SClippingFrustum SClippingFrustum, *PSClippingFrustum;

struct SClippingFrustum {
    undefined field0_0x0;
};

typedef struct CMwCmdExpClassParam CMwCmdExpClassParam, *PCMwCmdExpClassParam;

struct CMwCmdExpClassParam {
    undefined field0_0x0;
};

typedef struct SAllocInfo SAllocInfo, *PSAllocInfo;

struct SAllocInfo {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderSolid CPlugBitmapRenderSolid, *PCPlugBitmapRenderSolid;

struct CPlugBitmapRenderSolid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaVideoParams CGameCtnMediaVideoParams, *PCGameCtnMediaVideoParams;

struct CGameCtnMediaVideoParams {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlacedBlockInGrid> CFastBuffer<struct_SPlacedBlockInGrid>, *PCFastBuffer<struct_SPlacedBlockInGrid>;

struct CFastBuffer<struct_SPlacedBlockInGrid> {
    undefined field0_0x0;
};

typedef struct SPlugGpuLoadFx SPlugGpuLoadFx, *PSPlugGpuLoadFx;

struct SPlugGpuLoadFx {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraCustom SMwParamInfos_CGameCtnMediaBlockCameraCustom, *PSMwParamInfos_CGameCtnMediaBlockCameraCustom;

struct SMwParamInfos_CGameCtnMediaBlockCameraCustom {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CTrackManiaPlayerInfo*> CFastBuffer<class_CTrackManiaPlayerInfo*>, *PCFastBuffer<class_CTrackManiaPlayerInfo*>;

struct CFastBuffer<class_CTrackManiaPlayerInfo*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CDx9TextureKeeper*> CFastBuffer<class_CDx9TextureKeeper*>, *PCFastBuffer<class_CDx9TextureKeeper*>;

struct CFastBuffer<class_CDx9TextureKeeper*> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagWNDCLASSEXW - /winuser.h/tagWNDCLASSEXW */

typedef enum EManialinkEntryType {
} EManialinkEntryType;

typedef struct SRequirementOld11_13 SRequirementOld11_13, *PSRequirementOld11_13;

struct SRequirementOld11_13 {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwNodRef<class_CManoeuvre>,6,unsigned_long> CFixedArray<class_CMwNodRef<class_CManoeuvre>,6,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CManoeuvre>,6,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CManoeuvre>,6,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat> CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>, *PCFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat>;

struct CFastBufferCat<class_CHmsCorpusLight*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CatchGuardRN CatchGuardRN, *PCatchGuardRN;

struct CatchGuardRN {
    undefined field0_0x0;
};

typedef struct CSystemFidFile CSystemFidFile, *PCSystemFidFile;

struct CSystemFidFile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRace SMwParamInfos_CGameRace, *PSMwParamInfos_CGameRace;

struct SMwParamInfos_CGameRace {
    undefined field0_0x0;
};

typedef struct CMwParamProc CMwParamProc, *PCMwParamProc;

struct CMwParamProc {
    undefined field0_0x0;
};

typedef struct SHeaderIcon SHeaderIcon, *PSHeaderIcon;

struct SHeaderIcon {
    undefined field0_0x0;
};

typedef struct CSceneMobil CSceneMobil, *PCSceneMobil;

struct CSceneMobil {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyCharacterTunings SMwParamInfos_CSceneToyCharacterTunings, *PSMwParamInfos_CSceneToyCharacterTunings;

struct SMwParamInfos_CSceneToyCharacterTunings {
    undefined field0_0x0;
};

typedef struct CMwCmdExpIso4Param CMwCmdExpIso4Param, *PCMwCmdExpIso4Param;

struct CMwCmdExpIso4Param {
    undefined field0_0x0;
};

typedef struct SPuffLull SPuffLull, *PSPuffLull;

struct SPuffLull {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCCtnMediaBlockEventTrackMania CMwClassInfoCCtnMediaBlockEventTrackMania, *PCMwClassInfoCCtnMediaBlockEventTrackMania;

struct CMwClassInfoCCtnMediaBlockEventTrackMania {
    undefined field0_0x0;
};

typedef struct GxLightPoint GxLightPoint, *PGxLightPoint;

struct GxLightPoint {
    undefined field0_0x0;
};

typedef struct CPlugModelLodMesh CPlugModelLodMesh, *PCPlugModelLodMesh;

struct CPlugModelLodMesh {
    undefined field0_0x0;
};

typedef enum EHmsCorpusCat {
} EHmsCorpusCat;

typedef struct CGameAdvertisingNadeo CGameAdvertisingNadeo, *PCGameAdvertisingNadeo;

struct CGameAdvertisingNadeo {
    undefined field0_0x0;
};

typedef struct SSkinIndex SSkinIndex, *PSSkinIndex;

struct SSkinIndex {
    undefined field0_0x0;
};

typedef struct SServerInfoContext SServerInfoContext, *PSServerInfoContext;

struct SServerInfoContext {
    undefined field0_0x0;
};

typedef struct SStreamDecl SStreamDecl, *PSStreamDecl;

struct SStreamDecl {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugShader SMwParamInfos_CPlugShader, *PSMwParamInfos_CPlugShader;

struct SMwParamInfos_CPlugShader {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnChallengeGroup*> CFastBuffer<class_CGameCtnChallengeGroup*>, *PCFastBuffer<class_CGameCtnChallengeGroup*>;

struct CFastBuffer<class_CGameCtnChallengeGroup*> {
    undefined field0_0x0;
};

typedef struct SLightMapInfo SLightMapInfo, *PSLightMapInfo;

struct SLightMapInfo {
    undefined field0_0x0;
};

typedef struct SLightBallLoc SLightBallLoc, *PSLightBallLoc;

struct SLightBallLoc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileFidCache SMwParamInfos_CPlugFileFidCache, *PSMwParamInfos_CPlugFileFidCache;

struct SMwParamInfos_CPlugFileFidCache {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SHmsCameraLocation> CFastBuffer<struct_SHmsCameraLocation>, *PCFastBuffer<struct_SHmsCameraLocation>;

struct CFastBuffer<struct_SHmsCameraLocation> {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,218,unsigned_long> CFixedArray<unsigned_long,218,unsigned_long>, *PCFixedArray<unsigned_long,218,unsigned_long>;

struct CFixedArray<unsigned_long,218,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnBlock*> CFastBuffer<class_CGameCtnBlock*>, *PCFastBuffer<class_CGameCtnBlock*>;

struct CFastBuffer<class_CGameCtnBlock*> {
    undefined field0_0x0;
};

typedef struct CFuncSin CFuncSin, *PCFuncSin;

struct CFuncSin {
    undefined field0_0x0;
};

typedef struct _Locinfo _Locinfo, *P_Locinfo;

struct _Locinfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSystemArchiveNod::SExternalRef> CFastBuffer<struct_CSystemArchiveNod::SExternalRef>, *PCFastBuffer<struct_CSystemArchiveNod::SExternalRef>;

struct CFastBuffer<struct_CSystemArchiveNod::SExternalRef> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockEditorTriangles CGameCtnMediaBlockEditorTriangles, *PCGameCtnMediaBlockEditorTriangles;

struct CGameCtnMediaBlockEditorTriangles {
    undefined field0_0x0;
};

typedef struct SMasterServerInfos SMasterServerInfos, *PSMasterServerInfos;

struct SMasterServerInfos {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockFxBlurMotion CMwClassInfoCGameCtnMediaBlockFxBlurMotion, *PCMwClassInfoCGameCtnMediaBlockFxBlurMotion;

struct CMwClassInfoCGameCtnMediaBlockFxBlurMotion {
    undefined field0_0x0;
};

typedef struct CTrackManiaPlayerProfile CTrackManiaPlayerProfile, *PCTrackManiaPlayerProfile;

struct CTrackManiaPlayerProfile {
    undefined field0_0x0;
};

typedef struct CSceneController CSceneController, *PCSceneController;

struct CSceneController {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugBitmap*> CFastCallback1P<class_CPlugBitmap*>, *PCFastCallback1P<class_CPlugBitmap*>;

struct CFastCallback1P<class_CPlugBitmap*> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CDx9ShaderKeeper::SPassDesc> CFastArray<struct_CDx9ShaderKeeper::SPassDesc>, *PCFastArray<struct_CDx9ShaderKeeper::SPassDesc>;

struct CFastArray<struct_CDx9ShaderKeeper::SPassDesc> {
    undefined field0_0x0;
};

typedef struct CFunc CFunc, *PCFunc;

struct CFunc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameBuddy*> CFastBuffer<class_CGameBuddy*>, *PCFastBuffer<class_CGameBuddy*>;

struct CFastBuffer<class_CGameBuddy*> {
    undefined field0_0x0;
};

typedef struct CSceneSector CSceneSector, *PCSceneSector;

struct CSceneSector {
    undefined field0_0x0;
};

typedef struct CFastBuffer<char> CFastBuffer<char>, *PCFastBuffer<char>;

struct CFastBuffer<char> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CControlCredit::SBlock> CFastBuffer<struct_CControlCredit::SBlock>, *PCFastBuffer<struct_CControlCredit::SBlock>;

struct CFastBuffer<struct_CControlCredit::SBlock> {
    undefined field0_0x0;
};

typedef struct SHeaderDesc SHeaderDesc, *PSHeaderDesc;

struct SHeaderDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockFx SMwParamInfos_CGameCtnMediaBlockFx, *PSMwParamInfos_CGameCtnMediaBlockFx;

struct SMwParamInfos_CGameCtnMediaBlockFx {
    undefined field0_0x0;
};

typedef struct bad_exception bad_exception, *Pbad_exception;

struct bad_exception {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugBitmapPackInput*> CFastBuffer<class_CPlugBitmapPackInput*>, *PCFastBuffer<class_CPlugBitmapPackInput*>;

struct CFastBuffer<class_CPlugBitmapPackInput*> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_ULARGE_INTEGER - /winnt.h/_ULARGE_INTEGER */

typedef struct SMwParamInfos_CPlugBitmapPack SMwParamInfos_CPlugBitmapPack, *PSMwParamInfos_CPlugBitmapPack;

struct SMwParamInfos_CPlugBitmapPack {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamStringInt> CMwParamFastArray<class_CMwParamStringInt>, *PCMwParamFastArray<class_CMwParamStringInt>;

struct CMwParamFastArray<class_CMwParamStringInt> {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_CGameCtnMediaBlockFx::SLinkClassId,4,unsigned_long> CFixedArray<struct_CGameCtnMediaBlockFx::SLinkClassId,4,unsigned_long>, *PCFixedArray<struct_CGameCtnMediaBlockFx::SLinkClassId,4,unsigned_long>;

struct CFixedArray<struct_CGameCtnMediaBlockFx::SLinkClassId,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFuncCurves2Real CFuncCurves2Real, *PCFuncCurves2Real;

struct CFuncCurves2Real {
    undefined field0_0x0;
};

typedef struct SRequestElement SRequestElement, *PSRequestElement;

struct SRequestElement {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameControlDataType*> CFastBuffer<class_CGameControlDataType*>, *PCFastBuffer<class_CGameControlDataType*>;

struct CFastBuffer<class_CGameControlDataType*> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraOrbital CMwClassInfoCGameCtnMediaBlockCameraOrbital, *PCMwClassInfoCGameCtnMediaBlockCameraOrbital;

struct CMwClassInfoCGameCtnMediaBlockCameraOrbital {
    undefined field0_0x0;
};

typedef struct CFastCallback2P<class_CGameCtnChallengeInfo*,int&> CFastCallback2P<class_CGameCtnChallengeInfo*,int&>, *PCFastCallback2P<class_CGameCtnChallengeInfo*,int&>;

struct CFastCallback2P<class_CGameCtnChallengeInfo*,int&> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugVolumeShadow*> CFastBuffer<class_CPlugVolumeShadow*>, *PCFastBuffer<class_CPlugVolumeShadow*>;

struct CFastBuffer<class_CPlugVolumeShadow*> {
    undefined field0_0x0;
};

typedef struct vorbis_comment vorbis_comment, *Pvorbis_comment;

struct vorbis_comment {
    undefined field0_0x0;
};

typedef struct CGameEnvironmentManager CGameEnvironmentManager, *PCGameEnvironmentManager;

struct CGameEnvironmentManager {
    undefined field0_0x0;
};

typedef struct CGamePlayground CGamePlayground, *PCGamePlayground;

struct CGamePlayground {
    undefined field0_0x0;
};

typedef struct CFastStringBase<char> CFastStringBase<char>, *PCFastStringBase<char>;

struct CFastStringBase<char> {
    undefined field0_0x0;
};

typedef enum EStatus {
} EStatus;

typedef struct CControlTimeLine2 CControlTimeLine2, *PCControlTimeLine2;

struct CControlTimeLine2 {
    undefined field0_0x0;
};

typedef struct CPlugBlendShape CPlugBlendShape, *PCPlugBlendShape;

struct CPlugBlendShape {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlPlayerInput CTrackManiaControlPlayerInput, *PCTrackManiaControlPlayerInput;

struct CTrackManiaControlPlayerInput {
    undefined field0_0x0;
};

typedef struct CPlugVertexStream CPlugVertexStream, *PCPlugVertexStream;

struct CPlugVertexStream {
    undefined field0_0x0;
};

typedef struct _D3DXCONSTANT_DESC _D3DXCONSTANT_DESC, *P_D3DXCONSTANT_DESC;

struct _D3DXCONSTANT_DESC {
    undefined field0_0x0;
};

typedef struct CAudioBufferKeeper CAudioBufferKeeper, *PCAudioBufferKeeper;

struct CAudioBufferKeeper {
    undefined field0_0x0;
};

typedef struct SRayReceiver SRayReceiver, *PSRayReceiver;

struct SRayReceiver {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<class_CPlugFilePng*,class_CClassicBuffer&,int> CFastCallback3P<class_CPlugFilePng*,class_CClassicBuffer&,int>, *PCFastCallback3P<class_CPlugFilePng*,class_CClassicBuffer&,int>;

struct CFastCallback3P<class_CPlugFilePng*,class_CClassicBuffer&,int> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncManagerCharacter SMwParamInfos_CFuncManagerCharacter, *PSMwParamInfos_CFuncManagerCharacter;

struct SMwParamInfos_CFuncManagerCharacter {
    undefined field0_0x0;
};

typedef struct CFastBufferString CFastBufferString, *PCFastBufferString;

struct CFastBufferString {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoClassic CGameCtnBlockInfoClassic, *PCGameCtnBlockInfoClassic;

struct CGameCtnBlockInfoClassic {
    undefined field0_0x0;
};

typedef struct SHistoryPoint SHistoryPoint, *PSHistoryPoint;

struct SHistoryPoint {
    undefined field0_0x0;
};

typedef struct CMwTimer CMwTimer, *PCMwTimer;

struct CMwTimer {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CVisionResourceFile> CMwNodRef<class_CVisionResourceFile>, *PCMwNodRef<class_CVisionResourceFile>;

struct CMwNodRef<class_CVisionResourceFile> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpDiv CMwCmdExpDiv, *PCMwCmdExpDiv;

struct CMwCmdExpDiv {
    undefined field0_0x0;
};

typedef struct CGamePlayerTagData CGamePlayerTagData, *PCGamePlayerTagData;

struct CGamePlayerTagData {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetClient SMwParamInfos_CNetClient, *PSMwParamInfos_CNetClient;

struct SMwParamInfos_CNetClient {
    undefined field0_0x0;
};

typedef struct SImpression SImpression, *PSImpression;

struct SImpression {
    undefined field0_0x0;
};

typedef struct CVirtualisedBuffer<class_CFastString> CVirtualisedBuffer<class_CFastString>, *PCVirtualisedBuffer<class_CFastString>;

struct CVirtualisedBuffer<class_CFastString> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_SOldKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_SOldKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_SOldKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_SOldKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CGameControlMove CGameControlMove, *PCGameControlMove;

struct CGameControlMove {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/TypeDescriptor - /TypeDescriptor */

typedef struct CAudioSoundEngine CAudioSoundEngine, *PCAudioSoundEngine;

struct CAudioSoundEngine {
    undefined field0_0x0;
};

typedef struct SHmsVPackerCreate SHmsVPackerCreate, *PSHmsVPackerCreate;

struct SHmsVPackerCreate {
    undefined field0_0x0;
};

typedef struct CDx9VStreamKeeper CDx9VStreamKeeper, *PCDx9VStreamKeeper;

struct CDx9VStreamKeeper {
    undefined field0_0x0;
};

typedef struct CIPCSharedMem_Recipient CIPCSharedMem_Recipient, *PCIPCSharedMem_Recipient;

struct CIPCSharedMem_Recipient {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicle::SVisualArm> CFastBuffer<struct_CSceneVehicle::SVisualArm>, *PCFastBuffer<struct_CSceneVehicle::SVisualArm>;

struct CFastBuffer<struct_CSceneVehicle::SVisualArm> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionPlayCmd SMwParamInfos_CMotionPlayCmd, *PSMwParamInfos_CMotionPlayCmd;

struct SMwParamInfos_CMotionPlayCmd {
    undefined field0_0x0;
};

typedef struct SNat128 SNat128, *PSNat128;

struct SNat128 {
    undefined field0_0x0;
};

typedef struct CGamePlayerProfile CGamePlayerProfile, *PCGamePlayerProfile;

struct CGamePlayerProfile {
    undefined field0_0x0;
};

typedef struct CMwParamQuat CMwParamQuat, *PCMwParamQuat;

struct CMwParamQuat {
    undefined field0_0x0;
};

typedef enum EArchive {
} EArchive;

typedef struct _strflt _strflt, *P_strflt;

struct _strflt {
    int sign;
    int decpt;
    int flag;
    char *mantissa;
};

typedef struct SMwParamInfos_CGameChampionship SMwParamInfos_CGameChampionship, *PSMwParamInfos_CGameChampionship;

struct SMwParamInfos_CGameChampionship {
    undefined field0_0x0;
};

typedef struct CMotionPath CMotionPath, *PCMotionPath;

struct CMotionPath {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameLadderScores::SFilteredScores> CFastBuffer<struct_CGameLadderScores::SFilteredScores>, *PCFastBuffer<struct_CGameLadderScores::SFilteredScores>;

struct CFastBuffer<struct_CGameLadderScores::SFilteredScores> {
    undefined field0_0x0;
};

typedef struct GxSurfTriangleHeight GxSurfTriangleHeight, *PGxSurfTriangleHeight;

struct GxSurfTriangleHeight {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockUi SMwParamInfos_CGameCtnMediaBlockUi, *PSMwParamInfos_CGameCtnMediaBlockUi;

struct SMwParamInfos_CGameCtnMediaBlockUi {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SLadderResult> CFastBuffer<struct_CGameMasterServer::SLadderResult>, *PCFastBuffer<struct_CGameMasterServer::SLadderResult>;

struct CFastBuffer<struct_CGameMasterServer::SLadderResult> {
    undefined field0_0x0;
};

typedef struct CGameCtnZoneFlat CGameCtnZoneFlat, *PCGameCtnZoneFlat;

struct CGameCtnZoneFlat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncTreeTranslate SMwParamInfos_CFuncTreeTranslate, *PSMwParamInfos_CFuncTreeTranslate;

struct SMwParamInfos_CFuncTreeTranslate {
    undefined field0_0x0;
};

typedef struct SPlugTreeOptimCriteria SPlugTreeOptimCriteria, *PSPlugTreeOptimCriteria;

struct SPlugTreeOptimCriteria {
    undefined field0_0x0;
};

typedef struct CHmsStateDyna CHmsStateDyna, *PCHmsStateDyna;

struct CHmsStateDyna {
    undefined field0_0x0;
};

typedef struct CMwCmdExpEnumParam CMwCmdExpEnumParam, *PCMwCmdExpEnumParam;

struct CMwCmdExpEnumParam {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint> CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>, *PCFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint>;

struct CFastArray<struct_CMotionTrackMobilPitchin::SurfacePoint> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyCharacter SMwParamInfos_CSceneToyCharacter, *PSMwParamInfos_CSceneToyCharacter;

struct SMwParamInfos_CSceneToyCharacter {
    undefined field0_0x0;
};

typedef struct CPlugMusicType CPlugMusicType, *PCPlugMusicType;

struct CPlugMusicType {
    undefined field0_0x0;
};

typedef struct CPlugFileImg CPlugFileImg, *PCPlugFileImg;

struct CPlugFileImg {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SEnvModStrings> CFastBuffer<struct_SEnvModStrings>, *PCFastBuffer<struct_SEnvModStrings>;

struct CFastBuffer<struct_SEnvModStrings> {
    undefined field0_0x0;
};

typedef struct GmSurfMesh GmSurfMesh, *PGmSurfMesh;

struct GmSurfMesh {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameRemoteBuffer::SUser*> CFastBuffer<struct_CGameRemoteBuffer::SUser*>, *PCFastBuffer<struct_CGameRemoteBuffer::SUser*>;

struct CFastBuffer<struct_CGameRemoteBuffer::SUser*> {
    undefined field0_0x0;
};

typedef struct CPlugTreeFrustum CPlugTreeFrustum, *PCPlugTreeFrustum;

struct CPlugTreeFrustum {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFidParameters> CFastBuffer<class_CSystemFidParameters>, *PCFastBuffer<class_CSystemFidParameters>;

struct CFastBuffer<class_CSystemFidParameters> {
    undefined field0_0x0;
};

typedef struct CTrackManiaPlayerInfo CTrackManiaPlayerInfo, *PCTrackManiaPlayerInfo;

struct CTrackManiaPlayerInfo {
    undefined field0_0x0;
};

typedef struct CGameControlCardNetOnlineNews CGameControlCardNetOnlineNews, *PCGameControlCardNetOnlineNews;

struct CGameControlCardNetOnlineNews {
    undefined field0_0x0;
};

typedef struct SPolyVert SPolyVert, *PSPolyVert;

struct SPolyVert {
    undefined field0_0x0;
};

typedef struct CFastMapTable<class_CGameRemoteBuffer*> CFastMapTable<class_CGameRemoteBuffer*>, *PCFastMapTable<class_CGameRemoteBuffer*>;

struct CFastMapTable<class_CGameRemoteBuffer*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel> CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>, *PCFastBuffer<struct_CSceneVehicleStruct::SVisualWheel>;

struct CFastBuffer<struct_CSceneVehicleStruct::SVisualWheel> {
    undefined field0_0x0;
};

typedef struct CPlugFileGPUP CPlugFileGPUP, *PCPlugFileGPUP;

struct CPlugFileGPUP {
    undefined field0_0x0;
};

typedef struct IDirect3DSurface9 IDirect3DSurface9, *PIDirect3DSurface9;

struct IDirect3DSurface9 {
    undefined field0_0x0;
};

typedef struct SWindGlobalStartParams SWindGlobalStartParams, *PSWindGlobalStartParams;

struct SWindGlobalStartParams {
    undefined field0_0x0;
};

typedef struct SEnvMod SEnvMod, *PSEnvMod;

struct SEnvMod {
    undefined field0_0x0;
};

typedef struct CMwCmdExpEnumCastedNum CMwCmdExpEnumCastedNum, *PCMwCmdExpEnumCastedNum;

struct CMwCmdExpEnumCastedNum {
    undefined field0_0x0;
};

typedef struct CPlugTreeGenerator CPlugTreeGenerator, *PCPlugTreeGenerator;

struct CPlugTreeGenerator {
    undefined field0_0x0;
};

typedef struct CMwCmdExpClass CMwCmdExpClass, *PCMwCmdExpClass;

struct CMwCmdExpClass {
    undefined field0_0x0;
};

typedef struct _Ctypevec _Ctypevec, *P_Ctypevec;

struct _Ctypevec {
    uint _Page;
    short *_Table;
    int _Delfl;
    wchar_t *_LocaleName;
};

typedef struct CMwNodRef<class_CPlugFileGPUV> CMwNodRef<class_CPlugFileGPUV>, *PCMwNodRef<class_CPlugFileGPUV>;

struct CMwNodRef<class_CPlugFileGPUV> {
    undefined field0_0x0;
};

typedef struct CSystemCommandLine CSystemCommandLine, *PCSystemCommandLine;

struct CSystemCommandLine {
    undefined field0_0x0;
};

typedef struct CSceneSoundManager CSceneSoundManager, *PCSceneSoundManager;

struct CSceneSoundManager {
    undefined field0_0x0;
};

typedef struct SPackedDesc SPackedDesc, *PSPackedDesc;

struct SPackedDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnApp::SCampaignScoresRequest*> CFastBuffer<struct_CGameCtnApp::SCampaignScoresRequest*>, *PCFastBuffer<struct_CGameCtnApp::SCampaignScoresRequest*>;

struct CFastBuffer<struct_CGameCtnApp::SCampaignScoresRequest*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRemoteBufferPool SMwParamInfos_CGameRemoteBufferPool, *PSMwParamInfos_CGameRemoteBufferPool;

struct SMwParamInfos_CGameRemoteBufferPool {
    undefined field0_0x0;
};

typedef struct CNetFormQuerrySessions CNetFormQuerrySessions, *PCNetFormQuerrySessions;

struct CNetFormQuerrySessions {
    undefined field0_0x0;
};

typedef struct SShaderMask SShaderMask, *PSShaderMask;

struct SShaderMask {
    undefined field0_0x0;
};

typedef struct CGamePlaygroundInterface CGamePlaygroundInterface, *PCGamePlaygroundInterface;

struct CGamePlaygroundInterface {
    undefined field0_0x0;
};

typedef struct SOldFrustumInfos SOldFrustumInfos, *PSOldFrustumInfos;

struct SOldFrustumInfos {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwNodRef<class_CManoeuvre>,4,unsigned_long> CFixedArray<class_CMwNodRef<class_CManoeuvre>,4,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CManoeuvre>,4,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CManoeuvre>,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugBlendShapes CPlugBlendShapes, *PCPlugBlendShapes;

struct CPlugBlendShapes {
    undefined field0_0x0;
};

typedef enum _D3DTRANSFORMSTATETYPE {
} _D3DTRANSFORMSTATETYPE;

typedef struct SMwParamInfos_CTrackManiaEditorIcon SMwParamInfos_CTrackManiaEditorIcon, *PSMwParamInfos_CTrackManiaEditorIcon;

struct SMwParamInfos_CTrackManiaEditorIcon {
    undefined field0_0x0;
};

typedef struct _flt _flt, *P_flt;

struct _flt {
    int flags;
    int nbytes;
    long lval;
    double dval;
};

typedef struct SRtWheelToCpu SRtWheelToCpu, *PSRtWheelToCpu;

struct SRtWheelToCpu {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFuncClouds::SHeightPoint> CFastBuffer<struct_CFuncClouds::SHeightPoint>, *PCFastBuffer<struct_CFuncClouds::SHeightPoint>;

struct CFastBuffer<struct_CFuncClouds::SHeightPoint> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEnum SMwParamInfos_CControlEnum, *PSMwParamInfos_CControlEnum;

struct SMwParamInfos_CControlEnum {
    undefined field0_0x0;
};

typedef enum EErrorCode {
} EErrorCode;

typedef struct CNetUDP CNetUDP, *PCNetUDP;

struct CNetUDP {
    undefined field0_0x0;
};

typedef struct CHmsPoc CHmsPoc, *PCHmsPoc;

struct CHmsPoc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerScore::STrainingMedalsScores> CFastBuffer<struct_CGamePlayerScore::STrainingMedalsScores>, *PCFastBuffer<struct_CGamePlayerScore::STrainingMedalsScores>;

struct CFastBuffer<struct_CGamePlayerScore::STrainingMedalsScores> {
    undefined field0_0x0;
};

typedef struct SMeshGroup SMeshGroup, *PSMeshGroup;

struct SMeshGroup {
    undefined field0_0x0;
};

typedef struct SEnumFileFolderInfo SEnumFileFolderInfo, *PSEnumFileFolderInfo;

struct SEnumFileFolderInfo {
    undefined field0_0x0;
};

typedef struct STarget STarget, *PSTarget;

struct STarget {
    undefined field0_0x0;
};

typedef struct CPlugModelTree CPlugModelTree, *PCPlugModelTree;

struct CPlugModelTree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockImage SMwParamInfos_CGameCtnMediaBlockImage, *PSMwParamInfos_CGameCtnMediaBlockImage;

struct SMwParamInfos_CGameCtnMediaBlockImage {
    undefined field0_0x0;
};

typedef struct SPlugModelExportOptions SPlugModelExportOptions, *PSPlugModelExportOptions;

struct SPlugModelExportOptions {
    undefined field0_0x0;
};

typedef struct CStyleSheetElem<class_CFuncEnum> CStyleSheetElem<class_CFuncEnum>, *PCStyleSheetElem<class_CFuncEnum>;

struct CStyleSheetElem<class_CFuncEnum> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetTeamInfo::SMemberInfo> CFastBuffer<struct_CGameNetTeamInfo::SMemberInfo>, *PCFastBuffer<struct_CGameNetTeamInfo::SMemberInfo>;

struct CFastBuffer<struct_CGameNetTeamInfo::SMemberInfo> {
    undefined field0_0x0;
};

typedef enum ECullMode {
} ECullMode;


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_SECURITY_ATTRIBUTES - /winbase.h/_SECURITY_ATTRIBUTES */

typedef struct CFastBuffer<struct_SFontBitmapInternalPages> CFastBuffer<struct_SFontBitmapInternalPages>, *PCFastBuffer<struct_SFontBitmapInternalPages>;

struct CFastBuffer<struct_SFontBitmapInternalPages> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleCar SMwParamInfos_CSceneVehicleCar, *PSMwParamInfos_CSceneVehicleCar;

struct SMwParamInfos_CSceneVehicleCar {
    undefined field0_0x0;
};

typedef struct CFuncLightColor CFuncLightColor, *PCFuncLightColor;

struct CFuncLightColor {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_RTL_CRITICAL_SECTION - /winnt.h/_RTL_CRITICAL_SECTION */

typedef struct CSystemCmdAssert CSystemCmdAssert, *PCSystemCmdAssert;

struct CSystemCmdAssert {
    undefined field0_0x0;
};

typedef struct CSceneFxDistor2d CSceneFxDistor2d, *PCSceneFxDistor2d;

struct CSceneFxDistor2d {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamInteger> CMwParamFastArray<class_CMwParamInteger>, *PCMwParamFastArray<class_CMwParamInteger>;

struct CMwParamFastArray<class_CMwParamInteger> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapPackElem CPlugBitmapPackElem, *PCPlugBitmapPackElem;

struct CPlugBitmapPackElem {
    undefined field0_0x0;
};

typedef struct GmSpring<float> GmSpring<float>, *PGmSpring<float>;

struct GmSpring<float> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerCharacterAdv SMwParamInfos_CMotionManagerCharacterAdv, *PSMwParamInfos_CMotionManagerCharacterAdv;

struct SMwParamInfos_CMotionManagerCharacterAdv {
    undefined field0_0x0;
};

typedef struct SStageDesc SStageDesc, *PSStageDesc;

struct SStageDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CInputBindingsConfig::SGameActionToReconnect> CFastBuffer<struct_CInputBindingsConfig::SGameActionToReconnect>, *PCFastBuffer<struct_CInputBindingsConfig::SGameActionToReconnect>;

struct CFastBuffer<struct_CInputBindingsConfig::SGameActionToReconnect> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CHmsItem::SHmsCollisionGroupPair> CFastArray<struct_CHmsItem::SHmsCollisionGroupPair>, *PCFastArray<struct_CHmsItem::SHmsCollisionGroupPair>;

struct CFastArray<struct_CHmsItem::SHmsCollisionGroupPair> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaVideoShooter CGameCtnMediaVideoShooter, *PCGameCtnMediaVideoShooter;

struct CGameCtnMediaVideoShooter {
    undefined field0_0x0;
};

typedef struct GmSurfQuad GmSurfQuad, *PGmSurfQuad;

struct GmSurfQuad {
    undefined field0_0x0;
};

typedef struct CVisionShaderKeeper CVisionShaderKeeper, *PCVisionShaderKeeper;

struct CVisionShaderKeeper {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwNod*> CFastArray<class_CMwNod*>, *PCFastArray<class_CMwNod*>;

struct CFastArray<class_CMwNod*> {
    undefined field0_0x0;
};

typedef struct SHeaderCommunity SHeaderCommunity, *PSHeaderCommunity;

struct SHeaderCommunity {
    undefined field0_0x0;
};

typedef enum xmlrpc_timeoutType {
} xmlrpc_timeoutType;

typedef struct CFastArray<class_CSystemFidFile*> CFastArray<class_CSystemFidFile*>, *PCFastArray<class_CSystemFidFile*>;

struct CFastArray<class_CSystemFidFile*> {
    undefined field0_0x0;
};

typedef struct CGameRemoteBuffer CGameRemoteBuffer, *PCGameRemoteBuffer;

struct CGameRemoteBuffer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_> CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugMaterial>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugMaterial>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewport::SLensFlare> CFastBuffer<struct_CVisionViewport::SLensFlare>, *PCFastBuffer<struct_CVisionViewport::SLensFlare>;

struct CFastBuffer<struct_CVisionViewport::SLensFlare> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetwork::SRpcBannedPlayer> CFastBuffer<struct_CGameNetwork::SRpcBannedPlayer>, *PCFastBuffer<struct_CGameNetwork::SRpcBannedPlayer>;

struct CFastBuffer<struct_CGameNetwork::SRpcBannedPlayer> {
    undefined field0_0x0;
};

typedef enum EDayTime2 {
} EDayTime2;

typedef struct CFastBuffer<struct_CIPCRemoteControl_SAuthParams*> CFastBuffer<struct_CIPCRemoteControl_SAuthParams*>, *PCFastBuffer<struct_CIPCRemoteControl_SAuthParams*>;

struct CFastBuffer<struct_CIPCRemoteControl_SAuthParams*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdLog SMwParamInfos_CMwCmdLog, *PSMwParamInfos_CMwCmdLog;

struct SMwParamInfos_CMwCmdLog {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlButton SMwParamInfos_CControlButton, *PSMwParamInfos_CControlButton;

struct SMwParamInfos_CControlButton {
    undefined field0_0x0;
};

typedef struct CNetSystemError CNetSystemError, *PCNetSystemError;

struct CNetSystemError {
    undefined field0_0x0;
};

typedef enum EDayTime4 {
} EDayTime4;

typedef struct CGameControlCardLeague CGameControlCardLeague, *PCGameControlCardLeague;

struct CGameControlCardLeague {
    undefined field0_0x0;
};

typedef struct CPlugFileGPUV CPlugFileGPUV, *PCPlugFileGPUV;

struct CPlugFileGPUV {
    undefined field0_0x0;
};

typedef struct CMwCmdBuffer CMwCmdBuffer, *PCMwCmdBuffer;

struct CMwCmdBuffer {
    undefined field0_0x0;
};

typedef struct CPlugFileOggVorbis CPlugFileOggVorbis, *PCPlugFileOggVorbis;

struct CPlugFileOggVorbis {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameControlSelection::SSelectableObject> CFastBuffer<struct_CGameControlSelection::SSelectableObject>, *PCFastBuffer<struct_CGameControlSelection::SSelectableObject>;

struct CFastBuffer<struct_CGameControlSelection::SSelectableObject> {
    undefined field0_0x0;
};

typedef struct NvStripInfo NvStripInfo, *PNvStripInfo;

struct NvStripInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SCorpusLighted> CFastBuffer<struct_CVisionViewportDx9::SCorpusLighted>, *PCFastBuffer<struct_CVisionViewportDx9::SCorpusLighted>;

struct CFastBuffer<struct_CVisionViewportDx9::SCorpusLighted> {
    undefined field0_0x0;
};

typedef struct CHmsPortal CHmsPortal, *PCHmsPortal;

struct CHmsPortal {
    undefined field0_0x0;
};

typedef struct CIteratorSurface CIteratorSurface, *PCIteratorSurface;

struct CIteratorSurface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyStem SMwParamInfos_CSceneToyStem, *PSMwParamInfos_CSceneToyStem;

struct SMwParamInfos_CSceneToyStem {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>, *PCFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>;

struct CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<int,struct_SFastCat> CFastBufferCat<int,struct_SFastCat>, *PCFastBufferCat<int,struct_SFastCat>;

struct CFastBufferCat<int,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerScore::SCampaignRecordsState> CFastBuffer<struct_CGamePlayerScore::SCampaignRecordsState>, *PCFastBuffer<struct_CGamePlayerScore::SCampaignRecordsState>;

struct CFastBuffer<struct_CGamePlayerScore::SCampaignRecordsState> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnApp::SNationConfig> CFastBuffer<struct_CGameCtnApp::SNationConfig>, *PCFastBuffer<struct_CGameCtnApp::SNationConfig>;

struct CFastBuffer<struct_CGameCtnApp::SNationConfig> {
    undefined field0_0x0;
};

typedef struct SComputeContext SComputeContext, *PSComputeContext;

struct SComputeContext {
    undefined field0_0x0;
};

typedef struct CGameProcess CGameProcess, *PCGameProcess;

struct CGameProcess {
    undefined field0_0x0;
};

typedef struct SRemoteDatasPage SRemoteDatasPage, *PSRemoteDatasPage;

struct SRemoteDatasPage {
    undefined field0_0x0;
};

typedef enum ECapTexKind {
} ECapTexKind;

typedef enum EStencilOp {
} EStencilOp;

typedef struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>, *Pbasic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>;

struct basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFxFur CPlugMaterialFxFur, *PCPlugMaterialFxFur;

struct CPlugMaterialFxFur {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers> CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>, *PCFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>;

struct CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers> {
    undefined field0_0x0;
};

typedef struct _Locimp _Locimp, *P_Locimp;

struct _Locimp {
    undefined field0_0x0;
};

typedef enum EPlaneId {
} EPlaneId;

typedef struct CFastBuffer<struct_SPlugTreeOptimTransf> CFastBuffer<struct_SPlugTreeOptimTransf>, *PCFastBuffer<struct_SPlugTreeOptimTransf>;

struct CFastBuffer<struct_SPlugTreeOptimTransf> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRace1P CTrackManiaRace1P, *PCTrackManiaRace1P;

struct CTrackManiaRace1P {
    undefined field0_0x0;
};

typedef struct CFixedArray<char_const*,31,unsigned_long> CFixedArray<char_const*,31,unsigned_long>, *PCFixedArray<char_const*,31,unsigned_long>;

struct CFixedArray<char_const*,31,unsigned_long> {
    undefined field0_0x0;
};

typedef struct OBJFaceIndex OBJFaceIndex, *POBJFaceIndex;

struct OBJFaceIndex {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSoundVideo SMwParamInfos_CPlugSoundVideo, *PSMwParamInfos_CPlugSoundVideo;

struct SMwParamInfos_CPlugSoundVideo {
    undefined field0_0x0;
};

typedef enum EPlugRenderDevice {
} EPlugRenderDevice;

typedef struct CFastArray<class_CCrystalTexCoord> CFastArray<class_CCrystalTexCoord>, *PCFastArray<class_CCrystalTexCoord>;

struct CFastArray<class_CCrystalTexCoord> {
    undefined field0_0x0;
};

typedef struct CPlugTreeGenText CPlugTreeGenText, *PCPlugTreeGenText;

struct CPlugTreeGenText {
    undefined field0_0x0;
};

typedef struct CTrackManiaControlMatchSettingsCard CTrackManiaControlMatchSettingsCard, *PCTrackManiaControlMatchSettingsCard;

struct CTrackManiaControlMatchSettingsCard {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnVehicle CGameControlCardCtnVehicle, *PCGameControlCardCtnVehicle;

struct CGameControlCardCtnVehicle {
    undefined field0_0x0;
};

typedef struct CGameManialinkFileEntry CGameManialinkFileEntry, *PCGameManialinkFileEntry;

struct CGameManialinkFileEntry {
    undefined field0_0x0;
};

typedef struct SPartGroup SPartGroup, *PSPartGroup;

struct SPartGroup {
    undefined field0_0x0;
};

typedef enum EGxUVGenerate {
} EGxUVGenerate;

typedef struct CGameSkillScoreComputer CGameSkillScoreComputer, *PCGameSkillScoreComputer;

struct CGameSkillScoreComputer {
    undefined field0_0x0;
};

typedef struct SurfacePoint SurfacePoint, *PSurfacePoint;

struct SurfacePoint {
    undefined field0_0x0;
};

typedef struct SZoneGenealogy SZoneGenealogy, *PSZoneGenealogy;

struct SZoneGenealogy {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsCollisionManager::SZone*> CFastBuffer<struct_CHmsCollisionManager::SZone*>, *PCFastBuffer<struct_CHmsCollisionManager::SZone*>;

struct CFastBuffer<struct_CHmsCollisionManager::SZone*> {
    undefined field0_0x0;
};

typedef struct SObjectColors SObjectColors, *PSObjectColors;

struct SObjectColors {
    undefined field0_0x0;
};

typedef struct SSpecularSubMapCat SSpecularSubMapCat, *PSSpecularSubMapCat;

struct SSpecularSubMapCat {
    undefined field0_0x0;
};

typedef struct CFastBuffer<unsigned_int> CFastBuffer<unsigned_int>, *PCFastBuffer<unsigned_int>;

struct CFastBuffer<unsigned_int> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel> CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>, *PCFastBuffer<struct_CSceneVehicleCar::SSimulationWheel>;

struct CFastBuffer<struct_CSceneVehicleCar::SSimulationWheel> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlPlayerInfoCard SMwParamInfos_CTrackManiaControlPlayerInfoCard, *PSMwParamInfos_CTrackManiaControlPlayerInfoCard;

struct SMwParamInfos_CTrackManiaControlPlayerInfoCard {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSceneMobil*> CFastBuffer<class_CSceneMobil*>, *PCFastBuffer<class_CSceneMobil*>;

struct CFastBuffer<class_CSceneMobil*> {
    undefined field0_0x0;
};

typedef struct CMwParamReal CMwParamReal, *PCMwParamReal;

struct CMwParamReal {
    undefined field0_0x0;
};

typedef struct CFuncColor CFuncColor, *PCFuncColor;

struct CFuncColor {
    undefined field0_0x0;
};

typedef struct CCrystalLink CCrystalLink, *PCCrystalLink;

struct CCrystalLink {
    undefined field0_0x0;
};

typedef struct SHmsClearDesc SHmsClearDesc, *PSHmsClearDesc;

struct SHmsClearDesc {
    undefined field0_0x0;
};

typedef enum EGxTexArg {
} EGxTexArg;

typedef struct SBlockDesc SBlockDesc, *PSBlockDesc;

struct SBlockDesc {
    undefined field0_0x0;
};

typedef struct SRequestInfos SRequestInfos, *PSRequestInfos;

struct SRequestInfos {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CSceneToyBoat::STeamMateWayPoint>::SKey> {
    undefined field0_0x0;
};

typedef struct GmOctree<struct_CHmsCollisionManager::SColOctreeCell> GmOctree<struct_CHmsCollisionManager::SColOctreeCell>, *PGmOctree<struct_CHmsCollisionManager::SColOctreeCell>;

struct GmOctree<struct_CHmsCollisionManager::SColOctreeCell> {
    undefined field0_0x0;
};

typedef struct SShaderCustom SShaderCustom, *PSShaderCustom;

struct SShaderCustom {
    undefined field0_0x0;
};

typedef struct _Sentry_base _Sentry_base, *P_Sentry_base;

struct _Sentry_base {
    undefined field0_0x0;
};

typedef struct CGameCtnMasterServer CGameCtnMasterServer, *PCGameCtnMasterServer;

struct CGameCtnMasterServer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CVisionViewportDx9 SMwParamInfos_CVisionViewportDx9, *PSMwParamInfos_CVisionViewportDx9;

struct SMwParamInfos_CVisionViewportDx9 {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CTrackManiaMatchSettings CTrackManiaMatchSettings, *PCTrackManiaMatchSettings;

struct CTrackManiaMatchSettings {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSkip> CFastBuffer<struct_SSkip>, *PCFastBuffer<struct_SSkip>;

struct CFastBuffer<struct_SSkip> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaControlScores2::SCell> CFastBuffer<struct_CTrackManiaControlScores2::SCell>, *PCFastBuffer<struct_CTrackManiaControlScores2::SCell>;

struct CFastBuffer<struct_CTrackManiaControlScores2::SCell> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpBool SMwParamInfos_CMwCmdExpBool, *PSMwParamInfos_CMwCmdExpBool;

struct SMwParamInfos_CMwCmdExpBool {
    undefined field0_0x0;
};

typedef struct CGameCtnCollector CGameCtnCollector, *PCGameCtnCollector;

struct CGameCtnCollector {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCSceneMobil CMwClassInfoCSceneMobil, *PCMwClassInfoCSceneMobil;

struct CMwClassInfoCSceneMobil {
    undefined field0_0x0;
};

typedef struct CNetMasterServerUptoDateCheck CNetMasterServerUptoDateCheck, *PCNetMasterServerUptoDateCheck;

struct CNetMasterServerUptoDateCheck {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep> CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>, *PCFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep>;

struct CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStep> {
    undefined field0_0x0;
};

typedef struct CGameRaceInterface CGameRaceInterface, *PCGameRaceInterface;

struct CGameRaceInterface {
    undefined field0_0x0;
};

typedef struct CMotionTeamManager CMotionTeamManager, *PCMotionTeamManager;

struct CMotionTeamManager {
    undefined field0_0x0;
};

typedef struct SEnvironment SEnvironment, *PSEnvironment;

struct SEnvironment {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlStyle SMwParamInfos_CControlStyle, *PSMwParamInfos_CControlStyle;

struct SMwParamInfos_CControlStyle {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsItem SMwParamInfos_CHmsItem, *PSMwParamInfos_CHmsItem;

struct SMwParamInfos_CHmsItem {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameCtnMediaClip> CFastBufferRef<class_CGameCtnMediaClip>, *PCFastBufferRef<class_CGameCtnMediaClip>;

struct CFastBufferRef<class_CGameCtnMediaClip> {
    undefined field0_0x0;
};

typedef struct SPlayerIdentification SPlayerIdentification, *PSPlayerIdentification;

struct SPlayerIdentification {
    undefined field0_0x0;
};

typedef struct CFastMap<class_CMwId,float> CFastMap<class_CMwId,float>, *PCFastMap<class_CMwId,float>;

struct CFastMap<class_CMwId,float> {
    undefined field0_0x0;
};

typedef struct CMwCmdIdentInterface CMwCmdIdentInterface, *PCMwCmdIdentInterface;

struct CMwCmdIdentInterface {
    undefined field0_0x0;
};

typedef struct CControlMediaPlayer CControlMediaPlayer, *PCControlMediaPlayer;

struct CControlMediaPlayer {
    undefined field0_0x0;
};

typedef struct CSystemFileMemMapped CSystemFileMemMapped, *PCSystemFileMemMapped;

struct CSystemFileMemMapped {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameAdvertisingElement*> CFastBuffer<class_CGameAdvertisingElement*>, *PCFastBuffer<class_CGameAdvertisingElement*>;

struct CFastBuffer<class_CGameAdvertisingElement*> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCamera> CMwNodRef<class_CGameCamera>, *PCMwNodRef<class_CGameCamera>;

struct CMwNodRef<class_CGameCamera> {
    undefined field0_0x0;
};

typedef struct CMwParamNaturalRange CMwParamNaturalRange, *PCMwParamNaturalRange;

struct CMwParamNaturalRange {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_ACL - /winnt.h/_ACL */

typedef struct CMotionLight CMotionLight, *PCMotionLight;

struct CMotionLight {
    undefined field0_0x0;
};

typedef enum EConstraintType {
} EConstraintType;

typedef struct CMotionGroupPlayers CMotionGroupPlayers, *PCMotionGroupPlayers;

struct CMotionGroupPlayers {
    undefined field0_0x0;
};

typedef struct CSceneFxGrayAccum CSceneFxGrayAccum, *PCSceneFxGrayAccum;

struct CSceneFxGrayAccum {
    undefined field0_0x0;
};

typedef struct bad_alloc bad_alloc, *Pbad_alloc;

struct bad_alloc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpOr SMwParamInfos_CMwCmdExpOr, *PSMwParamInfos_CMwCmdExpOr;

struct SMwParamInfos_CMwCmdExpOr {
    undefined field0_0x0;
};

typedef struct SMaterial SMaterial, *PSMaterial;

struct SMaterial {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugFileVHlsl::CCustomDefine*> CFastBuffer<class_CPlugFileVHlsl::CCustomDefine*>, *PCFastBuffer<class_CPlugFileVHlsl::CCustomDefine*>;

struct CFastBuffer<class_CPlugFileVHlsl::CCustomDefine*> {
    undefined field0_0x0;
};

typedef struct CPlug CPlug, *PCPlug;

struct CPlug {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderPlaneR CPlugBitmapRenderPlaneR, *PCPlugBitmapRenderPlaneR;

struct CPlugBitmapRenderPlaneR {
    undefined field0_0x0;
};

typedef struct SCorpusLighted SCorpusLighted, *PSCorpusLighted;

struct SCorpusLighted {
    undefined field0_0x0;
};

typedef struct CFuncLight CFuncLight, *PCFuncLight;

struct CFuncLight {
    undefined field0_0x0;
};

typedef struct CHmsZoneVPacker CHmsZoneVPacker, *PCHmsZoneVPacker;

struct CHmsZoneVPacker {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceTriggerAbsorbContact CTrackManiaRaceTriggerAbsorbContact, *PCTrackManiaRaceTriggerAbsorbContact;

struct CTrackManiaRaceTriggerAbsorbContact {
    undefined field0_0x0;
};

typedef struct SHeaderUserData SHeaderUserData, *PSHeaderUserData;

struct SHeaderUserData {
    undefined field0_0x0;
};

typedef struct CNetMasterHost CNetMasterHost, *PCNetMasterHost;

struct CNetMasterHost {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionLight SMwParamInfos_CMotionLight, *PSMwParamInfos_CMotionLight;

struct SMwParamInfos_CMotionLight {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCalendarEvent SMwParamInfos_CGameControlCardCalendarEvent, *PSMwParamInfos_CGameControlCardCalendarEvent;

struct SMwParamInfos_CGameControlCardCalendarEvent {
    undefined field0_0x0;
};

typedef struct CSceneFxCameraBlend CSceneFxCameraBlend, *PCSceneFxCameraBlend;

struct CSceneFxCameraBlend {
    undefined field0_0x0;
};

typedef struct SControlListInternalHelper SControlListInternalHelper, *PSControlListInternalHelper;

struct SControlListInternalHelper {
    undefined field0_0x0;
};

typedef struct CInputDeviceDx8Mouse CInputDeviceDx8Mouse, *PCInputDeviceDx8Mouse;

struct CInputDeviceDx8Mouse {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<class_GmVec3> CFastBufferWheel<class_GmVec3>, *PCFastBufferWheel<class_GmVec3>;

struct CFastBufferWheel<class_GmVec3> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRemoteBufferDataInfoSearchs SMwParamInfos_CGameRemoteBufferDataInfoSearchs, *PSMwParamInfos_CGameRemoteBufferDataInfoSearchs;

struct SMwParamInfos_CGameRemoteBufferDataInfoSearchs {
    undefined field0_0x0;
};

typedef struct CGenAudioMusic<class_COalAudioSound> CGenAudioMusic<class_COalAudioSound>, *PCGenAudioMusic<class_COalAudioSound>;

struct CGenAudioMusic<class_COalAudioSound> {
    undefined field0_0x0;
};

typedef struct CPlugEngine CPlugEngine, *PCPlugEngine;

struct CPlugEngine {
    undefined field0_0x0;
};

typedef struct CMwParamVec3 CMwParamVec3, *PCMwParamVec3;

struct CMwParamVec3 {
    undefined field0_0x0;
};

typedef struct SVoteSpecificRatio SVoteSpecificRatio, *PSVoteSpecificRatio;

struct SVoteSpecificRatio {
    undefined field0_0x0;
};

typedef struct CMwParamVec2 CMwParamVec2, *PCMwParamVec2;

struct CMwParamVec2 {
    undefined field0_0x0;
};

typedef struct SSceneToyBoat_OldState SSceneToyBoat_OldState, *PSSceneToyBoat_OldState;

struct SSceneToyBoat_OldState {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CDx9TextureKeeper*,16,unsigned_long> CFixedArray<class_CDx9TextureKeeper*,16,unsigned_long>, *PCFixedArray<class_CDx9TextureKeeper*,16,unsigned_long>;

struct CFixedArray<class_CDx9TextureKeeper*,16,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastStringInt CFastStringInt, *PCFastStringInt;

struct CFastStringInt {
    undefined field0_0x0;
};

typedef struct CControlFrameAnimated CControlFrameAnimated, *PCControlFrameAnimated;

struct CControlFrameAnimated {
    undefined field0_0x0;
};

typedef enum ECurveDrawMode {
} ECurveDrawMode;

typedef struct CFastBuffer<struct_CPlugFile::SPlugFileType> CFastBuffer<struct_CPlugFile::SPlugFileType>, *PCFastBuffer<struct_CPlugFile::SPlugFileType>;

struct CFastBuffer<struct_CPlugFile::SPlugFileType> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlUiElement SMwParamInfos_CControlUiElement, *PSMwParamInfos_CControlUiElement;

struct SMwParamInfos_CControlUiElement {
    undefined field0_0x0;
};

typedef struct CFuncTree CFuncTree, *PCFuncTree;

struct CFuncTree {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugMaterial> CMwNodRef<class_CPlugMaterial>, *PCMwNodRef<class_CPlugMaterial>;

struct CMwNodRef<class_CPlugMaterial> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GxVertex2> CFastBuffer<class_GxVertex2>, *PCFastBuffer<class_GxVertex2>;

struct CFastBuffer<class_GxVertex2> {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<class_GmVec2> CFastBufferWheel<class_GmVec2>, *PCFastBufferWheel<class_GmVec2>;

struct CFastBufferWheel<class_GmVec2> {
    undefined field0_0x0;
};

typedef struct SField15UpTo17 SField15UpTo17, *PSField15UpTo17;

struct SField15UpTo17 {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamString> CMwParamFastBuffer<class_CMwParamString>, *PCMwParamFastBuffer<class_CMwParamString>;

struct CMwParamFastBuffer<class_CMwParamString> {
    undefined field0_0x0;
};

typedef struct CPlugRessourceStrings CPlugRessourceStrings, *PCPlugRessourceStrings;

struct CPlugRessourceStrings {
    undefined field0_0x0;
};

typedef struct SCustomBitmapOld SCustomBitmapOld, *PSCustomBitmapOld;

struct SCustomBitmapOld {
    undefined field0_0x0;
};

typedef struct CSceneFxMotionBlur CSceneFxMotionBlur, *PCSceneFxMotionBlur;

struct CSceneFxMotionBlur {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CCrystal::SSmoothingGroup> CFastBuffer<struct_CCrystal::SSmoothingGroup>, *PCFastBuffer<struct_CCrystal::SSmoothingGroup>;

struct CFastBuffer<struct_CCrystal::SSmoothingGroup> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnChapter SMwParamInfos_CGameCtnChapter, *PSMwParamInfos_CGameCtnChapter;

struct SMwParamInfos_CGameCtnChapter {
    undefined field0_0x0;
};

typedef struct SBindingToSort SBindingToSort, *PSBindingToSort;

struct SBindingToSort {
    undefined field0_0x0;
};

typedef struct CSystemFid CSystemFid, *PCSystemFid;

struct CSystemFid {
    undefined field0_0x0;
};

typedef struct SFxCat SFxCat, *PSFxCat;

struct SFxCat {
    undefined field0_0x0;
};

typedef struct CSceneMobilLeaves CSceneMobilLeaves, *PCSceneMobilLeaves;

struct CSceneMobilLeaves {
    undefined field0_0x0;
};

typedef struct EHExceptionRecord EHExceptionRecord, *PEHExceptionRecord;

struct EHExceptionRecord {
    undefined field0_0x0;
};

typedef struct STMQuickInfo STMQuickInfo, *PSTMQuickInfo;

struct STMQuickInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaNetworkServerInfo SMwParamInfos_CTrackManiaNetworkServerInfo, *PSMwParamInfos_CTrackManiaNetworkServerInfo;

struct SMwParamInfos_CTrackManiaNetworkServerInfo {
    undefined field0_0x0;
};

typedef struct CTrackMania CTrackMania, *PCTrackMania;

struct CTrackMania {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugFilePso*> CFastCallback1P<class_CPlugFilePso*>, *PCFastCallback1P<class_CPlugFilePso*>;

struct CFastCallback1P<class_CPlugFilePso*> {
    undefined field0_0x0;
};

typedef struct CMwParamVec4 CMwParamVec4, *PCMwParamVec4;

struct CMwParamVec4 {
    undefined field0_0x0;
};

typedef struct S13 S13, *PS13;

struct S13 {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockSound CMwClassInfoCGameCtnMediaBlockSound, *PCMwClassInfoCGameCtnMediaBlockSound;

struct CMwClassInfoCGameCtnMediaBlockSound {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CBoatSail>_> CFastBuffer<class_CMwNodRef<class_CBoatSail>_>, *PCFastBuffer<class_CMwNodRef<class_CBoatSail>_>;

struct CFastBuffer<class_CMwNodRef<class_CBoatSail>_> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwId> CFastArray<class_CMwId>, *PCFastArray<class_CMwId>;

struct CFastArray<class_CMwId> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat>, *PCFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat>;

struct CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> {
    undefined field0_0x0;
};

typedef struct CVisionData CVisionData, *PCVisionData;

struct CVisionData {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlacedBlockInGridBuffer> CFastBuffer<struct_SPlacedBlockInGridBuffer>, *PCFastBuffer<struct_SPlacedBlockInGridBuffer>;

struct CFastBuffer<struct_SPlacedBlockInGridBuffer> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaContext CGameCtnMediaContext, *PCGameCtnMediaContext;

struct CGameCtnMediaContext {
    undefined field0_0x0;
};

typedef struct SRpcNetworkStats SRpcNetworkStats, *PSRpcNetworkStats;

struct SRpcNetworkStats {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFileGPU::SLoadDesc> CFastBuffer<struct_CPlugFileGPU::SLoadDesc>, *PCFastBuffer<struct_CPlugFileGPU::SLoadDesc>;

struct CFastBuffer<struct_CPlugFileGPU::SLoadDesc> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SHmsCameraProjection> CFastBuffer<struct_SHmsCameraProjection>, *PCFastBuffer<struct_SHmsCameraProjection>;

struct CFastBuffer<struct_SHmsCameraProjection> {
    undefined field0_0x0;
};

typedef struct SDynaPart SDynaPart, *PSDynaPart;

struct SDynaPart {
    undefined field0_0x0;
};

typedef struct CGamePlayerUIdAllocator CGamePlayerUIdAllocator, *PCGamePlayerUIdAllocator;

struct CGamePlayerUIdAllocator {
    undefined field0_0x0;
};

typedef enum ECmpFunc {
} ECmpFunc;

typedef struct CScene CScene, *PCScene;

struct CScene {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s_TryBlockMapEntry - /_s_TryBlockMapEntry */

typedef struct SMwParamInfos_CGameTournament SMwParamInfos_CGameTournament, *PSMwParamInfos_CGameTournament;

struct SMwParamInfos_CGameTournament {
    undefined field0_0x0;
};

typedef struct SWaveFormat SWaveFormat, *PSWaveFormat;

struct SWaveFormat {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockFxBlurDepth::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CFuncSegment::SKey> CFastBufferKey<struct_CFuncSegment::SKey>, *PCFastBufferKey<struct_CFuncSegment::SKey>;

struct CFastBufferKey<struct_CFuncSegment::SKey> {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_CGameCtnChapter::SCustomMusic,3,unsigned_long> CFixedArray<struct_CGameCtnChapter::SCustomMusic,3,unsigned_long>, *PCFixedArray<struct_CGameCtnChapter::SCustomMusic,3,unsigned_long>;

struct CFixedArray<struct_CGameCtnChapter::SCustomMusic,3,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialFx CPlugMaterialFx, *PCPlugMaterialFx;

struct CPlugMaterialFx {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelLodMesh::SLevel> CFastBuffer<struct_CPlugModelLodMesh::SLevel>, *PCFastBuffer<struct_CPlugModelLodMesh::SLevel>;

struct CFastBuffer<struct_CPlugModelLodMesh::SLevel> {
    undefined field0_0x0;
};

typedef struct CMotionShader CMotionShader, *PCMotionShader;

struct CMotionShader {
    undefined field0_0x0;
};

typedef struct SSimulationWheel SSimulationWheel, *PSSimulationWheel;

struct SSimulationWheel {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneMobil> CMwNodRef<class_CSceneMobil>, *PCMwNodRef<class_CSceneMobil>;

struct CMwNodRef<class_CSceneMobil> {
    undefined field0_0x0;
};

typedef struct CNetFormConnectionAdmin CNetFormConnectionAdmin, *PCNetFormConnectionAdmin;

struct CNetFormConnectionAdmin {
    undefined field0_0x0;
};

typedef struct CPlugSoundEngineComponent CPlugSoundEngineComponent, *PCPlugSoundEngineComponent;

struct CPlugSoundEngineComponent {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxBloomData SMwParamInfos_CSceneFxBloomData, *PSMwParamInfos_CSceneFxBloomData;

struct SMwParamInfos_CSceneFxBloomData {
    undefined field0_0x0;
};

typedef struct SLensFlare SLensFlare, *PSLensFlare;

struct SLensFlare {
    undefined field0_0x0;
};

typedef struct CControlStyleSheet CControlStyleSheet, *PCControlStyleSheet;

struct CControlStyleSheet {
    undefined field0_0x0;
};

typedef struct DIDEVICEINSTANCEW DIDEVICEINSTANCEW, *PDIDEVICEINSTANCEW;

struct DIDEVICEINSTANCEW {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SCriteria> CFastBuffer<struct_CGameMasterServer::SCriteria>, *PCFastBuffer<struct_CGameMasterServer::SCriteria>;

struct CFastBuffer<struct_CGameMasterServer::SCriteria> {
    undefined field0_0x0;
};

typedef struct SBenchShader SBenchShader, *PSBenchShader;

struct SBenchShader {
    undefined field0_0x0;
};

typedef struct SDataDecl SDataDecl, *PSDataDecl;

struct SDataDecl {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugFileVso*> CFastCallback1P<class_CPlugFileVso*>, *PCFastCallback1P<class_CPlugFileVso*>;

struct CFastCallback1P<class_CPlugFileVso*> {
    undefined field0_0x0;
};

typedef struct CSceneMoods CSceneMoods, *PCSceneMoods;

struct CSceneMoods {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScene SMwParamInfos_CScene, *PSMwParamInfos_CScene;

struct SMwParamInfos_CScene {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnGhost SMwParamInfos_CGameControlCardCtnGhost, *PSMwParamInfos_CGameControlCardCtnGhost;

struct SMwParamInfos_CGameControlCardCtnGhost {
    undefined field0_0x0;
};

typedef struct CVisionViewport CVisionViewport, *PCVisionViewport;

struct CVisionViewport {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRemoteBufferDataInfo SMwParamInfos_CGameRemoteBufferDataInfo, *PSMwParamInfos_CGameRemoteBufferDataInfo;

struct SMwParamInfos_CGameRemoteBufferDataInfo {
    undefined field0_0x0;
};

typedef struct SImpressionRecord SImpressionRecord, *PSImpressionRecord;

struct SImpressionRecord {
    undefined field0_0x0;
};

typedef struct STextSettings STextSettings, *PSTextSettings;

struct STextSettings {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlCredit SMwParamInfos_CControlCredit, *PSMwParamInfos_CControlCredit;

struct SMwParamInfos_CControlCredit {
    undefined field0_0x0;
};

typedef enum EFigures {
} EFigures;

typedef struct SSceneToyBoat_ReplayState SSceneToyBoat_ReplayState, *PSSceneToyBoat_ReplayState;

struct SSceneToyBoat_ReplayState {
    undefined field0_0x0;
};

typedef struct CCallbackMeasureImpression CCallbackMeasureImpression, *PCCallbackMeasureImpression;

struct CCallbackMeasureImpression {
    undefined field0_0x0;
};

typedef struct CHdrElement CHdrElement, *PCHdrElement;

struct CHdrElement {
    undefined field0_0x0;
};

typedef struct SParam_Fid_Common SParam_Fid_Common, *PSParam_Fid_Common;

struct SParam_Fid_Common {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SShaderTweakSampler> CFastBuffer<struct_CVisionViewportDx9::SShaderTweakSampler>, *PCFastBuffer<struct_CVisionViewportDx9::SShaderTweakSampler>;

struct CFastBuffer<struct_CVisionViewportDx9::SShaderTweakSampler> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraEffectAdaptativeNearZ SMwParamInfos_CGameControlCameraEffectAdaptativeNearZ, *PSMwParamInfos_CGameControlCameraEffectAdaptativeNearZ;

struct SMwParamInfos_CGameControlCameraEffectAdaptativeNearZ {
    undefined field0_0x0;
};

typedef struct CPlugShaderApply CPlugShaderApply, *PCPlugShaderApply;

struct CPlugShaderApply {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>, *PCFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>;

struct CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> {
    undefined field0_0x0;
};

typedef enum EMobilStateQuality {
} EMobilStateQuality;

typedef struct CFastBuffer<wchar_t> CFastBuffer<wchar_t>, *PCFastBuffer<wchar_t>;

struct CFastBuffer<wchar_t> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CFuncKeysPath*> CFastArray<class_CFuncKeysPath*>, *PCFastArray<class_CFuncKeysPath*>;

struct CFastArray<class_CFuncKeysPath*> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugBlendShape> CFastArray<class_CPlugBlendShape>, *PCFastArray<class_CPlugBlendShape>;

struct CFastArray<class_CPlugBlendShape> {
    undefined field0_0x0;
};

typedef struct CHmsPicker CHmsPicker, *PCHmsPicker;

struct CHmsPicker {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameLadderRanking*> CFastBuffer<class_CGameLadderRanking*>, *PCFastBuffer<class_CGameLadderRanking*>;

struct CFastBuffer<class_CGameLadderRanking*> {
    undefined field0_0x0;
};

typedef struct SInOut SInOut, *PSInOut;

struct SInOut {
    undefined field0_0x0;
};

typedef struct SHeaderVersion SHeaderVersion, *PSHeaderVersion;

struct SHeaderVersion {
    undefined field0_0x0;
};

typedef struct CGameCtnReplayRecordInfo CGameCtnReplayRecordInfo, *PCGameCtnReplayRecordInfo;

struct CGameCtnReplayRecordInfo {
    undefined field0_0x0;
};

typedef struct SPlayerTagsConfig SPlayerTagsConfig, *PSPlayerTagsConfig;

struct SPlayerTagsConfig {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMwNodRef<class_CPlugMaterial>_> CFastArray<class_CMwNodRef<class_CPlugMaterial>_>, *PCFastArray<class_CMwNodRef<class_CPlugMaterial>_>;

struct CFastArray<class_CMwNodRef<class_CPlugMaterial>_> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringUpDownCase CMwCmdExpStringUpDownCase, *PCMwCmdExpStringUpDownCase;

struct CMwCmdExpStringUpDownCase {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmVector2<unsigned_short>_> CFastBuffer<class_GmVector2<unsigned_short>_>, *PCFastBuffer<class_GmVector2<unsigned_short>_>;

struct CFastBuffer<class_GmVector2<unsigned_short>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaPlayerInfo SMwParamInfos_CTrackManiaPlayerInfo, *PSMwParamInfos_CTrackManiaPlayerInfo;

struct SMwParamInfos_CTrackManiaPlayerInfo {
    undefined field0_0x0;
};

typedef struct SQueuedNetNod SQueuedNetNod, *PSQueuedNetNod;

struct SQueuedNetNod {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameCtnCampaign> CFastBufferRef<class_CGameCtnCampaign>, *PCFastBufferRef<class_CGameCtnCampaign>;

struct CFastBufferRef<class_CGameCtnCampaign> {
    undefined field0_0x0;
};

typedef struct CSceneMessageHandler CSceneMessageHandler, *PCSceneMessageHandler;

struct CSceneMessageHandler {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SHmsVPackerObjectPacked> CFastBuffer<struct_SHmsVPackerObjectPacked>, *PCFastBuffer<struct_SHmsVPackerObjectPacked>;

struct CFastBuffer<struct_SHmsVPackerObjectPacked> {
    undefined field0_0x0;
};

typedef struct CCallback CCallback, *PCCallback;

struct CCallback {
    undefined field0_0x0;
};

typedef struct SPrimitiveGroup SPrimitiveGroup, *PSPrimitiveGroup;

struct SPrimitiveGroup {
    undefined field0_0x0;
};

typedef struct CGameNetSearchRequest CGameNetSearchRequest, *PCGameNetSearchRequest;

struct CGameNetSearchRequest {
    undefined field0_0x0;
};

typedef struct CFuncLightIntensity CFuncLightIntensity, *PCFuncLightIntensity;

struct CFuncLightIntensity {
    undefined field0_0x0;
};

typedef struct IDirect3DVertexBuffer9 IDirect3DVertexBuffer9, *PIDirect3DVertexBuffer9;

struct IDirect3DVertexBuffer9 {
    undefined field0_0x0;
};

typedef enum _SE_OBJECT_TYPE {
    SE_UNKNOWN_OBJECT_TYPE=0,
    SE_FILE_OBJECT=1,
    SE_SERVICE=2,
    SE_PRINTER=3,
    SE_REGISTRY_KEY=4,
    SE_LMSHARE=5,
    SE_KERNEL_OBJECT=6,
    SE_WINDOW_OBJECT=7,
    SE_DS_OBJECT=8,
    SE_DS_OBJECT_ALL=9,
    SE_PROVIDER_DEFINED_OBJECT=10,
    SE_WMIGUID_OBJECT=11,
    SE_REGISTRY_WOW64_32KEY=12
} _SE_OBJECT_TYPE;

typedef struct SMwParamInfos_CGameCalendarEvent SMwParamInfos_CGameCalendarEvent, *PSMwParamInfos_CGameCalendarEvent;

struct SMwParamInfos_CGameCalendarEvent {
    undefined field0_0x0;
};

typedef enum EDirectory {
} EDirectory;

typedef struct CGameControlCard CGameControlCard, *PCGameControlCard;

struct CGameControlCard {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmIso3> CFastArray<class_GmIso3>, *PCFastArray<class_GmIso3>;

struct CFastArray<class_GmIso3> {
    undefined field0_0x0;
};

typedef struct SMwIdInternal SMwIdInternal, *PSMwIdInternal;

struct SMwIdInternal {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioSoundEngine SMwParamInfos_CAudioSoundEngine, *PSMwParamInfos_CAudioSoundEngine;

struct SMwParamInfos_CAudioSoundEngine {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CSceneToyStem::SStemInfo> CFastArray<struct_CSceneToyStem::SStemInfo>, *PCFastArray<struct_CSceneToyStem::SStemInfo>;

struct CFastArray<struct_CSceneToyStem::SStemInfo> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetwork SMwParamInfos_CGameNetwork, *PSMwParamInfos_CGameNetwork;

struct SMwParamInfos_CGameNetwork {
    undefined field0_0x0;
};

typedef struct SHmsRenderRect SHmsRenderRect, *PSHmsRenderRect;

struct SHmsRenderRect {
    undefined field0_0x0;
};

typedef enum _D3DPOOL {
} _D3DPOOL;

typedef struct SStringParam SStringParam, *PSStringParam;

struct SStringParam {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnMediaClip> CMwNodRef<class_CGameCtnMediaClip>, *PCMwNodRef<class_CGameCtnMediaClip>;

struct CMwNodRef<class_CGameCtnMediaClip> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated> CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>, *PCFastBuffer<struct_CHmsVPackerCell::STreeMipLocated>;

struct CFastBuffer<struct_CHmsVPackerCell::STreeMipLocated> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpBoolParam CMwCmdExpBoolParam, *PCMwCmdExpBoolParam;

struct CMwCmdExpBoolParam {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapPackInput SMwParamInfos_CPlugBitmapPackInput, *PSMwParamInfos_CPlugBitmapPackInput;

struct SMwParamInfos_CPlugBitmapPackInput {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeGenSolid SMwParamInfos_CPlugTreeGenSolid, *PSMwParamInfos_CPlugTreeGenSolid;

struct SMwParamInfos_CPlugTreeGenSolid {
    undefined field0_0x0;
};

typedef struct CGameLoadProgress CGameLoadProgress, *PCGameLoadProgress;

struct CGameLoadProgress {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_WayPointMesh_struct> CFastBuffer<struct_WayPointMesh_struct>, *PCFastBuffer<struct_WayPointMesh_struct>;

struct CFastBuffer<struct_WayPointMesh_struct> {
    undefined field0_0x0;
};

typedef struct CFuncShaderTweakKeysTranss CFuncShaderTweakKeysTranss, *PCFuncShaderTweakKeysTranss;

struct CFuncShaderTweakKeysTranss {
    undefined field0_0x0;
};

typedef struct CHmsCollisionManager CHmsCollisionManager, *PCHmsCollisionManager;

struct CHmsCollisionManager {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSceneMoods_Light> CFastBuffer<struct_SSceneMoods_Light>, *PCFastBuffer<struct_SSceneMoods_Light>;

struct CFastBuffer<struct_SSceneMoods_Light> {
    undefined field0_0x0;
};

typedef struct CNetIPAddress CNetIPAddress, *PCNetIPAddress;

struct CNetIPAddress {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentVec2 CMwCmdAffectIdentVec2, *PCMwCmdAffectIdentVec2;

struct CMwCmdAffectIdentVec2 {
    undefined field0_0x0;
};

typedef enum EExtrapolation {
} EExtrapolation;

typedef struct CFastArray<class_CFuncKeySkel> CFastArray<class_CFuncKeySkel>, *PCFastArray<class_CFuncKeySkel>;

struct CFastArray<class_CFuncKeySkel> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnDecoration SMwParamInfos_CGameCtnDecoration, *PSMwParamInfos_CGameCtnDecoration;

struct SMwParamInfos_CGameCtnDecoration {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServer::SCustomFileInfo> CFastBuffer<struct_CGameMasterServer::SCustomFileInfo>, *PCFastBuffer<struct_CGameMasterServer::SCustomFileInfo>;

struct CFastBuffer<struct_CGameMasterServer::SCustomFileInfo> {
    undefined field0_0x0;
};

typedef struct SField SField, *PSField;

struct SField {
    undefined field0_0x0;
};

typedef struct CTransactionalNatural<4294967295> CTransactionalNatural<4294967295>, *PCTransactionalNatural<4294967295>;

struct CTransactionalNatural<4294967295> {
    undefined field0_0x0;
};

typedef struct CPlugMaterialCustom CPlugMaterialCustom, *PCPlugMaterialCustom;

struct CPlugMaterialCustom {
    undefined field0_0x0;
};

typedef struct CPfmMeshInterface CPfmMeshInterface, *PCPfmMeshInterface;

struct CPfmMeshInterface {
    undefined field0_0x0;
};

typedef struct fd_set fd_set, *Pfd_set;

struct fd_set {
    uint fd_count;
    uint fd_array[64];
};

typedef struct CFixedArray<class_CMwNodRef<class_CPlugFileGPUV>,29,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugFileGPUV>,29,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugFileGPUV>,29,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugFileGPUV>,29,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SPixCopyDesc SPixCopyDesc, *PSPixCopyDesc;

struct SPixCopyDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CInputDevice SMwParamInfos_CInputDevice, *PSMwParamInfos_CInputDevice;

struct SMwParamInfos_CInputDevice {
    undefined field0_0x0;
};

typedef struct CGameControlCameraTrackManiaRace CGameControlCameraTrackManiaRace, *PCGameControlCameraTrackManiaRace;

struct CGameControlCameraTrackManiaRace {
    undefined field0_0x0;
};

typedef struct SEvent SEvent, *PSEvent;

struct SEvent {
    undefined field0_0x0;
};

typedef struct SOccInput SOccInput, *PSOccInput;

struct SOccInput {
    undefined field0_0x0;
};

typedef struct CMwCmdExpBoolBin CMwCmdExpBoolBin, *PCMwCmdExpBoolBin;

struct CMwCmdExpBoolBin {
    undefined field0_0x0;
};

typedef struct CMotionEmitterLeaves CMotionEmitterLeaves, *PCMotionEmitterLeaves;

struct CMotionEmitterLeaves {
    undefined field0_0x0;
};

typedef struct GmFuncRealFromReal2 GmFuncRealFromReal2, *PGmFuncRealFromReal2;

struct GmFuncRealFromReal2 {
    undefined field0_0x0;
};

typedef struct SFogCache SFogCache, *PSFogCache;

struct SFogCache {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugMaterial::SDeviceMat> CFastArray<struct_CPlugMaterial::SDeviceMat>, *PCFastArray<struct_CPlugMaterial::SDeviceMat>;

struct CFastArray<struct_CPlugMaterial::SDeviceMat> {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_SStdGpuMask,39,unsigned_long> CFixedArray<struct_SStdGpuMask,39,unsigned_long>, *PCFixedArray<struct_SStdGpuMask,39,unsigned_long>;

struct CFixedArray<struct_SStdGpuMask,39,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentNum CMwCmdAffectIdentNum, *PCMwCmdAffectIdentNum;

struct CMwCmdAffectIdentNum {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameNetTeamInfo> CMwNodRef<class_CGameNetTeamInfo>, *PCMwNodRef<class_CGameNetTeamInfo>;

struct CMwNodRef<class_CGameNetTeamInfo> {
    undefined field0_0x0;
};

typedef struct SPixUpdatePar SPixUpdatePar, *PSPixUpdatePar;

struct SPixUpdatePar {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/HMMIO__ - /mmsystem.h/HMMIO__ */

typedef struct CGameControlGridCard CGameControlGridCard, *PCGameControlGridCard;

struct CGameControlGridCard {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_STangentUV> CFastArray<struct_STangentUV>, *PCFastArray<struct_STangentUV>;

struct CFastArray<struct_STangentUV> {
    undefined field0_0x0;
};

typedef struct SSurfaceId SSurfaceId, *PSSurfaceId;

struct SSurfaceId {
    undefined field0_0x0;
};

typedef enum EDirtyProps {
} EDirtyProps;

typedef struct CNetMasterServerRequest CNetMasterServerRequest, *PCNetMasterServerRequest;

struct CNetMasterServerRequest {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugBitmap> CMwNodRef<class_CPlugBitmap>, *PCMwNodRef<class_CPlugBitmap>;

struct CMwNodRef<class_CPlugBitmap> {
    undefined field0_0x0;
};

typedef struct CGameControlCameraFree CGameControlCameraFree, *PCGameControlCameraFree;

struct CGameControlCameraFree {
    undefined field0_0x0;
};

typedef struct CGameNetDataDownload CGameNetDataDownload, *PCGameNetDataDownload;

struct CGameNetDataDownload {
    undefined field0_0x0;
};

typedef struct GmVector3<unsigned_long> GmVector3<unsigned_long>, *PGmVector3<unsigned_long>;

struct GmVector3<unsigned_long> {
    undefined field0_0x0;
};

typedef struct SChildGen SChildGen, *PSChildGen;

struct SChildGen {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_GmBoxAligned,3,unsigned_long> CFixedArray<class_GmBoxAligned,3,unsigned_long>, *PCFixedArray<class_GmBoxAligned,3,unsigned_long>;

struct CFixedArray<class_GmBoxAligned,3,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneToyStem>_> CFastBuffer<class_CMwNodRef<class_CSceneToyStem>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneToyStem>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneToyStem>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CControlEffectSimi::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo> CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>, *PCFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo>;

struct CFastBuffer<struct_CTrackManiaNetwork::SRpcSkinInfo> {
    undefined field0_0x0;
};

typedef struct CPlugVolumeProjector CPlugVolumeProjector, *PCPlugVolumeProjector;

struct CPlugVolumeProjector {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CInputDevice::SRumble> CFastBuffer<struct_CInputDevice::SRumble>, *PCFastBuffer<struct_CInputDevice::SRumble>;

struct CFastBuffer<struct_CInputDevice::SRumble> {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorPuzzle CTrackManiaEditorPuzzle, *PCTrackManiaEditorPuzzle;

struct CTrackManiaEditorPuzzle {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetSource*> CFastBuffer<class_CNetSource*>, *PCFastBuffer<class_CNetSource*>;

struct CFastBuffer<class_CNetSource*> {
    undefined field0_0x0;
};

typedef struct CGameNetOnlineNews CGameNetOnlineNews, *PCGameNetOnlineNews;

struct CGameNetOnlineNews {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsPortalProperty SMwParamInfos_CHmsPortalProperty, *PSMwParamInfos_CHmsPortalProperty;

struct SMwParamInfos_CHmsPortalProperty {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraEffectGroup SMwParamInfos_CGameControlCameraEffectGroup, *PSMwParamInfos_CGameControlCameraEffectGroup;

struct SMwParamInfos_CGameControlCameraEffectGroup {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3 CMwCmdExpVec3, *PCMwCmdExpVec3;

struct CMwCmdExpVec3 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwClassInfoViewer SMwParamInfos_CMwClassInfoViewer, *PSMwParamInfos_CMwClassInfoViewer;

struct SMwParamInfos_CMwClassInfoViewer {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoFlat CGameCtnBlockInfoFlat, *PCGameCtnBlockInfoFlat;

struct CGameCtnBlockInfoFlat {
    undefined field0_0x0;
};

typedef enum ESpectatorCameraType {
} ESpectatorCameraType;

typedef struct CMwCmdExpIso4Function CMwCmdExpIso4Function, *PCMwCmdExpIso4Function;

struct CMwCmdExpIso4Function {
    undefined field0_0x0;
};

typedef struct DIEFFECTINFOW DIEFFECTINFOW, *PDIEFFECTINFOW;

struct DIEFFECTINFOW {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaPlayerInfo::SRpcPlayerQuickInfo> CFastBuffer<struct_CTrackManiaPlayerInfo::SRpcPlayerQuickInfo>, *PCFastBuffer<struct_CTrackManiaPlayerInfo::SRpcPlayerQuickInfo>;

struct CFastBuffer<struct_CTrackManiaPlayerInfo::SRpcPlayerQuickInfo> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugMaterial> CFastBufferRef<class_CPlugMaterial>, *PCFastBufferRef<class_CPlugMaterial>;

struct CFastBufferRef<class_CPlugMaterial> {
    undefined field0_0x0;
};

typedef struct SPlugTreeInRenderFlags SPlugTreeInRenderFlags, *PSPlugTreeInRenderFlags;

struct SPlugTreeInRenderFlags {
    undefined field0_0x0;
};

typedef struct SSystemTime SSystemTime, *PSSystemTime;

struct SSystemTime {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneToyStem> CMwNodRef<class_CSceneToyStem>, *PCMwNodRef<class_CSceneToyStem>;

struct CMwNodRef<class_CSceneToyStem> {
    undefined field0_0x0;
};

typedef struct CGameAnalyzer CGameAnalyzer, *PCGameAnalyzer;

struct CGameAnalyzer {
    undefined field0_0x0;
};

typedef struct SFieldUpTo14 SFieldUpTo14, *PSFieldUpTo14;

struct SFieldUpTo14 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneFx>_> CFastBuffer<class_CMwNodRef<class_CSceneFx>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneFx>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneFx>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsPackLightMapCache::SMap> CFastBuffer<struct_CHmsPackLightMapCache::SMap>, *PCFastBuffer<struct_CHmsPackLightMapCache::SMap>;

struct CFastBuffer<struct_CHmsPackLightMapCache::SMap> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemData SMwParamInfos_CSystemData, *PSMwParamInfos_CSystemData;

struct SMwParamInfos_CSystemData {
    undefined field0_0x0;
};

typedef struct CDx9VisualKeeper CDx9VisualKeeper, *PCDx9VisualKeeper;

struct CDx9VisualKeeper {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMotorbikeEnvMaterial SMwParamInfos_CSceneMotorbikeEnvMaterial, *PSMwParamInfos_CSceneMotorbikeEnvMaterial;

struct SMwParamInfos_CSceneMotorbikeEnvMaterial {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockTransitionFade SMwParamInfos_CGameCtnMediaBlockTransitionFade, *PSMwParamInfos_CGameCtnMediaBlockTransitionFade;

struct SMwParamInfos_CGameCtnMediaBlockTransitionFade {
    undefined field0_0x0;
};

typedef struct SPacked SPacked, *PSPacked;

struct SPacked {
    undefined field0_0x0;
};

typedef struct CControlEffectSimi CControlEffectSimi, *PCControlEffectSimi;

struct CControlEffectSimi {
    undefined field0_0x0;
};

typedef struct CMwCmdExpIso4Ident CMwCmdExpIso4Ident, *PCMwCmdExpIso4Ident;

struct CMwCmdExpIso4Ident {
    undefined field0_0x0;
};

typedef struct COalDevice COalDevice, *PCOalDevice;

struct COalDevice {
    undefined field0_0x0;
};

typedef struct SNetConfig SNetConfig, *PSNetConfig;

struct SNetConfig {
    undefined field0_0x0;
};

typedef struct SReplayToValidateData SReplayToValidateData, *PSReplayToValidateData;

struct SReplayToValidateData {
    undefined field0_0x0;
};

typedef struct CControlImage CControlImage, *PCControlImage;

struct CControlImage {
    undefined field0_0x0;
};

typedef struct SPrecalcLighing_Spot SPrecalcLighing_Spot, *PSPrecalcLighing_Spot;

struct SPrecalcLighing_Spot {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockFxBloom SMwParamInfos_CGameCtnMediaBlockFxBloom, *PSMwParamInfos_CGameCtnMediaBlockFxBloom;

struct SMwParamInfos_CGameCtnMediaBlockFxBloom {
    undefined field0_0x0;
};

typedef struct CControlLayout CControlLayout, *PCControlLayout;

struct CControlLayout {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameNetOnlineMessage>_> CFastBuffer<class_CMwNodRef<class_CGameNetOnlineMessage>_>, *PCFastBuffer<class_CMwNodRef<class_CGameNetOnlineMessage>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameNetOnlineMessage>_> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugVertexStream> CMwNodRef<class_CPlugVertexStream>, *PCMwNodRef<class_CPlugVertexStream>;

struct CMwNodRef<class_CPlugVertexStream> {
    undefined field0_0x0;
};

typedef struct SPlayerRecord SPlayerRecord, *PSPlayerRecord;

struct SPlayerRecord {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameManialink::SDicoEntry> CFastBuffer<struct_CGameManialink::SDicoEntry>, *PCFastBuffer<struct_CGameManialink::SDicoEntry>;

struct CFastBuffer<struct_CGameManialink::SDicoEntry> {
    undefined field0_0x0;
};

typedef enum EImportType {
} EImportType;

typedef struct SMwParamInfos_CPlugMusic SMwParamInfos_CPlugMusic, *PSMwParamInfos_CPlugMusic;

struct SMwParamInfos_CPlugMusic {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum_EPlugGpuRegSet,218,unsigned_long> CFixedArray<enum_EPlugGpuRegSet,218,unsigned_long>, *PCFixedArray<enum_EPlugGpuRegSet,218,unsigned_long>;

struct CFixedArray<enum_EPlugGpuRegSet,218,unsigned_long> {
    undefined field0_0x0;
};

typedef enum _D3DTEXTUREFILTERTYPE {
} _D3DTEXTUREFILTERTYPE;

typedef struct CFastBuffer<struct_SPlugGpuDefine> CFastBuffer<struct_SPlugGpuDefine>, *PCFastBuffer<struct_SPlugGpuDefine>;

struct CFastBuffer<struct_SPlugGpuDefine> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncVisualShiver SMwParamInfos_CFuncVisualShiver, *PSMwParamInfos_CFuncVisualShiver;

struct SMwParamInfos_CFuncVisualShiver {
    undefined field0_0x0;
};

typedef enum EBoatType {
} EBoatType;

typedef struct SMwParamInfos_CMwCmdScriptVarVec3 SMwParamInfos_CMwCmdScriptVarVec3, *PSMwParamInfos_CMwCmdScriptVarVec3;

struct SMwParamInfos_CMwCmdScriptVarVec3 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameControlGridCtnChallengeGroup>_> CFastBuffer<class_CMwNodRef<class_CGameControlGridCtnChallengeGroup>_>, *PCFastBuffer<class_CMwNodRef<class_CGameControlGridCtnChallengeGroup>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameControlGridCtnChallengeGroup>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarVec2 SMwParamInfos_CMwCmdScriptVarVec2, *PSMwParamInfos_CMwCmdScriptVarVec2;

struct SMwParamInfos_CMwCmdScriptVarVec2 {
    undefined field0_0x0;
};

typedef struct CSceneObject CSceneObject, *PCSceneObject;

struct CSceneObject {
    undefined field0_0x0;
};

typedef struct SPickItem SPickItem, *PSPickItem;

struct SPickItem {
    undefined field0_0x0;
};

typedef enum ESetUpAction {
} ESetUpAction;

typedef struct CXmlNod CXmlNod, *PCXmlNod;

struct CXmlNod {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoSlope SMwParamInfos_CGameCtnBlockInfoSlope, *PSMwParamInfos_CGameCtnBlockInfoSlope;

struct SMwParamInfos_CGameCtnBlockInfoSlope {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmVec4> CFastArray<class_GmVec4>, *PCFastArray<class_GmVec4>;

struct CFastArray<class_GmVec4> {
    undefined field0_0x0;
};

typedef struct VertexCache VertexCache, *PVertexCache;

struct VertexCache {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaEnvironmentManager SMwParamInfos_CTrackManiaEnvironmentManager, *PSMwParamInfos_CTrackManiaEnvironmentManager;

struct SMwParamInfos_CTrackManiaEnvironmentManager {
    undefined field0_0x0;
};

typedef struct SVectMap SVectMap, *PSVectMap;

struct SVectMap {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>::SBuildInput> CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>::SBuildInput>, *PCFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>::SBuildInput>;

struct CFastBuffer<struct_GmOctreeLowMem<struct_GmOctreeLowMemCell_i15b>::SBuildInput> {
    undefined field0_0x0;
};

typedef struct SSkinData SSkinData, *PSSkinData;

struct SSkinData {
    undefined field0_0x0;
};

typedef struct CFixedArray<char,4,unsigned_long> CFixedArray<char,4,unsigned_long>, *PCFixedArray<char,4,unsigned_long>;

struct CFixedArray<char,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CGameDialogs CGameDialogs, *PCGameDialogs;

struct CGameDialogs {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpNumBin SMwParamInfos_CMwCmdExpNumBin, *PSMwParamInfos_CMwCmdExpNumBin;

struct SMwParamInfos_CMwCmdExpNumBin {
    undefined field0_0x0;
};

typedef struct CPlugFileSndGen CPlugFileSndGen, *PCPlugFileSndGen;

struct CPlugFileSndGen {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmVec2> CFastArray<class_GmVec2>, *PCFastArray<class_GmVec2>;

struct CFastArray<class_GmVec2> {
    undefined field0_0x0;
};

typedef struct SLoadDesc SLoadDesc, *PSLoadDesc;

struct SLoadDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct SSurface SSurface, *PSSurface;

struct SSurface {
    undefined field0_0x0;
};

typedef struct CPlugFileFidCache CPlugFileFidCache, *PCPlugFileFidCache;

struct CPlugFileFidCache {
    undefined field0_0x0;
};

typedef struct SRpcPackDescInfo SRpcPackDescInfo, *PSRpcPackDescInfo;

struct SRpcPackDescInfo {
    undefined field0_0x0;
};

typedef struct SZone SZone, *PSZone;

struct SZone {
    undefined field0_0x0;
};

typedef struct ctype<char> ctype<char>, *Pctype<char>;

struct ctype<char> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmVec3> CFastArray<class_GmVec3>, *PCFastArray<class_GmVec3>;

struct CFastArray<class_GmVec3> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CControlBase>_> CFastBuffer<class_CMwNodRef<class_CControlBase>_>, *PCFastBuffer<class_CMwNodRef<class_CControlBase>_>;

struct CFastBuffer<class_CMwNodRef<class_CControlBase>_> {
    undefined field0_0x0;
};

typedef struct SRpcPlayerRanking SRpcPlayerRanking, *PSRpcPlayerRanking;

struct SRpcPlayerRanking {
    undefined field0_0x0;
};

typedef struct SAutoStartParams SAutoStartParams, *PSAutoStartParams;

struct SAutoStartParams {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GxColor> CFastBuffer<class_GxColor>, *PCFastBuffer<class_GxColor>;

struct CFastBuffer<class_GxColor> {
    undefined field0_0x0;
};

typedef struct SBill SBill, *PSBill;

struct SBill {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlMatchSettingsCard SMwParamInfos_CTrackManiaControlMatchSettingsCard, *PSMwParamInfos_CTrackManiaControlMatchSettingsCard;

struct SMwParamInfos_CTrackManiaControlMatchSettingsCard {
    undefined field0_0x0;
};

typedef struct CNetFileTransferUpload CNetFileTransferUpload, *PCNetFileTransferUpload;

struct CNetFileTransferUpload {
    undefined field0_0x0;
};

typedef enum ESpriteColor0 {
} ESpriteColor0;

typedef struct SCallStackFidContext SCallStackFidContext, *PSCallStackFidContext;

struct SCallStackFidContext {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionPlay SMwParamInfos_CMotionPlay, *PSMwParamInfos_CMotionPlay;

struct SMwParamInfos_CMotionPlay {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugTree*> CFastBuffer<class_CPlugTree*>, *PCFastBuffer<class_CPlugTree*>;

struct CFastBuffer<class_CPlugTree*> {
    undefined field0_0x0;
};

typedef struct CGameCtnArticle CGameCtnArticle, *PCGameCtnArticle;

struct CGameCtnArticle {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugVisual3D SMwParamInfos_CPlugVisual3D, *PSMwParamInfos_CPlugVisual3D;

struct SMwParamInfos_CPlugVisual3D {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapAddress SMwParamInfos_CPlugBitmapAddress, *PSMwParamInfos_CPlugBitmapAddress;

struct SMwParamInfos_CPlugBitmapAddress {
    undefined field0_0x0;
};

typedef struct _s_CatchableType _s_CatchableType, *P_s_CatchableType;

struct _s_CatchableType {
    undefined field0_0x0;
};

typedef struct CGameChampionship CGameChampionship, *PCGameChampionship;

struct CGameChampionship {
    undefined field0_0x0;
};

typedef struct CGameCampaignScores CGameCampaignScores, *PCGameCampaignScores;

struct CGameCampaignScores {
    undefined field0_0x0;
};

typedef struct STrainingMedalsScores STrainingMedalsScores, *PSTrainingMedalsScores;

struct STrainingMedalsScores {
    undefined field0_0x0;
};

typedef struct SApplyField2 SApplyField2, *PSApplyField2;

struct SApplyField2 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGameCtnPainter::CConstructionImage> CFastBuffer<class_CGameCtnPainter::CConstructionImage>, *PCFastBuffer<class_CGameCtnPainter::CConstructionImage>;

struct CFastBuffer<class_CGameCtnPainter::CConstructionImage> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileImg SMwParamInfos_CPlugFileImg, *PSMwParamInfos_CPlugFileImg;

struct SMwParamInfos_CPlugFileImg {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockCamera CGameCtnMediaBlockCamera, *PCGameCtnMediaBlockCamera;

struct CGameCtnMediaBlockCamera {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameDialogShootVideo SMwParamInfos_CGameDialogShootVideo, *PSMwParamInfos_CGameDialogShootVideo;

struct SMwParamInfos_CGameDialogShootVideo {
    undefined field0_0x0;
};

typedef struct SPixelCopy SPixelCopy, *PSPixelCopy;

struct SPixelCopy {
    undefined field0_0x0;
};

typedef struct CGameFeatures CGameFeatures, *PCGameFeatures;

struct CGameFeatures {
    undefined field0_0x0;
};

typedef struct CMotionParticleEmitterModel CMotionParticleEmitterModel, *PCMotionParticleEmitterModel;

struct CMotionParticleEmitterModel {
    undefined field0_0x0;
};

typedef struct CPlugGpuCompileCache CPlugGpuCompileCache, *PCPlugGpuCompileCache;

struct CPlugGpuCompileCache {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsZoneVPacker::SClipPlane> CFastBuffer<struct_CHmsZoneVPacker::SClipPlane>, *PCFastBuffer<struct_CHmsZoneVPacker::SClipPlane>;

struct CFastBuffer<struct_CHmsZoneVPacker::SClipPlane> {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamColor> CMwParamFastArray<class_CMwParamColor>, *PCMwParamFastArray<class_CMwParamColor>;

struct CMwParamFastArray<class_CMwParamColor> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SBlendShapeFrame> CFastBuffer<struct_CPlugModelMesh::SBlendShapeFrame>, *PCFastBuffer<struct_CPlugModelMesh::SBlendShapeFrame>;

struct CFastBuffer<struct_CPlugModelMesh::SBlendShapeFrame> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Sub CMwCmdExpVec3Sub, *PCMwCmdExpVec3Sub;

struct CMwCmdExpVec3Sub {
    undefined field0_0x0;
};

typedef struct CHighFreqCallback CHighFreqCallback, *PCHighFreqCallback;

struct CHighFreqCallback {
    undefined field0_0x0;
};

typedef struct ios_base ios_base, *Pios_base;

struct ios_base {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CPlugBlendShapeVertex> CFastArray<class_CPlugBlendShapeVertex>, *PCFastArray<class_CPlugBlendShapeVertex>;

struct CFastArray<class_CPlugBlendShapeVertex> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockFxColors CMwClassInfoCGameCtnMediaBlockFxColors, *PCMwClassInfoCGameCtnMediaBlockFxColors;

struct CMwClassInfoCGameCtnMediaBlockFxColors {
    undefined field0_0x0;
};

typedef struct z_stream_s z_stream_s, *Pz_stream_s;

struct z_stream_s {
    undefined field0_0x0;
};

typedef enum ETriSpin {
} ETriSpin;

typedef struct CHmsForceField CHmsForceField, *PCHmsForceField;

struct CHmsForceField {
    undefined field0_0x0;
};

typedef struct CGameControlCardMessage CGameControlCardMessage, *PCGameControlCardMessage;

struct CGameControlCardMessage {
    undefined field0_0x0;
};

typedef struct SHemiInfo SHemiInfo, *PSHemiInfo;

struct SHemiInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CMotionManager>_> CFastBuffer<class_CMwNodRef<class_CMotionManager>_>, *PCFastBuffer<class_CMwNodRef<class_CMotionManager>_>;

struct CFastBuffer<class_CMwNodRef<class_CMotionManager>_> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_GmSurfMesh::STriangle> CFastArray<struct_GmSurfMesh::STriangle>, *PCFastArray<struct_GmSurfMesh::STriangle>;

struct CFastArray<struct_GmSurfMesh::STriangle> {
    undefined field0_0x0;
};

typedef enum ECardinalDir {
} ECardinalDir;

typedef struct CFastBuffer<struct_CPlugVisual::SSkinIndex> CFastBuffer<struct_CPlugVisual::SSkinIndex>, *PCFastBuffer<struct_CPlugVisual::SSkinIndex>;

struct CFastBuffer<struct_CPlugVisual::SSkinIndex> {
    undefined field0_0x0;
};

typedef struct CSysFidNodRef<class_CHmsPackLightMap> CSysFidNodRef<class_CHmsPackLightMap>, *PCSysFidNodRef<class_CHmsPackLightMap>;

struct CSysFidNodRef<class_CHmsPackLightMap> {
    undefined field0_0x0;
};

typedef struct CGamePopUp CGamePopUp, *PCGamePopUp;

struct CGamePopUp {
    undefined field0_0x0;
};

typedef struct CGameNetFileTransfer CGameNetFileTransfer, *PCGameNetFileTransfer;

struct CGameNetFileTransfer {
    undefined field0_0x0;
};

typedef struct CGameControlPlayerAvatar CGameControlPlayerAvatar, *PCGameControlPlayerAvatar;

struct CGameControlPlayerAvatar {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_> CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>, *PCFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_>;

struct CFastBufferKey<class_CMwNodRef<class_CFuncCurvesReal>_> {
    undefined field0_0x0;
};

typedef struct CSceneTrafficPath CSceneTrafficPath, *PCSceneTrafficPath;

struct CSceneTrafficPath {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CDx9DeviceCaps::SFormat> CFastArray<struct_CDx9DeviceCaps::SFormat>, *PCFastArray<struct_CDx9DeviceCaps::SFormat>;

struct CFastArray<struct_CDx9DeviceCaps::SFormat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoClip SMwParamInfos_CGameCtnBlockInfoClip, *PSMwParamInfos_CGameCtnBlockInfoClip;

struct SMwParamInfos_CGameCtnBlockInfoClip {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlock SMwParamInfos_CGameCtnMediaBlock, *PSMwParamInfos_CGameCtnMediaBlock;

struct SMwParamInfos_CGameCtnMediaBlock {
    undefined field0_0x0;
};

typedef struct CMwCmdSwitch CMwCmdSwitch, *PCMwCmdSwitch;

struct CMwCmdSwitch {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneSector>_> CFastBuffer<class_CMwNodRef<class_CSceneSector>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneSector>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneSector>_> {
    undefined field0_0x0;
};

typedef struct CFastBufferStringInt CFastBufferStringInt, *PCFastBufferStringInt;

struct CFastBufferStringInt {
    undefined field0_0x0;
};

typedef struct CMwCmdExpClassFunction CMwCmdExpClassFunction, *PCMwCmdExpClassFunction;

struct CMwCmdExpClassFunction {
    undefined field0_0x0;
};

typedef struct SPlugVDcls SPlugVDcls, *PSPlugVDcls;

struct SPlugVDcls {
    undefined field0_0x0;
};

typedef struct CPlugVolumeShadow CPlugVolumeShadow, *PCPlugVolumeShadow;

struct CPlugVolumeShadow {
    undefined field0_0x0;
};

typedef struct CMwCmdExpString CMwCmdExpString, *PCMwCmdExpString;

struct CMwCmdExpString {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetHttpResult*> CFastBuffer<class_CNetHttpResult*>, *PCFastBuffer<class_CNetHttpResult*>;

struct CFastBuffer<class_CNetHttpResult*> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceNetLaps CTrackManiaRaceNetLaps, *PCTrackManiaRaceNetLaps;

struct CTrackManiaRaceNetLaps {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CInputPort SMwParamInfos_CInputPort, *PSMwParamInfos_CInputPort;

struct SMwParamInfos_CInputPort {
    undefined field0_0x0;
};

typedef struct SRenderInfo SRenderInfo, *PSRenderInfo;

struct SRenderInfo {
    undefined field0_0x0;
};

typedef struct CMotionParticleType CMotionParticleType, *PCMotionParticleType;

struct CMotionParticleType {
    undefined field0_0x0;
};

typedef struct SEventStunt SEventStunt, *PSEventStunt;

struct SEventStunt {
    undefined field0_0x0;
};

typedef struct SVehicleState SVehicleState, *PSVehicleState;

struct SVehicleState {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmQuat,struct_SFastCat> CFastBufferCat<class_GmQuat,struct_SFastCat>, *PCFastBufferCat<class_GmQuat,struct_SFastCat>;

struct CFastBufferCat<class_GmQuat,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneObject>_> CFastBuffer<class_CMwNodRef<class_CSceneObject>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneObject>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneObject>_> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockSound CGameCtnMediaBlockSound, *PCGameCtnMediaBlockSound;

struct CGameCtnMediaBlockSound {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceInterface SMwParamInfos_CTrackManiaRaceInterface, *PSMwParamInfos_CTrackManiaRaceInterface;

struct SMwParamInfos_CTrackManiaRaceInterface {
    undefined field0_0x0;
};

typedef struct SInstanceId SInstanceId, *PSInstanceId;

struct SInstanceId {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2 CMwCmdExpVec2, *PCMwCmdExpVec2;

struct CMwCmdExpVec2 {
    undefined field0_0x0;
};

typedef enum EAsyncOp {
} EAsyncOp;

typedef struct CTrackManiaEnvironmentManager CTrackManiaEnvironmentManager, *PCTrackManiaEnvironmentManager;

struct CTrackManiaEnvironmentManager {
    undefined field0_0x0;
};

typedef struct GmClipFlag_HalfCube GmClipFlag_HalfCube, *PGmClipFlag_HalfCube;

struct GmClipFlag_HalfCube {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoFrontier CGameCtnBlockInfoFrontier, *PCGameCtnBlockInfoFrontier;

struct CGameCtnBlockInfoFrontier {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdBuffer SMwParamInfos_CMwCmdBuffer, *PSMwParamInfos_CMwCmdBuffer;

struct SMwParamInfos_CMwCmdBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemFidFile SMwParamInfos_CSystemFidFile, *PSMwParamInfos_CSystemFidFile;

struct SMwParamInfos_CSystemFidFile {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SGameCtnRacePlayerCheckpoint> CFastArray<struct_SGameCtnRacePlayerCheckpoint>, *PCFastArray<struct_SGameCtnRacePlayerCheckpoint>;

struct CFastArray<struct_SGameCtnRacePlayerCheckpoint> {
    undefined field0_0x0;
};

typedef struct GmRectAligned GmRectAligned, *PGmRectAligned;

struct GmRectAligned {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<struct_CPlugBitmap::SCompress*> CFastCallback1P<struct_CPlugBitmap::SCompress*>, *PCFastCallback1P<struct_CPlugBitmap::SCompress*>;

struct CFastCallback1P<struct_CPlugBitmap::SCompress*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlQuad SMwParamInfos_CControlQuad, *PSMwParamInfos_CControlQuad;

struct SMwParamInfos_CControlQuad {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlTrackManiaTeamCard SMwParamInfos_CControlTrackManiaTeamCard, *PSMwParamInfos_CControlTrackManiaTeamCard;

struct SMwParamInfos_CControlTrackManiaTeamCard {
    undefined field0_0x0;
};

typedef union UNumValue UNumValue, *PUNumValue;

union UNumValue {
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneToyCharacterTuning>_> CFastBuffer<class_CMwNodRef<class_CSceneToyCharacterTuning>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneToyCharacterTuning>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneToyCharacterTuning>_> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumCastedEnum CMwCmdExpNumCastedEnum, *PCMwCmdExpNumCastedEnum;

struct CMwCmdExpNumCastedEnum {
    undefined field0_0x0;
};

typedef struct CGamePlayer CGamePlayer, *PCGamePlayer;

struct CGamePlayer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneSoundSource SMwParamInfos_CSceneSoundSource, *PSMwParamInfos_CSceneSoundSource;

struct SMwParamInfos_CSceneSoundSource {
    undefined field0_0x0;
};

typedef struct CGameMenuScaleEffect CGameMenuScaleEffect, *PCGameMenuScaleEffect;

struct CGameMenuScaleEffect {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugVertexStream::SStreamOrDeclType> CFastBuffer<struct_CPlugVertexStream::SStreamOrDeclType>, *PCFastBuffer<struct_CPlugVertexStream::SStreamOrDeclType>;

struct CFastBuffer<struct_CPlugVertexStream::SStreamOrDeclType> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamStringInt> CMwParamFastBufferCat<class_CMwParamStringInt>, *PCMwParamFastBufferCat<class_CMwParamStringInt>;

struct CMwParamFastBufferCat<class_CMwParamStringInt> {
    undefined field0_0x0;
};

typedef struct length_error length_error, *Plength_error;

struct length_error {
    undefined field0_0x0;
};

typedef enum ELinkType {
} ELinkType;

typedef struct CSceneToyDisplayProgress CSceneToyDisplayProgress, *PCSceneToyDisplayProgress;

struct CSceneToyDisplayProgress {
    undefined field0_0x0;
};

typedef struct SCompressRotation SCompressRotation, *PSCompressRotation;

struct SCompressRotation {
    undefined field0_0x0;
};

typedef struct CLoaderZip CLoaderZip, *PCLoaderZip;

struct CLoaderZip {
    undefined field0_0x0;
};

typedef struct CGameLadderRanking CGameLadderRanking, *PCGameLadderRanking;

struct CGameLadderRanking {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelLodMesh::SDataLayer> CFastBuffer<struct_CPlugModelLodMesh::SDataLayer>, *PCFastBuffer<struct_CPlugModelLodMesh::SDataLayer>;

struct CFastBuffer<struct_CPlugModelLodMesh::SDataLayer> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaSwitcher SMwParamInfos_CTrackManiaSwitcher, *PSMwParamInfos_CTrackManiaSwitcher;

struct SMwParamInfos_CTrackManiaSwitcher {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameControlCardCalendar::SMonth*> CFastBuffer<struct_CGameControlCardCalendar::SMonth*>, *PCFastBuffer<struct_CGameControlCardCalendar::SMonth*>;

struct CFastBuffer<struct_CGameControlCardCalendar::SMonth*> {
    undefined field0_0x0;
};

typedef struct SQuat_6 SQuat_6, *PSQuat_6;

struct SQuat_6 {
    undefined field0_0x0;
};

typedef struct CGenAudioSoundMulti<class_COalAudioSound> CGenAudioSoundMulti<class_COalAudioSound>, *PCGenAudioSoundMulti<class_COalAudioSound>;

struct CGenAudioSoundMulti<class_COalAudioSound> {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarBool CMwCmdScriptVarBool, *PCMwCmdScriptVarBool;

struct CMwCmdScriptVarBool {
    undefined field0_0x0;
};

typedef struct GmVector2<unsigned_long> GmVector2<unsigned_long>, *PGmVector2<unsigned_long>;

struct GmVector2<unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPfmNode CPfmNode, *PCPfmNode;

struct CPfmNode {
    undefined field0_0x0;
};

typedef struct CDx9IndexBuffer CDx9IndexBuffer, *PCDx9IndexBuffer;

struct CDx9IndexBuffer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetIPSource*> CFastBuffer<class_CNetIPSource*>, *PCFastBuffer<class_CNetIPSource*>;

struct CFastBuffer<class_CNetIPSource*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameNetTeamInfo>_> CFastBuffer<class_CMwNodRef<class_CGameNetTeamInfo>_>, *PCFastBuffer<class_CMwNodRef<class_CGameNetTeamInfo>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameNetTeamInfo>_> {
    undefined field0_0x0;
};

typedef struct SLineFlags SLineFlags, *PSLineFlags;

struct SLineFlags {
    undefined field0_0x0;
};

typedef enum EGxAlphaCmp {
} EGxAlphaCmp;

typedef struct CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> CFastBuffer<struct_CVisionViewportDx9::SLoadedLight>, *PCFastBuffer<struct_CVisionViewportDx9::SLoadedLight>;

struct CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRace1PGhosts CTrackManiaRace1PGhosts, *PCTrackManiaRace1PGhosts;

struct CTrackManiaRace1PGhosts {
    undefined field0_0x0;
};

typedef struct runtime_error runtime_error, *Pruntime_error;

struct runtime_error {
    undefined field0_0x0;
};

typedef enum EServerInfoArchiveState {
} EServerInfoArchiveState;

typedef struct CFastBuffer<class_CMwNodRef<class_CBoatTeamMateActionDesc>_> CFastBuffer<class_CMwNodRef<class_CBoatTeamMateActionDesc>_>, *PCFastBuffer<class_CMwNodRef<class_CBoatTeamMateActionDesc>_>;

struct CFastBuffer<class_CMwNodRef<class_CBoatTeamMateActionDesc>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnZoneFrontier SMwParamInfos_CGameCtnZoneFrontier, *PSMwParamInfos_CGameCtnZoneFrontier;

struct SMwParamInfos_CGameCtnZoneFrontier {
    undefined field0_0x0;
};

typedef enum EReload {
} EReload;

typedef struct CFuncNoise CFuncNoise, *PCFuncNoise;

struct CFuncNoise {
    undefined field0_0x0;
};

typedef struct SPacked_Before2007_02_27 SPacked_Before2007_02_27, *PSPacked_Before2007_02_27;

struct SPacked_Before2007_02_27 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxDistor2d SMwParamInfos_CSceneFxDistor2d, *PSMwParamInfos_CSceneFxDistor2d;

struct SMwParamInfos_CSceneFxDistor2d {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnZoneTest SMwParamInfos_CGameCtnZoneTest, *PSMwParamInfos_CGameCtnZoneTest;

struct SMwParamInfos_CGameCtnZoneTest {
    undefined field0_0x0;
};

typedef struct GmLocOrbitVal GmLocOrbitVal, *PGmLocOrbitVal;

struct GmLocOrbitVal {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneExtraFlocking::SBirdData*> CFastBuffer<struct_CSceneExtraFlocking::SBirdData*>, *PCFastBuffer<struct_CSceneExtraFlocking::SBirdData*>;

struct CFastBuffer<struct_CSceneExtraFlocking::SBirdData*> {
    undefined field0_0x0;
};

typedef struct CNetServer CNetServer, *PCNetServer;

struct CNetServer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEntry SMwParamInfos_CControlEntry, *PSMwParamInfos_CControlEntry;

struct SMwParamInfos_CControlEntry {
    undefined field0_0x0;
};

typedef struct CGameCtnDecorationTerrainModifier CGameCtnDecorationTerrainModifier, *PCGameCtnDecorationTerrainModifier;

struct CGameCtnDecorationTerrainModifier {
    undefined field0_0x0;
};

typedef struct SMemberInfo SMemberInfo, *PSMemberInfo;

struct SMemberInfo {
    undefined field0_0x0;
};

typedef struct CSystemFidsDrive CSystemFidsDrive, *PCSystemFidsDrive;

struct CSystemFidsDrive {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugVisual::SSplit> CFastBuffer<struct_CPlugVisual::SSplit>, *PCFastBuffer<struct_CPlugVisual::SSplit>;

struct CFastBuffer<struct_CPlugVisual::SSplit> {
    undefined field0_0x0;
};

typedef struct _Lockit _Lockit, *P_Lockit;

struct _Lockit {
    undefined field0_0x0;
};

typedef struct SAxis SAxis, *PSAxis;

struct SAxis {
    undefined field0_0x0;
};

typedef struct CCacheTweakKeysTrans CCacheTweakKeysTrans, *PCCacheTweakKeysTrans;

struct CCacheTweakKeysTrans {
    undefined field0_0x0;
};

typedef struct SRequirementOld10 SRequirementOld10, *PSRequirementOld10;

struct SRequirementOld10 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMobilFlockAttractor SMwParamInfos_CSceneMobilFlockAttractor, *PSMwParamInfos_CSceneMobilFlockAttractor;

struct SMwParamInfos_CSceneMobilFlockAttractor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemFids SMwParamInfos_CSystemFids, *PSMwParamInfos_CSystemFids;

struct SMwParamInfos_CSystemFids {
    undefined field0_0x0;
};

typedef struct CSceneToySubway CSceneToySubway, *PCSceneToySubway;

struct CSceneToySubway {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamVec4> CMwParamFastBuffer<class_CMwParamVec4>, *PCMwParamFastBuffer<class_CMwParamVec4>;

struct CMwParamFastBuffer<class_CMwParamVec4> {
    undefined field0_0x0;
};

typedef enum _D3DTEXTURESTAGESTATETYPE {
} _D3DTEXTURESTAGESTATETYPE;

typedef struct SMenuLeaguePathStepInfos SMenuLeaguePathStepInfos, *PSMenuLeaguePathStepInfos;

struct SMenuLeaguePathStepInfos {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/PMD - /ehdata.h/PMD */

typedef struct SFastKey<struct_CVisionViewport::SLensFlare,class_CHmsCorpusLight*> SFastKey<struct_CVisionViewport::SLensFlare,class_CHmsCorpusLight*>, *PSFastKey<struct_CVisionViewport::SLensFlare,class_CHmsCorpusLight*>;

struct SFastKey<struct_CVisionViewport::SLensFlare,class_CHmsCorpusLight*> {
    undefined field0_0x0;
};

typedef struct CHmsZoneElem CHmsZoneElem, *PCHmsZoneElem;

struct CHmsZoneElem {
    undefined field0_0x0;
};

typedef struct CConstArray<class_GmVec4> CConstArray<class_GmVec4>, *PCConstArray<class_GmVec4>;

struct CConstArray<class_GmVec4> {
    undefined field0_0x0;
};

typedef struct ALCdevice_struct ALCdevice_struct, *PALCdevice_struct;

struct ALCdevice_struct {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraOrbital SMwParamInfos_CGameCtnMediaBlockCameraOrbital, *PSMwParamInfos_CGameCtnMediaBlockCameraOrbital;

struct SMwParamInfos_CGameCtnMediaBlockCameraOrbital {
    undefined field0_0x0;
};

typedef struct CMotionWindBlocker CMotionWindBlocker, *PCMotionWindBlocker;

struct CMotionWindBlocker {
    undefined field0_0x0;
};

typedef struct CFastArray<class_GmQuat> CFastArray<class_GmQuat>, *PCFastArray<class_GmQuat>;

struct CFastArray<class_GmQuat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlugModelFurFluff> CFastBuffer<struct_SPlugModelFurFluff>, *PCFastBuffer<struct_SPlugModelFurFluff>;

struct CFastBuffer<struct_SPlugModelFurFluff> {
    undefined field0_0x0;
};

typedef struct CClassicBufferMemory CClassicBufferMemory, *PCClassicBufferMemory;

struct CClassicBufferMemory {
    undefined field0_0x0;
};

typedef enum ELightMapQuality {
} ELightMapQuality;

typedef struct CInputDeviceDx8Keyboard CInputDeviceDx8Keyboard, *PCInputDeviceDx8Keyboard;

struct CInputDeviceDx8Keyboard {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugBitmap> CFastBufferRef<class_CPlugBitmap>, *PCFastBufferRef<class_CPlugBitmap>;

struct CFastBufferRef<class_CPlugBitmap> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleStruct SMwParamInfos_CSceneVehicleStruct, *PSMwParamInfos_CSceneVehicleStruct;

struct SMwParamInfos_CSceneVehicleStruct {
    undefined field0_0x0;
};

typedef struct CMotionTimerLoop CMotionTimerLoop, *PCMotionTimerLoop;

struct CMotionTimerLoop {
    undefined field0_0x0;
};

typedef struct CCacheArray CCacheArray, *PCCacheArray;

struct CCacheArray {
    undefined field0_0x0;
};

typedef struct SOldBlendShape SOldBlendShape, *PSOldBlendShape;

struct SOldBlendShape {
    undefined field0_0x0;
};

typedef struct AsyncIOData AsyncIOData, *PAsyncIOData;

struct AsyncIOData {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_MEMORYSTATUS - /winbase.h/_MEMORYSTATUS */

typedef struct CFixedArray<struct_CSceneVehicle::SEnvironment,2,unsigned_long> CFixedArray<struct_CSceneVehicle::SEnvironment,2,unsigned_long>, *PCFixedArray<struct_CSceneVehicle::SEnvironment,2,unsigned_long>;

struct CFixedArray<struct_CSceneVehicle::SEnvironment,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsZoneVPacker::SVisualWrap> CFastBuffer<struct_CHmsZoneVPacker::SVisualWrap>, *PCFastBuffer<struct_CHmsZoneVPacker::SVisualWrap>;

struct CFastBuffer<struct_CHmsZoneVPacker::SVisualWrap> {
    undefined field0_0x0;
};

typedef struct CHmsCameraFx CHmsCameraFx, *PCHmsCameraFx;

struct CHmsCameraFx {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_> CFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnGhostInfo>_> {
    undefined field0_0x0;
};

typedef struct CPfmCell CPfmCell, *PCPfmCell;

struct CPfmCell {
    undefined field0_0x0;
};

typedef struct SDownloadProgress SDownloadProgress, *PSDownloadProgress;

struct SDownloadProgress {
    undefined field0_0x0;
};

typedef enum EFindWay {
} EFindWay;

typedef struct CControlStyle CControlStyle, *PCControlStyle;

struct CControlStyle {
    undefined field0_0x0;
};

typedef struct CFuncKeySkel CFuncKeySkel, *PCFuncKeySkel;

struct CFuncKeySkel {
    undefined field0_0x0;
};

typedef struct CAudioMusic CAudioMusic, *PCAudioMusic;

struct CAudioMusic {
    undefined field0_0x0;
};

typedef struct GmScaleTrans2 GmScaleTrans2, *PGmScaleTrans2;

struct GmScaleTrans2 {
    undefined field0_0x0;
};

typedef enum ERenderPath {
} ERenderPath;

typedef struct SQueueElem SQueueElem, *PSQueueElem;

struct SQueueElem {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_EXCEPTION_POINTERS - /excpt.h/_EXCEPTION_POINTERS */

typedef struct CFastBuffer<struct_CSceneVehicle::SVisualEmitter> CFastBuffer<struct_CSceneVehicle::SVisualEmitter>, *PCFastBuffer<struct_CSceneVehicle::SVisualEmitter>;

struct CFastBuffer<struct_CSceneVehicle::SVisualEmitter> {
    undefined field0_0x0;
};

typedef struct CControlUiElement CControlUiElement, *PCControlUiElement;

struct CControlUiElement {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugMaterialFxFur SMwParamInfos_CPlugMaterialFxFur, *PSMwParamInfos_CPlugMaterialFxFur;

struct SMwParamInfos_CPlugMaterialFxFur {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> CFastBufferCat<class_CHmsCorpus*,struct_SFastCat>, *PCFastBufferCat<class_CHmsCorpus*,struct_SFastCat>;

struct CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CMwNod> CMwNodRef<class_CMwNod>, *PCMwNodRef<class_CMwNod>;

struct CMwNodRef<class_CMwNod> {
    undefined field0_0x0;
};

typedef struct CSceneToyCharacterDesc CSceneToyCharacterDesc, *PCSceneToyCharacterDesc;

struct CSceneToyCharacterDesc {
    undefined field0_0x0;
};

typedef struct CGameControlEditDisplay CGameControlEditDisplay, *PCGameControlEditDisplay;

struct CGameControlEditDisplay {
    undefined field0_0x0;
};

typedef struct SBitmapSpecularsLA SBitmapSpecularsLA, *PSBitmapSpecularsLA;

struct SBitmapSpecularsLA {
    undefined field0_0x0;
};

typedef struct SLeaf SLeaf, *PSLeaf;

struct SLeaf {
    undefined field0_0x0;
};

typedef struct SParamsValue SParamsValue, *PSParamsValue;

struct SParamsValue {
    undefined field0_0x0;
};

typedef struct CFuncShaderLayerUV CFuncShaderLayerUV, *PCFuncShaderLayerUV;

struct CFuncShaderLayerUV {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CSceneToyStem> CFastBufferRef<class_CSceneToyStem>, *PCFastBufferRef<class_CSceneToyStem>;

struct CFastBufferRef<class_CSceneToyStem> {
    undefined field0_0x0;
};

typedef struct STMServerParameters STMServerParameters, *PSTMServerParameters;

struct STMServerParameters {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoPylon CGameCtnBlockInfoPylon, *PCGameCtnBlockInfoPylon;

struct CGameCtnBlockInfoPylon {
    undefined field0_0x0;
};

typedef struct STextSettings_ColorAndChars STextSettings_ColorAndChars, *PSTextSettings_ColorAndChars;

struct STextSettings_ColorAndChars {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo> CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>, *PCFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo>;

struct CFastBuffer<struct_CGameCtnMediaTracker::SBlockEditInfo> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockImage CMwClassInfoCGameCtnMediaBlockImage, *PCMwClassInfoCGameCtnMediaBlockImage;

struct CMwClassInfoCGameCtnMediaBlockImage {
    undefined field0_0x0;
};

typedef struct CConstArray<char_const*> CConstArray<char_const*>, *PCConstArray<char_const*>;

struct CConstArray<char_const*> {
    undefined field0_0x0;
};

typedef struct CMwCmdLog CMwCmdLog, *PCMwCmdLog;

struct CMwCmdLog {
    undefined field0_0x0;
};

typedef struct CPlugBitmapPack CPlugBitmapPack, *PCPlugBitmapPack;

struct CPlugBitmapPack {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionPlaySound SMwParamInfos_CMotionPlaySound, *PSMwParamInfos_CMotionPlaySound;

struct SMwParamInfos_CMotionPlaySound {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaClip SMwParamInfos_CGameCtnMediaClip, *PSMwParamInfos_CGameCtnMediaClip;

struct SMwParamInfos_CGameCtnMediaClip {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRace1P SMwParamInfos_CTrackManiaRace1P, *PSMwParamInfos_CTrackManiaRace1P;

struct SMwParamInfos_CTrackManiaRace1P {
    undefined field0_0x0;
};

typedef struct SSailManoeuvre SSailManoeuvre, *PSSailManoeuvre;

struct SSailManoeuvre {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal> {
    undefined field0_0x0;
};

typedef enum _D3DBLENDOP {
} _D3DBLENDOP;

typedef enum EPlane {
} EPlane;

typedef enum EInOut {
} EInOut;

typedef struct CMwNodRef<class_CSceneSoundSource> CMwNodRef<class_CSceneSoundSource>, *PCMwNodRef<class_CSceneSoundSource>;

struct CMwNodRef<class_CSceneSoundSource> {
    undefined field0_0x0;
};

typedef struct SPlugGpuDefine SPlugGpuDefine, *PSPlugGpuDefine;

struct SPlugGpuDefine {
    undefined field0_0x0;
};

typedef struct GmMat43 GmMat43, *PGmMat43;

struct GmMat43 {
    undefined field0_0x0;
};

typedef struct SPlayerInfosMS SPlayerInfosMS, *PSPlayerInfosMS;

struct SPlayerInfosMS {
    undefined field0_0x0;
};

typedef struct CPlugSurface CPlugSurface, *PCPlugSurface;

struct CPlugSurface {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SExpTri> CFastBuffer<struct_SExpTri>, *PCFastBuffer<struct_SExpTri>;

struct CFastBuffer<struct_SExpTri> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetConnection::SEmmissionElem> CFastBuffer<struct_CNetConnection::SEmmissionElem>, *PCFastBuffer<struct_CNetConnection::SEmmissionElem>;

struct CFastBuffer<struct_CNetConnection::SEmmissionElem> {
    undefined field0_0x0;
};

typedef struct CPlugModelFurHairInfo CPlugModelFurHairInfo, *PCPlugModelFurHairInfo;

struct CPlugModelFurHairInfo {
    undefined field0_0x0;
};

typedef enum ESendRequestResult {
} ESendRequestResult;

typedef struct SMwParamInfos_CSceneMobilClouds SMwParamInfos_CSceneMobilClouds, *PSMwParamInfos_CSceneMobilClouds;

struct SMwParamInfos_CSceneMobilClouds {
    undefined field0_0x0;
};

typedef struct CReal16 CReal16, *PCReal16;

struct CReal16 {
    undefined field0_0x0;
};

typedef struct SMwTimedValueInstant<struct_SInputEvent> SMwTimedValueInstant<struct_SInputEvent>, *PSMwTimedValueInstant<struct_SInputEvent>;

struct SMwTimedValueInstant<struct_SInputEvent> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CManoeuvre SMwParamInfos_CManoeuvre, *PSMwParamInfos_CManoeuvre;

struct SMwParamInfos_CManoeuvre {
    undefined field0_0x0;
};

typedef struct CGameRemoteBufferDataInfo CGameRemoteBufferDataInfo, *PCGameRemoteBufferDataInfo;

struct CGameRemoteBufferDataInfo {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamVec4> CMwParamFastBufferCat<class_CMwParamVec4>, *PCMwParamFastBufferCat<class_CMwParamVec4>;

struct CMwParamFastBufferCat<class_CMwParamVec4> {
    undefined field0_0x0;
};

typedef struct CSceneVehicleMaterial CSceneVehicleMaterial, *PCSceneVehicleMaterial;

struct CSceneVehicleMaterial {
    undefined field0_0x0;
};

typedef struct CSystemDialogManager CSystemDialogManager, *PCSystemDialogManager;

struct CSystemDialogManager {
    undefined field0_0x0;
};

typedef struct CGamePlayerScore CGamePlayerScore, *PCGamePlayerScore;

struct CGamePlayerScore {
    undefined field0_0x0;
};

typedef struct CFuncPlug CFuncPlug, *PCFuncPlug;

struct CFuncPlug {
    undefined field0_0x0;
};

typedef struct SPlugFileType SPlugFileType, *PSPlugFileType;

struct SPlugFileType {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugSolid> CMwNodRef<class_CPlugSolid>, *PCMwNodRef<class_CPlugSolid>;

struct CMwNodRef<class_CPlugSolid> {
    undefined field0_0x0;
};

typedef struct _EXPLICIT_ACCESS_W _EXPLICIT_ACCESS_W, *P_EXPLICIT_ACCESS_W;

typedef enum _ACCESS_MODE {
    NOT_USED_ACCESS=0,
    GRANT_ACCESS=1,
    SET_ACCESS=2,
    DENY_ACCESS=3,
    REVOKE_ACCESS=4,
    SET_AUDIT_SUCCESS=5,
    SET_AUDIT_FAILURE=6
} _ACCESS_MODE;

typedef struct _TRUSTEE_W _TRUSTEE_W, *P_TRUSTEE_W;

typedef enum _MULTIPLE_TRUSTEE_OPERATION {
    NO_MULTIPLE_TRUSTEE=0,
    TRUSTEE_IS_IMPERSONATE=1
} _MULTIPLE_TRUSTEE_OPERATION;

typedef enum _TRUSTEE_FORM {
    TRUSTEE_IS_SID=0,
    TRUSTEE_IS_NAME=1,
    TRUSTEE_BAD_FORM=2,
    TRUSTEE_IS_OBJECTS_AND_SID=3,
    TRUSTEE_IS_OBJECTS_AND_NAME=4
} _TRUSTEE_FORM;

typedef enum _TRUSTEE_TYPE {
    TRUSTEE_IS_UNKNOWN=0,
    TRUSTEE_IS_USER=1,
    TRUSTEE_IS_GROUP=2,
    TRUSTEE_IS_DOMAIN=3,
    TRUSTEE_IS_ALIAS=4,
    TRUSTEE_IS_WELL_KNOWN_GROUP=5,
    TRUSTEE_IS_DELETED=6,
    TRUSTEE_IS_INVALID=7,
    TRUSTEE_IS_COMPUTER=8
} _TRUSTEE_TYPE;

struct _TRUSTEE_W {
    struct _TRUSTEE_W *pMultipleTrustee;
    enum _MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    enum _TRUSTEE_FORM TrusteeForm;
    enum _TRUSTEE_TYPE TrusteeType;
    wchar_t *ptstrName;
};

struct _EXPLICIT_ACCESS_W {
    ulong grfAccessPermissions;
    enum _ACCESS_MODE grfAccessMode;
    ulong grfInheritance;
    struct _TRUSTEE_W Trustee;
};

typedef struct CFuncManagerCharacterAdv CFuncManagerCharacterAdv, *PCFuncManagerCharacterAdv;

struct CFuncManagerCharacterAdv {
    undefined field0_0x0;
};

typedef struct SInputEvent SInputEvent, *PSInputEvent;

struct SInputEvent {
    undefined field0_0x0;
};

typedef struct CClassicBufferCrypted CClassicBufferCrypted, *PCClassicBufferCrypted;

struct CClassicBufferCrypted {
    undefined field0_0x0;
};

typedef struct CIteratorShader CIteratorShader, *PCIteratorShader;

struct CIteratorShader {
    undefined field0_0x0;
};

typedef enum EFillMode {
} EFillMode;

typedef struct IDirect3DDevice9 IDirect3DDevice9, *PIDirect3DDevice9;

struct IDirect3DDevice9 {
    undefined field0_0x0;
};

typedef struct CVisionEngine CVisionEngine, *PCVisionEngine;

struct CVisionEngine {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<struct_CPlugTreeMapShaderFill::SFillValue*> CFastCallback1P<struct_CPlugTreeMapShaderFill::SFillValue*>, *PCFastCallback1P<struct_CPlugTreeMapShaderFill::SFillValue*>;

struct CFastCallback1P<struct_CPlugTreeMapShaderFill::SFillValue*> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameChallengeScores> CMwNodRef<class_CGameChallengeScores>, *PCMwNodRef<class_CGameChallengeScores>;

struct CMwNodRef<class_CGameChallengeScores> {
    undefined field0_0x0;
};

typedef struct CFuncKeysTransQuat CFuncKeysTransQuat, *PCFuncKeysTransQuat;

struct CFuncKeysTransQuat {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_> CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CXmlTiDocumentWrapper> CMwNodRef<class_CXmlTiDocumentWrapper>, *PCMwNodRef<class_CXmlTiDocumentWrapper>;

struct CMwNodRef<class_CXmlTiDocumentWrapper> {
    undefined field0_0x0;
};

typedef struct CCrystalTriangle CCrystalTriangle, *PCCrystalTriangle;

struct CCrystalTriangle {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_CHmsPackLightMap::SProgress,4,unsigned_long> CFixedArray<struct_CHmsPackLightMap::SProgress,4,unsigned_long>, *PCFixedArray<struct_CHmsPackLightMap::SProgress,4,unsigned_long>;

struct CFixedArray<struct_CHmsPackLightMap::SProgress,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CMotionManager CMotionManager, *PCMotionManager;

struct CMotionManager {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CXmlAttribute SMwParamInfos_CXmlAttribute, *PSMwParamInfos_CXmlAttribute;

struct SMwParamInfos_CXmlAttribute {
    undefined field0_0x0;
};

typedef struct CXmlElement CXmlElement, *PCXmlElement;

struct CXmlElement {
    undefined field0_0x0;
};

typedef struct CGameCtnParticleParam CGameCtnParticleParam, *PCGameCtnParticleParam;

struct CGameCtnParticleParam {
    undefined field0_0x0;
};

typedef struct GxLightAmbient GxLightAmbient, *PGxLightAmbient;

struct GxLightAmbient {
    undefined field0_0x0;
};

typedef struct CPlugTreeGenSolid CPlugTreeGenSolid, *PCPlugTreeGenSolid;

struct CPlugTreeGenSolid {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SStringParamInt_const*> CFastArray<struct_SStringParamInt_const*>, *PCFastArray<struct_SStringParamInt_const*>;

struct CFastArray<struct_SStringParamInt_const*> {
    undefined field0_0x0;
};

typedef struct CGenAudioSoundSurface<class_COalAudioSound> CGenAudioSoundSurface<class_COalAudioSound>, *PCGenAudioSoundSurface<class_COalAudioSound>;

struct CGenAudioSoundSurface<class_COalAudioSound> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient> CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient>, *PCFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient>;

struct CFastBuffer<struct_CGameNetPlayerInfo::SPagesOnClient> {
    undefined field0_0x0;
};

typedef enum EColorDepth {
} EColorDepth;

typedef struct SMwParamInfo SMwParamInfo, *PSMwParamInfo;

struct SMwParamInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting> CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting>, *PCFastBuffer<struct_CGameRace::SPlayerInfosForTargetting>;

struct CFastBuffer<struct_CGameRace::SPlayerInfosForTargetting> {
    undefined field0_0x0;
};

typedef struct CFastMapTable<struct_CGameAdvertising::SInstanceId> CFastMapTable<struct_CGameAdvertising::SInstanceId>, *PCFastMapTable<struct_CGameAdvertising::SInstanceId>;

struct CFastMapTable<struct_CGameAdvertising::SInstanceId> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CScenePath> CMwNodRef<class_CScenePath>, *PCMwNodRef<class_CScenePath>;

struct CMwNodRef<class_CScenePath> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnGhostInfo SMwParamInfos_CGameCtnGhostInfo, *PSMwParamInfos_CGameCtnGhostInfo;

struct SMwParamInfos_CGameCtnGhostInfo {
    undefined field0_0x0;
};

typedef struct CFuncEnum CFuncEnum, *PCFuncEnum;

struct CFuncEnum {
    undefined field0_0x0;
};

typedef struct CPlugFileModelObj CPlugFileModelObj, *PCPlugFileModelObj;

struct CPlugFileModelObj {
    undefined field0_0x0;
};

typedef struct CCallbackSceneVehicleBallAfterContacts CCallbackSceneVehicleBallAfterContacts, *PCCallbackSceneVehicleBallAfterContacts;

struct CCallbackSceneVehicleBallAfterContacts {
    undefined field0_0x0;
};

typedef struct SSubPage SSubPage, *PSSubPage;

struct SSubPage {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlUiRange SMwParamInfos_CControlUiRange, *PSMwParamInfos_CControlUiRange;

struct SMwParamInfos_CControlUiRange {
    undefined field0_0x0;
};

typedef struct CGameCtnNetServerInfo CGameCtnNetServerInfo, *PCGameCtnNetServerInfo;

struct CGameCtnNetServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlock SMwParamInfos_CGameCtnBlock, *PSMwParamInfos_CGameCtnBlock;

struct SMwParamInfos_CGameCtnBlock {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaClipGroup SMwParamInfos_CGameCtnMediaClipGroup, *PSMwParamInfos_CGameCtnMediaClipGroup;

struct SMwParamInfos_CGameCtnMediaClipGroup {
    undefined field0_0x0;
};

typedef struct SPlugFontFormat SPlugFontFormat, *PSPlugFontFormat;

struct SPlugFontFormat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRemoteBuffer SMwParamInfos_CGameRemoteBuffer, *PSMwParamInfos_CGameRemoteBuffer;

struct SMwParamInfos_CGameRemoteBuffer {
    undefined field0_0x0;
};

typedef struct CGameControlCameraMaster CGameControlCameraMaster, *PCGameControlCameraMaster;

struct CGameControlCameraMaster {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceAnalyzer SMwParamInfos_CTrackManiaRaceAnalyzer, *PSMwParamInfos_CTrackManiaRaceAnalyzer;

struct SMwParamInfos_CTrackManiaRaceAnalyzer {
    undefined field0_0x0;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    uint VirtualAddress;
    uint SizeOfRawData;
    uint PointerToRawData;
    uint PointerToRelocations;
    uint PointerToLinenumbers;
    uint16.conflict NumberOfRelocations;
    uint16.conflict NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct ID3DXBuffer ID3DXBuffer, *PID3DXBuffer;

struct ID3DXBuffer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SManiaCodeGameAction*> CFastBuffer<struct_SManiaCodeGameAction*>, *PCFastBuffer<struct_SManiaCodeGameAction*>;

struct CFastBuffer<struct_SManiaCodeGameAction*> {
    undefined field0_0x0;
};

typedef struct CPlugPhysicalObject CPlugPhysicalObject, *PCPlugPhysicalObject;

struct CPlugPhysicalObject {
    undefined field0_0x0;
};

typedef struct CGameSafeFrameConfig CGameSafeFrameConfig, *PCGameSafeFrameConfig;

struct CGameSafeFrameConfig {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsPackLightMap::SBlock> CFastBuffer<struct_CHmsPackLightMap::SBlock>, *PCFastBuffer<struct_CHmsPackLightMap::SBlock>;

struct CFastBuffer<struct_CHmsPackLightMap::SBlock> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLightBall SMwParamInfos_GxLightBall, *PSMwParamInfos_GxLightBall;

struct SMwParamInfos_GxLightBall {
    undefined field0_0x0;
};

typedef struct CGameCtnEdControlCamCustom CGameCtnEdControlCamCustom, *PCGameCtnEdControlCamCustom;

struct CGameCtnEdControlCamCustom {
    undefined field0_0x0;
};

typedef struct CGameLadderRankingSkill CGameLadderRankingSkill, *PCGameLadderRankingSkill;

struct CGameLadderRankingSkill {
    undefined field0_0x0;
};

typedef struct CMwCmdBlockFunction CMwCmdBlockFunction, *PCMwCmdBlockFunction;

struct CMwCmdBlockFunction {
    undefined field0_0x0;
};

typedef enum ECollisionGroup {
} ECollisionGroup;

typedef struct CFastArray<class_CCrystalEdge*> CFastArray<class_CCrystalEdge*>, *PCFastArray<class_CCrystalEdge*>;

struct CFastArray<class_CCrystalEdge*> {
    undefined field0_0x0;
};

typedef struct IDirect3DIndexBuffer9 IDirect3DIndexBuffer9, *PIDirect3DIndexBuffer9;

struct IDirect3DIndexBuffer9 {
    undefined field0_0x0;
};

typedef struct CPlugModelFur CPlugModelFur, *PCPlugModelFur;

struct CPlugModelFur {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel> CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>, *PCFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel>;

struct CFastBuffer<struct_CSceneVehicleStruct::SSimulationWheel> {
    undefined field0_0x0;
};

typedef struct CClassicDependant CClassicDependant, *PCClassicDependant;

struct CClassicDependant {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnNetServerInfo::SChallengeList_Info> CFastBuffer<struct_CGameCtnNetServerInfo::SChallengeList_Info>, *PCFastBuffer<struct_CGameCtnNetServerInfo::SChallengeList_Info>;

struct CFastBuffer<struct_CGameCtnNetServerInfo::SChallengeList_Info> {
    undefined field0_0x0;
};

typedef struct CSceneExtraFlocking CSceneExtraFlocking, *PCSceneExtraFlocking;

struct CSceneExtraFlocking {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceInterface CTrackManiaRaceInterface, *PCTrackManiaRaceInterface;

struct CTrackManiaRaceInterface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpNeg SMwParamInfos_CMwCmdExpNeg, *PSMwParamInfos_CMwCmdExpNeg;

struct SMwParamInfos_CMwCmdExpNeg {
    undefined field0_0x0;
};

typedef struct CGameCalendar CGameCalendar, *PCGameCalendar;

struct CGameCalendar {
    undefined field0_0x0;
};

typedef struct SParamEffectMaster SParamEffectMaster, *PSParamEffectMaster;

struct SParamEffectMaster {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSystemConfig> CMwNodRef<class_CSystemConfig>, *PCMwNodRef<class_CSystemConfig>;

struct CMwNodRef<class_CSystemConfig> {
    undefined field0_0x0;
};

typedef struct logic_error logic_error, *Plogic_error;

struct logic_error {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastBuffer<class_GmVec4>,2,unsigned_long> CFixedArray<class_CFastBuffer<class_GmVec4>,2,unsigned_long>, *PCFixedArray<class_CFastBuffer<class_GmVec4>,2,unsigned_long>;

struct CFixedArray<class_CFastBuffer<class_GmVec4>,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugBitmap CPlugBitmap, *PCPlugBitmap;

struct CPlugBitmap {
    undefined field0_0x0;
};

typedef struct CGameControlCameraEffectGroup CGameControlCameraEffectGroup, *PCGameControlCameraEffectGroup;

struct CGameControlCameraEffectGroup {
    undefined field0_0x0;
};

typedef struct CIPCRemoteControl_SAuthParams CIPCRemoteControl_SAuthParams, *PCIPCRemoteControl_SAuthParams;

struct CIPCRemoteControl_SAuthParams {
    undefined field0_0x0;
};

typedef enum EPlugVideoTimer {
} EPlugVideoTimer;

typedef struct CPfmHeap CPfmHeap, *PCPfmHeap;

struct CPfmHeap {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>, *PCFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat>;

struct CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamQuat> CMwParamFastArray<class_CMwParamQuat>, *PCMwParamFastArray<class_CMwParamQuat>;

struct CMwParamFastArray<class_CMwParamQuat> {
    undefined field0_0x0;
};

typedef struct CSceneVehicleSpeedBoat CSceneVehicleSpeedBoat, *PCSceneVehicleSpeedBoat;

struct CSceneVehicleSpeedBoat {
    undefined field0_0x0;
};

typedef struct CLoadGeomVertexGen<2113> CLoadGeomVertexGen<2113>, *PCLoadGeomVertexGen<2113>;

struct CLoadGeomVertexGen<2113> {
    undefined field0_0x0;
};

typedef struct CSceneMobilTraffic CSceneMobilTraffic, *PCSceneMobilTraffic;

struct CSceneMobilTraffic {
    undefined field0_0x0;
};

typedef struct SDx9StreamDesc SDx9StreamDesc, *PSDx9StreamDesc;

struct SDx9StreamDesc {
    undefined field0_0x0;
};

typedef struct CSceneFxColors CSceneFxColors, *PCSceneFxColors;

struct CSceneFxColors {
    undefined field0_0x0;
};

typedef struct CPlugFileGpuBuilder CPlugFileGpuBuilder, *PCPlugFileGpuBuilder;

struct CPlugFileGpuBuilder {
    undefined field0_0x0;
};

typedef struct GmBinTree2 GmBinTree2, *PGmBinTree2;

struct GmBinTree2 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileGen SMwParamInfos_CPlugFileGen, *PSMwParamInfos_CPlugFileGen;

struct SMwParamInfos_CPlugFileGen {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraPath SMwParamInfos_CGameCtnMediaBlockCameraPath, *PSMwParamInfos_CGameCtnMediaBlockCameraPath;

struct SMwParamInfos_CGameCtnMediaBlockCameraPath {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost> CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost>, *PCFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost>;

struct CFastBuffer<struct_CTrackManiaRace::SPlayerOrGhost> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SCustomBitmapOld> CFastArray<struct_SCustomBitmapOld>, *PCFastArray<struct_SCustomBitmapOld>;

struct CFastArray<struct_SCustomBitmapOld> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugModelTree> CMwNodRef<class_CPlugModelTree>, *PCMwNodRef<class_CPlugModelTree>;

struct CMwNodRef<class_CPlugModelTree> {
    undefined field0_0x0;
};

typedef struct SHeaderThumbnail SHeaderThumbnail, *PSHeaderThumbnail;

struct SHeaderThumbnail {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugVisual*> CFastCallback1P<class_CPlugVisual*>, *PCFastCallback1P<class_CPlugVisual*>;

struct CFastCallback1P<class_CPlugVisual*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CXmlComment SMwParamInfos_CXmlComment, *PSMwParamInfos_CXmlComment;

struct SMwParamInfos_CXmlComment {
    undefined field0_0x0;
};

typedef struct SLightSpotLoc SLightSpotLoc, *PSLightSpotLoc;

struct SLightSpotLoc {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamColor> CMwParamFastBufferCat<class_CMwParamColor>, *PCMwParamFastBufferCat<class_CMwParamColor>;

struct CMwParamFastBufferCat<class_CMwParamColor> {
    undefined field0_0x0;
};

typedef struct SManialinkFormat SManialinkFormat, *PSManialinkFormat;

struct SManialinkFormat {
    undefined field0_0x0;
};

typedef struct SHmsVPackerObjectBase SHmsVPackerObjectBase, *PSHmsVPackerObjectBase;

struct SHmsVPackerObjectBase {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameAdvertising SMwParamInfos_CGameAdvertising, *PSMwParamInfos_CGameAdvertising;

struct SMwParamInfos_CGameAdvertising {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGamePlayerScore*> CFastBuffer<class_CGamePlayerScore*>, *PCFastBuffer<class_CGamePlayerScore*>;

struct CFastBuffer<class_CGamePlayerScore*> {
    undefined field0_0x0;
};

typedef struct CMotionTrackMobilMove CMotionTrackMobilMove, *PCMotionTrackMobilMove;

struct CMotionTrackMobilMove {
    undefined field0_0x0;
};

typedef enum EReadFileRes {
} EReadFileRes;

typedef struct CFastBuffer<struct_CPlugModelMesh::STangent> CFastBuffer<struct_CPlugModelMesh::STangent>, *PCFastBuffer<struct_CPlugModelMesh::STangent>;

struct CFastBuffer<struct_CPlugModelMesh::STangent> {
    undefined field0_0x0;
};

typedef struct SBlendableVals SBlendableVals, *PSBlendableVals;

struct SBlendableVals {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCSystemNodWrapper CMwClassInfoCSystemNodWrapper, *PCMwClassInfoCSystemNodWrapper;

struct CMwClassInfoCSystemNodWrapper {
    undefined field0_0x0;
};

typedef enum EShouldBePlaying {
} EShouldBePlaying;

typedef struct CFastBuffer<struct_CHmsZoneVPacker::SStackLocation> CFastBuffer<struct_CHmsZoneVPacker::SStackLocation>, *PCFastBuffer<struct_CHmsZoneVPacker::SStackLocation>;

struct CFastBuffer<struct_CHmsZoneVPacker::SStackLocation> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotions SMwParamInfos_CMotions, *PSMwParamInfos_CMotions;

struct SMwParamInfos_CMotions {
    undefined field0_0x0;
};

typedef enum EVersion {
} EVersion;

typedef enum ECubeFace {
} ECubeFace;

typedef struct CGameMobil CGameMobil, *PCGameMobil;

struct CGameMobil {
    undefined field0_0x0;
};

typedef struct SElement SElement, *PSElement;

struct SElement {
    undefined field0_0x0;
};

typedef struct CDx9TextureKeeper CDx9TextureKeeper, *PCDx9TextureKeeper;

struct CDx9TextureKeeper {
    undefined field0_0x0;
};

typedef struct SEmitParams SEmitParams, *PSEmitParams;

struct SEmitParams {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_MEMORYSTATUSEX - /winbase.h/_MEMORYSTATUSEX */

typedef struct CGameCtnChallengeParameters CGameCtnChallengeParameters, *PCGameCtnChallengeParameters;

struct CGameCtnChallengeParameters {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,8,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,8,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugShaderApply>,8,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugShaderApply>,8,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CSceneToyMotorbike CSceneToyMotorbike, *PCSceneToyMotorbike;

struct CSceneToyMotorbike {
    undefined field0_0x0;
};

typedef struct CPlugFontBitmap CPlugFontBitmap, *PCPlugFontBitmap;

struct CPlugFontBitmap {
    undefined field0_0x0;
};

typedef enum _D3DDEVTYPE {
} _D3DDEVTYPE;

typedef struct CFastBuffer<struct_SVectMap> CFastBuffer<struct_SVectMap>, *PCFastBuffer<struct_SVectMap>;

struct CFastBuffer<struct_SVectMap> {
    undefined field0_0x0;
};

typedef struct CPlugVisualIndexed CPlugVisualIndexed, *PCPlugVisualIndexed;

struct CPlugVisualIndexed {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SSphere> CFastBuffer<struct_CPlugModelMesh::SSphere>, *PCFastBuffer<struct_CPlugModelMesh::SSphere>;

struct CFastBuffer<struct_CPlugModelMesh::SSphere> {
    undefined field0_0x0;
};

typedef struct SDirDesc SDirDesc, *PSDirDesc;

struct SDirDesc {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<unsigned_long,struct_SFastCat> CFastBufferCat<unsigned_long,struct_SFastCat>, *PCFastBufferCat<unsigned_long,struct_SFastCat>;

struct CFastBufferCat<unsigned_long,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCollectorVehicle SMwParamInfos_CGameCtnCollectorVehicle, *PSMwParamInfos_CGameCtnCollectorVehicle;

struct SMwParamInfos_CGameCtnCollectorVehicle {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderPortal SMwParamInfos_CPlugBitmapRenderPortal, *PSMwParamInfos_CPlugBitmapRenderPortal;

struct SMwParamInfos_CPlugBitmapRenderPortal {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTransition CGameCtnMediaBlockTransition, *PCGameCtnMediaBlockTransition;

struct CGameCtnMediaBlockTransition {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMessageHandler SMwParamInfos_CSceneMessageHandler, *PSMwParamInfos_CSceneMessageHandler;

struct SMwParamInfos_CSceneMessageHandler {
    undefined field0_0x0;
};

typedef struct CVisionVisualKeeper CVisionVisualKeeper, *PCVisionVisualKeeper;

struct CVisionVisualKeeper {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMasterServer::SBuddyAsker> CFastBuffer<struct_CGameCtnMasterServer::SBuddyAsker>, *PCFastBuffer<struct_CGameCtnMasterServer::SBuddyAsker>;

struct CFastBuffer<struct_CGameCtnMasterServer::SBuddyAsker> {
    undefined field0_0x0;
};

typedef struct CAudioSoundBink CAudioSoundBink, *PCAudioSoundBink;

struct CAudioSoundBink {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid> CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>, *PCFastBuffer<struct_CPlugBitmapRenderSolid::SSolid>;

struct CFastBuffer<struct_CPlugBitmapRenderSolid::SSolid> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleCarTuning SMwParamInfos_CSceneVehicleCarTuning, *PSMwParamInfos_CSceneVehicleCarTuning;

struct SMwParamInfos_CSceneVehicleCarTuning {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncTreeSubVisualSequence SMwParamInfos_CFuncTreeSubVisualSequence, *PSMwParamInfos_CFuncTreeSubVisualSequence;

struct SMwParamInfos_CFuncTreeSubVisualSequence {
    undefined field0_0x0;
};

typedef struct CGameNetTeamInfo CGameNetTeamInfo, *PCGameNetTeamInfo;

struct CGameNetTeamInfo {
    undefined field0_0x0;
};

typedef struct GxColor GxColor, *PGxColor;

struct GxColor {
    undefined field0_0x0;
};

typedef struct CMwParamBool CMwParamBool, *PCMwParamBool;

struct CMwParamBool {
    undefined field0_0x0;
};

typedef struct SRenderState SRenderState, *PSRenderState;

struct SRenderState {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumParam CMwCmdExpNumParam, *PCMwCmdExpNumParam;

struct CMwCmdExpNumParam {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CDx9StateBlock::SPackedDesc> CFastArray<struct_CDx9StateBlock::SPackedDesc>, *PCFastArray<struct_CDx9StateBlock::SPackedDesc>;

struct CFastArray<struct_CDx9StateBlock::SPackedDesc> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SBlendShape2> CFastBuffer<struct_CPlugModelMesh::SBlendShape2>, *PCFastBuffer<struct_CPlugModelMesh::SBlendShape2>;

struct CFastBuffer<struct_CPlugModelMesh::SBlendShape2> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion - /IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion */

typedef struct SGamePlayCoefs SGamePlayCoefs, *PSGamePlayCoefs;

struct SGamePlayCoefs {
    undefined field0_0x0;
};

typedef struct CVisionTexConverter CVisionTexConverter, *PCVisionTexConverter;

struct CVisionTexConverter {
    undefined field0_0x0;
};

typedef struct GmFrustumIso4 GmFrustumIso4, *PGmFrustumIso4;

struct GmFrustumIso4 {
    undefined field0_0x0;
};

typedef enum EPostType {
} EPostType;

typedef struct CMwParamNatural CMwParamNatural, *PCMwParamNatural;

struct CMwParamNatural {
    undefined field0_0x0;
};

typedef struct SVisualArm SVisualArm, *PSVisualArm;

struct SVisualArm {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockTriangles SMwParamInfos_CGameCtnMediaBlockTriangles, *PSMwParamInfos_CGameCtnMediaBlockTriangles;

struct SMwParamInfos_CGameCtnMediaBlockTriangles {
    undefined field0_0x0;
};

typedef struct SCallVoteContext SCallVoteContext, *PSCallVoteContext;

struct SCallVoteContext {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatParam SMwParamInfos_CBoatParam, *PSMwParamInfos_CBoatParam;

struct SMwParamInfos_CBoatParam {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CControlBase*> CFastArray<class_CControlBase*>, *PCFastArray<class_CControlBase*>;

struct CFastArray<class_CControlBase*> {
    undefined field0_0x0;
};

typedef enum ESort {
} ESort;

typedef struct SMwParamInfos_CPlugModel SMwParamInfos_CPlugModel, *PSMwParamInfos_CPlugModel;

struct SMwParamInfos_CPlugModel {
    undefined field0_0x0;
};

typedef struct SVisualEmitter SVisualEmitter, *PSVisualEmitter;

struct SVisualEmitter {
    undefined field0_0x0;
};

typedef enum EFilterMode {
} EFilterMode;

typedef struct SQuickInfo SQuickInfo, *PSQuickInfo;

struct SQuickInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameTournament>_> CFastBuffer<class_CMwNodRef<class_CGameTournament>_>, *PCFastBuffer<class_CMwNodRef<class_CGameTournament>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameTournament>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerParticles SMwParamInfos_CMotionManagerParticles, *PSMwParamInfos_CMotionManagerParticles;

struct SMwParamInfos_CMotionManagerParticles {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SOldBlendShape> CFastBuffer<struct_CPlugModelMesh::SOldBlendShape>, *PCFastBuffer<struct_CPlugModelMesh::SOldBlendShape>;

struct CFastBuffer<struct_CPlugModelMesh::SOldBlendShape> {
    undefined field0_0x0;
};

typedef struct CFastMap<class_CMwId,unsigned_long> CFastMap<class_CMwId,unsigned_long>, *PCFastMap<class_CMwId,unsigned_long>;

struct CFastMap<class_CMwId,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CDx9PixelShader CDx9PixelShader, *PCDx9PixelShader;

struct CDx9PixelShader {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamString> CMwParamFastArray<class_CMwParamString>, *PCMwParamFastArray<class_CMwParamString>;

struct CMwParamFastArray<class_CMwParamString> {
    undefined field0_0x0;
};

typedef struct CPlugVisualGrid CPlugVisualGrid, *PCPlugVisualGrid;

struct CPlugVisualGrid {
    undefined field0_0x0;
};

typedef struct CNetSource CNetSource, *PCNetSource;

struct CNetSource {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemPackDesc*> CFastBuffer<class_CSystemPackDesc*>, *PCFastBuffer<class_CSystemPackDesc*>;

struct CFastBuffer<class_CSystemPackDesc*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockFxColors SMwParamInfos_CGameCtnMediaBlockFxColors, *PSMwParamInfos_CGameCtnMediaBlockFxColors;

struct SMwParamInfos_CGameCtnMediaBlockFxColors {
    undefined field0_0x0;
};

typedef struct SStyle SStyle, *PSStyle;

struct SStyle {
    undefined field0_0x0;
};

typedef struct SSysGraphicAdapter SSysGraphicAdapter, *PSSysGraphicAdapter;

struct SSysGraphicAdapter {
    undefined field0_0x0;
};

typedef struct SIdRemap SIdRemap, *PSIdRemap;

struct SIdRemap {
    undefined field0_0x0;
};

typedef struct SPlacedBlockInGrid SPlacedBlockInGrid, *PSPlacedBlockInGrid;

struct SPlacedBlockInGrid {
    undefined field0_0x0;
};

typedef struct CMwCmdCall CMwCmdCall, *PCMwCmdCall;

struct CMwCmdCall {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNumBin CMwCmdExpNumBin, *PCMwCmdExpNumBin;

struct CMwCmdExpNumBin {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SRemoteControlNodMethod*> CFastBuffer<struct_SRemoteControlNodMethod*>, *PCFastBuffer<struct_SRemoteControlNodMethod*>;

struct CFastBuffer<struct_SRemoteControlNodMethod*> {
    undefined field0_0x0;
};

typedef enum ELoadGfxPerfResult {
} ELoadGfxPerfResult;

typedef struct CFastArray<struct_CPlugFileGPU::SSemantic> CFastArray<struct_CPlugFileGPU::SSemantic>, *PCFastArray<struct_CPlugFileGPU::SSemantic>;

struct CFastArray<struct_CPlugFileGPU::SSemantic> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayground SMwParamInfos_CGamePlayground, *PSMwParamInfos_CGamePlayground;

struct SMwParamInfos_CGamePlayground {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaMatchSettingsControlGrid SMwParamInfos_CTrackManiaMatchSettingsControlGrid, *PSMwParamInfos_CTrackManiaMatchSettingsControlGrid;

struct SMwParamInfos_CTrackManiaMatchSettingsControlGrid {
    undefined field0_0x0;
};

typedef struct SVehicleCarState SVehicleCarState, *PSVehicleCarState;

struct SVehicleCarState {
    undefined field0_0x0;
};

typedef struct CSceneMobilClouds CSceneMobilClouds, *PCSceneMobilClouds;

struct CSceneMobilClouds {
    undefined field0_0x0;
};

typedef enum EStdShader2 {
} EStdShader2;

typedef enum ESceneLight {
} ESceneLight;

typedef enum ESceneMobilQuality {
} ESceneMobilQuality;

typedef struct SMwParamInfos_CControlRadar SMwParamInfos_CControlRadar, *PSMwParamInfos_CControlRadar;

struct SMwParamInfos_CControlRadar {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SFastCat> CFastBuffer<struct_SFastCat>, *PCFastBuffer<struct_SFastCat>;

struct CFastBuffer<struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CNetFileTransfer CNetFileTransfer, *PCNetFileTransfer;

struct CNetFileTransfer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetDataDownload SMwParamInfos_CGameNetDataDownload, *PSMwParamInfos_CGameNetDataDownload;

struct SMwParamInfos_CGameNetDataDownload {
    undefined field0_0x0;
};

typedef enum EMwIconList {
} EMwIconList;

typedef struct SLadderResult SLadderResult, *PSLadderResult;

struct SLadderResult {
    undefined field0_0x0;
};

typedef struct SAgainstGroup SAgainstGroup, *PSAgainstGroup;

struct SAgainstGroup {
    undefined field0_0x0;
};

typedef struct SMoodRemaping SMoodRemaping, *PSMoodRemaping;

struct SMoodRemaping {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaTrack CGameCtnMediaTrack, *PCGameCtnMediaTrack;

struct CGameCtnMediaTrack {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetwork::SPlayerInfosToSend> CFastBuffer<struct_CGameNetwork::SPlayerInfosToSend>, *PCFastBuffer<struct_CGameNetwork::SPlayerInfosToSend>;

struct CFastBuffer<struct_CGameNetwork::SPlayerInfosToSend> {
    undefined field0_0x0;
};

typedef struct CGameSystemOverlay CGameSystemOverlay, *PCGameSystemOverlay;

struct CGameSystemOverlay {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CPlugSurfaceMaterialData,31,unsigned_long> CFixedArray<class_CPlugSurfaceMaterialData,31,unsigned_long>, *PCFixedArray<class_CPlugSurfaceMaterialData,31,unsigned_long>;

struct CFixedArray<class_CPlugSurfaceMaterialData,31,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMipMapLevel3d SMipMapLevel3d, *PSMipMapLevel3d;

struct SMipMapLevel3d {
    undefined field0_0x0;
};

typedef struct CGameAdvertising CGameAdvertising, *PCGameAdvertising;

struct CGameAdvertising {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleTuning SMwParamInfos_CSceneVehicleTuning, *PSMwParamInfos_CSceneVehicleTuning;

struct SMwParamInfos_CSceneVehicleTuning {
    undefined field0_0x0;
};

typedef enum EGxBlend {
} EGxBlend;

typedef struct CPlugBitmapRenderCamera CPlugBitmapRenderCamera, *PCPlugBitmapRenderCamera;

struct CPlugBitmapRenderCamera {
    undefined field0_0x0;
};

typedef struct CControlFrame CControlFrame, *PCControlFrame;

struct CControlFrame {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCPlugBitmapHighLevel CMwClassInfoCPlugBitmapHighLevel, *PCMwClassInfoCPlugBitmapHighLevel;

struct CMwClassInfoCPlugBitmapHighLevel {
    undefined field0_0x0;
};

typedef struct SFuncProxy SFuncProxy, *PSFuncProxy;

struct SFuncProxy {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEffectCombined SMwParamInfos_CControlEffectCombined, *PSMwParamInfos_CControlEffectCombined;

struct SMwParamInfos_CControlEffectCombined {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugBlendShapes::SRefVertex> CFastArray<struct_CPlugBlendShapes::SRefVertex>, *PCFastArray<struct_CPlugBlendShapes::SRefVertex>;

struct CFastArray<struct_CPlugBlendShapes::SRefVertex> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SVertexDataLayer> CFastBuffer<struct_SVertexDataLayer>, *PCFastBuffer<struct_SVertexDataLayer>;

struct CFastBuffer<struct_SVertexDataLayer> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamIso3 SMwParamInfos_CMwParamIso3, *PSMwParamInfos_CMwParamIso3;

struct SMwParamInfos_CMwParamIso3 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamIso4 SMwParamInfos_CMwParamIso4, *PSMwParamInfos_CMwParamIso4;

struct SMwParamInfos_CMwParamIso4 {
    undefined field0_0x0;
};

typedef enum EEffectMode {
} EEffectMode;

typedef struct STri_PosTexTgt STri_PosTexTgt, *PSTri_PosTexTgt;

struct STri_PosTexTgt {
    undefined field0_0x0;
};

typedef enum EFocus {
} EFocus;

typedef struct SMwParamInfos_CSceneTrafficPath SMwParamInfos_CSceneTrafficPath, *PSMwParamInfos_CSceneTrafficPath;

struct SMwParamInfos_CSceneTrafficPath {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugSurface> CFastBufferRef<class_CPlugSurface>, *PCFastBufferRef<class_CPlugSurface>;

struct CFastBufferRef<class_CPlugSurface> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioPort SMwParamInfos_CAudioPort, *PSMwParamInfos_CAudioPort;

struct SMwParamInfos_CAudioPort {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,22,unsigned_long> CFixedArray<unsigned_long,22,unsigned_long>, *PCFixedArray<unsigned_long,22,unsigned_long>;

struct CFixedArray<unsigned_long,22,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SCompress SCompress, *PSCompress;

struct SCompress {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCSceneToyBoat CMwClassInfoCSceneToyBoat, *PCMwClassInfoCSceneToyBoat;

struct CMwClassInfoCSceneToyBoat {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CMwNod> CFastBufferRef<class_CMwNod>, *PCFastBufferRef<class_CMwNod>;

struct CFastBufferRef<class_CMwNod> {
    undefined field0_0x0;
};

typedef struct SChallengeScoresAndPlayerRecordsRequest SChallengeScoresAndPlayerRecordsRequest, *PSChallengeScoresAndPlayerRecordsRequest;

struct SChallengeScoresAndPlayerRecordsRequest {
    undefined field0_0x0;
};

typedef struct CSceneToyCharacterTuning CSceneToyCharacterTuning, *PCSceneToyCharacterTuning;

struct CSceneToyCharacterTuning {
    undefined field0_0x0;
};

typedef struct CMwStatsValue CMwStatsValue, *PCMwStatsValue;

struct CMwStatsValue {
    undefined field0_0x0;
};

typedef struct SMainContext SMainContext, *PSMainContext;

struct SMainContext {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugShader*> CFastBuffer<class_CPlugShader*>, *PCFastBuffer<class_CPlugShader*>;

struct CFastBuffer<class_CPlugShader*> {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderShadow CPlugBitmapRenderShadow, *PCPlugBitmapRenderShadow;

struct CPlugBitmapRenderShadow {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNod SMwParamInfos_CGameNod, *PSMwParamInfos_CGameNod;

struct SMwParamInfos_CGameNod {
    undefined field0_0x0;
};

typedef struct CSceneToySeaHouleTable CSceneToySeaHouleTable, *PCSceneToySeaHouleTable;

struct CSceneToySeaHouleTable {
    undefined field0_0x0;
};

typedef struct CGameCtnNetwork CGameCtnNetwork, *PCGameCtnNetwork;

struct CGameCtnNetwork {
    undefined field0_0x0;
};

typedef struct CNetIPCConnectedClient CNetIPCConnectedClient, *PCNetIPCConnectedClient;

struct CNetIPCConnectedClient {
    undefined field0_0x0;
};

typedef struct SEngine SEngine, *PSEngine;

struct SEngine {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_LIST_ENTRY - /winnt.h/_LIST_ENTRY */

typedef enum _D3DSAMPLERSTATETYPE {
} _D3DSAMPLERSTATETYPE;

typedef struct SDx9Static SDx9Static, *PSDx9Static;

struct SDx9Static {
    undefined field0_0x0;
};

typedef struct SFastToken SFastToken, *PSFastToken;

struct SFastToken {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpNot SMwParamInfos_CMwCmdExpNot, *PSMwParamInfos_CMwCmdExpNot;

struct SMwParamInfos_CMwCmdExpNot {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringParam CMwCmdExpStringParam, *PCMwCmdExpStringParam;

struct CMwCmdExpStringParam {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SRpcChallengeQuickInfo> CFastBuffer<struct_CTrackManiaNetwork::SRpcChallengeQuickInfo>, *PCFastBuffer<struct_CTrackManiaNetwork::SRpcChallengeQuickInfo>;

struct CFastBuffer<struct_CTrackManiaNetwork::SRpcChallengeQuickInfo> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_cpinfo - /winnls.h/_cpinfo */

typedef struct CGameCtnPainterSetting CGameCtnPainterSetting, *PCGameCtnPainterSetting;

struct CGameCtnPainterSetting {
    undefined field0_0x0;
};

typedef struct TiXmlString TiXmlString, *PTiXmlString;

struct TiXmlString {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParamClass CMwCmdAffectParamClass, *PCMwCmdAffectParamClass;

struct CMwCmdAffectParamClass {
    undefined field0_0x0;
};

typedef struct CGameManialinkEntry CGameManialinkEntry, *PCGameManialinkEntry;

struct CGameManialinkEntry {
    undefined field0_0x0;
};

typedef struct CSceneToyDisplayGraph CSceneToyDisplayGraph, *PCSceneToyDisplayGraph;

struct CSceneToyDisplayGraph {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo> CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>, *PCFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo>;

struct CFastBuffer<struct_GmOctree<struct_SMeshOctreeCell>::SEntInfo> {
    undefined field0_0x0;
};

typedef struct SParamEffect SParamEffect, *PSParamEffect;

struct SParamEffect {
    undefined field0_0x0;
};

typedef struct CPlugFileZip CPlugFileZip, *PCPlugFileZip;

struct CPlugFileZip {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CClassicBufferMemory*> CFastBuffer<class_CClassicBufferMemory*>, *PCFastBuffer<class_CClassicBufferMemory*>;

struct CFastBuffer<class_CClassicBufferMemory*> {
    undefined field0_0x0;
};

typedef struct SMipMapLevel SMipMapLevel, *PSMipMapLevel;

struct SMipMapLevel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicle SMwParamInfos_CSceneVehicle, *PSMwParamInfos_CSceneVehicle;

struct SMwParamInfos_CSceneVehicle {
    undefined field0_0x0;
};

typedef struct CFuncTreeBend CFuncTreeBend, *PCFuncTreeBend;

struct CFuncTreeBend {
    undefined field0_0x0;
};

typedef struct SLensFlareAdd SLensFlareAdd, *PSLensFlareAdd;

struct SLensFlareAdd {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_LARGE_INTEGER - /winnt.h/_LARGE_INTEGER */

typedef struct SMwParamInfos_CMwCmdBlockMain SMwParamInfos_CMwCmdBlockMain, *PSMwParamInfos_CMwCmdBlockMain;

struct SMwParamInfos_CMwCmdBlockMain {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetIPSource SMwParamInfos_CNetIPSource, *PSMwParamInfos_CNetIPSource;

struct SMwParamInfos_CNetIPSource {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmIso3,struct_SFastCat> CFastBufferCat<class_GmIso3,struct_SFastCat>, *PCFastBufferCat<class_GmIso3,struct_SFastCat>;

struct CFastBufferCat<class_GmIso3,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CSceneVehicleTuning CSceneVehicleTuning, *PCSceneVehicleTuning;

struct CSceneVehicleTuning {
    undefined field0_0x0;
};

typedef struct CSceneVehicleGlider CSceneVehicleGlider, *PCSceneVehicleGlider;

struct CSceneVehicleGlider {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameSafeFrameConfig> CMwNodRef<class_CGameSafeFrameConfig>, *PCMwNodRef<class_CGameSafeFrameConfig>;

struct CMwNodRef<class_CGameSafeFrameConfig> {
    undefined field0_0x0;
};

typedef struct SPylonMobil SPylonMobil, *PSPylonMobil;

struct SPylonMobil {
    undefined field0_0x0;
};

typedef struct CMwCmdFunctionInterface CMwCmdFunctionInterface, *PCMwCmdFunctionInterface;

struct CMwCmdFunctionInterface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpNum SMwParamInfos_CMwCmdExpNum, *PSMwParamInfos_CMwCmdExpNum;

struct SMwParamInfos_CMwCmdExpNum {
    undefined field0_0x0;
};

typedef enum EMenusResult {
} EMenusResult;

typedef struct SMwParamInfos_CControlEffectMotion SMwParamInfos_CControlEffectMotion, *PSMwParamInfos_CControlEffectMotion;

struct SMwParamInfos_CControlEffectMotion {
    undefined field0_0x0;
};

typedef struct SNormalDec3N SNormalDec3N, *PSNormalDec3N;

struct SNormalDec3N {
    undefined field0_0x0;
};

typedef struct SSurfacePoint SSurfacePoint, *PSSurfacePoint;

struct SSurfacePoint {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSceneMoods_Mood> CFastBuffer<struct_SSceneMoods_Mood>, *PCFastBuffer<struct_SSceneMoods_Mood>;

struct CFastBuffer<struct_SSceneMoods_Mood> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpBoolBin SMwParamInfos_CMwCmdExpBoolBin, *PSMwParamInfos_CMwCmdExpBoolBin;

struct SMwParamInfos_CMwCmdExpBoolBin {
    undefined field0_0x0;
};

typedef struct CGameCtnZoneFrontier CGameCtnZoneFrontier, *PCGameCtnZoneFrontier;

struct CGameCtnZoneFrontier {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorFree CTrackManiaEditorFree, *PCTrackManiaEditorFree;

struct CTrackManiaEditorFree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugModelLodMesh SMwParamInfos_CPlugModelLodMesh, *PSMwParamInfos_CPlugModelLodMesh;

struct SMwParamInfos_CPlugModelLodMesh {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_GmClipFlag_HalfCube> CFastBuffer<struct_GmClipFlag_HalfCube>, *PCFastBuffer<struct_GmClipFlag_HalfCube>;

struct CFastBuffer<struct_GmClipFlag_HalfCube> {
    undefined field0_0x0;
};

typedef struct GmSimi2 GmSimi2, *PGmSimi2;

struct GmSimi2 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameOutlineBox SMwParamInfos_CGameOutlineBox, *PSMwParamInfos_CGameOutlineBox;

struct SMwParamInfos_CGameOutlineBox {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoRectAsym CGameCtnBlockInfoRectAsym, *PCGameCtnBlockInfoRectAsym;

struct CGameCtnBlockInfoRectAsym {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderLightOcc CPlugBitmapRenderLightOcc, *PCPlugBitmapRenderLightOcc;

struct CPlugBitmapRenderLightOcc {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockCameraGame CGameCtnMediaBlockCameraGame, *PCGameCtnMediaBlockCameraGame;

struct CGameCtnMediaBlockCameraGame {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CTrackManiaRaceScore*> CFastBuffer<class_CTrackManiaRaceScore*>, *PCFastBuffer<class_CTrackManiaRaceScore*>;

struct CFastBuffer<class_CTrackManiaRaceScore*> {
    undefined field0_0x0;
};

typedef struct SRasterizeVertex SRasterizeVertex, *PSRasterizeVertex;

struct SRasterizeVertex {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld> CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld>, *PCFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld>;

struct CFastBuffer<struct_CGameCtnMenus::SFrameLadderRankingsStepOld> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnChapter SMwParamInfos_CGameControlCardCtnChapter, *PSMwParamInfos_CGameControlCardCtnChapter;

struct SMwParamInfos_CGameControlCardCtnChapter {
    undefined field0_0x0;
};

typedef struct CHmsCorpus2d CHmsCorpus2d, *PCHmsCorpus2d;

struct CHmsCorpus2d {
    undefined field0_0x0;
};

typedef struct SNewTriangleVert SNewTriangleVert, *PSNewTriangleVert;

struct SNewTriangleVert {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarEnum CMwCmdScriptVarEnum, *PCMwCmdScriptVarEnum;

struct CMwCmdScriptVarEnum {
    undefined field0_0x0;
};

typedef enum EAccountType {
} EAccountType;

typedef struct Rep Rep, *PRep;

struct Rep {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SMaterial> CFastBuffer<struct_CPlugModelMesh::SMaterial>, *PCFastBuffer<struct_CPlugModelMesh::SMaterial>;

struct CFastBuffer<struct_CPlugModelMesh::SMaterial> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsCorpus2d SMwParamInfos_CHmsCorpus2d, *PSMwParamInfos_CHmsCorpus2d;

struct SMwParamInfos_CHmsCorpus2d {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2Param CMwCmdExpVec2Param, *PCMwCmdExpVec2Param;

struct CMwCmdExpVec2Param {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetMasterHost SMwParamInfos_CNetMasterHost, *PSMwParamInfos_CNetMasterHost;

struct SMwParamInfos_CNetMasterHost {
    undefined field0_0x0;
};

typedef struct CMotionCmdBase CMotionCmdBase, *PCMotionCmdBase;

struct CMotionCmdBase {
    undefined field0_0x0;
};

typedef struct CTrackManiaSwitcher CTrackManiaSwitcher, *PCTrackManiaSwitcher;

struct CTrackManiaSwitcher {
    undefined field0_0x0;
};

typedef struct CPlugVisualOctree CPlugVisualOctree, *PCPlugVisualOctree;

struct CPlugVisualOctree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetTeamInfo SMwParamInfos_CGameNetTeamInfo, *PSMwParamInfos_CGameNetTeamInfo;

struct SMwParamInfos_CGameNetTeamInfo {
    undefined field0_0x0;
};

typedef struct SRaceInputs SRaceInputs, *PSRaceInputs;

struct SRaceInputs {
    undefined field0_0x0;
};

typedef struct CMwParamIntegerRange CMwParamIntegerRange, *PCMwParamIntegerRange;

struct CMwParamIntegerRange {
    undefined field0_0x0;
};

typedef struct CInputDeviceMouse CInputDeviceMouse, *PCInputDeviceMouse;

struct CInputDeviceMouse {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockMusicEffect CMwClassInfoCGameCtnMediaBlockMusicEffect, *PCMwClassInfoCGameCtnMediaBlockMusicEffect;

struct CMwClassInfoCGameCtnMediaBlockMusicEffect {
    undefined field0_0x0;
};

typedef struct CMotionTrackMobilPitchin CMotionTrackMobilPitchin, *PCMotionTrackMobilPitchin;

struct CMotionTrackMobilPitchin {
    undefined field0_0x0;
};

typedef struct SImpressionAxe SImpressionAxe, *PSImpressionAxe;

struct SImpressionAxe {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxStereoscopy SMwParamInfos_CSceneFxStereoscopy, *PSMwParamInfos_CSceneFxStereoscopy;

struct SMwParamInfos_CSceneFxStereoscopy {
    undefined field0_0x0;
};

typedef struct CMultiArray<class_GmVec3> CMultiArray<class_GmVec3>, *PCMultiArray<class_GmVec3>;

struct CMultiArray<class_GmVec3> {
    undefined field0_0x0;
};

typedef struct SCustomFileInfo SCustomFileInfo, *PSCustomFileInfo;

struct SCustomFileInfo {
    undefined field0_0x0;
};

typedef struct md5_state_s md5_state_s, *Pmd5_state_s;

struct md5_state_s {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameSkin SMwParamInfos_CGameSkin, *PSMwParamInfos_CGameSkin;

struct SMwParamInfos_CGameSkin {
    undefined field0_0x0;
};

typedef struct SParamEffectCombined SParamEffectCombined, *PSParamEffectCombined;

struct SParamEffectCombined {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SMeshOctreeCell> CFastBuffer<struct_SMeshOctreeCell>, *PCFastBuffer<struct_SMeshOctreeCell>;

struct CFastBuffer<struct_SMeshOctreeCell> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewport::SDelayedToSortPass> CFastBuffer<struct_CVisionViewport::SDelayedToSortPass>, *PCFastBuffer<struct_CVisionViewport::SDelayedToSortPass>;

struct CFastBuffer<struct_CVisionViewport::SDelayedToSortPass> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFxBlur CGameCtnMediaBlockFxBlur, *PCGameCtnMediaBlockFxBlur;

struct CGameCtnMediaBlockFxBlur {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetNod*> CFastBuffer<class_CNetNod*>, *PCFastBuffer<class_CNetNod*>;

struct CFastBuffer<class_CNetNod*> {
    undefined field0_0x0;
};

typedef struct CClassicBufferZip CClassicBufferZip, *PCClassicBufferZip;

struct CClassicBufferZip {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer> CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>, *PCFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>;

struct CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer> {
    undefined field0_0x0;
};

typedef struct GmField2Compressed GmField2Compressed, *PGmField2Compressed;

struct GmField2Compressed {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>, *PCFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>;

struct CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFileGPU::SDxDefine> CFastBuffer<struct_CPlugFileGPU::SDxDefine>, *PCFastBuffer<struct_CPlugFileGPU::SDxDefine>;

struct CFastBuffer<struct_CPlugFileGPU::SDxDefine> {
    undefined field0_0x0;
};

typedef struct SFileDesc SFileDesc, *PSFileDesc;

struct SFileDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCamera SMwParamInfos_CGameControlCamera, *PSMwParamInfos_CGameControlCamera;

struct SMwParamInfos_CGameControlCamera {
    undefined field0_0x0;
};

typedef struct SGridAddChildContext SGridAddChildContext, *PSGridAddChildContext;

struct SGridAddChildContext {
    undefined field0_0x0;
};

typedef struct CPlugFileVideo CPlugFileVideo, *PCPlugFileVideo;

struct CPlugFileVideo {
    undefined field0_0x0;
};

typedef union UPlugRenderDevice UPlugRenderDevice, *PUPlugRenderDevice;

union UPlugRenderDevice {
};

typedef struct CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>, *PCFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>;

struct CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> {
    undefined field0_0x0;
};

typedef struct CFuncKeysSkel CFuncKeysSkel, *PCFuncKeysSkel;

struct CFuncKeysSkel {
    undefined field0_0x0;
};

typedef struct CSysFidNodRef<class_CScene3d> CSysFidNodRef<class_CScene3d>, *PCSysFidNodRef<class_CScene3d>;

struct CSysFidNodRef<class_CScene3d> {
    undefined field0_0x0;
};

typedef struct CCallbackSceneToyCharacterAfterContacts CCallbackSceneToyCharacterAfterContacts, *PCCallbackSceneToyCharacterAfterContacts;

struct CCallbackSceneToyCharacterAfterContacts {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMobilTraffic SMwParamInfos_CSceneMobilTraffic, *PSMwParamInfos_CSceneMobilTraffic;

struct SMwParamInfos_CSceneMobilTraffic {
    undefined field0_0x0;
};

typedef struct CPlugIndexBuffer CPlugIndexBuffer, *PCPlugIndexBuffer;

struct CPlugIndexBuffer {
    undefined field0_0x0;
};

typedef struct CMwCmdSwitchType CMwCmdSwitchType, *PCMwCmdSwitchType;

struct CMwCmdSwitchType {
    undefined field0_0x0;
};

typedef struct CDx9DeviceCaps CDx9DeviceCaps, *PCDx9DeviceCaps;

struct CDx9DeviceCaps {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CHmsWaterRegion::SCell> CFastArray<struct_CHmsWaterRegion::SCell>, *PCFastArray<struct_CHmsWaterRegion::SCell>;

struct CFastArray<struct_CHmsWaterRegion::SCell> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlGridCtnChallengeGroup SMwParamInfos_CGameControlGridCtnChallengeGroup, *PSMwParamInfos_CGameControlGridCtnChallengeGroup;

struct SMwParamInfos_CGameControlGridCtnChallengeGroup {
    undefined field0_0x0;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    uint Name;
    uint16.conflict Id;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct CPlugFileModel3ds CPlugFileModel3ds, *PCPlugFileModel3ds;

struct CPlugFileModel3ds {
    undefined field0_0x0;
};

typedef enum EChallengeType {
} EChallengeType;

typedef struct CFixedArray<class_CMwNodRef<class_CPlugShader>,2,unsigned_long> CFixedArray<class_CMwNodRef<class_CPlugShader>,2,unsigned_long>, *PCFixedArray<class_CMwNodRef<class_CPlugShader>,2,unsigned_long>;

struct CFixedArray<class_CMwNodRef<class_CPlugShader>,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceNet SMwParamInfos_CTrackManiaRaceNet, *PSMwParamInfos_CTrackManiaRaceNet;

struct SMwParamInfos_CTrackManiaRaceNet {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsSoundSource SMwParamInfos_CHmsSoundSource, *PSMwParamInfos_CHmsSoundSource;

struct SMwParamInfos_CHmsSoundSource {
    undefined field0_0x0;
};

typedef struct SHemiRect SHemiRect, *PSHemiRect;

struct SHemiRect {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetMasterServerRequest::SRequestElement*> CFastBuffer<struct_CNetMasterServerRequest::SRequestElement*>, *PCFastBuffer<struct_CNetMasterServerRequest::SRequestElement*>;

struct CFastBuffer<struct_CNetMasterServerRequest::SRequestElement*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapSampler SMwParamInfos_CPlugBitmapSampler, *PSMwParamInfos_CPlugBitmapSampler;

struct SMwParamInfos_CPlugBitmapSampler {
    undefined field0_0x0;
};

typedef enum ETransfoMode {
} ETransfoMode;

typedef struct CSceneSoundSource CSceneSoundSource, *PCSceneSoundSource;

struct CSceneSoundSource {
    undefined field0_0x0;
};

typedef struct CMotionManagerMeteoPuffLull CMotionManagerMeteoPuffLull, *PCMotionManagerMeteoPuffLull;

struct CMotionManagerMeteoPuffLull {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFxBloom CGameCtnMediaBlockFxBloom, *PCGameCtnMediaBlockFxBloom;

struct CGameCtnMediaBlockFxBloom {
    undefined field0_0x0;
};

typedef struct CCrystalQuadEqui CCrystalQuadEqui, *PCCrystalQuadEqui;

struct CCrystalQuadEqui {
    undefined field0_0x0;
};

typedef struct CHdrDeclaration CHdrDeclaration, *PCHdrDeclaration;

struct CHdrDeclaration {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardChampionship SMwParamInfos_CGameControlCardChampionship, *PSMwParamInfos_CGameControlCardChampionship;

struct SMwParamInfos_CGameControlCardChampionship {
    undefined field0_0x0;
};

typedef struct GmReal4_64 GmReal4_64, *PGmReal4_64;

struct GmReal4_64 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderVDepPlaneY SMwParamInfos_CPlugBitmapRenderVDepPlaneY, *PSMwParamInfos_CPlugBitmapRenderVDepPlaneY;

struct SMwParamInfos_CPlugBitmapRenderVDepPlaneY {
    undefined field0_0x0;
};

typedef struct CPlugModel CPlugModel, *PCPlugModel;

struct CPlugModel {
    undefined field0_0x0;
};

typedef struct SNodFid SNodFid, *PSNodFid;

struct SNodFid {
    undefined field0_0x0;
};

typedef struct CManoeuvre CManoeuvre, *PCManoeuvre;

struct CManoeuvre {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFileSnd> CMwNodRef<class_CPlugFileSnd>, *PCMwNodRef<class_CPlugFileSnd>;

struct CMwNodRef<class_CPlugFileSnd> {
    undefined field0_0x0;
};

typedef struct STexStageCat STexStageCat, *PSTexStageCat;

struct STexStageCat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderCubeMap SMwParamInfos_CPlugBitmapRenderCubeMap, *PSMwParamInfos_CPlugBitmapRenderCubeMap;

struct SMwParamInfos_CPlugBitmapRenderCubeMap {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamMwId> CMwParamFastBufferCat<class_CMwParamMwId>, *PCMwParamFastBufferCat<class_CMwParamMwId>;

struct CMwParamFastBufferCat<class_CMwParamMwId> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugBitmap>_> CFastBuffer<class_CMwNodRef<class_CPlugBitmap>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugBitmap>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugBitmap>_> {
    undefined field0_0x0;
};

typedef struct CMwParamMwId CMwParamMwId, *PCMwParamMwId;

struct CMwParamMwId {
    undefined field0_0x0;
};

typedef struct SHighQuality SHighQuality, *PSHighQuality;

struct SHighQuality {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamIso3> CMwParamFastArray<class_CMwParamIso3>, *PCMwParamFastArray<class_CMwParamIso3>;

struct CMwParamFastArray<class_CMwParamIso3> {
    undefined field0_0x0;
};

typedef struct CPlugFileGPU CPlugFileGPU, *PCPlugFileGPU;

struct CPlugFileGPU {
    undefined field0_0x0;
};

typedef struct CGbxGame CGbxGame, *PCGbxGame;

struct CGbxGame {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneField>_> CFastBuffer<class_CMwNodRef<class_CSceneField>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneField>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneField>_> {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamIso4> CMwParamFastArray<class_CMwParamIso4>, *PCMwParamFastArray<class_CMwParamIso4>;

struct CMwParamFastArray<class_CMwParamIso4> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLadderRankingSkill SMwParamInfos_CGameLadderRankingSkill, *PSMwParamInfos_CGameLadderRankingSkill;

struct SMwParamInfos_CGameLadderRankingSkill {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRender SMwParamInfos_CPlugBitmapRender, *PSMwParamInfos_CPlugBitmapRender;

struct SMwParamInfos_CPlugBitmapRender {
    undefined field0_0x0;
};

typedef struct CFixedArray<char_const*,218,unsigned_long> CFixedArray<char_const*,218,unsigned_long>, *PCFixedArray<char_const*,218,unsigned_long>;

struct CFixedArray<char_const*,218,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastString,6,unsigned_long> CFixedArray<class_CFastString,6,unsigned_long>, *PCFixedArray<class_CFastString,6,unsigned_long>;

struct CFixedArray<class_CFastString,6,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SQuadTreeMeshUv> CFastBuffer<struct_SQuadTreeMeshUv>, *PCFastBuffer<struct_SQuadTreeMeshUv>;

struct CFastBuffer<struct_SQuadTreeMeshUv> {
    undefined field0_0x0;
};

typedef struct SGameMasterServerRequestContext SGameMasterServerRequestContext, *PSGameMasterServerRequestContext;

struct SGameMasterServerRequestContext {
    undefined field0_0x0;
};

typedef enum EVCompUnitV {
} EVCompUnitV;

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    uint Characteristics;
    uint TimeDateStamp;
    uint16.conflict MajorVersion;
    uint16.conflict MinorVersion;
    uint16.conflict NumberOfNamedEntries;
    uint16.conflict NumberOfIdEntries;
};

typedef struct CMwClassInfoViewer CMwClassInfoViewer, *PCMwClassInfoViewer;

struct CMwClassInfoViewer {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringTrunc CMwCmdExpStringTrunc, *PCMwCmdExpStringTrunc;

struct CMwCmdExpStringTrunc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastStringInt> CFastBuffer<class_CFastStringInt>, *PCFastBuffer<class_CFastStringInt>;

struct CFastBuffer<class_CFastStringInt> {
    undefined field0_0x0;
};

typedef struct STravelParent STravelParent, *PSTravelParent;

struct STravelParent {
    undefined field0_0x0;
};

typedef struct SSampler SSampler, *PSSampler;

struct SSampler {
    undefined field0_0x0;
};

typedef struct CPlugBitmapRenderVDepPlaneY CPlugBitmapRenderVDepPlaneY, *PCPlugBitmapRenderVDepPlaneY;

struct CPlugBitmapRenderVDepPlaneY {
    undefined field0_0x0;
};

typedef struct SGmSmoothReal SGmSmoothReal, *PSGmSmoothReal;

struct SGmSmoothReal {
    undefined field0_0x0;
};

typedef struct SGameCtnMediaTriggerZone SGameCtnMediaTriggerZone, *PSGameCtnMediaTriggerZone;

struct SGameCtnMediaTriggerZone {
    undefined field0_0x0;
};

typedef struct CGameCtnCollectorVehicle CGameCtnCollectorVehicle, *PCGameCtnCollectorVehicle;

struct CGameCtnCollectorVehicle {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeVisualMip SMwParamInfos_CPlugTreeVisualMip, *PSMwParamInfos_CPlugTreeVisualMip;

struct SMwParamInfos_CPlugTreeVisualMip {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameNetManialinkPage>_> CFastBuffer<class_CMwNodRef<class_CGameNetManialinkPage>_>, *PCFastBuffer<class_CMwNodRef<class_CGameNetManialinkPage>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameNetManialinkPage>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderSub SMwParamInfos_CPlugBitmapRenderSub, *PSMwParamInfos_CPlugBitmapRenderSub;

struct SMwParamInfos_CPlugBitmapRenderSub {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameMenuColorEffect SMwParamInfos_CGameMenuColorEffect, *PSMwParamInfos_CGameMenuColorEffect;

struct SMwParamInfos_CGameMenuColorEffect {
    undefined field0_0x0;
};

typedef struct SKey SKey, *PSKey;

struct SKey {
    undefined field0_0x0;
};

typedef struct CPlugModelFences CPlugModelFences, *PCPlugModelFences;

struct CPlugModelFences {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameSafeFrameConfig SMwParamInfos_CGameSafeFrameConfig, *PSMwParamInfos_CGameSafeFrameConfig;

struct SMwParamInfos_CGameSafeFrameConfig {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxDepthOfField SMwParamInfos_CSceneFxDepthOfField, *PSMwParamInfos_CSceneFxDepthOfField;

struct SMwParamInfos_CSceneFxDepthOfField {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnArticle SMwParamInfos_CGameCtnArticle, *PSMwParamInfos_CGameCtnArticle;

struct SMwParamInfos_CGameCtnArticle {
    undefined field0_0x0;
};

typedef struct CSystemFile CSystemFile, *PCSystemFile;

struct CSystemFile {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleStruct::SVisualLight> CFastBuffer<struct_CSceneVehicleStruct::SVisualLight>, *PCFastBuffer<struct_CSceneVehicleStruct::SVisualLight>;

struct CFastBuffer<struct_CSceneVehicleStruct::SVisualLight> {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockTransitionFade CGameCtnMediaBlockTransitionFade, *PCGameCtnMediaBlockTransitionFade;

struct CGameCtnMediaBlockTransitionFade {
    undefined field0_0x0;
};

typedef struct CMwCmdInst CMwCmdInst, *PCMwCmdInst;

struct CMwCmdInst {
    undefined field0_0x0;
};

typedef enum PATH_RESULT {
} PATH_RESULT;

typedef struct GmSphereCapCone3_Cull_Sphere GmSphereCapCone3_Cull_Sphere, *PGmSphereCapCone3_Cull_Sphere;

struct GmSphereCapCone3_Cull_Sphere {
    undefined field0_0x0;
};

typedef struct CNetMasterServerDownload CNetMasterServerDownload, *PCNetMasterServerDownload;

struct CNetMasterServerDownload {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameCtnDecorationTerrainModifier> CFastBufferRef<class_CGameCtnDecorationTerrainModifier>, *PCFastBufferRef<class_CGameCtnDecorationTerrainModifier>;

struct CFastBufferRef<class_CGameCtnDecorationTerrainModifier> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Function CMwCmdExpVec3Function, *PCMwCmdExpVec3Function;

struct CMwCmdExpVec3Function {
    undefined field0_0x0;
};

typedef struct CFuncTreeRotate CFuncTreeRotate, *PCFuncTreeRotate;

struct CFuncTreeRotate {
    undefined field0_0x0;
};

typedef struct CAudioPort CAudioPort, *PCAudioPort;

struct CAudioPort {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugSound> CMwNodRef<class_CPlugSound>, *PCMwNodRef<class_CPlugSound>;

struct CMwNodRef<class_CPlugSound> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxColors SMwParamInfos_CSceneFxColors, *PSMwParamInfos_CSceneFxColors;

struct SMwParamInfos_CSceneFxColors {
    undefined field0_0x0;
};

typedef struct CGameAdvertisingElement CGameAdvertisingElement, *PCGameAdvertisingElement;

struct CGameAdvertisingElement {
    undefined field0_0x0;
};

typedef struct CSceneFxOccZCmp CSceneFxOccZCmp, *PCSceneFxOccZCmp;

struct CSceneFxOccZCmp {
    undefined field0_0x0;
};

typedef struct CSystemKeyboard CSystemKeyboard, *PCSystemKeyboard;

struct CSystemKeyboard {
    undefined field0_0x0;
};

typedef struct STransformDesc STransformDesc, *PSTransformDesc;

struct STransformDesc {
    undefined field0_0x0;
};

typedef struct CMwCmdFastCallUser CMwCmdFastCallUser, *PCMwCmdFastCallUser;

struct CMwCmdFastCallUser {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamInteger> CMwParamFastBufferCat<class_CMwParamInteger>, *PCMwParamFastBufferCat<class_CMwParamInteger>;

struct CMwParamFastBufferCat<class_CMwParamInteger> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameGhost SMwParamInfos_CGameGhost, *PSMwParamInfos_CGameGhost;

struct SMwParamInfos_CGameGhost {
    undefined field0_0x0;
};

typedef struct CSystemFids CSystemFids, *PCSystemFids;

struct CSystemFids {
    undefined field0_0x0;
};

typedef enum EGxTexOutput {
} EGxTexOutput;

typedef struct SPixelBlend SPixelBlend, *PSPixelBlend;

struct SPixelBlend {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockFxColors CGameCtnMediaBlockFxColors, *PCGameCtnMediaBlockFxColors;

struct CGameCtnMediaBlockFxColors {
    undefined field0_0x0;
};

typedef struct CPlugFileGpuFxD3d CPlugFileGpuFxD3d, *PCPlugFileGpuFxD3d;

struct CPlugFileGpuFxD3d {
    undefined field0_0x0;
};

typedef struct CMwParamString CMwParamString, *PCMwParamString;

struct CMwParamString {
    undefined field0_0x0;
};

typedef struct CGameNetwork CGameNetwork, *PCGameNetwork;

struct CGameNetwork {
    undefined field0_0x0;
};

typedef struct CSystemMouse CSystemMouse, *PCSystemMouse;

struct CSystemMouse {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneObjectLink SMwParamInfos_CSceneObjectLink, *PSMwParamInfos_CSceneObjectLink;

struct SMwParamInfos_CSceneObjectLink {
    undefined field0_0x0;
};

typedef struct CSystemFidMemory CSystemFidMemory, *PCSystemFidMemory;

struct CSystemFidMemory {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemFidBuffer SMwParamInfos_CSystemFidBuffer, *PSMwParamInfos_CSystemFidBuffer;

struct SMwParamInfos_CSystemFidBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePopUp SMwParamInfos_CGamePopUp, *PSMwParamInfos_CGamePopUp;

struct SMwParamInfos_CGamePopUp {
    undefined field0_0x0;
};

typedef struct _D3DXIMAGE_INFO _D3DXIMAGE_INFO, *P_D3DXIMAGE_INFO;

struct _D3DXIMAGE_INFO {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_MMCKINFO - /mmsystem.h/_MMCKINFO */

typedef struct CMwCmdExpBool CMwCmdExpBool, *PCMwCmdExpBool;

struct CMwCmdExpBool {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SPlayerTagsConfig::SPlayerTagConfig> CFastBuffer<struct_SPlayerTagsConfig::SPlayerTagConfig>, *PCFastBuffer<struct_SPlayerTagsConfig::SPlayerTagConfig>;

struct CFastBuffer<struct_SPlayerTagsConfig::SPlayerTagConfig> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayer SMwParamInfos_CGamePlayer, *PSMwParamInfos_CGamePlayer;

struct SMwParamInfos_CGamePlayer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerOfficialScores::SFilteredPlayerRank> CFastBuffer<struct_CGamePlayerOfficialScores::SFilteredPlayerRank>, *PCFastBuffer<struct_CGamePlayerOfficialScores::SFilteredPlayerRank>;

struct CFastBuffer<struct_CGamePlayerOfficialScores::SFilteredPlayerRank> {
    undefined field0_0x0;
};

typedef struct _Vector_iterator<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> _Vector_iterator<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_>, *P_Vector_iterator<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_>;

struct _Vector_iterator<class_NvEdgeInfo*,class_std::allocator<class_NvEdgeInfo*>_> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamMwId> CMwParamFastBuffer<class_CMwParamMwId>, *PCMwParamFastBuffer<class_CMwParamMwId>;

struct CMwParamFastBuffer<class_CMwParamMwId> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionGroupPlayers SMwParamInfos_CMotionGroupPlayers, *PSMwParamInfos_CMotionGroupPlayers;

struct SMwParamInfos_CMotionGroupPlayers {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsZoneVPacker::SShaderWrap> CFastBuffer<struct_CHmsZoneVPacker::SShaderWrap>, *PCFastBuffer<struct_CHmsZoneVPacker::SShaderWrap>;

struct CFastBuffer<struct_CHmsZoneVPacker::SShaderWrap> {
    undefined field0_0x0;
};

typedef struct CTrackManiaMenus CTrackManiaMenus, *PCTrackManiaMenus;

struct CTrackManiaMenus {
    undefined field0_0x0;
};

typedef enum EStateBlock {
} EStateBlock;

typedef struct CFastBufferRef<class_CSceneSector> CFastBufferRef<class_CSceneSector>, *PCFastBufferRef<class_CSceneSector>;

struct CFastBufferRef<class_CSceneSector> {
    undefined field0_0x0;
};

typedef struct CSceneVehicleTunings CSceneVehicleTunings, *PCSceneVehicleTunings;

struct CSceneVehicleTunings {
    undefined field0_0x0;
};

typedef struct GmField2 GmField2, *PGmField2;

struct GmField2 {
    undefined field0_0x0;
};

typedef struct D3DXMATRIX D3DXMATRIX, *PD3DXMATRIX;

struct D3DXMATRIX {
    undefined field0_0x0;
};

typedef struct CNetNod CNetNod, *PCNetNod;

struct CNetNod {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugShaderApply> CMwNodRef<class_CPlugShaderApply>, *PCMwNodRef<class_CPlugShaderApply>;

struct CMwNodRef<class_CPlugShaderApply> {
    undefined field0_0x0;
};

typedef struct CEditionDataBitmap CEditionDataBitmap, *PCEditionDataBitmap;

struct CEditionDataBitmap {
    undefined field0_0x0;
};

typedef struct SPlugGpuParamSkipSampler SPlugGpuParamSkipSampler, *PSPlugGpuParamSkipSampler;

struct SPlugGpuParamSkipSampler {
    undefined field0_0x0;
};

typedef struct CNetUPnP CNetUPnP, *PCNetUPnP;

struct CNetUPnP {
    undefined field0_0x0;
};

typedef struct _Vector_iterator<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_> _Vector_iterator<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_>, *P_Vector_iterator<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_>;

struct _Vector_iterator<class_NvStripInfo*,class_std::allocator<class_NvStripInfo*>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugShaderSpritePath SMwParamInfos_CPlugShaderSpritePath, *PSMwParamInfos_CPlugShaderSpritePath;

struct SMwParamInfos_CPlugShaderSpritePath {
    undefined field0_0x0;
};

typedef struct CPlugBitmapPackInput CPlugBitmapPackInput, *PCPlugBitmapPackInput;

struct CPlugBitmapPackInput {
    undefined field0_0x0;
};

typedef struct CMwCmdExpEnum CMwCmdExpEnum, *PCMwCmdExpEnum;

struct CMwCmdExpEnum {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNeg CMwCmdExpNeg, *PCMwCmdExpNeg;

struct CMwCmdExpNeg {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CBoatSail> CFastBufferRef<class_CBoatSail>, *PCFastBufferRef<class_CBoatSail>;

struct CFastBufferRef<class_CBoatSail> {
    undefined field0_0x0;
};

typedef struct SParamShaderFlags SParamShaderFlags, *PSParamShaderFlags;

struct SParamShaderFlags {
    undefined field0_0x0;
};

typedef struct SIdRemapTable SIdRemapTable, *PSIdRemapTable;

struct SIdRemapTable {
    undefined field0_0x0;
};

typedef struct CGameNetSearchRequest_Servers CGameNetSearchRequest_Servers, *PCGameNetSearchRequest_Servers;

struct CGameNetSearchRequest_Servers {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardLadderRanking SMwParamInfos_CGameControlCardLadderRanking, *PSMwParamInfos_CGameControlCardLadderRanking;

struct SMwParamInfos_CGameControlCardLadderRanking {
    undefined field0_0x0;
};

typedef struct SEventCheckpoint SEventCheckpoint, *PSEventCheckpoint;

struct SEventCheckpoint {
    undefined field0_0x0;
};

typedef struct LocatedGmSurf LocatedGmSurf, *PLocatedGmSurf;

struct LocatedGmSurf {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameTournament> CFastBufferRef<class_CGameTournament>, *PCFastBufferRef<class_CGameTournament>;

struct CFastBufferRef<class_CGameTournament> {
    undefined field0_0x0;
};

typedef struct SComp SComp, *PSComp;

struct SComp {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneFxSuperSample::SMultiLight> CFastBuffer<struct_CSceneFxSuperSample::SMultiLight>, *PCFastBuffer<struct_CSceneFxSuperSample::SMultiLight>;

struct CFastBuffer<struct_CSceneFxSuperSample::SMultiLight> {
    undefined field0_0x0;
};

typedef enum EGameState {
} EGameState;

typedef struct CFastBuffer<struct_SIPCRemoteControl_Implem::SDeliveryHandlers> CFastBuffer<struct_SIPCRemoteControl_Implem::SDeliveryHandlers>, *PCFastBuffer<struct_SIPCRemoteControl_Implem::SDeliveryHandlers>;

struct CFastBuffer<struct_SIPCRemoteControl_Implem::SDeliveryHandlers> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat> CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>, *PCFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat>;

struct CFastBuffer<struct_CPlugBitmap::SSpecularSubMapCat> {
    undefined field0_0x0;
};

typedef struct CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord> CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>, *PCFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord>;

struct CFastMapTable<struct_CGameAdvertisingElement::CImpressionCollector::SImpressionRecord> {
    undefined field0_0x0;
};

typedef struct xmlrpc_xportparms xmlrpc_xportparms, *Pxmlrpc_xportparms;

struct xmlrpc_xportparms {
    undefined field0_0x0;
};

typedef struct CFastBuffer<unsigned_short> CFastBuffer<unsigned_short>, *PCFastBuffer<unsigned_short>;

struct CFastBuffer<unsigned_short> {
    undefined field0_0x0;
};

typedef struct SFlagsOld1To2 SFlagsOld1To2, *PSFlagsOld1To2;

struct SFlagsOld1To2 {
    undefined field0_0x0;
};

typedef struct CStyleSheetElem<class_CControlStyle> CStyleSheetElem<class_CControlStyle>, *PCStyleSheetElem<class_CControlStyle>;

struct CStyleSheetElem<class_CControlStyle> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_> CFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_>, *PCFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameManialinkEntry>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraTarget SMwParamInfos_CGameControlCameraTarget, *PSMwParamInfos_CGameControlCameraTarget;

struct SMwParamInfos_CGameControlCameraTarget {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSoundSurface SMwParamInfos_CPlugSoundSurface, *PSMwParamInfos_CPlugSoundSurface;

struct SMwParamInfos_CPlugSoundSurface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraFree SMwParamInfos_CGameControlCameraFree, *PSMwParamInfos_CGameControlCameraFree;

struct SMwParamInfos_CGameControlCameraFree {
    undefined field0_0x0;
};

typedef struct _SHFILEOPSTRUCTW _SHFILEOPSTRUCTW, *P_SHFILEOPSTRUCTW;

struct _SHFILEOPSTRUCTW {
    struct HWND__ *hwnd;
    uint wFunc;
    wchar_t *pFrom;
    wchar_t *pTo;
    ushort fFlags;
    int fAnyOperationsAborted;
    void *hNameMappings;
    wchar_t *lpszProgressTitle;
};

typedef struct CFastBuffer<struct_SBindingToSort> CFastBuffer<struct_SBindingToSort>, *PCFastBuffer<struct_SBindingToSort>;

struct CFastBuffer<struct_SBindingToSort> {
    undefined field0_0x0;
};

typedef enum EControlMode {
} EControlMode;

typedef struct CGameControlCardProfile CGameControlCardProfile, *PCGameControlCardProfile;

struct CGameControlCardProfile {
    undefined field0_0x0;
};

typedef struct CHmsCollisionBuffer CHmsCollisionBuffer, *PCHmsCollisionBuffer;

struct CHmsCollisionBuffer {
    undefined field0_0x0;
};

typedef struct CPlugTreeVisualGrider CPlugTreeVisualGrider, *PCPlugTreeVisualGrider;

struct CPlugTreeVisualGrider {
    undefined field0_0x0;
};

typedef struct SFilteredInfos SFilteredInfos, *PSFilteredInfos;

struct SFilteredInfos {
    undefined field0_0x0;
};

typedef struct SComputeCamera SComputeCamera, *PSComputeCamera;

struct SComputeCamera {
    undefined field0_0x0;
};

typedef struct _CRT_FLOAT _CRT_FLOAT, *P_CRT_FLOAT;

struct _CRT_FLOAT {
    float f;
};

typedef struct CFastArray<class_CMwNodRef<class_CPlugBitmap>_> CFastArray<class_CMwNodRef<class_CPlugBitmap>_>, *PCFastArray<class_CMwNodRef<class_CPlugBitmap>_>;

struct CFastArray<class_CMwNodRef<class_CPlugBitmap>_> {
    undefined field0_0x0;
};

typedef struct CFuncFullColorGradient CFuncFullColorGradient, *PCFuncFullColorGradient;

struct CFuncFullColorGradient {
    undefined field0_0x0;
};

typedef struct CTrackManiaMatchSettingsControlGrid CTrackManiaMatchSettingsControlGrid, *PCTrackManiaMatchSettingsControlGrid;

struct CTrackManiaMatchSettingsControlGrid {
    undefined field0_0x0;
};

typedef struct CMwCmdExpPower CMwCmdExpPower, *PCMwCmdExpPower;

struct CMwCmdExpPower {
    undefined field0_0x0;
};

typedef struct CPlugFileGen CPlugFileGen, *PCPlugFileGen;

struct CPlugFileGen {
    undefined field0_0x0;
};

typedef struct SChallengeOpponents SChallengeOpponents, *PSChallengeOpponents;

struct SChallengeOpponents {
    undefined field0_0x0;
};

typedef struct SFollowedNode SFollowedNode, *PSFollowedNode;

struct SFollowedNode {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileGPU SMwParamInfos_CPlugFileGPU, *PSMwParamInfos_CPlugFileGPU;

struct SMwParamInfos_CPlugFileGPU {
    undefined field0_0x0;
};

typedef struct NvStripifier NvStripifier, *PNvStripifier;

struct NvStripifier {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlFrameStyled SMwParamInfos_CControlFrameStyled, *PSMwParamInfos_CControlFrameStyled;

struct SMwParamInfos_CControlFrameStyled {
    undefined field0_0x0;
};

typedef enum EPlugVDclType {
} EPlugVDclType;

typedef struct CFastBuffer<struct_CPlugPointsInSphereOpt::SPack> CFastBuffer<struct_CPlugPointsInSphereOpt::SPack>, *PCFastBuffer<struct_CPlugPointsInSphereOpt::SPack>;

struct CFastBuffer<struct_CPlugPointsInSphereOpt::SPack> {
    undefined field0_0x0;
};

typedef enum ECipherOpMode {
} ECipherOpMode;

typedef struct CNetRequestData CNetRequestData, *PCNetRequestData;

struct CNetRequestData {
    undefined field0_0x0;
};

typedef struct CPlugVisualIndexedTriangles CPlugVisualIndexedTriangles, *PCPlugVisualIndexedTriangles;

struct CPlugVisualIndexedTriangles {
    undefined field0_0x0;
};

typedef enum ERealInterp {
} ERealInterp;

typedef struct SSolid SSolid, *PSSolid;

struct SSolid {
    undefined field0_0x0;
};

typedef enum EOutputRT {
} EOutputRT;

typedef enum EGmVec3Interp {
} EGmVec3Interp;

typedef struct CFastArray<unsigned_char> CFastArray<unsigned_char>, *PCFastArray<unsigned_char>;

struct CFastArray<unsigned_char> {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockCameraCustom CMwClassInfoCGameCtnMediaBlockCameraCustom, *PCMwClassInfoCGameCtnMediaBlockCameraCustom;

struct CMwClassInfoCGameCtnMediaBlockCameraCustom {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CGamePlayerInfo*> CFastBuffer<class_CGamePlayerInfo*>, *PCFastBuffer<class_CGamePlayerInfo*>;

struct CFastBuffer<class_CGamePlayerInfo*> {
    undefined field0_0x0;
};

typedef struct _D3DVIEWPORT9 _D3DVIEWPORT9, *P_D3DVIEWPORT9;

struct _D3DVIEWPORT9 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaEditorIconPage SMwParamInfos_CTrackManiaEditorIconPage, *PSMwParamInfos_CTrackManiaEditorIconPage;

struct SMwParamInfos_CTrackManiaEditorIconPage {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CHmsZoneOverlay*> CFastBuffer<class_CHmsZoneOverlay*>, *PCFastBuffer<class_CHmsZoneOverlay*>;

struct CFastBuffer<class_CHmsZoneOverlay*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject> CFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject>, *PCFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject>;

struct CFastBuffer<struct_CPlugBitmapRenderHemisphere::SHemiObject> {
    undefined field0_0x0;
};

typedef struct CMwCmdExp CMwCmdExp, *PCMwCmdExp;

struct CMwCmdExp {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFont::SCharStyle::SStyle> CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>, *PCFastBuffer<struct_CPlugFont::SCharStyle::SStyle>;

struct CFastBuffer<struct_CPlugFont::SCharStyle::SStyle> {
    undefined field0_0x0;
};

typedef struct SChunkFlags SChunkFlags, *PSChunkFlags;

struct SChunkFlags {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameHighScore> CMwNodRef<class_CGameHighScore>, *PCMwNodRef<class_CGameHighScore>;

struct CMwNodRef<class_CGameHighScore> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockCameraEffectShake::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct TiXmlParsingData TiXmlParsingData, *PTiXmlParsingData;

struct TiXmlParsingData {
    undefined field0_0x0;
};

typedef struct xmlrpc_call_info xmlrpc_call_info, *Pxmlrpc_call_info;

struct xmlrpc_call_info {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugVolumeShadow*> CFastCallback1P<class_CPlugVolumeShadow*>, *PCFastCallback1P<class_CPlugVolumeShadow*>;

struct CFastCallback1P<class_CPlugVolumeShadow*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameMenuScaleEffect SMwParamInfos_CGameMenuScaleEffect, *PSMwParamInfos_CGameMenuScaleEffect;

struct SMwParamInfos_CGameMenuScaleEffect {
    undefined field0_0x0;
};

typedef struct SVertexFlags SVertexFlags, *PSVertexFlags;

struct SVertexFlags {
    undefined field0_0x0;
};

typedef struct CPlugTreeVisualMip CPlugTreeVisualMip, *PCPlugTreeVisualMip;

struct CPlugTreeVisualMip {
    undefined field0_0x0;
};

typedef enum EGxBlendOp {
} EGxBlendOp;

typedef struct CGameCtnPylonColumn CGameCtnPylonColumn, *PCGameCtnPylonColumn;

struct CGameCtnPylonColumn {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastString*> CFastBuffer<class_CFastString*>, *PCFastBuffer<class_CFastString*>;

struct CFastBuffer<class_CFastString*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionSkel SMwParamInfos_CMotionSkel, *PSMwParamInfos_CMotionSkel;

struct SMwParamInfos_CMotionSkel {
    undefined field0_0x0;
};

typedef struct CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>, *PCFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue>;

struct CFastMapTable<struct_CPlugTreeMapShaderFill::SFillValue> {
    undefined field0_0x0;
};

typedef struct CSceneMobilOnVisibleWake CSceneMobilOnVisibleWake, *PCSceneMobilOnVisibleWake;

struct CSceneMobilOnVisibleWake {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlDisplayGraph SMwParamInfos_CControlDisplayGraph, *PSMwParamInfos_CControlDisplayGraph;

struct SMwParamInfos_CControlDisplayGraph {
    undefined field0_0x0;
};

typedef struct SPackListElem SPackListElem, *PSPackListElem;

struct SPackListElem {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleSpeedBoatTuning SMwParamInfos_CSceneVehicleSpeedBoatTuning, *PSMwParamInfos_CSceneVehicleSpeedBoatTuning;

struct SMwParamInfos_CSceneVehicleSpeedBoatTuning {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_CPlugBitmapRenderHemisphere::SHemiRect,22,unsigned_long> CFixedArray<struct_CPlugBitmapRenderHemisphere::SHemiRect,22,unsigned_long>, *PCFixedArray<struct_CPlugBitmapRenderHemisphere::SHemiRect,22,unsigned_long>;

struct CFixedArray<struct_CPlugBitmapRenderHemisphere::SHemiRect,22,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SPackModel SPackModel, *PSPackModel;

struct SPackModel {
    undefined field0_0x0;
};

typedef struct CMwCmdFor CMwCmdFor, *PCMwCmdFor;

struct CMwCmdFor {
    undefined field0_0x0;
};

typedef struct SWindShiftTimeSlice SWindShiftTimeSlice, *PSWindShiftTimeSlice;

struct SWindShiftTimeSlice {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapHighLevel SMwParamInfos_CPlugBitmapHighLevel, *PSMwParamInfos_CPlugBitmapHighLevel;

struct SMwParamInfos_CPlugBitmapHighLevel {
    undefined field0_0x0;
};

typedef struct CCrystalEdge CCrystalEdge, *PCCrystalEdge;

struct CCrystalEdge {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameControlCameraEffect> CMwNodRef<class_CGameControlCameraEffect>, *PCMwNodRef<class_CGameControlCameraEffect>;

struct CMwNodRef<class_CGameControlCameraEffect> {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamClass> CMwParamFastBufferCat<class_CMwParamClass>, *PCMwParamFastBufferCat<class_CMwParamClass>;

struct CMwParamFastBufferCat<class_CMwParamClass> {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_s__RTTICompleteObjectLocator - /_s__RTTICompleteObjectLocator */

typedef struct CScanner CScanner, *PCScanner;

struct CScanner {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderScene3d SMwParamInfos_CPlugBitmapRenderScene3d, *PSMwParamInfos_CPlugBitmapRenderScene3d;

struct SMwParamInfos_CPlugBitmapRenderScene3d {
    undefined field0_0x0;
};

typedef struct CFuncPathMeshLocation CFuncPathMeshLocation, *PCFuncPathMeshLocation;

struct CFuncPathMeshLocation {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMobil SMwParamInfos_CSceneMobil, *PSMwParamInfos_CSceneMobil;

struct SMwParamInfos_CSceneMobil {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionPath SMwParamInfos_CMotionPath, *PSMwParamInfos_CMotionPath;

struct SMwParamInfos_CMotionPath {
    undefined field0_0x0;
};

typedef struct TiXmlAttribute TiXmlAttribute, *PTiXmlAttribute;

struct TiXmlAttribute {
    undefined field0_0x0;
};

typedef struct CSceneToyRock CSceneToyRock, *PCSceneToyRock;

struct CSceneToyRock {
    undefined field0_0x0;
};

typedef struct CGameCtnGhostInfo CGameCtnGhostInfo, *PCGameCtnGhostInfo;

struct CGameCtnGhostInfo {
    undefined field0_0x0;
};

typedef struct SLadderStats SLadderStats, *PSLadderStats;

struct SLadderStats {
    undefined field0_0x0;
};

typedef struct basic_streambuf<char,struct_std::char_traits<char>_> basic_streambuf<char,struct_std::char_traits<char>_>, *Pbasic_streambuf<char,struct_std::char_traits<char>_>;

struct basic_streambuf<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockCameraPath::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CCrystalTriangleEqui CCrystalTriangleEqui, *PCCrystalTriangleEqui;

struct CCrystalTriangleEqui {
    undefined field0_0x0;
};

typedef struct GmOctree<struct_SMeshOctreeCell> GmOctree<struct_SMeshOctreeCell>, *PGmOctree<struct_SMeshOctreeCell>;

struct GmOctree<struct_SMeshOctreeCell> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlField2 SMwParamInfos_CControlField2, *PSMwParamInfos_CControlField2;

struct SMwParamInfos_CControlField2 {
    undefined field0_0x0;
};

typedef struct SUsage SUsage, *PSUsage;

struct SUsage {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,13,unsigned_long> CFixedArray<unsigned_long,13,unsigned_long>, *PCFixedArray<unsigned_long,13,unsigned_long>;

struct CFixedArray<unsigned_long,13,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SFilter SFilter, *PSFilter;

struct SFilter {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastString> CFastBuffer<class_CFastString>, *PCFastBuffer<class_CFastString>;

struct CFastBuffer<class_CFastString> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneToyCharacterTuning> CMwNodRef<class_CSceneToyCharacterTuning>, *PCMwNodRef<class_CSceneToyCharacterTuning>;

struct CMwNodRef<class_CSceneToyCharacterTuning> {
    undefined field0_0x0;
};

typedef enum EMemoryUsage {
} EMemoryUsage;

typedef struct CMwNodRef<class_CMwRefBuffer> CMwNodRef<class_CMwRefBuffer>, *PCMwNodRef<class_CMwRefBuffer>;

struct CMwNodRef<class_CMwRefBuffer> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpAnd SMwParamInfos_CMwCmdExpAnd, *PSMwParamInfos_CMwCmdExpAnd;

struct SMwParamInfos_CMwCmdExpAnd {
    undefined field0_0x0;
};

typedef struct SFeature SFeature, *PSFeature;

struct SFeature {
    undefined field0_0x0;
};

typedef struct CPlugShaderSprite CPlugShaderSprite, *PCPlugShaderSprite;

struct CPlugShaderSprite {
    undefined field0_0x0;
};

typedef struct CPlugFileAvi CPlugFileAvi, *PCPlugFileAvi;

struct CPlugFileAvi {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugModelMesh::SPolyGroup> CFastBuffer<struct_CPlugModelMesh::SPolyGroup>, *PCFastBuffer<struct_CPlugModelMesh::SPolyGroup>;

struct CFastBuffer<struct_CPlugModelMesh::SPolyGroup> {
    undefined field0_0x0;
};

typedef struct STimeLineIo STimeLineIo, *PSTimeLineIo;

struct STimeLineIo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameAnalyzer SMwParamInfos_CGameAnalyzer, *PSMwParamInfos_CGameAnalyzer;

struct SMwParamInfos_CGameAnalyzer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpString SMwParamInfos_CMwCmdExpString, *PSMwParamInfos_CMwCmdExpString;

struct SMwParamInfos_CMwCmdExpString {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCalendar SMwParamInfos_CGameCalendar, *PSMwParamInfos_CGameCalendar;

struct SMwParamInfos_CGameCalendar {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnReplayRecordInfo SMwParamInfos_CGameCtnReplayRecordInfo, *PSMwParamInfos_CGameCtnReplayRecordInfo;

struct SMwParamInfos_CGameCtnReplayRecordInfo {
    undefined field0_0x0;
};

typedef struct CSystemData CSystemData, *PCSystemData;

struct CSystemData {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmVec4,struct_SFastCat> CFastBufferCat<class_GmVec4,struct_SFastCat>, *PCFastBufferCat<class_GmVec4,struct_SFastCat>;

struct CFastBufferCat<class_GmVec4,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CSceneObjectLink CSceneObjectLink, *PCSceneObjectLink;

struct CSceneObjectLink {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CBoatTeamMateActionDesc> CFastBufferRef<class_CBoatTeamMateActionDesc>, *PCFastBufferRef<class_CBoatTeamMateActionDesc>;

struct CFastBufferRef<class_CBoatTeamMateActionDesc> {
    undefined field0_0x0;
};

typedef struct basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>, *Pbasic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>;

struct basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaEditorTerrain SMwParamInfos_CTrackManiaEditorTerrain, *PSMwParamInfos_CTrackManiaEditorTerrain;

struct SMwParamInfos_CTrackManiaEditorTerrain {
    undefined field0_0x0;
};

typedef struct CNetFileTransferDataToSend CNetFileTransferDataToSend, *PCNetFileTransferDataToSend;

struct CNetFileTransferDataToSend {
    undefined field0_0x0;
};

typedef enum ESaveSequenceEvent {
} ESaveSequenceEvent;

typedef struct CGameControlCardGeneric CGameControlCardGeneric, *PCGameControlCardGeneric;

struct CGameControlCardGeneric {
    undefined field0_0x0;
};

typedef enum EPlugShaderVertexColor {
} EPlugShaderVertexColor;

typedef struct CInputDeviceDx8Pad CInputDeviceDx8Pad, *PCInputDeviceDx8Pad;

struct CInputDeviceDx8Pad {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileFidContainer SMwParamInfos_CPlugFileFidContainer, *PSMwParamInfos_CPlugFileFidContainer;

struct SMwParamInfos_CPlugFileFidContainer {
    undefined field0_0x0;
};

typedef struct SCriteria SCriteria, *PSCriteria;

struct SCriteria {
    undefined field0_0x0;
};

typedef struct CGameControlCameraTrackManiaRace3 CGameControlCameraTrackManiaRace3, *PCGameControlCameraTrackManiaRace3;

struct CGameControlCameraTrackManiaRace3 {
    undefined field0_0x0;
};

typedef struct CGameControlCameraTrackManiaRace2 CGameControlCameraTrackManiaRace2, *PCGameControlCameraTrackManiaRace2;

struct CGameControlCameraTrackManiaRace2 {
    undefined field0_0x0;
};

typedef struct CTrackManiaPlayerCameraSet CTrackManiaPlayerCameraSet, *PCTrackManiaPlayerCameraSet;

struct CTrackManiaPlayerCameraSet {
    undefined field0_0x0;
};

typedef struct _tiddata _tiddata, *P_tiddata;

typedef struct setloc_struct setloc_struct, *Psetloc_struct;

struct setloc_struct {
    wchar_t *pchLanguage;
    wchar_t *pchCountry;
    int iLocState;
    int iPrimaryLen;
    int bAbbrevLanguage;
    int bAbbrevCountry;
    uint _cachecp;
    wchar_t _cachein[131];
    wchar_t _cacheout[131];
    struct _is_ctype_compatible _Loc_c[5];
    wchar_t _cacheLocaleName[85];
};

struct _tiddata {
    ulong _tid;
    uint _thandle;
    int _terrno;
    ulong _tdoserrno;
    uint _fpds;
    ulong _holdrand;
    char *_token;
    wchar_t *_wtoken;
    uchar *_mtoken;
    char *_errmsg;
    wchar_t *_werrmsg;
    char *_namebuf0;
    wchar_t *_wnamebuf0;
    char *_namebuf1;
    wchar_t *_wnamebuf1;
    char *_asctimebuf;
    wchar_t *_wasctimebuf;
    void *_gmtimebuf;
    char *_cvtbuf;
    uchar _con_ch_buf[5];
    ushort _ch_buf_used;
    void *_initaddr;
    void *_initarg;
    void *_pxcptacttab;
    void *_tpxcptinfoptrs;
    int _tfpecode;
    struct threadmbcinfostruct *ptmbcinfo;
    struct threadlocaleinfostruct *ptlocinfo;
    int _ownlocale;
    ulong _NLG_dwCode;
    void *_terminate;
    void *_unexpected;
    void *_translator;
    void *_purecall;
    void *_curexception;
    void *_curcontext;
    int _ProcessingThrow;
    void *_curexcspec;
    void *_pFrameInfoChain;
    struct setloc_struct _setloc_data;
    void *_reserved1;
    void *_reserved2;
    void *_reserved3;
    void *_reserved4;
    void *_reserved5;
    int _cxxReThrow;
    ulong __initDomain;
    int _initapartment;
};

typedef struct CSceneVehicleMaterialGroup CSceneVehicleMaterialGroup, *PCSceneVehicleMaterialGroup;

struct CSceneVehicleMaterialGroup {
    undefined field0_0x0;
};

typedef struct SDelayedToSortPass SDelayedToSortPass, *PSDelayedToSortPass;

struct SDelayedToSortPass {
    undefined field0_0x0;
};

typedef struct SNetStateBuffer SNetStateBuffer, *PSNetStateBuffer;

struct SNetStateBuffer {
    undefined field0_0x0;
};

typedef struct CMotionTeamAction CMotionTeamAction, *PCMotionTeamAction;

struct CMotionTeamAction {
    undefined field0_0x0;
};

typedef struct CGameControlCardNetTeamInfo CGameControlCardNetTeamInfo, *PCGameControlCardNetTeamInfo;

struct CGameControlCardNetTeamInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerScore::SLadderMatchResult> CFastBuffer<struct_CGamePlayerScore::SLadderMatchResult>, *PCFastBuffer<struct_CGamePlayerScore::SLadderMatchResult>;

struct CFastBuffer<struct_CGamePlayerScore::SLadderMatchResult> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CAudioSound*> CFastBuffer<class_CAudioSound*>, *PCFastBuffer<class_CAudioSound*>;

struct CFastBuffer<class_CAudioSound*> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SZoneGenealogy*> CFastArray<struct_SZoneGenealogy*>, *PCFastArray<struct_SZoneGenealogy*>;

struct CFastArray<struct_SZoneGenealogy*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaNetwork SMwParamInfos_CTrackManiaNetwork, *PSMwParamInfos_CTrackManiaNetwork;

struct SMwParamInfos_CTrackManiaNetwork {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugModelTree>_> CFastBuffer<class_CMwNodRef<class_CPlugModelTree>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugModelTree>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugModelTree>_> {
    undefined field0_0x0;
};

typedef struct CNetClientInfo CNetClientInfo, *PCNetClientInfo;

struct CNetClientInfo {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CPlugFileFidContainer::SFolderDesc> CFastBuffer<struct_CPlugFileFidContainer::SFolderDesc>, *PCFastBuffer<struct_CPlugFileFidContainer::SFolderDesc>;

struct CFastBuffer<struct_CPlugFileFidContainer::SFolderDesc> {
    undefined field0_0x0;
};

typedef struct SAllVisualTravel SAllVisualTravel, *PSAllVisualTravel;

struct SAllVisualTravel {
    undefined field0_0x0;
};

typedef struct CPlugVisualLines CPlugVisualLines, *PCPlugVisualLines;

struct CPlugVisualLines {
    undefined field0_0x0;
};

typedef struct CHmsSoundSource CHmsSoundSource, *PCHmsSoundSource;

struct CHmsSoundSource {
    undefined field0_0x0;
};

typedef struct Replicator Replicator, *PReplicator;

struct Replicator {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLadderScoresComputer SMwParamInfos_CGameLadderScoresComputer, *PSMwParamInfos_CGameLadderScoresComputer;

struct SMwParamInfos_CGameLadderScoresComputer {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CNetMasterServerRequest> CFastBufferRef<class_CNetMasterServerRequest>, *PCFastBufferRef<class_CNetMasterServerRequest>;

struct CFastBufferRef<class_CNetMasterServerRequest> {
    undefined field0_0x0;
};

typedef struct TiXmlNode TiXmlNode, *PTiXmlNode;

struct TiXmlNode {
    undefined field0_0x0;
};

typedef struct SMenuChooseChallenge SMenuChooseChallenge, *PSMenuChooseChallenge;

struct SMenuChooseChallenge {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncCurves2Real SMwParamInfos_CFuncCurves2Real, *PSMwParamInfos_CFuncCurves2Real;

struct SMwParamInfos_CFuncCurves2Real {
    undefined field0_0x0;
};

typedef enum EFilterAnisoQ {
} EFilterAnisoQ;

typedef struct SVisualId SVisualId, *PSVisualId;

struct SVisualId {
    undefined field0_0x0;
};

typedef struct SDeprecatedPlayerCampaignSkillScore SDeprecatedPlayerCampaignSkillScore, *PSDeprecatedPlayerCampaignSkillScore;

struct SDeprecatedPlayerCampaignSkillScore {
    undefined field0_0x0;
};

typedef enum EAlignVertical {
} EAlignVertical;

typedef enum ETextureFormat {
} ETextureFormat;

typedef struct SMwParamInfos_CSceneVehicleBallTuning SMwParamInfos_CSceneVehicleBallTuning, *PSMwParamInfos_CSceneVehicleBallTuning;

struct SMwParamInfos_CSceneVehicleBallTuning {
    undefined field0_0x0;
};

typedef struct CGameControlDataType CGameControlDataType, *PCGameControlDataType;

struct CGameControlDataType {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>, *PCFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>;

struct CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarVec2 CMwCmdScriptVarVec2, *PCMwCmdScriptVarVec2;

struct CMwCmdScriptVarVec2 {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarVec3 CMwCmdScriptVarVec3, *PCMwCmdScriptVarVec3;

struct CMwCmdScriptVarVec3 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_OBJTri> CFastBuffer<struct_OBJTri>, *PCFastBuffer<struct_OBJTri>;

struct CFastBuffer<struct_OBJTri> {
    undefined field0_0x0;
};

typedef enum ECampaignType {
} ECampaignType;

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    uint OffsetToData;
    uint Size;
    uint CodePage;
    uint Reserved;
};

typedef struct SMwParamInfos_CHmsPoc SMwParamInfos_CHmsPoc, *PSMwParamInfos_CHmsPoc;

struct SMwParamInfos_CHmsPoc {
    undefined field0_0x0;
};

typedef struct CMotionSkelBlender CMotionSkelBlender, *PCMotionSkelBlender;

struct CMotionSkelBlender {
    undefined field0_0x0;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

struct IMAGE_OPTIONAL_HEADER32 {
    uint16.conflict Magic;
    uint8 MajorLinkerVersion;
    uint8 MinorLinkerVersion;
    uint SizeOfCode;
    uint SizeOfInitializedData;
    uint SizeOfUninitializedData;
    uint AddressOfEntryPoint;
    uint BaseOfCode;
    uint BaseOfData;
    wchar32 *ImageBase;
    uint SectionAlignment;
    uint FileAlignment;
    uint16.conflict MajorOperatingSystemVersion;
    uint16.conflict MinorOperatingSystemVersion;
    uint16.conflict MajorImageVersion;
    uint16.conflict MinorImageVersion;
    uint16.conflict MajorSubsystemVersion;
    uint16.conflict MinorSubsystemVersion;
    uint Win32VersionValue;
    uint SizeOfImage;
    uint SizeOfHeaders;
    uint CheckSum;
    uint16.conflict Subsystem;
    uint16.conflict DllCharacteristics;
    uint SizeOfStackReserve;
    uint SizeOfStackCommit;
    uint SizeOfHeapReserve;
    uint SizeOfHeapCommit;
    uint LoaderFlags;
    uint NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

struct IMAGE_FILE_HEADER {
    uint16.conflict Machine;
    uint16.conflict NumberOfSections;
    uint TimeDateStamp;
    uint PointerToSymbolTable;
    uint NumberOfSymbols;
    uint16.conflict SizeOfOptionalHeader;
    uint16.conflict Characteristics;
};

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct _D3DPRESENT_PARAMETERS_ _D3DPRESENT_PARAMETERS_, *P_D3DPRESENT_PARAMETERS_;

struct _D3DPRESENT_PARAMETERS_ {
    undefined field0_0x0;
};

typedef struct GmBoxAligned GmBoxAligned, *PGmBoxAligned;

struct GmBoxAligned {
    undefined field0_0x0;
};

typedef enum EErrorType {
} EErrorType;

typedef struct GmFrustum GmFrustum, *PGmFrustum;

struct GmFrustum {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_TIME_ZONE_INFORMATION - /winbase.h/_TIME_ZONE_INFORMATION */

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockCameraCustom::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameAdvertisingRadial::SCellDesc> CFastBuffer<struct_CGameAdvertisingRadial::SCellDesc>, *PCFastBuffer<struct_CGameAdvertisingRadial::SCellDesc>;

struct CFastBuffer<struct_CGameAdvertisingRadial::SCellDesc> {
    undefined field0_0x0;
};

typedef enum EPlugGpuPipeline {
} EPlugGpuPipeline;

typedef struct SStdGpuMask SStdGpuMask, *PSStdGpuMask;

struct SStdGpuMask {
    undefined field0_0x0;
};

typedef struct SHmsPhysicalCollision SHmsPhysicalCollision, *PSHmsPhysicalCollision;

struct SHmsPhysicalCollision {
    undefined field0_0x0;
};

typedef struct CNetFileTransferDownload CNetFileTransferDownload, *PCNetFileTransferDownload;

struct CNetFileTransferDownload {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CMotion*> CFastArray<class_CMotion*>, *PCFastArray<class_CMotion*>;

struct CFastArray<class_CMotion*> {
    undefined field0_0x0;
};

typedef enum EMwParamType {
} EMwParamType;

typedef struct CBoatSailState CBoatSailState, *PCBoatSailState;

struct CBoatSailState {
    undefined field0_0x0;
};

typedef struct CHmsPackLightMapMood CHmsPackLightMapMood, *PCHmsPackLightMapMood;

struct CHmsPackLightMapMood {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CCrystalFace*> CFastBuffer<class_CCrystalFace*>, *PCFastBuffer<class_CCrystalFace*>;

struct CFastBuffer<class_CCrystalFace*> {
    undefined field0_0x0;
};

typedef struct SOldTriggerZone SOldTriggerZone, *PSOldTriggerZone;

struct SOldTriggerZone {
    undefined field0_0x0;
};

typedef struct CMwCmdExpStringConcat CMwCmdExpStringConcat, *PCMwCmdExpStringConcat;

struct CMwCmdExpStringConcat {
    undefined field0_0x0;
};

typedef enum ETerrain {
} ETerrain;

typedef struct CFastBuffer<struct_CMotionManagerParticles::SPartGroup> CFastBuffer<struct_CMotionManagerParticles::SPartGroup>, *PCFastBuffer<struct_CMotionManagerParticles::SPartGroup>;

struct CFastBuffer<struct_CMotionManagerParticles::SPartGroup> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CControlListItem>_> CFastBuffer<class_CMwNodRef<class_CControlListItem>_>, *PCFastBuffer<class_CMwNodRef<class_CControlListItem>_>;

struct CFastBuffer<class_CMwNodRef<class_CControlListItem>_> {
    undefined field0_0x0;
};

typedef struct CFastCallback2P<unsigned_long,unsigned_long> CFastCallback2P<unsigned_long,unsigned_long>, *PCFastCallback2P<unsigned_long,unsigned_long>;

struct CFastCallback2P<unsigned_long,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CPlugViewDepLocator CPlugViewDepLocator, *PCPlugViewDepLocator;

struct CPlugViewDepLocator {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_union_530 - /winbase.h/_union_530 */

typedef struct CMwNodRef<class_CGameControlGridCtnChallengeGroup> CMwNodRef<class_CGameControlGridCtnChallengeGroup>, *PCMwNodRef<class_CGameControlGridCtnChallengeGroup>;

struct CMwNodRef<class_CGameControlGridCtnChallengeGroup> {
    undefined field0_0x0;
};

typedef struct GmField2Base GmField2Base, *PGmField2Base;

struct GmField2Base {
    undefined field0_0x0;
};

typedef struct SStringParamInt SStringParamInt, *PSStringParamInt;

struct SStringParamInt {
    undefined field0_0x0;
};

typedef struct CPlugTreeLight CPlugTreeLight, *PCPlugTreeLight;

struct CPlugTreeLight {
    undefined field0_0x0;
};

typedef struct CMwCmdExpSupEgal CMwCmdExpSupEgal, *PCMwCmdExpSupEgal;

struct CMwCmdExpSupEgal {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_union_518 - /winbase.h/_union_518 */

typedef struct CSceneExtraFlockingCharacters CSceneExtraFlockingCharacters, *PCSceneExtraFlockingCharacters;

struct CSceneExtraFlockingCharacters {
    undefined field0_0x0;
};

typedef struct CMwCmdContinue CMwCmdContinue, *PCMwCmdContinue;

struct CMwCmdContinue {
    undefined field0_0x0;
};

typedef struct CGameNetServer CGameNetServer, *PCGameNetServer;

struct CGameNetServer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SRecordUnit> CFastBuffer<struct_SRecordUnit>, *PCFastBuffer<struct_SRecordUnit>;

struct CFastBuffer<struct_SRecordUnit> {
    undefined field0_0x0;
};

typedef struct CHmsCorpus CHmsCorpus, *PCHmsCorpus;

struct CHmsCorpus {
    undefined field0_0x0;
};

typedef struct SPlugFaceCull SPlugFaceCull, *PSPlugFaceCull;

struct SPlugFaceCull {
    undefined field0_0x0;
};

typedef enum EState {
} EState;

typedef struct CStridedArray<float> CStridedArray<float>, *PCStridedArray<float>;

struct CStridedArray<float> {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceNet CTrackManiaRaceNet, *PCTrackManiaRaceNet;

struct CTrackManiaRaceNet {
    undefined field0_0x0;
};

typedef struct CControlUiRange CControlUiRange, *PCControlUiRange;

struct CControlUiRange {
    undefined field0_0x0;
};

typedef struct CMotionManagerMeteo CMotionManagerMeteo, *PCMotionManagerMeteo;

struct CMotionManagerMeteo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTeamActionInfo SMwParamInfos_CMotionTeamActionInfo, *PSMwParamInfos_CMotionTeamActionInfo;

struct SMwParamInfos_CMotionTeamActionInfo {
    undefined field0_0x0;
};

typedef union GxBGRAColor.conflict GxBGRAColor.conflict, *PGxBGRAColor.conflict;

union GxBGRAColor.conflict {
};

typedef struct SMwParamInfos_CGameCtnMenus SMwParamInfos_CGameCtnMenus, *PSMwParamInfos_CGameCtnMenus;

struct SMwParamInfos_CGameCtnMenus {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnDecorationMood SMwParamInfos_CGameCtnDecorationMood, *PSMwParamInfos_CGameCtnDecorationMood;

struct SMwParamInfos_CGameCtnDecorationMood {
    undefined field0_0x0;
};

typedef struct CSceneVehicleStruct CSceneVehicleStruct, *PCSceneVehicleStruct;

struct CSceneVehicleStruct {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlContainer SMwParamInfos_CControlContainer, *PSMwParamInfos_CControlContainer;

struct SMwParamInfos_CControlContainer {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockCameraOrbital::SKeyVal> {
    undefined field0_0x0;
};

typedef struct SKeyVal SKeyVal, *PSKeyVal;

struct SKeyVal {
    undefined field0_0x0;
};

typedef struct vector<unsigned_short,class_std::allocator<unsigned_short>_> vector<unsigned_short,class_std::allocator<unsigned_short>_>, *Pvector<unsigned_short,class_std::allocator<unsigned_short>_>;

struct vector<unsigned_short,class_std::allocator<unsigned_short>_> {
    undefined field0_0x0;
};

typedef struct CMotionTrackTree CMotionTrackTree, *PCMotionTrackTree;

struct CMotionTrackTree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlScores SMwParamInfos_CTrackManiaControlScores, *PSMwParamInfos_CTrackManiaControlScores;

struct SMwParamInfos_CTrackManiaControlScores {
    undefined field0_0x0;
};

typedef enum ESceneMeteo_WindStrength {
} ESceneMeteo_WindStrength;

typedef struct CSysFidNodRef<class_CPlugShaderApply> CSysFidNodRef<class_CPlugShaderApply>, *PCSysFidNodRef<class_CPlugShaderApply>;

struct CSysFidNodRef<class_CPlugShaderApply> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugModelFur SMwParamInfos_CPlugModelFur, *PSMwParamInfos_CPlugModelFur;

struct SMwParamInfos_CPlugModelFur {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatTeamMateActionDesc SMwParamInfos_CBoatTeamMateActionDesc, *PSMwParamInfos_CBoatTeamMateActionDesc;

struct SMwParamInfos_CBoatTeamMateActionDesc {
    undefined field0_0x0;
};

typedef struct CSceneFxBloom CSceneFxBloom, *PCSceneFxBloom;

struct CSceneFxBloom {
    undefined field0_0x0;
};

typedef enum EMatchOver {
} EMatchOver;

typedef struct SMwParamInfos_CNetServerInfo SMwParamInfos_CNetServerInfo, *PSMwParamInfos_CNetServerInfo;

struct SMwParamInfos_CNetServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSoundEngine SMwParamInfos_CPlugSoundEngine, *PSMwParamInfos_CPlugSoundEngine;

struct SMwParamInfos_CPlugSoundEngine {
    undefined field0_0x0;
};

typedef struct SCameraPreset SCameraPreset, *PSCameraPreset;

struct SCameraPreset {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfoClassic SMwParamInfos_CGameCtnBlockInfoClassic, *PSMwParamInfos_CGameCtnBlockInfoClassic;

struct SMwParamInfos_CGameCtnBlockInfoClassic {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemConfig SMwParamInfos_CSystemConfig, *PSMwParamInfos_CSystemConfig;

struct SMwParamInfos_CSystemConfig {
    undefined field0_0x0;
};

typedef struct CMotions CMotions, *PCMotions;

struct CMotions {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlColorChooser SMwParamInfos_CControlColorChooser, *PSMwParamInfos_CControlColorChooser;

struct SMwParamInfos_CControlColorChooser {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlockCameraSimple CGameCtnMediaBlockCameraSimple, *PCGameCtnMediaBlockCameraSimple;

struct CGameCtnMediaBlockCameraSimple {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneLocation SMwParamInfos_CSceneLocation, *PSMwParamInfos_CSceneLocation;

struct SMwParamInfos_CSceneLocation {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrackVisual SMwParamInfos_CMotionTrackVisual, *PSMwParamInfos_CMotionTrackVisual;

struct SMwParamInfos_CMotionTrackVisual {
    undefined field0_0x0;
};

typedef struct SSel SSel, *PSSel;

struct SSel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapPackElem SMwParamInfos_CPlugBitmapPackElem, *PSMwParamInfos_CPlugBitmapPackElem;

struct SMwParamInfos_CPlugBitmapPackElem {
    undefined field0_0x0;
};

typedef struct CDx9StateBlock CDx9StateBlock, *PCDx9StateBlock;

struct CDx9StateBlock {
    undefined field0_0x0;
};

typedef struct SPlayerTechnicalParametrization SPlayerTechnicalParametrization, *PSPlayerTechnicalParametrization;

struct SPlayerTechnicalParametrization {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,17,unsigned_long> CFixedArray<unsigned_long,17,unsigned_long>, *PCFixedArray<unsigned_long,17,unsigned_long>;

struct CFixedArray<unsigned_long,17,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneObject SMwParamInfos_CSceneObject, *PSMwParamInfos_CSceneObject;

struct SMwParamInfos_CSceneObject {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CControlButton*> CFastBuffer<class_CControlButton*>, *PCFastBuffer<class_CControlButton*>;

struct CFastBuffer<class_CControlButton*> {
    undefined field0_0x0;
};

typedef struct CNetIPC CNetIPC, *PCNetIPC;

struct CNetIPC {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnNetwork SMwParamInfos_CGameCtnNetwork, *PSMwParamInfos_CGameCtnNetwork;

struct SMwParamInfos_CGameCtnNetwork {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerScoresShooter SMwParamInfos_CGamePlayerScoresShooter, *PSMwParamInfos_CGamePlayerScoresShooter;

struct SMwParamInfos_CGamePlayerScoresShooter {
    undefined field0_0x0;
};

typedef struct CPlugFileGpuFx CPlugFileGpuFx, *PCPlugFileGpuFx;

struct CPlugFileGpuFx {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameAdvertising::SImpressionAxe> CFastBuffer<struct_CGameAdvertising::SImpressionAxe>, *PCFastBuffer<struct_CGameAdvertising::SImpressionAxe>;

struct CFastBuffer<struct_CGameAdvertising::SImpressionAxe> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SShaderBlurDepth> CFastBuffer<struct_CVisionViewportDx9::SShaderBlurDepth>, *PCFastBuffer<struct_CVisionViewportDx9::SShaderBlurDepth>;

struct CFastBuffer<struct_CVisionViewportDx9::SShaderBlurDepth> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdentEnum CMwCmdAffectIdentEnum, *PCMwCmdAffectIdentEnum;

struct CMwCmdAffectIdentEnum {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameManiaNetResource SMwParamInfos_CGameManiaNetResource, *PSMwParamInfos_CGameManiaNetResource;

struct SMwParamInfos_CGameManiaNetResource {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarEnum SMwParamInfos_CMwCmdScriptVarEnum, *PSMwParamInfos_CMwCmdScriptVarEnum;

struct SMwParamInfos_CMwCmdScriptVarEnum {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastStringIntForArray> CFastBuffer<class_CFastStringIntForArray>, *PCFastBuffer<class_CFastStringIntForArray>;

struct CFastBuffer<class_CFastStringIntForArray> {
    undefined field0_0x0;
};

typedef struct SGroup SGroup, *PSGroup;

struct SGroup {
    undefined field0_0x0;
};

typedef struct CGameNetOnlineMessage CGameNetOnlineMessage, *PCGameNetOnlineMessage;

struct CGameNetOnlineMessage {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsZoneElem SMwParamInfos_CHmsZoneElem, *PSMwParamInfos_CHmsZoneElem;

struct SMwParamInfos_CHmsZoneElem {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyRock SMwParamInfos_CSceneToyRock, *PSMwParamInfos_CSceneToyRock;

struct SMwParamInfos_CSceneToyRock {
    undefined field0_0x0;
};

typedef struct CSysFidNodRef<class_CPlugMaterial> CSysFidNodRef<class_CPlugMaterial>, *PCSysFidNodRef<class_CPlugMaterial>;

struct CSysFidNodRef<class_CPlugMaterial> {
    undefined field0_0x0;
};

typedef struct SServerWithBuddies SServerWithBuddies, *PSServerWithBuddies;

struct SServerWithBuddies {
    undefined field0_0x0;
};

typedef struct SShaderMaterialField SShaderMaterialField, *PSShaderMaterialField;

struct SShaderMaterialField {
    undefined field0_0x0;
};

typedef struct CAudioEngine CAudioEngine, *PCAudioEngine;

struct CAudioEngine {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileOggVorbis SMwParamInfos_CPlugFileOggVorbis, *PSMwParamInfos_CPlugFileOggVorbis;

struct SMwParamInfos_CPlugFileOggVorbis {
    undefined field0_0x0;
};

typedef struct SHmsCameraLocation SHmsCameraLocation, *PSHmsCameraLocation;

struct SHmsCameraLocation {
    undefined field0_0x0;
};

typedef struct SRequirement SRequirement, *PSRequirement;

struct SRequirement {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnApp::SLightMapInfo> CFastBuffer<struct_CGameCtnApp::SLightMapInfo>, *PCFastBuffer<struct_CGameCtnApp::SLightMapInfo>;

struct CFastBuffer<struct_CGameCtnApp::SLightMapInfo> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3Add CMwCmdExpVec3Add, *PCMwCmdExpVec3Add;

struct CMwCmdExpVec3Add {
    undefined field0_0x0;
};

typedef struct TiXmlBase TiXmlBase, *PTiXmlBase;

struct TiXmlBase {
    undefined field0_0x0;
};

typedef enum EClear {
} EClear;

typedef struct SMwParamInfos_CFuncEnum SMwParamInfos_CFuncEnum, *PSMwParamInfos_CFuncEnum;

struct SMwParamInfos_CFuncEnum {
    undefined field0_0x0;
};

typedef struct CPlugSurfaceMaterialData CPlugSurfaceMaterialData, *PCPlugSurfaceMaterialData;

struct CPlugSurfaceMaterialData {
    undefined field0_0x0;
};

typedef struct CControlListMap CControlListMap, *PCControlListMap;

struct CControlListMap {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemKeyboard SMwParamInfos_CSystemKeyboard, *PSMwParamInfos_CSystemKeyboard;

struct SMwParamInfos_CSystemKeyboard {
    undefined field0_0x0;
};

typedef struct CCallbackSceneToyBroomStickComputeForces CCallbackSceneToyBroomStickComputeForces, *PCCallbackSceneToyBroomStickComputeForces;

struct CCallbackSceneToyBroomStickComputeForces {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeLight SMwParamInfos_CPlugTreeLight, *PSMwParamInfos_CPlugTreeLight;

struct SMwParamInfos_CPlugTreeLight {
    undefined field0_0x0;
};

typedef struct SHeaderCollectorFolders SHeaderCollectorFolders, *PSHeaderCollectorFolders;

struct SHeaderCollectorFolders {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/IMAGE_DOS_HEADER - /DOS/IMAGE_DOS_HEADER */

typedef struct SMwParamInfos_CPlugShaderGeneric SMwParamInfos_CPlugShaderGeneric, *PSMwParamInfos_CPlugShaderGeneric;

struct SMwParamInfos_CPlugShaderGeneric {
    undefined field0_0x0;
};

typedef struct SBlockEditInfo SBlockEditInfo, *PSBlockEditInfo;

struct SBlockEditInfo {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CPlugTree*,struct_CHmsPicker::SCorpusCat> CFastBufferCat<class_CPlugTree*,struct_CHmsPicker::SCorpusCat>, *PCFastBufferCat<class_CPlugTree*,struct_CHmsPicker::SCorpusCat>;

struct CFastBufferCat<class_CPlugTree*,struct_CHmsPicker::SCorpusCat> {
    undefined field0_0x0;
};

typedef struct CEditionData CEditionData, *PCEditionData;

struct CEditionData {
    undefined field0_0x0;
};

typedef struct GmLine2 GmLine2, *PGmLine2;

struct GmLine2 {
    undefined field0_0x0;
};

typedef struct xmlrpc_client_transport xmlrpc_client_transport, *Pxmlrpc_client_transport;

struct xmlrpc_client_transport {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmap SMwParamInfos_CPlugBitmap, *PSMwParamInfos_CPlugBitmap;

struct SMwParamInfos_CPlugBitmap {
    undefined field0_0x0;
};

typedef enum EMsgGameConnectionType {
} EMsgGameConnectionType;

typedef struct SMwParamInfos_CPlugBitmapRenderSolid SMwParamInfos_CPlugBitmapRenderSolid, *PSMwParamInfos_CPlugBitmapRenderSolid;

struct SMwParamInfos_CPlugBitmapRenderSolid {
    undefined field0_0x0;
};

typedef struct SPlayerMobil SPlayerMobil, *PSPlayerMobil;

struct SPlayerMobil {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyTrain SMwParamInfos_CSceneToyTrain, *PSMwParamInfos_CSceneToyTrain;

struct SMwParamInfos_CSceneToyTrain {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneMood>_> CFastBuffer<class_CMwNodRef<class_CSceneMood>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneMood>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneMood>_> {
    undefined field0_0x0;
};

typedef enum EInputsMode {
} EInputsMode;

typedef struct SPlayerInfosForTargetting SPlayerInfosForTargetting, *PSPlayerInfosForTargetting;

struct SPlayerInfosForTargetting {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncTreeRotate SMwParamInfos_CFuncTreeRotate, *PSMwParamInfos_CFuncTreeRotate;

struct SMwParamInfos_CFuncTreeRotate {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockText SMwParamInfos_CGameCtnMediaBlockText, *PSMwParamInfos_CGameCtnMediaBlockText;

struct SMwParamInfos_CGameCtnMediaBlockText {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnChallengeParameters SMwParamInfos_CGameCtnChallengeParameters, *PSMwParamInfos_CGameCtnChallengeParameters;

struct SMwParamInfos_CGameCtnChallengeParameters {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SModule> CFastArray<struct_SModule>, *PCFastArray<struct_SModule>;

struct CFastArray<struct_SModule> {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<class_CPlugFileSndGen*> CFastBufferWheel<class_CPlugFileSndGen*>, *PCFastBufferWheel<class_CPlugFileSndGen*>;

struct CFastBufferWheel<class_CPlugFileSndGen*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileAvi SMwParamInfos_CPlugFileAvi, *PSMwParamInfos_CPlugFileAvi;

struct SMwParamInfos_CPlugFileAvi {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncGroup SMwParamInfos_CFuncGroup, *PSMwParamInfos_CFuncGroup;

struct SMwParamInfos_CFuncGroup {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceAnalyzer CTrackManiaRaceAnalyzer, *PCTrackManiaRaceAnalyzer;

struct CTrackManiaRaceAnalyzer {
    undefined field0_0x0;
};

typedef struct CSceneLocation CSceneLocation, *PCSceneLocation;

struct CSceneLocation {
    undefined field0_0x0;
};

typedef struct GxTexCoordSet GxTexCoordSet, *PGxTexCoordSet;

struct GxTexCoordSet {
    undefined field0_0x0;
};

typedef struct SOctreeLowMem_BuildParam SOctreeLowMem_BuildParam, *PSOctreeLowMem_BuildParam;

struct SOctreeLowMem_BuildParam {
    undefined field0_0x0;
};

typedef struct CSceneToyFxDynaBump CSceneToyFxDynaBump, *PCSceneToyFxDynaBump;

struct CSceneToyFxDynaBump {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockMusicEffect::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,39,unsigned_long> CFixedArray<unsigned_long,39,unsigned_long>, *PCFixedArray<unsigned_long,39,unsigned_long>;

struct CFixedArray<unsigned_long,39,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CCtnMediaBlockEventTrackMania CCtnMediaBlockEventTrackMania, *PCCtnMediaBlockEventTrackMania;

struct CCtnMediaBlockEventTrackMania {
    undefined field0_0x0;
};

typedef struct CNetFileTransferForm CNetFileTransferForm, *PCNetFileTransferForm;

struct CNetFileTransferForm {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFuncTreeSubVisualSequence*> CFastBuffer<class_CFuncTreeSubVisualSequence*>, *PCFastBuffer<class_CFuncTreeSubVisualSequence*>;

struct CFastBuffer<class_CFuncTreeSubVisualSequence*> {
    undefined field0_0x0;
};

typedef struct CControlDisplayGraph CControlDisplayGraph, *PCControlDisplayGraph;

struct CControlDisplayGraph {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_TiXmlElement*> CFastBuffer<class_TiXmlElement*>, *PCFastBuffer<class_TiXmlElement*>;

struct CFastBuffer<class_TiXmlElement*> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpOr CMwCmdExpOr, *PCMwCmdExpOr;

struct CMwCmdExpOr {
    undefined field0_0x0;
};

typedef struct CNetClient CNetClient, *PCNetClient;

struct CNetClient {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapPacker SMwParamInfos_CPlugBitmapPacker, *PSMwParamInfos_CPlugBitmapPacker;

struct SMwParamInfos_CPlugBitmapPacker {
    undefined field0_0x0;
};

typedef struct SPlugUrlLink SPlugUrlLink, *PSPlugUrlLink;

struct SPlugUrlLink {
    undefined field0_0x0;
};

typedef struct SPack SPack, *PSPack;

struct SPack {
    undefined field0_0x0;
};

typedef struct CMwParamFastBufferCat<class_CMwParamBool> CMwParamFastBufferCat<class_CMwParamBool>, *PCMwParamFastBufferCat<class_CMwParamBool>;

struct CMwParamFastBufferCat<class_CMwParamBool> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockCameraSimple::SKeyVal> {
    undefined field0_0x0;
};

typedef struct CLoaderFile CLoaderFile, *PCLoaderFile;

struct CLoaderFile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsCorpus SMwParamInfos_CHmsCorpus, *PSMwParamInfos_CHmsCorpus;

struct SMwParamInfos_CHmsCorpus {
    undefined field0_0x0;
};

typedef struct SModule SModule, *PSModule;

struct SModule {
    undefined field0_0x0;
};

typedef struct SBuddyAsker SBuddyAsker, *PSBuddyAsker;

struct SBuddyAsker {
    undefined field0_0x0;
};

typedef struct CMwParamFastBuffer<class_CMwParamClass> CMwParamFastBuffer<class_CMwParamClass>, *PCMwParamFastBuffer<class_CMwParamClass>;

struct CMwParamFastBuffer<class_CMwParamClass> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugModelLodMesh>_> CFastBuffer<class_CMwNodRef<class_CPlugModelLodMesh>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugModelLodMesh>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugModelLodMesh>_> {
    undefined field0_0x0;
};

typedef struct GmQuadTree<struct_SQuadTreeMeshUv> GmQuadTree<struct_SQuadTreeMeshUv>, *PGmQuadTree<struct_SQuadTreeMeshUv>;

struct GmQuadTree<struct_SQuadTreeMeshUv> {
    undefined field0_0x0;
};

typedef struct CLoader CLoader, *PCLoader;

struct CLoader {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarClass CMwCmdScriptVarClass, *PCMwCmdScriptVarClass;

struct CMwCmdScriptVarClass {
    undefined field0_0x0;
};

typedef enum EMakeDir {
} EMakeDir;

typedef struct CGameControlCardCalendarEvent CGameControlCardCalendarEvent, *PCGameControlCardCalendarEvent;

struct CGameControlCardCalendarEvent {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugDecoratorTree>_> CFastBuffer<class_CMwNodRef<class_CPlugDecoratorTree>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugDecoratorTree>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugDecoratorTree>_> {
    undefined field0_0x0;
};

typedef struct SVisualLocation SVisualLocation, *PSVisualLocation;

struct SVisualLocation {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdSwitchType SMwParamInfos_CMwCmdSwitchType, *PSMwParamInfos_CMwCmdSwitchType;

struct SMwParamInfos_CMwCmdSwitchType {
    undefined field0_0x0;
};

typedef struct CLoadGeomDynaSprite CLoadGeomDynaSprite, *PCLoadGeomDynaSprite;

struct CLoadGeomDynaSprite {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CInputDeviceDx8Pad::SObjectDesc> CFastBuffer<struct_CInputDeviceDx8Pad::SObjectDesc>, *PCFastBuffer<struct_CInputDeviceDx8Pad::SObjectDesc>;

struct CFastBuffer<struct_CInputDeviceDx8Pad::SObjectDesc> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugShader> CMwNodRef<class_CPlugShader>, *PCMwNodRef<class_CPlugShader>;

struct CMwNodRef<class_CPlugShader> {
    undefined field0_0x0;
};

typedef struct SComputeShadowContext SComputeShadowContext, *PSComputeShadowContext;

struct SComputeShadowContext {
    undefined field0_0x0;
};

typedef struct CTrackManiaIntro CTrackManiaIntro, *PCTrackManiaIntro;

struct CTrackManiaIntro {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionWeather SMwParamInfos_CMotionWeather, *PSMwParamInfos_CMotionWeather;

struct SMwParamInfos_CMotionWeather {
    undefined field0_0x0;
};

typedef struct CMwCmdFiber CMwCmdFiber, *PCMwCmdFiber;

struct CMwCmdFiber {
    undefined field0_0x0;
};

typedef struct CSceneVehicleBall CSceneVehicleBall, *PCSceneVehicleBall;

struct CSceneVehicleBall {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugModelMesh> CMwNodRef<class_CPlugModelMesh>, *PCMwNodRef<class_CPlugModelMesh>;

struct CMwNodRef<class_CPlugModelMesh> {
    undefined field0_0x0;
};

typedef struct CConstArray<struct_SHmsItem_CallbackSortCustom_Elem> CConstArray<struct_SHmsItem_CallbackSortCustom_Elem>, *PCConstArray<struct_SHmsItem_CallbackSortCustom_Elem>;

struct CConstArray<struct_SHmsItem_CallbackSortCustom_Elem> {
    undefined field0_0x0;
};

typedef struct CIPCSharedMem CIPCSharedMem, *PCIPCSharedMem;

struct CIPCSharedMem {
    undefined field0_0x0;
};

typedef struct GxMesh GxMesh, *PGxMesh;

struct GxMesh {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugVisual*> CFastBuffer<class_CPlugVisual*>, *PCFastBuffer<class_CPlugVisual*>;

struct CFastBuffer<class_CPlugVisual*> {
    undefined field0_0x0;
};

typedef struct CVisionViewportNull CVisionViewportNull, *PCVisionViewportNull;

struct CVisionViewportNull {
    undefined field0_0x0;
};

typedef enum EHemiLayout {
} EHemiLayout;

typedef struct SMwParamInfos_CGameControlCardLeague SMwParamInfos_CGameControlCardLeague, *PSMwParamInfos_CGameControlCardLeague;

struct SMwParamInfos_CGameControlCardLeague {
    undefined field0_0x0;
};

typedef struct SPointInTri SPointInTri, *PSPointInTri;

struct SPointInTri {
    undefined field0_0x0;
};

typedef struct CMwCmdExpMult CMwCmdExpMult, *PCMwCmdExpMult;

struct CMwCmdExpMult {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlMediaPlayer SMwParamInfos_CControlMediaPlayer, *PSMwParamInfos_CControlMediaPlayer;

struct SMwParamInfos_CControlMediaPlayer {
    undefined field0_0x0;
};

typedef struct CSystemFidBuffer CSystemFidBuffer, *PCSystemFidBuffer;

struct CSystemFidBuffer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncWeather SMwParamInfos_CFuncWeather, *PSMwParamInfos_CFuncWeather;

struct SMwParamInfos_CFuncWeather {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParamBool CMwCmdAffectParamBool, *PCMwCmdAffectParamBool;

struct CMwCmdAffectParamBool {
    undefined field0_0x0;
};

typedef struct _DDPIXELFORMAT _DDPIXELFORMAT, *P_DDPIXELFORMAT;

struct _DDPIXELFORMAT {
    undefined field0_0x0;
};

typedef enum ESnowKind {
} ESnowKind;

typedef struct CFuncVisualBlendShapeSequence CFuncVisualBlendShapeSequence, *PCFuncVisualBlendShapeSequence;

struct CFuncVisualBlendShapeSequence {
    undefined field0_0x0;
};

typedef struct CGameAnalyzerContext CGameAnalyzerContext, *PCGameAnalyzerContext;

struct CGameAnalyzerContext {
    undefined field0_0x0;
};

typedef struct timeval timeval, *Ptimeval;

struct timeval {
    long tv_sec;
    long tv_usec;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferPool>_> CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferPool>_>, *PCFastBuffer<class_CMwNodRef<class_CGameRemoteBufferPool>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameRemoteBufferPool>_> {
    undefined field0_0x0;
};

typedef enum ESolidQuality {
} ESolidQuality;

typedef struct SMwParamInfos_CControlImage SMwParamInfos_CControlImage, *PSMwParamInfos_CControlImage;

struct SMwParamInfos_CControlImage {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlFrame SMwParamInfos_CControlFrame, *PSMwParamInfos_CControlFrame;

struct SMwParamInfos_CControlFrame {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaRaceNetTimeAttack SMwParamInfos_CTrackManiaRaceNetTimeAttack, *PSMwParamInfos_CTrackManiaRaceNetTimeAttack;

struct SMwParamInfos_CTrackManiaRaceNetTimeAttack {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarString CMwCmdScriptVarString, *PCMwCmdScriptVarString;

struct CMwCmdScriptVarString {
    undefined field0_0x0;
};

typedef struct CGameCtnEditor CGameCtnEditor, *PCGameCtnEditor;

struct CGameCtnEditor {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CFuncShader*> CFastArray<class_CFuncShader*>, *PCFastArray<class_CFuncShader*>;

struct CFastArray<class_CFuncShader*> {
    undefined field0_0x0;
};

typedef struct CPlugDecoratorTree CPlugDecoratorTree, *PCPlugDecoratorTree;

struct CPlugDecoratorTree {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamVec2> CMwParamFastArray<class_CMwParamVec2>, *PCMwParamFastArray<class_CMwParamVec2>;

struct CMwParamFastArray<class_CMwParamVec2> {
    undefined field0_0x0;
};

typedef enum EChallengePlayModeMS {
} EChallengePlayModeMS;

typedef struct CHmsPhysicalContact CHmsPhysicalContact, *PCHmsPhysicalContact;

struct CHmsPhysicalContact {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatSailState SMwParamInfos_CBoatSailState, *PSMwParamInfos_CBoatSailState;

struct SMwParamInfos_CBoatSailState {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFileVHlsl> CMwNodRef<class_CPlugFileVHlsl>, *PCMwNodRef<class_CPlugFileVHlsl>;

struct CMwNodRef<class_CPlugFileVHlsl> {
    undefined field0_0x0;
};

typedef enum EGetState {
} EGetState;

typedef struct CPlugFileText CPlugFileText, *PCPlugFileText;

struct CPlugFileText {
    undefined field0_0x0;
};

typedef struct CFuncKeysCmd CFuncKeysCmd, *PCFuncKeysCmd;

struct CFuncKeysCmd {
    undefined field0_0x0;
};

typedef struct CMwParamClass CMwParamClass, *PCMwParamClass;

struct CMwParamClass {
    undefined field0_0x0;
};

typedef struct GmTransQuat GmTransQuat, *PGmTransQuat;

struct GmTransQuat {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugMaterialFxDynaBump SMwParamInfos_CPlugMaterialFxDynaBump, *PSMwParamInfos_CPlugMaterialFxDynaBump;

struct SMwParamInfos_CPlugMaterialFxDynaBump {
    undefined field0_0x0;
};

typedef struct CFuncSkelValues CFuncSkelValues, *PCFuncSkelValues;

struct CFuncSkelValues {
    undefined field0_0x0;
};

typedef struct CFuncWeather CFuncWeather, *PCFuncWeather;

struct CFuncWeather {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCampaignPlayerScores> CMwNodRef<class_CGameCampaignPlayerScores>, *PCMwNodRef<class_CGameCampaignPlayerScores>;

struct CMwNodRef<class_CGameCampaignPlayerScores> {
    undefined field0_0x0;
};

typedef struct CBoatParam CBoatParam, *PCBoatParam;

struct CBoatParam {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerMeteo SMwParamInfos_CMotionManagerMeteo, *PSMwParamInfos_CMotionManagerMeteo;

struct SMwParamInfos_CMotionManagerMeteo {
    undefined field0_0x0;
};

typedef enum EBlockType {
} EBlockType;

typedef struct SEmitterPrecalc SEmitterPrecalc, *PSEmitterPrecalc;

struct SEmitterPrecalc {
    undefined field0_0x0;
};

typedef struct CGameMasterServer CGameMasterServer, *PCGameMasterServer;

struct CGameMasterServer {
    undefined field0_0x0;
};

typedef struct COalAudioPort COalAudioPort, *PCOalAudioPort;

struct COalAudioPort {
    undefined field0_0x0;
};

typedef struct CSceneFxStereoscopy CSceneFxStereoscopy, *PCSceneFxStereoscopy;

struct CSceneFxStereoscopy {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileBink SMwParamInfos_CPlugFileBink, *PSMwParamInfos_CPlugFileBink;

struct SMwParamInfos_CPlugFileBink {
    undefined field0_0x0;
};

typedef struct CTrackManiaEditorIcon CTrackManiaEditorIcon, *PCTrackManiaEditorIcon;

struct CTrackManiaEditorIcon {
    undefined field0_0x0;
};

typedef struct CPlugSolid CPlugSolid, *PCPlugSolid;

struct CPlugSolid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameControlCameraEffect>_> CFastBuffer<class_CMwNodRef<class_CGameControlCameraEffect>_>, *PCFastBuffer<class_CMwNodRef<class_CGameControlCameraEffect>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameControlCameraEffect>_> {
    undefined field0_0x0;
};

typedef enum EXmlParamAction {
} EXmlParamAction;

typedef struct CFastBuffer<class_GmVec3> CFastBuffer<class_GmVec3>, *PCFastBuffer<class_GmVec3>;

struct CFastBuffer<class_GmVec3> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SCameraFxSharedRT> CFastBuffer<struct_CVisionViewportDx9::SCameraFxSharedRT>, *PCFastBuffer<struct_CVisionViewportDx9::SCameraFxSharedRT>;

struct CFastBuffer<struct_CVisionViewportDx9::SCameraFxSharedRT> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnApp SMwParamInfos_CGameCtnApp, *PSMwParamInfos_CGameCtnApp;

struct SMwParamInfos_CGameCtnApp {
    undefined field0_0x0;
};

typedef enum EQueryStyle {
} EQueryStyle;

typedef struct CMwCmdAffectParamVec3 CMwCmdAffectParamVec3, *PCMwCmdAffectParamVec3;

struct CMwCmdAffectParamVec3 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmVec2> CFastBuffer<class_GmVec2>, *PCFastBuffer<class_GmVec2>;

struct CFastBuffer<class_GmVec2> {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectParamVec2 CMwCmdAffectParamVec2, *PCMwCmdAffectParamVec2;

struct CMwCmdAffectParamVec2 {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<int> CFastCallback1P<int>, *PCFastCallback1P<int>;

struct CFastCallback1P<int> {
    undefined field0_0x0;
};

typedef enum EAnisoQOld {
} EAnisoQOld;

typedef enum ETmValidateResult {
} ETmValidateResult;

typedef struct CFastBuffer<class_GmVec4> CFastBuffer<class_GmVec4>, *PCFastBuffer<class_GmVec4>;

struct CFastBuffer<class_GmVec4> {
    undefined field0_0x0;
};

typedef struct basic_filebuf<char,struct_std::char_traits<char>_> basic_filebuf<char,struct_std::char_traits<char>_>, *Pbasic_filebuf<char,struct_std::char_traits<char>_>;

struct basic_filebuf<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct CGameControlCamera CGameControlCamera, *PCGameControlCamera;

struct CGameControlCamera {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCampaignScores> CMwNodRef<class_CGameCampaignScores>, *PCMwNodRef<class_CGameCampaignScores>;

struct CMwNodRef<class_CGameCampaignScores> {
    undefined field0_0x0;
};

typedef struct CSceneFxVisionK CSceneFxVisionK, *PCSceneFxVisionK;

struct CSceneFxVisionK {
    undefined field0_0x0;
};

typedef struct SCallbackList SCallbackList, *PSCallbackList;

struct SCallbackList {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockFxBlurDepth SMwParamInfos_CGameCtnMediaBlockFxBlurDepth, *PSMwParamInfos_CGameCtnMediaBlockFxBlurDepth;

struct SMwParamInfos_CGameCtnMediaBlockFxBlurDepth {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetMasterServerInfo SMwParamInfos_CNetMasterServerInfo, *PSMwParamInfos_CNetMasterServerInfo;

struct SMwParamInfos_CNetMasterServerInfo {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CFastStringInt_const&> CFastCallback1P<class_CFastStringInt_const&>, *PCFastCallback1P<class_CFastStringInt_const&>;

struct CFastCallback1P<class_CFastStringInt_const&> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSystemEngine::SCallBack_OnFidConnected> CFastBuffer<struct_CSystemEngine::SCallBack_OnFidConnected>, *PCFastBuffer<struct_CSystemEngine::SCallBack_OnFidConnected>;

struct CFastBuffer<struct_CSystemEngine::SCallBack_OnFidConnected> {
    undefined field0_0x0;
};

typedef struct CGameMultiLocalProfileHeader CGameMultiLocalProfileHeader, *PCGameMultiLocalProfileHeader;

struct CGameMultiLocalProfileHeader {
    undefined field0_0x0;
};

typedef struct facet facet, *Pfacet;

struct facet {
    undefined field0_0x0;
};

typedef struct ctype_base ctype_base, *Pctype_base;

struct ctype_base {
    undefined field0_0x0;
};

typedef struct CControlButton CControlButton, *PCControlButton;

struct CControlButton {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleMaterialGroup SMwParamInfos_CSceneVehicleMaterialGroup, *PSMwParamInfos_CSceneVehicleMaterialGroup;

struct SMwParamInfos_CSceneVehicleMaterialGroup {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraSimple SMwParamInfos_CGameCtnMediaBlockCameraSimple, *PSMwParamInfos_CGameCtnMediaBlockCameraSimple;

struct SMwParamInfos_CGameCtnMediaBlockCameraSimple {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CNetFileTransferUpload*> CFastBuffer<class_CNetFileTransferUpload*>, *PCFastBuffer<class_CNetFileTransferUpload*>;

struct CFastBuffer<class_CNetFileTransferUpload*> {
    undefined field0_0x0;
};

typedef struct CDx9VertexShader CDx9VertexShader, *PCDx9VertexShader;

struct CDx9VertexShader {
    undefined field0_0x0;
};

typedef struct CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>, *PCFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState>;

struct CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> {
    undefined field0_0x0;
};

typedef struct CClassicBufferZlib CClassicBufferZlib, *PCClassicBufferZlib;

struct CClassicBufferZlib {
    undefined field0_0x0;
};

typedef struct CNetNod_CheckedArchive CNetNod_CheckedArchive, *PCNetNod_CheckedArchive;

struct CNetNod_CheckedArchive {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlMediaItem SMwParamInfos_CControlMediaItem, *PSMwParamInfos_CControlMediaItem;

struct SMwParamInfos_CControlMediaItem {
    undefined field0_0x0;
};

typedef struct CSystemCrashDump CSystemCrashDump, *PCSystemCrashDump;

struct CSystemCrashDump {
    undefined field0_0x0;
};

typedef struct SRpcPlayerQuickInfo SRpcPlayerQuickInfo, *PSRpcPlayerQuickInfo;

struct SRpcPlayerQuickInfo {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfoRoad CGameCtnBlockInfoRoad, *PCGameCtnBlockInfoRoad;

struct CGameCtnBlockInfoRoad {
    undefined field0_0x0;
};

typedef struct SEventEndOfLap SEventEndOfLap, *PSEventEndOfLap;

struct SEventEndOfLap {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmNat2> CFastBuffer<class_GmNat2>, *PCFastBuffer<class_GmNat2>;

struct CFastBuffer<class_GmNat2> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioMusic SMwParamInfos_CAudioMusic, *PSMwParamInfos_CAudioMusic;

struct SMwParamInfos_CAudioMusic {
    undefined field0_0x0;
};

typedef struct SOalSource SOalSource, *PSOalSource;

struct SOalSource {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerInfo SMwParamInfos_CGamePlayerInfo, *PSMwParamInfos_CGamePlayerInfo;

struct SMwParamInfos_CGamePlayerInfo {
    undefined field0_0x0;
};

typedef struct CMwEngineMain CMwEngineMain, *PCMwEngineMain;

struct CMwEngineMain {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_tagRECT> CFastBuffer<struct_tagRECT>, *PCFastBuffer<struct_tagRECT>;

struct CFastBuffer<struct_tagRECT> {
    undefined field0_0x0;
};

typedef struct CControlOverlay CControlOverlay, *PCControlOverlay;

struct CControlOverlay {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CFastStringForArray> CFastBuffer<class_CFastStringForArray>, *PCFastBuffer<class_CFastStringForArray>;

struct CFastBuffer<class_CFastStringForArray> {
    undefined field0_0x0;
};

typedef struct CGameRequestData CGameRequestData, *PCGameRequestData;

struct CGameRequestData {
    undefined field0_0x0;
};

typedef struct SHeaderTMDesc SHeaderTMDesc, *PSHeaderTMDesc;

struct SHeaderTMDesc {
    undefined field0_0x0;
};

typedef struct CGameCtnChallengeInfo CGameCtnChallengeInfo, *PCGameCtnChallengeInfo;

struct CGameCtnChallengeInfo {
    undefined field0_0x0;
};

typedef struct CNetFormEnumSessions CNetFormEnumSessions, *PCNetFormEnumSessions;

struct CNetFormEnumSessions {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2Mult CMwCmdExpVec2Mult, *PCMwCmdExpVec2Mult;

struct CMwCmdExpVec2Mult {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo> CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>, *PCFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>;

struct CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo> {
    undefined field0_0x0;
};

typedef struct CGameCtnEdControlCam CGameCtnEdControlCam, *PCGameCtnEdControlCam;

struct CGameCtnEdControlCam {
    undefined field0_0x0;
};

typedef enum EPainterMode {
} EPainterMode;

typedef struct CPlugSoundEngine CPlugSoundEngine, *PCPlugSoundEngine;

struct CPlugSoundEngine {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_> CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugModelMesh>_> {
    undefined field0_0x0;
};

typedef struct SManiaCodeAction SManiaCodeAction, *PSManiaCodeAction;

struct SManiaCodeAction {
    undefined field0_0x0;
};

typedef struct SStereoscopy SStereoscopy, *PSStereoscopy;

struct SStereoscopy {
    undefined field0_0x0;
};

typedef struct CPlugFileJpg CPlugFileJpg, *PCPlugFileJpg;

struct CPlugFileJpg {
    undefined field0_0x0;
};

typedef struct TiXmlPrinter TiXmlPrinter, *PTiXmlPrinter;

struct TiXmlPrinter {
    undefined field0_0x0;
};

typedef struct SVisualToMerge SVisualToMerge, *PSVisualToMerge;

struct SVisualToMerge {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat> CFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat>, *PCFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat>;

struct CFastBufferCat<struct_CHmsViewport::SVisibleCamera,struct_CHmsViewport::SVisibleZoneCat> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec3MultIso CMwCmdExpVec3MultIso, *PCMwCmdExpVec3MultIso;

struct CMwCmdExpVec3MultIso {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardGeneric SMwParamInfos_CGameControlCardGeneric, *PSMwParamInfos_CGameControlCardGeneric;

struct SMwParamInfos_CGameControlCardGeneric {
    undefined field0_0x0;
};

typedef struct SBuildInput SBuildInput, *PSBuildInput;

struct SBuildInput {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CAudioSoundBink::SSetting> CFastBuffer<struct_CAudioSoundBink::SSetting>, *PCFastBuffer<struct_CAudioSoundBink::SSetting>;

struct CFastBuffer<struct_CAudioSoundBink::SSetting> {
    undefined field0_0x0;
};

typedef enum ESceneLightUpdate {
} ESceneLightUpdate;

typedef struct SMwParamInfos_CSceneToyMotorbike SMwParamInfos_CSceneToyMotorbike, *PSMwParamInfos_CSceneToyMotorbike;

struct SMwParamInfos_CSceneToyMotorbike {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugIndexBuffer SMwParamInfos_CPlugIndexBuffer, *PSMwParamInfos_CPlugIndexBuffer;

struct SMwParamInfos_CPlugIndexBuffer {
    undefined field0_0x0;
};

typedef struct SValidate_Internal SValidate_Internal, *PSValidate_Internal;

struct SValidate_Internal {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_OSVERSIONINFOA - /winnt.h/_OSVERSIONINFOA */

typedef struct CFastBufferRef<class_CGameChallengeScores> CFastBufferRef<class_CGameChallengeScores>, *PCFastBufferRef<class_CGameChallengeScores>;

struct CFastBufferRef<class_CGameChallengeScores> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncPathMesh SMwParamInfos_CFuncPathMesh, *PSMwParamInfos_CFuncPathMesh;

struct SMwParamInfos_CFuncPathMesh {
    undefined field0_0x0;
};

typedef enum EBoolCond {
} EBoolCond;

typedef struct SCachedPageCards SCachedPageCards, *PSCachedPageCards;

struct SCachedPageCards {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneFxBloomData>_> CFastBuffer<class_CMwNodRef<class_CSceneFxBloomData>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneFxBloomData>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneFxBloomData>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerInfo::SSkinInfo> CFastBuffer<struct_CGamePlayerInfo::SSkinInfo>, *PCFastBuffer<struct_CGamePlayerInfo::SSkinInfo>;

struct CFastBuffer<struct_CGamePlayerInfo::SSkinInfo> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerProfile SMwParamInfos_CGamePlayerProfile, *PSMwParamInfos_CGamePlayerProfile;

struct SMwParamInfos_CGamePlayerProfile {
    undefined field0_0x0;
};

typedef struct CGameLadderScores CGameLadderScores, *PCGameLadderScores;

struct CGameLadderScores {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCampaign SMwParamInfos_CGameCtnCampaign, *PSMwParamInfos_CGameCtnCampaign;

struct SMwParamInfos_CGameCtnCampaign {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CXmlElement SMwParamInfos_CXmlElement, *PSMwParamInfos_CXmlElement;

struct SMwParamInfos_CXmlElement {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmNat3> CFastBuffer<class_GmNat3>, *PCFastBuffer<class_GmNat3>;

struct CFastBuffer<class_GmNat3> {
    undefined field0_0x0;
};

typedef struct basic_ios<char,struct_std::char_traits<char>_> basic_ios<char,struct_std::char_traits<char>_>, *Pbasic_ios<char,struct_std::char_traits<char>_>;

struct basic_ios<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct GxSurfQuadHeight GxSurfQuadHeight, *PGxSurfQuadHeight;

struct GxSurfQuadHeight {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_WIN32_FIND_DATAW - /winbase.h/_WIN32_FIND_DATAW */

typedef struct CSystemConfig CSystemConfig, *PCSystemConfig;

struct CSystemConfig {
    undefined field0_0x0;
};

typedef struct CNetTcpUnconnectedClientSocket CNetTcpUnconnectedClientSocket, *PCNetTcpUnconnectedClientSocket;

struct CNetTcpUnconnectedClientSocket {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemMouse SMwParamInfos_CSystemMouse, *PSMwParamInfos_CSystemMouse;

struct SMwParamInfos_CSystemMouse {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsConfig SMwParamInfos_CHmsConfig, *PSMwParamInfos_CHmsConfig;

struct SMwParamInfos_CHmsConfig {
    undefined field0_0x0;
};

typedef enum EPlayerType {
} EPlayerType;


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/CLIENT_ID - /CLIENT_ID */

typedef struct CGameCalendarEvent CGameCalendarEvent, *PCGameCalendarEvent;

struct CGameCalendarEvent {
    undefined field0_0x0;
};

typedef struct CMwCmdScriptVarFloat CMwCmdScriptVarFloat, *PCMwCmdScriptVarFloat;

struct CMwCmdScriptVarFloat {
    undefined field0_0x0;
};

typedef struct SActionMapDescription SActionMapDescription, *PSActionMapDescription;

struct SActionMapDescription {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GxVertex> CFastBuffer<class_GxVertex>, *PCFastBuffer<class_GxVertex>;

struct CFastBuffer<class_GxVertex> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpVec3 SMwParamInfos_CMwCmdExpVec3, *PSMwParamInfos_CMwCmdExpVec3;

struct SMwParamInfos_CMwCmdExpVec3 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardManager SMwParamInfos_CGameControlCardManager, *PSMwParamInfos_CGameControlCardManager;

struct SMwParamInfos_CGameControlCardManager {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdExpVec2 SMwParamInfos_CMwCmdExpVec2, *PSMwParamInfos_CMwCmdExpVec2;

struct SMwParamInfos_CMwCmdExpVec2 {
    undefined field0_0x0;
};

typedef struct CTrackManiaIPCCallbacks CTrackManiaIPCCallbacks, *PCTrackManiaIPCCallbacks;

struct CTrackManiaIPCCallbacks {
    undefined field0_0x0;
};

typedef enum ESailType {
} ESailType;

typedef struct CFastBuffer<class_CMwNodRef<class_CGameLeague>_> CFastBuffer<class_CMwNodRef<class_CGameLeague>_>, *PCFastBuffer<class_CMwNodRef<class_CGameLeague>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameLeague>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlBase SMwParamInfos_CControlBase, *PSMwParamInfos_CControlBase;

struct SMwParamInfos_CControlBase {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMotionSkelBlender::CBlendedSolid> CFastBuffer<class_CMotionSkelBlender::CBlendedSolid>, *PCFastBuffer<class_CMotionSkelBlender::CBlendedSolid>;

struct CFastBuffer<class_CMotionSkelBlender::CBlendedSolid> {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CDx9TextureKeeper*,4,unsigned_long> CFixedArray<class_CDx9TextureKeeper*,4,unsigned_long>, *PCFixedArray<class_CDx9TextureKeeper*,4,unsigned_long>;

struct CFixedArray<class_CDx9TextureKeeper*,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmVec3,struct_SFastCat> CFastBufferCat<class_GmVec3,struct_SFastCat>, *PCFastBufferCat<class_GmVec3,struct_SFastCat>;

struct CFastBufferCat<class_GmVec3,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionPlayer SMwParamInfos_CMotionPlayer, *PSMwParamInfos_CMotionPlayer;

struct SMwParamInfos_CMotionPlayer {
    undefined field0_0x0;
};

typedef enum EPredictionType {
} EPredictionType;

typedef enum ESourceStatus {
} ESourceStatus;

typedef enum EType {
} EType;

typedef struct CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent> CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>, *PCFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>;

struct CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent> {
    undefined field0_0x0;
};

typedef struct CGameRace CGameRace, *PCGameRace;

struct CGameRace {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncEnvelope SMwParamInfos_CFuncEnvelope, *PSMwParamInfos_CFuncEnvelope;

struct SMwParamInfos_CFuncEnvelope {
    undefined field0_0x0;
};

typedef struct CMotionManagerCharacterAdv CMotionManagerCharacterAdv, *PCMotionManagerCharacterAdv;

struct CMotionManagerCharacterAdv {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugVisual SMwParamInfos_CPlugVisual, *PSMwParamInfos_CPlugVisual;

struct SMwParamInfos_CPlugVisual {
    undefined field0_0x0;
};

typedef struct CGameCtnCollectorList CGameCtnCollectorList, *PCGameCtnCollectorList;

struct CGameCtnCollectorList {
    undefined field0_0x0;
};

typedef struct CCrystalTravelEdge CCrystalTravelEdge, *PCCrystalTravelEdge;

struct CCrystalTravelEdge {
    undefined field0_0x0;
};

typedef struct SHmsVPackerObjectPacked SHmsVPackerObjectPacked, *PSHmsVPackerObjectPacked;

struct SHmsVPackerObjectPacked {
    undefined field0_0x0;
};

typedef struct CPlugShaderGeneric CPlugShaderGeneric, *PCPlugShaderGeneric;

struct CPlugShaderGeneric {
    undefined field0_0x0;
};

typedef enum ELoadId {
} ELoadId;

typedef struct SMwParamInfos_CGameCtnBlockInfoPylon SMwParamInfos_CGameCtnBlockInfoPylon, *PSMwParamInfos_CGameCtnBlockInfoPylon;

struct SMwParamInfos_CGameCtnBlockInfoPylon {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncPlug SMwParamInfos_CFuncPlug, *PSMwParamInfos_CFuncPlug;

struct SMwParamInfos_CFuncPlug {
    undefined field0_0x0;
};

typedef struct CFastBufferDep<class_CSceneCamera> CFastBufferDep<class_CSceneCamera>, *PCFastBufferDep<class_CSceneCamera>;

struct CFastBufferDep<class_CSceneCamera> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileVideo SMwParamInfos_CPlugFileVideo, *PSMwParamInfos_CPlugFileVideo;

struct SMwParamInfos_CPlugFileVideo {
    undefined field0_0x0;
};

typedef struct CGameScoresVersion CGameScoresVersion, *PCGameScoresVersion;

struct CGameScoresVersion {
    undefined field0_0x0;
};

typedef struct SItAllShader SItAllShader, *PSItAllShader;

struct SItAllShader {
    undefined field0_0x0;
};

typedef enum ETurboType {
} ETurboType;

typedef struct CMotionPlaySoundMobil CMotionPlaySoundMobil, *PCMotionPlaySoundMobil;

struct CMotionPlaySoundMobil {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetHttpResult SMwParamInfos_CNetHttpResult, *PSMwParamInfos_CNetHttpResult;

struct SMwParamInfos_CNetHttpResult {
    undefined field0_0x0;
};

typedef struct SSurvivalScore SSurvivalScore, *PSSurvivalScore;

struct SSurvivalScore {
    undefined field0_0x0;
};

typedef struct CMwCmdExpIso4Inverse CMwCmdExpIso4Inverse, *PCMwCmdExpIso4Inverse;

struct CMwCmdExpIso4Inverse {
    undefined field0_0x0;
};

typedef struct CHmsConfig CHmsConfig, *PCHmsConfig;

struct CHmsConfig {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameMenuFrame SMwParamInfos_CGameMenuFrame, *PSMwParamInfos_CGameMenuFrame;

struct SMwParamInfos_CGameMenuFrame {
    undefined field0_0x0;
};

typedef struct SQuadTreeMeshUv SQuadTreeMeshUv, *PSQuadTreeMeshUv;

struct SQuadTreeMeshUv {
    undefined field0_0x0;
};

typedef struct basic_istream<wchar_t,struct_std::char_traits<wchar_t>_> basic_istream<wchar_t,struct_std::char_traits<wchar_t>_>, *Pbasic_istream<wchar_t,struct_std::char_traits<wchar_t>_>;

struct basic_istream<wchar_t,struct_std::char_traits<wchar_t>_> {
    undefined field0_0x0;
};

typedef enum EObjectKind {
} EObjectKind;

typedef struct CFastArray<struct_CGameRace::SCameraPreset> CFastArray<struct_CGameRace::SCameraPreset>, *PCFastArray<struct_CGameRace::SCameraPreset>;

struct CFastArray<struct_CGameRace::SCameraPreset> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameMasterServer SMwParamInfos_CGameMasterServer, *PSMwParamInfos_CGameMasterServer;

struct SMwParamInfos_CGameMasterServer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMobilSnow SMwParamInfos_CSceneMobilSnow, *PSMwParamInfos_CSceneMobilSnow;

struct SMwParamInfos_CSceneMobilSnow {
    undefined field0_0x0;
};

typedef struct SRpm SRpm, *PSRpm;

struct SRpm {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastBuffer<struct_CVisionViewportDx9::SSurface>,4,unsigned_long> CFixedArray<class_CFastBuffer<struct_CVisionViewportDx9::SSurface>,4,unsigned_long>, *PCFixedArray<class_CFastBuffer<struct_CVisionViewportDx9::SSurface>,4,unsigned_long>;

struct CFixedArray<class_CFastBuffer<struct_CVisionViewportDx9::SSurface>,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSystemPackManager::SQueueElem> CFastBuffer<struct_CSystemPackManager::SQueueElem>, *PCFastBuffer<struct_CSystemPackManager::SQueueElem>;

struct CFastBuffer<struct_CSystemPackManager::SQueueElem> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockTime SMwParamInfos_CGameCtnMediaBlockTime, *PSMwParamInfos_CGameCtnMediaBlockTime;

struct SMwParamInfos_CGameCtnMediaBlockTime {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsPrecalcRender SMwParamInfos_CHmsPrecalcRender, *PSMwParamInfos_CHmsPrecalcRender;

struct SMwParamInfos_CHmsPrecalcRender {
    undefined field0_0x0;
};

typedef struct IDirect3DTexture9 IDirect3DTexture9, *PIDirect3DTexture9;

struct IDirect3DTexture9 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlTimeLine2 SMwParamInfos_CControlTimeLine2, *PSMwParamInfos_CControlTimeLine2;

struct SMwParamInfos_CControlTimeLine2 {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecularsLA> CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecularsLA>, *PCFastBuffer<struct_CVisionViewportDx9::SBitmapSpecularsLA>;

struct CFastBuffer<struct_CVisionViewportDx9::SBitmapSpecularsLA> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneObjectLink> CMwNodRef<class_CSceneObjectLink>, *PCMwNodRef<class_CSceneObjectLink>;

struct CMwNodRef<class_CSceneObjectLink> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SServerWithBuddies> CFastBuffer<struct_SServerWithBuddies>, *PCFastBuffer<struct_SServerWithBuddies>;

struct CFastBuffer<struct_SServerWithBuddies> {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneFxNod> CMwNodRef<class_CSceneFxNod>, *PCMwNodRef<class_CSceneFxNod>;

struct CMwNodRef<class_CSceneFxNod> {
    undefined field0_0x0;
};

typedef struct CVisionResourceFile CVisionResourceFile, *PCVisionResourceFile;

struct CVisionResourceFile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneConfig SMwParamInfos_CSceneConfig, *PSMwParamInfos_CSceneConfig;

struct SMwParamInfos_CSceneConfig {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGamePlayerScore SMwParamInfos_CGamePlayerScore, *PSMwParamInfos_CGamePlayerScore;

struct SMwParamInfos_CGamePlayerScore {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrackTree SMwParamInfos_CMotionTrackTree, *PSMwParamInfos_CMotionTrackTree;

struct SMwParamInfos_CMotionTrackTree {
    undefined field0_0x0;
};

typedef struct CFuncTreeElevator CFuncTreeElevator, *PCFuncTreeElevator;

struct CFuncTreeElevator {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CNetMasterServer::SMasterServerInfos> CFastBuffer<struct_CNetMasterServer::SMasterServerInfos>, *PCFastBuffer<struct_CNetMasterServer::SMasterServerInfos>;

struct CFastBuffer<struct_CNetMasterServer::SMasterServerInfos> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnCampaign::SkinSet> CFastBuffer<struct_CGameCtnCampaign::SkinSet>, *PCFastBuffer<struct_CGameCtnCampaign::SkinSet>;

struct CFastBuffer<struct_CGameCtnCampaign::SkinSet> {
    undefined field0_0x0;
};

typedef enum ECommitStatus {
} ECommitStatus;

typedef struct GmLine3 GmLine3, *PGmLine3;

struct GmLine3 {
    undefined field0_0x0;
};

typedef struct SGameCtnIdentifier SGameCtnIdentifier, *PSGameCtnIdentifier;

struct SGameCtnIdentifier {
    undefined field0_0x0;
};

typedef struct CMwCmdAffectIdent CMwCmdAffectIdent, *PCMwCmdAffectIdent;

struct CMwCmdAffectIdent {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CSceneMobil*,struct_SFastCat> CFastBufferCat<class_CSceneMobil*,struct_SFastCat>, *PCFastBufferCat<class_CSceneMobil*,struct_SFastCat>;

struct CFastBufferCat<class_CSceneMobil*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CAudioPort::SAutoBalancedSound> CFastBuffer<struct_CAudioPort::SAutoBalancedSound>, *PCFastBuffer<struct_CAudioPort::SAutoBalancedSound>;

struct CFastBuffer<struct_CAudioPort::SAutoBalancedSound> {
    undefined field0_0x0;
};

typedef struct CHmsItem CHmsItem, *PCHmsItem;

struct CHmsItem {
    undefined field0_0x0;
};

typedef struct SLocTreeCorpus SLocTreeCorpus, *PSLocTreeCorpus;

struct SLocTreeCorpus {
    undefined field0_0x0;
};

typedef struct CHmsPocEmitter CHmsPocEmitter, *PCHmsPocEmitter;

struct CHmsPocEmitter {
    undefined field0_0x0;
};

typedef struct SBufferLists<struct_SPolyVert> SBufferLists<struct_SPolyVert>, *PSBufferLists<struct_SPolyVert>;

struct SBufferLists<struct_SPolyVert> {
    undefined field0_0x0;
};

typedef struct CSceneFxHeadTrack CSceneFxHeadTrack, *PCSceneFxHeadTrack;

struct CSceneFxHeadTrack {
    undefined field0_0x0;
};

typedef enum EKindOS {
} EKindOS;

typedef struct SMwParamInfos_CSceneFx SMwParamInfos_CSceneFx, *PSMwParamInfos_CSceneFx;

struct SMwParamInfos_CSceneFx {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaBlock3dStereo CGameCtnMediaBlock3dStereo, *PCGameCtnMediaBlock3dStereo;

struct CGameCtnMediaBlock3dStereo {
    undefined field0_0x0;
};

typedef struct CGameNetFormAdmin CGameNetFormAdmin, *PCGameNetFormAdmin;

struct CGameNetFormAdmin {
    undefined field0_0x0;
};

typedef struct CSystemWindow CSystemWindow, *PCSystemWindow;

struct CSystemWindow {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CPlugVolumeShadow*,struct_SFastCat> CFastBufferCat<class_CPlugVolumeShadow*,struct_SFastCat>, *PCFastBufferCat<class_CPlugVolumeShadow*,struct_SFastCat>;

struct CFastBufferCat<class_CPlugVolumeShadow*,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CHmsVPackerLevel> CFastArray<class_CHmsVPackerLevel>, *PCFastArray<class_CHmsVPackerLevel>;

struct CFastArray<class_CHmsVPackerLevel> {
    undefined field0_0x0;
};

typedef struct CNetHttpClient CNetHttpClient, *PCNetHttpClient;

struct CNetHttpClient {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CFastString> CFastArray<class_CFastString>, *PCFastArray<class_CFastString>;

struct CFastArray<class_CFastString> {
    undefined field0_0x0;
};

typedef struct SScreenShot SScreenShot, *PSScreenShot;

struct SScreenShot {
    undefined field0_0x0;
};

typedef enum ETextMode {
} ETextMode;

typedef struct CMwNodRef<class_CGameRemoteBufferPool> CMwNodRef<class_CGameRemoteBufferPool>, *PCMwNodRef<class_CGameRemoteBufferPool>;

struct CMwNodRef<class_CGameRemoteBufferPool> {
    undefined field0_0x0;
};

typedef struct SShaderBlurDepth SShaderBlurDepth, *PSShaderBlurDepth;

struct SShaderBlurDepth {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CManoeuvre*> CFastArray<class_CManoeuvre*>, *PCFastArray<class_CManoeuvre*>;

struct CFastArray<class_CManoeuvre*> {
    undefined field0_0x0;
};

typedef struct SMwTimedValueInstant<struct_SInputEventsStoreElem> SMwTimedValueInstant<struct_SInputEventsStoreElem>, *PSMwTimedValueInstant<struct_SInputEventsStoreElem>;

struct SMwTimedValueInstant<struct_SInputEventsStoreElem> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraOrbital3d SMwParamInfos_CGameControlCameraOrbital3d, *PSMwParamInfos_CGameControlCameraOrbital3d;

struct SMwParamInfos_CGameControlCameraOrbital3d {
    undefined field0_0x0;
};

typedef enum EKindCpu {
} EKindCpu;

typedef struct CMwCmdAffectParamString CMwCmdAffectParamString, *PCMwCmdAffectParamString;

struct CMwCmdAffectParamString {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsViewport::SVisualLocation> CFastBuffer<struct_CHmsViewport::SVisualLocation>, *PCFastBuffer<struct_CHmsViewport::SVisualLocation>;

struct CFastBuffer<struct_CHmsViewport::SVisualLocation> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2Function CMwCmdExpVec2Function, *PCMwCmdExpVec2Function;

struct CMwCmdExpVec2Function {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CFastBuffer<class_CGameCtnFieldUnit*>*> CFastArray<class_CFastBuffer<class_CGameCtnFieldUnit*>*>, *PCFastArray<class_CFastBuffer<class_CGameCtnFieldUnit*>*>;

struct CFastArray<class_CFastBuffer<class_CGameCtnFieldUnit*>*> {
    undefined field0_0x0;
};

typedef struct CPlugSoundMulti CPlugSoundMulti, *PCPlugSoundMulti;

struct CPlugSoundMulti {
    undefined field0_0x0;
};

typedef struct CMwCmdExpVec2Sub CMwCmdExpVec2Sub, *PCMwCmdExpVec2Sub;

struct CMwCmdExpVec2Sub {
    undefined field0_0x0;
};

typedef struct CCtnMediaBlockUiTMSimpleEvtsDisplay CCtnMediaBlockUiTMSimpleEvtsDisplay, *PCCtnMediaBlockUiTMSimpleEvtsDisplay;

struct CCtnMediaBlockUiTMSimpleEvtsDisplay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugTreeGenText SMwParamInfos_CPlugTreeGenText, *PSMwParamInfos_CPlugTreeGenText;

struct SMwParamInfos_CPlugTreeGenText {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlGrid SMwParamInfos_CControlGrid, *PSMwParamInfos_CControlGrid;

struct SMwParamInfos_CControlGrid {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>, *PCFastBuffer<struct_CHmsCollisionManager::SColOctreeCell>;

struct CFastBuffer<struct_CHmsCollisionManager::SColOctreeCell> {
    undefined field0_0x0;
};

typedef struct CFastCallback1P<class_CPlugFileGPUV*> CFastCallback1P<class_CPlugFileGPUV*>, *PCFastCallback1P<class_CPlugFileGPUV*>;

struct CFastCallback1P<class_CPlugFileGPUV*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncSin SMwParamInfos_CFuncSin, *PSMwParamInfos_CFuncSin;

struct SMwParamInfos_CFuncSin {
    undefined field0_0x0;
};

typedef struct STmValidateParam STmValidateParam, *PSTmValidateParam;

struct STmValidateParam {
    undefined field0_0x0;
};

typedef struct SGmSmoothReal2 SGmSmoothReal2, *PSGmSmoothReal2;

struct SGmSmoothReal2 {
    undefined field0_0x0;
};

typedef struct CCallbackSceneToyBoatComputeForces CCallbackSceneToyBoatComputeForces, *PCCallbackSceneToyBoatComputeForces;

struct CCallbackSceneToyBoatComputeForces {
    undefined field0_0x0;
};

typedef struct CInputPortNull CInputPortNull, *PCInputPortNull;

struct CInputPortNull {
    undefined field0_0x0;
};

typedef enum ENonPowOfTwo {
} ENonPowOfTwo;

typedef enum EPriorityLevel {
} EPriorityLevel;

typedef struct SHotSeat SHotSeat, *PSHotSeat;

struct SHotSeat {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneTrafficGraph::SHub> CFastBuffer<struct_CSceneTrafficGraph::SHub>, *PCFastBuffer<struct_CSceneTrafficGraph::SHub>;

struct CFastBuffer<struct_CSceneTrafficGraph::SHub> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre> CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>, *PCFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>;

struct CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre> {
    undefined field0_0x0;
};

typedef struct SHmsVPackerObject SHmsVPackerObject, *PSHmsVPackerObject;

struct SHmsVPackerObject {
    undefined field0_0x0;
};

typedef struct GxBGRAColor GxBGRAColor, *PGxBGRAColor;

struct GxBGRAColor {
    undefined field0_0x0;
};

typedef struct SCameraFxSharedRT SCameraFxSharedRT, *PSCameraFxSharedRT;

struct SCameraFxSharedRT {
    undefined field0_0x0;
};

typedef struct CPlugBitmapSampler CPlugBitmapSampler, *PCPlugBitmapSampler;

struct CPlugBitmapSampler {
    undefined field0_0x0;
};

typedef struct CLoadGeomDynaSpriteGen<0,0,1,0,0,0> CLoadGeomDynaSpriteGen<0,0,1,0,0,0>, *PCLoadGeomDynaSpriteGen<0,0,1,0,0,0>;

struct CLoadGeomDynaSpriteGen<0,0,1,0,0,0> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_SGameCtnIdentifier> CFastArray<struct_SGameCtnIdentifier>, *PCFastArray<struct_SGameCtnIdentifier>;

struct CFastArray<struct_SGameCtnIdentifier> {
    undefined field0_0x0;
};

typedef struct SPlugTreeOptimTransf SPlugTreeOptimTransf, *PSPlugTreeOptimTransf;

struct SPlugTreeOptimTransf {
    undefined field0_0x0;
};

typedef struct CControlTimeLine CControlTimeLine, *PCControlTimeLine;

struct CControlTimeLine {
    undefined field0_0x0;
};

typedef enum EWaveType {
} EWaveType;

typedef struct SMwParamInfos_CFuncLightColor SMwParamInfos_CFuncLightColor, *PSMwParamInfos_CFuncLightColor;

struct SMwParamInfos_CFuncLightColor {
    undefined field0_0x0;
};

typedef enum EStickerMode {
} EStickerMode;


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/DotNetPdbInfo - /PDB/DotNetPdbInfo */

typedef struct CFastBuffer<struct_CDx9StateBlock::STexStageCat> CFastBuffer<struct_CDx9StateBlock::STexStageCat>, *PCFastBuffer<struct_CDx9StateBlock::STexStageCat>;

struct CFastBuffer<struct_CDx9StateBlock::STexStageCat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScene2d SMwParamInfos_CScene2d, *PSMwParamInfos_CScene2d;

struct SMwParamInfos_CScene2d {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlCheckPointList SMwParamInfos_CTrackManiaControlCheckPointList, *PSMwParamInfos_CTrackManiaControlCheckPointList;

struct SMwParamInfos_CTrackManiaControlCheckPointList {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapApply SMwParamInfos_CPlugBitmapApply, *PSMwParamInfos_CPlugBitmapApply;

struct SMwParamInfos_CPlugBitmapApply {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScene3d SMwParamInfos_CScene3d, *PSMwParamInfos_CScene3d;

struct SMwParamInfos_CScene3d {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetOnlineMessage SMwParamInfos_CGameNetOnlineMessage, *PSMwParamInfos_CGameNetOnlineMessage;

struct SMwParamInfos_CGameNetOnlineMessage {
    undefined field0_0x0;
};

typedef struct OBJTri OBJTri, *POBJTri;

struct OBJTri {
    undefined field0_0x0;
};

typedef enum EInputAssignMessage {
} EInputAssignMessage;

typedef struct CMwClassInfoCCtnMediaBlockUiTMSimpleEvtsDisplay CMwClassInfoCCtnMediaBlockUiTMSimpleEvtsDisplay, *PCMwClassInfoCCtnMediaBlockUiTMSimpleEvtsDisplay;

struct CMwClassInfoCCtnMediaBlockUiTMSimpleEvtsDisplay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionManagerMeteoPuffLull SMwParamInfos_CMotionManagerMeteoPuffLull, *PSMwParamInfos_CMotionManagerMeteoPuffLull;

struct SMwParamInfos_CMotionManagerMeteoPuffLull {
    undefined field0_0x0;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

struct IMAGE_LOAD_CONFIG_DIRECTORY32 {
    uint Size;
    uint TimeDateStamp;
    uint16.conflict MajorVersion;
    uint16.conflict MinorVersion;
    uint GlobalFlagsClear;
    uint GlobalFlagsSet;
    uint CriticalSectionDefaultTimeout;
    uint DeCommitFreeBlockThreshold;
    uint DeCommitTotalFreeThreshold;
    wchar32 *LockPrefixTable;
    uint MaximumAllocationSize;
    uint VirtualMemoryThreshold;
    uint ProcessHeapFlags;
    uint ProcessAffinityMask;
    uint16.conflict CsdVersion;
    uint16.conflict DependentLoadFlags;
    wchar32 *EditList;
    wchar32 *SecurityCookie;
    wchar32 *SEHandlerTable;
    uint SEHandlerCount;
};

typedef struct CSystemNodWrapper CSystemNodWrapper, *PCSystemNodWrapper;

struct CSystemNodWrapper {
    undefined field0_0x0;
};

typedef struct SIfBlock SIfBlock, *PSIfBlock;

struct SIfBlock {
    undefined field0_0x0;
};

typedef struct CSceneToyCharacterTunings CSceneToyCharacterTunings, *PCSceneToyCharacterTunings;

struct CSceneToyCharacterTunings {
    undefined field0_0x0;
};

typedef struct CControlSimi2 CControlSimi2, *PCControlSimi2;

struct CControlSimi2 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetConnection SMwParamInfos_CNetConnection, *PSMwParamInfos_CNetConnection;

struct SMwParamInfos_CNetConnection {
    undefined field0_0x0;
};

typedef struct CMotionManagerWeathers CMotionManagerWeathers, *PCMotionManagerWeathers;

struct CMotionManagerWeathers {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleMaterialGroup>_> CFastBuffer<class_CMwNodRef<class_CSceneVehicleMaterialGroup>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneVehicleMaterialGroup>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleMaterialGroup>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetClientInfo SMwParamInfos_CNetClientInfo, *PSMwParamInfos_CNetClientInfo;

struct SMwParamInfos_CNetClientInfo {
    undefined field0_0x0;
};

typedef enum EStdShader {
} EStdShader;

typedef struct tagLC_STRINGS tagLC_STRINGS, *PtagLC_STRINGS;

struct tagLC_STRINGS {
    wchar_t szLanguage[64];
    wchar_t szCountry[64];
    wchar_t szCodePage[16];
    wchar_t szLocaleName[85];
};

typedef struct CFastBuffer<class_CMwNodRef<class_CNetMasterServerRequest>_> CFastBuffer<class_CMwNodRef<class_CNetMasterServerRequest>_>, *PCFastBuffer<class_CMwNodRef<class_CNetMasterServerRequest>_>;

struct CFastBuffer<class_CMwNodRef<class_CNetMasterServerRequest>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncPuffLull SMwParamInfos_CFuncPuffLull, *PSMwParamInfos_CFuncPuffLull;

struct SMwParamInfos_CFuncPuffLull {
    undefined field0_0x0;
};

typedef struct GmBoxOriented GmBoxOriented, *PGmBoxOriented;

struct GmBoxOriented {
    undefined field0_0x0;
};

typedef struct CSceneLocationCamera CSceneLocationCamera, *PCSceneLocationCamera;

struct CSceneLocationCamera {
    undefined field0_0x0;
};

typedef struct CSceneTrafficGraph CSceneTrafficGraph, *PCSceneTrafficGraph;

struct CSceneTrafficGraph {
    undefined field0_0x0;
};

typedef struct SImageHF SImageHF, *PSImageHF;

struct SImageHF {
    undefined field0_0x0;
};

typedef struct SHeaderFolderDep SHeaderFolderDep, *PSHeaderFolderDep;

struct SHeaderFolderDep {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToySeaHouleFixe SMwParamInfos_CSceneToySeaHouleFixe, *PSMwParamInfos_CSceneToySeaHouleFixe;

struct SMwParamInfos_CSceneToySeaHouleFixe {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerNetworkInfo> CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerNetworkInfo>, *PCFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerNetworkInfo>;

struct CFastBuffer<struct_CTrackManiaNetwork::SRpcPlayerNetworkInfo> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnApp::SGeomSkinRemap> CFastBuffer<struct_CGameCtnApp::SGeomSkinRemap>, *PCFastBuffer<struct_CGameCtnApp::SGeomSkinRemap>;

struct CFastBuffer<struct_CGameCtnApp::SGeomSkinRemap> {
    undefined field0_0x0;
};

typedef struct GxLightFrustum GxLightFrustum, *PGxLightFrustum;

struct GxLightFrustum {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncNoise SMwParamInfos_CFuncNoise, *PSMwParamInfos_CFuncNoise;

struct SMwParamInfos_CFuncNoise {
    undefined field0_0x0;
};

typedef struct GmMat4 GmMat4, *PGmMat4;

struct GmMat4 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlFrameAnimated SMwParamInfos_CControlFrameAnimated, *PSMwParamInfos_CControlFrameAnimated;

struct SMwParamInfos_CControlFrameAnimated {
    undefined field0_0x0;
};

typedef enum EPlugRenderQuality {
} EPlugRenderQuality;

typedef struct CFuncPathMesh CFuncPathMesh, *PCFuncPathMesh;

struct CFuncPathMesh {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyCharacterDesc SMwParamInfos_CSceneToyCharacterDesc, *PSMwParamInfos_CSceneToyCharacterDesc;

struct SMwParamInfos_CSceneToyCharacterDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlDataType SMwParamInfos_CGameControlDataType, *PSMwParamInfos_CGameControlDataType;

struct SMwParamInfos_CGameControlDataType {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSceneVehicleStruct::SVisualArm> CFastBuffer<struct_CSceneVehicleStruct::SVisualArm>, *PCFastBuffer<struct_CSceneVehicleStruct::SVisualArm>;

struct CFastBuffer<struct_CSceneVehicleStruct::SVisualArm> {
    undefined field0_0x0;
};

typedef struct CCrystalTriangleRaw CCrystalTriangleRaw, *PCCrystalTriangleRaw;

struct CCrystalTriangleRaw {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxNod SMwParamInfos_CSceneFxNod, *PSMwParamInfos_CSceneFxNod;

struct SMwParamInfos_CSceneFxNod {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnCollectorVehicle>_> CFastBuffer<class_CMwNodRef<class_CGameCtnCollectorVehicle>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnCollectorVehicle>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnCollectorVehicle>_> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerProfile::SVehicleProfile> CFastBuffer<struct_CGamePlayerProfile::SVehicleProfile>, *PCFastBuffer<struct_CGamePlayerProfile::SVehicleProfile>;

struct CFastBuffer<struct_CGamePlayerProfile::SVehicleProfile> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaMatchSettings SMwParamInfos_CTrackManiaMatchSettings, *PSMwParamInfos_CTrackManiaMatchSettings;

struct SMwParamInfos_CTrackManiaMatchSettings {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrackMobilScale SMwParamInfos_CMotionTrackMobilScale, *PSMwParamInfos_CMotionTrackMobilScale;

struct SMwParamInfos_CMotionTrackMobilScale {
    undefined field0_0x0;
};

typedef enum ERenderMode {
} ERenderMode;

typedef struct CMwParamFastArray<class_CMwParamVec3> CMwParamFastArray<class_CMwParamVec3>, *PCMwParamFastArray<class_CMwParamVec3>;

struct CMwParamFastArray<class_CMwParamVec3> {
    undefined field0_0x0;
};

typedef struct GmIso3 GmIso3, *PGmIso3;

struct GmIso3 {
    undefined field0_0x0;
};

typedef struct SShaderQuality SShaderQuality, *PSShaderQuality;

struct SShaderQuality {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<class_CFastStringInt_const&,class_CFastStringInt_const&,struct_CPlugFileImg::SDesc_const&> CFastCallback3P<class_CFastStringInt_const&,class_CFastStringInt_const&,struct_CPlugFileImg::SDesc_const&>, *PCFastCallback3P<class_CFastStringInt_const&,class_CFastStringInt_const&,struct_CPlugFileImg::SDesc_const&>;

struct CFastCallback3P<class_CFastStringInt_const&,class_CFastStringInt_const&,struct_CPlugFileImg::SDesc_const&> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToySea SMwParamInfos_CSceneToySea, *PSMwParamInfos_CSceneToySea;

struct SMwParamInfos_CSceneToySea {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnChallenge SMwParamInfos_CGameCtnChallenge, *PSMwParamInfos_CGameCtnChallenge;

struct SMwParamInfos_CGameCtnChallenge {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_> CFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCalendarEvent>_> {
    undefined field0_0x0;
};

typedef struct _CRT_DOUBLE _CRT_DOUBLE, *P_CRT_DOUBLE;

struct _CRT_DOUBLE {
    double x;
};

typedef struct CCallbackComputeForcesSpeedBoat CCallbackComputeForcesSpeedBoat, *PCCallbackComputeForcesSpeedBoat;

struct CCallbackComputeForcesSpeedBoat {
    undefined field0_0x0;
};

typedef struct vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_>, *Pvector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_>;

struct vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> {
    undefined field0_0x0;
};

typedef struct CGameControlCardCtnGhost CGameControlCardCtnGhost, *PCGameControlCardCtnGhost;

struct CGameControlCardCtnGhost {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCursor SMwParamInfos_CGameCtnCursor, *PSMwParamInfos_CGameCtnCursor;

struct SMwParamInfos_CGameCtnCursor {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_19 - /winnt.h/_struct_19 */

typedef struct SMwParamInfos_CControlSlider SMwParamInfos_CControlSlider, *PSMwParamInfos_CControlSlider;

struct SMwParamInfos_CControlSlider {
    undefined field0_0x0;
};

typedef struct SPagesOnClient SPagesOnClient, *PSPagesOnClient;

struct SPagesOnClient {
    undefined field0_0x0;
};

typedef enum EProtocol {
} EProtocol;

typedef struct CGameEngine CGameEngine, *PCGameEngine;

struct CGameEngine {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_23 - /winnt.h/_struct_23 */


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_20 - /winnt.h/_struct_20 */


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_struct_22 - /winnt.h/_struct_22 */

typedef struct CSceneConfig CSceneConfig, *PCSceneConfig;

struct CSceneConfig {
    undefined field0_0x0;
};

typedef struct CFuncGroup CFuncGroup, *PCFuncGroup;

struct CFuncGroup {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleEmitter>_> CFastBuffer<class_CMwNodRef<class_CSceneVehicleEmitter>_>, *PCFastBuffer<class_CMwNodRef<class_CSceneVehicleEmitter>_>;

struct CFastBuffer<class_CMwNodRef<class_CSceneVehicleEmitter>_> {
    undefined field0_0x0;
};

typedef struct CMwCmdExpNum CMwCmdExpNum, *PCMwCmdExpNum;

struct CMwCmdExpNum {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionBone SMwParamInfos_CMotionBone, *PSMwParamInfos_CMotionBone;

struct SMwParamInfos_CMotionBone {
    undefined field0_0x0;
};

typedef struct CGameCtnNetForm CGameCtnNetForm, *PCGameCtnNetForm;

struct CGameCtnNetForm {
    undefined field0_0x0;
};

typedef struct CXmlText CXmlText, *PCXmlText;

struct CXmlText {
    undefined field0_0x0;
};

typedef struct SParam_Fids SParam_Fids, *PSParam_Fids;

struct SParam_Fids {
    undefined field0_0x0;
};

typedef struct SRecipient SRecipient, *PSRecipient;

struct SRecipient {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdScriptVarIso4 SMwParamInfos_CMwCmdScriptVarIso4, *PSMwParamInfos_CMwCmdScriptVarIso4;

struct SMwParamInfos_CMwCmdScriptVarIso4 {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlockFxBlurDepth CMwClassInfoCGameCtnMediaBlockFxBlurDepth, *PCMwClassInfoCGameCtnMediaBlockFxBlurDepth;

struct CMwClassInfoCGameCtnMediaBlockFxBlurDepth {
    undefined field0_0x0;
};

typedef enum EFormat {
} EFormat;

typedef struct CTrackManiaBench CTrackManiaBench, *PCTrackManiaBench;

struct CTrackManiaBench {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CPlugModelLodMesh> CFastBufferRef<class_CPlugModelLodMesh>, *PCFastBufferRef<class_CPlugModelLodMesh>;

struct CFastBufferRef<class_CPlugModelLodMesh> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SOldCutKey2> CFastBuffer<struct_SOldCutKey2>, *PCFastBuffer<struct_SOldCutKey2>;

struct CFastBuffer<struct_SOldCutKey2> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_COalDevice SMwParamInfos_COalDevice, *PSMwParamInfos_COalDevice;

struct SMwParamInfos_COalDevice {
    undefined field0_0x0;
};

typedef struct SRpcPlayerInfo SRpcPlayerInfo, *PSRpcPlayerInfo;

struct SRpcPlayerInfo {
    undefined field0_0x0;
};

typedef struct _Vector_iterator<int,class_std::allocator<int>_> _Vector_iterator<int,class_std::allocator<int>_>, *P_Vector_iterator<int,class_std::allocator<int>_>;

struct _Vector_iterator<int,class_std::allocator<int>_> {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugVertexStream::SDataDecl> CFastArray<struct_CPlugVertexStream::SDataDecl>, *PCFastArray<struct_CPlugVertexStream::SDataDecl>;

struct CFastArray<struct_CPlugVertexStream::SDataDecl> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTimerLoop SMwParamInfos_CMotionTimerLoop, *PSMwParamInfos_CMotionTimerLoop;

struct SMwParamInfos_CMotionTimerLoop {
    undefined field0_0x0;
};

typedef struct CXmlComment CXmlComment, *PCXmlComment;

struct CXmlComment {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCameraEffect SMwParamInfos_CGameControlCameraEffect, *PSMwParamInfos_CGameControlCameraEffect;

struct SMwParamInfos_CGameControlCameraEffect {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLightPoint SMwParamInfos_GxLightPoint, *PSMwParamInfos_GxLightPoint;

struct SMwParamInfos_GxLightPoint {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,4,unsigned_long> CFixedArray<unsigned_long,4,unsigned_long>, *PCFixedArray<unsigned_long,4,unsigned_long>;

struct CFixedArray<unsigned_long,4,unsigned_long> {
    undefined field0_0x0;
};

typedef struct GmMat42 GmMat42, *PGmMat42;

struct GmMat42 {
    undefined field0_0x0;
};

typedef struct CGameHighScore CGameHighScore, *PCGameHighScore;

struct CGameHighScore {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemFid SMwParamInfos_CSystemFid, *PSMwParamInfos_CSystemFid;

struct SMwParamInfos_CSystemFid {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CPlugFilePHlsl> CMwNodRef<class_CPlugFilePHlsl>, *PCMwNodRef<class_CPlugFilePHlsl>;

struct CMwNodRef<class_CPlugFilePHlsl> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugShaderApply SMwParamInfos_CPlugShaderApply, *PSMwParamInfos_CPlugShaderApply;

struct SMwParamInfos_CPlugShaderApply {
    undefined field0_0x0;
};

typedef struct GmMat3 GmMat3, *PGmMat3;

struct GmMat3 {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum_EPlugGpuPipeline,218,unsigned_long> CFixedArray<enum_EPlugGpuPipeline,218,unsigned_long>, *PCFixedArray<enum_EPlugGpuPipeline,218,unsigned_long>;

struct CFixedArray<enum_EPlugGpuPipeline,218,unsigned_long> {
    undefined field0_0x0;
};

typedef enum EContactInterest {
} EContactInterest;

typedef struct SSpecularHighlight SSpecularHighlight, *PSSpecularHighlight;

struct SSpecularHighlight {
    undefined field0_0x0;
};

typedef struct CHdrDocument CHdrDocument, *PCHdrDocument;

struct CHdrDocument {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxSuperSample SMwParamInfos_CSceneFxSuperSample, *PSMwParamInfos_CSceneFxSuperSample;

struct SMwParamInfos_CSceneFxSuperSample {
    undefined field0_0x0;
};

typedef struct CMwCmdExpBoolIdent CMwCmdExpBoolIdent, *PCMwCmdExpBoolIdent;

struct CMwCmdExpBoolIdent {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnCampaign SMwParamInfos_CGameControlCardCtnCampaign, *PSMwParamInfos_CGameControlCardCtnCampaign;

struct SMwParamInfos_CGameControlCardCtnCampaign {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/_CONSOLE_READCONSOLE_CONTROL - /wincon.h/_CONSOLE_READCONSOLE_CONTROL */

typedef struct CAudioSoundEngine_Mixer CAudioSoundEngine_Mixer, *PCAudioSoundEngine_Mixer;

struct CAudioSoundEngine_Mixer {
    undefined field0_0x0;
};

typedef struct CFastArray<class_CSceneToySeaHoule*> CFastArray<class_CSceneToySeaHoule*>, *PCFastArray<class_CSceneToySeaHoule*>;

struct CFastArray<class_CSceneToySeaHoule*> {
    undefined field0_0x0;
};

typedef struct SSortKeyReal SSortKeyReal, *PSSortKeyReal;

struct SSortKeyReal {
    undefined field0_0x0;
};

typedef struct CMwNoRecur CMwNoRecur, *PCMwNoRecur;

struct CMwNoRecur {
    undefined field0_0x0;
};

typedef struct CFastBuffer<int> CFastBuffer<int>, *PCFastBuffer<int>;

struct CFastBuffer<int> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLightDirectional SMwParamInfos_GxLightDirectional, *PSMwParamInfos_GxLightDirectional;

struct SMwParamInfos_GxLightDirectional {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsPicker SMwParamInfos_CHmsPicker, *PSMwParamInfos_CHmsPicker;

struct SMwParamInfos_CHmsPicker {
    undefined field0_0x0;
};

typedef struct GmIso4 GmIso4, *PGmIso4;

struct GmIso4 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneMobilLeaves SMwParamInfos_CSceneMobilLeaves, *PSMwParamInfos_CSceneMobilLeaves;

struct SMwParamInfos_CSceneMobilLeaves {
    undefined field0_0x0;
};

typedef struct CClassicBuffer CClassicBuffer, *PCClassicBuffer;

struct CClassicBuffer {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameControlGridCard::SCachedPageCards> CFastBuffer<struct_CGameControlGridCard::SCachedPageCards>, *PCFastBuffer<struct_CGameControlGridCard::SCachedPageCards>;

struct CFastBuffer<struct_CGameControlGridCard::SCachedPageCards> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamQuat SMwParamInfos_CMwParamQuat, *PSMwParamInfos_CMwParamQuat;

struct SMwParamInfos_CMwParamQuat {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_GmIso4,struct_SFastCat> CFastBufferCat<class_GmIso4,struct_SFastCat>, *PCFastBufferCat<class_GmIso4,struct_SFastCat>;

struct CFastBufferCat<class_GmIso4,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsPortal SMwParamInfos_CHmsPortal, *PSMwParamInfos_CHmsPortal;

struct SMwParamInfos_CHmsPortal {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal>, *PCFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal>;

struct CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleGlider SMwParamInfos_CSceneVehicleGlider, *PSMwParamInfos_CSceneVehicleGlider;

struct SMwParamInfos_CSceneVehicleGlider {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmInt4> CFastBuffer<class_GmInt4>, *PCFastBuffer<class_GmInt4>;

struct CFastBuffer<class_GmInt4> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaTrack SMwParamInfos_CGameCtnMediaTrack, *PSMwParamInfos_CGameCtnMediaTrack;

struct SMwParamInfos_CGameCtnMediaTrack {
    undefined field0_0x0;
};

typedef struct CInputPort CInputPort, *PCInputPort;

struct CInputPort {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugVisualGrid SMwParamInfos_CPlugVisualGrid, *PSMwParamInfos_CPlugVisualGrid;

struct SMwParamInfos_CPlugVisualGrid {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionCmdBase SMwParamInfos_CMotionCmdBase, *PSMwParamInfos_CMotionCmdBase;

struct SMwParamInfos_CMotionCmdBase {
    undefined field0_0x0;
};

typedef struct CImplementation CImplementation, *PCImplementation;

struct CImplementation {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetURLSource SMwParamInfos_CNetURLSource, *PSMwParamInfos_CNetURLSource;

struct SMwParamInfos_CNetURLSource {
    undefined field0_0x0;
};

typedef enum EActionMapType {
} EActionMapType;

typedef struct SMwParamInfos_CPlugSurfaceGeom SMwParamInfos_CPlugSurfaceGeom, *PSMwParamInfos_CPlugSurfaceGeom;

struct SMwParamInfos_CPlugSurfaceGeom {
    undefined field0_0x0;
};

typedef struct CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>, *PCFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>;

struct CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> {
    undefined field0_0x0;
};

typedef struct SFavouriteInfo SFavouriteInfo, *PSFavouriteInfo;

struct SFavouriteInfo {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CGameCtnGhost> CMwNodRef<class_CGameCtnGhost>, *PCMwNodRef<class_CGameCtnGhost>;

struct CMwNodRef<class_CGameCtnGhost> {
    undefined field0_0x0;
};

typedef struct STmRaceLowFps STmRaceLowFps, *PSTmRaceLowFps;

struct STmRaceLowFps {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CPlugVisual::SSubVisual> CFastArray<struct_CPlugVisual::SSubVisual>, *PCFastArray<struct_CPlugVisual::SSubVisual>;

struct CFastArray<struct_CPlugVisual::SSubVisual> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameChallengeScores::SFilteredInfos*> CFastBuffer<struct_CGameChallengeScores::SFilteredInfos*>, *PCFastBuffer<struct_CGameChallengeScores::SFilteredInfos*>;

struct CFastBuffer<struct_CGameChallengeScores::SFilteredInfos*> {
    undefined field0_0x0;
};

typedef struct GmSpring<class_GmVec3> GmSpring<class_GmVec3>, *PGmSpring<class_GmVec3>;

struct GmSpring<class_GmVec3> {
    undefined field0_0x0;
};

typedef enum EGmSurfType {
} EGmSurfType;

typedef struct CFastCallback1P<struct_SControlUrlLink_const&> CFastCallback1P<struct_SControlUrlLink_const&>, *PCFastCallback1P<struct_SControlUrlLink_const&>;

struct CFastCallback1P<struct_SControlUrlLink_const&> {
    undefined field0_0x0;
};

typedef struct GmSurfTriangle GmSurfTriangle, *PGmSurfTriangle;

struct GmSurfTriangle {
    undefined field0_0x0;
};

typedef struct CGameCtnMediaClipPlayer CGameCtnMediaClipPlayer, *PCGameCtnMediaClipPlayer;

struct CGameCtnMediaClipPlayer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFontBitmap SMwParamInfos_CPlugFontBitmap, *PSMwParamInfos_CPlugFontBitmap;

struct SMwParamInfos_CPlugFontBitmap {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamMwId> CMwParamFastArray<class_CMwParamMwId>, *PCMwParamFastArray<class_CMwParamMwId>;

struct CMwParamFastArray<class_CMwParamMwId> {
    undefined field0_0x0;
};

typedef enum EKey_IsCrypted {
} EKey_IsCrypted;

typedef enum ERpmState {
} ERpmState;

typedef struct CControlColorChooser CControlColorChooser, *PCControlColorChooser;

struct CControlColorChooser {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTrack SMwParamInfos_CMotionTrack, *PSMwParamInfos_CMotionTrack;

struct SMwParamInfos_CMotionTrack {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardProfile SMwParamInfos_CGameControlCardProfile, *PSMwParamInfos_CGameControlCardProfile;

struct SMwParamInfos_CGameControlCardProfile {
    undefined field0_0x0;
};

typedef struct CCallbackSceneVehicleCarComputeForces CCallbackSceneVehicleCarComputeForces, *PCCallbackSceneVehicleCarComputeForces;

struct CCallbackSceneVehicleCarComputeForces {
    undefined field0_0x0;
};

typedef struct GmSurfEllipsoid GmSurfEllipsoid, *PGmSurfEllipsoid;

struct GmSurfEllipsoid {
    undefined field0_0x0;
};

typedef struct CFuncManagerCharacter CFuncManagerCharacter, *PCFuncManagerCharacter;

struct CFuncManagerCharacter {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,2,unsigned_long> CFixedArray<unsigned_long,2,unsigned_long>, *PCFixedArray<unsigned_long,2,unsigned_long>;

struct CFixedArray<unsigned_long,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CGameMobil> CFastBufferRef<class_CGameMobil>, *PCFastBufferRef<class_CGameMobil>;

struct CFastBufferRef<class_CGameMobil> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameRemoteBufferDataInfoRankings SMwParamInfos_CGameRemoteBufferDataInfoRankings, *PSMwParamInfos_CGameRemoteBufferDataInfoRankings;

struct SMwParamInfos_CGameRemoteBufferDataInfoRankings {
    undefined field0_0x0;
};

typedef struct CNetEngine CNetEngine, *PCNetEngine;

struct CNetEngine {
    undefined field0_0x0;
};

typedef struct SLevel SLevel, *PSLevel;

struct SLevel {
    undefined field0_0x0;
};

typedef struct SOfficialRecordState SOfficialRecordState, *PSOfficialRecordState;

struct SOfficialRecordState {
    undefined field0_0x0;
};

typedef struct CFixedArrayParam<char_const*,1> CFixedArrayParam<char_const*,1>, *PCFixedArrayParam<char_const*,1>;

struct CFixedArrayParam<char_const*,1> {
    undefined field0_0x0;
};

typedef struct basic_ostream<char,struct_std::char_traits<char>_> basic_ostream<char,struct_std::char_traits<char>_>, *Pbasic_ostream<char,struct_std::char_traits<char>_>;

struct basic_ostream<char,struct_std::char_traits<char>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnGhostInfo SMwParamInfos_CGameControlCardCtnGhostInfo, *PSMwParamInfos_CGameControlCardCtnGhostInfo;

struct SMwParamInfos_CGameControlCardCtnGhostInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyFilaments SMwParamInfos_CSceneToyFilaments, *PSMwParamInfos_CSceneToyFilaments;

struct SMwParamInfos_CSceneToyFilaments {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SLodMeshGroup> CFastBuffer<struct_SLodMeshGroup>, *PCFastBuffer<struct_SLodMeshGroup>;

struct CFastBuffer<struct_SLodMeshGroup> {
    undefined field0_0x0;
};

typedef enum EUnlocks {
} EUnlocks;

typedef enum EMaterialMode {
} EMaterialMode;

typedef struct SMwParamInfos_CMotionEmitterParticles SMwParamInfos_CMotionEmitterParticles, *PSMwParamInfos_CMotionEmitterParticles;

struct SMwParamInfos_CMotionEmitterParticles {
    undefined field0_0x0;
};

typedef enum ESurface {
} ESurface;

typedef struct SGxPixRect SGxPixRect, *PSGxPixRect;

struct SGxPixRect {
    undefined field0_0x0;
};

typedef struct CHmsShadowGroup CHmsShadowGroup, *PCHmsShadowGroup;

struct CHmsShadowGroup {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CGameNetwork::SVoteSpecificRatio> CFastArray<struct_CGameNetwork::SVoteSpecificRatio>, *PCFastArray<struct_CGameNetwork::SVoteSpecificRatio>;

struct CFastArray<struct_CGameNetwork::SVoteSpecificRatio> {
    undefined field0_0x0;
};

typedef struct SCampaignMedals SCampaignMedals, *PSCampaignMedals;

struct SCampaignMedals {
    undefined field0_0x0;
};

typedef enum ENormalFormat {
} ENormalFormat;

typedef enum EParamType {
} EParamType;

typedef enum EStackType {
} EStackType;

typedef struct CMwNodRef<class_CGameNetOnlineMessage> CMwNodRef<class_CGameNetOnlineMessage>, *PCMwNodRef<class_CGameNetOnlineMessage>;

struct CMwNodRef<class_CGameNetOnlineMessage> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSound SMwParamInfos_CPlugSound, *PSMwParamInfos_CPlugSound;

struct SMwParamInfos_CPlugSound {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CSystemFid*,6,unsigned_long> CFixedArray<class_CSystemFid*,6,unsigned_long>, *PCFixedArray<class_CSystemFid*,6,unsigned_long>;

struct CFixedArray<class_CSystemFid*,6,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFastBufferKey<struct_SDummy> CFastBufferKey<struct_SDummy>, *PCFastBufferKey<struct_SDummy>;

struct CFastBufferKey<struct_SDummy> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameHighScore SMwParamInfos_CGameHighScore, *PSMwParamInfos_CGameHighScore;

struct SMwParamInfos_CGameHighScore {
    undefined field0_0x0;
};

typedef struct GmMat2 GmMat2, *PGmMat2;

struct GmMat2 {
    undefined field0_0x0;
};

typedef struct CNetMasterServer CNetMasterServer, *PCNetMasterServer;

struct CNetMasterServer {
    undefined field0_0x0;
};

typedef enum EAdvertisingMode {
} EAdvertisingMode;

typedef struct CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores> CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores>, *PCFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores>;

struct CFastBuffer<struct_CTrackManiaNetwork::SRpcForcedScores> {
    undefined field0_0x0;
};

typedef enum EInterfaceMusic {
} EInterfaceMusic;

typedef struct CFastBufferRef<class_CSceneFxBloomData> CFastBufferRef<class_CSceneFxBloomData>, *PCFastBufferRef<class_CSceneFxBloomData>;

struct CFastBufferRef<class_CSceneFxBloomData> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSoundMulti SMwParamInfos_CPlugSoundMulti, *PSMwParamInfos_CPlugSoundMulti;

struct SMwParamInfos_CPlugSoundMulti {
    undefined field0_0x0;
};

typedef struct CMotionTrackMobilScale CMotionTrackMobilScale, *PCMotionTrackMobilScale;

struct CMotionTrackMobilScale {
    undefined field0_0x0;
};

typedef struct CMwClassInfoCGameCtnMediaBlock CMwClassInfoCGameCtnMediaBlock, *PCMwClassInfoCGameCtnMediaBlock;

struct CMwClassInfoCGameCtnMediaBlock {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>, *PCFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert>;

struct CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> {
    undefined field0_0x0;
};

typedef enum _D3DMULTISAMPLE_TYPE {
} _D3DMULTISAMPLE_TYPE;

typedef struct SMwParamInfos_CSystemEngine SMwParamInfos_CSystemEngine, *PSMwParamInfos_CSystemEngine;

struct SMwParamInfos_CSystemEngine {
    undefined field0_0x0;
};

typedef struct CTrackManiaRaceScore CTrackManiaRaceScore, *PCTrackManiaRaceScore;

struct CTrackManiaRaceScore {
    undefined field0_0x0;
};

typedef struct CFastCallbackInstance3P<class_CNetMasterServer,class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> CFastCallbackInstance3P<class_CNetMasterServer,class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>, *PCFastCallbackInstance3P<class_CNetMasterServer,class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>;

struct CFastCallbackInstance3P<class_CNetMasterServer,class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> {
    undefined field0_0x0;
};

typedef struct SVehicleSimpleState_ReplayAfter211003 SVehicleSimpleState_ReplayAfter211003, *PSVehicleSimpleState_ReplayAfter211003;

struct SVehicleSimpleState_ReplayAfter211003 {
    undefined field0_0x0;
};

typedef enum EListMap2ControlType {
} EListMap2ControlType;

typedef struct SBumpNormalFromHeight SBumpNormalFromHeight, *PSBumpNormalFromHeight;

struct SBumpNormalFromHeight {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToySeaHoule SMwParamInfos_CSceneToySeaHoule, *PSMwParamInfos_CSceneToySeaHoule;

struct SMwParamInfos_CSceneToySeaHoule {
    undefined field0_0x0;
};

typedef struct _String_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_> _String_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_>, *P_String_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_>;

struct _String_iterator<char,struct_std::char_traits<char>,class_std::allocator<char>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncColor SMwParamInfos_CFuncColor, *PSMwParamInfos_CFuncColor;

struct SMwParamInfos_CFuncColor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsZoneOverlay SMwParamInfos_CHmsZoneOverlay, *PSMwParamInfos_CHmsZoneOverlay;

struct SMwParamInfos_CHmsZoneOverlay {
    undefined field0_0x0;
};

typedef struct CControlTrackManiaTeamCard CControlTrackManiaTeamCard, *PCControlTrackManiaTeamCard;

struct CControlTrackManiaTeamCard {
    undefined field0_0x0;
};

typedef struct CHmsAmbientOcc CHmsAmbientOcc, *PCHmsAmbientOcc;

struct CHmsAmbientOcc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaPlayerProfile SMwParamInfos_CTrackManiaPlayerProfile, *PSMwParamInfos_CTrackManiaPlayerProfile;

struct SMwParamInfos_CTrackManiaPlayerProfile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaClipViewer SMwParamInfos_CGameCtnMediaClipViewer, *PSMwParamInfos_CGameCtnMediaClipViewer;

struct SMwParamInfos_CGameCtnMediaClipViewer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnDecorationTerrainModifier SMwParamInfos_CGameCtnDecorationTerrainModifier, *PSMwParamInfos_CGameCtnDecorationTerrainModifier;

struct SMwParamInfos_CGameCtnDecorationTerrainModifier {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamVec2 SMwParamInfos_CMwParamVec2, *PSMwParamInfos_CMwParamVec2;

struct SMwParamInfos_CMwParamVec2 {
    undefined field0_0x0;
};

typedef struct CMwParamFastArray<class_CMwParamVec4> CMwParamFastArray<class_CMwParamVec4>, *PCMwParamFastArray<class_CMwParamVec4>;

struct CMwParamFastArray<class_CMwParamVec4> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamVec3 SMwParamInfos_CMwParamVec3, *PSMwParamInfos_CMwParamVec3;

struct SMwParamInfos_CMwParamVec3 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamVec4 SMwParamInfos_CMwParamVec4, *PSMwParamInfos_CMwParamVec4;

struct SMwParamInfos_CMwParamVec4 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatTeamActionDesc SMwParamInfos_CBoatTeamActionDesc, *PSMwParamInfos_CBoatTeamActionDesc;

struct SMwParamInfos_CBoatTeamActionDesc {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CControlContainer*> CFastBuffer<class_CControlContainer*>, *PCFastBuffer<class_CControlContainer*>;

struct CFastBuffer<class_CControlContainer*> {
    undefined field0_0x0;
};

typedef struct CNetFileTransferDataToWrite CNetFileTransferDataToWrite, *PCNetFileTransferDataToWrite;

struct CNetFileTransferDataToWrite {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaVideoParams SMwParamInfos_CGameCtnMediaVideoParams, *PSMwParamInfos_CGameCtnMediaVideoParams;

struct SMwParamInfos_CGameCtnMediaVideoParams {
    undefined field0_0x0;
};

typedef struct CSceneToyCharacter CSceneToyCharacter, *PCSceneToyCharacter;

struct CSceneToyCharacter {
    undefined field0_0x0;
};

typedef struct CMwCmdBufferCore CMwCmdBufferCore, *PCMwCmdBufferCore;

struct CMwCmdBufferCore {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnDecorationSize SMwParamInfos_CGameCtnDecorationSize, *PSMwParamInfos_CGameCtnDecorationSize;

struct SMwParamInfos_CGameCtnDecorationSize {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemWindow SMwParamInfos_CSystemWindow, *PSMwParamInfos_CSystemWindow;

struct SMwParamInfos_CSystemWindow {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SSceneLoc> CFastBuffer<struct_SSceneLoc>, *PCFastBuffer<struct_SSceneLoc>;

struct CFastBuffer<struct_SSceneLoc> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnArticle SMwParamInfos_CGameControlCardCtnArticle, *PSMwParamInfos_CGameControlCardCtnArticle;

struct SMwParamInfos_CGameControlCardCtnArticle {
    undefined field0_0x0;
};

typedef enum TiXmlEncoding {
} TiXmlEncoding;

typedef struct CGameRemoteBufferPool CGameRemoteBufferPool, *PCGameRemoteBufferPool;

struct CGameRemoteBufferPool {
    undefined field0_0x0;
};

typedef struct CPlugVisualIndexedLines CPlugVisualIndexedLines, *PCPlugVisualIndexedLines;

struct CPlugVisualIndexedLines {
    undefined field0_0x0;
};

typedef struct CFixedArray<unsigned_long,10,unsigned_long> CFixedArray<unsigned_long,10,unsigned_long>, *PCFixedArray<unsigned_long,10,unsigned_long>;

struct CFixedArray<unsigned_long,10,unsigned_long> {
    undefined field0_0x0;
};

typedef enum EStdGpuV {
} EStdGpuV;

typedef struct CMotionManagerParticles CMotionManagerParticles, *PCMotionManagerParticles;

struct CMotionManagerParticles {
    undefined field0_0x0;
};

typedef enum EStdGpuP {
} EStdGpuP;

typedef struct GmCamVal GmCamVal, *PGmCamVal;

struct GmCamVal {
    undefined field0_0x0;
};

typedef struct SFastCat SFastCat, *PSFastCat;

struct SFastCat {
    undefined field0_0x0;
};

typedef struct SFolderDesc SFolderDesc, *PSFolderDesc;

struct SFolderDesc {
    undefined field0_0x0;
};

typedef struct CMotionPlaySound CMotionPlaySound, *PCMotionPlaySound;

struct CMotionPlaySound {
    undefined field0_0x0;
};

typedef struct CStridedArray<unsigned_char> CStridedArray<unsigned_char>, *PCStridedArray<unsigned_char>;

struct CStridedArray<unsigned_char> {
    undefined field0_0x0;
};

typedef struct CGameNetFormCallVote CGameNetFormCallVote, *PCGameNetFormCallVote;

struct CGameNetFormCallVote {
    undefined field0_0x0;
};

typedef struct CGbxApp CGbxApp, *PCGbxApp;

struct CGbxApp {
    undefined field0_0x0;
};

typedef struct CCurveInterface CCurveInterface, *PCCurveInterface;

struct CCurveInterface {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncGroupElem SMwParamInfos_CFuncGroupElem, *PSMwParamInfos_CFuncGroupElem;

struct SMwParamInfos_CFuncGroupElem {
    undefined field0_0x0;
};

typedef struct StaticInit StaticInit, *PStaticInit;

struct StaticInit {
    undefined field0_0x0;
};

typedef struct CFixedArray<enum__D3DDECLTYPE,17,unsigned_long> CFixedArray<enum__D3DDECLTYPE,17,unsigned_long>, *PCFixedArray<enum__D3DDECLTYPE,17,unsigned_long>;

struct CFixedArray<enum__D3DDECLTYPE,17,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwId,12,unsigned_long> CFixedArray<class_CMwId,12,unsigned_long>, *PCFixedArray<class_CMwId,12,unsigned_long>;

struct CFixedArray<class_CMwId,12,unsigned_long> {
    undefined field0_0x0;
};

typedef struct TiXmlDeclaration TiXmlDeclaration, *PTiXmlDeclaration;

struct TiXmlDeclaration {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBlendShapes SMwParamInfos_CPlugBlendShapes, *PSMwParamInfos_CPlugBlendShapes;

struct SMwParamInfos_CPlugBlendShapes {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlLayout SMwParamInfos_CControlLayout, *PSMwParamInfos_CControlLayout;

struct SMwParamInfos_CControlLayout {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameLadderRanking SMwParamInfos_CGameLadderRanking, *PSMwParamInfos_CGameLadderRanking;

struct SMwParamInfos_CGameLadderRanking {
    undefined field0_0x0;
};

typedef struct CMwNodRef<class_CSceneVehicleEmitter> CMwNodRef<class_CSceneVehicleEmitter>, *PCMwNodRef<class_CSceneVehicleEmitter>;

struct CMwNodRef<class_CSceneVehicleEmitter> {
    undefined field0_0x0;
};

typedef struct CFuncEnvelope CFuncEnvelope, *PCFuncEnvelope;

struct CFuncEnvelope {
    undefined field0_0x0;
};

typedef struct CSceneMobilSnow CSceneMobilSnow, *PCSceneMobilSnow;

struct CSceneMobilSnow {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugDecoratorTree SMwParamInfos_CPlugDecoratorTree, *PSMwParamInfos_CPlugDecoratorTree;

struct SMwParamInfos_CPlugDecoratorTree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioBufferKeeper SMwParamInfos_CAudioBufferKeeper, *PSMwParamInfos_CAudioBufferKeeper;

struct SMwParamInfos_CAudioBufferKeeper {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlUiDockable SMwParamInfos_CControlUiDockable, *PSMwParamInfos_CControlUiDockable;

struct SMwParamInfos_CControlUiDockable {
    undefined field0_0x0;
};

typedef struct SPartGroupEmitter SPartGroupEmitter, *PSPartGroupEmitter;

struct SPartGroupEmitter {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CPlugSolid>_> CFastBuffer<class_CMwNodRef<class_CPlugSolid>_>, *PCFastBuffer<class_CMwNodRef<class_CPlugSolid>_>;

struct CFastBuffer<class_CMwNodRef<class_CPlugSolid>_> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnZone SMwParamInfos_CGameCtnZone, *PSMwParamInfos_CGameCtnZone;

struct SMwParamInfos_CGameCtnZone {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> CFastBuffer<struct_CVisionViewport::SDelayedToSort64b>, *PCFastBuffer<struct_CVisionViewport::SDelayedToSort64b>;

struct CFastBuffer<struct_CVisionViewport::SDelayedToSort64b> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameBulletModel SMwParamInfos_CGameBulletModel, *PSMwParamInfos_CGameBulletModel;

struct SMwParamInfos_CGameBulletModel {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTeamAction SMwParamInfos_CMotionTeamAction, *PSMwParamInfos_CMotionTeamAction;

struct SMwParamInfos_CMotionTeamAction {
    undefined field0_0x0;
};

typedef enum EAntialias {
} EAntialias;

typedef struct SPart SPart, *PSPart;

struct SPart {
    undefined field0_0x0;
};

typedef struct CHmsOcclusion CHmsOcclusion, *PCHmsOcclusion;

struct CHmsOcclusion {
    undefined field0_0x0;
};

typedef struct CGameControlCardNetOnlineEvent CGameControlCardNetOnlineEvent, *PCGameControlCardNetOnlineEvent;

struct CGameControlCardNetOnlineEvent {
    undefined field0_0x0;
};

typedef enum EVertexColor {
} EVertexColor;

typedef struct SMwParamInfos_CMwCmdScriptVarClass SMwParamInfos_CMwCmdScriptVarClass, *PSMwParamInfos_CMwCmdScriptVarClass;

struct SMwParamInfos_CMwCmdScriptVarClass {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CMwNodRef<class_CGameCtnDecorationTerrainModifier>_> CFastBuffer<class_CMwNodRef<class_CGameCtnDecorationTerrainModifier>_>, *PCFastBuffer<class_CMwNodRef<class_CGameCtnDecorationTerrainModifier>_>;

struct CFastBuffer<class_CMwNodRef<class_CGameCtnDecorationTerrainModifier>_> {
    undefined field0_0x0;
};

typedef struct CGameNetFormTimeSync CGameNetFormTimeSync, *PCGameNetFormTimeSync;

struct CGameNetFormTimeSync {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsCorpusLight SMwParamInfos_CHmsCorpusLight, *PSMwParamInfos_CHmsCorpusLight;

struct SMwParamInfos_CHmsCorpusLight {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGameMasterServerRequestParams::SParam> CFastBuffer<struct_CGameMasterServerRequestParams::SParam>, *PCFastBuffer<struct_CGameMasterServerRequestParams::SParam>;

struct CFastBuffer<struct_CGameMasterServerRequestParams::SParam> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderHemisphere SMwParamInfos_CPlugBitmapRenderHemisphere, *PSMwParamInfos_CPlugBitmapRenderHemisphere;

struct SMwParamInfos_CPlugBitmapRenderHemisphere {
    undefined field0_0x0;
};

typedef struct CMwCmdContainer CMwCmdContainer, *PCMwCmdContainer;

struct CMwCmdContainer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CBoatTeamDesc SMwParamInfos_CBoatTeamDesc, *PSMwParamInfos_CBoatTeamDesc;

struct SMwParamInfos_CBoatTeamDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCamera SMwParamInfos_CGameCtnMediaBlockCamera, *PSMwParamInfos_CGameCtnMediaBlockCamera;

struct SMwParamInfos_CGameCtnMediaBlockCamera {
    undefined field0_0x0;
};

typedef struct CControlEngine CControlEngine, *PCControlEngine;

struct CControlEngine {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockInfo CGameCtnBlockInfo, *PCGameCtnBlockInfo;

struct CGameCtnBlockInfo {
    undefined field0_0x0;
};

typedef struct GmNat2 GmNat2, *PGmNat2;

struct GmNat2 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugModelFences SMwParamInfos_CPlugModelFences, *PSMwParamInfos_CPlugModelFences;

struct SMwParamInfos_CPlugModelFences {
    undefined field0_0x0;
};

typedef struct SRenderFlags SRenderFlags, *PSRenderFlags;

struct SRenderFlags {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CControlBase*> CFastBuffer<class_CControlBase*>, *PCFastBuffer<class_CControlBase*>;

struct CFastBuffer<class_CControlBase*> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CPlugSound*> CFastBuffer<class_CPlugSound*>, *PCFastBuffer<class_CPlugSound*>;

struct CFastBuffer<class_CPlugSound*> {
    undefined field0_0x0;
};

typedef struct CMotionManagerCharacter CMotionManagerCharacter, *PCMotionManagerCharacter;

struct CMotionManagerCharacter {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdWhile SMwParamInfos_CMwCmdWhile, *PSMwParamInfos_CMwCmdWhile;

struct SMwParamInfos_CMwCmdWhile {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlColorChooser2 SMwParamInfos_CControlColorChooser2, *PSMwParamInfos_CControlColorChooser2;

struct SMwParamInfos_CControlColorChooser2 {
    undefined field0_0x0;
};

typedef struct CPlugGpuFxLocator CPlugGpuFxLocator, *PCPlugGpuFxLocator;

struct CPlugGpuFxLocator {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_GmInt3> CFastBuffer<class_GmInt3>, *PCFastBuffer<class_GmInt3>;

struct CFastBuffer<class_GmInt3> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CGamePlayerProfile::SCampaignUnlocks> CFastBuffer<struct_CGamePlayerProfile::SCampaignUnlocks>, *PCFastBuffer<struct_CGamePlayerProfile::SCampaignUnlocks>;

struct CFastBuffer<struct_CGamePlayerProfile::SCampaignUnlocks> {
    undefined field0_0x0;
};

typedef struct CFastBufferRef<class_CSceneGate> CFastBufferRef<class_CSceneGate>, *PCFastBufferRef<class_CSceneGate>;

struct CFastBufferRef<class_CSceneGate> {
    undefined field0_0x0;
};

typedef enum EPitchinMode {
} EPitchinMode;

typedef struct DIDEVICEOBJECTINSTANCEW DIDEVICEOBJECTINSTANCEW, *PDIDEVICEOBJECTINSTANCEW;

struct DIDEVICEOBJECTINSTANCEW {
    undefined field0_0x0;
};

typedef struct SMonth SMonth, *PSMonth;

struct SMonth {
    undefined field0_0x0;
};

typedef struct CSceneVehicleGliderTuning CSceneVehicleGliderTuning, *PCSceneVehicleGliderTuning;

struct CSceneVehicleGliderTuning {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlGridCard SMwParamInfos_CGameControlGridCard, *PSMwParamInfos_CGameControlGridCard;

struct SMwParamInfos_CGameControlGridCard {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEffectMoveFrame SMwParamInfos_CControlEffectMoveFrame, *PSMwParamInfos_CControlEffectMoveFrame;

struct SMwParamInfos_CControlEffectMoveFrame {
    undefined field0_0x0;
};

typedef struct CGameCtnBlockSkin CGameCtnBlockSkin, *PCGameCtnBlockSkin;

struct CGameCtnBlockSkin {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CSystemXmlTools::SStringRemap> CFastBuffer<struct_CSystemXmlTools::SStringRemap>, *PCFastBuffer<struct_CSystemXmlTools::SStringRemap>;

struct CFastBuffer<struct_CSystemXmlTools::SStringRemap> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnChallengeGroup SMwParamInfos_CGameCtnChallengeGroup, *PSMwParamInfos_CGameCtnChallengeGroup;

struct SMwParamInfos_CGameCtnChallengeGroup {
    undefined field0_0x0;
};

typedef enum EDbgLight {
} EDbgLight;

typedef enum ECipher {
} ECipher;

typedef struct CGameLeague CGameLeague, *PCGameLeague;

struct CGameLeague {
    undefined field0_0x0;
};

typedef enum ESkipMode {
} ESkipMode;

typedef struct SMwParamInfos_CGameControlPlayerInput SMwParamInfos_CGameControlPlayerInput, *PSMwParamInfos_CGameControlPlayerInput;

struct SMwParamInfos_CGameControlPlayerInput {
    undefined field0_0x0;
};

typedef enum EParam {
} EParam;

typedef struct SParamFuncShader SParamFuncShader, *PSParamFuncShader;

struct SParamFuncShader {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CFastString,2,unsigned_long> CFixedArray<class_CFastString,2,unsigned_long>, *PCFixedArray<class_CFastString,2,unsigned_long>;

struct CFixedArray<class_CFastString,2,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlStyleSheet SMwParamInfos_CControlStyleSheet, *PSMwParamInfos_CControlStyleSheet;

struct SMwParamInfos_CControlStyleSheet {
    undefined field0_0x0;
};

typedef struct SOldChars SOldChars, *PSOldChars;

struct SOldChars {
    undefined field0_0x0;
};

typedef struct CMwParamIso4 CMwParamIso4, *PCMwParamIso4;

struct CMwParamIso4 {
    undefined field0_0x0;
};

typedef struct CMwParamIso3 CMwParamIso3, *PCMwParamIso3;

struct CMwParamIso3 {
    undefined field0_0x0;
};

typedef struct CFuncKeysVisual CFuncKeysVisual, *PCFuncKeysVisual;

struct CFuncKeysVisual {
    undefined field0_0x0;
};

typedef enum EQuery {
} EQuery;

typedef enum EPlayerInfoArchiveState {
} EPlayerInfoArchiveState;

typedef struct CFastBuffer<class_CGameCtnCampaign*> CFastBuffer<class_CGameCtnCampaign*>, *PCFastBuffer<class_CGameCtnCampaign*>;

struct CFastBuffer<class_CGameCtnCampaign*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFileZip SMwParamInfos_CPlugFileZip, *PSMwParamInfos_CPlugFileZip;

struct SMwParamInfos_CPlugFileZip {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey> CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey>, *PCFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey>;

struct CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlock3dStereo::SKeyVal>::SKey> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncKeysNatural SMwParamInfos_CFuncKeysNatural, *PSMwParamInfos_CFuncKeysNatural;

struct SMwParamInfos_CFuncKeysNatural {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardNetTeamInfo SMwParamInfos_CGameControlCardNetTeamInfo, *PSMwParamInfos_CGameControlCardNetTeamInfo;

struct SMwParamInfos_CGameControlCardNetTeamInfo {
    undefined field0_0x0;
};

typedef struct CPlugModelShell CPlugModelShell, *PCPlugModelShell;

struct CPlugModelShell {
    undefined field0_0x0;
};

typedef struct CFixedArray<struct_SDx9VendorInfo,12,unsigned_long> CFixedArray<struct_SDx9VendorInfo,12,unsigned_long>, *PCFixedArray<struct_SDx9VendorInfo,12,unsigned_long>;

struct CFixedArray<struct_SDx9VendorInfo,12,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugSurface SMwParamInfos_CPlugSurface, *PSMwParamInfos_CPlugSurface;

struct SMwParamInfos_CPlugSurface {
    undefined field0_0x0;
};

typedef struct CSystemDialogManagerWin32 CSystemDialogManagerWin32, *PCSystemDialogManagerWin32;

struct CSystemDialogManagerWin32 {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwParamColor SMwParamInfos_CMwParamColor, *PSMwParamInfos_CMwParamColor;

struct SMwParamInfos_CMwParamColor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioSoundMulti SMwParamInfos_CAudioSoundMulti, *PSMwParamInfos_CAudioSoundMulti;

struct SMwParamInfos_CAudioSoundMulti {
    undefined field0_0x0;
};

typedef struct CMotionWeather CMotionWeather, *PCMotionWeather;

struct CMotionWeather {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CXmlText SMwParamInfos_CXmlText, *PSMwParamInfos_CXmlText;

struct SMwParamInfos_CXmlText {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncLightIntensity SMwParamInfos_CFuncLightIntensity, *PSMwParamInfos_CFuncLightIntensity;

struct SMwParamInfos_CFuncLightIntensity {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyLeash SMwParamInfos_CSceneToyLeash, *PSMwParamInfos_CSceneToyLeash;

struct SMwParamInfos_CSceneToyLeash {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnZoneFlat SMwParamInfos_CGameCtnZoneFlat, *PSMwParamInfos_CGameCtnZoneFlat;

struct SMwParamInfos_CGameCtnZoneFlat {
    undefined field0_0x0;
};

typedef struct CHmsVPackerLevelBase CHmsVPackerLevelBase, *PCHmsVPackerLevelBase;

struct CHmsVPackerLevelBase {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnNetServerInfo SMwParamInfos_CGameControlCardCtnNetServerInfo, *PSMwParamInfos_CGameControlCardCtnNetServerInfo;

struct SMwParamInfos_CGameControlCardCtnNetServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockEditorTriangles SMwParamInfos_CGameCtnMediaBlockEditorTriangles, *PSMwParamInfos_CGameCtnMediaBlockEditorTriangles;

struct SMwParamInfos_CGameCtnMediaBlockEditorTriangles {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapRenderWater SMwParamInfos_CPlugBitmapRenderWater, *PSMwParamInfos_CPlugBitmapRenderWater;

struct SMwParamInfos_CPlugBitmapRenderWater {
    undefined field0_0x0;
};

typedef struct CNetArchive CNetArchive, *PCNetArchive;

struct CNetArchive {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionWindBlocker SMwParamInfos_CMotionWindBlocker, *PSMwParamInfos_CMotionWindBlocker;

struct SMwParamInfos_CMotionWindBlocker {
    undefined field0_0x0;
};

typedef struct GmNat3 GmNat3, *PGmNat3;

struct GmNat3 {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CSceneToySubway::SLineDeform> CFastArray<struct_CSceneToySubway::SLineDeform>, *PCFastArray<struct_CSceneToySubway::SLineDeform>;

struct CFastArray<struct_CSceneToySubway::SLineDeform> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_COalAudioPort SMwParamInfos_COalAudioPort, *PSMwParamInfos_COalAudioPort;

struct SMwParamInfos_COalAudioPort {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsZone SMwParamInfos_CHmsZone, *PSMwParamInfos_CHmsZone;

struct SMwParamInfos_CHmsZone {
    undefined field0_0x0;
};

typedef struct SArrowParam SArrowParam, *PSArrowParam;

struct SArrowParam {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxBloom SMwParamInfos_CSceneFxBloom, *PSMwParamInfos_CSceneFxBloom;

struct SMwParamInfos_CSceneFxBloom {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncFullColorGradient SMwParamInfos_CFuncFullColorGradient, *PSMwParamInfos_CFuncFullColorGradient;

struct SMwParamInfos_CFuncFullColorGradient {
    undefined field0_0x0;
};

typedef struct CGameControlSelection CGameControlSelection, *PCGameControlSelection;

struct CGameControlSelection {
    undefined field0_0x0;
};

typedef struct CGameCtnDecoration CGameCtnDecoration, *PCGameCtnDecoration;

struct CGameCtnDecoration {
    undefined field0_0x0;
};

typedef enum EAllowedVoters {
} EAllowedVoters;

typedef struct SMwParamInfos_CGameControlCardCalendar SMwParamInfos_CGameControlCardCalendar, *PSMwParamInfos_CGameControlCardCalendar;

struct SMwParamInfos_CGameControlCardCalendar {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockInfo SMwParamInfos_CGameCtnBlockInfo, *PSMwParamInfos_CGameCtnBlockInfo;

struct SMwParamInfos_CGameCtnBlockInfo {
    undefined field0_0x0;
};

typedef struct SVertexPixelShaderContext SVertexPixelShaderContext, *PSVertexPixelShaderContext;

struct SVertexPixelShaderContext {
    undefined field0_0x0;
};

typedef enum ETmRaceDispPlayerInfoContext {
} ETmRaceDispPlayerInfoContext;

typedef struct SMwParamInfos_CPlugFileText SMwParamInfos_CPlugFileText, *PSMwParamInfos_CPlugFileText;

struct SMwParamInfos_CPlugFileText {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSystemConfigDisplay SMwParamInfos_CSystemConfigDisplay, *PSMwParamInfos_CSystemConfigDisplay;

struct SMwParamInfos_CSystemConfigDisplay {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagOFNW - /commdlg.h/tagOFNW */

typedef struct SMwParamInfos_CTrackManiaRace2PTurnBased SMwParamInfos_CTrackManiaRace2PTurnBased, *PSMwParamInfos_CTrackManiaRace2PTurnBased;

struct SMwParamInfos_CTrackManiaRace2PTurnBased {
    undefined field0_0x0;
};

typedef struct SSplit SSplit, *PSSplit;

struct SSplit {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockSkin SMwParamInfos_CGameCtnBlockSkin, *PSMwParamInfos_CGameCtnBlockSkin;

struct SMwParamInfos_CGameCtnBlockSkin {
    undefined field0_0x0;
};

typedef struct CMwStack CMwStack, *PCMwStack;

struct CMwStack {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>, *PCFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*>;

struct CFastCallback3P<class_CNetMasterServerRequest*,class_CFastString&,class_TiXmlElement*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameManialinkEntry SMwParamInfos_CGameManialinkEntry, *PSMwParamInfos_CGameManialinkEntry;

struct SMwParamInfos_CGameManialinkEntry {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CScenePoc SMwParamInfos_CScenePoc, *PSMwParamInfos_CScenePoc;

struct SMwParamInfos_CScenePoc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardCtnVehicle SMwParamInfos_CGameControlCardCtnVehicle, *PSMwParamInfos_CGameControlCardCtnVehicle;

struct SMwParamInfos_CGameControlCardCtnVehicle {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>, *PCFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc>;

struct CFastBuffer<struct_CHmsVPackerCell::SLightSpotLoc> {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_SScore*> CFastBuffer<struct_SScore*>, *PCFastBuffer<struct_SScore*>;

struct CFastBuffer<struct_SScore*> {
    undefined field0_0x0;
};

typedef struct CBoatTeamDesc CBoatTeamDesc, *PCBoatTeamDesc;

struct CBoatTeamDesc {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMotionTeamManager SMwParamInfos_CMotionTeamManager, *PSMwParamInfos_CMotionTeamManager;

struct SMwParamInfos_CMotionTeamManager {
    undefined field0_0x0;
};


/* WARNING! conflicting data type names: /TmForeverFixed.pdb/tagBITMAPINFOHEADER - /wingdi.h/tagBITMAPINFOHEADER */

typedef enum ERetCode {
} ERetCode;

typedef struct SMwParamInfos_CMwCmdSwitch SMwParamInfos_CMwCmdSwitch, *PSMwParamInfos_CMwCmdSwitch;

struct SMwParamInfos_CMwCmdSwitch {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdBlock SMwParamInfos_CMwCmdBlock, *PSMwParamInfos_CMwCmdBlock;

struct SMwParamInfos_CMwCmdBlock {
    undefined field0_0x0;
};

typedef struct CFastBuffer<class_CSystemFile*> CFastBuffer<class_CSystemFile*>, *PCFastBuffer<class_CSystemFile*>;

struct CFastBuffer<class_CSystemFile*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugLight SMwParamInfos_CPlugLight, *PSMwParamInfos_CPlugLight;

struct SMwParamInfos_CPlugLight {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnReplayRecord SMwParamInfos_CGameCtnReplayRecord, *PSMwParamInfos_CGameCtnReplayRecord;

struct SMwParamInfos_CGameCtnReplayRecord {
    undefined field0_0x0;
};

typedef struct CFastCallback3P<unsigned_long,unsigned_long,int&> CFastCallback3P<unsigned_long,unsigned_long,int&>, *PCFastCallback3P<unsigned_long,unsigned_long,int&>;

struct CFastCallback3P<unsigned_long,unsigned_long,int&> {
    undefined field0_0x0;
};

typedef struct CNetURLSource CNetURLSource, *PCNetURLSource;

struct CNetURLSource {
    undefined field0_0x0;
};

typedef struct CFastBuffer<struct_CInputEventsStore::SCachedValue> CFastBuffer<struct_CInputEventsStore::SCachedValue>, *PCFastBuffer<struct_CInputEventsStore::SCachedValue>;

struct CFastBuffer<struct_CInputEventsStore::SCachedValue> {
    undefined field0_0x0;
};

typedef enum ESortPosition {
} ESortPosition;

typedef struct CGameCtnMenus CGameCtnMenus, *PCGameCtnMenus;

struct CGameCtnMenus {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockGhost SMwParamInfos_CGameCtnMediaBlockGhost, *PSMwParamInfos_CGameCtnMediaBlockGhost;

struct SMwParamInfos_CGameCtnMediaBlockGhost {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncKeysTransQuat SMwParamInfos_CFuncKeysTransQuat, *PSMwParamInfos_CFuncKeysTransQuat;

struct SMwParamInfos_CFuncKeysTransQuat {
    undefined field0_0x0;
};

typedef enum EDx9VertexProcess {
} EDx9VertexProcess;

typedef struct SMwParamInfos_CPlugVisualSprite SMwParamInfos_CPlugVisualSprite, *PSMwParamInfos_CPlugVisualSprite;

struct SMwParamInfos_CPlugVisualSprite {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraEffect SMwParamInfos_CGameCtnMediaBlockCameraEffect, *PSMwParamInfos_CGameCtnMediaBlockCameraEffect;

struct SMwParamInfos_CGameCtnMediaBlockCameraEffect {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleGliderTuning SMwParamInfos_CSceneVehicleGliderTuning, *PSMwParamInfos_CSceneVehicleGliderTuning;

struct SMwParamInfos_CSceneVehicleGliderTuning {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneFxOccZCmp SMwParamInfos_CSceneFxOccZCmp, *PSMwParamInfos_CSceneFxOccZCmp;

struct SMwParamInfos_CSceneFxOccZCmp {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameDialogs SMwParamInfos_CGameDialogs, *PSMwParamInfos_CGameDialogs;

struct SMwParamInfos_CGameDialogs {
    undefined field0_0x0;
};

typedef enum EReplayGhostVersion {
} EReplayGhostVersion;

typedef struct CFixedArray<enum_EPlugVDclType,22,unsigned_long> CFixedArray<enum_EPlugVDclType,22,unsigned_long>, *PCFixedArray<enum_EPlugVDclType,22,unsigned_long>;

struct CFixedArray<enum_EPlugVDclType,22,unsigned_long> {
    undefined field0_0x0;
};

typedef struct CSystemConfigDisplay CSystemConfigDisplay, *PCSystemConfigDisplay;

struct CSystemConfigDisplay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CTrackManiaControlRaceScoreCard SMwParamInfos_CTrackManiaControlRaceScoreCard, *PSMwParamInfos_CTrackManiaControlRaceScoreCard;

struct SMwParamInfos_CTrackManiaControlRaceScoreCard {
    undefined field0_0x0;
};

typedef enum EEditorStatus {
} EEditorStatus;

typedef struct CFastBuffer<struct_CHmsCameraFx::SBitmapOutput> CFastBuffer<struct_CHmsCameraFx::SBitmapOutput>, *PCFastBuffer<struct_CHmsCameraFx::SBitmapOutput>;

struct CFastBuffer<struct_CHmsCameraFx::SBitmapOutput> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockUnit SMwParamInfos_CGameCtnBlockUnit, *PSMwParamInfos_CGameCtnBlockUnit;

struct SMwParamInfos_CGameCtnBlockUnit {
    undefined field0_0x0;
};

typedef struct CFastArray<struct_CHmsViewport::SDisplayMode> CFastArray<struct_CHmsViewport::SDisplayMode>, *PCFastArray<struct_CHmsViewport::SDisplayMode>;

struct CFastArray<struct_CHmsViewport::SDisplayMode> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneToyCharacterTuning SMwParamInfos_CSceneToyCharacterTuning, *PSMwParamInfos_CSceneToyCharacterTuning;

struct SMwParamInfos_CSceneToyCharacterTuning {
    undefined field0_0x0;
};

typedef struct CHmsItemShadow CHmsItemShadow, *PCHmsItemShadow;

struct CHmsItemShadow {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CHmsViewport SMwParamInfos_CHmsViewport, *PSMwParamInfos_CHmsViewport;

struct SMwParamInfos_CHmsViewport {
    undefined field0_0x0;
};

typedef struct fpos<int> fpos<int>, *Pfpos<int>;

struct fpos<int> {
    undefined field0_0x0;
};

typedef enum EFidType {
} EFidType;

typedef struct SMwParamInfos_CPlugTree SMwParamInfos_CPlugTree, *PSMwParamInfos_CPlugTree;

struct SMwParamInfos_CPlugTree {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlEffectSimi SMwParamInfos_CControlEffectSimi, *PSMwParamInfos_CControlEffectSimi;

struct SMwParamInfos_CControlEffectSimi {
    undefined field0_0x0;
};

typedef enum EDisplayType {
} EDisplayType;

typedef struct SMwParamInfos_CGameCtnBlockInfoFrontier SMwParamInfos_CGameCtnBlockInfoFrontier, *PSMwParamInfos_CGameCtnBlockInfoFrontier;

struct SMwParamInfos_CGameCtnBlockInfoFrontier {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameNetServerInfo SMwParamInfos_CGameNetServerInfo, *PSMwParamInfos_CGameNetServerInfo;

struct SMwParamInfos_CGameNetServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CMwCmdWait SMwParamInfos_CMwCmdWait, *PSMwParamInfos_CMwCmdWait;

struct SMwParamInfos_CMwCmdWait {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CAudioSound SMwParamInfos_CAudioSound, *PSMwParamInfos_CAudioSound;

struct SMwParamInfos_CAudioSound {
    undefined field0_0x0;
};

typedef enum EVehicleEvent {
} EVehicleEvent;

typedef struct CGameCtnMediaBlockCameraEffect CGameCtnMediaBlockCameraEffect, *PCGameCtnMediaBlockCameraEffect;

struct CGameCtnMediaBlockCameraEffect {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncShaderLayerUV SMwParamInfos_CFuncShaderLayerUV, *PSMwParamInfos_CFuncShaderLayerUV;

struct SMwParamInfos_CFuncShaderLayerUV {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugBitmapShader SMwParamInfos_CPlugBitmapShader, *PSMwParamInfos_CPlugBitmapShader;

struct SMwParamInfos_CPlugBitmapShader {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncSegment SMwParamInfos_CFuncSegment, *PSMwParamInfos_CFuncSegment;

struct SMwParamInfos_CFuncSegment {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLightFrustum SMwParamInfos_GxLightFrustum, *PSMwParamInfos_GxLightFrustum;

struct SMwParamInfos_GxLightFrustum {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CFuncKeys SMwParamInfos_CFuncKeys, *PSMwParamInfos_CFuncKeys;

struct SMwParamInfos_CFuncKeys {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneField SMwParamInfos_CSceneField, *PSMwParamInfos_CSceneField;

struct SMwParamInfos_CSceneField {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneGate SMwParamInfos_CSceneGate, *PSMwParamInfos_CSceneGate;

struct SMwParamInfos_CSceneGate {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_GxLightAmbient SMwParamInfos_GxLightAmbient, *PSMwParamInfos_GxLightAmbient;

struct SMwParamInfos_GxLightAmbient {
    undefined field0_0x0;
};

typedef struct CFastCrypt<int> CFastCrypt<int>, *PCFastCrypt<int>;

struct CFastCrypt<int> {
    undefined field0_0x0;
};

typedef enum EDisplayByteSizeUnit {
} EDisplayByteSizeUnit;

typedef struct STechniques STechniques, *PSTechniques;

struct STechniques {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwId,7,unsigned_long> CFixedArray<class_CMwId,7,unsigned_long>, *PCFixedArray<class_CMwId,7,unsigned_long>;

struct CFixedArray<class_CMwId,7,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameMobil SMwParamInfos_CGameMobil, *PSMwParamInfos_CGameMobil;

struct SMwParamInfos_CGameMobil {
    undefined field0_0x0;
};

typedef enum ESaveStateVersion {
} ESaveStateVersion;

typedef struct CFastArray<class_CPlugSoundEngineComponent*> CFastArray<class_CPlugSoundEngineComponent*>, *PCFastArray<class_CPlugSoundEngineComponent*>;

struct CFastArray<class_CPlugSoundEngineComponent*> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnBlockUnitInfo SMwParamInfos_CGameCtnBlockUnitInfo, *PSMwParamInfos_CGameCtnBlockUnitInfo;

struct SMwParamInfos_CGameCtnBlockUnitInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameSafeFrame SMwParamInfos_CGameSafeFrame, *PSMwParamInfos_CGameSafeFrame;

struct SMwParamInfos_CGameSafeFrame {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnNetServerInfo SMwParamInfos_CGameCtnNetServerInfo, *PSMwParamInfos_CGameCtnNetServerInfo;

struct SMwParamInfos_CGameCtnNetServerInfo {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameControlCardNetOnlineEvent SMwParamInfos_CGameControlCardNetOnlineEvent, *PSMwParamInfos_CGameControlCardNetOnlineEvent;

struct SMwParamInfos_CGameControlCardNetOnlineEvent {
    undefined field0_0x0;
};

typedef enum EStreamStatus {
} EStreamStatus;

typedef struct SMwParamInfos_CSceneExtraFlockingCharacters SMwParamInfos_CSceneExtraFlockingCharacters, *PSMwParamInfos_CSceneExtraFlockingCharacters;

struct SMwParamInfos_CSceneExtraFlockingCharacters {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnEditor SMwParamInfos_CGameCtnEditor, *PSMwParamInfos_CGameCtnEditor;

struct SMwParamInfos_CGameCtnEditor {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameSystemOverlay SMwParamInfos_CGameSystemOverlay, *PSMwParamInfos_CGameSystemOverlay;

struct SMwParamInfos_CGameSystemOverlay {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CNetServer SMwParamInfos_CNetServer, *PSMwParamInfos_CNetServer;

struct SMwParamInfos_CNetServer {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleSpeedBoat SMwParamInfos_CSceneVehicleSpeedBoat, *PSMwParamInfos_CSceneVehicleSpeedBoat;

struct SMwParamInfos_CSceneVehicleSpeedBoat {
    undefined field0_0x0;
};

typedef struct CFixedArray<class_CMwId,3,unsigned_long> CFixedArray<class_CMwId,3,unsigned_long>, *PCFixedArray<class_CMwId,3,unsigned_long>;

struct CFixedArray<class_CMwId,3,unsigned_long> {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CControlListMap SMwParamInfos_CControlListMap, *PSMwParamInfos_CControlListMap;

struct SMwParamInfos_CControlListMap {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneConfigVision SMwParamInfos_CSceneConfigVision, *PSMwParamInfos_CSceneConfigVision;

struct SMwParamInfos_CSceneConfigVision {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaTracker SMwParamInfos_CGameCtnMediaTracker, *PSMwParamInfos_CGameCtnMediaTracker;

struct SMwParamInfos_CGameCtnMediaTracker {
    undefined field0_0x0;
};

typedef enum EChallengeAlign {
} EChallengeAlign;

typedef enum EMethod {
} EMethod;

typedef enum EFormRelaying {
} EFormRelaying;

typedef struct SMwParamInfos_CPlugModelMesh SMwParamInfos_CPlugModelMesh, *PSMwParamInfos_CPlugModelMesh;

struct SMwParamInfos_CPlugModelMesh {
    undefined field0_0x0;
};

typedef enum _D3DXINCLUDE_TYPE {
} _D3DXINCLUDE_TYPE;

typedef struct SMwParamInfos_CSceneVehicleTunings SMwParamInfos_CSceneVehicleTunings, *PSMwParamInfos_CSceneVehicleTunings;

struct SMwParamInfos_CSceneVehicleTunings {
    undefined field0_0x0;
};

typedef enum EForceOpen {
} EForceOpen;

typedef struct SMwParamInfos_CMotionParticleType SMwParamInfos_CMotionParticleType, *PSMwParamInfos_CMotionParticleType;

struct SMwParamInfos_CMotionParticleType {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CSceneVehicleEnvironment SMwParamInfos_CSceneVehicleEnvironment, *PSMwParamInfos_CSceneVehicleEnvironment;

struct SMwParamInfos_CSceneVehicleEnvironment {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnMediaBlockCameraEffectShake SMwParamInfos_CGameCtnMediaBlockCameraEffectShake, *PSMwParamInfos_CGameCtnMediaBlockCameraEffectShake;

struct SMwParamInfos_CGameCtnMediaBlockCameraEffectShake {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CGameCtnCollector SMwParamInfos_CGameCtnCollector, *PSMwParamInfos_CGameCtnCollector;

struct SMwParamInfos_CGameCtnCollector {
    undefined field0_0x0;
};

typedef struct CNetFormRpcCall CNetFormRpcCall, *PCNetFormRpcCall;

struct CNetFormRpcCall {
    undefined field0_0x0;
};

typedef struct SMwParamInfos_CPlugFile SMwParamInfos_CPlugFile, *PSMwParamInfos_CPlugFile;

struct SMwParamInfos_CPlugFile {
    undefined field0_0x0;
};

typedef struct tagPOINT *LPPOINT;

typedef struct HACCEL__ *HACCEL;

typedef uint *PUINT;

typedef HINSTANCE HMODULE;

typedef HANDLE HLOCAL;

typedef int (*FARPROC)(void);

typedef WORD ATOM;

typedef struct HWINSTA__ *HWINSTA;


/* WARNING! conflicting data type names: /WinDef.h/tagRECT - /TmForeverFixed.pdb/tagRECT */

typedef struct tagRECT *LPRECT;

typedef BOOL *LPBOOL;

typedef struct HKEY__ *HKEY;

typedef DWORD *LPDWORD;

typedef struct HMENU__ *HMENU;

typedef struct _FILETIME *LPFILETIME;

typedef struct HDC__ *HDC;

typedef WORD *LPWORD;

typedef HKEY *PHKEY;

typedef int INT;

typedef HANDLE HGLOBAL;

typedef void *LPCVOID;


/* WARNING! conflicting data type names: /PE/IMAGE_OPTIONAL_HEADER32 - /TmForeverFixed.pdb/IMAGE_OPTIONAL_HEADER32 */


/* WARNING! conflicting data type names: /PE/IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct - /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct */


/* WARNING! conflicting data type names: /PE/IMAGE_DEBUG_DIRECTORY - /TmForeverFixed.pdb/IMAGE_DEBUG_DIRECTORY */


/* WARNING! conflicting data type names: /PE/IMAGE_FILE_HEADER - /TmForeverFixed.pdb/IMAGE_FILE_HEADER */


/* WARNING! conflicting data type names: /PE/IMAGE_NT_HEADERS32 - /TmForeverFixed.pdb/IMAGE_NT_HEADERS32 */


/* WARNING! conflicting data type names: /PE/IMAGE_RESOURCE_DIRECTORY_ENTRY - /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY_ENTRY */


/* WARNING! conflicting data type names: /PE/IMAGE_SECTION_HEADER - /TmForeverFixed.pdb/IMAGE_SECTION_HEADER */


/* WARNING! conflicting data type names: /PE/Misc - /TmForeverFixed.pdb/Misc */


/* WARNING! conflicting data type names: /PE/IMAGE_DATA_DIRECTORY - /TmForeverFixed.pdb/IMAGE_DATA_DIRECTORY */


/* WARNING! conflicting data type names: /PE/IMAGE_RESOURCE_DATA_ENTRY - /TmForeverFixed.pdb/IMAGE_RESOURCE_DATA_ENTRY */


/* WARNING! conflicting data type names: /PE/SectionFlags - /TmForeverFixed.pdb/SectionFlags */


/* WARNING! conflicting data type names: /PE/IMAGE_RESOURCE_DIRECTORY - /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY */


/* WARNING! conflicting data type names: /PE/IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion - /TmForeverFixed.pdb/IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion */


/* WARNING! conflicting data type names: /PE/IMAGE_LOAD_CONFIG_DIRECTORY32 - /TmForeverFixed.pdb/IMAGE_LOAD_CONFIG_DIRECTORY32 */


/* WARNING! conflicting data type names: /accctrl.h/_TRUSTEE_W - /TmForeverFixed.pdb/_TRUSTEE_W */

typedef enum _ACCESS_MODE ACCESS_MODE;

typedef enum _SE_OBJECT_TYPE SE_OBJECT_TYPE;


/* WARNING! conflicting data type names: /accctrl.h/_EXPLICIT_ACCESS_W - /TmForeverFixed.pdb/_EXPLICIT_ACCESS_W */

typedef struct _TRUSTEE_W TRUSTEE_W;

typedef enum _TRUSTEE_FORM TRUSTEE_FORM;

typedef struct _EXPLICIT_ACCESS_W *PEXPLICIT_ACCESS_W;

typedef enum _TRUSTEE_TYPE TRUSTEE_TYPE;

typedef enum _MULTIPLE_TRUSTEE_OPERATION MULTIPLE_TRUSTEE_OPERATION;

typedef ACCESS_MASK REGSAM;

typedef LONG LSTATUS;


/* WARNING! conflicting data type names: /shellapi.h/_SHFILEOPSTRUCTW - /TmForeverFixed.pdb/_SHFILEOPSTRUCTW */

typedef WORD FILEOP_FLAGS;

typedef struct _SHFILEOPSTRUCTW *LPSHFILEOPSTRUCTW;


/* WARNING! conflicting data type names: /unknwn.h/IUnknownVtbl - /TmForeverFixed.pdb/IUnknownVtbl */


/* WARNING! conflicting data type names: /unknwn.h/IUnknown - /TmForeverFixed.pdb/IUnknown */

typedef struct IUnknown *LPUNKNOWN;

