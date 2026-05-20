#ifndef CFASTBUFFERWHEEL_STRUCT_CGAMEPLAYGROUNDINTERFACE_HPP
#define CFASTBUFFERWHEEL_STRUCT_CGAMEPLAYGROUNDINTERFACE_HPP

#include "typedefs.h"

struct ulong;

struct CFastBufferWheel<struct_CGamePlaygroundInterface {
    struct SAvatarMessage> {
        void** vftable; // accesses: 4
        int field_0x4; // accesses: 5
        uint field_0x8; // accesses: 8
        undefined4 field_0xc; // accesses: 13
        int field_0x10; // accesses: 2

        // Member Functions
        GmVec3 * __thiscall Tail (void *this,CFastBufferWheel<class_GmVec3> *param_1);
        SBlockState * __thiscall PushNewElem (void *this, CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1);
        SHistoryPoint * __thiscall InsertNewElemFromStart (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2);
        void __thiscall ClearWheel (void *this,CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[8];
    undefined4 field_0xc; // accesses: 1
    ulong field_0x10; // accesses: 1

    // Member Functions
    SAvatarMessage> (void *this,CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *param_1, ulong param_2);
};

#endif // CFASTBUFFERWHEEL_STRUCT_CGAMEPLAYGROUNDINTERFACE_HPP
