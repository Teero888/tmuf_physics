import re
import sys
import os

def parse_dump(file_path):
    print(f"Reading {file_path}...")
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()

    print("Splitting into functions...")
    chunks = re.split(r'// =+\n// Function: .+\n// =+\n', content)
    chunks = chunks[1:]

    function_map = {}
    sig_name_regex = re.compile(r'([\w<>:~]+)\s*\(')
    call_regex = re.compile(r'\b([\w<>:~]+)\s*\(')
    
    reserved = {
        'if', 'while', 'for', 'switch', 'return', 'sizeof', '__thiscall', '__cdecl', '__stdcall', '__fastcall',
        'operator', 'new', 'delete', 'void', 'int', 'char', 'float', 'double', 'long', 'short', 'unsigned', 'signed',
        'struct', 'class', 'enum', 'union', 'typedef', 'static', 'const', 'extern', 'inline', 'break', 'continue',
        'case', 'default', 'do', 'goto', 'uint', 'ulong', 'ushort', 'uchar', 'longlong', 'code', 'undefined', 'undefined1',
        'undefined2', 'undefined4', 'undefined8', 'byte', 'word', 'dword', 'qword'
    }

    print(f"Processing {len(chunks)} chunks...")
    for chunk in chunks:
        brace_pos = chunk.find('{')
        if brace_pos == -1:
            continue
            
        signature = chunk[:brace_pos].strip()
        body = chunk[brace_pos:].strip()
        
        matches = list(sig_name_regex.finditer(signature))
        if not matches:
            continue
            
        func_name = matches[-1].group(1)
        
        # Skip standard library function definitions
        std_prefixes = ['std::', 'basic_string', 'vector', 'map', 'set', 'list', 'deque', 'ostream', 'istream', 'iostream', 'allocator', 'char_traits']
        is_std = False
        for prefix in std_prefixes:
            if func_name.startswith(prefix) or ("::" in func_name and prefix in func_name.split("::")[0]):
                is_std = True
                break
        if is_std:
            continue

        calls = set()
        for call_match in call_regex.finditer(body):
            name = call_match.group(1)
            if name not in reserved:
                calls.add(name)
        
        types = set()
        type_candidate_regex = re.compile(r'\b([CSEG][A-Z]\w+)\b')
        for type_match in type_candidate_regex.finditer(chunk):
            types.add(type_match.group(1))
            
        cast_regex = re.compile(r'\(([\w\s\*:]+)\s*\*+\)')
        for cast_match in cast_regex.finditer(chunk):
            t = cast_match.group(1).strip()
            t = re.sub(r'\b(const|struct|class)\b', '', t).strip()
            if t and t not in reserved and not t.isdigit():
                t_parts = t.split()
                if t_parts:
                    types.add(t_parts[-1])

        function_map[func_name] = {
            'signature': signature,
            'body': body,
            'calls': calls,
            'types': types
        }
    
    return function_map

def recurse_functions(start_funcs, function_map, physics_classes, physics_keywords):
    visited = set()
    to_visit = list(start_funcs)
    
    # Also add all functions from physics classes OR containing physics keywords to the starting set
    for func_name in function_map:
        is_physics = False
        for p_class in physics_classes:
            if func_name.startswith(p_class + "::"):
                is_physics = True
                break
        if not is_physics:
            func_name_lower = func_name.lower()
            for kw in physics_keywords:
                if kw.lower() in func_name_lower:
                    if "::" in func_name:
                        is_physics = True
                        break
        
        if is_physics:
            to_visit.append(func_name)

    found_functions = {}
    found_types = set()
    
    while to_visit:
        current = to_visit.pop(0)
        if current in visited:
            continue
        
        visited.add(current)
        
        if current in function_map:
            info = function_map[current]
            found_functions[current] = info
            found_types.update(info['types'])
            
            for call in info['calls']:
                if call not in visited:
                    to_visit.append(call)
        else:
            # Fuzzy match
            found_alt = False
            for func_name in function_map:
                if func_name.endswith("::" + current) or current.endswith("::" + func_name):
                    if len(func_name) > 5:
                        if func_name not in visited:
                            to_visit.append(func_name)
                            found_alt = True
                            break
            if not found_alt:
                pass
            
    return found_functions, found_types

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python recursive_extract.py <dump_file> <start_function>")
        sys.exit(1)
        
    dump_file = sys.argv[1]
    start_func = sys.argv[2]
    
    physics_classes = [
        "CHmsDyna", "CHmsCorpus", "CHmsItem", "CHmsCollision", "CPlugPhysicalObject",
        "CSceneVehicleCar", "CSceneVehicleCarTuning", "CSceneVehicleTuning", "CSceneVehicleTunings",
        "GmVec2", "GmVec3", "GmVec4", "GmMat2", "GmMat3", "GmMat4", "GmQuat", "GmIso3", "GmIso4",
        "SSurfaceId", "SDynaMath", "CPlugSurface", "CPlugSurfaceGeom", "CHmsCollisionManager",
        "CHmsCollisionBuffer", "CHmsConfig", "CHmsZone", "CHmsPortal", "CPlugSolid", "CPlugTree",
        "CMwTimer", "CMwProfiler", "CMwCmdBuffer", "CMwCmdBufferCore", "CGameVehicle", "CSceneVehicle",
        "CGameRace", "CGamePlayer", "CGameMobil", "CSceneMobil"
    ]
    
    physics_keywords = [
        "Simulate", "Integrate", "Step", "Advance", "UpdateAsync", "Physics", "Dynamics", "Collision",
        "Contact", "Force", "Impulse", "Torque", "Gravity", "Dampen", "Friction", "Tire", "Wheel"
    ]
    
    function_map = parse_dump(dump_file)
    
    print(f"Recursively searching from {start_func} and physics classes/keywords...")
    found_funcs, found_types = recurse_functions([start_func], function_map, physics_classes, physics_keywords)
    
    final_types = set()
    for t in found_types:
        t = re.sub(r'<.*>', '', t)
        if t and not t.isdigit():
            final_types.add(t)

    output_list = "physics_extracted_list.txt"
    print(f"Writing list to {output_list}...")
    with open(output_list, 'w') as f:
        f.write(f"Functions found: {len(found_funcs)}\n")
        f.write(f"Types found: {len(final_types)}\n\n")
        
        f.write("=== TYPES ===\n")
        for t in sorted(list(final_types)):
            f.write(f"{t}\n")
        f.write("\n")
        
        f.write("=== FUNCTIONS ===\n")
        for name in sorted(found_funcs.keys()):
            f.write(f"{name}\n")

    output_code = "physics_extracted_code.c"
    print(f"Writing code to {output_code}...")
    with open(output_code, 'w') as f:
        f.write("// Extracted Physics Code\n")
        f.write("// Starting from: " + start_func + " and core physics classes/keywords\n\n")
        
        for name in sorted(found_funcs.keys()):
            f.write(f"// =================================================\n")
            f.write(f"// Function: {name}\n")
            f.write(f"// =================================================\n")
            f.write(found_funcs[name]['signature'] + "\n")
            f.write("{\n" + found_funcs[name]['body'] + "\n}\n\n")

    print("Done.")
