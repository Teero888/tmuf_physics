// Class implementation: SSystemTime

// =================================================
// Function: SSystemTime::GetAsString_YMD_HMS
// =================================================
void __thiscall
SSystemTime::GetAsString_YMD_HMS
          (void *this,SSystemTime *param_1,CFastString *param_2,CFastString *param_3)
{
{
  SSystemTime *this_00;
  CFastString *pCVar1;
  SStringParam *unaff_EBX;
  SStringParam *unaff_ESI;
  int unaff_EDI;
  SSystemTime *pSStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined *puStack00000020;
  undefined *puStack00000024;
  undefined4 uStack00000028;
  void *in_stack_00000034;
  int in_stack_ffffffd4;
  SStringParam *pSVar2;
  SStringParam *pSVar3;
  undefined1 *puVar4;
  SStringParam *pSVar5;
  SStringParam *pSVar6;
  int iVar7;
  SStringParam *pSVar8;
  SStringParam *pSVar9;
  SSystemTime *pSVar10;
  
  this_00 = param_1;
  ExceptionList = &stack0xffffffec;
  pSVar2 = (SStringParam *)0x0;
  puVar4 = &DAT_00b2c878;
  pSVar5 = (SStringParam *)0x0;
  pSVar3 = (SStringParam *)PTR_DAT_00bbf7d8;
  CFastString::SetString
            ((CFastString *)param_1,(CFastStringInt *)&stack0xffffffe0,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffc8));
  CFastString::SetNatural
            ((CFastString *)&stack0xffffffdc,(CFastString *)(uint)*(ushort *)this,0,4,1,0,1,
             unaff_EDI);
  pSVar6 = pSVar5;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0xffffffe8,unaff_ESI);
  pCVar1 = param_2;
  pSVar8 = *(SStringParam **)param_2;
  iVar7 = *(int *)(param_2 + 4);
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0xffffffec,unaff_EBX);
  CFastString::SetNatural
            ((CFastString *)&stack0xffffffe8,(CFastString *)(*(byte *)((int)this + 2) & 0xf),0,2,1,0
             ,1,in_stack_ffffffd4);
  pSVar9 = pSVar8;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0xfffffff4,pSVar2);
  pSVar10 = *(SSystemTime **)(pCVar1 + 4);
  pSVar2 = *(SStringParam **)pCVar1;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0xfffffff8,pSVar3);
  CFastString::SetNatural
            ((CFastString *)&stack0xfffffff4,(CFastString *)(*(uint *)this >> 0x17 & 0x1f),0,2,1,0,1
             ,(int)puVar4);
  param_1 = pSVar10;
  pSVar10 = param_1;
  pSVar3 = pSVar2;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0x00000000,pSVar5);
  param_1 = *(SSystemTime **)(pCVar1 + 4);
  param_2 = *(CFastString **)pCVar1;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&param_1,pSVar6);
  CFastString::SetNatural
            ((CFastString *)&stack0x00000000,(CFastString *)(*(uint *)((int)this + 4) & 0x1f),0,2,1,
             0,1,iVar7);
  pSStack00000010 = param_1;
  param_3 = param_2;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&param_3,pSVar8);
  uStack00000014 = *(undefined4 *)pCVar1;
  pSStack00000010 = *(SSystemTime **)(pCVar1 + 4);
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0x00000010,pSVar9);
  CFastString::SetNatural
            ((CFastString *)&param_3,(CFastString *)(*(uint *)((int)this + 4) >> 5 & 0x3f),0,2,1,0,1
             ,(int)pSVar10);
  uStack00000018 = uStack00000014;
  uStack0000001c = pSStack00000010;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0x00000018,pSVar3);
  uStack0000001c = *(undefined4 *)(pCVar1 + 4);
  puStack00000020 = *(undefined **)pCVar1;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)&stack0x0000001c,pSVar2);
  CFastString::SetNatural
            ((CFastString *)&stack0x00000018,(CFastString *)(*(uint *)((int)this + 4) >> 0xb & 0x3f)
             ,0,2,1,0,1,(int)param_1);
  param_1 = (SSystemTime *)&stack0x00000024;
  puStack00000024 = puStack00000020;
  uStack00000028 = uStack0000001c;
  CFastString::Concat((CFastString *)this_00,(CFastStringInt *)param_1,(SStringParam *)param_2);
  if (puStack00000024 != PTR_DAT_00bbf7d8) {
    param_2 = (CFastString *)(puStack00000024 + -1);
    if ((puStack00000024[-1] & 0x80) != 0) {
      param_2 = (CFastString *)(puStack00000024 + -4);
    }
    param_1 = (SSystemTime *)0x441a22;
    operator_delete__(param_2);
  }
  ExceptionList = in_stack_00000034;
  return;
}
}

