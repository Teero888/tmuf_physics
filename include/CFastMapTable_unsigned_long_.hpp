#ifndef CFASTMAPTABLE_UNSIGNED_LONG__HPP
#define CFASTMAPTABLE_UNSIGNED_LONG__HPP

#include "typedefs.h"

struct CFastMapTable<unsigned_long> {
    struct SScanner {
        byte _padding_0x0[4];
        int field_0x4; // accesses: 2
        byte _padding_0x8[4];
        uint field_0xc; // accesses: 2

        // Member Functions
        int __thiscall GetNext (void *this,SScanner *param_1,ulong *param_2,SFillValue *param_3);
    };

    byte _padding_0x0[4];
    int field_0x4; // accesses: 11
    int field_0x8; // accesses: 9
    ulong field_0xc; // accesses: 9

    // Member Functions
    CFastString __thiscall GetElem (CFastMapTable<unsigned_long> *this,CVirtualisedBuffer<class_CFastString> *param_1, ulong param_2);
    int __thiscall IsPresent (CFastMapTable<unsigned_long> *this,CFastMapTable<unsigned_long> *param_1,ulong param_2);
    int __thiscall Resize(CFastMapTable<unsigned_long> *this,CVisionViewportDx9 *param_1);
    ulong __thiscall GetIndex (CFastMapTable<unsigned_long> *this,SStackLocation *param_1,SLocationAlloc *param_2);
    void __thiscall Add (CFastMapTable<unsigned_long> *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2);
    void __thiscall CFastMapTable<unsigned_long> (CFastMapTable<unsigned_long> *this,CFastMapTable<unsigned_long> *param_1,ulong param_2);
    void __thiscall Clear(CFastMapTable<unsigned_long> *this,TiXmlNode *param_1);
    void __thiscall RemoveIfFound (CFastMapTable<unsigned_long> *this,CFastBuffer<unsigned_int> *param_1,uint *param_2);
};

#endif // CFASTMAPTABLE_UNSIGNED_LONG__HPP
