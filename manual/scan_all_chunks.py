import sys
import struct

def scan_chunks(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    # Find the LZO compressed block if it exists
    # Or just search the raw data if it's already decompressed?
    # No, solid_decompressed.bin is the decompressed part!
    pass

if __name__ == "__main__":
    filepath = sys.argv[1]
    with open(filepath, "rb") as f:
        data = f.read()
    
    # We look for typical Trackmania chunk IDs, which start with 0x0900 (CPlug classes)
    print(f"Scanning {filepath} for chunk IDs...")
    for i in range(len(data) - 4):
        val = struct.unpack("<I", data[i:i+4])[0]
        class_id = val & 0xFFFFF000
        if class_id in [0x09005000, 0x0900C000, 0x0900D000, 0x0900F000, 0x09015000, 0x09056000, 0x09057000]:
            print(f"Offset 0x{i:06X}: Chunk ID 0x{val:08X}")
