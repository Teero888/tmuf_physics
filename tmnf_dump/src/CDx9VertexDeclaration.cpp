// Class implementation: CDx9VertexDeclaration

// =================================================
// Function: CDx9VertexDeclaration::AddDeclarationStream
// =================================================
void __cdecl
CDx9VertexDeclaration::AddDeclarationStream
          (CFastBuffer<struct__D3DVERTEXELEMENT9> *param_1,ulong param_2,SStreamDecl param_3)
{
{
  undefined2 uVar1;
  undefined4 uVar2;
  EPlugVDclType EVar3;
  SLoadedLight *pSVar4;
  SStreamDeclComp *pSVar5;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_ESI;
  int iVar6;
  EPlugVDcl unaff_EDI;
  undefined3 in_stack_0000000d;
  byte in_stack_00000010;
  
  pSVar5 = (SStreamDeclComp *)0x0;
  iVar6 = 0;
  do {
    if ((*(uint *)((int)&DAT_00d14378 + iVar6) & _param_3) != 0) {
      EVar3 = SStreamDeclComp::GetPlugRegType(&param_3,pSVar5,unaff_EDI);
      unaff_EDI = 0x97dd21;
      pSVar4 = CFastBuffer<struct_CNetClient::SQueuedNetNod>::AddNewElem((void *)param_2,unaff_ESI);
      uVar2 = *(undefined4 *)(&DAT_00d387d8 + EVar3 * 4);
      uVar1 = *(undefined2 *)((int)&DAT_00d38820 + iVar6);
      *(ushort *)pSVar4 = (ushort)in_stack_00000010;
      *(short *)(pSVar4 + 2) = (short)param_1;
      pSVar4[4] = SUB41(uVar2,0);
      pSVar4[5] = (SLoadedLight)0x0;
      pSVar4[6] = SUB21(uVar1,0);
      pSVar4[7] = *(SLoadedLight *)(&DAT_00d38822 + iVar6);
      if ((SUB41(uVar2,0) == (SLoadedLight)0x5) && ((*(byte *)(DAT_00d75ad8 + 0x550) & 1) == 0)) {
        pSVar4[4] = (SLoadedLight)0x4;
      }
      param_1 = (CFastBuffer<struct__D3DVERTEXELEMENT9> *)
                (uint)(ushort)((short)param_1 + *(short *)(&DAT_00d14188 + EVar3 * 4));
    }
    pSVar5 = pSVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (pSVar5 < (SStreamDeclComp *)&DAT_00000016);
  return;
}
}

// =================================================
// Function: CDx9VertexDeclaration::StaticSetStream01Decl
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl CDx9VertexDeclaration::StaticSetStream01Decl(SStreamDecl param_1,SStreamDecl param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  TiXmlAttribute *unaff_EBP;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_ESI;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  undefined3 in_stack_00000009;
  int in_stack_00000010;
  CFastBuffer<class_CPlugFileGPUV*> *pCVar3;
  SCasterCat *local_1c;
  undefined1 auStack_18 [4];
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined1 *local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00aea5c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (&DAT_00d75ae4,
                      (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd0));
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      local_1c = CFastBuffer<struct_CDx9StateBlock::STexStageCat>::operator[]
                           (&DAT_00d75ae4,pCVar2,(ulong)unaff_EDI);
      if ((*(int *)local_1c == _param_2) && (*(int *)(local_1c + 4) == in_stack_00000010)) break;
      pCVar2 = pCVar2 + 1;
    } while (pCVar2 < pCVar1);
  }
  if (pCVar2 == pCVar1) {
    local_1c = (SCasterCat *)
               CFastBuffer<struct_CGameNetPlayerInfo::SNetStateSendingInfo>::AddNewElem
                         (&DAT_00d75ae4,unaff_EDI);
    *(int *)local_1c = _param_2;
    *(int *)(local_1c + 4) = in_stack_00000010;
    CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>(&local_10,unaff_ESI);
    AddDeclarationStream((CFastBuffer<struct__D3DVERTEXELEMENT9> *)&local_c,0,param_2);
    if (in_stack_00000010 != 0) {
      AddDeclarationStream
                ((CFastBuffer<struct__D3DVERTEXELEMENT9> *)&local_c,1,SUB41(in_stack_00000010,0));
    }
    uStack_14 = 0xff;
    uStack_12 = 0;
    local_10 = &DAT_00000011;
    CFastBuffer<class_GmNat2>::Add(&local_c,(TiXmlAttributeSet *)&uStack_14,unaff_EBP);
    pCVar3 = (CFastBuffer<class_CPlugFileGPUV*> *)0x97de8a;
    (**(code **)(*DAT_00d75adc + 0x158))();
    uStack_4 = 0xffffffff;
    CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>(auStack_18,pCVar3);
  }
  (**(code **)(*DAT_00d75adc + 0x15c))(DAT_00d75adc,*(undefined4 *)(local_1c + 8));
  _DAT_00d75ae0 = local_1c;
  ExceptionList = local_10;
  return;
}
}

// =================================================
// Function: CDx9VertexDeclaration::StaticSetStream0Decl
// =================================================
void __cdecl CDx9VertexDeclaration::StaticSetStream0Decl(SStreamDecl param_1)
{
{
  StaticSetStream01Decl(param_1,(SStreamDecl)0x0);
  return;
}
}

