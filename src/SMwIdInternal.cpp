// Class implementation: SMwIdInternal

// =================================================
// Function: SMwIdInternal::SMwIdInternal
// =================================================
void __thiscall SMwIdInternal::SMwIdInternal(void *this,SMwIdInternal *param_1)
{
{
  code *pcVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00ae4b78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CFastBuffer<class_CPlugFileSndGen*>::CFastBuffer<class_CPlugFileSndGen*>
            (this,(CFastBuffer<class_CPlugFileSndGen*> *)(DAT_00cca150 ^ (uint)&stack0xffffffec));
  pcVar1 = CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>;
  _eh_vector_constructor_iterator_
            ((void *)((int)this + 0xc),8,0x20,
             CFastArray<class_CManoeuvre*>::CFastArray<class_CManoeuvre*>,
             CFastArray<class_CFuncShader*>::~CFastArray<class_CFuncShader*>);
  ExceptionList = pcVar1;
  return;
}
}

