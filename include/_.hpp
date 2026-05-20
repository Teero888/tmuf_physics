#ifndef __HPP
#define __HPP

#include "typedefs.h"

struct > {
    int field_0x0; // accesses: 28
    int * field_0x4; // accesses: 32
    uint field_0x8; // accesses: 11
    int field_0xc; // accesses: 17
    int field_0x10; // accesses: 2

    // Member Functions
    CMotionPlayer * __thiscall GetNodFromId (void *this,CFastBuffer<class_CMotionPlayer*> *param_1,CMwId *param_2);
    SBlockState * __thiscall Head (void *this, CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *param_1);
    SHistoryPoint * __thiscall InsertNewElemFromStart (void *this,CFastBufferWheel<struct_CHmsDyna::SHistoryPoint> *param_1,ulong param_2);
    int __thiscall Find (void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2);
    ulong __thiscall FindKey<unsigned_char> (void *this,CFastBuffer<class_CGameNetPlayerInfo*> *param_1, SFastKey<class_CGameNetPlayerInfo*,unsigned_char> *param_2);
    ulong __thiscall GetNodIndexFromId (void *this,CFastBuffer<class_CGameCtnCampaign*> *param_1,CMwId *param_2);
    void __thiscall AddTailWithUniqueId (void *this,CFastArray<class_CMotion*> *param_1,CMotion **param_2,char *param_3);
    void __thiscall ArchiveCountAndNods (void *this,CFastArray<class_CPlugSoundEngineComponent*> *param_1,CClassicArchive *param_2 );
    void __thiscall CopyFromFastArray (void *this,CFastArray<class_GmVec4> *param_1,CFastArray<class_GmVec4> *param_2);
    void __thiscall DeleteOneAt (void *this,CFastArray<class_CPlugShaderPass*> *param_1,CPlugShaderPass **param_2);
    void __thiscall Merge (void *this,CFastBuffer<class_CSceneMobil*> *param_1, CFastBuffer<class_CSceneMobil*> *param_2);
    void __thiscall Pop(void *this,SCharStyle *param_1);
    void __thiscall QSort (void *this,CFastBuffer<struct_CFastBufferKey<struct_CFuncSegment::SKey>::SKey> *param_1, _func___cdecl_int_SKey_ptr_SKey_ptr *param_2);
    void __thiscall ReleaseAll (void *this,CFastBuffer<class_CSystemPackDesc*> *param_1);
    void __thiscall ReleaseAllWheel (void *this,CFastBufferWheel<class_CPlugFileSndGen*> *param_1);
    void __thiscall RemoveElems (void *this,CFastArray<class_CCrystalEdge*> *param_1,CCrystalEdge **param_2,ulong param_3);
    void __thiscall ReplaceByLast (void *this,CFastBuffer<class_CPlugBitmap*> *param_1,CPlugBitmap **param_2);
    void __thiscall ReplaceByLastIfFound (void *this,CFastBuffer<struct_CGameRemoteBuffer::SUser*> *param_1,SUser **param_2);
};

#endif // __HPP
