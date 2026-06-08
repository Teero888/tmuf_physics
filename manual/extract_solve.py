import re

def extract_and_clean_solve_impulse():
    with open('../tmnf_dump/src/CHmsZoneDynamic.cpp', 'r') as f:
        content = f.read()
    
    start_idx = content.find('void __thiscall\nCHmsZoneDynamic::SolveImpulse')
    if start_idx == -1:
        print("Could not find SolveImpulse")
        return
        
    end_idx = content.find('\n}\n}', start_idx) + 4
    if end_idx < start_idx:
        print("Could not find end")
        return
        
    func_body = content[start_idx:end_idx]
    
    # Cleanups
    func_body = func_body.replace('void __thiscall\nCHmsZoneDynamic::SolveImpulse', 'void CHmsZoneDynamic::SolveImpulse')
    func_body = func_body.replace('(CHmsZoneDynamic *this,CHmsZoneDynamic *param_1,SHmsPhysicalCollision *param_2,\n          CHmsPhysicalContact *param_3,CHmsPhysicalContact *param_4)', '(SHmsPhysicalCollision *param_1, CHmsPhysicalContact *param_3, CHmsPhysicalContact *param_4)')
    func_body = func_body.replace('uint', 'uint32_t')
    func_body = func_body.replace('ushort', 'uint16_t')
    func_body = func_body.replace('uchar', 'uint8_t')
    func_body = func_body.replace('undefined4', 'uint32_t')
    func_body = func_body.replace('float10', 'float')
    func_body = func_body.replace('longlong', 'long long')
    func_body = func_body.replace('ulonglong', 'unsigned long long')
    func_body = func_body.replace('ulong', 'uint32_t')
    
    # Just to make it syntactically valid C++ as a starting point
    func_body = re.sub(r'in_stack_[0-9a-f]+', 'local_var', func_body)
    func_body = re.sub(r'extraout_ST[0-9]+(_[0-9]+)?', 'local_fvar', func_body)
    func_body = re.sub(r'unaff_[A-Z]+', 'local_reg', func_body)
    
    # We will write this raw cleaned string to a file to inspect.
    with open('Hms/CHmsZoneDynamic_SolveImpulse.cpp', 'w') as f:
        f.write('#include "CHmsZoneDynamic.hpp"\n')
        f.write('#include "GmVec3.hpp"\n')
        f.write('#include "CHmsCorpus.hpp"\n')
        f.write('#include "CHmsDyna.hpp"\n\n')
        f.write('float DAT_00d6eec0 = 0.5f;\n')
        f.write('float _DAT_00b56fb4 = 0.0001f;\n')
        f.write('float func_0x009c1b40() { return 1.0f; }\n\n')
        f.write(func_body)

extract_and_clean_solve_impulse()
