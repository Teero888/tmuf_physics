#ifndef TIXMLDECLARATION_HPP
#define TIXMLDECLARATION_HPP

#include "typedefs.h"

struct TiXmlDeclaration {
    byte _padding_0x0[44];
    undefined4 * field_0x2c; // accesses: 1
    undefined4 * field_0x30; // accesses: 1
    undefined4 * field_0x34; // accesses: 1

    // Member Functions
    void __thiscall TiXmlDeclaration(TiXmlDeclaration *this,TiXmlDeclaration *param_1);
};

#endif // TIXMLDECLARATION_HPP
