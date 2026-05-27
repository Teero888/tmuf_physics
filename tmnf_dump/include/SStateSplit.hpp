#ifndef SSTATESPLIT_HPP
#define SSTATESPLIT_HPP

#include "typedefs.h"

struct SStateSplit {
    byte _padding_0x0[168];
    undefined4 field_0xa8; // accesses: 2
    undefined4 field_0xac; // accesses: 2

    // Member Functions
    void __thiscall Allocate(void *this,SStateSplit *param_1,ulong param_2);
    void __thiscall Archive(void *this,CFastCrypt<unsigned_long> *param_1,CClassicArchive *param_2);
    void __thiscall SStateSplit(void *this,SStateSplit *param_1);
    void __thiscall ~SStateSplit(void *this,SStateSplit *param_1);
};

#endif // SSTATESPLIT_HPP
