// Class implementation: CGameControlCameraMaster_SSwitch

// =================================================
// Function: CGameControlCameraMaster::SSwitch::Reset
// =================================================
void __thiscall CGameControlCameraMaster::SSwitch::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_00000008;
  GmFrustumIso4 *in_stack_0000000c;
  GmFrustumIso4 *in_stack_00000010;
  GmFrustumIso4 *in_stack_00000014;
  
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 1;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  GmLocVal::Reset((void *)((int)this + 0x30),unaff_EDI);
  GmLensVal::Reset((void *)((int)this + 0x60),unaff_ESI);
  GmLocVal::Reset((void *)((int)this + 0x74),unaff_retaddr);
  GmLensVal::Reset((void *)((int)this + 0xa4),param_1);
  GmLocVal::Reset((void *)((int)this + 0xb8),in_stack_00000008);
  GmLensVal::Reset((void *)((int)this + 0xe8),in_stack_0000000c);
  GmLocVal::Reset((void *)((int)this + 0xfc),in_stack_00000010);
  GmLensVal::Reset((void *)((int)this + 300),in_stack_00000014);
  *(undefined4 *)((int)this + 0x140) = 0;
  *(undefined4 *)((int)this + 0x144) = 0;
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::SSwitch::SSwitch
// =================================================
void __thiscall CGameControlCameraMaster::SSwitch::SSwitch(void *this,SSwitch *param_1)
{
{
  GmFrustumIso4 *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  GmFrustumIso4 *unaff_retaddr;
  GmFrustumIso4 *in_stack_00000008;
  GmFrustumIso4 *in_stack_0000000c;
  GmFrustumIso4 *in_stack_00000010;
  GmFrustumIso4 *in_stack_00000014;
  
  GmLocVal::Reset((void *)((int)this + 0x30),unaff_EDI);
  GmLensVal::Reset((void *)((int)this + 0x60),unaff_ESI);
  GmLocVal::Reset((void *)((int)this + 0x74),unaff_retaddr);
  GmLensVal::Reset((void *)((int)this + 0xa4),(GmFrustumIso4 *)param_1);
  GmLocVal::Reset((void *)((int)this + 0xb8),in_stack_00000008);
  GmLensVal::Reset((void *)((int)this + 0xe8),in_stack_0000000c);
  GmLocVal::Reset((void *)((int)this + 0xfc),in_stack_00000010);
  GmLensVal::Reset((void *)((int)this + 300),in_stack_00000014);
  return;
}
}

// =================================================
// Function: CGameControlCameraMaster::SSwitch::Update
// =================================================
float __thiscall
CGameControlCameraMaster::SSwitch::Update
          (void *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3)
{
{
  int iVar1;
  GmFrustumIso4 *unaff_EBX;
  GmFrustumIso4 *unaff_ESI;
  undefined4 *puVar2;
  GmLensVal *pGVar3;
  GmFrustumIso4 *unaff_EDI;
  undefined4 *puVar4;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 fVar5;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  GmFrustumIso4 *in_stack_ffffff5c;
  float in_stack_ffffff60;
  GmLensVal *local_90;
  undefined4 local_8c;
  GmLensVal local_88 [4];
  undefined4 local_84 [8];
  float local_64;
  float local_60;
  float local_5c [3];
  undefined1 local_50 [16];
  GmLensVal local_40 [36];
  undefined1 local_1c [24];
  
  if (((*(int *)((int)this + 0xc) == 0) && (*(int *)((int)this + 0x18) == 0)) ||
     ((*(int *)((int)this + 8) == 0 && (*(int *)((int)this + 0x14) == 0)))) {
    return (float)in_ST0;
  }
  *(float *)((int)this + 0x144) = (float)param_1 + *(float *)((int)this + 0x144);
  GmLocVal::Reset(local_50,unaff_EDI);
  GmLensVal::Reset(local_1c,unaff_ESI);
  GmLocVal::Reset(&local_90,unaff_EBX);
  GmLensVal::Reset(local_5c,in_stack_ffffff5c);
  local_8c = 0;
  if (*(int *)((int)this + 0x14) == 0) {
    fVar5 = (float10)(**(code **)(**(int **)((int)this + 8) + 0x78))(local_88);
  }
  else {
    puVar2 = (undefined4 *)((int)this + 0xb8);
    pGVar3 = local_88;
    for (iVar1 = 0x11; fVar5 = extraout_ST0, iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pGVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      pGVar3 = pGVar3 + 4;
    }
  }
  if (*(int *)((int)this + 0x18) == 0) {
    fVar5 = (float10)(**(code **)(**(int **)((int)this + 0xc) + 0x78))(local_40);
  }
  else {
    puVar2 = (undefined4 *)((int)this + 0xfc);
    pGVar3 = local_40;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *(undefined4 *)pGVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      pGVar3 = pGVar3 + 4;
    }
  }
  local_90 = (GmLensVal *)0x0;
  if (0.0 < *(float *)((int)this + 0x144)) {
    if (*(float *)((int)this + 0x140) < *(float *)((int)this + 0x144) ==
        (*(float *)((int)this + 0x140) == *(float *)((int)this + 0x144))) {
      local_90 = (GmLensVal *)(*(float *)((int)this + 0x144) / *(float *)((int)this + 0x140));
    }
    else {
      local_8c = 1;
      *(undefined4 *)((int)this + 0x144) = *(undefined4 *)((int)this + 0x140);
      local_90 = (GmLensVal *)0x3f800000;
    }
  }
  else {
    *(undefined4 *)((int)this + 0x144) = 0;
    local_8c = 1;
  }
  if (*(int *)((int)this + 0x1c) != 0) {
    if (*(int *)((int)this + 0x20) != 0) {
      *(float *)((int)this + 0x54) = *(float *)((int)this + 0x24) + local_64;
      *(float *)((int)this + 0x58) = *(float *)((int)this + 0x28) + local_60;
      *(float *)((int)this + 0x5c) = *(float *)((int)this + 0x2c) + local_5c[0];
    }
    GmCamVal::SetLinearInterp
              ((undefined4 *)((int)this + 0x74),(GmLensVal *)((int)this + 0x30),local_88,local_90,
               in_stack_ffffff60);
    puVar2 = (undefined4 *)((int)this + 0x74);
    puVar4 = local_84;
    for (iVar1 = 0x11; fVar5 = extraout_ST0_00, iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  if (*(int *)((int)this + 0x10) == 0) {
    if (*(int *)((int)this + 0x1c) == 0) {
      pGVar3 = local_40;
      puVar2 = (undefined4 *)((int)this + 0x74);
      for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *(undefined4 *)pGVar3;
        pGVar3 = pGVar3 + 4;
        puVar2 = puVar2 + 1;
      }
    }
    return (float)fVar5;
  }
  GmCamVal::SetLinearInterp((void *)((int)this + 0x74),local_88,local_40,local_90,in_stack_ffffff60)
  ;
  return (float)extraout_ST0_01;
}
}

