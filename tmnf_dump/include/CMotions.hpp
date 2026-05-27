#ifndef CMOTIONS_HPP
#define CMOTIONS_HPP

#include "typedefs.h"

struct CMotionTrack;
struct GxTexCoordSet;

struct CMotions {
    void** vftable; // accesses: 1
    byte _padding_0x4[28];
    CMotionTrack * field_0x20; // accesses: 3

    // Member Functions
    CMotion * __thiscall AddMotion(CMotions *this,CSceneObject *param_1,CMwNod *param_2,CMwId *param_3,int param_4);
    int __thiscall WantAbsorbContact(CMotions *this,CMotions *param_1);
    void __thiscall CMotions(CMotions *this,CMotions *param_1);
    void __thiscall OnAbsorbContact(CMotions *this,CMotions *param_1,CHmsPhysicalContact *param_2);
    void __thiscall RemoveMotion(CMotions *this,CSceneObject *param_1,CMotion *param_2);
};

#endif // CMOTIONS_HPP
