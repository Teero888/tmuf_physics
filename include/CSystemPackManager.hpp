#ifndef CSYSTEMPACKMANAGER_HPP
#define CSYSTEMPACKMANAGER_HPP

#include "typedefs.h"

struct CSystemFids;
struct CSystemFidsFolder;

struct CSystemPackManager {
    void** vftable; // accesses: 5
    short * field_0x4; // accesses: 2
    int field_0x8; // accesses: 1
    byte _padding_0xc[8];
    int field_0x14; // accesses: 1
    byte _padding_0x18[8];
    int field_0x20; // accesses: 1
    void * field_0x24; // accesses: 1
    byte _padding_0x28[4];
    code * field_0x2c; // accesses: 1
    byte _padding_0x30[8];
    int field_0x38; // accesses: 3
    int field_0x3c; // accesses: 3
    int field_0x40; // accesses: 2
    byte _padding_0x44[4];
    int field_0x48; // accesses: 2
    CSystemFids * field_0x4c; // accesses: 1
    CSystemFids * field_0x50; // accesses: 3
    byte _padding_0x54[24];
    int field_0x6c; // accesses: 1

    // Member Functions
    CSystemFidFile * __thiscall GetPackElem (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2, CFastString *param_3,ulong param_4,CSystemFid *param_5,CMwNod *param_6);
    CSystemFidFile * __thiscall SimpleGetPackElem (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2, CFastString *param_3,ulong param_4,int *param_5,int param_6);
    CSystemPackDesc * __thiscall AddPackDesc (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2, SNat128 *param_3);
    CSystemPackDesc * __thiscall FindOrAddPackDescFromNameAndUrl (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2, CFastString *param_3,CSystemFidsFolder *param_4);
    CSystemPackDesc * __thiscall FindOrAddPackDescFromUrl (CSystemPackManager *this,CSystemPackManager *param_1,CFastString *param_2, CFastString *param_3,CSystemFidsFolder *param_4);
    CSystemPackDesc * __thiscall FindPackDesc (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2,int param_3);
    CSystemPackDesc * __thiscall FindPackDescFromNameAndUrl (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2, CFastString *param_3,int param_4);
    int __thiscall CanComputeChecksum (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFid *param_2);
    int __thiscall IsPackDescInCache (CSystemPackManager *this,CSystemPackManager *param_1,CSystemPackDesc *param_2);
    ulong __thiscall GetIndexForFid (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2);
    void __cdecl NormalizeUrl(CFastString *param_1);
    void __thiscall ArchivePackDesc (CSystemPackManager *this,CSystemPackManager *param_1,CClassicArchive *param_2, CSystemPackDesc **param_3);
    void __thiscall ExtractNameFromFileNameInCache (CSystemPackManager *this,CSystemPackManager *param_1,CFastStringInt *param_2, CFastStringInt *param_3);
    void __thiscall GetPackNameFromFid (CSystemPackManager *this,CSystemPackManager *param_1,CSystemFidFile *param_2, CFastStringInt *param_3);
    void __thiscall Reset(CSystemPackManager *this,GmFrustumIso4 *param_1);
};

#endif // CSYSTEMPACKMANAGER_HPP
