// Class implementation: CSceneVehicle

// =================================================
// Function: CSceneVehicle::AdjustSounds
// =================================================
void __thiscall
CSceneVehicle::AdjustSounds
          (CSceneVehicle *this,CSceneVehicle *param_1,float param_2,int param_3,int param_4,
          float param_5)
{
{
  int iVar1;
  CMwId CVar2;
  undefined3 extraout_var;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  int iVar5;
  CFastStringInt *unaff_EBX;
  CMwNod *unaff_EBP;
  CFastStringInt *unaff_ESI;
  CMwId *unaff_EDI;
  CMwId *pCVar6;
  int in_stack_00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000001c;
  CMwNod *in_stack_00000020;
  undefined4 in_stack_00000024;
  int in_stack_00000028;
  undefined4 in_stack_0000002c;
  int in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined1 *in_stack_00000038;
  undefined4 in_stack_0000003c;
  int in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000048;
  undefined4 in_stack_0000004c;
  int in_stack_00000050;
  undefined4 in_stack_00000054;
  CSceneVehicle *pCVar7;
  CFastStringInt *pCVar8;
  CMwId *pCVar9;
  CFastStringInt *pCVar10;
  
  pCVar10 = (CFastStringInt *)0xffffffff;
  pCVar9 = (CMwId *)&LAB_00accef0;
  pCVar8 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar7 = this;
  RetrieveSounds(this,(CSceneToyBoat *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  iVar1 = param_3;
  *(float *)(this + 0x84) = param_2;
  *(int *)(this + 0x8c) = param_4;
  *(float *)(this + 0x90) = param_5;
  iVar5 = *(int *)(this + 0x260);
  *(int *)(this + 0x88) = param_3;
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(float *)(*(int *)(iVar5 + 0x30) + 0x5c) = param_2;
    *(int *)(*(int *)(*(int *)(this + 0x260) + 0x30) + 0x60) = param_3;
    *(float *)(*(int *)(*(int *)(this + 0x260) + 0x30) + 0x70) = param_5;
  }
  iVar5 = *(int *)(this + 0x264);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(float *)(*(int *)(iVar5 + 0x30) + 0x5c) = param_2;
    *(int *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x60) = param_3;
    *(float *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x70) = param_5;
  }
  iVar5 = *(int *)(this + 0x268);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(float *)(*(int *)(iVar5 + 0x30) + 0x5c) = param_2;
    *(int *)(*(int *)(*(int *)(this + 0x268) + 0x30) + 0x60) = param_3;
    *(float *)(*(int *)(*(int *)(this + 0x268) + 0x30) + 0x70) = param_5;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&param_3);
  pCVar6 = (CMwId *)0x3;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var,CVar2),unaff_EDI);
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)unaff_ESI);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000018 != 0) {
    if (iVar5 != 0) {
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,(ulong)unaff_EBP);
    }
    if (*(CMwNod **)(this + 0x26c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x26c),unaff_EBP);
      *(undefined4 *)(this + 0x26c) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x26c);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(int *)(*(int *)(iVar5 + 0x30) + 0x5c) = param_4;
    *(int *)(*(int *)(*(int *)(this + 0x26c) + 0x30) + 0x60) = iVar1;
    *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
     (*(int *)(*(int *)(this + 0x26c) + 0x30) + 0x70) = in_stack_0000001c;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&param_5);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_00,CVar2),
                      (CMwId *)unaff_EBP);
  param_3 = -1;
  OnAccessViolation_ConcatToCrashFileName(unaff_EBX);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)unaff_EBX);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000020 != (CMwNod *)0x0) {
    if (iVar5 != 0) {
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,(ulong)pCVar7);
    }
    if (*(CMwNod **)(this + 0x270) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x270),(CMwNod *)pCVar7);
      *(undefined4 *)(this + 0x270) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x270);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(int *)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000018;
    *(int *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x70) = in_stack_00000024;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x0000001c);
  param_4 = 5;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_01,CVar2),
                      (CMwId *)pCVar7);
  param_5 = -NAN;
  OnAccessViolation_ConcatToCrashFileName(pCVar8);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar8);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000028 != 0) {
    if (iVar5 != 0) {
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,(ulong)pCVar9);
    }
    if (*(CMwNod **)(this + 0x274) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x274),(CMwNod *)pCVar9);
      *(undefined4 *)(this + 0x274) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x274);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(CMwNod **)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000020;
    *(int *)(*(int *)(*(int *)(this + 0x274) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x274) + 0x30) + 0x70) = in_stack_0000002c;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000024);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_02,CVar2),pCVar9);
  in_stack_0000001c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar10);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar10);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000030 != 0) {
    if (iVar5 != 0) {
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,(ulong)pCVar6);
    }
    if (*(CMwNod **)(this + 0x278) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x278),(CMwNod *)pCVar6);
      *(undefined4 *)(this + 0x278) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x278);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(int *)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000028;
    *(int *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x70) = in_stack_00000034;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x0000002c);
  in_stack_00000020 = (CMwNod *)&DAT_00000007;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_03,CVar2),pCVar6);
  in_stack_00000024 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)0xffffffff);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,0xffffffff);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000038 != (undefined1 *)0x0) {
    if (iVar5 != 0) {
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,4);
    }
    if (*(CMwNod **)(this + 0x27c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x27c),(CMwNod *)&DAT_00000004);
      *(undefined4 *)(this + 0x27c) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x27c);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(int *)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000030;
    *(int *)(*(int *)(*(int *)(this + 0x27c) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x27c) + 0x30) + 0x70) = in_stack_0000003c;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000034);
  in_stack_00000028 = 8;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_04,CVar2),
                      (CMwId *)&DAT_00000004);
  in_stack_0000002c = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_3);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x38,pCVar3,param_3);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000040 != 0) {
    if (iVar5 != 0) {
      param_3 = (int)pCVar3;
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,param_4);
    }
    if (*(CMwNod **)(this + 0x280) != (CMwNod *)0x0) {
      param_3 = 0x7cb510;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x280),(CMwNod *)param_4);
      *(undefined4 *)(this + 0x280) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x280);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(undefined1 **)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000038;
    *(int *)(*(int *)(*(int *)(this + 0x280) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x280) + 0x30) + 0x70) = in_stack_00000044;
  }
  param_3 = (int)s_SoundRoar_00b9f268;
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x0000003c);
  param_3 = CONCAT31(extraout_var_05,CVar2);
  in_stack_00000030 = 9;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)param_3,(CMwId *)param_4);
  in_stack_00000034 = 0xffffffff;
  param_4 = 0x7cb580;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_5);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    param_3 = 0x7cb58e;
    param_4 = (int)pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)param_5);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000048 != 0) {
    if (iVar5 != 0) {
      param_4 = 0x7cb5a6;
      param_5 = (float)pCVar3;
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,6);
    }
    if (*(CMwNod **)(this + 0x284) != (CMwNod *)0x0) {
      param_5 = 1.1452786e-38;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x284),(CMwNod *)&DAT_00000006);
      *(undefined4 *)(this + 0x284) = 0;
    }
  }
  iVar5 = *(int *)(this + 0x284);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0x30) != 0)) {
    *(int *)(*(int *)(iVar5 + 0x30) + 0x5c) = in_stack_00000040;
    *(int *)(*(int *)(*(int *)(this + 0x284) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x284) + 0x30) + 0x70) = in_stack_0000004c;
  }
  param_4 = (int)&stack0x0000002c;
  param_5 = (float)((int)"I@SoundVibrations" + 2);
  param_3 = 0x7cb5ff;
  CVar2 = CMwId::CreateFromLocalName((char *)param_4);
  param_5 = (float)CONCAT31(extraout_var_06,CVar2);
  in_stack_00000038 = &DAT_0000000a;
  param_4 = 0x7cb612;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)param_5,(CMwId *)&DAT_00000006);
  in_stack_0000003c = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_0000001c);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    iVar5 = 0;
  }
  else {
    param_5 = 1.1452962e-38;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_0000001c);
    iVar5 = *(int *)pSVar4;
  }
  if (in_stack_00000050 != 0) {
    if (iVar5 != 0) {
      in_stack_0000001c = pCVar3;
      CSceneMobil::LinkRemove((CSceneMobil *)this,(CSceneMobil *)pCVar3,(ulong)in_stack_00000020);
    }
    if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
      in_stack_0000001c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cb65a;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x288),in_stack_00000020);
      *(undefined4 *)(this + 0x288) = 0;
    }
  }
  if ((*(int *)(this + 0x288) != 0) && (iVar5 = *(int *)(*(int *)(this + 0x288) + 0x30), iVar5 != 0)
     ) {
    *(int *)(iVar5 + 0x5c) = in_stack_00000048;
    *(int *)(*(int *)(*(int *)(this + 0x288) + 0x30) + 0x60) = iVar1;
    *(undefined4 *)(*(int *)(*(int *)(this + 0x288) + 0x30) + 0x70) = in_stack_00000054;
  }
  ExceptionList = in_stack_00000038;
  return;
}
}

// =================================================
// Function: CSceneVehicle::AllWheelsSliding
// =================================================
int __thiscall CSceneVehicle::AllWheelsSliding(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = (**(code **)(*(int *)this + 0x188))();
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      iVar2 = (**(code **)(*(int *)this + 0x18c))(uVar3);
      if (iVar2 == 0) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  return 1;
}
}

// =================================================
// Function: CSceneVehicle::BuildVehicleMaterialsRemap
// =================================================
void __thiscall
CSceneVehicle::BuildVehicleMaterialsRemap(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CSceneVehicle *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CSystemFidFile **unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  ulong unaff_EDI;
  CSceneVehicle *pCVar4;
  
  this_00 = this + 0x6c;
  pCVar4 = this;
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x1f,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  CFastArray<class_CSystemFidFile*>::InitValue
            (this_00,(CFastArray<class_CSystemFidFile*> *)&stack0x00000000,unaff_ESI);
  if ((*(CMwRefBuffer **)(this + 0x68) != (CMwRefBuffer *)0x0) &&
     (pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CMwRefBuffer::GetCount(*(CMwRefBuffer **)(this + 0x68),unaff_EBP),
     pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0)) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x68) + 0x14),pCVar3,(ulong)unaff_EBX);
      unaff_EBX = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                  (uint)*(byte *)(*(int *)pSVar2 + 0x44);
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,unaff_EBX,(ulong)pCVar4);
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2 = pCVar3;
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::CSceneVehicle
// =================================================
void __thiscall CSceneVehicle::CSceneVehicle(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CMwNod *extraout_EAX;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBP;
  CMwNod *this_00;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastArray<class_CManoeuvre*> *unaff_EDI;
  GmSpring<float> *pGVar1;
  code *pcVar2;
  CMwCmdFastCall *pCStack0000000c;
  undefined1 uStack00000014;
  undefined1 uStack00000018;
  void *in_stack_0000001c;
  undefined1 uStack00000028;
  CSceneVehicle *pCVar3;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffff0;
  SVisualHandler *pSVar4;
  SVisualHandler *pSVar5;
  ulong uVar6;
  GmSpring<float> *pGVar7;
  CMwNod *pCVar8;
  
  pGVar7 = (GmSpring<float> *)0xffffffff;
  pSVar5 = (SVisualHandler *)&LAB_00acd29e;
  pSVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar3 = this;
  CSceneMobil::CSceneMobil
            ((CSceneMobil *)this,(CSceneMobil *)(DAT_00cca150 ^ (uint)&stack0xffffffe0));
  *(undefined ***)this = vftable;
  pGVar1 = (GmSpring<float> *)0x0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>(this + 0x6c,unaff_EDI);
  *(undefined4 *)(this + 0xb0) = 1;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb8) = 1;
  *(undefined4 *)(this + 0xb4) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xd4,unaff_ESI);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xe0,unaff_EBP);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xec,(CFastBuffer<class_CPlugFileSndGen*> *)pCVar3);
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0xf8,in_stack_fffffff0);
  uStack00000014 = 9;
  SVisualHandler::SVisualHandler(this + 0x104,pSVar4);
  SVisualHandler::SVisualHandler(this + 0x170,pSVar5);
  GmSpring<float>::GmSpring<float>(this + 0x214,pGVar7);
  GmSpring<float>::GmSpring<float>(this + 0x228,pGVar1);
  *(undefined4 *)(this + 0x248) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x254,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x260) = 0;
  *(undefined4 *)(this + 0x264) = 0;
  *(undefined4 *)(this + 0x268) = 0;
  *(undefined4 *)(this + 0x26c) = 0;
  *(undefined4 *)(this + 0x270) = 0;
  *(undefined4 *)(this + 0x274) = 0;
  *(undefined4 *)(this + 0x278) = 0;
  *(undefined4 *)(this + 0x27c) = 0;
  *(undefined4 *)(this + 0x280) = 0;
  *(undefined4 *)(this + 0x284) = 0;
  *(undefined4 *)(this + 0x288) = 0;
  pcVar2 = SEnvironment::SEnvironment;
  pCVar8 = (CMwNod *)0x2;
  pCVar3 = this + 0x28c;
  uVar6 = 0xc;
  uStack00000028 = 0x16;
  _eh_vector_constructor_iterator_
            (pCVar3,0xc,2,SEnvironment::SEnvironment,SEnvironment::~SEnvironment);
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
            (this + 0x2ac,
             (CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)pCVar3);
  *(undefined4 *)(this + 0x2d0) = 0;
  *(undefined4 *)(this + 0x2d4) = 0;
  *(undefined4 *)(this + 0x2d8) = 0;
  uStack00000018 = 0x1b;
  pCStack0000000c = operator_new(0x24);
  uStack00000018 = 0x1c;
  if (pCStack0000000c == (CMwCmdFastCall *)0x0) {
    this_00 = (CMwNod *)0x0;
  }
  else {
    CMwCmdFastCall::CMwCmdFastCall
              (pCStack0000000c,(CMwCmdFastCall *)this,
               (CMwNod *)CGameCtnMenus::_vcall__376__flat______,(_func___cdecl_void *)&DAT_0000001a,
               uVar6);
    this_00 = extraout_EAX;
  }
  in_stack_0000001c = (void *)CONCAT31(in_stack_0000001c._1_3_,0x1b);
  if (this_00 != *(CMwNod **)(this + 0x48)) {
    if (this_00 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_00,pCVar8);
    }
    if (*(CMwNod **)(this + 0x48) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x48),pCVar8);
    }
    *(CMwNod **)(this + 0x48) = this_00;
  }
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0x2a4) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 200) = 0x3f800000;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xd0) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x2a8) = 2;
  *(undefined4 *)(this + 0x4c) = 1;
  *(undefined4 *)(this + 0x7c) = 0;
  SoundEnableSet(this,(CSceneVehicle *)0x0,1,(ulong)pCVar8);
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x90) = 0x3f800000;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x94) = 3;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0xa0) = 0;
  VehicleReset(this,(CSceneVehicleBall *)pcVar2);
  *(undefined4 *)(this + 0x2dc) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 1;
  ExceptionList = in_stack_0000001c;
  return;
}
}

