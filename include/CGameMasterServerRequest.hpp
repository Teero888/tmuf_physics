#ifndef CGAMEMASTERSERVERREQUEST_HPP
#define CGAMEMASTERSERVERREQUEST_HPP

#include "typedefs.h"

struct CMwNod;

struct CGameMasterServerRequest {
    byte _padding_0x0[88];
    CGameMasterServerRequest * field_0x58; // accesses: 1
    CMwNod * field_0x5c; // accesses: 1
    CGameMasterServerRequest * field_0x60; // accesses: 1
    CMwNod * field_0x64; // accesses: 1

    // Member Functions
    void __thiscall SetRequestFailureCallBack (CGameMasterServerRequest *this,CGameMasterServerRequest *param_1,CMwNod *param_2, _func___cdecl_void_CGameMasterServerRequest_ptr *param_3);
    void __thiscall SetRequestSuccessCallBack (CGameMasterServerRequest *this,CGameMasterServerRequest *param_1,CMwNod *param_2, _func___cdecl_void_CGameMasterServerRequest_ptr *param_3);
};

#endif // CGAMEMASTERSERVERREQUEST_HPP
