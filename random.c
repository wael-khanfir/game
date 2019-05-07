#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int nombre(void)
{
    srand(time(NULL));

    return 1+rand()%4;
}
