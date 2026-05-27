// Class implementation: CSceneToyBoat

// =================================================
// Function: CSceneToyBoat::AbsorbContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::AbsorbContact
          (CSceneToyBoat *this,CSceneMobilAbsorbContact *param_1,CHmsItem *param_2,
          CHmsPhysicalContact *param_3)
{
{
  float fVar1;
  char cVar2;
  CMwNod *this_00;
  float fVar3;
  bool bVar4;
  CSceneSoundSource *this_01;
  CMwNod *pCVar5;
  float *pfVar6;
  void *this_02;
  char *extraout_EAX;
  char *pcVar7;
  int iVar8;
  int unaff_EBX;
  EPlugVideoTimer unaff_EBP;
  CFastString *unaff_ESI;
  CMwNod *unaff_EDI;
  float *pfVar9;
  float10 fVar10;
  code *pcVar11;
  CPlugFileVideo *pCVar12;
  ulong in_stack_ffffff94;
  int iStack_64;
  char *pcStack_60;
  float fStack_5c;
  float fStack_58;
  CFastStringInt aCStack_50 [4];
  char *pcStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00ace7fc;
  local_c = ExceptionList;
  pCVar5 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffff84);
  ExceptionList = &local_c;
  *(undefined4 *)(this + 0x3f4) = 1;
  this_00 = *(CMwNod **)(*(int *)(*(int *)(param_1 + 0x40) + 0x48) + 0x40);
  if (*(CMwNod **)(this + 0x3f8) != (CMwNod *)0x0) {
    CMwNod::MwSubDependant(*(CMwNod **)(this + 0x3f8),(CMwNod *)this,pCVar5);
  }
  *(CMwNod **)(this + 0x3f8) = this_00;
  CMwNod::MwAddDependant(this_00,(CMwNod *)this,unaff_EDI);
  pcVar11 = (code *)0x0;
  pfVar6 = (float *)(**(code **)(*(int *)this + 0x7c))();
  pfVar9 = &fStack_38;
  for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pfVar9 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    pfVar9 = pfVar9 + 1;
  }
  (**(code **)(**(int **)(param_2 + 0x40) + 0x78))();
  if ((DAT_00d6d3a8 & 1) == 0) {
    DAT_00d6d3a8 = DAT_00d6d3a8 | 1;
    CFastString::CFastString((CFastString *)&DAT_00d6d3a0,(CFastString *)"Course_",(char *)pcVar11);
    pcVar11 = `protected:_virtual_void___thiscall_CSceneToyBoat::
              AbsorbContact(class_CHmsPhysicalContact&)'::__l4::
              _dynamic_atexit_destructor_for__CourseName__;
    _atexit(`protected:_virtual_void___thiscall_CSceneToyBoat::
            AbsorbContact(class_CHmsPhysicalContact&)'::__l4::
            _dynamic_atexit_destructor_for__CourseName__);
  }
  if ((DAT_00d6d3a8 & 2) == 0) {
    DAT_00d6d3a8 = DAT_00d6d3a8 | 2;
    CFastString::CFastString((CFastString *)&DAT_00d6d398,(CFastString *)"Traffic_",(char *)pcVar11)
    ;
    pcVar11 = `protected:_virtual_void___thiscall_CSceneToyBoat::
              AbsorbContact(class_CHmsPhysicalContact&)'::__l4::
              _dynamic_atexit_destructor_for__TrafficName__;
    _atexit(`protected:_virtual_void___thiscall_CSceneToyBoat::
            AbsorbContact(class_CHmsPhysicalContact&)'::__l4::
            _dynamic_atexit_destructor_for__TrafficName__);
  }
  this_02 = (void *)(**(code **)(*(int *)this_00 + 0x14))();
  CMwId::GetString(this_02,(CMwStatsValue *)pcVar11,unaff_ESI);
  pCVar12 = (CPlugFileVideo *)0xa100000;
  iVar8 = (**(code **)(*(int *)this_00 + 0x10))();
  if (iVar8 == 0) {
    if (extraout_EAX == (char *)0x0) {
LAB_007e4ed4:
      GmVec3::SetMult(&pcStack_60,(SPlugFaceCull *)(param_2 + 0xc),(SPlugFaceCull *)&fStack_34,
                      (GmIso4 *)pCVar12);
      bVar4 = false;
      goto LAB_007e4f09;
    }
    pcVar7 = extraout_EAX;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    fStack_5c = (float)((int)pcVar7 - (int)(extraout_EAX + 1));
    pcStack_60 = extraout_EAX;
    iVar8 = CFastString::CompareNoCase
                      ((CFastString *)&DAT_00d6d3a0,(CFastStringInt *)&pcStack_60,
                       (SStringParam *)&DAT_00000007,(ulong)pCVar12);
    if (iVar8 != 0) {
      pcStack_4c = extraout_EAX;
      do {
        cVar2 = *pcStack_4c;
        pcStack_4c = pcStack_4c + 1;
      } while (cVar2 != '\0');
      pcStack_4c = (char *)((int)pcStack_4c - (int)(extraout_EAX + 1));
      pCVar12 = (CPlugFileVideo *)&DAT_00000008;
      iVar8 = CFastString::CompareNoCase
                        ((CFastString *)&DAT_00d6d398,aCStack_50,(SStringParam *)&DAT_00000008,
                         unaff_EBP);
      if (iVar8 != 0) goto LAB_007e4ed4;
    }
  }
  pcStack_60 = (char *)(fStack_10 - *(float *)(iStack_64 + 0x24));
  bVar4 = true;
  fStack_58 = (float)puStack_8 - *(float *)(iStack_64 + 0x2c);
LAB_007e4f09:
  pcStack_4c = pcStack_60;
  fStack_44 = fStack_58;
  fStack_5c = 0.0;
  fStack_48 = 0.0;
  fVar3 = fStack_58 * fStack_58 + (float)pcStack_60 * (float)pcStack_60 + 0.0;
  if (_DAT_00d07bc0 < fVar3) {
    fVar10 = (float10)func_0x009c1b40();
    fStack_44 = 1.0 / (float)fVar10;
    pcStack_4c = (char *)(fStack_44 * (float)pcStack_60);
    fStack_48 = (float)_PTR_00b2c178 * fStack_44;
    fStack_44 = fStack_44 * fStack_58;
  }
  pcStack_4c = (char *)(_DAT_00d07bb4 * (float)pcStack_4c);
  fStack_48 = _DAT_00d07bb4 * fStack_48;
  fStack_44 = _DAT_00d07bb4 * fStack_44;
  fStack_40 = *(float *)(param_2 + 0x20) * fStack_2c +
              fStack_30 * *(float *)(param_2 + 0x1c) + *(float *)(param_2 + 0x18) * fStack_34 +
              fStack_10;
  fStack_3c = fStack_20 * *(float *)(param_2 + 0x20) +
              fStack_24 * *(float *)(param_2 + 0x1c) + *(float *)(param_2 + 0x18) * fStack_28 +
              (float)local_c;
  fStack_38 = fStack_14 * *(float *)(param_2 + 0x20) +
              fStack_18 * *(float *)(param_2 + 0x1c) + fStack_1c * *(float *)(param_2 + 0x18) +
              (float)puStack_8;
  fVar1 = *(float *)(this + 0xdc);
  if (_DAT_00d07bc0 < fVar3) {
    fVar10 = (float10)func_0x009c1b40();
    fVar3 = 1.0 / (float)fVar10;
    pcStack_60 = (char *)(fVar3 * (float)pcStack_60);
    fStack_5c = (float)_PTR_00b2c178 * fVar3;
    fStack_58 = fVar3 * fStack_58;
    SolveContact((GmVec3 *)&fStack_40,(GmVec3 *)&pcStack_4c,(GmVec3 *)&pcStack_60,
                 (CSceneMobil *)this,*(CSceneMobil **)(this + 0x3f8));
  }
  if (*(float *)(*(int *)(this + 0x84) + 0x100) < ABS(fVar1 - *(float *)(this + 0xdc))) {
    if (bVar4) {
      this_01 = *(CSceneSoundSource **)(this + 0x3bc);
    }
    else {
      this_01 = *(CSceneSoundSource **)(this + 0x3c0);
      if ((*(short *)(param_2 + 0x48) == 5) &&
         (*(CSceneSoundSource **)(this + 0x3c4) != (CSceneSoundSource *)0x0)) {
        this_01 = *(CSceneSoundSource **)(this + 0x3c4);
      }
    }
    if (this_01 != (CSceneSoundSource *)0x0) {
      CSceneSoundSource::Play(this_01,pCVar12,unaff_EBP,unaff_EBX,in_stack_ffffff94);
    }
  }
  *(undefined4 *)(param_2 + 0x3c) = 0;
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::BSCoefGamePlayGet
// =================================================
float __thiscall CSceneToyBoat::BSCoefGamePlayGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  int iVar1;
  float fVar2;
  
  fVar2 = *(float *)(this + 0x7c) * *(float *)(this + 0x6c) * *(float *)(this + 0x70);
  if ((*(int *)(this + 0x130) != 0) &&
     ((iVar1 = *(int *)(*(int *)(*(int *)(this + 0x130) + 0x14) + 0x18), iVar1 == 2 || (iVar1 == 5))
     )) {
    return *(float *)(this + 0x74) * fVar2;
  }
  return *(float *)(this + 0x78) * fVar2;
}
}

// =================================================
// Function: CSceneToyBoat::BSCoefSurfGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CSceneToyBoat::BSCoefSurfGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  float fVar1;
  int iVar2;
  CSceneToyBoat *unaff_ESI;
  
  iVar2 = IsOnTheWind(this,unaff_ESI);
  if (iVar2 == 0) {
    fVar1 = *(float *)(this + 0x198);
    if (!NAN(fVar1) && 0.0 < fVar1 != (fVar1 == 0.0)) {
      return *(float *)(*(int *)(this + 0x84) + 0x44) * (float)_DAT_00b313b8 *
             *(float *)(this + 0x198) + (float)_DAT_00b2c188;
    }
  }
  else if (*(float *)(this + 0x198) < 0.0) {
    fVar1 = *(float *)(*(int *)(this + 0x84) + 0x44) * *(float *)(this + 0x198) +
            (float)_DAT_00b2c188;
    if (0.0 <= fVar1) {
      return fVar1;
    }
    return 0.0;
  }
  return 1.0;
}
}

// =================================================
// Function: CSceneToyBoat::ComputeForces
// =================================================
void __thiscall
CSceneToyBoat::ComputeForces
          (CSceneToyBoat *this,CCallbackSceneToyBroomStickComputeForces *param_1,CHmsItem *param_2,
          float param_3)
{
{
  void *this_00;
  SCasterCat *pSVar1;
  int iVar2;
  int iVar3;
  GmMat3 *unaff_EBX;
  GmIso4 *unaff_ESI;
  undefined4 *puVar4;
  CSceneToyBoat *pCVar5;
  CMwCmdScriptVarBool *pCVar6;
  ulong unaff_EDI;
  undefined4 *puVar7;
  ulong in_stack_ffffffd0;
  int in_stack_ffffffd4;
  undefined1 local_28 [8];
  CMwCmdScriptVarBool local_20 [32];
  
  if (*(int *)(this + 0x354) != 0) {
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,unaff_EDI);
    iVar3 = *(int *)(this + 0x200);
    puVar4 = (undefined4 *)(*(int *)(*(int *)(*(int *)pSVar1 + 0x58) + 0x328) + 0x10);
    puVar7 = (undefined4 *)&stack0xffffffd4;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar7 = puVar7 + 1;
    }
    if (iVar3 != 0) {
      pCVar5 = this + 0x204;
      puVar4 = (undefined4 *)&stack0xffffffd4;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *(undefined4 *)pCVar5;
        pCVar5 = pCVar5 + 4;
        puVar4 = puVar4 + 1;
      }
      *(undefined4 *)(this + 0x200) = 0;
    }
    UpdateBoatPhysics(this,(CSceneToyBoat *)param_2,(float)&stack0xffffffd4,unaff_ESI);
    GmMat3::OrthoNormalize(local_28,unaff_EBX);
    pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(*(int *)(this + 0x28) + 0x34),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,in_stack_ffffffd0);
    this_00 = *(void **)(*(int *)(*(int *)pSVar1 + 0x58) + 0x32c);
    pCVar6 = local_20;
    puVar4 = (undefined4 *)((int)this_00 + 0x10);
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *(undefined4 *)pCVar6;
      pCVar6 = pCVar6 + 4;
      puVar4 = puVar4 + 1;
    }
    GmQuat::Set(this_00,local_20,in_stack_ffffffd4);
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::DeltaMoveGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::DeltaMoveGet
          (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,float *param_3,GmVec3 *param_4)
{
{
  CSceneToyBoat *this_00;
  float fVar1;
  float unaff_retaddr;
  GmVec3 *pGVar2;
  
  pGVar2 = *(GmVec3 **)(this + 0xbc);
  fVar1 = RotationRadiusGet(this,*(CSceneToyBoat **)(this + 0x118),*(float *)(this + 0xd8));
  DeltaMoveGet(this_00,(CSceneToyBoat *)param_2,*(float *)(this_00 + 0xdc),
               (float *)(-unaff_retaddr * fVar1),pGVar2);
  return;
}
}

// =================================================
// Function: CSceneToyBoat::GlobalIsAutomaticSheetSet
// =================================================
void __thiscall
CSceneToyBoat::GlobalIsAutomaticSheetSet(CSceneToyBoat *this,CSceneToyBoat *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x124,pCVar3,unaff_EBP);
      pCVar3 = pCVar3 + 1;
      *(int *)(*(int *)pSVar2 + 0x70) = param_2;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::GlobalIsFullEaseOutSet
