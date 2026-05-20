// Class implementation: CMotionWeather

// =================================================
// Function: CMotionWeather::CMotionWeather
// =================================================
void __thiscall CMotionWeather::CMotionWeather(CMotionWeather *this,CMotionWeather *param_1)
{
{
  CMotionManaged *unaff_ESI;
  CFastBuffer<class_CPlugFileSndGen*> *unaff_retaddr;
  
  CMotionManaged::CMotionManaged((CMotionManaged *)this,unaff_ESI);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x24,unaff_retaddr);
  *(undefined4 *)(this + 0x34) = 4;
  *(undefined4 *)(this + 0x30) = 0;
  return;
}
}

// =================================================
// Function: CMotionWeather::ChangeClouds
// =================================================
void __cdecl CMotionWeather::ChangeClouds(CSceneMobilClouds *param_1,CFuncWeather *param_2)
{
{
  int iVar1;
  bool bVar2;
  CFastBuffer<class_GxVertex2> *pCVar3;
  SCasterCat *pSVar4;
  EArchive unaff_EBX;
  CSystemFid *unaff_EBP;
  ulong unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CSceneMobilClouds *in_stack_0000000c;
  undefined4 in_stack_00000010;
  
  if ((*(int *)(param_2 + 0xa0) == 0) && (*(int *)(param_2 + 0x9c) == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  iVar1 = *(int *)(param_2 + 0xe4);
  pCVar3 = (CFastBuffer<class_GxVertex2> *)
           CFastBuffer<class_CCrystalFace*>::GetCount((void *)(iVar1 + 0x24),unaff_EDI);
  CFastBufferRef<class_CPlugSolid>::AllocSetCount((void *)(!bVar2 + 0x48),pCVar3,unaff_ESI);
  pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar3 != (CFastBuffer<class_GxVertex2> *)0x0) {
    do {
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(iVar1 + 0x24),pCVar5,(ulong)unaff_EBP);
      unaff_EBP = (CSystemFid *)&DAT_00000007;
      pSVar4 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         ((void *)(!bVar2 + 0x48),pCVar5,*(ulong *)pSVar4);
      CSystemArchiveNod::LoadFromFid<class_CPlugSolid>
                ((CMwNodRef<class_CPlugSolid> *)pSVar4,unaff_EBP,unaff_EBX);
      pCVar5 = pCVar5 + 1;
    } while (pCVar5 < pCVar3);
  }
  *(undefined4 *)(in_stack_0000000c + 0x70) = in_stack_00000010;
  if (param_1 != *(CSceneMobilClouds **)(in_stack_0000000c + 0x54)) {
    if (param_1 != (CSceneMobilClouds *)0x0) {
      CMwNod::MwAddRef((CMwNod *)param_1,(CMwNod *)unaff_EBP);
    }
    if (*(CMwNod **)(in_stack_0000000c + 0x54) != (CMwNod *)0x0) {
      CMwNod::MwRelease(*(CMwNod **)(in_stack_0000000c + 0x54),(CMwNod *)unaff_EBP);
    }
    *(CSceneMobilClouds **)(in_stack_0000000c + 0x54) = param_1;
  }
  CSceneMobilClouds::BuildInstances(in_stack_0000000c,in_stack_0000000c);
  return;
}
}

