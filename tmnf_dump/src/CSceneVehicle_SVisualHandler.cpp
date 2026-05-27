// Class implementation: CSceneVehicle_SVisualHandler

// =================================================
// Function: CSceneVehicle::SVisualHandler::Init
// =================================================
void __thiscall
CSceneVehicle::SVisualHandler::Init
          (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  int iVar3;
  int unaff_ESI;
  undefined4 *puVar4;
  GmMat43 *unaff_EDI;
  undefined4 *puVar5;
  
  *(undefined4 *)((int)this + 0x68) = *(undefined4 *)(param_2 + 4);
  iVar1 = SolidGetTargetFromId((CMwId *)param_2,(CPlugSolid *)param_1,this);
  if (iVar1 == 0) {
    GmIso4::SetIdentity((void *)((int)this + 8),unaff_EDI);
  }
  else {
    iVar1 = *(int *)this;
    if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4) ==
        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      pSVar2 = (SCasterCat *)(iVar1 + 0x5c);
    }
    else {
      pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](*(void **)(iVar1 + 0xa4),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4),
                            (ulong)unaff_EDI);
      iVar1 = *(int *)this;
    }
    puVar4 = (undefined4 *)((int)this + 8);
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *(undefined4 *)pSVar2;
      pSVar2 = pSVar2 + 4;
      puVar4 = puVar4 + 1;
    }
    if ((*(byte *)(iVar1 + 0x9c) & 0x80) != 0) {
      *(uint *)(iVar1 + 0x9c) = *(uint *)(iVar1 + 0x9c) & 0xffffff7f;
    }
    if ((*(int *)((int)this + 4) == -1) && (((byte)(*(CPlugTree **)this)[0x9c] & 4) == 0)) {
      CPlugTree::SetUseLocation(*(CPlugTree **)this,(CPlugTree *)0x1,unaff_ESI);
      puVar4 = (undefined4 *)((int)this + 8);
      puVar5 = (undefined4 *)((int)this + 0x38);
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      return;
    }
  }
  puVar4 = (undefined4 *)((int)this + 8);
  puVar5 = (undefined4 *)((int)this + 0x38);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SVisualHandler::IsInit
// =================================================
int __thiscall CSceneVehicle::SVisualHandler::IsInit(void *this,SVisualHandler *param_1)
{
{
  return (uint)(*(int *)this != 0);
}
}

// =================================================
// Function: CSceneVehicle::SVisualHandler::Reset
// =================================================
void __thiscall CSceneVehicle::SVisualHandler::Reset(void *this,GmFrustumIso4 *param_1)
{
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)((int)this + 8);
  puVar3 = (undefined4 *)((int)this + 0x38);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}
}

// =================================================
// Function: CSceneVehicle::SVisualHandler::SVisualHandler
// =================================================
void __thiscall CSceneVehicle::SVisualHandler::SVisualHandler(void *this,SVisualHandler *param_1)
{
{
  GmMat43 *unaff_ESI;
  GmMat43 *unaff_retaddr;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  GmIso4::SetIdentity((void *)((int)this + 8),unaff_ESI);
  GmIso4::SetIdentity((void *)((int)this + 0x38),unaff_retaddr);
  *(undefined4 *)((int)this + 0x68) = 0;
  return;
}
}

// =================================================
// Function: CSceneVehicle::SVisualHandler::UpdateVisual
// =================================================
void __thiscall CSceneVehicle::SVisualHandler::UpdateVisual(void *this,SVisualHandler *param_1)
{
{
  int iVar1;
  SCasterCat *pSVar2;
  SVisualHandler *unaff_ESI;
  undefined4 *puVar3;
  ulong unaff_EDI;
  GmIso4 *unaff_retaddr;
  
  iVar1 = IsInit(this,unaff_ESI);
  if (iVar1 != 0) {
    if (*(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4) !=
        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
      pSVar2 = CFastBuffer<struct_CFastBufferKey<struct_CCtnMediaBlockEventTrackMania::SEvent>::SKey>
               ::operator[](*(void **)(*(int *)this + 0xa4),
                            *(CFastBuffer<struct_CVisionHmsZone::SCasterCat> **)((int)this + 4),
                            unaff_EDI);
      puVar3 = (undefined4 *)((int)this + 0x38);
      for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
        *(undefined4 *)pSVar2 = *puVar3;
        puVar3 = puVar3 + 1;
        pSVar2 = pSVar2 + 4;
      }
      return;
    }
    CPlugTree::SetLocation(*(CPlugTree **)this,(CPlugTree *)((int)this + 0x38),unaff_retaddr);
  }
  return;
}
}

