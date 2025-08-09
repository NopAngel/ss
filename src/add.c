#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/add.h"

void add_file(const char *filename) {
    FILE *src = fopen(filename, "rb");
    if (!src) {
        printf("File not found: %s\n", filename);
        return;
    }

    char path[256];
    snprintf(path, sizeof(path), ".ss/staging/%s", filename);

    FILE *dest = fopen(path, "wb");
    if (!dest) {
        perror("Failed to stage file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    printf("Staged: %s\n", filename);
}

