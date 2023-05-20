#include "strings.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Gmain.h"

int main()
{
    if (program() == 0)
        printf("\n");
    else
        return -1;
    return 0;
}