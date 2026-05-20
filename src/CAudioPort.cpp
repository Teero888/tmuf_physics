// Class implementation: CAudioPort

// =================================================
// Function: CAudioPort::AddSound
// =================================================
CAudioSound * __thiscall
CAudioPort::AddSound
          (CAudioPort *this,CAudioPort *param_1,CPlugSound *param_2,EBalanceGroup param_3,
          int param_4)
{
{
  EBalanceGroup EVar1;
  int iVar2;
  CAudioPort *extraout_EAX;
  undefined4 uVar3;
  ulong unaff_EBX;
  CPlugSound *unaff_EDI;
  CAudioPort *pCVar4;
  
  pCVar4 = param_1;
  if (param_1 != (CAudioPort *)0x0) {
    iVar2 = (**(code **)(*(int *)this + 0x88))();
    if (iVar2 != 0) {
      CreateSound(this,(CSceneSoundSource *)pCVar4,unaff_EDI);
      EVar1 = param_3;
      if (extraout_EAX != (CAudioPort *)0x0) {
        *(EBalanceGroup *)(extraout_EAX + 0x68) = param_3;
        if ((param_4 == 0) || (*(int *)(this + 0x14) == 2)) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        *(undefined4 *)(extraout_EAX + 0x48) = uVar3;
        pCVar4 = extraout_EAX;
        iVar2 = (**(code **)(*(int *)this + 0x94))();
        if (iVar2 == 0) {
          (**(code **)(*(int *)extraout_EAX + 4))(1);
          return (CAudioSound *)0x0;
        }
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (this + 0x48,(TiXmlAttributeSet *)&param_1,(TiXmlAttribute *)pCVar4);
        if ((*(int *)(this + 0x3c) != 0) && (EVar1 == 1)) {
          AutoBalance_Add(this,extraout_EAX,(CAudioSound *)0xffffffff,unaff_EBX);
        }
        return (CAudioSound *)extraout_EAX;
      }
    }
  }
  return (CAudioSound *)0x0;
}
}

// =================================================
// Function: CAudioPort::AutoBalance_Add
// =================================================
void __thiscall
CAudioPort::AutoBalance_Add(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3)
{
{
  CAudioPort *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_EBP;
  ulong unaff_ESI;
  CAudioSound *unaff_EDI;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_4 = 0;
  this_00 = this + 0x6c;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           FindAutoBalanceSound
                     ((CFastBuffer<struct_CAudioPort::SAutoBalancedSound> *)param_1,unaff_EDI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    if (param_2 == (CAudioSound *)pCVar1) goto LAB_0079e874;
    pSVar2 = CFastBuffer<class_GxColor>::operator[](this_00,pCVar1,(ulong)unaff_EDI);
    local_8 = *(undefined4 *)(pSVar2 + 4);
    local_4 = *(undefined4 *)(pSVar2 + 8);
    CFastBuffer<class_GmQuat>::RemoveAt
              (this_00,(CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)pCVar1,1,
               unaff_ESI);
  }
  if (param_2 == (CAudioSound *)0xffffffff) {
    param_2 = (CAudioSound *)CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EBP);
  }
  CFastBuffer<struct_CAudioPort::SAutoBalancedSound>::InsertElemAt
            (this_00,(CFastBuffer<struct_CInputDevice::SRumble> *)param_2,(ulong)&local_8,
             (SRumble *)unaff_EBP);
LAB_0079e874:
  *(undefined4 *)(param_1 + 0x70) = 1;
  return;
}
}

// =================================================
// Function: CAudioPort::AutoBalance_Sub
// =================================================
void __thiscall
CAudioPort::AutoBalance_Sub(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2)
{
{
  CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *pCVar1;
  CAudioSound *unaff_ESI;
  
  pCVar1 = (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)
           FindAutoBalanceSound
                     ((CFastBuffer<struct_CAudioPort::SAutoBalancedSound> *)param_1,unaff_ESI);
  if (pCVar1 != (CFastBuffer<struct_CNetClient::SQueuedNetConnectionLessNod> *)0xffffffff) {
    CFastBuffer<class_GmQuat>::RemoveAt(this + 0x6c,pCVar1,1,(ulong)unaff_ESI);
  }
  *(undefined4 *)(param_1 + 0x70) = 0;
  return;
}
}