// =================================================
void __thiscall
CSceneToyBoat::GlobalIsFullEaseOutSet(CSceneToyBoat *this,CSceneToyBoat *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x124,pCVar3,unaff_EBP);
      pCVar3 = pCVar3 + 1;
      *(int *)(*(int *)pSVar2 + 0x7c) = param_2;
    } while (pCVar3 < pCVar1);
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::GlobalSheetTargetNormedAngleSet
// =================================================
void __thiscall
CSceneToyBoat::GlobalSheetTargetNormedAngleSet
          (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2)
{
{
  float fVar1;
  CBoatSailState *this_00;
  float fVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  float unaff_EBX;
  CMwId *unaff_EBP;
  float unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  float fVar6;
  float in_stack_0000000c;
  float fStack00000010;
  CMwId *in_stack_fffffff4;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,unaff_EDI);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x124,pCVar5,(ulong)unaff_ESI);
      unaff_ESI = in_stack_0000000c;
      CBoatSailState::SheetTargetNormedAngleSet
                (*(CBoatSailState **)pSVar4,*(CBoatSailState **)(this + 0x1ac),
                 (int)in_stack_0000000c,(float)unaff_EBP);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  this_00 = *(CBoatSailState **)(this + 0x134);
  if ((*(CBoatSailState **)(this + 0x130) != (CBoatSailState *)0x0) &&
     (this_00 != (CBoatSailState *)0x0)) {
    CBoatSailState::OptimalSailAngleGet
              (*(CBoatSailState **)(this + 0x130),*(CBoatSail **)(this + 0x94),
               *(float *)(this + 0xb0),unaff_ESI,unaff_EBP);
    fStack00000010 = *(float *)(this + 0xb0);
    fVar6 = CBoatSailState::OptimalSailAngleGet
                      (this_00,*(CBoatSail **)(this + 0x94),fStack00000010,unaff_EBX,
                       in_stack_fffffff4);
    fVar6 = (in_stack_0000000c - fStack00000010) + fVar6;
    fVar2 = -*(float *)(*(int *)(this_00 + 0x14) + 0x60);
    fVar1 = *(float *)(*(int *)(this_00 + 0x14) + 0x60);
    if ((fVar6 <= fVar2) || (fVar2 = fVar1, fVar1 < fVar6 != (fVar1 == fVar6))) {
      fVar6 = fVar2;
    }
    *(float *)(this_00 + 0x80) = fVar6;
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::IsOnTheWind
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall CSceneToyBoat::IsOnTheWind(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  float fVar1;
  
  fVar1 = GmFunc::Mod(*(float *)(this + 0xd8) - *(float *)(this + 0x90),_DAT_00b5b910,_DAT_00ba112c)
  ;
  if (ABS(fVar1) < (float)_DAT_00b36be8) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CSceneToyBoat::Move
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::Move(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3)
{
{
  CBoatSailState *pCVar1;
  SSailManoeuvre SVar2;
  undefined3 extraout_var;
  CManoeuvre *pCVar3;
  int iVar4;
  CBoatSailState *this_00;
  float unaff_EBX;
  float unaff_EBP;
  float unaff_ESI;
  undefined4 *puVar5;
  float *pfVar6;
  float unaff_EDI;
  CBoatSailState *pCVar7;
  undefined4 *puVar8;
  float *pfVar9;
  float10 extraout_ST0;
  float10 fVar10;
  float fVar11;
  GmVec3 *pGVar12;
  float fVar13;
  float fVar14;
  CSceneToyBoat *in_stack_00000024;
  CSceneToyBoat *in_stack_0000002c;
  float in_stack_00000030;
  float in_stack_00000034;
  SSailManoeuvre *in_stack_ffffff1c;
  CSceneToyBoat *pCVar15;
  CSceneToyBoat *in_stack_ffffff24;
  float in_stack_ffffff28;
  float in_stack_ffffff38;
  GmVec3 *pGVar16;
  CBoatParam *pCVar17;
  CBoatParam *in_stack_ffffff40;
  CBoatParam *pCVar18;
  CBoatParam *pCVar19;
  float local_bc;
  float local_b8;
  CBoatSail *local_b4;
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  float local_a4;
  float local_a0;
  undefined4 local_94;
  undefined4 uStack_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float fStack_70;
  float fStack_6c;
  float local_68;
  float local_64;
  CBoatSail *local_60;
  CSceneToyBoat local_5c [4];
  float local_58;
  float local_54;
  float fStack_50;
  float fStack_48;
  float fStack_3c;
  undefined4 local_30 [4];
  GmMat2 aGStack_20 [28];
  undefined1 auStack_4 [4];
  
  pfVar9 = (float *)param_2;
  local_94 = *(undefined4 *)((int)param_2 + 8);
  local_8c = *(float *)((int)param_2 + 0x20);
  puVar5 = (undefined4 *)param_2;
  puVar8 = local_30;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  __CIatan2();
  pCVar15 = (CSceneToyBoat *)(float)extraout_ST0;
  *(CSceneToyBoat **)(this + 0xd8) = pCVar15;
  if (*(int *)(*(int *)(this + 0x84) + 0xbc) == 0) {
    OldComputeOptimalSailAngles
              (this,*(CSceneToyBoat **)(this + 0x98),*(float *)(this + 0x94),unaff_EDI);
  }
  SailManoeuvreUpdate(this,(CSceneToyBoat *)param_2,unaff_ESI);
  pCVar7 = *(CBoatSailState **)(this + 0x130);
  if ((pCVar7 != (CBoatSailState *)0x0) ||
     (pCVar7 = *(CBoatSailState **)(this + 0x134), local_b0 = _DAT_00b41d80,
     pCVar7 != (CBoatSailState *)0x0)) {
    in_stack_ffffff28 = *(float *)(this + 0x98);
    local_b4 = *(CBoatSail **)(this + 0x94);
    local_b0 = CBoatSail::BSGet(*(CBoatSail **)(pCVar7 + 0x14),local_b4,in_stack_ffffff28,unaff_EBP)
    ;
  }
  fVar14 = ABS(local_b0);
  if (fVar14 < _DAT_00ba1128) {
    local_b0 = _DAT_00b41d80;
  }
  *(undefined4 *)(this + 0xe0) = 0;
  fVar11 = 1.0;
  if (*(int *)(*(int *)(this + 0x84) + 0xbc) == 0) {
    this_00 = *(CBoatSailState **)(this + 0x134);
    if (this_00 == (CBoatSailState *)0x0) goto LAB_007e52e4;
    fVar11 = *(float *)(this + 0xb0);
    fVar13 = *(float *)(this + 0x98);
    pCVar1 = *(CBoatSailState **)(this + 0x94);
    fVar14 = fVar13;
  }
  else {
    fVar11 = 1.0;
    if (pCVar7 == (CBoatSailState *)0x0) goto LAB_007e52e4;
    fVar11 = *(float *)(this + 0xb0);
    fVar13 = *(float *)(this + 0x98);
    pCVar1 = *(CBoatSailState **)(this + 0x94);
    this_00 = pCVar7;
    fVar14 = fVar11;
  }
  fVar11 = CBoatSailState::BSCoefSailTuningGet(this_00,pCVar1,fVar13,fVar11,unaff_EBX);
LAB_007e52e4:
  fStack_6c = CBoatParam::BSCoefFromHeelGet
                        (*(CBoatParam **)(this + 0x84),(CBoatParam *)ABS(*(float *)(this + 0x10c)),
                         unaff_EBX);
  SVar2 = SailManoeuvreGet(this,local_5c);
  pCVar3 = SSailManoeuvre::ManoeuvreGet((void *)CONCAT31(extraout_var,SVar2),in_stack_ffffff1c);
  if (pCVar3 != (CManoeuvre *)0x0) {
    __CIsin();
  }
  pGVar12 = (GmVec3 *)BSCoefSurfGet(this,pCVar15);
  fVar13 = BSCoefGamePlayGet(this,in_stack_ffffff24);
  pCVar19 = (CBoatParam *)0x3f800000;
  if (local_bc != 1.0) {
    fVar13 = *(float *)(this + 0x80) * fVar13;
  }
  pGVar16 = (GmVec3 *)
            ((float)in_stack_ffffff40 * local_a0 * local_bc * (float)local_60 * fVar13 *
            in_stack_ffffff38);
  *(GmVec3 **)(this + 0xe0) = pGVar16;
  pCVar18 = (CBoatParam *)((float)pGVar16 - *(float *)(this + 0xdc));
  if ((float)pCVar18 <= 0.0) {
    pCVar19 = (CBoatParam *)
              (*(float *)(*(int *)(this + 0x84) + 0x34) * (float)pCVar18 -
              *(float *)(*(int *)(this + 0x84) + 0x30));
  }
  else if (pCVar7 != (CBoatSailState *)0x0) {
    pGVar16 = *(GmVec3 **)(this + 0x98);
    local_60 = *(CBoatSail **)(this + 0x94);
    pCVar18 = in_stack_ffffff40;
    local_bc = CBoatSail::AccelerationGet
                         (*(CBoatSail **)(pCVar7 + 0x14),local_60,(float)pGVar16,in_stack_ffffff28);
    pCVar19 = pCVar18;
  }
  if (ABS((float)pCVar18) < (float)in_stack_00000024 * ABS(local_bc)) {
    local_bc = (float)pCVar18 / (float)in_stack_00000024;
  }
  pCVar18 = *(CBoatParam **)(this + 0x84);
  if (*(int *)(pCVar18 + 0x94) == 0) {
    pCVar17 = *(CBoatParam **)(this + 0xdc);
    fVar13 = TillerAngleNormedGet
                       (this,(CSceneToyBoat *)
                             (uint)(*(float *)(this + 0x118) * *(float *)(this + 0x98) <
                                   (float)_PTR_00b2c178));
    fVar14 = CBoatParam::DecelerationFromTillerGet(pCVar18,pCVar19,fVar13,fVar14,(int)fVar11);
    *(float *)(this + 0xdc) =
         *(float *)(this + 0xdc) + (float)in_stack_0000002c * ((float)local_b4 - fVar14);
    in_stack_00000024 = in_stack_0000002c;
  }
  else {
    fStack_a8 = *(float *)((int)pfVar9 + 8);
    local_7c = *(float *)(this + 0xd0);
    local_80 = *(float *)(this + 0xcc);
    local_a4 = *(float *)((int)pfVar9 + 0x14);
    local_78 = *(float *)(this + 0xd4);
    local_68 = *(float *)((int)pfVar9 + 0x24);
    local_a0 = *(float *)((int)pfVar9 + 0x20);
    local_64 = *(float *)((int)pfVar9 + 0x28);
    local_60 = *(CBoatSail **)((int)pfVar9 + 0x2c);
    local_88 = 0.0;
    local_84 = local_a0;
    if (_DAT_00d07bc0 < fStack_a8 * fStack_a8 + 0.0 + local_a0 * local_a0) {
      local_8c = fStack_a8;
      fVar10 = (float10)func_0x009c1b40();
      fVar14 = 1.0 / (float)fVar10;
      fStack_a8 = fVar14 * local_8c;
      local_88 = fVar14 * 0.0;
      local_84 = local_84 * fVar14;
    }
    local_74 = local_84 - local_88 * 0.0;
    fStack_70 = fStack_a8 * 0.0 - local_84 * 0.0;
    fVar14 = local_88 * 0.0 - fStack_a8;
    local_58 = fStack_a8 * local_bc;
    local_54 = local_88 * local_bc;
    fStack_50 = local_84 * local_bc;
    fVar11 = local_78 * fVar14 + fStack_70 * local_7c + local_74 * local_80;
    fStack_6c = -fVar11 * ABS(fVar11) * *(float *)(pCVar18 + 0xa0);
    local_74 = fStack_6c * local_74;
    fStack_70 = fStack_70 * fStack_6c;
    fStack_6c = fStack_6c * fVar14;
    pCVar17 = (CBoatParam *)
              (((*(float *)(this + 0x188) - local_64) + *(float *)(pCVar18 + 0xb8)) /
              *(float *)(pCVar18 + 0xac));
    pCVar19 = (CBoatParam *)0x0;
    if (((float)pCVar17 < 0.0 == ((float)pCVar17 == 0.0)) &&
       (pCVar19 = pCVar17, !NAN((float)pCVar17) && 1.0 < (float)pCVar17 != ((float)pCVar17 == 1.0)))
    {
      pCVar19 = (CBoatParam *)0x3f800000;
    }
    fStack_3c = -((1.0 - (float)pCVar19) * *(float *)(pCVar18 + 0xb4));
    fStack_48 = -local_7c * *(float *)(pCVar18 + 0xb0);
    local_b4 = (CBoatSail *)(local_58 + 0.0 + local_74 + 0.0 + 0.0 + 0.0);
    local_b0 = local_54 + 0.0 + fStack_70 +
               *(float *)(pCVar18 + 0xa4) * (float)pCVar19 +
               (float)pCVar19 * (float)pCVar19 * *(float *)(pCVar18 + 0xa8) + fStack_3c + fStack_48;
    fStack_ac = fStack_50 + 0.0 + fStack_6c + 0.0 + 0.0 + 0.0;
    local_68 = local_68 + *(float *)(this + 0xcc) * (float)in_stack_00000024;
    local_64 = *(float *)(this + 0xd0) * (float)in_stack_00000024 + local_64;
    local_60 = (CBoatSail *)((float)local_60 + *(float *)(this + 0xd4) * (float)in_stack_00000024);
    local_a4 = local_b0 * (float)in_stack_00000024;
    local_a0 = fStack_ac * (float)in_stack_00000024;
    local_80 = (float)local_b4 * (float)in_stack_00000024 + local_80;
    local_7c = local_7c + local_a4;
    local_78 = local_a0 + local_78;
    *(float *)(this + 0xcc) = local_80;
    *(float *)(this + 0xd0) = local_7c;
    *(float *)(this + 0xd4) = local_78;
    *(float *)(this + 0xdc) =
         *(float *)(this + 0xd0) * local_88 + *(float *)(this + 0xcc) * fStack_a8 +
         *(float *)(this + 0xd4) * local_84;
    *(float *)((int)pfVar9 + 0x24) = local_68;
    *(float *)((int)pfVar9 + 0x28) = local_64;
    *(CBoatSail **)((int)pfVar9 + 0x2c) = local_60;
    fStack_a8 = (float)local_b4 * (float)in_stack_00000024;
  }
  uStack_90 = *(undefined4 *)((int)pfVar9 + 0x24);
  local_8c = *(float *)((int)pfVar9 + 0x28);
  local_88 = *(float *)((int)pfVar9 + 0x2c);
  DeltaMoveGet(this,in_stack_00000024,(float)&local_b8,&fStack_6c,pGVar12);
  local_b8 = *(float *)(this + 0xd8) + (float)local_b4;
  fVar14 = GmFunc::Mod(local_b8,0.0,_DAT_00ba1130);
  *(float *)(this + 0xd8) = fVar14;
  *(float *)(this + 0x120) = (float)local_b4 / in_stack_00000030;
  if (*(int *)(*(int *)(this + 0x84) + 0x94) == 0) {
    local_8c = local_68 + local_8c;
    local_88 = local_64 + local_88;
    local_84 = (float)local_60 + local_84;
  }
  local_b8 = -_DAT_00d07bb0;
  *(float *)(this + 0x3d8) = local_b8 * *(float *)(this + 0x3d8) + *(float *)(this + 0x3d8);
  *(float *)(this + 0x3dc) = *(float *)(this + 0x3dc) * local_b8 + *(float *)(this + 0x3dc);
  *(float *)(this + 0x3e0) = local_b8 * *(float *)(this + 0x3e0) + *(float *)(this + 0x3e0);
  fStack_a8 = *(float *)(this + 0x3d8) * in_stack_00000030;
  local_a4 = *(float *)(this + 0x3dc) * in_stack_00000030;
  local_a0 = in_stack_00000030 * *(float *)(this + 0x3e0);
  if (*(int *)(this + 0x400) == 0) {
    *(undefined4 *)(this + 0x3ec) = 0;
    *(undefined4 *)(this + 1000) = 0;
    *(undefined4 *)(this + 0x3e4) = 0;
  }
  else {
    fStack_a8 = *(float *)(this + 0x3e4) + fStack_a8;
    local_a4 = *(float *)(this + 1000) + local_a4;
    local_a0 = *(float *)(this + 0x3ec) + local_a0;
  }
  local_8c = fStack_a8 + local_8c;
  local_88 = local_a4 + local_88;
  local_84 = local_a0 + local_84;
  GmIso4::SetTranslation(auStack_4,(GmIso4 *)&local_8c,pGVar16);
  fVar14 = (1.0 - _DAT_00d07bb0) * *(float *)(this + 0x3fc);
  *(float *)(this + 0x3fc) = fVar14;
  puVar5 = pfVar9;
  puVar8 = local_30 + 3;
  for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar8 = puVar8 + 1;
  }
  local_b4 = (CBoatSail *)(fVar14 * in_stack_00000034 - local_b0);
  GmMat3::RotateY(local_30 + 3,(GmIso4 *)local_b4,(float)pCVar17);
  GmIso4::SetRotation(&param_1,aGStack_20,(float)pCVar19);
  pfVar6 = &param_2;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar9 = *pfVar6;
    pfVar6 = pfVar6 + 1;
    pfVar9 = pfVar9 + 1;
  }
  *(undefined4 *)(this + 0x400) = 0;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::OldComputeOptimalSailAngles
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::OldComputeOptimalSailAngles
          (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,float param_3)
{
{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  CBoatSailState *pCVar6;
  CBoatSailState *pCVar7;
  CBoatSailState *pCVar8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar9;
  SCasterCat *pSVar10;
  ESailType unaff_EBX;
  ESailType unaff_EBP;
  ESailType unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  int unaff_EDI;
  float fVar12;
  ESailType unaff_retaddr;
  float in_stack_00000010;
  CBoatSailState *pCStack00000014;
  CBoatSailState *pCStack0000001c;
  float in_stack_00000020;
  ESailType in_stack_fffffff8;
  
  if (*(int *)(this + 0x130) == 0) {
    fVar12 = 0.0;
  }
  else {
    fVar12 = CBoatSail::BestVmgAngleGet
                       (*(CBoatSail **)(*(int *)(this + 0x130) + 0x14),(CBoatSail *)param_2,
                        *(float *)(this + 0x1ac),unaff_EDI);
  }
  pCVar6 = SailStateGet(this,(CSceneToyBoat *)0x0,unaff_ESI);
  pCVar7 = SailStateGet(this,(CSceneToyBoat *)0x1,unaff_EBP);
  pCVar8 = SailStateGet(this,(CSceneToyBoat *)0x3,unaff_EBX);
  pCStack0000001c = SailStateGet(this,(CSceneToyBoat *)&DAT_00000004,in_stack_fffffff8);
  pCStack00000014 = SailStateGet(this,(CSceneToyBoat *)&DAT_00000005,(ESailType)fVar12);
  if (pCVar6 == (CBoatSailState *)0x0) goto LAB_007e0aec;
  iVar3 = *(int *)(this + 0x1ac);
  if (iVar3 == 0) {
LAB_007e0908:
    if ((float)pCStack0000001c <= in_stack_00000010) {
      if (iVar3 != 0) goto LAB_007e0921;
LAB_007e0934:
      if ((float)pCStack0000001c < _DAT_00ba12f8) goto LAB_007e0943;
      if (iVar3 != 0) goto LAB_007e098b;
      iVar3 = *(int *)(pCVar6 + 0x14);
      fVar2 = (*(float *)(iVar3 + 0x60) * ((float)pCStack0000001c - in_stack_00000010)) /
              ((float)_DAT_00ba12e8 - in_stack_00000010);
      *(float *)(pCVar6 + 0x6c) = fVar2;
      fVar12 = *(float *)(iVar3 + 0x60);
      fVar1 = *(float *)(iVar3 + 0x5c);
LAB_007e09f1:
      fVar12 = GmFunc::ClampReal(fVar2,fVar1,fVar12);
      *(float *)(pCVar6 + 0x6c) = fVar12;
    }
    else {
LAB_007e0911:
      *(undefined4 *)(pCVar6 + 0x6c) = 0;
    }
  }
  else {
    if ((float)pCStack0000001c < in_stack_00000010) goto LAB_007e0911;
    if (iVar3 == 0) goto LAB_007e0908;
LAB_007e0921:
    if ((float)pCStack0000001c <= _DAT_00ba12fc) {
      if (iVar3 == 0) goto LAB_007e0934;
LAB_007e098b:
      iVar3 = *(int *)(pCVar6 + 0x14);
      fVar2 = (((float)pCStack0000001c - in_stack_00000010) * (float)_DAT_00b55920 *
              *(float *)(iVar3 + 0x60)) / ((float)_DAT_00ba12f0 - in_stack_00000010);
      *(float *)(pCVar6 + 0x6c) = fVar2;
      fVar12 = -*(float *)(iVar3 + 0x5c);
      fVar1 = -*(float *)(iVar3 + 0x60);
      goto LAB_007e09f1;
    }
LAB_007e0943:
    fVar12 = *(float *)(*(int *)(pCVar6 + 0x14) + 0x60);
    *(float *)(pCVar6 + 0x6c) = fVar12;
    if (*(int *)(this + 0x1ac) == 0) {
      *(float *)(pCVar6 + 0x6c) = fVar12 * 1.0;
    }
    else {
      *(float *)(pCVar6 + 0x6c) = fVar12 * _DAT_00b2c060;
    }
  }
  if (pCVar7 != (CBoatSailState *)0x0) {
    iVar3 = *(int *)(pCVar7 + 0x14);
    if ((*(float *)(iVar3 + 0x5c) <= *(float *)(pCVar6 + 0x6c)) ||
       (*(float *)(pCVar6 + 0x6c) <= 0.0)) {
      if ((*(float *)(pCVar6 + 0x6c) <= -*(float *)(iVar3 + 0x5c)) ||
         (0.0 <= *(float *)(pCVar6 + 0x6c))) {
        *(undefined4 *)(pCVar7 + 0x6c) = *(undefined4 *)(pCVar6 + 0x6c);
        if (pCVar8 != (CBoatSailState *)0x0) {
          *(undefined4 *)(pCVar8 + 0x6c) = *(undefined4 *)(pCVar6 + 0x6c);
        }
        if (in_stack_00000020 != 0.0) {
          *(undefined4 *)((int)in_stack_00000020 + 0x6c) = *(undefined4 *)(pCVar6 + 0x6c);
        }
        if (pCStack00000014 == (CBoatSailState *)0x0) goto LAB_007e0aec;
        fVar12 = *(float *)(pCVar6 + 0x6c);
      }
      else {
        *(float *)(pCVar7 + 0x6c) = -*(float *)(iVar3 + 0x5c);
        if (pCVar8 != (CBoatSailState *)0x0) {
          *(float *)(pCVar8 + 0x6c) = -*(float *)(*(int *)(pCVar8 + 0x14) + 0x5c);
        }
        if (in_stack_00000020 != 0.0) {
          *(float *)((int)in_stack_00000020 + 0x6c) =
               -*(float *)(*(int *)((int)in_stack_00000020 + 0x14) + 0x5c);
        }
        if (pCStack00000014 == (CBoatSailState *)0x0) goto LAB_007e0aec;
        fVar12 = -*(float *)(*(int *)(pCStack00000014 + 0x14) + 0x5c);
      }
    }
    else {
      *(undefined4 *)(pCVar7 + 0x6c) = *(undefined4 *)(iVar3 + 0x5c);
      if (pCVar8 != (CBoatSailState *)0x0) {
        *(undefined4 *)(pCVar8 + 0x6c) = *(undefined4 *)(*(int *)(pCVar8 + 0x14) + 0x5c);
      }
      if (in_stack_00000020 != 0.0) {
        *(undefined4 *)((int)in_stack_00000020 + 0x6c) =
             *(undefined4 *)(*(int *)((int)in_stack_00000020 + 0x14) + 0x5c);
      }
      if (pCStack00000014 == (CBoatSailState *)0x0) goto LAB_007e0aec;
      fVar12 = *(float *)(*(int *)(pCStack00000014 + 0x14) + 0x5c);
    }
    *(float *)(pCStack00000014 + 0x6c) = fVar12;
  }
LAB_007e0aec:
  if (*(int *)(this + 0x1ac) == 0) {
    pCStack0000001c = (CBoatSailState *)(-(float)pCStack0000001c - (float)_DAT_00b77ec0);
  }
  else {
    pCStack0000001c = (CBoatSailState *)((float)_DAT_00b77ec0 - (float)pCStack0000001c);
  }
  pCVar6 = SailStateGet(this,(CSceneToyBoat *)0x2,unaff_retaddr);
  if (pCVar6 != (CBoatSailState *)0x0) {
    *(undefined4 *)(*(int *)(pCVar6 + 0x14) + 0x60) = _DAT_00ba1134;
    fVar12 = GmFunc::Mod(in_stack_00000020,_DAT_00b5b910,_DAT_00ba112c);
    *(float *)(pCVar6 + 0x6c) = fVar12;
  }
  pCVar9 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this + 0x124,(CFastBuffer<class_CCrystalFace*> *)param_1);
  pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar9 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar10 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                          (this + 0x124,pCVar11,(ulong)param_2);
      iVar3 = *(int *)pSVar10;
      iVar4 = *(int *)(iVar3 + 0x14);
      if (*(int *)(iVar4 + 0x18) != 0) {
        fVar12 = *(float *)(iVar4 + 0x60);
        fVar1 = *(float *)(iVar4 + 0x5c);
        fVar2 = *(float *)(iVar3 + 0x6c);
        if (*(int *)(iVar4 + 0x18) == 2) {
          if (*(int *)(this + 0x1ac) == 0) goto LAB_007e0be5;
LAB_007e0ba1:
          fVar5 = fVar1;
          if ((fVar1 < fVar2) && (fVar5 = fVar12, fVar12 < fVar2 == (fVar12 == fVar2)))
          goto LAB_007e0c0e;
        }
        else {
          if (*(int *)(this + 0x1ac) == 0) goto LAB_007e0ba1;
LAB_007e0be5:
          fVar5 = -fVar12;
          fVar1 = -fVar1;
          if ((fVar5 < fVar2) && (fVar5 = fVar1, fVar1 < fVar2 == (fVar1 == fVar2))) {
LAB_007e0c0e:
            fVar5 = fVar2;
          }
        }
        *(float *)(iVar3 + 0x6c) = fVar5;
      }
      pCVar11 = pCVar11 + 1;
    } while (pCVar11 < pCVar9);
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::RetrieveSounds
// =================================================
void __thiscall CSceneToyBoat::RetrieveSounds(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  CSceneToyBoat *this_00;
  CSceneObjectLink *pCVar1;
  CMwNod *this_01;
  CMwId CVar2;
  undefined3 extraout_var;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  undefined3 extraout_var_00;
  SLoadedLight *pSVar5;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  CMwNod *unaff_EBX;
  int unaff_EBP;
  CFastStringInt *unaff_ESI;
  CMwId *unaff_EDI;
  CMwNod *pCVar6;
  CFastStringInt *in_stack_00000008;
  int in_stack_0000000c;
  CMwNod *pCVar7;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar8;
  char *in_stack_00000018;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000001c;
  CFastStringInt *in_stack_00000020;
  int in_stack_00000024;
  char *in_stack_00000030;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000034;
  CFastStringInt *in_stack_00000038;
  int in_stack_0000003c;
  char *in_stack_00000048;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000004c;
  CFastStringInt *in_stack_00000050;
  char *in_stack_00000054;
  CMwId *pCVar9;
  CFastStringInt *in_stack_00000060;
  char *in_stack_00000064;
  char *in_stack_00000068;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000006c;
  CFastStringInt *pCVar10;
  int iVar11;
  char *in_stack_00000078;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000007c;
  CFastStringInt *pCVar12;
  int iVar13;
  char *in_stack_00000088;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000008c;
  CFastStringInt *pCVar14;
  int iVar15;
  char *in_stack_00000098;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_0000009c;
  char *in_stack_000000a8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_000000ac;
  char *in_stack_000000b8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_000000bc;
  char *in_stack_000000c8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_000000cc;
  char *in_stack_000000d8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_000000dc;
  CSceneMobil *in_stack_000000e8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_000000ec;
  CMwNod *in_stack_000000f8;
  CMwNod *in_stack_000000fc;
  undefined4 uStack00000100;
  undefined4 uStack00000104;
  undefined4 uStack00000110;
  void *pvStack00000114;
  void *in_stack_00000118;
  CMwId *in_stack_ffffffec;
  CFastStringInt *in_stack_fffffff0;
  void *pvVar16;
  CMwNod *pCVar17;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *pCVar18;
  
  pCVar18 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xffffffff;
  pCVar17 = (CMwNod *)&LAB_00ace7c0;
  this_00 = this + 0x3cc;
  pvVar16 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CFastBufferRef<class_CPlugMaterial>::Reset
            (this_00,(GmFrustumIso4 *)(DAT_00cca150 ^ (uint)&stack0xffffffdc));
  CVar2 = CMwId::CreateFromLocalName(&stack0xfffffff0);
  pCVar6 = (CMwNod *)0x0;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var,CVar2),unaff_EDI);
  OnAccessViolation_ConcatToCrashFileName(unaff_ESI);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e3de3:
    if (*(CMwNod **)(this + 0x38c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x38c),(CMwNod *)in_stack_ffffffec);
      *(undefined4 *)(this + 0x38c) = 0;
    }
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)unaff_ESI);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e3de3;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,unaff_EBP);
    pCVar7 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar7 != *(CMwNod **)(this + 0x38c)) {
      if (pCVar7 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar7,unaff_EBX);
      }
      if (*(CMwNod **)(this + 0x38c) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x38c),(CMwNod *)in_stack_ffffffec);
      }
      *(CMwNod **)(this + 0x38c) = pCVar7;
    }
  }
  CVar2 = CMwId::CreateFromLocalName(&stack0x00000000);
  pCVar7 = (CMwNod *)0x1;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_00,CVar2),
                      in_stack_ffffffec);
  pCVar8 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(in_stack_fffffff0);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e3e77:
    if (*(CMwNod **)(this + 0x390) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x390),(CMwNod *)pCVar18);
      *(undefined4 *)(this + 0x390) = 0;
    }
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_fffffff0);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e3e77;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,(int)pvVar16);
    this_01 = *(CMwNod **)(pCVar1 + 0x18);
    if (this_01 != *(CMwNod **)(this + 0x390)) {
      if (this_01 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(this_01,pCVar17);
      }
      if (*(CMwNod **)(this + 0x390) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x390),(CMwNod *)pCVar18);
      }
      *(CMwNod **)(this + 0x390) = this_01;
    }
  }
  pCVar17 = *(CMwNod **)(this + 0x390);
  pSVar5 = CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>::AddNewElem(this_00,pCVar18);
  if (pCVar17 != *(CMwNod **)pSVar5) {
    if (pCVar17 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar17,pCVar6);
    }
    if (*(CMwNod **)pSVar5 != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)pSVar5,(CMwNod *)0xffffffff);
    }
    *(CMwNod **)pSVar5 = pCVar17;
  }
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000018);
  pCVar6 = (CMwNod *)0x2;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_01,CVar2),
                      (CMwId *)0xffffffff);
  pCVar18 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xffffffff;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000008);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e3f36:
    if (*(CMwNod **)(this + 0x394) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x394),(CMwNod *)pCVar8);
      *(undefined4 *)(this + 0x394) = 0;
    }
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_00000008);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e3f36;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,in_stack_0000000c);
    pCVar17 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar17 != *(CMwNod **)(this + 0x394)) {
      if (pCVar17 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar17,pCVar7);
      }
      if (*(CMwNod **)(this + 0x394) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x394),(CMwNod *)pCVar8);
      }
      *(CMwNod **)(this + 0x394) = pCVar17;
    }
  }
  pCVar17 = *(CMwNod **)(this + 0x394);
  pSVar5 = CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>::AddNewElem(this_00,pCVar8);
  if (pCVar17 != *(CMwNod **)pSVar5) {
    if (pCVar17 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar17,(CMwNod *)in_stack_00000018);
    }
    if (*(CMwNod **)pSVar5 != (CMwNod *)0x0) {
      in_stack_00000018 = (char *)0x7e3f78;
      CMwNod::MwRelease(*(CMwNod **)pSVar5,(CMwNod *)in_stack_0000001c);
    }
    *(CMwNod **)pSVar5 = pCVar17;
  }
  in_stack_00000018 = "SoundAffalerSpi";
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000030);
  in_stack_00000018 = (char *)CONCAT31(extraout_var_02,CVar2);
  pCVar17 = (CMwNod *)0x3;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000018,
                      (CMwId *)in_stack_0000001c);
  pCVar8 = (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0xffffffff;
  in_stack_0000001c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e3faf;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000020);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e3ff9:
    if (*(CMwNod **)(this + 0x398) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x398),(CMwNod *)pCVar18);
      *(undefined4 *)(this + 0x398) = 0;
    }
  }
  else {
    in_stack_00000018 = (char *)0x7e3fbd;
    in_stack_0000001c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_00000020);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e3ff9;
    in_stack_00000020 = (CFastStringInt *)0x1;
    in_stack_0000001c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e3fcc;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,in_stack_00000024);
    pCVar7 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar7 != *(CMwNod **)(this + 0x398)) {
      if (pCVar7 != (CMwNod *)0x0) {
        in_stack_00000024 = 0x7e3fe2;
        CMwNod::MwAddRef(pCVar7,pCVar6);
      }
      if (*(CMwNod **)(this + 0x398) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x398),(CMwNod *)pCVar18);
      }
      *(CMwNod **)(this + 0x398) = pCVar7;
    }
  }
  pCVar6 = *(CMwNod **)(this + 0x398);
  pSVar5 = CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>::AddNewElem(this_00,pCVar18);
  if (pCVar6 != *(CMwNod **)pSVar5) {
    if (pCVar6 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_00000030);
    }
    if (*(CMwNod **)pSVar5 != (CMwNod *)0x0) {
      in_stack_00000030 = (char *)0x7e403b;
      CMwNod::MwRelease(*(CMwNod **)pSVar5,(CMwNod *)in_stack_00000034);
    }
    *(CMwNod **)pSVar5 = pCVar6;
  }
  in_stack_00000030 = "SoundHisserVoile";
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000048);
  in_stack_00000030 = (char *)CONCAT31(extraout_var_03,CVar2);
  pCVar6 = (CMwNod *)&DAT_00000004;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000030,
                      (CMwId *)in_stack_00000034);
  pCVar9 = (CMwId *)0xffffffff;
  in_stack_00000034 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4072;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000038);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e40bc:
    if (*(CMwNod **)(this + 0x39c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x39c),(CMwNod *)pCVar8);
      *(undefined4 *)(this + 0x39c) = 0;
    }
  }
  else {
    in_stack_00000030 = (char *)0x7e4080;
    in_stack_00000034 = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_00000038);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e40bc;
    in_stack_00000038 = (CFastStringInt *)0x1;
    in_stack_00000034 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e408f;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,in_stack_0000003c);
    pCVar7 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar7 != *(CMwNod **)(this + 0x39c)) {
      if (pCVar7 != (CMwNod *)0x0) {
        in_stack_0000003c = 0x7e40a5;
        CMwNod::MwAddRef(pCVar7,pCVar17);
      }
      if (*(CMwNod **)(this + 0x39c) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x39c),(CMwNod *)pCVar8);
      }
      *(CMwNod **)(this + 0x39c) = pCVar7;
    }
  }
  pCVar17 = *(CMwNod **)(this + 0x39c);
  pSVar5 = CFastBuffer<class_CMwNodRef<class_CSceneSoundSource>_>::AddNewElem(this_00,pCVar8);
  if (pCVar17 != *(CMwNod **)pSVar5) {
    if (pCVar17 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar17,(CMwNod *)in_stack_00000048);
    }
    if (*(CMwNod **)pSVar5 != (CMwNod *)0x0) {
      in_stack_00000048 = (char *)0x7e4100;
      CMwNod::MwRelease(*(CMwNod **)pSVar5,(CMwNod *)in_stack_0000004c);
    }
    *(CMwNod **)pSVar5 = pCVar17;
  }
  in_stack_00000048 = "SoundAffalerVoile";
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000060);
  in_stack_00000048 = (char *)CONCAT31(extraout_var_04,CVar2);
  pCVar10 = (CFastStringInt *)&DAT_00000005;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000048,
                      (CMwId *)in_stack_0000004c);
  iVar11 = -1;
  in_stack_0000004c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4136;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000050);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e417f:
    if (*(CMwNod **)(this + 0x3a0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3a0),(CMwNod *)pCVar9);
      *(undefined4 *)(this + 0x3a0) = 0;
    }
  }
  else {
    in_stack_00000048 = (char *)0x7e4143;
    in_stack_0000004c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_00000050);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e417f;
    in_stack_00000050 = (CFastStringInt *)0x1;
    in_stack_0000004c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4152;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,(int)in_stack_00000054);
    pCVar17 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar17 != *(CMwNod **)(this + 0x3a0)) {
      if (pCVar17 != (CMwNod *)0x0) {
        in_stack_00000054 = (char *)0x7e4168;
        CMwNod::MwAddRef(pCVar17,pCVar6);
      }
      if (*(CMwNod **)(this + 0x3a0) != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3a0),(CMwNod *)pCVar9);
      }
      *(CMwNod **)(this + 0x3a0) = pCVar17;
    }
  }
  in_stack_00000054 = &stack0x00000070;
  in_stack_00000050 = (CFastStringInt *)0x7e41a3;
  CVar2 = CMwId::CreateFromLocalName(in_stack_00000054);
  pCVar12 = (CFastStringInt *)&DAT_00000006;
  in_stack_00000054 = (char *)0x7e41b6;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)CONCAT31(extraout_var_05,CVar2),pCVar9);
  iVar13 = -1;
  OnAccessViolation_ConcatToCrashFileName(in_stack_00000060);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e420e:
    if (*(CMwNod **)(this + 0x3a4) != (CMwNod *)0x0) {
      in_stack_00000068 = (char *)0x7e421d;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3a4),(CMwNod *)in_stack_0000006c);
      *(undefined4 *)(this + 0x3a4) = 0;
    }
  }
  else {
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)in_stack_00000060);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e420e;
    in_stack_00000060 = (CFastStringInt *)0x1;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,(int)in_stack_00000064);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3a4)) {
      if (pCVar6 != (CMwNod *)0x0) {
        in_stack_00000064 = (char *)0x7e41f7;
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_00000068);
      }
      if (*(CMwNod **)(this + 0x3a4) != (CMwNod *)0x0) {
        in_stack_00000068 = (char *)0x7e4206;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3a4),(CMwNod *)in_stack_0000006c);
      }
      *(CMwNod **)(this + 0x3a4) = pCVar6;
    }
  }
  in_stack_00000064 = &stack0x00000080;
  in_stack_00000068 = "SoundFaseyageSpi";
  in_stack_00000060 = (CFastStringInt *)0x7e4232;
  CVar2 = CMwId::CreateFromLocalName(in_stack_00000064);
  in_stack_00000068 = (char *)CONCAT31(extraout_var_06,CVar2);
  pCVar14 = (CFastStringInt *)&DAT_00000007;
  in_stack_00000064 = (char *)0x7e4245;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000068,
                      (CMwId *)in_stack_0000006c);
  iVar15 = -1;
  in_stack_0000006c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4254;
  OnAccessViolation_ConcatToCrashFileName(pCVar10);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e429d:
    if (*(CMwNod **)(this + 0x3a8) != (CMwNod *)0x0) {
      in_stack_00000078 = (char *)0x7e42ac;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3a8),(CMwNod *)in_stack_0000007c);
      *(undefined4 *)(this + 0x3a8) = 0;
    }
  }
  else {
    in_stack_00000068 = (char *)0x7e4261;
    in_stack_0000006c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar10);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e429d;
    in_stack_0000006c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4270;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar11);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3a8)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_00000078);
      }
      if (*(CMwNod **)(this + 0x3a8) != (CMwNod *)0x0) {
        in_stack_00000078 = (char *)0x7e4295;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3a8),(CMwNod *)in_stack_0000007c);
      }
      *(CMwNod **)(this + 0x3a8) = pCVar6;
    }
  }
  in_stack_00000078 = "SoundCrack_Border";
  CVar2 = CMwId::CreateFromLocalName(&stack0x00000090);
  in_stack_00000078 = (char *)CONCAT31(extraout_var_07,CVar2);
  pCVar10 = (CFastStringInt *)&DAT_00000008;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000078,
                      (CMwId *)in_stack_0000007c);
  iVar11 = -1;
  in_stack_0000007c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e42e3;
  OnAccessViolation_ConcatToCrashFileName(pCVar12);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e432c:
    if (*(CMwNod **)(this + 0x3ac) != (CMwNod *)0x0) {
      in_stack_00000088 = (char *)0x7e433b;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3ac),(CMwNod *)in_stack_0000008c);
      *(undefined4 *)(this + 0x3ac) = 0;
    }
  }
  else {
    in_stack_00000078 = (char *)0x7e42f0;
    in_stack_0000007c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar12);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e432c;
    in_stack_0000007c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e42ff;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar13);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3ac)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_00000088);
      }
      if (*(CMwNod **)(this + 0x3ac) != (CMwNod *)0x0) {
        in_stack_00000088 = (char *)0x7e4324;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3ac),(CMwNod *)in_stack_0000008c);
      }
      *(CMwNod **)(this + 0x3ac) = pCVar6;
    }
  }
  in_stack_00000088 = "SoundWinch";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000a0);
  in_stack_00000088 = (char *)CONCAT31(extraout_var_08,CVar2);
  pCVar12 = (CFastStringInt *)&DAT_00000009;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000088,
                      (CMwId *)in_stack_0000008c);
  iVar13 = -1;
  in_stack_0000008c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4372;
  OnAccessViolation_ConcatToCrashFileName(pCVar14);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e43bb:
    if (*(CMwNod **)(this + 0x3b0) != (CMwNod *)0x0) {
      in_stack_00000098 = (char *)0x7e43ca;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3b0),(CMwNod *)in_stack_0000009c);
      *(undefined4 *)(this + 0x3b0) = 0;
    }
  }
  else {
    in_stack_00000088 = (char *)0x7e437f;
    in_stack_0000008c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar14);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e43bb;
    in_stack_0000008c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e438e;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar15);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3b0)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_00000098);
      }
      if (*(CMwNod **)(this + 0x3b0) != (CMwNod *)0x0) {
        in_stack_00000098 = (char *)0x7e43b3;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3b0),(CMwNod *)in_stack_0000009c);
      }
      *(CMwNod **)(this + 0x3b0) = pCVar6;
    }
  }
  in_stack_00000098 = "SoundPont";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000b0);
  in_stack_00000098 = (char *)CONCAT31(extraout_var_09,CVar2);
  pCVar14 = (CFastStringInt *)&DAT_0000000a;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_00000098,
                      (CMwId *)in_stack_0000009c);
  iVar15 = -1;
  in_stack_0000009c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4401;
  OnAccessViolation_ConcatToCrashFileName(pCVar10);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e444a:
    if (*(CMwNod **)(this + 0x3b4) != (CMwNod *)0x0) {
      in_stack_000000a8 = (char *)0x7e4459;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3b4),(CMwNod *)in_stack_000000ac);
      *(undefined4 *)(this + 0x3b4) = 0;
    }
  }
  else {
    in_stack_00000098 = (char *)0x7e440e;
    in_stack_0000009c = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar10);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e444a;
    in_stack_0000009c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e441d;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar11);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3b4)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_000000a8);
      }
      if (*(CMwNod **)(this + 0x3b4) != (CMwNod *)0x0) {
        in_stack_000000a8 = (char *)0x7e4442;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3b4),(CMwNod *)in_stack_000000ac);
      }
      *(CMwNod **)(this + 0x3b4) = pCVar6;
    }
  }
  in_stack_000000a8 = "SoundMat";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000c0);
  in_stack_000000a8 = (char *)CONCAT31(extraout_var_10,CVar2);
  pCVar10 = (CFastStringInt *)&DAT_0000000b;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_000000a8,
                      (CMwId *)in_stack_000000ac);
  iVar11 = -1;
  in_stack_000000ac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4490;
  OnAccessViolation_ConcatToCrashFileName(pCVar12);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e44d9:
    if (*(CMwNod **)(this + 0x3b8) != (CMwNod *)0x0) {
      in_stack_000000b8 = (char *)0x7e44e8;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3b8),(CMwNod *)in_stack_000000bc);
      *(undefined4 *)(this + 0x3b8) = 0;
    }
  }
  else {
    in_stack_000000a8 = (char *)0x7e449d;
    in_stack_000000ac = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar12);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e44d9;
    in_stack_000000ac = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e44ac;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar13);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3b8)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_000000b8);
      }
      if (*(CMwNod **)(this + 0x3b8) != (CMwNod *)0x0) {
        in_stack_000000b8 = (char *)0x7e44d1;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3b8),(CMwNod *)in_stack_000000bc);
      }
      *(CMwNod **)(this + 0x3b8) = pCVar6;
    }
  }
  in_stack_000000b8 = "SoundCollisionBoat";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000d0);
  in_stack_000000b8 = (char *)CONCAT31(extraout_var_11,CVar2);
  pCVar12 = (CFastStringInt *)&DAT_0000000c;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_000000b8,
                      (CMwId *)in_stack_000000bc);
  iVar13 = -1;
  in_stack_000000bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e451f;
  OnAccessViolation_ConcatToCrashFileName(pCVar14);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e4568:
    if (*(CMwNod **)(this + 0x3bc) != (CMwNod *)0x0) {
      in_stack_000000c8 = (char *)0x7e4577;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3bc),(CMwNod *)in_stack_000000cc);
      *(undefined4 *)(this + 0x3bc) = 0;
    }
  }
  else {
    in_stack_000000b8 = (char *)0x7e452c;
    in_stack_000000bc = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar14);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e4568;
    in_stack_000000bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e453b;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar15);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3bc)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_000000c8);
      }
      if (*(CMwNod **)(this + 0x3bc) != (CMwNod *)0x0) {
        in_stack_000000c8 = (char *)0x7e4560;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3bc),(CMwNod *)in_stack_000000cc);
      }
      *(CMwNod **)(this + 0x3bc) = pCVar6;
    }
  }
  in_stack_000000c8 = "SoundCollisionRock";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000e0);
  in_stack_000000c8 = (char *)CONCAT31(extraout_var_12,CVar2);
  pCVar14 = (CFastStringInt *)&DAT_0000000d;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_000000c8,
                      (CMwId *)in_stack_000000cc);
  iVar15 = -1;
  in_stack_000000cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e45ae;
  OnAccessViolation_ConcatToCrashFileName(pCVar10);
  if (pCVar3 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
LAB_007e45f7:
    if (*(CMwNod **)(this + 0x3c0) != (CMwNod *)0x0) {
      in_stack_000000d8 = (char *)0x7e4606;
      CMwNod::MwRelease(*(CMwNod **)(this + 0x3c0),(CMwNod *)in_stack_000000dc);
      *(undefined4 *)(this + 0x3c0) = 0;
    }
  }
  else {
    in_stack_000000c8 = (char *)0x7e45bb;
    in_stack_000000cc = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar10);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 == (CSceneObjectLink *)0x0) goto LAB_007e45f7;
    in_stack_000000cc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e45ca;
    CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar11);
    pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
    if (pCVar6 != *(CMwNod **)(this + 0x3c0)) {
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_000000d8);
      }
      if (*(CMwNod **)(this + 0x3c0) != (CMwNod *)0x0) {
        in_stack_000000d8 = (char *)0x7e45ef;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3c0),(CMwNod *)in_stack_000000dc);
      }
      *(CMwNod **)(this + 0x3c0) = pCVar6;
    }
  }
  in_stack_000000d8 = "SoundCollisionSand";
  CVar2 = CMwId::CreateFromLocalName(&stack0x000000f0);
  in_stack_000000d8 = (char *)CONCAT31(extraout_var_13,CVar2);
  uStack00000100 = 0xe;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,(CSceneMobil *)in_stack_000000d8,
                      (CMwId *)in_stack_000000dc);
  uStack00000104 = 0xffffffff;
  in_stack_000000dc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e463d;
  OnAccessViolation_ConcatToCrashFileName(pCVar12);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    in_stack_000000d8 = (char *)0x7e464a;
    in_stack_000000dc = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar12);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 != (CSceneObjectLink *)0x0) {
      in_stack_000000dc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e4659;
      CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar13);
      pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
      if (pCVar6 != *(CMwNod **)(this + 0x3c4)) {
        if (pCVar6 != (CMwNod *)0x0) {
          CMwNod::MwAddRef(pCVar6,(CMwNod *)in_stack_000000e8);
        }
        if (*(CMwNod **)(this + 0x3c4) != (CMwNod *)0x0) {
          in_stack_000000e8 = (CSceneMobil *)0x7e467e;
          CMwNod::MwRelease(*(CMwNod **)(this + 0x3c4),(CMwNod *)in_stack_000000ec);
        }
        *(CMwNod **)(this + 0x3c4) = pCVar6;
      }
      goto LAB_007e469b;
    }
  }
  if (*(CMwNod **)(this + 0x3c4) != (CMwNod *)0x0) {
    in_stack_000000e8 = (CSceneMobil *)0x7e4695;
    CMwNod::MwRelease(*(CMwNod **)(this + 0x3c4),(CMwNod *)in_stack_000000ec);
    *(undefined4 *)(this + 0x3c4) = 0;
  }
