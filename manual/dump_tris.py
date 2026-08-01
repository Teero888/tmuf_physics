import struct

def dump_triangles(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4 + 4
    idx += 1536 * 12 # vertices
    
    print("Dumping u1, u2, u3 (offsets 0x10, 0x14, 0x18) for first 10 Triangles:")
    for i in range(10):
        chunk = data[idx:idx+32]
        ints = struct.unpack("<8I", chunk)
        # +0x10 is ints[4]
        # +0x14 is ints[5]
        # +0x18 is ints[6]
        # +0x1C is ints[7]
        print(f"Tri {i}: u1={ints[4]}, u2={ints[5]}, u3={ints[6]}, u4={ints[7]}")
        idx += 32

dump_triangles("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
