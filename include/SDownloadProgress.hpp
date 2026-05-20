#ifndef SDOWNLOADPROGRESS_HPP
#define SDOWNLOADPROGRESS_HPP

#include "typedefs.h"

struct SDownloadProgress {
    void** vftable; // accesses: 2
    undefined4 field_0x4; // accesses: 3
    undefined4 field_0x8; // accesses: 3
    undefined4 field_0xc; // accesses: 2

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::GetCurProgress(void *this,SDownloadProgress *param_1);
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::GetTotalProgress(void *this,SDownloadProgress *param_1);
    void __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::SDownloadProgress(void *this,SDownloadProgress *param_1);
};

#endif // SDOWNLOADPROGRESS_HPP
