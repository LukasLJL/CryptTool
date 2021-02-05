//
// Created by GROSA5 on 2/4/2021.
//

#include <stdio.h>
#include "../munit/munit.h"
#include "../cryptlib/cript-permutation.h"

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

void resetArray(int currentArray[], const int defaultArray[], int len){
    for (int index = 0; index < len; index++){
        currentArray[index] = defaultArray[index];
    }
}

MunitResult canPermuteRow(const MunitParameter *params, void *user_data) {
    // generate random string key
    int testRow[] = {0, 1, 2, 3};
    int defaultRow[] = {0, 1, 2, 3};

    int expectedAfterShiftZero[] = {0, 1, 2, 3};
    int expectedAfterShiftOne[] = {3, 0, 1, 2};
    int expectedAfterShiftTwo[] = {2, 3, 0, 1};
    int expectedAfterShiftThree[] = {1, 2, 3, 0};

    performOffsetRow(testRow, 0, 4);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftZero);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 1, 4);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftOne);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 2, 4);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftTwo);
    resetArray(testRow, defaultRow, 4);

    performOffsetRow(testRow, 3, 4);
    munit_assert_memory_equal(sizeof defaultRow, testRow, expectedAfterShiftThree);
    resetArray(testRow, defaultRow, 4);

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
                "/can_gen_offset_map",
                canPermuteRow,
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