// =================================================
// Function: CAudioPort::CleanPlayablePlugSounds
// =================================================
void __thiscall
CAudioPort::CleanPlayablePlugSounds
          (CAudioPort *this,CAudioPort *param_1,int param_2,CPlugSound *param_3)
{
{
  CAudioPort *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SCasterCat *pSVar2;
  CHmsSoundSource *unaff_EBX;
  CAudioPort *unaff_EBP;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *unaff_ESI;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar3;
  CFastBuffer<class_CCrystalFace*> *unaff_EDI;
  int in_stack_00000010;
  ulong uVar4;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar5;
  CAudioPort *in_stack_ffffffe8;
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aca888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (&stack0xffffffe8,
             (CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffd8));
  this_00 = this + 0x48;
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_EDI);
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      uVar4 = 0x79df80;
      pCVar5 = pCVar3;
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (this_00,pCVar3,(ulong)unaff_ESI);
      if (*(int *)(*(int *)pSVar2 + 0x60) != 0) {
        if (in_stack_00000010 == 0) {
          pCVar5 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x79df97;
          unaff_ESI = pCVar3;
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                             (this_00,pCVar3,(ulong)unaff_EBP);
          if (*(int *)(*(int *)pSVar2 + 0x50) != 0) goto LAB_0079dfcb;
        }
        if (param_2 != 0) {
          pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,uVar4);
          if (*(CPlugSound **)(*(int *)pSVar2 + 0x44) != param_3) goto LAB_0079dfcb;
        }
        pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[](this_00,pCVar3,uVar4);
        CFastBuffer<class_CDx9TextureKeeper*>::Add
                  (auStack_14,(TiXmlAttributeSet *)pSVar2,(TiXmlAttribute *)pCVar5);
      }
LAB_0079dfcb:
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           CFastBuffer<class_CCrystalFace*>::GetCount
                     (auStack_10,(CFastBuffer<class_CCrystalFace*> *)unaff_ESI);
  pCVar3 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0;
  if (pCVar1 != (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0x0) {
    do {
      pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                         (&local_c,pCVar3,(ulong)unaff_EBP);
      DetachHmsSoundFromAudio(unaff_EBX,in_stack_ffffffe8);
      *(undefined4 *)(*(int *)pSVar2 + 0x58) = 0;
      unaff_EBP = *(CAudioPort **)pSVar2;
      RemoveSound(this,unaff_EBP,(CAudioSound *)unaff_EBX);
      pCVar3 = pCVar3 + 1;
    } while (pCVar3 < pCVar1);
  }
  CFastBuffer<class_CPlugFileGPUV*>::~CFastBuffer<class_CPlugFileGPUV*>
            (&local_c,(CFastBuffer<class_CPlugFileGPUV*> *)unaff_EBP);
  ExceptionList = param_1;
  return;
}
}

// =================================================
// Function: CAudioPort::CreateSound
// =================================================
void __thiscall
CAudioPort::CreateSound(CAudioPort *this,CSceneSoundSource *param_1,CPlugSound *param_2)
{
{
  CAudioPort *pCVar1;
  int iVar2;
  CAudioSoundEngine *this_00;
  CAudioSoundSurface *this_01;
  CAudioSoundMulti *this_02;
  ulong uVar3;
  CAudioMusic *this_03;
  CAudioSound *this_04;
  void *unaff_ESI;
  CAudioPort *pCVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00aca827;
  local_c = ExceptionList;
  pCVar1 = (CAudioPort *)(DAT_00cca150 ^ (uint)&stack0xffffffec);
  ExceptionList = &local_c;
  pCVar4 = (CAudioPort *)0x908e000;
  iVar2 = (**(code **)(*(int *)param_1 + 0x10))();
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x905e000);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x9064000);
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)param_1 + 0x10))(0x901c000);
        if ((iVar2 != 0) &&
           (uVar3 = CMwRefBuffer::GetCount
                              (*(CMwRefBuffer **)(param_1 + 0x74),
                               (CFastBuffer<class_CCrystalFace*> *)pCVar4), uVar3 != 0)) {
          this_03 = operator_new(0x80);
          uStack_4 = 3;
          if (this_03 == (CAudioMusic *)0x0) {
            ExceptionList = unaff_ESI;
            return;
          }
          CAudioMusic::CAudioMusic(this_03,(CAudioMusic *)param_1,(CPlugMusic *)this,pCVar1);
          ExceptionList = puStack_8;
          return;
        }
        this_04 = operator_new(0x78);
        puStack_8 = (undefined1 *)0x4;
        if (this_04 != (CAudioSound *)0x0) {
          CAudioSound::CAudioSound(this_04,(CAudioSound *)param_1,(CPlugSound *)this,pCVar4);
          ExceptionList = local_c;
          return;
        }
      }
      else {
        this_02 = operator_new(0x7c);
        puStack_8 = (undefined1 *)0x2;
        if (this_02 != (CAudioSoundMulti *)0x0) {
          CAudioSoundMulti::CAudioSoundMulti
                    (this_02,(CAudioSoundMulti *)param_1,(CPlugSoundMulti *)this,pCVar4);
          ExceptionList = local_c;
          return;
        }
      }
    }
    else {
      this_01 = operator_new(0x88);
      puStack_8 = (undefined1 *)0x1;
      if (this_01 != (CAudioSoundSurface *)0x0) {
        CAudioSoundSurface::CAudioSoundSurface
                  (this_01,(CAudioSoundSurface *)param_1,(CPlugSoundSurface *)this,pCVar4);
        ExceptionList = local_c;
        return;
      }
    }
  }
  else {
    this_00 = operator_new(0x174);
    puStack_8 = (undefined1 *)0x0;
    if (this_00 != (CAudioSoundEngine *)0x0) {
      CAudioSoundEngine::CAudioSoundEngine
                (this_00,(CAudioSoundEngine *)param_1,(CPlugSoundEngine *)this,pCVar4);
      ExceptionList = local_c;
      return;
    }
  }
  ExceptionList = unaff_ESI;
  return;
}
}

