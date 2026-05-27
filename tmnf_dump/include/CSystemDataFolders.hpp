#ifndef CSYSTEMDATAFOLDERS_HPP
#define CSYSTEMDATAFOLDERS_HPP

#include "typedefs.h"

struct CSystemFidsFolder;

struct CSystemDataFolders {
    void** vftable; // accesses: 1
    CSystemFidsFolder * field_0x4; // accesses: 1

    // Member Functions
    CSystemFidFile * __thiscall FindFidFromRelativeName (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3,int param_4, int param_5,int param_6);
    CSystemFidsFolder * __thiscall GetDir(void *this,CSystemDataFolders *param_1,ulong param_2,ulong param_3);
    CSystemFidsFolder * __thiscall GetUserDir(void *this,CSystemDataFolders *param_1,ulong param_2);
    int __thiscall GetRelativeNameFromFid (void *this,CSystemDataFolders *param_1,CSystemFid *param_2,CFastStringInt *param_3, ulong param_4);
    ulong __thiscall FindDirIndexFromRelPath (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3);
};

#endif // CSYSTEMDATAFOLDERS_HPP
