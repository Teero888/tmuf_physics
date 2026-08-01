import sys
import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = 0x04B6A8
    vertex_count = 1536
    end_idx = idx + vertex_count * 12
    
    print(f"End of vertices is 0x{end_idx:06X}")
    print("Next 16 words after vertices:")
    for i in range(16):
        if end_idx + 4 <= len(data):
            word = struct.unpack("<I", data[end_idx:end_idx+4])[0]
            try:
                float_val = struct.unpack("<f", data[end_idx:end_idx+4])[0]
            except:
                float_val = float('nan')
            print(f"  Word {i}: 0x{word:08X} ({word})  Float: {float_val}")
            end_idx += 4

parse("solid_decompressed.bin")
