#ifndef CFASTBUFFERWHEEL_STRUCT_SMWTIMEDVALUEINSTANT_STRUCT_SINPUTEVENTSSTOREELEM____HPP
#define CFASTBUFFERWHEEL_STRUCT_SMWTIMEDVALUEINSTANT_STRUCT_SINPUTEVENTSSTOREELEM____HPP

#include "typedefs.h"

struct CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> {
    void** vftable; // accesses: 2
    int field_0x4; // accesses: 3
    uint field_0x8; // accesses: 6
    undefined4 field_0xc; // accesses: 3
    undefined4 field_0x10; // accesses: 1

    // Member Functions
    GmVec3 * __thiscall Tail (void *this,CFastBufferWheel<class_GmVec3> *param_1);
    SBlockState * __thiscall Head (void *this, CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1);
    void __thiscall CopyFromWheel (void *this, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_2);
    void __thiscall InsertFromStart (void *this, CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *param_1, ulong param_2,SMwTimedValueInstant<struct_SInputEventsStoreElem> *param_3);
};

#endif // CFASTBUFFERWHEEL_STRUCT_SMWTIMEDVALUEINSTANT_STRUCT_SINPUTEVENTSSTOREELEM____HPP
