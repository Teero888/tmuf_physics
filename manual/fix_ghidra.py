import re

with open('Hms/CHmsZoneDynamic_SolveImpulse_Exact.cpp', 'r') as f:
    code = f.read()

# Fix signature
code = code.replace("void __thiscall\nCHmsZoneDynamic::SolveImpulse\n          (CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2,\n          CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4)",
"void CHmsZoneDynamic::SolveImpulse(SHmsPhysicalCollision* param_1, CHmsPhysicalContact* param_3, CHmsPhysicalContact* param_4)")

# Struct definitions mapping
code = code.replace("*(float *)param_1", "param_1->m_value00")
code = code.replace("*(int *)(param_1 + 8)", "((int)param_1->m_body1)")
code = code.replace("param_1 + 0x10", "&param_1->m_normal")
code = code.replace("*(float *)(param_1 + 0x14)", "param_1->m_normal.y")
code = code.replace("*(float *)(param_1 + 0x18)", "param_1->m_normal.z")
code = code.replace("*(float *)(param_1 + 0x1c)", "param_1->m_pos.x")
code = code.replace("*(float *)(param_1 + 0x20)", "param_1->m_pos.y")
code = code.replace("*(float *)(param_1 + 0x24)", "param_1->m_pos.z")
code = code.replace("*(float *)(param_1 + 0x28)", "param_1->m_value28.x")
code = code.replace("*(float *)(param_1 + 0x2c)", "param_1->m_value28.y")
code = code.replace("*(float *)(param_1 + 0x30)", "param_1->m_value28.z")
code = code.replace("(param_1 + 0x28)", "&param_1->m_value28")

code = code.replace("*(ushort *)(param_1 + 0x34)", "param_1->m_matId1")
code = code.replace("*(ushort *)(param_1 + 0x36)", "param_1->m_matId2")

# CHmsPhysicalContact mapping
code = code.replace("*(float *)param_3", "param_3->m_value00")
code = code.replace("param_3 + 0x24", "&param_3->m_value24")
code = code.replace("*(float *)(param_3 + 0x28)", "param_3->m_value24.y")
code = code.replace("*(float *)(param_3 + 0x2c)", "param_3->m_value24.z")

code = code.replace("param_3 + 0x30", "&param_3->m_value30")
code = code.replace("*(float *)(param_3 + 0x34)", "param_3->m_value30.y")
code = code.replace("*(float *)(param_3 + 0x38)", "param_3->m_value30.z")
code = code.replace("*(undefined4 *)(param_3 + 0x3c)", "param_3->m_active")

# param_4 mapping
code = code.replace("param_4 + 0x24", "&param_4->m_value24")
code = code.replace("*(float *)(param_4 + 0x28)", "param_4->m_value24.y")
code = code.replace("*(float *)(param_4 + 0x2c)", "param_4->m_value24.z")

code = code.replace("param_4 + 0x30", "&param_4->m_value30")
code = code.replace("*(float *)(param_4 + 0x34)", "param_4->m_value30.y")
code = code.replace("*(float *)(param_4 + 0x38)", "param_4->m_value30.z")
code = code.replace("*(undefined4 *)(param_4 + 0x3c)", "param_4->m_active")

# Some pointer casts
code = code.replace("(float)param_1", "param_1->m_normal.x") # Because Ghidra does (float)param_1 instead of *(float*)this_00 when it means normal? Wait, no. We will manually fix these.

with open('Hms/CHmsZoneDynamic_SolveImpulse_Exact.cpp', 'w') as f:
    f.write(code)

