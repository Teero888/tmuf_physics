#ifndef CINPUTPORT_HPP
#define CINPUTPORT_HPP

#include "typedefs.h"

struct CInputPort {
    void** vftable; // accesses: 2
    byte _final_padding[0x11]; // Total size: 0x15

    // Member Functions
    SInputEvent * __thiscall GetActionState(CInputPort *this,CInputPort *param_1,SInputActionDesc *param_2);
    int __thiscall FindDevice (CInputPort *this,CInputPort *param_1,CMwId *param_2,ulong *param_3,CInputDevice **param_4 );
    void __thiscall ClearInputs(CInputPort *this,CInputPort *param_1,int param_2);
    void __thiscall InternalGatherLatestInputs(CInputPort *this,CInputPort *param_1);
    void __thiscall OnFocusChanged(CInputPort *this,CInputPort *param_1);
    void __thiscall ReadCurMapLatestEventsFromHarware(CInputPort *this,CInputPort *param_1,int param_2);
    void __thiscall RumbleAdd (CInputPort *this,CInputDevice *param_1,ulong param_2,float param_3,float param_4);
    void __thiscall UpdateAsync(CInputPort *this,CInputPortDx8 *param_1);
};

#endif // CINPUTPORT_HPP
