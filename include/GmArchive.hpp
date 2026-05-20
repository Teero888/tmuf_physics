#ifndef GMARCHIVE_HPP
#define GMARCHIVE_HPP

#include "typedefs.h"

struct GmArchive {
    // No fields detected

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ReadQuat_6(CClassicBuffer *param_1,GmQuat *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ReadReal_3(CClassicBuffer *param_1,float *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ReadVec3Unit_4(CClassicBuffer *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl ReadVec3_4(CClassicBuffer *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl WriteQuat_6(CClassicBuffer *param_1,GmQuat *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl WriteReal_3(CClassicBuffer *param_1,float param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl WriteVec3Unit_2(CClassicBuffer *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl WriteVec3Unit_4(CClassicBuffer *param_1,GmVec3 *param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __cdecl WriteVec3_4(CClassicBuffer *param_1,GmVec3 *param_2);
    void __cdecl ReadVec3Pos_12(CClassicBuffer *param_1,GmVec3 *param_2);
    void __cdecl ReadVec3Pos_9(CClassicBuffer *param_1,GmVec3 *param_2);
    void __cdecl WriteVec3Pos_12(CClassicBuffer *param_1,GmVec3 *param_2);
    void __cdecl WriteVec3Pos_9(CClassicBuffer *param_1,GmVec3 *param_2);
};

#endif // GMARCHIVE_HPP
