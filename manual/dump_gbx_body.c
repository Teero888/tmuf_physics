#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <lzo/lzo1x.h>

int main(int argc, char** argv) {
    if (argc < 2) return 1;
    FILE* f = fopen(argv[1], "rb");
    if (!f) return 1;

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    uint8_t* data = (uint8_t*)malloc(size);
    fread(data, 1, size, f);
    fclose(f);

    if (memcmp(data, "GBX", 3) != 0) {
        printf("Not a GBX file\n");
        return 1;
    }

    uint16_t version = *(uint16_t*)(data + 3);
    uint32_t class_id = *(uint32_t*)(data + 9);
    
    // Header block
    uint32_t header_size = *(uint32_t*)(data + 13);
    uint32_t num_nodes = *(uint32_t*)(data + 17 + header_size);
    uint32_t num_ext_nodes = *(uint32_t*)(data + 21 + header_size);

    uint32_t body_offset = 25 + header_size;
    
    // Body starts here
    uint32_t num_uncompressed = *(uint32_t*)(data + body_offset);
    uint32_t num_compressed = *(uint32_t*)(data + body_offset + 4);

    printf("Class ID: 0x%08X\n", class_id);
    printf("Uncompressed size: %u\n", num_uncompressed);
    printf("Compressed size: %u\n", num_compressed);

    uint8_t* uncompressed = (uint8_t*)malloc(num_uncompressed);
    lzo_uint out_len = num_uncompressed;

    if (lzo_init() != LZO_E_OK) {
        printf("LZO init failed\n");
        return 1;
    }

    int r = lzo1x_decompress_safe(data + body_offset + 8, num_compressed, uncompressed, &out_len, NULL);
    if (r != LZO_E_OK) {
        printf("Decompression failed: %d\n", r);
        return 1;
    }

    FILE* out = fopen("tuning_body.bin", "wb");
    fwrite(uncompressed, 1, out_len, out);
    fclose(out);

    printf("Wrote tuning_body.bin (%lu bytes)\n", (unsigned long)out_len);
    return 0;
}
