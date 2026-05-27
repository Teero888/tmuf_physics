// Class implementation: CDx9VertexShader

// =================================================
// Function: CDx9VertexShader::FilterSetVertexShader
// =================================================
int __cdecl CDx9VertexShader::FilterSetVertexShader(CDx9VertexShader *param_1)
{
{
  int iVar1;
  ulong uVar2;
  CFastBuffer<class_CCrystalFace*> *pCVar3;
  
  if (param_1 != (CDx9VertexShader *)0x0) {
    iVar1 = UndirtyAndSetVertexShader(param_1,param_1);
    return iVar1;
  }
  pCVar3 = DAT_00d75af8;
  (**(code **)(*(int *)DAT_00d75af8 + 0x170))(DAT_00d75af8,0);
  if (DAT_00d75b00 != 0) {
    uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d75afc + 0x46c),pCVar3);
    if (uVar2 != 0) {
      UpdateClipPlaneEqs();
    }
  }
  DAT_00d75b00 = 0;
  return 1;
}
}

// =================================================
// Function: CDx9VertexShader::UndirtyAndSetVertexShader
// =================================================
int __thiscall CDx9VertexShader::UndirtyAndSetVertexShader(void *this,CDx9VertexShader *param_1)
{
{
  int iVar1;
  ulong uVar2;
  SNewTriangleVert *pSVar3;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *pSVar5;
  GmIso4 *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar6;
  CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *unaff_EDI;
  undefined4 *puVar7;
  CFastBuffer<class_CCrystalFace*> *pCVar8;
  undefined4 *puVar9;
  CFastBuffer<class_CCrystalFace*> *pCVar10;
  SPlugFaceCull *pSVar11;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_4c [4];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (*(int *)((int)this + 4) == 0) {
    Create(this,(CDx9VertexBuffer *)0x1);
  }
  pSVar11 = *(SPlugFaceCull **)((int)this + 4);
  pCVar8 = DAT_00d75af8;
  (**(code **)(*(int *)DAT_00d75af8 + 0x170))();
  iVar1 = DAT_00d75afc;
  uVar2 = CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d75afc + 0x46c),pCVar8);
  if (uVar2 == 0) {
    DAT_00d75b00 = this;
    return 1;
  }
  pSVar3 = CFastBuffer<struct_SHmsCameraProjection>::GetLastElem((void *)(iVar1 + 0x478),unaff_EDI);
  pSVar3 = CFastBuffer<struct_SHmsCameraLocation>::GetLastElem
                     ((void *)(iVar1 + 0x454),
                      (CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *)
                      pSVar3);
  GmMat4::SetMult(auStack_4c,(SPlugFaceCull *)pSVar3,pSVar11,unaff_ESI);
  uStack_98 = uStack_48;
  uStack_94 = uStack_38;
  uStack_90 = uStack_28;
  uStack_8c = uStack_18;
  uStack_88 = uStack_44;
  uStack_84 = uStack_34;
  uStack_80 = uStack_24;
  uStack_7c = uStack_14;
  uStack_78 = uStack_40;
  uStack_74 = uStack_30;
  uStack_70 = uStack_20;
  uStack_6c = uStack_10;
  uStack_68 = uStack_3c;
  uStack_64 = uStack_2c;
  uStack_60 = uStack_1c;
  uStack_5c = uStack_c;
  func_0x009f0ab8(&uStack_98,0,&uStack_98);
  pCVar8 = (CFastBuffer<class_CCrystalFace*> *)&stack0xffffff5c;
  pCVar10 = pCVar8;
  _D3DXMatrixTranspose_8();
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d75afc + 0x46c),pCVar8);
  pCVar6 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar4 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar5 = CFastBuffer<class_GxColor>::operator[]
                         ((void *)(DAT_00d75afc + 0x46c),pCVar6,(ulong)pCVar10);
      uStack_64 = *(undefined4 *)pSVar5;
      pCVar10 = (CFastBuffer<class_CCrystalFace*> *)&stack0xffffff5c;
      uStack_60 = *(undefined4 *)(pSVar5 + 4);
      puVar7 = &uStack_14;
      uStack_5c = *(undefined4 *)(pSVar5 + 8);
      uStack_58 = *(undefined4 *)(pSVar5 + 0xc);
      puVar9 = &uStack_64;
      _D3DXPlaneTransform_12();
      (**(code **)(*(int *)DAT_00d75af8 + 0xdc))(DAT_00d75af8,pCVar6,&uStack_20,puVar7,puVar9);
      pCVar6 = pCVar6 + 1;
    } while (pCVar6 < pCVar4);
  }
  DAT_00d75b00 = this;
  return 1;
}
}

// =================================================
// Function: CDx9VertexShader::UpdateClipPlaneEqs
// =================================================
void __cdecl CDx9VertexShader::UpdateClipPlaneEqs(void)
{
{
  int iVar1;
  int *piVar2;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  SCasterCat *unaff_EDI;
  
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(DAT_00d75afc + 0x46c),unaff_ESI);
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      piVar2 = DAT_00d75af8;
      iVar1 = *DAT_00d75af8;
      unaff_EDI = CFastBuffer<class_GxColor>::operator[]
                            ((void *)(DAT_00d75afc + 0x46c),pCVar4,(ulong)unaff_EDI);
      (**(code **)(iVar1 + 0xdc))(piVar2,pCVar4);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar3);
  }
  return;
}
}

