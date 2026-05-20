#ifndef CFASTBUFFER_UNSIGNED_SHORT__HPP
#define CFASTBUFFER_UNSIGNED_SHORT__HPP

#include "typedefs.h"

struct CFastBuffer<unsigned_short> {
    void** vftable; // accesses: 4
    void * field_0x4; // accesses: 5
    uint field_0x8; // accesses: 1

    // Member Functions
    void __thiscall Add(void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall CopyFromFastBuffer (void *this,CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_1, CFastBuffer<struct_CDx9StateBlock::STexStageState> *param_2);
    void __thiscall SetSizeAtLeast (void *this,CFastBuffer<struct_CCrystal::SSmoothingGroup> *param_1,ulong param_2);
};

#endif // CFASTBUFFER_UNSIGNED_SHORT__HPP
