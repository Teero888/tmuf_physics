#ifndef CMOTIONTRACKTREE_HPP
#define CMOTIONTRACKTREE_HPP

#include "typedefs.h"

struct CMwCmd;
struct CMwCmdFastCall;
struct CMwNod;
struct CPlugTree;

struct CMotionTrackTree {
    byte _padding_0x0[44];
    undefined4 field_0x2c; // accesses: 1
    undefined4 field_0x30; // accesses: 4
    undefined4 field_0x34; // accesses: 1
    CMwCmdFastCall * field_0x38; // accesses: 3

    // Member Functions
    void __thiscall CMotionTrackTree(CMotionTrackTree *this,CMotionTrackTree *param_1);
    void __thiscall SetFuncTree(CMotionTrackTree *this,CPlugTree *param_1,CFuncTree *param_2);
    void __thiscall SetIsPhysics(CMotionTrackTree *this,CMotionTrackTree *param_1,int param_2);
};

#endif // CMOTIONTRACKTREE_HPP
