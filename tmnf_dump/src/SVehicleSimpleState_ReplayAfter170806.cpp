// Class implementation: SVehicleSimpleState_ReplayAfter170806

// =================================================
// Function: SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
SVehicleSimpleState_ReplayAfter170806::RestoreFromStruct
          (void *this,SVehicleSimpleState_ReplayAfter040104 *param_1,SVehicleCarState *param_2,
          SState *param_3,SState *param_4,SState *param_5,SState *param_6)
{
{
  SState *unaff_EDI;
  
  SVehicleSimpleState_ReplayAfter081205::RestoreFromStruct
            (this,param_1,param_2,param_3,param_4,param_5,unaff_EDI);
  *(float *)(param_1 + 0x2c) =
       ((float)*(byte *)((int)this + 0x22) / (float)_DAT_00b55d50) * 1.0 + 0.0;
  return;
}
}

// =================================================
// Function: SVehicleSimpleState_ReplayAfter170806::SaveToStruct
// =================================================
void __thiscall
SVehicleSimpleState_ReplayAfter170806::SaveToStruct
          (void *this,SVehicleSimpleNetState *param_1,SVehicleCarState *param_2,float param_3,
          ulong param_4,int param_5,SState *param_6,int param_7,SState *param_8,int param_9,
          SState *param_10,int param_11,SState *param_12,int param_13)
{
{
  uchar uVar1;
  int unaff_ESI;
  SState *unaff_EDI;
  SState *unaff_retaddr;
  
  SVehicleSimpleState_ReplayAfter081205::SaveToStruct
            (this,param_1,param_2,param_3,param_4,param_5,unaff_EDI,unaff_ESI,unaff_retaddr,
             (int)param_1,(SState *)param_2,(int)param_3,(SState *)param_4,param_5);
  uVar1 = GmFunc::RealToNat8(*(float *)(param_1 + 0x2c),0.0,1.0);
  *(uchar *)((int)this + 0x22) = uVar1;
  return;
}
}

