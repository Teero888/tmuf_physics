// Class implementation: TiXmlNode

// =================================================
// Function: TiXmlNode::Clear
// =================================================
void __thiscall TiXmlNode::Clear(TiXmlNode *this,TiXmlNode *param_1)
{
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(this + 0x18);
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[10];
    (*(code *)*puVar2)(1);
  }
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}
}

// =================================================
// Function: TiXmlNode::FirstChild
// =================================================
TiXmlNode * __thiscall TiXmlNode::FirstChild(TiXmlNode *this,TiXmlNode *param_1,char *param_2)
{
{
  TiXmlNode TVar1;
  TiXmlNode *pTVar2;
  TiXmlNode *pTVar3;
  int iVar4;
  TiXmlNode *pTVar5;
  bool bVar6;
  
  pTVar2 = *(TiXmlNode **)(this + 0x18);
  do {
    if (pTVar2 == (TiXmlNode *)0x0) {
      return (TiXmlNode *)0x0;
    }
    pTVar3 = (TiXmlNode *)(*(int *)(pTVar2 + 0x20) + 8);
    pTVar5 = param_1;
    do {
      TVar1 = *pTVar3;
      bVar6 = (byte)TVar1 < (byte)*pTVar5;
      if (TVar1 != *pTVar5) {
LAB_0091be78:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0091be7d;
      }
      if (TVar1 == (TiXmlNode)0x0) break;
      TVar1 = pTVar3[1];
      bVar6 = (byte)TVar1 < (byte)pTVar5[1];
      if (TVar1 != pTVar5[1]) goto LAB_0091be78;
      pTVar3 = pTVar3 + 2;
      pTVar5 = pTVar5 + 2;
    } while (TVar1 != (TiXmlNode)0x0);
    iVar4 = 0;
LAB_0091be7d:
    if (iVar4 == 0) {
      return pTVar2;
    }
    pTVar2 = *(TiXmlNode **)(pTVar2 + 0x28);
  } while( true );
}
}

// =================================================
// Function: TiXmlNode::FirstChildElement
// =================================================
TiXmlElement * __thiscall
TiXmlNode::FirstChildElement(TiXmlNode *this,TiXmlNode *param_1,char *param_2)
{
{
  TiXmlNode *this_00;
  int iVar1;
  TiXmlElement *pTVar2;
  char *unaff_EDI;
  char *pcVar3;
  
  this_00 = FirstChild(this,param_1,unaff_EDI);
  while( true ) {
    if (this_00 == (TiXmlNode *)0x0) {
      return (TiXmlElement *)0x0;
    }
    pcVar3 = (char *)0x91bf4b;
    iVar1 = (**(code **)(*(int *)this_00 + 0x18))();
    if (iVar1 != 0) break;
    this_00 = NextSibling(this_00,param_1,pcVar3);
  }
  pTVar2 = (TiXmlElement *)(**(code **)(*(int *)this_00 + 0x18))();
  return pTVar2;
}
}

