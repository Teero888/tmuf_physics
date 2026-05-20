#ifndef CNETHTTPRESULT_HPP
#define CNETHTTPRESULT_HPP

#include "typedefs.h"

struct CNetHttpClient;

struct CNetHttpResult {
    byte _padding_0x0[80];
    undefined4 field_0x50; // accesses: 2
    CNetHttpClient * field_0x54; // accesses: 4

    // Member Functions
    void __thiscall Cancel(CNetHttpResult *this,CNetHttpResult *param_1);
    void __thiscall Pause(CNetHttpResult *this,CGameCtnMediaTracker *param_1);
};

#endif // CNETHTTPRESULT_HPP
