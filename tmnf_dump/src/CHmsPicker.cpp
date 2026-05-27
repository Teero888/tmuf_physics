// Class implementation: CHmsPicker

// =================================================
// Function: CHmsPicker::CHmsPicker
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CHmsPicker::CHmsPicker(CHmsPicker *this,CHmsPicker *param_1)
{
{
  GmMat43 *unaff_EBX;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat> *unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a96c86;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd4),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>::
  CFastBufferCat<class_CMwNodRef<class_CPlugMaterial>,struct_SFastCat>(this + 0xe8,unaff_ESI);
  local_c = _DAT_00b2c060;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(void **)(this + 0x1c) = local_c;
  *(void **)(this + 0x20) = local_c;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  local_8 = (undefined1 *)0x3f800000;
  uStack00000008 = 1;
  local_4 = 0x3f800000;
  *(void **)(this + 0x24) = local_c;
  *(void **)(this + 0x28) = local_c;
  *(undefined4 *)(this + 0x2c) = 0x3f800000;
  *(undefined4 *)(this + 0x30) = 0x3f800000;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x90) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  GmIso4::SetIdentity(this + 0x98,unaff_EBX);
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 200) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xcc) = 0;
  *(undefined4 *)(this + 0xdc) = 0xffffffff;
  *(void **)(this + 0xd0) = _DAT_00b2c060;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0;
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CHmsPicker::CopyFromPicker
// =================================================
void __thiscall CHmsPicker::CopyFromPicker(CHmsPicker *this,CHmsPicker *param_1,CHmsPicker *param_2)
{
{
  int iVar1;
  CHmsPicker *pCVar2;
  CHmsPicker *pCVar3;
  
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(this + 0x20) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(this + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(this + 0x30) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(this + 0x34) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(this + 0x38) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(this + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(param_1 + 0x58);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(this + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(this + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(this + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(this + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(this + 0x88) = *(undefined4 *)(param_1 + 0x88);
  pCVar2 = param_1 + 0x98;
  pCVar3 = this + 0x98;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)pCVar3 = *(undefined4 *)pCVar2;
    pCVar2 = pCVar2 + 4;
    pCVar3 = pCVar3 + 4;
  }
  *(undefined4 *)(this + 200) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(this + 0xcc) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(this + 0xd0) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(this + 0xd4) = *(undefined4 *)(param_1 + 0xd4);
  *(undefined4 *)(this + 0xd8) = *(undefined4 *)(param_1 + 0xd8);
  *(undefined4 *)(this + 0xdc) = *(undefined4 *)(param_1 + 0xdc);
  return;
}
}

