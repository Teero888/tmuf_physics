#ifndef CSCENE3D_HPP
#define CSCENE3D_HPP

#include "typedefs.h"

struct CSceneFxNod;

struct CScene3d {
    byte _padding_0x0[48];
    CSceneFx * field_0x30; // accesses: 1
    byte _padding_0x34[292];
    CSceneFxNod * field_0x158; // accesses: 4
    int field_0x15c; // accesses: 2

    // Member Functions
    CSceneFx * __thiscall SceneFxFindFromClassId (CScene3d *this,CScene3d *param_1,ulong param_2,CSceneFxNod **param_3);
    void __thiscall SceneFxGlobalStartStop(CScene3d *this,CScene3d *param_1,int param_2);
};

#endif // CSCENE3D_HPP