// =================================================
// Function: TiXmlNode::GetDocument
// =================================================
TiXmlDocument * __thiscall TiXmlNode::GetDocument(TiXmlNode *this,TiXmlNode *param_1)
{
{
  int iVar1;
  TiXmlDocument *pTVar2;
  
  while( true ) {
    if (this == (TiXmlNode *)0x0) {
      return (TiXmlDocument *)0x0;
    }
    iVar1 = (**(code **)(*(int *)this + 0x10))();
    if (iVar1 != 0) break;
    this = *(TiXmlNode **)(this + 0x10);
  }
                    /* WARNING: Could not recover jumptable at 0x0091b9c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pTVar2 = (TiXmlDocument *)(**(code **)(*(int *)this + 0x10))();
  return pTVar2;
}
}

// =================================================
// Function: TiXmlNode::Identify
// =================================================
TiXmlNode * __thiscall
TiXmlNode::Identify(TiXmlNode *this,TiXmlNode *param_1,char *param_2,TiXmlEncoding param_3)
{
{
  bool bVar1;
  TiXmlNode *pTVar2;
  char *pcVar3;
  TiXmlDocument *this_00;
  TiXmlDeclaration *this_01;
  TiXmlNode *extraout_EAX;
  TiXmlComment *this_02;
  TiXmlNode *extraout_EAX_00;
  TiXmlText *this_03;
  TiXmlNode *extraout_EAX_01;
  TiXmlUnknown *pTVar4;
  TiXmlNode *extraout_EAX_02;
  int iVar5;
  TiXmlNode *extraout_EAX_03;
  TiXmlElement *this_04;
  TiXmlNode *extraout_EAX_04;
  TiXmlDeclaration *unaff_EDI;
  void *local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00ae2612;
  local_c = ExceptionList;
  pTVar2 = (TiXmlNode *)(DAT_00cca150 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_c;
  pcVar3 = TiXmlBase::SkipWhiteSpace((char *)param_1,(TiXmlEncoding)param_2);
  if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) || (*pcVar3 != '<')) {
    ExceptionList = local_8;
    return (TiXmlNode *)0x0;
  }
  this_00 = GetDocument(this,pTVar2);
  pcVar3 = TiXmlBase::SkipWhiteSpace(pcVar3,(TiXmlEncoding)param_2);
  if (pcVar3 == (char *)0x0) {
    ExceptionList = local_8;
    return (TiXmlNode *)0x0;
  }
  if (*pcVar3 == '\0') {
    ExceptionList = local_8;
    return (TiXmlNode *)0x0;
  }
  bVar1 = TiXmlBase::StringEqual(pcVar3,"<?xml",true,(TiXmlEncoding)param_2);
  if (bVar1) {
    this_01 = operator_new(0x38);
    if (this_01 != (TiXmlDeclaration *)0x0) {
      TiXmlDeclaration::TiXmlDeclaration(this_01,unaff_EDI);
      pTVar2 = extraout_EAX;
      goto LAB_0091e7b7;
    }
  }
  else {
    bVar1 = TiXmlBase::StringEqual(pcVar3,"<!--",false,(TiXmlEncoding)param_2);
    if (bVar1) {
      this_02 = operator_new(0x2c);
      if (this_02 != (TiXmlComment *)0x0) {
        TiXmlComment::TiXmlComment(this_02,(TiXmlComment *)unaff_EDI);
        pTVar2 = extraout_EAX_00;
        goto LAB_0091e7b7;
      }
    }
    else {
      bVar1 = TiXmlBase::StringEqual(pcVar3,"<![CDATA[",false,(TiXmlEncoding)param_2);
      if (bVar1) {
        this_03 = operator_new(0x30);
        if (this_03 == (TiXmlText *)0x0) {
          pTVar2 = (TiXmlNode *)0x0;
          DAT_0000002c = 1;
        }
        else {
          TiXmlText::TiXmlText(this_03,(TiXmlText *)&DAT_00b2c878,(CFastStringInt *)unaff_EDI);
          extraout_EAX_01[0x2c] = (TiXmlNode)0x1;
          pTVar2 = extraout_EAX_01;
        }
        goto LAB_0091e7b7;
      }
      bVar1 = TiXmlBase::StringEqual(pcVar3,"<!",false,(TiXmlEncoding)param_2);
      if (bVar1) {
        pTVar4 = operator_new(0x2c);
        if (pTVar4 != (TiXmlUnknown *)0x0) {
          TiXmlUnknown::TiXmlUnknown(pTVar4,(TiXmlUnknown *)unaff_EDI);
          pTVar2 = extraout_EAX_02;
          goto LAB_0091e7b7;
        }
      }
      else {
        iVar5 = TiXmlBase::IsAlpha(pcVar3[1],(TiXmlEncoding)param_2);
        if ((iVar5 == 0) && (pcVar3[1] != '_')) {
          pTVar4 = operator_new(0x2c);
          if (pTVar4 != (TiXmlUnknown *)0x0) {
            TiXmlUnknown::TiXmlUnknown(pTVar4,(TiXmlUnknown *)unaff_EDI);
            pTVar2 = extraout_EAX_03;
            goto LAB_0091e7b7;
          }
        }
        else {
          this_04 = operator_new(0x50);
          if (this_04 != (TiXmlElement *)0x0) {
            TiXmlElement::TiXmlElement(this_04,(TiXmlElement *)&DAT_00b2c878,(char *)unaff_EDI);
            pTVar2 = extraout_EAX_04;
            goto LAB_0091e7b7;
          }
        }
      }
    }
  }
  pTVar2 = (TiXmlNode *)0x0;
LAB_0091e7b7:
  if (pTVar2 != (TiXmlNode *)0x0) {
    *(void **)(pTVar2 + 0x10) = local_c;
    ExceptionList = local_8;
    return pTVar2;
  }
  if (this_00 != (TiXmlDocument *)0x0) {
    TiXmlDocument::SetError
              (this_00,(TiXmlDocument *)0x3,0,(char *)0x0,(TiXmlParsingData *)0x0,
               (TiXmlEncoding)unaff_EDI);
    ExceptionList = local_8;
    return (TiXmlNode *)0x0;
  }
  ExceptionList = local_8;
  return (TiXmlNode *)0x0;
}
}

// =================================================
// Function: TiXmlNode::InsertEndChild
// =================================================
TiXmlNode * __thiscall
TiXmlNode::InsertEndChild(TiXmlNode *this,TiXmlNode *param_1,TiXmlNode *param_2)
{
{
  TiXmlDocument *pTVar1;
  TiXmlNode *pTVar2;
  TiXmlNode *unaff_ESI;
  TiXmlParsingData *unaff_retaddr;
  TiXmlDocument *pTVar3;
  int iVar4;
  char *pcVar5;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    pTVar1 = GetDocument(this,unaff_ESI);
    if (pTVar1 != (TiXmlDocument *)0x0) {
      pcVar5 = (char *)0x0;
      iVar4 = 0;
      pTVar3 = (TiXmlDocument *)0x0;
      pTVar1 = GetDocument(this,(TiXmlNode *)0x10);
      TiXmlDocument::SetError(pTVar1,pTVar3,iVar4,pcVar5,unaff_retaddr,(TiXmlEncoding)param_1);
    }
  }
  else {
    pTVar2 = (TiXmlNode *)(**(code **)(*(int *)param_1 + 0x3c))();
    if (pTVar2 != (TiXmlNode *)0x0) {
      pTVar2 = LinkEndChild(this,pTVar2,unaff_ESI);
      return pTVar2;
    }
  }
  return (TiXmlNode *)0x0;
}
}

// =================================================
// Function: TiXmlNode::LinkEndChild
// =================================================
TiXmlNode * __thiscall
TiXmlNode::LinkEndChild(TiXmlNode *this,TiXmlNode *param_1,TiXmlNode *param_2)
{
{
  TiXmlDocument *pTVar1;
  TiXmlParsingData *unaff_ESI;
  TiXmlEncoding unaff_retaddr;
  TiXmlDocument *pTVar2;
  int iVar3;
  TiXmlNode *pTVar4;
  char *pcVar5;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    pTVar4 = (TiXmlNode *)0x1;
    (*(code *)**(undefined4 **)param_1)();
    pTVar1 = GetDocument(this,pTVar4);
    if (pTVar1 != (TiXmlDocument *)0x0) {
      pcVar5 = (char *)0x0;
      iVar3 = 0;
      pTVar2 = (TiXmlDocument *)0x0;
      pTVar1 = GetDocument(this,(TiXmlNode *)0x10);
      TiXmlDocument::SetError(pTVar1,pTVar2,iVar3,pcVar5,unaff_ESI,unaff_retaddr);
    }
    return (TiXmlNode *)0x0;
  }
  *(TiXmlNode **)(param_1 + 0x10) = this;
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(this + 0x1c);
  *(undefined4 *)(param_1 + 0x28) = 0;
  if (*(int *)(this + 0x1c) != 0) {
    *(TiXmlNode **)(*(int *)(this + 0x1c) + 0x28) = param_1;
    *(TiXmlNode **)(this + 0x1c) = param_1;
    return param_1;
  }
  *(TiXmlNode **)(this + 0x18) = param_1;
  *(TiXmlNode **)(this + 0x1c) = param_1;
  return param_1;
}
}

// =================================================
// Function: TiXmlNode::NextSibling
// =================================================
TiXmlNode * __thiscall TiXmlNode::NextSibling(TiXmlNode *this,TiXmlNode *param_1,char *param_2)
{
{
  TiXmlNode TVar1;
  TiXmlNode *pTVar2;
  TiXmlNode *pTVar3;
  int iVar4;
  TiXmlNode *pTVar5;
  bool bVar6;
  
  pTVar2 = *(TiXmlNode **)(this + 0x28);
  do {
    if (pTVar2 == (TiXmlNode *)0x0) {
      return (TiXmlNode *)0x0;
    }
    pTVar3 = (TiXmlNode *)(*(int *)(pTVar2 + 0x20) + 8);
    pTVar5 = param_1;
    do {
      TVar1 = *pTVar3;
      bVar6 = (byte)TVar1 < (byte)*pTVar5;
      if (TVar1 != *pTVar5) {
LAB_0091bee8:
        iVar4 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
        goto LAB_0091beed;
      }
      if (TVar1 == (TiXmlNode)0x0) break;
      TVar1 = pTVar3[1];
      bVar6 = (byte)TVar1 < (byte)pTVar5[1];
      if (TVar1 != pTVar5[1]) goto LAB_0091bee8;
      pTVar3 = pTVar3 + 2;
      pTVar5 = pTVar5 + 2;
    } while (TVar1 != (TiXmlNode)0x0);
    iVar4 = 0;
LAB_0091beed:
    if (iVar4 == 0) {
      return pTVar2;
    }
    pTVar2 = *(TiXmlNode **)(pTVar2 + 0x28);
  } while( true );
}
}

// =================================================
// Function: TiXmlNode::NextSiblingElement
// =================================================
TiXmlElement * __thiscall
TiXmlNode::NextSiblingElement(TiXmlNode *this,TiXmlNode *param_1,char *param_2)
{
{
  TiXmlNode *this_00;
  int iVar1;
  TiXmlElement *pTVar2;
  char *unaff_EDI;
  char *pcVar3;
  
  this_00 = NextSibling(this,param_1,unaff_EDI);
  while( true ) {
    if (this_00 == (TiXmlNode *)0x0) {
      return (TiXmlElement *)0x0;
    }
    pcVar3 = (char *)0x91bfbb;
    iVar1 = (**(code **)(*(int *)this_00 + 0x18))();
    if (iVar1 != 0) break;
    this_00 = NextSibling(this_00,param_1,pcVar3);
  }
  pTVar2 = (TiXmlElement *)(**(code **)(*(int *)this_00 + 0x18))();
  return pTVar2;
}
}

// =================================================
// Function: TiXmlNode::TiXmlNode
// =================================================
void __thiscall TiXmlNode::TiXmlNode(TiXmlNode *this,TiXmlNode *param_1,NodeType param_2)
{
{
  *(undefined4 *)(this + 8) = 0xffffffff;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined ***)this = vftable;
  *(undefined4 **)(this + 0x20) = &DAT_00d72f38;
  *(undefined4 *)(this + 0x10) = 0;
  *(TiXmlNode **)(this + 0x14) = param_1;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}
}

// =================================================
// Function: TiXmlNode::~TiXmlNode
// =================================================
void __thiscall TiXmlNode::~TiXmlNode(TiXmlNode *this,TiXmlNode *param_1)
{
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_c = ExceptionList;
  puStack_8 = &LAB_00ae22f3;
  uVar3 = DAT_00cca150 ^ (uint)&stack0xffffffe8;
  ExceptionList = &local_c;
  *(undefined ***)this = vftable;
  puVar1 = *(undefined4 **)(this + 0x18);
  local_4 = 1;
  while (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    puVar1 = (undefined4 *)puVar1[10];
    (*(code *)*puVar2)(1,uVar3);
  }
  if (*(undefined4 **)(this + 0x20) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)(this + 0x20));
  }
  *(undefined ***)this = TiXmlBase::vftable;
  ExceptionList = local_c;
  return;
}
}

