// BUG: I MESSED UP COPYING THESE SO THERE ARE DUPLICATES OF SOME FUNCTIONS
// RECOPY THEM IF I HAVE TIME

/* public: __thiscall CClassicArchive::CClassicArchive(void) */

void __thiscall CClassicArchive::CClassicArchive(CClassicArchive *this)

{
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  return;
}

/* public: class CClassicBuffer * __thiscall CClassicArchive::DetachBuffer(int)
 */

CClassicBuffer *__thiscall CClassicArchive::DetachBuffer(CClassicArchive *this,
                                                         int param_1)

{
  CClassicBuffer *pCVar1;

  if (((param_1 != 0) && (*(int *)(this + 0x14) != 0)) &&
      (s_DeleteMwIdUserDataCallBack != (_func_void_CClassicArchive_ptr *)0x0)) {
    (*s_DeleteMwIdUserDataCallBack)(this);
  }
  pCVar1 = *(CClassicBuffer **)(this + 4);
  *(undefined4 *)(this + 4) = 0;
  return pCVar1;
}

/* public: class CClassicBuffer * __thiscall CClassicArchive::DetachBuffer(int)
 */

CClassicBuffer *__thiscall CClassicArchive::DetachBuffer(CClassicArchive *this,
                                                         int param_1)

{
  CClassicBuffer *pCVar1;

  if (((param_1 != 0) && (*(int *)(this + 0x14) != 0)) &&
      (s_DeleteMwIdUserDataCallBack != (_func_void_CClassicArchive_ptr *)0x0)) {
    (*s_DeleteMwIdUserDataCallBack)(this);
  }
  pCVar1 = *(CClassicBuffer **)(this + 4);
  *(undefined4 *)(this + 4) = 0;
  return pCVar1;
}

