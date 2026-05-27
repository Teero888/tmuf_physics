#ifndef CSCENEPICKERMANAGER_HPP
#define CSCENEPICKERMANAGER_HPP

#include "typedefs.h"

struct CHmsPicker;
struct CMwCmd;
struct CMwNod;

struct CScenePickerManager {
    void** vftable; // accesses: 1

    // Member Functions
    void __thiscall CScenePickerManager(CScenePickerManager *this,CScenePickerManager *param_1);
    void __thiscall EndFocus (CScenePickerManager *this,CScenePickerManager *param_1,CScenePickedItem *param_2);
    void __thiscall FillSceneInfoMouse (CScenePickerManager *this,CScenePickerManager *param_1,CSceneInfoMouse *param_2);
    void __thiscall Reset(CScenePickerManager *this,GmFrustumIso4 *param_1);
};

#endif // CSCENEPICKERMANAGER_HPP
