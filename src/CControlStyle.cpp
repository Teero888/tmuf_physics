// Class implementation: CControlStyle

// =================================================
// Function: CControlStyle::CControlStyle
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlStyle::CControlStyle(CControlStyle *this,CControlStyle *param_1)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  CMwId *unaff_EDI;
  CControlStyle *pCVar4;
  void *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ac7530;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CPlug::CPlug((CPlug *)this,(CPlug *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x14,unaff_EDI);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  pCVar4 = this + 0x5c;
  _eh_vector_constructor_iterator_
            (pCVar4,0x1c,3,STextSettings_ColorAndChars::STextSettings_ColorAndChars,
             STextSettings_ColorAndChars::~STextSettings_ColorAndChars);
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  CMwId::CMwId(this + 0xc4,(CMwId *)pCVar4);
  *(undefined4 *)(this + 0xd0) = 0;
  uVar1 = _DAT_00b31460;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xec) = 0;
  *(undefined4 *)(this + 0x100) = 0;
  *(undefined4 *)(this + 0x104) = 0;
  *(undefined4 *)(this + 0x108) = 0;
  *(undefined4 *)(this + 0x17c) = 0;
  *(undefined4 *)(this + 0x60) = 0x3f800000;
  *(undefined4 *)(this + 100) = 0x3f800000;
  *(undefined4 *)(this + 0x68) = 0x3f800000;
  *(undefined4 *)(this + 0x98) = uVar1;
  *(undefined4 *)(this + 0x6c) = 0x3f800000;
  *(undefined4 *)(this + 0x9c) = uVar1;
  *(undefined4 *)(this + 0xa0) = uVar1;
  *(undefined4 *)(this + 0x180) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0xa4) = 0x3f800000;
  uVar2 = _DAT_00b3380c;
  *(undefined4 *)(this + 0x7c) = 0x3f800000;
  *(undefined4 *)(this + 0x3c) = uVar2;
  *(undefined4 *)(this + 0x38) = uVar2;
  *(undefined4 *)(this + 0x80) = 0x3f800000;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x88) = 0x3f800000;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  uVar3 = _DAT_00b37b60;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0x48) = uVar3;
  *(undefined4 *)(this + 0xe8) = 0;
  *(undefined4 *)(this + 0x10c) = 0;
  *(undefined4 *)(this + 0x54) = uVar2;
  uVar3 = s__fff_Server_is_unreachable__00b541bf._1_4_;
  *(undefined4 *)(this + 0xb0) = 1;
  *(undefined4 *)(this + 0x58) = uVar3;
  *(undefined4 *)(this + 0x110) = 1;
  *(undefined4 *)(this + 200) = uVar2;
  *(undefined4 *)(this + 0xcc) = uVar2;
  *(undefined4 *)(this + 0xe4) = uVar2;
  *(undefined4 *)(this + 0xe0) = uVar2;
  *(undefined4 *)(this + 0xf0) = uVar1;
  uVar1 = _DAT_00b33a54;
  *(undefined4 *)(this + 0xf4) = _DAT_00b33a54;
  *(undefined4 *)(this + 0xf8) = uVar1;
  *(undefined4 *)(this + 0xfc) = uVar1;
  *(undefined4 *)(this + 0x114) = DAT_00b3d2a0;
  *(undefined4 *)(this + 0x118) = _DAT_00b93b34;
  *(undefined4 *)(this + 0x11c) = 0x3f800000;
  *(undefined4 *)(this + 0x120) = 0x3f800000;
  *(undefined4 *)(this + 0x124) = 0x3f800000;
  *(undefined4 *)(this + 0x128) = 0x3f800000;
  *(undefined4 *)(this + 300) = 0x3f800000;
  *(undefined4 *)(this + 0x130) = 0x3f800000;
  *(undefined4 *)(this + 0x134) = 0x3f800000;
  *(undefined4 *)(this + 0x138) = 0x3f800000;
  *(undefined4 *)(this + 0x148) = 0x3f800000;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 0;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0x3f800000;
  *(undefined4 *)(this + 0x168) = 0x3f800000;
  *(undefined4 *)(this + 0x15c) = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x16c) = 0;
  *(undefined4 *)(this + 0x170) = 0x3f800000;
  *(undefined4 *)(this + 0x174) = 0x3f800000;
  *(undefined4 *)(this + 0x178) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  ExceptionList = local_14;
  return;
}
}

