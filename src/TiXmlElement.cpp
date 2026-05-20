// Class implementation: TiXmlElement

// =================================================
// Function: TiXmlElement::Attribute
// =================================================
char * __thiscall
TiXmlElement::Attribute(TiXmlElement *this,TiXmlElement *param_1,char *param_2,int *param_3)
{
{
  char *pcVar1;
  undefined4 extraout_EAX;
  int *unaff_ESI;
  char *unaff_EDI;
  undefined4 *in_stack_00000010;
  
  pcVar1 = Attribute(this,param_1,unaff_EDI,unaff_ESI);
  if (in_stack_00000010 != (undefined4 *)0x0) {
    if (pcVar1 != (char *)0x0) {
      atoi();
      *in_stack_00000010 = extraout_EAX;
      return pcVar1;
    }
    *in_stack_00000010 = 0;
  }
  return pcVar1;
}
}

// =================================================
// Function: TiXmlElement::ClearThis
// =================================================
void __thiscall TiXmlElement::ClearThis(TiXmlElement *this,TiXmlElement *param_1)
{
{
  TiXmlElement *this_00;
  TiXmlElement *pTVar1;
  ulong unaff_ESI;
  CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *pCVar2;
  TiXmlNode *unaff_EDI;
  
  TiXmlNode::Clear((TiXmlNode *)this,unaff_EDI);
  this_00 = this + 0x2c;
  while( true ) {
    pTVar1 = *(TiXmlElement **)(this + 0x4c);
    if ((pTVar1 == this_00) || (pTVar1 == (TiXmlElement *)0x0)) break;
    pCVar2 = (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)
             (-(uint)(pTVar1 != this_00) & (uint)pTVar1);
    TiXmlAttributeSet::Remove(this_00,pCVar2,unaff_ESI);
    if (pCVar2 != (CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)0x0) {
      unaff_ESI = 1;
      (*(code *)**(undefined4 **)pCVar2)();
    }
  }
  return;
}
}

// =================================================
// Function: TiXmlElement::QueryDoubleAttribute
// =================================================
int __thiscall
TiXmlElement::QueryDoubleAttribute
          (TiXmlElement *this,TiXmlElement *param_1,char *param_2,double *param_3)
{
{
  TiXmlAttribute *this_00;
  int iVar1;
  GxTexCoordSet *unaff_retaddr;
  
  this_00 = (TiXmlAttribute *)
            TiXmlAttributeSet::Find
                      (this + 0x2c,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_retaddr);
  if (this_00 == (TiXmlAttribute *)0x0) {
    return 1;
  }
  iVar1 = TiXmlAttribute::QueryDoubleValue(this_00,(TiXmlAttribute *)param_3,(double *)param_1);
  return iVar1;
}
}

// =================================================
// Function: TiXmlElement::QueryIntAttribute
// =================================================
int __thiscall
TiXmlElement::QueryIntAttribute(TiXmlElement *this,TiXmlElement *param_1,char *param_2,int *param_3)
{
{
  TiXmlAttribute *this_00;
  int iVar1;
  GxTexCoordSet *unaff_retaddr;
  
  this_00 = (TiXmlAttribute *)
            TiXmlAttributeSet::Find
                      (this + 0x2c,(CFastArray<class_GxTexCoordSet> *)param_1,unaff_retaddr);
  if (this_00 == (TiXmlAttribute *)0x0) {
    return 1;
  }
  iVar1 = TiXmlAttribute::QueryIntValue(this_00,(TiXmlAttribute *)param_3,(int *)param_1);
  return iVar1;
}
}

// =================================================
// Function: TiXmlElement::TiXmlElement
// =================================================
void __thiscall TiXmlElement::TiXmlElement(TiXmlElement *this,TiXmlElement *param_1,char *param_2)
{
{
  TiXmlString TVar1;
  TiXmlString *pTVar2;
  uint unaff_ESI;
  TiXmlAttributeSet *unaff_EDI;
  TiXmlString *in_stack_0000000c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae24f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  TiXmlNode::TiXmlNode
            ((TiXmlNode *)this,(TiXmlNode *)0x1,
             (NodeType)((uint)DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  TiXmlAttributeSet::TiXmlAttributeSet(this + 0x2c,unaff_EDI);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  pTVar2 = in_stack_0000000c;
  do {
    TVar1 = *pTVar2;
    pTVar2 = pTVar2 + 1;
  } while (TVar1 != (TiXmlString)0x0);
  TiXmlString::assign(this + 0x20,in_stack_0000000c,(char *)(pTVar2 + -(int)(in_stack_0000000c + 1))
                      ,unaff_ESI);
  ExceptionList = (void *)0x0;
  return;
}
}

// =================================================
// Function: TiXmlElement::~TiXmlElement
// =================================================
void __thiscall TiXmlElement::~TiXmlElement(TiXmlElement *this,TiXmlElement *param_1)
{
{
  TiXmlElement *pTVar1;
  TiXmlAttributeSet *unaff_ESI;
  void *unaff_retaddr;
  TiXmlElement *pTVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00ae2523;
  local_c = ExceptionList;
  pTVar1 = (TiXmlElement *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  local_4 = 1;
  pTVar2 = this;
  ClearThis(this,pTVar1);
  TiXmlAttributeSet::~TiXmlAttributeSet(this + 0x2c,unaff_ESI);
  TiXmlNode::~TiXmlNode((TiXmlNode *)this,(TiXmlNode *)pTVar2);
  ExceptionList = unaff_retaddr;
  return;
}
}