// =================================================
// Function: CSceneVehicle::Chunk
// =================================================
void __thiscall
CSceneVehicle::Chunk
          (CSceneVehicle *this,CFuncSegment *param_1,CClassicArchive *param_2,ulong param_3)
{
{
  CSceneVehicle *unaff_ESI;
  CMwNodRef<class_CMwRefBuffer> *unaff_EDI;
  CMwNodRef<class_CMwRefBuffer> *unaff_retaddr;
  CSceneToyCharacterTunings *pCVar1;
  
  if (param_2 == (CClassicArchive *)0xa060000) {
    param_2 = *(CClassicArchive **)(this + 100);
    pCVar1 = (CSceneToyCharacterTunings *)&param_2;
    (**(code **)(*(int *)param_1 + 4))();
    if (*(int *)(param_1 + 8) == 0) {
      TuningsSet(this,(CSceneToyCharacter *)param_1,pCVar1);
    }
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x68),
               (CMwNodRef<class_CMwRefBuffer> *)pCVar1);
    if (*(int *)(param_1 + 8) == 0) {
      BuildVehicleMaterialsRemap(this,unaff_ESI);
    }
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x28c),unaff_EDI);
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x298),unaff_retaddr);
    CClassicArchive::MwDoNodRef<class_CMwRefBuffer>
              ((CClassicArchive *)param_1,(CClassicArchive *)(this + 0x60),
               (CMwNodRef<class_CMwRefBuffer> *)param_1);
  }
  else if (param_2 != (CClassicArchive *)0xffffffff) {
    CSceneMobil::Chunk((CSceneMobil *)this,param_1,param_2,(ulong)unaff_EDI);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::CreateDefaultData
// =================================================
void __thiscall CSceneVehicle::CreateDefaultData(CSceneVehicle *this,CCrystal *param_1)
{
{
  CMwRefBuffer *this_00;
  CMwNod *extraout_EAX;
  CSceneVehicleMaterial *this_01;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *extraout_EAX_00;
  CFastArray<struct_CDx9DeviceCaps::SFormat> *pCVar1;
  CMwNod *unaff_ESI;
  CMwRefBuffer *unaff_EDI;
  CMwNod *this_02;
  undefined4 uStack00000008;
  void *pvStack0000000c;
  CSceneVehicle *pCVar2;
  CSceneVehicle *pCVar3;
  
  pCVar3 = (CSceneVehicle *)&LAB_00accd66;
  ExceptionList = &stack0xfffffff4;
  pCVar2 = this;
  CSceneMobil::CreateDefaultData
            ((CSceneMobil *)this,(CCrystal *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  this_00 = operator_new(0x28);
  if (this_00 == (CMwRefBuffer *)0x0) {
    this_02 = (CMwNod *)0x0;
  }
  else {
    CMwRefBuffer::CMwRefBuffer(this_00,unaff_EDI);
    this_02 = extraout_EAX;
  }
  if (this_02 != *(CMwNod **)(this + 0x68)) {
    if (this_02 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(this_02,unaff_ESI);
    }
    if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x68),unaff_ESI);
    }
    *(CMwNod **)(this + 0x68) = this_02;
  }
  CMotionDayTime::SetMaterialMode
            (*(CMotionDayTime **)(this + 0x68),(CMotionDayTime *)0xa031000,(EMaterialMode)unaff_ESI)
  ;
  this_01 = operator_new(0x48);
  uStack00000008 = 1;
  if (this_01 == (CSceneVehicleMaterial *)0x0) {
    pCVar1 = (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x0;
  }
  else {
    CSceneVehicleMaterial::CSceneVehicleMaterial(this_01,(CSceneVehicleMaterial *)pCVar2);
    pCVar1 = extraout_EAX_00;
  }
  pvStack0000000c = (void *)0xffffffff;
  CMwRefBuffer::AddTail(*(CMwRefBuffer **)(this + 0x68),pCVar1,(SFormat *)this_00);
  BuildVehicleMaterialsRemap(this,pCVar3);
  ExceptionList = pvStack0000000c;
  return;
}
}

// =================================================
// Function: CSceneVehicle::GetChunkInfo
// =================================================
ulong __thiscall
CSceneVehicle::GetChunkInfo(CSceneVehicle *this,CFuncSegment *param_1,ulong param_2)
{
{
  ulong uVar1;
  
  if (param_1 == (CFuncSegment *)0xa060000) {
    return 3;
  }
  if (param_1 != (CFuncSegment *)0xffffffff) {
    uVar1 = CSceneMobil::GetChunkInfo((CSceneMobil *)this,param_1,param_2);
    return uVar1;
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CSceneVehicle::GetMwClassId
// =================================================
ulong __thiscall CSceneVehicle::GetMwClassId(CSceneVehicle *this,CControlStyle *param_1)
{
{
  return 0xa060000;
}
}

// =================================================
// Function: CSceneVehicle::GetUidChunkFromIndex
// =================================================
ulong __thiscall
CSceneVehicle::GetUidChunkFromIndex(CSceneVehicle *this,CMwCmdExpIso4Ident *param_1,ulong param_2)
{
{
  if ((CMwCmdExpIso4Ident *)&DAT_0000000c < param_1) {
    return (uint)(param_1 + -0xd) | 0xa060000;
  }
  if (param_1 < (CMwCmdExpIso4Ident *)&DAT_00000006) {
    if (param_1 == (CMwCmdExpIso4Ident *)0x0) {
      return 0x1001000;
    }
    return (uint)(param_1 + -1) | 0xa005000;
  }
  return (uint)(param_1 + -6) | 0xa011000;
}
}

// =================================================
// Function: CSceneVehicle::GetVehicleTuning
// =================================================
CSceneVehicleTuning * __thiscall
CSceneVehicle::GetVehicleTuning(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  
  pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)(*(int *)(this + 100) + 0x14),
                      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                       (*(int *)(this + 100) + 0x24),unaff_retaddr);
  return *(CSceneVehicleTuning **)pSVar1;
}
}

// =================================================
// Function: CSceneVehicle::Hide
// =================================================
void __thiscall CSceneVehicle::Hide(CSceneVehicle *this,CSceneToyMotorbike *param_1)
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  ulong unaff_EBP;
  int unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSceneToyMotorbike *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *pCVar7;
  
  CSceneMobil::Hide((CSceneMobil *)this,unaff_EDI);
  SetIsUpdateAsync(this,(CSceneVehicle *)0x0,unaff_ESI);
  pCVar7 = (CFastBuffer<class_CCrystalFace*> *)0x1;
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x0;
  (**(code **)(*(int *)this + 0x10c))();
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xf8,pCVar6);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0xf8,pCVar5,(ulong)pCVar7);
      pCVar7 = (CFastBuffer<class_CCrystalFace*> *)0x0;
      CMotionEmitterParticles::SetIsActive
                (*(CMotionEmitterParticles **)pSVar3,(CSceneObjectLink *)0x0,unaff_EBP);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,pCVar7);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar5,unaff_EBP);
      piVar1 = *(int **)(*(int *)pSVar3 + 0x18);
      if (piVar1 != (int *)0x0) {
        unaff_EBP = 0xa011000;
        iVar4 = (**(code **)(*piVar1 + 0x10))();
        if (iVar4 != 0) {
          (**(code **)(*piVar1 + 0x104))();
        }
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::InternalSoundRetrieve
// =================================================
void __thiscall
CSceneVehicle::InternalSoundRetrieve
          (CSceneVehicle *this,CSceneVehicle *param_1,CMwNodRef<class_CSceneSoundSource> *param_2,
          CMwId *param_3)
{
{
  CSceneObjectLink *this_00;
  CMwNod *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CMwId *unaff_ESI;
  int unaff_EDI;
  CMwNod *unaff_retaddr;
  int *in_stack_00000010;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId((CSceneMobil *)this,(CSceneMobil *)param_2,unaff_ESI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar1,(ulong)unaff_retaddr);
    this_00 = *(CSceneObjectLink **)pSVar2;
    if (this_00 != (CSceneObjectLink *)0x0) {
      CSceneObjectLink::SetIsActive(this_00,(CSceneObjectLink *)0x1,unaff_EDI);
      this_01 = *(CMwNod **)(this_00 + 0x18);
      if (this_01 != (CMwNod *)*in_stack_00000010) {
        if (this_01 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(this_01,(CMwNod *)param_1);
        }
        if ((CMwNod *)*in_stack_00000010 != (CMwNod *)0x0) {
          CMwNod::MwRelease((CMwNod *)*in_stack_00000010,(CMwNod *)param_2);
        }
        *in_stack_00000010 = (int)this_01;
      }
      if ((int *)*in_stack_00000010 == (int *)0x0) {
        return;
      }
      (**(code **)(*(int *)*in_stack_00000010 + 0xb4))();
      return;
    }
  }
  if (*(CMwNod **)param_2 != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)param_2,unaff_retaddr);
    *(undefined4 *)param_2 = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CSceneVehicle::MwGetClassInfo(CSceneVehicle *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d6d030;
}
}

// =================================================
// Function: CSceneVehicle::MwIsKindOf
// =================================================
int __thiscall
CSceneVehicle::MwIsKindOf(CSceneVehicle *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (((param_1 != (CMwCmdAffectParam *)0xa060000) && (param_1 != (CMwCmdAffectParam *)0xa011000))
     && (param_1 != (CMwCmdAffectParam *)0xa005000)) {
    return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
  }
  return 1;
}
}

// =================================================
// Function: CSceneVehicle::OnEnterScene
// =================================================
void __thiscall CSceneVehicle::OnEnterScene(CSceneVehicle *this,CSceneToyBroomstick *param_1)
{
{
  CSceneToyBroomstick *unaff_ESI;
  CSceneToyBoat *unaff_retaddr;
  CSceneVehicle *pCVar1;
  
  CSceneMobil::OnEnterScene((CSceneMobil *)this,unaff_ESI);
  (**(code **)(**(int **)(this + 0x48) + 0x7c))();
  RetrieveSounds(this,unaff_retaddr);
  pCVar1 = *(CSceneVehicle **)(this + 0x84);
  (**(code **)(*(int *)this + 0x180))
            (pCVar1,*(undefined4 *)(this + 0x88),*(undefined4 *)(this + 0x8c));
  if (*(int *)(this + 0x7c) == 0) {
    StartVehicleSounds(this,pCVar1);
  }
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xbc) = *(undefined4 *)(this + 0xb8);
  *(undefined4 *)(this + 0xc0) = 1;
  *(undefined4 *)(this + 0xc4) = 1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::OnLeaveScene
// =================================================
void __thiscall CSceneVehicle::OnLeaveScene(CSceneVehicle *this,CSceneToyRock *param_1)
{
{
  CSceneVehicle *unaff_ESI;
  CSceneToyRock *in_stack_00000008;
  
  if (*(int *)(this + 0x7c) == 0) {
    StopAllVehicleSounds(this,unaff_ESI);
  }
  (**(code **)(**(int **)(this + 0x48) + 0x80))();
  CSceneMobil::OnLeaveScene((CSceneMobil *)this,in_stack_00000008);
  return;
}
}

// =================================================
// Function: CSceneVehicle::OnNodLoaded
// =================================================
void __thiscall CSceneVehicle::OnNodLoaded(CSceneVehicle *this,CDx9DeviceCaps *param_1)
{
{
  CDx9DeviceCaps *unaff_ESI;
  
  CSceneObject::OnNodLoaded((CSceneObject *)this,unaff_ESI);
  *(undefined4 *)(this + 0xa0) = 1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::ParticleQualitySet
// =================================================
void __thiscall
CSceneVehicle::ParticleQualitySet
          (CSceneVehicle *this,CSceneVehicle *param_1,ESceneVehicleParticleQuality param_2)
{
{
  *(CSceneVehicle **)(this + 0xa8) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::PreloadResources
// =================================================
void __thiscall
CSceneVehicle::PreloadResources(CSceneVehicle *this,CSceneVehicle *param_1,CHmsViewport *param_2)
{
{
  CPlugTree *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CSceneVehicle *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  ulong uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar7 = *(int *)param_1;
  uVar6 = 0;
  uVar5 = 0;
  pCVar1 = CSceneMobil::GetTree((CSceneMobil *)this,(SVolatileTreePointer *)0x0);
  (**(code **)(iVar7 + 0xa0))(pCVar1,uVar5,uVar6);
  this_00 = this + 0x290;
  iVar7 = 2;
  do {
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar1);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar4,uVar5);
        uVar5 = *(ulong *)pSVar3;
        pCVar1 = (CPlugTree *)0x7c9288;
        (**(code **)(*(int *)param_1 + 0x100))();
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
    this_00 = this_00 + 0xc;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  (**(code **)(*(int *)param_1 + 0xa4))();
  return;
}
}

// =================================================
// Function: CSceneVehicle::ReloadSoundsToApplyFidParams
// =================================================
void __thiscall
CSceneVehicle::ReloadSoundsToApplyFidParams(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  int iVar1;
  CSystemFid *pCVar2;
  CSystemFid *unaff_ESI;
  CSystemFid *unaff_retaddr;
  
  if ((((*(int *)(this + 0x260) != 0) &&
       (iVar1 = *(int *)(*(int *)(this + 0x260) + 0x30), iVar1 != 0)) &&
      (iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0)) &&
     (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_ESI);
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x260) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x264) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x264) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x264) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x268) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x268) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x268) + 0x30) + 0x58),
               pCVar2,7);
  }
  if ((((*(int *)(this + 0x26c) != 0) &&
       (iVar1 = *(int *)(*(int *)(this + 0x26c) + 0x30), iVar1 != 0)) &&
      (iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0)) &&
     (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x26c) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x270) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x270) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x270) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x274) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x274) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x274) + 0x30) + 0x58),
               pCVar2,7);
  }
  if ((((*(int *)(this + 0x278) != 0) &&
       (iVar1 = *(int *)(*(int *)(this + 0x278) + 0x30), iVar1 != 0)) &&
      (iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0)) &&
     (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x278) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x27c) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x27c) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x27c) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x280) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x280) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x280) + 0x30) + 0x58),
               pCVar2,7);
  }
  if ((((*(int *)(this + 0x284) != 0) &&
       (iVar1 = *(int *)(*(int *)(this + 0x284) + 0x30), iVar1 != 0)) &&
      (iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0)) &&
     (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    unaff_retaddr = (CSystemFid *)&DAT_00000007;
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x284) + 0x30) + 0x58),
               pCVar2,7);
  }
  if (((*(int *)(this + 0x288) != 0) &&
      (iVar1 = *(int *)(*(int *)(this + 0x288) + 0x30), iVar1 != 0)) &&
     ((iVar1 = *(int *)(iVar1 + 0x58), iVar1 != 0 &&
      (pCVar2 = *(CSystemFid **)(iVar1 + 8), pCVar2 != (CSystemFid *)0x0)))) {
    pCVar2 = CSystemFid::ParametrizedGetLoadableFid(pCVar2,unaff_retaddr);
    CSystemArchiveNod::LoadFromFid<class_CPlugSound>
              ((CMwNodRef<class_CPlugSound> *)(*(int *)(*(int *)(this + 0x288) + 0x30) + 0x58),
               pCVar2,7);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::RemoveEnvironments
// =================================================
void __thiscall CSceneVehicle::RemoveEnvironments(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CSceneVehicle *pCVar1;
  CMwNod *unaff_EDI;
  int iVar2;
  
  pCVar1 = this + 0x28c;
  iVar2 = 2;
  do {
    if (*(CMwNod **)pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pCVar1,unaff_EDI);
      *(undefined4 *)pCVar1 = 0;
    }
    pCVar1 = pCVar1 + 0xc;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  ResetEnvironmentCacheTrees(this,param_1);
  return;
}
}

