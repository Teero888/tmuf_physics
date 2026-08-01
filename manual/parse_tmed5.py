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
            
            # Find all printable strings length >= 3
            strings = re.findall(b'[a-zA-Z0-9_.]{3,}', data)
            str_list = [s.decode('ascii') for s in strings]
            
            matched = []
            
            # Find the index of "Media" and "Solid"
            for i in range(len(str_list) - 2):
                if str_list[i] == 'Media' and str_list[i+1] == 'Solid':
                    # The following strings are the path components until a .Solid.Gbx
                    path_parts = []
                    j = i + 2
                    while j < len(str_list):
                        path_parts.append(str_list[j])
                        if str_list[j].endswith('.Solid.Gbx'):
                            # Form the full path
                            full_path = 'Stadium/Media/Solid/' + '/'.join(path_parts)
                            if full_path in solid_paths:
                                matched.append(full_path)
                            path_parts = [] # Reset for next one?
                            # Wait, sometimes there's multiple Solid.Gbx for the same folder prefix
                            # e.g. Circuit, Road, BaseGround.Solid.Gbx, BaseAir.Solid.Gbx
                            # If so, the next string might just be BaseAir.Solid.Gbx!
                            # Let's just check all solid_paths to see if they can be formed by 
                            # ANY combination of strings that appeared between "Solid" and ".Solid.Gbx"!
                            pass
                        j += 1
                        if j > i + 10: # limit lookahead
                            break
                            
            # An easier way: A valid path in solid_paths has components.
            # E.g. "Stadium/Media/Solid/Circuit/Road/BaseGround.Solid.Gbx"
            # If ALL components after 'Solid' appear in 'str_list' in the SAME order (with possible gaps for multiple files), 
            # then it's a match!
            for p in solid_paths:
                parts = p.split('/')
                try:
                    solid_idx = parts.index('Solid')
                except ValueError:
                    continue
                
                relevant = parts[solid_idx+1:]
                
                # Check if all relevant parts appear in str_list in order
                idx = 0
                match_ok = True
                search_start = 0
                for part in relevant:
                    try:
                        found_idx = str_list.index(part, search_start)
                        search_start = found_idx + 1 # must be after
                    except ValueError:
                        match_ok = False
                        break
                
                if match_ok:
                    matched.append(p)
                    
            if matched:
                block_map[block_name] = sorted(list(set(matched)))

with open('block_map.json', 'w') as f:
    json.dump(block_map, f, indent=2)

print(f"Mapped {len(block_map)} blocks")
