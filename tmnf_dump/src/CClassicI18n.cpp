// Class implementation: CClassicI18n

// =================================================
// Function: CClassicI18n::ComputeHashTable
// =================================================
void __thiscall CClassicI18n::ComputeHashTable(CClassicI18n *this,CClassicI18n *param_1)
{
{
  ulong uVar1;
  void *pvVar2;
  ulong unaff_EDI;
  wchar_t *pwVar3;
  
  operator_delete__(*(void **)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0;
  if (((*(ulong *)(this + 4) != 0) && (*(int *)(this + 8) != 0)) && (*(int *)(this + 0xc) != 0)) {
    uVar1 = CFastAlgo::ComputeHashSize(*(ulong *)(this + 4));
    *(ulong *)(this + 0x20) = uVar1;
    pvVar2 = operator_new__(-(uint)((int)((ulonglong)uVar1 * 2 >> 0x20) != 0) |
                            (uint)((ulonglong)uVar1 * 2));
    *(void **)(this + 0x1c) = pvVar2;
    _memset(pvVar2,-1,*(int *)(this + 0x20) * 2);
    if (*(int *)(this + 4) != 0) {
      pwVar3 = (wchar_t *)0x0;
      do {
        InsertMsg(this,*(CClassicI18n **)(*(int *)(this + 8) + (int)pwVar3 * 4),pwVar3,unaff_EDI);
        pwVar3 = (wchar_t *)((int)pwVar3 + 1);
      } while (pwVar3 < *(wchar_t **)(this + 4));
    }
  }
  return;
}
}

// =================================================
// Function: CClassicI18n::ConvertStringForWin32
// =================================================
wchar_t * __cdecl CClassicI18n::ConvertStringForWin32(CFastStringInt *param_1)
{
{
  CFastStringInt *this;
  int unaff_ESI;
  undefined4 uStack00000008;
  ulong in_stack_fffffff0;
  undefined1 *puVar1;
  SStringParam *pSVar2;
  undefined *local_4;
  
  this = param_1;
  CFastStringInt::GetUtf8(param_1,(CFastStringInt *)&DAT_00d71ca4,(CFastString *)0x0,unaff_ESI);
  puVar1 = &DAT_00b2c878;
  local_4 = &DAT_00b32c30;
  CFastString::ReplaceFirst
            ((CFastString *)&DAT_00d71ca4,(CFastString *)&local_4,(SStringParam *)&stack0xfffffff4,
             (SStringParam *)0x0,0xffffffff,in_stack_fffffff0);
  param_1 = (CFastStringInt *)0x2;
  pSVar2 = (SStringParam *)&DAT_00b32c2c;
  local_4 = (undefined *)0x1;
  CFastString::ReplaceFirst
            ((CFastString *)&DAT_00d71ca4,(CFastString *)&stack0xfffffff8,
             (SStringParam *)&stack0x00000000,(SStringParam *)0x0,0xffffffff,(ulong)puVar1);
  param_1 = DAT_00d71ca8;
  uStack00000008 = DAT_00d71ca4;
  CFastStringInt::SetUtf8(this,(CFastStringInt *)&param_1,pSVar2);
  return *(wchar_t **)(this + 4);
}
}

// =================================================
// Function: CClassicI18n::FindMsg
// =================================================
ulong __thiscall CClassicI18n::FindMsg(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2)
{
{
  ushort uVar1;
  uint uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong uVar4;
  CClassicI18n *pCVar5;
  int iVar6;
  SCasterCat *pSVar7;
  ushort *puVar8;
  uint uVar9;
  int iVar10;
  ulong unaff_ESI;
  ulong unaff_EDI;
  bool bVar11;
  
  uVar2 = *(uint *)(this + 0x20);
  uVar4 = CFastAlgo::ComputeHashVal((char *)param_1,(ulong *)0x0);
  uVar9 = uVar4 % uVar2;
  uVar1 = *(ushort *)(*(int *)(this + 0x1c) + uVar9 * 2);
  iVar10 = uVar4 % (uVar2 - 2) + 1;
  do {
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uint)uVar1;
    if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffff) {
      return 0xffffffff;
    }
    puVar8 = *(ushort **)(*(int *)(this + 8) + (int)pCVar3 * 4);
    pCVar5 = param_1;
    do {
      uVar1 = *(ushort *)pCVar5;
      bVar11 = uVar1 < *puVar8;
      if (uVar1 != *puVar8) {
LAB_00902166:
        iVar6 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
        goto LAB_0090216b;
      }
      if (uVar1 == 0) break;
      uVar1 = *(ushort *)(pCVar5 + 2);
      bVar11 = uVar1 < puVar8[1];
      if (uVar1 != puVar8[1]) goto LAB_00902166;
      pCVar5 = pCVar5 + 4;
      puVar8 = puVar8 + 2;
    } while (uVar1 != 0);
    iVar6 = 0;
LAB_0090216b:
    if (iVar6 == 0) {
      pSVar7 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[](this + 0x10,pCVar3,unaff_EDI)
      ;
      if (*pSVar7 == (SCasterCat)0x0) {
        pSVar7 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                           (this + 0x10,pCVar3,unaff_ESI);
        *pSVar7 = (SCasterCat)0x1;
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + 1;
      }
      return (ulong)pCVar3;
    }
    iVar6 = iVar10;
    if ((uint)(*(int *)(this + 0x20) - iVar10) <= uVar9) {
      iVar6 = iVar10 - *(int *)(this + 0x20);
    }
    uVar9 = uVar9 + iVar6;
    uVar1 = *(ushort *)(*(int *)(this + 0x1c) + uVar9 * 2);
  } while( true );
}
}

