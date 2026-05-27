// Class implementation: CGamePlayground

// =================================================
// Function: CGamePlayground::CGamePlayground
// =================================================
void __thiscall CGamePlayground::CGamePlayground(CGamePlayground *this,CGamePlayground *param_1)
{
{
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CGameNod *unaff_EDI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CGameNod::CGameNod((CGameNod *)this,unaff_EDI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x24,unaff_ESI);
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x38,unaff_retaddr);
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 1;
  this[0x1c] = (CGamePlayground)0xff;
  return;
}
}

// =================================================
// Function: CGamePlayground::Clean
// =================================================
void __thiscall CGamePlayground::Clean(CGamePlayground *this,CHmsOcclusion *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44),unaff_EDI);
    *(undefined4 *)(this + 0x44) = 0;
  }
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),unaff_ESI);
    *(undefined4 *)(this + 0x30) = 0;
  }
  if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x34),unaff_ESI);
    *(undefined4 *)(this + 0x34) = 0;
  }
  *(undefined4 *)(this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: CGamePlayground::CommonSwitchFrom
// =================================================
void __thiscall CGamePlayground::CommonSwitchFrom(CGamePlayground *this,CGamePlayground *param_1)
{
{
  if (*(int **)(this + 0x44) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005e3b0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(this + 0x44) + 0x7c))();
    return;
  }
  return;
}
}

// =================================================
// Function: CGamePlayground::GetPlayerNumber
// =================================================
ulong __thiscall
CGamePlayground::GetPlayerNumber(CGamePlayground *this,CGamePlayground *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x24,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x24,pCVar3,unaff_ESI);
      if (*(byte *)(*(int *)pSVar2 + 0x2c) == param_2) {
        return (ulong)pCVar3;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0xffffffff;
}
}

// =================================================
// Function: CGamePlayground::UpdateFromSettings
// =================================================
int __thiscall
CGamePlayground::UpdateFromSettings
          (CGamePlayground *this,CGamePlayground *param_1,CFastString *param_2,int param_3)
{
{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  TiXmlElement *this_00;
  undefined **ppuVar4;
  int iVar5;
  undefined *puVar6;
  char *unaff_EBX;
  TiXmlNode *unaff_ESI;
  TiXmlEncoding unaff_EDI;
  void *unaff_retaddr;
  SStringParam *in_stack_ffffff84;
  undefined *puStack_6c;
  undefined *local_64;
  undefined4 local_60;
  undefined *local_5c;
  undefined **local_58;
  int local_54;
  undefined **local_50 [9];
  char local_2c;
  undefined4 *local_24;
  undefined4 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  void *local_8;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00aa2438;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  TiXmlDocument::TiXmlDocument
            ((TiXmlDocument *)&local_60,(TiXmlDocument *)(DAT_00cca150 ^ (uint)&stack0xffffff78));
  local_8 = (void *)0x0;
  TiXmlDocument::Parse
            ((TiXmlDocument *)&local_5c,*(TiXmlDeclaration **)(param_1 + 4),(char *)0x0,
             (TiXmlParsingData *)0x0,unaff_EDI);
  if (local_2c == '\0') {
    this_00 = TiXmlNode::FirstChildElement((TiXmlNode *)&local_58,unaff_ESI,unaff_EBX);
    puVar2 = local_24;
    puVar3 = local_1c;
    while (local_24 = puVar3, this_00 != (TiXmlElement *)0x0) {
      local_60 = 0;
      local_58 = (undefined **)(*(int *)(this_00 + 0x20) + 8);
      if (local_58 == (undefined **)0x0) {
        local_54 = 0;
      }
      else {
        ppuVar4 = local_58;
        do {
          cVar1 = *(char *)ppuVar4;
          ppuVar4 = (undefined **)((int)ppuVar4 + 1);
        } while (cVar1 != '\0');
        local_54 = (int)ppuVar4 - (*(int *)(this_00 + 0x20) + 9);
      }
      local_64 = PTR_DAT_00bbf7d8;
      local_5c = PTR_DAT_00bbf7d8;
      local_1c = local_24;
      CFastString::SetString((CFastString *)&local_60,(CFastStringInt *)&local_58,in_stack_ffffff84)
      ;
      local_24 = puVar2;
      CXmlEngine::ReadAssociatedText(this_00,(CFastStringInt *)&local_64);
      ppuVar4 = &local_64;
      unaff_ESI = (TiXmlNode *)&local_5c;
      in_stack_ffffff84 = (SStringParam *)param_2;
      iVar5 = (**(code **)(*(int *)this + 0xa8))();
      if (iVar5 == 0) {
        if (puStack_6c != PTR_DAT_00bbf7d8) {
          puVar6 = puStack_6c + -1;
          if ((puStack_6c[-1] & 0x80) != 0) {
            puVar6 = puStack_6c + -4;
          }
          operator_delete__(puVar6);
        }
        if (local_64 != PTR_DAT_00bbf7d8) {
          puVar6 = local_64 + -1;
          if ((local_64[-1] & 0x80) != 0) {
            puVar6 = local_64 + -4;
          }
          operator_delete__(puVar6);
          local_64 = PTR_DAT_00bbf7d8;
        }
        goto LAB_005e3e27;
      }
      this_00 = TiXmlNode::NextSiblingElement((TiXmlNode *)this_00,unaff_ESI,(char *)ppuVar4);
      if (local_64 != PTR_DAT_00bbf7d8) {
        puVar6 = local_64 + -1;
        if ((local_64[-1] & 0x80) != 0) {
          puVar6 = local_64 + -4;
        }
        operator_delete__(puVar6);
        local_64 = PTR_DAT_00bbf7d8;
      }
      puVar2 = local_24;
      puVar3 = local_1c;
      if (local_5c != PTR_DAT_00bbf7d8) {
        puVar6 = local_5c + -1;
        if ((local_5c[-1] & 0x80) != 0) {
          puVar6 = local_5c + -4;
        }
        operator_delete__(puVar6);
        local_60 = 0;
        local_5c = PTR_DAT_00bbf7d8;
        puVar2 = local_24;
        puVar3 = local_1c;
      }
    }
    local_50[0] = TiXmlDocument::vftable;
  }
  else {
    local_58 = TiXmlDocument::vftable;
    if (*(int *)param_1 == 0) {
LAB_005e3e27:
      local_58 = TiXmlDocument::vftable;
      if (local_24 != &DAT_00d72f38) {
        operator_delete__(local_24);
      }
      TiXmlNode::~TiXmlNode((TiXmlNode *)&local_58,unaff_ESI);
      ExceptionList = local_8;
      return 0;
    }
  }
  if (local_24 != &DAT_00d72f38) {
    operator_delete__(local_24);
  }
  TiXmlNode::~TiXmlNode((TiXmlNode *)local_50,(TiXmlNode *)in_stack_ffffff84);
  ExceptionList = unaff_retaddr;
  return 1;
}
}

