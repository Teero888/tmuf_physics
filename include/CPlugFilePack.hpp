#ifndef CPLUGFILEPACK_HPP
#define CPLUGFILEPACK_HPP

#include "typedefs.h"

struct CPlugFilePack {
    void** vftable;
    byte _final_padding[0xac]; // Total size: 0xb0

    // Member Functions
    CSystemFid * __cdecl GetPackListFid(CSystemFids *param_1,int param_2);
    void __cdecl InstallPacks (char *param_1,int param_2,CClassicBuffer *param_3,CSystemFids *param_4, CSystemFids *param_5,CSystemFids *param_6,int param_7);
};

#endif // CPLUGFILEPACK_HPP
