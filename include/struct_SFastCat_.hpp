#ifndef STRUCT_SFASTCAT__HPP
#define STRUCT_SFASTCAT__HPP

#include "typedefs.h"

struct struct_SFastCat> {
    byte _padding_0x0[4];
    ulong field_0x4; // accesses: 12

    // Member Functions
    /* WARNING: Control flow encountered bad instruction data */ ulong __thiscall ChangeCatAt (void *this, CFastBufferCat<struct_SHmsItem_CallbackSortCustom_Elem,struct_SFastCat> *param_1, ulong param_2,ulong param_3,ulong param_4);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ SSamplerState * __thiscall GetElemInCat (void *this, CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> *param_1,ulong param_2,ulong param_3);
    GmQuat * __thiscall GetElemInAll (void *this,CFastBufferCat<class_GmQuat,struct_SFastCat> *param_1,ulong param_2);
    ulong __thiscall FindIndexInCat (void *this,CFastBufferCat<class_CNetHttpResult*,struct_SFastCat> *param_1, CNetHttpResult **param_2,ulong param_3);
    ulong __thiscall GetCountInCats (void *this,CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *param_1,ulong param_2, ulong param_3);
    ulong __thiscall SetParsingAll (void *this,CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *param_1);
    ulong __thiscall SetParsingCat (void *this,CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *param_1, ulong param_2,ulong param_3);
    void __thiscall AddInCat (void *this,CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *param_1, CHmsCorpus **param_2,ulong param_3);
    void __thiscall DeleteAll (void *this,CFastArray<class_CCrystalEdge*> *param_1);
    void __thiscall QSortEachCatArithmetic (void *this,CFastBufferCat<unsigned_long,struct_SFastCat> *param_1,int param_2, ulong param_3,ulong param_4);
    void __thiscall RemoveAll (void *this,CFastBufferCat<char,struct_SFastCat> *param_1);
    void __thiscall ReplaceByLastInAll (void *this,CFastBufferCat<class_CHmsCorpus*,struct_SFastCat> *param_1, CHmsCorpus **param_2,ulong *param_3);
    void __thiscall ResetCat (void *this, CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> *param_1,ulong param_2);
    void __thiscall ResetCatDescs (void *this, CFastBufferCat<enum__D3DFORMAT,struct_CDx9DeviceCaps::STextureRenderCat> *param_1);
    void __thiscall SetCatCount (void *this, CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat> *param_1,ulong param_2);
};

#endif // STRUCT_SFASTCAT__HPP
