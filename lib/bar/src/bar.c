#include <stdio.h>
#include "bar.h"

void func_bar(void)
{
    printf("%s\n", __func__);
}