LAB_007e469b:
  in_stack_000000e8 = (CSceneMobil *)0xba133c;
  CVar2 = CMwId::CreateFromLocalName((char *)&stack0x00000104);
  in_stack_000000e8 = (CSceneMobil *)CONCAT31(extraout_var_14,CVar2);
  uStack00000110 = 0xf;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CSceneMobil::LinkFindFromObjectId
                     ((CSceneMobil *)this,in_stack_000000e8,(CMwId *)in_stack_000000ec);
  pvStack00000114 = (void *)0xffffffff;
  in_stack_000000ec = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e46cc;
  OnAccessViolation_ConcatToCrashFileName(pCVar14);
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    in_stack_000000e8 = (CSceneMobil *)0x7e46d9;
    in_stack_000000ec = pCVar3;
    pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x38,pCVar3,(ulong)pCVar14);
    pCVar1 = *(CSceneObjectLink **)pSVar4;
    if (pCVar1 != (CSceneObjectLink *)0x0) {
      in_stack_000000ec = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x7e46e8;
      CSceneObjectLink::SetIsActive(pCVar1,(CSceneObjectLink *)0x1,iVar15);
      pCVar6 = *(CMwNod **)(pCVar1 + 0x18);
      if (pCVar6 == *(CMwNod **)(this + 0x3c8)) {
        ExceptionList = pvStack00000114;
        return;
      }
      if (pCVar6 != (CMwNod *)0x0) {
        CMwNod::MwAddRef(pCVar6,in_stack_000000f8);
      }
      if (*(CMwNod **)(this + 0x3c8) != (CMwNod *)0x0) {
        in_stack_000000f8 = (CMwNod *)0x7e470d;
        CMwNod::MwRelease(*(CMwNod **)(this + 0x3c8),in_stack_000000fc);
      }
      *(CMwNod **)(this + 0x3c8) = pCVar6;
      ExceptionList = in_stack_00000118;
      return;
    }
  }
  if (*(CMwNod **)(this + 0x3c8) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x3c8),in_stack_000000f8);
    *(undefined4 *)(this + 0x3c8) = 0;
  }
  ExceptionList = pvStack00000114;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::RotationRadiusGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSceneToyBoat::RotationRadiusGet(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2)
{
{
  float fVar1;
  
  if (ABS((float)param_1) * _DAT_00d07bc8 <= _DAT_00ba1128) {
    return _DAT_00ba1220;
  }
  fVar1 = *(float *)(*(int *)(this + 0x84) + 0x40) / (ABS((float)param_1) * _DAT_00d07bc8) -
          (float)_DAT_00ba1218;
  if (fVar1 < 0.0) {
    return 0.0;
  }
  return fVar1;
}
}

