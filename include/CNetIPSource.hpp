#ifndef CNETIPSOURCE_HPP
#define CNETIPSOURCE_HPP

#include "typedefs.h"

struct CNetIPSource {
    byte _padding_0x0[152];
    int field_0x98; // accesses: 1
    int field_0x9c; // accesses: 1
    byte _padding_0xa0[4];
    int field_0xa4; // accesses: 2
    int field_0xa8; // accesses: 2

    // Member Functions
    int __thiscall CanContact(CNetIPSource *this,CNetIPSource *param_1);
    int __thiscall CanContactThroughServer(CNetIPSource *this,CNetIPSource *param_1);
};

#endif // CNETIPSOURCE_HPP
