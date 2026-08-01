import sys
import struct
filepath = sys.argv[1]
with open(filepath, "rb") as f:
    data = f.read()
for i in range(len(data) - 4):
    val = struct.unpack("<I", data[i:i+4])[0]
    if (val & 0xFF000000) == 0x09000000:
        if (val & 0x00000FFF) == 0:
            print(f"Offset 0x{i:06X}: Class ID 0x{val:08X}")
