#ifndef CGAMEREMOTEBUFFERPOOL_HPP
#define CGAMEREMOTEBUFFERPOOL_HPP

#include "typedefs.h"

struct CGameRemoteBufferPool {
    byte _padding_0x0[20];
    int * field_0x14; // accesses: 4

    // Member Functions
    CGameRemoteBuffer * __thiscall GetOrCreateRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
    CGameRemoteBuffer * __thiscall GetRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
};

#endif // CGAMEREMOTEBUFFERPOOL_HPP
