#ifndef CMOTIONS_HPP
#define CMOTIONS_HPP

#include "typedefs.h"

struct CMotionCmdBase;
struct CMotionTrack;
struct GxTexCoordSet;

struct CMotions {
    byte _padding_0x0[32];
    undefined4 field_0x20; // accesses: 3
    byte _padding_0x24[12];
    CMotionCmdBase * field_0x30; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CMotion * __thiscall AddMotion(CMotions *this,CSceneObject *param_1,CMwNod *param_2,CMwId *param_3,int param_4);
    int __thiscall WantAbsorbContact(CMotions *this,CMotions *param_1);
    void __thiscall CMotions(CMotions *this,CMotions *param_1);
    void __thiscall OnAbsorbContact(CMotions *this,CMotions *param_1,CHmsPhysicalContact *param_2);
    void __thiscall RemoveMotion(CMotions *this,CSceneObject *param_1,CMotion *param_2);
};

#endif // CMOTIONS_HPP
