//
// Created by GROSA5 on 2/4/2021.
//

#include <stdio.h>
#include "../munit/munit.h"
#include "../cryptlib/cript-permutation.h"

void resetArray(int currentArray[], const int defaultArray[], int len){
    for (int index = 0; index < len; index++){
        currentArray[index] = defaultArray[index];
    }
}
void genKey(char * string){
    sprintf(string, "%d", munit_rand_int_range(0, INT16_MAX));
}

MunitResult canGenerateUnitOffsetValues(const MunitParameter *params, void *user_data) {
    char key[20];
    genKey(key);
    int *offset = getUnitOfOffset(key);
    for (int i = 0; i < 4; i++){
        munit_assert_int(offset[i], <, 4);
        munit_assert_int(offset[i], >=, 0);
    }
    return MUNIT_OK;
}
MunitResult canHashKey(const MunitParameter *params, void *user_data) {
    // generate random string key
    char key[20];
    genKey(key);
    //check if it has 8 digits
    munit_assert_int(9999999, <, hashKey(key));
    munit_assert_int(100000000, >, hashKey(key));
    return MUNIT_OK;
}
MunitResult canGenerateOffsetMap(const MunitParameter *params, void *user_data) {
    // generate random string key
    char key[20];
    genKey(key);

    // check if all values from 0 to 15 occur exactly once (through checksum)
    int *offsetMap = getOffsetMap(key);
    int checksum = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            checksum += offsetMap[4*i + j];
        }
    }
    munit_assert_int(120, ==, checksum);
    return MUNIT_OK;
}
MunitResult canPermuteRow(const MunitParameter *params, void *user_data) {
    int testRow[] = {0, 1, 2, 3};
    int defaultRow[] = {0, 1, 2, 3};

    int expectedAfterShiftZero[] = {0, 1, 2, 3};
    int expectedAfterShiftOne[] = {3, 0, 1, 2};
    int expectedAfterShiftTwo[] = {2, 3, 0, 1};
    int expectedAfterShiftThree[] = {1, 2, 3, 0};

    performOffsetRow(testRow, 0);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftZero);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 1);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftOne);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 2);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftTwo);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 3);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftThree);
    resetArray(testRow, defaultRow, 4);

    return MUNIT_OK;
}
MunitResult canPermuteColumn(const MunitParameter *params, void *user_data) {
    // the 9s are intended to represent unchanged values

    int testColumn[] =              {0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9, 9};
    int testColTwo[] =              {9, 0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9};
    int defaultColumn[] =           {0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9, 9};
    int defaultColTwo[] =           {9, 0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9};

    int expectedAfterShiftZero[] =  {0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9, 9};
    int expectedAfterShiftOne[] =   {3, 9, 9, 9, 0, 9, 9, 9, 1, 9, 9, 9, 2, 9, 9, 9};
    int expectedAfterShiftTwo[] =   {2, 9, 9, 9, 3, 9, 9, 9, 0, 9, 9, 9, 1, 9, 9, 9};
    int expectedAfterShiftThree[] = {1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9, 9, 0, 9, 9, 9};
    int expectedAfterColTwo[] =     {9, 1, 9, 9, 9, 2, 9, 9, 9, 3, 9, 9, 9, 0, 9, 9};

    performOffsetColumn(testColumn, 0, 0);
    munit_assert_memory_equal(sizeof defaultColumn, testColumn, expectedAfterShiftZero);
    resetArray(testColumn, defaultColumn, 16);

    performOffsetColumn(testColumn, 1, 0);
    munit_assert_memory_equal(sizeof defaultColumn, testColumn, expectedAfterShiftOne);
    resetArray(testColumn, defaultColumn, 16);

    performOffsetColumn(testColumn, 2, 0);
    munit_assert_memory_equal(sizeof defaultColumn, testColumn, expectedAfterShiftTwo);
    resetArray(testColumn, defaultColumn, 16);

    performOffsetColumn(testColumn, 3, 0);
    munit_assert_memory_equal(sizeof defaultColumn, testColumn, expectedAfterShiftThree);
    resetArray(testColumn, defaultColumn, 16);

    performOffsetColumn(testColTwo, 3, 1);
    munit_assert_memory_equal(sizeof defaultColTwo, testColTwo, expectedAfterColTwo);
    resetArray(testColTwo, defaultColTwo, 16);

    return MUNIT_OK;
}
MunitResult canPermute(const MunitParameter *params, void *user_data) {
    int offsetMap[] = {15, 16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    char testArray[] =      {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    char expectedArray[] =   {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'A', 'B'};

    void* permutedArray = permuteFromMap(testArray, offsetMap, sizeof testArray);
    munit_assert_memory_equal(sizeof testArray, permutedArray, expectedArray);

    return MUNIT_OK;
}
MunitResult canUnpermute(const MunitParameter *params, void *user_data) {
    int offsetMap[] = {15, 16, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

    char testArray[] =          {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'A', 'B'};
    char expectedArray[] =      {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

    void* unpermutedArray = unpermuteFromMap(testArray, offsetMap, sizeof testArray);
    munit_assert_memory_equal(sizeof testArray, unpermutedArray, expectedArray);

    return MUNIT_OK;
}
MunitResult canCreateCopy(const MunitParameter *params, void *user_data) {
    char testArray[] =    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    char expectedArray[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 0, 0, 0, 0, 0, 0, 0};

    void *newArray = createCopy(testArray, sizeof testArray);
    munit_assert_memory_equal(sizeof expectedArray, newArray, expectedArray);

    return MUNIT_OK;
}

MunitTest tests[] = {
        {
                "/can_gen_unit_offset_val",
                canGenerateUnitOffsetValues,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_gen_hash",
                canHashKey,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_gen_offset_map",
                canGenerateOffsetMap,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_permute_row",
                canPermuteRow,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_permute_column",
                canPermuteColumn,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_create_copy",
                canCreateCopy,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_permute",
                canPermute,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {
                "/can_unpermute",
                canUnpermute,
                NULL,
                NULL,
                MUNIT_TEST_OPTION_NONE,
                NULL
        },
        {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
        "/crypt-lib",
        tests,
        NULL,
        1,
        MUNIT_SUITE_OPTION_NONE
};

int main(int argc, const char *argv[]) {
    munit_suite_main(&suite, NULL, argc, (char *const *) argv);
}