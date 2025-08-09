#include <stdlib.h>
#include <stdio.h>

void show_head(void) {
    system("ls .ss/commits | sort | tail -n 1");
}

