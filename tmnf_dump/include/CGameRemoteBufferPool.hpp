#ifndef CGAMEREMOTEBUFFERPOOL_HPP
#define CGAMEREMOTEBUFFERPOOL_HPP

#include "typedefs.h"

struct CGameRemoteBufferPool {
    void** vftable; // accesses: 1

    // Member Functions
    CGameRemoteBuffer * __thiscall GetOrCreateRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
    CGameRemoteBuffer * __thiscall GetRemoteBuffer (CGameRemoteBufferPool *this,CGameRemoteBufferPool *param_1, CGameMasterServerRequestParams *param_2);
};

#endif // CGAMEREMOTEBUFFERPOOL_HPP
