// Class implementation: CFastStringBase_char

// =================================================
// Function: CFastStringBase<char>::AllocAtLeast
// =================================================
void __thiscall
CFastStringBase<char>::AllocAtLeast
          (CFastStringBase<char> *this,CFastStringBase<wchar_t> *param_1,ulong param_2,int param_3,
          SOldChars *param_4)
{
{
  undefined1 *puVar1;
  CFastStringBase<wchar_t> *pCVar2;
  wchar_t *pwVar3;
  undefined1 *puVar4;
  
  if (param_3 != 0) {
    *(undefined4 *)param_3 = *(undefined4 *)(this + 4);
  }
  if (*(CFastStringBase<wchar_t> **)this < param_1) {
    puVar1 = *(undefined1 **)(this + 4);
    if (puVar1 == &DAT_00b2c878) {
      pCVar2 = (CFastStringBase<wchar_t> *)0x0;
    }
    else if ((char)puVar1[-1] < '\0') {
      pCVar2 = (CFastStringBase<wchar_t> *)(*(uint *)(puVar1 + -4) & 0x7fffffff);
    }
    else {
      pCVar2 = (CFastStringBase<wchar_t> *)((byte)puVar1[-1] & 0x7f);
    }
    if (pCVar2 < param_1) {
      pwVar3 = HeapAllocGetChars((ulong)param_1);
      if ((param_2 != 0) && (*(uint *)this != 0)) {
        _memcpy(pwVar3,*(void **)(this + 4),*(uint *)this);
      }
      puVar1 = *(undefined1 **)(this + 4);
      if (param_3 == 0) {
        if (puVar1 != &DAT_00b2c878) {
          puVar4 = puVar1 + -1;
          if ((puVar1[-1] & 0x80) != 0) {
            puVar4 = puVar1 + -4;
          }
          operator_delete__(puVar4);
        }
      }
      else if (puVar1 != &DAT_00b2c878) {
        puVar4 = puVar1 + -1;
        if ((puVar1[-1] & 0x80) != 0) {
          puVar4 = puVar1 + -4;
        }
        *(undefined1 **)(param_3 + 4) = puVar4;
        *(wchar_t **)(this + 4) = pwVar3;
        return;
      }
      *(wchar_t **)(this + 4) = pwVar3;
    }
  }
  return;
}
}

// =================================================
// Function: CFastStringBase<char>::Clear
// =================================================
void __thiscall CFastStringBase<char>::Clear(CFastStringBase<char> *this,TiXmlNode *param_1)
{
{
  if (*(int *)this != 0) {
    *(undefined4 *)this = 0;
    **(undefined1 **)(this + 4) = 0;
  }
  return;
}
}

// =================================================
// Function: CFastStringBase<char>::HeapAllocGetChars
// =================================================
wchar_t * __cdecl CFastStringBase<char>::HeapAllocGetChars(ulong param_1)
{
{
  uint uVar1;
  uint *puVar2;
  
  if (param_1 < 0x80) {
    uVar1 = param_1 + 2;
  }
  else {
    uVar1 = param_1 + 5;
  }
  if (uVar1 < param_1) {
    uVar1 = 0xffffffff;
  }
  puVar2 = operator_new__(uVar1);
  if (param_1 >= 0x80) {
    *puVar2 = param_1 | 0x80000000;
    return (wchar_t *)(puVar2 + 1);
  }
  *(byte *)puVar2 = (byte)param_1 & 0x7f;
  return (wchar_t *)((int)puVar2 + 1);
}
}

// =================================================
// Function: CFastStringBase<char>::PreAlloc
// =================================================
void __thiscall
CFastStringBase<char>::PreAlloc
          (CFastStringBase<char> *this,CClassicBufferMemory *param_1,ulong param_2)
{
{
  SOldChars *unaff_EDI;
  
  if (param_1 != (CClassicBufferMemory *)0x0) {
    AllocAtLeast(this,(CFastStringBase<wchar_t> *)param_1,1,0,unaff_EDI);
    *(undefined1 *)(*(int *)(this + 4) + *(int *)this) = 0;
    if (*(CClassicBufferMemory **)this <= param_1) {
      param_1[*(int *)(this + 4)] = (CClassicBufferMemory)0x0;
    }
  }
  return;
}
}