// =================================================
// Function: CAudioPort::Fade
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CAudioPort::Fade(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,
                float param_4,float param_5,int param_6)
{
{
  STmRaceLowFps *unaff_ESI;
  
  if (param_1 != (CAudioPort *)0x0) {
    if ((param_5 != 0.0) && (_DAT_00b41d80 <= param_3)) {
      param_3 = 0.0;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      if (param_4 < _DAT_00b9a0d0 == (param_4 == _DAT_00b9a0d0)) {
        InternalFade(this,param_1,param_2,param_3,param_4,param_5,(int)unaff_ESI);
        return;
      }
      if ((param_3 < _DAT_00b41d80) && (param_5 != 0.0)) {
        CAudioSound::Stop((CAudioSound *)param_1,unaff_ESI);
        return;
      }
    }
  }
  return;
}
}

// =================================================
// Function: CAudioPort::FadePlay
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CAudioPort::FadePlay(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3)
{
{
  int unaff_ESI;
  EPlugVideoTimer unaff_EDI;
  ulong unaff_retaddr;
  float in_stack_00000014;
  
  if (param_1 != (CAudioPort *)0x0) {
    if (*(int *)(param_1 + 0x50) == 0) {
      CAudioSound::Play((CAudioSound *)param_1,_DAT_00b2c060,unaff_EDI,unaff_ESI,unaff_retaddr);
    }
    Fade(this,param_1,(CAudioSound *)0x0,1.0,in_stack_00000014,0.0,(int)param_1);
  }
  return;
}
}

// =================================================
// Function: CAudioPort::FadeStop
// =================================================
void __thiscall
CAudioPort::FadeStop
          (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,int param_4)
{
{
  int unaff_retaddr;
  
  if (param_1 != (CAudioPort *)0x0) {
    if (param_3 != 0.0) {
      *(undefined4 *)(param_1 + 0x5c) = 1;
    }
    Fade(this,param_1,(CAudioSound *)0x3f800000,0.0,(float)param_2,1.4013e-45,unaff_retaddr);
  }
  return;
}
}

// =================================================
// Function: CAudioPort::GetNbMaxSounds
// =================================================
ulong __thiscall CAudioPort::GetNbMaxSounds(CAudioPort *this,COalAudioPort *param_1)
{
{
  return *(ulong *)(this + 0x20);
}
}

