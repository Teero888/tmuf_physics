// Class implementation: GmMap2_unsigned_char

// =================================================
// Function: GmMap2<unsigned_char>::GetValue
// =================================================
GmVec3 __thiscall
GmMap2<unsigned_char>::GetValue(void *this,CFuncColorGradient *param_1,float param_2)
{
{
  uint uVar1;
  SCasterCat *pSVar2;
  bool bVar3;
  uint local_8;
  
  local_8 = (uint)(longlong)ROUND((*(float *)param_1 - *(float *)((int)this + 8)) / *(float *)this);
  uVar1 = local_8;
  bVar3 = local_8 < *(uint *)((int)this + 0x10);
  local_8 = (uint)(longlong)
                  ROUND((*(float *)(param_1 + 4) - *(float *)((int)this + 0xc)) /
                        *(float *)((int)this + 4));
  if ((bVar3) && (local_8 < *(uint *)((int)this + 0x14))) {
    pSVar2 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                       ((void *)((int)this + 0x1c),
                        (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                        (*(uint *)((int)this + 0x10) * local_8 + uVar1),(ulong)param_2);
    return SUB41(pSVar2,0);
  }
  return (GmVec3)((char)this + '\x18');
}
}

// =================================================
// Function: GmMap2<unsigned_char>::GmMap2<unsigned_char>
// =================================================
void __thiscall
GmMap2<unsigned_char>::GmMap2<unsigned_char>(void *this,GmMap2<unsigned_char> *param_1)
{
{
  CFastArray<class_CManoeuvre*> *unaff_ESI;
  
  CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>((void *)((int)this + 0x1c),unaff_ESI)
  ;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  return;
}
}

// =================================================
// Function: GmMap2<unsigned_char>::Init
// =================================================
void __thiscall
GmMap2<unsigned_char>::Init
          (void *this,CLoadGeomDynaSprite *param_1,CPlugVisualSprite *param_2,
          CVisionViewportDx9 *param_3,ESpriteColor0 *param_4)
{
{
  undefined4 uVar1;
  ulong unaff_retaddr;
  
  *(undefined4 *)((int)this + 8) = *(undefined4 *)param_1;
  *(undefined4 *)((int)this + 0xc) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)this = *(undefined4 *)param_2;
  *(undefined4 *)((int)this + 4) = *(undefined4 *)(param_2 + 4);
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)param_3;
  *(undefined4 *)((int)this + 0x14) = uVar1;
  *(char *)((int)this + 0x18) = (char)*param_4;
  CFastArray<char>::SetCount
            ((CFastArray<char> *)((int)this + 0x1c),
             (CFastBuffer<class_CSystemFidsFolder*> *)
             (*(int *)((int)this + 0x14) * *(int *)((int)this + 0x10)),unaff_retaddr);
  return;
}
}

// =================================================
// Function: GmMap2<unsigned_char>::IsInside
// =================================================
ulong __thiscall GmMap2<unsigned_char>::IsInside(void *this,GmRectAligned *param_1,GmVec2 *param_2)
{
{
  bool bVar1;
  uint local_8;
  
  local_8 = (uint)(longlong)ROUND((*(float *)param_1 - *(float *)((int)this + 8)) / *(float *)this);
  bVar1 = local_8 < *(uint *)((int)this + 0x10);
  local_8 = (uint)(longlong)
                  ROUND((*(float *)(param_1 + 4) - *(float *)((int)this + 0xc)) /
                        *(float *)((int)this + 4));
  if ((bVar1) && (local_8 < *(uint *)((int)this + 0x14))) {
    return 1;
  }
  return 0;
}
}

// =================================================
// Function: GmMap2<unsigned_char>::SetValue
// =================================================
void __thiscall GmMap2<unsigned_char>::SetValue(void *this,CMwCmdAffectParamBool *param_1)
{
{
  SCasterCat *pSVar1;
  ulong unaff_retaddr;
  SCasterCat *in_stack_0000000c;
  
  pSVar1 = CFastBuffer<struct_CPlugVisual::SSkinIndex>::operator[]
                     ((void *)((int)this + 0x1c),
                      (CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)
                      (*(int *)(param_1 + 4) * *(int *)((int)this + 0x10) + *(int *)param_1),
                      unaff_retaddr);
  *pSVar1 = *in_stack_0000000c;
  return;
}
}

