#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

int32_t packBitfield(int32_t b0, int32_t b1, int32_t b2) {
    return ((b2 & 1) << 2) | ((b1 & 1) << 1) | (b0 & 1);
}