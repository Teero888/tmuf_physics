#ifndef CGAMECTNMASTERSERVER_HPP
#define CGAMECTNMASTERSERVER_HPP

#include "typedefs.h"

struct CClassicBuffer;
struct CFastString;
struct CSystemFid;
struct TiXmlText;

struct CGameCtnMasterServer {
    struct SMedalsInfo {

        // Member Functions
        void __thiscall SMedalsInfo(void *this,SMedalsInfo *param_1);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 4
    byte _padding_0x8[4];
    CFastString * field_0xc; // accesses: 1
    CSystemFid * field_0x10; // accesses: 2
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[24];
    ulong field_0x30; // accesses: 1
    undefined4 field_0x34; // accesses: 2
    byte _padding_0x38[36];
    TiXmlText * field_0x5c; // accesses: 1
    byte _padding_0x60[168];
    int field_0x108; // accesses: 5
    byte _padding_0x10c[56];
    undefined4 field_0x144; // accesses: 2
    byte _padding_0x148[60];
    int field_0x184; // accesses: 1
    byte _padding_0x188[1320];
    int field_0x6b0; // accesses: 3

    // Member Functions
    CGameMasterServerRequest * __thiscall StopOfficialRecord (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,SOfficialRecordState *param_2);
    int __thiscall ReadForcedManialinksParams (CGameCtnMasterServer *this,CGameCtnMasterServer *param_1,TiXmlElement *param_2);
    void __thiscall ReadData (CGameCtnMasterServer *this,CClassicArchive *param_1,void *param_2,ulong param_3);
};

#endif // CGAMECTNMASTERSERVER_HPP
