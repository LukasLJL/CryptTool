//
// Created by GROSA5 on 2/7/2021.
//

#include <stdlib.h>

#define MAX_HASH_SIZE 100000000
#define HASH_SEED 82638153
#define OFFSET_ARRAY_LEN 4

int hashKey(const char *keySting) {
    // convert keyAsInt from String to int
    int keyAsInt = 0;
    int keyIndex = 0;
    while (keySting[keyIndex] != '\0' && keyIndex < 28) {
        keyIndex++;
        keyAsInt += 7 * keySting[keyIndex];
    }

    // permute it and ensure a size of 8 digits and positive
    int hash = abs((keyAsInt) ^ (keyAsInt * HASH_SEED) % MAX_HASH_SIZE);

    //make sure it can't be divided by HASH_SEED
    if (hash % HASH_SEED == 0){
        return hash + 1;
    }
    return hash;
}

void* createCopy(void *ptrData, size_t len){
    int differenceToBlock = len  + (OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN - ((len % OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN)) % OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN);

    // copy existing data
    void *copy = malloc(len + differenceToBlock);
    for (int index = 0; index < len; index++){
        *(((char *)copy) + index) = *(((char *)ptrData) + index);
    }

    // initialize remaining data to 0
    for (int index = 0; index < differenceToBlock; index++){
        *(((char *)copy) + index + (int) len) = 0;
    }

    return copy;
}