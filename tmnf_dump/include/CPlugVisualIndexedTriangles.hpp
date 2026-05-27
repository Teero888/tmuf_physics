#ifndef CPLUGVISUALINDEXEDTRIANGLES_HPP
#define CPLUGVISUALINDEXEDTRIANGLES_HPP

#include "typedefs.h"

struct CPlugVisualIndexedTriangles {
    void** vftable; // accesses: 1
    byte _final_padding[0x98]; // Total size: 0x9c

    // Member Functions
    void __thiscall CPlugVisualIndexedTriangles (CPlugVisualIndexedTriangles *this,CPlugVisualIndexedTriangles *param_1);
};

#endif // CPLUGVISUALINDEXEDTRIANGLES_HPP
