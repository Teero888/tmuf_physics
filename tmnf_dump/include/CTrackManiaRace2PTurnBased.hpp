#ifndef CTRACKMANIARACE2PTURNBASED_HPP
#define CTRACKMANIARACE2PTURNBASED_HPP

#include "typedefs.h"

struct CTrackManiaRace2PTurnBased {
    void** vftable;
    byte _final_padding[0x67c]; // Total size: 0x680

    // Member Functions
    void __thiscall UpdateAsync(CTrackManiaRace2PTurnBased *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACE2PTURNBASED_HPP
