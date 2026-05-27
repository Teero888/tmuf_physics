#ifndef CTRACKMANIARACENET_HPP
#define CTRACKMANIARACENET_HPP

#include "typedefs.h"

struct CGameNetPlayerInfo;
struct CGameNetwork;
struct CGameRace;
struct CTrackMania;
struct CTrackManiaRaceInterface;

struct CTrackManiaRaceNet {
    void** vftable; // accesses: 24
    byte _padding_0x4[20];
    int * field_0x18; // accesses: 8
    byte _final_padding[0x1e]; // Total size: 0x3a

    // Member Functions
    int __thiscall EndRunScoresVisible(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1);
    void __thiscall NotifyNewTime (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,ulong param_2,ulong param_3, uchar param_4);
    void __thiscall RaceInputsSendToServer (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,int param_2);
    void __thiscall SpectatorCameraChange(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1);
    void __thiscall SwitchToRace (CTrackManiaRaceNet *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceNet *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENET_HPP
