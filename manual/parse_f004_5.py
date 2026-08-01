import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = 0x04B6A8
    count = 0
    while idx + 4 <= len(data):
        val = struct.unpack("<f", data[idx:idx+4])[0]
        # Trackmania block bounds: -100 to 200 roughly.
        if abs(val) < 0.0001 or (abs(val) > 0.01 and abs(val) < 1000.0):
            count += 1
            idx += 4
        else:
            break

    vertices = count / 3
    print(f"Contiguous floats: {count} ({vertices} vertices)")
    print(f"Ends at offset: 0x{idx:06X}")

parse("solid_decompressed.bin")
