#include <stdio.h>
#include "Classic/CClassicArchive.hpp"
#include "Classic/CClassicBuffer.hpp"
#include "Mw/CMwNod.hpp"

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file.gbx>\n", argv[0]);
        return 1;
    }
    
    CClassicArchive* archive = CClassicArchive::LoadFromGbx(argv[1]);
    if (!archive || !archive->m_buffer) {
        printf("Failed to load GBX\n");
        return 1;
    }
    
    while (archive->m_buffer->GetCursor() < 1000000) {
        uint32_t chunkId;
        if (archive->m_buffer->Read(&chunkId, 4) != 4) break;
        if (chunkId == 0xFACADE01) break;
        
        uint32_t skip;
        if (archive->m_buffer->Read(&skip, 4) != 4) break;
        
        printf("Chunk: 0x%08X (skip %d bytes)\n", chunkId, skip);
        if (skip > 100000) break;
        
        uint32_t before = archive->m_buffer->GetCursor();
        archive->m_buffer->Seek(before + skip);
    }
    
    return 0;
}
