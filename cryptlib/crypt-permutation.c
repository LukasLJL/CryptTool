//
// Created by amos on 2/3/21.
//

#include <stdlib.h>
#include <stdio.h>
#include "crypt-permutation.h"
#include "cryptlib-io.h"
#include "crypt-components.h"

#define OFFSET_ARRAY_LEN 4
#define OFFSET_SEED 722

void *permute(void *ptrData, char *key, size_t len){
    int *offsetMap = getOffsetMap(key);
    return permuteFromMap(ptrData, offsetMap, len);
}
void *unpermute(void *ptrData, char *key, size_t len){
    int *offsetMap = getOffsetMap(key);
    return unpermuteFromMap(ptrData, offsetMap, len);
}

void *permuteFromMap(void *ptrData, const int *offSetMap, size_t len){
    char *permutedArray = createCopy(ptrData, len);
    char const *safeUnpermutedArray = createCopy(ptrData, len);

    for (int index = 0; index < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; index++){
        *(permutedArray + offSetMap[index] - 1) = *(safeUnpermutedArray + index);
    }

    return permutedArray;
}
void *unpermuteFromMap(void *ptrData, const int *offSetMap, size_t len){
    char const *permutedArray = createCopy(ptrData, len);
    char *unpermutedArray = createCopy(ptrData, len);

    for (int index = 0; index < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; index++){
        *(unpermutedArray + index) = *(permutedArray + offSetMap[index] - 1);
    }

    return unpermutedArray;
}

int *getOffsetMap(const char *key) {
    int *map = malloc(sizeof(int) * OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN);

    // catch error if memoryAllocationFailed
    catchMemoryAllocationFailure(map);

    // default initialize array
    for (int defaultIndex = 0; defaultIndex < OFFSET_ARRAY_LEN * OFFSET_ARRAY_LEN; defaultIndex++) {
        *(map + defaultIndex) = defaultIndex + 1;
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

    // translateAll permutation
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

    // translateAll permutation
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
        int offset = abs((keyHash + offsetIndex)* OFFSET_SEED % OFFSET_ARRAY_LEN);
        offsetArray[offsetIndex] = abs((keyHash * (offsetIndex + OFFSET_SEED)) % OFFSET_ARRAY_LEN);
    }

    return offsetArray;
}