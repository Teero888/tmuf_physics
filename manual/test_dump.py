import struct
with open('0900f004.bin', 'rb') as f:
    data = f.read()

words = struct.unpack('<' + 'I'*(len(data)//4), data[:(len(data)//4)*4])
for i in range(16):
    print(f"Word {i}: {words[i]} (0x{words[i]:08x})")
