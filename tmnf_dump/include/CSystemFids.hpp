#ifndef CSYSTEMFIDS_HPP
#define CSYSTEMFIDS_HPP

#include "typedefs.h"

struct CMwNod;

struct CSystemFids {
    void** vftable; // accesses: 7

    // Member Functions
    CSystemFid * __thiscall FindFid (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3, EFindWay param_4);
    CSystemFid * __thiscall FindFidFromBaseNameAndClassId (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong param_3);
    CSystemFid * __thiscall FindOrAddFid (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4 );
    CSystemFids * __thiscall FindLocationDown (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3, EFindWay param_4);
    CSystemFids * __thiscall FindOneLocationDown (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,int param_3, EFindWay param_4);
    CSystemFids * __thiscall FindOrAddLocationDown (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4 );
    CSystemFids * __thiscall FindOrAddOneLocationDown (CSystemFids *this,CSystemFids *param_1,CFastStringInt *param_2,ulong *param_3,int param_4 );
    CSystemFids * __thiscall TravelGetTreesNbRefDown(CSystemFids *this,CSystemFids *param_1,ulong param_2);
    int __thiscall IsOneBaseOf(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2);
    int __thiscall TruncLocals(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2,int param_3);
    ulong __cdecl GetTravelInfo(CMwNod *param_1);
    ulong __thiscall TravelFindNbBackRoot (CSystemFids *this,CSystemFids *param_1,CFastBuffer<class_CSystemFids*> *param_2);
    void __cdecl AddTree(CPlugTree *param_1);
    void __cdecl ClearChildTravelInfo(CSystemFids *param_1);
    void __cdecl SetTravelInfo(CMwNod *param_1,ulong param_2);
    void __thiscall AddCompareTree (CSystemFids *this,CSystemFids *param_1,CFastBuffer<class_CSystemFids*> *param_2);
    void __thiscall AddLeave(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2);
    void __thiscall AddLeaveIfNot(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2);
    void __thiscall CSystemFids(CSystemFids *this,CSystemFids *param_1);
    void __thiscall ClearTravelInfoDown(CSystemFids *this,CSystemFids *param_1);
    void __thiscall ConnectLeave(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2);
    void __thiscall ConnectTree(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2);
    void __thiscall CreateIndex(CSystemFids *this,CSystemFids *param_1,ulong *param_2);
    void __thiscall DeleteDown(CSystemFids *this,CSystemFids *param_1);
    void __thiscall FillPtrAtTravelIndex (CSystemFids *this,CSystemFids *param_1,CFastArray<class_CSystemFids*> *param_2);
    void __thiscall GetUp(CSystemFids *this,GmIso4 *param_1,GmVec3 *param_2);
    void __thiscall RefreshVirtualRecursive(CSystemFids *this,CSystemFids *param_1,int param_2);
    void __thiscall RemoveLeaveSafe(CSystemFids *this,CSystemFids *param_1,CSystemFid *param_2);
    void __thiscall RemoveTreeSafe(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2);
    void __thiscall TravelCountUp(CSystemFids *this,CSystemFids *param_1);
    void __thiscall TravelDuplicateFrom(CSystemFids *this,CSystemFids *param_1,CSystemFids *param_2);
    void __thiscall TravelMarkUp(CSystemFids *this,CSystemFids *param_1);
    void __thiscall ~CSystemFids(CSystemFids *this,CSystemFids *param_1);
};

#endif // CSYSTEMFIDS_HPP
