// Class implementation: CInputEventsStore

// =================================================
// Function: CInputEventsStore::AutoRegisterInput
// =================================================
ulong __thiscall
CInputEventsStore::AutoRegisterInput
          (void *this,CInputEventsStore *param_1,SInputActionDesc *param_2)
{
{
  CMwId CVar1;
  SCachedValue *pSVar2;
  undefined3 extraout_var;
  TiXmlAttributeSet *extraout_EAX;
  ulong unaff_EBX;
  CFastStringInt *unaff_ESI;
  TiXmlAttribute *unaff_EDI;
  TiXmlAttribute *in_stack_ffffffe4;
  undefined1 local_18 [12];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae0338;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pSVar2 = (SCachedValue *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     ((void *)((int)this + 0x20),
                      (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  CVar1 = CMwId::CreateFromLocalIndex((ulong)local_18);
  CFastBuffer<class_CMwId>::Add
            ((void *)((int)this + 0x2c),(TiXmlAttributeSet *)CONCAT31(extraout_var,CVar1),unaff_EDI)
  ;
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  CFastBuffer<class_CDx9TextureKeeper*>::Add
            ((void *)((int)this + 0x20),(TiXmlAttributeSet *)&stack0x0000000c,
             (TiXmlAttribute *)unaff_ESI);
  SCachedValue::SCachedValue(&local_c,pSVar2,unaff_EBX);
  CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
            ((void *)((int)this + 0x38),extraout_EAX,in_stack_ffffffe4);
  ExceptionList = param_2;
  return (ulong)pSVar2;
}
}

// =================================================
// Function: CInputEventsStore::CInputEventsStore
// =================================================
void __thiscall
CInputEventsStore::CInputEventsStore
          (void *this,CInputEventsStore *param_1,ulong param_2,int param_3)
{
{
  ulong unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>::
  CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_>
            (this,(CFastBufferWheel<struct_SMwTimedValueInstant<struct_SInputEventsStoreElem>_> *)
                  param_1,unaff_ESI);
  *(int *)((int)this + 0x18) = param_3;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x20),unaff_retaddr);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x2c),(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x38),(CFastBuffer<class_CPlugFileSndGen*> *)param_2);
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  return;
}
}

// =================================================
// Function: CInputEventsStore::ClearStore
// =================================================
void __thiscall CInputEventsStore::ClearStore(void *this,CInputEventsStore *param_1)
{
{
  SCachedValue *pSVar1;
  undefined4 *extraout_EAX;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *unaff_ESI;
  SCachedValue *pSVar3;
  SCachedValue *unaff_EDI;
  uchar **unaff_retaddr;
  ulong in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel(this,unaff_ESI);
  *(int *)((int)this + 0x1c) = *(int *)((int)this + 0x1c) + 1;
  pSVar1 = (SCachedValue *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x20),unaff_EBP);
  pSVar3 = (SCachedValue *)0x0;
  if (pSVar1 != (SCachedValue *)0x0) {
    do {
      SCachedValue::SCachedValue(&stack0xfffffffc,pSVar3,(ulong)unaff_EDI);
      unaff_EDI = pSVar3;
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((void *)((int)this + 0x38),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar3,unaff_EBX);
      *(undefined4 *)pSVar2 = *extraout_EAX;
      *(undefined4 *)(pSVar2 + 4) = extraout_EAX[1];
      pSVar3 = pSVar3 + 1;
      *(undefined4 *)(pSVar2 + 8) = extraout_EAX[2];
    } while (pSVar3 < pSVar1);
  }
  Lock(this,(CDx9DynamicVB *)0x0,in_stack_fffffff8,in_stack_fffffffc,unaff_retaddr,(ulong *)param_1)
  ;
  return;
}
}

// =================================================
// Function: CInputEventsStore::Convert
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short __cdecl CInputEventsStore::Convert(int param_1)
{
{
  ushort uVar1;
  ulong uVar2;
  uint uVar3;
  void *in_ECX;
  SInputActionDesc *unaff_ESI;
  GxTexCoordSet *unaff_EDI;
  float fVar4;
  uint *in_stack_00000010;
  
  uVar2 = CFastArray<class_CGameMenuFrame*>::Find
                    ((void *)((int)in_ECX + 0x20),(CFastArray<class_GxTexCoordSet> *)param_1,
                     unaff_EDI);
  if (uVar2 == 0xffffffff) {
    if (*(int *)((int)in_ECX + 0x18) != 0) {
      return 0;
    }
    uVar2 = AutoRegisterInput(in_ECX,*(CInputEventsStore **)param_1,unaff_ESI);
  }
  *(char *)((int)in_stack_00000010 + 3) = (char)uVar2;
  switch(**(undefined4 **)param_1) {
  case 0:
    *in_stack_00000010 =
         *in_stack_00000010 ^ ((uint)(*(int *)(param_1 + 4) != 0) ^ *in_stack_00000010) & 0xffffff;
    return 1;
  case 1:
    fVar4 = GmFunc::ClampReal(*(float *)(param_1 + 4),_DAT_00b36184,_DAT_00b36adc);
    *in_stack_00000010 =
         *in_stack_00000010 ^
         ((uint)(longlong)ROUND(fVar4 * (float)_DAT_00bbea60) ^ *in_stack_00000010) & 0xffffff;
    return 1;
  case 2:
    break;
  case 3:
    *in_stack_00000010 =
         *in_stack_00000010 ^ (*(uint *)(param_1 + 4) ^ *in_stack_00000010) & 0xffffff;
    return 1;
  case 4:
    DAT_00d7144c = *(undefined4 *)(param_1 + 4);
    DAT_00d71448 = *(undefined4 **)param_1;
    *in_stack_00000010 = *in_stack_00000010 & 0xff0004d2 | 0x4d2;
    return 1;
  default:
    return 0;
  }
  if (_DAT_00b36158 <= *(float *)(param_1 + 4)) {
    uVar1 = GmFunc::RealToNat16(*(float *)(param_1 + 4),0.0,_DAT_00b60320);
    uVar3 = uVar1 + 100;
  }
  else {
    uVar3 = 0;
  }
  *in_stack_00000010 = *in_stack_00000010 ^ (*in_stack_00000010 ^ uVar3) & 0xffffff;
  return 1;
}
}

