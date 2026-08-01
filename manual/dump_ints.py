import struct

def dump_ints(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    print(f"Chunk 0x0900F004 at {idx}")
    idx += 4 # chunk id
    idx += 4 # idIndex
    idx += 24 # boxMin, boxMax
    
    # Dump the next 10 integers
    ints = struct.unpack("<10I", data[idx:idx+40])
    for i, val in enumerate(ints):
        print(f"Word {i}: {val} (0x{val:08x})")
        
    # Also dump as floats
    floats = struct.unpack("<10f", data[idx:idx+40])
    for i, val in enumerate(floats):
        print(f"Float {i}: {val}")

dump_ints("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
