#ifndef CDX9VISUALKEEPER_HPP
#define CDX9VISUALKEEPER_HPP

#include "typedefs.h"

struct CDx9VisualKeeper {
    byte _padding_0x0[1];
    undefined2 field_0x1; // accesses: 5
    undefined2 field_0x2; // accesses: 2
    undefined2 field_0x4; // accesses: 48
    undefined2 field_0x6; // accesses: 2
    int field_0x8; // accesses: 19
    undefined4 field_0xc; // accesses: 4
    float field_0x10; // accesses: 1
    int * field_0x14; // accesses: 3
    float field_0x18; // accesses: 1
    byte _padding_0x1c[52];
    int field_0x50; // accesses: 4
    byte _padding_0x54[40];
    uchar ** field_0x7c; // accesses: 1
    byte _padding_0x80[24];
    int field_0x98; // accesses: 4
    int field_0x9c; // accesses: 1
    int field_0xa0; // accesses: 1
    byte _padding_0xa4[644];
    int field_0x328; // accesses: 1

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall LoadStaticGeometry(CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,ulong param_2);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RecordVertex2InVB (CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,uchar **param_2,GxVertex2 *param_3, ulong param_4,SStreamDecl *param_5);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ void __thiscall RecordVertex3InVB (CDx9VisualKeeper *this,CLoadGeomVertexGen<671098945> *param_1,uchar **param_2, GxVertex *param_3,ulong param_4);
    void __cdecl PackStaticGeometry(void);
    void __cdecl StaticInit(void);
};

#endif // CDX9VISUALKEEPER_HPP
