#ifndef CNETMASTERSERVERREQUEST_HPP
#define CNETMASTERSERVERREQUEST_HPP

#include "typedefs.h"

struct CNetHttpResult;

struct CNetMasterServerRequest {
    byte _padding_0x0[80];
    CNetHttpResult * field_0x50; // accesses: 2

    // Member Functions
    void __thiscall Abort(CNetMasterServerRequest *this,CNetMasterServerRequest *param_1);
};

#endif // CNETMASTERSERVERREQUEST_HPP
