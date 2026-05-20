#ifndef CMWENGINEINFO_HPP
#define CMWENGINEINFO_HPP

#include "typedefs.h"

struct CMwEngineInfo {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 1

    // Member Functions
    void __thiscall AddClass(CMwEngineInfo *this,CMwEngineInfo *param_1,CMwClassInfo *param_2);
    void __thiscall CMwEngineInfo(CMwEngineInfo *this,CMwEngineInfo *param_1);
};

#endif // CMWENGINEINFO_HPP