// =================================================
// Function: CClassicI18n::GetPrimaryLanguage
// =================================================
int __cdecl CClassicI18n::GetPrimaryLanguage(char *param_1,char *param_2)
{
{
  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) && (param_1[1] != '\0')) {
    *param_2 = *param_1;
    param_2[1] = param_1[1];
    param_2[2] = '\0';
    return (uint)(param_1[2] != '\0');
  }
  *(undefined2 *)param_2 = DAT_00b2ee60;
  param_2[2] = DAT_00b2ee62;
  return 0;
}
}

// =================================================
// Function: CClassicI18n::GetTranslatedString
// =================================================
wchar_t * __cdecl CClassicI18n::GetTranslatedString(CFastStringInt *param_1)
{
{
  wchar_t *pwVar1;
  wchar_t *unaff_retaddr;
  
  pwVar1 = GetTranslatedStringInternal
                     ((CClassicI18n *)&DAT_00d71d10,*(CClassicI18n **)(param_1 + 4),unaff_retaddr);
  return pwVar1;
}
}

// =================================================
// Function: CClassicI18n::GetTranslatedStringInternal
// =================================================
wchar_t * __thiscall
CClassicI18n::GetTranslatedStringInternal(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2)
{
{
  ulong uVar1;
  wchar_t *unaff_EDI;
  
  if (*(short *)param_1 != 0) {
    if ((*(int *)(this + 4) != 0) && (*(int *)(this + 0x1c) != 0)) {
      uVar1 = FindMsg(this,param_1,unaff_EDI);
      if (uVar1 != 0xffffffff) {
        param_1 = *(CClassicI18n **)(*(int *)(this + 0xc) + uVar1 * 4);
      }
    }
    param_1 = (CClassicI18n *)StripContext((char *)param_1);
  }
  return (wchar_t *)param_1;
}
}

// =================================================
// Function: CClassicI18n::InsertMsg
// =================================================
void __thiscall
CClassicI18n::InsertMsg(CClassicI18n *this,CClassicI18n *param_1,wchar_t *param_2,ulong param_3)
{
{
  uint uVar1;
  CClassicI18n *pCVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = *(uint *)(this + 0x20);
  uVar4 = CFastAlgo::ComputeHashVal((char *)param_1,(ulong *)0x0);
  uVar6 = uVar4 % uVar1;
  pCVar2 = *(CClassicI18n **)(this + 0x20);
  param_1 = (CClassicI18n *)0x0;
  iVar7 = uVar4 % (uVar1 - 2) + 1;
  if (pCVar2 != (CClassicI18n *)0x0) {
    iVar5 = uVar6 * 2;
    while (*(short *)(iVar5 + *(int *)(this + 0x1c)) != -1) {
      iVar3 = iVar7;
      if ((uint)((int)pCVar2 - iVar7) <= uVar6) {
        iVar5 = iVar5 + (int)pCVar2 * -2;
        iVar3 = iVar7 - (int)pCVar2;
      }
      uVar6 = uVar6 + iVar3;
      param_1 = param_1 + 1;
      iVar5 = iVar5 + iVar7 * 2;
      if (pCVar2 <= param_1) {
        return;
      }
    }
    *(undefined2 *)(*(int *)(this + 0x1c) + uVar6 * 2) = param_2._0_2_;
  }
  return;
}
}

