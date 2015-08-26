#ifndef _LITTLE_LANG_TEST_HELPER_H
#define _LITTLE_LANG_TEST_HELPER_H

#include <stdio.h>

#define XSTR(s) STR(s)
#define STR(s) #s
#define GLUE(a,b) a ## b
#define GLUE3(a,b,c) a ## b ## c

#define PASS(func)                                      \
    do {                                                \
        if (__current_test_passed)                      \
            puts(XSTR(GLUE(test_, func)) " : PASS");    \
        else                                            \
            puts(XSTR(GLUE(test_, func)) " : FAIL");    \
    } while (0)

#define TEST(func) void GLUE(test_, func) (void)

#define TEST_RUN(func)                          \
    do {                                        \
        __reset_test_passed;                    \
        GLUE(test_, func)();                    \
        PASS(func);                             \
    } while (0)

#define TEST_FAIL_MSG(msg)                                              \
    printf("assertion failed in %s at L:%d\n\t%s\n", __func__, __LINE__, msg)

static int __current_test_passed = 1;

static void __fail(void) {
    __current_test_passed = 0;
}

static void __pass(void) {
    if (!__current_test_passed)
        return;
    __current_test_passed = 1;
}

#define __reset_test_passed __current_test_passed = 1;

#define __check_predicate(b, msg)               \
    do {                                        \
        if (b) {                                \
            __pass();                           \
            break;                              \
        }                                       \
        else {                                  \
            __fail();                           \
            TEST_FAIL_MSG(msg);                 \
        }                                       \
    } while (0)

#define __assert(predicate, msg) do { __check_predicate(predicate, msg); } while (0)

#define assert_eq(a, b, msg) __assert(a == b, msg)
#define assert_ne(a, b, msg) __assert(a != b, msg)
#define assert_lt(a, b, msg) __assert(a < b, msg)
#define assert_lte(a, b, msg) __assert(a <= b, msg)
#define assert_gt(a, b, msg) __assert(a > b, msg)
#define assert_gte(a, b, msg) __assert(a >= b, msg)

#define assert_str_eq(a, b, msg) __assert(0 == strcmp(a, b), msg)
#define assert_str_ne(a, b, msg) __assert(0 != strcmp(a, b), msg)


#endif
