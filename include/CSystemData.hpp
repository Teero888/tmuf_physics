#ifndef CSYSTEMDATA_HPP
#define CSYSTEMDATA_HPP

#include "typedefs.h"

struct CMwNod;
struct CSystemFid;
struct CSystemPackDesc;
struct CSystemPackManager;

struct CSystemData {
    void** vftable; // accesses: 1

    // Member Functions
    CMwNod * __thiscall Get(CSystemData *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3, ulong *param_4);
    CSystemFid * __thiscall GetFid(CSystemData *this,CSystemData *param_1,CMwNod *param_2,CSystemFid *param_3, ulong *param_4);
    void __thiscall CSystemData(CSystemData *this,CSystemData *param_1);
    void __thiscall Set(CSystemData *this,CMwCmdScriptVarBool *param_1,int param_2);
    void __thiscall SetUpToDate(CSystemData *this,CSystemData *param_1,int param_2);
    void __thiscall SetUrl(CSystemData *this,CSystemData *param_1,CFastString *param_2,CFastString *param_3 );
};

#endif // CSYSTEMDATA_HPP
