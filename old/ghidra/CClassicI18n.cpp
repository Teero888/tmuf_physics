
/* public: virtual void * __thiscall CClassicI18n::`vector deleting
 * destructor'(unsigned int) */

void *__thiscall CClassicI18n::`vector_deleting_destructor'(CClassicI18n *this,uint param_1)

{
  ~CClassicI18n(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

/* public: __thiscall CClassicI18n::CClassicI18n(void) */

CClassicI18n *__thiscall CClassicI18n::CClassicI18n(CClassicI18n *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0d9b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  CFastArray<>::CFastArray<>((CFastArray<> *)(this + 0x10));
  local_4 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  _strcpy_s((char *)(this + 0x28), 0x20, "xx");
  ExceptionList = local_c;
  return this;
}

/* private: void __thiscall CClassicI18n::ComputeHashTable(void) */

void __thiscall CClassicI18n::ComputeHashTable(CClassicI18n *this)

{
  ulong uVar1;
  void *_Dst;

  operator_delete[](*(void **)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0;
  if (((*(ulong *)(this + 4) != 0) && (*(int *)(this + 8) != 0)) &&
      (*(int *)(this + 0xc) != 0)) {
    uVar1 = CFastAlgo::ComputeHashSize(*(ulong *)(this + 4));
    *(ulong *)(this + 0x20) = uVar1;
    _Dst = operator_new[](-(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) |
                          (uint)((ulonglong)uVar1 * 2));
    *(void **)(this + 0x1c) = _Dst;
    _memset(_Dst, -1, *(int *)(this + 0x20) * 2);
    if (*(int *)(this + 4) != 0) {
      uVar1 = 0;
      do {
        InsertMsg(this, *(wchar_t **)(*(int *)(this + 8) + uVar1 * 4), uVar1);
        uVar1 = uVar1 + 1;
      } while (uVar1 < *(uint *)(this + 4));
    }
  }
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static wchar_t const * __cdecl
   CClassicI18n::ConvertStringForWin32(class CFastStringInt
   &) */

wchar_t *__cdecl CClassicI18n::ConvertStringForWin32(CFastStringInt *param_1)

{
  char *local_10;
  undefined4 local_c;
  char *local_8;
  undefined4 local_4;

  CFastStringInt::GetUtf8(param_1, &CFastString::s_Temp, 0);
  local_10 = "";
  local_c = 0;
  local_8 = "\r";
  local_4 = 1;
  CFastString::ReplaceFirst(&CFastString::s_Temp, (SStringParam *)&local_8,
                            (SStringParam *)&local_10, 0, 0xffffffff);
  local_8 = "\r\n";
  local_4 = 2;
  local_10 = "\n";
  local_c = 1;
  CFastString::ReplaceFirst(&CFastString::s_Temp, (SStringParam *)&local_10,
                            (SStringParam *)&local_8, 0, 0xffffffff);
  local_8 = DAT_00d71ca8;
  local_4 = _s_Temp;
  CFastStringInt::SetUtf8(param_1, (SStringParam *)&local_8);
  return *(wchar_t **)(param_1 + 4);
}

/* private: unsigned long __thiscall CClassicI18n::FindMsg(wchar_t const *)const
 */

ulong __thiscall CClassicI18n::FindMsg(CClassicI18n *this, wchar_t *param_1)

{
  wchar_t wVar1;
  ushort uVar2;
  uint uVar3;
  ulong uVar4;
  wchar_t *pwVar5;
  int iVar6;
  SSkinIndex *pSVar7;
  wchar_t *pwVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;

  uVar3 = *(uint *)(this + 0x20);
  uVar4 = CFastAlgo::ComputeHashVal(param_1, (ulong *)0x0);
  uVar9 = uVar4 % uVar3;
  uVar2 = *(ushort *)(*(int *)(this + 0x1c) + uVar9 * 2);
  iVar10 = uVar4 % (uVar3 - 2) + 1;
  do {
    uVar3 = (uint)uVar2;
    if (uVar3 == 0xffff) {
      return 0xffffffff;
    }
    pwVar8 = *(wchar_t **)(*(int *)(this + 8) + uVar3 * 4);
    pwVar5 = param_1;
    do {
      wVar1 = *pwVar5;
      bVar11 = (ushort)wVar1 < (ushort)*pwVar8;
      if (wVar1 != *pwVar8) {
      LAB_00902166:
        iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_0090216b;
      }
      if (wVar1 == L'\0')
        break;
      wVar1 = pwVar5[1];
      bVar11 = (ushort)wVar1 < (ushort)pwVar8[1];
      if (wVar1 != pwVar8[1])
        goto LAB_00902166;
      pwVar5 = pwVar5 + 2;
      pwVar8 = pwVar8 + 2;
    } while (wVar1 != L'\0');
    iVar6 = 0;
  LAB_0090216b:
    if (iVar6 == 0) {
      pSVar7 = CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10), uVar3);
      if (*pSVar7 == (SSkinIndex)0x0) {
        pSVar7 =
            CFastBuffer<>::operator[]((CFastBuffer<> *)(this + 0x10), uVar3);
        *pSVar7 = (SSkinIndex)0x1;
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
      }
      return uVar3;
    }
    iVar6 = iVar10;
    if ((uint)(*(int *)(this + 0x20) - iVar10) <= uVar9) {
      iVar6 = iVar10 - *(int *)(this + 0x20);
    }
    uVar9 = uVar9 + iVar6;
    uVar2 = *(ushort *)(*(int *)(this + 0x1c) + uVar9 * 2);
  } while (true);
}

/* public: static int __cdecl CClassicI18n::GetPrimaryLanguage(char const *,char
 * *) */

int __cdecl CClassicI18n::GetPrimaryLanguage(char *param_1, char *param_2)

{
  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) &&
      (param_1[1] != '\0')) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = '\0';
    return (uint)(param_1[2] != '\0');
  }
  *(undefined2 *)param_2 = 0x7878;
  param_2[2] = '\0';
  return 0;
}

/* public: static wchar_t const * __cdecl
 * CClassicI18n::GetTranslatedString(wchar_t const *) */

wchar_t *__cdecl CClassicI18n::GetTranslatedString(wchar_t *param_1)

{
  wchar_t *pwVar1;

  pwVar1 = GetTranslatedStringInternal(&TheClassicI18n, param_1);
  return pwVar1;
}

/* public: static wchar_t const * __cdecl
   CClassicI18n::GetTranslatedString(class CFastStringInt const &) */

wchar_t *__cdecl CClassicI18n::GetTranslatedString(CFastStringInt *param_1)

{
  wchar_t *pwVar1;

  pwVar1 =
      GetTranslatedStringInternal(&TheClassicI18n, *(wchar_t **)(param_1 + 4));
  return pwVar1;
}

/* private: wchar_t const * __thiscall
 *CClassicI18n::GetTranslatedStringInternal(wchar_t const )const  */

wchar_t *__thiscall CClassicI18n::GetTranslatedStringInternal(
    CClassicI18n *this, wchar_t *param_1)

{
  ulong uVar1;

  if (*param_1 != L'\0') {
    if ((*(int *)(this + 4) != 0) && (*(int *)(this + 0x1c) != 0)) {
      uVar1 = FindMsg(this, param_1);
      if (uVar1 != 0xffffffff) {
        param_1 = *(wchar_t **)(*(int *)(this + 0xc) + uVar1 * 4);
      }
    }
    param_1 = StripContext(param_1);
  }
  return param_1;
}

/* private: void __thiscall CClassicI18n::InsertMsg(wchar_t const *,unsigned
 * long)const  */

void __thiscall CClassicI18n::InsertMsg(CClassicI18n *this, wchar_t *param_1,
                                        ulong param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;

  uVar1 = *(uint *)(this + 0x20);
  uVar4 = CFastAlgo::ComputeHashVal(param_1, (ulong *)0x0);
  uVar6 = uVar4 % uVar1;
  pwVar2 = *(wchar_t **)(this + 0x20);
  param_1 = (wchar_t *)0x0;
  iVar7 = uVar4 % (uVar1 - 2) + 1;
  if (pwVar2 != (wchar_t *)0x0) {
    iVar5 = uVar6 * 2;
    while (*(short *)(iVar5 + *(int *)(this + 0x1c)) != -1) {
      iVar3 = iVar7;
      if ((uint)((int)pwVar2 - iVar7) <= uVar6) {
        iVar5 = iVar5 + (int)pwVar2 * -2;
        iVar3 = iVar7 - (int)pwVar2;
      }
      uVar6 = uVar6 + iVar3;
      param_1 = (wchar_t *)((int)param_1 + 1);
      iVar5 = iVar5 + iVar7 * 2;
      if (pwVar2 <= param_1) {
        return;
      }
    }
    *(undefined2 *)(*(int *)(this + 0x1c) + uVar6 * 2) = (undefined2)param_2;
  }
  return;
}

/* public: static unsigned long __cdecl CClassicI18n::IsLanguageKindOf(char
 * const *,char const *) */

ulong __cdecl CClassicI18n::IsLanguageKindOf(char *param_1, char *param_2)

{
  int iVar1;
  int iVar2;

  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
      (param_1[1] == '\0')) {
    return 0;
  }
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) &&
      (param_2[1] != '\0')) {
    iVar1 = _toupper((int)*param_1);
    iVar2 = _toupper((int)*param_2);
    if (iVar1 == iVar2) {
      iVar1 = _toupper((int)param_1[1]);
      iVar2 = _toupper((int)param_2[1]);
      if (iVar1 == iVar2) {
        if (param_1[2] == '\0') {
          return 2 - (param_2[2] != '\0');
        }
        iVar1 = __stricmp(param_1, param_2);
        return (-(uint)(iVar1 != 0) & 0xfffffffe) + 2;
      }
    }
    return 0;
  }
  return 0;
}

/* public: int __thiscall CClassicI18n::IsLatinCharsInCurCatalog(unsigned
 * long)const  */

int __thiscall CClassicI18n::IsLatinCharsInCurCatalog(CClassicI18n *this,
                                                      ulong param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  SSkinIndex *pSVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  int local_4;

  iVar8 = 0;
  iVar9 = (-(uint)(param_1 != 0) & 0xfffffe0d) + 500;
  local_4 = 0;
  if ((param_1 == 0) || (param_1 <= *(uint *)(this + 0x18))) {
    uVar3 = *(uint *)(this + 4);
    uVar10 = 0;
    if (uVar3 != 0) {
      do {
        if (((param_1 == 0) || (pSVar6 = CFastBuffer<>::operator[](
                                    (CFastBuffer<> *)(this + 0x10), uVar10),
                                iVar8 = local_4, *pSVar6 != (SSkinIndex)0x0)) &&
            (puVar7 = *(ushort **)(*(int *)(this + 0xc) + uVar10 * 4),
             puVar7 != (ushort *)0x0)) {
          uVar2 = *puVar7;
          while (uVar2 != 0) {
            if (0x40 < uVar2) {
              if (uVar2 < 0x251) {
                iVar9 = iVar9 + 1;
              } else {
                iVar8 = iVar8 + 1;
              }
            }
            puVar1 = puVar7 + 1;
            puVar7 = puVar7 + 1;
            local_4 = iVar8;
            uVar2 = *puVar1;
          }
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar3);
    }
    fVar4 = (float)iVar9;
    if (iVar9 < 0) {
      fVar4 = fVar4 + 4.294967e+09;
    }
    fVar5 = (float)(iVar8 + iVar9);
    if (iVar8 + iVar9 < 0) {
      fVar5 = fVar5 + 4.294967e+09;
    }
    if (fVar4 / fVar5 <= 0.4) {
      return 0;
    }
  }
  return 1;
}

/* public: int __thiscall CClassicI18n::LoadMessageCatalog(char const *,class
   CClassicBuffer *,class CFastString &) */

int __thiscall CClassicI18n::LoadMessageCatalog(CClassicI18n *this,
                                                char *param_1,
                                                CClassicBuffer *param_2,
                                                CFastString *param_3)

{
  char cVar1;
  byte bVar2;
  wchar_t wVar3;
  CClassicBuffer *this_00;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  char **ppcVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  char **ppcVar11;
  wchar_t *pwVar12;
  ulong uVar13;
  wchar_t *pwVar14;
  int *piVar15;
  byte *pbVar16;
  CFastString *this_01;
  char *pcVar17;
  char *pcVar18;
  bool bVar19;
  uint uStack_44;
  char *pcStack_40;
  wchar_t *pwStack_3c;
  char *pcStack_38;
  wchar_t *pwStack_34;
  char *local_30;
  undefined4 local_2c;
  int iStack_28;
  int iStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  void *local_c;
  undefined *puStack_8;
  undefined4 uStack_4;

  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0e00;
  local_c = ExceptionList;
  uVar4 = ___security_cookie ^ (uint)&stack0xffffffa4;
  ExceptionList = &local_c;
  Reset(this);
  this_01 = param_3;
  local_30 = "";
  local_2c = 0;
  CFastString::SetString(param_3, (SStringParam *)&local_30);
  this_00 = param_2;
  if (((param_2 != (CClassicBuffer *)0x0) &&
       (uVar4 = (**(code **)(*(int *)param_2 + 0x18))(uVar4), 0x1b < uVar4)) &&
      (iVar5 = CClassicBuffer::ReadAll(this_00, &iStack_28, 0x1c),
       iVar5 != 0)) {
    if (iStack_28 == -0x6afbed22) {
      if (iStack_24 == 0) {
        *(uint *)(this + 4) = uStack_20;
        pvVar6 = operator_new[](
            -(uint)((int)((ulonglong)uStack_20 * 4 >> 0x20) != 0) |
            (uint)((ulonglong)uStack_20 * 4));
        *(void **)(this + 8) = pvVar6;
        pvVar6 = operator_new[](
            -(uint)((int)((ulonglong) * (uint *)(this + 4) * 4 >> 0x20) != 0) |
            (uint)((ulonglong) * (uint *)(this + 4) * 4));
        *(void **)(this + 0xc) = pvVar6;
        pvVar6 = operator_new[](
            -(uint)((int)((ulonglong) * (uint *)(this + 4) * 4 >> 0x20) != 0) |
            (uint)((ulonglong) * (uint *)(this + 4) * 4));
        ppcVar7 = (char **)operator_new[](
            -(uint)((int)((ulonglong) * (uint *)(this + 4) * 4 >> 0x20) != 0) |
            (uint)((ulonglong) * (uint *)(this + 4) * 4));
        CFastArray<char>::SetCount((CFastArray<char> *)(this + 0x10),
                                   *(ulong *)(this + 4));
        param_2 = (CClassicBuffer *)((uint)param_2 & 0xffffff00);
        CFastArray<>::InitValue(
            (CFastArray<> *)(CFastArray<char> *)(this + 0x10),
            (uchar *)&param_2);
        *(undefined4 *)(this + 0x18) = 0;
        iVar5 = (**(code **)(*(int *)this_00 + 0x14))();
        iVar8 = (**(code **)(*(int *)this_00 + 0x18))();
        iVar9 = (**(code **)(*(int *)this_00 + 0x14))();
        pcStack_40 = (char *)(iVar8 - iVar9);
        pcVar10 = (char *)operator_new[]((uint)pcStack_40);
        local_30 = pcVar10;
        iVar8 = CClassicBuffer::ReadAll(this_00, pcVar10, (ulong)pcStack_40);
        if (iVar8 == 0) {
          local_30 = "Invalid mo file";
          local_2c = 0xf;
          this_01 = param_3;
          goto LAB_00902967;
        }
        uStack_44 = 0;
        if (*(int *)(this + 4) != 0) {
          param_2 = (CClassicBuffer *)(pcVar10 + (iStack_18 - iVar5) + 4);
          piVar15 = (int *)(pcVar10 + (iStack_1c - iVar5) + 4);
          pcStack_38 = (char *)((int)pvVar6 - (int)ppcVar7);
          ppcVar11 = ppcVar7;
          do {
            *(char **)(pcStack_38 + (int)ppcVar11) =
                pcVar10 + (*piVar15 - iVar5);
            iVar8 = *(int *)param_2;
            param_2 = param_2 + 8;
            *ppcVar11 = pcVar10 + (iVar8 - iVar5);
            uStack_44 = uStack_44 + 1;
            piVar15 = piVar15 + 2;
            ppcVar11 = ppcVar11 + 1;
          } while (uStack_44 < *(uint *)(this + 4));
        }
        pwVar12 = (wchar_t *)operator_new[](
            -(uint)((int)(ZEXT48(pcStack_40) * 2 >> 0x20) != 0) |
            (uint)(ZEXT48(pcStack_40) * 2));
        uVar4 = 0;
        *(wchar_t **)(this + 0x24) = pwVar12;
        if (*(int *)(this + 4) != 0) {
          do {
            pbVar16 = *(byte **)((int)pvVar6 + uVar4 * 4);
            *(wchar_t **)(*(int *)(this + 8) + uVar4 * 4) = pwVar12;
            do {
              bVar2 = *pbVar16;
              *pwVar12 = (ushort)bVar2;
              pwVar12 = pwVar12 + 1;
              pbVar16 = pbVar16 + 1;
            } while ((ushort)bVar2 != L'\0');
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(this + 4));
        }
        ComputeHashTable(this);
        _strncpy_s((char *)(this + 0x28), 0x20, param_1, 0x1f);
        this[0x47] = (CClassicI18n)0x0;
        uVar13 = FindMsg(this, L"|I18NInternal|Encoding");
        if (uVar13 == 0xffffffff) {
          pcVar10 = "latin1";
        } else {
          pcVar10 = StripContext(ppcVar7[uVar13]);
        }
        iVar5 = 7;
        bVar19 = true;
        pcVar17 = pcVar10;
        pcVar18 = "latin1";
        do {
          if (iVar5 == 0)
            break;
          iVar5 = iVar5 + -1;
          bVar19 = *pcVar17 == *pcVar18;
          pcVar17 = pcVar17 + 1;
          pcVar18 = pcVar18 + 1;
        } while (bVar19);
        if (!bVar19) {
          iVar5 = 9;
          bVar19 = true;
          pcVar17 = "Encoding";
          do {
            if (iVar5 == 0)
              break;
            iVar5 = iVar5 + -1;
            bVar19 = *pcVar10 == *pcVar17;
            pcVar10 = pcVar10 + 1;
            pcVar17 = pcVar17 + 1;
          } while (bVar19);
          if (!bVar19) {
            CFastStringInt::CFastStringInt((CFastStringInt *)&pcStack_38);
            uStack_4 = 1;
            uVar4 = 0;
            if (*(int *)(this + 4) != 0) {
              do {
                SStringParam::SStringParam((SStringParam *)&pcStack_40,
                                           ppcVar7[uVar4]);
                CFastStringInt::SetUtf8((CFastStringInt *)&pcStack_38,
                                        (SStringParam *)&pcStack_40);
                pwVar14 = StripContext(pwStack_34);
                *(wchar_t **)(*(int *)(this + 0xc) + uVar4 * 4) = pwVar12;
                do {
                  wVar3 = *pwVar14;
                  *pwVar12 = wVar3;
                  pwVar12 = pwVar12 + 1;
                  pwVar14 = pwVar14 + 1;
                } while (wVar3 != L'\0');
                uVar4 = uVar4 + 1;
              } while (uVar4 < *(uint *)(this + 4));
            }
            ppcVar11 = &pcStack_38;
            goto LAB_00902905;
          }
        }
        CFastStringInt::CFastStringInt((CFastStringInt *)&pcStack_40);
        uStack_4 = 0;
        uVar4 = 0;
        if (*(int *)(this + 4) != 0) {
          do {
            pcStack_38 = ppcVar7[uVar4];
            if (pcStack_38 == (char *)0x0) {
              pwStack_34 = (wchar_t *)0x0;
            } else {
              pcVar10 = pcStack_38;
              do {
                cVar1 = *pcVar10;
                pcVar10 = pcVar10 + 1;
              } while (cVar1 != '\0');
              pwStack_34 = (wchar_t *)(pcVar10 + -(int)(pcStack_38 + 1));
            }
            CFastStringInt::SetString((CFastStringInt *)&pcStack_40,
                                      (SStringParam *)&pcStack_38);
            pwVar14 = StripContext(pwStack_3c);
            *(wchar_t **)(*(int *)(this + 0xc) + uVar4 * 4) = pwVar12;
            do {
              wVar3 = *pwVar14;
              *pwVar12 = wVar3;
              pwVar12 = pwVar12 + 1;
              pwVar14 = pwVar14 + 1;
            } while (wVar3 != L'\0');
            uVar4 = uVar4 + 1;
          } while (uVar4 < *(uint *)(this + 4));
        }
        ppcVar11 = &pcStack_40;
      LAB_00902905:
        uStack_4 = 0xffffffff;
        CGameCtnApp::SNationConfig::~SNationConfig((SNationConfig *)ppcVar11);
        operator_delete[](local_30);
        operator_delete[](pvVar6);
        operator_delete[](ppcVar7);
        local_30 = "";
        local_2c = 0;
        CFastString::SetString(param_3, (SStringParam *)&local_30);
        ExceptionList = local_c;
        return 1;
      }
      local_30 = "Invalid mo file: only version 0, revision 0 supported!";
      local_2c = 0x36;
      goto LAB_00902967;
    }
    if (iStack_28 == -0x21edfb6b) {
      local_30 = "Invalid mo file:  file byte order not supported";
      local_2c = 0x2f;
      goto LAB_00902967;
    }
  }
  local_2c = 0xf;
  local_30 = "Invalid mo file";
LAB_00902967:
  CFastString::SetString(this_01, (SStringParam *)&local_30);
  ExceptionList = local_c;
  return 0;
}

/* public: void __thiscall CClassicI18n::Reset(void) */

void __thiscall CClassicI18n::Reset(CClassicI18n *this)

{
  *(undefined4 *)(this + 4) = 0;
  operator_delete[](*(void **)(this + 8));
  *(undefined4 *)(this + 8) = 0;
  operator_delete[](*(void **)(this + 0xc));
  *(undefined4 *)(this + 0xc) = 0;
  operator_delete[](*(void **)(this + 0x24));
  *(undefined4 *)(this + 0x24) = 0;
  operator_delete[](*(void **)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  CFastArray<char>::SetCount((CFastArray<char> *)(this + 0x10), 0);
  *(undefined4 *)(this + 0x18) = 0;
  _strcpy_s((char *)(this + 0x28), 0x20, "xx");
  return;
}

/* public: static wchar_t const * __cdecl CClassicI18n::StripContext(wchar_t
 * const *) */

wchar_t *__cdecl CClassicI18n::StripContext(wchar_t *param_1)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;

  pwVar1 = param_1;
  if (*param_1 == L'|') {
    do {
      pwVar2 = pwVar1;
      if (pwVar2[1] == L'|')
        goto LAB_00901e98;
      pwVar1 = pwVar2 + 1;
    } while (pwVar2[1] != L'\0');
    if (pwVar2[1] == L'|') {
    LAB_00901e98:
      return pwVar2 + 2;
    }
  }
  return param_1;
}

/* public: static char const * __cdecl CClassicI18n::StripContext(char const *)
 */

char *__cdecl CClassicI18n::StripContext(char *param_1)

{
  char *pcVar1;
  char *pcVar2;

  pcVar2 = param_1;
  if (*param_1 == '|') {
    do {
      pcVar1 = pcVar2 + 1;
      param_1 = pcVar2 + 1;
      if (*pcVar1 == '|') {
        return pcVar2 + 2;
      }
      pcVar2 = param_1;
    } while (*pcVar1 != '\0');
  }
  return param_1;
}

/* public: virtual __thiscall CClassicI18n::~CClassicI18n(void) */

void __thiscall CClassicI18n::~CClassicI18n(CClassicI18n *this)

{
  void *local_c;
  undefined *puStack_8;
  undefined4 local_4;

  puStack_8 = &LAB_00ae0dcb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 0;
  Reset(this);
  local_4 = 0xffffffff;
  CFastArray<>::~CFastArray<>((CFastArray<> *)(this + 0x10));
  ExceptionList = local_c;
  return;
}
