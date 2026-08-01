import struct
import sys

def main():
    if len(sys.argv) < 2:
        return
    with open(sys.argv[1], 'rb') as f:
        data = f.read()

    magic = data[:3]
    version = struct.unpack('<H', data[3:5])[0]
    format_str = data[5:9].decode('ascii')
    
    print(f"Magic: {magic}, Version: {version}, Format: {format_str}")
    
    class_id = struct.unpack('<I', data[9:13])[0]
    print(f"Class ID: 0x{class_id:08X}")
    
    header_size = struct.unpack('<I', data[13:17])[0]
    num_nodes = struct.unpack('<I', data[17 + header_size: 21 + header_size])[0]
    num_ext_nodes = struct.unpack('<I', data[21 + header_size: 25 + header_size])[0]
    
    print(f"Header size: {header_size}")
    print(f"Nodes: {num_nodes}, Ext Nodes: {num_ext_nodes}")
    
    body_offset = 25 + header_size
    
    if format_str[2] == 'U':
        print("Body is uncompressed!")
        cursor = body_offset
        while cursor < len(data):
            if cursor + 4 > len(data): break
            chunk_id = struct.unpack('<I', data[cursor:cursor+4])[0]
            cursor += 4
            
            if chunk_id == 0xFACADE01:
                print("End of chunk list")
                break
                
            if cursor + 4 > len(data): break
            skip = struct.unpack('<I', data[cursor:cursor+4])[0]
            cursor += 4
            
            print(f"Chunk ID: 0x{chunk_id:08X}, Skip: {skip}")
            cursor += skip
            
main()
