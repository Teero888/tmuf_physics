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
            
            # Extract all readable ascii strings >= 4 chars
            strings = re.findall(b'[a-zA-Z0-9_/\\\\]{4,}', data)
            str_content = b' '.join(strings).decode('ascii')
            
            matched = set()
            for p in solid_paths:
                parts = p.split('/')
                # Get the part after 'Solid'
                try:
                    solid_idx = parts.index('Solid')
                except ValueError:
                    continue
                relevant = '/'.join(parts[solid_idx+1:])
                # Replace '/' with '\' and check if it's in str_content, or just check the last two folders
                p1, p2 = parts[-2], parts[-1]
                if p1 in str_content and p2 in str_content:
                    matched.add(p)
            
            if matched:
                block_map[block_name] = sorted(list(matched))

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