// =================================================
// Function: CSceneVehicle::ResetEnvironmentCacheTrees
// =================================================
void __thiscall
CSceneVehicle::ResetEnvironmentCacheTrees(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CPlugVisual *this_00;
  CPlugTree *pCVar1;
  SCasterCat *pSVar2;
  CPlugShader *this_01;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar3;
  CPlugMaterial *this_02;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBX;
  CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  int iVar5;
  CFastBuffer<class_CSystemFidsFolder*> *unaff_ESI;
  CSceneVehicle *this_03;
  void *this_04;
  SVolatileTreePointer *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CMwNod *in_stack_ffffffa0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffa4;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffa8;
  SVolatileTreePointer *pSVar7;
  ulong uVar8;
  CMwNod *pCVar9;
  CIteratorMaterial *pCVar10;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar11;
  CSceneMobil *in_stack_ffffffc4;
  CSceneVehicle *local_34;
  CPlugMaterial *local_30;
  CSceneVehicle *local_2c;
  int iStack_28;
  undefined4 uStack_24;
  CSceneVehicle *local_20;
  ulong local_1c [3];
  void *local_10;
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00acd0d0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_34 = this + 0x2ac;
  pSVar7 = (SVolatileTreePointer *)0x7ccb4c;
  local_2c = this;
  CFastBufferCat<char,struct_SFastCat>::RemoveAll
            (local_34,(CFastBufferCat<char,struct_SFastCat> *)
                      (DAT_00cca150 ^ (uint)&stack0xffffffb4));
  if ((*(int *)(this + 0x28c) != 0) && (*(int *)(this + 0x298) != 0)) {
    pCVar9 = (CMwNod *)0x7ccb6e;
    pCVar1 = CSceneMobil::GetTree((CSceneMobil *)this,unaff_EDI);
    if (pCVar1 != (CPlugTree *)0x0) {
      this_03 = this + 0x290;
      local_34 = (CSceneVehicle *)0x0;
      local_30 = (CPlugMaterial *)0x2;
      local_20 = this_03;
      do {
        unaff_ESI = (CFastBuffer<class_CSystemFidsFolder*> *)
                    CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(*(int *)(this_03 + -4) + 0x18),
                               (CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
        pCVar11 = (CFastBuffer<class_CPlugFileGPUV*> *)0x7ccba3;
        CFastArray<class_CMwNodRef<class_CPlugShader>_>::SetCount
                  (this_03,unaff_ESI,(ulong)unaff_EBP);
        unaff_EBP = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)0x7ccbaa;
        local_1c[0] = CFastBuffer<class_CCrystalFace*>::GetCount
                                (this_03,(CFastBuffer<class_CCrystalFace*> *)unaff_EBX);
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        if (local_1c[0] != 0) {
          do {
            this = (CSceneVehicle *)in_stack_ffffffc4;
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               ((void *)(*(int *)(this_03 + -4) + 0x18),pCVar6,
                                (ulong)in_stack_ffffffa0);
            this_01 = CPlugMaterial::GetSupportedShader
                                (*(CPlugMaterial **)pSVar2,(CPlugMaterial *)in_stack_ffffffa4);
            in_stack_ffffffa0 = (CMwNod *)0x7ccbd1;
            in_stack_ffffffa4 = pCVar6;
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (this_03,pCVar6,(ulong)in_stack_ffffffa8);
            if (this_01 != *(CPlugShader **)pSVar2) {
              if (this_01 != (CPlugShader *)0x0) {
                in_stack_ffffffa8 = (CFastBuffer<class_CCrystalFace*> *)0x7ccbe2;
                CMwNod::MwAddRef((CMwNod *)this_01,in_stack_ffffffa0);
              }
              if (*(CMwNod **)pSVar2 != (CMwNod *)0x0) {
                pSVar7 = (SVolatileTreePointer *)0x7ccbed;
                CMwNod::MwRelease(*(CMwNod **)pSVar2,pCVar9);
              }
              *(CPlugShader **)pSVar2 = this_01;
            }
            pCVar6 = pCVar6 + 1;
            in_stack_ffffffc4 = (CSceneMobil *)this;
          } while (pCVar6 < unaff_EBX);
        }
        pCVar3 = (CFastBuffer<class_CSystemFidsFolder*> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (this_03,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffa0);
        if (unaff_ESI < pCVar3) {
          in_stack_ffffffa0 = (CMwNod *)0x7ccc12;
          unaff_EBP = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)
                      CFastBuffer<class_CCrystalFace*>::GetCount(this_03,in_stack_ffffffa8);
        }
        this_03 = this_03 + 0xc;
        unaff_EBX = unaff_EBX + -1;
      } while (unaff_EBX != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0);
      CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
                (in_stack_ffffffc4,
                 (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
                  *)unaff_EBP,(ulong)in_stack_ffffffa8);
      pCVar1 = CSceneMobil::GetTree((CSceneMobil *)this,pSVar7);
      CPlugTree::CIteratorMaterial::CIteratorMaterial
                (&local_20,(CIteratorMaterial *)pCVar1,(CPlugTree *)0x0,(EMode)pCVar9);
      iStack_28 = *(int *)(this + 0x28c) + 0x18;
      local_2c = (CSceneVehicle *)(*(int *)(this + 0x298) + 0x18);
      while (local_10 != (void *)0x0) {
        pCVar10 = (CIteratorMaterial *)&local_34;
        uVar8 = 0x7ccc8b;
        this_02 = CPlugTree::CIteratorMaterial::GetNextMaterial
                            (local_1c,pCVar10,(CPlugTree **)pCVar11);
        pCVar9 = (CMwNod *)0x0;
        if (this_02 != (CPlugMaterial *)0x0) {
          CMwNod::MwAddRef((CMwNod *)this_02,(CMwNod *)unaff_ESI);
          pCVar9 = (CMwNod *)this_02;
          local_30 = this_02;
        }
        pCVar11 = (CFastBuffer<class_CPlugFileGPUV*> *)0x7cccac;
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastArray<class_CGameMenuFrame*>::Find
                           (local_20,(CFastArray<class_GxTexCoordSet> *)&local_30,
                            (GxTexCoordSet *)unaff_EBP);
        unaff_EBP = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)&local_2c
        ;
        unaff_ESI = (CFastBuffer<class_CSystemFidsFolder*> *)0x7cccbc;
        pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastArray<class_CGameMenuFrame*>::Find
                           (local_20,(CFastArray<class_GxTexCoordSet> *)unaff_EBP,
                            (GxTexCoordSet *)unaff_EBX);
        if ((pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) &&
           (pCVar6 = pCVar4, pCVar4 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)
           ) {
joined_r0x007cccfc:
          if (pCVar9 != (CMwNod *)0x0) {
            CMwNod::MwRelease(pCVar9,(CMwNod *)pCVar11);
          }
        }
        else {
          unaff_EBP = (CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)
                      &uStack_24;
          unaff_ESI = (CFastBuffer<class_CSystemFidsFolder*> *)0x7ccce7;
          unaff_EBX = pCVar6;
          CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
                    (local_20,unaff_EBP,(CHmsCorpus **)pCVar6,(ulong)in_stack_ffffffc4);
          this_00 = *(CPlugVisual **)(local_20 + 0x90);
          if (this_00 == (CPlugVisual *)0x0) goto joined_r0x007cccfc;
          iVar5 = 2;
          this_04 = local_10;
          do {
            pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_04,pCVar6,uVar8)
            ;
            uStack_24 = *(undefined4 *)pSVar2;
            uVar8 = 0;
            CPlugVisual::UpdateVisualFromShaderRequirement
                      (this_00,(CPlugVisual *)&uStack_24,(CPlugShader **)0x0,(CPlugShader *)pCVar10)
            ;
            this_04 = (void *)((int)this_04 + 0xc);
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(local_1c,pCVar11);
    }
  }
  ExceptionList = local_4;
  return;
}
}

// =================================================
// Function: CSceneVehicle::RetrieveLoadedLinkedSounds
// =================================================
void __thiscall
CSceneVehicle::RetrieveLoadedLinkedSounds(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  SLoadedLight *pSVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmFrustumIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  void *unaff_retaddr;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x254,unaff_ESI);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,unaff_EBP);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x38,pCVar6,(ulong)unaff_EDI);
      piVar1 = *(int **)(*(int *)pSVar3 + 0x18);
      if (piVar1 != (int *)0x0) {
        unaff_EDI = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xa00e000;
        iVar4 = (**(code **)(*piVar1 + 0x10))();
        if ((iVar4 != 0) && (iVar4 = *(int *)(*(int *)(piVar1[0xc] + 0x58) + 0x18), iVar4 != 0)) {
          pSVar5 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                             (unaff_retaddr,unaff_EDI);
          *(int **)(pSVar5 + 4) = piVar1;
          *(undefined4 *)pSVar5 = *(undefined4 *)(iVar4 + 8);
        }
      }
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::RetrieveSounds
// =================================================
void __thiscall CSceneVehicle::RetrieveSounds(CSceneVehicle *this,CSceneToyBoat *param_1)
{
{
  CMwId CVar1;
  CMwId *pCVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  CFastStringInt *unaff_ESI;
  CFastStringInt *unaff_EDI;
  CMwId *pCVar3;
  CFastStringInt *pCVar4;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined1 *puStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  CMwId *in_stack_ffffffec;
  CMwId *in_stack_fffffff0;
  CMwId *pCVar5;
  CMwId *pCVar6;
  CMwId *pCVar7;
  
  pCVar6 = (CMwId *)&LAB_00accd28;
  pCVar2 = (CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffe4);
  pCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CVar1 = CMwId::CreateFromLocalName(&stack0xffffffec);
  pCVar7 = (CMwId *)0x0;
  InternalSoundRetrieve
            (this,this + 0x260,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var,CVar1),
             pCVar2);
  OnAccessViolation_ConcatToCrashFileName(unaff_EDI);
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffff0);
  pCVar2 = (CMwId *)0x1;
  InternalSoundRetrieve
            (this,this + 0x264,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_00,CVar1)
             ,(CMwId *)unaff_EDI);
  param_1 = (CSceneToyBoat *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffff4);
  param_1 = (CSceneToyBoat *)0x2;
  InternalSoundRetrieve
            (this,this + 0x268,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_01,CVar1)
             ,(CMwId *)unaff_ESI);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffec);
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffff8);
  pCVar3 = (CMwId *)0x3;
  InternalSoundRetrieve
            (this,this + 0x26c,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_02,CVar1)
             ,in_stack_ffffffec);
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_fffffff0);
  CVar1 = CMwId::CreateFromLocalName(&stack0xfffffffc);
  pCVar4 = (CFastStringInt *)&DAT_00000004;
  InternalSoundRetrieve
            (this,this + 0x270,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_03,CVar1)
             ,in_stack_fffffff0);
  uStack00000010 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar5);
  CVar1 = CMwId::CreateFromLocalName(&stack0x00000000);
  uStack00000010 = 5;
  InternalSoundRetrieve
            (this,this + 0x274,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_04,CVar1)
             ,pCVar5);
  uStack00000014 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar6);
  CVar1 = CMwId::CreateFromLocalName((char *)&param_1);
  uStack00000014 = 6;
  InternalSoundRetrieve
            (this,this + 0x278,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_05,CVar1)
             ,pCVar6);
  uStack00000018 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar7);
  CVar1 = CMwId::CreateFromLocalName(&stack0x00000008);
  uStack00000018 = 7;
  InternalSoundRetrieve
            (this,this + 0x27c,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_06,CVar1)
             ,pCVar7);
  uStack0000001c = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar2);
  CVar1 = CMwId::CreateFromLocalName(&stack0x0000000c);
  uStack0000001c = 8;
  InternalSoundRetrieve
            (this,this + 0x280,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_07,CVar1)
             ,pCVar2);
  puStack00000020 = (undefined1 *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)param_1);
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000010);
  puStack00000020 = &DAT_00000009;
  InternalSoundRetrieve
            (this,this + 0x284,(CMwNodRef<class_CSceneSoundSource> *)CONCAT31(extraout_var_08,CVar1)
             ,(CMwId *)param_1);
  uStack00000024 = 0xffffffff;
  param_1 = (CSceneToyBoat *)0x7ca046;
  OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar3);
  param_1 = (CSceneToyBoat *)0xb9f258;
  CVar1 = CMwId::CreateFromLocalName((char *)&stack0x00000018);
  param_1 = (CSceneToyBoat *)CONCAT31(extraout_var_09,CVar1);
  uStack00000024 = 10;
  InternalSoundRetrieve(this,this + 0x288,(CMwNodRef<class_CSceneSoundSource> *)param_1,pCVar3);
  uStack00000028 = 0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(pCVar4);
  ExceptionList = puStack00000020;
  return;
}
}

// =================================================
// Function: CSceneVehicle::SetIsUpdateAsync
// =================================================
void __thiscall
CSceneVehicle::SetIsUpdateAsync(CSceneVehicle *this,CSceneVehicle *param_1,int param_2)
{
{
  if (*(CSceneVehicle **)(this + 0x4c) != param_1) {
    *(CSceneVehicle **)(this + 0x4c) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SetQuality
// =================================================
void __thiscall
CSceneVehicle::SetQuality(CSceneVehicle *this,CPlugTreeVisualMip *param_1,ulong param_2)
{
{
  CSceneVehicle *unaff_ESI;
  
  *(CPlugTreeVisualMip **)(this + 0xa4) = param_1;
  (**(code **)(*(int *)this + 0x184))();
  StartVehicleSounds(this,unaff_ESI);
  return;
}
}

// =================================================
// Function: CSceneVehicle::SetSolid
// =================================================
void __thiscall
CSceneVehicle::SetSolid(CSceneVehicle *this,CSceneToyMotorbike *param_1,CPlugSolid *param_2)
{
{
  CPlugSolid *unaff_ESI;
  
  CSceneMobil::SetSolid((CSceneMobil *)this,param_1,unaff_ESI);
  if (*(int *)(this + 0xa0) != 0) {
    (**(code **)(*(int *)this + 0x184))();
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::Show
// =================================================
void __thiscall CSceneVehicle::Show(CSceneVehicle *this,CSceneToyMotorbike *param_1)
{
{
  int *piVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  int unaff_ESI;
  CSceneToyMotorbike *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *pCVar6;
  ulong uVar7;
  
  CSceneMobil::Show((CSceneMobil *)this,unaff_EDI);
  SetIsUpdateAsync(this,(CSceneVehicle *)0x1,unaff_ESI);
  uVar7 = 1;
  pCVar6 = (CFastBuffer<class_CCrystalFace*> *)0x1;
  (**(code **)(*(int *)this + 0x10c))();
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x38,pCVar6);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this + 0x38,pCVar5,uVar7);
      piVar1 = *(int **)(*(int *)pSVar3 + 0x18);
      if (piVar1 != (int *)0x0) {
        uVar7 = 0xa011000;
        iVar4 = (**(code **)(*piVar1 + 0x10))();
        if (iVar4 != 0) {
          (**(code **)(*piVar1 + 0x100))();
        }
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SoundEnableSet
// =================================================
void __thiscall
CSceneVehicle::SoundEnableSet(CSceneVehicle *this,CSceneVehicle *param_1,int param_2,ulong param_3)
{
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  CSceneVehicle *unaff_ESI;
  
  uVar1 = *(uint *)(this + 0x7c);
  if (param_1 == (CSceneVehicle *)0x0) {
    uVar2 = uVar1 | param_2;
  }
  else {
    uVar2 = uVar1 & ~param_2;
  }
  if (uVar1 != uVar2) {
    *(uint *)(this + 0x7c) = uVar2;
    iVar3 = (**(code **)(*(int *)this + 0x78))();
    if (iVar3 != 0) {
      if (*(int *)(this + 0x7c) == 0) {
        StartVehicleSounds(this,unaff_ESI);
        return;
      }
      StopAllVehicleSounds(this,unaff_ESI);
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::StartVehicleSounds
// =================================================
void __thiscall CSceneVehicle::StartVehicleSounds(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  int iVar1;
  CSceneSoundSource *unaff_ESI;
  CPlugFileVideo *unaff_retaddr;
  int in_stack_00000008;
  ulong in_stack_0000000c;
  CPlugFileVideo *in_stack_00000010;
  EPlugVideoTimer in_stack_00000014;
  CPlugFileVideo *in_stack_00000018;
  EPlugVideoTimer in_stack_0000001c;
  int in_stack_00000020;
  ulong in_stack_00000024;
  
  if (*(CSceneSoundSource **)(this + 0x268) != (CSceneSoundSource *)0x0) {
    iVar1 = CSceneSoundSource::GetIsPlaying(*(CSceneSoundSource **)(this + 0x268),unaff_ESI);
    if (iVar1 == 0) {
      CSceneSoundSource::SetVolume
                (*(CSceneSoundSource **)(this + 0x268),(CSceneSoundSource *)0x0,(float)unaff_retaddr
                );
    }
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x268),unaff_retaddr,(EPlugVideoTimer)param_1,
               in_stack_00000008,in_stack_0000000c);
  }
  if (*(CSceneSoundSource **)(this + 0x278) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x278),in_stack_00000010,in_stack_00000014,
               (int)in_stack_00000018,in_stack_0000001c);
  }
  if (*(CSceneSoundSource **)(this + 0x264) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x264),in_stack_00000010,in_stack_00000014,
               (int)in_stack_00000018,in_stack_0000001c);
  }
  if (*(CSceneSoundSource **)(this + 0x270) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x270),in_stack_00000018,in_stack_0000001c,
               in_stack_00000020,in_stack_00000024);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::StopAllVehicleSounds
// =================================================
void __thiscall CSceneVehicle::StopAllVehicleSounds(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  STmRaceLowFps *unaff_ESI;
  STmRaceLowFps *unaff_retaddr;
  STmRaceLowFps *in_stack_00000008;
  
  if (*(CSceneSoundSource **)(this + 0x260) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x260),unaff_ESI);
  }
  if (*(CSceneSoundSource **)(this + 0x264) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x264),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x268) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x268),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x26c) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x26c),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x270) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x270),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x274) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x274),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x278) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x278),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x27c) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x27c),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x280) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x280),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x284) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x284),unaff_retaddr);
  }
  if (*(CSceneSoundSource **)(this + 0x288) != (CSceneSoundSource *)0x0) {
    CSceneSoundSource::Stop(*(CSceneSoundSource **)(this + 0x288),in_stack_00000008);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::TuningsSet
// =================================================
void __thiscall
CSceneVehicle::TuningsSet
          (CSceneVehicle *this,CSceneToyCharacter *param_1,CSceneToyCharacterTunings *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CSceneToyCharacter **)(this + 100)) {
    if (param_1 != (CSceneToyCharacter *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 100) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 100),unaff_ESI);
    }
    *(CSceneToyCharacter **)(this + 100) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::UpdateEvent
