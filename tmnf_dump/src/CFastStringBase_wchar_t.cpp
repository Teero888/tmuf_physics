// Class implementation: CFastStringBase_wchar_t

// =================================================
// Function: CFastStringBase<wchar_t>::AllocAtLeast
// =================================================
void __thiscall
CFastStringBase<wchar_t>::AllocAtLeast
          (void *this,CFastStringBase<wchar_t> *param_1,ulong param_2,int param_3,SOldChars *param_4
          )
{
{
  undefined2 *puVar1;
  CFastStringBase<wchar_t> *pCVar2;
  wchar_t *pwVar3;
  
  if (param_3 != 0) {
    *(undefined4 *)param_3 = *(undefined4 *)((int)this + 4);
  }
  if (*(CFastStringBase<wchar_t> **)this < param_1) {
    puVar1 = *(undefined2 **)((int)this + 4);
    if (puVar1 == &DAT_00b30b8c) {
      pCVar2 = (CFastStringBase<wchar_t> *)0x0;
    }
    else if ((char)*(byte *)((int)puVar1 + -1) < '\0') {
      pCVar2 = (CFastStringBase<wchar_t> *)(*(uint *)(puVar1 + -2) & 0x7fffffff);
    }
    else {
      pCVar2 = (CFastStringBase<wchar_t> *)(*(byte *)((int)puVar1 + -1) & 0x7f);
    }
    if (pCVar2 < param_1) {
      pwVar3 = HeapAllocGetChars((ulong)param_1);
      if ((param_2 != 0) && (*(int *)this != 0)) {
        _memcpy(pwVar3,*(void **)((int)this + 4),*(int *)this * 2);
      }
      puVar1 = *(undefined2 **)((int)this + 4);
      if (param_3 == 0) {
        if (puVar1 != &DAT_00b30b8c) {
          if ((*(byte *)((int)puVar1 + -1) & 0x80) != 0) {
            operator_delete__(puVar1 + -2);
            *(wchar_t **)((int)this + 4) = pwVar3;
            return;
          }
          operator_delete__(puVar1 + -1);
        }
      }
      else if (puVar1 != &DAT_00b30b8c) {
        if ((*(byte *)((int)puVar1 + -1) & 0x80) != 0) {
          *(undefined2 **)(param_3 + 4) = puVar1 + -2;
          *(wchar_t **)((int)this + 4) = pwVar3;
          return;
        }
        *(undefined2 **)(param_3 + 4) = puVar1 + -1;
        *(wchar_t **)((int)this + 4) = pwVar3;
        return;
      }
      *(wchar_t **)((int)this + 4) = pwVar3;
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringBase<wchar_t>::CopyAndClear
// =================================================
void __thiscall
CFastStringBase<wchar_t>::CopyAndClear
          (void *this,CFastStringBase<wchar_t> *param_1,CFastStringBase<wchar_t> *param_2)
{
{
  undefined *puVar1;
  
  puVar1 = *(undefined **)((int)this + 4);
  if (puVar1 != PTR_DAT_00bbf7dc) {
    if ((puVar1[-1] & 0x80) == 0) {
      puVar1 = puVar1 + -2;
    }
    else {
      puVar1 = puVar1 + -4;
    }
    operator_delete__(puVar1);
    *(undefined4 *)this = 0;
    *(undefined **)((int)this + 4) = PTR_DAT_00bbf7dc;
  }
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)param_1 = 0;
  *(undefined **)(param_1 + 4) = PTR_DAT_00bbf7dc;
  return;
}
}

// =================================================
// Function: CFastStringBase<wchar_t>::PreAlloc
// =================================================
void __thiscall
CFastStringBase<wchar_t>::PreAlloc(void *this,CClassicBufferMemory *param_1,ulong param_2)
{
{
  SOldChars *unaff_EDI;
  
  if (param_1 != (CClassicBufferMemory *)0x0) {
    AllocAtLeast(this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    *(undefined2 *)(*(int *)((int)this + 4) + *(int *)this * 2) = 0;
    if (*(CClassicBufferMemory **)this <= param_1) {
      *(undefined2 *)(*(int *)((int)this + 4) + (int)param_1 * 2) = 0;
    }
  }
  return;
}
}

