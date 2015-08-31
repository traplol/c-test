# c-test

c-test is a small testing framework for the C programming language. It consists of mostly macros and is a single
file that can be dropped into a project and be used to write module tests.

# usage
Create a new .c file and ```#include``` the module(s) to test along with ```#include "c_test.h"```.

By default, output messages should be colored but you may disable this by defining ```C_TEST_NO_COLORS``` at some point before including ```c_test.h```

### Declare a test
```
TEST(TheTestsName) {
  /* Use the c-test asserts here! */
  assert_str_ne("Hello", "World", "Hello shouldn't equal World");
}
```

### Running a test
Just call ```TEST_RUN(TheTestsName);``` somewhere that gets executed, usually in ```main``` for test modules.

### Implemented Assertions
```assert_p(p, msg)``` Asserts the predicate evaluates to true.

```assert_eq(e, a, msg)``` Asserts numeric e == a.

```assert_ne(e, a, msg)``` Asserts numeric e != a.

```assert_lt(e, a, msg)``` Asserts numeric e < a.

```assert_lte(e, a, msg)``` Asserts numeric e <= a.

```assert_gt(e, a, msg)``` Asserts numeric e > a.

```assert_gte(e, a, msg)``` Asserts numeric e >= a.

```assert_str_eq(e, a, msg)``` Asserts string equality.

```assert_str_ne(e, a, msg)``` Asserts string inequality.
