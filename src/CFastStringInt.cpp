// Class implementation: CFastStringInt

// =================================================
// Function: CFastStringInt::CFastStringInt
// =================================================
void __thiscall
CFastStringInt::CFastStringInt(void *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  *(undefined4 *)this = 0;
  *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  return;
}
}

// =================================================
// Function: CFastStringInt::Compare
// =================================================
void __thiscall
CFastStringInt::Compare(void *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4)
{
{
  SStringParam *unaff_ESI;
  int *in_stack_fffffff4;
  
  SetString(&DAT_00d71d70,(CFastStringInt *)param_1,unaff_ESI);
  Compare(this,(SParam_Fids *)&stack0xfffffff8,(SParam *)param_3,in_stack_fffffff4,DAT_00d71d74);
  return;
}
}

// =================================================
// Function: CFastStringInt::CompareNoCase
// =================================================
int __thiscall
CFastStringInt::CompareNoCase
          (void *this,CFastStringInt *param_1,SStringParam *param_2,ulong param_3)
{
{
  int iVar1;
  SStringParam *unaff_ESI;
  ulong in_stack_fffffff4;
  undefined4 local_8;
  undefined4 local_4;
  
  SetString(&DAT_00d71d70,param_1,unaff_ESI);
  local_8 = DAT_00d71d74;
  local_4 = DAT_00d71d70;
  iVar1 = CompareNoCase(this,(CFastStringInt *)&local_8,(SStringParam *)param_3,in_stack_fffffff4);
  return iVar1;
}
}

// =================================================
// Function: CFastStringInt::Concat
// =================================================
void __thiscall CFastStringInt::Concat(void *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  wchar_t *pwVar2;
  int iVar3;
  ulong unaff_EBP;
  SOldChars *unaff_ESI;
  SOldChars *unaff_EDI;
  CFastStringBase<wchar_t> *pCVar4;
  
  pwVar2 = *(wchar_t **)(param_1 + 4);
  pCVar4 = *(CFastStringBase<wchar_t> **)this;
  pCVar1 = pCVar4 + (int)pwVar2;
  if (pCVar1 != pCVar4) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar1,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar1 * 2) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar1;
  }
  iVar3 = CheckedStrCpy<unsigned_char>(pwVar2,(uchar *)unaff_ESI,unaff_EBP);
  pCVar4 = pCVar4 + iVar3;
  if (pCVar4 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar4,1,0,unaff_ESI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar4 * 2) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar4;
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::ConcatBefore
// =================================================
void __thiscall
CFastStringInt::ConcatBefore(void *this,CFastStringInt *param_1,SStringParamInt *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t *pwVar4;
  ulong unaff_ESI;
  SOldChars *unaff_EDI;
  undefined4 local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ae0e28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pwVar2 = *(wchar_t **)(param_1 + 4);
  iVar3 = *(int *)this;
  if (pwVar2 != (wchar_t *)0x0) {
    local_14 = 0;
    local_10 = (void *)0x0;
    local_4 = (void *)0x0;
    pCVar1 = (CFastStringBase<wchar_t> *)((int)pwVar2 + iVar3);
    if (pCVar1 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<wchar_t>::AllocAtLeast
                (this,pCVar1,0,(int)&local_14,(SOldChars *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
      *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar1 * 2) = 0;
      *(CFastStringBase<wchar_t> **)this = pCVar1;
    }
    if (iVar3 != 0) {
      _memmove((void *)(*(int *)((int)this + 4) + (int)pwVar2 * 2),local_10,iVar3 * 2);
    }
    pwVar4 = (wchar_t *)CheckedStrCpy<wchar_t>(pwVar2,(wchar_t *)unaff_EDI,unaff_ESI);
    if (pwVar4 != pwVar2) {
      _memmove((void *)(*(int *)((int)this + 4) + (int)pwVar4 * 2),
               (void *)(*(int *)((int)this + 4) + (int)pwVar2 * 2),iVar3 * 2);
    }
    pCVar1 = (CFastStringBase<wchar_t> *)(iVar3 + (int)pwVar4);
    if (pCVar1 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar1,1,0,unaff_EDI);
      *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar1 * 2) = 0;
      *(CFastStringBase<wchar_t> **)this = pCVar1;
    }
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&local_10,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EDI);
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CFastStringInt::ConcatFormat
// =================================================
void __thiscall CFastStringInt::ConcatFormat(void *this,CFastStringInt *param_1,char *param_2)
{
{
  char *in_stack_fffffff8;
  
  CFastString::InternalVFormat
            ((CFastString *)&DAT_00d71d68,(CFastString *)param_2,&stack0x0000000c,in_stack_fffffff8)
  ;
  Concat(param_2,(CFastStringInt *)&stack0xfffffffc,DAT_00d71d6c);
  return;
}
}

