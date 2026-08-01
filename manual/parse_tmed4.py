import zipfile
import re
import json

block_map = {}

with zipfile.ZipFile('../Stadium.zip', 'r') as z:
    solid_paths = [name for name in z.namelist() if name.endswith('.Solid.Gbx')]
    
    for name in z.namelist():
        if name.endswith('.TMEDClassic.Gbx') or name.endswith('.TMEDRoad.Gbx') or name.endswith('.TMEDClip.Gbx'):
            basename = name.split('/')[-1]
            block_name = basename.split('.')[0]
            data = z.read(name)
            
            # The exact file paths are stored with backslashes or forward slashes, e.g. "Media\Solid\Circuit\Road\BaseGround.Solid.Gbx"
            # But they might be split or length prefixed. However, let's extract all strings of length >= 10
            # that have no spaces and contain ".Solid.Gbx"
            strings = re.findall(b'[a-zA-Z0-9_/\\\\]+\\.Solid\\.Gbx', data)
            str_list = [s.decode('ascii').replace('\\', '/') for s in strings]
            
            matched = []
            for s in str_list:
                # Find the corresponding path in solid_paths
                for p in solid_paths:
                    if p.endswith(s):
                        matched.append(p)
                        break
            
            if matched:
                block_map[block_name] = sorted(list(set(matched)))

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