// =================================================
// Function: CSceneToyBoat::SailManoeuvreGet
// =================================================
SSailManoeuvre __thiscall
CSceneToyBoat::SailManoeuvreGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  undefined4 *in_stack_00000008;
  undefined4 *in_stack_0000000c;
  
  pCVar1 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x1c8);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1bc,unaff_EDI);
  uVar2 = DAT_00d07bd0;
  if (pCVar4 <= pCVar1) {
    *in_stack_00000008 = DAT_00d07bcc;
    uVar3 = DAT_00d07bd4;
    in_stack_00000008[1] = uVar2;
    in_stack_00000008[2] = uVar3;
    return SUB41(in_stack_00000008,0);
  }
  pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                     (this + 0x1bc,pCVar1,unaff_ESI);
  *in_stack_0000000c = *(undefined4 *)pSVar5;
  uVar2 = *(undefined4 *)(pSVar5 + 8);
  in_stack_0000000c[1] = *(undefined4 *)(pSVar5 + 4);
  in_stack_0000000c[2] = uVar2;
  return SUB41(in_stack_0000000c,0);
}
}

// =================================================
// Function: CSceneToyBoat::SailManoeuvreStop
// =================================================
void __thiscall CSceneToyBoat::SailManoeuvreStop(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(this + 0x1bc,unaff_ESI);
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x1c8) = 0;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::SailManoeuvreUpdate
// =================================================
void __thiscall
CSceneToyBoat::SailManoeuvreUpdate(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2)
{
{
  CSceneToyBoat *this_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  ulong uVar7;
  SCasterCat *pSVar8;
  CManoeuvre *pCVar9;
  ulong unaff_EBX;
  SSailManoeuvre *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff4;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  CSceneToyBoat *in_stack_fffffffc;
  
  this_00 = this + 0x1bc;
  uVar1 = *(uint *)(this + 0x1c8);
  uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (uVar1 < uVar7) {
    *(float *)(this + 0x1cc) = *(float *)(this + 0x1cc) + param_2;
    uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
    if (uVar1 < uVar7) {
      do {
        pSVar8 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                                     (this + 0x1c8),unaff_EBX);
        iVar2 = *(int *)(pSVar8 + 4);
        iVar3 = *(int *)pSVar8;
        iVar4 = *(int *)(pSVar8 + 8);
        *(int *)(iVar3 + 0x8c) = iVar2;
        if (iVar2 == 2) {
          *(int *)(this + 0x130) = iVar3;
LAB_007e0d4f:
          *(int *)(this + 0x1c8) = *(int *)(this + 0x1c8) + 1;
        }
        else {
          if (iVar2 != 5) {
            unaff_EBX = 0x7e0cdb;
            pCVar9 = SSailManoeuvre::ManoeuvreGet(&stack0x00000000,unaff_EBP);
            fVar5 = *(float *)(this + 0x1cc) / *(float *)(pCVar9 + 0x18);
            fVar6 = 0.0;
            if ((fVar5 < 0.0 == (fVar5 == 0.0)) &&
               (fVar6 = fVar5, !NAN(fVar5) && 1.0 < fVar5 != (fVar5 == 1.0))) {
              fVar6 = 1.0;
            }
            *(float *)(iVar3 + 0x90) = fVar6;
            if (iVar4 != 0) {
              *(float *)(iVar3 + 0x90) = 1.0 - *(float *)(iVar3 + 0x90);
            }
            if (*(float *)(pCVar9 + 0x18) < *(float *)(this + 0x1cc)) {
              *(float *)(this + 0x1cc) = *(float *)(this + 0x1cc) - *(float *)(pCVar9 + 0x18);
              goto LAB_007e0d4f;
            }
            break;
          }
          *(int *)(this + 0x1c8) = *(int *)(this + 0x1c8) + 1;
          if (*(int *)(this + 0x130) == iVar3) {
            *(undefined4 *)(this + 0x130) = 0;
          }
        }
        unaff_EBP = (SSailManoeuvre *)0x7e0d5d;
        uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_fffffff4);
      } while (*(uint *)(this + 0x1c8) < uVar7);
    }
    uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_fffffff8);
    if (uVar7 <= *(uint *)(this + 0x1c8)) {
      SailManoeuvreStop(this,in_stack_fffffffc);
    }
    *(undefined4 *)(this + 0x138) = 0;
    *(undefined4 *)(this + 0x13c) = 0;
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::SailStateGet
// =================================================
CBoatSailState * __thiscall
CSceneToyBoat::SailStateGet(CSceneToyBoat *this,CSceneToyBoat *param_1,ESailType param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x124,pCVar3,unaff_ESI);
      if (*(ESailType *)(*(int *)(*(CBoatSailState **)pSVar2 + 0x14) + 0x18) == param_2) {
        return *(CBoatSailState **)pSVar2;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (CBoatSailState *)0x0;
}
}

