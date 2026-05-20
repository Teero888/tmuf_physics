// Class implementation: CSystemFidParameters_SParam_Fids

// =================================================
// Function: CSystemFidParameters::SParam_Fids::Compare
// =================================================
void __thiscall
CSystemFidParameters::SParam_Fids::Compare
          (SParam_Fids *this,SParam_Fids *param_1,SParam *param_2,int *param_3,int *param_4)
{
{
  int extraout_EAX;
  
  if ((*(int *)(this + 4) == *(int *)(param_1 + 4)) &&
     (*(int *)(this + 0x24) == *(int *)(param_1 + 0x24))) {
    *param_3 = 0;
    if ((*(int *)(this + 0x14) == *(int *)(param_1 + 0x14)) &&
       (*(int *)(this + 0x10) == *(int *)(param_1 + 0x10))) {
      if (*(int **)(param_1 + 0x18) == *(int **)(this + 0x18)) {
        CFastString::Compare
                  ((CFastString *)(this + 0x18),(SParam_Fids *)&stack0xfffffff8,(SParam *)0x0,
                   *(int **)(param_1 + 0x1c),*(int **)(param_1 + 0x18));
        if (extraout_EAX == 0) {
          *param_4 = 1;
          return;
        }
      }
    }
    *param_4 = 0;
    return;
  }
  *param_3 = 1;
  *(undefined4 *)param_2 = 0;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::SParam_Fids::SParam_Fids
// =================================================
void __thiscall
CSystemFidParameters::SParam_Fids::SParam_Fids
          (SParam_Fids *this,SParam_Fids *param_1,CSystemFids *param_2)
{
{
  ulong unaff_ESI;
  
  SParam_Fid_Common::SParam_Fid_Common
            ((SParam_Fid_Common *)this,(SParam_Fid_Common *)&DAT_00000009,0,
             (CSystemPackDesc *)&DAT_00d71c9c,(CFastString *)0xffffffff,unaff_ESI);
  *(CSystemFids **)(this + 0x24) = param_2;
  *(undefined ***)this = vftable;
  return;
}
}

// =================================================
// Function: CSystemFidParameters::SParam_Fids::~SParam_Fids
// =================================================
void __thiscall
CSystemFidParameters::SParam_Fids::~SParam_Fids(SParam_Fids *this,SParam_Fids *param_1)
{
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar1 = *(undefined **)(this + 0x1c);
  if (puVar1 != PTR_DAT_00bbf7d8) {
    puVar2 = puVar1 + -1;
    if ((puVar1[-1] & 0x80) != 0) {
      puVar2 = puVar1 + -4;
    }
    operator_delete__(puVar2);
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined **)(this + 0x1c) = PTR_DAT_00bbf7d8;
  }
  SParam::~SParam((SParam *)this,(SParam *)param_1);
  return;
}
}

