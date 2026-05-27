#ifndef CNETMASTERHOST_HPP
#define CNETMASTERHOST_HPP

#include "typedefs.h"

struct CNetMasterHost {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall SetDirty(CNetMasterHost *this,CPlugVertexStream *param_1,int param_2);
};

#endif // CNETMASTERHOST_HPP
