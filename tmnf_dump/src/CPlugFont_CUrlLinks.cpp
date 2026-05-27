// Class implementation: CPlugFont_CUrlLinks

// =================================================
// Function: CPlugFont::CUrlLinks::AddLineFeed
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CPlugFont::CUrlLinks::AddLineFeed(CUrlLinks *this,CUrlLinks *param_1)
{
{
  undefined4 uVar1;
  SLoadedLight *pSVar2;
  CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *unaff_retaddr;
  TiXmlNode *in_stack_00000008;
  
  if (*(int *)(this + 0x20) != 0) {
    *(undefined4 *)(this + 0x28) = 1;
    pSVar2 = CFastBuffer<struct_CPlugFont::CUrlLinks::SUrlLink>::AddNewElem
                       (this + 0x14,unaff_retaddr);
    uVar1 = _DAT_00badb78;
    *(undefined4 *)pSVar2 = _DAT_00badb78;
    *(undefined4 *)(pSVar2 + 4) = uVar1;
    uVar1 = _DAT_00badb7c;
    *(undefined4 *)(pSVar2 + 8) = _DAT_00badb7c;
    *(undefined4 *)(pSVar2 + 0xc) = uVar1;
    *(undefined4 *)(pSVar2 + 0x10) = 0;
    *(undefined4 *)(pSVar2 + 0x14) = 0;
    SPlugUrlLink::Clear(pSVar2 + 0x18,in_stack_00000008);
    return;
  }
  return;
}
}

