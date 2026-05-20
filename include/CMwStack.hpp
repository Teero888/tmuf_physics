#ifndef CMWSTACK_HPP
#define CMWSTACK_HPP

#include "typedefs.h"

struct CMwStatsValue;

struct CMwStack {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 21
    undefined4 field_0x8; // accesses: 11
    undefined4 field_0xc; // accesses: 6
    undefined4 field_0x10; // accesses: 26
    undefined4 field_0x14; // accesses: 23
    undefined4 field_0x18; // accesses: 12
    undefined4 field_0x1c; // accesses: 1

    // Member Functions
    ulong __thiscall ChangeBaseVal(CMwStack *this,CMwStack *param_1,ulong param_2);
    ulong __thiscall FillIndexFromText (CMwStack *this,CMwStack *param_1,ulong param_2,CMwNod *param_3,CFastString *param_4);
    ulong __thiscall GetArgument (CMwStack *this,CMwStack *param_1,ulong param_2,EStackType param_3,ulong *param_4);
    ulong __thiscall InsertBaseIndex(CMwStack *this,CMwStack *param_1,ulong param_2);
    ulong __thiscall InsertBaseNameIndex(CMwStack *this,CMwStack *param_1,ulong param_2);
    ulong __thiscall InsertBaseVal(CMwStack *this,CMwStack *param_1,ulong param_2);
    ulong __thiscall MakeInfoFromStack(CMwStack *this,CMwStack *param_1,SMwParamInfo *param_2,CMwNod *param_3);
    ulong __thiscall WatchNextNameIndex (CMwStack *this,CMwStack *param_1,ulong *param_2,CMwNod **param_3,ulong param_4);
    void __thiscall CMwStack(CMwStack *this,CMwStack *param_1,ulong param_2);
    void __thiscall CopyFrom(CMwStack *this,SParam_Set *param_1,SParam *param_2);
    void __thiscall SetSize(CMwStack *this,CMwStatsValue *param_1,ulong param_2);
    void __thiscall ~CMwStack(CMwStack *this,CMwStack *param_1);
};

#endif // CMWSTACK_HPP
