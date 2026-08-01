import sys
import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = 0x04FEA8
    print(f"Data at 0x{idx:06X} (Expected Triangles):")
    for i in range(16):
        if idx + 4 <= len(data):
            word = struct.unpack("<I", data[idx:idx+4])[0]
            print(f"  Word {i}: 0x{word:08X} ({word})")
            idx += 4

parse("solid_decompressed.bin")
