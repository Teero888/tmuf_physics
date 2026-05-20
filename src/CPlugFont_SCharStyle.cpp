// Class implementation: CPlugFont_SCharStyle

// =================================================
// Function: CPlugFont::SCharStyle::Init
// =================================================
void __thiscall
CPlugFont::SCharStyle::Init
          (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  undefined4 uVar1;
  TiXmlAttribute *unaff_ESI;
  GmFrustumIso4 *unaff_EDI;
  
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)((int)this + 8) = *(undefined4 *)(param_1 + 8);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(uint *)((int)this + 0x14) = *(uint *)((int)this + 0x14) | 1;
  *(undefined4 *)((int)this + 0xc) = uVar1;
  *(uint *)((int)this + 0x10) = *(uint *)((int)this + 0x10) & 0xffffe010 | 0x10;
  CFastBuffer<struct_CSceneToySeaHouleTable::SImageHF>::Reset((void *)((int)this + 0x1c),unaff_EDI);
  CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::Add((void *)((int)this + 0x1c),this,unaff_ESI);
  *(undefined4 *)((int)this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: CPlugFont::SCharStyle::Pop
// =================================================
void __thiscall CPlugFont::SCharStyle::Pop(void *this,SCharStyle *param_1)
{
{
  void *this_00;
  ulong uVar1;
  SNewTriangleVert *pSVar2;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  ulong unaff_retaddr;
  
  this_00 = (void *)((int)this + 0x1c);
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (1 < uVar1) {
    pSVar2 = CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::GetLastElem(this_00,unaff_ESI);
    *(undefined4 *)this = *(undefined4 *)pSVar2;
    *(undefined4 *)((int)this + 4) = *(undefined4 *)(pSVar2 + 4);
    *(undefined4 *)((int)this + 8) = *(undefined4 *)(pSVar2 + 8);
    *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(pSVar2 + 0xc);
    *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(pSVar2 + 0x10);
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this_00,(CFastBuffer<class_CCrystalFace*> *)0x1);
    CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod>::RemoveAt
              (this_00,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)(uVar1 - 1),
               unaff_retaddr,(ulong)param_1);
  }
  return;
}
}

// =================================================
// Function: CPlugFont::SCharStyle::Push
// =================================================
void __thiscall
CPlugFont::SCharStyle::Push(void *this,CFastBufferWheel<float> *param_1,float *param_2)
{
{
  TiXmlAttribute *unaff_retaddr;
  
  CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::Add
            ((void *)((int)this + 0x1c),this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CPlugFont::SCharStyle::SCharStyle
// =================================================
void __thiscall CPlugFont::SCharStyle::SCharStyle(void *this,SCharStyle *param_1)
{
{
  CPlugVisualSprite *unaff_ESI;
  CLoadGeomDynaSprite *in_stack_00000008;
  CVisionViewportDx9 *pCVar1;
  ESpriteColor0 *pEVar2;
  
  pEVar2 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  pCVar1 = this;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            ((void *)((int)this + 0x1c),
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  Init(this,in_stack_00000008,unaff_ESI,pCVar1,pEVar2);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CPlugFont::SCharStyle::~SCharStyle
// =================================================
void __thiscall CPlugFont::SCharStyle::~SCharStyle(void *this,SCharStyle *param_1)
{
{
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            ((void *)((int)this + 0x1c),(CFastBuffer<class_CPlugFileGPUV*> *)param_1);
  return;
}
}

