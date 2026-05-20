#ifndef CTRACKMANIARACENET_HPP
#define CTRACKMANIARACENET_HPP

#include "typedefs.h"

struct CGameNetPlayerInfo;
struct CGameNetwork;
struct CGamePlayerCameraSet;
struct CGamePlayerInfo;
struct CGameRace;
struct CPlugAudio;
struct CTrackMania;
struct CTrackManiaRaceInterface;

struct CTrackManiaRaceNet {
    byte _padding_0x0[20];
    CPlugAudio * field_0x14; // accesses: 3
    int field_0x18; // accesses: 8
    byte _padding_0x1c[4];
    undefined4 field_0x20; // accesses: 8
    CTrackManiaRaceNet * field_0x24; // accesses: 4
    byte _padding_0x28[4];
    CGamePlayerCameraSet * field_0x2c; // accesses: 2
    byte _padding_0x30[8];
    CGamePlayerCameraSet * field_0x38; // accesses: 3
    CGamePlayerCameraSet * field_0x3c; // accesses: 2
    byte _padding_0x40[16];
    int field_0x50; // accesses: 1
    byte _padding_0x54[24];
    undefined4 field_0x6c; // accesses: 12
    undefined4 field_0x70; // accesses: 12
    undefined4 field_0x74; // accesses: 11
    undefined4 field_0x78; // accesses: 4
    undefined4 field_0x7c; // accesses: 10
    byte _padding_0x80[4];
    undefined4 field_0x84; // accesses: 8
    undefined4 field_0x88; // accesses: 2
    byte _padding_0x8c[12];
    undefined4 field_0x98; // accesses: 16
    undefined4 field_0x9c; // accesses: 2
    byte _padding_0xa0[8];
    int field_0xa8; // accesses: 2
    byte _padding_0xac[428];
    int field_0x258; // accesses: 1
    byte _padding_0x25c[96];
    CGameRace * field_0x2bc; // accesses: 1
    byte _padding_0x2c0[84];
    int field_0x314; // accesses: 1
    byte _padding_0x318[24];
    int field_0x330; // accesses: 2
    byte _padding_0x334[32];
    int field_0x354; // accesses: 2
    uint field_0x358; // accesses: 2
    int field_0x35c; // accesses: 1
    byte _padding_0x360[52];
    undefined4 field_0x394; // accesses: 1
    undefined4 field_0x398; // accesses: 1
    byte _padding_0x39c[380];
    CTrackManiaRaceInterface * field_0x518; // accesses: 2
    byte _padding_0x51c[60];
    undefined4 field_0x558; // accesses: 1
    byte _padding_0x55c[88];
    int field_0x5b4; // accesses: 10
    undefined4 field_0x5b8; // accesses: 5
    undefined4 field_0x5bc; // accesses: 6
    undefined4 field_0x5c0; // accesses: 2
    undefined4 field_0x5c4; // accesses: 3
    byte _padding_0x5c8[184];
    undefined4 field_0x680; // accesses: 2

    // Member Functions
    int __thiscall EndRunScoresVisible(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1);
    void __thiscall NotifyNewTime (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,ulong param_2,ulong param_3, uchar param_4);
    void __thiscall RaceInputsSendToServer (CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1,int param_2);
    void __thiscall SpectatorCameraChange(CTrackManiaRaceNet *this,CTrackManiaRaceNet *param_1);
    void __thiscall SwitchToRace (CTrackManiaRaceNet *this,CGameRace *param_1,GmNat3 param_2,ECardinalDir param_3);
    void __thiscall UpdateAsync(CTrackManiaRaceNet *this,CInputPortDx8 *param_1);
};

#endif // CTRACKMANIARACENET_HPP
