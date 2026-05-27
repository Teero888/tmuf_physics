#ifndef CCONTROLSTYLESHEET_HPP
#define CCONTROLSTYLESHEET_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CControlStyleSheet {
    void** vftable;
    byte _padding_0x4[36];
    CMwRefBuffer * field_0x28; // accesses: 2

    // Member Functions
    CMwNod * __thiscall GetStyleSheetElem (CControlStyleSheet *this,CControlStyleSheet *param_1,CMwId *param_2,CControlBase *param_3 );
};

#endif // CCONTROLSTYLESHEET_HPP
