import struct
with open('../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B', 'rb') as f:
    f.seek(0x60A64) # Offset of 0x0900F004
    data = f.read(100)
words = struct.unpack('<' + 'I'*(len(data)//4), data[:(len(data)//4)*4])
for i in range(16):
    print(f"Word {i}: {words[i]}")
