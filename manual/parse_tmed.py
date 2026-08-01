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
            
            # The structure often has "Media/Solid/" then the path.
            # We can find all strings that end with .Solid.Gbx, and then check all solid_paths
            # to see if they end with it. BUT to disambiguate, we can look for the folder names!
            strings = re.findall(b'[a-zA-Z0-9_/\\\\]{3,}', data)
            str_list = [s.decode('ascii').replace('\\', '/') for s in strings]
            
            matched = set()
            for p in solid_paths:
                # If the solid path is like Stadium/Media/Solid/Circuit/Road/BaseGround.Solid.Gbx
                # we check if all its components (like 'Circuit', 'Road', 'BaseGround.Solid.Gbx') 
                # are present in the TMED strings!
                parts = p.split('/')
                # Media/Solid is common, so we check parts after Solid
                try:
                    solid_idx = parts.index('Solid')
                except ValueError:
                    continue
                relevant_parts = parts[solid_idx+1:]
                
                # Check if all relevant_parts are present in str_list
                # Actually, some might be concatenated. Let's just check if the last 2 parts are in the file!
                if len(relevant_parts) >= 2:
                    p1, p2 = relevant_parts[-2], relevant_parts[-1]
                    # Also the full suffix
                    suffix = p1 + '/' + p2
                    # If this suffix or these parts are mentioned in the file
                    if p2 in str_list and p1 in str_list:
                        matched.add(p)
            
            if matched:
                block_map[block_name] = sorted(list(matched))

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
