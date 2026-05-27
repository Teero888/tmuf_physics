#ifndef CSYSTEMMANAGERFILE_HPP
#define CSYSTEMMANAGERFILE_HPP

#include "typedefs.h"

struct CSystemManagerFile {
    void** vftable; // accesses: 5

    // Member Functions
    CSystemFid * __thiscall CreateFidFromType (CSystemManagerFile *this,CSystemManagerFile *param_1,EFidType param_2);
    CSystemFidFile * __thiscall CreateFidFile(CSystemManagerFile *this,CSystemManagerFile *param_1);
    CSystemFidFile * __thiscall CreateFidResourceFile(CSystemManagerFile *this,CSystemManagerFile *param_1);
    CSystemFidMemory * __thiscall CreateFidMemory(CSystemManagerFile *this,CSystemManagerFile *param_1);
    CSystemFidsFolder * __thiscall CreateFidsFolder(CSystemManagerFile *this,CSystemManagerFile *param_1);
    EMakeDir __cdecl MakeDir(CFastStringInt *param_1);
    int __cdecl CompareFileTime(uint64 param_1,uint64 param_2);
    int __cdecl CopyFileW(CFastStringInt *param_1,CFastStringInt *param_2,int param_3);
    int __cdecl DeleteFileW(CFastStringInt *param_1,CSystemFids *param_2,int param_3);
    int __cdecl GetTimeWrite(CFastStringInt *param_1,uint64 *param_2);
    int __cdecl GiveDirAllRights(CFastStringInt *param_1);
    int __cdecl IsFileExists(CFastStringInt *param_1);
    int __cdecl IsFolderExists(CFastStringInt *param_1);
    int __cdecl MakeWritable(CFastStringInt *param_1);
    int __cdecl MoveFileW(CFastStringInt *param_1,CFastStringInt *param_2,int param_3);
    void __cdecl GetExeFullName(CFastStringInt *param_1);
    void __thiscall CSystemManagerFile(CSystemManagerFile *this,CSystemManagerFile *param_1);
};

#endif // CSYSTEMMANAGERFILE_HPP
