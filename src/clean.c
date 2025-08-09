#include <stdio.h>
#include <stdlib.h>
#include "../include/clean.h"

void clean_staging(void) {
    system("rm -rf .ss/staging/*");
    printf("Staging area cleaned.\n");
}

