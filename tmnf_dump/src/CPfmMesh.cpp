// Class implementation: CPfmMesh

// =================================================
// Function: CPfmMesh::AddCell
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CPfmMesh::AddCell(CPfmMesh *this,CPfmMesh *param_1,GmVec3 *param_2,GmVec3 *param_3,GmVec3 *param_4)
{
{
  CPfmCell *pCVar1;
  void *pvVar2;
  void *extraout_EAX;
  CPfmCell *unaff_ESI;
  GmVec3 *unaff_EDI;
  float fStack00000014;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00aecdeb;
  local_c = ExceptionList;
  pCVar1 = (CPfmCell *)(DAT_00cca150 ^ (uint)&stack0xffffffdc);
  ExceptionList = &local_c;
  if ((_DAT_00d79300 & 1) == 0) {
    _DAT_00d79300 = _DAT_00d79300 | 1;
    local_14 = 0x3f800000;
    _DAT_00d792f4 = 0.0;
    _DAT_00d792f8 = 1.0;
    local_10 = 0;
    _DAT_00d792fc = 0.0;
  }
  pvVar2 = operator_new(0x130);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    CPfmCell::CPfmCell(pvVar2,pCVar1);
    pvVar2 = extraout_EAX;
  }
  CPfmCell::Initialize(pvVar2,(CPfmCell *)param_2,param_3,param_4,unaff_EDI);
  fStack00000014 =
       *(float *)((int)pvVar2 + 0xc) * _DAT_00d792fc +
       *(float *)((int)pvVar2 + 4) * _DAT_00d792f4 + *(float *)((int)pvVar2 + 8) * _DAT_00d792f8;
  if (fStack00000014 < _DAT_00c418e0 == (fStack00000014 == _DAT_00c418e0)) {
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 4,(TiXmlAttributeSet *)&local_14,(TiXmlAttribute *)unaff_ESI);
  }
  else if (pvVar2 != (void *)0x0) {
    CPfmCell::~CPfmCell(pvVar2,unaff_ESI);
    operator_delete(pvVar2);
    ExceptionList = (void *)0xffffffff;
    return;
  }
  ExceptionList = (void *)0xffffffff;
  return;
}
}

// =================================================
// Function: CPfmMesh::Clear
// =================================================
void __thiscall CPfmMesh::Clear(CPfmMesh *this,TiXmlNode *param_1)
{
{
  CPfmMesh *this_00;
  undefined4 *puVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  undefined4 *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  void *local_c;
  undefined4 *local_8;
  void *pvStack_4;
  
  pvStack_4 = (void *)0xffffffff;
  local_8 = (undefined4 *)&LAB_00aecd58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  this_00 = this + 4;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (this_00,(CFastBuffer<class_CCrystalFace*> *)
                              (DAT_00cca150 ^ (uint)&stack0xffffffe0));
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar4,(ulong)unaff_EDI);
      puVar1 = *(undefined4 **)pSVar3;
      local_8 = puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        unaff_EDI = puVar1 + 0x14;
        _eh_vector_destructor_iterator_(unaff_EDI,0x2c,3,(_func___cdecl_void_void_ptr *)unaff_EDI);
        local_c = (void *)0xffffffff;
        *puVar1 = CPfmPlane::vftable;
        operator_delete(puVar1);
      }
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  CFastBuffer<class_CSystemFidsFolder*>::SetCount
            (this_00,(CFastBuffer<class_CSystemFidsFolder*> *)0x0,(ulong)unaff_EDI);
  ExceptionList = pvStack_4;
  return;
}
}

// =================================================
// Function: CPfmMesh::LinkCells
// =================================================
void __thiscall CPfmMesh::LinkCells(CPfmMesh *this,CPfmMesh *param_1)
{
{
  CPfmMesh *this_00;
  GmVec3 *pGVar1;
  GmVec3 *this_01;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  int iVar4;
  GmVec3 *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  GmVec3 *unaff_ESI;
  GmVec3 *unaff_EDI;
  CPfmCell *in_stack_fffffff8;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *local_4;
  
  this_00 = this + 4;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  local_4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,local_4,(ulong)unaff_EDI);
      pGVar1 = *(GmVec3 **)pSVar3;
      pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
      do {
        unaff_EDI = (GmVec3 *)pCVar5;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar5,(ulong)unaff_ESI);
        this_01 = *(GmVec3 **)pSVar3;
        if (pGVar1 != this_01) {
          if (*(int *)(pGVar1 + 0xd4) == 0) {
            unaff_EDI = pGVar1 + 0x2c;
            unaff_ESI = pGVar1;
            iVar4 = CPfmCell::RequestLink
                              (this_01,(CPfmCell *)(pGVar1 + 0x20),unaff_EDI,pGVar1,
                               (CPfmCell *)unaff_EBX);
            if (iVar4 != 0) {
              *(GmVec3 **)(pGVar1 + 0xd4) = this_01;
              goto LAB_00a5afd0;
            }
          }
          if (*(int *)(pGVar1 + 0xd8) == 0) {
            unaff_ESI = pGVar1 + 0x38;
            unaff_EDI = pGVar1 + 0x2c;
            unaff_EBX = pGVar1;
            iVar4 = CPfmCell::RequestLink
                              (this_01,(CPfmCell *)unaff_EDI,unaff_ESI,pGVar1,in_stack_fffffff8);
            if (iVar4 != 0) {
              *(GmVec3 **)(pGVar1 + 0xd8) = this_01;
              goto LAB_00a5afd0;
            }
          }
          if (*(int *)(pGVar1 + 0xdc) == 0) {
            unaff_ESI = pGVar1 + 0x20;
            unaff_EDI = pGVar1 + 0x38;
            unaff_EBX = pGVar1;
            iVar4 = CPfmCell::RequestLink
                              (this_01,(CPfmCell *)unaff_EDI,unaff_ESI,pGVar1,in_stack_fffffff8);
            if (iVar4 != 0) {
              *(GmVec3 **)(pGVar1 + 0xdc) = this_01;
            }
          }
        }
LAB_00a5afd0:
        pCVar5 = pCVar5 + 1;
      } while (pCVar5 < pCVar2);
      local_4 = local_4 + 1;
    } while (local_4 < pCVar2);
  }
  return;
}
}

