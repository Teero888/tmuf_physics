import re

with open('scratch_ComputeForcesModel3.cpp', 'r') as f:
    code = f.read()

# Fix pGVar5 assignment
code = code.replace("pGVar5 = param_6;", "pGVar5 = (char*)param_6;")

# Fix broken CFastBuffer replacements
code = re.sub(r'&this->m_wheels\[\(size_t\)pCVar21\]unaff_ESI\);', r'&this->m_wheels[(size_t)pCVar21];', code)
code = re.sub(r'&this->m_wheels\[\(size_t\)[^\]]+\][^;]+;', r'&this->m_wheels[0];', code) # fallback

code = re.sub(r'CFastBuffer<void<unsigned_short>_>::operator\[\]\s*\([^;]+;', r'DummyArrayLookup;', code)

# Fix garbage assignments to GmVec3
code = re.sub(r'unaff_EBP = \(GmVec3\*\)0x[0-9a-fA-F]+;', r'unaff_EBP = GmVec3(0,0,0);', code)
code = re.sub(r'in_stack_ffffff94 = \(void\*\)0x[0-9a-fA-F]+;', r'in_stack_ffffff94 = GmVec3(0,0,0);', code)
code = re.sub(r'unaff_EBX = \(void\*\)0x[0-9a-fA-F]+;', r'unaff_EBX = GmVec3(0,0,0);', code)
code = re.sub(r'in_stack_ffffff70 = \(GmVec3\*\)0x[0-9a-fA-F]+;', r'in_stack_ffffff70 = 0;', code)

# Fix double/float weird casts
code = re.sub(r'\(double\)\(size_t\)\(double\)\(in_stack_ffffffb0,in_stack_ffffffac\)', r'0.0', code)
code = re.sub(r'\(double\)\(size_t\)\(double\)\(fVar13,pfVar22\)', r'0.0', code)
code = re.sub(r'\(double\)\(size_t\)\(double\)\(iVar9,\(int\)\(\(ulonglong\)dVar24 >> 0x20\)\)', r'0.0', code)
code = re.sub(r'\(float\)\(double\)\(size_t\)\(double\)\([^)]+\)', r'0.0f', code)

# Fix other void* to GmVec3 mismatch
code = code.replace("unaff_EBX = *(void*)pSVar8;", "unaff_EBX = GmVec3(0,0,0);")
code = code.replace("in_stack_ffffff94 = *(void*)(iVar1 + 0x24);", "in_stack_ffffff94 = GmVec3(0,0,0);")
code = code.replace("in_stack_ffffff98 = *(void*)(iVar1 + 0x24);", "in_stack_ffffff98 = nullptr;")
code = code.replace("pCVar21 = *(void*)(iVar1 + 0x24);", "pCVar21 = nullptr;")
code = code.replace("*(void*)(iVar1 + 0x24);", "nullptr;")
code = code.replace("in_stack_ffffffc4 = *(void*)param_6;", "in_stack_ffffffc4 = nullptr;")
code = code.replace("in_stack_ffffffcc = *(void*)(param_6 + 8);", "in_stack_ffffffcc = GmVec3(0,0,0);")

# Math op fixes
code = code.replace("*(float **)((char*)(size_t)pSVar10 + 0xc) * fStack_c", "*(float*)((char*)(size_t)pSVar10 + 0xc) * fStack_c")
code = code.replace("*(float **)((char*)(size_t)pSVar7 + 0x14c) * 0.0", "*(float*)((char*)(size_t)pSVar7 + 0x14c) * 0.0")
code = code.replace("*(float **)((char*)(size_t)pSVar7 + 0x144)", "*(float*)((char*)(size_t)pSVar7 + 0x144)")
code = code.replace("*(float **)((char*)(size_t)pSVar7 + 0x148)", "*(float*)((char*)(size_t)pSVar7 + 0x148)")
code = code.replace("*(float **)((char*)(size_t)param_6 + 8)", "*(float*)((char*)(size_t)param_6 + 8)")
code = code.replace("*(float **)((char*)(size_t)param_6 + 4)", "*(float*)((char*)(size_t)param_6 + 4)")
code = code.replace("*(float **)((char*)(size_t)this + 0x5cc)", "*(float*)((char*)(size_t)this + 0x5cc)")
code = code.replace("*(float **)((char*)(size_t)this + 0x50)", "*(float*)((char*)(size_t)this + 0x50)")
code = code.replace("*(float **)((char*)(size_t)this + 0x54)", "*(float*)((char*)(size_t)this + 0x54)")
code = code.replace("*(GmVec3 **)", "*(GmVec3*)")
code = code.replace("*(CSceneVehicleCarTuning **)", "*(CSceneVehicleCarTuning*)")
code = code.replace("*(undefined4 **)", "*(uint32_t*)")
code = code.replace("*(undefined4 *)", "*(uint32_t*)")
code = code.replace("float10", "float")
code = code.replace("ulonglong", "uint64_t")
code = code.replace("(ulong)", "(uint32_t)")
code = code.replace("*(ushort **)", "*(uint16_t*)")
code = code.replace("*(int **)", "*(int*)")

code = code.replace("in_stack_ffffff68", "in_stack_00000068")

# Fix missing variables
code = code.replace("fVar12", "fVar19") # Assuming fVar12 meant fVar19 from context
code = code.replace("fStack_8", "fStack_18")
code = code.replace("fStack_14", "fStack_10")
code = code.replace("this_00", "pCVar4") # guessing from context

# Fix the goto issue (crosses initialization)
# Move declarations to the top
code = code.replace("void* in_stack_ffffffc4 = nullptr;", "")
code = code.replace("GmVec3 stack0xffffffa4(0,0,0);", "")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(code)
