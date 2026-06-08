import re
import os

with open('../tmnf_dump/src/CSceneVehicleCar.cpp', 'r') as f:
    lines = f.readlines()

start_idx = -1
end_idx = -1
for i, line in enumerate(lines):
    if "CSceneVehicleCar::ComputeForcesModel3" in line and "void __thiscall" in lines[i-1]:
        start_idx = i - 1
    if start_idx != -1 and line.startswith("}") and i > start_idx + 10:
        if lines[i-1].startswith("}"):
            end_idx = i + 1
            break

code = "".join(lines[start_idx:end_idx])

# Fix signature
code = code.replace("void __thiscall\nCSceneVehicleCar::ComputeForcesModel3\n          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,\n          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,\n          SBlendableVals *param_10,int *param_11,float *param_12)",
"void CSceneVehicleCar::ComputeForcesModel3_Exact(CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, void *param_10,int *param_11,float *param_12)")

code = code.replace("void __thiscall\nCSceneVehicleCar::ComputeForcesModel3", "void CSceneVehicleCar::ComputeForcesModel3_Exact")

# Strip variables block
lines = code.split("\n")
new_lines = []
in_decl = True
decl_inserted = False
for line in lines:
    if "{" in line and not decl_inserted:
        new_lines.append(line)
        new_lines.append("""
    float fVar13=0, fVar14=0, fVar15=0, fVar19=0, fVar20=0, fStack_4=0, fStack_c=0;
    float extraout_ST0=0, extraout_ST0_00=0, extraout_ST0_01=0;
    double dVar24=0;
    GmVec3 unaff_EBP(0,0,0), unaff_EBX(0,0,0), in_stack_ffffff94(0,0,0);
    GmVec3 in_stack_ffffffd4(0,0,0), in_stack_ffffffe0(0,0,0), in_stack_ffffffcc(0,0,0);
    CSceneVehicleCar::SSimulationWheel* pSVar7 = nullptr;
    CSceneVehicleCar::SSimulationWheel* pSVar10 = nullptr;
    CSceneVehicleCar* pCVar3 = nullptr;
    CSceneVehicleCarTuning* pCVar4 = nullptr;
    void* pSVar8 = nullptr;
    void* pCVar6 = nullptr;
    void* pCVar21 = nullptr;
    void* pCVar17 = nullptr;
    void* pGVar11 = nullptr;
    void* in_stack_ffffffa0 = nullptr;
    void* in_stack_ffffff98 = nullptr;
    void* unaff_EDI = nullptr;
    uint32_t unaff_ESI = 0;
    int iVar1=0, iVar9=0;
    float* pfVar22 = nullptr;
    float* in_stack_00000064 = nullptr;
    float* in_stack_00000068 = nullptr;
    int* in_stack_0000005c = nullptr;
    int* in_stack_0000003c = nullptr;
    
    float in_stack_ffffffb8=0, in_stack_ffffffbc=0, in_stack_ffffffc0=0, in_stack_ffffffa8=0;
    float in_stack_ffffffb4=0, in_stack_ffffffc8=0, in_stack_ffffffd0=0, in_stack_ffffffd8=0;
    float in_stack_ffffffdc=0;
    GmVec3 stack0xffffffa4(0,0,0);
    GmVec3 fStack_18(0,0,0);
    GmVec3 fStack_10(0,0,0);
    GmVec3 pGVar18(0,0,0);
    float in_stack_ffffff70=0;
    char* pGVar5 = nullptr;
    float in_stack_00000070=0;
    float in_stack_00000050=0, in_stack_00000058=0;
    
    uint32_t uStack00000034=0, in_stack_00000074=0, in_stack_ffffff64=0, in_stack_ffffff6c=0;
    uint32_t in_stack_ffffff74=0, in_stack_ffffff78=0, in_stack_ffffff7c=0, uVar16=0;
    uint32_t in_stack_ffffffac=0, uVar23=0, in_stack_ffffffb0=0;
    void* in_stack_ffffffc4 = nullptr;
    void* pSStack00000080 = nullptr;
    void* this_00 = nullptr;
    float fStack_8=0, fStack_14=0;
    float in_stack_00000038=0;
        """)
        decl_inserted = True
        continue
    if "CSceneVehicleCar::ComputeForcesModel3_Exact" in line:
        new_lines.append(line)
        continue
    
    if in_decl and "=" not in line and ";" in line and "return" not in line and "if " not in line and "{" not in line and "}" not in line:
        continue 
    if "iVar1 = " in line or "fVar13 = " in line or "pSVar7 = " in line or "if (" in line:
        in_decl = False
        
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
code = code.replace("_PTR_00b2c178", "(float*)0")
code = code.replace("_DAT_00b313b8", "1.0f")
code = code.replace("_DAT_00b362c0", "1.0f")
code = code.replace("_DAT_00b36110", "1.0f")
code = code.replace("_DAT_00b2c060", "1.0f")

# Known fields
code = code.replace("this + 0x2e8", "&this->m_wheels")
code = code.replace("*(int *)(this + 100)", "(int)(size_t)this->m_field_64")

# Comment out complex function calls
code = re.sub(r'WheelAddForceToVehicle[^;]+;', '// WheelAddForce', code)
code = re.sub(r'AddVehicleCentralForce[^;]+;', '// AddVehicleCentralForce', code)
code = re.sub(r'AddVehicleTorque[^;]+;', '// AddVehicleTorque', code)