// =================================================
int __thiscall
CSceneVehicle::UpdateEvent
          (CSceneVehicle *this,CSceneVehicle *param_1,EVehicleEvent param_2,ulong param_3)
{
{
  EVehicleEvent EVar1;
  
  if (*(int *)(this + (int)param_1 * 8 + 0xac) == 0) {
    *(undefined4 *)(this + (int)param_1 * 8 + 0xac) = 1;
    *(EVehicleEvent *)(this + (int)param_1 * 8 + 0xb0) = param_2;
  }
  else {
    EVar1 = *(EVehicleEvent *)(this + (int)param_1 * 8 + 0xb0);
    *(EVehicleEvent *)(this + (int)param_1 * 8 + 0xb0) = param_2;
    if (EVar1 != param_2) {
      return 1;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicle::VehicleAsyncWorldSpeedGet
// =================================================
void __thiscall
CSceneVehicle::VehicleAsyncWorldSpeedGet(CSceneVehicle *this,CSceneVehicle *param_1,GmVec3 *param_2)
{
{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleCurrentEnvironmentSet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneVehicle::VehicleCurrentEnvironmentSet
          (CSceneVehicle *this,CSceneVehicle *param_1,int param_2,float param_3)
{
{
  CPlugShader *this_00;
  CSceneLight *this_01;
  CMwId CVar1;
  CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *pCVar2;
  int iVar3;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  ulong uVar6;
  undefined3 extraout_var;
  GmVec4 *pGVar7;
  undefined3 extraout_var_00;
  int iVar8;
  ESceneLight EVar9;
  EPlugGpuPipeline *unaff_EBX;
  CPlugShader *unaff_EBP;
  CPlugShader *unaff_ESI;
  CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  CMwId *unaff_EDI;
  CSceneVehicle *this_02;
  float in_stack_00000010;
  undefined4 in_stack_00000014;
  CFastBuffer<class_CCrystalFace*> *pCVar12;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar13;
  CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *in_stack_ffffffcc;
  CSceneVehicle *local_30;
  GmVec4 *pGStack_2c;
  float fStack_28;
  char acStack_1c [4];
  int *piStack_18;
  GmVec4 *pGStack_14;
  CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *pCStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00acce90;
  local_c = ExceptionList;
  pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
           (DAT_00cca150 ^ (uint)&stack0xffffffbc);
  ExceptionList = &local_c;
  iVar3 = (**(code **)(*(int *)this + 0x78))();
  if (((iVar3 != 0) && (*(int *)(this + 0x14) != 0)) &&
     (((param_1 != (CSceneVehicle *)0x0) != 0 || (*(int *)(this + 0x2a8) != 0)))) {
    iVar3 = *(int *)(this + 0x28);
    *(int *)(this + 0x2a4) = param_2;
    *(uint *)(this + 0x2a8) = (uint)(param_1 != (CSceneVehicle *)0x0);
    if ((iVar3 != 0) &&
       (pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar3 + 0x34),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)pCVar2),
       *(int *)pSVar4 != 0)) {
      pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x0;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar3 + 0x34),
                          (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_EDI);
      if (*(int *)(*(int *)pSVar4 + 0x58) != 0) {
        unaff_EDI = (CMwId *)0x0;
        pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x7cae34;
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar3 + 0x34),
                            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_ESI);
        *(undefined4 *)(*(int *)(*(int *)pSVar4 + 0x58) + 0x104) = in_stack_00000014;
      }
    }
    if ((*(int *)(this + 0x28c) != 0) && (*(int *)(this + 0x298) != 0)) {
      if ((param_1 == (CSceneVehicle *)0x0) ||
         (param_1 = (CSceneVehicle *)0x1, (float)param_2 <= _DAT_00b31460)) {
        param_1 = (CSceneVehicle *)0x0;
      }
      local_c = (void *)CFastBuffer<class_CCrystalFace*>::GetCount
                                  (this + 0x2ac,(CFastBuffer<class_CCrystalFace*> *)pCVar2);
      pCVar10 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x0;
      local_30 = (CSceneVehicle *)0x0;
      if (local_c != (void *)0x0) {
        this_02 = this + (uint)(param_1 != (CSceneVehicle *)0x0) * 0xc + 0x290;
        do {
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetParsingCat
                             (this + 0x2ac,pCVar10,1,(ulong)pCVar2);
          pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_02,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar10,
                              (ulong)unaff_EDI);
          this_00 = *(CPlugShader **)pSVar4;
          pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          pCVar2 = pCVar10;
          if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
            do {
              pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x7caef8;
              pSVar4 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::
                       operator[](this + 0x2ac,pCVar11,(ulong)unaff_ESI);
              unaff_EDI = (CMwId *)0x7caf00;
              unaff_ESI = this_00;
              CPlugTree::SetShader(*(CPlugTree **)pSVar4,(CPlugBitmapShader *)this_00,unaff_EBP);
              pCVar11 = pCVar11 + 1;
            } while (pCVar11 < pCVar5);
          }
          if ((param_1 != (CSceneVehicle *)0x0) &&
             (uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                                (this_00 + 0x2c,(CFastBuffer<class_CCrystalFace*> *)pCVar2),
             uVar6 != 0)) {
            CVar1 = CMwId::CreateFromLocalName(acStack_1c);
            pGVar7 = CPlugShader::GetLoadFxValue
                               (this_00,(CPlugShader *)CONCAT31(extraout_var,CVar1),(CMwId *)0x0,
                                (SPlugGpuLoadFx **)0x0,(CPlugShaderPass **)0x0,
                                (EPlugGpuPipeline *)0x0,(ulong *)unaff_EDI);
            OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)unaff_ESI);
            if (pGVar7 != (GmVec4 *)0x0) {
              *(float *)(pGVar7 + 0xc) = 1.0 - in_stack_00000010;
            }
            CVar1 = CMwId::CreateFromLocalName((char *)&pGStack_14);
            pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                     CONCAT31(extraout_var_00,CVar1);
            unaff_EDI = (CMwId *)&pCStack_10;
            param_1 = (CSceneVehicle *)0x1;
            pCVar12 = (CFastBuffer<class_CCrystalFace*> *)0x7caf94;
            pGVar7 = CPlugShader::GetLoadFxValue
                               (this_00,(CPlugShader *)pCVar2,unaff_EDI,(SPlugGpuLoadFx **)unaff_ESI
                                ,(CPlugShaderPass **)unaff_EBP,unaff_EBX,(ulong *)in_stack_ffffffcc)
            ;
            in_stack_ffffffcc =
                 (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x7cafa7;
            pGStack_14 = pGVar7;
            OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)pCVar2);
            if (pGVar7 != (GmVec4 *)0x0) {
              param_1 = _DAT_00000000;
              pCStack_10 = _DAT_00b36144;
              in_stack_ffffffcc =
                   (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)0x7cafce;
              iVar3 = (**(code **)(*piStack_18 + 0x78))();
              pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                       CFastBuffer<class_CCrystalFace*>::GetCount
                                 ((void *)(*(int *)(iVar3 + 0x14) + 0x20),pCVar12);
              pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              if (pCVar5 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                do {
                  pCVar13 = pCVar11;
                  pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                     ((void *)(*(int *)(iVar3 + 0x14) + 0x20),pCVar11,(ulong)pCVar2)
                  ;
                  this_01 = *(CSceneLight **)pSVar4;
                  pCVar2 = (CFastBufferCat<struct_CInputPort::SMappedAction,struct_SFastCat> *)
                           0x7caffa;
                  iVar8 = (**(code **)(*(int *)this_01 + 0x78))();
                  pGVar7 = pGStack_2c;
                  if ((iVar8 == iVar3) &&
                     (EVar9 = CSceneLight::GetKindLight(this_01,(CSceneLight *)pCVar13), EVar9 == 0)
                     ) {
                    fStack_28 = *(float *)(*(int *)(*(int *)(this_01 + 0x30) + 0x88) + 0x24) *
                                *(float *)(*(int *)(*(int *)(this_01 + 0x30) + 0x88) + 0x18);
                    break;
                  }
                  pCVar11 = pCVar11 + 1;
                } while (pCVar11 < pCVar5);
              }
              pGStack_14 = (GmVec4 *)(fStack_28 + (float)param_2 * ((float)pGStack_14 - fStack_28));
              *(GmVec4 **)pGVar7 = pGStack_14;
              *(GmVec4 **)(pGVar7 + 4) = pGStack_14;
              *(GmVec4 **)(pGVar7 + 8) = pGStack_14;
              *(float *)(pGVar7 + 0xc) = 1.0;
            }
          }
          pCVar10 = in_stack_ffffffcc + 1;
          this = local_30;
          in_stack_ffffffcc = pCVar10;
        } while (pCVar10 < pCStack_10);
      }
    }
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleHelperNameGet
// =================================================
CSceneMobil * __thiscall
CSceneVehicle::VehicleHelperNameGet(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  return *(CSceneMobil **)(this + 0x2d0);
}
}

// =================================================
// Function: CSceneVehicle::VehicleHelperNameSet
// =================================================
void __thiscall
CSceneVehicle::VehicleHelperNameSet(CSceneVehicle *this,CSceneVehicle *param_1,CSceneMobil *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CSceneVehicle **)(this + 0x2d0)) {
    if (param_1 != (CSceneVehicle *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x2d0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2d0),unaff_ESI);
    }
    *(CSceneVehicle **)(this + 0x2d0) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleHorn
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicle::VehicleHorn(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CPlugFileSnd *this_00;
  int iVar1;
  int iVar2;
  CPlugSound *pCVar3;
  CSceneSoundSource *unaff_ESI;
  CSceneMobil *unaff_EDI;
  float fVar4;
  CPlugFileSnd *unaff_retaddr;
  CPlugFileVideo *in_stack_00000010;
  EPlugVideoTimer in_stack_00000014;
  int in_stack_00000018;
  ulong in_stack_0000001c;
  
  iVar1 = CSceneMobil::IsZombie((CSceneMobil *)this,unaff_EDI);
  if ((iVar1 != 0) && (iVar2 = (**(code **)(*(int *)this + 0x108))(), iVar2 == 0)) {
    return;
  }
  if (DAT_00d06e04 == 0) {
    if (*(int *)(this + 0x94) == 0) {
      return;
    }
    *(int *)(this + 0x94) = *(int *)(this + 0x94) + -1;
  }
  if (iVar1 == 0) {
    *(int *)(this + 0xb0) = *(int *)(this + 0xb0) + 1;
  }
  if ((((*(int *)(this + 0x7c) == 0) &&
       (*(CSceneSoundSource **)(this + 0x260) != (CSceneSoundSource *)0x0)) &&
      (pCVar3 = CSceneSoundSource::GetPlugSound(*(CSceneSoundSource **)(this + 0x260),unaff_ESI),
      pCVar3 != (CPlugSound *)0x0)) &&
     (((this_00 = *(CPlugFileSnd **)(pCVar3 + 0x18), this_00 != (CPlugFileSnd *)0x0 &&
       (*(short *)(this_00 + 0x16) == 1)) &&
      (fVar4 = CPlugFileSnd::GetLength(this_00,unaff_retaddr),
      fVar4 < _DAT_00b36194 != (fVar4 == _DAT_00b36194))))) {
    CSceneSoundSource::Play
              (*(CSceneSoundSource **)(this + 0x260),in_stack_00000010,in_stack_00000014,
               in_stack_00000018,in_stack_0000001c);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleInitFromSolid
// =================================================
void __thiscall CSceneVehicle::VehicleInitFromSolid(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CLoadGeomDynaSprite *pCVar1;
  CSceneVehicleStruct *this_00;
  int *piVar2;
  CPlugTree *pCVar3;
  CPlugShader *pCVar4;
  CPlugBitmapRender *this_01;
  CPlugBitmapAddress *pCVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  CFastBuffer<class_GxVertex2> *pCVar8;
  CLoadGeomDynaSprite *pCVar9;
  SCasterCat *pSVar10;
  CPlugVisualSprite *pCVar11;
  int iVar12;
  SCasterCat *pSVar13;
  CMwNod *unaff_EBX;
  EMode unaff_EBP;
  SVolatileTreePointer *unaff_ESI;
  CMwNod *unaff_EDI;
  float10 fVar14;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar15;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar16;
  SCasterCat *pSStack0000000c;
  CSceneVehicle *in_stack_00000010;
  SCasterCat *in_stack_00000014;
  SPlugFaceCull SStack00000018;
  undefined3 uStack00000019;
  void *in_stack_0000001c;
  float in_stack_00000020;
  float in_stack_00000034;
  float in_stack_00000040;
  void *in_stack_00000058;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  SVolatileTreePointer *in_stack_ffffffa0;
  CSceneVehicle *pCVar17;
  CPlugShader *in_stack_ffffffa8;
  CFastString *in_stack_ffffffac;
  ulong in_stack_ffffffb0;
  CVisionViewportDx9 *in_stack_ffffffb4;
  ESpriteColor0 *in_stack_ffffffb8;
  CVisionViewportDx9 *in_stack_ffffffbc;
  ESpriteColor0 *in_stack_ffffffc0;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffc4;
  ulong in_stack_ffffffc8;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffcc;
  ulong in_stack_ffffffd4;
  SPlugFaceCull *pSVar18;
  CLoadGeomDynaSprite *in_stack_ffffffd8;
  SPlugFaceCull *pSVar19;
  SVisualHandler *in_stack_ffffffdc;
  CLoadGeomDynaSprite *in_stack_ffffffe0;
  CPlugVisualSprite *in_stack_ffffffe4;
  CLoadGeomDynaSprite *pCVar20;
  CLoadGeomDynaSprite *in_stack_ffffffe8;
  CPlugVisualSprite *in_stack_ffffffec;
  SCasterCat *in_stack_fffffff0;
  SCasterCat *pSVar21;
  CPlugVisualSprite *pCVar22;
  ESpriteColor0 *pEVar23;
  SCasterCat *pSVar24;
  SVisualHandler *this_02;
  
  this_02 = (SVisualHandler *)0xffffffff;
  pSVar24 = (SCasterCat *)&LAB_00acd2d8;
  if (*(int *)(this + 0x60) != 0) {
    pCVar1 = *(CLoadGeomDynaSprite **)(*(int *)(this + 0x28) + 0x14);
    pEVar23 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    pCVar17 = this;
    ResetEnvironmentCacheTrees(this,(CSceneVehicle *)(DAT_00cca150 ^ (uint)&stack0xffffff90));
    if (*(CMwNod **)(this + 0x2d8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x2d8),unaff_EDI);
      *(undefined4 *)(this + 0x2d8) = 0;
    }
    pCVar3 = CSceneMobil::GetTree((CSceneMobil *)this,unaff_ESI);
    CPlugTree::CIteratorShader::CIteratorShader
              (&stack0xffffffd4,(CIteratorShader *)pCVar3,(CPlugTree *)0x0,unaff_EBP);
    pSStack0000000c = (SCasterCat *)0x0;
    do {
      if (in_stack_ffffffe4 == (CPlugVisualSprite *)0x0) goto LAB_007cd300;
      pCVar4 = CPlugTree::CIteratorShader::GetNextShader
                         (&stack0xffffffd8,(CIteratorShader *)0x0,(CPlugTree **)unaff_EBX);
      unaff_EBX = (CMwNod *)0x0;
      this_01 = CPlugShader::FindBitmapRenderByClassId
                          (pCVar4,(CPlugShader *)0x9021000,0,(CPlugBitmap **)0x0,
                           (CPlugBitmapAddress **)in_stack_ffffffa0);
      in_stack_ffffffe4 = in_stack_ffffffec;
    } while (this_01 == (CPlugBitmapRender *)0x0);
    if (this_01 != *(CPlugBitmapRender **)(this + 0x2d8)) {
      in_stack_ffffffa0 = (SVolatileTreePointer *)0x7cd2eb;
      CMwNod::MwAddRef((CMwNod *)this_01,unaff_EBX);
      if (*(CMwNod **)(this + 0x2d8) != (CMwNod *)0x0) {
        pCVar17 = (CSceneVehicle *)0x7cd2fa;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x2d8),unaff_EBX);
      }
      *(CPlugBitmapRender **)(this + 0x2d8) = this_01;
    }
LAB_007cd300:
    pSStack0000000c = (SCasterCat *)0xffffffff;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&stack0xffffffd8,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EBX);
    *(undefined4 *)(this + 0x2dc) = 0;
    pCVar3 = CSceneMobil::GetTree((CSceneMobil *)this,in_stack_ffffffa0);
    CPlugTree::CIteratorShader::CIteratorShader
              (&stack0xffffffe0,(CIteratorShader *)pCVar3,(CPlugTree *)0x0,(EMode)pCVar17);
    _SStack00000018 = 1.4013e-45;
    CMwId::CreateFromLocalName(&stack0xffffffc4);
    SStack00000018 = (SPlugFaceCull)0x2;
    pSVar7 = in_stack_fffffff0;
    do {
      if (pSVar7 == (SCasterCat *)0x0) goto LAB_007cd37c;
      pCVar4 = CPlugTree::CIteratorShader::GetNextShader
                         (&stack0xffffffe4,(CIteratorShader *)0x0,(CPlugTree **)in_stack_ffffffa8);
      in_stack_ffffffa8 = (CPlugShader *)&stack0xffffffc8;
      pCVar5 = CPlugShader::FindLayerByName(pCVar4,in_stack_ffffffa8,in_stack_ffffffac);
      pSVar7 = pSVar24;
    } while (pCVar5 == (CPlugBitmapAddress *)0x0);
    *(undefined4 *)(this + 0x2dc) = 1;
