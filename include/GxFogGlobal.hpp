#ifndef GXFOGGLOBAL_HPP
#define GXFOGGLOBAL_HPP

#include "typedefs.h"

struct GxFogGlobal {
    byte _padding_0x0[24];
    uint field_0x18; // accesses: 4

    // Member Functions
    void __thiscall ArchiveFog(void *this,GxFogGlobal *param_1,CClassicArchive *param_2);
};

#endif // GXFOGGLOBAL_HPP
