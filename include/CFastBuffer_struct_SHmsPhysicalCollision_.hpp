#ifndef CFASTBUFFER_STRUCT_SHMSPHYSICALCOLLISION__HPP
#define CFASTBUFFER_STRUCT_SHMSPHYSICALCOLLISION__HPP

#include "typedefs.h"

struct CFastBuffer<struct_SHmsPhysicalCollision> {

    // Member Functions
    SLoadedLight * __thiscall AddNewElem (void *this,CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *param_1);
    void __thiscall QSort (void *this,CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *param_1, _func___cdecl_int_SKey_ptr_SKey_ptr *param_2);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_STRUCT_SHMSPHYSICALCOLLISION__HPP
