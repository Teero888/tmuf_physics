#ifndef CSCENEENGINE_HPP
#define CSCENEENGINE_HPP

#include "typedefs.h"

struct CSceneEngine {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    undefined4 field_0x20; // accesses: 1
    undefined4 field_0x24; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x007d1466) */ /* WARNING: Removing unreachable block (ram,0x007d1438) */ /* WARNING: Removing unreachable block (ram,0x007d1490) */ /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneEngine::UpdateAsync(CSceneEngine *this,CInputPortDx8 *param_1);
    void __thiscall CSceneEngine(CSceneEngine *this,CSceneEngine *param_1);
};

#endif // CSCENEENGINE_HPP
