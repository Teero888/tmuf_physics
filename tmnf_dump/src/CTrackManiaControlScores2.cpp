// Class implementation: CTrackManiaControlScores2

// =================================================
// Function: CTrackManiaControlScores2::Clean
// =================================================
void __thiscall
CTrackManiaControlScores2::Clean(CTrackManiaControlScores2 *this,CHmsOcclusion *param_1)
{
{
  if (*(int *)(this + 0x1e4) != 0) {
    (**(code **)(*(int *)this + 0x1fc))(*(int *)(this + 0x1e4),0);
  }
  *(undefined4 *)(this + 0x1e4) = 0;
  *(undefined4 *)(this + 0x218) = 0;
  *(undefined4 *)(this + 0x21c) = 1;
  CControlBase::Clean((CControlBase *)this,param_1);
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores2::FinishShouldBeVisible
// =================================================
int __thiscall
CTrackManiaControlScores2::FinishShouldBeVisible
          (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1,
          CFastBuffer<class_CTrackManiaRaceScore*> *param_2)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](param_1,pCVar4,unaff_ESI);
      iVar1 = *(int *)pSVar3;
      if ((((iVar1 != 0) && (*(int *)(iVar1 + 0x54) != 0)) && (*(int *)(iVar1 + 0x28) != -1)) &&
         (*(int *)(iVar1 + 0x28) != 0)) {
        return 1;
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  return 0;
}
}

// =================================================
// Function: CTrackManiaControlScores2::IsDirty
// =================================================
int __thiscall
CTrackManiaControlScores2::IsDirty
          (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1)
{
{
  if ((*(int *)(this + 0x220) == *(int *)(this + 0x218)) && (*(int *)(this + 0x224) == 0)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CTrackManiaControlScores2::SetDisplayScoreElseLadderScore
// =================================================
void __thiscall
CTrackManiaControlScores2::SetDisplayScoreElseLadderScore
          (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1,int param_2)
{
{
  if (param_1 != *(CTrackManiaControlScores2 **)(this + 0x1c0)) {
    *(CTrackManiaControlScores2 **)(this + 0x1c0) = param_1;
    *(undefined4 *)(this + 0x224) = 1;
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores2::SetListTitle
// =================================================
void __thiscall
CTrackManiaControlScores2::SetListTitle
          (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1,ulong param_2,
          CFastStringInt *param_3)
{
{
  CTrackManiaControlScores2 *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CControlButton *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastStringInt *unaff_retaddr;
  
  this_00 = this + 0x1a4;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (param_2 < uVar1) {
    pSVar2 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        (ulong)param_3);
    CControlLabel::SetLabel(*(CControlLabel **)(pSVar2 + 0x10),unaff_ESI,unaff_retaddr);
    pSVar2 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                       (this_00,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        (ulong)param_1);
    (**(code **)(**(int **)(pSVar2 + 0x10) + 0x1a8))();
  }
  return;
}
}

// =================================================
// Function: CTrackManiaControlScores2::Update
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CTrackManiaControlScores2::Update
          (CTrackManiaControlScores2 *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3)
{
{
  SCasterCat SVar1;
  short sVar2;
  wchar_t wVar3;
  CTrackManiaRaceScore *this_00;
  CFastBuffer<class_CCrystalFace*> *pCVar4;
  ulong uVar5;
  SCasterCat *pSVar6;
  SLoadedLight *pSVar7;
  ulong uVar8;
  CFastBuffer<class_GxVertex2> *pCVar9;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar10;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar11;
  SCasterCat *pSVar12;
  SCasterCat *pSVar13;
  int iVar14;
  CFastString *pCVar15;
  CFastString *pCVar16;
  CMwId *pCVar17;
  CTrackManiaControlScores2 *pCVar18;
  undefined *puVar19;
  undefined *puVar20;
  wchar_t *pwVar21;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  CTrackManiaControlScores2 *unaff_EBP;
  code *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar22;
  ulong unaff_EDI;
  uint uVar23;
  bool bVar24;
  float10 in_ST0;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  float10 extraout_ST0_05;
  float10 extraout_ST0_06;
  float10 extraout_ST0_07;
  float10 extraout_ST0_08;
  uint in_stack_00000010;
  int in_stack_00000014;
  int in_stack_00000018;
  undefined1 *in_stack_0000001c;
  undefined *in_stack_00000020;
  undefined1 in_stack_00000028;
  undefined1 in_stack_0000002c;
  undefined1 in_stack_00000030;
  undefined1 uStack00000034;
  undefined3 uStack00000035;
  undefined1 in_stack_00000038;
  undefined1 in_stack_00000048;
  undefined1 in_stack_0000004c;
  undefined1 in_stack_00000060;
  undefined1 in_stack_00000064;
  undefined1 in_stack_00000068;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffed4;
  CFastBuffer<class_CPlugFileSndGen*> *in_stack_fffffed8;
  code *in_stack_fffffedc;
  ulong uVar25;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffee4;
  ulong in_stack_fffffee8;
  uchar *in_stack_fffffeec;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffef0;
  char *pcVar26;
  uchar *in_stack_fffffef8;
  CFastStringInt *pCVar27;
  uchar *in_stack_fffffefc;
  CFastStringInt *pCVar28;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar29;
  CFastStringInt *pCVar30;
  CControlBase *pCVar31;
  CFastStringInt *pCVar32;
  CTrackManiaControlScores2 *pCVar33;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_ffffff0c;
  CControlBase *in_stack_ffffff10;
  uint *puVar34;
  SStringParam *pSVar35;
  CFastStringInt *in_stack_ffffff1c;
  CFastString *pCVar36;
  undefined *in_stack_ffffff2c;
  SCasterCat *in_stack_ffffff30;
  SCasterCat *pSVar37;
  CFastStringInt *in_stack_ffffff34;
  CTrackManiaControlScores2 *pCStack_c8;
  undefined *local_c4;
  undefined *puStack_c0;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_bc;
  SCasterCat *local_b8;
  CTrackManiaControlScores2 *local_b4;
  undefined *local_b0;
  ulong *puStack_ac;
  undefined *puStack_a8;
  wchar_t *local_a4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_a0;
  CTrackManiaControlScores2 *local_9c;
  SCasterCat *local_98;
  undefined *local_94;
  ulong *local_90;
  undefined4 local_8c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_88;
  CFastString *local_84;
  undefined *local_80;
  undefined4 local_7c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_78;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_74;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_70;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_6c;
  int local_68;
  CFastString *local_64;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_60;
  CFastString *local_5c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_58;
  undefined4 local_54;
  undefined *local_50;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4c;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_48;
  undefined *local_44;
  undefined *local_40;
  undefined *local_3c;
  CFastString *local_38;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined4 local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined1 *local_10;
  SCasterCat *local_c;
  SCasterCat *pSStack_8;
  
  local_c = (SCasterCat *)0xffffffff;
  local_10 = &LAB_00a84800;
  local_14 = ExceptionList;
  pCVar4 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xfffffec8);
  ExceptionList = &local_14;
  *(undefined4 *)(this + 0x224) = 0;
  if ((*(int *)(this + 0x1e4) != 0) &&
     (pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)this,
     uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1a4,pCVar4), in_ST0 = extraout_ST0,
     uVar5 != 0)) {
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 0x1fc),in_stack_00000018);
    if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x194) !=
        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      local_88 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x198);
      local_84 = *(CFastString **)(this + 0x19c);
      local_80 = *(undefined **)(this + 0x1a0);
      if (in_stack_00000018 != 0) {
        local_84 = (CFastString *)((float)local_84 - (float)_DAT_00b337c0);
      }
      pSVar6 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](this + 0x158,
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x194),
                            unaff_EDI);
      *(CFastString **)(pSVar6 + 0x24) = local_84;
      *(undefined **)(pSVar6 + 0x28) = local_80;
      *(undefined4 *)(pSVar6 + 0x2c) = local_7c;
    }
    uVar5 = param_3;
    uVar25 = 0;
    local_8c = 0xffffffff;
    if (*(int *)(this + 0x214) == 0) {
      switch(*(undefined4 *)(param_3 + 0x200)) {
      case 1:
      case 7:
        uVar25 = 0;
        break;
      case 9:
        local_8c = *(undefined4 *)(param_3 + 0x234);
      case 3:
      case 6:
      case 8:
        uVar25 = 1;
      }
    }
    else if (*(int *)(this + 0x214) == 1) {
      uVar25 = 0;
    }
    if ((_DAT_00d55a8c & 1) == 0) {
      _DAT_00d55a8c = _DAT_00d55a8c | 1;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d55a80,(CFastBuffer<class_CPlugFileSndGen*> *)unaff_ESI);
      unaff_ESI = `public:_void___thiscall_CTrackManiaControlScores2::
                  Update(class_CFastBuffer<class_CTrackManiaRaceScore*>_const&,class_CTrackManiaControlScores2_const*,class_CTrackManiaNetworkServerInfo_const*,class_CTrackManiaPlayerInfo*,int,int)'
                  ::__l18::_dynamic_atexit_destructor_for__ScoresToSort__;
      _atexit(`public:_void___thiscall_CTrackManiaControlScores2::
              Update(class_CFastBuffer<class_CTrackManiaRaceScore*>_const&,class_CTrackManiaControlScores2_const*,class_CTrackManiaNetworkServerInfo_const*,class_CTrackManiaPlayerInfo*,int,int)'
              ::__l18::_dynamic_atexit_destructor_for__ScoresToSort__);
    }
    CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset
              (&DAT_00d55a80,(GmFrustumIso4 *)unaff_ESI);
    local_bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
               CFastBuffer<class_CCrystalFace*>::GetCount(param_1,unaff_EBX);
    pCVar29 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (local_bc != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pCVar10 = pCVar29;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (param_1,pCVar29,(ulong)in_stack_fffffed4);
        this_00 = *(CTrackManiaRaceScore **)pSVar6;
        if ((this_00 != (CTrackManiaRaceScore *)0x0) && (*(int *)(this_00 + 0x54) != 0)) {
          if (*(int *)(this + 0x214) == 0) {
            if (*(int *)(param_3 + 0x200) == 6) {
              in_stack_fffffed4 = (CFastBuffer<class_CCrystalFace*> *)0x4469f0;
              iVar14 = CTrackManiaRaceScore::IsPureSpectator
                                 (this_00,(CTrackManiaPlayerInfo *)0x4469f0);
              if (iVar14 != 0) goto LAB_00446a42;
            }
            pSVar7 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                               (&DAT_00d55a80,
                                (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)pCVar29);
            *(CTrackManiaRaceScore **)(pSVar7 + 4) = this_00;
            switch(*(undefined4 *)(param_3 + 0x200)) {
            case 1:
              *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x18);
              break;
            default:
              *(undefined4 *)pSVar7 = 0xffffffff;
              break;
            case 3:
            case 9:
              *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x14);
              break;
            case 6:
              *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x14);
              break;
            case 7:
              *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x18);
              break;
            case 8:
              *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x1c);
            }
          }
          else if (((*(int *)(this + 0x214) == 1) && (*(int *)(this_00 + 0x28) != -1)) &&
                  (*(int *)(this_00 + 0x28) != 0)) {
            in_stack_fffffed4 = (CFastBuffer<class_CCrystalFace*> *)0x4469d3;
            pSVar7 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem
                               (&DAT_00d55a80,
                                (CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)0x4469d3);
            *(CTrackManiaRaceScore **)(pSVar7 + 4) = this_00;
            *(undefined4 *)pSVar7 = *(undefined4 *)(this_00 + 0x28);
          }
        }
