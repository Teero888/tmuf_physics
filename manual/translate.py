import re

with open('../tmnf_dump/src/CHmsZoneDynamic.cpp', 'r') as f:
    lines = f.readlines()

start_idx = -1
end_idx = -1
for i, line in enumerate(lines):
    if "CHmsZoneDynamic::SolveImpulse" in line and "void __thiscall" in lines[i-1]:
        start_idx = i - 1
    if start_idx != -1 and line.startswith("}") and i > start_idx + 10:
        if lines[i-1].startswith("}"):
            end_idx = i + 1
            break

if start_idx == -1 or end_idx == -1:
    print("Could not find SolveImpulse")
    exit(1)

code = "".join(lines[start_idx:end_idx])

# Replacements
code = code.replace('CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2,\n          CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4', 'SHmsPhysicalCollision *collision, CHmsPhysicalContact *contact1, CHmsPhysicalContact *contact2')
code = code.replace('param_1', 'collision')
code = code.replace('param_2', 'collision_param2') # Actually, ECX was `this` and param_1 was also `this`?
# In Ghidra __thiscall: ECX=this. Stack args: param_1, param_2, param_3, param_4.
# Wait, the signature in ghidra is:
# void __thiscall CHmsZoneDynamic::SolveImpulse(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2, CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4)
# Actually, the real signature is:
# void CHmsZoneDynamic::SolveImpulse(SHmsPhysicalCollision* collision, CHmsPhysicalContact* contact1, CHmsPhysicalContact* contact2)
# If the real has 3 args, ghidra has this, param_1(this?), param_2(collision), param_3(contact1), param_4(contact2).
# Let's look at the body of the ghidra function.
# fVar5 = *(float *)param_1;  <- this means param_1 is the collision!
# Why? Because in MSVC __thiscall, this is in ECX. 
# But maybe ghidra inferred `param_1` is the first stack argument. If it's `collision`, then `param_1` = `collision`.
# `param_3` = `contact1`, `param_4` = `contact2`? Let's check `if (param_3 != (CHmsPhysicalContact *)0x0)`
# Yes, `param_3` and `param_4` are the contacts.
# So param_1 -> collision, param_3 -> contact1, param_4 -> contact2. param_2 is unused? Wait, in line 915:
# fVar5 = (float)param_2 * *(float *)(param_1 + 0x20) + (float)param_1 * *(float *)(param_1 + 0x1c) + (float)param_3 * *(float *)(param_1 + 0x24);
# Wait, casting param_1 and param_3 to float? That means they are registers that got misidentified as parameters!
# Ah! In MSVC __thiscall, `this` is in ECX. 
# If Ghidra says `fVar5 = (float)param_2 * ...` where `param_2` is cast to float, maybe `param_2` was a floating point register? No, param_2 is a pointer in the signature.
# Actually, `*(float *)param_1` = `m_value00`. `*(int *)(param_1 + 8)` = `m_body`. This exactly matches `SHmsPhysicalCollision`. So `param_1` is `collision`!

with open('Hms/CHmsZoneDynamic_SolveImpulse_Exact.cpp', 'w') as f:
    f.write(code)

print("Saved to Hms/CHmsZoneDynamic_SolveImpulse_Exact.cpp")
