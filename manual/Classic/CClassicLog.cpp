#include "CClassicLog.hpp"
#include <cstdint>

// Cross-Platform console output handling
#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else
    #include <iostream>
#endif

// Engine Globals extracted from assembly
extern CClassicLog g_GlobalLog; // DAT_00d71e20
extern int g_LogDisabled;       // DAT_00d71d88
extern uint32_t g_LastFlushTime; // DAT_00d71e7c
extern uint32_t g_FlushTimeout;  // DAT_00d34134 (e.g., 5000ms)

// Global Output Streams
extern std::ostream* g_OutStream1; // DAT_00d71e24
extern std::ostream* g_OutStream2; // DAT_00d71e34
extern std::ostream* g_OutStream3; // DAT_00d71e48

extern CFastString g_GlobalLogStr; // DAT_00d71e54
extern const char* g_LogCStr;      // DAT_00d71e58

// External functions
extern void CSystemFileName_ConvertToSystemName_AndCreate(CFastString* inPath, CFastString* outSysPath);

// =================================================
// Function: CClassicLog::AddLogStringInFile
// =================================================
void CClassicLog::AddLogStringInFile() {
    // 0 = no force flush, 1 = target main stream, 0 = no extra flags
    InternalAddLogString(false, 1, 0); 
}

// =================================================
// Function: CClassicLog::ConsoleAddLogString
// Cross-Platform console writer.
// =================================================
void CClassicLog::ConsoleAddLogString(uint32_t flags, CFastString* logStr) {
    bool isConsoleEnabled = true; 
    
    if (isConsoleEnabled) {
        // Assume CFastString layout: [0x00] = length, [0x04] = char* buffer
        uint32_t length = *(uint32_t*)logStr; 
        const char* buffer = *(const char**)((char*)logStr + 4); 

#ifdef _WIN32
        // Original Win32 Direct Console Write
        HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        if (hConsoleOutput != INVALID_HANDLE_VALUE) {
            DWORD charsWritten = 0;
            WriteConsoleA(hConsoleOutput, buffer, length, &charsWritten, NULL);
        }
#else
        // POSIX / Linux / macOS Standard Output
        // Using std::cout.write to respect the exact string length 
        // without relying on null-terminators (mimics WriteConsoleA exactly)
        std::cout.write(buffer, length);
        std::cout.flush();
#endif
    }
}

// =================================================
// Function: CClassicLog::FlushWhenTimeOut
// =================================================
void CClassicLog::FlushWhenTimeOut(bool forceFlush, int param2) {
    if (m_useTimeoutFlush == 0) {
        if (!forceFlush) return;
    } else {
        uint32_t currentTime = m_getTimeFunc(); // Must be updated to return uint32_t
        if (!forceFlush && ((currentTime - g_LastFlushTime) < g_FlushTimeout)) {
            return;
        }
        g_LastFlushTime = currentTime;
        
        if (m_flushCallback != nullptr) {
            m_flushCallback(this);
        }
    }

    if (m_fileStream != nullptr) m_fileStream->flush();
    if (m_consoleStream != nullptr) m_consoleStream->flush();
}

// =================================================
// Function: CClassicLog::InternalAddLogString
// Routes formatted strings to the active C++ standard streams.
// =================================================
void CClassicLog::InternalAddLogString(bool forceFlush, int streamMask, int param3) {
    if (g_LogDisabled == 0) {
        
        // Write to stream 1
        if ((streamMask != 0 && g_OutStream2 == nullptr) || param3 != 0) {
            if (g_OutStream1 != nullptr) {
                *g_OutStream1 << g_LogCStr;
            }
        }
        
        // Write to stream 2
        if (g_OutStream2 != nullptr) {
            *g_OutStream2 << g_LogCStr;
        }
        
        // Write to stream 3
        if (g_OutStream3 != nullptr) {
            *g_OutStream3 << g_LogCStr;
        }

        // Try to trigger a flush on the global instance
        g_GlobalLog.FlushWhenTimeOut(forceFlush, 0);
    }
}

// =================================================
// Function: CClassicLog::SetOutputFile
// Prepares the path and opens the std::ofstream.
// =================================================
void CClassicLog::SetOutputFile(CFastString* folderPath, CFastString* fileName, bool append) {
    // 1. Copy strings into the class members
    // Uses CFastString internals deduced from Ghidra output
    m_folderPath = *folderPath;
    m_fileName = *fileName;

    // 2. Concatenate folder + filename
    CFastString fullPath = m_folderPath;
    // fullPath.Concat(&m_fileName); // Equivalent to CFastStringInt::Concat
    
    // 3. Convert to valid OS path
    CFastString systemPath;
    CSystemFileName_ConvertToSystemName_AndCreate(&fullPath, &systemPath);

    // 4. Open the file stream
    // 0x40 = std::ios_base::out, 0x01 = std::ios_base::app (if append is true)
    std::ios_base::openmode mode = std::ios::out;
    if (append) {
        mode |= std::ios::app;
    }

    // Extract the raw C-string for the fstream constructor
    const char* rawSysPath = *(const char**)((char*)&systemPath + 4);
    
    std::ofstream* newFileStream = new std::ofstream(rawSysPath, mode);
    
    // Store it
    m_fileStream = newFileStream;
    
    // Clear out secondary streams if append wasn't requested
    if (!append) {
        m_secondaryStream = nullptr;
    }
}