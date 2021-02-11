//
// Created by GROSA5 on 2/7/2021.
//

#include <stdio.h>
#include "crypt-translate.h"
#include "crypt-components.h"

int getOffsetSeed(const char *key) {
    return hashKey(key) % 254;
}

void translateChar(void *byte, int seed) {
    unsigned char *ptrByteValue = ((unsigned char *) byte);
    *ptrByteValue = *ptrByteValue + seed;
}

void *translate(void *binData, char *key, size_t len) {
    int offset = getOffsetSeed(key);
    return translateAll(binData, getOffsetSeed(key), len);
}

void *untranslate(void *binData, char *key, size_t len) {
    int offset = getOffsetSeed(key) * (-1);
    return translateAll(binData, getOffsetSeed(key) * (-1), len);
}

void *translateAll(void *binData, int offset, size_t len) {
    char *copy = createCopy(binData, len);
    for (int index = 0; index < len; index++) {
        translateChar(copy + index, offset);
    }
    return copy;
}