import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    code = f.read()

# Fix the GetCount
code = code.replace("pCVar6 = (void*)0;", "pCVar6 = (void*)(size_t)this->m_wheels.Count;")

# Fix the operator[]
code = code.replace("pSVar7 = DUMMY_CFAST_CALL\n                         (&this->m_wheels,pCVar21,(uint32_t)(size_t)unaff_ESI);",
                    "pSVar7 = &this->m_wheels[(size_t)pCVar21];")
code = code.replace("pSVar7 = DUMMY_CFAST_CALL\n                         (&this->m_wheels,pCVar21,(uint32_t)unaff_ESI);",
                    "pSVar7 = &this->m_wheels[(size_t)pCVar21];")
# If it's on a single line:
code = code.replace("pSVar7 = DUMMY_CFAST_CALL(&this->m_wheels,pCVar21,(uint32_t)(size_t)unaff_ESI);",
                    "pSVar7 = &this->m_wheels[(size_t)pCVar21];")

with open("scratch_ComputeForcesModel3_patched.cpp", "w") as f:
    f.write(code)

print("Patched GetCount")
