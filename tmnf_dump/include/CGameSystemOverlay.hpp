#ifndef CGAMESYSTEMOVERLAY_HPP
#define CGAMESYSTEMOVERLAY_HPP

#include "typedefs.h"

struct CGameSystemOverlay {
    void** vftable;
    byte _final_padding[0x5]; // Total size: 0x9

    // Member Functions
    void __thiscall ToolBarSetForceOpen (CGameSystemOverlay *this,CGameSystemOverlay *param_1,int param_2,EForceOpen param_3);
};

#endif // CGAMESYSTEMOVERLAY_HPP
