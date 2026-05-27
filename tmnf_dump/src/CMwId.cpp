// Class implementation: CMwId

// =================================================
// Function: CMwId::CMwId
// =================================================
void __thiscall CMwId::CMwId(void *this,CMwId *param_1)
{
{
  *(undefined4 *)this = *(undefined4 *)param_1;
  return;
}
}

// =================================================
// Function: CMwId::CreateFromLocalIndex
// =================================================
CMwId __cdecl CMwId::CreateFromLocalIndex(ulong param_1)
{
{
  CMwId *unaff_ESI;
  undefined4 in_stack_0000000c;
  
  CMwId((void *)param_1,unaff_ESI);
  *(undefined4 *)param_1 = in_stack_0000000c;
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CMwId::CreateFromLocalName
// =================================================
CMwId __cdecl CMwId::CreateFromLocalName(char *param_1)
{
{
  CFastStringInt *unaff_ESI;
  CMwId *in_stack_0000000c;
  void *local_c;
  undefined1 *puStack_8;
  void *local_4;
  
  puStack_8 = &LAB_00a82839;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_4 = (void *)0x0;
  CMwId(param_1,(CMwId *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  local_c = (void *)0x1;
  SetLocalName(param_1,in_stack_0000000c,unaff_ESI);
  ExceptionList = local_4;
  return SUB41(param_1,0);
}
}

// =================================================
// Function: CMwId::GetName
// =================================================
CFastString __thiscall CMwId::GetName(void *this,CTrackManiaEditorIconPage *param_1)
{
{
  char cVar1;
  CFastString extraout_AL;
  char *extraout_EAX;
  char *pcVar2;
  undefined *extraout_EAX_00;
  undefined *puVar3;
  CFastString *unaff_ESI;
  void *unaff_retaddr;
  void *in_stack_0000000c;
  SStringParam *in_stack_ffffffdc;
  undefined4 local_1c;
  undefined *local_18;
  undefined *local_14;
  int local_10;
  undefined *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00ae4c18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  GetString(this,(CMwStatsValue *)(DAT_00cca150 ^ (uint)&stack0xffffffd8),unaff_ESI);
  if (extraout_EAX != (char *)0x0) {
    pcVar2 = extraout_EAX;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    local_10 = (int)pcVar2 - (int)(extraout_EAX + 1);
    CFastStringInt::SetLatin1OrUtf8(in_stack_0000000c,(CFastStringInt *)&local_14,in_stack_ffffffdc)
    ;
    ExceptionList = unaff_retaddr;
    return extraout_AL;
  }
  local_1c = 0;
  local_18 = PTR_DAT_00bbf7d8;
  GetName(this,(CTrackManiaEditorIconPage *)&local_1c);
  local_8 = (undefined1 *)local_1c;
  local_c = local_18;
  CFastStringInt::SetLatin1OrUtf8(in_stack_0000000c,(CFastStringInt *)&local_c,in_stack_ffffffdc);
  if (local_14 != PTR_DAT_00bbf7d8) {
    puVar3 = local_14 + -1;
    if ((local_14[-1] & 0x80) != 0) {
      puVar3 = local_14 + -4;
    }
    operator_delete__(puVar3);
    local_14 = extraout_EAX_00;
  }
  ExceptionList = unaff_retaddr;
  return SUB41(local_14,0);
}
}

// =================================================
// Function: CMwId::GetString
// =================================================
void __thiscall CMwId::GetString(void *this,CMwStatsValue *param_1,CFastString *param_2)
{
{
  uint uVar1;
  void *this_00;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  ulong unaff_retaddr;
  
  this_00 = DAT_00d739e0;
  uVar1 = *(uint *)this;
  if (((uVar1 & 0xc0000000) != 0x40000000) && ((uVar1 & 0xc0000000) != 0x80000000)) {
    return;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     ((void *)((int)DAT_00d739e0 + ((uVar1 & 0x3fffffff) >> 0x10) * 8 + 0xc),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar1 & 0xffff),unaff_ESI);
  CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
            (this_00,*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)pSVar2,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwId::SetLocalName
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CMwId::SetLocalName(void *this,CMwId *param_1,CFastStringInt *param_2)
{
{
  int unaff_ESI;
  CFastStringInt *unaff_retaddr;
  
  if ((_DAT_00d739f4 & 1) == 0) {
    _DAT_00d739f4 = _DAT_00d739f4 | 1;
    _DAT_00d739ec = 0;
    DAT_00d739f0 = (CMwId *)PTR_DAT_00bbf7d8;
    _atexit(`public:_void___thiscall_CMwId::SetLocalName(class_CFastStringInt_const&)'::__l2::
            _dynamic_atexit_destructor_for__Utf8__);
  }
  CFastStringInt::GetUtf8(param_1,(CFastStringInt *)&DAT_00d739ec,(CFastString *)0x0,unaff_ESI);
  SetLocalName(this,DAT_00d739f0,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CMwId::StaticInit
// =================================================
void __cdecl CMwId::StaticInit(void)
{
{
  undefined4 *puVar1;
  SMwIdInternal *pSVar2;
  void *pvVar3;
  void *extraout_EAX;
  CFastBuffer<class_CSystemFidsFolder*> *pCVar4;
  undefined4 extraout_EAX_00;
  ulong unaff_ESI;
  void *in_stack_00000008;
  CSystemFidFile **ppCVar5;
  CMwId *pCVar6;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pCVar6 = (CMwId *)&LAB_00ae4c9b;
  pSVar2 = (SMwIdInternal *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ppCVar5 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pvVar3 = operator_new(0x110);
  local_4 = 0;
  if (pvVar3 == (void *)0x0) {
    DAT_00d739e0 = (void *)0x0;
  }
  else {
    SMwIdInternal::SMwIdInternal(pvVar3,pSVar2);
    DAT_00d739e0 = extraout_EAX;
  }
  CFastBuffer<unsigned_char>::SetSizeAtLeast
            (DAT_00d739e0,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)0x249f0,unaff_ESI);
  pCVar4 = (CFastBuffer<class_CSystemFidsFolder*> *)CFastAlgo::ComputeHashSize(0x1d4c);
  CFastArray<enum_CTrackManiaEditorTerrain::EUpdate>::SetCount
            ((void *)((int)DAT_00d739e0 + 0xc),pCVar4,(ulong)pvVar3);
  local_4 = 0xffffffff;
  CFastArray<class_CSystemFidFile*>::InitValue
            ((void *)((int)DAT_00d739e0 + 0xc),(CFastArray<class_CSystemFidFile*> *)&local_4,ppCVar5
            );
  *(undefined4 *)((int)DAT_00d739e0 + 0x10c) = 1;
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    DAT_00d739e4 = 0;
  }
  else {
    CMwId(pvVar3,pCVar6);
    DAT_00d739e4 = extraout_EAX_00;
  }
  DAT_00d72e88 = DeleteArchiveUserData;
  for (puVar1 = DAT_00d739e8; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[1]) {
    (*(code *)*puVar1)();
  }
  ExceptionList = in_stack_00000008;
  return;
}
}