// =================================================
// Function: CFastStringInt::FilterTo7bit
// =================================================
int __cdecl CFastStringInt::FilterTo7bit(CFastString *param_1,SStringParam *param_2,char param_3)
{
{
  char *pcVar1;
  int iVar2;
  SStringParam *unaff_ESI;
  SStringParam *in_stack_00000010;
  SStringParam *in_stack_fffffff4;
  undefined4 local_8;
  undefined4 local_4;
  
  pcVar1 = *(char **)param_2;
  if ((((pcVar1 != (char *)0x0) && (*pcVar1 == -0x11)) && (pcVar1[1] == -0x45)) &&
     (pcVar1[2] == -0x41)) {
    SetUtf8(&DAT_00d71d70,(CFastStringInt *)param_2,in_stack_fffffff4);
    local_8 = DAT_00d71d74;
    local_4 = DAT_00d71d70;
    iVar2 = FilterTo7bit((CFastString *)param_2,(SStringParam *)&local_8,(char)in_stack_00000010);
    return iVar2;
  }
  CFastString::SetString(param_1,(CFastStringInt *)param_2,unaff_ESI);
  iVar2 = FilterTo7bit(param_1,in_stack_00000010,(char)in_stack_fffffff4);
  return iVar2;
}
}

// =================================================
// Function: CFastStringInt::FindFirst
// =================================================
ulong __thiscall
CFastStringInt::FindFirst(void *this,CFastStringInt *param_1,ulong param_2,ulong param_3)
{
{
  while( true ) {
    if (*(uint *)this <= param_2) {
      return 0xffffffff;
    }
    if ((CFastStringInt *)(uint)*(ushort *)(*(int *)((int)this + 4) + param_2 * 2) == param_1)
    break;
    param_2 = param_2 + 1;
  }
  return param_2;
}
}

// =================================================
// Function: CFastStringInt::FindLast
// =================================================
ulong __thiscall
CFastStringInt::FindLast(void *this,CFastStringInt *param_1,ulong param_2,ulong param_3)
{
{
  if (*(uint *)this <= param_2) {
    param_2 = *(uint *)this - 1;
  }
  while( true ) {
    if ((int)param_2 < 0) {
      return 0xffffffff;
    }
    if ((CFastStringInt *)(uint)*(ushort *)(*(int *)((int)this + 4) + param_2 * 2) == param_1)
    break;
    param_2 = param_2 - 1;
  }
  return param_2;
}
}

// =================================================
// Function: CFastStringInt::GetAscii
// =================================================
void __thiscall CFastStringInt::GetAscii(void *this,CFastStringInt *param_1,CFastString *param_2)
{
{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)((int)this + 4);
  local_8 = *(undefined4 *)this;
  local_4 = 0;
  FilterTo7bit((CFastString *)param_1,(SStringParam *)&local_c,'_');
  return;
}
}

