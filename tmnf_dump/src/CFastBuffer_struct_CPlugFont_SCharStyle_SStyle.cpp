// Class implementation: CFastBuffer_struct_CPlugFont_SCharStyle_SStyle

// =================================================
// Function: CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::Add
// =================================================
void __thiscall
CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::Add
          (void *this,TiXmlAttributeSet *param_1,TiXmlAttribute *param_2)
{
{
  undefined4 *puVar1;
  int iVar2;
  ulong unaff_EDI;
  
  iVar2 = *(int *)this;
  CFastBuffer<struct_CSystemArchiveNod::SExternalRef>::SetSizeAtLeast
            (this,(CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1),unaff_EDI);
  puVar1 = (undefined4 *)(*(int *)((int)this + 4) + *(int *)this * 0x14);
  *puVar1 = *(undefined4 *)param_2;
  puVar1[1] = *(undefined4 *)(param_2 + 4);
  puVar1[2] = *(undefined4 *)(param_2 + 8);
  puVar1[3] = *(undefined4 *)(param_2 + 0xc);
  puVar1[4] = *(undefined4 *)(param_2 + 0x10);
  *(CFastBuffer<struct_CCrystal::SSmoothingGroup> **)this =
       (CFastBuffer<struct_CCrystal::SSmoothingGroup> *)(iVar2 + 1);
  return;
}
}

// =================================================
// Function: CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::GetLastElem
// =================================================
SNewTriangleVert * __thiscall
CFastBuffer<struct_CPlugFont::SCharStyle::SStyle>::GetLastElem
          (void *this,
          CFastBuffer<struct_CGameCtnMediaBlockEditorTriangles::SNewTriangleVert> *param_1)
{
{
  return (SNewTriangleVert *)(*(int *)((int)this + 4) + -0x14 + *(int *)this * 0x14);
}
}

