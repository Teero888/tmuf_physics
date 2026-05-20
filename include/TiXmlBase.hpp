#ifndef TIXMLBASE_HPP
#define TIXMLBASE_HPP

#include "typedefs.h"

struct TiXmlBase {

    // Member Functions
    bool __cdecl StringEqual(char *param_1,char *param_2,bool param_3,TiXmlEncoding param_4);
    char * __cdecl SkipWhiteSpace(char *param_1,TiXmlEncoding param_2);
    int __cdecl IsAlpha(uchar param_1,TiXmlEncoding param_2);
};

#endif // TIXMLBASE_HPP
