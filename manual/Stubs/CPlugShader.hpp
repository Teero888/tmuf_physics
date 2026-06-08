#ifndef CPLUGSHADER_HPP
#define CPLUGSHADER_HPP

#include "CMwNod.hpp"
class CPlugBitmapRender;
class CPlugShader : public CMwNod {
public:
    static CPlugBitmapRender* FindBitmapRenderByClassId(CPlugShader* s, CPlugShader* s2, int i, void* p, void* p2) { return nullptr; }
};

#endif
