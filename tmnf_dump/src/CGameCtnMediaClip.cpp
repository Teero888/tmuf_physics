// Class implementation: CGameCtnMediaClip

// =================================================
// Function: CGameCtnMediaClip::CreateFromGhosts
// =================================================
CGameCtnMediaClip * __cdecl
CGameCtnMediaClip::CreateFromGhosts(CFastBufferRef<class_CGameCtnGhost> *param_1,int param_2)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CGameCtnMediaClip *pCVar3;
  TiXmlAttribute *unaff_EBX;
  TiXmlAttributeSet *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_00000010;
  undefined1 local_18 [8];
  undefined4 local_10;
  void *local_c;
  undefined1 *local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  local_8 = &LAB_00aaf7c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (local_18,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd8)
            );
  pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)param_2,unaff_EDI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)param_2,pCVar4,(ulong)unaff_ESI);
      local_10 = *(undefined4 *)pSVar2;
      unaff_ESI = (TiXmlAttributeSet *)&local_10;
      CFastBuffer<class_CDx9TextureKeeper*>::Add(&local_c,unaff_ESI,unaff_EBX);
      pCVar4 = pCVar4 + 1;
    } while (pCVar4 < pCVar1);
  }
  pCVar3 = CreateFromGhosts((CFastBufferRef<class_CGameCtnGhost> *)&local_10,in_stack_00000010);
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&local_10,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_ESI);
  ExceptionList = (void *)0x0;
  return pCVar3;
}
}

// =================================================
// Function: CGameCtnMediaClip::GetMediaBlockEndMax
// =================================================
float __thiscall
CGameCtnMediaClip::GetMediaBlockEndMax(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1)
{
{
  int iVar1;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar2;
  SCasterCat *pSVar3;
  ulong uVar4;
  ulong unaff_EBX;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  float10 fVar6;
  float fStack_4;
  
  pCVar2 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar2 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar5,unaff_ESI);
      iVar1 = *(int *)pSVar3;
      unaff_ESI = 0x6742d4;
      uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                        ((void *)(iVar1 + 0x1c),(CFastBuffer<class_CCrystalFace*> *)unaff_EBP);
      if (uVar4 != 0) {
        unaff_EBP = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)(uVar4 - 1);
        unaff_ESI = 0x6742e3;
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           ((void *)(iVar1 + 0x1c),unaff_EBP,unaff_EBX);
        unaff_EBX = 0x6742ef;
        fVar6 = (float10)(**(code **)(**(int **)pSVar3 + 0xa4))();
        if (fStack_4 < (float)fVar6) {
          fStack_4 = (float)fVar6;
        }
      }
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar2);
  }
  return fStack_4;
}
}

// =================================================
// Function: CGameCtnMediaClip::KeepPlayingGet
// =================================================
int __thiscall CGameCtnMediaClip::KeepPlayingGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1)
{
{
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,unaff_EDI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x14,pCVar3,unaff_ESI);
      if (*(int *)(*(int *)pSVar2 + 0x28) != 0) {
        return 1;
      }
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  return 0;
}
}

// =================================================
// Function: CGameCtnMediaClip::StartTimeGet
// =================================================
float __thiscall CGameCtnMediaClip::StartTimeGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1)
{
{
  return *(float *)(this + 0x3c);
}
}

// =================================================
// Function: CGameCtnMediaClip::StopTimeGet
// =================================================
float __thiscall CGameCtnMediaClip::StopTimeGet(CGameCtnMediaClip *this,CGameCtnMediaClip *param_1)
{
{
  float fVar1;
  
  if (0.0 < *(float *)(this + 0x40)) {
    return *(float *)(this + 0x40);
  }
  fVar1 = GetMediaBlockEndMax(this,param_1);
  return fVar1;
}
}

