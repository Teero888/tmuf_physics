import re

with open("../tmnf_dump/src/CSceneVehicleCar.cpp", "r") as f:
    lines = f.readlines()

new_lines = []
in_model3 = False
in_decl = False
decl_inserted = False

for line in lines:
    if "CSceneVehicleCar::ComputeForcesModel3" in line and not "Exact" in line:
        in_model3 = True
        in_decl = True
    
    if not in_model3:
        continue
        
    if line.startswith("}"):
        new_lines.append("}")
        break
        
    if "void __thiscall\n" in line:
        continue
    if "CSceneVehicleCar::ComputeForcesModel3" in line and not "Exact" in line:
        line = line.replace("CSceneVehicleCar::ComputeForcesModel3", "void CSceneVehicleCar::ComputeForcesModel3_Exact")
        
    if "void CSceneVehicleCar::ComputeForcesModel3_Exact(" in line and not decl_inserted:
        new_lines.append(line)
        new_lines.append("""{
    float fStack_c, fStack_18, fStack_14, fStack_10, fStack_8, fStack_4, fStack_78, fStack_2c, fStack_30, fStack_4c, fStack_d0;
    float extraout_ST0, extraout_ST0_00, extraout_ST0_01;
    float in_stack_ffffffb4, in_stack_ffffffb8, in_stack_ffffffbc, in_stack_ffffffc0;
    float unaff_EBP = 0, unaff_EBX = 0, in_stack_ffffff94 = 0;
    float in_stack_ffffff8c = 0, in_stack_ffffff88 = 0;
    void* in_stack_ffffffa0 = nullptr;
    float in_stack_ffffffc4 = 0, in_stack_ffffffc8 = 0, in_stack_ffffff74 = 0, in_stack_ffffff78 = 0, in_stack_ffffff7c = 0;
    void* in_stack_ffffff64 = nullptr;
    void* in_stack_ffffff70 = nullptr;
    float* in_stack_00000068 = nullptr;
    GmVec3 in_stack_ffffffcc(0,0,0);
    int uVar23 = 0, iVar9 = 0;
    double dVar24 = 0;
    float fVar13 = 0, pfVar22 = 0;
    CSceneVehicleCar::SSimulationWheel* pSVar10 = nullptr;
    CSceneVehicleCar* pCVar3 = nullptr;
    CSceneVehicleCarTuning* pCVar4 = nullptr;
    void* pSVar8 = nullptr;
    void* pCVar6 = nullptr;
    void* this_00 = param_1;
    void* pSVar7 = nullptr;
    float fVar14 = 0, fVar19 = 0, fVar20 = 0, fVar15 = 0;
    void* pCVar21 = nullptr;
    int iVar1 = 0;
""")
        decl_inserted = True
        continue
    if "CSceneVehicleCar::ComputeForcesModel3_Exact" in line:
        new_lines.append(line)
        continue
    
    if in_decl:
        if "pGVar5 = param_6;" in line:
            in_decl = False
        else:
            continue
        
    new_lines.append(line)

code = "\n".join(new_lines)

# Math fixes
code = code.replace("func_0x009c1b40()", "1.0f")
code = code.replace("__CIcos()", "extraout_ST0 = std::cos(0.0f)")
code = code.replace("__CIsin()", "extraout_ST0_00 = std::sin(0.0f); extraout_ST0_01 = std::sin(0.0f)")
code = code.replace("ABS(", "std::abs(")
code = code.replace("NAN(", "std::isnan(")

# Globals
code = code.replace("_DAT_00d0ac60", "0.0001f")
code = code.replace("_PTR_00b2c178", "1.0f") # _PTR_00b2c178 in FPU code is usually just 1.0f or a static float
code = code.replace("_DAT_00b313b8", "1.0f")
code = code.replace("_DAT_00b362c0", "1.0f")
code = code.replace("_DAT_00b36110", "1.0f")
code = code.replace("_DAT_00b2c060", "1.0f")

