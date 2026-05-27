#ifndef CPLUGFILESND_HPP
#define CPLUGFILESND_HPP

#include "typedefs.h"

struct CPlugFileSnd {
    void** vftable;
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    float __thiscall GetLength(CPlugFileSnd *this,CPlugFileSnd *param_1);
    ulong __thiscall GetNbBlocks(CPlugFileSnd *this,CPlugFileSnd *param_1);
};

#endif // CPLUGFILESND_HPP
