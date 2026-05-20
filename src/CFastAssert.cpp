// Class implementation: CFastAssert

// =================================================
// Function: CFastAssert::StaticInit
// =================================================
void __cdecl CFastAssert::StaticInit(void)
{
{
  DAT_00d343d4 = GetCurrentThreadId();
  _set_se_translator(ExceptionWin32);
  __set_invalid_parameter_handler(OnInvalidParameter);
  __set_purecall_handler(OnPureVirtualCall);
  _set_new_handler(OnProgramMemoryDepletion);
  return;
}
}

