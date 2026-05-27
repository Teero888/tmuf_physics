// Class implementation: CMwNodRef_class_CPlugFileGPUP

// =================================================
// Function: CMwNodRef<class_CPlugFileGPUP>::ParamSetValue
// =================================================
void __thiscall
CMwNodRef<class_CPlugFileGPUP>::ParamSetValue
          (void *this,CSysFidNodRef<class_CHmsPackLightMap> *param_1,CMwStack *param_2,void *param_3
          )
{
{
  CFastStringInt *unaff_ESI;
  CMwNod *unaff_EDI;
  
  if (*(int *)(param_1 + 0x18) < 0) {
    if (param_2 != *(CMwStack **)this) {
      if (param_2 != (CMwStack *)0x0) {
        CMwNod::MwAddRef((CMwNod *)param_2,unaff_EDI);
      }
      if (*(CMwNod **)this != (CMwNod *)0x0) {
        CMwNod::MwRelease(*(CMwNod **)this,(CMwNod *)unaff_ESI);
      }
      *(CMwStack **)this = param_2;
    }
    return;
  }
  CMwNod::Param_Set(*(CMwNod **)this,(CMwNod *)param_1,(CFastString *)param_2,unaff_ESI);
  return;
}
}

