#ifndef CCONTROLTIMELINE2_HPP
#define CCONTROLTIMELINE2_HPP

#include "typedefs.h"

struct CPlugTree;

struct CControlTimeLine2 {
    byte _padding_0x0[312];
    CControlTimeLine2 * field_0x138; // accesses: 2
    float field_0x13c; // accesses: 2
    float field_0x140; // accesses: 1
    byte _padding_0x144[16];
    float field_0x154; // accesses: 1
    float field_0x158; // accesses: 1
    byte _padding_0x15c[292];
    int * field_0x280; // accesses: 4

    // Member Functions
    void __thiscall GetTreeXFromTime (CControlTimeLine2 *this,CControlTimeLine2 *param_1,float param_2,float *param_3, int *param_4);
    void __thiscall TimeSet(CControlTimeLine2 *this,CControlTimeLine2 *param_1,float param_2);
    void __thiscall UpdateTimeVisual(CControlTimeLine2 *this,CControlTimeLine *param_1);
};

#endif // CCONTROLTIMELINE2_HPP
