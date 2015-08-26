#include "c_test.h"

TEST(ShouldFail) {
    assert_eq(1, 1, "1 != 1");
    assert_eq(1, 2, "1 != 2");

    assert_ne(1, 1, "1 == 1");
    assert_ne(1, 2, "1 == 2");

    assert_lt(1, 2, "1 not less than 2");
    assert_lt(1, 1, "1 not less than 1");
    assert_lt(1, 0, "1 not less than 0");

    assert_lte(1, 2, "1 not less than or equal to 2");
    assert_lte(1, 1, "1 not less than or equal to 1");
    assert_lte(1, 0, "1 not less than or equal to 0");

    assert_gt(1, 2, "1 not greater than 2");
    assert_gt(1, 1, "1 not greater than 1");
    assert_gt(1, 0, "1 not greater than 0");

    assert_gte(1, 2, "1 not greater than or equal to 2");
    assert_gte(1, 1, "1 not greater than or equal to 1");
    assert_gte(1, 0, "1 not greater than or equal to 0");

    assert_str_eq("Hello", "Hello", "Hello != Hello");
    assert_str_eq("Hello", "Cat", "Hello != Cat");

    assert_str_ne("Hello", "Hello", "Hello == Hello");
    assert_str_ne("Hello", "Cat", "Hello == Cat");
}

TEST(ShouldPass) {
    assert_eq(1, 1, "1 != 1");

    assert_ne(1, 2, "1 == 2");

    assert_lt(1, 2, "1 not less than 2");

    assert_lte(1, 2, "1 not less than or equal to 2");
    assert_lte(1, 1, "1 not less than or equal to 1");

    assert_gt(1, 0, "1 not greater than 0");

    assert_gte(1, 1, "1 not greater than or equal to 1");
    assert_gte(1, 0, "1 not greater than or equal to 0");

    assert_str_eq("Hello", "Hello", "Hello != Hello");

    assert_str_ne("Hello", "Cat", "Hello == Cat");
}

int main(void) {
    TEST_RUN(ShouldPass);
    TEST_RUN(ShouldFail);
    return 0;
}