// =================================================
// Function: CMotionWeather::ChangeMaterial
// =================================================
void __thiscall
CMotionWeather::ChangeMaterial
          (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3)
{
{
  CMotionWeather *this_00;
  CPlugTree *this_01;
  ulong uVar1;
  CSystemFid *pCVar2;
  SCasterCat *pSVar3;
  CSceneToySea *unaff_EBX;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  CPlugMaterialCustom *unaff_ESI;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar4;
  CPlugShader *unaff_retaddr;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCStack00000010;
  
  this_00 = this + 0x24;
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  if (uVar1 != 0) {
    if (*(int *)(this + 0x34) == 0) {
      pCVar2 = *(CSystemFid **)(param_2 + param_3 * 4 + 0x18);
    }
    else {
      pCVar2 = *(CSystemFid **)(param_2 + *(int *)(this + 0x34) * 4 + 0x24);
    }
    CSystemArchiveNod::LoadFromFid((CMwNod **)&param_2,pCVar2,7);
    pCStack00000010 =
         (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
         CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
    pCVar4 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
    if (pCStack00000010 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
      do {
        pSVar3 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                           (this_00,pCVar4,(ulong)unaff_ESI);
        this_01 = *(CPlugTree **)pSVar3;
        unaff_ESI = (CPlugMaterialCustom *)pCStack00000010;
        CPlugTree::SetMaterial
                  (this_01,(CPlugMaterialCustom *)pCStack00000010,(CPlugMaterial *)unaff_EBX);
        if (*(int *)(this + 0x34) != 0) {
          unaff_EBX = *(CSceneToySea **)(this_01 + 0x94);
          unaff_ESI = (CPlugMaterialCustom *)0x574b5d;
          CSceneToySea::UpdateShaderFromHoule
                    (*(CSceneToySea **)(this + 0x18),unaff_EBX,unaff_retaddr);
        }
        pCVar4 = pCVar4 + 1;
      } while (pCVar4 < pCStack00000010);
    }
  }
  return;
}
}

// =================================================
// Function: CMotionWeather::GetSkyGradVBitmapAdr
// =================================================
int __thiscall
CMotionWeather::GetSkyGradVBitmapAdr
          (CMotionWeather *this,CMotionWeather *param_1,CPlugBitmapAddress **param_2)
{
{
  CPlugShader *this_00;
  ulong uVar1;
  SCasterCat *pSVar2;
  CPlugBitmapAddress *pCVar3;
  ulong unaff_ESI;
  undefined4 *in_stack_00000018;
  char *in_stack_ffffffec;
  CFastString *in_stack_fffffff0;
  SHeaderCommunity *pSVar4;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  local_8 = &LAB_00a98b58;
  if (*(int *)(this + 0x34) == 0) {
    pSVar4 = ExceptionList;
    ExceptionList = &stack0xfffffff4;
    uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount
                      (this + 0x24,
                       (CFastBuffer<class_CCrystalFace*> *)(DAT_00cca150 ^ (uint)&stack0xffffffe8));
    if (uVar1 != 0) {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this + 0x24,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                          unaff_ESI);
      this_00 = *(CPlugShader **)(*(int *)pSVar2 + 0x94);
      if (this_00 != (CPlugShader *)0x0) {
        CFastString::CFastString
                  ((CFastString *)&stack0xfffffff4,(CFastString *)"GradientV",in_stack_ffffffec);
        param_2 = (CPlugBitmapAddress **)0x0;
        pCVar3 = CPlugShader::FindLayerByName(this_00,(CPlugShader *)&local_8,in_stack_fffffff0);
        CGameCtnChallenge::SHeaderCommunity::~SHeaderCommunity(&local_4,pSVar4);
        if (pCVar3 != (CPlugBitmapAddress *)0x0) {
          *in_stack_00000018 = pCVar3;
          ExceptionList = (void *)0x0;
          return 1;
        }
      }
    }
  }
  ExceptionList = param_2;
  return 0;
}
}

// =================================================
// Function: CMotionWeather::GetTreeSea
// =================================================
int __thiscall
CMotionWeather::GetTreeSea(CMotionWeather *this,CMotionWeather *param_1,CPlugTree **param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  undefined4 *in_stack_0000000c;
  
  if ((*(int *)(this + 0x34) != 1) && (*(int *)(this + 0x34) != 2)) {
    return 0;
  }
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x24,unaff_ESI);
  if (uVar1 == 0) {
    return 0;
  }
  pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                     (this + 0x24,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0,
                      unaff_retaddr);
  *in_stack_0000000c = *(undefined4 *)pSVar2;
  return 1;
}
}

// =================================================
// Function: CMotionWeather::GetTreeStars
// =================================================
int __thiscall
CMotionWeather::GetTreeStars(CMotionWeather *this,CMotionWeather *param_1,CPlugTree **param_2)
{
{
  if ((*(int *)(this + 0x34) == 0) && (*(int *)(this + 0x30) != 0)) {
    *(int *)param_1 = *(int *)(this + 0x30);
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: CMotionWeather::OnDayTimeChange
// =================================================
void __thiscall
CMotionWeather::OnDayTimeChange
          (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3)
{
{
  if (*(int *)(this + 0x34) != 3) {
    ChangeMaterial(this,param_1,param_2,param_3);
    return;
  }
  return;
}
}

// =================================================
// Function: CMotionWeather::OnWeatherChange
// =================================================
void __thiscall
CMotionWeather::OnWeatherChange
          (CMotionWeather *this,CMotionWeather *param_1,CFuncWeather *param_2,EDayTime4 param_3)
{
{
  if (*(int *)(this + 0x34) != 3) {
    ChangeMaterial(this,param_1,param_2,param_3);
    return;
  }
  if (*(int *)(param_1 + 0xe4) != 0) {
    ChangeClouds(*(CSceneMobilClouds **)(this + 0x18),(CFuncWeather *)param_1);
  }
  return;
}
}

