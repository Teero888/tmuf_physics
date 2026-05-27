#ifndef CMWPARAMFASTBUFFER_CLASS_CMWPARAMMWID__HPP
#define CMWPARAMFASTBUFFER_CLASS_CMWPARAMMWID__HPP

#include "typedefs.h"

struct CMwParamFastBuffer<class_CMwParamMwId> {
    void** vftable;

    // Member Functions
    GmVec4 * __cdecl GetElemFromStack (CFastBufferCat<class_GmVec4,struct_SFastCat> *param_1,CMwStack *param_2);
};

#endif // CMWPARAMFASTBUFFER_CLASS_CMWPARAMMWID__HPP
