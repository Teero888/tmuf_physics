#ifndef CCLASSICBUFFER_HPP
#define CCLASSICBUFFER_HPP
#include "typedefs.h"

class CClassicBufferMemory;

class CClassicBuffer {
  // TODO: figure out fields and types

  __thiscall CClassicBuffer();
  __thiscall ~CClassicBuffer();
  void *__thiscall scalar_deleting_destructor(uint param_1);
  void __thiscall AddCompressedBlock(CClassicBufferMemory *param_1);
  int __thiscall CopyFrom(CClassicBuffer *param_1);
  CClassicBufferMemory *__thiscall CreateUncompressedBlock();
  int __thiscall IsEqualBuffer(CClassicBuffer *param_1);
  int __thiscall ReadAll(void *param_1, ulong param_2);
  ulong __thiscall Skip(ulong param_1);
  int __thiscall WriteAll(void *param_1, ulong param_2);
};

#endif // CCLASSICBUFFER_HPP