// Class implementation: CControlQuad

// =================================================
// Function: CControlQuad::AddMargin
// =================================================
void __thiscall
CControlQuad::AddMargin(CControlQuad *this,CControlQuad *param_1,GmBoxAligned *param_2)
{
{
  float fVar1;
  CFuncEnum *pCVar2;
  CMwNod *pCVar3;
  CControlQuad *unaff_ESI;
  CControlQuad *unaff_EDI;
  void *in_stack_0000000c;
  GmVec3 *in_stack_ffffffe0;
  GmVec3 *in_stack_ffffffe4;
  float local_10;
  float local_c;
  float local_8;
  GmBoxAligned local_4 [4];
  
  if (*(int *)(this + 0x140) != -1) {
    pCVar2 = QuadGetIcons(unaff_EDI);
    if (pCVar2 != (CFuncEnum *)0x0) {
      CControlBase::GetControlDrawTree((CControlBase *)this,(CControlBase *)0x0,(int)unaff_EDI);
      pCVar2 = QuadGetIcons(unaff_ESI);
      if (*(int *)(pCVar2 + 0x4c) != 0) {
        pCVar2 = QuadGetIcons(unaff_ESI);
        pCVar3 = CMwRefBuffer::GetFromId
                           (*(CMwRefBuffer **)(pCVar2 + 0x4c),(CMwRefBuffer *)(this + 0x140),
                            (CMwId *)unaff_ESI);
        if (pCVar3 != (CMwNod *)0x0) {
          fVar1 = *(float *)(pCVar3 + 0x3c);
          GmBoxAligned::GetMinMax(in_stack_0000000c,local_4,(GmVec3 *)&local_10,in_stack_ffffffe0);
          local_c = local_c + fVar1;
          local_8 = local_10 + local_8;
          GmBoxAligned::SetMinMax
                    (in_stack_0000000c,(GmBoxAligned *)&stack0x00000000,(GmVec3 *)&local_c,
                     in_stack_ffffffe4);
        }
      }
    }
  }
  return;
}
}

// =================================================
// Function: CControlQuad::CControlQuad
// =================================================
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CControlQuad::CControlQuad(CControlQuad *this,CControlQuad *param_1)
{
{
  undefined4 uVar1;
  CMwId *unaff_EDI;
  void *local_c;
  undefined1 *local_8;
  void *local_4;
  
  local_4 = (void *)0xffffffff;
  local_8 = &LAB_00ac6bc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CControlBase::CControlBase
            ((CControlBase *)this,(CControlBase *)(DAT_00cca150 ^ (uint)&stack0xffffffe4));
  *(undefined ***)this = vftable;
  CMwId::CMwId(this + 0x140,unaff_EDI);
  uVar1 = _DAT_00b2c060;
  *(undefined4 *)(this + 0x120) = _DAT_00b2c060;
  *(undefined4 *)(this + 0x124) = uVar1;
  *(undefined4 *)(this + 300) = 0;
  *(undefined4 *)(this + 0x130) = 0;
  *(uint *)(this + 0xfc) = *(uint *)(this + 0xfc) & 0xfffff7d7 | 2;
  *(undefined4 *)(this + 0x134) = 0;
  *(undefined4 *)(this + 0x138) = 0;
  *(undefined4 *)(this + 0x13c) = 0;
  *(undefined4 *)(this + 0x128) = 2;
  ExceptionList = local_4;
  return;
}
}

