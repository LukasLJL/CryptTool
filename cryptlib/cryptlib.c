//
// Created by amos on 2/3/21.
//

/*
 * TODO:
 *  - Permutation function:
 *      - matrix to matrix
 *  - Translation function
 */

#include <stdlib.h>

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

int *getSetForOffsetFromKey(int key) {
    // initialize new array in heap
    int *offsetArray = malloc(OFFSET_ARRAY_LEN * sizeof(int));

    // set values for array between 0 and 3
    for (int offsetIndex = 0; offsetIndex < OFFSET_ARRAY_LEN; offsetIndex++){
        offsetArray[offsetIndex] = abs((key * (offsetIndex + OFFSET_SEED)) % 4);
    }

    return offsetArray;
}