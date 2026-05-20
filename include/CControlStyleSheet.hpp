#ifndef CCONTROLSTYLESHEET_HPP
#define CCONTROLSTYLESHEET_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CControlStyleSheet {
    byte _padding_0x0[40];
    CMwRefBuffer * field_0x28; // accesses: 2
    byte _padding_0x2c[340];
    CControlStyleSheet * field_0x180; // accesses: 1

    // Member Functions
    CMwNod * __thiscall GetStyleSheetElem (CControlStyleSheet *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3 );
};

#endif // CCONTROLSTYLESHEET_HPP