# Known fields
code = code.replace("this + 0x2e8", "&this->m_wheels")
code = code.replace("(void *)(iVar1 + 0x14)", "&((CSceneVehicleCarTuning*)(size_t)iVar1)->m_field_14")
code = code.replace("(void *)(iVar9 + 0x14)", "&((CSceneVehicleCarTuning*)(size_t)iVar9)->m_field_14")
code = code.replace("(void *)((int)(size_t)this->m_field_64 + 0x14)", "&((CSceneVehicleCarTuning*)this->m_field_64)->m_field_14")
code = code.replace("*(uintptr_t*)(size_t)pSVar8", "(uintptr_t)(size_t)pSVar8")
code = code.replace("*(int *)(this + 100)", "(int)(size_t)this->m_field_64")

# Keep complex function calls
# (removed commenting out of WheelAddForceToVehicle, AddVehicleCentralForce, AddVehicleTorque)

code = code.replace("CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetMaxSideFrictionFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle", "((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralCoefFromAngle")
code = code.replace("CSceneVehicleCarTuning::GetRolloverLateralFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerDriveTorqueFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetAccelFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetAccelFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerSlowDownFromSpeed")

# Fix Ghidra adding 2 extra FPU/this arguments to tuning methods
code = re.sub(r'->GetSteerDriveTorqueFromSpeed\s*\(\s*[^,]+\s*,\s*[^,]+\s*,\s*([^)]+)\s*\)', r'->GetSteerDriveTorqueFromSpeed(\1)', code)
code = re.sub(r'->GetRolloverLateralCoefFromAngle\s*\(\s*[^,]+\s*,\s*[^,]+\s*,\s*([^)]+)\s*\)', r'->GetRolloverLateralCoefFromAngle(\1)', code)
code = re.sub(r'->GetRolloverLateralFromSpeed\s*\(\s*[^,]+\s*,\s*[^,]+\s*,\s*([^)]+)\s*\)', r'->GetRolloverLateralFromSpeed(\1)', code)
code = re.sub(r'->GetAccelFromSpeed\s*\(\s*[^,]+\s*,\s*[^,]+\s*,\s*([^)]+)\s*\)', r'->GetAccelFromSpeed(\1)', code)

# Strip CFastBuffer calls safely
code = re.sub(r'CFastBuffer<[^>]+>::GetCount\([^)]+\)', r'0', code)
code = re.sub(r'CFastBuffer<[^>]+>::operator\[\]', r'DUMMY_CFAST_CALL', code)

# Primitive types
code = re.sub(r'\buint\b', "uint32_t", code)
code = re.sub(r'\bulonglong\b', "uint64_t", code)
code = re.sub(r'\bulong\b', "uint32_t", code)
code = re.sub(r'\bushort\b', "uint16_t", code)
code = re.sub(r'\bundefined4\b', "uint32_t", code)
code = re.sub(r'\bfloat10\b', "float", code)

# Float variables that Ghidra typed as GmVec3 or pointers
code = re.sub(r'\(\s*GmVec3\s*\*\)\s*\(\s*(fStack_4 \*\s*[a-zA-Z0-9_]+)\s*\)', r'\1', code)
code = re.sub(r'\(\s*CFastBuffer<struct_CVisionHmsZone::SCasterCat>\s*\*\)\s*\(\s*(fStack_4 \*\s*[a-zA-Z0-9_]+)\s*\)', r'\1', code)
code = re.sub(r'\(\s*GmVec3\s*\*\)\s*\(\s*(in_stack_[a-z0-9_]+\s*\+\s*fStack_4)\s*\)', r'\1', code)
code = re.sub(r'\(\s*CFastBuffer<struct_CVisionHmsZone::SCasterCat>\s*\*\)\s*\(\s*(fStack_4\s*\+\s*in_stack_[a-z0-9_]+)\s*\)', r'\1', code)
code = re.sub(r'\(\s*CFastBuffer<struct_CVisionHmsZone::SCasterCat>\s*\*\)\s*\(\s*\(\s*float\s*\)\s*(in_stack_[a-z0-9_]+\s*\+\s*in_stack_[a-z0-9_]+)\s*\)', r'\1', code)
code = re.sub(r'\(\s*CFastBuffer<struct_CVisionHmsZone::SCasterCat>\s*\*\)\s*\(\s*\(\s*float\s*\)\s*in_stack_[a-z0-9_]+\s*\+\s*in_stack_[a-z0-9_]+\s*\)', lambda m: m.group(0).replace('(CFastBuffer<struct_CVisionHmsZone::SCasterCat> *)', ''), code)

