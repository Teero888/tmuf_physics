#ifndef CFASTBUFFER_STRUCT_SHMSCAMERALOCATION__HPP
#define CFASTBUFFER_STRUCT_SHMSCAMERALOCATION__HPP

#include "typedefs.h"

struct CFastBuffer<struct_SHmsCameraLocation> {
    void** vftable; // accesses: 4
    int field_0x4; // accesses: 2

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    SNewTriangleVert * __thiscall GetLastElem (void *this, CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1);
};

#endif // CFASTBUFFER_STRUCT_SHMSCAMERALOCATION__HPP
