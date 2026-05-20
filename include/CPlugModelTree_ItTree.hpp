#ifndef CPLUGMODELTREE_ITTREE_HPP
#define CPLUGMODELTREE_ITTREE_HPP

#include "typedefs.h"

struct CPlugModelTree_ItTree {
    byte _padding_0x0[44];
    int field_0x2c; // accesses: 2

    // Member Functions
    CPlugModelTree * __thiscall GetNextTree(void *this,CPlugModelTree_ItTree *param_1);
};

#endif // CPLUGMODELTREE_ITTREE_HPP
