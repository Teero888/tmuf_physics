#ifndef CFASTRECTTABLE_INT__HPP
#define CFASTRECTTABLE_INT__HPP

#include "typedefs.h"

struct CFastRectTable<int> {

    // Member Functions
    CMwNod * __thiscall Get (void *this,CSystemData *param_1,CSystemFid *param_2,CSystemFid *param_3,ulong *param_4);
    ulong __thiscall AddColumn(void *this,CFastRectTable<int> *param_1);
    void __thiscall AddLine (void *this,CPlugVisualLines2D *param_1,GmVec2 *param_2,GmVec2 *param_3,GxColor *param_4);
    void __thiscall CFastRectTable<int>(void *this,CFastRectTable<int> *param_1);
    void __thiscall ReplaceColumnByLastAt(void *this,CFastRectTable<int> *param_1,ulong param_2);
    void __thiscall ReplaceLineByLastAt(void *this,CFastRectTable<int> *param_1,ulong param_2);
    void __thiscall SetAllocColumnCountAtLeast (void *this,CFastRectTable<int> *param_1,ulong param_2);
    void __thiscall SetAllocLineCountAtLeast(void *this,CFastRectTable<int> *param_1,ulong param_2);
};

#endif // CFASTRECTTABLE_INT__HPP
