#ifndef GMUNIT_HPP
#define GMUNIT_HPP

#include "typedefs.h"

struct GmUnit {

    // Member Functions
    /* WARNING: Globals starting with '_' overlap smaller symbols at the same address */ float __cdecl ConvertReal(EConvertMethod param_1,float param_2);
    int __cdecl ConvertMethodGet(CFastString *param_1,EConvertMethod *param_2,CFastStringInt *param_3);
    void __cdecl ConvertRealString(EConvertMethod param_1,CFastStringInt *param_2);
};

#endif // GMUNIT_HPP
