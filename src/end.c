#include <stdlib.h>
#include <stdio.h>

void end_repo(void) {
    system("rm -rf .ss");
    printf("Repository deleted.\n");
}

