// Class implementation: CNetUPnP

// =================================================
// Function: CNetUPnP::ForceAdd
// =================================================
int __thiscall
CNetUPnP::ForceAdd(CNetUPnP *this,CNetUPnP *param_1,EProtocol param_2,ushort param_3,
                  CNetIPAddress *param_4,ushort param_5,CFastStringInt *param_6)
{
{
  int extraout_EAX;
  
  Remove(this,(CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *)param_1,param_2);
  Add(this,(TiXmlAttributeSet *)param_1,(TiXmlAttribute *)param_2);
  return (uint)(extraout_EAX != 0);
}
}

// =================================================
// Function: CNetUPnP::InitCollection
// =================================================
int __thiscall CNetUPnP::InitCollection(CNetUPnP *this,CNetUPnP *param_1)
{
{
  int iVar1;
  
  if (*(int *)(this + 0x14) == 0) {
    return 0;
  }
  if (*(int *)(this + 0x18) != 0) {
    return 1;
  }
  iVar1 = (**(code **)(**(int **)(this + 0x14) + 0x1c))(*(int **)(this + 0x14),this + 0x18);
  if (iVar1 < 0) {
    return 0;
  }
  return (uint)(*(int *)(this + 0x18) != 0);
}
}

// =================================================
// Function: CNetUPnP::Remove
// =================================================
void __thiscall
CNetUPnP::Remove(CNetUPnP *this,
                CFastBufferKey<struct_CGameCtnMediaBlockTransitionFade::SKeyVal> *param_1,
                ulong param_2)
{
{
  int iVar1;
  SStringParam *unaff_ESI;
  CNetUPnP *unaff_EDI;
  undefined2 in_stack_0000000c;
  SNationConfig *pSVar2;
  undefined4 local_14;
  undefined *puStack_10;
  undefined *local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  if ((*(int *)(this + 0x18) == 0) && (iVar1 = InitCollection(this,unaff_EDI), iVar1 == 0)) {
    return;
  }
  if (param_2 == 0) {
    local_c = &DAT_00b51f74;
    local_8 = 3;
    CFastStringInt::CFastStringInt(&local_14,(CFastStringInt *)&local_c,unaff_ESI);
    iVar1 = Ordinal_2(local_c);
    if (puStack_10 != PTR_DAT_00bbf7dc) {
      if ((puStack_10[-1] & 0x80) == 0) {
        puStack_10 = puStack_10 + -2;
      }
      else {
        puStack_10 = puStack_10 + -4;
      }
      operator_delete__(puStack_10);
      local_14 = 0;
      puStack_10 = PTR_DAT_00bbf7dc;
    }
  }
  else {
    if (param_2 != 1) {
      return;
    }
    local_c = &DAT_00b51f70;
    local_8 = 3;
    CFastStringInt::CFastStringInt(local_4,(CFastStringInt *)&local_c,unaff_ESI);
    pSVar2 = (SNationConfig *)0x510065;
    iVar1 = Ordinal_2(param_1);
    CGameCtnApp::SNationConfig::~SNationConfig(&local_8,pSVar2);
  }
  if (iVar1 == 0) {
    return;
  }
  (**(code **)(**(int **)(this + 0x18) + 0x28))(*(int **)(this + 0x18),in_stack_0000000c,iVar1);
  Ordinal_6(iVar1);
  return;
}
}

