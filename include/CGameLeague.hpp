#ifndef CGAMELEAGUE_HPP
#define CGAMELEAGUE_HPP

#include "typedefs.h"

struct SStringParam;

struct CGameLeague {
    byte _padding_0x0[4];
    undefined * field_0x4; // accesses: 4
    byte _padding_0x8[16];
    SStringParam * field_0x18; // accesses: 1
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 1

    // Member Functions
    /* WARNING: Removing unreachable block (ram,0x006484e5) */ void __cdecl CGameLeague::GetRecursivesPathsFromFullPath (CFastStringInt *param_1,CFastBuffer<class_CFastStringInt> *param_2);
    void __cdecl GetNameAndPathFromFullPath (CFastStringInt *param_1,CFastStringInt *param_2,CFastStringInt *param_3);
    void __cdecl GetPathStepsFromFullPath (CFastStringInt *param_1,CFastBuffer<class_CFastStringInt> *param_2);
    void __thiscall GetFullPath(CGameLeague *this,CGameLeague *param_1,CFastStringInt *param_2);
    void __thiscall GetPathSteps (CGameLeague *this,CGameLeague *param_1,CFastBuffer<class_CFastStringInt> *param_2);
};

#endif // CGAMELEAGUE_HPP