// =================================================
// Function: CSceneToyBoat::SailSwitchTo
// =================================================
int __thiscall
CSceneToyBoat::SailSwitchTo(CSceneToyBoat *this,CSceneToyBoat *param_1,ESailType param_2)
{
{
  CSceneToyBoat *pCVar1;
  SSailManoeuvre SVar2;
  CBoatSailState *pCVar3;
  undefined3 extraout_var;
  SCasterCat *pSVar5;
  CManoeuvre *pCVar6;
  GmFrustumIso4 *unaff_EBX;
  ESailType EVar7;
  TiXmlAttributeSet *unaff_EBP;
  TiXmlAttribute *unaff_ESI;
  ESailType unaff_EDI;
  TiXmlAttribute *in_stack_ffffffe8;
  SSailManoeuvre *in_stack_ffffffec;
  CBoatSailState *local_10;
  CBoatSailState *local_c;
  CBoatSailState *local_8;
  ESailType local_4;
  int *piVar4;
  
  if (param_1 == (CSceneToyBoat *)0x0) {
    return 0;
  }
  pCVar3 = SailStateGet(this,param_1,unaff_EDI);
  SVar2 = SailManoeuvreGet(this,(CSceneToyBoat *)&local_8);
  piVar4 = (int *)CONCAT31(extraout_var,SVar2);
  if (((*piVar4 == DAT_00d07bcc) && (piVar4[1] == DAT_00d07bd0)) && (piVar4[2] == DAT_00d07bd4)) {
    param_2 = *(ESailType *)(this + 0x130);
    if (pCVar3 == (CBoatSailState *)param_2) {
      return 0;
    }
    pCVar1 = this + 0x1bc;
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,unaff_EBX);
    if (pCVar3 != (CBoatSailState *)0x0) {
      local_c = (CBoatSailState *)0x0;
      local_8 = (CBoatSailState *)0x0;
      local_10 = pCVar3;
      CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
                (pCVar1,(TiXmlAttributeSet *)&local_10,unaff_ESI);
      local_8 = (CBoatSailState *)0x1;
      local_4 = 0;
      unaff_EBX = (GmFrustumIso4 *)0x7e5be4;
      local_c = pCVar3;
      CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
                (pCVar1,(TiXmlAttributeSet *)&local_c,(TiXmlAttribute *)unaff_EBP);
      unaff_EBP = (TiXmlAttributeSet *)&local_8;
      local_4 = 2;
      unaff_ESI = (TiXmlAttribute *)0x7e5c00;
      local_8 = pCVar3;
      CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add(pCVar1,unaff_EBP,in_stack_ffffffe8);
    }
    EVar7 = param_2;
    if (param_2 == 0) goto LAB_007e5ca1;
    local_10 = (CBoatSailState *)0x3;
    local_c = (CBoatSailState *)0x0;
    CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
              (pCVar1,(TiXmlAttributeSet *)&stack0xffffffec,(TiXmlAttribute *)unaff_EBX);
    local_10 = (CBoatSailState *)EVar7;
    local_c = (CBoatSailState *)0x4;
    local_8 = (CBoatSailState *)0x0;
    CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
              (pCVar1,(TiXmlAttributeSet *)&local_10,unaff_ESI);
  }
  else {
    if (pCVar3 != *(CBoatSailState **)(this + 0x130)) {
      return 0;
    }
    pCVar1 = this + 0x1bc;
    pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                       (pCVar1,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x1c8),
                        (ulong)unaff_EBX);
    EVar7 = *(ESailType *)pSVar5;
    local_4 = EVar7;
    if (*(int *)(pSVar5 + 4) != 0) {
      if (*(int *)(pSVar5 + 4) != 1) {
        return 0;
      }
      CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,(GmFrustumIso4 *)unaff_ESI)
      ;
      local_8 = (CBoatSailState *)0x1;
      local_4 = 1;
      local_c = (CBoatSailState *)EVar7;
      CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
                (pCVar1,(TiXmlAttributeSet *)&local_c,(TiXmlAttribute *)unaff_EBP);
      local_4 = 5;
      local_8 = (CBoatSailState *)EVar7;
      CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
                (pCVar1,(TiXmlAttributeSet *)&local_8,in_stack_ffffffe8);
      *(undefined4 *)(this + 0x1c8) = 0;
      pCVar6 = SSailManoeuvre::ManoeuvreGet(&param_2,in_stack_ffffffec);
      *(float *)(this + 0x1cc) = *(float *)(pCVar6 + 0x18) - *(float *)(this + 0x1cc);
      return 1;
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset(pCVar1,(GmFrustumIso4 *)unaff_ESI);
  }
  local_8 = (CBoatSailState *)0x5;
  local_4 = 0;
  local_c = (CBoatSailState *)EVar7;
  CFastBuffer<struct_CSceneToyBoat::SSailManoeuvre>::Add
            (this + 0x1bc,(TiXmlAttributeSet *)&local_c,(TiXmlAttribute *)unaff_EBP);
LAB_007e5ca1:
  *(undefined4 *)(this + 0x1cc) = 0;
  *(undefined4 *)(this + 0x1c8) = 0;
  return 1;
}
}

// =================================================
// Function: CSceneToyBoat::SailTypeAfterManoeuvresGet
// =================================================
ESailType __thiscall
CSceneToyBoat::SailTypeAfterManoeuvresGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ESailType EVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneToyBoat *in_stack_00000008;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1bc,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (this + 0x1bc,pCVar4,unaff_ESI);
      if (*(int *)(pSVar2 + 4) == 2) {
        return *(ESailType *)(*(int *)(*(int *)pSVar2 + 0x14) + 0x18);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  EVar3 = SailTypeCurGet(this,in_stack_00000008);
  return EVar3;
}
}

// =================================================
// Function: CSceneToyBoat::SailTypeCurGet
// =================================================
ESailType __thiscall CSceneToyBoat::SailTypeCurGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  if (*(int *)(this + 0x130) != 0) {
    return *(ESailType *)(*(int *)(*(int *)(this + 0x130) + 0x14) + 0x18);
  }
  return 6;
}
}

// =================================================
// Function: CSceneToyBoat::SailTypeNextGet
// =================================================
ESailType __thiscall CSceneToyBoat::SailTypeNextGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  int iVar1;
  ESailType EVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  int extraout_ECX;
  ulong unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CSceneToyBoat *unaff_EDI;
  
  EVar2 = SailTypeCurGet(this,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(extraout_ECX + 0x1bc),unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar4 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         ((void *)(extraout_ECX + 0x1bc),pCVar5,unaff_EBP);
      if (((*(int *)pSVar4 != 0) && (iVar1 = *(int *)(*(int *)pSVar4 + 0x14), iVar1 != 0)) &&
         (*(ESailType *)(iVar1 + 0x18) != EVar2)) {
        return *(ESailType *)(*(int *)(*(int *)pSVar4 + 0x14) + 0x18);
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  return 6;
}
}

