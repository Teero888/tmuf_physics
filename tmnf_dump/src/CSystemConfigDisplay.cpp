// Class implementation: CSystemConfigDisplay

// =================================================
// Function: CSystemConfigDisplay::ApplyDynamicPresets
// =================================================
void __thiscall
CSystemConfigDisplay::ApplyDynamicPresets(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *unaff_EBP;
  void *unaff_ESI;
  CSystemConfigDisplay *unaff_EDI;
  
  uVar1 = *(undefined4 *)(this + 0x70);
  uVar2 = *(undefined4 *)(this + 0x74);
  uVar3 = *(undefined4 *)(this + 0x6c);
  if (*(int *)(this + 0x40) == 0) {
    ComputeAutoQuality(this,unaff_EDI);
  }
  else {
    SetPreset(this,*(CSystemConfigDisplay **)(this + 0x44),(EPreset)unaff_EDI);
  }
  if (*(int *)(this + 0x68) != 0) {
    *(undefined4 *)(this + 0x6c) = uVar3;
    *(undefined4 *)(this + 0x70) = uVar1;
    *(undefined4 *)(this + 0x74) = uVar2;
  }
  iVar4 = CSystemFile_testerror(unaff_ESI,unaff_EBP);
  if (iVar4 == 0) {
    *(undefined4 *)(this + 0x78) = 0;
  }
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::CSystemConfigDisplay
// =================================================
void __thiscall
CSystemConfigDisplay::CSystemConfigDisplay(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(undefined4 *)(this + 0xb8) = 2;
  *(undefined4 *)(this + 0xbc) = 2;
  *(undefined4 *)(this + 0xa4) = 1;
  *(undefined4 *)(this + 0xc4) = 1;
  *(undefined4 *)(this + 0x58) = 1;
  *(undefined4 *)(this + 0x7c) = 1;
  *(undefined4 *)(this + 0x3c) = 1;
  *(undefined4 *)(this + 200) = 1;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined ***)this = vftable;
  *(undefined4 *)(this + 0x90) = 10000;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0x50) = 3;
  *(undefined4 *)(this + 0xd4) = 3;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x80) = 10;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0xcc) = 4;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 100) = 0;
  LowFpsReset(this,param_1);
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::ComputeAutoQuality
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemConfigDisplay::ComputeAutoQuality(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  byte bVar8;
  CPlugFileGpuBuilder *this_00;
  uint uVar9;
  char *unaff_EBP;
  CPlugFileGpuBuilder *unaff_EDI;
  bool bVar10;
  
  if (*(int *)(this + 0x40) == 0) {
    iVar1 = *(int *)(this + 0x3c);
    bVar8 = 1;
    fVar2 = _DAT_00b31460;
    if ((iVar1 != 0) && ((iVar1 == 1 || (fVar2 = _DAT_00b313ac, iVar1 != 2)))) {
      fVar2 = 1.0;
    }
    fVar3 = (float)(DAT_00d542d0 * DAT_00d542cc);
    if (DAT_00d542d0 * DAT_00d542cc < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    fVar3 = fVar3 / (float)_DAT_00b313b0;
    uVar9 = (uint)DAT_00d542b4;
    if ((DAT_00d542d5 & 1) == 0) {
      uVar9 = uVar9 / 3;
    }
    if (uVar9 < 0x65) {
      if (uVar9 < 0x33) {
        *(uint *)(this + 0x48) = (uint)(0x1c < uVar9);
      }
      else {
        *(undefined4 *)(this + 0x48) = 2;
      }
    }
    else {
      *(undefined4 *)(this + 0x48) = 3;
    }
    *(undefined4 *)(this + 100) = 0;
    if (((DAT_00d5430c & 1) != 0) ||
       (CSystemEngine::LoadGraphicPerformance(), (DAT_00d5430c & 1) != 0)) {
      fVar4 = fVar2 * DAT_00d542e8;
      fVar5 = (float)_DAT_00b313f8;
      if ((0 < *(int *)(this + 0x3c)) || ((float)_DAT_00b313f0 <= fVar4)) {
        *(undefined4 *)(this + 0x78) = 0;
      }
      else {
        fVar7 = (float)_DAT_00b313e8;
        *(undefined4 *)(this + 0x78) = 1;
        if (fVar7 <= fVar4) {
          if (fVar5 <= fVar4) {
            *(undefined4 *)(this + 0x7c) = 2;
          }
          else {
            *(undefined4 *)(this + 0x7c) = 1;
          }
        }
        else {
          *(undefined4 *)(this + 0x7c) = 0;
        }
      }
      fVar7 = _DAT_00b313a8;
      if ((_DAT_00b313e0 <= fVar4) && (fVar7 = _DAT_00b313ac, fVar5 <= fVar4)) {
        fVar7 = 1.0;
      }
      *(float *)(this + 0x84) = fVar7;
      fVar5 = (float)_DAT_00b2f740;
      *(uint *)(this + 0x60) = (uint)(fVar5 < fVar4);
      if ((*(int *)(this + 0x98) != 0) || ((DAT_00d542d5 & 2) == 0)) {
        bVar8 = 0;
      }
      *(undefined4 *)(this + 0x5c) = 0;
      fVar4 = _DAT_00d54308 * fVar2;
      fVar7 = (float)_DAT_00b313d8;
      if (fVar4 <= (float)_DAT_00c418d8 * fVar3) {
        if (fVar4 <= fVar3 * (float)_DAT_00b2f728) {
          fVar6 = fVar3 * fVar7;
          if (fVar4 <= fVar6) {
            if (_DAT_00d54304 * fVar2 <= fVar6) {
              if (_DAT_00d54300 * fVar2 <= fVar6) {
                if (_DAT_00d542fc * fVar2 <= fVar6) {
                  if (_DAT_00d542f8 * fVar2 <= fVar6) {
                    *(undefined4 *)(this + 0xd4) = 0;
                  }
                  else {
                    *(undefined4 *)(this + 0xd4) = 1;
                  }
                }
                else {
                  *(undefined4 *)(this + 0xd4) = 2;
                }
                *(undefined4 *)(this + 0x54) = 1;
              }
              else {
                *(undefined4 *)(this + 0xd4) = 3;
                *(undefined4 *)(this + 0x54) = 2;
              }
            }
            else {
              *(undefined4 *)(this + 0xd4) = 4;
              *(uint *)(this + 0x54) = bVar8 + 2;
            }
          }
          else {
            *(undefined4 *)(this + 0xd4) = 4;
            *(undefined4 *)(this + 0x54) = 3;
          }
        }
        else {
          *(undefined4 *)(this + 0xd4) = 5;
          *(undefined4 *)(this + 0x54) = 3;
        }
      }
      else {
        *(undefined4 *)(this + 0xd4) = 5;
        *(undefined4 *)(this + 0x54) = 4;
        *(undefined4 *)(this + 0x5c) = 1;
      }
      if ((_DAT_00d542f0 * fVar2 <= fVar3 * fVar5) || (DAT_00d542e8 * fVar2 <= (float)_DAT_00b313d0)
         ) {
        if (_DAT_00d542f0 * fVar2 <= (float)_DAT_00b313c8 * fVar3) {
          if (DAT_00d542ec * fVar2 <= fVar3 * (float)_DAT_00b313c0) {
            if (_DAT_00d542f8 * fVar2 <= fVar7 * fVar3) {
              *(undefined4 *)(this + 0x4c) = 0;
            }
            else {
              *(undefined4 *)(this + 0x4c) = 1;
            }
          }
          else {
            *(undefined4 *)(this + 0x4c) = 2;
          }
          *(undefined4 *)(this + 0x68) = 0;
        }
        else {
          *(undefined4 *)(this + 0x4c) = 3;
          *(uint *)(this + 0x68) = (uint)(0xc4 < DAT_00d542b4);
        }
      }
      else {
        *(undefined4 *)(this + 0x4c) = 4;
        *(uint *)(this + 0x68) = (uint)(0xc4 < DAT_00d542b4);
      }
      if (*(int *)(this + 0x68) == 0) {
        *(undefined4 *)(this + 0x74) = 0;
        *(undefined4 *)(this + 0x70) = 0;
        *(undefined4 *)(this + 0x6c) = 0;
      }
      Tweak_NVidia_C51(this,param_1);
      return;
    }
    if (DAT_00d71e54 != 0) {
      DAT_00d71e54 = 0;
      *DAT_00d71e58 = 0;
    }
    this_00 = CFastString::operator<<
                        ((CFastString *)&DAT_00d71e54,(CPlugFileGpuBuilder *)0xb31400,
                         (char *)&lpOutputString_00b2bcc4);
    CFastString::operator<<((CFastString *)this_00,unaff_EDI,unaff_EBP);
    CClassicLog::AddLogStringInFile();
    *(undefined4 *)(this + 0x78) = 1;
    if (DAT_00d542b0 == 0) {
      *(undefined4 *)(this + 0x7c) = 0;
      *(undefined4 *)(this + 0xd4) = 0;
      *(undefined4 *)(this + 0x54) = 1;
      *(undefined4 *)(this + 0x4c) = 0;
    }
    else if (DAT_00d542b0 == 1) {
      *(undefined4 *)(this + 0x7c) = 1;
      *(undefined4 *)(this + 0xd4) = 1;
      *(undefined4 *)(this + 0x54) = 1;
      *(undefined4 *)(this + 0x4c) = 1;
    }
    else {
      bVar10 = DAT_00d542b0 == 2;
      *(undefined4 *)(this + 0x54) = 2;
      if (bVar10) {
        *(undefined4 *)(this + 0x7c) = 2;
        *(undefined4 *)(this + 0xd4) = 2;
        *(undefined4 *)(this + 0x4c) = 1;
      }
      else {
        *(undefined4 *)(this + 0x78) = 0;
        *(undefined4 *)(this + 0xd4) = 3;
        *(undefined4 *)(this + 0x4c) = 2;
      }
    }
    *(undefined4 *)(this + 0x68) = 0;
    *(undefined4 *)(this + 0x60) = 0;
    if (DAT_00d542b8 == 0) {
      *(float *)(this + 0x84) = _DAT_00b313a8;
      *(undefined4 *)(this + 0x5c) = 0;
      return;
    }
    if (DAT_00d542b8 < 0x100) {
      *(float *)(this + 0x84) = _DAT_00b313ac;
      *(undefined4 *)(this + 0x5c) = 0;
      return;
    }
    *(undefined4 *)(this + 0x84) = 0x3f800000;
    *(undefined4 *)(this + 0x5c) = 0;
  }
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::ComputeHighestResolutionFS
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemConfigDisplay::ComputeHighestResolutionFS
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  ulong uVar6;
  SCasterCat *pSVar7;
  ulong unaff_EBX;
  GxTexCoordSet *unaff_ESI;
  int *piVar8;
  CFastArray<class_GxTexCoordSet> *unaff_EDI;
  int iVar9;
  int local_30;
  float local_2c;
  int local_28 [9];
  
  local_28[0] = 0x280;
  local_28[1] = 0x1e0;
  local_28[2] = 800;
  local_28[3] = 600;
  local_28[4] = 0x400;
  local_28[5] = 0x300;
  local_28[6] = DAT_00d542cc;
  local_28[7] = DAT_00d542d0;
  iVar9 = 3;
  while( true ) {
    iVar1 = local_28[iVar9 * 2];
    iVar2 = local_28[iVar9 * 2 + 1];
    piVar8 = local_28 + iVar9 * 2;
    local_30 = iVar1;
    local_2c = (float)iVar2;
    iVar5 = CFastBuffer<class_GmNat2>::Find
                      (&DAT_00d542dc,(CFastArray<class_GxTexCoordSet> *)&local_30,
                       (GxTexCoordSet *)unaff_EDI);
    for (; (iVar5 == -1 && (iVar9 != 0)); iVar9 = iVar9 + -1) {
      iVar1 = piVar8[-2];
      iVar2 = piVar8[-1];
      piVar8 = piVar8 + -2;
      local_2c = (float)iVar1;
      local_28[0] = iVar2;
      iVar5 = CFastBuffer<class_GmNat2>::Find
                        (&DAT_00d542dc,(CFastArray<class_GxTexCoordSet> *)&local_2c,unaff_ESI);
    }
    unaff_EDI = (CFastArray<class_GxTexCoordSet> *)&local_2c;
    iVar5 = CFastBuffer<class_GmNat2>::Find(&DAT_00d542dc,unaff_EDI,unaff_ESI);
    if (iVar5 == -1) {
      uVar6 = CFastBuffer<class_CCrystalFace*>::GetCount
                        (&DAT_00d542dc,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
      if (uVar6 == 0) {
        *(undefined4 *)((int)local_2c + 0x14) = 0x280;
        *(undefined4 *)((int)local_2c + 0x18) = 0x1e0;
        return;
      }
      pSVar7 = CFastBuffer<struct_SFastCat>::operator[]
                         (&DAT_00d542dc,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          unaff_EBX);
      *(undefined4 *)(local_28[0] + 0x14) = *(undefined4 *)pSVar7;
      *(undefined4 *)(local_28[0] + 0x18) = *(undefined4 *)(pSVar7 + 4);
      return;
    }
    if ((DAT_00d5430c & 1) == 0) break;
    fVar3 = (float)iVar2;
    if (iVar2 < 0) {
      fVar3 = fVar3 + _DAT_00c418d0;
    }
    fVar4 = (float)iVar1;
    if (iVar1 < 0) {
      fVar4 = fVar4 + _DAT_00c418d0;
    }
    local_2c = (fVar4 * fVar3) / (float)_DAT_00b313b0;
    if ((local_2c * (float)_DAT_00b2f738 < _DAT_00d542f8) || (iVar9 == 0)) break;
    iVar9 = iVar9 + -1;
  }
  iVar1 = local_28[iVar9 * 2 + 3];
  *(int *)(local_30 + 0x14) = local_28[iVar9 * 2 + 2];
  *(int *)(local_30 + 0x18) = iVar1;
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::InternalApplyPreset
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CSystemConfigDisplay::InternalApplyPreset
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,EPreset param_2)
{
{
  undefined4 uVar1;
  undefined4 uVar2;
  bool bVar3;
  CSystemConfigDisplay *unaff_retaddr;
  
  uVar2 = _DAT_00b313ac;
  uVar1 = _DAT_00b313a8;
  switch(param_1) {
  case (CSystemConfigDisplay *)0x1:
    *(undefined4 *)(this + 0x48) = 0;
    *(undefined4 *)(this + 0x4c) = 0;
    *(undefined4 *)(this + 0xd4) = 0;
    *(undefined4 *)(this + 0x54) = 0;
    *(undefined4 *)(this + 0x78) = 1;
    *(undefined4 *)(this + 0x7c) = 0;
    break;
  case (CSystemConfigDisplay *)0x2:
    *(undefined4 *)(this + 0x84) = _DAT_00b313a8;
    *(undefined4 *)(this + 0x48) = 1;
    *(undefined4 *)(this + 0x4c) = 1;
    *(undefined4 *)(this + 0xd4) = 1;
    *(undefined4 *)(this + 0x54) = 1;
    *(undefined4 *)(this + 0x78) = 1;
    *(undefined4 *)(this + 0x7c) = 1;
    *(undefined4 *)(this + 0x5c) = 0;
    *(undefined4 *)(this + 0x60) = 0;
    *(undefined4 *)(this + 100) = 0;
    *(undefined4 *)(this + 0x68) = 0;
    Tweak_NVidia_C51(this,unaff_retaddr);
    return;
  case (CSystemConfigDisplay *)0x3:
    *(undefined4 *)(this + 0x48) = 2;
    *(undefined4 *)(this + 0x4c) = 2;
    *(undefined4 *)(this + 0x54) = 2;
    *(undefined4 *)(this + 0xd4) = 3;
    *(undefined4 *)(this + 0x78) = 0;
    uVar1 = uVar2;
    break;
  case (CSystemConfigDisplay *)0x4:
    *(undefined4 *)(this + 0x48) = 3;
    *(undefined4 *)(this + 0x4c) = 3;
    *(undefined4 *)(this + 0x54) = 3;
    *(undefined4 *)(this + 0xd4) = 4;
    *(undefined4 *)(this + 0x78) = 0;
    uVar1 = 0x3f800000;
    break;
  case (CSystemConfigDisplay *)0x5:
    *(undefined4 *)(this + 0x84) = 0x3f800000;
    *(undefined4 *)(this + 0x4c) = 4;
    *(undefined4 *)(this + 0x54) = 4;
    *(undefined4 *)(this + 0x48) = 3;
    *(undefined4 *)(this + 0xd4) = 5;
    *(undefined4 *)(this + 0x78) = 0;
    *(undefined4 *)(this + 0x5c) = 1;
    *(undefined4 *)(this + 0x60) = 1;
    *(undefined4 *)(this + 100) = 0;
    bVar3 = 0xc4 < DAT_00d542b4;
    *(undefined4 *)(this + 0x6c) = 0;
    *(uint *)(this + 0x68) = (uint)bVar3;
    *(undefined4 *)(this + 0x70) = 1;
    *(undefined4 *)(this + 0x74) = 1;
  default:
    Tweak_NVidia_C51(this,unaff_retaddr);
    return;
  }
  *(undefined4 *)(this + 0x84) = uVar1;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  Tweak_NVidia_C51(this,unaff_retaddr);
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::IsGraphicAdpaterMain_NVidia_C51
// =================================================
int __thiscall
CSystemConfigDisplay::IsGraphicAdpaterMain_NVidia_C51
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  uint uVar1;
  
  uVar1 = 0;
  if (DAT_00d542a0 == 0x10de) {
    do {
      if (DAT_00d542a4 == *(int *)((int)&DAT_00ccccb8 + uVar1)) {
        return 1;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0x40);
  }
  return 0;
}
}

// =================================================
// Function: CSystemConfigDisplay::LowFpsReset
// =================================================
void __thiscall
CSystemConfigDisplay::LowFpsReset(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  *(undefined4 *)(this + 0xd0) = 0;
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::MultiThreadGetScale
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float __thiscall
CSystemConfigDisplay::MultiThreadGetScale(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  float fVar1;
  ulong uVar2;
  
  uVar2 = MultiThreadGetThreadCount(this,this);
  if (uVar2 < 2) {
    return 1.0;
  }
  fVar1 = (float)(int)(uVar2 - 1);
  if ((int)(uVar2 - 1) < 0) {
    fVar1 = fVar1 + _DAT_00c418d0;
  }
  return fVar1 * (float)_DAT_00b313b8 + (float)_DAT_00b2c188;
}
}

// =================================================
// Function: CSystemConfigDisplay::MultiThreadGetThreadCount
// =================================================
ulong __thiscall
CSystemConfigDisplay::MultiThreadGetThreadCount
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  uint uVar1;
  
  if (*(int *)(this + 200) == 0) {
    return 1;
  }
  uVar1 = *(uint *)(this + 0xcc);
  if (DAT_00ccb5e8 <= *(uint *)(this + 0xcc)) {
    uVar1 = DAT_00ccb5e8;
  }
  return uVar1;
}
}

// =================================================
// Function: CSystemConfigDisplay::SetDefaultsDisplay
// =================================================
void __thiscall
CSystemConfigDisplay::SetDefaultsDisplay(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  int iVar1;
  CSystemConfigDisplay *unaff_EBX;
  ushort unaff_SI;
  CSystemConfigDisplay *unaff_EDI;
  
  ComputeHighestResolutionFS(this,unaff_EDI);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 1;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x98) = 0;
  *(undefined4 *)(this + 0x9c) = 0;
  *(undefined4 *)(this + 0x8c) = 7;
  *(undefined4 *)(this + 0x90) = 10000;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xa4) = 0;
  *(undefined4 *)(this + 0xa8) = 0;
  *(undefined4 *)(this + 0xac) = 0;
  if (DAT_00d542a0 != 0x10de) goto LAB_00438154;
  if (DAT_00d542b0 != 2) {
    if (DAT_00d542b0 < 3) goto LAB_00438154;
    iVar1 = SSysGraphicAdapter::IsDriverRecentOrEqual
                      (&DAT_00d542a0,(SSysGraphicAdapter *)&DAT_00000006,0xe,10,0x1a25,unaff_SI);
    if (iVar1 != 0) goto LAB_00438154;
  }
  *(undefined4 *)(this + 0xac) = 1;
