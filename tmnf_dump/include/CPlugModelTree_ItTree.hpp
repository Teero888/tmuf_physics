#ifndef CPLUGMODELTREE_ITTREE_HPP
#define CPLUGMODELTREE_ITTREE_HPP

#include "typedefs.h"

struct CPlugModelTree;

struct CPlugModelTree_ItTree {
    void** vftable; // accesses: 2
    byte _padding_0x4[8];
    CPlugModelTree * field_0xc; // accesses: 4

    // Member Functions
    CPlugModelTree * __thiscall GetNextTree(void *this,CPlugModelTree_ItTree *param_1);
};

#endif // CPLUGMODELTREE_ITTREE_HPP
