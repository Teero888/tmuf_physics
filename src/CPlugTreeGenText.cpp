// Class implementation: CPlugTreeGenText

// =================================================
// Function: CPlugTreeGenText::ComputeLineCount
// =================================================
ulong __thiscall
CPlugTreeGenText::ComputeLineCount(CPlugTreeGenText *this,CPlugTreeGenText *param_1)
{
{
  ulong uVar1;
  int unaff_retaddr;
  
  if (*(int *)(this + 0x44) == -1) {
    return 1;
  }
  uVar1 = InternalGenerateTreeMultiLine
                    (this,(CPlugTreeGenText *)0x0,(CPlugTree *)0x0,(CUrlLinks *)0x0,
                     (CEditionData **)0x1,unaff_retaddr);
  return uVar1;
}
}

// =================================================
// Function: CPlugTreeGenText::InternalGenerateTreeMultiLine
// =================================================
/* WARNING: Removing unreachable block (ram,0x00857074) */
/* WARNING: Removing unreachable block (ram,0x0085707a) */
/* WARNING: Removing unreachable block (ram,0x0085710d) */
/* WARNING: Removing unreachable block (ram,0x00857135) */
/* WARNING: Removing unreachable block (ram,0x0085715a) */
/* WARNING: Removing unreachable block (ram,0x00857179) */
/* WARNING: Removing unreachable block (ram,0x0085715e) */
/* WARNING: Removing unreachable block (ram,0x0085716d) */
/* WARNING: Removing unreachable block (ram,0x0085716f) */
/* WARNING: Removing unreachable block (ram,0x00857185) */
/* WARNING: Removing unreachable block (ram,0x008571ba) */
/* WARNING: Removing unreachable block (ram,0x008571c0) */
/* WARNING: Removing unreachable block (ram,0x008571da) */
/* WARNING: Removing unreachable block (ram,0x008571eb) */
/* WARNING: Removing unreachable block (ram,0x008571f6) */
/* WARNING: Removing unreachable block (ram,0x00857200) */
/* WARNING: Removing unreachable block (ram,0x0085720c) */
/* WARNING: Removing unreachable block (ram,0x00857215) */
/* WARNING: Removing unreachable block (ram,0x00857233) */
/* WARNING: Removing unreachable block (ram,0x00857248) */
/* WARNING: Removing unreachable block (ram,0x00857250) */
/* WARNING: Removing unreachable block (ram,0x00857266) */
/* WARNING: Removing unreachable block (ram,0x00857272) */
/* WARNING: Removing unreachable block (ram,0x00857284) */
/* WARNING: Removing unreachable block (ram,0x0085728d) */
/* WARNING: Removing unreachable block (ram,0x008572a1) */
/* WARNING: Removing unreachable block (ram,0x008572a4) */
/* WARNING: Removing unreachable block (ram,0x008572d2) */
/* WARNING: Removing unreachable block (ram,0x008572ea) */
/* WARNING: Removing unreachable block (ram,0x0085731e) */
/* WARNING: Removing unreachable block (ram,0x00857325) */
/* WARNING: Removing unreachable block (ram,0x0085733d) */
/* WARNING: Removing unreachable block (ram,0x00857346) */
/* WARNING: Removing unreachable block (ram,0x0085735c) */
/* WARNING: Removing unreachable block (ram,0x00857365) */
/* WARNING: Removing unreachable block (ram,0x00857375) */
/* WARNING: Removing unreachable block (ram,0x00857397) */
/* WARNING: Removing unreachable block (ram,0x008573b2) */
/* WARNING: Removing unreachable block (ram,0x0085739b) */
/* WARNING: Removing unreachable block (ram,0x008573ae) */
/* WARNING: Removing unreachable block (ram,0x008573b0) */
/* WARNING: Removing unreachable block (ram,0x008573c2) */
/* WARNING: Removing unreachable block (ram,0x008573e9) */
/* WARNING: Removing unreachable block (ram,0x008573ca) */
/* WARNING: Removing unreachable block (ram,0x008573e4) */
/* WARNING: Removing unreachable block (ram,0x008573cf) */
/* WARNING: Removing unreachable block (ram,0x008573d4) */
/* WARNING: Removing unreachable block (ram,0x008573f7) */
/* WARNING: Removing unreachable block (ram,0x00857400) */
/* WARNING: Removing unreachable block (ram,0x00857437) */
/* WARNING: Removing unreachable block (ram,0x00857448) */
/* WARNING: Removing unreachable block (ram,0x00857457) */
/* WARNING: Removing unreachable block (ram,0x0085745f) */
/* WARNING: Removing unreachable block (ram,0x00857462) */
/* WARNING: Removing unreachable block (ram,0x0085747c) */
/* WARNING: Removing unreachable block (ram,0x00857484) */
/* WARNING: Removing unreachable block (ram,0x0085748c) */
/* WARNING: Removing unreachable block (ram,0x0085748f) */
/* WARNING: Recovered jumptable eliminated as dead code */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __thiscall
CPlugTreeGenText::InternalGenerateTreeMultiLine
          (CPlugTreeGenText *this,CPlugTreeGenText *param_1,CPlugTree *param_2,CUrlLinks *param_3,
          CEditionData **param_4,int param_5)
{
{
  uint uVar1;
  bool bVar2;
  CPlugVisualSprite *pCVar3;
  CFastStringInt *pCVar4;
  CPlugTree *extraout_EAX;
  undefined *puVar5;
  undefined2 *puVar6;
  ESpriteColor0 *unaff_EBX;
  CVisionViewportDx9 *unaff_ESI;
  float fVar7;
  CPlugTree *this_00;
  code *unaff_EDI;
  void *in_stack_00000018;
  CVisionViewportDx9 *in_stack_fffffef8;
  ESpriteColor0 *in_stack_fffffefc;
  ulong in_stack_ffffff00;
  ulong in_stack_ffffff04;
  ulong in_stack_ffffff08;
  CFastStringInt *in_stack_ffffff0c;
  CFastStringInt *in_stack_ffffff10;
  CPlugTreeGenText *in_stack_ffffff14;
  SStringParam *in_stack_ffffff18;
  int local_dc;
  CPlugTree *local_d8;
  float local_d4;
  float local_d0;
  undefined *local_cc;
  undefined *local_c8;
  uint local_c4;
  undefined *local_c0;
  ulong local_bc;
  undefined2 *local_b8;
  float local_b4;
  undefined2 *local_b0;
  int local_ac;
  float local_a8;
  float fStack_a4;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined1 *local_94;
  undefined1 *local_90;
  undefined4 uStack_8c;
  undefined *puStack_84;
  undefined *local_80;
  undefined4 local_7c;
  uint local_74;
  undefined *puStack_70;
  undefined4 local_6c;
  uint local_68;
  undefined *local_64;
  undefined4 uStack_60;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00ad579b;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  pCVar3 = (CPlugVisualSprite *)(uint)(param_1 != (CPlugTreeGenText *)0x0);
  if ((DAT_00d6ea10 & 1) == 0) {
    DAT_00d6ea10 = DAT_00d6ea10 | 1;
    local_c = 0;
    CPlugFont::SCharStyle::SCharStyle
              (&DAT_00d6e9e8,(SCharStyle *)(DAT_00cca150 ^ (uint)&stack0xfffffee8));
    _atexit(`protected:_unsigned_long___thiscall_CPlugTreeGenText::
            InternalGenerateTreeMultiLine(class_CPlugTree*,class_CPlugFont::CUrlLinks*,class_CUrlLinks::CEditionData**,int)const_'
            ::__l2::_dynamic_atexit_destructor_for__StyleText__);
    local_8 = 0xffffffff;
  }
  if ((DAT_00d6ea10 & 2) == 0) {
    DAT_00d6ea10 = DAT_00d6ea10 | 2;
    local_8 = 1;
    CPlugFont::SCharStyle::SCharStyle(&DAT_00d6e9c0,(SCharStyle *)unaff_EDI);
    unaff_EDI = `protected:_unsigned_long___thiscall_CPlugTreeGenText::
                InternalGenerateTreeMultiLine(class_CPlugTree*,class_CPlugFont::CUrlLinks*,class_CUrlLinks::CEditionData**,int)const_'
                ::__l2::_dynamic_atexit_destructor_for__StyleCurLine__;
    _atexit(`protected:_unsigned_long___thiscall_CPlugTreeGenText::
            InternalGenerateTreeMultiLine(class_CPlugTree*,class_CPlugFont::CUrlLinks*,class_CUrlLinks::CEditionData**,int)const_'
            ::__l2::_dynamic_atexit_destructor_for__StyleCurLine__);
  }
  CPlugFont::SCharStyle::Init
            (&DAT_00d6e9e8,(CLoadGeomDynaSprite *)(this + 0x20),(CPlugVisualSprite *)unaff_EDI,
             unaff_ESI,unaff_EBX);
  CPlugFont::SCharStyle::Init
            (&DAT_00d6e9c0,(CLoadGeomDynaSprite *)(this + 0x20),pCVar3,in_stack_fffffef8,
             in_stack_fffffefc);
  local_b8 = (undefined2 *)0x0;
  local_b4 = 0.0;
  local_d8 = (CPlugTree *)0x0;
  local_c4 = 0;
  local_c0 = PTR_DAT_00bbf7dc;
  CFastStringBase<wchar_t>::PreAlloc(&local_c4,(CClassicBufferMemory *)0x3e8,in_stack_ffffff00);
  local_dc = 0;
  local_d8 = (CPlugTree *)PTR_DAT_00bbf7dc;
  CFastStringBase<wchar_t>::PreAlloc(&local_dc,(CClassicBufferMemory *)0x3e8,in_stack_ffffff04);
  local_cc = (undefined *)0x0;
  local_c8 = PTR_DAT_00bbf7dc;
  in_stack_00000018 = (void *)CONCAT31(in_stack_00000018._1_3_,4);
  CFastStringBase<wchar_t>::PreAlloc(&local_cc,(CClassicBufferMemory *)0x3e8,in_stack_ffffff08);
  local_bc = CFastStringInt::ReadCharsStart(this + 0x18,in_stack_ffffff0c);
LAB_00856cba:
  if ((local_bc == 0) && (local_b4 == 0.0)) {
    if (local_c0 != PTR_DAT_00bbf7dc) {
      puVar5 = local_c0 + -4;
      if ((local_c0[-1] & 0x80) == 0) {
        puVar5 = local_c0 + -2;
      }
      operator_delete__(puVar5);
      local_c4 = 0;
      local_c0 = PTR_DAT_00bbf7dc;
    }
    if (local_cc != PTR_DAT_00bbf7dc) {
      puVar5 = local_cc + -4;
      if ((local_cc[-1] & 0x80) == 0) {
        puVar5 = local_cc + -2;
      }
      operator_delete__(puVar5);
      local_d0 = 0.0;
      local_cc = PTR_DAT_00bbf7dc;
    }
    if (local_b0 != (undefined2 *)PTR_DAT_00bbf7dc) {
      puVar6 = local_b0 + -2;
      if ((*(byte *)((int)local_b0 + -1) & 0x80) == 0) {
        puVar6 = local_b0 + -1;
      }
      operator_delete__(puVar6);
    }
    ExceptionList = in_stack_00000018;
    return (ulong)local_c8;
  }
  local_a0 = &DAT_00b2c878;
  local_9c = 0;
  CFastStringInt::SetString(&local_d0,(CFastStringInt *)&local_a0,(SStringParam *)in_stack_ffffff10)
  ;
  local_d0 = 0.0;
  local_d4 = 0.0;
  puVar6 = local_b8;
  while (puVar6 != (undefined2 *)0x0) {
    in_stack_ffffff10 = (CFastStringInt *)&local_b8;
    pCVar4 = (CFastStringInt *)
             CFastStringInt::ReadCharsNext(this + 0x18,in_stack_ffffff10,(ulong *)in_stack_ffffff14)
    ;
    if ((pCVar4 == (CFastStringInt *)0x0) || (pCVar4 == (CFastStringInt *)&DAT_0000000a)) break;
    if (((pCVar4 == (CFastStringInt *)&DAT_00000020) ||
        ((((pCVar4 == (CFastStringInt *)&DAT_0000002c || (pCVar4 == (CFastStringInt *)0x2e)) ||
          (pCVar4 == (CFastStringInt *)0x21)) ||
         ((pCVar4 == (CFastStringInt *)&DAT_0000003f || (pCVar4 == (CFastStringInt *)0x3a)))))) ||
       ((pCVar4 == (CFastStringInt *)&DAT_0000003b ||
        ((pCVar4 == (CFastStringInt *)&DAT_0000002f || (pCVar4 == (CFastStringInt *)0x2d)))))) {
      in_stack_ffffff10 = (CFastStringInt *)0x856d45;
      CFastStringInt::Concat(&local_c8,pCVar4,in_stack_ffffff18);
      local_c8 = (undefined *)0x1;
      in_stack_ffffff14 = (CPlugTreeGenText *)pCVar4;
      puVar6 = local_b0;
    }
    else {
      if (local_cc != (undefined *)0x0) break;
      in_stack_ffffff10 = (CFastStringInt *)0x856d5f;
      CFastStringInt::Concat(&local_c8,pCVar4,in_stack_ffffff18);
      in_stack_ffffff14 = (CPlugTreeGenText *)pCVar4;
      puVar6 = local_b0;
    }
  }
  local_d0 = (float)(local_c4 + 1);
  do {
    local_a8 = 0.0;
    if (local_cc != (undefined *)0x0) {
      local_b4 = 0.0;
      if (local_c0 != (undefined *)0x0) {
        CFastStringBase<wchar_t>::AllocAtLeast
                  (&local_c0,(CFastStringBase<wchar_t> *)0x0,1,0,(SOldChars *)in_stack_ffffff14);
        *local_b8 = 0;
        local_bc = 0;
      }
      if (local_b0 != (undefined2 *)0x0) {
        CFastStringInt::Concat
                  (&local_c0,(CFastStringInt *)(uint)*(ushort *)(local_ac + -2 + (int)local_b0 * 2),
                   (SStringParam *)in_stack_ffffff14);
        _DAT_00d6e9d8 = 0;
        local_b8 = (undefined2 *)
                   CPlugFont::GetLength(*(CPlugFont **)(this + 0x54),(CPlugFileSnd *)&local_bc);
      }
      puStack_70 = local_c8;
      local_74 = local_c4;
      local_6c = 0;
      CFastStringInt::Concat(&local_bc,(CFastStringInt *)&local_74,in_stack_ffffff18);
      in_stack_ffffff18 = (SStringParam *)&DAT_00d6e9c0;
      in_stack_ffffff14 = this + 0x30;
      in_stack_ffffff10 = (CFastStringInt *)&local_b8;
      _DAT_00d6e9d8 = 0;
      local_a8 = CPlugFont::GetLength
                           (*(CPlugFont **)(this + 0x54),(CPlugFileSnd *)in_stack_ffffff10);
      local_a8 = local_a8 - local_b4;
    }
    if ((*(float *)(this + 0x40) <= 0.0) || (local_a8 + (float)local_d8 <= *(float *)(this + 0x40)))
    {
      fVar7 = 0.0;
    }
    else {
      fVar7 = 1.4013e-45;
    }
    if ((((*(int *)(this + 0x48) == 0) || (*(float *)(this + 0x44) == 0.0)) ||
        ((uint)local_d0 < (uint)*(float *)(this + 0x44))) || (*(int *)(this + 0x3c) == 2)) {
      local_b4 = fVar7;
      if (fVar7 == 0.0) goto LAB_00856e9b;
    }
    else {
      local_b4 = 0.0;
LAB_00856e9b:
      fVar7 = local_b4;
      in_stack_ffffff10 = (CFastStringInt *)&puStack_84;
      puStack_84 = local_c8;
      local_80 = local_cc;
      local_7c = 0;
      CFastStringInt::Concat(&local_b0,in_stack_ffffff10,(SStringParam *)in_stack_ffffff14);
      local_d4 = fStack_a4 + local_d4;
    }
    if (((local_d4 != 0.0) || (local_b8 == (undefined2 *)0x0)) || (fVar7 != 0.0)) {
      uVar1 = *(uint *)(this + 0x50);
      bVar2 = false;
      if ((*(uint *)(this + 0x4c) < uVar1) && (uVar1 != 0xffffffff)) {
        if ((local_c4 < *(uint *)(this + 0x4c)) || (uVar1 < local_c4)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
      }
      if (local_dc != 0) {
        local_a0 = (undefined1 *)0x0;
        _DAT_00d6ea00 = 0;
        fStack_a4 = 0.0;
        if (bVar2) {
          _DAT_00d6ea00 = 0;
          (**(code **)(**(int **)(this + 0x54) + 0x7c))();
        }
        else {
          local_d8 = operator_new(0xac);
          if (local_d8 == (CPlugTree *)0x0) {
            this_00 = (CPlugTree *)0x0;
          }
          else {
            CPlugTree::CPlugTree(local_d8,(CPlugTree *)in_stack_ffffff14);
            this_00 = extraout_EAX;
          }
          CPlugTree::SetIsRooted(this_00,(CPlugTree *)0x0,(int)in_stack_ffffff14);
          (**(code **)(*(int *)param_1 + 0x88))();
          (**(code **)(**(int **)(this + 0x54) + 0x7c))();
          fVar7 = local_b4;
          in_stack_ffffff14 = (CPlugTreeGenText *)this_00;
        }
      }
      if (param_2 != (CPlugTree *)0x0) {
        CPlugFont::CUrlLinks::AddLineFeed((CUrlLinks *)param_2,(CUrlLinks *)in_stack_ffffff14);
      }
      local_c4 = local_c4 + 1;
      local_d8 = (CPlugTree *)0x0;
      local_d0 = (float)((int)local_d0 + 1);
      in_stack_ffffff10 = (CFastStringInt *)&local_94;
      local_94 = &DAT_00b2c878;
      local_90 = (undefined1 *)0x0;
      CFastStringInt::SetString(&local_b0,in_stack_ffffff10,(SStringParam *)in_stack_ffffff14);
      if (fVar7 != 0.0) {
        in_stack_ffffff14 = (CPlugTreeGenText *)&local_68;
        local_68 = local_c4;
        local_64 = local_c8;
        uStack_60 = 0;
        in_stack_ffffff10 = (CFastStringInt *)0x857052;
        CFastStringInt::Concat(&local_ac,(CFastStringInt *)in_stack_ffffff14,in_stack_ffffff18);
        local_d0 = (float)local_a0 + (float)_PTR_00b2c178;
      }
    }
    if ((local_d8 == (CPlugTree *)0x0) || (fVar7 == 0.0)) goto LAB_00856cba;
    local_90 = &DAT_00b2c878;
    uStack_8c = 0;
    CFastStringInt::SetString
              (&local_d0,(CFastStringInt *)&local_90,(SStringParam *)in_stack_ffffff10);
  } while( true );
}
}

