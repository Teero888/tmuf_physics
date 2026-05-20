#ifndef CGAMENETSERVERINFO_HPP
#define CGAMENETSERVERINFO_HPP

#include "typedefs.h"

struct CGameNetServerInfo {
    byte _padding_0x0[180];
    int field_0xb4; // accesses: 2

    // Member Functions
    void __thiscall SetReloadNeeded (CGameNetServerInfo *this,CGameNetServerInfo *param_1,EReload param_2);
};

#endif // CGAMENETSERVERINFO_HPP
