#ifndef CNETUDP_HPP
#define CNETUDP_HPP

#include "typedefs.h"

struct CNetUDP {

    // Member Functions
    ERetCode __thiscall SendTo(void *this,CNetUDP *param_1,CNetIPAddress *param_2,CClassicBufferMemory *param_3);
};

#endif // CNETUDP_HPP