// =================================================
// Function: CAudioPort::InternalFade
// =================================================
void __thiscall
CAudioPort::InternalFade
          (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,float param_3,float param_4,
          float param_5,int param_6)
{
{
  CAudioPort *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SLoadedLight *this_01;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  GmFrustumIso4 *unaff_ESI;
  CAudioSound *unaff_EDI;
  float in_stack_0000001c;
  undefined4 in_stack_00000020;
  
  this_00 = this + 0x60;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           FindFadingSound((CFastBuffer<struct_CAudioPort::SFadingSound> *)param_1,unaff_EDI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
    this_01 = CFastBuffer<struct_CAudioPort::SFadingSound>::AddNewElem
                        (this_00,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)param_1);
    SFadingSound::Reset(this_01,unaff_ESI);
  }
  pSVar2 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[](this_00,pCVar1,unaff_EBX);
  if (*(int *)(pSVar2 + 0xc) != 0) {
    if (*(float *)(pSVar2 + 0x1c) <= param_5) {
      *(float *)(pSVar2 + 0x1c) = *(float *)(pSVar2 + 0x1c);
      return;
    }
    *(float *)(pSVar2 + 0x1c) = param_5;
    return;
  }
  *(undefined4 *)(pSVar2 + 0xc) = in_stack_00000020;
  *(float *)(pSVar2 + 8) = 1.0 / in_stack_0000001c;
  *(int *)(pSVar2 + 0x10) = param_6;
  *(float *)(pSVar2 + 0x1c) = param_5;
  return;
}
}

// =================================================
// Function: CAudioPort::RemoveSound
// =================================================
void __thiscall CAudioPort::RemoveSound(CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2)
{
{
  CFastBufferRef<class_CGameMobil> *pCVar1;
  CAudioSound *unaff_EBX;
  STmRaceLowFps *unaff_EBP;
  CAudioSound *unaff_ESI;
  GxTexCoordSet *unaff_EDI;
  int iStack0000000c;
  CFastBufferRef<class_CGameMobil> *in_stack_00000010;
  ulong uVar2;
  
  if (param_1 != (CAudioPort *)0x0) {
    CAudioSound::Stop((CAudioSound *)param_1,unaff_EBP);
    iStack0000000c =
         CFastArray<class_CGameMenuFrame*>::Find
                   (this + 0x48,(CFastArray<class_GxTexCoordSet> *)&param_2,unaff_EDI);
    if (iStack0000000c != -1) {
      pCVar1 = (CFastBufferRef<class_CGameMobil> *)
               FindFadingSound((CFastBuffer<struct_CAudioPort::SFadingSound> *)param_1,unaff_EBX);
      if (pCVar1 != (CFastBufferRef<class_CGameMobil> *)0xffffffff) {
        CFastBuffer<struct_CControlListMap2::SControlElem>::ReplaceByLastAt
                  (this + 0x60,pCVar1,1,(ulong)unaff_EBX);
      }
      AutoBalance_Sub(this,param_1,unaff_ESI);
      uVar2 = 1;
      (**(code **)(*(int *)param_1 + 4))();
      CFastBuffer<class_CNetHttpResult*>::ReplaceByLastAt(this + 0x48,in_stack_00000010,1,uVar2);
    }
  }
  return;
}
}

// =================================================
// Function: CAudioPort::SetSecondaryVolume
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall
CAudioPort::SetSecondaryVolume
          (CAudioPort *this,CAudioPort *param_1,CAudioSound *param_2,ulong param_3,float param_4)
{
{
  CAudioPort *this_00;
  CFastBuffer<struct_CVisionHmsZone::SCasterCat> *pCVar1;
  SLoadedLight *this_01;
  SCasterCat *pSVar2;
  ulong unaff_EBX;
  GmFrustumIso4 *unaff_ESI;
  CAudioSound *unaff_EDI;
  int in_stack_00000014;
  undefined4 in_stack_00000018;
  
  this_00 = this + 0x60;
  pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
           FindFadingSound((CFastBuffer<struct_CAudioPort::SFadingSound> *)param_1,unaff_EDI);
  if (pCVar1 == (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)0xffffffff) {
    if (ABS((float)param_3 - (float)_DAT_00b2c188) < _DAT_00b9a0d0) {
      return;
    }
    pCVar1 = (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
             CFastBuffer<class_CCrystalFace*>::GetCount
                       (this_00,(CFastBuffer<class_CCrystalFace*> *)unaff_EDI);
    this_01 = CFastBuffer<struct_CAudioPort::SFadingSound>::AddNewElem
                        (this_00,(CFastBuffer<struct_CVisionViewportDx9::SLoadedLight> *)param_1);
    SFadingSound::Reset(this_01,unaff_ESI);
  }
  pSVar2 = CFastBuffer<struct_CVisionHmsZone::SCasterCat>::operator[](this_00,pCVar1,unaff_EBX);
  *(undefined4 *)(pSVar2 + in_stack_00000014 * 4 + 0x10) = in_stack_00000018;
  return;
}
}

