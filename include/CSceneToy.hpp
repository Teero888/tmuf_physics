#ifndef CSCENETOY_HPP
#define CSCENETOY_HPP

#include "typedefs.h"

struct CSceneToy {
    void** vftable; // accesses: 1
    byte _final_padding[0x68]; // Total size: 0x6c

    // Member Functions
    void __thiscall CSceneToy(CSceneToy *this,CSceneToy *param_1);
};

#endif // CSCENETOY_HPP
