#ifndef CSCENEVEHICLESTRUCT_HPP
#define CSCENEVEHICLESTRUCT_HPP

#include "typedefs.h"

struct CFuncKeysReal;
struct CMwNod;

struct CSceneVehicleStruct {
    struct SSimulationWheel {
        byte _padding_0x0[4];
        undefined4 field_0x4; // accesses: 1
        undefined4 field_0x8; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SSimulationWheel(void *this,SSimulationWheel *param_1);
    };

    struct SVisualArm {
        byte _padding_0x0[8];
        undefined4 field_0x8; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
    };

    struct SVisualWheel {
        byte _padding_0x0[32];
        undefined4 field_0x20; // accesses: 1
        undefined4 field_0x24; // accesses: 1

        // Member Functions
        void __thiscall Reset(void *this,GmFrustumIso4 *param_1);
        void __thiscall SVisualWheel(void *this,SVisualWheel *param_1);
        void __thiscall ~SVisualWheel(void *this,SVisualWheel *param_1);
    };

    byte _padding_0x0[68];
    undefined4 field_0x44; // accesses: 8
    undefined4 field_0x48; // accesses: 8
    undefined4 field_0x4c; // accesses: 8

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall CSceneVehicleStruct(CSceneVehicleStruct *this,CSceneVehicleStruct *param_1);
    ulong __thiscall GetVisualIndexFromMobilQuality (CSceneVehicleStruct *this,CSceneVehicleStruct *param_1,ESceneMobilQuality param_2);
};

#endif // CSCENEVEHICLESTRUCT_HPP
