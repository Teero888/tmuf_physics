#ifndef CPLUGFILEPACK_HPP
#define CPLUGFILEPACK_HPP

#include "typedefs.h"

struct CPlugFilePack {
    byte _padding_0x0[1];
    undefined4 field_0x1; // accesses: 1
    undefined4 field_0x5; // accesses: 1
    undefined4 field_0x9; // accesses: 1
    undefined4 field_0xd; // accesses: 1
    undefined4 field_0x11; // accesses: 1
    undefined4 field_0x15; // accesses: 1
    undefined4 field_0x19; // accesses: 1
    undefined4 field_0x1d; // accesses: 1
    byte _padding_0x21[75];
    undefined4 * field_0x6c; // accesses: 2

    // Member Functions
    CSystemFid * __cdecl GetPackListFid(CSystemFids *param_1,int param_2);
    void __cdecl InstallPacks (char *param_1,int param_2,CClassicBuffer *param_3,CSystemFids *param_4, CSystemFids *param_5,CSystemFids *param_6,int param_7);
};

#endif // CPLUGFILEPACK_HPP