LAB_00438154:
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0xb0) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(undefined4 *)(this + 0xc4) = 1;
  *(undefined4 *)(this + 0x58) = 1;
  *(undefined4 *)(this + 0xb8) = 2;
  *(undefined4 *)(this + 0xbc) = 2;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x7c) = 1;
  *(undefined4 *)(this + 0x80) = 10;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 200) = 1;
  *(undefined4 *)(this + 0xcc) = 4;
  if (*(int *)(this + 0x40) != 0) {
    SetPreset(this,*(CSystemConfigDisplay **)(this + 0x44),(EPreset)unaff_EBX);
    *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0xd4);
    return;
  }
  ComputeAutoQuality(this,unaff_EBX);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0xd4);
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::SetPreset
// =================================================
void __thiscall
CSystemConfigDisplay::SetPreset
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,EPreset param_2)
{
{
  EPreset unaff_ESI;
  
  *(CSystemConfigDisplay **)(this + 0x44) = param_1;
  InternalApplyPreset(this,param_1,unaff_ESI);
  if (*(int *)(this + 0x68) == 0) {
    *(undefined4 *)(this + 0x74) = 0;
    *(undefined4 *)(this + 0x70) = 0;
    *(undefined4 *)(this + 0x6c) = 0;
  }
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::SetSafeValues
// =================================================
void __thiscall
CSystemConfigDisplay::SetSafeValues
          (CSystemConfigDisplay *this,CSystemConfigDisplay *param_1,int param_2,GmNat2 *param_3)
{
{
  undefined4 uVar1;
  
  *(undefined4 *)(this + 0x30) = 1;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)param_2;
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x84) = 0x3f800000;
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x94) = 0;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x98) = 1;
  *(undefined4 *)(this + 0x9c) = 1;
  *(undefined4 *)(this + 0xa4) = 1;
  *(undefined4 *)(this + 0xa8) = 1;
  *(undefined4 *)(this + 0xac) = 1;
  *(undefined4 *)(this + 0xb0) = 1;
  *(undefined4 *)(this + 0x40) = 1;
  *(undefined4 *)(this + 0xcc) = 1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(uint *)(this + 0x20) = (uint)(param_1 != (CSystemConfigDisplay *)0x0);
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xd4) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x88) = 2;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x8c) = 7;
  *(undefined4 *)(this + 0x90) = 50000;
  *(undefined4 *)(this + 0xa0) = 0;
  *(undefined4 *)(this + 0xb4) = 0;
  *(undefined4 *)(this + 0xc0) = 0;
  *(undefined4 *)(this + 0xc4) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0xb8) = 0;
  *(undefined4 *)(this + 0xbc) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 200) = 0;
  return;
}
}

