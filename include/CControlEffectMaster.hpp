#ifndef CCONTROLEFFECTMASTER_HPP
#define CCONTROLEFFECTMASTER_HPP

#include "typedefs.h"

struct CMwRefBuffer;

struct CControlEffectMaster {
    byte _padding_0x0[32];
    CControlEffect * field_0x20; // accesses: 1
    CControlEffect * field_0x24; // accesses: 1
    CControlEffect * field_0x28; // accesses: 1
    CControlEffect * field_0x2c; // accesses: 1
    CControlEffect * field_0x30; // accesses: 1
    CControlEffect * field_0x34; // accesses: 1
    CControlEffect * field_0x38; // accesses: 1
    CControlEffect * field_0x3c; // accesses: 1
    CControlEffect * field_0x40; // accesses: 1
    CControlEffect * field_0x44; // accesses: 1
    CMwRefBuffer * field_0x48; // accesses: 3
    byte _padding_0x4c[208];
    int field_0x11c; // accesses: 1

    // Member Functions
    CControlEffect * __thiscall GetEffect (CControlEffectMaster *this,CControlEffectMaster *param_1,EEffectMode param_2);
    void __thiscall CleanUp (CControlEffectMaster *this,CControlEffectMotion *param_1,CControlBase *param_2, SParamEffect *param_3);
    void __thiscall ClearCurrentEffect (CControlEffectMaster *this,CControlEffectMaster *param_1,CControlBase *param_2);
    void __thiscall Init (CControlEffectMaster *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2, CVisionViewportDx9 *param_3,ESpriteColor0 *param_4);
};

#endif // CCONTROLEFFECTMASTER_HPP
