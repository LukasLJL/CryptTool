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

int *getOffsetMap(const char *key) {
    int *map = malloc(sizeof(int) * OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN);

    // catch error if memoryAllocationFailed
    catchMemoryAllocationFailure(map);

    // default initialize array
    for (int defaultIndex = 0; defaultIndex < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; defaultIndex++) {
        *(map + defaultIndex) = defaultIndex;
    }

    int *offset = getUnitOfOffset(key);
    for (int rowIndex = 0; rowIndex < OFFSET_ARRAY_LEN; rowIndex++) {
        performOffsetRow(map + rowIndex * OFFSET_ARRAY_LEN, offset[rowIndex]);
        performOffsetColumn(map, offset[rowIndex], rowIndex);
    }

    return map;
}

void performOffsetColumn(int *matrixPtr, int permutationLen, int colPos) {
    // create copy of column
    int colCopy[OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN];
    for (int index = 0; index < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; index++) {
        colCopy[index] = matrixPtr[index];
    }

    // translate permutation
    for (int colIndex = 0; colIndex < OFFSET_ARRAY_LEN; colIndex++) {
        int newIndex = ((colIndex + permutationLen) % OFFSET_ARRAY_LEN) * OFFSET_ARRAY_LEN + colPos;
        matrixPtr[newIndex] = colCopy[colIndex * OFFSET_ARRAY_LEN + colPos];
    }
}

void performOffsetRow(int *rowPtr, int permutationLen) {
    // create copy of row
    int rowCopy[OFFSET_ARRAY_LEN];
    for (int rowIndex = 0; rowIndex < OFFSET_ARRAY_LEN; rowIndex++) {
        rowCopy[rowIndex] = rowPtr[rowIndex];
    }

    // translate permutation
    for (int rowIndex = 0; rowIndex < OFFSET_ARRAY_LEN; rowIndex++) {
        int newIndex = (rowIndex + permutationLen) % OFFSET_ARRAY_LEN;
        rowPtr[newIndex] = rowCopy[rowIndex];
    }
}

int *getUnitOfOffset(const char *key) {
    int keyHash = hashKey(key);

    // initialize new array in heap
    int *offsetArray = malloc(OFFSET_ARRAY_LEN * sizeof(int));
    catchMemoryAllocationFailure(offsetArray);

    // set values for array between 0 and OFFSET_ARRAY_LEN
    for (int offsetIndex = 0; offsetIndex < OFFSET_ARRAY_LEN; offsetIndex++) {
        offsetArray[offsetIndex] = abs((keyHash * (offsetIndex + OFFSET_SEED)) % OFFSET_ARRAY_LEN);
    }

    return offsetArray;
}