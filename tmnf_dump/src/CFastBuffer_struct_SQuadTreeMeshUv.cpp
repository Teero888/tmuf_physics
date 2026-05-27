// Class implementation: CFastBuffer_struct_SQuadTreeMeshUv

// =================================================
// Function: CFastBuffer<struct_SQuadTreeMeshUv>::Add
// =================================================
void __thiscall
CFastBuffer<struct_SQuadTreeMeshUv>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  CFastBuffer<struct_CFastBufferKey<struct_CGameCtnMediaBlockSound::SKeyVal>::SKey>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 0x18);
  *puVar1 = *(undefined4 *)param_2;
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  puVar1[2] = *(undefined4 *)(param_2 + 8);
  puVar1[3] = *(undefined4 *)(param_2 + 0xc);
  puVar1[4] = *(undefined4 *)(param_2 + 0x10);
  puVar1[5] = *(undefined4 *)(param_2 + 0x14);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1);
  return;
}
}

