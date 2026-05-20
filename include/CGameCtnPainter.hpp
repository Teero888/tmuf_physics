#ifndef CGAMECTNPAINTER_HPP
#define CGAMECTNPAINTER_HPP

#include "typedefs.h"

struct CControlContainer;
struct CControlGrid;

struct CGameCtnPainter {
    byte _padding_0x0[20];
    undefined4 field_0x14; // accesses: 2
    byte _padding_0x18[660];
    int field_0x2ac; // accesses: 4
    byte _padding_0x2b0[24];
    CControlContainer * field_0x2c8; // accesses: 11
    byte _padding_0x2cc[4];
    int field_0x2d0; // accesses: 6
    byte _padding_0x2d4[44];
    int field_0x300; // accesses: 6
    byte _padding_0x304[56];
    undefined4 field_0x33c; // accesses: 2
    undefined4 field_0x340; // accesses: 2
    byte _padding_0x344[8];
    ulong field_0x34c; // accesses: 2
    ulong field_0x350; // accesses: 2

    // Member Functions
    CFastBuffer<class_CControlButton*> * __thiscall GetActiveButtons(CGameCtnPainter *this,CGameCtnPainter *param_1);
    CFastBuffer<class_CGameCtnPainter::CConstructionImage> * __thiscall GetActiveImages(CGameCtnPainter *this,CGameCtnPainter *param_1);
    void __thiscall StepImagesOnLeft(CGameCtnPainter *this,CGameCtnPainter *param_1);
    void __thiscall StepImagesOnRight(CGameCtnPainter *this,CGameCtnPainter *param_1);
};

#endif // CGAMECTNPAINTER_HPP
