import struct

def test_be(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4 + 4
    idx += 1536 * 12 # vertices
    
    print("Reading Triangles as Big-Endian Ints:")
    for i in range(2):
        chunk = data[idx:idx+32]
        ints = struct.unpack(">8I", chunk)
        print(f"Tri {i}: {ints}")
        idx += 32

test_be("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