code = code.replace("CSceneVehicleCarTuning::GetMaxSideFrictionFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetMaxSideFrictionFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetRolloverLateralCoefFromAngle", "((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralCoefFromAngle")
code = code.replace("CSceneVehicleCarTuning::GetRolloverLateralFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetRolloverLateralFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetSteerDriveTorqueFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerDriveTorqueFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetAccelFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetAccelFromSpeed")
code = code.replace("CSceneVehicleCarTuning::GetSteerSlowDownFromSpeed", "((CSceneVehicleCarTuning*)this->m_field_64)->GetSteerSlowDownFromSpeed")

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

code = code.replace("class_GmVector2", "void")
code = code.replace("struct_CVisionHmsZone", "void")
code = code.replace("class_CCrystalFace", "void")
code = code.replace("SCasterCat", "void")

# Clean pointer casts
code = re.sub(r'\(\s*float\s*\)\s*([a-zA-Z0-9_]+)', r'(float)(size_t)\1', code)
code = re.sub(r'\(\s*int\s*\)\s*([a-zA-Z0-9_]+)', r'(int)(size_t)\1', code)
code = re.sub(r'\(\s*double\s*\)\s*([a-zA-Z0-9_]+)', r'(double)(size_t)\1', code)
code = re.sub(r'\(\s*uint32_t\s*\)\s*([a-zA-Z0-9_]+)', r'(uint32_t)(size_t)\1', code)
code = re.sub(r'\(\s*uint64_t\s*\)\s*([a-zA-Z0-9_]+)', r'(uint64_t)(size_t)\1', code)

code = code.replace("SUB84", "(float)(size_t)")
code = code.replace("CONCAT44", "(uint64_t)(size_t)")

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

# Commas / Multiple parameters in float casts - EXACT matches only
code = code.replace("dVar24 = (double)(size_t)(double)(in_stack_ffffffb0,in_stack_ffffffac);", "dVar24 = 0;")
code = code.replace("dVar24 = (double)(double)(in_stack_ffffffb0,in_stack_ffffffac);", "dVar24 = 0;")
code = code.replace("uVar23 = (float)(size_t)(dVar24,0);", "uVar23 = 0;")
code = code.replace("uVar23 = (float)(dVar24,0);", "uVar23 = 0;")
code = code.replace("dVar24 = (double)(size_t)(double)(fVar13,pfVar22);", "dVar24 = 0;")
code = code.replace("dVar24 = (double)(double)(fVar13,pfVar22);", "dVar24 = 0;")
code = code.replace("dVar24 = (double)(size_t)(double)(iVar9,(int)(size_t)((uint64_t)(size_t)dVar24 >> 0x20));", "dVar24 = 0;")
code = code.replace("dVar24 = (double)(double)(iVar9,(int)((uint64_t)dVar24 >> 0x20));", "dVar24 = 0;")
code = code.replace("(float)(size_t)(double)(size_t)(double)(in_stack_ffffffb4,(int)(size_t)((uint64_t)(size_t)dVar24 >> 0x20))", "0.0f")
code = code.replace("(float)(size_t)(double)(size_t)(double)(iVar9,(int)(size_t)((uint64_t)(size_t)dVar24 >> 0x20))", "0.0f")
code = code.replace("(float)(size_t)(double)(size_t)(double)(in_stack_ffffffcc,(int)(size_t)((uint64_t)(size_t)dVar24 >> 0x20))", "0.0f")
code = code.replace("(float)(size_t)(double)(size_t)(double)(in_stack_ffffffd4,(int)(size_t)((uint64_t)(size_t)dVar24 >> 0x20))", "0.0f")

# Assignments to GmVec3 from void*
bad_assignments = [
    r'unaff_EBP = \([a-zA-Z0-9_\* ]+\)[^;]+;',
    r'unaff_EBX = \([a-zA-Z0-9_\* ]+\)[^;]+;',
    r'in_stack_ffffff94 = \([a-zA-Z0-9_\* ]+\)[^;]+;',
    r'in_stack_ffffff70 = \([a-zA-Z0-9_\* ]+\)[^;]+;'
]
for p in bad_assignments:
    code = re.sub(p, lambda m: m.group(0).split('=')[0] + '= GmVec3(0,0,0);', code)

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

# Remove stray CFastBuffer casts
code = re.sub(r'\(\s*CFastBuffer<void::void>\s*\*\s*\)', '(void*)', code)

code = code.replace("in_stack_ffffff68", "in_stack_00000068")
code = code.replace("fVar12", "fVar19") 
code = code.replace("in_stack_00000078", "in_stack_00000058")

# Fix syntax errors in array lookups
code = re.sub(r'&this->m_wheels\[\(size_t\)[^\]]+\][^;]+;', r'&this->m_wheels[0];', code) 
code = code.replace("pSVar7 = ((void*)0)unaff_ESI);", "pSVar7 = &this->m_wheels[0];")
code = code.replace("= ((void*)0)unaff_ESI);", "= &this->m_wheels[0];")

final = """#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "CHmsItem.hpp"
#include <cmath>
#include <cstdint>

#define DUMMY_CFAST_CALL(...) ((void*)0)

""" + code

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(final)