LAB_007cd37c:
    _SStack00000018 = (float)CONCAT31(uStack00000019,1);
    OnAccessViolation_ConcatToCrashFileName((CFastStringInt *)in_stack_ffffffa8);
    _SStack00000018 = -NAN;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
              (&stack0xffffffe4,(CFastBuffer<class_CPlugFileGPUV*> *)in_stack_ffffffa8);
    this_00 = *(CSceneVehicleStruct **)(this + 0x60);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CSceneVehicleStruct::GetVisualIndexFromMobilQuality
                       (this_00,*(CSceneVehicleStruct **)(this + 0xa4),
                        (ESceneMobilQuality)in_stack_ffffffac);
    pSVar7 = CFastBuffer<struct_CVisionViewportDx9::SRenderTarget>::operator[]
                       (this_00 + 0x20,pCVar6,in_stack_ffffffb0);
    pSVar21 = pSVar7;
    SVisualHandler::Init
              (this + 0x104,pCVar1,(CPlugVisualSprite *)(pSVar7 + 0xc),in_stack_ffffffb4,
               in_stack_ffffffb8);
    SVisualHandler::Init
              (this + 0x170,pCVar1,(CPlugVisualSprite *)(pSVar7 + 4),in_stack_ffffffbc,
               in_stack_ffffffc0);
    pCVar8 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(pSVar7 + 0x24,in_stack_ffffffc4);
    CFastBuffer<struct_CSceneVehicle::SVisualWheel>::AllocSetCount
              (this + 0xe0,pCVar8,in_stack_ffffffc8);
    pCVar9 = (CLoadGeomDynaSprite *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xe0,in_stack_ffffffcc);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    pCVar20 = (CLoadGeomDynaSprite *)0x0;
    if (pCVar9 != (CLoadGeomDynaSprite *)0x0) {
      do {
        pSVar7 = CFastBuffer<struct_CSceneVehicle::SVisualWheel>::operator[]
                           (this + 0xe0,pCVar6,(ulong)pSVar21);
        pSVar10 = CFastBuffer<struct_CPlugVisual::SSplit>::operator[]
                            (in_stack_fffffff0 + 0x24,pCVar6,in_stack_ffffffd4);
        pSVar21 = (SCasterCat *)pCVar1;
        SVisualHandler::Init
                  (pSVar7 + 8,pCVar1,(CPlugVisualSprite *)pSVar10,
                   (CVisionViewportDx9 *)in_stack_ffffffd8,(ESpriteColor0 *)in_stack_ffffffdc);
        in_stack_ffffffd4 = 0x7cd437;
        in_stack_ffffffd8 = pCVar1;
        SVisualHandler::Init
                  (pSVar7 + 0xe0,pCVar1,(CPlugVisualSprite *)(pSVar10 + 0x10),
                   (CVisionViewportDx9 *)in_stack_ffffffe0,(ESpriteColor0 *)pCVar9);
        in_stack_ffffffdc = (SVisualHandler *)0x7cd444;
        in_stack_ffffffe0 = pCVar1;
        SVisualHandler::Init
                  (pSVar7 + 0x74,pCVar1,(CPlugVisualSprite *)(pSVar10 + 8),
                   (CVisionViewportDx9 *)in_stack_ffffffe8,(ESpriteColor0 *)in_stack_ffffffec);
        in_stack_ffffffec = (CPlugVisualSprite *)(pSVar10 + 0x18);
        pCVar9 = (CLoadGeomDynaSprite *)0x7cd454;
        in_stack_ffffffe8 = pCVar1;
        SVisualHandler::Init
                  (pSVar7 + 0x14c,pCVar1,in_stack_ffffffec,(CVisionViewportDx9 *)in_stack_fffffff0,
                   pEVar23);
        *(undefined4 *)pSVar7 = *(undefined4 *)(pSVar10 + 0x20);
        pCVar6 = pCVar6 + 1;
        *(undefined4 *)(pSVar7 + 4) = *(undefined4 *)(pSVar10 + 0x24);
        pSVar7 = in_stack_00000014;
        this = in_stack_00000010;
        pCVar20 = pCVar9;
      } while (pCVar6 < pSStack0000000c);
    }
    pSVar10 = pSVar7 + 0x30;
    pCVar8 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pSVar10,(CFastBuffer<class_CCrystalFace*> *)pSVar21);
    CFastBuffer<struct_CSceneVehicle::SVisualArm>::AllocSetCount
              (this + 0xd4,pCVar8,in_stack_ffffffd4);
    pCVar11 = (CPlugVisualSprite *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (this + 0xd4,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffd8);
    pSVar21 = (SCasterCat *)0x0;
    if (pCVar11 != (CPlugVisualSprite *)0x0) {
      do {
        this = (CSceneVehicle *)pSVar10;
        pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar21;
        pSVar10 = CFastBuffer<struct_CSceneVehicle::SVisualArm>::operator[]
                            (this_02,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar21,
                             (ulong)in_stack_ffffffdc);
        pSVar7 = CFastArray<class_CCrystalTexCoord>::operator[]
                           (param_1,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar21,
                            (ulong)in_stack_ffffffe0);
        *(undefined4 *)pSVar10 = 0;
        *(undefined4 *)(pSVar10 + 8) = *(undefined4 *)(pSVar7 + 4);
        pSVar21 = pSVar10 + 0x10;
        *(undefined4 *)(pSVar10 + 4) = 1;
        in_stack_ffffffdc = (SVisualHandler *)pCVar1;
        SVisualHandler::Init
                  (pSVar21,pCVar1,(CPlugVisualSprite *)(pSVar7 + 0x1c),(CVisionViewportDx9 *)pCVar20
                   ,(ESpriteColor0 *)in_stack_ffffffe8);
        in_stack_ffffffe0 = (CLoadGeomDynaSprite *)0x7cd4fb;
        pCVar20 = pCVar1;
        SVisualHandler::Init
                  (pSVar10 + 0x7c,pCVar1,(CPlugVisualSprite *)(pSVar7 + 0xc),
                   (CVisionViewportDx9 *)in_stack_ffffffec,(ESpriteColor0 *)pCVar6);
        pCVar22 = (CPlugVisualSprite *)(pSVar7 + 0x14);
        in_stack_ffffffe8 = (CLoadGeomDynaSprite *)0x7cd50b;
        in_stack_ffffffec = (CPlugVisualSprite *)pCVar1;
        SVisualHandler::Init
                  (pSVar10 + 0xe8,pCVar1,pCVar22,(CVisionViewportDx9 *)this,(ESpriteColor0 *)pSVar24
                  );
        *(undefined4 *)(pSVar10 + 0xc) = *(undefined4 *)(pSVar7 + 8);
        pSVar7 = (SCasterCat *)0x7cd518;
        iVar12 = SVisualHandler::IsInit(pSVar21,this_02);
        if (iVar12 != 0) {
          this_02 = (SVisualHandler *)0x7cd528;
          iVar12 = SVisualHandler::IsInit(pSVar10 + 0x7c,in_stack_ffffffdc);
          if ((iVar12 != 0) &&
             (iVar12 = SVisualHandler::IsInit(pSVar10 + 0xe8,in_stack_ffffffdc), iVar12 != 0)) {
            iVar12 = *(int *)(*(int *)pSVar21 + 0x90);
            pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar10 + 0x14);
            if (iVar12 != 0) {
              pSVar24 = pSVar10 + 0x154;
              *(float *)pSVar24 = *(float *)(pSVar10 + 0x3c);
              *(undefined4 *)(pSVar10 + 0x158) = *(undefined4 *)(pSVar10 + 0x40);
              *(undefined4 *)(pSVar10 + 0x15c) = *(undefined4 *)(pSVar10 + 0x44);
              if (pCVar6 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
                in_stack_00000060 = *(undefined4 *)(iVar12 + 0x3c);
                in_stack_00000040 = *(float *)(iVar12 + 0x48);
              }
              else {
                pSVar21 = CFastBuffer<struct_CPlugModelMesh::SVertexDataLayer>::operator[]
                                    ((void *)(*(int *)(iVar12 + 0x50) + 0x24),pCVar6,(ulong)pCVar11)
                ;
                in_stack_00000064 = *(undefined4 *)(pSVar21 + 8);
                in_stack_00000040 = *(float *)(pSVar21 + 0x14);
                param_1 = (CSceneVehicle *)pCVar6;
              }
              pSVar19 = (SPlugFaceCull *)(pSVar10 + 0x18);
              _SStack00000018 = 0.0;
              pSVar18 = &stack0x00000018;
              in_stack_0000001c = (void *)0x0;
              pSVar21 = pSVar10 + 0x160;
              in_stack_00000020 = in_stack_00000040 + in_stack_00000034;
              GmVec3::SetMult(pSVar21,pSVar18,pSVar19,(GmIso4 *)in_stack_ffffffdc);
              _SStack00000018 = *(float *)(pSVar10 + 0x168) - *(float *)(pSVar10 + 0x15c);
              pCVar11 = (CPlugVisualSprite *)
                        (_SStack00000018 * _SStack00000018 +
                        (*(float *)pSVar21 - *(float *)pSVar24) *
                        (*(float *)pSVar21 - *(float *)pSVar24) +
                        (*(float *)(pSVar10 + 0x164) - *(float *)(pSVar10 + 0x158)) *
                        (*(float *)(pSVar10 + 0x164) - *(float *)(pSVar10 + 0x158)));
              in_stack_ffffffdc = (SVisualHandler *)0x7cd609;
              fVar14 = (float10)func_0x009c1b40();
              this_02 = (SVisualHandler *)(float)fVar14;
              *(SVisualHandler **)(pSVar10 + 0x16c) = this_02;
              GmVec3::MultInverse(pSVar21,(GmIso3 *)(pSVar10 + 0xf0),(GmIso3 *)pSVar18);
              GmVec3::MultInverse(pSVar24,(GmIso3 *)(pSVar10 + 0x84),(GmIso3 *)pSVar19);
              *(undefined4 *)pSVar10 = 1;
            }
          }
        }
        pSVar21 = (SCasterCat *)(pCVar22 + 1);
        pSVar10 = (SCasterCat *)this;
        pSVar24 = pSVar7;
      } while (pSVar21 < pCVar11);
    }
    pCVar17 = this + 0xec;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (pCVar17,(GmFrustumIso4 *)in_stack_ffffffdc);
    pSStack0000000c = pSVar7 + 0x3c;
    pCVar8 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pSStack0000000c,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffe0);
    CFastBuffer<struct_CSceneVehicle::SVisualLight>::AllocSetCount(pCVar17,pCVar8,(ulong)pCVar20);
    pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (pCVar17,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffffe8);
    pCVar15 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pCVar16 = pCVar15;
        pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>
                 ::operator[](this + 0xec,pCVar15,(ulong)in_stack_ffffffec);
        pSVar13 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                            (in_stack_0000001c,pCVar15,(ulong)pSVar21);
        in_stack_ffffffec = (CPlugVisualSprite *)pCVar1;
        pSVar21 = pSVar13;
        SVisualHandler::Init
                  (pSVar7,pCVar1,(CPlugVisualSprite *)pSVar13,(CVisionViewportDx9 *)pSVar10,
                   (ESpriteColor0 *)pSVar24);
        *(undefined4 *)(pSVar7 + 0x70) = *(undefined4 *)(pSVar13 + 8);
        *(undefined4 *)(pSVar7 + 0x6c) = 0;
        pSVar24 = (SCasterCat *)0x7cd6cb;
        iVar12 = SVisualHandler::IsInit(pSVar7,this_02);
        if ((iVar12 != 0) && (piVar2 = *(int **)pSVar7, piVar2 != (int *)0x0)) {
          this_02 = (SVisualHandler *)0x9062000;
          pSVar24 = (SCasterCat *)0x7cd6e3;
          iVar12 = (**(code **)(*piVar2 + 0x10))();
          if (iVar12 != 0) {
            *(int *)(pSVar7 + 0x6c) = piVar2[0x2c];
          }
        }
        pCVar15 = pCVar16 + 1;
      } while (pCVar15 < pCVar6);
    }
    VisualEmittersInit(this,(CSceneVehicle *)in_stack_ffffffec);
  }
  ExceptionList = in_stack_00000058;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleInputBrakeSet
// =================================================
void __thiscall
CSceneVehicle::VehicleInputBrakeSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2)
{
{
  *(CSceneVehicleGlider **)(this + 0x54) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleInputGasSet
// =================================================
void __thiscall
CSceneVehicle::VehicleInputGasSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2)
{
{
  *(CSceneVehicleGlider **)(this + 0x50) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleInputSteerGet
// =================================================
float __thiscall
CSceneVehicle::VehicleInputSteerGet(CSceneVehicle *this,CSceneVehicleGlider *param_1)
{
{
  return *(float *)(this + 0x58);
}
}

// =================================================
// Function: CSceneVehicle::VehicleInputSteerSet
// =================================================
void __thiscall
CSceneVehicle::VehicleInputSteerSet(CSceneVehicle *this,CSceneVehicleGlider *param_1,float param_2)
{
{
  *(CSceneVehicleGlider **)(this + 0x58) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleIsNetworkedSet
// =================================================
void __thiscall
CSceneVehicle::VehicleIsNetworkedSet(CSceneVehicle *this,CSceneVehicle *param_1,int param_2)
{
{
  *(CSceneVehicle **)(this + 0x78) = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleReset
// =================================================
void __thiscall CSceneVehicle::VehicleReset(CSceneVehicle *this,CSceneVehicleBall *param_1)
{
{
  CHmsSoundSource *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  GmFrustumIso4 *unaff_EBX;
  GmFrustumIso4 *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  GmSpring<float> *unaff_retaddr;
  CFastBuffer<class_CCrystalFace*> *in_stack_00000008;
  CHmsSoundSource *in_stack_0000000c;
  int in_stack_00000010;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack0000001c;
  CHmsSoundSource *in_stack_00000024;
  CSceneVehicle *pCVar5;
  
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x1f8) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  pCVar5 = this;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xe0,unaff_EDI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_CSceneVehicle::SVisualWheel>::operator[]
                         (this + 0xe0,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = (CFastBuffer<class_CCrystalFace*> *)0x7cb6f2;
      SVisualWheel::Reset(pSVar3,unaff_EBP);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xd4,unaff_ESI);
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar3 = CFastBuffer<struct_CSceneVehicle::SVisualArm>::operator[]
                         (this + 0xd4,pCVar4,(ulong)unaff_EBP);
      unaff_EBP = (GmFrustumIso4 *)0x7cb71f;
      SVisualArm::Reset(pSVar3,unaff_EBX);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  SVisualHandler::Reset(this + 0x104,unaff_EBP);
  SVisualHandler::Reset(this + 0x170,unaff_EBX);
  GmSpring<float>::ClearVals(this + 0x228,(GmSpring<float> *)pCVar5);
  GmSpring<float>::ClearVals(this + 0x214,unaff_retaddr);
  *(undefined4 *)(this + 0x23c) = 0;
  *(undefined4 *)(this + 0x240) = 0;
  CHmsItem::ResetDynamicState(*(CHmsItem **)(this + 0x28),(CHmsItem *)param_1);
  pCStack0000001c =
       (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
       CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xf8,in_stack_00000008);
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack0000001c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0xf8,pCVar2,(ulong)in_stack_0000000c)
      ;
      if (*(CMotionEmitterParticles **)pSVar3 != (CMotionEmitterParticles *)0x0) {
        in_stack_0000000c = (CHmsSoundSource *)0x0;
        CMotionEmitterParticles::SetIsActive
                  (*(CMotionEmitterParticles **)pSVar3,(CSceneObjectLink *)0x0,in_stack_00000010);
        *(undefined4 *)(*(int *)pSVar3 + 0x84) = 1;
      }
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCStack0000001c);
  }
  if ((*(int *)(this + 0x260) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x260) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x264) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x264) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x268) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x268) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x26c) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x26c) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x270) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x270) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x274) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x274) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x278) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x278) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x27c) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x27c) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x280) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x280) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x284) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x284) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_0000000c);
  }
  if ((*(int *)(this + 0x288) != 0) &&
     (pCVar1 = *(CHmsSoundSource **)(*(int *)(this + 0x288) + 0x30),
     pCVar1 != (CHmsSoundSource *)0x0)) {
    CHmsSoundSource::ResetSoundParams(pCVar1,in_stack_00000024);
    return;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::VehicleStateComputeBlendVal
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneVehicle::VehicleStateComputeBlendVal(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  uint uVar1;
  float fVar2;
  float fVar3;
  CMwCmdBufferCore *this_00;
  CMwId *pCVar4;
  int iVar5;
  SMwSchemeTimedProperties *pSVar6;
  CSceneMobil *unaff_ESI;
  uint uVar7;
  CPlugAudio *unaff_EDI;
  float in_stack_00000008;
  CSceneVehicle *pCVar8;
  
  this_00 = *(CMwCmdBufferCore **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CMwCmdBufferCore *)0x0) {
    this_00 = DAT_00d731e0 + 0xa0;
  }
  pCVar8 = this;
  pCVar4 = CPlugAudio::MwGetId((CPlugAudio *)this_00,unaff_EDI);
  uVar7 = *(uint *)pCVar4;
  if (*(int *)(this + 0x78) != 0) {
    if (DAT_00d67524 < uVar7) {
      uVar7 = uVar7 - DAT_00d67524;
    }
    else {
      uVar7 = 0;
    }
  }
  iVar5 = CSceneMobil::IsZombie((CSceneMobil *)this,unaff_ESI);
  if (iVar5 == 0) {
    pSVar6 = CMwCmdBufferCore::GetSchemeProperies
                       (DAT_00d731e0,(CMwCmdBufferCore *)&DAT_0000008c,(ulong)pCVar8);
    uVar1 = *(uint *)pSVar6;
    iVar5 = (uVar7 / uVar1) * uVar1;
    if (iVar5 - uVar7 == 0) {
      in_stack_00000008 = 1.0;
    }
    else {
      iVar5 = uVar7 - iVar5;
      fVar2 = (float)iVar5;
      if (iVar5 < 0) {
        fVar2 = fVar2 + _DAT_00c418d0;
      }
      fVar3 = (float)(int)uVar1;
      if ((int)uVar1 < 0) {
        fVar3 = fVar3 + _DAT_00c418d0;
      }
      in_stack_00000008 = fVar2 / fVar3;
    }
  }
  else {
    iVar5 = *(int *)(*(int *)(this + 0x28) + 0x4c);
    if ((iVar5 == -1) || (iVar5 == *(int *)(*(int *)(this + 0x28) + 0x48))) {
      return 0.0;
    }
  }
  if (in_stack_00000008 < 0.0) {
    return 0.0;
  }
  if (in_stack_00000008 <= 1.0) {
    return in_stack_00000008;
  }
  return 1.0;
}
}

