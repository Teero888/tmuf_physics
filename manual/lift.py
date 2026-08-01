import sys
import re

def parse_asm(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
        
    out = []
    out.append("#include <stdint.h>")
    out.append("#include <stdio.h>")
    out.append("#include <math.h>")
    out.append("")
    out.append("struct CPU {")
    out.append("    uint32_t eax, ebx, ecx, edx, esi, edi, ebp, esp;")
    out.append("    float st[8];")
    out.append("    int fpu_top;")
    out.append("    uint8_t flags;")
    out.append("};")
    out.append("")
    out.append("extern CPU cpu;")
    out.append("extern uint8_t* mem;")
    out.append("")
    out.append("void ComputeForcesModel3_Exact_Lifted() {")
    
    for line in lines:
        if not line.strip() or line.startswith("..") or line.startswith("Disassembly"):
            continue
        
        match = re.match(r'\s*([0-9a-f]+):\s+([0-9a-f ]+)\s+(.+)', line)
        if match:
            addr = match.group(1)
            raw_bytes = match.group(2)
            instr = match.group(3).strip()
            
            # Remove comments from objdump
            if '<' in instr:
                instr = instr.split('<')[0].strip()
            
            out.append(f"    /* {addr} */ // {instr}")
        else:
            if "<.text" in line:
                pass
            else:
                out.append(f"    // Unparsed: {line.strip()}")
                
    out.append("}")
    
    with open('lifted_forces.cpp', 'w') as f:
        f.write("\n".join(out) + "\n")

if __name__ == "__main__":
    parse_asm("c_forces_asm.txt")
