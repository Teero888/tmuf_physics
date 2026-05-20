#ifndef CPLUGVISUAL3D_HPP
#define CPLUGVISUAL3D_HPP

#include "typedefs.h"

struct CPlugVisual3D {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CPlugVisual3D(CPlugVisual3D *this,CPlugVisual3D *param_1,CPlugVisual3D *param_2);
    void __thiscall SetVertices (CPlugVisual3D *this,CPlugVisual3D *param_1,ulong param_2,GxVertex *param_3);
};

#endif // CPLUGVISUAL3D_HPP
