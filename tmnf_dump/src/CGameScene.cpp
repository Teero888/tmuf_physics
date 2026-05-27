// Class implementation: CGameScene

// =================================================
// Function: CGameScene::GameMobilGetFromId
// =================================================
CGameMobil * __thiscall
CGameScene::GameMobilGetFromId(CGameScene *this,CGameScene *param_1,ulong param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x1c,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x1c,pCVar3,unaff_ESI);
      if (*(ulong *)(*(CGameMobil **)pSVar2 + 0x18) == param_2) {
        return *(CGameMobil **)pSVar2;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return (CGameMobil *)0x0;
}
}

// =================================================
// Function: CGameScene::GameMobilRemove
// =================================================
void __thiscall
CGameScene::GameMobilRemove(CGameScene *this,CGameScene *param_1,CGameMobil *param_2)
{
{
  int iVar1;
  SNewTriangleVert *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  undefined4 uStack0000000c;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(iVar1 + 0x24) + 0xa0))(iVar1);
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  pSVar2 = CFastBuffer<class_CClassicBufferMemory*>::GetLastElem(this + 0x1c,unaff_EDI);
  *(undefined4 *)(*(int *)pSVar2 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  CFastBufferRef<class_CGameMobil>::ReplaceByLastAt
            (this + 0x1c,*(CFastBufferRef<class_CGameMobil> **)(param_1 + 0x1c),1,unaff_ESI);
  uStack0000000c = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
                    /* WARNING: Could not recover jumptable at 0x005da53d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(this + 0x14) + 0x7c))();
  return;
}
}

