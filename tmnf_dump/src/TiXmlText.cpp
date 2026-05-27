// Class implementation: TiXmlText

// =================================================
// Function: TiXmlText::TiXmlText
// =================================================
void __thiscall TiXmlText::TiXmlText(TiXmlText *this,TiXmlText *param_1,CFastStringInt *param_2)
{
{
  TiXmlString TVar1;
  TiXmlString *pTVar2;
  uint unaff_ESI;
  int unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae2438;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  TiXmlNode::TiXmlNode
            ((TiXmlNode *)this,(TiXmlNode *)&DAT_00000004,
             (NodeType)((uint)DAT_00cca150 ^ (uint)&stack0xffffffe8));
  *(undefined ***)this = vftable;
  CFastStringInt::GetUtf8(param_2,(CFastStringInt *)&DAT_00d71ca4,(CFastString *)0x0,unaff_EDI);
  pTVar2 = DAT_00d71ca8;
  do {
    TVar1 = *pTVar2;
    pTVar2 = pTVar2 + 1;
  } while (TVar1 != (TiXmlString)0x0);
  TiXmlString::assign(this + 0x20,DAT_00d71ca8,(char *)(pTVar2 + -(int)(DAT_00d71ca8 + 1)),unaff_ESI
                     );
  this[0x2c] = (TiXmlText)0x0;
  ExceptionList = (void *)0x0;
  return;
}
}