// =================================================
// Function: CControlStyle::Fork
// =================================================
CControlStyle * __cdecl CControlStyle::Fork(CControlStyle *param_1)
{
{
  CMwNod *pCVar1;
  CControlStyle *pCVar2;
  CControlStyle *this;
  CControlStyle *extraout_EAX;
  CMwNod *unaff_EBX;
  undefined4 *puVar3;
  CMwNod *unaff_EBP;
  int iVar4;
  CMwCmdBlockMain *unaff_ESI;
  CMwNod *unaff_EDI;
  int in_stack_00000008;
  void *in_stack_00000010;
  CControlStyle *pCStack00000014;
  CControlStyleSheet *in_stack_ffffffe8;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00ac755b;
  local_c = ExceptionList;
  pCVar2 = (CControlStyle *)(DAT_00cca150 ^ (uint)&stack0xffffffd4);
  ExceptionList = &local_c;
  this = operator_new(0x184);
  local_4 = 0;
  if (this == (CControlStyle *)0x0) {
    pCVar2 = (CControlStyle *)0x0;
  }
  else {
    CControlStyle(this,pCVar2);
    pCVar2 = extraout_EAX;
  }
  *(undefined4 *)(pCVar2 + 0x14) = *(undefined4 *)(in_stack_00000008 + 0x14);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x18);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x18)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EDI);
    }
    if (*(CMwNod **)(pCVar2 + 0x18) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x18),unaff_EDI);
    }
    *(CMwNod **)(pCVar2 + 0x18) = pCVar1;
  }
  SetFocusGainedScript
            (pCVar2,*(CControlStyle **)(in_stack_00000008 + 0x1c),(CMwCmdBlockMain *)unaff_EDI);
  SetFocusLostScript(pCVar2,*(CControlStyle **)(in_stack_00000008 + 0x20),unaff_ESI);
  *(undefined4 *)(pCVar2 + 0x24) = *(undefined4 *)(in_stack_00000008 + 0x24);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x28);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x28)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBP);
    }
    if (*(CMwNod **)(pCVar2 + 0x28) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x28),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x28) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x2c);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x2c)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(pCVar2 + 0x2c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x2c),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x2c) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x30);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x30)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(pCVar2 + 0x30) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x30),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x30) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x34);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x34)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(pCVar2 + 0x34) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x34),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x34) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0x38) = *(undefined4 *)(in_stack_00000008 + 0x38);
  *(undefined4 *)(pCVar2 + 0x3c) = *(undefined4 *)(in_stack_00000008 + 0x3c);
  *(undefined4 *)(pCVar2 + 0x40) = *(undefined4 *)(in_stack_00000008 + 0x40);
  *(undefined4 *)(pCVar2 + 0x44) = *(undefined4 *)(in_stack_00000008 + 0x44);
  *(undefined4 *)(pCVar2 + 0x48) = *(undefined4 *)(in_stack_00000008 + 0x48);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x4c);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x4c)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(pCVar2 + 0x4c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x4c),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x4c) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x50);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x50)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,unaff_EBX);
    }
    if (*(CMwNod **)(pCVar2 + 0x50) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x50),unaff_EBX);
    }
    *(CMwNod **)(pCVar2 + 0x50) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0x54) = *(undefined4 *)(in_stack_00000008 + 0x54);
  pCStack00000014 = pCVar2 + 0x5c;
  *(undefined4 *)(pCVar2 + 0x58) = *(undefined4 *)(in_stack_00000008 + 0x58);
  puVar3 = (undefined4 *)(in_stack_00000008 + 0x60);
  iVar4 = (int)pCVar2 - in_stack_00000008;
  local_c = (void *)0x3;
  do {
    *(undefined4 *)pCStack00000014 = puVar3[-1];
    *(undefined4 *)((int)puVar3 + iVar4) = *puVar3;
    *(undefined4 *)((int)puVar3 + iVar4 + 4) = puVar3[1];
    *(undefined4 *)((int)puVar3 + iVar4 + 8) = puVar3[2];
    *(undefined4 *)((int)puVar3 + iVar4 + 0xc) = puVar3[3];
    puStack_8 = (undefined1 *)puVar3[5];
    local_4 = puVar3[4];
    CFastStringInt::SetString
              (pCStack00000014 + 0x14,(CFastStringInt *)&puStack_8,(SStringParam *)unaff_EBX);
    puVar3 = puVar3 + 7;
    puStack_8 = (undefined1 *)((int)puStack_8 + -1);
  } while (puStack_8 != (undefined1 *)0x0);
  *(undefined4 *)(pCVar2 + 0xb0) = *(undefined4 *)(in_stack_00000008 + 0xb0);
  *(undefined4 *)(pCVar2 + 0xb4) = *(undefined4 *)(in_stack_00000008 + 0xb4);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xb8);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xb8)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)0x773af6);
    }
    if (*(CMwNod **)(pCVar2 + 0xb8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xb8),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xb8) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xbc);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xbc)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xbc) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xbc),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xbc) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xc0);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xc0)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xc0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xc0),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xc0) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0xc4) = *(undefined4 *)(in_stack_00000008 + 0xc4);
  *(undefined4 *)(pCVar2 + 200) = *(undefined4 *)(in_stack_00000008 + 200);
  *(undefined4 *)(pCVar2 + 0xcc) = *(undefined4 *)(in_stack_00000008 + 0xcc);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xd0);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xd0)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xd0) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xd0),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xd0) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xd4);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xd4)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xd4) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xd4),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xd4) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xd8);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xd8)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xd8) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xd8),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xd8) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0xdc) = *(undefined4 *)(in_stack_00000008 + 0xdc);
  *(undefined4 *)(pCVar2 + 0xe0) = *(undefined4 *)(in_stack_00000008 + 0xe0);
  *(undefined4 *)(pCVar2 + 0xe4) = *(undefined4 *)(in_stack_00000008 + 0xe4);
  *(undefined4 *)(pCVar2 + 0xe8) = *(undefined4 *)(in_stack_00000008 + 0xe8);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0xec);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0xec)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0xec) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0xec),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0xec) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0xf0) = *(undefined4 *)(in_stack_00000008 + 0xf0);
  *(undefined4 *)(pCVar2 + 0xf4) = *(undefined4 *)(in_stack_00000008 + 0xf4);
  *(undefined4 *)(pCVar2 + 0xf8) = *(undefined4 *)(in_stack_00000008 + 0xf8);
  *(undefined4 *)(pCVar2 + 0xfc) = *(undefined4 *)(in_stack_00000008 + 0xfc);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x100);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x100)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0x100) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x100),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0x100) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x104);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x104)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0x104) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x104),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0x104) = pCVar1;
  }
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x108);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x108)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0x108) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x108),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0x108) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0x10c) = *(undefined4 *)(in_stack_00000008 + 0x10c);
  *(undefined4 *)(pCVar2 + 0x110) = *(undefined4 *)(in_stack_00000008 + 0x110);
  *(undefined4 *)(pCVar2 + 0x114) = *(undefined4 *)(in_stack_00000008 + 0x114);
  *(undefined4 *)(pCVar2 + 0x118) = *(undefined4 *)(in_stack_00000008 + 0x118);
  *(undefined4 *)(pCVar2 + 0x11c) = *(undefined4 *)(in_stack_00000008 + 0x11c);
  *(undefined4 *)(pCVar2 + 0x120) = *(undefined4 *)(in_stack_00000008 + 0x120);
  *(undefined4 *)(pCVar2 + 0x124) = *(undefined4 *)(in_stack_00000008 + 0x124);
  *(undefined4 *)(pCVar2 + 0x128) = *(undefined4 *)(in_stack_00000008 + 0x128);
  *(undefined4 *)(pCVar2 + 300) = *(undefined4 *)(in_stack_00000008 + 300);
  *(undefined4 *)(pCVar2 + 0x130) = *(undefined4 *)(in_stack_00000008 + 0x130);
  *(undefined4 *)(pCVar2 + 0x134) = *(undefined4 *)(in_stack_00000008 + 0x134);
  *(undefined4 *)(pCVar2 + 0x138) = *(undefined4 *)(in_stack_00000008 + 0x138);
  *(undefined4 *)(pCVar2 + 0x13c) = *(undefined4 *)(in_stack_00000008 + 0x13c);
  *(undefined4 *)(pCVar2 + 0x140) = *(undefined4 *)(in_stack_00000008 + 0x140);
  *(undefined4 *)(pCVar2 + 0x144) = *(undefined4 *)(in_stack_00000008 + 0x144);
  *(undefined4 *)(pCVar2 + 0x148) = *(undefined4 *)(in_stack_00000008 + 0x148);
  *(undefined4 *)(pCVar2 + 0x14c) = *(undefined4 *)(in_stack_00000008 + 0x14c);
  *(undefined4 *)(pCVar2 + 0x150) = *(undefined4 *)(in_stack_00000008 + 0x150);
  *(undefined4 *)(pCVar2 + 0x154) = *(undefined4 *)(in_stack_00000008 + 0x154);
  *(undefined4 *)(pCVar2 + 0x158) = *(undefined4 *)(in_stack_00000008 + 0x158);
  *(undefined4 *)(pCVar2 + 0x15c) = *(undefined4 *)(in_stack_00000008 + 0x15c);
  *(undefined4 *)(pCVar2 + 0x160) = *(undefined4 *)(in_stack_00000008 + 0x160);
  *(undefined4 *)(pCVar2 + 0x164) = *(undefined4 *)(in_stack_00000008 + 0x164);
  *(undefined4 *)(pCVar2 + 0x168) = *(undefined4 *)(in_stack_00000008 + 0x168);
  *(undefined4 *)(pCVar2 + 0x16c) = *(undefined4 *)(in_stack_00000008 + 0x16c);
  *(undefined4 *)(pCVar2 + 0x170) = *(undefined4 *)(in_stack_00000008 + 0x170);
  *(undefined4 *)(pCVar2 + 0x174) = *(undefined4 *)(in_stack_00000008 + 0x174);
  *(undefined4 *)(pCVar2 + 0x178) = *(undefined4 *)(in_stack_00000008 + 0x178);
  pCVar1 = *(CMwNod **)(in_stack_00000008 + 0x17c);
  if (pCVar1 != *(CMwNod **)(pCVar2 + 0x17c)) {
    if (pCVar1 != (CMwNod *)0x0) {
      CMwNod::MwAddRef(pCVar1,(CMwNod *)in_stack_ffffffe8);
    }
    if (*(CMwNod **)(pCVar2 + 0x17c) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(pCVar2 + 0x17c),(CMwNod *)in_stack_ffffffe8);
    }
    *(CMwNod **)(pCVar2 + 0x17c) = pCVar1;
  }
  *(undefined4 *)(pCVar2 + 0x180) = *(undefined4 *)(in_stack_00000008 + 0x180);
  *(undefined4 *)(pCVar2 + 0x14) = 0xffffffff;
  InternalDetachFromStyleSheet
            (pCVar2,*(CControlStyle **)(in_stack_00000008 + 0x180),in_stack_ffffffe8);
  ExceptionList = in_stack_00000010;
  return pCVar2;
}
}

