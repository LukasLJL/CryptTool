//
// Created by GROSA5 on 2/7/2021.
//

#include <stdlib.h>
#include "crypt-translate.h"

int getOffsetSeed(const char * key) {
    return hashKey(key) % 255;
}

unsigned char translateChar(unsigned char character, int seed){
    character = character + seed;
    return character;
}

void *translate(void * binData, char *key, size_t len) {


    return NULL;
}