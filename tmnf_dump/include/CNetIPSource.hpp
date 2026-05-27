#ifndef CNETIPSOURCE_HPP
#define CNETIPSOURCE_HPP

#include "typedefs.h"

struct CNetIPSource {
    void** vftable;
    byte _final_padding[0x18]; // Total size: 0x1c

    // Member Functions
    int __thiscall CanContact(CNetIPSource *this,CNetIPSource *param_1);
    int __thiscall CanContactThroughServer(CNetIPSource *this,CNetIPSource *param_1);
};

#endif // CNETIPSOURCE_HPP
