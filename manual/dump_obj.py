import struct

def dump_obj(filepath):
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
    
    meshVersion = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    numVertices = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    numTriangles = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    with open("mesh_verts.obj", "w") as out:
        for _ in range(numVertices):
            v = struct.unpack("<3f", data[idx:idx+12])
            out.write(f"v {v[0]} {v[1]} {v[2]}\n")
            idx += 12
            
    print(f"Dumped {numVertices} vertices to mesh_verts.obj")

dump_obj("solid_decompressed.bin")
