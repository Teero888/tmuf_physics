#ifndef CSYSTEMFILE_HPP
#define CSYSTEMFILE_HPP

#include "typedefs.h"

struct CFastStringInt;
struct SStringParamInt;

struct CSystemFile {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 4
    byte _padding_0x8[4];
    int field_0xc; // accesses: 14
    undefined4 * field_0x10; // accesses: 7
    undefined4 field_0x14; // accesses: 2
    undefined * field_0x18; // accesses: 4
    DWORD field_0x1c; // accesses: 6
    int field_0x20; // accesses: 13
    int field_0x24; // accesses: 13

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ long __cdecl Open(_D3DXINCLUDE_TYPE param_1,char *param_2,void *param_3,void **param_4,uint *param_5 );
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ReadCallbackByteReaded(ulong param_1);
    float __thiscall GetLength(CSystemFile *this,CPlugFileSnd *param_1);
    int __thiscall SetOffset(CSystemFile *this,CSystemFile *param_1,ulong param_2);
    ulong __thiscall InternalChunkedRead(CSystemFile *this,CSystemFile *param_1,void *param_2,ulong param_3);
    ulong __thiscall Read(CSystemFile *this,CClassicBufferCrypted *param_1,void *param_2,ulong param_3);
    void __cdecl UpdateAsyncIO(void);
    void __thiscall CSystemFile(CSystemFile *this,CSystemFile *param_1);
    void __thiscall Close(CSystemFile *this,CClassicLog *param_1);
    void __thiscall Flush(CSystemFile *this,CGameAdvertisingRadial *param_1);
    void __thiscall ~CSystemFile(CSystemFile *this,CSystemFile *param_1);
};

#endif // CSYSTEMFILE_HPP
