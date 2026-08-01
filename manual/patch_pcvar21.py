import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    orig = f.read()

# Replace pCVar21 with loop_index when it's used as a loop index
# Wait, pCVar21 is used as loop index at:
# 105: pCVar21 = (void*)0;
# 108: pSVar7 = &this->m_wheels[(size_t)pCVar21];
# 137: DUMMY_CFAST_CALL((void *)(iVar1 + 0x14),in_stack_ffffff98,(uint32_t)(size_t)pCVar21);
# 275: pCVar21 = pCVar21 + 1;
# 276: } while (pCVar21 < pCVar6);

# BUT it's ALSO used as loop index later!
# 360: pCVar21 = (void*)0;
# 518: pCVar21 = (void*)0;
# 563: pCVar21 = (void*)0;

# Wait, if I just rename the INNER reassignments to pCVar21_tmp?
# Reassignments are:
# 140: pCVar21 = *(void**)(iVar1 + 0x24);
# 143: DUMMY_CFAST_CALL(...,pCVar21,...);
# 152: pCVar21 = (void*)0; 
# (Wait, if it was set to 0, what was it used for?)
# 351: pCVar21 = *(void**)(iVar1 + 0x24);
# 354: DUMMY_CFAST_CALL(...,pCVar21,...);

orig = orig.replace("pCVar21 = *(void**)(iVar1 + 0x24);", "void* pCVar21_tmp = *(void**)(iVar1 + 0x24);")
orig = orig.replace("((void *)(iVar1 + 0x14),pCVar21,(uint32_t)(size_t)in_stack_ffffffa0);", "((void *)(iVar1 + 0x14),pCVar21_tmp,(uint32_t)(size_t)in_stack_ffffffa0);")

# At line 152: pCVar21 = (void*)0; -> void* pCVar21_tmp2 = (void*)0;
# But wait, is it used?

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(orig)
print("Patched pCVar21")
