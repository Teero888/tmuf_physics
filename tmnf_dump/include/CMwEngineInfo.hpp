#ifndef CMWENGINEINFO_HPP
#define CMWENGINEINFO_HPP

#include "typedefs.h"

struct CMwEngineInfo {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall AddClass(CMwEngineInfo *this,CMwEngineInfo *param_1,CMwClassInfo *param_2);
    void __thiscall CMwEngineInfo(CMwEngineInfo *this,CMwEngineInfo *param_1);
};

#endif // CMWENGINEINFO_HPP
