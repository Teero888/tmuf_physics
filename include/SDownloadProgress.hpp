#ifndef SDOWNLOADPROGRESS_HPP
#define SDOWNLOADPROGRESS_HPP

#include "typedefs.h"

struct SDownloadProgress {
    int field_0x0; // accesses: 2
    int field_0x4; // accesses: 3
    int field_0x8; // accesses: 3
    int field_0xc; // accesses: 2

    // Member Functions
    float __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::GetCurProgress(void *this,SDownloadProgress *param_1);
    float __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::GetTotalProgress(void *this,SDownloadProgress *param_1);
    void __thiscall UpdateDownloadProgress(void)'::__l2:: SDownloadProgress::SDownloadProgress(void *this,SDownloadProgress *param_1);
};

#endif // SDOWNLOADPROGRESS_HPP
