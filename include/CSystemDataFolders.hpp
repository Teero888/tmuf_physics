#ifndef CSYSTEMDATAFOLDERS_HPP
#define CSYSTEMDATAFOLDERS_HPP

#include "typedefs.h"

struct CSystemDataFolders {
    byte _padding_0x0[20];
    int field_0x14; // accesses: 2
    int field_0x18; // accesses: 3

    // Member Functions
    CSystemFidFile * __thiscall FindFidFromRelativeName (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3,int param_4, int param_5,int param_6);
    CSystemFidsFolder * __thiscall GetDir(void *this,CSystemDataFolders *param_1,ulong param_2,ulong param_3);
    CSystemFidsFolder * __thiscall GetUserDir(void *this,CSystemDataFolders *param_1,ulong param_2);
    int __thiscall GetRelativeNameFromFid (void *this,CSystemDataFolders *param_1,CSystemFid *param_2,CFastStringInt *param_3, ulong param_4);
    ulong __thiscall FindDirIndexFromRelPath (void *this,CSystemDataFolders *param_1,ulong param_2,CFastStringInt *param_3);
};

#endif // CSYSTEMDATAFOLDERS_HPP
