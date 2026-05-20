#ifndef CGAMEMASTERSERVERREQUESTPARAMS_HPP
#define CGAMEMASTERSERVERREQUESTPARAMS_HPP

#include "typedefs.h"

struct SStringParam;

struct CGameMasterServerRequestParams {
    byte _padding_0x0[12];
    SStringParam * field_0xc; // accesses: 1

    // Member Functions
    SParam * __thiscall InternalGetParam (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1, CFastString *param_2);
    int __thiscall GetParam (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1, CFastString *param_2,CFastString *param_3);
    int __thiscall GetParamAsNatural (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1, CFastString *param_2,ulong *param_3);
    int __thiscall GetParamAsStringInt (CGameMasterServerRequestParams *this,CGameMasterServerRequestParams *param_1, CFastString *param_2,CFastStringInt *param_3);
};

#endif // CGAMEMASTERSERVERREQUESTPARAMS_HPP
