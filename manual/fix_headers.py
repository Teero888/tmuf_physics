import os
import re

def fix_header(src, dst):
    if not os.path.exists(src):
        return
    with open(src, 'r') as f:
        code = f.read()
    
    # Remove __thiscall
    code = code.replace('__thiscall ', '')
    code = code.replace('_thiscall ', '')
    
    # Remove ClassName *this,
    # Regex: ClassName *this,  where ClassName is \w+
    code = re.sub(r'\w+\s*\*this,', '', code)
    code = re.sub(r'\w+\s*\*this\)', ')', code)
    
    # Remove ~ClassName(ClassName *param_1) -> ~ClassName()
    code = re.sub(r'~(\w+)\s*\([^)]*\)', r'~\1()', code)
    
    with open(dst, 'w') as f:
        f.write(code)

os.makedirs('Hms', exist_ok=True)
fix_header('../tmnf_dump/include/CHmsItem.hpp', 'Hms/CHmsItem.hpp')
fix_header('../tmnf_dump/include/CHmsCorpus.hpp', 'Hms/CHmsCorpus.hpp')