// =================================================
// Function: CSceneVehicle::VehicleUpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicle::VehicleUpdateAsync(CSceneVehicle *this,CSceneVehicleBall *param_1)
{
{
  float fVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  CSceneSoundSource *unaff_ESI;
  CSceneVehicle *pCVar6;
  
  pCVar6 = this;
  if ((*(CSceneSoundSource **)(this + 0x268) != (CSceneSoundSource *)0x0) &&
     (iVar2 = CSceneSoundSource::GetIsPlaying(*(CSceneSoundSource **)(this + 0x268),unaff_ESI),
     iVar2 != 0)) {
    iVar2 = *(int *)(*(int *)(this + 0x268) + 0x30);
    if (ABS(*(float *)(iVar2 + 0x70) - *(float *)(this + 0x90)) < _DAT_00b41d80) {
      fVar1 = *(float *)(this + 0x90);
    }
    else {
      fVar1 = *(float *)(DAT_00d731e0 + 0x80);
      if (fVar1 < 1.0 == (fVar1 == 1.0)) {
        fVar1 = 1.0;
      }
      fVar1 = (*(float *)(this + 0x90) - *(float *)(iVar2 + 0x70)) * (float)_DAT_00b38328 * fVar1 +
              *(float *)(iVar2 + 0x70);
    }
    *(float *)(iVar2 + 0x70) = fVar1;
  }
  if (DAT_00d06e04 == 0) {
    puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)pCVar6);
    uVar4 = *puVar3;
    if (*(uint *)(this + 0x98) <= uVar4) {
      uVar5 = *(uint *)(this + 0x98) + 30000;
      *(uint *)(this + 0x98) = uVar5;
      if (uVar5 < uVar4) {
        *(uint *)(this + 0x98) = uVar4;
      }
      uVar4 = *(int *)(this + 0x94) + 1;
      if (2 < uVar4) {
        uVar4 = 3;
      }
      *(uint *)(this + 0x94) = uVar4;
    }
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::VirtualParam_Add
// =================================================
ulong __thiscall
CSceneVehicle::VirtualParam_Add
          (CSceneVehicle *this,CMwCmdScriptVarClass *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  void *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  iVar4 = iVar1 + -1;
  *(int *)(param_1 + 0x18) = iVar4;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa060007) {
    if (-1 < iVar4) {
      CMwNod::Param_Add(*(CMwNod **)(this + 0x28c),(CMwNod *)param_1,param_2,unaff_ESI);
    }
  }
  else if (iVar2 == 0xa060008) {
    if (-1 < iVar4) {
      CMwNod::Param_Add(*(CMwNod **)(this + 0x298),(CMwNod *)param_1,param_2,unaff_ESI);
      return 0;
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CSceneMobil::VirtualParam_Add((CSceneMobil *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicle::VirtualParam_Get
// =================================================
ulong __thiscall
CSceneVehicle::VirtualParam_Get
          (CSceneVehicle *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  CMwValueStd *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  iVar4 = iVar1 + -1;
  *(int *)(param_1 + 0x18) = iVar4;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa060007) {
    if (iVar4 < 0) {
      *(undefined4 *)param_2 = *(undefined4 *)(this + 0x28c);
      return 0;
    }
    CMwNod::Param_Get(*(CMwNod **)(this + 0x28c),(CMwNod *)param_1,param_2,unaff_ESI);
  }
  else {
    if (iVar2 == 0xa060008) {
      if (iVar4 < 0) {
        *(undefined4 *)param_2 = *(undefined4 *)(this + 0x298);
        return 0;
      }
      CMwNod::Param_Get(*(CMwNod **)(this + 0x298),(CMwNod *)param_1,param_2,unaff_ESI);
      return 0;
    }
    if (iVar2 != -1) {
      *(int *)(param_1 + 0x18) = iVar1;
      uVar3 = CSceneMobil::VirtualParam_Get((CSceneMobil *)this,param_1,param_2,param_3);
      return uVar3;
    }
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicle::VirtualParam_Set
// =================================================
ulong __thiscall
CSceneVehicle::VirtualParam_Set
          (CSceneVehicle *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + iVar2 * 4);
  iVar1 = iVar2 + -1;
  *(int *)(param_1 + 0x18) = iVar1;
  uVar4 = *(uint *)(iVar3 + 4);
  if (uVar4 < 0xa060007) {
    if (uVar4 == 0xa060006) {
      if (iVar1 < 0) {
        if (param_2 != *(CMwStack **)(this + 0x68)) {
          if (param_2 != (CMwStack *)0x0) {
            CMwNod::MwAddRef((CMwNod *)param_2,unaff_EDI);
          }
          if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
            CMwNod::MwRelease(*(CMwNod **)(this + 0x68),unaff_ESI);
          }
          *(CMwStack **)(this + 0x68) = param_2;
          BuildVehicleMaterialsRemap(this,(CSceneVehicle *)unaff_ESI);
          return 0;
        }
      }
      else {
        CMwNod::Param_Set(*(CMwNod **)(this + 0x68),(CMwNod *)param_1,(CFastString *)param_2,
                          (CFastStringInt *)unaff_EDI);
      }
      BuildVehicleMaterialsRemap(this,(CSceneVehicle *)unaff_ESI);
      return 0;
    }
    if (uVar4 == 0xa060001) {
      if ((iVar1 < 0) && (param_2 != (CMwStack *)0x0)) {
        TuningsSet(this,(CSceneToyCharacter *)param_2,(CSceneToyCharacterTunings *)unaff_EDI);
        (**(code **)(*(int *)this + 0x174))();
        return 0;
      }
      CMwParamClass::SetValue((CMwParamClass *)param_2,(CMwCmdAffectParamBool *)(this + 100));
      return 0;
    }
  }
  else if (uVar4 < 0xa06000a) {
    if (uVar4 == 0xa060009) {
      SetIsUpdateAsync(this,*(CSceneVehicle **)param_2,(int)unaff_EDI);
      return 0;
    }
    if (uVar4 == 0xa060007) {
      CMwNodRef<class_CPlugFileGPUP>::ParamSetValue
                (this + 0x28c,(CSysFidNodRef<class_CHmsPackLightMap> *)param_1,param_2,unaff_EDI);
      return 0;
    }
    if (uVar4 == 0xa060008) {
      CMwNodRef<class_CPlugFileGPUP>::ParamSetValue
                (this + 0x298,(CSysFidNodRef<class_CHmsPackLightMap> *)param_1,param_2,unaff_EDI);
      return 0;
    }
  }
  else if (uVar4 == 0xffffffff) {
    return 0;
  }
  *(int *)(param_1 + 0x18) = iVar2;
  uVar5 = CSceneMobil::VirtualParam_Set((CSceneMobil *)this,param_1,param_2,unaff_EDI);
  return uVar5;
}
}

// =================================================
// Function: CSceneVehicle::VirtualParam_Sub
// =================================================
ulong __thiscall
CSceneVehicle::VirtualParam_Sub
          (CSceneVehicle *this,CGameCtnDecorationMood *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  void *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  iVar4 = iVar1 + -1;
  *(int *)(param_1 + 0x18) = iVar4;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0xa060007) {
    if (-1 < iVar4) {
      CMwNod::Param_Sub(*(CMwNod **)(this + 0x28c),(CMwNod *)param_1,param_2,unaff_ESI);
    }
  }
  else if (iVar2 == 0xa060008) {
    if (-1 < iVar4) {
      CMwNod::Param_Sub(*(CMwNod **)(this + 0x298),(CMwNod *)param_1,param_2,unaff_ESI);
      return 0;
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CSceneMobil::VirtualParam_Sub((CSceneMobil *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CSceneVehicle::VisualEmittersInit
// =================================================
void __thiscall CSceneVehicle::VisualEmittersInit(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CSceneVehicle *this_00;
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  int iVar5;
  uint uVar6;
  SLoadedLight *pSVar7;
  CMwNod *extraout_EAX;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar8;
  CMotion *unaff_EBP;
  CMwNod *this_01;
  CMwNod *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneObject *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffffe8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CMwNod *in_stack_ffffffec;
  void *local_c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff;
  pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&LAB_00acd0fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CSceneVehicleStruct::GetVisualIndexFromMobilQuality
            (*(CSceneVehicleStruct **)(this + 0x60),*(CSceneVehicleStruct **)(this + 0xa4),
             (ESceneMobilQuality)((uint)DAT_00cca150 ^ (uint)&stack0xffffffd8));
  this_00 = this + 0xf8;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar8,(ulong)unaff_ESI);
      pCVar9 = *(CSceneObject **)pSVar3;
      if (pCVar9 != (CSceneObject *)0x0) {
        CSceneObject::RemoveMotion((CSceneObject *)this,pCVar9,unaff_EBP);
        unaff_ESI = (CMwNod *)pCVar9;
      }
      if (*(CMwNod **)pSVar3 != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)pSVar3,unaff_ESI);
        *(undefined4 *)pSVar3 = 0;
      }
      pCVar8 = pCVar8 + 1;
    } while (pCVar8 < pCVar2);
  }
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this_00,(GmFrustumIso4 *)unaff_ESI);
  if (*(int *)(this + 0xa8) != -1) {
    local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(*(int *)(this + 0x60) + 0x38),
                         (CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
    pCStack_8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pCVar8 = pCStack_8;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 0x60) + 0x38),pCStack_8,(ulong)unaff_EBX);
        iVar1 = *(int *)pSVar3;
        if (*(int *)(iVar1 + 0x18 + *(int *)(this + 0xa8) * 4) != 0) {
          pCVar10 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar1 + 0x34);
          if (pCVar10 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007cceb8:
            if (*(int *)(iVar1 + 0x30) != -1) {
              uVar6 = (**(code **)(*(int *)this + 0x188))();
              if (uVar6 <= *(uint *)(iVar1 + 0x30)) goto LAB_007ccf8b;
            }
            pSVar7 = CFastBuffer<struct_CSceneVehicle::SVisualEmitter>::AddNewElem
                               (this + 0xf8,unaff_EBX);
            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 4) = pCVar8;
            iVar5 = 0x7cceed;
            param_1 = operator_new(0x90);
            this_01 = (CMwNod *)0x0;
            if (param_1 != (CSceneVehicle *)0x0) {
              CMotionEmitterParticles::CMotionEmitterParticles
                        ((CMotionEmitterParticles *)param_1,
                         (CMotionEmitterParticles *)in_stack_ffffffe8);
              this_01 = extraout_EAX;
            }
            if (this_01 != *(CMwNod **)pSVar7) {
              if (this_01 != (CMwNod *)0x0) {
                CMwNod::MwAddRef(this_01,in_stack_ffffffec);
              }
              if (*(CMwNod **)pSVar7 != (CMwNod *)0x0) {
                CMwNod::MwRelease(*(CMwNod **)pSVar7,in_stack_ffffffec);
              }
              *(CMwNod **)pSVar7 = this_01;
            }
            *(undefined4 *)(*(int *)pSVar7 + 0x1c) = 0;
            unaff_EBX = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x7ccf46;
            CMotionEmitterParticles::SetEmitterModel
                      (*(CMotionEmitterParticles **)pSVar7,
                       *(CMotionEmitterParticles **)(iVar1 + 0x18 + *(int *)(this + 0xa8) * 4),
                       (CMotionParticleEmitterModel *)in_stack_ffffffec);
            CMotionEmitterParticles::SetIsActive
                      (*(CMotionEmitterParticles **)pSVar7,(CSceneObjectLink *)0x0,(int)pCVar2);
            in_stack_ffffffec = *(CMwNod **)pSVar7;
            pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
            in_stack_ffffffe8 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7ccf60;
            (**(code **)(*(int *)this + 0xa8))();
            if (*(int *)(this + 0x14) != 0) {
              (**(code **)(**(int **)pSVar7 + 0xb8))();
            }
            *(undefined4 *)(*(int *)pSVar7 + 0x7c) = *(undefined4 *)(iVar1 + 0x38);
            CMotionEmitterParticles::SetIsEventMode
                      (*(CMotionEmitterParticles **)pSVar7,
                       *(CMotionEmitterParticles **)(iVar1 + 0x3c),iVar5);
            pCVar8 = pCStack_8;
          }
          else {
            unaff_EBX = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x7cce95;
            pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                     CFastBuffer<class_CCrystalFace*>::GetCount
                               (this + 0xec,(CFastBuffer<class_CCrystalFace*> *)0x7cce95);
            if (pCVar10 < pCVar4) {
              unaff_EBX = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x7ccea9;
              pSVar3 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>
                       ::operator[](this + 0xec,pCVar10,(ulong)in_stack_ffffffec);
              in_stack_ffffffec = (CMwNod *)0x7cceb0;
              iVar5 = SVisualHandler::IsInit(pSVar3,(SVisualHandler *)pCVar2);
              in_stack_ffffffe8 = pCVar10;
              if (iVar5 != 0) goto LAB_007cceb8;
            }
          }
        }
