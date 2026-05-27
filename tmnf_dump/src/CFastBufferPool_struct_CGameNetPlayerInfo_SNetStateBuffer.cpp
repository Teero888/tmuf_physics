// Class implementation: CFastBufferPool_struct_CGameNetPlayerInfo_SNetStateBuffer

// =================================================
// Function: CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SetSize
// =================================================
void __thiscall
CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SetSize
          (CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this,CMwStatsValue *param_1,
          ulong param_2)
{
{
  CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer> *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  ulong uVar3;
  SCasterCat *pSVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  ulong unaff_EDI;
  ulong unaff_retaddr;
  
  this_00 = this + 4;
  CFastBuffer<struct_CFastBufferPool<struct_CGameNetPlayerInfo::SNetStateBuffer>::SElem>::
  AllocSetCount(this_00,(CFastBuffer<class_GxVertex2> *)param_1,unaff_ESI);
  uVar3 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar3 - 1);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pCVar2 = pCVar5 + 1;
      pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](this_00,pCVar5,unaff_EDI);
      *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)(pSVar4 + 0x2c) = pCVar2;
      pCVar5 = pCVar2;
    } while (pCVar2 < pCVar1);
  }
  pSVar4 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>::
           operator[](this_00,pCVar1,unaff_retaddr);
  *(undefined4 *)(pSVar4 + 0x2c) = 0xffffffff;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}
}

