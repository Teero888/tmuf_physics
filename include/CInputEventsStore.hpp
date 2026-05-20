#ifndef CINPUTEVENTSSTORE_HPP
#define CINPUTEVENTSSTORE_HPP

#include "typedefs.h"

struct CDx9DynamicVB;

struct CInputEventsStore {
    struct SCachedValue {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1
        int field_0x8; // accesses: 1

        // Member Functions
        void __thiscall SCachedValue(void *this,SCachedValue *param_1,ulong param_2);
    };

    void** vftable;
    byte _padding_0x4[16];
    CDx9DynamicVB * field_0x14; // accesses: 2
    int field_0x18; // accesses: 1
    int field_0x1c; // accesses: 3

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ short __cdecl Convert(int param_1);
    EState __thiscall GetState(void *this,CMwCmdFiber *param_1);
    int __thiscall InsertSorted (void *this,CInputEventsStore *param_1,SInputEvent *param_2,ulong param_3);
    int __thiscall SetState (void *this,CInputEventsStore *param_1,SInputEvent *param_2,ulong param_3);
    ulong __thiscall AutoRegisterInput (void *this,CInputEventsStore *param_1,SInputActionDesc *param_2);
    void __thiscall CInputEventsStore (void *this,CInputEventsStore *param_1,ulong param_2,int param_3);
    void __thiscall ClearStore(void *this,CInputEventsStore *param_1);
    void __thiscall Lock (void *this,CDx9DynamicVB *param_1,ulong param_2,ulong param_3,uchar **param_4, ulong *param_5);
    void __thiscall RegisterInput (void *this,CInputEventsStore *param_1,SInputActionDesc *param_2,CMwId *param_3);
};

#endif // CINPUTEVENTSSTORE_HPP