// =================================================
// Function: CSceneToyBoat::SolveContact
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CSceneToyBoat::SolveContact
          (GmVec3 *param_1,GmVec3 *param_2,GmVec3 *param_3,CSceneMobil *param_4,CSceneMobil *param_5
          )
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float unaff_EBX;
  CSceneMobil *pCVar7;
  CSceneMobil *pCVar8;
  float *pfVar9;
  GmVec3 *pGVar10;
  float10 fVar11;
  float *unaff_retaddr;
  SPlugFaceCull *pSVar12;
  GmIso4 *pGVar13;
  float fStack_8c;
  float local_88;
  float local_84;
  float local_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float local_6c;
  undefined4 local_68;
  float local_64 [4];
  float fStack_54;
  float fStack_48;
  float fStack_3c;
  GmVec3 aGStack_38 [4];
  float fStack_34;
  float fStack_30;
  float fStack_24;
  float fStack_18;
  float fStack_c;
  float *pfStack_4;
  
  local_80 = 0.0;
  local_84 = 0.0;
  local_88 = 0.0;
  local_64[0] = 0.0;
  local_68 = 0;
  local_6c = 0.0;
  pCVar7 = (CSceneMobil *)0x0;
  if ((param_4 != (CSceneMobil *)0x0) &&
     (iVar4 = (**(code **)(*(int *)param_4 + 0x10))(0xa100000), iVar4 != 0)) {
    pCVar7 = param_4;
  }
  pCVar8 = (CSceneMobil *)0x0;
  if ((param_5 != (CSceneMobil *)0x0) &&
     (iVar4 = (**(code **)(*(int *)param_5 + 0x10))(0xa100000), iVar4 != 0)) {
    pCVar8 = param_5;
  }
  pGVar13 = (GmIso4 *)0x0;
  pfVar5 = (float *)(**(code **)(*(int *)param_4 + 0x7c))();
  pfVar9 = local_64;
  for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar9 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar9 = pfVar9 + 1;
  }
  pSVar12 = (SPlugFaceCull *)0x0;
  puVar6 = (undefined4 *)(**(code **)(*(int *)param_4 + 0x7c))();
  pGVar10 = aGStack_38;
  for (iVar4 = 0xc; pfVar5 = pfStack_4, iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pGVar10 = *puVar6;
    puVar6 = puVar6 + 1;
    pGVar10 = pGVar10 + 4;
  }
  if (pCVar7 != (CSceneMobil *)0x0) {
    fVar1 = *(float *)(pCVar7 + 0xdc);
    unaff_EBX = *(float *)(pCVar7 + 0x3d8) + fVar1 * local_64[1];
    fStack_8c = *(float *)(pCVar7 + 0x3dc) + fStack_54 * fVar1;
    local_88 = *(float *)(pCVar7 + 0x3e0) + fVar1 * fStack_48;
  }
  if (pCVar8 != (CSceneMobil *)0x0) {
    fVar1 = *(float *)(pCVar8 + 0xdc);
    fStack_74 = *(float *)(pCVar8 + 0x3d8) + fVar1 * fStack_30;
    fStack_70 = *(float *)(pCVar8 + 0x3dc) + fStack_24 * fVar1;
    local_6c = *(float *)(pCVar8 + 0x3e0) + fVar1 * fStack_18;
  }
  local_80 = fStack_74 - unaff_EBX;
  fStack_7c = fStack_70 - fStack_8c;
  fStack_78 = local_6c - local_88;
  local_84 = fStack_78 * *(float *)(param_1 + 8) +
             fStack_7c * *(float *)(param_1 + 4) + *(float *)param_1 * local_80;
  if (0.0 < local_84) {
    local_84 = local_84 * _DAT_00d07bbc;
    fVar1 = local_84;
    if (pCVar7 != (CSceneMobil *)0x0) {
      fStack_8c = local_84 * *(float *)(param_1 + 4);
      local_88 = local_84 * *(float *)(param_1 + 8);
      GmVec3::SetMultTranspose
                (&local_80,(GmVec3 *)&stack0xffffff70,(GmVec3 *)&local_68,(GmMat3 *)pSVar12);
      pSVar12 = (SPlugFaceCull *)local_64;
      *(float *)(pCVar7 + 0xdc) = *(float *)(pCVar7 + 0xdc) + fStack_74;
      fStack_74 = 0.0;
      GmVec3::SetMult(&fStack_8c,(SPlugFaceCull *)&fStack_7c,pSVar12,pGVar13);
      *(float *)(pCVar7 + 0x3d8) = local_88 + *(float *)(pCVar7 + 0x3d8);
      *(float *)(pCVar7 + 0x3dc) = *(float *)(pCVar7 + 0x3dc) + (float)_PTR_00b2c178;
      *(float *)(pCVar7 + 0x3e0) = local_80 + *(float *)(pCVar7 + 0x3e0);
      fVar2 = *pfVar5;
      fVar3 = pfVar5[2];
      fStack_8c = (fVar3 - fStack_34) * local_88 - local_80 * (fVar2 - fStack_3c);
      *(float *)(pCVar7 + 0x3fc) = fStack_8c * _DAT_00d07bb8;
      fVar1 = fStack_7c;
      local_88 = fVar2 - fStack_3c;
      local_80 = fVar3 - fStack_34;
    }
    if (pCVar8 != (CSceneMobil *)0x0) {
      fStack_8c = -fVar1 * *(float *)(param_1 + 4);
      local_88 = -fVar1 * *(float *)(param_1 + 8);
      GmVec3::SetMultTranspose(&local_80,(GmVec3 *)&stack0xffffff70,aGStack_38,(GmMat3 *)pSVar12);
      *(float *)(pCVar8 + 0xdc) = *(float *)(pCVar8 + 0xdc) + fStack_74;
      fStack_74 = 0.0;
      GmVec3::SetMult(&fStack_8c,(SPlugFaceCull *)&fStack_7c,(SPlugFaceCull *)&fStack_34,pGVar13);
      *(float *)(pCVar8 + 0x3d8) = local_88 + *(float *)(pCVar8 + 0x3d8);
      *(float *)(pCVar8 + 0x3dc) = *(float *)(pCVar8 + 0x3dc) + (float)_PTR_00b2c178;
      *(float *)(pCVar8 + 0x3e0) = local_80 + *(float *)(pCVar8 + 0x3e0);
      fVar1 = *pfVar5;
      fVar2 = pfVar5[2];
      fStack_8c = (fVar2 - (float)pfStack_4) * local_88 - local_80 * (fVar1 - fStack_c);
      *(float *)(pCVar8 + 0x3fc) = fStack_8c * _DAT_00d07bb8;
      local_88 = fVar1 - fStack_c;
      local_80 = fVar2 - (float)pfStack_4;
    }
  }
  fVar1 = (float)_DAT_00b43310;
  if (pCVar7 != (CSceneMobil *)0x0) {
    *(float *)(pCVar7 + 0x3e4) = *unaff_retaddr + *(float *)(pCVar7 + 0x3e4);
    *(float *)(pCVar7 + 1000) = unaff_retaddr[1] + *(float *)(pCVar7 + 1000);
    *(float *)(pCVar7 + 0x3ec) = unaff_retaddr[2] + *(float *)(pCVar7 + 0x3ec);
    if (_DAT_00ba12e4 <
        *(float *)(pCVar7 + 0x3ec) * *(float *)(pCVar7 + 0x3ec) +
        *(float *)(pCVar7 + 0x3e4) * *(float *)(pCVar7 + 0x3e4) +
        *(float *)(pCVar7 + 1000) * *(float *)(pCVar7 + 1000)) {
      if (_DAT_00d07bc0 <
          *(float *)(pCVar7 + 0x3ec) * *(float *)(pCVar7 + 0x3ec) +
          *(float *)(pCVar7 + 0x3e4) * *(float *)(pCVar7 + 0x3e4) +
          *(float *)(pCVar7 + 1000) * *(float *)(pCVar7 + 1000)) {
        fVar11 = (float10)func_0x009c1b40();
        fVar1 = 1.0 / (float)fVar11;
        *(float *)(pCVar7 + 0x3e4) = fVar1 * *(float *)(pCVar7 + 0x3e4);
        *(float *)(pCVar7 + 1000) = *(float *)(pCVar7 + 1000) * fVar1;
        *(float *)(pCVar7 + 0x3ec) = fVar1 * *(float *)(pCVar7 + 0x3ec);
        fVar1 = (float)_DAT_00b43310;
      }
      *(float *)(pCVar7 + 0x3e4) = *(float *)(pCVar7 + 0x3e4) * fVar1;
      *(float *)(pCVar7 + 1000) = *(float *)(pCVar7 + 1000) * fVar1;
      *(float *)(pCVar7 + 0x3ec) = *(float *)(pCVar7 + 0x3ec) * fVar1;
    }
    *(undefined4 *)(pCVar7 + 0x400) = 1;
  }
  if (pCVar8 == (CSceneMobil *)0x0) {
    return;
  }
  *(float *)(pCVar8 + 0x3e4) = *(float *)(pCVar8 + 0x3e4) - *unaff_retaddr;
  *(float *)(pCVar8 + 1000) = *(float *)(pCVar8 + 1000) - unaff_retaddr[1];
  *(float *)(pCVar8 + 0x3ec) = *(float *)(pCVar8 + 0x3ec) - unaff_retaddr[2];
  if (*(float *)(pCVar8 + 0x3ec) * *(float *)(pCVar8 + 0x3ec) +
      *(float *)(pCVar8 + 0x3e4) * *(float *)(pCVar8 + 0x3e4) +
      *(float *)(pCVar8 + 1000) * *(float *)(pCVar8 + 1000) <= _DAT_00ba12e4) {
    *(undefined4 *)(pCVar8 + 0x400) = 1;
    return;
  }
  if (_DAT_00d07bc0 <
      *(float *)(pCVar8 + 0x3ec) * *(float *)(pCVar8 + 0x3ec) +
      *(float *)(pCVar8 + 0x3e4) * *(float *)(pCVar8 + 0x3e4) +
      *(float *)(pCVar8 + 1000) * *(float *)(pCVar8 + 1000)) {
    fVar11 = (float10)func_0x009c1b40();
    fVar1 = 1.0 / (float)fVar11;
    *(float *)(pCVar8 + 0x3e4) = fVar1 * *(float *)(pCVar8 + 0x3e4);
    *(float *)(pCVar8 + 1000) = fVar1 * *(float *)(pCVar8 + 1000);
    *(float *)(pCVar8 + 0x3ec) = fVar1 * *(float *)(pCVar8 + 0x3ec);
    fVar1 = (float)_DAT_00b43310;
  }
  *(float *)(pCVar8 + 0x3e4) = *(float *)(pCVar8 + 0x3e4) * fVar1;
  *(float *)(pCVar8 + 1000) = *(float *)(pCVar8 + 1000) * fVar1;
  *(float *)(pCVar8 + 0x3ec) = fVar1 * *(float *)(pCVar8 + 0x3ec);
  *(undefined4 *)(pCVar8 + 0x400) = 1;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::TillerAngleNormedGet
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall CSceneToyBoat::TillerAngleNormedGet(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  return *(float *)(this + 0x118) / _DAT_00d07bc8;
}
}

// =================================================
// Function: CSceneToyBoat::UpdateBoatPhysics
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::UpdateBoatPhysics
          (CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3)
{
{
  GmVec2 *pGVar1;
  void *this_00;
  ulong *puVar2;
  ESailType EVar3;
  undefined4 uVar4;
  CMotionManager *this_01;
  undefined4 *puVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  SCasterCat *pSVar7;
  int iVar8;
  CSceneToyBoat *this_02;
  int extraout_EDX;
  int extraout_EDX_00;
  CSceneToyBoat *unaff_EBX;
  ulong unaff_EBP;
  CSceneToyBoat *unaff_ESI;
  CSceneToyBoat *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CMwTimerAdapter *unaff_EDI;
  CSceneToyBoat *pCVar11;
  float fVar12;
  float fVar13;
  CSceneToyBoat *in_stack_00000014;
  float in_stack_00000018;
  CSceneToyBoat *in_stack_0000001c;
  CSceneToyBoat *in_stack_00000020;
  CSceneToyBoat *in_stack_00000024;
  float *pfVar14;
  float in_stack_ffffffec;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff0;
  CSceneToyBoat *in_stack_fffffff4;
  GmIso4 *in_stack_fffffff8;
  GmIso4 *pGVar15;
  
  pCVar9 = this + 0x2c4;
  pCVar11 = this + 0x238;
  for (iVar8 = 0x23; iVar8 != 0; iVar8 = iVar8 + -1) {
    *(undefined4 *)pCVar11 = *(undefined4 *)pCVar9;
    pCVar9 = pCVar9 + 4;
    pCVar11 = pCVar11 + 4;
  }
  this_00 = *(void **)(DAT_00d731e0 + 0x14);
  if (this_00 == (void *)0x0) {
    this_00 = (void *)(DAT_00d731e0 + 0xa0);
  }
  iVar8 = *(int *)(this + 0x28);
  puVar2 = CMwTimerAdapter::GetTickTime(this_00,unaff_EDI);
  *(ulong *)(iVar8 + 0x48) = *puVar2;
  if (*(int *)(this + 0x168) != 0) {
    EVar3 = SailTypeCurGet(this,unaff_ESI);
    iVar8 = extraout_EDX;
    if ((EVar3 == 2) ||
       (EVar3 = SailTypeCurGet(this_02,unaff_EBX), iVar8 = extraout_EDX_00, EVar3 == 5)) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    *(undefined4 *)(iVar8 + 0xb8) = uVar4;
    *(undefined4 *)(*(int *)(this + 0x168) + 0xcc) = *(undefined4 *)(this + 0xd8);
    *(undefined4 *)(*(int *)(this + 0x168) + 0xd0) = *(undefined4 *)(this + 0xdc);
  }
  this_01 = CScene::GetManager(*(CScene **)(this + 0x14),(CScene *)0x8052000,unaff_EBP);
  fVar13 = in_stack_00000018;
  pGVar15 = (GmIso4 *)0x0;
  if (this_01 != (CMotionManager *)0x0) {
    pfVar14 = *(float **)(this + 0x168);
    param_1 = *(CSceneToyBoat **)((int)in_stack_00000018 + 0x24);
    param_2 = *(float *)((int)in_stack_00000018 + 0x2c);
    pCVar9 = this + 0xa0;
    pGVar1 = (GmVec2 *)(this + 0x8c);
    CMotionManagerMeteo::WindGetDirectionAndIntensityAt
              ((CMotionManagerMeteo *)this_01,(CMotionManagerMeteo *)&param_1,pGVar1,
               (float *)(this + 0x88),(float *)pCVar9,(CMotionWindBlocker *)(this + 0x9c));
    fVar12 = GmFunc::Mod(-*(float *)pGVar1,_DAT_00b5b910,_DAT_00ba112c);
    *(float *)pGVar1 = fVar12;
    fVar12 = GmFunc::Mod(-*(float *)pCVar9,_DAT_00b5b910,_DAT_00ba112c);
    *(float *)pCVar9 = fVar12;
    param_1 = *(CSceneToyBoat **)((int)fVar13 + 0x2c);
    pGVar1 = (GmVec2 *)(this + 0xbc);
    CMotionManagerMeteo::StreamGetDirectionAndIntensityAt
              ((CMotionManagerMeteo *)in_stack_fffffff8,(CMotionManagerMeteo *)&stack0x00000000,
               pGVar1,(float *)(this + 0xb8),pfVar14);
    pGVar15 = (GmIso4 *)((float)_DAT_00b36110 - *(float *)pGVar1);
    fVar13 = GmFunc::Mod((float)pGVar15,_DAT_00b5b910,_DAT_00ba112c);
    *(float *)pGVar1 = fVar13;
  }
  UpdateNavValues(this,in_stack_00000014,in_stack_ffffffec);
  if (_DAT_00ba1128 < ABS(*(float *)(this + 0x11c) - *(float *)(this + 0x118))) {
    in_stack_00000018 = *(float *)(*(int *)(this + 0x84) + 0x20) * in_stack_00000018;
    param_1 = *(CSceneToyBoat **)(this + 0x11c);
    pCVar9 = (CSceneToyBoat *)(*(float *)(this + 0x118) - in_stack_00000018);
    param_2 = in_stack_00000018 + *(float *)(this + 0x118);
    if (((float)pCVar9 < (float)param_1) &&
       (pCVar9 = param_1, param_2 < (float)param_1 != (param_2 == (float)param_1))) {
      pCVar9 = (CSceneToyBoat *)param_2;
    }
    *(CSceneToyBoat **)(this + 0x118) = pCVar9;
  }
  if (*(int *)(this + 0x134) != 0) {
    puVar5 = DAT_00d739e4;
    if (*(int *)(this + 0x130) != 0) {
      puVar5 = (undefined4 *)(*(int *)(*(int *)(this + 0x130) + 0x14) + 0x7c);
    }
    *(undefined4 *)(*(int *)(this + 0x134) + 0x94) = *puVar5;
  }
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x124,in_stack_fffffff0);
  pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar6 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x124,pCVar10,(ulong)in_stack_fffffff4);
      in_stack_fffffff4 = in_stack_00000020;
      CBoatSailState::UpdateSailPhysics
                (*(CBoatSailState **)pSVar7,*(CBoatSailState **)(this + 0x94),
                 *(float *)(this + 0xb0),*(float *)(this + 0x10c),(float)in_stack_00000020,
                 (float)in_stack_fffffff8);
      pCVar10 = pCVar10 + 1;
    } while (pCVar10 < pCVar6);
  }
  pCVar9 = in_stack_00000020;
  ComputePitchinLocation
            (this,in_stack_0000001c,(float)in_stack_00000020,(GmIso4 *)in_stack_fffffff4);
  UpdateHeel(this,in_stack_00000020,(float)pCVar9,in_stack_fffffff8);
  Move(this,in_stack_00000024,(float)pCVar9,pGVar15);
  if (*(int *)(this + 0x35c) != 0) {
    UpdateSounds(this,param_1);
  }
  param_1 = this;
  SSceneToyBoat_ReplayState::SetFromBoat
            (in_stack_00000024,(SSceneToyBoat_NetState *)this,(CSceneToyBoat *)param_2);
  return;
}
}

