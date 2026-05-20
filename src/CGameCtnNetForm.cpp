// Class implementation: CGameCtnNetForm

// =================================================
// Function: CGameCtnNetForm::CGameCtnNetForm
// =================================================
void __thiscall
CGameCtnNetForm::CGameCtnNetForm
          (CGameCtnNetForm *this,CGameCtnNetForm *param_1,EMessageType param_2)
{
{
  CClassicBufferMemory *this_00;
  ulong unaff_ESI;
  CClassicBufferMemory *unaff_EDI;
  undefined4 in_stack_00000014;
  CGameCtnNetForm *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00abe753;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CGameNetForm::CGameNetForm
            ((CGameNetForm *)this,(CGameNetForm *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
  this_00 = (CClassicBufferMemory *)(this + 0x24);
  *(undefined ***)this = vftable;
  CClassicBufferMemory::CClassicBufferMemory(this_00,unaff_EDI);
  param_1 = (CGameCtnNetForm *)CONCAT31(param_1._1_3_,1);
  CClassicBufferMemory::PreAlloc(this_00,(CClassicBufferMemory *)&DAT_00000080,unaff_ESI);
  CClassicBufferMemory::Empty(this_00,(CClassicBufferMemory *)pCVar1);
  *(undefined4 *)(this + 0x20) = in_stack_00000014;
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CGameCtnNetForm::ValidatePacketForcedMods
// =================================================
int __cdecl
CGameCtnNetForm::ValidatePacketForcedMods
          (int param_1,int param_2,int param_3,uchar param_4,uchar *param_5,ulong param_6)
{
{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  
  if ((param_6 < 8) || (param_6 < 4)) {
    return 0;
  }
  uVar2 = *(uint *)(param_5 + 4);
  if (uVar2 < 0x11) {
    uVar5 = 8;
    puVar4 = (uint *)(param_5 + 8);
    if (7 < param_6) {
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          uVar3 = *puVar4;
          if (0x80 < uVar3) {
            return 0;
          }
          uVar5 = uVar5 + 4 + uVar3;
          pcVar1 = (char *)((int)puVar4 + uVar3 + 4);
          if (param_6 < uVar5) {
            return 0;
          }
          if (*pcVar1 != '\x02') {
            return 0;
          }
          uVar3 = *(uint *)(pcVar1 + 1);
          if (0x200 < uVar3) {
            return 0;
          }
          uVar5 = uVar5 + 5 + uVar3;
          puVar4 = (uint *)(pcVar1 + uVar3 + 5);
          if (param_6 < uVar5) {
            return 0;
          }
          if (uVar3 != 0) {
            uVar3 = *puVar4;
            if (0x200 < uVar3) {
              return 0;
            }
            uVar5 = uVar5 + 4 + uVar3;
            puVar4 = (uint *)((int)puVar4 + uVar3 + 4);
            if (param_6 < uVar5) {
              return 0;
            }
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar2);
      }
      return (uint)(uVar5 == param_6);
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameCtnNetForm::ValidatePacketForcedMusic
// =================================================
int __cdecl
CGameCtnNetForm::ValidatePacketForcedMusic
          (int param_1,int param_2,int param_3,uchar param_4,uchar *param_5,ulong param_6)
{
{
  uint uVar1;
  uint uVar2;
  
  if (8 < param_6) {
    if ((3 < param_6) && (param_5[4] == '\x02')) {
      uVar1 = *(uint *)(param_5 + 5);
      if (((uVar1 < 0x201) && (uVar2 = uVar1 + 9, uVar2 <= param_6)) &&
         ((uVar1 == 0 ||
          ((*(uint *)(param_5 + uVar1 + 9) < 0x201 &&
           (uVar2 = uVar1 + 0xd + *(uint *)(param_5 + uVar1 + 9), uVar2 <= param_6)))))) {
        return (uint)(uVar2 == param_6);
      }
    }
  }
  return 0;
}
}

// =================================================
// Function: CGameCtnNetForm::~CGameCtnNetForm
// =================================================
void __thiscall CGameCtnNetForm::~CGameCtnNetForm(CGameCtnNetForm *this,CGameCtnNetForm *param_1)
{
{
  CClassicBufferMemory *pCVar1;
  CGameNetForm *unaff_ESI;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00abe778;
  local_c = ExceptionList;
  pCVar1 = (CClassicBufferMemory *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = (void *)0x0;
  CClassicBufferMemory::~CClassicBufferMemory((CClassicBufferMemory *)(this + 0x24),pCVar1);
  CGameNetForm::~CGameNetForm((CGameNetForm *)this,unaff_ESI);
  ExceptionList = local_4;
  return;
}
}

