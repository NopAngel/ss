#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/remote.h"

void set_remote(const char *url) {
    FILE *f = fopen(".ss/remote.txt", "w");
    if (!f) {
        perror("Failed to set remote");
        return;
    }
    fprintf(f, "%s\n", url);
    fclose(f);
    printf("Remote set to: %s\n", url);
}

