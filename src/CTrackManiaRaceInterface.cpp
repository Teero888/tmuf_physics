// Class implementation: CTrackManiaRaceInterface

// =================================================
// Function: CTrackManiaRaceInterface::CallVoteMessage_Hide
// =================================================
void __thiscall
CTrackManiaRaceInterface::CallVoteMessage_Hide
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  *(undefined4 *)(this + 0x13c) = 0;
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x138),0);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::GetGame
// =================================================
CTrackMania * __thiscall
CTrackManiaRaceInterface::GetGame
          (CTrackManiaRaceInterface *this,CTrackManiaEnvironmentManager *param_1)
{
{
  if (*(int *)(this + 0xa0) != 0) {
    return *(CTrackMania **)(*(int *)(this + 0xa0) + 0x18);
  }
  return (CTrackMania *)0x0;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::GetKeyFromActionIndex
// =================================================
void __thiscall
CTrackManiaRaceInterface::GetKeyFromActionIndex
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,
          SInputActionDesc *param_2,CFastStringInt *param_3)
{
{
  CFastStringInt *pCVar1;
  CTrackMania *pCVar2;
  CInputBindingsConfig *this_00;
  CInputBindingsConfig *pCVar3;
  ulong uVar4;
  SCasterCat *pSVar5;
  int iVar6;
  void *this_01;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_EBX;
  SInputActionDesc *unaff_EBP;
  int unaff_ESI;
  CGameCtnApp *unaff_EDI;
  CInputBindingsConfig *in_stack_00000010;
  void *in_stack_00000018;
  CFastStringInt *in_stack_0000001c;
  void *in_stack_00000020;
  undefined4 in_stack_00000024;
  int *in_stack_0000002c;
  CMwId *in_stack_ffffffbc;
  SStringParam *pSVar7;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffc0;
  CInputPort *pCVar8;
  ulong in_stack_ffffffc4;
  CMwId *pCVar9;
  ulong *in_stack_ffffffc8;
  CInputDevice **in_stack_ffffffcc;
  SNationConfig *pSVar10;
  CFastBuffer<struct_CInputBindingsConfig::SBinding> *in_stack_ffffffd0;
  undefined1 *local_2c;
  undefined4 local_28;
  CInputPort local_24 [8];
  undefined1 *local_1c;
  undefined4 local_18;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a8cbc0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_2c = &DAT_00b2c878;
  local_28 = 0;
  CFastStringInt::SetString
            (param_2,(CFastStringInt *)&local_2c,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffac));
  pCVar2 = GetGame(this,(CTrackManiaEnvironmentManager *)0x0);
  this_00 = CGameCtnApp::GetCurrentInputBindings((CGameCtnApp *)pCVar2,unaff_EDI,unaff_ESI);
  pCVar3 = (CInputBindingsConfig *)
           CInputBindingsConfig::FindAction(this_00,in_stack_00000010,unaff_EBP);
  if (pCVar3 == (CInputBindingsConfig *)0xffffffff) {
    local_1c = &DAT_00b304c0;
    local_18 = 1;
    CFastStringInt::SetString
              (in_stack_00000018,(CFastStringInt *)&local_1c,(SStringParam *)unaff_EBX);
  }
  else {
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(local_14,unaff_EBX);
    in_stack_00000010 = (CInputBindingsConfig *)0x0;
    CInputBindingsConfig::GetBindings(this_00,pCVar3,(ulong)local_10,DAT_00d739e4,in_stack_ffffffbc)
    ;
    uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(&local_c,in_stack_ffffffc0);
    if (uVar4 != 0) {
      pSVar5 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (&local_8,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          in_stack_ffffffc4);
      pCVar9 = (CMwId *)&stack0x00000024;
      pCVar8 = local_24;
      pCVar2 = GetGame(this,(CTrackManiaEnvironmentManager *)(pSVar5 + 4));
      iVar6 = CInputPort::FindDevice
                        (*(CInputPort **)(pCVar2 + 0x6c),pCVar8,pCVar9,in_stack_ffffffc8,
                         in_stack_ffffffcc);
      if (iVar6 != 0) {
        local_c = (void *)0x0;
        local_8 = PTR_DAT_00bbf7dc;
        pSVar10 = (SNationConfig *)&local_c;
        pSVar7 = *(SStringParam **)(pSVar5 + 8);
        in_stack_00000024 = CONCAT31(in_stack_00000024._1_3_,1);
        (**(code **)(*in_stack_0000002c + 0x80))();
        pCVar1 = in_stack_0000001c;
        uStack_4 = local_1c;
        param_1 = (CTrackManiaRaceInterface *)0x0;
        CFastStringInt::Concat(in_stack_0000001c,(CFastStringInt *)&uStack_4,pSVar7);
        iVar6 = (**(code **)(*(int *)in_stack_0000001c + 0x78))();
        if (iVar6 == 2) {
          CFastStringInt::ConcatFormat(this_01,pCVar1," (Pad %d)");
        }
        CGameCtnApp::SNationConfig::~SNationConfig(local_10,pSVar10);
      }
    }
    in_stack_00000024 = 0xffffffff;
    CFastBuffer<struct_CInputBindingsConfig::SBinding>::
    ~CFastBuffer<struct_CInputBindingsConfig::SBinding>(&param_1,in_stack_ffffffd0);
  }
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::GetRace
// =================================================
CTrackManiaRaceNet * __thiscall
CTrackManiaRaceInterface::GetRace(CTrackManiaRaceInterface *this,CTrackManiaNetwork *param_1)
{
{
  return *(CTrackManiaRaceNet **)(this + 0xa0);
}
}

// =================================================
// Function: CTrackManiaRaceInterface::GetStuntMessages
// =================================================
/* WARNING: Removing unreachable block (ram,0x004c2f89) */
/* WARNING: Removing unreachable block (ram,0x004c30b3) */
/* WARNING: Removing unreachable block (ram,0x004c30b7) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
CTrackManiaRaceInterface::GetStuntMessages
          (int param_1,SEventStunt *param_2,CFastStringInt *param_3,CFastStringInt *param_4,
          CFastStringInt *param_5)
{
{
  SStringParam SVar1;
  int iVar2;
  CFastString *pCVar3;
  SEventStunt *pSVar4;
  float fVar5;
  SEventStunt *pSVar6;
  CFastStringInt *this;
  CFastStringInt *this_00;
  SStringParam *pSVar7;
  CFastStringInt *pCVar8;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  undefined4 *extraout_EAX_03;
  SStringParamInt *pSVar9;
  SStringParamInt *pSVar10;
  uint uVar11;
  SStringParam *unaff_EBX;
  SStringParam *unaff_ESI;
  SStringParam *unaff_EDI;
  undefined1 in_stack_00000018;
  undefined1 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined1 in_stack_0000002c;
  undefined1 in_stack_00000030;
  undefined1 in_stack_00000038;
  SStringParam *in_stack_ffffffac;
  SStringParam *pSVar12;
  char *pcVar13;
  SStringParam *pSVar14;
  SStringParam *in_stack_ffffffc4;
  CFastStringInt *in_stack_ffffffc8;
  CFastString *pCVar15;
  SStringParamInt *in_stack_ffffffd0;
  SStringParamInt *in_stack_ffffffd4;
  SStringParamInt *in_stack_ffffffd8;
  SStringParamInt *in_stack_ffffffdc;
  SStringParamInt *pSVar16;
  undefined4 local_18;
  void *local_14;
  undefined1 *local_10;
  undefined4 local_c;
  CFastStringInt *local_8;
  
  local_c = 0xffffffff;
  local_10 = &LAB_00a8cc18;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  CFastStringInt::SetString
            (param_5,(CFastStringInt *)&stack0xffffffb0,
             (SStringParam *)(DAT_00cca150 ^ (uint)&stack0xffffffa0));
  this_00 = param_4;
  CFastStringInt::SetString(param_4,(CFastStringInt *)&stack0xffffffb4,unaff_EDI);
  this = param_3;
  pcVar13 = " ";
  CFastStringInt::SetString(param_3,(CFastStringInt *)&stack0xffffffb8,unaff_ESI);
  pSVar6 = param_2;
  if (param_1 == 0) {
    if (*(int *)param_2 == 1) {
      ExceptionList = param_2;
      return;
    }
    if (0x10 < *(int *)param_2) {
      ExceptionList = param_2;
      return;
    }
  }
  pSVar14 = (SStringParam *)(&PTR_DAT_00cd6e38)[*(int *)param_2];
  if (pSVar14 == (SStringParam *)0x0) {
    pCVar8 = (CFastStringInt *)0x0;
  }
  else {
    pSVar7 = pSVar14;
    do {
      SVar1 = *pSVar7;
      pSVar7 = pSVar7 + 1;
    } while (SVar1 != (SStringParam)0x0);
    pCVar8 = (CFastStringInt *)(pSVar7 + -(int)(pSVar14 + 1));
  }
  CFastStringInt::CFastStringInt(&stack0xffffffcc,(CFastStringInt *)&stack0xffffffbc,unaff_EBX);
  local_18 = 0;
  pSVar10 = in_stack_ffffffd4;
  CFastStringInt::SetString(this,(CFastStringInt *)&stack0xffffffe0,in_stack_ffffffac);
  param_2 = (SEventStunt *)CONCAT31(param_2._1_3_,1);
  iVar2 = *(int *)pSVar6;
  if (iVar2 == 0x22) {
    CFastString::SetNatural
              ((CFastString *)&stack0xffffffd4,*(CFastString **)(pSVar6 + 8),1,0,0,0,1,(int)pcVar13)
    ;
    in_stack_ffffffd8 = in_stack_ffffffdc;
    CFastStringInt::SetString(this_00,(CFastStringInt *)&stack0xffffffd0,pSVar14);
    CFastStringInt::Concat(this_00,(CFastStringInt *)&stack0xffffffd4,(SStringParam *)pCVar8);
    goto LAB_004c33d4;
  }
  if (iVar2 == 0x23) {
    CFastString::SetNatural
              ((CFastString *)&stack0xffffffd4,*(CFastString **)(pSVar6 + 8),1,0,0,0,1,(int)pcVar13)
    ;
    in_stack_ffffffd8 = in_stack_ffffffdc;
    CFastStringInt::SetString(this_00,(CFastStringInt *)&stack0xffffffd0,pSVar14);
    CFastStringInt::Concat(this_00,(CFastStringInt *)&stack0xffffffd4,(SStringParam *)pCVar8);
    goto LAB_004c33d4;
  }
  if (iVar2 == 0x25) {
    CFastString::SetNatural
              ((CFastString *)&stack0xffffffd4,(CFastString *)0x0,1,0,0,0,1,(int)pcVar13);
    CFastStringInt::SetString(param_5,(CFastStringInt *)&stack0xffffffd0,pSVar14);
    goto LAB_004c33d4;
  }
  pCVar15 = (CFastString *)0x0;
  pCVar3 = *(CFastString **)(pSVar6 + 4);
  pSVar7 = (SStringParam *)PTR_DAT_00bbf7d8;
  if (pCVar3 != (CFastString *)0x0) {
    if (*(int *)pSVar6 == 0x24) {
      fVar5 = (float)(int)pCVar3;
      if ((int)pCVar3 < 0) {
        fVar5 = fVar5 + _DAT_00c418d0;
      }
      pCVar15 = (CFastString *)(fVar5 / (float)_DAT_00c418d8);
      CFastString::SetReal((CFastString *)&stack0xffffffd4,pCVar15,1.4013e-45,(ulong)pcVar13);
      SStringParam::SStringParam(&local_18,(SStringParam *)&DAT_00b45a24,(char *)pSVar14);
      pcVar13 = (char *)0x4c3161;
      in_stack_ffffffdc = pSVar10;
      in_stack_ffffffd8 = in_stack_ffffffd0;
      CFastStringInt::Concat(this,(CFastStringInt *)&local_14,(SStringParam *)pCVar8);
      pSVar14 = (SStringParam *)0x4c317d;
      pSVar10 = in_stack_ffffffdc;
      in_stack_ffffffd0 = in_stack_ffffffd8;
      CFastStringInt::Concat(this,(CFastStringInt *)&stack0xffffffd8,in_stack_ffffffc4);
      pCVar8 = (CFastStringInt *)0x4c318b;
      SStringParam::SStringParam(&local_c,(SStringParam *)" sec)",(char *)in_stack_ffffffc8);
      in_stack_ffffffc8 = (CFastStringInt *)&local_8;
      in_stack_ffffffc4 = (SStringParam *)0x4c3197;
      CFastStringInt::Concat(this,in_stack_ffffffc8,(SStringParam *)pCVar15);
    }
    else {
      CFastString::SetNatural((CFastString *)&stack0xffffffd4,pCVar3,1,0,0,0,1,(int)pcVar13);
      pSVar12 = (SStringParam *)0x4c31be;
      SStringParam::SStringParam(&local_18,(SStringParam *)&DAT_00b2d0d4,(char *)pSVar14);
      pcVar13 = (char *)0x4c31ca;
      CFastStringInt::Concat(this,(CFastStringInt *)&local_14,(SStringParam *)pCVar8);
      pCVar8 = (CFastStringInt *)&stack0xffffffd8;
      pSVar14 = (SStringParam *)0x4c31e6;
      pSVar9 = pSVar10;
      pSVar16 = in_stack_ffffffd0;
      CFastStringInt::Concat(this,pCVar8,in_stack_ffffffc4);
      uVar11 = *(uint *)(pSVar6 + 4) / 0xb4;
      in_stack_ffffffd8 = in_stack_ffffffd0;
      in_stack_ffffffdc = pSVar10;
      if (5 < uVar11) {
        uVar11 = 5;
      }
      for (; in_stack_ffffffd0 = pSVar16, pSVar10 = pSVar9, uVar11 != 0; uVar11 = uVar11 - 1) {
        in_stack_ffffffc8 = (CFastStringInt *)&DAT_00b2ceb0;
        pCVar15 = (CFastString *)0x1;
        CFastStringInt::Concat(this,(CFastStringInt *)&stack0xffffffc8,pSVar12);
        pSVar9 = pSVar10;
        pSVar16 = in_stack_ffffffd0;
      }
    }
  }
  if (*(int *)(pSVar6 + 0x18) == 0) {
    if ((*(int *)(pSVar6 + 0x10) != 0) || (*(int *)(pSVar6 + 0x14) != 0)) {
      SStringParam::SStringParam(&stack0xffffffe4,(SStringParam *)"Straight ",pcVar13);
      CFastStringInt::CFastStringInt(&stack0xffffffd0,(CFastStringInt *)&local_18,pSVar14);
      local_c = extraout_EAX_00[1];
      local_8 = (CFastStringInt *)*extraout_EAX_00;
      in_stack_00000018 = 3;
      goto LAB_004c32ab;
    }
  }
  else {
    SStringParam::SStringParam(&stack0xffffffe4,(SStringParam *)"Master ",pcVar13);
    CFastStringInt::CFastStringInt(&stack0xffffffd0,(CFastStringInt *)&local_18,pSVar14);
    local_c = extraout_EAX[1];
    local_8 = (CFastStringInt *)*extraout_EAX;
    in_stack_00000018 = 2;
LAB_004c32ab:
    pSVar14 = (SStringParam *)&local_c;
    pcVar13 = (char *)0x4c32ba;
    CFastStringInt::ConcatBefore(this,(CFastStringInt *)pSVar14,(SStringParamInt *)pCVar8);
    in_stack_0000001c = 1;
    pCVar8 = (CFastStringInt *)0x4c32c8;
    CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffffd8,(SNationConfig *)in_stack_ffffffc4);
  }
  if (*(CFastString **)(pSVar6 + 0x1c) != (CFastString *)0x0) {
    CFastString::SetNatural
              ((CFastString *)&stack0xffffffd4,*(CFastString **)(pSVar6 + 0x1c),1,0,0,0,1,
               (int)pcVar13);
    SStringParam::SStringParam(&local_18,(SStringParam *)"Chained ",(char *)pSVar14);
    CFastStringInt::CFastStringInt
              (&stack0xffffffd4,(CFastStringInt *)&local_14,(SStringParam *)pCVar8);
    local_8 = (CFastStringInt *)extraout_EAX_01[1];
    pSVar4 = (SEventStunt *)*extraout_EAX_01;
    in_stack_0000001c = 4;
    CFastStringInt::ConcatBefore
              (this,(CFastStringInt *)&local_8,(SStringParamInt *)in_stack_ffffffc4);
    in_stack_00000020 = CONCAT31(in_stack_00000020._1_3_,1);
    CGameCtnApp::SNationConfig::~SNationConfig(&stack0xffffffdc,(SNationConfig *)in_stack_ffffffc8);
    if (1 < *(uint *)(pSVar6 + 0x1c)) {
      SStringParam::SStringParam(&local_8,(SStringParam *)&DAT_00b459f8,(char *)pCVar15);
      CFastStringInt::CFastStringInt(&stack0xffffffe4,(CFastStringInt *)&stack0xfffffffc,pSVar7);
      param_2 = (SEventStunt *)extraout_EAX_02[1];
      param_3 = (CFastStringInt *)*extraout_EAX_02;
      in_stack_0000002c = 5;
      param_4 = (CFastStringInt *)0x0;
      CFastStringInt::ConcatBefore(this,(CFastStringInt *)&param_2,in_stack_ffffffd4);
      in_stack_00000030 = 1;
      CGameCtnApp::SNationConfig::~SNationConfig(&local_14,(SNationConfig *)in_stack_ffffffd8);
      param_3 = local_8;
      param_2 = pSVar4;
      CFastStringInt::CFastStringInt
                (&param_4,(CFastStringInt *)&param_2,(SStringParam *)in_stack_ffffffdc);
      in_stack_00000020 = extraout_EAX_03[1];
      in_stack_00000024 = *extraout_EAX_03;
      in_stack_00000038 = 6;
      in_stack_00000028 = 0;
      in_stack_ffffffd8 = (SStringParamInt *)0x4c33cb;
      CFastStringInt::ConcatBefore(this,(CFastStringInt *)&stack0x00000020,pSVar10);
      pSVar10 = (SStringParamInt *)0x4c33d4;
      CGameCtnApp::SNationConfig::~SNationConfig
                (&stack0x00000018,(SNationConfig *)in_stack_ffffffd0);
    }
  }
LAB_004c33d4:
  if (in_stack_ffffffd8 != (SStringParamInt *)PTR_DAT_00bbf7d8) {
    pSVar9 = in_stack_ffffffd8 + -1;
    if (((byte)in_stack_ffffffd8[-1] & 0x80) != 0) {
      pSVar9 = in_stack_ffffffd8 + -4;
    }
    operator_delete__(pSVar9);
  }
  if (pSVar10 != (SStringParamInt *)PTR_DAT_00bbf7dc) {
    if (((byte)pSVar10[-1] & 0x80) == 0) {
      pSVar10 = pSVar10 + -2;
    }
    else {
      pSVar10 = pSVar10 + -4;
    }
    operator_delete__(pSVar10);
  }
  ExceptionList = param_2;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::IsMeaningFulPosition
// =================================================
int __thiscall
CTrackManiaRaceInterface::IsMeaningFulPosition
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  int iVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CGameRace *pCVar4;
  ulong unaff_retaddr;
  CGameRace *pCVar5;
  
  if (*(int *)(this + 0xa0) != 0) {
    pCVar5 = (CGameRace *)0x24044000;
    iVar1 = (**(code **)(**(int **)(this + 0xa0) + 0x10))();
    if (iVar1 != 0) {
      pCVar4 = *(CGameRace **)(this + 0xa0);
      CGameRace::GetLocalPlayerInfo(pCVar4,pCVar5);
      pCVar4 = pCVar4 + 0x590;
      uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(pCVar4,unaff_ESI);
      if (uVar2 != 0) {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar4,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            unaff_retaddr);
        iVar1 = CTrackManiaRaceScore::IsNullScore
                          (*(CTrackManiaRaceScore **)pSVar3,(CTrackManiaRaceScore *)param_1);
        return (uint)(iVar1 == 0);
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::NoMoveMessage_Start
// =================================================
void __thiscall
CTrackManiaRaceInterface::NoMoveMessage_Start
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,CFastStringInt *param_2)
{
{
  CFastStringInt *unaff_ESI;
  
  if (*(CControlLabel **)(this + 0xb0) != (CControlLabel *)0x0) {
    CControlLabel::SetLabel(*(CControlLabel **)(this + 0xb0),(CControlButton *)param_1,unaff_ESI);
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xb0),1);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::NoMoveMessage_Stop
// =================================================
void __thiscall
CTrackManiaRaceInterface::NoMoveMessage_Stop
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CPlugAudio *this_00;
  CMwId *pCVar1;
  CPlugAudio *unaff_ESI;
  
  *(undefined4 *)(this + 0xb4) = 0xffffffff;
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar1 = CPlugAudio::MwGetId(this_00,unaff_ESI);
  if ((*(int *)(this + 0xc0) == -1) || (1999 < (uint)(*(int *)pCVar1 - *(int *)(this + 0xc0)))) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xb0),0);
    *(undefined4 *)(this + 0xc0) = 0xffffffff;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::OnNetSpectatorCameraChange
// =================================================
void __thiscall
CTrackManiaRaceInterface::OnNetSpectatorCameraChange
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  int iVar1;
  
  if (*(int *)(this + 0xd8) != 0) {
    if (*(int *)(*(int *)(this + 0xa0) + 0x6c) == 2) {
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 300),0);
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x130),0);
      if ((((*(int *)(*(int *)(this + 0xa0) + 0x84) == 0) ||
           (iVar1 = *(int *)(*(int *)(this + 0xa0) + 700), iVar1 == 0)) ||
          (*(int *)(iVar1 + 0x70) != 0)) || (*(int *)(iVar1 + 0x74) != 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x128),iVar1);
                    /* WARNING: Could not recover jumptable at 0x004bf7c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(this + 0xa0) + 0xec))();
      return;
    }
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 300),1);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x130),1);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x128),1);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::OnServerInfoChange
// =================================================
void __thiscall
CTrackManiaRaceInterface::OnServerInfoChange
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CTrackManiaNetworkServerInfo *pCVar1;
  CTrackManiaNetwork *unaff_ESI;
  CTrackManiaNetwork *unaff_retaddr;
  CTrackManiaNetwork *in_stack_00000008;
  CTrackManiaNetwork *in_stack_0000000c;
  CTrackManiaNetwork *in_stack_00000010;
  CTrackManiaNetwork *in_stack_00000014;
  CTrackManiaNetwork *in_stack_00000018;
  CTrackManiaNetwork *in_stack_0000001c;
  
  pCVar1 = CTrackManiaNetwork::GetServerInfo(*(CTrackManiaNetwork **)(this + 0xa8),unaff_ESI);
  if (pCVar1 != (CTrackManiaNetworkServerInfo *)0x0) {
    pCVar1 = CTrackManiaNetwork::GetServerInfo(*(CTrackManiaNetwork **)(this + 0xa8),unaff_retaddr);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"EntryTimeAttackLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 1),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),(CTrackManiaNetwork *)param_1);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"EntryTeamPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 6),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_00000008);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"EntryRoundPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 3),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_0000000c);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"EntryEswcCupPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 9),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_00000010);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"LabelTimeAttackLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 1),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_00000014);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"LabelTeamPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 6),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_00000018);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"LabelRoundPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 3),1,0);
    pCVar1 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_0000001c);
    CControlTools::ControlRetrieveAndSetVisible
              (*(CControlContainer **)(this + 0xdc),"LabelEswcCupPointsLimit",
               (uint)(*(int *)(pCVar1 + 0x200) == 9),1,0);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::OnStuntEvent
// =================================================
void __thiscall
CTrackManiaRaceInterface::OnStuntEvent
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,SEventStunt *param_2)
{
{
  CFastStringInt *pCVar1;
  CTrackMania *this_00;
  int iVar2;
  ulong *puVar3;
  undefined *puVar4;
  CMwTimerAdapter *unaff_ESI;
  CFastStringInt *unaff_EDI;
  void *unaff_retaddr;
  CTrackMania *pCVar5;
  SEventStunt *pSVar6;
  CFastStringInt *pCVar7;
  undefined4 local_24;
  undefined *local_20;
  undefined4 local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined *local_4;
  
  local_8 = &LAB_00a8cc58;
  local_c = ExceptionList;
  pCVar1 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffd4);
  ExceptionList = &local_c;
  if (*(int *)param_1 == 0x22) {
    *(undefined4 *)(this + 0x158) = 1;
  }
  local_14 = (undefined *)0x0;
  local_10 = PTR_DAT_00bbf7dc;
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7dc;
  local_24 = 0;
  local_20 = PTR_DAT_00bbf7dc;
  pCVar7 = (CFastStringInt *)&local_24;
  pSVar6 = (SEventStunt *)&local_1c;
  pCVar5 = (CTrackMania *)&local_14;
  local_4 = (undefined *)0x2;
  this_00 = GetGame(this,(CTrackManiaEnvironmentManager *)param_1);
  iVar2 = CTrackMania::IsInStuntsMode(this_00,pCVar5);
  GetStuntMessages(iVar2,pSVar6,pCVar7,pCVar1,unaff_EDI);
  puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  *(ulong *)(this + 0x154) = *(int *)(*(int *)(this + 0xa0) + 0x130) + *puVar3;
  CControlTools::ControlSetLabel(*(CControlBase **)(this + 0x148),(CFastStringInt *)&local_8);
  CControlTools::ControlSetLabel(*(CControlBase **)(this + 0x14c),(CFastStringInt *)&local_10);
  CControlTools::ControlSetLabel(*(CControlBase **)(this + 0x150),(CFastStringInt *)&local_18);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x148),1);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x14c),0);
  iVar2 = (**(code **)(**(int **)(this + 0xa0) + 0xec))();
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x14c),iVar2);
  if (local_14 != PTR_DAT_00bbf7dc) {
    puVar4 = local_14 + -4;
    if ((local_14[-1] & 0x80) == 0) {
      puVar4 = local_14 + -2;
    }
    operator_delete__(puVar4);
    local_18 = (undefined *)0x0;
    local_14 = PTR_DAT_00bbf7dc;
  }
  if (local_c != PTR_DAT_00bbf7dc) {
    puVar4 = local_c + -4;
    if ((local_c[-1] & 0x80) == 0) {
      puVar4 = local_c + -2;
    }
    operator_delete__(puVar4);
    local_10 = (undefined *)0x0;
    local_c = PTR_DAT_00bbf7dc;
  }
  if (local_4 != PTR_DAT_00bbf7dc) {
    puVar4 = local_4 + -4;
    if ((local_4[-1] & 0x80) == 0) {
      puVar4 = local_4 + -2;
    }
    operator_delete__(puVar4);
  }
  ExceptionList = unaff_retaddr;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::OnStuntTimeOverMessage
// =================================================
void __thiscall
CTrackManiaRaceInterface::OnStuntTimeOverMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  ulong uVar1;
  CTrackMania *this_00;
  int iVar2;
  ulong *puVar3;
  CFastStringInt *pCVar4;
  undefined *puVar5;
  CGamePlayerInfo *pCVar6;
  CFastStringInt *extraout_EAX;
  undefined1 *puVar7;
  CMwTimerAdapter *unaff_EBP;
  CTrackMania *unaff_ESI;
  undefined *puStack00000010;
  void *in_stack_00000014;
  undefined1 uStack0000001c;
  wchar_t *in_stack_ffffffd4;
  SStringParam *in_stack_ffffffd8;
  CGameRace *in_stack_ffffffdc;
  int in_stack_ffffffe0;
  SStringParam *in_stack_ffffffe4;
  undefined *local_14;
  CFastStringInt local_10 [4];
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a8cc98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = GetGame(this,(CTrackManiaEnvironmentManager *)(DAT_00cca150 ^ (uint)&stack0xffffffcc));
  iVar2 = CTrackMania::IsInStuntsMode(this_00,unaff_ESI);
  if ((iVar2 != 0) && (*(int *)(this + 0x158) == 0)) {
    puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EBP);
    uVar1 = *puVar3;
    pCVar4 = (CFastStringInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Go to the Finish!",
                        in_stack_ffffffd4);
    CFastStringInt::CFastStringInt(&local_14,pCVar4,in_stack_ffffffd8);
    puStack00000010 = (undefined *)0x0;
    CControlTools::ControlSetLabel(*(CControlBase **)(this + 0x148),local_10);
    puStack00000010 = (undefined *)0xffffffff;
    if (local_c != PTR_DAT_00bbf7dc) {
      if ((local_c[-1] & 0x80) == 0) {
        puVar5 = local_c + -2;
      }
      else {
        puVar5 = local_c + -4;
      }
      operator_delete__(puVar5);
    }
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x148),1);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x14c),0);
    local_14 = PTR_DAT_00bbf7d8;
    puStack00000010 = (undefined *)0x1;
    pCVar6 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),in_stack_ffffffdc);
    CFastString::SetNatural
              ((CFastString *)&local_14,*(CFastString **)(pCVar6 + 0x2d4),1,0,0,0,1,
               in_stack_ffffffe0);
    CFastStringInt::CFastStringInt
              (&stack0x00000008,(CFastStringInt *)&stack0x00000000,in_stack_ffffffe4);
    uStack0000001c = 2;
    CControlTools::ControlSetLabel(*(CControlBase **)(this + 0x150),extraout_EAX);
    if (puStack00000010 != PTR_DAT_00bbf7dc) {
      if ((puStack00000010[-1] & 0x80) == 0) {
        puVar5 = puStack00000010 + -2;
      }
      else {
        puVar5 = puStack00000010 + -4;
      }
      operator_delete__(puVar5);
    }
    *(ulong *)(this + 0x154) = DAT_00cd4020 + uVar1;
    if (local_8 != PTR_DAT_00bbf7d8) {
      puVar7 = local_8 + -1;
      if ((local_8[-1] & 0x80) != 0) {
        puVar7 = local_8 + -4;
      }
      operator_delete__(puVar7);
    }
  }
  ExceptionList = in_stack_00000014;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::SetAvatarIconChat
// =================================================
void __thiscall
CTrackManiaRaceInterface::SetAvatarIconChat
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1,CGamePlayerInfo *param_2
          ,CFastStringInt *param_3)
{
{
  CTrackManiaRaceNet *pCVar1;
  int iVar2;
  CGamePlayerInfo *pCVar3;
  ulong *puVar4;
  CGameApp *unaff_EBX;
  CTrackManiaNetwork *unaff_ESI;
  EAvatarVariant unaff_EDI;
  EAvatarVariant unaff_retaddr;
  CFastStringInt *in_stack_00000010;
  
  if (param_1 != (CTrackManiaRaceInterface *)0x0) {
    pCVar1 = GetRace(this,unaff_ESI);
    iVar2 = CGameApp::Profile_IsAvatarsEnabled(*(CGameApp **)(pCVar1 + 0x18),unaff_EBX);
    if (iVar2 != 0) {
      pCVar3 = (CGamePlayerInfo *)CGameAvatar::ComputeVariantFromText(in_stack_00000010);
      CGameControlPlayerAvatar::Display
                (this + 0x220,(CGameControlPlayerAvatar *)param_1,pCVar3,unaff_EDI);
      CGameControlPlayerAvatar::Display
                (this + 0x23c,(CGameControlPlayerAvatar *)param_1,pCVar3,unaff_retaddr);
      puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),(CMwTimerAdapter *)param_1);
      *(ulong *)(this + 0x21c) = *puVar4;
      return;
    }
  }
  CGameControlPlayerAvatar::Display
            (this + 0x220,(CGameControlPlayerAvatar *)0x0,(CGamePlayerInfo *)0x0,unaff_retaddr);
  CGameControlPlayerAvatar::Display
            (this + 0x23c,(CGameControlPlayerAvatar *)0x0,(CGamePlayerInfo *)0x0,
             (EAvatarVariant)param_1);
  *(undefined4 *)(this + 0x21c) = 0;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateAsync
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateAsync(CTrackManiaRaceInterface *this,CInputPortDx8 *param_1)
{
{
  uint uVar1;
  bool bVar2;
  ulong *puVar3;
  CGamePlayerInfo *pCVar4;
  int iVar5;
  CTrackMania *pCVar6;
  int iVar7;
  CTrackManiaNetworkServerInfo *pCVar8;
  CTrackManiaRaceInterface *unaff_EBX;
  CGameRace *unaff_EBP;
  CMwTimerAdapter *unaff_ESI;
  CInputPortDx8 *unaff_EDI;
  CTrackManiaRaceInterface *unaff_retaddr;
  CTrackManiaEnvironmentManager *in_stack_00000008;
  CTrackManiaRaceInterface *in_stack_0000000c;
  CTrackManiaRaceInterface *in_stack_00000010;
  CTrackManiaRaceInterface *in_stack_00000014;
  CTrackManiaRaceInterface *in_stack_00000018;
  CTrackManiaRaceInterface *in_stack_0000001c;
  CTrackManiaRaceInterface *in_stack_00000020;
  CTrackManiaRaceInterface *in_stack_00000024;
  CTrackManiaRaceInterface *in_stack_00000028;
  CTrackManiaRaceInterface *in_stack_0000002c;
  CTrackManiaRaceInterface *in_stack_00000030;
  CTrackManiaRaceInterface *in_stack_00000034;
  CTrackManiaRaceInterface *in_stack_00000038;
  CTrackManiaRaceInterface *in_stack_0000003c;
  CTrackManiaRaceInterface *in_stack_00000054;
  CTrackManiaRaceInterface *pCVar9;
  
  CGamePlaygroundInterface::UpdateAsync((CGamePlaygroundInterface *)this,unaff_EDI);
  puVar3 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  uVar1 = *puVar3;
  pCVar4 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_EBP);
  pCVar9 = (CTrackManiaRaceInterface *)0x24044000;
  iVar5 = (**(code **)(**(int **)(this + 0xa0) + 0x10))();
  UpdateRaceCountdown(this,pCVar9);
  UpdateCheckpointInfo(this,unaff_EBX);
  UpdateNoMoveMessage(this,unaff_retaddr);
  UpdateTimeColor(this,(CTrackManiaRaceInterface *)param_1);
  pCVar6 = GetGame(this,in_stack_00000008);
  if ((*(int *)(pCVar6 + 0x268) == 0) && (*(int *)(*(int *)(this + 0xa0) + 0x260) == 0)) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xf0),iVar7);
  iVar7 = (**(code **)(**(int **)(this + 0xa0) + 0x10))();
  if (iVar7 == 0) {
LAB_004c6361:
    iVar7 = 0;
  }
  else {
    pCVar8 = CTrackManiaNetwork::GetServerInfo
                       (*(CTrackManiaNetwork **)(this + 0xa8),(CTrackManiaNetwork *)0x24044000);
    if (*(int *)(pCVar8 + 0x198) == 0) goto LAB_004c6361;
    iVar7 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xf4),iVar7);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xf8),*(int *)(this + 0x9c));
  UpdateCallVoteMessage(this,(CTrackManiaRaceInterface *)0x24044000);
  UpdateDownloadProgress(this,in_stack_0000000c);
  UpdateRaceMessage(this,in_stack_00000010);
  UpdateStuntMessage(this,in_stack_00000014);
  UpdateMainFramesVisibility(this,in_stack_00000018);
  if (iVar5 != 0) {
    UpdateRefereesWorkingMessage(this,in_stack_0000001c);
    UpdateChat(this,in_stack_00000020);
    UpdateChatIcon(this,in_stack_00000024);
    UpdateMultiCountdown(this,in_stack_00000028);
    UpdateSpectatorCounter(this,in_stack_0000002c);
    UpdateEndMatchCountdown(this,in_stack_00000030);
    UpdatePodium(this,in_stack_00000034);
  }
  if (uVar1 < *(uint *)(this + 0x270)) {
    if (*(int *)(this + 0x108) != 0) {
      iVar7 = (**(code **)(**(int **)(this + 0x108) + 0x108))();
      if (iVar7 != 0) goto LAB_004c640a;
    }
    iVar7 = 1;
  }
  else {
LAB_004c640a:
    iVar7 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x268),iVar7);
  if ((((*(int *)(pCVar4 + 0x88) == 0) && (*(int *)(pCVar4 + 0x90) != 0)) &&
      (*(int *)(pCVar4 + 0x6c) == 0)) &&
     (((*(int *)(pCVar4 + 0x70) == 0 || (*(int *)(pCVar4 + 0x2b4) != -1)) ||
      (*(int *)(pCVar4 + 0x2e0) != 0)))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x100),(uint)!bVar2);
  iVar7 = IsMeaningFulPosition(this,in_stack_00000038);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x104),iVar7);
  UpdateScores(this,in_stack_0000003c);
  if (*(int *)(this + 0x108) != 0) {
    iVar7 = (**(code **)(**(int **)(this + 0x108) + 0x108))();
    if (iVar7 != 0) {
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xb0),0);
    }
  }
  if (((iVar5 == 0) || (*(int *)(*(int *)(this + 0xa0) + 0x288) == 0)) ||
     (*(int *)(*(int *)(this + 0xa8) + 0x83c) != 2)) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xfc),iVar7);
  if (((iVar5 == 0) || (*(int *)(*(int *)(this + 0xa0) + 0x288) == 0)) ||
     (*(int *)(*(int *)(this + 0xa8) + 0x83c) != 3)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x114),iVar5);
  UpdatePleaseWaitMessage(this,in_stack_00000054);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateCallVoteMessage
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateCallVoteMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  CTrackManiaRaceInterface *in_stack_00000008;
  
  if (*(int *)(this + 0x13c) != 0) {
    puVar1 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
    if (*(int *)(this + 0x13c) + 3000U < *puVar1) {
      CallVoteMessage_Hide(this,in_stack_00000008);
      return;
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateChat
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateChat
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  uint *puVar1;
  CGameNetwork *pCVar2;
  CGamePlayerInfo CVar3;
  CGamePlayerInfo *pCVar4;
  int iVar5;
  int extraout_EAX;
  ulong uVar6;
  CPlugTreeGenText *this_00;
  SCasterCat *pSVar7;
  CGameNetPlayerInfo *pCVar8;
  CControlEntry *this_01;
  SStringParam *unaff_EBX;
  CFastStringInt *unaff_ESI;
  CGamePlaygroundInterface *unaff_EDI;
  CFastStringInt *pCVar9;
  CGamePlayerInfo CVar10;
  uchar in_stack_ffffff80;
  uchar in_stack_ffffff84;
  uchar uVar11;
  ulong in_stack_ffffff88;
  ulong in_stack_ffffff8c;
  int iVar12;
  SParam_Fids *pSVar13;
  char cVar14;
  SStringParam *pSVar15;
  CFastStringInt *pCVar16;
  CFastStringInt *pCVar17;
  SNationConfig *pSVar18;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffa8;
  undefined1 *puStack_54;
  undefined *local_50;
  undefined4 local_4c;
  CGameNetwork *pCStack_48;
  undefined *puStack_44;
  undefined1 auStack_40 [4];
  CFastStringInt aCStack_3c [4];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined *puStack_18;
  CGameNetwork *local_14;
  undefined1 *local_10;
  undefined4 uStack_c;
  
  pCVar17 = (CFastStringInt *)&stack0xfffffffc;
  uStack_c = 0xffffffff;
  local_10 = &LAB_00a8cd48;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(CGameRace **)(this + 0xa0) == (CGameRace *)0x0) {
    ExceptionList = local_10;
    return;
  }
  iVar12 = 0x4c3d64;
  pCVar4 = CGameRace::GetLocalPlayerInfo
                     (*(CGameRace **)(this + 0xa0),
                      (CGameRace *)(DAT_00cca150 ^ (uint)&stack0xffffff98));
  if (pCVar4 == (CGamePlayerInfo *)0x0) {
    ExceptionList = local_10;
    return;
  }
  if (DAT_00d566cc != 0) {
    if (*(int *)(*(int *)(this + 0xa0) + 0x288) == 0) {
      if (((*(int **)(this + 0x210) != (int *)0x0) &&
          (iVar5 = (**(code **)(**(int **)(this + 0x210) + 0x108))(), iVar5 != 0)) &&
         ((*(uint *)(*(int *)(this + 0x210) + 0xfc) & 0x4000) == 0)) {
        puVar1 = (uint *)(*(int *)(this + 0x210) + 0xfc);
        *puVar1 = *puVar1 & 0xfffffffd;
        cVar14 = -0x2b;
        (**(code **)(**(int **)(this + 0x210) + 0x1a8))();
        this_01 = *(CControlEntry **)(this + 0x210);
LAB_004c3e32:
        in_stack_ffffff80 = 0xcc;
        CControlEntry::SetEditedStringAndGiveFocus
                  (this_01,(CControlEntry *)&DAT_00d566cc,DAT_00d56698,in_stack_ffffff88);
        in_stack_ffffff88 = 0;
        in_stack_ffffff84 = 'G';
        CFastStringInt::SetLength(&DAT_00d566cc,(CFastString *)0x0,in_stack_ffffff8c,iVar12,cVar14);
      }
    }
    else if (((*(int **)(this + 0x25c) != (int *)0x0) &&
             (iVar5 = (**(code **)(**(int **)(this + 0x25c) + 0x108))(), iVar5 != 0)) &&
            ((*(uint *)(*(int *)(this + 0x25c) + 0xfc) & 0x4000) == 0)) {
      puVar1 = (uint *)(*(int *)(this + 0x25c) + 0xfc);
      *puVar1 = *puVar1 & 0xfffffffd;
      cVar14 = '%';
      (**(code **)(**(int **)(this + 0x25c) + 0x1a8))();
      this_01 = *(CControlEntry **)(this + 0x25c);
      goto LAB_004c3e32;
    }
  }
  uVar11 = (uchar)in_stack_ffffff88;
  if (*(int *)(this + 0x298) == 0) goto LAB_004c3efd;
  pSVar13 = (SParam_Fids *)&local_50;
  pCVar2 = (CGameNetwork *)(this + 0x290);
  local_50 = &DAT_00b45a7c;
  local_4c = 3;
  iVar12 = 0x4c3e77;
  CFastStringInt::Compare(pCVar2,pSVar13,(SParam *)0x3,(int *)unaff_EDI,(int *)unaff_ESI);
  if (extraout_EAX == 0) {
    CFastStringInt::TruncBeforeIndex(pCVar2,(CFastStringInt *)0x2,(ulong)pCVar17);
    if ((*(int *)(pCVar4 + 0x70) == 0) && (*(int *)(pCVar4 + 0x74) == 0)) {
      CVar10 = *(CGamePlayerInfo *)(*(int *)(this + 0xa0) + 0x1c);
      CVar3 = pCVar4[0x24];
      pCVar17 = (CFastStringInt *)0x0;
      if (CVar3 == CVar10) {
        pSVar15 = (SStringParam *)0x3;
      }
      else {
LAB_004c3ea7:
        pCVar17 = (CFastStringInt *)0x0;
        pSVar15 = (SStringParam *)0x1;
        CVar10 = CVar3;
      }
    }
    else {
      CVar3 = pCVar4[0x78];
      pCVar17 = (CFastStringInt *)0x0;
      if (CVar3 != (CGamePlayerInfo)0xfc) goto LAB_004c3ea7;
      pSVar15 = (SStringParam *)0x2;
      CVar10 = *(CGamePlayerInfo *)(*(int *)(this + 0xa0) + 0x1c);
    }
  }
  else {
    pSVar15 = (SStringParam *)0x0;
    pSVar13 = (SParam_Fids *)0x0;
    CVar10 = (CGamePlayerInfo)0xff;
  }
  unaff_ESI = (CFastStringInt *)0x0;
  unaff_EDI = (CGamePlaygroundInterface *)0x0;
  CGameNetwork::ChatSend
            (*(CGameNetwork **)(this + 0xa8),pCVar2,(CFastStringInt *)0xff,(uchar)CVar10,
             in_stack_ffffff80,in_stack_ffffff84,uVar11,iVar12,(int)pSVar13);
  puStack_54 = &DAT_00b2c878;
  local_50 = (undefined *)0x0;
  CFastStringInt::SetString(pCVar2,(CFastStringInt *)&puStack_54,pSVar15);
  *(undefined4 *)(this + 0x298) = 0;
LAB_004c3efd:
  if ((*(int *)(*(int *)(this + 0xa8) + 0xac) != 0) || (*(int *)(this + 0x29c) != 0)) {
    pCVar16 = (CFastStringInt *)0x4c3f1e;
    iVar12 = CGamePlaygroundInterface::ChatIsAllowed((CGamePlaygroundInterface *)this,unaff_EDI);
    if (iVar12 != 0) {
      if (*(int *)(this + 0x214) != 0) {
        if (*(int *)(*(int *)(this + 0xa8) + 0xac) != 0) {
          uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                            ((void *)(*(int *)(this + 0xa8) + 0x88),
                             (CFastBuffer<class_CCrystalFace*> *)0x4c3f4f);
          if (uVar6 == 0) {
            unaff_EDI = (CGamePlaygroundInterface *)0x4c408b;
            SStringParam::SStringParam(&uStack_38,(SStringParam *)&DAT_00b2c98c,(char *)pCVar17);
            pCVar17 = (CFastStringInt *)&uStack_34;
            unaff_ESI = (CFastStringInt *)0x4c40a1;
            CFastStringInt::SetString((void *)(*(int *)(this + 0x214) + 0x130),pCVar17,unaff_EBX);
          }
          else {
            pCStack_48 = (CGameNetwork *)0x0;
            puStack_44 = PTR_DAT_00bbf7dc;
            unaff_EDI = (CGamePlaygroundInterface *)0x4c3f77;
            SStringParam::SStringParam(auStack_40,(SStringParam *)&DAT_00b2c878,(char *)pCVar17);
            pCVar17 = aCStack_3c;
            unaff_ESI = (CFastStringInt *)0x4c3f8d;
            CFastStringInt::SetString((void *)(*(int *)(this + 0x214) + 0x130),pCVar17,unaff_EBX);
            pSVar18 = (SNationConfig *)0x4c3f9e;
            uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                              ((void *)(*(int *)(this + 0xa8) + 0x88),in_stack_ffffffa8);
            for (pCVar9 = (CFastStringInt *)(uVar6 - 1); -1 < (int)pCVar9; pCVar9 = pCVar9 + -1) {
              CGameNetwork::FormatChat
                        (*(CGameNetwork **)(this + 0xa8),(CGameNetwork *)&puStack_54,pCVar9,0xb45a70
                         ,"0F0","F00",(char *)pCVar16);
              if ((int)pCVar9 < 1) {
                uStack_28 = local_50;
                uStack_2c = local_4c;
                uStack_24 = 0;
                SStringParam::SStringParam(auStack_40,(SStringParam *)"$z$s%1",(char *)unaff_EDI);
                pSVar15 = (SStringParam *)&uStack_28;
                pCVar16 = aCStack_3c;
              }
              else {
                uStack_38 = local_4c;
                uStack_34 = local_50;
                uStack_30 = 0;
                SStringParam::SStringParam(&pCStack_48,(SStringParam *)"$z$s%1\n",(char *)unaff_EDI)
                ;
                pSVar15 = (SStringParam *)&uStack_34;
                pCVar16 = (CFastStringInt *)&puStack_44;
              }
              CFastStringInt::SetCompose(&local_4c,pCVar16,pSVar15,(SStringParamInt *)unaff_ESI);
              puStack_18 = puStack_44;
              unaff_ESI = (CFastStringInt *)&puStack_18;
              local_14 = pCStack_48;
              local_10 = (undefined1 *)0x0;
              unaff_EDI = (CGamePlaygroundInterface *)0x4c4061;
              CFastStringInt::Concat
                        ((void *)(*(int *)(this + 0x214) + 0x130),unaff_ESI,(SStringParam *)pCVar17)
              ;
            }
            pCVar17 = (CFastStringInt *)0x4c407b;
            CGameCtnApp::SNationConfig::~SNationConfig(&puStack_44,pSVar18);
          }
          unaff_EBX = (SStringParam *)0x4c40b1;
          (**(code **)(**(int **)(this + 0x214) + 0x1a8))();
          if ((*(int *)(this + 0x2a0) == 0) && (*(int *)(this + 0x218) != 0)) {
            uStack_24 = *(undefined4 *)(*(int *)(this + 0x214) + 0x134);
            uStack_20 = *(undefined4 *)(*(int *)(this + 0x214) + 0x130);
            uStack_1c = 0;
            CFastStringInt::SetString
                      ((void *)(*(int *)(this + 0x218) + 0x130),(CFastStringInt *)&uStack_24,
                       (SStringParam *)pCVar16);
            pCVar16 = (CFastStringInt *)0x4c4102;
            (**(code **)(**(int **)(this + 0x218) + 0x1a8))();
          }
          if (((*(int *)(*(int *)(this + 0xa0) + 0x288) != 0) && (*(int *)(this + 0x25c) != 0)) &&
             (*(int *)(this + 0x260) != 0)) {
            uStack_30 = *(undefined4 *)(*(int *)(this + 0x214) + 0x134);
            uStack_2c = *(undefined4 *)(*(int *)(this + 0x214) + 0x130);
            uStack_28 = 0;
            CFastStringInt::SetString
                      ((void *)(*(int *)(this + 0x260) + 0x130),(CFastStringInt *)&uStack_30,
                       (SStringParam *)pCVar16);
            pCVar16 = (CFastStringInt *)0x4c4161;
            (**(code **)(**(int **)(this + 0x260) + 0x1a8))();
          }
        }
        this_00 = CControlText::GetTextGenerator
                            (*(CControlText **)(this + 0x214),(CControlText *)pCVar16);
        if (this_00 != (CPlugTreeGenText *)0x0) {
          uVar6 = CPlugTreeGenText::ComputeLineCount(this_00,(CPlugTreeGenText *)unaff_EDI);
          if (uVar6 < 5) {
            uVar6 = 5;
          }
          if (uVar6 - 5 < *(uint *)(this + 0x2a4)) {
            *(ulong *)(this + 0x2a4) = uVar6 - 5;
          }
          *(ulong *)(this_00 + 0x4c) = (uVar6 - *(int *)(this + 0x2a4)) + -5;
          *(ulong *)(this_00 + 0x50) = (uVar6 - *(int *)(this + 0x2a4)) + -1;
          unaff_EDI = (CGamePlaygroundInterface *)0x4c41be;
          (**(code **)(**(int **)(this + 0x214) + 0x1a8))();
        }
      }
      uVar11 = (uchar)pCVar17;
      pCVar2 = *(CGameNetwork **)(this + 0xa8);
      if ((*(int *)(pCVar2 + 0xac) != 0) &&
         (uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                            (pCVar2 + 0x88,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI),
         uVar6 != 0)) {
        pSVar7 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (pCVar2 + 0x94,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                            (ulong)unaff_ESI);
        pCStack_48 = (CGameNetwork *)CONCAT31(pCStack_48._1_3_,*pSVar7);
        pCVar8 = CGameNetwork::GetPlayerInfoFromUId(pCVar2,pCStack_48,uVar11);
        if (pCVar8 != (CGameNetPlayerInfo *)0x0) {
          pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                             ((void *)(*(int *)(this + 0xa8) + 0x88),
                              (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,(ulong)unaff_EBX
                             );
          SetAvatarIconChat(this,(CTrackManiaRaceInterface *)pCVar8,(CGamePlayerInfo *)pSVar7,
                            (CFastStringInt *)in_stack_ffffffa8);
        }
      }
    }
    *(undefined4 *)(*(int *)(this + 0xa8) + 0xac) = 0;
    *(undefined4 *)(this + 0x29c) = 0;
  }
  ExceptionList = local_10;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateChatIcon
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateChatIcon
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  CFastStringInt *unaff_retaddr;
  
  if (*(int *)(this + 0x21c) != 0) {
    puVar1 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
    if ((*(uint *)(this + 0x21c) < *puVar1) && (3000 < *puVar1 - *(uint *)(this + 0x21c))) {
      SetAvatarIconChat(this,(CTrackManiaRaceInterface *)0x0,(CGamePlayerInfo *)&DAT_00d71d58,
                        unaff_retaddr);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateCheckpointInfo
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateCheckpointInfo
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  CPlugAudio *this_00;
  CMwId *pCVar2;
  CPlugAudio *unaff_ESI;
  CGameRace *unaff_EDI;
  
  pCVar1 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_EDI);
  this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_00 == (CPlugAudio *)0x0) {
    this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar2 = CPlugAudio::MwGetId(this_00,unaff_ESI);
  if ((((*(int *)(pCVar1 + 0x70) == 0) && (*(int *)(pCVar1 + 0x74) == 0)) &&
      (*(int *)(this + 0x188) != 0)) && (*(int *)(this + 0x188) + 2000U < *(uint *)pCVar2)) {
    *(undefined4 *)(this + 0x188) = 0;
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x178),0);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x17c),0);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x180),0);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x184),0);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateDownloadProgress
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRaceInterface::UpdateDownloadProgress
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  char cVar1;
  SCasterCat *pSVar2;
  SDownloadProgress *unaff_EBX;
  void *this_00;
  SDownloadProgress *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SDownloadProgress *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> **ppCVar4;
  SDownloadProgress *unaff_EDI;
  float fVar5;
  int in_stack_0000000c;
  CFastBuffer<class_CCrystalFace*> *in_stack_ffffffac;
  SDownloadProgress *in_stack_ffffffb0;
  SDownloadProgress *in_stack_ffffffb4;
  SDownloadProgress *in_stack_ffffffb8;
  SDownloadProgress *pSVar6;
  SDownloadProgress *in_stack_ffffffc0;
  SDownloadProgress *in_stack_ffffffc4;
  float local_38;
  ulong local_34;
  ulong local_30;
  float local_2c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_28 [4];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_18;
  int iStack_14;
  undefined1 auStack_10 [8];
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_8;
  int local_4;
  
  this_00 = (void *)(*(int *)(*(int *)(this + 0xa8) + 0x1b4) + 0x2c);
  `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
  SDownloadProgress::SDownloadProgress(&stack0xffffffc0,unaff_EDI);
  `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
  SDownloadProgress::SDownloadProgress(&local_2c,unaff_ESI);
  `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
  SDownloadProgress::SDownloadProgress(&local_18,unaff_EBP);
  `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
  SDownloadProgress::SDownloadProgress(&local_4,unaff_EBX);
  pSVar6 = (SDownloadProgress *)0x0;
  local_30 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_ffffffac);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (local_30 != 0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar3,(ulong)in_stack_ffffffb0);
      cVar1 = *(char *)(*(int *)(*(CNetFileTransferDownload **)pSVar2 + 0x74) + 0x70);
      if ((cVar1 == DAT_00ce9c28) || (cVar1 == DAT_00ce9c29)) {
        ppCVar4 = local_28;
      }
      else if ((cVar1 == DAT_00ce9c2a) || (cVar1 == DAT_00ce9c2b)) {
        ppCVar4 = &local_18;
      }
      else if (cVar1 == DAT_00ce9c2c) {
        ppCVar4 = &local_8;
      }
      else {
        ppCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)&stack0x00000008;
      }
      local_34 = 0;
      local_38 = 0.0;
      in_stack_ffffffb0 = (SDownloadProgress *)&local_34;
      CNetFileTransferDownload::GetSizeDone
                (*(CNetFileTransferDownload **)pSVar2,(CNetFileTransferDownload *)&local_38,
                 (ulong *)in_stack_ffffffb0,(ulong *)in_stack_ffffffb4);
      *ppCVar4 = *ppCVar4 + 1;
      if ((local_34 == local_30) && (local_30 != 0)) {
        ppCVar4[1] = ppCVar4[1] + 1;
      }
      else {
        ppCVar4[2] = ppCVar4[2] + local_34;
        ppCVar4[3] = ppCVar4[3] + local_30;
        if (local_30 != 0) {
          local_2c = (float)(int)local_34;
          if ((int)local_34 < 0) {
            local_2c = local_2c + _DAT_00c418d0;
          }
          fVar5 = (float)(int)local_30;
          if ((int)local_30 < 0) {
            fVar5 = fVar5 + _DAT_00c418d0;
          }
          local_2c = local_2c / fVar5;
          if (local_2c < local_38 == (local_2c == local_38)) {
            local_38 = local_2c;
          }
        }
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < local_28[0]);
  }
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetTotalProgress(&local_2c,in_stack_ffffffb0);
  *(float *)(this + 0x1d0) = fVar5;
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetCurProgress(local_28,in_stack_ffffffb4);
  *(float *)(this + 0x1d4) = fVar5;
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetTotalProgress(&iStack_14,in_stack_ffffffb8);
  *(float *)(this + 0x1d8) = fVar5;
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetCurProgress(auStack_10,pSVar6);
  *(float *)(this + 0x1dc) = fVar5;
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetTotalProgress(&param_1,in_stack_ffffffc0);
  *(float *)(this + 0x1e0) = fVar5;
  fVar5 = `private:_void___thiscall_CTrackManiaRaceInterface::UpdateDownloadProgress(void)'::__l2::
          SDownloadProgress::GetCurProgress(&stack0x00000008,in_stack_ffffffc4);
  *(float *)(this + 0x1e4) = fVar5;
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x1e8) = local_28[0];
  CControlTools::ControlSetVisible
            (*(CControlBase **)(this + 0x1cc),(uint)(0.0 < (float)local_28[0]));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1b4),(uint)(iStack_14 != 0));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1b8),(uint)(iStack_14 != 0));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1bc),(uint)(local_4 != 0));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1c0),(uint)(local_4 != 0));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1c4),(uint)(in_stack_0000000c != 0));
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1c8),(uint)(in_stack_0000000c != 0));
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateEndMatchCountdown
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateEndMatchCountdown
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGameRace *this_00;
  uint uVar1;
  CGamePlayerInfo *pCVar2;
  int iVar3;
  int iVar4;
  CGameRace *unaff_EDI;
  
  this_00 = *(CGameRace **)(this + 0xa0);
  pCVar2 = CGameRace::GetLocalPlayerInfo(this_00,unaff_EDI);
  iVar3 = (**(code **)(*(int *)this + 0x98))();
  uVar1 = *(uint *)(iVar3 + 0x80);
  iVar3 = *(int *)(*(int *)(this + 0xa8) + 0x65c);
  if (*(int *)(this_00 + 0x288) == 0) {
    if ((*(int *)(pCVar2 + 0x70) == 0) && (*(int *)(pCVar2 + 0x74) == 0)) {
      iVar3 = (**(code **)(*(int *)this_00 + 0x1a8))();
      if ((iVar3 != 0) && (*(int *)(pCVar2 + 0x2ac) != 0)) goto LAB_004bf275;
    }
    else {
      iVar4 = (**(code **)(*(int *)this_00 + 0x1a8))();
      if ((iVar4 != 0) && (*(int *)(pCVar2 + 0x2ac) != 0)) goto LAB_004bf29c;
    }
  }
  else {
LAB_004bf29c:
    if (iVar3 == 0) {
LAB_004bf275:
      if ((uVar1 >> 7 & 1) == 0) {
        iVar3 = 1;
        goto LAB_004bf2a0;
      }
    }
  }
  iVar3 = 0;
LAB_004bf2a0:
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x160),iVar3);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateLapsCounter
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateLapsCounter
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CControlTools::ControlSetVisible
            (*(CControlBase **)(this + 0x19c),(uint)(1 < *(uint *)(*(int *)(this + 0xa0) + 0xec)));
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateMainFramesVisibility
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateMainFramesVisibility
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  bool bVar1;
  CGamePlayer *pCVar2;
  CGameControlCamera *pCVar3;
  int iVar4;
  int iVar5;
  CGamePlaygroundInterface *unaff_EBX;
  uint uVar6;
  CGamePlaygroundInterface *unaff_EBP;
  byte *pbVar7;
  CGameRace *unaff_ESI;
  CGamePlayerCameraSet *unaff_EDI;
  int unaff_retaddr;
  CTrackManiaRaceInterface *in_stack_00000014;
  CGameRace *pCVar8;
  CTrackManiaRaceInterface *in_stack_fffffff4;
  int iStack_4;
  
  CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_ESI);
  pCVar8 = (CGameRace *)0x24042000;
  (**(code **)(**(int **)(this + 0xa0) + 0x10))();
  iVar5 = *(int *)(*(CGameRace **)(this + 0xa0) + 0x288);
  pCVar2 = CGameRace::GetLocalPlayer(*(CGameRace **)(this + 0xa0),pCVar8);
  pCVar3 = CGamePlayerCameraSet::CamPtrGetCur(*(CGamePlayerCameraSet **)(pCVar2 + 0x20),unaff_EDI);
  if ((pCVar3 == (CGameControlCamera *)0x0) ||
     ((*(int *)(pCVar3 + 0xb0) == 0 &&
      (iVar4 = (**(code **)(*(int *)pCVar3 + 0x10))(0x3072000), iVar4 == 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iVar4 = (**(code **)(*(int *)this + 0x98))();
  pbVar7 = (byte *)(iVar4 + 0x80);
  uVar6 = *(uint *)(iVar4 + 0x80) >> 7 & 1;
  if (((iVar5 == 0) && (iStack_4 == 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xcc),iVar4);
  if (((iVar5 == 0) && ((*pbVar7 & 2) != 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xe8),iVar4);
  if (((iVar5 == 0) && ((*pbVar7 & 2) != 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xec),iVar4);
  if ((((iVar5 == 0) && (iStack_4 == 0)) && (unaff_retaddr != 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xe0),iVar4);
  if (((iVar5 == 0) && (iStack_4 != 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xd8),iVar4);
  if (((iVar5 == 0) && (iStack_4 == 0)) &&
     ((unaff_retaddr == 0 && (((*pbVar7 & 4) != 0 && (uVar6 == 0)))))) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x118),iVar4);
  if ((((iVar5 == 0) &&
       (iVar4 = CGamePlaygroundInterface::ChatIsAllowed((CGamePlaygroundInterface *)this,unaff_EBP),
       iVar4 != 0)) && ((*pbVar7 & 8) != 0)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x204),iVar4);
  if (((iVar5 == 0) && (bVar1)) && (uVar6 == 0)) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xe4),iVar4);
  if (((iVar5 == 0) && (iStack_4 == 0)) && (((*pbVar7 & 0x10) != 0 && (uVar6 == 0)))) {
    iVar4 = 1;
  }
  else {
    iVar4 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1a4),iVar4);
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x264),(uint)(uVar6 == 0));
  if ((((iVar5 == 0) ||
       (iVar5 = CGamePlaygroundInterface::ChatIsAllowed((CGamePlaygroundInterface *)this,unaff_EBX),
       iVar5 == 0)) || ((*pbVar7 & 8) == 0)) || (uVar6 != 0)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 600),iVar5);
  UpdateLapsCounter(this,in_stack_fffffff4);
  OnServerInfoChange(this,in_stack_00000014);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateMultiCountdown
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateMultiCountdown
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGameRace *this_00;
  uint uVar1;
  CGamePlayerInfo *pCVar2;
  CPlugAudio *this_01;
  CMwId *pCVar3;
  uint uVar4;
  CPlugAudio *unaff_ESI;
  CGameRace *unaff_EDI;
  
  this_00 = *(CGameRace **)(this + 0xa0);
  pCVar2 = CGameRace::GetLocalPlayerInfo(this_00,unaff_EDI);
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar3 = CPlugAudio::MwGetId(this_01,unaff_ESI);
  uVar1 = *(uint *)pCVar3;
  if (*(int *)(*(int *)(this + 0xa0) + 0x288) == 0) {
    uVar4 = (**(code **)(*(int *)this_00 + 0x1a8))();
    if (*(int *)(pCVar2 + 0x2ac) == 0) goto LAB_004bf397;
    if (uVar4 == 0) {
      return;
    }
  }
  else {
    if (*(int *)(*(int *)(this + 0xa8) + 0x65c) != 0) {
      return;
    }
    uVar4 = *(uint *)(*(int *)(this + 0xa8) + 0x838);
    if (uVar4 == 0) goto LAB_004bf369;
  }
  if (uVar1 < uVar4) {
    uVar4 = uVar4 - uVar1;
LAB_004bf397:
    *(uint *)(this + 200) = uVar4;
    return;
  }
LAB_004bf369:
  *(undefined4 *)(this + 200) = 0;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateNoMoveMessage
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRaceInterface::UpdateNoMoveMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  int iVar1;
  undefined *puVar2;
  CTrackManiaPlayerProfile *pCVar3;
  CGamePlayerInfo *pCVar4;
  CMwId *pCVar5;
  CGamePlayer *pCVar6;
  ulong uVar7;
  int iVar8;
  SStringParamInt *pSVar9;
  CPlugAudio *this_00;
  CGameRace *unaff_EBX;
  CGameRace *unaff_ESI;
  CTrackMania *unaff_EDI;
  bool bVar10;
  float10 fVar11;
  undefined1 uStack0000000c;
  void *in_stack_0000001c;
  CFastStringInt *pCVar12;
  SStringParam *pSVar13;
  wchar_t *in_stack_ffffffb8;
  CFastStringInt *in_stack_ffffffbc;
  SNationConfig *pSVar14;
  SNationConfig *pSVar15;
  SNationConfig *pSVar16;
  SNationConfig *pSStack_30;
  undefined *puStack_2c;
  undefined4 uStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  SNationConfig *pSStack_1c;
  undefined4 uStack_18;
  undefined *puStack_14;
  SNationConfig *pSStack_10;
  void *local_c;
  undefined1 *puStack_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  puStack_8 = &LAB_00a8ce18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar3 = CTrackMania::GetTMCurrentProfile
                     (*(CTrackMania **)(*(int *)(this + 0xa0) + 0x18),
                      (CTrackMania *)(DAT_00cca150 ^ (uint)&stack0xffffffa8));
  if ((2 < *(uint *)(pCVar3 + 0x2fc)) &&
     (pCVar3 = CTrackMania::GetTMCurrentProfile
                         (*(CTrackMania **)(*(int *)(this + 0xa0) + 0x18),unaff_EDI),
     2 < *(uint *)(pCVar3 + 0x300))) {
    ExceptionList = pvStack_4;
    return;
  }
  pCVar4 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_ESI);
  if (*(int *)(pCVar4 + 0x70) != 0) {
    ExceptionList = pvStack_4;
    return;
  }
  if (*(int *)(pCVar4 + 0x74) != 0) {
    ExceptionList = pvStack_4;
    return;
  }
  if (3 < *(uint *)(*(int *)(this + 0xa0) + 0x500)) {
    this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
    }
    unaff_ESI = (CGameRace *)0x4c4d26;
    pCVar5 = CPlugAudio::MwGetId(this_00,(CPlugAudio *)0x4c4d26);
    iVar8 = *(int *)pCVar5;
    bVar10 = false;
    pCVar12 = (CFastStringInt *)0x4c4d35;
    pCVar6 = CGameRace::GetLocalPlayer(*(CGameRace **)(this + 0xa0),unaff_EBX);
    if ((((pCVar6 != (CGamePlayer *)0x0) && (iVar1 = *(int *)(pCVar6 + 0x1c), iVar1 != 0)) &&
        (*(int *)(iVar1 + 0x70) == 0)) &&
       ((*(int *)(iVar1 + 0x74) == 0 && (*(int *)(iVar1 + 0x314) == 1)))) {
      if (*(int *)(pCVar6 + 0x28) != 0) {
        unaff_EBX = (CGameRace *)0x4c4d7b;
        fVar11 = (float10)(**(code **)(**(int **)(*(int *)(pCVar6 + 0x28) + 0x14) + 0x134))();
        uVar7 = GmFunc::IsZero(ABS((float)fVar11),_DAT_00b36160);
        bVar10 = uVar7 == 0;
        if ((bVar10) && ((uint)(iVar8 - *(int *)(this + 0xc4)) < *(uint *)(this + 0xbc)))
        goto LAB_004c4f8d;
      }
      if ((*(int *)(this + 0xb4) == -1) && (!bVar10)) {
        *(int *)(this + 0xb4) = iVar8;
      }
      if (((*(int *)(this + 0xc0) != -1) ||
          ((uint)(iVar8 - *(int *)(this + 0xb4)) < *(uint *)(this + 0xb8))) &&
         ((uint)(iVar8 - *(int *)(this + 0xc4)) < *(uint *)(this + 0xbc))) {
        ExceptionList = pvStack_4;
        return;
      }
      *(int *)(this + 0xc0) = iVar8;
      puVar2 = PTR_DAT_00bbf7dc;
      pSVar16 = (SNationConfig *)0x0;
      pSVar14 = (SNationConfig *)0x0;
      pSVar15 = (SNationConfig *)PTR_DAT_00bbf7dc;
      GetKeyFromActionIndex
                (this,(CTrackManiaRaceInterface *)PTR_DAT_00cd3f5c,
                 (SInputActionDesc *)&stack0xffffffc8,(CFastStringInt *)unaff_ESI);
      GetKeyFromActionIndex
                (this,(CTrackManiaRaceInterface *)PTR_DAT_00cd3f60,
                 (SInputActionDesc *)&stack0xffffffc4,pCVar12);
      uStack_28 = 0;
      puStack_24 = PTR_DAT_00bbf7dc;
      uStack0000000c = 2;
      iVar8 = (**(code **)(**(int **)(this + 0xa0) + 0xf4))();
      if ((iVar8 == 0) && (iVar8 = (**(code **)(**(int **)(this + 0xa0) + 0xf0))(), iVar8 == 0)) {
        puStack_20 = puStack_2c;
        pSStack_1c = pSStack_30;
        uStack_18 = 0;
        puStack_14 = puVar2;
        local_c = (void *)0x0;
        pSStack_10 = pSVar16;
        pSVar9 = (SStringParamInt *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,
                            (CClassicI18n *)L"Press %1 to respawn\nPress %2 to restart",
                            (wchar_t *)unaff_EBX);
        SStringParamInt::SStringParamInt(&pvStack_4,pSVar9,in_stack_ffffffb8);
        pSVar9 = (SStringParamInt *)&uStack_18;
        pSVar13 = (SStringParam *)&local_c;
      }
      else {
        puStack_14 = puStack_2c;
        puStack_20 = puVar2;
        pSStack_10 = pSStack_30;
        local_c = (void *)0x0;
        uStack_18 = 0;
        pSStack_1c = pSVar16;
        pSVar9 = (SStringParamInt *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,
                            (CClassicI18n *)L"Press %1 to respawn\nPress %2 to retire",
                            (wchar_t *)unaff_EBX);
        SStringParamInt::SStringParamInt(&pvStack_4,pSVar9,in_stack_ffffffb8);
        pSVar9 = (SStringParamInt *)&local_c;
        pSVar13 = (SStringParam *)&uStack_18;
      }
      CFastStringInt::SetCompose(&puStack_20,(CFastStringInt *)&stack0x00000000,pSVar13,pSVar9);
      NoMoveMessage_Start(this,(CTrackManiaRaceInterface *)&puStack_20,in_stack_ffffffbc);
      CGameCtnApp::SNationConfig::~SNationConfig(&pSStack_1c,pSVar14);
      CGameCtnApp::SNationConfig::~SNationConfig(&uStack_28,pSVar15);
      CGameCtnApp::SNationConfig::~SNationConfig(&pSStack_1c,pSVar16);
      ExceptionList = in_stack_0000001c;
      return;
    }
    if (*(int **)(this + 0xb0) == (int *)0x0) {
      ExceptionList = pvStack_4;
      return;
    }
    iVar8 = (**(code **)(**(int **)(this + 0xb0) + 0x108))();
    if (iVar8 == 0) {
      ExceptionList = pvStack_4;
      return;
    }
  }
LAB_004c4f8d:
  NoMoveMessage_Stop(this,(CTrackManiaRaceInterface *)unaff_ESI);
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdatePleaseWaitMessage
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdatePleaseWaitMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  int iVar2;
  CGameRace *unaff_ESI;
  
  if (*(int *)(this + 0x9c) == 0) {
    return;
  }
  if (*(CGameRace **)(this + 0xa0) == (CGameRace *)0x0) {
    return;
  }
  pCVar1 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_ESI);
  if (pCVar1 == (CGamePlayerInfo *)0x0) {
    return;
  }
  if ((((*(int *)(pCVar1 + 0x2ac) == 0) &&
       ((*(int *)(this + 0x108) == 0 ||
        (iVar2 = (**(code **)(**(int **)(this + 0x108) + 0x108))(), iVar2 == 0)))) &&
      ((*(int *)(this + 0xfc) == 0 ||
       (iVar2 = (**(code **)(**(int **)(this + 0xfc) + 0x108))(), iVar2 == 0)))) &&
     ((*(int *)(this + 0x114) == 0 ||
      (iVar2 = (**(code **)(**(int **)(this + 0x114) + 0x108))(), iVar2 == 0)))) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 500),1);
    return;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 500),0);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdatePodium
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRaceInterface::UpdatePodium
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  uint uVar1;
  ulong uVar2;
  float fVar3;
  float fVar4;
  ulong *puVar5;
  CMwTimerAdapter *unaff_ESI;
  CMwTimerAdapter *in_stack_ffffffc0;
  float local_38;
  float local_34;
  float local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [40];
  
  puVar5 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  if (*(int *)(this + 0x2b0) != 0) {
    uVar1 = *(uint *)(this + 0x2f0);
    if (0xfffffffc < uVar1) {
      if (uVar1 != 0xffffffff) {
        *(uint *)(this + 0x2f0) = uVar1 + 1;
        return;
      }
      puVar5 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),in_stack_ffffffc0);
      uVar2 = *puVar5;
      *(ulong *)(this + 0x2f0) = uVar2;
      *(ulong *)(this + 0x300) = uVar2 + 5000;
      return;
    }
    fVar4 = (float)(int)(*puVar5 - uVar1);
    if ((int)(*puVar5 - uVar1) < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    fVar3 = (float)(int)(*(int *)(this + 0x300) - uVar1);
    if ((int)(*(int *)(this + 0x300) - uVar1) < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    fVar4 = fVar4 / fVar3;
    fVar3 = 0.0;
    if ((fVar4 < 0.0 == (fVar4 == 0.0)) &&
       (fVar3 = fVar4, !NAN(fVar4) && 1.0 < fVar4 != (fVar4 == 1.0))) {
      fVar3 = 1.0;
    }
    fVar4 = (float)_DAT_00b3d2c0 * fVar3 * fVar3 - (fVar3 + fVar3) * fVar3 * fVar3;
    local_38 = *(float *)(this + 0x2f4) +
               fVar4 * (*(float *)(this + 0x304) - *(float *)(this + 0x2f4));
    local_34 = (*(float *)(this + 0x308) - *(float *)(this + 0x2f8)) * fVar4 +
               *(float *)(this + 0x2f8);
    local_30 = *(float *)(this + 0x2fc) +
               fVar4 * (*(float *)(this + 0x30c) - *(float *)(this + 0x2fc));
    GmIso4::SetLookAt(local_2c,(GmIso4 *)&local_38,(GmVec3 *)(this + 0x310),(GmVec3 *)0x0,
                      (ulong)in_stack_ffffffc0);
    (**(code **)(**(int **)(this + 0x2b0) + 0x88))(local_28,0);
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateRaceCountdown
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateRaceCountdown
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  ulong uVar1;
  CGamePlayerInfo *pCVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  SCasterCat *pSVar4;
  uint unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CGameRace *unaff_retaddr;
  
  if ((*(int *)(this + 0x1a0) != 0) &&
     (uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(*(int *)(this + 0x1a0) + 0x144),unaff_EDI), 3 < uVar1)) {
    pCVar2 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_retaddr);
    if ((*(int *)(pCVar2 + 0x70) != 0) || (*(int *)(pCVar2 + 0x74) != 0)) {
      CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1a0),0);
      return;
    }
    CControlTools::ControlSetVisible
              (*(CControlBase **)(this + 0x1a0),(uint)(*(uint *)(*(int *)(this + 0xa0) + 0x500) < 4)
              );
    pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       ((void *)(*(int *)(this + 0x1a0) + 0x144),unaff_ESI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(*(int *)(this + 0x1a0) + 0x144),pCVar5,unaff_EBX);
        unaff_EBX = (uint)(*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                            (*(int *)(this + 0xa0) + 0x500) == pCVar5);
        CControlTools::ControlSetVisible(*(CControlBase **)pSVar4,unaff_EBX);
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar3);
    }
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateRaceMessage
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRaceInterface::UpdateRaceMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CSceneVehicleCar *this_00;
  uint uVar1;
  bool bVar2;
  CGamePlayer *pCVar3;
  int iVar4;
  SStringParamInt *pSVar5;
  CGamePlayerInfo *pCVar6;
  int extraout_EAX;
  int extraout_EAX_00;
  CMwId *pCVar7;
  CGamePlayerInfo *this_01;
  CPlugAudio *this_02;
  SStringParam *unaff_EDI;
  int iVar8;
  undefined2 in_FPUControlWord;
  float fVar9;
  undefined4 in_stack_00000008;
  undefined4 in_stack_0000001c;
  CGameRace *in_stack_ffffffa0;
  CFastStringInt *in_stack_ffffffa4;
  SStringParam *pSVar10;
  CFastStringInt *pCVar11;
  wchar_t *in_stack_ffffffc0;
  wchar_t *in_stack_ffffffc4;
  SStringParamInt *in_stack_ffffffc8;
  SNationConfig *pSVar12;
  undefined8 uStack_30;
  int iStack_28;
  int iStack_24;
  undefined *puStack_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00a8ce48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar8 = 0;
  if (*(int *)(this + 0x140) == 0) {
    ExceptionList = local_8;
    return;
  }
  pCVar3 = CGameRace::GetLocalPlayer
                     (*(CGameRace **)(this + 0xa0),
                      (CGameRace *)(DAT_00cca150 ^ (uint)&stack0xffffffb0));
  if (pCVar3 == (CGamePlayer *)0x0) {
    ExceptionList = local_8;
    return;
  }
  this_00 = *(CSceneVehicleCar **)(*(int *)(pCVar3 + 0x28) + 0x14);
  if (this_00 == (CSceneVehicleCar *)0x0) {
    ExceptionList = local_8;
    return;
  }
  iVar4 = (**(code **)(*(int *)this_00 + 0x10))(0xa02b000);
  if (iVar4 == 0) {
    ExceptionList = local_8;
    return;
  }
  if ((_DAT_00d566dc & 1) == 0) {
    _DAT_00d566dc = _DAT_00d566dc | 1;
    DAT_00d566d4 = 0;
    DAT_00d566d8 = PTR_DAT_00bbf7dc;
    _atexit(`private:_void___thiscall_CTrackManiaRaceInterface::UpdateRaceMessage(void)'::__l9::
            _dynamic_atexit_destructor_for__Msg__);
  }
  pCVar11 = (CFastStringInt *)((int)&uStack_30 + 4);
  uStack_30 = CONCAT44(DAT_00d71d5c,(undefined4)uStack_30);
  iStack_28 = DAT_00d71d58;
  iStack_24 = 0;
  pSVar10 = (SStringParam *)0x4c5072;
  CFastStringInt::SetString(&DAT_00d566d4,pCVar11,unaff_EDI);
  if (*(int *)(this_00 + 0x600) == 2) {
    fVar9 = CSceneVehicleCar::GetRouletteCurrentBoostFactor
                      (this_00,(CSceneVehicleCar *)in_stack_ffffffa0);
    iStack_24 = 0;
    puStack_20 = PTR_DAT_00bbf7dc;
    in_stack_00000008 = 0;
    pSVar12 = (SNationConfig *)CONCAT22((short)((uint)fVar9 >> 0x10),in_FPUControlWord);
    pCVar11 = (CFastStringInt *)&iStack_24;
    uStack_30 = (longlong)ROUND(fVar9 * (float)_DAT_00b40f30);
    unaff_EDI = (SStringParam *)&DAT_00b45b90;
    pSVar10 = (SStringParam *)0x4c50da;
    CFastStringInt::ConcatFormat(PTR_DAT_00bbf7dc,pCVar11,"%d%%");
    uStack_10 = uStack_18;
    local_c = pvStack_1c;
    local_8 = (undefined1 *)0x0;
    pSVar5 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Turbo %1 !",
                        in_stack_ffffffc0);
    SStringParamInt::SStringParamInt(&stack0x00000000,pSVar5,in_stack_ffffffc4);
    CFastStringInt::SetCompose
              (&DAT_00d566d4,(CFastStringInt *)&param_1,(SStringParam *)&local_8,in_stack_ffffffc8);
    in_stack_0000001c = 0xffffffff;
    CGameCtnApp::SNationConfig::~SNationConfig(&uStack_10,pSVar12);
  }
  if (*(int *)(this_00 + 0x60c) == 0) {
    pCVar6 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),in_stack_ffffffa0);
    if ((pCVar6 != (CGamePlayerInfo *)0x0) &&
       (this_01 = pCVar6 + 0x30c, *(int *)(pCVar6 + 0x30c) != 0)) {
      iStack_28 = *(int *)this_01;
      uStack_30 = CONCAT44(*(undefined4 *)(pCVar6 + 0x310),(undefined4)uStack_30);
      iStack_24 = 0;
      CFastStringInt::SetString
                (&DAT_00d566d4,(CFastStringInt *)((int)&uStack_30 + 4),
                 (SStringParam *)in_stack_ffffffa4);
      iStack_24 = DAT_00d71d58;
      iStack_28 = DAT_00d71d5c;
      puStack_20 = (undefined *)0x0;
      in_stack_ffffffa4 = (CFastStringInt *)&iStack_28;
      goto LAB_004c51b5;
    }
  }
  else {
    pSVar5 = (SStringParamInt *)
             CClassicI18n::GetTranslatedStringInternal
                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Free wheeling !",
                        (wchar_t *)in_stack_ffffffa0);
    SStringParamInt::SStringParamInt(&puStack_20,pSVar5,(wchar_t *)in_stack_ffffffa4);
    in_stack_ffffffa4 = (CFastStringInt *)&pvStack_1c;
    this_01 = (CGamePlayerInfo *)&DAT_00d566d4;
LAB_004c51b5:
    CFastStringInt::SetString(this_01,in_stack_ffffffa4,pSVar10);
  }
  uStack_30._4_4_ = DAT_00d71d5c;
  iStack_28 = DAT_00d71d58;
  iStack_24 = 0;
  if ((DAT_00d71d58 != DAT_00d566d4) ||
     (CFastStringInt::Compare
                (&DAT_00d566d4,(SParam_Fids *)((int)&uStack_30 + 4),(SParam *)0x0,
                 (int *)in_stack_ffffffa4,(int *)pSVar10), extraout_EAX != 0)) {
    uStack_30._0_4_ = 0;
    if ((DAT_00d566d4 != *(int *)(*(int *)(this + 0x140) + 0x130)) ||
       (CFastStringInt::Compare
                  ((int *)(*(int *)(this + 0x140) + 0x130),(SParam_Fids *)&stack0xffffffc8,
                   (SParam *)0x0,(int *)in_stack_ffffffa4,(int *)pSVar10), extraout_EAX_00 != 0)) {
      bVar2 = true;
      goto LAB_004c522e;
    }
  }
  bVar2 = false;
LAB_004c522e:
  this_02 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_02 == (CPlugAudio *)0x0) {
    this_02 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar7 = CPlugAudio::MwGetId(this_02,(CPlugAudio *)pCVar11);
  uVar1 = *(uint *)pCVar7;
  if (bVar2) {
    uStack_30._0_4_ = 0;
    CFastStringInt::SetString
              ((void *)(*(int *)(this + 0x140) + 0x130),(CFastStringInt *)&stack0xffffffc8,unaff_EDI
              );
    (**(code **)(**(int **)(this + 0x140) + 0x1a8))();
    *(uint *)(this + 0x144) = uVar1;
  }
  if ((*(uint *)(this + 0x144) < uVar1) && (uVar1 - *(uint *)(this + 0x144) < 3000)) {
    iVar8 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x140),iVar8);
  ExceptionList = local_8;
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateRefereesWorkingMessage
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateRefereesWorkingMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  if ((*(int *)(*(int *)(this + 0xa0) + 0x288) != 0) &&
     (*(int *)(*(int *)(this + 0xa8) + 0x65c) != 0)) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1f8),1);
    return;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1f8),0);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateScores
// =================================================
/* WARNING: Removing unreachable block (ram,0x004c0282) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CTrackManiaRaceInterface::UpdateScores
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  uint uVar1;
  CTrackManiaRaceNet *this_00;
  uint uVar2;
  float fVar3;
  ulong *puVar4;
  CPlugAudio *this_01;
  CMwId *pCVar5;
  int iVar6;
  CTrackMania *pCVar7;
  SInputEvent *pSVar8;
  CGamePlayerInfo *pCVar9;
  CTrackManiaNetworkServerInfo *pCVar10;
  int iVar11;
  uint uVar12;
  SInputActionDesc *unaff_EBP;
  uint uVar13;
  CPlugAudio *unaff_ESI;
  CMwTimerAdapter *unaff_EDI;
  CTrackManiaRaceNet *pCVar14;
  CInputPort *pCVar15;
  int iStack_10;
  undefined4 local_8;
  
  puVar4 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_EDI);
  uVar1 = *puVar4;
  this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
  if (this_01 == (CPlugAudio *)0x0) {
    this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
  }
  pCVar5 = CPlugAudio::MwGetId(this_01,unaff_ESI);
  local_8 = *(undefined4 *)pCVar5;
  uVar12 = 0;
  pCVar15 = (CInputPort *)0x24044000;
  uVar13 = 0;
  iVar6 = (**(code **)(**(int **)(this + 0xa0) + 0x10))();
  if (iVar6 != 0) {
    this_00 = *(CTrackManiaRaceNet **)(this + 0xa0);
    pCVar14 = (CTrackManiaRaceNet *)0x4c012d;
    iVar6 = (**(code **)(*(int *)this + 0x98))();
    uVar2 = *(uint *)(iVar6 + 0x80);
    uVar12 = uVar2 >> 7 & 1;
    if ((uVar2 & 0x40) == 0) {
      if (*(int *)(this_00 + 0x288) == 0) {
        if (*(int *)(*(int *)(this_00 + 0x20) + 0x20) == *(int *)(*(int *)(this + 0xa0) + 200)) {
          pCVar7 = GetGame(this,(CTrackManiaEnvironmentManager *)PTR_DAT_00cd3fa4);
          pCVar14 = (CTrackManiaRaceNet *)0x4c01d9;
          pSVar8 = CInputPort::GetActionState(*(CInputPort **)(pCVar7 + 0x6c),pCVar15,unaff_EBP);
          uVar13 = *(uint *)(pSVar8 + 4);
        }
        if (*(int *)(*(int *)(this + 0xa8) + 0x840) != 0) {
          uVar13 = 1;
        }
        if (*(int *)(*(int *)(this + 0xa8) + 0x844) != 0) {
          uVar13 = 1;
        }
        iVar11 = CTrackManiaRaceNet::EndRunScoresVisible(this_00,pCVar14);
        if (iVar11 != 0) {
          uVar13 = 1;
        }
      }
      else {
        uVar13 = (uint)(*(int *)(*(int *)(this + 0xa8) + 0x83c) == 1);
        if ((*(int *)(this + 0x2b0) != 0) && (uVar1 < *(uint *)(this + 0x300))) {
          uVar13 = 0;
        }
      }
    }
    else if (*(int *)(*(int *)(this_00 + 0x20) + 0x20) == *(int *)(*(int *)(this + 0xa0) + 200)) {
      pCVar7 = GetGame(this,(CTrackManiaEnvironmentManager *)PTR_DAT_00cd3fa4);
      pSVar8 = CInputPort::GetActionState(*(CInputPort **)(pCVar7 + 0x6c),pCVar15,unaff_EBP);
      uVar13 = *(uint *)(pSVar8 + 4);
    }
    if ((*(int *)(*(int *)(this + 0xa0) + 0x288) != 0) &&
       (*(int *)(*(int *)(this + 0xa8) + 0x83c) == 1)) {
      uVar1 = *(uint *)(*(int *)(this + 0xa8) + 0x838);
      if (*(uint *)(this + 0x110) < uVar1) {
        iVar11 = uVar1 + *(uint *)(this + 0x110);
        fVar3 = (float)iVar11;
        if (iVar11 < 0) {
          fVar3 = fVar3 + _DAT_00c418d0;
        }
        local_8 = (undefined4)(longlong)ROUND(fVar3 * (float)_DAT_00b313b8);
      }
    }
    if (*(CTrackManiaControlScores2 **)(this + 0x108) != (CTrackManiaControlScores2 *)0x0) {
      CTrackManiaControlScores2::SetDisplayScoreElseLadderScore
                (*(CTrackManiaControlScores2 **)(this + 0x108),(CTrackManiaControlScores2 *)0x1,
                 (int)pCVar15);
      if ((uVar13 == 0) || (iStack_10 != 0)) {
        *(undefined4 *)(this + 0x110) = 0;
      }
      else {
        iVar11 = (**(code **)(**(int **)(this + 0x108) + 0x108))();
        if ((iVar11 == 0) || (*(int *)(this + 0x110) == 0)) {
          *(undefined4 *)(this + 0x110) = local_8;
        }
        iVar11 = (**(code **)(**(int **)(this + 0x108) + 0x108))();
        if (iVar11 == 0) {
LAB_004c02f5:
          pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this_00,(CGameRace *)unaff_EBP);
          pCVar15 = *(CInputPort **)(*(int *)(this + 0xa0) + 0x288);
          unaff_EBP = (SInputActionDesc *)0x0;
          pCVar10 = CTrackManiaNetwork::GetServerInfo
                              (*(CTrackManiaNetwork **)(this + 0xa8),(CTrackManiaNetwork *)pCVar9);
          CTrackManiaControlScores2::Update
                    (*(CTrackManiaControlScores2 **)(this + 0x108),
                     (SGmSmoothReal2 *)(this_00 + 0x590),(int)(this_00 + 0x5a8),(ulong)pCVar10);
        }
        else {
          pCVar15 = (CInputPort *)0x4c02f1;
          iVar11 = CTrackManiaControlScores2::IsDirty
                             (*(CTrackManiaControlScores2 **)(this + 0x108),
                              (CTrackManiaControlScores2 *)unaff_EBP);
          if (iVar11 != 0) goto LAB_004c02f5;
        }
        (**(code **)(**(int **)(this + 0x108) + 0x180))();
      }
    }
    if (*(int *)(this + 0x10c) != 0) {
      iVar11 = (**(code **)(*(int *)this_00 + 0x10))(0x24037000);
      if (((iVar11 != 0) && ((*(byte *)(iVar6 + 0x80) & 0x20) != 0)) &&
         (*(int *)(this + 0x2b0) == 0)) {
        iVar6 = CTrackManiaControlScores2::FinishShouldBeVisible
                          (*(CTrackManiaControlScores2 **)(this + 0x10c),
                           (CTrackManiaControlScores2 *)(this_00 + 0x59c),
                           (CFastBuffer<class_CTrackManiaRaceScore*> *)pCVar15);
        if ((iVar6 != 0) && (iStack_10 == 0)) {
          iVar6 = (**(code **)(**(int **)(this + 0x10c) + 0x108))();
          if ((iVar6 == 0) ||
             (iVar6 = CTrackManiaControlScores2::IsDirty
                                (*(CTrackManiaControlScores2 **)(this + 0x10c),
                                 (CTrackManiaControlScores2 *)unaff_EBP), iVar6 != 0)) {
            pCVar9 = CGameRace::GetLocalPlayerInfo((CGameRace *)this_00,(CGameRace *)unaff_EBP);
            pCVar10 = CTrackManiaNetwork::GetServerInfo
                                (*(CTrackManiaNetwork **)(this + 0xa8),(CTrackManiaNetwork *)pCVar9)
            ;
            CTrackManiaControlScores2::Update
                      (*(CTrackManiaControlScores2 **)(this + 0x10c),
                       (SGmSmoothReal2 *)(this_00 + 0x59c),0,(ulong)pCVar10);
          }
          goto LAB_004c03f8;
        }
      }
      iStack_10 = 0;
    }
LAB_004c03f8:
    if ((uVar13 != 0) && (uVar12 == 0)) {
      iVar6 = 1;
      goto LAB_004c041e;
    }
  }
  iVar6 = 0;
LAB_004c041e:
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x108),iVar6);
  if ((iStack_10 == 0) || (uVar12 != 0)) {
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x10c),iVar6);
  if ((uVar13 == 0) || (uVar12 != 0)) {
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1ac),iVar6);
  if ((uVar13 == 0) && (uVar12 == 0)) {
    iVar6 = 1;
  }
  else {
    iVar6 = 0;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1b0),iVar6);
  if (((uVar13 == 0) || (*(int *)(*(int *)(this + 0xa0) + 0x288) != 0)) || (uVar12 != 0)) {
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0xdc),iVar6);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateSpectatorCounter
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateSpectatorCounter
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  CGameRace *unaff_ESI;
  
  pCVar1 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_ESI);
  if (((*(int *)(pCVar1 + 0x7c) != 0) && (*(int *)(pCVar1 + 0x70) == 0)) &&
     (*(int *)(pCVar1 + 0x74) == 0)) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1ec),1);
    return;
  }
  CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1ec),0);
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateStuntMessage
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateStuntMessage
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  ulong *puVar1;
  CMwTimerAdapter *unaff_ESI;
  
  puVar1 = CMwTimer::GetTickTime((void *)(DAT_00d731e0 + 0x70),unaff_ESI);
  if (*(uint *)(this + 0x154) <= *puVar1) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x148),0);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x14c),0);
    *(undefined4 *)(this + 0x158) = 0;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaRaceInterface::UpdateTimeColor
// =================================================
void __thiscall
CTrackManiaRaceInterface::UpdateTimeColor
          (CTrackManiaRaceInterface *this,CTrackManiaRaceInterface *param_1)
{
{
  CGamePlayerInfo *pCVar1;
  CTrackMania *this_00;
  int iVar2;
  CTrackManiaNetworkServerInfo *pCVar3;
  CTrackManiaEnvironmentManager *unaff_ESI;
  CGameRace *unaff_EDI;
  int iVar4;
  CTrackMania *unaff_retaddr;
  CTrackManiaNetwork *in_stack_00000008;
  CCrystalVertex *in_stack_0000000c;
  
  pCVar1 = CGameRace::GetLocalPlayerInfo(*(CGameRace **)(this + 0xa0),unaff_EDI);
  iVar4 = *(int *)(this + 0x168);
  if ((*(int *)(pCVar1 + 0x70) == 0) && (*(int *)(pCVar1 + 0x74) == 0)) {
    this_00 = GetGame(this,unaff_ESI);
    iVar2 = CTrackMania::IsInStuntsMode(this_00,unaff_retaddr);
    if ((iVar2 != 0) && (*(uint *)(*(int *)(this + 0xa0) + 0x250) < 0x1389)) {
      iVar4 = *(int *)(this + 0x16c);
    }
    iVar2 = CGameNetwork::IsConnected(*(CGameNetwork **)(this + 0xa8),(CCrystalVertex *)param_1);
    if (iVar2 != 0) {
      pCVar3 = CTrackManiaNetwork::GetServerInfo
                         (*(CTrackManiaNetwork **)(this + 0xa8),in_stack_00000008);
      if (*(int *)(pCVar3 + 0x198) != 0) {
        iVar4 = *(int *)(this + 0x16c);
      }
    }
    iVar2 = CGameNetwork::IsConnected(*(CGameNetwork **)(this + 0xa8),in_stack_0000000c);
    if ((iVar2 != 0) && (*(int *)(*(int *)(this + 0xa8) + 0x7c8) == 0)) {
      iVar4 = *(int *)(this + 0x170);
    }
  }
  if (iVar4 != 0) {
    CControlBase::CStyleSheetElem<class_CControlStyle>::Set
              (*(CMwCmdScriptVarBool **)(this + 0x15c) + 0x110,
               *(CMwCmdScriptVarBool **)(this + 0x15c),iVar4);
  }
  return;
}
}

