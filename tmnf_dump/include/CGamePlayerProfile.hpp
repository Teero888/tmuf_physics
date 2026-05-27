#ifndef CGAMEPLAYERPROFILE_HPP
#define CGAMEPLAYERPROFILE_HPP

#include "typedefs.h"

struct CGameLeague;

struct CGamePlayerProfile {
    void** vftable;
    byte _padding_0x4[36];
    CGameLeague * field_0x28; // accesses: 1
    byte _final_padding[0x264]; // Total size: 0x290

    // Member Functions
    ulong __thiscall FindVehicleProfileFromVehicleIdent (CGamePlayerProfile *this,CGamePlayerProfile *param_1,SGameCtnIdentifier *param_2);
    void __thiscall ForceFavouriteAdd (CGamePlayerProfile *this,CGamePlayerProfile *param_1,CFastString *param_2);
    void __thiscall GetAnalogSensibility (CGamePlayerProfile *this,CGamePlayerProfile *param_1,ulong param_2,float *param_3, float *param_4);
    void __thiscall UpdateLeagueSteps(CGamePlayerProfile *this,CGamePlayerProfile *param_1);
};

#endif // CGAMEPLAYERPROFILE_HPP
