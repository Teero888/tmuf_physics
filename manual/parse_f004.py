import sys
import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    if idx == -1:
        print("0x0900F004 not found.")
        return
    
    print(f"Found 0x0900F004 at 0x{idx:06X}")
    idx += 4
    
    # 1. CMwId::Archive
    # Usually a 32-bit int. Let's print the next few words.
    print("Next 40 words:")
    for i in range(40):
        if idx + 4 <= len(data):
            word = struct.unpack("<I", data[idx:idx+4])[0]
            float_val = struct.unpack("<f", data[idx:idx+4])[0]
            print(f"  Word {i}: 0x{word:08X} ({word})  Float: {float_val}")
            idx += 4

parse("solid_decompressed.bin")
