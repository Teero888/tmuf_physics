import struct

def test_xor():
    with open("solid_decompressed.bin", "rb") as f:
        data = f.read()
    
    idx = 0x04B77C
    ivXor = 0x00007503B81540EA
    ivXor_bytes = struct.pack("<Q", ivXor)
    
    garbage = data[idx:idx+32]
    fixed = bytearray()
    for i in range(32):
        fixed.append(garbage[i] ^ ivXor_bytes[i % 8])
    
    print("Fixed words:")
    for i in range(8):
        word = struct.unpack("<I", fixed[i*4:i*4+4])[0]
        fval = struct.unpack("<f", fixed[i*4:i*4+4])[0]
        print(f"Word {i}: 0x{word:08X} float: {fval}")

test_xor()
