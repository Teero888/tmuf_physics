// Class implementation: STmRaceLowFps

// =================================================
// Function: STmRaceLowFps::ResetFrames
// =================================================
void __thiscall STmRaceLowFps::ResetFrames(void *this,STmRaceLowFps *param_1)
{
{
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage> *unaff_ESI;
  
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  CFastBufferWheel<struct_CGamePlaygroundInterface::SAvatarMessage>::ClearWheel
            ((void *)((int)this + 0xc),unaff_ESI);
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  return;
}
}

// =================================================
// Function: STmRaceLowFps::Start
// =================================================
void __thiscall STmRaceLowFps::Start(void *this,CGameCtnBench *param_1)
{
{
  CPlugAudio *this_00;
  CMwId *pCVar1;
  STmRaceLowFps *unaff_ESI;
  CPlugAudio *unaff_retaddr;
  
  if (*(int *)this == 0) {
    ResetFrames(this,unaff_ESI);
    this_00 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
    if (this_00 == (CPlugAudio *)0x0) {
      this_00 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
    }
    pCVar1 = CPlugAudio::MwGetId(this_00,unaff_retaddr);
    *(undefined4 *)((int)this + 0x20) = *(undefined4 *)pCVar1;
    *(undefined4 *)((int)this + 4) = 1;
    *(undefined4 *)((int)this + 8) = 1;
  }
  return;
}
}

// =================================================
// Function: STmRaceLowFps::Stop
// =================================================
void __thiscall STmRaceLowFps::Stop(void *this,STmRaceLowFps *param_1)
{
{
  *(undefined4 *)((int)this + 4) = 0;
  return;
}
}

// =================================================
// Function: STmRaceLowFps::StopAndReset
// =================================================
void __thiscall STmRaceLowFps::StopAndReset(void *this,STmRaceLowFps *param_1)
{
{
  void *this_00;
  STmRaceLowFps *unaff_ESI;
  STmRaceLowFps *unaff_retaddr;
  
  Stop(this,unaff_ESI);
  ResetFrames(this_00,unaff_retaddr);
  *(undefined4 *)this = 0;
  return;
}
}

