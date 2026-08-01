#include <stdio.h>
#include <stdint.h>
int main() {
    uint32_t firstTriangle[8];
    for (int i = 0; i < 8; i++) {
        printf("Word %d: 0x%08x\n", i, firstTriangle[i]);
    }
    return 0;
}