// =================================================
// Function: CClassicI18n::IsLanguageKindOf
// =================================================
ulong __cdecl CClassicI18n::IsLanguageKindOf(char *param_1,char *param_2)
{
{
  int iVar1;
  int iVar2;
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) || (param_1[1] == '\0')) {
    return 0;
  }
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (param_2[1] != '\0')) {
    iVar1 = _toupper((int)*param_1);
    iVar2 = _toupper((int)*param_2);
    if (iVar1 == iVar2) {
      iVar1 = _toupper((int)param_1[1]);
      iVar2 = _toupper((int)param_2[1]);
      if (iVar1 == iVar2) {
        if (param_1[2] == '\0') {
          return 2 - (param_2[2] != '\0');
        }
        iVar1 = __stricmp(param_1,param_2);
        return (-(uint)(iVar1 != 0) & 0xfffffffe) + 2;
      }
    }
    return 0;
  }
  return 0;
}
}

// =================================================
// Function: CClassicI18n::IsLatinCharsInCurCatalog
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CClassicI18n::IsLatinCharsInCurCatalog(CClassicI18n *this,CClassicI18n *param_1,ulong param_2)
{
{
  ushort *puVar1;
  ushort uVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  float fVar4;
  float fVar5;
  SCasterCat *pSVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  ulong unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  int unaff_retaddr;
  
  iVar8 = 0;
  iVar9 = (-(uint)(param_1 != (CClassicI18n *)0x0) & 0xfffffe0d) + 500;
  if ((param_1 == (CClassicI18n *)0x0) || (param_1 <= *(CClassicI18n **)(this + 0x18))) {
    pCVar3 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 4);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        if (((param_1 == (CClassicI18n *)0x0) ||
            (pSVar6 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                                (this + 0x10,pCVar10,unaff_EDI), iVar8 = unaff_retaddr,
            *pSVar6 != (SCasterCat)0x0)) &&
           (puVar7 = *(ushort **)(*(int *)(this + 0xc) + (int)pCVar10 * 4), puVar7 != (ushort *)0x0)
           ) {
          uVar2 = *puVar7;
          while (uVar2 != 0) {
            if (0x40 < uVar2) {
              if (uVar2 < 0x251) {
                iVar9 = iVar9 + 1;
              }
              else {
                iVar8 = iVar8 + 1;
              }
            }
            puVar1 = puVar7 + 1;
            puVar7 = puVar7 + 1;
            uVar2 = *puVar1;
          }
        }
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar3);
    }
    fVar4 = (float)iVar9;
    if (iVar9 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    fVar5 = (float)(iVar8 + iVar9);
    if (iVar8 + iVar9 < 0) {
      fVar5 = fVar5 + _DAT_00c418d0;
    }
    if (fVar4 / fVar5 <= (float)_DAT_00b4fbd0) {
      return 0;
    }
  }
  return 1;
}
}

