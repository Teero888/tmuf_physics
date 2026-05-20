// Class implementation: CControlSimi2

// =================================================
// Function: CControlSimi2::Update
// =================================================
float __thiscall
CControlSimi2::Update(CControlSimi2 *this,SGmSmoothReal2 *param_1,int param_2,ulong param_3)
{
{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  float *pfVar4;
  float fVar5;
  SCasterCat *pSVar6;
  ulong uVar7;
  ulong unaff_ESI;
  float10 in_ST0;
  float10 extraout_ST0;
  float unaff_retaddr;
  COalAudioPort *in_stack_fffffff0;
  
  if (*(int *)(this + 0x14) != 0) {
    pSVar6 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       ((void *)(DAT_00d73300 + 0x20),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)&DAT_00000013,unaff_ESI);
    uVar7 = CAudioPort::GetNbMaxSounds(*(CAudioPort **)pSVar6,in_stack_fffffff0);
    ScreenToRect((GmVec2 *)(*(int *)(uVar7 + 0x24) + 0x58),(GmRectAligned *)(this + 0x3c),
                 (GmVec2 *)&stack0x00000000);
    fVar5 = unaff_retaddr - *(float *)(this + 0x1c);
    iVar2 = *(int *)(this + 0x18);
    fVar1 = *(float *)(this + 0x20);
    in_ST0 = extraout_ST0;
    if (iVar2 == 1) {
      puVar3 = *(undefined4 **)(this + 0x14);
      *puVar3 = *(undefined4 *)(this + 0x24);
      puVar3[1] = *(undefined4 *)(this + 0x28);
      pfVar4 = *(float **)(this + 0x14);
      *pfVar4 = *pfVar4 + fVar5;
      pfVar4[1] = pfVar4[1] + ((float)param_1 - fVar1);
    }
    else {
      if (iVar2 == 2) {
        *(float *)(*(int *)(this + 0x14) + 8) = *(float *)(this + 0x2c) + fVar5;
        return (float)extraout_ST0;
      }
      if (iVar2 == 3) {
        iVar2 = *(int *)(this + 0x14);
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(this + 0x30);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(this + 0x34);
        *(float *)(*(int *)(this + 0x14) + 0xc) = *(float *)(*(int *)(this + 0x14) + 0xc) - fVar5;
        *(float *)(*(int *)(this + 0x14) + 0x10) =
             *(float *)(*(int *)(this + 0x14) + 0x10) + ((float)param_1 - fVar1);
        return (float)extraout_ST0;
      }
    }
  }
  return (float)in_ST0;
}
}

