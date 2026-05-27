// Class implementation: CMwRefBuffer

// =================================================
// Function: CMwRefBuffer::AddTail
// =================================================
void __thiscall
CMwRefBuffer::AddTail
          (CMwRefBuffer *this,CFastArray<struct_CDx9DeviceCaps::SFormat> *param_1,SFormat *param_2)
{
{
  CFastArray<struct_CDx9DeviceCaps::SFormat> *this_00;
  int iVar1;
  CMwNod *unaff_EDI;
  
  this_00 = param_1;
  if (param_1 != (CFastArray<struct_CDx9DeviceCaps::SFormat> *)0x0) {
    if ((*(int *)(this + 0x24) != 0) &&
       (iVar1 = (**(code **)(*(int *)param_1 + 0x10))(*(int *)(this + 0x24)), iVar1 == 0)) {
      return;
    }
    if (*(int *)(this + 0x20) != 0) {
      CMwNod::MwAddRef((CMwNod *)this_00,unaff_EDI);
    }
    CFastBuffer<class_CDx9TextureKeeper*>::Add
              (this + 0x14,(TiXmlAttributeSet *)&param_1,(TiXmlAttribute *)unaff_EDI);
  }
  return;
}
}

// =================================================
// Function: CMwRefBuffer::CMwRefBuffer
// =================================================
void __thiscall CMwRefBuffer::CMwRefBuffer(CMwRefBuffer *this,CMwRefBuffer *param_1)
{
{
  CMwNod *unaff_ESI;
  CMwNod *unaff_retaddr;
  
  CMwNod::CMwNod((CMwNod *)this,unaff_ESI,unaff_retaddr);
  *(undefined ***)this = vftable;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this + 0x14,(CFastBuffer<class_CPlugFileSndGen*> *)param_1);
  *(undefined4 *)(this + 0x20) = 1;
  *(undefined4 *)(this + 0x24) = 0x1001000;
  return;
}
}

// =================================================
// Function: CMwRefBuffer::GetCount
// =================================================
ulong __thiscall
CMwRefBuffer::GetCount(CMwRefBuffer *this,CFastBuffer<class_CCrystalFace*> *param_1)
{
{
  ulong uVar1;
  
  uVar1 = CFastBuffer<class_CCrystalFace*>::GetCount(this + 0x14,param_1);
  return uVar1;
}
}

// =================================================
// Function: CMwRefBuffer::GetFromId
// =================================================
CMwNod * __thiscall CMwRefBuffer::GetFromId(CMwRefBuffer *this,CMwRefBuffer *param_1,CMwId *param_2)
{
{
  CMotionPlayer *pCVar1;
  
  pCVar1 = CFastBuffer<class_CMotionPlayer*>::GetNodFromId
                     (this + 0x14,(CFastBuffer<class_CMotionPlayer*> *)param_1,param_2);
  return (CMwNod *)pCVar1;
}
}

// =================================================
// Function: CMwRefBuffer::GetFromIndex
// =================================================
CMwNod * __thiscall
CMwRefBuffer::GetFromIndex(CMwRefBuffer *this,CMwRefBuffer *param_1,ulong param_2)
{
{
  ulong uVar1;
  SCasterCat *pSVar2;
  CFastBuffer<class_CCrystalFace*> *unaff_ESI;
  ulong unaff_retaddr;
  
  uVar1 = GetCount(this,unaff_ESI);
  if (param_2 < uVar1) {
    pSVar2 = CFastBuffer<class_GmVector2<unsigned_short>_>::operator[]
                       (this + 0x14,(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)param_2,
                        unaff_retaddr);
    return *(CMwNod **)pSVar2;
  }
  return (CMwNod *)0x0;
}
}

