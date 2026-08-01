import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    if idx == -1: return
    idx += 4
    
    idx += 4 # CMwId
    
    boxMin = struct.unpack("<3f", data[idx:idx+12])
    idx += 12
    boxMax = struct.unpack("<3f", data[idx:idx+12])
    idx += 12
    
    key_float = boxMin[0] - boxMax[0]
    key_int = struct.unpack("<I", struct.pack("<f", key_float))[0]
    
    meshVersion = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    numVertices = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    numTriangles = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    idx += numVertices * 12
    
    print(f"numTriangles: {numTriangles}")
    for i in range(min(5, numTriangles)):
        chunk = data[idx:idx+32]
        idx += 32
        
        ints = struct.unpack("<8I", chunk)
        dec_ints = []
        for x in ints:
            xored = x ^ key_int
            # bswap32
            bswapped = ((xored << 24) & 0xff000000) | ((xored << 8) & 0x00ff0000) | ((xored >> 8) & 0x0000ff00) | ((xored >> 24) & 0x000000ff)
            dec_ints.append(bswapped)
            
        dec_floats = [struct.unpack("<f", struct.pack("<I", x))[0] for x in dec_ints]
        
        print(f"Tri {i}:")
        print(f"  Vec4 U01: {dec_floats[0]:.4f}, {dec_floats[1]:.4f}, {dec_floats[2]:.4f}, {dec_floats[3]:.4f}")
        print(f"  Int3 Indices: {dec_ints[4]}, {dec_ints[5]}, {dec_ints[6]}")
        
        w7_bytes = struct.pack("<I", dec_ints[7])
        surf_idx, u04, u05 = struct.unpack("<hBB", w7_bytes)
        print(f"  SurfaceIndex: {surf_idx}, U04: {u04}, U05: {u05}")

parse("solid_decompressed.bin")
