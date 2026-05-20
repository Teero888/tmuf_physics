#ifndef CFASTBUFFER_STRUCT_SHMSRENDERRECT__HPP
#define CFASTBUFFER_STRUCT_SHMSRENDERRECT__HPP

#include "typedefs.h"

struct CFastBuffer<struct_SHmsRenderRect> {
    void** vftable; // accesses: 3
    void * field_0x4; // accesses: 4
    uint field_0x8; // accesses: 1

    // Member Functions
    SNewTriangleVert * __thiscall GetLastElem (void *this, CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_STRUCT_SHMSRENDERRECT__HPP
