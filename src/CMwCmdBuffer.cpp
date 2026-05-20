// Class implementation: CMwCmdBuffer

// =================================================
// Function: CMwCmdBuffer::AddCmd
// =================================================
void __thiscall CMwCmdBuffer::AddCmd(CMwCmdBuffer *this,CMwCmdBuffer *param_1,CMwCmd *param_2)
{
{
  CMwCmdBuffer *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  SCasterCat *pSVar3;
  CMwNod *unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CMwNod *in_stack_0000000c;
  
  if (((byte)param_1[0x18] & 2) == 0) {
    this_00 = this + 0x20;
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x1;
    if (1 < uVar1) {
      do {
        pSVar2 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar5,(ulong)unaff_ESI);
        unaff_ESI = pCVar4;
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar4,(ulong)unaff_EBX);
        if (*(uint *)(pSVar2 + 4) < *(uint *)(pSVar3 + 4)) {
          pCVar4 = pCVar5;
        }
        pCVar5 = pCVar5 + 1;
        this = (CMwCmdBuffer *)param_2;
      } while (pCVar5 < param_1);
    }
    CFastBufferCat<class_CNetHttpResult*,struct_SFastCat>::AddInCat
              (this_00,(CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat> *)
                       &param_2,(CHmsCorpus **)pCVar4,(ulong)unaff_ESI);
    CMwNod::MwAddRef(in_stack_0000000c,unaff_EBX);
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
  }
  return;
}
}

// =================================================
// Function: CMwCmdBuffer::CMwCmdBuffer
// =================================================
void __thiscall CMwCmdBuffer::CMwCmdBuffer(CMwCmdBuffer *this,CMwCmdBuffer *param_1)
{
{
  ulong unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  CMwCmdBuffer *pCVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae5983;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = this;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffe8),unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat>::CFastBufferCat<class_CMwCmd*,struct_SFastCat>
            (this + 0x20,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)&DAT_0000000a,10,unaff_ESI
            );
  uStack00000008 = 1;
  *(undefined4 *)(this + 0x1c) = 0;
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount
            (this + 0x20,
             (CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
              *)0x1,(ulong)pCVar1);
  *(undefined4 *)(this + 0x14) = 0xffffffff;
  *(undefined4 *)(this + 0x18) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 0;
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: CMwCmdBuffer::GetMwClassId
// =================================================
ulong __thiscall CMwCmdBuffer::GetMwClassId(CMwCmdBuffer *this,CControlStyle *param_1)
{
{
  return 0x101c000;
}
}

// =================================================
// Function: CMwCmdBuffer::MwGetClassInfo
// =================================================
CMwClassInfo * __thiscall CMwCmdBuffer::MwGetClassInfo(CMwCmdBuffer *this,CFuncSegment *param_1)
{
{
  return (CMwClassInfo *)&DAT_00d73b7c;
}
}

// =================================================
// Function: CMwCmdBuffer::MwIsKindOf
// =================================================
int __thiscall CMwCmdBuffer::MwIsKindOf(CMwCmdBuffer *this,CMwCmdAffectParam *param_1,ulong param_2)
{
{
  if (param_1 == (CMwCmdAffectParam *)0x101c000) {
    return 1;
  }
  return (uint)(param_1 == (CMwCmdAffectParam *)0x1001000);
}
}

// =================================================
// Function: CMwCmdBuffer::MwNewCMwCmdBuffer
// =================================================
CMwNod * __cdecl CMwCmdBuffer::MwNewCMwCmdBuffer(void)
{
{
  CMwCmdBuffer *pCVar1;
  CMwNod *extraout_EAX;
  CMwCmdBuffer *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae59db;
  local_c = ExceptionList;
  pCVar1 = (CMwCmdBuffer *)(DAT_00cca150 ^ (uint)&local_10);
  ExceptionList = &local_c;
  local_10 = operator_new(0x48);
  local_4 = 0;
  if (local_10 != (CMwCmdBuffer *)0x0) {
    CMwCmdBuffer(local_10,pCVar1);
    ExceptionList = local_8;
    return extraout_EAX;
  }
  ExceptionList = local_c;
  return (CMwNod *)0x0;
}
}

