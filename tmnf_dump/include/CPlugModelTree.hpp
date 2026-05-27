#ifndef CPLUGMODELTREE_HPP
#define CPLUGMODELTREE_HPP

#include "typedefs.h"

struct CPlugModelTree {
    void** vftable;
    byte _final_padding[0xdc]; // Total size: 0xe0

    // Member Functions
    void __thiscall SurfaceAdd (CPlugModelTree *this,CVisionViewportDx9 *param_1,ESurface param_2,GmNat2 *param_3, _D3DFORMAT param_4,_D3DMULTISAMPLE_TYPE param_5,IDirect3DSurface9 *param_6);
};

#endif // CPLUGMODELTREE_HPP
