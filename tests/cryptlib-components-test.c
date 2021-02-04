//
// Created by GROSA5 on 2/4/2021.
//

#include "../munit/munit.h"
#include "../cryptlib/criptlib.h"

MunitResult canCheckIfDivisibleByThreeOrFive(const MunitParameter *params, void *user_data){
    munit_assert_true(getOne());
    return MUNIT_OK;
}

MunitTest tests[] = {
        {
                "/works",
                canCheckIfDivisibleByThreeOrFive,
                      NULL,
                            NULL,
                                  MUNIT_TEST_OPTION_NONE,
                                                          NULL
        },
        { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
        "/crypt-lib",
        tests,
        NULL,
        1,
        MUNIT_SUITE_OPTION_NONE
};

int main(int argc, const char* argv[]){
    munit_suite_main(&suite, NULL, argc, (char *const *) argv);
}