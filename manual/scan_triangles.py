import struct

def scan(filepath):
    with open(filepath, "rb") as f:
        data = f.read()

    idx = data.find(struct.pack("<I", 0x0900F004))
    idx += 4 + 4 + 24 + 4 + 4 + 4
    
    seq_len = 0
    start_offset = 0
    
    for i in range(idx, len(data) - 4, 4): # try ints
        val = struct.unpack("<I", data[i:i+4])[0]
        if val < 1536:
            if seq_len == 0:
                start_offset = i
            seq_len += 1
            if seq_len >= 15:
                print(f"Found long sequence of small ints at offset {start_offset} (rel: {start_offset - idx})")
                
                ints = struct.unpack("<8I", data[start_offset:start_offset+32])
                print("Ints:", ints)
                break
        else:
            seq_len = 0

scan("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B")
