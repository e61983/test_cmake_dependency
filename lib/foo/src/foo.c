#include <stdio.h>
#include "foo.h"

void func_foo(void)
{
    printf("%s\n", __func__);
}
