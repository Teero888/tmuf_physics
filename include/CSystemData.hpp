#ifndef CSYSTEMDATA_HPP
#define CSYSTEMDATA_HPP

#include "typedefs.h"

struct CMwNod;
struct CSystemFid;
struct CSystemFidsFolder;
struct CSystemPackDesc;
struct CSystemPackManager;

struct CSystemData {
    byte _padding_0x0[4];
    CSystemFidsFolder * field_0x4; // accesses: 2
    byte _padding_0x8[12];
    undefined4 field_0x14; // accesses: 3
    undefined * field_0x18; // accesses: 1
    undefined4 field_0x1c; // accesses: 15
    undefined4 field_0x20; // accesses: 9
    undefined4 field_0x24; // accesses: 3
    byte _padding_0x28[32];
    int field_0x48; // accesses: 2
    byte _padding_0x4c[24];
    int field_0x64; // accesses: 3
    int field_0x68; // accesses: 1

    // Member Functions
    CMwNod * __thiscall Get(CSystemData *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3, ulong *param_4);
    CSystemFid * __thiscall GetFid(CSystemData *this,CSystemData *param_1,CMwNod *param_2,CSystemFid *param_3, ulong *param_4);
    void __thiscall CSystemData(CSystemData *this,CSystemData *param_1);
    void __thiscall Set(CSystemData *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetUpToDate(CSystemData *this,CSystemData *param_1,int param_2);
    void __thiscall SetUrl(CSystemData *this,CSystemData *param_1,CFastString *param_2,CFastString *param_3 );
};

#endif // CSYSTEMDATA_HPP
