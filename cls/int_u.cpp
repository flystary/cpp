#include <cstring>

#include "int_u.h"


void uint64_to_bytes(uint64_t i, char* bytes) {
    memset(bytes, '\0', 8);
    bytes[7] = 0xff & i;
    bytes[6] = 0xff & i >> 8;
    bytes[5] = 0xff & i >> 16;
    bytes[4] = 0xff & i >> 24;
    bytes[3] = 0xff & i >> 32;
    bytes[2] = 0xff & i >> 40;
    bytes[1] = 0xff & i >> 48;
    bytes[0] = 0xff & i >> 56;
}

uint64_t bytes_to_uint64(const char* bytes) {
    uint64_t i = 0;

    for (int index = 0; index < 8; index++) {
        uint64_t temp = (unsigned char)bytes[index];
        i += (temp << ((7 - index) * 8));
    }
    return i;
}

