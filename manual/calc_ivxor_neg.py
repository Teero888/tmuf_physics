import struct

def calc_ivxor():
    # Min.X - Max.X
    val = -64.38720703125
    data = struct.pack("<f", val)
    print(f"Data bytes: {[hex(b) for b in data]}")
    
    ivXor = 0
    for i in range(4):
        lopart = ivXor & 0xFFFFFFFF
        hipart = (ivXor >> 32) & 0xFFFFFFFF
        
        lopart = (data[i] | 0xAA) ^ (((lopart << 13) & 0xFFFFFFFF) | (hipart >> 19))
        hipart = ((ivXor << 13) >> 32) & 0xFFFFFFFF
        
        ivXor = (hipart << 32) | lopart

    print(f"Calculated ivXor: 0x{ivXor:016X}")
    return ivXor

calc_ivxor()
