//
// Created by GROSA5 on 2/7/2021.
//

#include <stdlib.h>

#define MAX_HASH_SIZE 100000000
#define HASH_SEED 82638153

int hashKey(const char *keySting) {
    // convert keyAsInt from String to int
    int keyAsInt = 0;
    int keyIndex = 0;
    while (keySting[keyIndex] != '\0') {
        keyIndex++;
        keyAsInt += 7 * keySting[keyIndex];
    }

    // permute it and ensure a size of 8 digits and positive
    return abs((keyAsInt) ^ (keyAsInt * HASH_SEED) % MAX_HASH_SIZE);
}
