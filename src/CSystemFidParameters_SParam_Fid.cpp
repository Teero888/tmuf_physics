// Class implementation: CSystemFidParameters_SParam_Fid

// =================================================
// Function: CSystemFidParameters::SParam_Fid::SParam_Fid
// =================================================
void __thiscall
CSystemFidParameters::SParam_Fid::SParam_Fid
          (SParam_Fid *this,SParam_Fid *param_1,CSystemFid *param_2)
{
{
  ulong unaff_ESI;
  
  SParam_Fid_Common::SParam_Fid_Common
            ((SParam_Fid_Common *)this,(SParam_Fid_Common *)0x1,0,(CSystemPackDesc *)&DAT_00d71c9c,
             (CFastString *)0xffffffff,unaff_ESI);
  *(CSystemFid **)(this + 0x24) = param_2;
  *(undefined ***)this = vftable;
  return;
}
}

