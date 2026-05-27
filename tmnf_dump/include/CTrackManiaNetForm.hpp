#ifndef CTRACKMANIANETFORM_HPP
#define CTRACKMANIANETFORM_HPP

#include "typedefs.h"

struct CTrackManiaNetForm {
    void** vftable; // accesses: 2
    byte _padding_0x4[136];
    undefined4 field_0x8c; // accesses: 2
    undefined * field_0x90; // accesses: 3
    byte _padding_0x94[4];
    undefined4 field_0x98; // accesses: 2
    undefined * field_0x9c; // accesses: 3
    byte _padding_0xa0[12];
    undefined4 field_0xac; // accesses: 2
    undefined * field_0xb0; // accesses: 3

    // Member Functions
    void __thiscall CTrackManiaNetForm(CTrackManiaNetForm *this,CTrackManiaNetForm *param_1);
    void __thiscall ~CTrackManiaNetForm(CTrackManiaNetForm *this,CTrackManiaNetForm *param_1);
};

#endif // CTRACKMANIANETFORM_HPP
