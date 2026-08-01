import struct

def find_offset(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    if idx == -1: return
    idx += 4
    
    print("Words after 0x0900F004:")
    for i in range(20):
        val = struct.unpack("<I", data[idx+i*4:idx+i*4+4])[0]
        fval = struct.unpack("<f", data[idx+i*4:idx+i*4+4])[0]
        print(f"  Word {i}: 0x{val:08X} ({val}) - float: {fval}")

find_offset("solid_decompressed.bin")
