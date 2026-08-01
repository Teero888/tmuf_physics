import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4 + 4
    # idx is now at Word 10
    
    numVertices = 1606
    print(f"Skipping {numVertices * 12} bytes...")
    idx += numVertices * 12
    
    # Dump 64 bytes
    dump = data[idx:idx+64]
    print("Hex:")
    for i in range(0, len(dump), 16):
        print(dump[i:i+16].hex())
    
    print("UInt16:")
    for i in range(0, len(dump), 16):
        print(struct.unpack("<8H", dump[i:i+16]))

parse("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