// =================================================
// Function: CInputEventsStore::GetState
// =================================================
EState __thiscall CInputEventsStore::GetState(void *this,CMwCmdFiber *param_1)
{
{
  undefined4 local_c [3];
  
  GetState(this,param_1);
  *(undefined4 **)param_1 = local_c;
  *(undefined4 *)(param_1 + 4) = local_c[0];
  return (EState)param_1;
}
}

// =================================================
// Function: CInputEventsStore::InsertSorted
// =================================================
int __thiscall
CInputEventsStore::InsertSorted
          (void *this,CInputEventsStore *param_1,SInputEvent *param_2,ulong param_3)
{
{
  short sVar1;
  undefined2 extraout_var;
  SInputEvent *unaff_retaddr;
  
  sVar1 = Convert((int)param_1);
  if (CONCAT22(extraout_var,sVar1) == 0) {
    return 0;
  }
  InsertSorted(this,(CInputEventsStore *)&stack0xfffffffc,unaff_retaddr,(ulong)param_1);
  return 1;
}
}

// =================================================
// Function: CInputEventsStore::Lock
// =================================================
void __thiscall
CInputEventsStore::Lock
          (void *this,CDx9DynamicVB *param_1,ulong param_2,ulong param_3,uchar **param_4,
          ulong *param_5)
{
{
  *(CDx9DynamicVB **)((int)this + 0x14) = param_1;
  return;
}
}

// =================================================
// Function: CInputEventsStore::RegisterInput
// =================================================
void __thiscall
CInputEventsStore::RegisterInput
          (void *this,CInputEventsStore *param_1,SInputActionDesc *param_2,CMwId *param_3)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  TiXmlAttributeSet *extraout_EAX;
  SCasterCat *pSVar2;
  TiXmlAttribute *unaff_EBX;
  TiXmlAttribute *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  GxTexCoordSet *unaff_EDI;
  TiXmlAttributeSet *in_stack_00000010;
  undefined4 in_stack_00000014;
  int in_stack_0000001c;
  ulong in_stack_fffffff4;
  TiXmlAttribute *in_stack_fffffff8;
  ulong in_stack_fffffffc;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastArray<class_CGameMenuFrame*>::Find
                     ((void *)((int)this + 0x2c),(CFastArray<class_GxTexCoordSet> *)param_2,
                      unaff_EDI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount((void *)((int)this + 0x20),unaff_ESI);
    CFastBuffer<class_CMwId>::Add((void *)((int)this + 0x2c),in_stack_00000010,unaff_EBP);
    in_stack_00000014 = 0;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              ((void *)((int)this + 0x20),(TiXmlAttributeSet *)&stack0x00000014,unaff_EBX);
    SCachedValue::SCachedValue(&param_1,(SCachedValue *)pCVar1,in_stack_fffffff4);
    CFastBuffer<struct_CInputEventsStore::SCachedValue>::Add
              ((void *)((int)this + 0x38),extraout_EAX,in_stack_fffffff8);
  }
  if (in_stack_0000001c != 0) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)((int)this + 0x20),pCVar1,in_stack_fffffffc);
    *(int *)pSVar2 = in_stack_0000001c;
  }
  return;
}
}

// =================================================
// Function: CInputEventsStore::SetState
// =================================================
int __thiscall
CInputEventsStore::SetState
          (void *this,CInputEventsStore *param_1,SInputEvent *param_2,ulong param_3)
{
{
  short sVar1;
  undefined2 extraout_var;
  uint unaff_EBX;
  SInputEvent *unaff_retaddr;
  SInputEvent *pSVar2;
  CInputEventsStore **local_10;
  uint local_4;
  
  local_10 = &param_1;
  sVar1 = Convert((int)param_1);
  if (CONCAT22(extraout_var,sVar1) == 0) {
    return 0;
  }
  pSVar2 = unaff_retaddr;
  GetState(this,(CMwCmdFiber *)(local_4 >> 0x18));
  if (((unaff_EBX ^ local_4) & 0xffffff) != 0) {
    InsertSorted(this,(CInputEventsStore *)&local_10,unaff_retaddr,(ulong)pSVar2);
  }
  return 1;
}
}