// =================================================
// Function: CClassicI18n::LoadMessageCatalog
// =================================================
int __thiscall
CClassicI18n::LoadMessageCatalog
          (CClassicI18n *this,CClassicI18n *param_1,char *param_2,CClassicBuffer *param_3,
          CFastString *param_4)
{
{
  byte bVar1;
  SStringParam SVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  CClassicBuffer *pCVar9;
  int *piVar10;
  ushort *puVar11;
  char *pcVar12;
  ushort *puVar13;
  CClassicBuffer *pCVar14;
  byte *pbVar15;
  SStringParam **this_00;
  CSystemFidFile **unaff_EBX;
  ulong unaff_EBP;
  SStringParam *unaff_ESI;
  char *pcVar16;
  SStringParam *unaff_EDI;
  char *pcVar17;
  bool bVar18;
  void *unaff_retaddr;
  CFastString *in_stack_00000014;
  CFastArray<class_CSystemFidFile*> in_stack_00000018;
  CClassicI18n *pCVar19;
  SStringParam *pSVar20;
  CFastStringInt *pCVar21;
  ulong uVar22;
  SNationConfig *pSVar23;
  wchar_t *pwVar24;
  CFastArray<class_CSystemFidFile*> *pCVar25;
  SStringParam *in_stack_ffffffb4;
  int *piStack_44;
  void *pvStack_40;
  SStringParam *pSStack_3c;
  SStringParam *pSStack_38;
  SStringParam *pSStack_34;
  SStringParam *pSStack_30;
  CClassicBuffer *local_2c;
  char *local_28;
  char *local_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  uint uStack_14;
  int iStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0e00;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  Reset(this,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffa4));
  local_2c = (CClassicBuffer *)&DAT_00b2c878;
  local_28 = (char *)0x0;
  CFastString::SetString(param_4,(CFastStringInt *)&local_2c,unaff_EDI);
  if ((param_4 == (CFastString *)0x0) ||
     (uVar4 = (**(code **)(*(int *)param_4 + 0x18))(), uVar4 < 0x1c)) {
    pCVar21 = (CFastStringInt *)&local_28;
  }
  else {
    pCVar21 = (CFastStringInt *)0x1c;
    iVar5 = CClassicBuffer::ReadAll
                      ((CClassicBuffer *)param_4,(CClassicBuffer *)&uStack_20,(void *)0x1c,
                       (ulong)unaff_ESI);
    if (iVar5 == 0) {
      unaff_ESI = (SStringParam *)&local_24;
    }
    else {
      if (iStack_1c == -0x6afbed22) {
        if (iStack_18 == 0) {
          *(uint *)(this + 4) = uStack_14;
          pvVar6 = operator_new__(-(uint)((int)((ulonglong)uStack_14 * 4 >> 0x20) != 0) |
                                  (uint)((ulonglong)uStack_14 * 4));
          *(void **)(this + 8) = pvVar6;
          pvVar6 = operator_new__(-(uint)((int)((ulonglong)*(uint *)(this + 4) * 4 >> 0x20) != 0) |
                                  (uint)((ulonglong)*(uint *)(this + 4) * 4));
          *(void **)(this + 0xc) = pvVar6;
          pSStack_3c = operator_new__(-(uint)((int)((ulonglong)*(uint *)(this + 4) * 4 >> 0x20) != 0
                                             ) | (uint)((ulonglong)*(uint *)(this + 4) * 4));
          pvStack_40 = operator_new__(-(uint)((int)((ulonglong)*(uint *)(this + 4) * 4 >> 0x20) != 0
                                             ) | (uint)((ulonglong)*(uint *)(this + 4) * 4));
          uVar22 = 0x902663;
          CFastArray<char>::SetCount
                    ((CFastArray<char> *)(this + 0x10),
                     *(CFastBuffer<class_CSystemFidsFolder*> **)(this + 4),unaff_EBP);
          pCVar25 = &stack0x00000018;
          in_stack_00000018 = (CFastArray<class_CSystemFidFile*>)0x0;
          unaff_ESI = (SStringParam *)0x902673;
          CFastArray<unsigned_char>::InitValue((CFastArray<char> *)(this + 0x10),pCVar25,unaff_EBX);
          *(undefined4 *)(this + 0x18) = 0;
          iVar5 = (**(code **)(*(int *)param_4 + 0x14))();
          iVar7 = (**(code **)(*(int *)param_4 + 0x18))();
          pCVar21 = (CFastStringInt *)0x902695;
          iVar8 = (**(code **)(*(int *)param_4 + 0x14))();
          pSStack_3c = (SStringParam *)(iVar7 - iVar8);
          pCVar9 = operator_new__((uint)pSStack_3c);
          local_2c = pCVar9;
          iVar7 = CClassicBuffer::ReadAll((CClassicBuffer *)param_4,pCVar9,pSStack_3c,uVar22);
          if (iVar7 == 0) {
            pCVar21 = (CFastStringInt *)&local_28;
            local_28 = "Invalid mo file";
            local_24 = (char *)0xf;
            goto LAB_00902967;
          }
          pSStack_3c = (SStringParam *)0x0;
          if (*(int *)(this + 4) != 0) {
            param_4 = (CFastString *)(pCVar9 + (iStack_10 - iVar5) + 4);
            pCVar14 = pCVar9 + (uStack_14 - iVar5) + 4;
            pSStack_30 = (SStringParam *)((int)pvStack_40 - (int)piStack_44);
            piVar10 = piStack_44;
            do {
              *(CClassicBuffer **)(pSStack_30 + (int)piVar10) = pCVar9 + (*(int *)pCVar14 - iVar5);
              iVar7 = *(int *)param_4;
              param_4 = param_4 + 8;
              *piVar10 = (int)(pCVar9 + (iVar7 - iVar5));
              pSStack_3c = pSStack_3c + 1;
              pCVar14 = pCVar14 + 8;
              piVar10 = piVar10 + 1;
            } while (pSStack_3c < *(SStringParam **)(this + 4));
          }
          puVar11 = operator_new__(-(uint)((int)(ZEXT48(pSStack_38) * 2 >> 0x20) != 0) |
                                   (uint)(ZEXT48(pSStack_38) * 2));
          uVar4 = 0;
          *(ushort **)(this + 0x24) = puVar11;
          if (*(int *)(this + 4) != 0) {
            do {
              pbVar15 = *(byte **)((int)pvStack_40 + uVar4 * 4);
              *(ushort **)(*(int *)(this + 8) + uVar4 * 4) = puVar11;
              do {
                bVar1 = *pbVar15;
                *puVar11 = (ushort)bVar1;
                puVar11 = puVar11 + 1;
                pbVar15 = pbVar15 + 1;
              } while (bVar1 != 0);
              uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint *)(this + 4));
          }
          ComputeHashTable(this,(CClassicI18n *)unaff_ESI);
          pCVar19 = this + 0x28;
          pSVar20 = (SStringParam *)&DAT_00000020;
          _strncpy_s((char *)pCVar19,0x20,(char *)param_4,0x1f);
          pwVar24 = L"|I18NInternal|Encoding";
          this[0x47] = (CClassicI18n)0x0;
          pSVar23 = (SNationConfig *)0x9027c6;
          uVar22 = FindMsg(this,(CClassicI18n *)L"|I18NInternal|Encoding",(wchar_t *)pCVar25);
          if (uVar22 == 0xffffffff) {
            pcVar12 = "latin1";
          }
          else {
            pwVar24 = L"쒃\xeb04렅\xf728»⢿믷謀맰\a";
            pcVar12 = StripContext(*(char **)(pSStack_3c + uVar22 * 4));
          }
          iVar5 = 7;
          bVar18 = true;
          pcVar16 = pcVar12;
          pcVar17 = "latin1";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar18 = *pcVar16 == *pcVar17;
            pcVar16 = pcVar16 + 1;
            pcVar17 = pcVar17 + 1;
          } while (bVar18);
          if (!bVar18) {
            iVar5 = 9;
            bVar18 = true;
            pcVar16 = "Encoding";
            do {
              if (iVar5 == 0) break;
              iVar5 = iVar5 + -1;
              bVar18 = *pcVar12 == *pcVar16;
              pcVar12 = pcVar12 + 1;
              pcVar16 = pcVar16 + 1;
            } while (bVar18);
            if (!bVar18) {
              CFastStringInt::CFastStringInt(&local_28,pCVar21,in_stack_ffffffb4);
              in_stack_00000014 = (CFastString *)0x1;
              uVar4 = 0;
              if (*(int *)(this + 4) != 0) {
                do {
                  SStringParam::SStringParam
                            (&piStack_44,*(SStringParam **)(pCVar21 + uVar4 * 4),(char *)pCVar19);
                  CFastStringInt::SetUtf8(&pSStack_38,(CFastStringInt *)&pvStack_40,pSVar20);
                  pCVar19 = (CClassicI18n *)0x90284b;
                  pSVar20 = pSStack_30;
                  puVar13 = (ushort *)StripContext((char *)pSStack_30);
                  *(ushort **)(*(int *)(this + 0xc) + uVar4 * 4) = puVar11;
                  do {
                    uVar3 = *puVar13;
                    *puVar11 = uVar3;
                    puVar11 = puVar11 + 1;
                    puVar13 = puVar13 + 1;
                  } while (uVar3 != 0);
                  uVar4 = uVar4 + 1;
                } while (uVar4 < *(uint *)(this + 4));
              }
              this_00 = &pSStack_34;
              goto LAB_00902905;
            }
          }
          CFastStringInt::CFastStringInt(&pSStack_30,pCVar21,in_stack_ffffffb4);
          in_stack_00000014 = (CFastString *)0x0;
          uVar4 = 0;
          if (*(int *)(this + 4) != 0) {
            do {
              pSStack_38 = *(SStringParam **)(in_stack_ffffffb4 + uVar4 * 4);
              if (pSStack_38 == (SStringParam *)0x0) {
                pSStack_34 = (SStringParam *)0x0;
              }
              else {
                pSStack_34 = pSStack_38;
                do {
                  SVar2 = *pSStack_34;
                  pSStack_34 = pSStack_34 + 1;
                } while (SVar2 != (SStringParam)0x0);
                pSStack_34 = pSStack_34 + -(int)(pSStack_38 + 1);
              }
              CFastStringInt::SetString(&pvStack_40,(CFastStringInt *)&pSStack_38,pSVar20);
              pSVar20 = pSStack_38;
              puVar13 = (ushort *)StripContext((char *)pSStack_38);
              *(ushort **)(*(int *)(this + 0xc) + uVar4 * 4) = puVar11;
              do {
                uVar3 = *puVar13;
                *puVar11 = uVar3;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              } while (uVar3 != 0);
              uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint *)(this + 4));
          }
          this_00 = &pSStack_3c;
LAB_00902905:
          CGameCtnApp::SNationConfig::~SNationConfig(this_00,pSVar23);
          operator_delete__(local_28);
          operator_delete__(pvStack_40);
          operator_delete__(piStack_44);
          local_28 = "";
          local_24 = (char *)0x0;
          CFastString::SetString
                    (in_stack_00000014,(CFastStringInt *)&local_28,(SStringParam *)pwVar24);
          ExceptionList = (void *)0xffffffff;
          return 1;
        }
        unaff_ESI = (SStringParam *)&local_24;
        local_24 = "Invalid mo file: only version 0, revision 0 supported!";
        uStack_20 = 0x36;
        in_stack_00000014 = param_4;
        goto LAB_00902967;
      }
      if (iStack_1c == -0x21edfb6b) {
        unaff_ESI = (SStringParam *)&local_24;
        local_24 = "Invalid mo file:  file byte order not supported";
        uStack_20 = 0x2f;
        in_stack_00000014 = param_4;
        goto LAB_00902967;
      }
      unaff_ESI = (SStringParam *)&local_24;
    }
  }
  local_24 = (char *)0xf;
  local_28 = "Invalid mo file";
  in_stack_00000014 = param_4;