void __thiscall CClassicArchive::DoBool(CClassicArchive *this, CClassicArchive *param_1, int *param_2, ulong param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteBool(this, param_1, param_2, param_3);
    return;
  }
  ReadBool(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoData(void *,unsigned long) */

void __thiscall CClassicArchive::DoData(CClassicArchive *this, void *param_1,
                                        ulong param_2)

{
  if (*(int *)(this + 8) != 0) {
    WriteData(this, param_1, param_2);
  }
  ReadData(this, param_1, param_2);
  return;
}

/* public: void __thiscall CClassicArchive::DoInteger(int *,unsigned long,int)
 */

void __thiscall CClassicArchive::DoInteger(CClassicArchive *this, int *param_1,
                                           ulong param_2, int param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteInteger(this, param_1, param_2, param_3);
    return;
  }
  ReadInteger(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoMarker(char const *) */

void __thiscall CClassicArchive::DoMarker(CClassicArchive *this, char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined local_104[256];
  uint local_4;

  local_4 = ___security_cookie ^ (uint)local_104;
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (*(int *)(this + 8) == 0) {
    ReadData(this, local_104, (int)pcVar2 - (int)(param_1 + 1));
  } else {
    WriteData(this, param_1, (int)pcVar2 - (int)(param_1 + 1));
  }
  @__security_check_cookie @4(local_4 ^ (uint)local_104);
  return;
}

/* public: void __thiscall CClassicArchive::DoMask(unsigned long *,unsigned
 * long) */

void __thiscall CClassicArchive::DoMask(CClassicArchive *this, ulong *param_1,
                                        ulong param_2)

{
  DoNatural(this, param_1, param_2, 1);
  return;
}

/* public: void __thiscall CClassicArchive::DoNat128(struct SNat128 *,unsigned
 * long) */

void __thiscall CClassicArchive::DoNat128(CClassicArchive *this,
                                          SNat128 *param_1, ulong param_2)

{
  DoData(this, param_1, param_2 << 4);
  return;
}

/* public: void __thiscall CClassicArchive::DoNat16(unsigned short *,unsigned
 * long,int) */

void __thiscall CClassicArchive::DoNat16(CClassicArchive *this, ushort *param_1,
                                         ulong param_2, int param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteNat16(this, param_1, param_2, param_3);
    return;
  }
  ReadNat16(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoNat64(unsigned __int64 *,unsigned
 * long,int) */

void __thiscall CClassicArchive::DoNat64(CClassicArchive *this,
                                         __uint64 *param_1, ulong param_2,
                                         int param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteNat64(this, param_1, param_2, param_3);
    return;
  }
  ReadNat64(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoNat8(unsigned char *,unsigned
 * long,int) */

void __thiscall CClassicArchive::DoNat8(CClassicArchive *this, uchar *param_1,
                                        ulong param_2, int param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteNat8(this, param_1, param_2, param_3);
    return;
  }
  ReadNat8(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoNatural(unsigned long *,unsigned
 * long,int) */

void __thiscall CClassicArchive::DoNatural(CClassicArchive *this,
                                           ulong *param_1, ulong param_2,
                                           int param_3)

{
  if (*(int *)(this + 8) != 0) {
    WriteNatural(this, param_1, param_2, param_3);
    return;
  }
  ReadNatural(this, param_1, param_2, param_3);
  return;
}

/* public: void __thiscall CClassicArchive::DoReal(float *,unsigned long) */

void __thiscall CClassicArchive::DoReal(CClassicArchive *this, float *param_1,
                                        ulong param_2)

{
  if (*(int *)(this + 8) != 0) {
    WriteReal(this, param_1, param_2);
    return;
  }
  ReadReal(this, param_1, param_2);
  return;
}

/* public: void __thiscall CClassicArchive::DoString(class CFastString
 * *,unsigned long) */

void __thiscall CClassicArchive::DoString(CClassicArchive *this,
                                          CFastString *param_1, ulong param_2)

{
  if (*(int *)(this + 8) != 0) {
    WriteString(this, param_1, param_2);
    return;
  }
  ReadString(this, param_1, param_2);
  return;
}

/* public: void __thiscall CClassicArchive::DoString(class CFastStringInt
 * *,unsigned long) */

void __thiscall CClassicArchive::DoString(CClassicArchive *this,
                                          CFastStringInt *param_1,
                                          ulong param_2)

{
  if (*(int *)(this + 8) != 0) {
    WriteString(this, param_1, param_2);
    return;
  }
  ReadString(this, param_1, param_2);
  return;
}

/* public: void __thiscall CClassicArchive::DoStringI18nComment(class
 * CFastStringInt *,char const *)
 */

void __thiscall CClassicArchive::DoStringI18nComment(CClassicArchive *this,
                                                     CFastStringInt *param_1,
                                                     char *param_2)

{
  if (*(int *)(this + 8) != 0) {
    WriteString(this, param_1, 1);
    return;
  }
  ReadString(this, param_1, 1);
  return;
}

/* public: void __thiscall CClassicArchive::MwDoNodRef<class CMwRefBuffer>(class
   CMwNodRef<class CMwRefBuffer> &) */

void __thiscall CClassicArchive::MwDoNodRef<>(CClassicArchive *this,
                                              CMwNodRef<> *param_1)

{
  CMwNodRef<> *pCVar1;
  CMwNod *unaff_retaddr;

  pCVar1 = param_1;
  param_1 = *(CMwNodRef<> **)param_1;
  (**(code **)(*(int *)this + 4))(&param_1);
  if (unaff_retaddr != *(CMwNod **)pCVar1) {
    if (unaff_retaddr != (CMwNod *)0x0) {
      CMwNod::MwAddRef(unaff_retaddr);
    }
    if (*(CMwNod **)pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pCVar1);
    }
    *(CMwNod **)pCVar1 = unaff_retaddr;
  }
  return;
}
/* public: void __thiscall CClassicArchive::ReadBool(int *,unsigned long) */

void __thiscall CClassicArchive::ReadBool(CClassicArchive *this, int *param_1,
                                          ulong param_2)

{
  uint uVar1;
  uint uVar2;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1,
                            param_2 * 4);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      uVar2 = uVar1 + 1;
      param_1[uVar1] = (uint)(DAT_00d71e88 == 'T');
      uVar1 = uVar2;
    } while (uVar2 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadData(void *,unsigned long) */

void __thiscall CClassicArchive::ReadData(CClassicArchive *this, void *param_1,
                                          ulong param_2)

{
  if (param_2 != 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadData(void *,unsigned long) */

void __thiscall CClassicArchive::ReadData(CClassicArchive *this, void *param_1,
                                          ulong param_2)

{
  if (param_2 != 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  return;
}

/* protected: int __thiscall CClassicArchive::ReadLine(void) */

int __thiscall CClassicArchive::ReadLine(CClassicArchive *this)

{
  int iVar1;
  undefined4 uStack_4;

  DAT_00d72e94 = 0;
  uStack_4 = this;
  while (true) {
    iVar1 = CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4),
                                    (void *)((int)&uStack_4 + 3), 1);
    if (iVar1 == 0) {
      return 0;
    }
    if (uStack_4._3_1_ == '|') {
      iVar1 = CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4),
                                      (void *)((int)&uStack_4 + 3), 1);
      if (iVar1 == 0) {
        return 0;
      }
      if (uStack_4._3_1_ == '\r') {
        iVar1 = CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4),
                                        (void *)((int)&uStack_4 + 3), 1);
        if (iVar1 == 0) {
          return 0;
        }
        (&DAT_00d71e88)[DAT_00d72e94] = 0;
        return 1;
      }
    }
    if ((uStack_4._3_1_ == '\n') &&
        (*(char *)((int)&CClassicBuffer::s_IsBufferExceptions + DAT_00d72e94 +
                   3) == '\r'))
      break;
    if (0xffe < DAT_00d72e94)
      goto LAB_0090960a;
    (&DAT_00d71e88)[DAT_00d72e94] = uStack_4._3_1_;
    DAT_00d72e94 = DAT_00d72e94 + 1;
  }
  DAT_00d72e94 = DAT_00d72e94 - 1;
LAB_0090960a:
  (&DAT_00d71e88)[DAT_00d72e94] = 0;
  return 0;
}

/* public: void __thiscall CClassicArchive::ReadMask(unsigned long *,unsigned
 * long) */

void __thiscall CClassicArchive::ReadMask(CClassicArchive *this, ulong *param_1,
                                          ulong param_2)

{
  ReadNatural(this, param_1, param_2, 1);
  return;
}

/* public: void __thiscall CClassicArchive::ReadNat16(unsigned short *,unsigned
 * long,int) */

void __thiscall CClassicArchive::ReadNat16(CClassicArchive *this,
                                           ushort *param_1, ulong param_2,
                                           int param_3)

{
  ulong uVar1;
  uint uVar2;
  char *_Format;

  uVar1 = param_2;
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1,
                            param_2 * 2);
    return;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      if (param_3 == 0) {
        _Format = "%hu";
      } else {
        _Format = "%hx";
      }
      _sscanf_s(&DAT_00d71e88, _Format, &param_2);
      param_1[uVar2] = (ushort)param_2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadNat64(unsigned __int64
 * *,unsigned long,int) */

void __thiscall CClassicArchive::ReadNat64(CClassicArchive *this,
                                           __uint64 *param_1, ulong param_2,
                                           int param_3)

{
  uint uVar1;
  char *_Format;
  undefined4 local_8;
  undefined4 local_4;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1,
                            param_2 * 8);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      if (param_3 == 0) {
        _Format = "%I64u";
      } else {
        _Format = "%I64x";
      }
      _sscanf_s(&DAT_00d71e88, _Format, &local_8);
      *(undefined4 *)(param_1 + uVar1) = local_8;
      *(undefined4 *)((int)param_1 + uVar1 * 8 + 4) = local_4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadNat8(unsigned char *,unsigned
 * long,int) */

void __thiscall CClassicArchive::ReadNat8(CClassicArchive *this, uchar *param_1,
                                          ulong param_2, int param_3)

{
  ulong uVar1;
  uint uVar2;
  char *_Format;

  uVar1 = param_2;
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      if (param_3 == 0) {
        _Format = "%hu";
      } else {
        _Format = "%hx";
      }
      _sscanf_s(&DAT_00d71e88, _Format, &param_2);
      param_1[uVar2] = (uchar)param_2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadNatural(unsigned long *,unsigned
 * long,int) */

void __thiscall CClassicArchive::ReadNatural(CClassicArchive *this,
                                             ulong *param_1, ulong param_2,
                                             int param_3)

{
  ulong uVar1;
  uint uVar2;
  char *_Format;

  uVar1 = param_2;
  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1,
                            param_2 * 4);
    return;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      if (param_3 == 0) {
        _Format = "%u";
      } else {
        _Format = "%x";
      }
      _sscanf_s(&DAT_00d71e88, _Format, &param_2);
      param_1[uVar2] = param_2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}

/* public: void __thiscall CClassicArchive::ReadReal(float *,unsigned long) */

void __thiscall CClassicArchive::ReadReal(CClassicArchive *this, float *param_1,
                                          ulong param_2)

{
  uint uVar1;
  double dVar2;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::ReadAll(*(CClassicBuffer **)(this + 4), param_1,
                            param_2 * 4);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      ReadLine(this);
      dVar2 = _atof(&DAT_00d71e88);
      param_1[uVar1] = (float)dVar2;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CClassicArchive::ReadString(class CFastString
 * *,unsigned long) */

void __thiscall CClassicArchive::ReadString(CClassicArchive *this,
                                            CFastString *param_1, ulong param_2)

{
  undefined *puVar1;
  bool bVar2;
  int iVar3;
  CFastString *pCVar4;
  int *this_00;
  undefined4 *this_01;
  ulong uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 *local_c;
  char *local_8;
  CClassicArchive *local_4;

  uVar5 = param_2;
  local_4 = this;
  if (*(int *)(this + 0xc) == 0) {
    this_01 = (undefined4 *)param_1;
    if (param_2 != 0) {
      do {
        local_c = (undefined1 *)0xffffffff;
        iVar3 = CClassicBuffer::ReadAll(*(CClassicBuffer **)(local_4 + 4),
                                        &local_c, 4);
        if (((undefined1 *)0xfffffff < local_c) || (iVar3 == 0)) {
          if (_s_LogStringToAdd != 0) {
            _s_LogStringToAdd = 0;
            *DAT_00d71e58 = 0;
          }
          pcVar8 = "\r\n";
          pcVar7 = ")";
          puVar6 = local_c;
          pCVar4 = CFastString::operator<<(
              &CClassicLog::s_LogStringToAdd,
              "[CrashInfo] Corrupted ReadString? (Length = ");
          pCVar4 = CFastString::operator<<(pCVar4, (ulong)puVar6);
          pCVar4 = CFastString::operator<<(pCVar4, pcVar7);
          CFastString::operator<<(pCVar4, pcVar8);
          CClassicLog::AddLogStringInFile();
          if (s_ThrowCorruptedArchive != (_func_void *)0x0) {
            (*s_ThrowCorruptedArchive)();
          }
        }
        puVar6 = local_c;
        if (local_c != (undefined1 *)*this_01) {
          CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this_01,
                                              (ulong)local_c, 1,
                                              (SOldChars *)0x0);
          puVar6[this_01[1]] = 0;
          *this_01 = puVar6;
        }
        if (((local_c != (undefined1 *)0x0) &&
             (iVar3 =
                  CClassicBuffer::ReadAll(*(CClassicBuffer **)(local_4 + 4),
                                          (void *)this_01[1], (ulong)local_c),
              iVar3 == 0)) &&
            (s_ThrowCorruptedArchive != (_func_void *)0x0)) {
          (*s_ThrowCorruptedArchive)();
        }
        this_01 = this_01 + 2;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
  } else {
    this_00 = (int *)param_1;
    if (param_2 != 0) {
      do {
        bVar2 = false;
        if (*this_00 != 0) {
          *this_00 = 0;
          *(undefined *)this_00[1] = 0;
          bVar2 = false;
        }
        do {
          iVar3 = ReadLine(local_4);
          if (iVar3 == 0) {
            bVar2 = true;
          } else {
            (&DAT_00d71e88)[DAT_00d72e94] = 0xd;
            (&DAT_00d71e89)[DAT_00d72e94] = 10;
            puVar1 = &DAT_00d71e8a + DAT_00d72e94;
            DAT_00d72e94 = DAT_00d72e94 + 2;
            *puVar1 = 0;
          }
          local_c = &DAT_00d71e88;
          pcVar7 = &DAT_00d71e88;
          do {
            local_8 = pcVar7;
            pcVar7 = local_8 + 1;
          } while (*local_8 != '\0');
          local_8 = local_8 + -0xd71e88;
          CFastString::Concat((CFastString *)this_00, (SStringParam *)&local_c);
        } while (!bVar2);
        param_2 = param_2 - 1;
        this_00 = this_00 + 2;
      } while (param_2 != 0);
    }
  }
  if ((s_AllowUnprintableStrings == 0) && (uVar5 != 0)) {
    do {
      CFastString::FilterStringForPrintableChars(param_1);
      param_1 = param_1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CClassicArchive::ReadString(class CFastString
 * *,unsigned long) */

void __thiscall CClassicArchive::ReadString(CClassicArchive *this,
                                            CFastString *param_1, ulong param_2)

{
  undefined *puVar1;
  bool bVar2;
  int iVar3;
  CFastString *pCVar4;
  int *this_00;
  undefined4 *this_01;
  ulong uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined1 *local_c;
  char *local_8;
  CClassicArchive *local_4;

  uVar5 = param_2;
  local_4 = this;
  if (*(int *)(this + 0xc) == 0) {
    this_01 = (undefined4 *)param_1;
    if (param_2 != 0) {
      do {
        local_c = (undefined1 *)0xffffffff;
        iVar3 = CClassicBuffer::ReadAll(*(CClassicBuffer **)(local_4 + 4),
                                        &local_c, 4);
        if (((undefined1 *)0xfffffff < local_c) || (iVar3 == 0)) {
          if (_s_LogStringToAdd != 0) {
            _s_LogStringToAdd = 0;
            *DAT_00d71e58 = 0;
          }
          pcVar8 = "\r\n";
          pcVar7 = ")";
          puVar6 = local_c;
          pCVar4 = CFastString::operator<<(
              &CClassicLog::s_LogStringToAdd,
              "[CrashInfo] Corrupted ReadString? (Length = ");
          pCVar4 = CFastString::operator<<(pCVar4, (ulong)puVar6);
          pCVar4 = CFastString::operator<<(pCVar4, pcVar7);
          CFastString::operator<<(pCVar4, pcVar8);
          CClassicLog::AddLogStringInFile();
          if (s_ThrowCorruptedArchive != (_func_void *)0x0) {
            (*s_ThrowCorruptedArchive)();
          }
        }
        puVar6 = local_c;
        if (local_c != (undefined1 *)*this_01) {
          CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this_01,
                                              (ulong)local_c, 1,
                                              (SOldChars *)0x0);
          puVar6[this_01[1]] = 0;
          *this_01 = puVar6;
        }
        if (((local_c != (undefined1 *)0x0) &&
             (iVar3 =
                  CClassicBuffer::ReadAll(*(CClassicBuffer **)(local_4 + 4),
                                          (void *)this_01[1], (ulong)local_c),
              iVar3 == 0)) &&
            (s_ThrowCorruptedArchive != (_func_void *)0x0)) {
          (*s_ThrowCorruptedArchive)();
        }
        this_01 = this_01 + 2;
        param_2 = param_2 - 1;
      } while (param_2 != 0);
    }
  } else {
    this_00 = (int *)param_1;
    if (param_2 != 0) {
      do {
        bVar2 = false;
        if (*this_00 != 0) {
          *this_00 = 0;
          *(undefined *)this_00[1] = 0;
          bVar2 = false;
        }
        do {
          iVar3 = ReadLine(local_4);
          if (iVar3 == 0) {
            bVar2 = true;
          } else {
            (&DAT_00d71e88)[DAT_00d72e94] = 0xd;
            (&DAT_00d71e89)[DAT_00d72e94] = 10;
            puVar1 = &DAT_00d71e8a + DAT_00d72e94;
            DAT_00d72e94 = DAT_00d72e94 + 2;
            *puVar1 = 0;
          }
          local_c = &DAT_00d71e88;
          pcVar7 = &DAT_00d71e88;
          do {
            local_8 = pcVar7;
            pcVar7 = local_8 + 1;
          } while (*local_8 != '\0');
          local_8 = local_8 + -0xd71e88;
          CFastString::Concat((CFastString *)this_00, (SStringParam *)&local_c);
        } while (!bVar2);
        param_2 = param_2 - 1;
        this_00 = this_00 + 2;
      } while (param_2 != 0);
    }
  }
  if ((s_AllowUnprintableStrings == 0) && (uVar5 != 0)) {
    do {
      CFastString::FilterStringForPrintableChars(param_1);
      param_1 = param_1 + 8;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: void __thiscall CClassicArchive::SkipData(unsigned long) */

void __thiscall CClassicArchive::SkipData(CClassicArchive *this, ulong param_1)

{
  CFastString *this_00;
  uint uVar1;
  char *pcVar2;

  if (param_1 != 0) {
    if (*(int *)(this + 8) == 0) {
      CClassicBuffer::Skip(*(CClassicBuffer **)(this + 4), param_1);
    } else {
      if (_s_LogStringToAdd != 0) {
        _s_LogStringToAdd = 0;
        *DAT_00d71e58 = 0;
      }
      pcVar2 = "\r\n";
      this_00 = CFastString::operator<<(&CClassicLog::s_LogStringToAdd,
                                        "[Archive] SAVING ERROR: Saving "
                                        "skipped datas => data may be lost !!");
      CFastString::operator<<(this_00, pcVar2);
      CClassicLog::AddLogStringInFile();
      _memset(&DAT_00d71e88, 0, 0x1000);
      if (param_1 != 0) {
        do {
          uVar1 = param_1;
          if (0x1000 < param_1) {
            uVar1 = 0x1000;
          }
          WriteData(this, &DAT_00d71e88, uVar1);
          param_1 = param_1 - uVar1;
        } while (param_1 != 0);
        return;
      }
    }
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteBool(int const *,unsigned long)
 */

void __thiscall CClassicArchive::WriteBool(CClassicArchive *this, int *param_1,
                                           ulong param_2)

{
  uint uVar1;
  char *pcVar2;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1,
                             param_2 * 4);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (param_1[uVar1] == 0) {
        pcVar2 = "False";
      } else {
        pcVar2 = "True";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88, pcVar2);
      WriteLine(this);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteData(void const *,unsigned
 * long) */

void __thiscall CClassicArchive::WriteData(CClassicArchive *this, void *param_1,
                                           ulong param_2)

{
  if (param_2 != 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteData(void const *,unsigned
 * long) */

void __thiscall CClassicArchive::WriteData(CClassicArchive *this, void *param_1,
                                           ulong param_2)

{
  if (param_2 != 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  return;
}

/* protected: void __thiscall CClassicArchive::WriteLine(void) */

void __thiscall CClassicArchive::WriteLine(CClassicArchive *this)

{
  (&DAT_00d71e88)[DAT_00d72e94] = 0xd;
  (&DAT_00d71e89)[DAT_00d72e94] = 10;
  DAT_00d72e94 = DAT_00d72e94 + 2;
  CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), &DAT_00d71e88,
                           DAT_00d72e94);
  return;
}

/* protected: void __thiscall CClassicArchive::WriteLine(void) */

void __thiscall CClassicArchive::WriteLine(CClassicArchive *this)

{
  (&DAT_00d71e88)[DAT_00d72e94] = 0xd;
  (&DAT_00d71e89)[DAT_00d72e94] = 10;
  DAT_00d72e94 = DAT_00d72e94 + 2;
  CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), &DAT_00d71e88,
                           DAT_00d72e94);
  return;
}

void __thiscall CClassicArchive::WriteMask(CClassicArchive *this, CClassicArchive *param_1, ulong *param_2, ulong param_3)

{
  int unaff_retaddr;

  WriteNatural(this, param_1, param_2, 1, unaff_retaddr);
  return;
}

/* public: void __thiscall CClassicArchive::WriteNat16(unsigned short const
 * *,unsigned long,int) */

void __thiscall CClassicArchive::WriteNat16(CClassicArchive *this,
                                            ushort *param_1, ulong param_2,
                                            int param_3)

{
  ushort uVar1;
  uint uVar2;
  char *pcVar3;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1,
                             param_2 * 2);
    return;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      if (param_3 == 0) {
        uVar1 = param_1[uVar2];
        pcVar3 = "%hu";
      } else {
        uVar1 = param_1[uVar2];
        pcVar3 = "%hx";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88, pcVar3, (uint)uVar1);
      WriteLine(this);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteNat64(unsigned __int64 const
 * *,unsigned long,int)
 */

void __thiscall CClassicArchive::WriteNat64(CClassicArchive *this,
                                            __uint64 *param_1, ulong param_2,
                                            int param_3)

{
  uint uVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 uVar4;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1,
                             param_2 * 8);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (param_3 == 0) {
        uVar4 = *(undefined4 *)((int)param_1 + uVar1 * 8 + 4);
        uVar3 = *(undefined4 *)(param_1 + uVar1);
        pcVar2 = "%I64u";
      } else {
        uVar4 = *(undefined4 *)((int)param_1 + uVar1 * 8 + 4);
        uVar3 = *(undefined4 *)(param_1 + uVar1);
        pcVar2 = "%I64x";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88, pcVar2, uVar3, uVar4);
      WriteLine(this);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteNat8(unsigned char const
 * *,unsigned long,int) */

void __thiscall CClassicArchive::WriteNat8(CClassicArchive *this,
                                           uchar *param_1, ulong param_2,
                                           int param_3)

{
  uint uVar1;
  char *pcVar2;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1, param_2);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (param_3 == 0) {
        pcVar2 = "%hu";
      } else {
        pcVar2 = "%hx";
      }
      DAT_00d72e94 =
          sprintf_s<4096>(&DAT_00d71e88, pcVar2, (uint)param_1[uVar1]);
      WriteLine(this);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteNatural(unsigned long const
 * *,unsigned long,int) */

void __thiscall CClassicArchive::WriteNatural(CClassicArchive *this,
                                              ulong *param_1, ulong param_2,
                                              int param_3)

{
  uint uVar1;
  char *pcVar2;
  ulong uVar3;

  if (*(int *)(this + 0xc) == 0) {
    CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1,
                             param_2 * 4);
    return;
  }
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (param_3 == 0) {
        uVar3 = param_1[uVar1];
        pcVar2 = "%u";
      } else {
        uVar3 = param_1[uVar1];
        pcVar2 = "%x";
      }
      DAT_00d72e94 = sprintf_s<4096>(&DAT_00d71e88, pcVar2, uVar3);
      WriteLine(this);
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteReal(float const *,unsigned
 * long) */

void __thiscall CClassicArchive::WriteReal(CClassicArchive *this,
                                           float *param_1, ulong param_2)

{
  uint uVar1;

  if (*(int *)(this + 0xc) != 0) {
    uVar1 = 0;
    if (param_2 != 0) {
      do {
        DAT_00d72e94 =
            sprintf_s<4096>(&DAT_00d71e88, "%f", (double)param_1[uVar1]);
        WriteLine(this);
        uVar1 = uVar1 + 1;
      } while (uVar1 < param_2);
    }
    return;
  }
  // TODO: idk what this means, its annotated as override in ghidra
  CClassicBuffer::WriteAll(*(CClassicBuffer **)(this + 4), param_1,
                           param_2 * 4);
  return;
}
/* public: void __thiscall CClassicArchive::WriteString(class CFastString const
 * *,unsigned long) */

void __thiscall CClassicArchive::WriteString(CClassicArchive *this,
                                             CFastString *param_1,
                                             ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  CFastString *pCVar3;
  uint uVar4;
  uint uVar5;
  uint local_4;

  pCVar3 = param_1;
  if (*(int *)(this + 0xc) == 0) {
    uVar5 = 0;
    if (param_2 != 0) {
      do {
        param_1 = *(CFastString **)(pCVar3 + uVar5 * 8);
        uVar2 = *(undefined4 *)(pCVar3 + uVar5 * 8 + 4);
        (**(code **)(**(int **)(this + 4) + 8))(&param_1, 4);
        if (param_1 != (CFastString *)0x0) {
          (**(code **)(**(int **)(this + 4) + 8))(uVar2, param_1);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_2);
    }
  } else {
    local_4 = 0;
    if (param_2 != 0) {
      do {
        uVar5 = *(uint *)(param_1 + local_4 * 8);
        iVar1 = *(int *)(param_1 + local_4 * 8 + 4);
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            if (*(char *)(iVar1 + uVar4) == '|') {
              WriteData(this, "|", 1);
            }
            if ((*(char *)(iVar1 + uVar4) == '\r') &&
                (*(char *)(iVar1 + 1 + uVar4) == '\n')) {
              WriteData(this, "|", 1);
            }
            (**(code **)(**(int **)(this + 4) + 8))((char *)(iVar1 + uVar4), 1);
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar5);
        }
        WriteData(this, "\r\n", 2);
        local_4 = local_4 + 1;
      } while (local_4 < param_2);
      return;
    }
  }
  return;
}

/* public: void __thiscall CClassicArchive::WriteString(class CFastStringInt
 * const *,unsigned long)
 */

void __thiscall CClassicArchive::WriteString(CClassicArchive *this,
                                             CFastStringInt *param_1,
                                             ulong param_2)

{
  int iVar1;
  uint uVar2;
  ulong local_4;

  if (param_2 != 0) {
    local_4 = param_2;
    do {
      CFastStringInt::GetUtf8OrAscii(param_1, (CFastString *)&DAT_00d72e98);
      iVar1 = DAT_00d72e9c;
      param_2 = DAT_00d72e98;
      if (*(int *)(this + 0xc) == 0) {
        (**(code **)(**(int **)(this + 4) + 8))(&param_2, 4);
        if (param_2 != 0) {
          (**(code **)(**(int **)(this + 4) + 8))(iVar1, param_2);
        }
      } else {
        uVar2 = 0;
        if (DAT_00d72e98 != 0) {
          do {
            if (*(char *)(iVar1 + uVar2) == '|') {
              WriteData(this, "|", 1);
            }
            if ((*(char *)(iVar1 + uVar2) == '\r') &&
                (*(char *)(iVar1 + 1 + uVar2) == '\n')) {
              WriteData(this, "|", 1);
            }
            (**(code **)(**(int **)(this + 4) + 8))((char *)(iVar1 + uVar2), 1);
            uVar2 = uVar2 + 1;
          } while (uVar2 < param_2);
        }
        WriteData(this, "\r\n", 2);
      }
      param_1 = param_1 + 8;
      local_4 = local_4 - 1;
    } while (local_4 != 0);
  }
  return;
}

/* public: virtual __thiscall CClassicArchive::~CClassicArchive(void) */

void __thiscall CClassicArchive::~CClassicArchive(CClassicArchive *this)

{
  *(undefined ***)this = vftable;
  if ((*(int *)(this + 0x14) != 0) &&
      (s_DeleteMwIdUserDataCallBack != (_func_void_CClassicArchive_ptr *)0x0)) {
    (*s_DeleteMwIdUserDataCallBack)(this);
  }
  return;
}
