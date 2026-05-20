#ifndef CCONTROLURLLINKS_HPP
#define CCONTROLURLLINKS_HPP

#include "typedefs.h"

struct CControlUrlLinks {
    void** vftable;
    byte _padding_0x4[324];
    undefined4 field_0x148; // accesses: 1
    byte _final_padding[0x18]; // Total size: 0x164

    // Member Functions
    void __thiscall ForceDirty(CControlUrlLinks *this,CControlUrlLinks *param_1);
};

#endif // CCONTROLURLLINKS_HPP