LAB_00446a42:
        pCVar29 = pCVar10 + 1;
        uVar5 = param_3;
      } while (pCVar29 < local_bc);
    }
    uVar8 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55a80,in_stack_fffffed4);
    CControlTools::ControlSetVisible(*(CControlBase **)(this + 500),(uint)(uVar8 != 0));
    pCStack_c8 = (CTrackManiaControlScores2 *)
                 (-(uint)(*(int *)(uVar5 + 0x200) != 6) & in_stack_00000010);
    pCVar32 = (CFastStringInt *)0x0;
    local_3c = (undefined *)0x0;
    local_38 = (CFastString *)PTR_DAT_00bbf7d8;
    pCVar36 = (CFastString *)0x0;
    puStack_c0 = (undefined *)0x0;
    local_bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7d8;
    local_88 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_84 = (CFastString *)PTR_DAT_00bbf7d8;
    puStack_ac = (ulong *)0x0;
    puStack_a8 = PTR_DAT_00bbf7dc;
    local_9c = (CTrackManiaControlScores2 *)0x0;
    local_98 = (SCasterCat *)PTR_DAT_00bbf7d8;
    local_54 = 0;
    local_50 = PTR_DAT_00bbf7dc;
    local_78 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    local_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7d8;
    param_2 = 7;
    puVar20 = PTR_DAT_00bbf7d8;
    if ((_DAT_00d55a8c & 2) == 0) {
      _DAT_00d55a8c = _DAT_00d55a8c | 2;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d55a74,in_stack_fffffed8);
      _atexit(`public:_void___thiscall_CTrackManiaControlScores2::
              Update(class_CFastBuffer<class_CTrackManiaRaceScore*>_const&,class_CTrackManiaControlScores2_const*,class_CTrackManiaNetworkServerInfo_const*,class_CTrackManiaPlayerInfo*,int,int)'
              ::__l35::_dynamic_atexit_destructor_for__ListElemCounts__);
    }
    if ((_DAT_00d55a8c & 4) == 0) {
      _DAT_00d55a8c = _DAT_00d55a8c | 4;
      CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
                (&DAT_00d55a68,(CFastBuffer<class_CPlugFileSndGen*> *)in_stack_fffffedc);
      in_stack_fffffedc =
           `public:_void___thiscall_CTrackManiaControlScores2::
           Update(class_CFastBuffer<class_CTrackManiaRaceScore*>_const&,class_CTrackManiaControlScores2_const*,class_CTrackManiaNetworkServerInfo_const*,class_CTrackManiaPlayerInfo*,int,int)'
           ::__l35::_dynamic_atexit_destructor_for__ListCurCells__;
      _atexit(`public:_void___thiscall_CTrackManiaControlScores2::
              Update(class_CFastBuffer<class_CTrackManiaRaceScore*>_const&,class_CTrackManiaControlScores2_const*,class_CTrackManiaNetworkServerInfo_const*,class_CTrackManiaPlayerInfo*,int,int)'
              ::__l35::_dynamic_atexit_destructor_for__ListCurCells__);
    }
    pCVar9 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this + 0x1a4,(CFastBuffer<class_CCrystalFace*> *)in_stack_fffffedc);
    CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount(&DAT_00d55a74,pCVar9,uVar25);
    pCVar9 = (CFastBuffer<class_GxVertex2> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1a4,in_stack_fffffee4);
    CFastBuffer<class_GmVector2<unsigned_short>_>::AllocSetCount
              (&DAT_00d55a68,pCVar9,in_stack_fffffee8);
    local_a4 = (wchar_t *)(*(int *)(this + 0x1c8) * *(int *)(this + 0x1c4));
    pCVar33 = (CTrackManiaControlScores2 *)0x0;
    CFastBuffer<int>::FillWith
              (&DAT_00d55a74,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0xffffff08,
               in_stack_fffffeec);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55a80,in_stack_fffffef0);
    pCVar22 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar10 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar6 = CFastBuffer<struct_SFastCat>::operator[](&DAT_00d55a80,pCVar22,(ulong)pCVar11);
        if ((*(int *)(this + 0x214) == 0) && (*(int *)(param_3 + 0x200) == 6)) {
          pCVar11 = *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                     (*(int *)(*(int *)(pSVar6 + 4) + 0x54) + 0x240);
        }
        else {
          pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        }
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d55a74,pCVar11,(ulong)in_stack_fffffef8);
        *(int *)pSVar6 = *(int *)pSVar6 + 1;
        pCVar22 = pCVar22 + 1;
      } while (pCVar22 < pCVar10);
    }
    uVar23 = 0;
    pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
              CFastBuffer<class_CCrystalFace*>::GetCount
                        (pCVar36 + 0x1a4,(CFastBuffer<class_CCrystalFace*> *)pCVar11);
    pCVar10 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar11 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d55a74,pCVar10,(ulong)in_stack_fffffef8);
        if (uVar23 < *(uint *)pSVar6) {
          uVar23 = *(uint *)pSVar6;
        }
        pCVar10 = pCVar10 + 1;
      } while (pCVar10 < pCVar11);
    }
    if (local_98 == (SCasterCat *)0x0) {
      uVar23 = 0;
    }
    else {
      uVar23 = (uint)(local_98 + (uVar23 - 1)) / (uint)local_98;
    }
    *(uint *)(puVar20 + 0x21c) = uVar23;
    if (uVar23 == 0) {
      *(undefined4 *)(puVar20 + 0x21c) = 1;
    }
    pSVar6 = (SCasterCat *)0x0;
    puVar34 = (uint *)0x0;
    CFastBuffer<int>::FillWith
              (&DAT_00d55a74,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0xffffff14,
               in_stack_fffffef8);
    pSVar35 = (SStringParam *)0x0;
    CFastBuffer<int>::FillWith
              (&DAT_00d55a68,(CFixedArray<unsigned_char,8,unsigned_long> *)&stack0xffffff18,
               in_stack_fffffefc);
    if (*(uint *)(in_stack_ffffff30 + 0x21c) <= *(uint *)(in_stack_ffffff30 + 0x218)) {
      *(uint *)(in_stack_ffffff30 + 0x218) = *(uint *)(in_stack_ffffff30 + 0x21c) - 1;
    }
    *(undefined4 *)(in_stack_ffffff30 + 0x220) = *(undefined4 *)(in_stack_ffffff30 + 0x218);
    pSVar37 = in_stack_ffffff30;
    local_b8 = (SCasterCat *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (&DAT_00d55a80,(CFastBuffer<class_CCrystalFace*> *)pCVar29);
    pSVar12 = (SCasterCat *)0x0;
    if (local_b8 != (SCasterCat *)0x0) {
      do {
        pCVar28 = (CFastStringInt *)0x446cdb;
        pSVar12 = CFastBuffer<struct_SFastCat>::operator[]
                            (&DAT_00d55a80,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pSVar6,
                             (ulong)pCVar32);
        pSVar37 = *(SCasterCat **)(*(int *)(pSVar12 + 4) + 0x54);
        bVar24 = pSVar37 == local_98;
        if ((*(int *)(in_stack_ffffff30 + 0x214) == 0) && (*(int *)(param_3 + 0x200) == 6)) {
          pCVar32 = *(CFastStringInt **)(pSVar37 + 0x240);
        }
        else {
          pCVar32 = (CFastStringInt *)0x0;
        }
        pCVar30 = (CFastStringInt *)0x446d25;
        local_4c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar32;
        pSVar13 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                            (&DAT_00d55a74,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar32
                             ,(ulong)pCVar33);
        pCVar11 = local_48;
        if (*(uint *)pSVar13 < (uint)(*(int *)(in_stack_ffffff30 + 0x220) * (int)local_84)) {
          *(uint *)pSVar13 = *(uint *)pSVar13 + 1;
        }
        else {
          local_98 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                               (&DAT_00d55a68,local_48,(ulong)in_stack_ffffff0c);
          pCVar32 = (CFastStringInt *)0x446d65;
          pSVar6 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (in_stack_ffffff30 + 0x1a4,pCVar11,*(ulong *)local_98);
          pSVar13 = CFastBuffer<struct_CTrackManiaControlScores2::SCell>::operator[]
                              (pSVar6,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                                      in_stack_ffffff10,(ulong)puVar34);
          in_stack_ffffff10 = *(CControlBase **)pSVar13;
          puVar34 = (uint *)0x1;
          in_stack_ffffff0c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x446d78;
          CControlTools::ControlSetVisible(in_stack_ffffff10,1);
          if ((*(int *)(in_stack_ffffff30 + 0x214) == 1) && (*(int *)(pSVar13 + 0xc) != 0)) {
            if (*(int *)(param_3 + 0x200) == 6) {
              pSVar6 = in_stack_ffffff30 + 0x1d0;
              if (*(int *)(puStack_c0 + 0x240) != 0) {
                pSVar6 = in_stack_ffffff30 + 0x1d4;
              }
            }
            else {
              pSVar6 = in_stack_ffffff30 + 0x1d8;
            }
            if (*(int *)(*(int *)(pSVar13 + 0xc) + 0x140) != *(int *)pSVar6) {
              *(int *)(*(int *)(pSVar13 + 0xc) + 0x140) = *(int *)pSVar6;
              puVar34 = (uint *)0x446ddb;
              (**(code **)(**(int **)(pSVar13 + 0xc) + 0x1a8))();
            }
          }
          pCVar33 = (CTrackManiaControlScores2 *)pCVar11;
          pSVar6 = pSVar12;
          pCVar16 = pCVar36;
          if (*(int *)(pSVar13 + 4) != 0) {
            (**(code **)(**(int **)(pSVar13 + 4) + 0x1a0))();
            (**(code **)(**(int **)(pSVar13 + 4) + 0x1a0))();
            if (*(int *)(in_stack_ffffff30 + 400) == 0) {
              CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 4),0);
              CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 4),0);
              pCVar33 = (CTrackManiaControlScores2 *)pCVar11;
              pSVar6 = pSVar12;
              pCVar16 = pCVar36;
            }
            else {
              CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 4),1);
              CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 4),1);
              CControlBase::BindEvent
                        (*(CControlBase **)(pSVar13 + 4),(CControlBase *)0x0,
                         (EEvent)in_stack_ffffff30,(CMwNod *)OnPlayerSelect,
                         (_func___cdecl_void_ulong *)(uint)(byte)pCVar36[0x24],(ulong)pCVar28);
              pCVar28 = (CFastStringInt *)(uint)(byte)puVar20[0x24];
              CControlBase::BindEvent
                        (*(CControlBase **)(pSVar13 + 4),(CControlBase *)&DAT_00000004,
                         (EEvent)in_stack_ffffff30,(CMwNod *)OnPlayerSelect2,
                         (_func___cdecl_void_ulong *)pCVar28,(ulong)pCVar30);
              pCVar33 = (CTrackManiaControlScores2 *)pCVar11;
              pSVar6 = pSVar12;
              pCVar16 = pCVar36;
            }
          }
          if (*(int *)(in_stack_ffffff30 + 0x170) != 0) {
            CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x2c),(uint)bVar24);
          }
          if (*(int *)(in_stack_ffffff30 + 0x174) != 0) {
            pCVar28 = (CFastStringInt *)
                      CTrackManiaRaceScore::IsPureSpectator
                                ((CTrackManiaRaceScore *)puVar34[1],(CTrackManiaPlayerInfo *)pCVar28
                                );
            CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x30),(int)pCVar28);
          }
          if (*(int *)(in_stack_ffffff30 + 0x168) != 0) {
            CFastString::SetNatural
                      ((CFastString *)&local_18,(CFastString *)(pSVar35 + 1),1,0,0,0,1,(int)pCVar28)
            ;
            in_stack_0000001c = local_10;
            in_stack_00000020 = local_14;
            local_1c = (undefined *)0x0;
            local_18 = PTR_DAT_00bbf7dc;
            in_stack_00000030 = 8;
            CFastStringInt::SetString
                      (&local_1c,(CFastStringInt *)&stack0x0000001c,(SStringParam *)pCVar30);
            pCVar28 = *(CFastStringInt **)(pSVar13 + 0x34);
            pCVar30 = (CFastStringInt *)&local_18;
            uStack00000034 = 9;
            CControlTools::ControlSetLabel((CControlBase *)pCVar28,pCVar30);
            _uStack00000034 = (void *)CONCAT31(uStack00000035,7);
            if (local_14 != PTR_DAT_00bbf7dc) {
              if ((local_14[-1] & 0x80) == 0) {
                pCVar30 = (CFastStringInt *)(local_14 + -2);
              }
              else {
                pCVar30 = (CFastStringInt *)(local_14 + -4);
              }
              pCVar28 = (CFastStringInt *)0x446f63;
              operator_delete__(pCVar30);
              local_18 = (undefined *)0x0;
              local_14 = PTR_DAT_00bbf7dc;
            }
            if (*(int *)(pSVar13 + 0x34) != 0) {
              pCVar30 = (CFastStringInt *)0x7006000;
              pCVar28 = (CFastStringInt *)0x446f8e;
              iVar14 = (**(code **)(**(int **)(pSVar13 + 0x34) + 0x10))();
              if (iVar14 != 0) {
                *(uint *)(*(int *)(pSVar13 + 0x34) + 0x124) =
                     -(uint)(*(int *)(puVar34[1] + 0x50) != 0) & 2;
              }
            }
          }
          pCVar27 = (CFastStringInt *)(pCVar16 + 0x14);
          pCVar36 = pCVar16;
          CControlTools::ControlSetLabel(*(CControlBase **)(pSVar13 + 0x3c),pCVar27);
          if (*(int *)(in_stack_ffffff30 + 0x16c) != 0) {
            pCVar27 = (CFastStringInt *)(uint)(*(int *)(pCVar16 + 0x30) != 0);
            CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x38),(int)pCVar27);
            if (*(int *)(pSVar13 + 0x38) != 0) {
              pCVar27 = (CFastStringInt *)0x0;
              CGameControlPlayerAvatar::Display
                        (pSVar13 + 0x10,(CGameControlPlayerAvatar *)pCVar16,(CGamePlayerInfo *)0x0,
                         (EAvatarVariant)pCVar28);
            }
          }
          if ((*(int *)(pCVar16 + 0x1dc) == 0) && (*(int *)(puVar34[1] + 0x4c) == 0)) {
            bVar24 = false;
          }
          else {
            bVar24 = true;
          }
          if ((*(int *)(in_stack_ffffff30 + 0x188) == 0) || (pSVar37 = (SCasterCat *)0x1, !bVar24))
          {
            pSVar37 = (SCasterCat *)0x0;
          }
          if (*(int *)(in_stack_ffffff30 + 0x178) != 0) {
            pCVar16 = (CFastString *)*puVar34;
            pCVar15 = pCVar16;
            if ((((in_stack_ffffff10 == (CControlBase *)0x1) &&
                 (pCVar16 != (CFastString *)0xffffffff)) && (local_5c != (CFastString *)0xffffffff))
               && (local_5c < pCVar16)) {
              pCVar15 = local_5c;
            }
            if (in_stack_ffffff10 == (CControlBase *)0x0) {
              pCVar27 = (CFastStringInt *)&local_b8;
              CMwTimer::GetMmSsCcTimeStringFromMwTime((ulong)pCVar16,(CFastString *)pCVar27);
            }
            else if (in_stack_ffffff10 == (CControlBase *)0x1) {
              pCVar27 = (CFastStringInt *)0x1;
              CFastString::SetNatural((CFastString *)&local_b8,pCVar15,1,0,0,0,1,(int)pCVar28);
            }
            local_c = local_b8;
            pSStack_8 = (SCasterCat *)local_bc;
            local_4c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
            local_48 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc;
            in_stack_00000028 = 10;
            CFastStringInt::SetString(&local_4c,(CFastStringInt *)&local_c,(SStringParam *)pCVar27);
            in_stack_0000002c = 0xb;
            CControlTools::ControlSetLabel
                      (*(CControlBase **)(pSVar13 + 0x40),(CFastStringInt *)&local_48);
            in_stack_0000002c = 7;
            if (local_44 != PTR_DAT_00bbf7dc) {
              if ((local_44[-1] & 0x80) == 0) {
                puVar19 = local_44 + -2;
              }
              else {
                puVar19 = local_44 + -4;
              }
              operator_delete__(puVar19);
              local_48 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
              local_44 = PTR_DAT_00bbf7dc;
            }
            if ((*(int *)(in_stack_ffffff30 + 0x1c0) == 0) && (pSVar37 != (SCasterCat *)0x0)) {
              iVar14 = 0;
            }
            else {
              iVar14 = 1;
            }
            CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x40),iVar14);
          }
          if (*(int *)(in_stack_ffffff30 + 0x17c) != 0) {
            pCVar27 = *(CFastStringInt **)(puVar34[1] + 0x24);
            if (pCVar27 == (CFastStringInt *)0x0) {
              pCVar27 = (CFastStringInt *)&stack0x00000010;
              in_stack_00000010 = DAT_00d71ca0;
              in_stack_00000014 = DAT_00d71c9c;
              CFastString::SetString((CFastString *)&local_9c,pCVar27,(SStringParam *)pCVar28);
            }
            else {
              if (*(int *)(param_3 + 0x200) == 6) {
                pCVar16 = pCVar36;
                if (*(int *)(pCVar36 + 0x240) == 0) {
                  pcVar26 = "$00f+%d";
                }
                else {
                  pcVar26 = "$f00+%d";
                }
              }
              else {
                pcVar26 = "$080+%d";
                pCVar16 = (CFastString *)&local_9c;
              }
              CFastString::Format(pCVar16,(CFastString *)&local_9c,pcVar26);
            }
            unaff_EBP = local_9c;
            local_2c = (undefined *)0x0;
            local_28 = PTR_DAT_00bbf7dc;
            in_stack_00000028 = 0xc;
            CFastStringInt::SetString
                      (&local_2c,(CFastStringInt *)&stack0xfffffffc,(SStringParam *)pCVar27);
            in_stack_0000002c = 0xd;
            CControlTools::ControlSetLabel
                      (*(CControlBase **)(pSVar13 + 0x44),(CFastStringInt *)&local_28);
            in_stack_0000002c = 7;
            if (local_24 != PTR_DAT_00bbf7dc) {
              if ((local_24[-1] & 0x80) == 0) {
                puVar19 = local_24 + -2;
              }
              else {
                puVar19 = local_24 + -4;
              }
              operator_delete__(puVar19);
              local_28 = (undefined *)0x0;
              local_24 = PTR_DAT_00bbf7dc;
            }
          }
          if (*(int *)(in_stack_ffffff30 + 0x180) != 0) {
            CMwTimer::GetMmSsCcTimeStringFromMwTime(*puVar34,(CFastString *)&local_b8);
            param_2 = (int)local_b4;
            param_3 = (ulong)local_b8;
            local_40 = (undefined *)0x0;
            local_3c = PTR_DAT_00bbf7dc;
            in_stack_0000002c = 0xe;
            CFastStringInt::SetString(&local_40,(CFastStringInt *)&param_2,(SStringParam *)pCVar28);
            in_stack_00000030 = 0xf;
            CControlTools::ControlSetLabel
                      (*(CControlBase **)(pSVar13 + 0x4c),(CFastStringInt *)&local_3c);
            in_stack_00000030 = 7;
            if (local_38 != (CFastString *)PTR_DAT_00bbf7dc) {
              if (((byte)local_38[-1] & 0x80) == 0) {
                pCVar16 = local_38 + -2;
              }
              else {
                pCVar16 = local_38 + -4;
              }
              operator_delete__(pCVar16);
              local_3c = (undefined *)0x0;
              local_38 = (CFastString *)PTR_DAT_00bbf7dc;
            }
            CFastString::SetNatural
                      ((CFastString *)&local_60,*(CFastString **)(*(int *)(pSVar35 + 4) + 0x20),1,0,
                       0,0,1,(int)pCVar30);
            local_88 = local_58;
            local_84 = local_5c;
            local_30 = 0;
            local_2c = PTR_DAT_00bbf7dc;
            _uStack00000034 = (void *)CONCAT31(uStack00000035,0x10);
            CFastStringInt::SetString(&local_30,(CFastStringInt *)&local_88,(SStringParam *)pCVar32)
            ;
            in_stack_00000038 = 0x11;
            CControlTools::ControlSetLabel
                      (*(CControlBase **)(pSVar13 + 0x50),(CFastStringInt *)&local_2c);
            in_stack_00000038 = 7;
            if (local_28 != PTR_DAT_00bbf7dc) {
              if ((local_28[-1] & 0x80) == 0) {
                puVar19 = local_28 + -2;
              }
              else {
                puVar19 = local_28 + -4;
              }
              operator_delete__(puVar19);
              local_2c = (undefined *)0x0;
              local_28 = PTR_DAT_00bbf7dc;
            }
            if ((*(int *)(in_stack_ffffff30 + 0x1c0) == 0) && (local_c4 != (undefined *)0x0)) {
              pCVar32 = (CFastStringInt *)0x0;
            }
            else {
              pCVar32 = (CFastStringInt *)0x1;
            }
            pCVar30 = *(CFastStringInt **)(pSVar13 + 0x48);
            pCVar28 = (CFastStringInt *)0x447451;
            CControlTools::ControlSetVisible((CControlBase *)pCVar30,(int)pCVar32);
          }
          if (*(int *)(in_stack_ffffff30 + 0x184) != 0) {
            if ((*(int *)(pSVar13 + 0x58) != 0) &&
               (iVar14 = (**(code **)(**(int **)(pSVar13 + 0x58) + 0x10))(), iVar14 != 0)) {
              *(uint *)(*(int *)(pSVar13 + 0x58) + 0x124) = (-(uint)bVar24 & 0xfffffffe) + 2;
            }
            CGameMasterServer::GetLadderRankAsStringInt
                      (*(ulong *)(pCVar36 + 0x1b0),0xffffffff,(CFastStringInt *)&local_30);
            CControlTools::ControlSetLabel
                      (*(CControlBase **)(pSVar13 + 0x58),(CFastStringInt *)&local_30);
          }
          pCVar17 = *(CMwId **)(in_stack_ffffff30 + 0x184);
          CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x54),(int)pCVar17);
          if (*(int *)(in_stack_ffffff30 + 0x188) != 0) {
            if (pSVar37 == (SCasterCat *)0x0) {
LAB_00447649:
              pCVar17 = (CMwId *)0x0;
            }
            else {
              pSVar37 = *(SCasterCat **)(puVar34[1] + 0x2c);
              iVar14 = 0;
              if (((float)pSVar37 != (float)_DAT_00b337a0) &&
                 ((float)pSVar37 != (float)_DAT_00b33798)) {
                CFastString::SetRealWithoutExponent
                          ((CFastString *)&local_78,(CFastString *)ABS((float)pSVar37),2.8026e-45,
                           (ulong)pCVar28);
                local_c = (SCasterCat *)0xb33788;
                if (NAN((float)in_stack_ffffff34) ||
                    0.0 < (float)in_stack_ffffff34 == ((float)in_stack_ffffff34 == 0.0)) {
                  local_c = (SCasterCat *)&DAT_00b3377c;
                }
                if (local_c == (SCasterCat *)0x0) {
                  pSStack_8 = (SCasterCat *)0x0;
                }
                else {
                  pSStack_8 = local_c;
                  do {
                    SVar1 = *pSStack_8;
                    pSStack_8 = pSStack_8 + 1;
                  } while (SVar1 != (SCasterCat)0x0);
                  pSStack_8 = pSStack_8 + -(int)(local_c + 1);
                }
                CFastString::ConcatBefore
                          ((CFastString *)&local_74,(CFastStringInt *)&local_c,
                           (SStringParamInt *)pCVar30);
                local_78 = local_6c;
                local_74 = local_70;
                pCVar36 = (CFastString *)0x0;
                _uStack00000034 = (void *)CONCAT31(uStack00000035,0x12);
                puVar20 = PTR_DAT_00bbf7dc;
                CFastStringInt::SetString
                          (&stack0xffffff24,(CFastStringInt *)&local_78,(SStringParam *)pCVar32);
                pCVar30 = *(CFastStringInt **)(pSVar13 + 0x60);
                pCVar32 = (CFastStringInt *)&stack0xffffff28;
                in_stack_00000038 = 0x13;
                pCVar28 = (CFastStringInt *)0x4475e8;
                CControlTools::ControlSetLabel((CControlBase *)pCVar30,pCVar32);
                in_stack_00000038 = 7;
                if (in_stack_ffffff2c != PTR_DAT_00bbf7dc) {
                  if ((in_stack_ffffff2c[-1] & 0x80) == 0) {
                    pCVar32 = (CFastStringInt *)(in_stack_ffffff2c + -2);
                  }
                  else {
                    pCVar32 = (CFastStringInt *)(in_stack_ffffff2c + -4);
                  }
                  pCVar30 = (CFastStringInt *)0x447613;
                  operator_delete__(pCVar32);
                  puVar20 = (undefined *)0x0;
                  in_stack_ffffff2c = PTR_DAT_00bbf7dc;
                }
                iVar14 = 1;
              }
              CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x60),iVar14);
              if (*(int *)(in_stack_ffffff30 + 0x1c0) != 0) goto LAB_00447649;
              pCVar17 = (CMwId *)0x1;
            }
            CControlTools::ControlSetVisible(*(CControlBase **)(pSVar13 + 0x5c),(int)pCVar17);
          }
          if (*(int *)(in_stack_ffffff30 + 0x18c) != 0) {
            iVar14 = 0;
            if (((*(int *)(param_3 + 0x200) == 9) && (in_stack_00000014 == 0)) &&
               (in_stack_ffffff10 == (CControlBase *)0x1)) {
              if (local_5c < (CFastString *)*puVar34) {
                if (puVar20 == (undefined *)0x0) {
                  local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                             CClassicI18n::GetTranslatedStringInternal
                                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Winner!",
                                        (wchar_t *)pCVar28);
                  if (local_6c == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
                    local_68 = 0;
                  }
                  else {
                    pCVar11 = local_6c;
                    do {
                      sVar2 = *(short *)pCVar11;
                      pCVar11 = pCVar11 + 2;
                    } while (sVar2 != 0);
                    local_68 = (int)pCVar11 - (int)(local_6c + 2) >> 1;
                  }
                  pCVar28 = (CFastStringInt *)&local_6c;
                  local_64 = (CFastString *)0x1;
                  pCVar17 = (CMwId *)0x447732;
                  CFastStringInt::SetString(&local_84,pCVar28,(SStringParam *)pCVar30);
                  pSVar37 = pSVar37 + 1;
                  iVar14 = 2;
                }
                else {
                  pCVar17 = (CMwId *)0x0;
                  CControlTools::CreateRankText((ulong)(puVar20 + 1),(CFastStringInt *)&local_88,0);
                  puVar20 = puVar20 + 1;
                  iVar14 = 2;
                }
              }
              else if ((CFastString *)*puVar34 == local_5c) {
                pCStack_c8 = (CTrackManiaControlScores2 *)
                             CClassicI18n::GetTranslatedStringInternal
                                       ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"Finalist!",
                                        (wchar_t *)pCVar28);
                if (pCStack_c8 == (CTrackManiaControlScores2 *)0x0) {
                  local_c4 = (undefined *)0x0;
                }
                else {
                  pCVar18 = pCStack_c8;
                  do {
                    wVar3 = *(wchar_t *)pCVar18;
                    pCVar18 = pCVar18 + 2;
                  } while (wVar3 != L'\0');
                  local_c4 = (undefined *)((int)pCVar18 - (int)(pCStack_c8 + 2) >> 1);
                }
                pCVar28 = (CFastStringInt *)&pCStack_c8;
                iVar14 = 1;
                puStack_c0 = (undefined *)0x1;
                pCVar17 = (CMwId *)0x447797;
                CFastStringInt::SetString(&local_84,pCVar28,(SStringParam *)pCVar30);
              }
            }
            CMwId::CMwId(&local_b4,pCVar17);
            in_stack_0000002c = 0x14;
            if (iVar14 == 1) {
              local_b0 = *(undefined **)(in_stack_ffffff30 + 0x1e0);
LAB_004477d6:
              if ((*(int *)(pSVar13 + 0x40) != 0) &&
                 (iVar14 = (**(code **)(**(int **)(pSVar13 + 0x40) + 0x108))(), iVar14 != 0)) {
                CControlTools::ControlSetLabel
                          (*(CControlBase **)(pSVar13 + 0x40),(CFastStringInt *)&local_88);
              }
            }
            else {
              if (iVar14 == 2) {
                local_b0 = *(undefined **)(in_stack_ffffff30 + 0x1dc);
                goto LAB_004477d6;
              }
              if ((iVar14 == 2) || (iVar14 == 1)) goto LAB_004477d6;
            }
            iVar14 = *(int *)(pSVar13 + 100);
            if ((iVar14 != 0) && (*(undefined **)(iVar14 + 0x140) != local_b0)) {
              *(undefined **)(iVar14 + 0x140) = local_b0;
              (**(code **)(**(int **)(pSVar13 + 100) + 0x1a8))();
            }
            CControlTools::ControlSetVisible
                      (*(CControlBase **)(pSVar13 + 100),(uint)(local_b0 != (undefined *)0xffffffff)
                      );
            in_stack_0000002c = 7;
            OnAccessViolation_ConcatToCrashFileName(pCVar28);
          }
          *puStack_ac = *puStack_ac + 1;
          uVar5 = *puStack_ac;
          pSVar12 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                              (in_stack_ffffff30 + 0x1a4,local_58,(ulong)pCVar28);
          uVar25 = CFastBuffer<class_CCrystalFace*>::GetCount
                             (pSVar12,(CFastBuffer<class_CCrystalFace*> *)pCVar30);
          pSVar12 = pSVar6;
          if (uVar5 == uVar25) break;
        }
        pSVar6 = pSVar6 + 1;
        pSVar12 = pSVar6;
      } while (pSVar6 < local_b8);
    }
    local_b4 = (CTrackManiaControlScores2 *)
               CFastBuffer<class_CCrystalFace*>::GetCount
                         (in_stack_ffffff30 + 0x1a4,(CFastBuffer<class_CCrystalFace*> *)pCVar32);
    if (local_b4 != (CTrackManiaControlScores2 *)0x0) {
      pCVar11 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        pCVar31 = (CControlBase *)0x4478b0;
        pCVar29 = pCVar11;
        pSVar6 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                           (pCStack_c8 + 0x1a4,pCVar11,(ulong)pCVar33);
        uVar5 = CFastBuffer<class_CCrystalFace*>::GetCount
                          (pSVar6,(CFastBuffer<class_CCrystalFace*> *)in_stack_ffffff0c);
        pCVar33 = (CTrackManiaControlScores2 *)0x4478c4;
        in_stack_ffffff0c = pCVar11;
        pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (&DAT_00d55a68,pCVar11,(ulong)in_stack_ffffff10);
        for (uVar23 = *(uint *)pSVar6; uVar23 < uVar5; uVar23 = uVar23 + 1) {
          pSVar6 = CFastBuffer<struct_CVisionViewportDx9::SProjectorReceivers>::operator[]
                             (pSVar37 + 0x1a4,pCVar11,uVar23);
          pSVar6 = CFastBuffer<struct_CTrackManiaControlScores2::SCell>::operator[]
                             (pSVar6,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar31,
                              (ulong)pCVar29);
          pCVar31 = *(CControlBase **)pSVar6;
          pCVar29 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
          CControlTools::ControlSetVisible(pCVar31,0);
        }
        pCVar11 = pCVar11 + 1;
      } while (pCVar11 < local_b4);
    }
    iVar14 = param_2;
    if ((*(int *)(param_3 + 0x200) == 6) && (param_2 != 0)) {
      local_98 = (SCasterCat *)0x0;
      local_94 = PTR_DAT_00bbf7d8;
      local_a0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_9c = (CTrackManiaControlScores2 *)PTR_DAT_00bbf7dc;
      local_b4 = (CTrackManiaControlScores2 *)0x0;
      local_b0 = PTR_DAT_00bbf7dc;
      in_stack_00000038 = 0x17;
      local_bc = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"|TeamColorName|Blue",
                            (wchar_t *)pCVar33);
      if (local_bc == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
        local_b8 = (SCasterCat *)0x0;
      }
      else {
        pSVar6 = (SCasterCat *)local_bc;
        do {
          sVar2 = *(short *)pSVar6;
          pSVar6 = pSVar6 + 2;
        } while (sVar2 != 0);
        local_b8 = (SCasterCat *)((int)pSVar6 - (int)(local_bc + 2) >> 1);
      }
      local_b4 = (CTrackManiaControlScores2 *)0x1;
      CFastStringInt::SetString
                (&local_b0,(CFastStringInt *)&local_bc,(SStringParam *)in_stack_ffffff0c);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)iVar14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          (ulong)in_stack_ffffff10);
      pCVar33 = (CTrackManiaControlScores2 *)0x0;
      CFastString::SetNatural
                ((CFastString *)&local_8c,*(CFastString **)(*(int *)pSVar6 + 0x14),1,0,0,0,1,
                 (int)puVar34);
      local_64 = local_84;
      local_60 = local_88;
      pCStack_c8 = (CTrackManiaControlScores2 *)0x0;
      local_c4 = PTR_DAT_00bbf7dc;
      in_stack_00000048 = 0x18;
      CFastStringInt::SetString(&pCStack_c8,(CFastStringInt *)&local_64,pSVar35);
      puStack_ac = (ulong *)puStack_c0;
      puStack_a8 = local_c4;
      local_50 = local_9c;
      local_4c = local_a0;
      local_a4 = (wchar_t *)0x0;
      local_48 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      in_stack_0000004c = 0x19;
      local_70 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xb33720;
      local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_0000000d;
      CFastStringInt::SetCompose
                (&local_8c,(CFastStringInt *)&local_70,(SStringParam *)&local_50,
                 (SStringParamInt *)&puStack_ac);
      in_stack_0000004c = 0x17;
      if (puStack_c0 != PTR_DAT_00bbf7dc) {
        if ((puStack_c0[-1] & 0x80) == 0) {
          puVar19 = puStack_c0 + -2;
        }
        else {
          puVar19 = puStack_c0 + -4;
        }
        operator_delete__(puVar19);
      }
      SetListTitle(local_b4,(CTrackManiaControlScores2 *)0x0,(ulong)&local_8c,in_stack_ffffff1c);
      local_a4 = CClassicI18n::GetTranslatedStringInternal
                           ((CClassicI18n *)&DAT_00d71d10,(CClassicI18n *)L"|TeamColorName|Red",
                            (wchar_t *)pSVar12);
      if (local_a4 == (wchar_t *)0x0) {
        local_a0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      }
      else {
        pwVar21 = local_a4;
        do {
          wVar3 = *pwVar21;
          pwVar21 = pwVar21 + 1;
        } while (wVar3 != L'\0');
        local_a0 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                   ((int)pwVar21 - (int)(local_a4 + 1) >> 1);
      }
      local_9c = (CTrackManiaControlScores2 *)0x1;
      CFastStringInt::SetString(&local_98,(CFastStringInt *)&local_a4,(SStringParam *)pCVar36);
      pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)iVar14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1,
                          (ulong)puVar20);
      CFastString::SetNatural
                ((CFastString *)&local_74,*(CFastString **)(*(int *)pSVar6 + 0x14),1,0,0,0,1,
                 (int)in_stack_ffffff2c);
      local_4c = local_6c;
      local_48 = local_70;
      local_b0 = (undefined *)0x0;
      puStack_ac = (ulong *)PTR_DAT_00bbf7dc;
      in_stack_00000060 = 0x1a;
      CFastStringInt::SetString(&local_b0,(CFastStringInt *)&local_4c,(SStringParam *)pSVar37);
      local_94 = puStack_a8;
      local_90 = puStack_ac;
      local_38 = local_84;
      local_34 = local_88;
      in_stack_00000064 = 0x1b;
      local_8c = 0;
      local_30 = 0;
      local_58 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xb336e8;
      local_54 = 0xd;
      CFastStringInt::SetCompose
                (&local_74,(CFastStringInt *)&local_58,(SStringParam *)&local_38,
                 (SStringParamInt *)&local_94);
      in_stack_00000064 = 0x17;
      if (puStack_a8 != PTR_DAT_00bbf7dc) {
        if ((puStack_a8[-1] & 0x80) == 0) {
          puVar20 = puStack_a8 + -2;
        }
        else {
          puVar20 = puStack_a8 + -4;
        }
        operator_delete__(puVar20);
      }
      SetListTitle(local_9c,(CTrackManiaControlScores2 *)0x1,(ulong)&local_74,in_stack_ffffff34);
      if (local_80 != PTR_DAT_00bbf7dc) {
        if ((local_80[-1] & 0x80) == 0) {
          puVar20 = local_80 + -2;
        }
        else {
          puVar20 = local_80 + -4;
        }
        operator_delete__(puVar20);
        local_84 = (CFastString *)0x0;
        local_80 = PTR_DAT_00bbf7dc;
      }
      if (local_6c != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc) {
        if (((byte)local_6c[-1] & 0x80) == 0) {
          pCVar11 = local_6c + -2;
        }
        else {
          pCVar11 = local_6c + -4;
        }
        operator_delete__(pCVar11);
        local_70 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
        local_6c = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc;
      }
      in_stack_00000068 = 7;
      if (local_64 != (CFastString *)PTR_DAT_00bbf7d8) {
        pCVar36 = local_64 + -1;
        if (((byte)local_64[-1] & 0x80) != 0) {
          pCVar36 = local_64 + -4;
        }
        operator_delete__(pCVar36);
      }
    }
    UpdatePageButtons(pCStack_c8,pCVar33);
    in_ST0 = extraout_ST0_00;
    if (local_40 != PTR_DAT_00bbf7d8) {
      puVar20 = local_40 + -1;
      if ((local_40[-1] & 0x80) != 0) {
        puVar20 = local_40 + -4;
      }
      operator_delete__(puVar20);
      in_ST0 = extraout_ST0_01;
    }
    if (local_1c != PTR_DAT_00bbf7dc) {
      puVar20 = local_1c + -4;
      if ((local_1c[-1] & 0x80) == 0) {
        puVar20 = local_1c + -2;
      }
      operator_delete__(puVar20);
      local_20 = 0;
      local_1c = PTR_DAT_00bbf7dc;
      in_ST0 = extraout_ST0_02;
    }
    if (local_64 != (CFastString *)PTR_DAT_00bbf7d8) {
      pCVar36 = local_64 + -1;
      if (((byte)local_64[-1] & 0x80) != 0) {
        pCVar36 = local_64 + -4;
      }
      operator_delete__(pCVar36);
      local_68 = 0;
      local_64 = (CFastString *)PTR_DAT_00bbf7d8;
      in_ST0 = extraout_ST0_03;
    }
    if (local_74 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc) {
      pCVar11 = local_74 + -4;
      if (((byte)local_74[-1] & 0x80) == 0) {
        pCVar11 = local_74 + -2;
      }
      operator_delete__(pCVar11);
      local_78 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      local_74 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7dc;
      in_ST0 = extraout_ST0_04;
    }
    if (local_50 != PTR_DAT_00bbf7d8) {
      puVar20 = local_50 + -1;
      if ((local_50[-1] & 0x80) != 0) {
        puVar20 = local_50 + -4;
      }
      operator_delete__(puVar20);
      local_54 = 0;
      local_50 = PTR_DAT_00bbf7d8;
      in_ST0 = extraout_ST0_05;
    }
    if (local_88 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7d8) {
      pCVar11 = local_88 + -1;
      if (((byte)local_88[-1] & 0x80) != 0) {
        pCVar11 = local_88 + -4;
      }
      operator_delete__(pCVar11);
      local_8c = 0;
      local_88 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)PTR_DAT_00bbf7d8;
      in_ST0 = extraout_ST0_06;
    }
    if (local_a4 != (wchar_t *)PTR_DAT_00bbf7d8) {
      pwVar21 = (wchar_t *)((int)local_a4 + -1);
      if ((*(byte *)((int)local_a4 + -1) & 0x80) != 0) {
        pwVar21 = local_a4 + -2;
      }
      operator_delete__(pwVar21);
      puStack_a8 = (undefined *)0x0;
      local_a4 = (wchar_t *)PTR_DAT_00bbf7d8;
      in_ST0 = extraout_ST0_07;
    }
    if (unaff_EBP != (CTrackManiaControlScores2 *)PTR_DAT_00bbf7d8) {
      pCVar33 = unaff_EBP + -1;
      if (((byte)unaff_EBP[-1] & 0x80) != 0) {
        pCVar33 = unaff_EBP + -4;
      }
      operator_delete__(pCVar33);
      in_ST0 = extraout_ST0_08;
    }
  }
  ExceptionList = _uStack00000034;
  return (float)in_ST0;
}
}

// =================================================
// Function: CTrackManiaControlScores2::UpdatePageButtons
// =================================================
void __thiscall
CTrackManiaControlScores2::UpdatePageButtons
          (CTrackManiaControlScores2 *this,CTrackManiaControlScores2 *param_1)
{
{
  CControlTools::ControlSetReadOnlyAndDraw
            (*(CControlBase **)(this + 0x1e8),(uint)(*(int *)(this + 0x218) == 0),0);
  CControlTools::ControlSetReadOnlyAndDraw
            (*(CControlBase **)(this + 0x1ec),
             (uint)(*(int *)(this + 0x218) == *(int *)(this + 0x21c) + -1),0);
  CControlTools::ControlSetVisible
            (*(CControlBase **)(this + 0x1e8),(uint)(1 < *(uint *)(this + 0x21c)));
  CControlTools::ControlSetVisible
            (*(CControlBase **)(this + 0x1ec),(uint)(1 < *(uint *)(this + 0x21c)));
  return;
}
}

