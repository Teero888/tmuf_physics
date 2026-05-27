#ifndef CCLASSICLOG_HPP
#define CCLASSICLOG_HPP

#include "CFastString.hpp"
#include <fstream>
#include <iostream>

// =================================================
// CClassicLog
// Global logging, console output, and file streaming.
// Note: Optimized for 32-bit pointer sizes.
// =================================================
class CClassicLog {
public:
    virtual ~CClassicLog() {} // 0x00 - vftable

    std::ostream* m_secondaryStream;          // 0x04 
    int m_useTimeoutFlush;                    // 0x08 - Flag to enable delayed flushing
    
    // Function pointers for callbacks
    typedef void (*FlushCallback)(CClassicLog*);
    typedef uint32_t (*GetTimeFunc)();
    
    FlushCallback m_flushCallback;            // 0x0C
    GetTimeFunc m_getTimeFunc;                // 0x10
    
    std::ofstream* m_fileStream;              // 0x14 - Main file output
    
    CFastString m_folderPath;                 // 0x18 (Assuming 8-byte CFastString)
    CFastString m_fileName;                   // 0x20
    
    std::ostream* m_consoleStream;            // 0x28

    // Member Functions
    static void AddLogStringInFile();
    static void ConsoleAddLogString(uint32_t flags, CFastString* logStr);
    static void InternalAddLogString(bool forceFlush, int streamMask, int param3);
    
    void FlushWhenTimeOut(bool forceFlush, int param2);
    void SetOutputFile(CFastString* folderPath, CFastString* fileName, bool append);
};

#endif // CCLASSICLOG_HPP