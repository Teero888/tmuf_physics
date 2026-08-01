import re
with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# AddVehicleCentralForce at line 227
code = code.replace(
"""              in_stack_00000068 = (float*)(size_t)0;
              // AddVehicleCentralForce
              iVar9 = (int)(size_t)this->m_field_64;""",
"""              in_stack_00000068 = (float*)(size_t)0;
              GmVec3 cforce0((float)(*(size_t*)&unaff_EBX) * (float)(size_t)pCVar3, in_stack_ffffffa8, 0.0f); this->AddVehicleCentralForce(this, (CSceneVehicleCar*)&cforce0, nullptr);
              iVar9 = (int)(size_t)this->m_field_64;"""
)

funcs = ['GetRolloverLateralCoefFromAngle', 'GetRolloverLateralFromSpeed', 'GetSteerDriveTorqueFromSpeed', 'GetAccelFromSpeed']
for func in funcs:
    code = re.sub(r'->' + func + r'\s*\([^,]+,\s*[^,]+,\s*([^)]+)\s*\)', r'->' + func + r'(\1)', code, flags=re.DOTALL)
    
code = code.replace("GetMaxSideFrictionFromSpeed(in_stack_00000068)", "GetMaxSideFrictionFromSpeed((float)(size_t)in_stack_00000068)")
code = code.replace("(float)pCVar6", "(float)(size_t)pCVar6")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
