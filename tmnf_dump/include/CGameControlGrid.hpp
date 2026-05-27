#ifndef CGAMECONTROLGRID_HPP
#define CGAMECONTROLGRID_HPP

#include "typedefs.h"

struct CGameRemoteBuffer;
struct CGameRemoteBufferPool;

struct CGameControlGrid {
    void** vftable; // accesses: 1
    byte _padding_0x4[460];
    uint field_0x1d0; // accesses: 3
    byte _padding_0x1d4[48];
    CGameControlGrid * field_0x204; // accesses: 3
    byte _padding_0x208[16];
    CGameRemoteBuffer * field_0x218; // accesses: 5
    CGameRemoteBuffer * field_0x21c; // accesses: 1
    byte _final_padding[0x34]; // Total size: 0x254

    // Member Functions
    CGameRemoteBuffer * __thiscall Remote_InternalGetBuffer (CGameControlGrid *this,CGameControlGrid *param_1,int param_2);
    CGameRemoteBuffer * __thiscall Remote_InternalGetBufferFromParams (CGameControlGrid *this,CGameControlGrid *param_1,CGameMasterServerRequestParams *param_2, int param_3);
    void __thiscall Remote_Clean(CGameControlGrid *this,CGameControlGrid *param_1);
    void __thiscall Remote_RegisterToBuffer(CGameControlGrid *this,CGameControlGrid *param_1);
    void __thiscall Remote_SetPool (CGameControlGrid *this,CGameControlGrid *param_1,CGameRemoteBufferPool *param_2);
    void __thiscall Remote_UnregisterFromBuffer(CGameControlGrid *this,CGameControlGrid *param_1);
    void __thiscall SetForcedPageCountFromDataCount (CGameControlGrid *this,CGameControlGrid *param_1,ulong param_2);
};

#endif // CGAMECONTROLGRID_HPP
