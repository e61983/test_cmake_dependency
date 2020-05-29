#include <stdio.h>
#include "bar.h"
#include "foo.h"

void func_bar(void)
{
    func_foo();
    printf("%s\n", __func__);
}
