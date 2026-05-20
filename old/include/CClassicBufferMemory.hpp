#ifndef CCLASSICBUFFERMEMORY_H
#define CCLASSICBUFFERMEMORY_H

#include "typedefs.h"

class CClassicBuffer;

class CClassicBufferMemory {
  // TODO: figure out fields and types

  __thiscall CClassicBufferMemory();
  __thiscall ~CClassicBufferMemory();

  void *__thiscall scalar_deleting_destructor(uint param_1);
  void __thiscall AdvanceOffset(ulong param_1);
  void __thiscall Attach(void *param_1, ulong param_2);
  int __thiscall Close();
  void __thiscall CopyAndDetachBufferMemory(CClassicBufferMemory *param_1);
  void __thiscall Empty();
  void __thiscall EmptyAndFreeMemory();
  ulong __thiscall GetActualSize();
  int __thiscall IsEqualBuffer(CClassicBufferMemory *param_1);
  void __thiscall PreAlloc(ulong param_1);
  ulong __thiscall Read(void *param_1, ulong param_2);
  void __thiscall Reset();
  void __thiscall SetCurOffset(ulong param_1);
  ulong __thiscall Write(void *param_1, ulong param_2);
  ulong __thiscall WriteCopy(CClassicBuffer *param_1, ulong param_2);
  ulong __thiscall WriteVoid(ulong param_1);
};

#endif // CCLASSICBUFFERMEMORY_H