// =================================================
// Function: CSceneToyBoat::UpdateFromDynamicState
// =================================================
void __thiscall
CSceneToyBoat::UpdateFromDynamicState
          (CSceneToyBoat *this,CSceneToyBoat *param_1,CClassicBufferMemory *param_2,ulong param_3,
          ulong param_4)
{
{
  ulong unaff_ESI;
  ulong unaff_EDI;
  
  (**(code **)(*(int *)param_1 + 0x14))();
  SSceneToyBoat_NetState::RestoreFromBuffer
            (&DAT_00d6e180,(SSceneToyBoat_NetState *)param_1,(CClassicBufferMemory *)param_3,
             unaff_EDI);
  if (*(int *)(this + 0x14) != 0) {
    SSceneToyBoat_NetState::ApplyExtrapolatedStateToBoat
              (&DAT_00d6e180,(SSceneToyBoat_NetState *)this,(CSceneToyBoat *)param_3,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::UpdateHeel
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::UpdateHeel(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3)
{
{
  CBoatSail *pCVar1;
  double dVar2;
  CBoatSailState *this_00;
  int iVar3;
  GmVec3 *unaff_EBX;
  float unaff_EBP;
  CMwId *unaff_ESI;
  float *pfVar4;
  float unaff_EDI;
  float *pfVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float fVar7;
  float in_stack_00000010;
  float *in_stack_00000014;
  float in_stack_0000001c;
  float in_stack_0000002c;
  CBoatSail *pCVar8;
  CBoatSail *pCVar9;
  CBoatSail *in_stack_ffffff28;
  GmVec3 *in_stack_ffffff2c;
  GmVec3 *pGVar10;
  CBoatSail *in_stack_ffffff30;
  float fVar11;
  float fVar12;
  float fVar13;
  float in_stack_ffffff44;
  GmMat2 *local_b4;
  float fStack_b0;
  float fStack_ac;
  CBoatSail *pCStack_a8;
  float local_a4;
  GmIso4 *apGStack_a0 [2];
  GmIso4 *pGStack_98;
  undefined1 local_94 [4];
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  GmIso4 *pGStack_7c;
  float fStack_78;
  float fStack_74;
  CMwCmdScriptVarBool *pCStack_70;
  float local_6c;
  GmVec3 *pGStack_68;
  GmVec3 *pGStack_64;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  float afStack_44 [4];
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  GmIso4 *pGStack_24;
  float fStack_20;
  float fStack_1c;
  float local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  undefined1 auStack_c [12];
  
  if (*(int *)(*(int *)(this + 0x84) + 0xbc) == 0) {
    this_00 = *(CBoatSailState **)(this + 0x134);
    if (this_00 == (CBoatSailState *)0x0) goto LAB_007df967;
    pCVar9 = *(CBoatSail **)(this + 0xb0);
    pCVar8 = *(CBoatSail **)(this + 0x98);
    pCVar1 = *(CBoatSail **)(this + 0x94);
    in_stack_ffffff28 = pCVar9;
    in_stack_ffffff30 = pCVar8;
  }
  else {
    this_00 = *(CBoatSailState **)(this + 0x130);
    if ((this_00 == (CBoatSailState *)0x0) &&
       (this_00 = *(CBoatSailState **)(this + 0x134), this_00 == (CBoatSailState *)0x0))
    goto LAB_007df967;
    pCVar9 = *(CBoatSail **)(this + 0xb0);
    pCVar8 = *(CBoatSail **)(this + 0x98);
    pCVar1 = *(CBoatSail **)(this + 0x94);
    in_stack_ffffff28 = pCVar1;
    in_stack_ffffff30 = pCVar9;
  }
  CBoatSailState::HeelGet(this_00,pCVar1,(float)pCVar8,(float)pCVar9,unaff_EDI,unaff_ESI,unaff_EBP);
LAB_007df967:
  iVar3 = *(int *)(this + 0x84);
  *(float *)(this + 0x114) = *(float *)(this + 0x114) + in_stack_00000010;
  fVar12 = *(float *)(this + 0x94) * (float)_DAT_00b87260 * (float)_DAT_00b5b9c0 +
           (float)_DAT_00b4fbd0;
  __CIsin();
  fVar7 = *(float *)(iVar3 + 0x70);
  pfVar4 = in_stack_00000014;
  pfVar5 = &local_6c;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  fVar7 = fVar7 * fVar12 * (float)extraout_ST0;
  pfVar4 = &local_6c;
  pfVar5 = &local_18;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar5 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    pfVar5 = pfVar5 + 1;
  }
  GmMat3::GetLine(&local_18,(GmMat3 *)0x0,(ulong)local_94,unaff_EBX);
  GmMat3::GetLine(local_14,(GmMat3 *)0x1,(ulong)&local_b4,(GmVec3 *)in_stack_ffffff28);
  GmMat3::GetLine(local_10,(GmMat3 *)0x2,(ulong)&local_a4,in_stack_ffffff2c);
  fVar6 = (float10)func_0x009c1d90();
  fVar12 = (float)fVar6;
  if ((float)pCStack_a8 < 0.0) {
    dVar2 = _DAT_00b5b918;
    if (0.0 <= fVar12) {
      dVar2 = _DAT_00b36110;
    }
    fVar12 = (float)dVar2 - fVar12;
  }
  fVar12 = *(float *)(*(int *)(this + 0x84) + 0x6c) * *(float *)(this + 0x110) +
           ((float)local_b4 - fVar12) * *(float *)(*(int *)(this + 0x84) + 0x68);
  *(float *)(this + 0x110) = fVar12;
  local_b4 = (GmMat2 *)(fVar12 * in_stack_0000001c);
  pGStack_7c = apGStack_a0[0];
  fStack_78 = 0.0;
  fStack_74 = (float)pGStack_98;
  fVar12 = (float)pGStack_98 * (float)pGStack_98 +
           (float)apGStack_a0[0] * (float)apGStack_a0[0] + 0.0;
  if (_DAT_00d07bc0 < fVar12) {
    fStack_78 = (float)0;
    fVar6 = (float10)func_0x009c1b40();
    fVar12 = 1.0 / (float)fVar6;
    pGStack_7c = (GmIso4 *)(fVar12 * (float)apGStack_a0[0]);
    fStack_78 = (float)_PTR_00b2c178 * fVar12;
    fStack_74 = fVar12 * (float)pGStack_98;
  }
  GmQuat::SetRotation(&pCStack_70,local_b4,(float)&pGStack_7c);
  GmMat3::Set(&fStack_30,pCStack_70,(int)local_6c);
  fVar13 = fStack_90 * fStack_2c + fStack_8c * fStack_28 + fStack_88 * (float)pGStack_24;
  fVar11 = local_18 * fStack_88 + fStack_1c * fStack_8c + fStack_20 * fStack_90;
  fStack_90 = fStack_88 * fStack_30 + afStack_44[3] * fStack_90 + fStack_34 * fStack_8c;
  local_b4 = (GmMat2 *)(fVar11 * local_a4 - (float)apGStack_a0[0] * fVar13);
  fStack_b0 = fStack_90 * (float)apGStack_a0[0] - (float)pCStack_a8 * fVar11;
  fStack_ac = (float)pCStack_a8 * fVar13 - fStack_90 * local_a4;
  fVar13 = fStack_b0 * fStack_b0 + (float)local_b4 * (float)local_b4 + fStack_ac * fStack_ac;
  pGVar10 = pGStack_64;
  if (_DAT_00d07bc0 < fVar13) {
    fVar6 = (float10)func_0x009c1b40();
    fVar13 = 1.0 / (float)fVar6;
    local_b4 = (GmMat2 *)(fVar13 * (float)local_b4);
    fStack_b0 = fVar13 * fStack_b0;
    fStack_ac = fVar13 * fStack_ac;
    pGVar10 = pGStack_64;
  }
  fStack_90 = fStack_b0 * (float)apGStack_a0[0] - fStack_ac * local_a4;
  fStack_8c = (float)pCStack_a8 * fStack_ac - (float)local_b4 * (float)apGStack_a0[0];
  fStack_88 = (float)local_b4 * local_a4 - (float)pCStack_a8 * fStack_b0;
  GmMat3::SetLine(local_14,(GmMat3 *)0x0,(ulong)&fStack_90,pGStack_68);
  GmMat3::SetLine(local_10,(GmMat3 *)0x1,(ulong)&fStack_b0,pGVar10);
  GmMat3::SetLine(auStack_c,(GmMat3 *)0x2,(ulong)apGStack_a0,(GmVec3 *)in_stack_ffffff30);
  pCVar9 = (CBoatSail *)(fStack_b0 + (float)local_b4);
  iVar3 = *(int *)(this + 0x130);
  *(CBoatSail **)(this + 0x10c) = pCVar9;
  if ((iVar3 != 0) || (iVar3 = *(int *)(this + 0x134), iVar3 != 0)) {
    in_stack_ffffff44 = *(float *)(this + 0x98);
    local_b4 = *(GmMat2 **)(this + 0x94);
    fStack_b0 = CBoatSail::LuffAngleSpeedGet
                          (*(CBoatSail **)(iVar3 + 0x14),(CBoatSail *)local_b4,in_stack_ffffff44,
                           *(float *)(this + 0xb0),(float)(iVar3 + 0x94),(CMwId *)pCVar9,
                           *(float *)(iVar3 + 0x84),fVar7);
    local_b4 = *(GmMat2 **)(this + 0x98);
    pCVar9 = *(CBoatSail **)(this + 0xdc);
    local_a4 = CBoatSail::RevolveAngleSpeedGet
                         (*(CBoatSail **)(iVar3 + 0x14),pCVar9,(float)local_b4,fVar11);
    if (*(int *)(this + 0x138) != 0) {
      fStack_b0 = *(float *)(this + 0xb0);
      local_b4 = *(GmMat2 **)(this + 0x98);
      pCStack_a8 = *(CBoatSail **)(this + 0x94);
      fVar7 = CBoatSail::LuffAngleSpeedGet
                        (*(CBoatSail **)(*(int *)(this + 0x138) + 0x14),pCStack_a8,(float)local_b4,
                         fStack_b0,(float)(iVar3 + 0x94),*(CMwId **)(this + 0x10c),
                         *(float *)(iVar3 + 0x84),fVar13);
      fStack_ac = ABS((float)pCStack_a8);
      if (fStack_ac < ABS(fVar7 * *(float *)(this + 0x13c))) {
        pCStack_a8 = (CBoatSail *)(fVar7 * *(float *)(this + 0x13c));
      }
    }
    apGStack_a0[0] = (GmIso4 *)(((float)apGStack_a0[0] + (float)pCStack_a8) * in_stack_0000002c);
    GmMat3::RotateY(&param_1,apGStack_a0[0],fVar12);
  }
  GmIso4::SetRotation(auStack_4c,(GmMat2 *)&param_2,in_stack_ffffff44);
  iVar3 = *(int *)(this + 0x84);
  apGStack_a0[0] = (GmIso4 *)ABS(*(float *)(this + 0x10c));
  pGStack_98 = apGStack_a0[0];
  if (*(int *)(iVar3 + 0x14) == 1) {
    pGStack_7c = pGStack_24;
    fStack_78 = fStack_20;
    fStack_74 = fStack_1c;
    __CIsin();
    pGStack_98 = (GmIso4 *)
                 ((float)extraout_ST0_01 * (float)_DAT_00b313b8 * *(float *)(iVar3 + 0x18));
    if ((float)pGStack_98 <= 0.0) {
      GmIso4::SetTranslation(auStack_48,(GmIso4 *)&pGStack_7c,(GmVec3 *)pCVar9);
    }
    else {
      fStack_78 = (float)pGStack_98;
      if (*(int *)(this + 0x164) != 0) {
        fStack_78 = (float)pGStack_98 + fStack_20;
      }
      GmIso4::SetTranslation(auStack_48,(GmIso4 *)&pGStack_7c,(GmVec3 *)pCVar9);
    }
  }
  else if (*(int *)(iVar3 + 0x14) == 2) {
    pGStack_7c = pGStack_24;
    fStack_78 = fStack_20;
    fStack_74 = fStack_1c;
    __CIsin();
    pGStack_98 = (GmIso4 *)
                 ((float)extraout_ST0_00 * (float)_DAT_00b313b8 * *(float *)(iVar3 + 0x18) -
                 *(float *)(iVar3 + 0x1c));
    if (0.0 < (float)pGStack_98) {
      fStack_78 = (float)pGStack_98;
      if (*(int *)(this + 0x164) != 0) {
        fStack_78 = (float)pGStack_98 + fStack_20;
      }
      GmIso4::SetTranslation(auStack_48,(GmIso4 *)&pGStack_7c,(GmVec3 *)pCVar9);
    }
  }
  pfVar4 = afStack_44;
  for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
    *in_stack_00000014 = *pfVar4;
    pfVar4 = pfVar4 + 1;
    in_stack_00000014 = in_stack_00000014 + 1;
  }
  return;
}
}

// =================================================
// Function: CSceneToyBoat::UpdateNavValues
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSceneToyBoat::UpdateNavValues(CSceneToyBoat *this,CSceneToyBoat *param_1,float param_2)
{
{
  float fVar1;
  int iVar2;
  float fVar3;
  ulong uVar4;
  uint uVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  uint uVar6;
  GmVec2 *unaff_EBP;
  GmVec2 *unaff_ESI;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  GmVec2 *unaff_EDI;
  float10 extraout_ST0;
  float10 fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fStack0000000c;
  GmVec2 *pGVar15;
  float local_40;
  float local_3c;
  float local_34;
  undefined4 local_10;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  fVar14 = *(float *)(this + 0xd8);
  fVar1 = *(float *)(this + 0xd8);
  local_8 = 0x3f800000;
  local_4 = fVar1;
  PolarToVskCartesian(unaff_EDI,unaff_ESI);
  fVar3 = *(float *)(this + 0xdc) * 1.0;
  fVar1 = *(float *)(this + 0xdc) * fVar1;
  local_8 = *(undefined4 *)(this + 0xb8);
  fVar12 = *(float *)(this + 0xbc);
  local_4 = fVar12;
  PolarToVskCartesian(unaff_EDI,unaff_ESI);
  local_8 = *(undefined4 *)(this + 0x88);
  local_4 = *(float *)(this + 0x8c);
  PolarToVskCartesian(unaff_EDI,unaff_ESI);
  local_8 = *(undefined4 *)(this + 0x9c);
  local_4 = *(float *)(this + 0xa0);
  PolarToVskCartesian(unaff_EDI,unaff_ESI);
  VskCartesianToPolar(unaff_EDI,unaff_ESI);
  local_3c = --(-local_34 - fVar12);
  VskCartesianToPolar(unaff_EDI,unaff_ESI);
  VskCartesianToPolar(unaff_EDI,unaff_ESI);
  *(float *)(this + 0xb4) = fVar3;
  fVar12 = GmFunc::Mod(fVar1 - fVar14,_DAT_00b5b910,_DAT_00ba112c);
  *(float *)(this + 0xb0) = fVar12;
  *(undefined4 *)(this + 0x94) = local_10;
  fVar12 = GmFunc::Mod(local_c,_DAT_00b5b910,_DAT_00ba112c);
  *(float *)(this + 0x90) = fVar12;
  fVar12 = GmFunc::Mod(local_c - fVar14,_DAT_00b5b910,_DAT_00ba112c);
  *(float *)(this + 0x98) = fVar12;
  *(undefined4 *)(this + 0xa8) = local_8;
  fVar13 = GmFunc::Mod(local_4,_DAT_00b5b910,_DAT_00ba112c);
  *(float *)(this + 0xa4) = fVar13;
  pGVar15 = (GmVec2 *)(local_4 - fVar14);
  fVar14 = GmFunc::Mod((float)pGVar15,_DAT_00b5b910,_DAT_00ba112c);
  *(float *)(this + 0xac) = fVar14;
  *(uint *)(this + 0x1ac) = (uint)(0.0 <= fVar12);
  *(uint *)(this + 0x1b0) = (uint)(ABS(fVar12) < (float)_DAT_00b36be8);
  __CIcos();
  *(float *)(this + 0x100) = (float)extraout_ST0 * *(float *)(this + 0xdc);
  fVar14 = *(float *)(this + 0xf8);
  *(float *)(this + 0xf8) = fVar14 - (float)param_1;
  if (fVar14 - (float)param_1 <= 0.0) {
    local_8 = *(undefined4 *)(this + 0xdc);
    local_4 = *(float *)(this + 0xd8);
    PolarToVskCartesian(unaff_EDI,unaff_ESI);
    CFastBufferWheel<class_GmVec2>::Push
              (this + 0xe4,(CFastBufferWheel<float> *)&local_8,(float *)unaff_EDI);
    fVar14 = *(float *)(this + 0xf8);
    fVar12 = (float)_DAT_00b43310;
    *(float *)(this + 0xf8) = fVar14 + fVar12;
    if (fVar14 + fVar12 <= 0.0) {
      *(undefined4 *)(this + 0xf8) = _DAT_00b33a54;
    }
  }
  local_40 = 0.0;
  uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0xe4,unaff_EBX);
  uVar6 = 0;
  if (3 < (int)uVar4) {
    uVar5 = *(uint *)(this + 0xec);
    do {
      uVar10 = *(int *)(this + 0xf0) + uVar6;
      uVar7 = uVar10;
      if (uVar5 <= uVar10) {
        uVar7 = uVar10 - uVar5;
      }
      iVar2 = *(int *)(this + 0xe8);
      uVar8 = uVar10 + 1;
      if (uVar5 <= uVar8) {
        uVar8 = uVar8 - uVar5;
      }
      uVar9 = uVar10 + 2;
      if (uVar5 <= uVar9) {
        uVar9 = uVar9 - uVar5;
      }
      uVar10 = uVar10 + 3;
      if (uVar5 <= uVar10) {
        uVar10 = uVar10 - uVar5;
      }
      uVar6 = uVar6 + 4;
      local_40 = local_40 + *(float *)(iVar2 + uVar7 * 8) + *(float *)(iVar2 + uVar8 * 8) +
                 *(float *)(iVar2 + uVar9 * 8) + *(float *)(iVar2 + uVar10 * 8);
      local_3c = *(float *)(iVar2 + 4 + uVar10 * 8) +
                 *(float *)(iVar2 + 4 + uVar9 * 8) +
                 *(float *)(iVar2 + 4 + uVar8 * 8) + *(float *)(iVar2 + 4 + uVar7 * 8) + local_3c;
    } while (uVar6 < uVar4 - 3);
  }
  if (uVar6 < uVar4) {
    do {
      uVar5 = *(int *)(this + 0xf0) + uVar6;
      if (*(uint *)(this + 0xec) <= uVar5) {
        uVar5 = uVar5 - *(uint *)(this + 0xec);
      }
      local_40 = local_40 + *(float *)(*(int *)(this + 0xe8) + uVar5 * 8);
      uVar6 = uVar6 + 1;
      local_3c = *(float *)(*(int *)(this + 0xe8) + uVar5 * 8 + 4) + local_3c;
    } while (uVar6 < uVar4);
  }
  fVar14 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    fVar14 = fVar14 + _DAT_00c418d0;
  }
  fVar14 = 1.0 / (fVar14 + (float)_DAT_00b362c0);
  local_40 = fVar14 * local_40;
  fVar14 = fVar14 * local_3c;
  fStack0000000c = local_40 * local_40 + fVar14 * fVar14;
  fVar11 = (float10)func_0x009c1b40();
  fStack0000000c = _DAT_00b2c060;
  if (-1 < (int)(local_40 * fVar3 + fVar14 * fVar1)) {
    fStack0000000c = 1.0;
  }
  *(float *)(this + 0xfc) = fStack0000000c * (float)fVar11;
  VskCartesianToPolar(unaff_EBP,pGVar15);
  *(undefined4 *)(this + 0x108) = local_8;
  fVar14 = GmFunc::Mod(local_4,0.0,_DAT_00ba1130);
  *(float *)(this + 0x104) = fVar14;
  return;
}
}

