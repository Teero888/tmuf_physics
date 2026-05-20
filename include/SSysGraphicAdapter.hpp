#ifndef SSYSGRAPHICADAPTER_HPP
#define SSYSGRAPHICADAPTER_HPP

#include "typedefs.h"

struct SSysGraphicAdapter {
    byte _padding_0x0[4];
    WCHAR * field_0x4; // accesses: 1

    // Member Functions
    /* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */ void __thiscall CaptureInfoGpu(void *this,SSysGraphicAdapter *param_1,ulong param_2);
    int __thiscall IsDriverRecentOrEqual (void *this,SSysGraphicAdapter *param_1,ushort param_2,ushort param_3,ushort param_4, ushort param_5);
};

#endif // SSYSGRAPHICADAPTER_HPP
