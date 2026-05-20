#ifndef CGAMEPLAYERUIDALLOCATOR_HPP
#define CGAMEPLAYERUIDALLOCATOR_HPP

#include "typedefs.h"

struct CGamePlayerUIdAllocator {
    byte _padding_0x0[1292];
    char field_0x50c; // accesses: 2
    char field_0x50d; // accesses: 4

    // Member Functions
    void __thiscall AssociatePlayerInfo (void *this,CGamePlayerUIdAllocator *param_1,uchar param_2,CGameNetPlayerInfo *param_3);
    void __thiscall GetUnallocatedRange (void *this,CGamePlayerUIdAllocator *param_1,uchar *param_2,uchar *param_3);
};

#endif // CGAMEPLAYERUIDALLOCATOR_HPP
