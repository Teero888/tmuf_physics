// Class implementation: CGameNetPlayerInfo

// =================================================
// Function: CGameNetPlayerInfo::CGameNetPlayerInfo
// =================================================
void __thiscall
CGameNetPlayerInfo::CGameNetPlayerInfo(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1)
{
{
  ulong uVar1;
  SStringParam *unaff_EBX;
  SStringParam *unaff_ESI;
  CMwNod *unaff_EDI;
  undefined1 uStack00000008;
  undefined1 uStack0000000c;
  undefined1 uStack00000010;
  void *in_stack_00000020;
  undefined1 uStack00000024;
  CClassicBufferMemory *in_stack_ffffffe0;
  CMwId *in_stack_ffffffe4;
  char *pcVar2;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar3;
  CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *in_stack_fffffff0;
  CFastBuffer<class_CPlugFileSndGen*> *pCVar4;
  undefined1 *puVar5;
  
  pCVar4 = ExceptionList;
  ExceptionList = &stack0xfffffff4;
  CMwNod::CMwNod((CMwNod *)this,(CMwNod *)(DAT_00cca150 ^ (uint)&stack0xffffffd4),unaff_EDI);
  *(undefined ***)this = vftable;
  pcVar2 = "Unnamed";
  pCVar3 = (CFastBuffer<class_CPlugFileSndGen*> *)&DAT_00000007;
  CFastStringInt::CFastStringInt(this + 0x14,(CFastStringInt *)&stack0xffffffe8,unaff_ESI);
  uStack00000008 = 1;
  puVar5 = &DAT_00b2c878;
  CFastStringInt::CFastStringInt(this + 0x1c,(CFastStringInt *)&stack0xfffffff8,unaff_EBX);
  *(undefined4 *)(this + 0x24) = 0xff;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined **)(this + 0x2c) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined **)(this + 0x38) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined **)(this + 0x44) = PTR_DAT_00bbf7d8;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  uStack0000000c = 6;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 0;
  *(undefined4 *)(this + 0x90) = 1;
  *(undefined4 *)(this + 0x94) = 0;
  CClassicBufferMemory::CClassicBufferMemory
            ((CClassicBufferMemory *)(this + 0x98),in_stack_ffffffe0);
  uStack00000010 = 7;
  *(undefined4 *)(this + 0xb8) = 2;
  *(undefined4 *)(this + 0xbc) = 0;
  CMwId::CMwId(this + 0xc0,in_stack_ffffffe4);
  *(undefined4 *)(this + 0xc4) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 200,(CFastBuffer<class_CPlugFileSndGen*> *)pcVar2);
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0xd8) = 0;
  *(undefined4 *)(this + 0xdc) = 0;
  *(undefined4 *)(this + 0xe0) = 0;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0xe4,pCVar3);
  CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::
  CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>
            ((CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *)(this + 0xf0),
             in_stack_fffffff0);
  *(undefined4 *)(this + 0x124) = 0;
  *(undefined4 *)(this + 0x128) = 0x100000;
  *(undefined4 *)(this + 300) = 0x10000;
  *(undefined2 *)(this + 0x130) = 2;
  *(undefined2 *)(this + 0x132) = 0;
  *(undefined4 *)(this + 0x134) = 0x100007f;
  *(undefined2 *)(this + 0x140) = 0;
  *(undefined4 *)(this + 0x144) = 0;
  *(undefined4 *)(this + 0x148) = 0;
  *(undefined4 *)(this + 0x14c) = 0;
  *(undefined4 *)(this + 0x150) = 1;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(this + 0x168,pCVar4);
  uStack00000024 = 0xc;
  *(undefined4 *)(this + 0x174) = 0xffffffff;
  *(undefined4 *)(this + 0x154) = 0;
  *(undefined4 *)(this + 0x158) = 0;
  *(undefined4 *)(this + 0x15c) = 0;
  *(undefined4 *)(this + 0x160) = 0;
  *(undefined4 *)(this + 0x164) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  this[0x78] = (CGameNetPlayerInfo)0xff;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x114) = 0;
  *(undefined4 *)(this + 0x118) = 0;
  *(undefined4 *)(this + 0x11c) = 0;
  *(undefined4 *)(this + 0x120) = 0xffffffff;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  uVar1 = CSystemEngine::GetExeCheckSum();
  *(ulong *)(this + 0x108) = uVar1;
  *(undefined4 *)(this + 0x10c) = DAT_00d54230;
  *(undefined4 *)(this + 0x110) = DAT_00d54228;
  CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SetSize
            ((CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *)(this + 0xf0),
             (CMwStatsValue *)&DAT_00000014,(ulong)puVar5);
  ExceptionList = in_stack_00000020;
  return;
}
}

// =================================================
// Function: CGameNetPlayerInfo::IsSpectator
// =================================================
int __thiscall CGameNetPlayerInfo::IsSpectator(CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1)
{
{
  if ((*(int *)(this + 0x70) == 0) && (*(int *)(this + 0x74) == 0)) {
    return 0;
  }
  return 1;
}
}

// =================================================
// Function: CGameNetPlayerInfo::RemoveNetStateSending
// =================================================
void __thiscall
CGameNetPlayerInfo::RemoveNetStateSending
          (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2)
{
{
  CGameNetPlayerInfo *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  this_00 = this + 0x168;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    while (pSVar2 = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                              (this_00,pCVar3,unaff_EBX), pSVar2[8] != (SCasterCat)param_2) {
      pCVar3 = pCVar3 + 1;
      if (pCVar1 <= pCVar3) {
        return;
      }
    }
    CFastBuffer<struct_CHmsCameraFx::SBitmapOutput>::ReplaceByLastAt
              (this_00,(CFastBufferRef<class_CGameMobil> *)pCVar3,1,unaff_ESI);
  }
  return;
}
}

// =================================================
// Function: CGameNetPlayerInfo::SetDirty
// =================================================
void __thiscall
CGameNetPlayerInfo::SetDirty(CGameNetPlayerInfo *this,CPlugVertexStream *param_1,int param_2)
{
{
  *(undefined4 *)(this + 0x150) = 1;
  return;
}
}

// =================================================
// Function: CGameNetPlayerInfo::SetGeneratedPlayerUId
// =================================================
void __thiscall
CGameNetPlayerInfo::SetGeneratedPlayerUId
          (CGameNetPlayerInfo *this,CGameNetPlayerInfo *param_1,uchar param_2)
{
{
  CGameNetPlayerInfo *unaff_retaddr;
  
  this[0x24] = SUB41(param_1,0);
  *(undefined4 *)(this + 100) = 1;
  CGamePlayerUIdAllocator::AssociatePlayerInfo
            (&DAT_00d6a358,(CGamePlayerUIdAllocator *)param_1,(uchar)this,unaff_retaddr);
  return;
}
}

