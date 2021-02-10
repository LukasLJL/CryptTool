//
// Created by GROSA5 on 2/7/2021.
//

#include <stdio.h>
#include "crypt-translate.h"
#include "crypt-components.h"

int getOffsetSeed(const char *key) {
    return hashKey(key) % 255;
}

void translateChar(void *byte, int seed) {
    *((unsigned char *) byte) = *((unsigned char *) byte) + seed;
}

void *translate(void *binData, char *key, size_t len) {
    return translateAll(binData, getOffsetSeed(key), len);
}

void *untranslate(void *binData, char *key, size_t len) {
    return translateAll(binData, getOffsetSeed(key) * (-1), len);
}

void *translateAll(void *binData, int offset, size_t len) {
    char *copy = createCopy(binData, len);
    for (int index = 0; index < len; index++) {
        translateChar(copy + index, offset);
    }
    return copy;
}