import struct
import sys

def parse_tuning(filename):
    with open(filename, 'rb') as f:
        data = f.read()
    
    header_size = struct.unpack('<I', data[13:17])[0]
    body_offset = 25 + header_size
    body = data[body_offset:]
    
    print(f"Body length: {len(body)}")
    
    # Dump the body to a file for analysis
    with open('body.bin', 'wb') as f:
        f.write(body)

if __name__ == '__main__':
    parse_tuning(sys.argv[1])
