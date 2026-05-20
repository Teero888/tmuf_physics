#ifndef CPFMCELL_HPP
#define CPFMCELL_HPP

#include "typedefs.h"

struct CPfmCell {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 5

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall ComputeCellData(void *this,CPfmCell *param_1);
    int __thiscall ForcePointToCellCollumn(void *this,CPfmCell *param_1,GmVec3 *param_2);
    int __thiscall RequestLink (void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,CPfmCell *param_4);
    void __thiscall CPfmCell(void *this,CPfmCell *param_1);
    void __thiscall Initialize(void *this,CPfmCell *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4);
    void __thiscall ~CPfmCell(void *this,CPfmCell *param_1);
};

#endif // CPFMCELL_HPP