// =================================================
// Function: STmRaceLowFps::UpdateAsync
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall STmRaceLowFps::UpdateAsync(void *this,CInputPortDx8 *param_1)
{
{
  void *this_00;
  CFastBuffer<class_CCrystalFace*> *pCVar1;
  float fVar2;
  CMwId *pCVar3;
  ulong uVar4;
  SBlockState *pSVar5;
  GmVec3 *pGVar6;
  uint uVar7;
  CPlugAudio *this_01;
  void *this_02;
  CFastBufferWheel<struct_CGameCtnMediaBlockEditorTriangles::SBlockState> *unaff_EBX;
  int iVar8;
  CPlugAudio *unaff_EBP;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  STmRaceLowFps *unaff_EDI;
  bool bVar9;
  CFastBufferWheel<class_GmVec3> *pCVar10;
  CFastBufferWheel<class_GmVec3> *in_stack_00000008;
  CFastBufferWheel<float> *in_stack_0000000c;
  float *in_stack_00000010;
  CFastBuffer<class_CCrystalFace*> *in_stack_00000014;
  CFastBufferWheel<class_GmVec3> *in_stack_00000018;
  CFastBuffer<class_CCrystalFace*> *in_stack_0000001c;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffff8;
  CFastBuffer<class_CCrystalFace*> *in_stack_fffffffc;
  
  if (*(int *)((int)this + 4) != 0) {
    bVar9 = DAT_00ccb5f0 != 0;
    iVar8 = *(int *)((int)this + 8);
    *(int *)((int)this + 8) = DAT_00ccb5f0;
    if (bVar9) {
      if (iVar8 == 0) {
        ResetFrames(this,unaff_EDI);
      }
      this_01 = *(CPlugAudio **)(DAT_00d731e0 + 0x14);
      if (this_01 == (CPlugAudio *)0x0) {
        this_01 = (CPlugAudio *)(DAT_00d731e0 + 0xa0);
      }
      pCVar3 = CPlugAudio::MwGetId(this_01,unaff_EBP);
      pCVar1 = *(CFastBuffer<class_CCrystalFace*> **)pCVar3;
      pCVar10 = *(CFastBufferWheel<class_GmVec3> **)(DAT_00d731e0 + 0x80);
      if ((*(CFastBuffer<class_CCrystalFace*> **)((int)this + 0x20) !=
           (CFastBuffer<class_CCrystalFace*> *)0xffffffff) &&
         (pCVar1 < *(CFastBuffer<class_CCrystalFace*> **)((int)this + 0x20))) {
        Stop(this,(STmRaceLowFps *)in_stack_fffffff8);
        in_stack_fffffff8 = (CFastBuffer<class_CCrystalFace*> *)0x4fd045;
        Start(this_02,(CGameCtnBench *)in_stack_fffffffc);
      }
      fVar2 = _DAT_00b4fbd8;
      *(CFastBuffer<class_CCrystalFace*> **)((int)this + 0x20) = pCVar1;
      if ((fVar2 < (float)pCVar10) ||
         (uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount
                            ((void *)((int)this + 0xc),in_stack_fffffff8), uVar4 != 0)) {
        this_00 = (void *)((int)this + 0xc);
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,unaff_ESI);
        if (uVar4 == 0) {
          iVar8 = -1;
        }
        else {
          pSVar5 = CFastBufferWheel<class_CPlugFileSndGen*>::Head(this_00,unaff_EBX);
          iVar8 = *(int *)pSVar5;
        }
        CFastBufferWheel<class_CPlugFileSndGen*>::Push
                  (this_00,(CFastBufferWheel<float> *)&stack0x0000000c,(float *)in_stack_fffffff8);
        uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_fffffffc);
        if (1 < uVar4) {
          if ((uint)((int)pCVar1 - iVar8) < 0x53) {
            *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + 1;
          }
          else {
            *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + 1;
          }
          pGVar6 = CFastBufferWheel<unsigned_long>::Tail(this_00,pCVar10);
          if (5000 < (uint)((int)pCVar1 - *(int *)pGVar6)) {
            if (*(uint *)((int)this + 0x24) < *(uint *)((int)this + 0x28)) {
              *(undefined4 *)this = 1;
              *(undefined4 *)((int)this + 4) = 0;
            }
            uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,pCVar1);
            while (1 < uVar7) {
              pGVar6 = CFastBufferWheel<unsigned_long>::Tail(this_00,in_stack_00000008);
              iVar8 = *(int *)pGVar6;
              if ((uint)((int)pCVar1 - iVar8) < 0x1389) {
                return;
              }
              in_stack_00000008 = (CFastBufferWheel<class_GmVec3> *)0x4fd10b;
              CFastBufferWheel<class_GmVec2>::Pull(this_00,in_stack_0000000c,in_stack_00000010);
              in_stack_00000010 = (float *)0x4fd112;
              uVar4 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_00000014);
              if (uVar4 != 0) {
                in_stack_00000014 = (CFastBuffer<class_CCrystalFace*> *)0x4fd11e;
                pGVar6 = CFastBufferWheel<unsigned_long>::Tail(this_00,in_stack_00000018);
                if ((uint)(*(int *)pGVar6 - iVar8) < 0x53) {
                  *(int *)((int)this + 0x24) = *(int *)((int)this + 0x24) + -1;
                }
                else {
                  *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + -1;
                }
              }
              in_stack_00000018 = (CFastBufferWheel<class_GmVec3> *)0x4fd138;
              uVar7 = CFastBuffer<class_CCrystalFace*>::GetCount(this_00,in_stack_0000001c);
            }
          }
        }
      }
    }
  }
  return;
}
}

