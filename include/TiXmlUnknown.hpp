#ifndef TIXMLUNKNOWN_HPP
#define TIXMLUNKNOWN_HPP

#include "typedefs.h"

struct TiXmlUnknown {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall TiXmlUnknown(TiXmlUnknown *this,TiXmlUnknown *param_1);
};

#endif // TIXMLUNKNOWN_HPP