// =================================================
// Function: SSystemTime::GetT2SubT1InMilliseconds
// =================================================
int64 __cdecl SSystemTime::GetT2SubT1InMilliseconds(SSystemTime *param_1,SSystemTime *param_2)
{
{
  uint extraout_EAX;
  uint uVar1;
  int extraout_EDX;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 4);
  uVar3 = *(uint *)(param_2 + 4);
  __allmul();
  __allmul();
  __allmul();
  __allmul();
  __allmul();
  __allmul();
  uVar2 = uVar1 >> 0x11 & 0x3ff;
  uVar1 = extraout_EAX - uVar2;
  uVar3 = uVar3 >> 0x11 & 0x3ff;
  return CONCAT44((extraout_EDX - (uint)(extraout_EAX < uVar2)) + (uint)CARRY4(uVar1,uVar3),
                  uVar1 + uVar3);
}
}

// =================================================
// Function: SSystemTime::IsInvalid
// =================================================
int __thiscall SSystemTime::IsInvalid(void *this,SSystemTime *param_1)
{
{
  if (((((*(uint *)this & 0xffff) == 0) && ((*(uint *)this & 0xfff0000) == 0)) &&
      ((*(uint *)((int)this + 4) & 0x1f) == 0)) && ((*(uint *)((int)this + 4) & 0x7ffffe0) == 0)) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: SSystemTime::SSystemTime
// =================================================
void __thiscall SSystemTime::SSystemTime(void *this,SSystemTime *param_1)
{
{
  *(uint *)this = *(uint *)this & 0xfffffff;
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) & 0x7ffffff;
  return;
}
}

// =================================================
// Function: SSystemTime::SetFromFileTime
// =================================================
void __thiscall SSystemTime::SetFromFileTime(void *this,SSystemTime *param_1,uint64 param_2)
{
{
  _SYSTEMTIME *unaff_ESI;
  _SYSTEMTIME local_10;
  
  FileTimeToSystemTime((FILETIME *)&stack0xffffffe8,&local_10);
  Win32SystemTimeToSystemTime(unaff_ESI,param_1);
  return;
}
}

// =================================================
// Function: SSystemTime::SetFromLocalTime
// =================================================
void __thiscall SSystemTime::SetFromLocalTime(void *this,SSystemTime *param_1)
{
{
  _SYSTEMTIME *unaff_ESI;
  SSystemTime *in_stack_fffffff0;
  
  GetLocalTime((LPSYSTEMTIME)&stack0xfffffff0);
  Win32SystemTimeToSystemTime(unaff_ESI,in_stack_fffffff0);
  return;
}
}

// =================================================
// Function: SSystemTime::SetFromSystemTime
// =================================================
void __thiscall SSystemTime::SetFromSystemTime(void *this,SSystemTime *param_1)
{
{
  _SYSTEMTIME *unaff_ESI;
  SSystemTime *in_stack_fffffff0;
  
  GetSystemTime((LPSYSTEMTIME)&stack0xfffffff0);
  Win32SystemTimeToSystemTime(unaff_ESI,in_stack_fffffff0);
  return;
}
}

// =================================================
// Function: SSystemTime::SetInvalid
// =================================================
void __thiscall SSystemTime::SetInvalid(void *this,CGameScoresVersion *param_1)
{
{
  *(uint *)((int)this + 4) = *(uint *)((int)this + 4) & 0xf8000000;
  *(undefined2 *)this = 0;
  *(uint *)this = *(uint *)this & 0xf000ffff;
  return;
}
}

