// Class implementation: CGameNetForm

// =================================================
// Function: CGameNetForm::CGameNetForm
// =================================================
void __thiscall CGameNetForm::CGameNetForm(CGameNetForm *this,CGameNetForm *param_1)
{
{
  CNetNod *unaff_ESI;
  
  CNetNod::CNetNod((CNetNod *)this,unaff_ESI);
  this[0x1c] = (CGameNetForm)0xff;
  this[0x1d] = (CGameNetForm)0xff;
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CGameNetForm::~CGameNetForm
// =================================================
void __thiscall CGameNetForm::~CGameNetForm(CGameNetForm *this,CGameNetForm *param_1)
{
{
  *(undefined ***)this = vftable;
  CNetNod::~CNetNod((CNetNod *)this,(CNetNod *)param_1);
  return;
}
}

