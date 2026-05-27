// Class implementation: TiXmlAttribute

// =================================================
// Function: TiXmlAttribute::QueryDoubleValue
// =================================================
int __thiscall
TiXmlAttribute::QueryDoubleValue(TiXmlAttribute *this,TiXmlAttribute *param_1,double *param_2)
{
{
  int iVar1;
  
  iVar1 = _sscanf_s((char *)(*(int *)(this + 0x18) + 8),"%lf");
  return -(uint)(iVar1 != 1) & 2;
}
}

// =================================================
// Function: TiXmlAttribute::QueryIntValue
// =================================================
int __thiscall
TiXmlAttribute::QueryIntValue(TiXmlAttribute *this,TiXmlAttribute *param_1,int *param_2)
{
{
  int iVar1;
  
  iVar1 = _sscanf_s((char *)(*(int *)(this + 0x18) + 8),"%d");
  return -(uint)(iVar1 != 1) & 2;
}
}

