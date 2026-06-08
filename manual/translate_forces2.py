import re

with open('scratch_ForcesModel3.cpp', 'r') as f:
    code = f.read()

# Includes
headers = """#include "CSceneVehicleCar.hpp"
#include "CSceneVehicleCarTuning.hpp"
#include "CHmsItem.hpp"
#include <cmath>
#include <cstdint>

struct SBlendableVals;

void WheelAddForceToVehicle(CSceneVehicleCar *this_ptr, CSceneVehicleCar::SSimulationWheel *wheel, float param_4, GmVec3 *param_3) {}
void AddVehicleCentralForce(CSceneVehicleCar *this_ptr, CSceneVehicleCar *param_1, GmVec3 *param_2) {}
void AddVehicleTorque(CSceneVehicleCar *this_ptr, CSceneVehicleCar *param_1, GmVec3 *param_2) {}

double func_0x009c1b40() { return 1.0; } // dummy sqrt
"""

# Replace definition
code = code.replace("void __thiscall\nCSceneVehicleCar::ComputeForcesModel3\n          (CSceneVehicleCar *this,CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3,\n          float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9,\n          SBlendableVals *param_10,int *param_11,float *param_12)", 
"void CSceneVehicleCar_ComputeForcesModel3(CSceneVehicleCar *this_ptr, CSceneVehicleCar *param_1,float param_2,GmVec3 *param_3, float param_4,float param_5,GmVec3 *param_6,GmVec3 *param_7,float param_8,int param_9, SBlendableVals *param_10,int *param_11,float *param_12)")

# Replace all `this` with `this_ptr`
code = re.sub(r'\bthis\b', 'this_ptr', code)

# Remove all variable declarations at the start of the function!
# We will just change them to auto or specific types. But wait, C++ requires declarations.
# Instead of doing that, let's just replace all the Ghidra types with `intptr_t`, `float`, etc.
code = re.sub(r'CFastBuffer<[^>]+>\s*\*', 'float ', code)
code = code.replace("SCasterCat *", "float ")
code = code.replace("GmVec3 *", "float ")
code = code.replace("CSceneVehicleCarTuning *", "float ")
code = code.replace("CSceneVehicleCar *", "float ")
code = code.replace("float10", "double")
code = code.replace("undefined4", "uint32_t")
code = code.replace("undefined2", "uint16_t")
code = code.replace("ulong", "uint32_t")
code = code.replace("ushort", "uint16_t")
code = code.replace("uint", "uint32_t")

# Let's fix the specific pointers that need to be pointers:
code = code.replace("float pSVar7;", "CSceneVehicleCar::SSimulationWheel* pSVar7;")
code = code.replace("float pSVar10;", "CSceneVehicleCar::SSimulationWheel* pSVar10;")
code = code.replace("float param_6;", "GmVec3* param_6;")
code = code.replace("float param_1;", "CSceneVehicleCar* param_1;")
code = code.replace("float param_3;", "GmVec3* param_3;")
code = code.replace("float param_7;", "GmVec3* param_7;")
code = code.replace("float unaff_EBP;", "GmVec3* unaff_EBP;")
code = code.replace("float unaff_EBX;", "GmVec3* unaff_EBX;")
code = code.replace("float in_stack_ffffffd4;", "GmVec3* in_stack_ffffffd4;")
code = code.replace("float in_stack_ffffffe0;", "GmVec3* in_stack_ffffffe0;")
code = code.replace("float in_stack_ffffffcc;", "GmVec3* in_stack_ffffffcc;")

# Remove Ghidra casts entirely!
code = re.sub(r'\(\s*(CFastBuffer<[^>]+>\s*\*)\s*\)', '', code)
code = re.sub(r'\(\s*(SCasterCat\s*\*)\s*\)', '', code)
code = re.sub(r'\(\s*(GmVec3\s*\*)\s*\)', '', code)
code = re.sub(r'\(\s*(CSceneVehicleCarTuning\s*\*)\s*\)', '', code)
code = re.sub(r'\(\s*(CSceneVehicleCar\s*\*)\s*\)', '', code)

# Math replacements
code = code.replace("__CIcos()", "extraout_ST0 = std::cos(0.0)") # dummy arg
code = code.replace("__CIsin()", "extraout_ST0_00 = std::sin(0.0); extraout_ST0_01 = std::sin(0.0)")
code = code.replace("ABS(", "std::abs(")
code = code.replace("NAN(", "std::isnan(")
code = code.replace("SUB84", "(float)")
code = code.replace("CONCAT44", "(double)")

# Fix pointer arithmetic by casting to char*
code = re.sub(r'\(\(int\)([^)]+)\)', r'((int)(size_t)(\1))', code)
code = re.sub(r'\bthis_ptr \+ ([0-9a-fxA-FX]+)', r'((char*)this_ptr + \1)', code)
code = re.sub(r'\bpSVar7 \+ ([0-9a-fxA-FX]+)', r'((char*)pSVar7 + \1)', code)
code = re.sub(r'\bpSVar10 \+ ([0-9a-fxA-FX]+)', r'((char*)pSVar10 + \1)', code)
code = re.sub(r'\bpSVar8 \+ ([0-9a-fxA-FX]+)', r'((char*)pSVar8 + \1)', code)
code = re.sub(r'\biVar1 \+ ([0-9a-fxA-FX]+)', r'((char*)(size_t)iVar1 + \1)', code)
code = re.sub(r'\biVar9 \+ ([0-9a-fxA-FX]+)', r'((char*)(size_t)iVar9 + \1)', code)
code = re.sub(r'\bparam_6 \+ ([0-9a-fxA-FX]+)', r'((char*)param_6 + \1)', code)

# C++ casting syntax for fast buffers
code = re.sub(r'DummyArrayLookup', '0; //', code)

# Globals
code = code.replace("_DAT_00d0ac60", "0.0001f")
code = code.replace("_PTR_00b2c178", "(float*)0")
code = code.replace("_DAT_00b313b8", "1.0f")
code = code.replace("_DAT_00b362c0", "1.0f")
code = code.replace("_DAT_00b36110", "1.0f")
code = code.replace("_DAT_00b2c060", "1.0f")

with open('scratch_ComputeForcesModel3.cpp', 'w') as f:
    f.write(headers + code)