LAB_00902967:
  CFastString::SetString(in_stack_00000014,pCVar21,unaff_ESI);
  ExceptionList = unaff_retaddr;
  return 0;
}
}

// =================================================
// Function: CClassicI18n::Reset
// =================================================
void __thiscall CClassicI18n::Reset(CClassicI18n *this,GmFrustumIso4 *param_1)
{
{
  ulong unaff_EDI;
  
  *(undefined4 *)(this + 4) = 0;
  operator_delete__(*(void **)(this + 8));
  *(undefined4 *)(this + 8) = 0;
  operator_delete__(*(void **)(this + 0xc));
  *(undefined4 *)(this + 0xc) = 0;
  operator_delete__(*(void **)(this + 0x24));
  *(undefined4 *)(this + 0x24) = 0;
  operator_delete__(*(void **)(this + 0x1c));
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  CFastArray<char>::SetCount
            ((CFastArray<char> *)(this + 0x10),(CFastBuffer<class_CSystemFidsFolder*> *)0x0,
             unaff_EDI);
  *(undefined4 *)(this + 0x18) = 0;
  _strcpy_s((char *)(this + 0x28),0x20,"xx");
  return;
}
}

// =================================================
// Function: CClassicI18n::StripContext
// =================================================
char * __cdecl CClassicI18n::StripContext(char *param_1)
{
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
}

