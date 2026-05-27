#ifndef STRUCT_SFASTCATSMALL__HPP
#define STRUCT_SFASTCATSMALL__HPP

#include "typedefs.h"

struct struct_SFastCatSmall> {
    byte _padding_0x0[12];
    int field_0xc; // accesses: 2

    // Member Functions
    ulong __thiscall GetCatIndexFromIndexInAll (void *this,CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *param_1, ulong param_2);
    void __thiscall AddInCat (void *this,CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *param_1, CHmsCorpus **param_2,ulong param_3);
    void __thiscall DeleteAll (void *this,CFastArray<class_CCrystalEdge*> *param_1);
    void __thiscall ReplaceByLastInAllAt (void *this, CFastBufferCat<struct_CSystemFidParameters::SParam*,struct_SFastCatSmall> *param_1, ulong param_2);
    void __thiscall ReplaceByLastInCatAt (void *this,CFastBufferCat<class_CMwCmd*,struct_SFastCat> *param_1,ulong param_2, ulong param_3);
    void __thiscall ResetCatDescs (void *this, CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *param_1);
    void __thiscall SetCatCount (void *this, CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> *param_1,ulong param_2);
};

#endif // STRUCT_SFASTCATSMALL__HPP