// =================================================
// Function: CMwCmdBuffer::Run
// =================================================
void __thiscall CMwCmdBuffer::Run(CMwCmdBuffer *this,CMwCmdExpStringConcat *param_1)
{
{
  CMwCmdBuffer *this_00;
  CMwNod *this_01;
  int iVar1;
  ulong uVar2;
  SCasterCat *pSVar3;
  SSamplerState *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBX;
  ulong unaff_EBP;
  ulong unaff_ESI;
  CMwCmdBuffer *pCVar6;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar7;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *in_stack_00000008;
  
  if (*(int *)(this + 0x44) != 0) {
    this_00 = this + 0x20;
    pCVar7 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBX);
    if (uVar2 != 0) {
      do {
        pCVar5 = pCVar7;
        pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this_00,pCVar7,(ulong)unaff_EDI);
        pCVar6 = (CMwCmdBuffer *)0x0;
        if (*(int *)(pSVar3 + 4) != 0) {
          do {
            pSVar4 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                               (this_00,(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                                         *)pCVar6,(ulong)pCVar7,(ulong)pCVar5);
            this_01 = *(CMwNod **)pSVar4;
            if ((*(uint *)(this_01 + 0x18) & 2) == 0) {
              pCVar6 = pCVar6 + 1;
            }
            else {
              *(uint *)(this_01 + 0x18) = *(uint *)(this_01 + 0x18) & 0xfffffffd;
              CMwNod::MwRelease(this_01,(CMwNod *)0x93e572);
              pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)pCVar6;
              unaff_EDI = pCVar7;
              CFastBufferCat<class_CMwCmd*,struct_SFastCat>::ReplaceByLastInCatAt
                        (this_00,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)pCVar6,
                         (ulong)pCVar7,unaff_ESI);
              in_stack_00000008 = in_stack_00000008 + -1;
            }
          } while (pCVar6 < this);
        }
        pCVar7 = pCVar7 + 1;
        pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                 CFastBuffer<class_CCrystalFace*>::GetCount
                           (this_00,(CFastBuffer<class_CCrystalFace*> *)pCVar5);
      } while (pCVar7 < pCVar5);
    }
    *(undefined4 *)(this + 0x44) = 0;
  }
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x18) = in_stack_00000008;
  pSVar3 = CFastBuffer<struct_SFastCat>::operator[](this + 0x20,in_stack_00000008,unaff_ESI);
  iVar1 = *(int *)(pSVar3 + 4);
  *(int *)(this + 0x1c) = iVar1;
  *(undefined4 *)(this + 0x14) = 0;
  if (iVar1 != 0) {
    do {
      pSVar4 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                         (this + 0x20,
                          *(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
                            **)(this + 0x14),(ulong)in_stack_00000008,unaff_EBP);
      unaff_EBP = 0x93e5d9;
      (**(code **)(**(int **)pSVar4 + 0x78))();
      *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
    } while (*(uint *)(this + 0x14) < *(uint *)(this + 0x1c));
  }
  return;
}
}

// =================================================
// Function: CMwCmdBuffer::SetCatCount
// =================================================
void __thiscall
CMwCmdBuffer::SetCatCount
          (CMwCmdBuffer *this,
          CFastBufferCat<struct_CPlugBitmap::SSpecularHighlight,struct_CPlugBitmap::SSpecularSubMapCat>
          *param_1,ulong param_2)
{
{
  CFastBufferCat<class_CPlugTree*,struct_SFastCat>::SetCatCount(this + 0x20,param_1,param_2);
  return;
}
}

