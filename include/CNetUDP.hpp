#ifndef CNETUDP_HPP
#define CNETUDP_HPP

#include "typedefs.h"

struct CNetUDP {
    byte _padding_0x0[12];
    undefined4 field_0xc; // accesses: 1

    // Member Functions
    ERetCode __thiscall SendTo(void *this,CNetUDP *param_1,CNetIPAddress *param_2,CClassicBufferMemory *param_3);
};

#endif // CNETUDP_HPP