code = re.sub(r'\(\s*SCasterCat\s*\*\)', '', code)
code = re.sub(r'\(\s*float\s*\)\s*unaff_EBP', 'unaff_EBP', code)
code = re.sub(r'\(\s*float\s*\)\s*unaff_EBX', 'unaff_EBX', code)
code = re.sub(r'\(\s*float\s*\)\s*in_stack_ffffff94', 'in_stack_ffffff94', code)

# Clean pointer casts
code = re.sub(r'\(\s*float\s*\)\s*([a-zA-Z0-9_]+)', r'(float)(size_t)\1', code)
code = re.sub(r'\(\s*int\s*\)\s*([a-zA-Z0-9_]+)', r'(int)(size_t)\1', code)
code = re.sub(r'\(\s*double\s*\)\s*([a-zA-Z0-9_]+)', r'(double)(size_t)\1', code)
code = re.sub(r'\(\s*uint32_t\s*\)\s*([a-zA-Z0-9_]+)', r'(uint32_t)(size_t)\1', code)
code = re.sub(r'\(\s*uint64_t\s*\)\s*([a-zA-Z0-9_]+)', r'(uint64_t)(size_t)\1', code)

code = code.replace("SUB84", "(float)(size_t)")

# CONCAT44 replace with fVar13 where appropriate
code = re.sub(r'\(float\)\(double\)\(size_t\)\(uint64_t\)\(size_t\)\(in_stack_ffffffb4,\(int\)\(\(uint64_t\)\(size_t\)dVar24 >> 0x20\)\)', 'fVar13', code)
code = re.sub(r'\(float\)\(size_t\)\(double\)\(size_t\)\(uint64_t\)\(size_t\)\(in_stack_ffffffb4,\(int\)\(size_t\)\(\(uint64_t\)\(size_t\)dVar24 >> 0x20\)\)', 'fVar13', code)

# Fix std::abs for tuning values
code = code.replace("std::abs((float)(size_t)in_stack_ffffffa0)", "std::abs(*(float*)((char*)(size_t)this->m_field_64 + 0x24))")

# Fix pointer arithmetic by casting to char*
def fix_mem_access(m):
    typ = m.group(1).replace(" ", "")
    typ = typ.replace("*", "*")
    ptr = m.group(2)
    offset = m.group(3)
    return f"*({typ}*)((char*)(size_t){ptr} + {offset})"

code = re.sub(r'\*\(\s*([a-zA-Z0-9_:\* ]+)\s*\)\s*\(\s*([a-zA-Z0-9_]+)\s*\+\s*([0-9a-fxA-FX]+)\s*\)', fix_mem_access, code)
code = re.sub(r'\*\(\s*([a-zA-Z0-9_:\* ]+)\s*\)\s*\(\s*\*\(\s*([a-zA-Z0-9_:\* ]+)\s*\)\s*\(\s*([a-zA-Z0-9_]+)\s*\+\s*([0-9a-fxA-FX]+)\s*\)\s*\+\s*([0-9a-fxA-FX]+)\s*\)', 
              r'*(\1*)((char*)(size_t)*(\2*)((char*)(size_t)\3 + \4) + \5)', code)
code = re.sub(r'\*\(\s*([a-zA-Z0-9_:\* ]+)\s*\)\s*([a-zA-Z0-9_]+)', r'*(\1*)(size_t)\2', code)

