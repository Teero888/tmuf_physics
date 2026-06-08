import struct
with open("../steamdata/GameData/Stadium_Extracted/Stadium/Media/Solid/03087AFCAF9BD557046938047A36D3614B", "rb") as f:
    data = f.read()

# search for LZO decompressed body
# It's a GBX file, the actual uncompressed data is inside.
# But we already dumped it via CClassicArchive!
