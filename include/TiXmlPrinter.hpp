#ifndef TIXMLPRINTER_HPP
#define TIXMLPRINTER_HPP

#include "typedefs.h"

struct TiXmlPrinter {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 1
    byte _padding_0x8[4];
    undefined4 * field_0xc; // accesses: 3
    undefined4 * field_0x10; // accesses: 2
    undefined4 * field_0x14; // accesses: 2

    // Member Functions
    void __thiscall TiXmlPrinter(TiXmlPrinter *this,TiXmlPrinter *param_1);
    void __thiscall ~TiXmlPrinter(TiXmlPrinter *this,TiXmlPrinter *param_1);
};

#endif // TIXMLPRINTER_HPP
