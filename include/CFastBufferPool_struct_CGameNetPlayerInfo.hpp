#ifndef CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP
#define CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP

#include "typedefs.h"

struct CFastBufferPool<struct_CGameNetPlayerInfo {
    struct SNetStateBuffer> {
        byte _padding_0x0[16];
        undefined4 field_0x10; // accesses: 1
        byte _padding_0x14[24];
        undefined4 field_0x2c; // accesses: 1

        // Member Functions
        void __thiscall SetSize (CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this,CMwStatsValue *param_1, ulong param_2);
    };

    byte _padding_0x0[16];
    undefined4 field_0x10; // accesses: 1
    undefined4 field_0x14; // accesses: 1

    // Member Functions
    SNetStateBuffer> (CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this, CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *param_1);
};

#endif // CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP
