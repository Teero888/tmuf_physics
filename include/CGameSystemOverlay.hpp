#ifndef CGAMESYSTEMOVERLAY_HPP
#define CGAMESYSTEMOVERLAY_HPP

#include "typedefs.h"

struct CGameSystemOverlay {
    byte _padding_0x0[56];
    uint field_0x38; // accesses: 4

    // Member Functions
    void __thiscall ToolBarSetForceOpen (CGameSystemOverlay *this,CGameSystemOverlay *param_1,int param_2,EForceOpen param_3);
};

#endif // CGAMESYSTEMOVERLAY_HPP
