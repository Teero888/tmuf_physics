import zipfile
import re
import json

block_map = {}

# All paths in zip
solid_paths = []

with zipfile.ZipFile('../Stadium.zip', 'r') as z:
    for name in z.namelist():
        if name.endswith('.Solid.Gbx'):
            solid_paths.append(name)
    
    for name in z.namelist():
        if name.endswith('.TMEDClassic.Gbx') or name.endswith('.TMEDRoad.Gbx') or name.endswith('.TMEDClip.Gbx'):
            # The block name is the filename without extension
            basename = name.split('/')[-1]
            block_name = basename.split('.')[0]
            
            data = z.read(name)
            strings = re.findall(b'[\x20-\x7E]{5,}', data)
            solids = [s.decode('ascii') for s in strings if s.endswith(b'.Solid.Gbx')]
            
            # Match the short names (e.g. "BaseGround.Solid.Gbx") with paths in solid_paths
            # We will just save all matched solid_paths that end with any of these solids
            matched = []
            for s in solids:
                for p in solid_paths:
                    if p.endswith(s):
                        matched.append(p)
            
            # Deduplicate and sort
            matched = sorted(list(set(matched)))
            if matched:
                block_map[block_name] = matched

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
