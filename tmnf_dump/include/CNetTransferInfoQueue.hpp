#ifndef CNETTRANSFERINFOQUEUE_HPP
#define CNETTRANSFERINFOQUEUE_HPP

#include "typedefs.h"

struct TiXmlAttribute;

struct CNetTransferInfoQueue {
    void** vftable;
    int field_0x4; // accesses: 6
    uint field_0x8; // accesses: 5
    int field_0xc; // accesses: 2
    int field_0x10; // accesses: 6
    int field_0x14; // accesses: 6
    TiXmlAttribute * field_0x18; // accesses: 2
    TiXmlAttribute * field_0x1c; // accesses: 2
    TiXmlAttribute * field_0x20; // accesses: 2

    // Member Functions
    void __thiscall Add (CNetTransferInfoQueue *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
};

#endif // CNETTRANSFERINFOQUEUE_HPP
