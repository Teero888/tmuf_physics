import json

with open('block_map.json', 'r') as f:
    block_map = json.load(f)

out = "#pragma once\n#include <string>\n#include <vector>\n#include <unordered_map>\n\n"
out += "inline std::unordered_map<std::string, std::vector<std::string>> g_blockMap = {\n"

for block, paths in block_map.items():
    out += f'    {{"{block}", {{\n'
    for p in paths:
        out += f'        "{p}",\n'
    out += "    }},\n"

out += "};\n"

with open('Gm/GmBlockMap.hpp', 'w') as f:
    f.write(out)
