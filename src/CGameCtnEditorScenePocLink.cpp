// Class implementation: CGameCtnEditorScenePocLink

// =================================================
// Function: CGameCtnEditorScenePocLink::CGameCtnEditorScenePocLink
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnEditorScenePocLink::CGameCtnEditorScenePocLink
          (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1)
{
{
  undefined4 uVar1;
  float fVar2;
  CSceneObjectLink *unaff_ESI;
  
  CSceneObjectLink::CSceneObjectLink((CSceneObjectLink *)this,unaff_ESI);
  uVar1 = _DAT_00b77ea4;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0x70) = uVar1;
  fVar2 = _DAT_00ce9474;
  *(undefined4 *)(this + 100) = 0;
  *(float *)(this + 0x78) = fVar2 * (float)_DAT_00b313d8 * (float)_DAT_00b33620;
  *(undefined4 *)(this + 0x74) = _DAT_00b33628;
  *(undefined4 *)(this + 0xbc) = _DAT_00b36154;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  fVar2 = _DAT_00ce9474;
  *(undefined4 *)(this + 0x68) = 0;
  *(float *)(this + 0x84) = fVar2;
  return;
}
}

// =================================================
// Function: CGameCtnEditorScenePocLink::ClampHAngle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CGameCtnEditorScenePocLink::ClampHAngle
          (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1,float *param_2)
{
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *(float *)param_1;
  if (fVar1 < 0.0) {
    *(float *)param_1 = -*(float *)param_1;
  }
  fVar5 = _DAT_00b77eac;
  fVar4 = _DAT_00b77df8;
  fVar2 = (float)_DAT_00b77ed0;
  fVar3 = (float)_DAT_00b59bb8;
  while ((fVar5 < *(float *)param_1 || (ABS(*(float *)param_1 - fVar2) < fVar4))) {
    *(float *)param_1 = *(float *)param_1 - fVar3;
  }
  if (ABS(*(float *)param_1 - (float)_DAT_00b36bf0) < fVar4) {
    *(undefined4 *)param_1 = _DAT_00b36108;
  }
  fVar2 = *(float *)param_1;
  if (fVar1 < 0.0) {
    fVar2 = -fVar2;
  }
  *(float *)param_1 = fVar2;
  return;
}
}

// =================================================
// Function: CGameCtnEditorScenePocLink::GetForwardDirectionFromCurrentHAngle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ECardinalDir __thiscall
CGameCtnEditorScenePocLink::GetForwardDirectionFromCurrentHAngle
          (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1)
{
{
  int iVar1;
  CGameCtnEditorScenePocLink *unaff_ESI;
  float *unaff_EDI;
  
  iVar1 = IsHAngleNeedClamp(this,unaff_ESI);
  if (iVar1 != 0) {
    ClampHAngle(this,this + 0x7c,unaff_EDI);
    *(float *)(this + 0x80) = *(float *)(this + 0x7c) + (float)param_1;
  }
  if (*(float *)(this + 0x7c) < (float)_DAT_00b77f00) {
    return 3;
  }
  if (*(float *)(this + 0x7c) < (float)_DAT_00b77ef8) {
    return 2;
  }
  if ((float)_DAT_00b77ef0 <= *(float *)(this + 0x7c)) {
    if (*(float *)(this + 0x7c) < (float)_DAT_00b5b8d8) {
      return 0;
    }
    if (*(float *)(this + 0x7c) < (float)_DAT_00b77ee8) {
      return 3;
    }
    if (*(float *)(this + 0x7c) < (float)_DAT_00b77ee0) {
      return 2;
    }
  }
  return 1;
}
}

// =================================================
// Function: CGameCtnEditorScenePocLink::IsHAngleNeedClamp
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CGameCtnEditorScenePocLink::IsHAngleNeedClamp
          (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1)
{
{
  ulong uVar1;
  
  if (((((float)_DAT_00b77ec8 <= *(float *)(this + 0x7c)) &&
       (*(float *)(this + 0x7c) <= (float)_DAT_00b77ec0)) &&
      (_DAT_00b77df8 <= ABS(*(float *)(this + 0x7c) - (float)_DAT_00b77eb8))) &&
     (uVar1 = GmFunc::AreNearlyEqual(*(float *)(this + 0x7c),_DAT_00b77eac,_DAT_00b77df8),
     uVar1 == 0)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameCtnEditorScenePocLink::SetTarget
// =================================================
void __thiscall
CGameCtnEditorScenePocLink::SetTarget
          (CGameCtnEditorScenePocLink *this,CGameCtnEditorScenePocLink *param_1,CSceneMobil *param_2
          )
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CGameCtnEditorScenePocLink **)(this + 0xb8)) {
    if (param_1 != (CGameCtnEditorScenePocLink *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0xb8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0xb8),unaff_ESI);
    }
    *(CGameCtnEditorScenePocLink **)(this + 0xb8) = param_1;
  }
  return;
}
}

