//
// Created by amos on 2/3/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "cript-permutation.h"
#include "cryptlib-io.h"

#define MAX_HASH_SIZE 100000000
#define HASH_SEED 82638153
#define OFFSET_ARRAY_LEN 4
#define OFFSET_SEED 720

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

int* getOffsetMap(const char *key){
    int *map = malloc(sizeof(int) * OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN);

    // catch error if memoryAllocationFailed
    catchMemoryAllocationFailure(map);

    // default initialize array
    for (int defaultIndex = 0; defaultIndex < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; defaultIndex++){
        *(map + defaultIndex) = defaultIndex;
    }

    int *offset = getSetForOffsetFromKey(key);

    return map;
}

int *getSetForOffsetFromKey(const char* key) {
    int keyHash = hashKey(key);

    // initialize new array in heap
    int *offsetArray = malloc(OFFSET_ARRAY_LEN * sizeof(int));
    catchMemoryAllocationFailure(offsetArray);

    // set values for array between 0 and 3
    for (int offsetIndex = 0; offsetIndex < OFFSET_ARRAY_LEN; offsetIndex++){
        offsetArray[offsetIndex] = abs((keyHash * (offsetIndex + OFFSET_SEED)) % 4);
    }

    return offsetArray;
}