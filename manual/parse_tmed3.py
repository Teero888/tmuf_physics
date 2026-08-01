import zipfile
import json
import re

block_map = {}

with zipfile.ZipFile('../Stadium.zip', 'r') as z:
    solid_paths = [name for name in z.namelist() if name.endswith('.Solid.Gbx')]
    
    for name in z.namelist():
        if name.endswith('.TMEDClassic.Gbx') or name.endswith('.TMEDRoad.Gbx') or name.endswith('.TMEDClip.Gbx'):
            basename = name.split('/')[-1]
            block_name = basename.split('.')[0]
            data = z.read(name)
            
            # Just find ALL Solid filenames in the data
            strings = re.findall(b'[a-zA-Z0-9_.-]+\\.Solid\\.Gbx', data)
            found_solids = set([s.decode('ascii') for s in strings])
            
            # Now we need to figure out which full solid_path corresponds to these
            # A TMED file often contains the folder names too
            folders_b = re.findall(b'[a-zA-Z0-9_]{3,}', data)
            folders = set([f.decode('ascii') for f in folders_b])
            
            matched = []
            for p in solid_paths:
                p_file = p.split('/')[-1]
                if p_file in found_solids:
                    # check if the parent folder is also in the TMED file!
                    parent = p.split('/')[-2]
                    if parent in folders:
                        matched.append(p)
                        
            if matched:
                block_map[block_name] = sorted(list(set(matched)))

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
