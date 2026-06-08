import struct
import sys

with open("solid_decompressed.bin", "rb") as f:
    data = f.read()

offset = 912
count = struct.unpack("<I", data[offset:offset+4])[0]
print(f"Extracting {count} vertices from offset {offset}")

vertices = []
for i in range(count):
    v_off = offset + 4 + i * 12
    x, y, z = struct.unpack("<fff", data[v_off:v_off+12])
    vertices.append((x, y, z))

tri_offset_start = offset + 4 + count * 12
for i in range(tri_offset_start, len(data) - 4, 4):
    num_indices = struct.unpack("<I", data[i:i+4])[0]
    if 1000 < num_indices < 15000 and num_indices % 3 == 0:
        try:
            indices = struct.unpack(f"<{num_indices}H", data[i+4:i+4+num_indices*2])
            valid = True
            for idx in indices:
                if idx >= count:
                    valid = False
                    break
            if valid:
                print(f"Found {num_indices//3} triangles at offset {i} (16-bit array)")
                with open("vehicle_mesh.obj", "w") as out:
                    for v in vertices:
                        out.write(f"v {v[0]} {v[1]} {v[2]}\n")
                    for j in range(num_indices//3):
                        idx0 = indices[j*3] + 1
                        idx1 = indices[j*3+1] + 1
                        idx2 = indices[j*3+2] + 1
                        out.write(f"f {idx0} {idx1} {idx2}\n")
                print("Saved vehicle_mesh.obj")
                sys.exit(0)
        except:
            pass
