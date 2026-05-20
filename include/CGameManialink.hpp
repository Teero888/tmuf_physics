#ifndef CGAMEMANIALINK_HPP
#define CGAMEMANIALINK_HPP

#include "typedefs.h"

struct CControlContainer;
struct CControlFrame;
struct CControlLabel;
struct CControlStyleSheet;
struct CMwNod;
struct SManialinkFormat;
struct TiXmlElement;
struct TiXmlNode;

struct CGameManialink {
    struct SBuildPageParams {

        // Member Functions
        /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall SBuildPageParams(void *this,SBuildPageParams *param_1);
        void __thiscall ~SBuildPageParams(void *this,SBuildPageParams *param_1);
    };

    byte _padding_0x0[4];
    SManialinkFormat * field_0x4; // accesses: 1
    TiXmlElement * field_0x8; // accesses: 4
    TiXmlElement * field_0xc; // accesses: 9
    int field_0x10; // accesses: 2
    byte _padding_0x14[8];
    TiXmlElement * field_0x1c; // accesses: 1
    int field_0x20; // accesses: 5
    int field_0x24; // accesses: 1
    byte _padding_0x28[4];
    undefined4 field_0x2c; // accesses: 9
    CControlLabel * field_0x30; // accesses: 1
    float field_0x34; // accesses: 2
    undefined4 field_0x38; // accesses: 2
    undefined4 field_0x3c; // accesses: 1
    undefined * field_0x40; // accesses: 1
    byte _padding_0x44[316];
    int field_0x180; // accesses: 2
    undefined4 field_0x184; // accesses: 1
    byte _padding_0x188[12];
    int field_0x194; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ CGameManialinkPage * __cdecl BuildPage(SBuildPageParams *param_1,EErrorCode *param_2);
    void __cdecl AddPageToContainer(CGameManialinkPage *param_1,CControlFrame *param_2,float param_3);
};

#endif // CGAMEMANIALINK_HPP