// =================================================
// Function: CControlStyle::GetMwClassId
// =================================================
ulong __thiscall CControlStyle::GetMwClassId(CControlStyle *this,CControlStyle *param_1)
{
{
  return 0x7017000;
}
}

// =================================================
// Function: CControlStyle::InternalDetachFromStyleSheet
// =================================================
void __thiscall
CControlStyle::InternalDetachFromStyleSheet
          (CControlStyle *this,CControlStyle *param_1,CControlStyleSheet *param_2)
{
{
  CMwNod *pCVar1;
  CFastStringInt *pCVar2;
  undefined *puVar3;
  CControlStyle *pCVar4;
  CControlStyle *this_00;
  SStringParam *unaff_EDI;
  void *local_38;
  undefined *local_34;
  undefined4 local_30 [2];
  CMwNod *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ac7408;
  local_c = ExceptionList;
  pCVar2 = (CFastStringInt *)(DAT_00cca150 ^ (uint)&stack0xffffffb4);
  ExceptionList = &local_c;
  if (param_1 == (CControlStyle *)0x0) {
    param_1 = *(CControlStyle **)(this + 0x180);
  }
  *(undefined4 *)(this + 0x180) = 0;
  if (param_1 != (CControlStyle *)0x0) {
    pCVar4 = (CControlStyle *)0x0;
    this_00 = this + 0x70;
    do {
      local_14 = 0;
      local_10 = PTR_DAT_00bbf7dc;
      local_4 = 0;
      InternalGetTextSettings
                (this,pCVar4,(ETextMode)local_30,(STextSettings *)param_1,
                 (CControlStyleSheet *)pCVar2);
      pCVar2 = (CFastStringInt *)&local_38;
      local_38 = local_c;
      *(undefined4 *)(this_00 + -0x14) = 8;
      local_34 = local_10;
      local_30[0] = 0;
      CFastStringInt::SetString(this_00,pCVar2,unaff_EDI);
      pCVar1 = local_28;
      *(undefined4 *)(this_00 + -0x10) = local_1c;
      *(undefined4 *)(this_00 + -0xc) = local_18;
      *(undefined4 *)(this_00 + -8) = local_14;
      *(undefined **)(this_00 + -4) = local_10;
      *(undefined4 *)(this + 0x54) = local_24;
      *(undefined4 *)(this + 0x58) = local_20;
      if (local_28 != *(CMwNod **)(this + 0x50)) {
        if (local_28 != (CMwNod *)0x0) {
          unaff_EDI = (SStringParam *)0x772f9d;
          CMwNod::MwAddRef(local_28,(CMwNod *)pCVar2);
        }
        if (*(CMwNod **)(this + 0x50) != (CMwNod *)0x0) {
          CMwNod::MwRelease(*(CMwNod **)(this + 0x50),(CMwNod *)pCVar2);
        }
        *(CMwNod **)(this + 0x50) = pCVar1;
      }
      local_4 = 0xffffffff;
      if (local_10 != PTR_DAT_00bbf7dc) {
        if ((local_10[-1] & 0x80) == 0) {
          puVar3 = local_10 + -2;
        }
        else {
          puVar3 = local_10 + -4;
        }
        operator_delete__(puVar3);
      }
      pCVar4 = pCVar4 + 1;
      this_00 = this_00 + 0x1c;
    } while ((int)pCVar4 < 3);
  }
  ExceptionList = local_c;
  return;
}
}

