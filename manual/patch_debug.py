import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    code = f.read()

debug_print = """
              if (fVar15 == 0.0f || pCVar4 == 0 || fVar13 == 0.0f) {
                  // printf("param_5 components: fVar15=%f, pCVar4=%f, fVar13=%f\\n", fVar15, (float)(size_t)pCVar4, fVar13);
              } else {
                  printf("param_5: %f (fVar15=%f, pCVar4=%f, fVar13=%f)\\n", param_5, fVar15, (float)(size_t)pCVar4, fVar13);
              }
              fStack_8 = -param_5;
"""

code = code.replace("fStack_8 = -param_5;", debug_print)

with open("scratch_ComputeForcesModel3_patched.cpp", "w") as f:
    f.write(code)

print("Patched debug")
