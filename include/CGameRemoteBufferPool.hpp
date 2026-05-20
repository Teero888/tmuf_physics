#ifndef CGAMEREMOTEBUFFERPOOL_HPP
#define CGAMEREMOTEBUFFERPOOL_HPP

#include "typedefs.h"

struct CGameRemoteBufferPool {
    void** vftable; // accesses: 1
    byte _padding_0x4[16];
    int * field_0x14; // accesses: 4

    // Member Functions
    CGameRemoteBuffer * __thiscall GetOrCreateRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
    CGameRemoteBuffer * __thiscall GetRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
};

#endif // CGAMEREMOTEBUFFERPOOL_HPP
