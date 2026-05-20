#ifndef CCLASSICCRYPTO_BLOWFISH_HPP
#define CCLASSICCRYPTO_BLOWFISH_HPP

#include "typedefs.h"

struct CClassicCrypto_BlowFish {
    void** vftable; // accesses: 1
    byte _padding_0x4[64];
    uint field_0x44; // accesses: 1

    // Member Functions
    void __thiscall DoBlock (void *this,CClassicCrypto_BlowFish *param_1,uint64 *param_2,uint64 *param_3);
    void __thiscall DoString (void *this,CClassicCrypto_BlowFish *param_1,CFastString *param_2,CFastString *param_3, ECipherOpMode param_4,uint64 *param_5,int param_6);
};

#endif // CCLASSICCRYPTO_BLOWFISH_HPP
