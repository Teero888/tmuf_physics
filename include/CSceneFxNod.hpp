#ifndef CSCENEFXNOD_HPP
#define CSCENEFXNOD_HPP

#include "typedefs.h"

struct CHmsViewport;
struct CMwNod;

struct CSceneFxNod {
    byte _padding_0x0[20];
    CSceneFxNod * field_0x14; // accesses: 4
    CHmsViewport * field_0x18; // accesses: 3
    CSceneFxNod * field_0x1c; // accesses: 8
    byte _padding_0x20[16];
    CMwNod * field_0x30; // accesses: 13
    byte _padding_0x34[16];
    CSceneFxNod * field_0x44; // accesses: 2

    // Member Functions
    CSceneFxNod * __thiscall NodFindFromFx(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFx *param_2);
    CSceneFxNod * __thiscall NodFindFromFxClassId(CSceneFxNod *this,CSceneFxNod *param_1,ulong param_2);
    CSceneFxNod * __thiscall NodInputGet(CSceneFxNod *this,CSceneFxNod *param_1);
    int __thiscall CanActive(CSceneFxNod *this,CSceneFxFlares *param_1,CHmsCamera *param_2);
    int __thiscall IsActiveThisOrChild(CSceneFxNod *this,CSceneFxNod *param_1);
    int __thiscall NodInputSel(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFxNod *param_2);
    int __thiscall StartStop(CSceneFxNod *this,CSceneFxNod *param_1,int param_2);
    int __thiscall StartStopSafe(CSceneFxNod *this,CSceneFxNod *param_1,int param_2);
    void __thiscall CameraCallBack(CSceneFxNod *this,CSceneFxNod *param_1,int param_2);
    void __thiscall FxSet(CSceneFxNod *this,CSceneFxNod *param_1,CSceneFx *param_2);
    void __thiscall PreLoad(CSceneFxNod *this,CSceneFxCompo *param_1);
    void __thiscall UpdateAllActivityFromScene(CSceneFxNod *this,CSceneFxNod *param_1,CScene3d *param_2);
};

#endif // CSCENEFXNOD_HPP
