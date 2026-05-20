#ifndef CSCENEVEHICLESTRUCT_HPP
#define CSCENEVEHICLESTRUCT_HPP

#include "typedefs.h"

struct CFuncKeysReal;
struct CMwNod;

struct CSceneVehicleStruct {
    struct SSimulationWheel {

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSimulationWheel(void *this,SSimulationWheel *param_1);
    };

    struct SVisualArm {
        void** vftable; // accesses: 1
        undefined4 field_0x4; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    struct SVisualWheel {

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualWheel(void *this,SVisualWheel *param_1);
        void __thiscall ~SVisualWheel(void *this,SVisualWheel *param_1);
    };

    void** vftable; // accesses: 1
    byte _padding_0x4[64];
    CMwNod * field_0x44; // accesses: 8
    CMwNod * field_0x48; // accesses: 8
    CMwNod * field_0x4c; // accesses: 8

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicleStruct(CSceneVehicleStruct *this,CSceneVehicleStruct *param_1);
    ulong __thiscall GetVisualIndexFromMobilQuality (CSceneVehicleStruct *this,CSceneVehicleStruct *param_1,ESceneMobilQuality param_2);
};

#endif // CSCENEVEHICLESTRUCT_HPP
