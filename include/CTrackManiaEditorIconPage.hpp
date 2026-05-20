#ifndef CTRACKMANIAEDITORICONPAGE_HPP
#define CTRACKMANIAEDITORICONPAGE_HPP

#include "typedefs.h"

struct CTrackManiaEditorIconPage {
    byte _padding_0x0[40];
    int field_0x28; // accesses: 1

    // Member Functions
    CFastString __thiscall GetName (CTrackManiaEditorIconPage *this,CTrackManiaEditorIconPage *param_1);
    CTrackManiaEditorIcon * __thiscall GetRepresentativeArticleIcon (CTrackManiaEditorIconPage *this,CTrackManiaEditorIconPage *param_1);
    void __thiscall GetIcon (CTrackManiaEditorIconPage *this,CMwParamFastBuffer<class_CMwParamVec4> *param_1, EMwIconList *param_2,EMwIconList *param_3);
};

#endif // CTRACKMANIAEDITORICONPAGE_HPP