// =================================================
// Function: CFastStringInt::GetEscaped
// =================================================
void __thiscall CFastStringInt::GetEscaped(void *this,CFastStringInt *param_1,CFastString *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  byte bVar2;
  CFastStringInt *unaff_EBX;
  SOldChars *unaff_ESI;
  uint uVar3;
  int unaff_EDI;
  char in_stack_00000014;
  CFastStringInt *pCVar4;
  
  GetUtf8(this,(CFastStringInt *)&DAT_00d71d68,(CFastString *)0x0,unaff_EDI);
  pCVar1 = (CFastStringBase<wchar_t> *)(DAT_00d71d68 * 2);
  if (pCVar1 != *(CFastStringBase<wchar_t> **)param_2) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)param_2,pCVar1,1,0,unaff_ESI);
    pCVar1[*(int *)(param_2 + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)param_2 = pCVar1;
  }
  if (*(int *)param_2 != 0) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)param_2,(CFastStringBase<wchar_t> *)0x0,1,0,this);
    **(undefined1 **)(param_2 + 4) = 0;
    *(undefined4 *)param_2 = 0;
  }
  uVar3 = 0;
  if (DAT_00d71d68 != 0) {
    do {
      bVar2 = *(byte *)(DAT_00d71d6c + uVar3);
      param_1 = (CFastStringInt *)CONCAT31(param_1._1_3_,bVar2);
      if (bVar2 == 0) {
        return;
      }
      pCVar4 = param_1;
      if ((((bVar2 < 0x61) || (0x7a < bVar2)) && ((bVar2 < 0x30 || (0x39 < bVar2)))) &&
         ((((bVar2 < 0x41 || (0x5a < bVar2)) && (bVar2 != 0x5f)) &&
          ((bVar2 != 0x2d && (bVar2 != 0x2e)))))) {
        if (bVar2 == 0x20) {
          pCVar4 = (CFastStringInt *)&DAT_0000002b;
        }
        else {
          bVar2 = bVar2 >> 4;
          CFastString::Concat(param_2,(CFastStringInt *)&DAT_00000025,(SStringParam *)unaff_EBX);
          if (bVar2 < 10) {
            unaff_EBX = (CFastStringInt *)((char)bVar2 + 0x30);
          }
          else {
            unaff_EBX = (CFastStringInt *)((char)bVar2 + 0x57);
          }
          CFastString::Concat(param_2,unaff_EBX,this);
          if (in_stack_00000014 < '\n') {
            pCVar4 = (CFastStringInt *)(in_stack_00000014 + 0x30);
          }
          else {
            pCVar4 = (CFastStringInt *)(in_stack_00000014 + 0x57);
          }
        }
      }
      CFastString::Concat(param_2,pCVar4,(SStringParam *)unaff_EBX);
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_00d71d68);
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::GetLatin1
// =================================================
CFastString __thiscall CFastStringInt::GetLatin1(void *this,CFastStringInt *param_1)
{
{
  char *pcVar1;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ae0e69;
  local_c = ExceptionList;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  GetLatin1(this,(CFastStringInt *)&DAT_00d71d68);
  CFastString::CFastString((CFastString *)param_1,(CFastString *)&DAT_00d71d68,pcVar1);
  ExceptionList = local_8;
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CFastStringInt::GetLimitedSizeUtf8OrAscii
// =================================================
void __thiscall
CFastStringInt::GetLimitedSizeUtf8OrAscii
          (void *this,CFastStringInt *param_1,CFastString *param_2,ulong param_3)
{
{
  bool bVar1;
  CFastStringInt *this_00;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  ulong unaff_EBX;
  CFastStringInt *unaff_EBP;
  SOldChars *unaff_ESI;
  int iVar5;
  ulong *unaff_EDI;
  undefined4 uStack00000010;
  CFastString *pCStack00000014;
  ulong *in_stack_fffffff4;
  SStringParamInt *in_stack_fffffffc;
  
  this_00 = param_1;
  if (*(int *)param_1 != 0) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)param_1,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_ESI);
    **(undefined1 **)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
  }
  uVar2 = param_3;
  if (*(int *)this != 0) {
    uVar3 = *(int *)this * 2;
    param_2 = (CFastString *)0x0;
    if ((param_3 != 0) && (param_3 * 2 < uVar3)) {
      uVar3 = param_3 * 2;
    }
    CFastStringBase<char>::PreAlloc
              ((CFastStringBase<char> *)param_1,(CClassicBufferMemory *)(uVar3 + 3),unaff_EBX);
    pCStack00000014 = (CFastString *)ReadCharsStart(this,unaff_EBP);
    uVar3 = ReadCharsNext(this,(CFastStringInt *)&stack0x00000014,in_stack_fffffff4);
    if (uVar3 != 0) {
      do {
        if (uVar3 != 0xfeff) {
          bVar1 = false;
          iVar5 = 0;
          if ((param_1 != (CFastStringInt *)0x0) && ((uVar3 & 0xffffff80) != 0)) {
            bVar1 = true;
            iVar5 = 3;
          }
          uVar4 = ConcatUtf8Char((CFastString *)this_00,(ulong)unaff_EDI);
          if ((uVar2 != 0) && (uVar2 < pCStack00000014 + iVar5 + uVar4)) {
            CFastString::TruncAfter((CFastString *)this_00,pCStack00000014,(ulong)unaff_EDI);
            break;
          }
          if (bVar1) {
            param_1 = (CFastStringInt *)0x0;
          }
          pCStack00000014 = pCStack00000014 + iVar5 + uVar4;
          this = param_2;
        }
        uVar3 = ReadCharsNext(this,(CFastStringInt *)&stack0x00000018,unaff_EDI);
      } while (uVar3 != 0);
      param_3 = (ulong)&DAT_00bbf800;
      uStack00000010 = 3;
      CFastString::ConcatBefore((CFastString *)this_00,(CFastStringInt *)&param_3,in_stack_fffffffc)
      ;
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::GetNextToken
// =================================================
int __thiscall
CFastStringInt::GetNextToken(void *this,CFastStringInt *param_1,SFastTokenInt *param_2)
{
{
  int iVar1;
  wchar_t wVar2;
  uint uVar3;
  int iVar4;
  wchar_t *pwVar5;
  SStringParam *unaff_EBX;
  short *psVar6;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  uVar3 = *(uint *)(param_1 + 0x14);
  if (*(uint *)this < uVar3) {
    *(uint *)param_1 = *(uint *)param_1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (*(int *)(param_1 + 4) != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      **(undefined2 **)(param_1 + 8) = 0;
    }
    return 0;
  }
  iVar1 = *(int *)((int)this + 4) + uVar3 * 2;
  if (*(short *)(*(int *)((int)this + 4) + uVar3 * 2) == 0) {
    *(uint *)param_1 = *(uint *)param_1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0xc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    if (*(int *)(param_1 + 4) != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      **(undefined2 **)(param_1 + 8) = 0;
    }
    return 0;
  }
  iVar4 = func_0x009c3b07(iVar1,*(undefined4 *)(param_1 + 0x1c));
  *(int *)(param_1 + 0xc) = iVar1 - *(int *)((int)this + 4) >> 1;
  uStack_4 = 1;
  iStack_c = iVar1;
  iStack_8 = iVar4;
  SetString(param_1 + 4,(CFastStringInt *)&iStack_c,unaff_EBX);
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  wVar2 = *(wchar_t *)(iVar1 + iVar4 * 2);
  psVar6 = (short *)(iVar1 + iVar4 * 2);
  if (((byte)*param_1 & 2) == 0) {
    if ((wVar2 != L'\0') &&
       (pwVar5 = _wcschr(*(wchar_t **)(param_1 + 0x1c),wVar2), pwVar5 != (wchar_t *)0x0)) {
      psVar6 = psVar6 + 1;
    }
  }
  else {
    while ((wVar2 != L'\0' &&
           (pwVar5 = _wcschr(*(wchar_t **)(param_1 + 0x1c),wVar2), pwVar5 != (wchar_t *)0x0))) {
      wVar2 = psVar6[1];
      psVar6 = psVar6 + 1;
    }
  }
  *(int *)(param_1 + 0x14) = (int)psVar6 - *(int *)((int)this + 4) >> 1;
  *(uint *)param_1 = *(uint *)param_1 ^ ((uint)(*psVar6 == 0) ^ *(uint *)param_1) & 1;
  return 1;
}
}

// =================================================
// Function: CFastStringInt::GetUtf8
// =================================================
void __thiscall
CFastStringInt::GetUtf8(void *this,CFastStringInt *param_1,CFastString *param_2,int param_3)
{
{
  ulong uVar1;
  void *this_00;
  SOldChars *unaff_ESI;
  ulong unaff_EDI;
  CFastStringInt *unaff_retaddr;
  ulong uStack00000010;
  
  if (*(int *)param_1 != 0) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)param_1,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_ESI);
    **(undefined1 **)(param_1 + 4) = 0;
    *(undefined4 *)param_1 = 0;
  }
  if (*(int *)this != 0) {
    CFastStringBase<char>::PreAlloc
              ((CFastStringBase<char> *)param_1,
               (CClassicBufferMemory *)((-(uint)(param_3 != 0) & 3) + *(int *)this * 2),unaff_EDI);
    if (param_3 != 0) {
      ConcatUtf8Char((CFastString *)param_1,(ulong)unaff_retaddr);
    }
    uStack00000010 = ReadCharsStart(this,unaff_retaddr);
    uVar1 = ReadCharsNext(this_00,(CFastStringInt *)&stack0x00000010,(ulong *)param_1);
    while (uVar1 != 0) {
      if (uVar1 != 0xfeff) {
        ConcatUtf8Char((CFastString *)param_1,(ulong)param_2);
      }
      uVar1 = ReadCharsNext(this,(CFastStringInt *)&stack0x00000014,(ulong *)param_2);
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::GetUtf8OrAscii
// =================================================
void __thiscall
CFastStringInt::GetUtf8OrAscii(void *this,CFastStringInt *param_1,CFastString *param_2)
{
{
  ulong unaff_retaddr;
  
  GetLimitedSizeUtf8OrAscii(this,param_1,(CFastString *)0x0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CFastStringInt::InternalSetCompose
// =================================================
void __thiscall
CFastStringInt::InternalSetCompose
          (void *this,CFastStringInt *param_1,ulong param_2,wchar_t *param_3,char *param_4,
          CFastArray<struct_SStringParamInt_const*> *param_5)
{
{
  uint *puVar1;
  bool bVar2;
  wchar_t wVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  wchar_t *pwVar9;
  ulong unaff_EBX;
  CFastStringBase<wchar_t> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  CFastStringInt *pCVar11;
  CFastStringInt *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar12;
  uint uVar13;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  wchar_t *pwVar14;
  void *in_stack_00000018;
  ulong uVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  int *piStack_44;
  byte *local_40;
  CFastStringBase<wchar_t> *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  wchar_t *local_2c;
  int local_28;
  undefined4 local_24;
  uint local_20 [8];
  
  pbVar8 = (byte *)param_4;
  pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  local_3c = (CFastStringBase<wchar_t> *)&DAT_00b30b8c;
  local_38 = 0;
  local_34 = 1;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_4,unaff_EDI);
  pCVar11 = param_1;
  pCVar10 = local_3c;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    bVar2 = false;
    do {
      uVar15 = 0x9036fa;
      pCVar16 = pCVar12;
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_5,pCVar12,(ulong)unaff_ESI);
      if (**(int **)pSVar5 == *(int *)(param_1 + 4)) {
        if (!bVar2) {
          local_24 = *(undefined4 *)param_1;
          unaff_ESI = (CFastStringInt *)&local_28;
          bVar2 = true;
          local_20[0] = 0;
          pCVar16 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x903731;
          local_28 = *(int *)(param_1 + 4);
          SetString(&DAT_00d71d70,unaff_ESI,(SStringParam *)unaff_EBP);
          local_30 = DAT_00d71d74;
          local_2c = DAT_00d71d70;
          local_28 = 0;
        }
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_3,pCVar12,uVar15);
        *(CFastStringBase<wchar_t> ***)pSVar5 = &local_3c;
      }
      pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_4,pCVar12,(ulong)pCVar16);
      if (*(uint *)(*(int *)pSVar5 + 4) < 2) {
        iVar6 = 0;
      }
      else {
        pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_5,pCVar12,(ulong)unaff_ESI);
        iVar6 = *(int *)(*(int *)pSVar5 + 4) + -2;
      }
      pCVar12 = pCVar12 + 1;
      pCVar11 = pCVar11 + iVar6;
      pCVar10 = (CFastStringBase<wchar_t> *)pCVar11;
    } while (pCVar12 < pCVar4);
  }
  local_3c = pCVar10;
  if (pCVar11 != (CFastStringInt *)*piStack_44) {
    CFastStringBase<wchar_t>::AllocAtLeast
              (piStack_44,(CFastStringBase<wchar_t> *)pCVar11,1,0,(SOldChars *)unaff_ESI);
    *(undefined2 *)(piStack_44[1] + (int)pCVar11 * 2) = 0;
    *piStack_44 = (int)pCVar11;
  }
  pwVar14 = (wchar_t *)piStack_44[1];
  pCVar10 = (CFastStringBase<wchar_t> *)0x0;
  local_40 = (byte *)param_4;
  param_4 = (char *)0x0;
  if (param_2 != 0) {
    do {
      if (param_3 == (wchar_t *)0x0) {
        wVar3 = (wchar_t)*pbVar8;
        pbVar8 = pbVar8 + 1;
        local_40 = pbVar8;
      }
      else {
        wVar3 = *param_3;
        param_3 = param_3 + 1;
      }
      if (wVar3 == L'\0') break;
      if ((ushort)wVar3 < 0x20) {
        if (((wVar3 == L'\t') || (wVar3 == L'\n')) || (wVar3 == L'\r')) goto LAB_0090380c;
      }
      else if (wVar3 != L'\x7f') {
LAB_0090380c:
        if (wVar3 == L'%') {
          param_4 = param_4 + 1;
          if (param_3 == (wchar_t *)0x0) {
            uVar7 = (uint)*pbVar8;
            pbVar8 = pbVar8 + 1;
            local_40 = pbVar8;
          }
          else {
            uVar7 = (uint)(ushort)*param_3;
            param_3 = param_3 + 1;
          }
          if (uVar7 == 0) break;
          if (uVar7 == 0x25) {
            *pwVar14 = L'%';
            pwVar14 = pwVar14 + 1;
            pCVar10 = pCVar10 + 1;
          }
          else {
            pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar7 - 0x31);
            if (pCVar4 < (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000009) {
              local_20[(int)pCVar4] = 1;
              SStringParamInt::SStringParamInt
                        (&local_2c,(SStringParamInt *)L"<XXX>",(wchar_t *)unaff_ESI);
              unaff_ESI = (CFastStringInt *)0x90389c;
              pCVar12 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        CFastBuffer<class_CCrystalFace*>::GetCount
                                  (in_stack_00000018,(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
              uVar7 = local_20[0];
              if (pCVar4 < pCVar12) {
                unaff_ESI = (CFastStringInt *)0x9038a8;
                pSVar5 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                   (in_stack_00000018,pCVar4,unaff_EBX);
                puVar1 = *(uint **)pSVar5;
                local_20[0] = *puVar1;
                local_20[1] = puVar1[1];
                local_20[2] = puVar1[2];
                uVar7 = local_20[1];
                unaff_EBP = pCVar4;
              }
              uVar13 = 0;
              pwVar9 = local_2c;
              pbVar8 = local_40;
              if (uVar7 != 0) {
                do {
                  wVar3 = *pwVar9;
                  if (wVar3 == L'\0') break;
                  if ((ushort)wVar3 < 0x20) {
                    if (((wVar3 == L'\t') || (wVar3 == L'\n')) || (wVar3 == L'\r'))
                    goto LAB_009038eb;
                  }
                  else if (wVar3 != L'\x7f') {
LAB_009038eb:
                    *pwVar14 = wVar3;
                    pCVar10 = pCVar10 + 1;
                    pwVar14 = pwVar14 + 1;
                    if ((int)local_3c < (int)pCVar10) break;
                  }
                  uVar13 = uVar13 + 1;
                  pwVar9 = pwVar9 + 1;
                } while (uVar13 < uVar7);
              }
            }
          }
        }
        else {
          *pwVar14 = wVar3;
          pwVar14 = pwVar14 + 1;
          pCVar10 = pCVar10 + 1;
        }
      }
      param_4 = param_4 + 1;
    } while (param_4 < param_2);
  }
  if (pCVar10 != (CFastStringBase<wchar_t> *)*piStack_44) {
    CFastStringBase<wchar_t>::AllocAtLeast(piStack_44,pCVar10,1,0,(SOldChars *)unaff_ESI);
    *(undefined2 *)(piStack_44[1] + (int)pCVar10 * 2) = 0;
    *piStack_44 = (int)pCVar10;
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::ReadCharsNext
// =================================================
ulong __thiscall CFastStringInt::ReadCharsNext(void *this,CFastStringInt *param_1,ulong *param_2)
{
{
  ushort uVar1;
  
  uVar1 = **(ushort **)param_1;
  *(ushort **)param_1 = *(ushort **)param_1 + 1;
  return (uint)uVar1;
}
}

// =================================================
// Function: CFastStringInt::ReadCharsStart
// =================================================
ulong __thiscall CFastStringInt::ReadCharsStart(void *this,CFastStringInt *param_1)
{
{
  return *(ulong *)((int)this + 4);
}
}

// =================================================
// Function: CFastStringInt::SetCompose
// =================================================
void __thiscall
CFastStringInt::SetCompose
          (void *this,CFastStringInt *param_1,SStringParam *param_2,SStringParamInt *param_3)
{
{
  SCasterCat *pSVar1;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  undefined4 in_stack_00000010;
  
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (&DAT_00d71d7c,(CFastBuffer<class_CSystemFidsFolder*> *)0x1,unaff_ESI);
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (&DAT_00d71d7c,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  *(undefined4 *)pSVar1 = in_stack_00000010;
  InternalSetCompose(this,*(CFastStringInt **)(param_3 + 4),0,*(wchar_t **)param_3,&DAT_00d71d7c,
                     (CFastArray<struct_SStringParamInt_const*> *)param_1);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (&DAT_00d71d7c,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,(ulong)param_2);
  return;
}
}

// =================================================
// Function: CFastStringInt::SetEscaped
// =================================================
void __thiscall CFastStringInt::SetEscaped(void *this,CFastStringInt *param_1,CFastString *param_2)
{
{
  char cVar1;
  CFastStringBase<wchar_t> *pCVar2;
  char *pcVar3;
  char cVar4;
  byte bVar5;
  SStringParam *unaff_ESI;
  char *pcVar6;
  SOldChars *unaff_EDI;
  undefined1 *puStack_4;
  
  pCVar2 = *(CFastStringBase<wchar_t> **)param_1;
  if (pCVar2 != DAT_00d71d68) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)&DAT_00d71d68,pCVar2,1,0,unaff_EDI)
    ;
    DAT_00d71d6c[(int)pCVar2] = 0;
    DAT_00d71d68 = pCVar2;
  }
  if (DAT_00d71d68 != (CFastStringBase<wchar_t> *)0x0) {
    CFastStringBase<char>::AllocAtLeast
              ((CFastStringBase<char> *)&DAT_00d71d68,(CFastStringBase<wchar_t> *)0x0,1,0,
               (SOldChars *)unaff_ESI);
    *DAT_00d71d6c = 0;
    DAT_00d71d68 = (CFastStringBase<wchar_t> *)0x0;
  }
  cVar4 = **(char **)(param_1 + 4);
  pcVar3 = *(char **)(param_1 + 4);
  while (cVar4 != '\0') {
    pcVar6 = pcVar3 + 1;
    param_2._1_3_ = (undefined3)((uint)param_2 >> 8);
    param_2 = (CFastString *)CONCAT31(param_2._1_3_,cVar4);
    if (cVar4 == '+') {
      param_2 = (CFastString *)CONCAT31(param_2._1_3_,0x20);
LAB_00904630:
      CFastString::Concat((CFastString *)&DAT_00d71d68,(CFastStringInt *)param_2,unaff_ESI);
    }
    else {
      if (cVar4 != '%') goto LAB_00904630;
      cVar4 = *pcVar6;
      pcVar6 = pcVar3 + 2;
      if (cVar4 == '\0') break;
      if ((byte)(cVar4 - 0x30U) < 10) {
LAB_009045f7:
        cVar1 = *pcVar6;
        pcVar6 = pcVar3 + 3;
        if (cVar1 != '\0') {
          bVar5 = cVar1 - 0x30;
          if (9 < bVar5) {
            if ((byte)(cVar1 + 0x9fU) < 6) {
              bVar5 = cVar1 + 0xa9;
            }
            else {
              if (5 < (byte)(cVar1 + 0xbfU)) goto LAB_0090463f;
              bVar5 = cVar1 - 0x37;
            }
          }
          param_2 = (CFastString *)CONCAT31(param_2._1_3_,cVar4 << 4 | bVar5);
          goto LAB_00904630;
        }
        break;
      }
      if (((byte)(cVar4 + 0x9fU) < 6) || ((byte)(cVar4 + 0xbfU) < 6)) {
        cVar4 = cVar4 + -7;
        goto LAB_009045f7;
      }
    }
LAB_0090463f:
    pcVar3 = pcVar6;
    cVar4 = *pcVar6;
  }
  puStack_4 = DAT_00d71d6c;
  SetUtf8(this,(CFastStringInt *)&puStack_4,unaff_ESI);
  return;
}
}

// =================================================
// Function: CFastStringInt::SetLatin1OrUtf8
// =================================================
void __thiscall
CFastStringInt::SetLatin1OrUtf8(void *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  char *pcVar1;
  CFastStringBase<wchar_t> *pCVar2;
  ulong unaff_EBX;
  SStringParam *unaff_ESI;
  SOldChars *unaff_EDI;
  
  pcVar1 = *(char **)param_1;
  if ((((pcVar1 != (char *)0x0) && (*pcVar1 == -0x11)) && (pcVar1[1] == -0x45)) &&
     (pcVar1[2] == -0x41)) {
    SetUtf8(this,param_1,unaff_ESI);
    return;
  }
  pCVar2 = *(CFastStringBase<wchar_t> **)(param_1 + 4);
  if (pCVar2 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar2,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar2 * 2) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar2;
  }
  if (*(wchar_t **)(param_1 + 4) != (wchar_t *)0x0) {
    pCVar2 = (CFastStringBase<wchar_t> *)
             CheckedStrCpy<unsigned_char>(*(wchar_t **)(param_1 + 4),(uchar *)unaff_ESI,unaff_EBX);
    if (pCVar2 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar2,1,0,(SOldChars *)unaff_ESI);
      *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar2 * 2) = 0;
      *(CFastStringBase<wchar_t> **)this = pCVar2;
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::SetLength
// =================================================
void __thiscall
CFastStringInt::SetLength(void *this,CFastString *param_1,ulong param_2,int param_3,char param_4)
{
{
  SOldChars *unaff_EDI;
  
  if (param_1 != *(CFastString **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)param_1 * 2) = 0;
    *(CFastString **)this = param_1;
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::SetString
// =================================================
void __thiscall CFastStringInt::SetString(void *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  char *pcVar1;
  CFastStringBase<wchar_t> *pCVar2;
  ulong unaff_EBX;
  SStringParam *unaff_ESI;
  SOldChars *unaff_EDI;
  
  pcVar1 = *(char **)param_1;
  if ((((pcVar1 != (char *)0x0) && (*pcVar1 == -0x11)) && (pcVar1[1] == -0x45)) &&
     (pcVar1[2] == -0x41)) {
    SetUtf8(this,param_1,unaff_ESI);
    return;
  }
  pCVar2 = *(CFastStringBase<wchar_t> **)(param_1 + 4);
  if (pCVar2 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar2,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar2 * 2) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar2;
  }
  if (*(wchar_t **)(param_1 + 4) != (wchar_t *)0x0) {
    pCVar2 = (CFastStringBase<wchar_t> *)
             CheckedStrCpy<unsigned_char>(*(wchar_t **)(param_1 + 4),(uchar *)unaff_ESI,unaff_EBX);
    if (pCVar2 != *(CFastStringBase<wchar_t> **)this) {
      CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar2,1,0,(SOldChars *)unaff_ESI);
      *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar2 * 2) = 0;
      *(CFastStringBase<wchar_t> **)this = pCVar2;
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::SetUtf8
// =================================================
void __thiscall CFastStringInt::SetUtf8(void *this,CFastStringInt *param_1,SStringParam *param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  CFastStringInt *pCVar2;
  SStringParam *unaff_ESI;
  SOldChars *unaff_EDI;
  
  pCVar1 = *(CFastStringBase<wchar_t> **)(param_1 + 4);
  if (pCVar1 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar1,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)pCVar1 * 2) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar1;
  }
  if (*(int *)this != 0) {
    CFastStringBase<wchar_t>::AllocAtLeast
              (this,(CFastStringBase<wchar_t> *)0x0,1,0,(SOldChars *)unaff_ESI);
    **(undefined2 **)((int)this + 4) = 0;
    *(undefined4 *)this = 0;
  }
  pCVar2 = (CFastStringInt *)ReadNextUtf8Char((char **)unaff_ESI);
  do {
    if (pCVar2 == (CFastStringInt *)0x0) {
      return;
    }
    if (pCVar2 != (CFastStringInt *)0xfeff) {
      if (pCVar2 < (CFastStringInt *)&DAT_00000020) {
        if (((pCVar2 == (CFastStringInt *)&DAT_00000009) ||
            (pCVar2 == (CFastStringInt *)&DAT_0000000a)) ||
           (pCVar2 == (CFastStringInt *)&DAT_0000000d)) goto LAB_00904088;
      }
      else if (pCVar2 != (CFastStringInt *)0x7f) {
LAB_00904088:
        Concat(this,pCVar2,unaff_ESI);
      }
    }
    pCVar2 = (CFastStringInt *)ReadNextUtf8Char((char **)unaff_ESI);
  } while( true );
}
}

// =================================================
// Function: CFastStringInt::TruncAfterIndex
// =================================================
void __thiscall CFastStringInt::TruncAfterIndex(void *this,CFastStringInt *param_1,ulong param_2)
{
{
  SOldChars *unaff_EDI;
  
  if (param_1 < *(CFastStringInt **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + (int)param_1 * 2) = 0;
    *(CFastStringInt **)this = param_1;
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::TruncBeforeIndex
// =================================================
void __thiscall CFastStringInt::TruncBeforeIndex(void *this,CFastStringInt *param_1,ulong param_2)
{
{
  CFastStringBase<wchar_t> *pCVar1;
  SStringParam *unaff_ESI;
  SOldChars *unaff_EDI;
  undefined1 *local_8;
  undefined4 local_4;
  
  if (*(CFastStringInt **)this <= param_1 + 1) {
    local_8 = &DAT_00b2c878;
    local_4 = 0;
    SetString(this,(CFastStringInt *)&local_8,unaff_ESI);
    return;
  }
  pCVar1 = (CFastStringBase<wchar_t> *)(*(CFastStringInt **)this + (-1 - (int)param_1));
  _memmove(*(void **)((int)this + 4),(void *)((int)*(void **)((int)this + 4) + (int)param_1 * 2 + 2)
           ,(int)pCVar1 * 2);
  if (pCVar1 != *(CFastStringBase<wchar_t> **)this) {
    CFastStringBase<wchar_t>::AllocAtLeast(this,pCVar1,1,0,unaff_EDI);
    *(undefined2 *)((int)pCVar1 * 2 + *(int *)((int)this + 4)) = 0;
    *(CFastStringBase<wchar_t> **)this = pCVar1;
  }
  return;
}
}

// =================================================
// Function: CFastStringInt::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CFastStringInt::_scalar_deleting_destructor_(void *this,CPfmHeap *param_1,uint param_2)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  }
  if (((uint)param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