// =================================================
// Function: CMwCmdBuffer::UnistallCmd
// =================================================
void __thiscall
CMwCmdBuffer::UnistallCmd(CMwCmdBuffer *this,CMwCmdBuffer *param_1,CMwCmd *param_2,int param_3)
{
{
  CMwCmdBuffer *this_00;
  CMwNod *this_01;
  SSamplerState *pSVar1;
  ulong unaff_EBX;
  CMwNod *unaff_EBP;
  ulong unaff_ESI;
  ulong *unaff_EDI;
  CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat>
  *unaff_retaddr;
  int in_stack_00000010;
  ulong local_8;
  CMwCmd *local_4;
  
  this_00 = this + 0x20;
  CFastBufferCat<class_CMwCmd*,struct_SFastCat>::FindIndexInAll
            (this_00,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)&param_1,&local_4,&local_8,
             unaff_EDI);
  pSVar1 = CFastBufferCat<class_CSceneMobil*,struct_SFastCat>::GetElemInCat
                     (this_00,unaff_retaddr,(ulong)local_4,unaff_ESI);
  this_01 = *(CMwNod **)pSVar1;
  if ((*(CFastBufferCat<struct_CDx9StateBlock::SSamplerState,struct_CDx9StateBlock::SSamplerCat> **)
        (this + 0x14) < unaff_retaddr) && (local_4 == *(CMwCmd **)(this + 0x18))) {
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
    *(uint *)(this_01 + 0x18) = *(uint *)(this_01 + 0x18) & 0xfffffffd;
    CMwNod::MwRelease(this_01,unaff_EBP);
    CFastBufferCat<class_CMwCmd*,struct_SFastCat>::ReplaceByLastInCatAt
              (this_00,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)unaff_retaddr,(ulong)local_4
               ,unaff_EBX);
    return;
  }
  if (in_stack_00000010 != 0) {
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
    *(uint *)(this_01 + 0x18) = *(uint *)(this_01 + 0x18) & 0xfffffffd;
    CMwNod::MwRelease(this_01,unaff_EBP);
    CFastBufferCat<class_CMwCmd*,struct_SFastCat>::ReplaceByLastInCatAt
              (this_00,(CFastBufferCat<class_CMwCmd*,struct_SFastCat> *)unaff_retaddr,(ulong)local_4
               ,unaff_EBX);
    *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
    return;
  }
  *(undefined4 *)(this + 0x44) = 1;
  return;
}
}

// =================================================
// Function: CMwCmdBuffer::VirtualParam_Get
// =================================================
ulong __thiscall
CMwCmdBuffer::VirtualParam_Get
          (CMwCmdBuffer *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x101c001) {
    uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,unaff_ESI);
    *(CMwValueStd **)param_3 = param_3 + 4;
    *(ulong *)(param_3 + 4) = uVar3;
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CMwCmdBuffer::_vector_deleting_destructor_
// =================================================
void * __thiscall
CMwCmdBuffer::_vector_deleting_destructor_
          (CMwCmdBuffer *this,CRpcCallInternal *param_1,uint param_2)
{
{
  CMwCmdBuffer *unaff_ESI;
  
  ~CMwCmdBuffer(this,unaff_ESI);
  if ((param_2 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
}

// =================================================
// Function: CMwCmdBuffer::~CMwCmdBuffer
// =================================================
void __thiscall CMwCmdBuffer::~CMwCmdBuffer(CMwCmdBuffer *this,CMwCmdBuffer *param_1)
{
{
  CMwCmdBuffer *this_00;
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CMwNod *unaff_EBX;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_EBP;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat> *unaff_EDI;
  void *in_stack_00000008;
  undefined4 uStack0000000c;
  ulong uVar5;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ae59b3;
  local_c = ExceptionList;
  pCVar1 = (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x2c,pCVar1);
  this_00 = this + 0x20;
  CFastBufferCat<class_CDx9VisualKeeper*,struct_SFastCat>::SetParsingAll(this_00,unaff_EDI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(this + 0x14) = pCVar2;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar5 = 0x93e3ef;
      pCVar6 = pCVar4;
      pSVar3 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar4,(ulong)unaff_ESI);
      unaff_ESI = (CFastBuffer<class_CPlugFileGPUV*> *)0x93e3fb;
      (**(code **)(**(int **)pSVar3 + 0x80))();
      pSVar3 = CFastBufferCat<class_CHmsCorpus*,struct_CVisionHmsZone::SCasterCat>::operator[]
                         (this_00,pCVar4,uVar5);
      CMwNod::MwRelease(*(CMwNod **)pSVar3,(CMwNod *)pCVar6);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar2);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x2c,unaff_ESI);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this_00,unaff_EBP);
  uStack0000000c = 0xffffffff;
  CMwNod::~CMwNod((CMwNod *)this,unaff_EBX);
  ExceptionList = in_stack_00000008;
  return;
}
}

