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

## License
The MIT License (MIT)

Copyright (c) 2015 Max Mickey

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.