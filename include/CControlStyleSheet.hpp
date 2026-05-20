#ifndef CCONTROLSTYLESHEET_HPP
#define CCONTROLSTYLESHEET_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CControlStyleSheet {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 4
    byte _padding_0x18[16];
    CMwRefBuffer * field_0x28; // accesses: 2

    // Member Functions
    CMwNod * __thiscall GetStyleSheetElem (CControlStyleSheet *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3 );
};

#endif // CCONTROLSTYLESHEET_HPP
