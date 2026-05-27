// Class implementation: CSystemFid_SCallStackFidContext

// =================================================
// Function: CSystemFid::SCallStackFidContext::SCallStackFidContext
// =================================================
void __thiscall
CSystemFid::SCallStackFidContext::SCallStackFidContext
          (void *this,SCallStackFidContext *param_1,CSystemFid *param_2)
{
{
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  TiXmlAttribute *unaff_EBX;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  *(undefined4 *)this = 0xffffffff;
  *(undefined4 *)((int)this + 4) = 0;
  if ((param_1 != (SCallStackFidContext *)0x0) &&
     ((uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55460,unaff_EDI), uVar1 == 0 ||
      (pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(&DAT_00d55460,unaff_ESI),
      *(SCallStackFidContext **)pSVar2 != param_1)))) {
    *(ulong *)this = uVar1;
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (&DAT_00d55460,(TiXmlAttributeSet *)&stack0x0000000c,unaff_EBX);
    *(SCallStackFidContext **)((int)this + 4) = param_1;
  }
  return;
}
}

// =================================================
// Function: CSystemFid::SCallStackFidContext::~SCallStackFidContext
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemFid::SCallStackFidContext::~SCallStackFidContext(void *this,SCallStackFidContext *param_1)
{
{
  int iVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  
  iVar1 = *(int *)this;
  if ((iVar1 != -1) && (*(int *)((int)this + 4) != 0)) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount(&DAT_00d55460,unaff_ESI);
    if (uVar2 == iVar1 + 1U) {
      _DAT_00d55460 = _DAT_00d55460 + -1;
    }
  }
  return;
}
}

