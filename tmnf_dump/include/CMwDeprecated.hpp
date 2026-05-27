#ifndef CMWDEPRECATED_HPP
#define CMWDEPRECATED_HPP

#include "typedefs.h"

struct CMwDeprecated {
    void** vftable;

    // Member Functions
    ulong __cdecl WrapClassId(ulong param_1);
    void __thiscall Chunk(void *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3);
};

#endif // CMWDEPRECATED_HPP
