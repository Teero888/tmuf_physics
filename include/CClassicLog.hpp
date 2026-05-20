#ifndef CCLASSICLOG_HPP
#define CCLASSICLOG_HPP

#include "typedefs.h"

struct CClassicLog {
    void** vftable;
    int * field_0x4; // accesses: 2
    int field_0x8; // accesses: 1
    code * field_0xc; // accesses: 1
    code * field_0x10; // accesses: 1
    int * field_0x14; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall FlushWhenTimeOut(CClassicLog *this,CClassicLog *param_1,int param_2);
    void __cdecl AddLogStringInFile(void);
    void __cdecl ConsoleAddLogString(ulong param_1,CFastString *param_2);
    void __cdecl InternalAddLogString(int param_1,int param_2,int param_3);
    void __thiscall SetOutputFile (CClassicLog *this,CClassicLog *param_1,CFastStringInt *param_2,CFastStringInt *param_3, int param_4);
};

#endif // CCLASSICLOG_HPP