code = code.replace("this + 0x5c4", "((char*)(size_t)this + 0x5c4)")
code = code.replace("this + 0x5e8", "((char*)(size_t)this + 0x5e8)")
code = code.replace("this + 0x50", "((char*)(size_t)this + 0x50)")
code = code.replace("this + 0x54", "((char*)(size_t)this + 0x54)")
code = code.replace("this + 0x68", "((char*)(size_t)this + 0x68)")
code = code.replace("this + 0x5cc", "((char*)(size_t)this + 0x5cc)")

code = code.replace("pGVar5 = param_6;", "pGVar5 = (char*)param_6;")

code = re.sub(r'\*\(\s*float\s*\*\*\s*\)', '*(float*)', code)
code = re.sub(r'\*\(\s*GmVec3\s*\*\*\s*\)', '*(GmVec3*)', code)
code = re.sub(r'\*\(\s*int\s*\*\*\s*\)', '*(int*)', code)
code = re.sub(r'\*\(\s*uint16_t\s*\*\*\s*\)', '*(uint16_t*)', code)
code = re.sub(r'\*\(\s*uint32_t\s*\*\*\s*\)', '*(uint32_t*)', code)
code = re.sub(r'\*\(\s*CSceneVehicleCarTuning\s*\*\*\s*\)', '*(CSceneVehicleCarTuning*)', code)
code = re.sub(r'\*\(\s*CFastBuffer<void::void>\s*\*\*\s*\)', '*(void*)', code)
code = re.sub(r'\*\(\s*CFastBuffer<void\*>\s*\*\*\s*\)', '*(void*)', code)
code = re.sub(r'\*\(\s*void\s*\*\*\s*\)', '*(void*)', code)
code = re.sub(r'\(\s*CFastBuffer<void::void>\s*\*\s*\)', '(void*)', code)

code = code.replace("in_stack_ffffff68", "in_stack_00000068")
code = code.replace("fVar12", "fVar19") 
code = code.replace("in_stack_00000078", "in_stack_00000058")

code = re.sub(r'&this->m_wheels\[\(size_t\)[^\]]+\][^;]+;', r'&this->m_wheels[0];', code) 
code = code.replace("pSVar7 = ((void*)0)unaff_ESI);", "pSVar7 = &this->m_wheels[0];")
code = code.replace("= ((void*)0)unaff_ESI);", "= &this->m_wheels[0];")

final = """#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "CHmsItem.hpp"
#include <cmath>
#include <cstdint>

struct DummyCast {
    void* ptr;
    DummyCast(void* p) : ptr(p) {}
    template<typename T> operator T*() { return (T*)ptr; }
    operator size_t() { return (size_t)ptr; }
    operator int() { return (uintptr_t)(size_t)ptr; }
    operator float() { 
        union { size_t s; float f; } u; 
        u.s = (size_t)ptr; 
        return u.f; 
    }
};

static uint8_t g_dummy_buffer[2048];
static void* g_dummy_ptr = &g_dummy_buffer[0];

template<typename T, typename DummyType>
DummyCast DUMMY_CFAST_CALL(CFastBuffer<T>* buffer, DummyType, uint32_t index) {
    if (!buffer || index >= buffer->GetCount()) return DummyCast(&g_dummy_buffer[0]);
    return DummyCast((void*)&(*buffer)[index]);
}
template<typename T, typename DummyType>
DummyCast DUMMY_CFAST_CALL(CFastArray<T>* buffer, DummyType, uint32_t index) {
    if (!buffer || index >= buffer->GetCount()) return DummyCast(&g_dummy_buffer[0]);
    return DummyCast((void*)&(*buffer)[index]);
}
template<typename DummyType>
inline DummyCast DUMMY_CFAST_CALL(void* ptr, DummyType, uint32_t index) {
    return DummyCast(&g_dummy_ptr);
}

""" + code

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(final)

print("Done")
