#ifndef CCLASSICARCHIVE_HPP
#define CCLASSICARCHIVE_HPP
#include "typedefs.h"

class CClassicBuffer;
class SNat128;

class CClassicArchive {
  // TODO: figure out fields and types

  __thiscall CClassicArchive();
  __thiscall ~CClassicArchive();

  CClassicBuffer *__thiscall DetachBuffer(int param_1);

  void __thiscall DoBool(int *param_1, ulong param_2);
  void __thiscall DoData(void *param_1, ulong param_2);
  void __thiscall DoInteger(int *param_1, ulong param_2, int param_3);
  void __thiscall DoMarker(char *param_1);
  void __thiscall DoMask(ulong *param_1, ulong param_2);
  void __thiscall DoNat128(SNat128 *param_1, ulong param_2);
  void __thiscall DoNat16(ushort *param_1, ulong param_2, int param_3);
  void __thiscall DoNat64(__uint64 *param_1, ulong param_2, int param_3);
  void __thiscall DoNat8(uchar *param_1, ulong param_2, int param_3);
  void __thiscall DoNatural(ulong *param_1, ulong param_2, int param_3);
  void __thiscall DoReal(float *param_1, ulong param_2);
  void __thiscall DoString(CFastString *param_1, ulong param_2);
  void __thiscall DoString(CFastStringInt *param_1, ulong param_2);
  void __thiscall DoStringI18nComment(CFastStringInt *param_1, char *param_2);
  void __thiscall MwDoNodRef<CMwRefBuffer>(CMwNodRef<CMwRefBuffer> *param_1);

  void __thiscall ReadBool(int *param_1, ulong param_2);
  void __thiscall ReadData(void *param_1, ulong param_2);
  void __thiscall ReadInteger(int *param_1, ulong param_2, int param_3);
  int __thiscall ReadLine();
  void __thiscall ReadMask(ulong *param_1, ulong param_2);
  void __thiscall ReadNat16(ushort *param_1, ulong param_2, int param_3);
  void __thiscall ReadNat64(__uint64 *param_1, ulong param_2, int param_3);
  void __thiscall ReadNat8(uchar *param_1, ulong param_2, int param_3);
  void __thiscall ReadNatural(ulong *param_1, ulong param_2, int param_3);
  void __thiscall ReadReal(float *param_1, ulong param_2);
  void __thiscall ReadString(CFastString *param_1, ulong param_2);
  void __thiscall ReadString(CFastStringInt *param_1, ulong param_2);

  void __thiscall SkipData(ulong param_1);

  void __thiscall WriteBool(int *param_1, ulong param_2);
  void __thiscall WriteData(void *param_1, ulong param_2);
  void __thiscall WriteInteger(int *param_1, ulong param_2, int param_3);
  void __thiscall WriteLine();
  void __thiscall WriteMask(ulong *param_1, ulong param_2);
  void __thiscall WriteNat16(ushort *param_1, ulong param_2, int param_3);
  void __thiscall WriteNat64(__uint64 *param_1, ulong param_2, int param_3);
  void __thiscall WriteNat8(uchar *param_1, ulong param_2, int param_3);
  void __thiscall WriteNatural(ulong *param_1, ulong param_2, int param_3);
  void __thiscall WriteReal(float *param_1, ulong param_2);
  void __thiscall WriteString(CFastString *param_1, ulong param_2);
  void __thiscall WriteString(CFastStringInt *param_1, ulong param_2);
};

#endif // CCLASSICARCHIVE_HPP