// =================================================
// Function: CSystemConfigDisplay::Tweak_NVidia_C51
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall
CSystemConfigDisplay::Tweak_NVidia_C51(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  int iVar1;
  int extraout_EDX;
  CSystemConfigDisplay *unaff_retaddr;
  
  iVar1 = IsGraphicAdpaterMain_NVidia_C51(this,unaff_retaddr);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(extraout_EDX + 0x40) != 0) {
    if (*(int *)(extraout_EDX + 0x44) == 0) {
      return 0;
    }
    if (*(int *)(extraout_EDX + 0x40) != 0) goto LAB_00437774;
  }
  *(undefined4 *)(extraout_EDX + 0x84) = _DAT_00b313a8;
  *(undefined4 *)(extraout_EDX + 0x48) = 3;
  *(undefined4 *)(extraout_EDX + 0x4c) = 2;
  *(undefined4 *)(extraout_EDX + 0xd4) = 3;
  *(undefined4 *)(extraout_EDX + 0x54) = 2;
  *(undefined4 *)(extraout_EDX + 0x78) = 0;
  *(undefined4 *)(extraout_EDX + 0x5c) = 0;
  *(undefined4 *)(extraout_EDX + 0x60) = 0;
  *(undefined4 *)(extraout_EDX + 0x68) = 0;
LAB_00437774:
  *(undefined4 *)(extraout_EDX + 0x8c) = 5;
  return 1;
}
}

// =================================================
// Function: CSystemConfigDisplay::WaterGeom
// =================================================
int __thiscall
CSystemConfigDisplay::WaterGeom(CSystemConfigDisplay *this,CSystemConfigDisplay *param_1)
{
{
  if ((*(int *)(this + 0x60) != 0) && ((DAT_00d55754 == 0 || (*(int *)(this + 100) != 0)))) {
    return 1;
  }
  return 0;
}
}