// =================================================
// Function: CGamePlayground::VirtualParam_Get
// =================================================
ulong __thiscall
CGamePlayground::VirtualParam_Get
          (CGamePlayground *this,CPlugBlendShapes *param_1,CMwStack *param_2,CMwValueStd *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwNod *this_00;
  CMwValueStd *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x300d000) {
    if (iVar1 + -1 < 0) {
      this_00 = (CMwNod *)(**(code **)(*(int *)this + 0x94))();
    }
    else {
      this_00 = (CMwNod *)(**(code **)(*(int *)this + 0x94))();
      if (-1 < *(int *)(param_1 + 0x18)) {
        CMwNod::Param_Get(this_00,(CMwNod *)param_1,param_2,unaff_ESI);
        return 0;
      }
    }
    *(CMwNod **)param_2 = this_00;
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Get((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CGamePlayground::VirtualParam_Set
// =================================================
ulong __thiscall
CGamePlayground::VirtualParam_Set
          (CGamePlayground *this,CSystemData *param_1,CMwStack *param_2,void *param_3)
{
{
  int iVar1;
  int iVar2;
  ulong uVar3;
  CMwNod *this_00;
  CFastStringInt *unaff_ESI;
  
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + iVar1 * 4);
  *(int *)(param_1 + 0x18) = iVar1 + -1;
  iVar2 = *(int *)(iVar2 + 4);
  if (iVar2 == 0x300d000) {
    if (-1 < iVar1 + -1) {
      this_00 = (CMwNod *)(**(code **)(*(int *)this + 0x94))();
      if (-1 < *(int *)(param_1 + 0x18)) {
        CMwNod::Param_Set(this_00,(CMwNod *)param_1,(CFastString *)param_2,unaff_ESI);
      }
    }
  }
  else if (iVar2 != -1) {
    *(int *)(param_1 + 0x18) = iVar1;
    uVar3 = CMwNod::VirtualParam_Set((CMwNod *)this,param_1,param_2,unaff_ESI);
    return uVar3;
  }
  return 0;
}
}

// =================================================
// Function: CGamePlayground::~CGamePlayground
// =================================================
void __thiscall CGamePlayground::~CGamePlayground(CGamePlayground *this,CGamePlayground *param_1)
{
{
  CMwNod *pCVar1;
  CFastBuffer<class_CPlugFileGPUV*> *unaff_ESI;
  void *in_stack_00000008;
  undefined4 uStack0000000c;
  CGamePlayground *pCVar2;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  CGameNod *pCVar4;
  
  pCVar3 = ExceptionList;
  pCVar4 = (CGameNod *)&LAB_00aa2394;
  pCVar1 = (CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  pCVar2 = this;
  if (*(CMwNod **)(this + 0x44) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x44),pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x38,unaff_ESI);
  if (*(CMwNod **)(this + 0x34) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x34),(CMwNod *)pCVar2);
  }
  in_stack_00000008 = (void *)CONCAT31(in_stack_00000008._1_3_,1);
  if (*(CMwNod **)(this + 0x30) != (CMwNod *)0x0) {
    CMwNod::MwRelease(*(CMwNod **)(this + 0x30),(CMwNod *)pCVar3);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(this + 0x24,pCVar3);
  uStack0000000c = 0xffffffff;
  CGameNod::~CGameNod((CGameNod *)this,pCVar4);
  ExceptionList = in_stack_00000008;
  return;
}
}