LAB_007ccf8b:
        pCStack_8 = pCVar8 + 1;
      } while (pCStack_8 < local_4);
    }
  }
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::VisualUpdateAsync
// =================================================
/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneVehicle::VisualUpdateAsync(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  GmIso4 *pGVar1;
  CMotionEmitterParticles *pCVar2;
  int *piVar3;
  float fVar4;
  int iVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  CGameCtnZone *pCVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  SObjectColors *pSVar12;
  CHmsCorpus *pCVar13;
  void *pvVar14;
  GmVec4 *pGVar15;
  SVisualHandler *unaff_EBX;
  GmMat3 *pGVar16;
  float unaff_ESI;
  CSceneVehicle *pCVar17;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar18;
  undefined4 *puVar19;
  SVisualHandler *unaff_EDI;
  CSceneObjectLink *pCVar20;
  undefined4 *puVar21;
  float *pfVar22;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar23;
  float fVar24;
  undefined1 *puVar25;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffec8;
  GmMat3 *pGVar26;
  GxLight *in_stack_fffffecc;
  ushort *puVar27;
  CHmsZone *pCVar28;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffed0;
  GmVec3 *pGVar29;
  CHmsCorpus *pCVar30;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_fffffed4;
  SPlugFaceCull *in_stack_fffffed8;
  SPlugFaceCull *pSVar31;
  CMwId *in_stack_fffffedc;
  undefined4 *puVar32;
  SPlugFaceCull *pSStack_11c;
  CSceneObjectLink *pCStack_114;
  undefined8 uStack_10c;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_e8;
  float *pfStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_cc;
  float fStack_c8;
  short asStack_c4 [2];
  float fStack_c0;
  float fStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_94;
  float fStack_90;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack_8c;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_64;
  float fStack_5c;
  undefined4 uStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float afStack_34 [5];
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  
  puVar25 = &stack0xfffffffc;
  fVar4 = (float)(**(code **)(*(int *)this + 0x198))();
  fStack_d4 = (float)(**(code **)(*(int *)this + 0x19c))();
  iVar5 = SVisualHandler::IsInit(this + 0x170,unaff_EDI);
  if (iVar5 != 0) {
    pGVar1 = *(GmIso4 **)((int)fVar4 + 0x28);
    pCVar17 = this + 0x178;
    pfVar22 = afStack_34;
    for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar22 = *(float *)pCVar17;
      pCVar17 = pCVar17 + 4;
      pfVar22 = pfVar22 + 1;
    }
    GmIso4::RotateZ(afStack_34,pGVar1,unaff_ESI);
    GmIso4::RotateX(afStack_34 + 1,*(GmIso4 **)((int)fVar4 + 0x24),(float)puVar25);
    pfVar22 = afStack_34 + 2;
    pCVar17 = this + 0x1a8;
    for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
      *(float *)pCVar17 = *pfVar22;
      pfVar22 = pfVar22 + 1;
      pCVar17 = pCVar17 + 4;
    }
    SVisualHandler::UpdateVisual(this + 0x170,unaff_EBX);
  }
  if (*(float *)((int)fVar4 + 0x10) <= _DAT_00b36144) {
    puVar32 = (undefined4 *)0x0;
  }
  else {
    puVar32 = (undefined4 *)0x3f800000;
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xec,in_stack_fffffec8);
  pCVar18 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>
               ::operator[](this + 0xec,pCVar18,(ulong)in_stack_fffffecc);
      if ((*(GxLight **)(pSVar7 + 0x6c) != (GxLight *)0x0) && (*(int *)(pSVar7 + 0x70) != 0)) {
        if (*(int *)(this + 0x80) == 0) {
          in_stack_fffffecc = (GxLight *)((float)pCVar6 * (float)_DAT_00b313b8);
        }
        else {
          in_stack_fffffecc =
               (GxLight *)((float)_DAT_00b313b8 + (float)pCVar6 * (float)_DAT_00b313b8);
        }
        uStack_10c = (double)CONCAT44(in_stack_fffffecc,(undefined4 *)uStack_10c);
        GxLight::SetIntensity
                  (*(GxLight **)(pSVar7 + 0x6c),in_stack_fffffecc,(float)in_stack_fffffed0);
      }
      pCVar18 = pCVar18 + 1;
    } while (pCVar18 < pCVar6);
  }
  pGVar26 = *(GmMat3 **)(this + 0xa4);
  CSceneVehicleStruct::GetVisualIndexFromMobilQuality
            (*(CSceneVehicleStruct **)(this + 0x60),(CSceneVehicleStruct *)pGVar26,
             (ESceneMobilQuality)in_stack_fffffecc);
  pCStack_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xf8,in_stack_fffffed0);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCStack_8c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      fVar24 = fStack_b8;
      puVar27 = (ushort *)0x7cba25;
      pSVar7 = CFastBuffer<struct_SFastCat>::operator[](this + 0xf8,pCVar6,(ulong)in_stack_fffffed4)
      ;
      in_stack_fffffed4 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar7 + 4);
      pGVar29 = (GmVec3 *)0x7cba38;
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(*(int *)(this + 0x60) + 0x38),in_stack_fffffed4,
                          (ulong)in_stack_fffffed8);
      iVar5 = *(int *)pSVar7;
      switch(*(undefined4 *)(iVar5 + 0x14)) {
      case 1:
        in_stack_fffffed8 = (SPlugFaceCull *)0x0;
        in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cba61;
        CMotionEmitterParticles::SetIsActive
                  ((CMotionEmitterParticles *)*(undefined4 *)uStack_10c,(CSceneObjectLink *)0x0,
                   (int)in_stack_fffffedc);
        break;
      case 2:
        in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cba70;
        pCVar8 = CHmsItem::GetZone(*(CHmsItem **)(this + 0x28),(CGameCtnCollection *)0x0,
                                   in_stack_fffffedc);
        in_stack_fffffedc = (CMwId *)0x7cba7c;
        pvVar14 = (void *)(**(code **)(*(int *)pCVar8 + 0xa8))();
        pCVar2 = (CMotionEmitterParticles *)*puVar32;
        in_stack_fffffed8 = (SPlugFaceCull *)((int)fVar4 + 0x34);
        GmBoxAligned::SetMult
                  (afStack_34 + 3,(SPlugFaceCull *)(this + 0x1dc),in_stack_fffffed8,
                   (GmIso4 *)pGVar26);
        fStack_54 = afStack_34[4];
        uStack_4c = uStack_1c;
        fStack_50 = ABS(fStack_14) + fStack_20;
        uStack_48 = 0;
        uStack_44 = _DAT_00b3617c;
        uStack_40 = 0;
        iVar10 = CHmsCollisionManager::SZone::IntersectSegment3
                           (pvVar14,(SZone *)&DAT_00000004,(ECollisionGroup)&fStack_54,
                            (GmVec3 *)&uStack_48,(GmVec3 *)asStack_c4,&fStack_c8,puVar27);
        if ((iVar10 != 0) && (asStack_c4[0] == 0xd)) {
          fStack_f8 = *(float *)((int)fVar4 + 0x6c);
          fStack_f4 = *(float *)((int)fVar4 + 0x70);
          fStack_f0 = *(float *)((int)fVar4 + 0x74);
          fVar23 = (float10)func_0x009c1b40();
          fVar4 = (float)fVar23;
          if ((_DAT_00b9f250 < fVar4) &&
             (iVar10 = (**(code **)(*(int *)this + 0x1a0))(), *(int *)(iVar10 + 0x24) != 0)) {
            iVar10 = (**(code **)(*(int *)this + 0x1a0))();
            CFuncKeysReal::GetValue
                      (*(CFuncKeysReal **)(iVar10 + 0x24),
                       (CFuncColorGradient *)(fVar4 * (float)_DAT_00b3d2a8),0.0);
            if (_DAT_00b9f250 < (float)extraout_ST0) {
              fVar4 = 1.0 / fVar4;
              fStack_f8 = fVar4 * fStack_f8;
              fStack_f4 = fStack_f4 * fVar4;
              fStack_f0 = fVar4 * fStack_f0;
              fStack_d0 = fStack_f4 * 0.0 - fStack_f0;
              pCStack_cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                           (fStack_f0 * 0.0 - fStack_f8 * 0.0);
              fStack_c8 = fStack_f8 - fStack_f4 * 0.0;
              fVar4 = fStack_c8 * fStack_c8 +
                      (float)pCStack_cc * (float)pCStack_cc + fStack_d0 * fStack_d0;
              uStack_10c = (double)CONCAT44(uStack_10c._4_4_,fVar4);
              if (_DAT_00d06e08 < fVar4) {
                fVar23 = (float10)func_0x009c1b40();
                fVar4 = 1.0 / (float)fVar23;
                pCStack_114 = (CSceneObjectLink *)0x1;
                fStack_d0 = fVar4 * fStack_d0;
                pCStack_cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                             ((float)pCStack_cc * fVar4);
                fStack_c8 = fVar4 * fStack_c8;
                GmMat3::SetDOVandLeftV
                          (pCVar2 + 0x24,(GmMat3 *)&fStack_f8,(GmVec3 *)&fStack_d0,pGVar29);
                GmVec3::SetMult(afStack_34,
                                (SPlugFaceCull *)(*(int *)(*(int *)(this + 0x28) + 0x14) + 0x50),
                                pSStack_11c,(GmIso4 *)in_stack_fffffed4);
                fVar4 = *(float *)((int)pvVar14 + 0x178);
                fVar24 = (float)_DAT_00b362c0;
                *(float *)(pCVar2 + 0x48) = afStack_34[1];
                *(float *)(pCVar2 + 0x4c) = fVar4 + fVar24;
                *(float *)(pCVar2 + 0x50) = afStack_34[3];
                fStack_6c = fStack_f0 * (float)_DAT_00b33a58;
                fStack_64 = (float)_DAT_00b33a58 * fStack_e8;
                *(float *)(pCVar2 + 0x48) = *(float *)(pCVar2 + 0x48) + fStack_6c;
                *(float *)(pCVar2 + 0x4c) = *(float *)(pCVar2 + 0x4c) + (float)_PTR_00b2c178;
                *(float *)(pCVar2 + 0x50) = fStack_64 + *(float *)(pCVar2 + 0x50);
                pGVar29 = (GmVec3 *)0x0;
                fVar4 = 1.0 - fStack_b8;
                fVar24 = GmFunc::ClampReal(fVar4,0.0,1.0);
                *(float *)(pCVar2 + 0x6c) = fVar24 * uStack_10c._4_4_;
                in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cbda6;
                iVar10 = (**(code **)(*(int *)this + 0x1a0))();
                CFuncKeysReal::GetValue
                          (*(CFuncKeysReal **)(iVar10 + 0x24),
                           (CFuncColorGradient *)
                           (fVar4 * (float)_DAT_00b3d298 * (float)_DAT_00b3d2a8),0.0);
                uStack_10c = (double)CONCAT44(uStack_10c._4_4_,(float)extraout_ST0_00);
                puVar32 = (undefined4 *)(1.0 - fStack_c0);
                fVar4 = GmFunc::ClampReal((float)puVar32,0.0,1.0);
                *(float *)(this + 500) = fVar4 * fVar4 * (float)extraout_ST0_00;
              }
            }
          }
        }
        pGVar26 = (GmMat3 *)0x7cbe1a;
        CMotionEmitterParticles::SetIsActive(pCVar2,pCStack_114,(int)pGVar29);
        if (pCStack_114 == (CSceneObjectLink *)0x0) {
          *(undefined4 *)(this + 500) = 0;
        }
        else {
          this[0x201] = (CSceneVehicle)0xd;
        }
        break;
      case 3:
        if (*(int *)(this + 0x1f8) != 0) {
          iVar10 = *(int *)(*(CHmsItem **)(this + 0x28) + 0x14);
          fStack_5c = *(float *)((int)fVar4 + 0x3c) * *(float *)(iVar10 + 0x58) +
                      *(float *)(iVar10 + 0x50) * *(float *)((int)fVar4 + 0x34) +
                      *(float *)((int)fVar4 + 0x38) * *(float *)(iVar10 + 0x54) +
                      *(float *)((int)fVar4 + 0x58);
          pCVar2 = (CMotionEmitterParticles *)*(undefined4 *)uStack_10c;
          fStack_54 = *(float *)((int)fVar4 + 0x54) * *(float *)(iVar10 + 0x58) +
                      *(float *)((int)fVar4 + 0x4c) * *(float *)(iVar10 + 0x50) +
                      *(float *)((int)fVar4 + 0x50) * *(float *)(iVar10 + 0x54) +
                      *(float *)((int)fVar4 + 0x60);
          in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cbe98;
          pCVar8 = CHmsItem::GetZone(*(CHmsItem **)(this + 0x28),(CGameCtnCollection *)0x0,
                                     in_stack_fffffedc);
          iVar10 = (**(code **)(*(int *)pCVar8 + 0xa8))();
          fVar4 = *(float *)(iVar10 + 0x178);
          fVar24 = (float)_DAT_00b362c0;
          in_stack_fffffedc = (CMwId *)0x1;
          *(undefined4 *)(pCVar2 + 0x48) = uStack_58;
          *(float *)(pCVar2 + 0x4c) = fVar4 + fVar24;
          *(float *)(pCVar2 + 0x50) = fStack_50;
          *(undefined4 *)(pCVar2 + 0x60) = *(undefined4 *)(this + 0x204);
          *(undefined4 *)(pCVar2 + 100) = *(undefined4 *)(this + 0x208);
          *(undefined4 *)(pCVar2 + 0x68) = *(undefined4 *)(this + 0x20c);
          in_stack_fffffed8 = (SPlugFaceCull *)0x7cbef3;
          CMotionEmitterParticles::SetIsActive(pCVar2,(CSceneObjectLink *)0x1,(int)puVar32);
          *(undefined4 *)(this + 0x1f8) = 0;
          this[0x200] = (CSceneVehicle)0xd;
          this[0x201] = (CSceneVehicle)0xd;
          fVar23 = (float10)func_0x009c1b40();
          uStack_10c = (double)(float)fVar23;
          puVar32 = (undefined4 *)0x7cbf5b;
          (**(code **)(*(int *)this + 0x1a0))();
          uVar9 = *(uint *)(this + 0x1fc);
          if (uVar9 < 2) {
            uVar9 = 2;
          }
          *(uint *)(this + 0x1fc) = uVar9;
        }
        break;
      case 4:
        uStack_ac = *(undefined4 *)(this + 200);
        uStack_a8 = *(undefined4 *)(this + 0xcc);
        fStack_a4 = *(float *)(this + 0xd0);
        fStack_a0 = 1.0;
        if (*(int *)(this + 0x210) != 0) {
          GxColor::GetHLS(&uStack_ac,(GxColor *)&fStack_20,(GmVec3 *)in_stack_fffffedc);
          uStack_18 = _DAT_00b3380c;
          in_stack_fffffed8 = (SPlugFaceCull *)&uStack_1c;
          in_stack_fffffedc = (CMwId *)0x3f800000;
          in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cbfea;
          GxColor::SetHLS(&uStack_a8,(GxColor *)in_stack_fffffed8,(GmVec3 *)0x3f800000,
                          (float)puVar32);
        }
        if (((*(int *)(this + 0x74) != 0) || (*(int *)(this + 0x210) != 0)) &&
           (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar5 + 0x34) !=
            (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff)) {
          pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>
                   ::operator[](this + 0xec,
                                *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar5 + 0x34),
                                (ulong)in_stack_fffffed4);
          pGVar16 = (GmMat3 *)((int)fVar4 + 0x34);
          fStack_78 = *(float *)((int)fVar24 + 0x3c) * *(float *)(pSVar7 + 100) +
                      *(float *)(pSVar7 + 0x5c) * *(float *)((int)fVar24 + 0x34) +
                      *(float *)((int)fVar24 + 0x38) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar24 + 0x58);
          fStack_74 = *(float *)((int)fVar24 + 0x48) * *(float *)(pSVar7 + 100) +
                      *(float *)((int)fVar24 + 0x40) * *(float *)(pSVar7 + 0x5c) +
                      *(float *)((int)fVar24 + 0x44) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar24 + 0x5c);
          fStack_70 = *(float *)((int)fVar24 + 0x54) * *(float *)(pSVar7 + 100) +
                      *(float *)((int)fVar24 + 0x4c) * *(float *)(pSVar7 + 0x5c) +
                      *(float *)((int)fVar24 + 0x50) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar24 + 0x60);
          fStack_84 = *(float *)((int)fVar4 + 0x3c) * *(float *)(pSVar7 + 100) +
                      *(float *)(pSVar7 + 0x5c) * *(float *)pGVar16 +
                      *(float *)((int)fVar4 + 0x38) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar4 + 0x58);
          fStack_80 = *(float *)((int)fVar4 + 0x48) * *(float *)(pSVar7 + 100) +
                      *(float *)((int)fVar4 + 0x44) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar4 + 0x40) * *(float *)(pSVar7 + 0x5c) +
                      *(float *)((int)fVar4 + 0x5c);
          fStack_7c = *(float *)((int)fVar4 + 0x54) * *(float *)(pSVar7 + 100) +
                      *(float *)((int)fVar4 + 0x50) * *(float *)(pSVar7 + 0x60) +
                      *(float *)((int)fVar4 + 0x4c) * *(float *)(pSVar7 + 0x5c) +
                      *(float *)((int)fVar4 + 0x60);
          fStack_94 = fStack_84 - fStack_78;
          fStack_90 = fStack_80 - fStack_74;
          pCStack_8c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(fStack_7c - fStack_70);
          piVar3 = (int *)(fStack_90 * fStack_90 + fStack_94 * fStack_94 +
                          (float)pCStack_8c * (float)pCStack_8c);
          if (_DAT_00d06e08 < (float)piVar3) {
            pGVar29 = (GmVec3 *)0x7cc17c;
            fStack_d4 = fStack_94;
            fStack_d0 = fStack_90;
            pCStack_cc = pCStack_8c;
            GmVec3::MultTranspose(&fStack_d4,pGVar16,(GmMat3 *)in_stack_fffffed8);
            pCStack_114 = (CSceneObjectLink *)
                          (fStack_c8 * fStack_c8 +
                          (float)pCStack_cc * (float)pCStack_cc + fStack_d0 * fStack_d0);
            in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar16;
            if (_DAT_00d06e08 < (float)pCStack_114) {
              in_stack_fffffed8 = (SPlugFaceCull *)0x7cc1b4;
              fVar23 = (float10)func_0x009c1b40();
              puVar32 = (undefined4 *)(1.0 / (float)fVar23);
              pGVar26 = (GmMat3 *)&fStack_dc;
              fStack_dc = (float)puVar32 * fStack_dc;
              fStack_d8 = fStack_d8 * (float)puVar32;
              fStack_d4 = (float)puVar32 * fStack_d4;
              fStack_5c = 1.0;
              uStack_58 = 0;
              fStack_54 = 0.0;
              GmMat3::SetDOVandLeftV((void *)(*piVar3 + 0x24),pGVar26,(GmVec3 *)&fStack_5c,pGVar29);
              in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pGVar16;
            }
          }
          iVar10 = *(int *)pCStack_114;
          *(undefined4 *)(iVar10 + 0x48) = *(undefined4 *)(pSVar7 + 0x5c);
          *(undefined4 *)(iVar10 + 0x4c) = *(undefined4 *)(pSVar7 + 0x60);
          *(undefined4 *)(iVar10 + 0x50) = *(undefined4 *)(pSVar7 + 100);
        }
        iVar10 = *(int *)pCStack_114;
        *(undefined4 *)(iVar10 + 0x70) = uStack_b4;
        *(undefined4 *)(iVar10 + 0x74) = uStack_b0;
        *(undefined4 *)(iVar10 + 0x78) = uStack_ac;
        if ((*(int *)(this + 0x74) == 0) && (*(int *)(this + 0x210) == 0)) {
          CMotionEmitterParticles::SetIsActive
                    (*(CMotionEmitterParticles **)pCStack_114,(CSceneObjectLink *)0x0,
                     (int)in_stack_fffffed4);
        }
        else {
          CMotionEmitterParticles::SetIsActive
                    (*(CMotionEmitterParticles **)pCStack_114,(CSceneObjectLink *)0x1,
                     (int)in_stack_fffffed4);
        }
        break;
      default:
        if (*(int *)(this + 0x78) == 0) {
          pSVar31 = *(SPlugFaceCull **)(iVar5 + 0x30);
          pCVar20 = (CSceneObjectLink *)0x1;
          if (pSVar31 != (SPlugFaceCull *)0xffffffff) {
            if (*(int *)(iVar5 + 0x24) == -1) {
LAB_007cc2f5:
              if ((((*(int *)(iVar5 + 0x2c) == 0) || (*(int *)((int)fVar4 + 0x1c) != 0)) ||
                  (iVar10 = AllWheelsSliding(this,(CSceneVehicle *)in_stack_fffffed4), iVar10 != 0))
                 && (((*(int *)(iVar5 + 0x28) == 0 ||
                      (iVar10 = (**(code **)(*(int *)this + 0x18c))(*(undefined4 *)(iVar5 + 0x30)),
                      iVar10 != 0)) || (*(int *)((int)fVar4 + 0x1c) != 0)))) goto LAB_007cc32e;
            }
            else {
              in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cc2cb;
              uVar9 = (**(code **)(*(int *)this + 400))();
              in_stack_fffffedc = (CMwId *)(uVar9 & 0xffff);
              pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                                 ((void *)(*(int *)(this + 0x60) + 0x2c),
                                  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(iVar5 + 0x24)
                                  ,(ulong)puVar27);
              pGVar26 = (GmMat3 *)0x7cc2f0;
              iVar10 = CFastArray<class_CGameMenuFrame*>::Find
                                 ((void *)(*(int *)pSVar7 + 0x14),
                                  (CFastArray<class_GxTexCoordSet> *)&stack0xfffffee0,
                                  (GxTexCoordSet *)pGVar29);
              in_stack_fffffed8 = pSVar31;
              if (iVar10 != -1) goto LAB_007cc2f5;
            }
            pCVar20 = (CSceneObjectLink *)0x0;
          }
LAB_007cc32e:
          pCVar28 = (CHmsZone *)0x7cc33a;
          CMotionEmitterParticles::SetIsActive
                    (*(CMotionEmitterParticles **)pCStack_114,pCVar20,(int)in_stack_fffffed4);
          if (pCVar20 != (CSceneObjectLink *)0x0) {
            fStack_e0 = pfStack_e4[1];
            iVar10 = *(int *)pCStack_114;
            fStack_dc = 0.0;
            fStack_d8 = *pfStack_e4;
            if ((*(int *)((int)uStack_10c._4_4_ + 0x88) == 0) ||
               (fStack_d8 * fStack_d8 + fStack_e0 * fStack_e0 + 0.0 <= _DAT_00b41d80)) {
              puVar19 = (undefined4 *)((int)uStack_10c._4_4_ + 0x40);
              puVar21 = (undefined4 *)(iVar10 + 0x24);
              for (iVar11 = 0xc; iVar11 != 0; iVar11 = iVar11 + -1) {
                *puVar21 = *puVar19;
                puVar19 = puVar19 + 1;
                puVar21 = puVar21 + 1;
              }
            }
            else {
              in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              pCVar28 = (CHmsZone *)0x7cc3a4;
              GmMat3::SetDOV((undefined4 *)(iVar10 + 0x24),(GmMat3 *)&fStack_e0,(GmVec3 *)0x0,
                             (ulong)in_stack_fffffed8);
              *(undefined4 *)(iVar10 + 0x48) = *(undefined4 *)((int)uStack_10c._4_4_ + 100);
              *(undefined4 *)(iVar10 + 0x4c) = *(undefined4 *)((int)uStack_10c._4_4_ + 0x68);
              *(undefined4 *)(iVar10 + 0x50) = *(undefined4 *)((int)uStack_10c._4_4_ + 0x6c);
            }
            pSVar31 = *(SPlugFaceCull **)((int)uStack_10c._4_4_ + 0x30);
            pfVar22 = (float *)0x0;
            if (pSVar31 != (SPlugFaceCull *)0xffffffff) {
              in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cc3e4;
              pfVar22 = (float *)(**(code **)(*(int *)this + 0x194))();
              *(float *)(iVar10 + 0x48) = *pfVar22 + *(float *)(iVar10 + 0x48);
              *(float *)(iVar10 + 0x4c) = pfVar22[1] + *(float *)(iVar10 + 0x4c);
              *(float *)(iVar10 + 0x50) = pfVar22[2] + *(float *)(iVar10 + 0x50);
              in_stack_fffffed8 = pSVar31;
            }
            pCVar6 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                      ((int)uStack_10c._4_4_ + 0x34);
            if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
              in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cc414;
              pSVar7 = CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockFxColors::SKeyVal>::SKey>
                       ::operator[](this + 0xec,pCVar6,(ulong)in_stack_fffffedc);
              *(float *)(iVar10 + 0x48) = *(float *)(pSVar7 + 0x5c) + *(float *)(iVar10 + 0x48);
              *(float *)(iVar10 + 0x4c) = *(float *)(pSVar7 + 0x60) + *(float *)(iVar10 + 0x4c);
              *(float *)(iVar10 + 0x50) = *(float *)(pSVar7 + 100) + *(float *)(iVar10 + 0x50);
              in_stack_fffffed8 = (SPlugFaceCull *)pCVar6;
            }
            fStack_a4 = ABS((float)pfStack_e4);
            fStack_a0 = ABS(fStack_e0);
            fStack_9c = ABS(fStack_dc);
            fVar4 = *(float *)((int)uStack_10c._4_4_ + 0x8c);
            *(float *)(iVar10 + 0x6c) = fVar4;
            pSStack_11c = (SPlugFaceCull *)
                          (fVar4 + *(float *)((int)uStack_10c._4_4_ + 0x98) * fStack_9c +
                                   fStack_a4 * *(float *)((int)uStack_10c._4_4_ + 0x90) +
                                   *(float *)((int)uStack_10c._4_4_ + 0x94) * fStack_a0);
            *(SPlugFaceCull **)(iVar10 + 0x6c) = pSStack_11c;
            if (*(float *)((int)uStack_10c._4_4_ + 0x9c) * (float)*(int *)((int)fStack_e8 + 0x1c) ==
                (float)_PTR_00b2c178) {
              fVar4 = 0.0;
            }
            else {
              fVar4 = 1.0;
            }
            *(float *)(iVar10 + 0x6c) = (float)pSStack_11c + fVar4;
            *(undefined4 *)(iVar10 + 0x60) = *(undefined4 *)((int)uStack_10c._4_4_ + 0xa0);
            *(undefined4 *)(iVar10 + 100) = *(undefined4 *)((int)uStack_10c._4_4_ + 0xa4);
            *(undefined4 *)(iVar10 + 0x68) = *(undefined4 *)((int)uStack_10c._4_4_ + 0xa8);
            fVar4 = *(float *)((int)uStack_10c._4_4_ + 0xb0);
            fVar24 = *(float *)((int)uStack_10c._4_4_ + 0xb4);
            *(float *)(iVar10 + 0x60) =
                 (float)pfStack_e4 * *(float *)((int)uStack_10c._4_4_ + 0xac) +
                 *(float *)(iVar10 + 0x60);
            *(float *)(iVar10 + 100) = fVar4 * fStack_e0 + *(float *)(iVar10 + 100);
            *(float *)(iVar10 + 0x68) = fVar24 * fStack_dc + *(float *)(iVar10 + 0x68);
            fVar4 = *(float *)((int)uStack_10c._4_4_ + 0xbc);
            if (*(int *)((int)fStack_e8 + 0x1c) == 0) {
              fVar24 = 0.0;
            }
            else {
              fVar24 = 1.0;
            }
            fStack_f8 = fVar24 * *(float *)((int)uStack_10c._4_4_ + 0xc0) * fStack_dc;
            *(float *)(iVar10 + 0x60) =
                 *(float *)(iVar10 + 0x60) +
                 fVar24 * *(float *)((int)uStack_10c._4_4_ + 0xb8) * (float)pfStack_e4;
            *(float *)(iVar10 + 100) = fVar4 * fStack_e0 * fVar24 + *(float *)(iVar10 + 100);
            *(float *)(iVar10 + 0x68) = fStack_f8 + *(float *)(iVar10 + 0x68);
            if (*(int *)(this + 0x2d8) != 0) {
              pCVar30 = (CHmsCorpus *)0x7cc5e1;
              iVar11 = (**(code **)(*(int *)this + 0x78))();
              pCVar13 = CHmsItem::GetCorpus(*(CHmsItem **)(this + 0x28),
                                            *(CHmsItem **)(iVar11 + 0x38),pCVar28);
              pGVar26 = (GmMat3 *)0x7cc5f9;
              pSVar12 = CPlugBitmapRenderLightFromMap::ObjectGrabColors
                                  (*(CPlugBitmapRenderLightFromMap **)(this + 0x2d8),
                                   (CPlugBitmapRenderLightFromMap *)pCVar13,pCVar30);
              if (pSVar12 != (SObjectColors *)0x0) {
                iVar11 = 0;
                if (pfVar22 != (float *)0x0) {
                  if (*pfVar22 <= 0.0) {
                    iVar11 = 1;
                    if (pfVar22[2] <= 0.0) {
                      iVar11 = 3;
                    }
                  }
                  else if (pfVar22[2] <= 0.0) {
                    iVar11 = 2;
                  }
                  else {
                    iVar11 = 0;
                  }
                }
                uVar9 = *(uint *)(pSVar12 + iVar11 * 4);
                fVar4 = (float)_DAT_00b3d080;
                pSStack_11c = (SPlugFaceCull *)(uVar9 & 0xff);
                *(float *)(iVar10 + 0x70) = (float)(uVar9 >> 0x10 & 0xff) * fVar4;
                *(float *)(iVar10 + 0x74) = (float)(uVar9 >> 8 & 0xff) * fVar4;
                *(float *)(iVar10 + 0x78) = fVar4 * (float)(int)pSStack_11c;
              }
            }
          }
        }
        else {
          in_stack_fffffed8 = (SPlugFaceCull *)0x0;
          in_stack_fffffed4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7cc2a5;
          CMotionEmitterParticles::SetIsActive
                    ((CMotionEmitterParticles *)*(undefined4 *)uStack_10c,(CSceneObjectLink *)0x0,
                     (int)in_stack_fffffedc);
        }
      }
      pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(iVar5 + 1);
      fVar4 = fStack_e8;
    } while (pCVar6 < pCStack_8c);
  }
  if (*(int *)(this + 0x2dc) != 0) {
    iVar5 = (**(code **)(*(int *)this + 0x78))();
    pCVar13 = CHmsItem::GetCorpus(*(CHmsItem **)(this + 0x28),*(CHmsItem **)(iVar5 + 0x38),
                                  (CHmsZone *)in_stack_fffffed4);
    if (*(int *)(pCVar13 + 0x4c) == 0) {
      pvVar14 = operator_new(0x24);
      if (pvVar14 == (void *)0x0) {
        pvVar14 = (void *)0x0;
      }
      else {
        CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
        CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>
                  (pvVar14,(CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *)
                           in_stack_fffffed8);
      }
      *(void **)(pCVar13 + 0x4c) = pvVar14;
    }
    pGVar15 = CPlugShaderLoadIds::FindOrAddLoadId
                        (*(void **)(pCVar13 + 0x4c),(CPlugShaderLoadIds *)0xc5,
                         (ELoadId)in_stack_fffffedc);
    *(undefined4 *)pGVar15 = *(undefined4 *)((int)fVar4 + 0x2c);
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::WaterSplash
// =================================================
void __thiscall
CSceneVehicle::WaterSplash(CSceneVehicle *this,CSceneVehicle *param_1,GmVec3 *param_2)
{
{
  int iVar1;
  CSceneMobil *unaff_ESI;
  
  iVar1 = CSceneMobil::IsZombie((CSceneMobil *)this,unaff_ESI);
  if (iVar1 == 0) {
    *(int *)(this + 0xb8) = *(int *)(this + 0xb8) + 1;
  }
  else {
    iVar1 = (**(code **)(*(int *)this + 0x108))();
    if (iVar1 == 0) {
      return;
    }
  }
  *(undefined4 *)(this + 0x204) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x208) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x20c) = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + 0x1f8) = 1;
  return;
}
}

