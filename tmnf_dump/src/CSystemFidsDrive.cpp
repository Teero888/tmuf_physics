// Class implementation: CSystemFidsDrive

// =================================================
// Function: CSystemFidsDrive::CSystemFidsDrive
// =================================================
void __thiscall CSystemFidsDrive::CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1)
{
{
  CSystemFidsFolder *unaff_ESI;
  
  CSystemFidsFolder::CSystemFidsFolder((CSystemFidsFolder *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  *(CSystemFidsDrive **)(this + 0x18) = this;
  return;
}
}

// =================================================
// Function: CSystemFidsDrive::SetDriveName
// =================================================
void __thiscall
CSystemFidsDrive::SetDriveName
          (CSystemFidsDrive *this,CSystemFidsDrive *param_1,CFastStringInt *param_2)
{
{
  SStringParam *unaff_EDI;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = *(undefined4 *)param_1;
  uStack_c = *(undefined4 *)(param_1 + 4);
  uStack_4 = 0;
  CFastStringInt::SetString((CFastStringInt *)(this + 0x40),(CFastStringInt *)&uStack_c,unaff_EDI);
  CSystemFileName::StripTrailingSlash((CFastStringInt *)(this + 0x40));
  (**(code **)(*(int *)this + 0xbc))();
  return;
}
}

// =================================================
// Function: CSystemFidsDrive::~CSystemFidsDrive
// =================================================
void __thiscall
CSystemFidsDrive::~CSystemFidsDrive(CSystemFidsDrive *this,CSystemFidsDrive *param_1)
{
{
  *(undefined ***)this = vftable;
  CSystemFidsFolder::~CSystemFidsFolder((CSystemFidsFolder *)this,(CSystemFidsFolder *)param_1);
  return;
}
}