// =================================================
// Function: CControlStyle::InternalGetTextSettings
// =================================================
void __thiscall
CControlStyle::InternalGetTextSettings
          (CControlStyle *this,CControlStyle *param_1,ETextMode param_2,STextSettings *param_3,
          CControlStyleSheet *param_4)
{
{
  SCasterCat *pSVar1;
  int iVar2;
  ETextMode unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  SStringParam *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(this + (int)(param_1 + 4) * 0x1c + 4);
  local_8 = *(undefined4 *)(this + (int)(param_1 + 4) * 0x1c);
  local_4 = 0;
  CFastStringInt::SetString((void *)(param_2 + 0x1c),(CFastStringInt *)&local_c,unaff_EDI);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(this + 0x54);
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(this + 0x58);
  *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(this + (int)param_1 * 0x1c + 0x60);
  *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(this + (int)param_1 * 0x1c + 100);
  *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(this + (int)param_1 * 0x1c + 0x68);
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(this + (int)param_1 * 0x1c + 0x6c);
  *(undefined4 *)param_2 = *(undefined4 *)(this + 0x50);
  if (param_4 != (CControlStyleSheet *)0x0) {
    if ((int)*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + (int)param_1 * 0x1c + 0x5c)
        < 8) {
      pSVar1 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                         (param_4 + 0x18,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (this + (int)param_1 * 0x1c + 0x5c),unaff_ESI);
      *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)pSVar1;
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(pSVar1 + 4);
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(pSVar1 + 8);
      pSVar1 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (param_4 + 0x20,
                          *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)
                           (this + (int)param_1 * 0x1c + 0x5c),unaff_EBP);
      *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)pSVar1;
    }
    iVar2 = InternalShouldFontBeTakenFromMaster(this,(CControlStyle *)param_4,unaff_EBX);
    if ((iVar2 != 0) && (*(int *)(param_4 + 0x14) != 0)) {
      *(undefined4 *)param_2 = *(undefined4 *)(*(int *)(param_4 + 0x14) + 0x50);
      *(float *)(param_2 + 8) =
           *(float *)(*(int *)(param_4 + 0x14) + 0x58) * *(float *)(param_2 + 8);
      *(float *)(param_2 + 4) =
           *(float *)(*(int *)(param_4 + 0x14) + 0x54) * *(float *)(param_2 + 4);
    }
  }
  return;
}
}

