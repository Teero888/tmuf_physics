
/* public: static int __cdecl GmVec3::ComputeTriangleTangentUV(struct
 * GmVec3::STri_PosTexTgt &) */

int __cdecl GmVec3::ComputeTriangleTangentUV(STri_PosTexTgt *param_1)

{
  ulong uVar1;
  ulong uVar2;

  uVar2 = 0;
  do {
    uVar1 = ComputeTriangleTangentUV_Rotated(param_1, uVar2);
    if (uVar1 != 0) {
      return uVar1;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  return 0;
}