// =================================================
// Function: CSceneVehicle::WheelGetAsyncGroundContactPos
// =================================================
GmVec3 * __thiscall
CSceneVehicle::WheelGetAsyncGroundContactPos
          (CSceneVehicle *this,CSceneVehicle *param_1,ulong param_2)
{
{
  return (GmVec3 *)&DAT_00d706d4;
}
}

// =================================================
// Function: CSceneVehicle::WheelGetContactMaterial
// =================================================
ushort __thiscall
CSceneVehicle::WheelGetContactMaterial(CSceneVehicle *this,CSceneVehicle *param_1,ulong param_2)
{
{
  return 0xffff;
}
}

// =================================================
// Function: CSceneVehicle::_scalar_deleting_destructor_
// =================================================
void * __thiscall
CSceneVehicle::_scalar_deleting_destructor_(CSceneVehicle *this,CPfmHeap *param_1,uint param_2)
{
{
  CSceneVehicle *unaff_ESI;
  
  ~CSceneVehicle(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CSceneVehicle::_vcall__372__flat______
// =================================================
void __thiscall CSceneVehicle::_vcall__372__flat______(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
                    /* WARNING: Could not recover jumptable at 0x0061fa82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x174))();
  return;
}
}

// =================================================
// Function: CSceneVehicle::_vcall__388__flat______
// =================================================
void __thiscall CSceneVehicle::_vcall__388__flat______(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
                    /* WARNING: Could not recover jumptable at 0x00637252. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)this + 0x184))();
  return;
}
}

// =================================================
// Function: CSceneVehicle::~CSceneVehicle
// =================================================
void __thiscall CSceneVehicle::~CSceneVehicle(CSceneVehicle *this,CSceneVehicle *param_1)
{
{
  CMwNod *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CMwNod *unaff_EDI;
  uint unaff_retaddr;
  uint uVar2;
  CMwNod *pCVar3;
  undefined1 uStack00000008;
  void *in_stack_00000018;
  CSceneVehicle *pCVar4;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar5;
  code *pcVar6;
  CSceneVehicle *pCVar7;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar8;
  undefined1 *puVar9;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar10;
  undefined4 uVar11;
  undefined3 uVar13;
  CFastArray<class_CFuncShader*> *pCVar12;
  
  pCVar8 = ExceptionList;
  puVar9 = &LAB_00acd0a5;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  uVar11 = 0;
  pCVar7 = this;
  if (*(CMwNod **)(this + 0x2d8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2d8),pCVar1);
  }
  uVar2 = unaff_retaddr & 0xffffff00;
  if (*(CMwNod **)(this + 0x2d4) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2d4),unaff_EDI);
  }
  uVar2 = uVar2 & 0xffffff00;
  if (*(CMwNod **)(this + 0x2d0) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x2d0),unaff_EDI);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0x2b8,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EDI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2ac,unaff_ESI);
  pcVar6 = SEnvironment::~SEnvironment;
  pCVar1 = (CMwNod *)0x2;
  pCVar4 = this + 0x28c;
  pCVar5 = (CFastBuffer<class_CPlugFileGPUV*> *)&DAT_0000000c;
  uStack00000008 = 0x16;
  _eh_vector_destructor_iterator_(pCVar4,0xc,2,SEnvironment::~SEnvironment);
  pCVar10 = (CFastBuffer<class_CPlugFileGPUV*> *)CONCAT31((int3)((uint)puVar9 >> 8),0x15);
  if (*(CMwNod **)(this + 0x288) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x288),(CMwNod *)pCVar4);
  }
  uVar13 = (undefined3)((uint)uVar11 >> 8);
  if (*(CMwNod **)(this + 0x284) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x284),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x280) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x280),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x27c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x27c),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x278) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x278),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x274) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x274),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x270) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x270),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x26c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x26c),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x268) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x268),(CMwNod *)pCVar5);
  }
  if (*(CMwNod **)(this + 0x264) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x264),(CMwNod *)pCVar5);
  }
  pCVar12 = (CFastArray<class_CFuncShader*> *)CONCAT31(uVar13,0xb);
  if (*(CMwNod **)(this + 0x260) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x260),(CMwNod *)pCVar5);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x254,pCVar5);
  pCVar3 = (CMwNod *)CONCAT31((int3)(uVar2 >> 8),9);
  if (*(CMwNod **)(this + 0x248) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x248),pCVar1);
  }
  param_1 = (CSceneVehicle *)CONCAT31(param_1._1_3_,8);
  CFastBuffer<struct_CSceneVehicle::SVisualEmitter>::
  ~CFastBuffer<struct_CSceneVehicle::SVisualEmitter>
            (this + 0xf8,(CFastBuffer<struct_CSceneVehicle::SVisualEmitter> *)pcVar6);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (this + 0xec,(CFastBuffer<class_CPlugFileGPUV*> *)pCVar7);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0xe0,pCVar8);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0xd4,pCVar10);
  CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>(this + 0x6c,pCVar12);
  in_stack_00000018 = (void *)CONCAT31(in_stack_00000018._1_3_,3);
  if (*(CMwNod **)(this + 0x68) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x68),pCVar3);
  }
  if (*(CMwNod **)(this + 100) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 100),(CMwNod *)param_1);
  }
  if (*(CMwNod **)(this + 0x60) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x60),(CMwNod *)param_1);
  }
  if (*(CMwNod **)(this + 0x48) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x48),(CMwNod *)param_1);
  }
  CSceneMobil::~CSceneMobil((CSceneMobil *)this,(CSceneMobil *)param_1);
  ExceptionList = in_stack_00000018;
  return;
}
}

