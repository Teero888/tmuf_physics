import lzo
import struct

def parse(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = 0x04B6A8
    compressed_size = 1606
    uncompressed_size = 1536

    compressed_data = data[idx:idx+compressed_size]
    
    try:
        decompressed_data = lzo.decompress(compressed_data, False, uncompressed_size)
        print(f"Decompressed {len(decompressed_data)} bytes successfully!")
        
        # Verify first few floats
        for i in range(5):
            val = struct.unpack("<f", decompressed_data[i*4:i*4+4])[0]
            print(f"Float {i}: {val}")
    except Exception as e:
        print(f"LZO Decompression failed: {e}")

parse("solid_decompressed.bin")
