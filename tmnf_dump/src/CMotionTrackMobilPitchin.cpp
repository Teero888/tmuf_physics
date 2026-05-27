// Class implementation: CMotionTrackMobilPitchin

// =================================================
// Function: CMotionTrackMobilPitchin::ComputeAngleAndMoyenne
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionTrackMobilPitchin::ComputeAngleAndMoyenne
          (CMotionTrackMobilPitchin *this,CMotionTrackMobilPitchin *param_1,float *param_2,
          float *param_3)
{
{
  float fVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float local_8;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x48,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GxColor>::operator[](this + 0x48,pCVar4,unaff_ESI);
      pCVar4 = pCVar4 + 1;
      local_8 = (*(float *)(pSVar3 + 0xc) - *(float *)(this + 0xa4)) *
                (*(float *)(pSVar3 + 8) - *(float *)(this + 0xa8)) + local_8;
    } while (pCVar4 < pCVar2);
  }
  fVar1 = (float)(int)pCVar2;
  if ((int)pCVar2 < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  if ((*(float *)(this + 0xb0) <= (float)_DAT_00b5ca28) ||
     (_DAT_00b5c9e8 <= *(float *)(this + 0xb0))) {
    *(undefined4 *)(this + 0x7c) = 0;
    *(float *)(this + 0x80) = 0.0 / fVar1;
    *(undefined4 *)(this + 0x84) = *(undefined4 *)(this + 0xb0);
    __CIatan();
    *param_2 = (float)extraout_ST0;
  }
  else {
    *(undefined4 *)(this + 0x7c) = 0;
    *(undefined4 *)(this + 0x80) = 0;
    *(undefined4 *)(this + 0x84) = 0x3f800000;
    *param_2 = 0.0;
  }
  if (((float)_DAT_00b5ca28 < *(float *)(this + 0xac)) && (*(float *)(this + 0xac) < _DAT_00b5c9e8))
  {
    *(undefined4 *)(this + 0x70) = 0x3f800000;
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined4 *)(this + 0x78) = 0;
    *param_3 = 0.0;
    return;
  }
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0xac);
  *(float *)(this + 0x74) = local_8 / fVar1;
  *(undefined4 *)(this + 0x78) = 0;
  __CIatan();
  *param_3 = (float)extraout_ST0_00;
  return;
}
}

