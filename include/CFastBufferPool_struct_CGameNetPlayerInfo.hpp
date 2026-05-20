#ifndef CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP
#define CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP

#include "typedefs.h"

struct CFastBufferPool<struct_CGameNetPlayerInfo {
    struct SNetStateBuffer> {
        void** vftable; // accesses: 1
        byte _padding_0x4[12];
        undefined4 field_0x10; // accesses: 2
        undefined4 field_0x14; // accesses: 1

        // Member Functions
        void __thiscall SetSize (CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this,CMwStatsValue *param_1, ulong param_2);
    };


    // Member Functions
    SNetStateBuffer> (CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this, CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *param_1);
};

#endif // CFASTBUFFERPOOL_STRUCT_CGAMENETPLAYERINFO_HPP