// =================================================
// Function: CSceneToyBoat::UpdateSounds
// =================================================
/* WARNING: Variable defined which should be unmapped: param_1 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CSceneToyBoat::UpdateSounds(CSceneToyBoat *this,CSceneToyBoat *param_1)
{
{
  CSceneSoundSource *pCVar1;
  int iVar2;
  float fVar3;
  CPlugFileVideo *pCVar4;
  float fVar5;
  CPlugFileVideo *pCVar6;
  float fVar7;
  CBoatSailState *pCVar8;
  CPlugFileVideo *unaff_ESI;
  ESailType unaff_EDI;
  float10 fVar9;
  int unaff_retaddr;
  CPlugFileVideo *in_stack_00000008;
  CPlugFileVideo *in_stack_0000000c;
  STmRaceLowFps *in_stack_00000010;
  float in_stack_00000014;
  ulong in_stack_00000018;
  ulong in_stack_0000001c;
  float fStack00000028;
  
  if (*(int *)(this + 0x35c) != 0) {
    if (*(CSceneSoundSource **)(this + 0x3b8) != (CSceneSoundSource *)0x0) {
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x3b8),unaff_ESI,(EPlugVideoTimer)this,unaff_retaddr
                 ,(ulong)param_1);
    }
    fVar5 = (float)_DAT_00b313b8;
    if (*(int *)(this + 0x3b4) != 0) {
      pCVar4 = (CPlugFileVideo *)
               (ABS(*(float *)(this + 0xdc) * (float)_DAT_00b5b9c0) / (float)_DAT_00b48cb8 + fVar5);
      pCVar6 = _DAT_00b31460;
      if (((float)pCVar4 < (float)_DAT_00b31460 != ((float)pCVar4 == (float)_DAT_00b31460)) ||
         (pCVar6 = pCVar4, in_stack_0000000c = (CPlugFileVideo *)0x3f800000, (float)pCVar4 < 1.0)) {
        in_stack_0000000c = pCVar6;
      }
      *(CPlugFileVideo **)(*(int *)(*(int *)(this + 0x3b4) + 0x30) + 0x70) = in_stack_0000000c;
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x3b4),in_stack_00000008,
                 (EPlugVideoTimer)in_stack_0000000c,(int)in_stack_00000010,(ulong)in_stack_00000014)
      ;
      fVar5 = (float)_DAT_00b313b8;
    }
    if (*(int *)(this + 0x3c8) != 0) {
      fVar7 = ABS(*(float *)(this + 0xdc) * (float)_DAT_00b5b9c0 * (float)_DAT_00b38328) /
              (float)_DAT_00b48cb8;
      fVar3 = 0.0;
      if ((fVar7 < 0.0 == (fVar7 == 0.0)) &&
         (fVar3 = fVar7, !NAN(fVar7) && 1.0 < fVar7 != (fVar7 == 1.0))) {
        fVar3 = 1.0;
      }
      *(float *)(*(int *)(*(int *)(this + 0x3c8) + 0x30) + 0x74) =
           (float)_DAT_00b5b8e0 * fVar3 + (float)_DAT_00b541b8;
      in_stack_0000000c = (CPlugFileVideo *)(fVar3 * fVar5 + fVar5);
      *(CPlugFileVideo **)(*(int *)(*(int *)(this + 0x3c8) + 0x30) + 0x70) = in_stack_0000000c;
      CSceneSoundSource::Play
                (*(CSceneSoundSource **)(this + 0x3c8),in_stack_00000008,
                 (EPlugVideoTimer)in_stack_0000000c,(int)in_stack_00000010,(ulong)in_stack_00000014)
      ;
    }
    pCVar1 = *(CSceneSoundSource **)(this + 0x3a4);
    if (pCVar1 != (CSceneSoundSource *)0x0) {
      pCVar8 = SailStateGet(this,(CSceneToyBoat *)0x0,unaff_EDI);
      if ((pCVar8 == (CBoatSailState *)0x0) || (*(float *)(pCVar8 + 0xa4) <= (float)_DAT_00b362c0))
      {
        CSceneSoundSource::Stop(pCVar1,(STmRaceLowFps *)in_stack_00000008);
      }
      else {
        in_stack_00000010 =
             (STmRaceLowFps *)
             ((*(float *)(this + 0x94) * (float)_DAT_00b5b9c0) / (float)_DAT_00b3d260 +
             (float)_DAT_00b3d2b8);
        *(STmRaceLowFps **)(*(int *)(pCVar1 + 0x30) + 0x74) = in_stack_00000010;
        *(undefined4 *)(*(int *)(*(int *)(this + 0x3a4) + 0x30) + 0x70) =
             *(undefined4 *)(pCVar8 + 0xa4);
        CSceneSoundSource::Play
                  (*(CSceneSoundSource **)(this + 0x3a4),in_stack_00000008,
                   (EPlugVideoTimer)in_stack_0000000c,(int)in_stack_00000010,
                   (ulong)in_stack_00000014);
      }
    }
    if (*(CSceneSoundSource **)(this + 0x3a8) != (CSceneSoundSource *)0x0) {
      iVar2 = *(int *)(this + 0x130);
      if (((iVar2 == 0) || (*(float *)(iVar2 + 0xa4) <= (float)_DAT_00b362c0)) ||
         ((iVar2 = *(int *)(*(int *)(iVar2 + 0x14) + 0x18), iVar2 != 2 && (iVar2 != 5)))) {
        CSceneSoundSource::Stop
                  (*(CSceneSoundSource **)(this + 0x3a8),(STmRaceLowFps *)in_stack_0000000c);
      }
      else {
        in_stack_00000014 =
             (*(float *)(this + 0x94) * (float)_DAT_00b5b9c0) / (float)_DAT_00b3d260 +
             (float)_DAT_00ba1330;
        *(float *)(*(int *)(*(int *)(this + 0x3a4) + 0x30) + 0x74) = in_stack_00000014;
        *(undefined4 *)(*(int *)(*(int *)(this + 0x3a4) + 0x30) + 0x70) =
             *(undefined4 *)(*(int *)(this + 0x130) + 0xa4);
        CSceneSoundSource::Play
                  (*(CSceneSoundSource **)(this + 0x3a8),in_stack_0000000c,
                   (EPlugVideoTimer)in_stack_00000010,(int)in_stack_00000014,in_stack_00000018);
      }
    }
    pCVar1 = *(CSceneSoundSource **)(this + 0x38c);
    if (pCVar1 != (CSceneSoundSource *)0x0) {
      if (*(int *)(this + 0x358) == 0) {
        CSceneSoundSource::Stop(pCVar1,(STmRaceLowFps *)in_stack_0000000c);
      }
      else {
        fVar5 = *(float *)(this + 0xb4) / (float)_PTR_00b5b9b8;
        in_stack_00000014 = _DAT_00b33a54;
        if ((fVar5 < (float)_DAT_00b43310 == (fVar5 == (float)_DAT_00b43310)) &&
           (in_stack_00000014 = fVar5, 1.0 < fVar5 != (fVar5 == 1.0))) {
          in_stack_00000014 = 1.0;
        }
        *(float *)(*(int *)(pCVar1 + 0x30) + 0x70) = in_stack_00000014;
        CSceneSoundSource::Play
                  (*(CSceneSoundSource **)(this + 0x38c),in_stack_0000000c,
                   (EPlugVideoTimer)in_stack_00000010,(int)in_stack_00000014,in_stack_00000018);
      }
    }
    pCVar8 = SailStateGet(this,(CSceneToyBoat *)0x0,(ESailType)in_stack_0000000c);
    pCVar1 = *(CSceneSoundSource **)(this + 0x3b0);
    if ((pCVar1 != (CSceneSoundSource *)0x0) && (pCVar8 != (CBoatSailState *)0x0)) {
      if (*(int *)(pCVar8 + 0x98) == 0) {
        CSceneSoundSource::Stop(pCVar1,in_stack_00000010);
        *(undefined4 *)(*(int *)(*(int *)(this + 0x3b0) + 0x30) + 0x78) = 0;
        return;
      }
      CSceneSoundSource::Play
                (pCVar1,(CPlugFileVideo *)in_stack_00000010,(EPlugVideoTimer)in_stack_00000014,
                 in_stack_00000018,in_stack_0000001c);
      fStack00000028 = ABS(*(float *)(pCVar8 + 0x80) - *(float *)(pCVar8 + 0x84));
      fVar9 = (float10)func_0x009c2390();
      *(float *)(*(int *)(*(int *)(this + 0x3b0) + 0x30) + 0x78) = (float)fVar9;
    }
  }
  return;
}
}

