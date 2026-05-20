
/* void __cdecl OrderWindowedValues(float &,float &,float) */

void __cdecl OrderWindowedValues(float *param_1, float *param_2, float param_3)

{
  float *pfVar1;

  pfVar1 = param_1;
  if (*param_2 < *param_1 == (NAN(*param_2) || NAN(*param_1))) {
    pfVar1 = param_2;
  }
  if (*param_2 < *param_1) {
    param_1 = param_2;
  }
  if ((*param_1 + param_3) - *pfVar1 <= *pfVar1 - *param_1) {
    *param_1 = *param_1 + param_3;
    return;
  }
  return;
}
