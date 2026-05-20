// Class implementation: GmSurfEllipsoid

// =================================================
// Function: GmSurfEllipsoid::CreateEllipsoidDefaultData
// =================================================
void __thiscall
GmSurfEllipsoid::CreateEllipsoidDefaultData(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1)
{
{
  *(undefined4 *)(this + 8) = 0x3f800000;
  *(undefined4 *)(this + 0xc) = 0x3f800000;
  *(undefined4 *)(this + 0x10) = 0x3f800000;
  return;
}
}

// =================================================
// Function: GmSurfEllipsoid::GetEllipsoidBoundingBox
// =================================================
void __thiscall
GmSurfEllipsoid::GetEllipsoidBoundingBox
          (GmSurfEllipsoid *this,GmSurfEllipsoid *param_1,GmBoxAligned *param_2)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(this + 8);
  uVar2 = *(undefined4 *)(this + 0xc);
  uVar3 = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)param_1 = 0;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  return;
}
}

// =================================================
// Function: GmSurfEllipsoid::GmSurfEllipsoid
// =================================================
void __thiscall GmSurfEllipsoid::GmSurfEllipsoid(GmSurfEllipsoid *this,GmSurfEllipsoid *param_1)
{
{
  GmSurf *unaff_ESI;
  
  GmSurf::GmSurf((GmSurf *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  this[6] = (GmSurfEllipsoid)0x1;
  return;
}
}

