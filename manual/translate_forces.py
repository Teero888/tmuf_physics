import re

with open('scratch_ForcesModel3.cpp', 'r') as f:
    code = f.read()

# Replace this + 100 with this->m_tuning
code = code.replace("*(int *)(this + 100)", "this->m_tuning")
code = code.replace("this + 100", "this->m_tuning")
# Replace this + 0x2e8 with &this->m_wheels
code = code.replace("this + 0x2e8", "&this->m_wheels")
code = code.replace("*(int *)(this + 0x60c)", "this->field_0x60c")
code = code.replace("*(float *)(this + 0x5cc)", "this->field_0x5cc")
code = code.replace("*(float *)(this + 0x50)", "this->field_0x50")
code = code.replace("*(float *)(this + 0x54)", "this->field_0x54")
code = code.replace("*(undefined4 *)(this + 0x5c4)", "this->field_0x5c4")
code = code.replace("*(float *)(this + 0x840)", "this->field_0x840")
code = code.replace("*(int *)(this + 0x600)", "this->field_0x600")
code = code.replace("*(float *)(this + 0x5f4)", "this->field_0x5f4")
code = code.replace("*(float *)(this + 0x5e8)", "this->field_0x5e8")

# SSimulationWheel
code = code.replace("*(float *)(pSVar7 + 0x144)", "wheel->field_0x144")
code = code.replace("*(float *)(pSVar7 + 0x148)", "wheel->field_0x148")
code = code.replace("*(float *)(pSVar7 + 0x14c)", "wheel->field_0x14c")
code = code.replace("*(int *)(pSVar7 + 0x124)", "wheel->field_0x124")
code = code.replace("*(ushort *)(pSVar7 + 0x128)", "wheel->field_0x128")
code = code.replace("*(int *)(pSVar7 + 300)", "wheel->field_0x12c")
code = code.replace("*(undefined4 *)(pSVar7 + 300)", "wheel->field_0x12c")
code = code.replace("*(float *)(pSVar10 + 0xc)", "wheel10->field_0xc")
code = code.replace("*(int *)(pSVar7 + 4)", "wheel->field_0x4")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)

print("Generated scratch_ComputeForcesModel3.cpp")
