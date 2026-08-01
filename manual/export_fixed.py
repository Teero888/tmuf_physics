import struct

def export_obj(filepath, outpath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4
    numVertices = struct.unpack("<I", data[idx:idx+4])[0]
    idx += 4
    
    vertices = []
    for _ in range(numVertices):
        v = struct.unpack("<3f", data[idx:idx+12])
        vertices.append(v)
        idx += 12
        
    numTriangles = struct.unpack("<H", data[idx:idx+2])[0]
    idx += 2
    
    triangles = []
    for _ in range(numTriangles):
        t = struct.unpack("<4H", data[idx:idx+8])
        triangles.append(t)
        idx += 8

    with open(outpath, "w") as f:
        for v in vertices:
            f.write(f"v {v[0]} {v[1]} {v[2]}\n")
        for t in triangles:
            f.write(f"f {t[0]+1} {t[1]+1} {t[2]+1}\n")

    print(f"Exported {numVertices} vertices and {numTriangles} triangles to {outpath}")

export_obj("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B", "fixed.obj")
