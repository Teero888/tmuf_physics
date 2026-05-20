#ifndef CMWENGINEMAIN_HPP
#define CMWENGINEMAIN_HPP

#include "typedefs.h"

struct CMwEngineMain {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall AddEngine (CMwEngineMain *this,CMwEngineMain *param_1,ulong param_2,CMwEngine *param_3);
    void __thiscall CMwEngineMain(CMwEngineMain *this,CMwEngineMain *param_1);
};

#endif // CMWENGINEMAIN_HPP
