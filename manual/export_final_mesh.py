import struct
import math

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    if idx == -1:
        print("0x0900F004 not found")
        return

    idx += 4
    idx += 4 # CMwId
    
    idx += 24 # Bounding Box
    meshVersion = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    numVertices = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    numTriangles = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    vertices = []
    for i in range(numVertices):
        v_data = data[idx:idx+12]
        idx += 12
        if i < 17:
            x, y, z = struct.unpack("<3f", v_data)
            vertices.append((x, y, z))
        elif i >= 17 and i <= 24:
            # garbage, just append 0
            vertices.append((0, 0, 0))
        else:
            ints = struct.unpack("<3I", v_data)
            v = []
            for val in ints:
                bswapped = ((val << 24) & 0xff000000) | ((val << 8) & 0x00ff0000) | ((val >> 8) & 0x0000ff00) | ((val >> 24) & 0x000000ff)
                v.append(struct.unpack("<f", struct.pack("<I", bswapped))[0])
            vertices.append(v)
            
    # STriangle array
    idx += numTriangles * 32
    
    # Octree version
    octree_ver = data[idx]
    idx += 1
    
    # CookedTriangles
    tris = []
    for i in range(numTriangles):
        chunk = data[idx:idx+32]
        idx += 32
        
        i0, i1, i2 = struct.unpack("<3I", chunk[16:28])
        tris.append((i0, i1, i2))
        
    # write to obj
    with open("track_mesh_final.obj", "w") as out:
        for v in vertices:
            out.write(f"v {v[0]} {v[1]} {v[2]}\n")
        for t in tris:
            out.write(f"f {t[0]+1} {t[1]+1} {t[2]+1}\n")
            
    print(f"Exported track_mesh_final.obj with {numVertices} vertices and {numTriangles} triangles.")

parse("solid_decompressed.bin")