// =================================================
// Function: CMotionTrackMobilPitchin::ComputePitchinLocation
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CMotionTrackMobilPitchin::ComputePitchinLocation
          (CMotionTrackMobilPitchin *this,CSceneToyBoat *param_1,float param_2,GmIso4 *param_3)
{
{
  uint uVar1;
  uint uVar2;
  CPlugAudio *this_00;
  CMwId *pCVar3;
  GmVec3 *pGVar4;
  int iVar5;
  GmVec3 *unaff_EBX;
  GmVec3 *unaff_EBP;
  CPlugAudio *unaff_ESI;
  GmIso4 *pGVar6;
  float *unaff_EDI;
  GmIso3 **ppGVar7;
  float10 fVar8;
  float fVar9;
  GmIso3 *pGVar10;
  GmVec3 *in_stack_ffffff40;
  GmVec3 *in_stack_ffffff44;
  GmVec3 *in_stack_ffffff48;
  GmVec3 *pGVar11;
  float in_stack_ffffff50;
  float local_ac;
  GmMat2 *pGStack_a8;
  float fStack_a4;
  float fStack_a0;
  float local_9c;
  GmMat2 *pGStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float local_80;
  float local_7c;
  float local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  CMwCmdScriptVarBool *pCStack_68;
  int iStack_64;
  GmIso3 *local_60;
  undefined1 local_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  GmMat2 aGStack_4c [16];
  GmIso3 aGStack_3c [8];
  undefined1 auStack_34 [28];
  GmIso3 aGStack_18 [8];
  undefined1 auStack_10 [16];
  
  local_80 = 0.0;
  local_ac = 0.0;
  ComputeAngleAndMoyenne(this,(CMotionTrackMobilPitchin *)&local_80,&local_ac,unaff_EDI);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar3 = CPlugAudio::MwGetId(this_00,unaff_ESI);
  uVar1 = *(uint *)pCVar3;
  uVar2 = *(uint *)(this + 0xb4);
  *(uint *)(this + 0xb4) = uVar1;
  if (uVar1 != uVar2) {
    if ((uVar1 < uVar2) || (pGVar4 = (GmVec3 *)(uVar1 - uVar2), (GmVec3 *)&DAT_000001f4 < pGVar4)) {
      *(float *)(param_3 + 0x28) = *(float *)(this + 0xa4) + *(float *)(this + 0x6c);
    }
    else {
      local_7c = (float)(int)pGVar4 * (float)_DAT_00b30a18;
      if (*(float *)(this + 0x54) != 0.0) {
        _DAT_00d680ac = *(undefined4 *)(param_3 + 0x24);
        _DAT_00d680b0 = *(float *)(param_3 + 0x28);
        _DAT_00d680b4 = *(undefined4 *)(param_3 + 0x2c);
        pGVar4 = (GmVec3 *)((*(float *)(this + 0xa4) - _DAT_00d680b0) + *(float *)(this + 0x6c));
        if ((float)pGVar4 <= 0.0) {
          _DAT_00d680b0 = *(float *)(this + 0x6c) + *(float *)(this + 0xa4);
        }
        else {
          pGVar11 = (GmVec3 *)(*(float *)(this + 0x54) * local_7c);
          fVar9 = GmFunc::ClampReal((float)pGVar4,-(float)pGVar11,(float)pGVar11);
          _DAT_00d680b0 = fVar9 + _DAT_00d680b0;
          pGVar4 = pGVar11;
        }
        GmIso4::SetTranslation(param_3,(GmIso4 *)&DAT_00d680ac,unaff_EBP);
      }
      pGVar6 = param_3;
      ppGVar7 = &local_60;
      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
        *ppGVar7 = *(GmIso3 **)pGVar6;
        pGVar6 = pGVar6 + 4;
        ppGVar7 = ppGVar7 + 1;
      }
      GmMat3::GetLine(&local_60,(GmMat3 *)0x0,(ulong)&local_9c,unaff_EBX);
      GmMat3::GetLine(local_5c,(GmMat3 *)0x2,(ulong)&local_80,in_stack_ffffff40);
      fVar8 = (float10)func_0x009c1d90();
      pGStack_a8 = (GmMat2 *)(float)fVar8;
      *(GmMat2 **)(this + 0x88) = pGStack_a8;
      fVar8 = (float10)func_0x009c1d90();
      *(float *)(this + 0x8c) = (float)fVar8;
      if (*(float *)(this + 0x68) != 0.0) {
        local_ac = -fStack_6c - (float)pGStack_a8;
        pGStack_a8 = (GmMat2 *)
                     GmFunc::ClampReal(local_ac,-(*(float *)(this + 0x68) * fStack_70),
                                       *(float *)(this + 0x68) * fStack_70);
        fStack_88 = fStack_94;
        fStack_84 = 0.0;
        local_80 = fStack_8c;
        local_ac = fStack_8c * fStack_8c + fStack_94 * fStack_94 + 0.0;
        if (_DAT_00ce0b98 < local_ac) {
          fVar8 = (float10)func_0x009c1b40();
          local_ac = 1.0 / (float)fVar8;
          fStack_88 = local_ac * fStack_94;
          fStack_84 = (float)_PTR_00b2c178 * local_ac;
          local_80 = local_ac * fStack_8c;
        }
        GmQuat::SetRotation(&pCStack_68,pGStack_a8,(float)&fStack_88);
        pGVar10 = local_60;
        GmMat3::Set(auStack_34,pCStack_68,iStack_64);
        GmVec3::Mult(&fStack_84,aGStack_3c,pGVar10);
      }
      if (*(float *)(this + 100) != 0.0) {
        local_ac = (float)pGStack_98 - *(float *)(this + 0x8c);
        pGStack_98 = (GmMat2 *)
                     GmFunc::ClampReal(local_ac,-(fStack_70 * *(float *)(this + 100)),
                                       fStack_70 * *(float *)(this + 100));
        fStack_88 = local_7c;
        fStack_84 = 0.0;
        local_80 = fStack_74;
        local_ac = fStack_74 * fStack_74 + local_7c * local_7c + 0.0;
        if (_DAT_00ce0b98 < local_ac) {
          fVar8 = (float10)func_0x009c1b40();
          local_ac = 1.0 / (float)fVar8;
          fStack_88 = local_ac * local_7c;
          fStack_84 = (float)_PTR_00b2c178 * local_ac;
          local_80 = local_ac * fStack_74;
        }
        GmQuat::SetRotation(&pCStack_68,pGStack_98,(float)&fStack_88);
        GmMat3::Set(auStack_10,pCStack_68,iStack_64);
        GmVec3::Mult(&local_9c,aGStack_18,local_60);
      }
      fStack_a4 = local_78 * fStack_8c - fStack_90 * fStack_74;
      fStack_a0 = fStack_94 * fStack_74 - local_7c * fStack_8c;
      local_9c = local_7c * fStack_90 - fStack_94 * local_78;
      local_ac = fStack_a4 * fStack_a4 + fStack_a0 * fStack_a0 + local_9c * local_9c;
      if (_DAT_00ce0b98 < local_ac) {
        fVar8 = (float10)func_0x009c1b40();
        local_ac = 1.0 / (float)fVar8;
        fStack_a4 = local_ac * fStack_a4;
        fStack_a0 = fStack_a0 * local_ac;
        local_9c = local_ac * local_9c;
      }
      fStack_94 = fStack_a0 * fStack_74 - local_78 * local_9c;
      fStack_90 = local_7c * local_9c - fStack_a4 * fStack_74;
      fStack_8c = fStack_a4 * local_78 - fStack_a0 * local_7c;
      GmMat3::SetLine(auStack_58,(GmMat3 *)0x0,(ulong)&fStack_94,in_stack_ffffff44);
      GmMat3::SetLine(auStack_54,(GmMat3 *)0x1,(ulong)&fStack_a0,in_stack_ffffff48);
      GmMat3::SetLine(auStack_50,(GmMat3 *)0x2,(ulong)&fStack_74,pGVar4);
      if (*(float *)(this + 0x68) != 0.0) {
        GmIso4::SetRotation(param_3,aGStack_4c,in_stack_ffffff50);
        return;
      }
      if (*(float *)(this + 100) != 0.0) {
        GmIso4::SetRotation(param_3,aGStack_4c,in_stack_ffffff50);
        return;
      }
    }
  }
  return;
}
}

