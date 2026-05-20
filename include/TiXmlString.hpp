#ifndef TIXMLSTRING_HPP
#define TIXMLSTRING_HPP

#include "typedefs.h"

struct TiXmlString {

    // Member Functions
    TiXmlString * __thiscall append(void *this,TiXmlString *param_1,char *param_2,uint param_3);
    TiXmlString * __thiscall assign(void *this,TiXmlString *param_1,char *param_2,uint param_3);
    void __thiscall TiXmlString(void *this,TiXmlString *param_1,char *param_2,uint param_3);
    void __thiscall init(void *this,basic_ios<char,struct_std::char_traits<char>_> *param_1, basic_streambuf<char,struct_std::char_traits<char>_> *param_2,bool param_3);
    void __thiscall reserve (void *this,vector<class_NvFaceInfo*,class_std::allocator<class_NvFaceInfo*>_> *param_1, uint param_2);
};

#endif // TIXMLSTRING_HPP
