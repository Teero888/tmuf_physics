import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    code = f.read()

# Replace hardcoded offsets
code = re.sub(r'\*\s*\(\s*uint32_t\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x5c4\s*\)\s*\)', 'this->m_engine.m_field_0x28', code)
code = re.sub(r'\*\s*\(\s*int\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x5c4\s*\)\s*\)', 'this->m_engine.m_field_0x28', code)
code = re.sub(r'\*\s*\(\s*float\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x5cc\s*\)\s*\)', 'this->m_engine.m_field_0x30', code)
code = re.sub(r'\*\s*\(\s*float\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x5e8\s*\)\s*\)', 'this->m_engineForce', code)
code = re.sub(r'\*\s*\(\s*float\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x5f4\s*\)', 'this->m_field_0x5f4', code)
code = re.sub(r'\*\s*\(\s*int\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x600\s*\)', 'this->m_field_0x600', code)
code = re.sub(r'\*\s*\(\s*float\s*\*\s*\)\s*\(\s*\(\s*char\s*\*\s*\)\s*\(\s*size_t\s*\)\s*this\s*\+\s*0x840\s*\)', 'this->m_field_0x840', code)

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(code)

print("Done")
