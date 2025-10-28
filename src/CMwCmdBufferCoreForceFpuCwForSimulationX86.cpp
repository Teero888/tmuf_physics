
/* WARNING: Globals starting with '_' overlap smaller symbols at the same
 * address */
/* public: static void __cdecl CMwCmdBufferCore::ForceFpuCwForSimulationX86(char
 * const *) */

void __cdecl CMwCmdBufferCore::ForceFpuCwForSimulationX86(char *param_1)

{
  ushort in_FPUControlWord;

  if ((in_FPUControlWord & 0x300) != 0) {
    _DAT_00d732f0 = _DAT_00d732f0 + 1;
    in_FPUControlWord = in_FPUControlWord & 0xfcff;
  }
  if ((in_FPUControlWord & 0xc00) != 0) {
    _DAT_00d732ec = _DAT_00d732ec + 1;
  }
  return;
}
