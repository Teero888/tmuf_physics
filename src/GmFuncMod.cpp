
/* public: static unsigned long __cdecl GmFunc::Mod(int,int) */

ulong __cdecl GmFunc::Mod(int param_1, int param_2)

{
  ulong uVar1;

  uVar1 = param_1 % param_2;
  if ((int)uVar1 < 0) {
    uVar1 = uVar1 + param_2;
  }
  return uVar1;
}
