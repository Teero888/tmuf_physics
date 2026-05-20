#ifndef CPLUGVISUALQUADS_HPP
#define CPLUGVISUALQUADS_HPP

#include "typedefs.h"

struct CPlugVisualQuads {
    void** vftable; // accesses: 1
    byte _final_padding[0x94]; // Total size: 0x98

    // Member Functions
    void __thiscall BoxQuadAdd (CPlugVisualQuads *this,CPlugVisualQuads *param_1,float param_2,ulong param_3, GxColor *param_4);
    void __thiscall CPlugVisualQuads(CPlugVisualQuads *this,CPlugVisualQuads *param_1);
    void __thiscall CreateQuadZ (CPlugVisualQuads *this,CPlugVisualQuads *param_1,GmVec3 param_2,float param_3, float param_4,GxColor *param_5,ulong param_6,GmVec3 *param_7);
};

#endif // CPLUGVISUALQUADS_HPP
