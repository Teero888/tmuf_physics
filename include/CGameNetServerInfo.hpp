#ifndef CGAMENETSERVERINFO_HPP
#define CGAMENETSERVERINFO_HPP

#include "typedefs.h"

struct CGameNetServerInfo {
    void** vftable;
    byte _final_padding[0xe]; // Total size: 0x12

    // Member Functions
    void __thiscall SetReloadNeeded (CGameNetServerInfo *this,CGameNetServerInfo *param_1,EReload param_2);
};

#endif // CGAMENETSERVERINFO_HPP
