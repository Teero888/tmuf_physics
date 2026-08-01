import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    code = f.read()

# Replace the broken steering block with a cleaner one
steer_block = """
              if (*(int*)((char*)(size_t)pSVar7 + 4) != 0) {
                extern float g_carSteer;
                float steer_angle = g_carSteer; // We can adjust sign later
                float cos_a = std::cos(steer_angle);
                float sin_a = std::sin(steer_angle);
                
                // Original code was rotating the right vector by the steer angle
                // unaff_EBP, unaff_EBX, in_stack_ffffff94 is the normalized vector
                float x = (float)(size_t)unaff_EBP;
                float y = (float)(size_t)unaff_EBX;
                float z = (float)(size_t)in_stack_ffffff94;
                
                // Assuming rotation around Z axis (0,0,1)? No, steering is around Y axis!
                // Let's just use a standard Y-axis rotation matrix for the wheel right vector
                float new_x = x * cos_a + z * sin_a;
                float new_y = y;
                float new_z = -x * sin_a + z * cos_a;
                
                unaff_EBP = (void*)(size_t)*(uint32_t*)&new_x;
                unaff_EBX = (void*)(size_t)*(uint32_t*)&new_y;
                in_stack_ffffff94 = (void*)(size_t)*(uint32_t*)&new_z;
              }
"""

# Find the old block:
old_block_regex = r"if \(\*\(\s*int\*\s*\)\(\(char\*\)\(size_t\)pSVar7 \+ 4\) \!= 0\) \{.*?in_stack_ffffff94 = GmVec3\(0,0,0\);\s*\}"

code = re.sub(old_block_regex, steer_block, code, flags=re.DOTALL)

with open("scratch_ComputeForcesModel3_patched.cpp", "w") as f:
    f.write(code)

print("Patched steering block")
