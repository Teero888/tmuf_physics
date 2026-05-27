// Class implementation: CHmsLight

// =================================================
// Function: CHmsLight::CHmsLight
// =================================================
void __thiscall CHmsLight::CHmsLight(CHmsLight *this,CHmsLight *param_1)
{
{
  CHmsPoc *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CHmsPoc::CHmsPoc((CHmsPoc *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x58,unaff_retaddr);
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x8c) = 1;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x78) = 0x3f800000;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  return;
}
}

// =================================================
// Function: CHmsLight::SetForceShadowGroup
// =================================================
void __thiscall
CHmsLight::SetForceShadowGroup(CHmsLight *this,CHmsLight *param_1,int param_2,ulong param_3)
{
{
  *(uint *)(this + 0x8c) =
       ((uint)(param_1 != (CHmsLight *)0x0) | (param_2 & 0xfU) * 2) * 8 |
       *(uint *)(this + 0x8c) & 0xffffff07;
  return;
}
}

// =================================================
// Function: CHmsLight::SetGxLight
// =================================================
void __thiscall CHmsLight::SetGxLight(CHmsLight *this,CHmsLight *param_1,GxLight *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CHmsLight **)(this + 0x88)) {
    if (param_1 != (CHmsLight *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x88) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x88),unaff_ESI);
    }
    *(CHmsLight **)(this + 0x88) = param_1;
  }
  return;
}
}

// =================================================
// Function: CHmsLight::SetProjectorBitmap
// =================================================
void __thiscall
CHmsLight::SetProjectorBitmap(CHmsLight *this,CHmsLight *param_1,CPlugBitmap *param_2)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (param_1 != *(CHmsLight **)(this + 0x70)) {
    if (param_1 != (CHmsLight *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,unaff_EDI);
    }
    if (*(CMwNod **)(this + 0x70) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(this + 0x70),unaff_ESI);
    }
    *(CHmsLight **)(this + 0x70) = param_1;
  }
  return;
}
}

// =================================================
// Function: CHmsLight::SetReflectPlaneIsEnable
// =================================================
void __thiscall CHmsLight::SetReflectPlaneIsEnable(CHmsLight *this,CHmsLight *param_1,int param_2)
{
{
  *(uint *)(this + 0x8c) =
       *(uint *)(this + 0x8c) ^
       ((uint)(param_1 != (CHmsLight *)0x0) * 4 ^ *(uint *)(this + 0x8c)) & 4;
  return;
}
}

// =================================================
// Function: CHmsLight::SetUpdateType
// =================================================
void __thiscall CHmsLight::SetUpdateType(CHmsLight *this,CHmsLight *param_1,ELightUpdate param_2)
{
{
  uint uVar1;
  CHmsZoneVPacker *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  CHmsCorpusLight *unaff_EBX;
  CHmsZoneVPacker *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CHmsZoneVPacker *pCVar5;
  
  uVar1 = *(uint *)(this + 0x8c);
  if ((CHmsLight *)(uVar1 & 3) != param_1) {
    *(uint *)(this + 0x8c) = (uVar1 ^ (uint)param_1) & 3 ^ uVar1;
    pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x58,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this + 0x58,pCVar4,(ulong)unaff_ESI);
        pCVar5 = *(CHmsZoneVPacker **)pSVar3;
        this_00 = *(CHmsZoneVPacker **)(*(int *)(pCVar5 + 0x14) + 0x104);
        if (this_00 != (CHmsZoneVPacker *)0x0) {
          if (((byte)*(undefined4 *)(this + 0x8c) & 3) == 1) {
            CHmsZoneVPacker::RemoveLight(this_00,pCVar5,unaff_EBX);
            unaff_ESI = pCVar5;
          }
          else {
            CHmsZoneVPacker::AddNewLight(this_00,pCVar5,unaff_EBX);
            unaff_ESI = pCVar5;
          }
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCVar2);
    }
  }
  return;
}
}

