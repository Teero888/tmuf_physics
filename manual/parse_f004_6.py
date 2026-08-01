import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = 0x04BCEE
    print(f"Data around 0x{idx:06X}:")
    for i in range(-2, 4):
        offset = idx + i * 4
        if offset + 4 <= len(data):
            word = struct.unpack("<I", data[offset:offset+4])[0]
            print(f"  Offset 0x{offset:06X}: 0x{word:08X} ({word})")

parse("solid_decompressed.bin")
