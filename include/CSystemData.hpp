#ifndef CSYSTEMDATA_HPP
#define CSYSTEMDATA_HPP

#include "typedefs.h"

struct CMwCmdScriptVarBool;
struct CMwNod;
struct CMwParamClass;
struct CSystemFid;
struct CSystemFidsFolder;
struct CSystemPackDesc;
struct CSystemPackManager;

struct CSystemData {
    void** vftable; // accesses: 5
    CMwNod * field_0x4; // accesses: 2
    byte _padding_0x8[8];
    int * field_0x10; // accesses: 18
    CMwNod * field_0x14; // accesses: 4
    undefined * field_0x18; // accesses: 54
    CMwNod * field_0x1c; // accesses: 15
    CMwCmdScriptVarBool * field_0x20; // accesses: 9
    undefined4 field_0x24; // accesses: 3

    // Member Functions
    CMwNod * __thiscall Get(CSystemData *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3, ulong *param_4);
    CSystemFid * __thiscall GetFid(CSystemData *this,CSystemData *param_1,CMwNod *param_2,CSystemFid *param_3, ulong *param_4);
    void __thiscall CSystemData(CSystemData *this,CSystemData *param_1);
    void __thiscall Set(CSystemData *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetUpToDate(CSystemData *this,CSystemData *param_1,int param_2);
    void __thiscall SetUrl(CSystemData *this,CSystemData *param_1,CFastString *param_2,CFastString *param_3 );
};

#endif // CSYSTEMDATA_HPP
