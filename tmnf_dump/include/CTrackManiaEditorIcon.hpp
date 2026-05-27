#ifndef CTRACKMANIAEDITORICON_HPP
#define CTRACKMANIAEDITORICON_HPP

#include "typedefs.h"

struct CTrackManiaEditorIcon {
    void** vftable;
    byte _padding_0x4[24];
    CTrackManiaEditorIcon * field_0x1c; // accesses: 1

    // Member Functions
    void __thiscall SetMotherPage (CTrackManiaEditorIcon *this,CTrackManiaEditorIcon *param_1, CTrackManiaEditorIconPage *param_2);
};

#endif // CTRACKMANIAEDITORICON_HPP
