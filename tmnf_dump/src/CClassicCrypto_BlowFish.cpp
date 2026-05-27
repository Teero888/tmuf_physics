// Class implementation: CClassicCrypto_BlowFish

// =================================================
// Function: CClassicCrypto_BlowFish::DoBlock
// =================================================
void __thiscall
CClassicCrypto_BlowFish::DoBlock
          (void *this,CClassicCrypto_BlowFish *param_1,uint64 *param_2,uint64 *param_3)
{
{
  uint uVar1;
  uint extraout_EAX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  
  __aullshr();
  uVar3 = *(uint *)param_1 ^ *(uint *)this;
  iVar4 = 2;
  uVar2 = extraout_EAX;
  puVar5 = (uint *)((int)this + 8);
  do {
    uVar2 = uVar2 ^ (*(int *)((int)this + (uVar3 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar3 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar3 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar3 & 0xff) * 4 + 0xc48) ^ puVar5[-1];
    uVar3 = uVar3 ^ (*(int *)((int)this + (uVar2 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar2 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar2 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar2 & 0xff) * 4 + 0xc48) ^ *puVar5;
    uVar2 = uVar2 ^ (*(int *)((int)this + (uVar3 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar3 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar3 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar3 & 0xff) * 4 + 0xc48) ^ puVar5[1];
    uVar3 = uVar3 ^ (*(int *)((int)this + (uVar2 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar2 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar2 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar2 & 0xff) * 4 + 0xc48) ^ puVar5[2];
    uVar2 = uVar2 ^ (*(int *)((int)this + (uVar3 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar3 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar3 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar3 & 0xff) * 4 + 0xc48) ^ puVar5[3];
    uVar3 = uVar3 ^ (*(int *)((int)this + (uVar2 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar2 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar2 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar2 & 0xff) * 4 + 0xc48) ^ puVar5[4];
    uVar2 = uVar2 ^ (*(int *)((int)this + (uVar3 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar3 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar3 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar3 & 0xff) * 4 + 0xc48) ^ puVar5[5];
    uVar3 = uVar3 ^ (*(int *)((int)this + (uVar2 >> 0x10 & 0xff) * 4 + 0x448) +
                     *(int *)((int)this + (uVar2 >> 0x18) * 4 + 0x48) ^
                    *(uint *)((int)this + (uVar2 >> 8 & 0xff) * 4 + 0x848)) +
                    *(int *)((int)this + (uVar2 & 0xff) * 4 + 0xc48) ^ puVar5[6];
    iVar4 = iVar4 + -1;
    puVar5 = puVar5 + 8;
  } while (iVar4 != 0);
  uVar1 = *(uint *)((int)this + 0x44);
  *(uint *)((int)param_2 + 4) = uVar3;
  *(uint *)param_2 = uVar1 ^ uVar2;
  return;
}
}

// =================================================
// Function: CClassicCrypto_BlowFish::DoString
// =================================================
void __thiscall
CClassicCrypto_BlowFish::DoString
          (void *this,CClassicCrypto_BlowFish *param_1,CFastString *param_2,CFastString *param_3,
          ECipherOpMode param_4,uint64 *param_5,int param_6)
{
{
  CFastStringBase<wchar_t> CVar1;
  ECipherOpMode this_00;
  uint extraout_EAX;
  ulong uVar2;
  uint uVar3;
  uint extraout_EAX_00;
  uint64 *puVar4;
  uint uVar5;
  uint64 *puVar6;
  uint64 *extraout_EDX;
  int iVar7;
  uint64 *puVar8;
  SOldChars *unaff_ESI;
  CFastStringBase<wchar_t> *pCVar9;
  SOldChars *unaff_EDI;
  CFastStringBase<wchar_t> *pCVar10;
  uint64 *puVar11;
  uint in_stack_0000001c;
  uint64 *in_stack_00000020;
  void *local_24;
  CFastStringBase<wchar_t> *local_20;
  CFastStringBase<wchar_t> *local_1c;
  CFastStringBase<wchar_t> *local_18;
  undefined4 local_14;
  uint64 *local_10;
  uint64 *local_c;
  uint64 *local_8;
  void *local_4;
  
  this_00 = param_4;
  local_4 = (void *)0xffffffff;
  local_8 = (uint64 *)&LAB_00ae1f00;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar9 = *(CFastStringBase<wchar_t> **)param_1;
  pCVar10 = pCVar9 + (-(int)pCVar9 & 7);
  CFastString::CFastString
            ((CFastString *)&local_24,(CFastString *)param_1,
             (char *)(DAT_00cca150 ^ (uint)&stack0xffffffc4));
  if (pCVar10 != local_20) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)&local_20,pCVar10,1,0,unaff_EDI);
    local_18[(int)pCVar10] = (CFastStringBase<wchar_t>)0x0;
    local_1c = pCVar10;
  }
  for (; pCVar9 < pCVar10; pCVar9 = pCVar9 + 1) {
    local_18[(int)pCVar9] = (CFastStringBase<wchar_t>)0x0;
  }
  param_3 = (CFastString *)0x0;
  if (param_5 == (uint64 *)0x0) {
    if (*(int *)((int)local_24 + 0x1048) == 2) {
      if (*(int *)param_6 == 0 && *(int *)(param_6 + 4) == 0) {
        CFastAlgo::GetRandomNat32();
        __allshl();
        local_8 = extraout_EDX;
        uVar2 = CFastAlgo::GetRandomNat32();
        *(ulong *)param_6 = uVar2 | extraout_EAX;
        *(uint64 **)(param_6 + 4) = local_8;
      }
      if (in_stack_0000001c != 0) {
        param_3 = (CFastString *)&DAT_00000008;
        if (*(int *)param_4 != 8) {
          CFastStringBase<char>::AllocAtLeast
                    ((CFastStringBase<char> *)param_4,(CFastStringBase<wchar_t> *)&DAT_00000008,1,0,
                     unaff_ESI);
          *(undefined1 *)(*(int *)(param_4 + 4) + 8) = 0;
          *(undefined4 *)param_4 = 8;
        }
        uVar3 = *(uint *)param_6;
        uVar5 = *(uint *)(param_6 + 4);
        iVar7 = 8;
        do {
          *(char *)(iVar7 + -1 + *(int *)(param_4 + 4)) = (char)uVar3;
          uVar3 = uVar3 >> 8 | uVar5 << 0x18;
          uVar5 = uVar5 >> 8;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    else if (in_stack_0000001c != 0) {
      if (*(uint *)param_1 < 8) {
        if (*(int *)param_4 != 0) {
          CFastStringBase<char>::AllocAtLeast
                    ((CFastStringBase<char> *)param_4,(CFastStringBase<wchar_t> *)0x0,1,0,unaff_ESI)
          ;
          **(undefined1 **)(param_4 + 4) = 0;
          *(undefined4 *)param_4 = 0;
        }
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity
                  (&local_1c,(SHeaderCommunity *)unaff_ESI);
        ExceptionList = local_4;
        return;
      }
      *(undefined4 *)(param_6 + 4) = 0;
      *(undefined4 *)param_6 = 0;
      CVar1 = *local_18;
      *(undefined4 *)(param_6 + 4) = 0;
      *(uint *)param_6 = (uint)(byte)CVar1;
      CVar1 = local_18[1];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = (uint)(byte)CVar1 | *(uint *)param_6 << 8;
      CVar1 = local_18[2];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = (uint)(byte)CVar1 | *(uint *)param_6 << 8;
      CVar1 = local_18[3];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = (uint)(byte)CVar1 | *(uint *)param_6 << 8;
      CVar1 = local_18[4];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = (uint)(byte)CVar1 | *(uint *)param_6 << 8;
      CVar1 = local_18[5];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = (uint)(byte)CVar1 | *(uint *)param_6 << 8;
      uVar5 = *(uint *)param_6 << 8;
      uVar3 = (byte)local_18[6] | uVar5;
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | *(uint *)param_6 >> 0x18;
      *(uint *)param_6 = uVar3;
      *(uint *)param_6 = uVar3 << 8 | (uint)(byte)local_18[7];
      *(uint *)(param_6 + 4) = *(int *)(param_6 + 4) << 8 | uVar5 >> 0x18;
      CFastString::TruncBefore
                ((CFastString *)&local_1c,(CFastString *)(local_1c + -8),(ulong)unaff_ESI);
      local_1c = local_18;
      pCVar10 = local_18;
    }
    __aullshr();
    param_4 = *(ECipherOpMode *)param_6;
    in_stack_0000001c = extraout_EAX_00;
  }
  pCVar9 = (CFastStringBase<wchar_t> *)(param_3 + (int)pCVar10);
  if (pCVar9 != *(CFastStringBase<wchar_t> **)this_00) {
    CFastStringBase<char>::AllocAtLeast((CFastStringBase<char> *)this_00,pCVar9,1,0,unaff_ESI);
    pCVar9[*(int *)(this_00 + 4)] = (CFastStringBase<wchar_t>)0x0;
    *(CFastStringBase<wchar_t> **)this_00 = pCVar9;
  }
  pCVar9 = (CFastStringBase<wchar_t> *)0x0;
  if (pCVar10 != (CFastStringBase<wchar_t> *)0x0) {
    do {
      puVar6 = (uint64 *)
               CONCAT31(CONCAT21(CONCAT11(local_18[(int)pCVar9],(local_18 + 1)[(int)pCVar9]),
                                 (local_18 + 2)[(int)pCVar9]),(local_18 + 3)[(int)pCVar9]);
      puVar11 = (uint64 *)
                CONCAT31(CONCAT21(CONCAT11((local_18 + 4)[(int)pCVar9],(local_18 + 5)[(int)pCVar9]),
                                  (local_18 + 6)[(int)pCVar9]),(local_18 + 7)[(int)pCVar9]);
      if ((*(int *)((int)local_24 + 0x1048) == 2) && (param_5 == (uint64 *)0x0)) {
        puVar6 = (uint64 *)((uint)puVar6 ^ in_stack_0000001c);
        puVar11 = (uint64 *)((uint)puVar11 ^ param_4);
      }
      local_14 = 0;
      local_10 = (uint64 *)0x0;
      local_c = puVar6;
      local_8 = puVar11;
      DoBlock(local_24,(CClassicCrypto_BlowFish *)&local_c,(uint64 *)&local_14,(uint64 *)unaff_ESI);
      puVar4 = local_c;
      puVar8 = local_10;
      if (param_6 == 0) {
        if (*(int *)(local_20 + 0x1048) == 2) {
          in_stack_00000020 = local_10;
          param_5 = local_c;
        }
        else {
          puVar8 = (uint64 *)((uint)local_10 ^ (uint)in_stack_00000020);
          puVar4 = (uint64 *)((uint)local_c ^ (uint)param_5);
          param_5 = puVar11;
          in_stack_00000020 = puVar6;
        }
      }
      iVar7 = 4;
      do {
        pCVar9[(param_4 - 1) + *(int *)(this_00 + 4) + iVar7] = SUB41(puVar8,0);
        pCVar9[param_4 + 3 + *(int *)(this_00 + 4) + iVar7] = SUB41(puVar4,0);
        puVar8 = (uint64 *)((uint)puVar8 >> 8);
        puVar4 = (uint64 *)((uint)puVar4 >> 8);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      pCVar9 = pCVar9 + 8;
    } while (pCVar9 < local_1c);
  }
  if (*(int *)((int)local_24 + 0x1048) == 1) {
    CFastString::FilterStringForPrintableChars((CFastString *)this_00);
  }
  if (local_18 != (CFastStringBase<wchar_t> *)PTR_DAT_00bbf7d8) {
    pCVar9 = local_18 + -1;
    if (((byte)local_18[-1] & 0x80) != 0) {
      pCVar9 = local_18 + -4;
    }
    operator_delete__(pCVar9);
  }
  ExceptionList = local_4;
  return;
}
}

