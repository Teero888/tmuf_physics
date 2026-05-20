#ifndef CMWENGINEMANAGER_HPP
#define CMWENGINEMANAGER_HPP

#include "typedefs.h"

struct CMwEngineManager {
    byte _padding_0x0[4];
    uint field_0x4; // accesses: 2

    // Member Functions
    CMwClassInfo * __thiscall GetClassInfo(CMwEngineManager *this,CMwEngineManager *param_1,ulong param_2);
    void __thiscall AddClass(CMwEngineManager *this,CMwEngineInfo *param_1,CMwClassInfo *param_2);
};

#endif // CMWENGINEMANAGER_HPP
