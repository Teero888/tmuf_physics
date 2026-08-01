import struct

def dump_triangle(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4 + 4
    # idx is at Vertices
    idx += 1536 * 12
    # idx is at Triangles
    
    chunk = data[idx:idx+32]
    print("Triangle 0 bytes:", chunk.hex())
    floats = struct.unpack("<8f", chunk)
    ints = struct.unpack("<8I", chunk)
    shorts = struct.unpack("<16H", chunk)
    print("Floats:", floats)
    print("Ints:", ints)
    print("Shorts:", shorts)

dump_triangle("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
