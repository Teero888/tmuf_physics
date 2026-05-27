#ifndef CPLUGVISUALINDEXED_HPP
#define CPLUGVISUALINDEXED_HPP

#include "typedefs.h"

struct CMwNod;

struct CPlugVisualIndexed {
    void** vftable; // accesses: 1
    byte _padding_0x4[148];
    CMwNod * field_0x98; // accesses: 7

    // Member Functions
    void __thiscall CPlugVisualIndexed (CPlugVisualIndexed *this,CPlugVisualIndexed *param_1,CPlugVisualIndexed *param_2);
    void __thiscall SetVerticesAndIndices (CPlugVisualIndexed *this,CPlugVisualIndexed *param_1,ulong param_2,GxVertex *param_3, ulong param_4,ushort *param_5);
};

#endif // CPLUGVISUALINDEXED_HPP
