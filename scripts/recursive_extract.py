import re
import sys
import os

# Resolve absolute paths relative to this script's location
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

def parse_dump(file_path):
    # If path is relative, resolve it relative to CURRENT WORKING DIRECTORY
    # (Because the dump file is usually provided as a CLI argument)
    abs_path = os.path.abspath(file_path)
    print(f"Reading {abs_path}...")
    with open(abs_path, 'r', encoding='utf-8', errors='ignore') as f:
        content = f.read()
    print("Splitting into functions...")
    chunks = re.split(r'// =+\n// Function: .+\n// =+\n', content)
    chunks = chunks[1:]
    function_map = {}
    sig_name_regex = re.compile(r'([\w<>:~]+)\s*\(')
    call_regex = re.compile(r'\b([\w<>:~]+)\s*\(')
    reserved = {'if', 'while', 'for', 'switch', 'return', 'sizeof', '__thiscall', '__cdecl', '__stdcall', '__fastcall',
                'operator', 'new', 'delete', 'void', 'int', 'char', 'float', 'double', 'long', 'short', 'unsigned', 'signed',
                'struct', 'class', 'enum', 'union', 'typedef', 'static', 'const', 'extern', 'inline', 'break', 'continue',
                'case', 'default', 'do', 'goto', 'uint', 'ulong', 'ushort', 'uchar', 'longlong', 'code', 'undefined', 'undefined1',
                'undefined2', 'undefined4', 'undefined8', 'byte', 'word', 'dword', 'qword'}
    print(f"Processing {len(chunks)} chunks...")
    for chunk in chunks:
        brace_pos = chunk.find('{')
        if brace_pos == -1: continue
        signature = chunk[:brace_pos].strip()
        body = chunk[brace_pos:].strip()
        matches = list(sig_name_regex.finditer(signature))
        if not matches: continue
        func_name = matches[-1].group(1)
        std_prefixes = ['std::', 'basic_string', 'vector', 'map', 'set', 'list', 'deque', 'ostream', 'istream', 'iostream', 'allocator', 'char_traits']
        if any(func_name.startswith(p) or ("::" in func_name and p in func_name.split("::")[0]) for p in std_prefixes): continue
        calls = set()
        for call_match in call_regex.finditer(body):
            name = call_match.group(1)
            if name not in reserved: calls.add(name)
        types = set()
        for type_match in re.finditer(r'\b([CSEG][A-Z]\w+)\b', chunk): types.add(type_match.group(1))
        for cast_match in re.finditer(r'\(([\w\s\*:]+)\s*\*+\)', chunk):
            t = re.sub(r'\b(const|struct|class)\b', '', cast_match.group(1)).strip()
            if t and t not in reserved and not t.isdigit():
                parts = t.split()
                if parts: types.add(parts[-1])
        function_map[func_name] = {'signature': signature, 'body': body, 'calls': calls, 'types': types}
    return function_map

def recurse_functions(start_funcs, function_map, physics_classes, physics_keywords):
    visited = set()
    to_visit = list(start_funcs)
    for func_name in function_map:
        is_physics = any(func_name.startswith(pc + "::") for pc in physics_classes)
        if not is_physics:
            is_physics = any(kw.lower() in func_name.lower() and "::" in func_name for kw in physics_keywords)
        if is_physics: to_visit.append(func_name)
    found_functions = {}
    found_types = set()
    while to_visit:
        current = to_visit.pop(0)
        if current in visited: continue
        visited.add(current)
        if current in function_map:
            info = function_map[current]
            found_functions[current] = info
            found_types.update(info['types'])
            for call in info['calls']:
                if call not in visited: to_visit.append(call)
        else:
            for func_name in function_map:
                if (func_name.endswith("::" + current) or current.endswith("::" + func_name)) and len(func_name) > 5:
                    if func_name not in visited:
                        to_visit.append(func_name)
                        break
    return found_functions, found_types

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python recursive_extract.py <dump_file> <start_function>")
        sys.exit(1)
    dump_file = sys.argv[1]
    start_func = sys.argv[2]
    physics_classes = ["CHmsDyna", "CHmsCorpus", "CHmsItem", "CHmsCollision", "CPlugPhysicalObject", "CSceneVehicleCar", "CSceneVehicleCarTuning", "CSceneVehicleTuning", "CSceneVehicleTunings", "GmVec2", "GmVec3", "GmVec4", "GmMat2", "GmMat3", "GmMat4", "GmQuat", "GmIso3", "GmIso4", "SSurfaceId", "SDynaMath", "CPlugSurface", "CPlugSurfaceGeom", "CHmsCollisionManager", "CHmsCollisionBuffer", "CHmsConfig", "CHmsZone", "CHmsPortal", "CPlugSolid", "CPlugTree", "CMwTimer", "CMwProfiler", "CMwCmdBuffer", "CMwCmdBufferCore", "CGameVehicle", "CSceneVehicle", "CGameRace", "CGamePlayer", "CGameMobil", "CSceneMobil"]
    physics_keywords = ["Simulate", "Integrate", "Step", "Advance", "UpdateAsync", "Physics", "Dynamics", "Collision", "Contact", "Force", "Impulse", "Torque", "Gravity", "Dampen", "Friction", "Tire", "Wheel"]
    function_map = parse_dump(dump_file)
    found_funcs, found_types = recurse_functions([start_func], function_map, physics_classes, physics_keywords)
    output_code = os.path.join(SCRIPT_DIR, "physics_extracted_code.c")
    with open(output_code, 'w') as f:
        f.write(f"// Extracted Physics Code from {start_func}\n\n")
        for name in sorted(found_funcs.keys()):
            f.write(f"// =================================================\n// Function: {name}\n// =================================================\n{found_funcs[name]['signature']}\n{{\n{found_funcs[name]['body']}\n}}\n\n")
    print(f"Done. Extracted code in {output_code}")
