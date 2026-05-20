#ifndef CSYSTEMPACKMANAGER_HPP
#define CSYSTEMPACKMANAGER_HPP

#include "typedefs.h"

struct CMwNod;
struct CSystemFidFile;
struct CSystemFids;
struct CSystemFidsFolder;

struct CSystemPackManager {
    byte _padding_0x0[4];
    undefined4 field_0x4; // accesses: 9
    undefined4 field_0x8; // accesses: 2
    void * field_0xc; // accesses: 2
    undefined4 field_0x10; // accesses: 1
    int field_0x14; // accesses: 2
    uint field_0x18; // accesses: 1
    int field_0x1c; // accesses: 2
    int field_0x20; // accesses: 2
    void * field_0x24; // accesses: 4
    undefined * field_0x28; // accesses: 2
    code * field_0x2c; // accesses: 1
    byte _padding_0x30[8];
    code * field_0x38; // accesses: 4
    code * field_0x3c; // accesses: 4
    int field_0x40; // accesses: 3
    int field_0x44; // accesses: 1
    int field_0x48; // accesses: 6
    CSystemFidsFolder * field_0x4c; // accesses: 3
    CSystemFidsFolder * field_0x50; // accesses: 3
    byte _padding_0x54[4];
    int field_0x58; // accesses: 1
    byte _padding_0x5c[4];
    int field_0x60; // accesses: 1
    int field_0x64; // accesses: 1
    byte _padding_0x68[4];
    int field_0x6c; // accesses: 2

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
