// Class implementation: TiXmlAttributeSet

// =================================================
// Function: TiXmlAttributeSet::Find
// =================================================
int __thiscall
TiXmlAttributeSet::Find(void *this,CFastArray<class_GxTexCoordSet> *param_1,GxTexCoordSet *param_2)
{
{
  CFastArray<class_GxTexCoordSet> CVar1;
  void *pvVar2;
  CFastArray<class_GxTexCoordSet> *pCVar3;
  int iVar4;
  CFastArray<class_GxTexCoordSet> *pCVar5;
  bool bVar6;
  
  pvVar2 = *(void **)((int)this + 0x20);
  do {
    if (pvVar2 == this) {
      return 0;
    }
    pCVar3 = (CFastArray<class_GxTexCoordSet> *)(*(int *)((int)pvVar2 + 0x14) + 8);
    pCVar5 = param_1;
    do {
      CVar1 = *pCVar3;
      bVar6 = (byte)CVar1 < (byte)*pCVar5;
      if (CVar1 != *pCVar5) {
LAB_0091c278:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0091c27d;
      }
      if (CVar1 == (CFastArray<class_GxTexCoordSet>)0x0) break;
      CVar1 = pCVar3[1];
      bVar6 = (byte)CVar1 < (byte)pCVar5[1];
      if (CVar1 != pCVar5[1]) goto LAB_0091c278;
      pCVar3 = pCVar3 + 2;
      pCVar5 = pCVar5 + 2;
    } while (CVar1 != (CFastArray<class_GxTexCoordSet>)0x0);
    iVar4 = 0;
LAB_0091c27d:
    if (iVar4 == 0) {
      return (int)pvVar2;
    }
    pvVar2 = *(void **)((int)pvVar2 + 0x20);
  } while( true );
}
}

// =================================================
// Function: TiXmlAttributeSet::Remove
// =================================================
void __thiscall
TiXmlAttributeSet::Remove
          (void *this,CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *param_1,
          ulong param_2)
{
{
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *pCVar1;
  
  pCVar1 = *(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> **)((int)this + 0x20);
  if (pCVar1 != this) {
    while (pCVar1 != param_1) {
      pCVar1 = *(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> **)(pCVar1 + 0x20)
      ;
      if (pCVar1 == this) {
        return;
      }
    }
    *(undefined4 *)(*(int *)(pCVar1 + 0x1c) + 0x20) = *(undefined4 *)(pCVar1 + 0x20);
    *(undefined4 *)(*(int *)(pCVar1 + 0x20) + 0x1c) = *(undefined4 *)(pCVar1 + 0x1c);
    *(undefined4 *)(pCVar1 + 0x20) = 0;
    *(undefined4 *)(pCVar1 + 0x1c) = 0;
  }
  return;
}
}

// =================================================
// Function: TiXmlAttributeSet::TiXmlAttributeSet
// =================================================
void __thiscall TiXmlAttributeSet::TiXmlAttributeSet(void *this,TiXmlAttributeSet *param_1)
{
{
  *(undefined4 *)((int)this + 8) = 0xffffffff;
  *(undefined4 *)((int)this + 4) = 0xffffffff;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined ***)this = TiXmlAttribute::vftable;
  *(undefined4 **)((int)this + 0x14) = &DAT_00d72f38;
  *(undefined4 **)((int)this + 0x18) = &DAT_00d72f38;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(void **)((int)this + 0x20) = this;
  *(void **)((int)this + 0x1c) = this;
  return;
}
}

// =================================================
// Function: TiXmlAttributeSet::~TiXmlAttributeSet
// =================================================
void __thiscall TiXmlAttributeSet::~TiXmlAttributeSet(void *this,TiXmlAttributeSet *param_1)
{
{
  if (*(undefined4 **)((int)this + 0x18) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)((int)this + 0x18));
  }
  if (*(undefined4 **)((int)this + 0x14) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)((int)this + 0x14));
  }
  *(undefined ***)this = TiXmlBase::vftable;
  return;
}
}

