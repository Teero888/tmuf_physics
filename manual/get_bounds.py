import struct
import sys

with open(sys.argv[1], 'rb') as f:
    data = f.read()

idx = data.find(struct.pack('<I', 0x0900F004))
if idx == -1:
    print("Chunk not found!")
    sys.exit(1)

# skip chunk ID (4) + meshId (4)
bbox_data = data[idx+8:idx+32]
minx, miny, minz, maxx, maxy, maxz = struct.unpack('<6f', bbox_data)
print(f"Min: {minx:.2f}, {miny:.2f}, {minz:.2f}")
print(f"Max: {maxx:.2f}, {maxy:.2f}, {maxz:.2f}")
