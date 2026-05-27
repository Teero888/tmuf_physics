// Class implementation: TiXmlPrinter

// =================================================
// Function: TiXmlPrinter::TiXmlPrinter
// =================================================
void __thiscall TiXmlPrinter::TiXmlPrinter(TiXmlPrinter *this,TiXmlPrinter *param_1)
{
{
  char *pcVar1;
  uint unaff_ESI;
  TiXmlPrinter *pTVar2;
  void *pvVar3;
  
  pvVar3 = ExceptionList;
  pcVar1 = (char *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &stack0xfffffff4;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 4) = 0;
  this[8] = (TiXmlPrinter)0x0;
  *(undefined4 **)(this + 0xc) = &DAT_00d72f38;
  pTVar2 = this;
  TiXmlString::TiXmlString(this + 0x10,(TiXmlString *)&DAT_00b515cc,pcVar1,unaff_ESI);
  param_1 = (TiXmlPrinter *)CONCAT31(param_1._1_3_,2);
  TiXmlString::TiXmlString(this + 0x14,(TiXmlString *)&DAT_00b32c2c,(char *)pTVar2,(uint)pvVar3);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: TiXmlPrinter::~TiXmlPrinter
// =================================================
void __thiscall TiXmlPrinter::~TiXmlPrinter(TiXmlPrinter *this,TiXmlPrinter *param_1)
{
{
  if (*(undefined4 **)(this + 0x14) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)(this + 0x14));
  }
  if (*(undefined4 **)(this + 0x10) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)(this + 0x10));
  }
  if (*(undefined4 **)(this + 0xc) != &DAT_00d72f38) {
    operator_delete__(*(undefined4 **)(this + 0xc));
  }
  *(undefined ***)this = TiXmlVisitor::vftable;
  return;
}
}

