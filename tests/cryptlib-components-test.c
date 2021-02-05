//
// Created by GROSA5 on 2/4/2021.
//

#include <stdio.h>
#include "../munit/munit.h"
#include "../cryptlib/cript-permutation.h"

MunitResult canGenerateOffsetFromKey(const MunitParameter *params, void *user_data) {
    int *offset = getSetForOffsetFromKey(munit_rand_int_range(9999999, 100000000));
    for (int i = 0; i < 4; i++){
        munit_assert_int(offset[i], <, 4);
        munit_assert_int(offset[i], >=, 0);
    }
    return MUNIT_OK;
}
MunitResult canHashKey(const MunitParameter *params, void *user_data) {
    // generate random string key
    char key[20];
    sprintf(key, "%d", munit_rand_int_range(0, INT16_MAX));
    //check if it has 8 digits
    munit_assert_int(9999999, <, hashKey(key));
    munit_assert_int(100000000, >, hashKey(key));
    return MUNIT_OK;
}

MunitResult canGenerateOffsetMap(const MunitParameter *params, void *user_data) {
    // generate random string key
    char key[20];
    sprintf(key, "%d", munit_rand_int_range(0, INT16_MAX));

    // check if all values from 0 to 15 occur exactly once (through checksum)
    int **offsetMap = getOffsetMap(key);
    int checksum = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            checksum += offsetMap[i][j];
        }
    }
    munit_assert_int(120, ==, checksum);
    return MUNIT_OK;
}

MunitTest tests[] = {
        {
                "/can_gen_offset",
                canGenerateOffsetFromKey,
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