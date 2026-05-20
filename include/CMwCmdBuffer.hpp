#ifndef CMWCMDBUFFER_HPP
#define CMWCMDBUFFER_HPP

#include "typedefs.h"

struct CMwCmd;

struct CMwCmdBuffer {
    void** vftable; // accesses: 3
    byte _padding_0x4[16];
    uint field_0x14; // accesses: 7
    undefined4 field_0x18; // accesses: 2
    uint field_0x1c; // accesses: 9
    byte _padding_0x20[36];
    undefined4 field_0x44; // accesses: 4

    // Member Functions
    CMwClassInfo * __thiscall MwGetClassInfo(CMwCmdBuffer *this,CFuncSegment *param_1);
    CMwNod * __cdecl MwNewCMwCmdBuffer(void);
    int __thiscall MwIsKindOf(CMwCmdBuffer *this,CMwCmdAffectParam *param_1,ulong param_2);
    ulong __thiscall GetMwClassId(CMwCmdBuffer *this,CControlStyle *param_1);
    ulong __thiscall VirtualParam_Get (CMwCmdBuffer *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3);
    void * __thiscall _vector_deleting_destructor_ (CMwCmdBuffer *this,CRpcCallInternal *param_1,uint param_2);
    void __thiscall AddCmd(CMwCmdBuffer *this,CMwCmdBuffer *param_1,CMwCmd *param_2);
    void __thiscall CMwCmdBuffer(CMwCmdBuffer *this,CMwCmdBuffer *param_1);
    void __thiscall Run(CMwCmdBuffer *this,CMwCmdExpStringConcat *param_1);
    void __thiscall SetCatCount (CMwCmdBuffer *this, CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> *param_1,ulong param_2);
    void __thiscall UnistallCmd(CMwCmdBuffer *this,CMwCmdBuffer *param_1,CMwCmd *param_2,int param_3);
    void __thiscall ~CMwCmdBuffer(CMwCmdBuffer *this,CMwCmdBuffer *param_1);
};

#endif // CMWCMDBUFFER_HPP
