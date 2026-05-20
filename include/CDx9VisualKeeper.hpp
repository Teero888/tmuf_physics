#ifndef CDX9VISUALKEEPER_HPP
#define CDX9VISUALKEEPER_HPP

#include "typedefs.h"

struct CDx9VisualKeeper {
    void** vftable;
    int * field_0x4; // accesses: 20
    byte _padding_0x8[144];
    int field_0x98; // accesses: 2

    // Member Functions
    void __cdecl PackStaticGeometry(void);
    void __cdecl StaticInit(void);
    void __thiscall LoadStaticGeometry(CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,ulong param_2);
    void __thiscall RecordVertex2InVB (CDx9VisualKeeper *this,CDx9VisualKeeper *param_1,uchar **param_2,GxVertex2 *param_3, ulong param_4,SStreamDecl *param_5);
    void __thiscall RecordVertex3InVB (CDx9VisualKeeper *this,CLoadGeomVertexGen<671098945> *param_1,uchar **param_2, GxVertex *param_3,ulong param_4);
};

#endif // CDX9VISUALKEEPER_HPP
