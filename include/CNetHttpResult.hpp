#ifndef CNETHTTPRESULT_HPP
#define CNETHTTPRESULT_HPP

#include "typedefs.h"

struct CNetHttpClient;

struct CNetHttpResult {
    void** vftable;
    byte _final_padding[0x6]; // Total size: 0xa

    // Member Functions
    void __thiscall Cancel(CNetHttpResult *this,CNetHttpResult *param_1);
    void __thiscall Pause(CNetHttpResult *this,CGameCtnMediaTracker *param_1);
};

#endif // CNETHTTPRESULT_HPP