// =================================================
// Function: CControlStyle::InternalShouldFontBeTakenFromMaster
// =================================================
int __thiscall
CControlStyle::InternalShouldFontBeTakenFromMaster
          (CControlStyle *this,CControlStyle *param_1,ETextMode param_2)
{
{
  if ((*(int *)(this + 0x50) != 0) &&
     ((*(byte *)(*(int *)(*(int *)(this + 0x50) + 8) + 0x18) & 4) == 0)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CControlStyle::SetFocusGainedScript
// =================================================
void __thiscall
CControlStyle::SetFocusGainedScript
          (CControlStyle *this,CControlStyle *param_1,CMwCmdBlockMain *param_2)
{
{
  CMwNod *unaff_EDI;
  CMwNod *pCVar1;
  
  if (param_1 != (CControlStyle *)0x0) {
    pCVar1 = (CMwNod *)0x7001000;
    (**(code **)(*(int *)param_1 + 0xac))();
    CMwNod::MwAddRef((CMwNod *)param_1,pCVar1);
  }
  if (*(CMwNod **)(this + 0x1c) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x1c),unaff_EDI);
  }
  *(CControlStyle **)(this + 0x1c) = param_1;
  return;
}
}

// =================================================
// Function: CControlStyle::SetFocusLostScript
// =================================================
void __thiscall
CControlStyle::SetFocusLostScript
          (CControlStyle *this,CControlStyle *param_1,CMwCmdBlockMain *param_2)
{
{
  CMwNod *unaff_EDI;
  CMwNod *pCVar1;
  
  if (param_1 != (CControlStyle *)0x0) {
    pCVar1 = (CMwNod *)0x7001000;
    (**(code **)(*(int *)param_1 + 0xac))();
    CMwNod::MwAddRef((CMwNod *)param_1,pCVar1);
  }
  if (*(CMwNod **)(this + 0x20) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x20),unaff_EDI);
  }
  *(CControlStyle **)(this + 0x20) = param_1;
  return;
}
}

