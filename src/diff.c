#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/diff.h"

void show_diff(const char *filename) {
    char staged_path[256];
    snprintf(staged_path, sizeof(staged_path), ".ss/staging/%s", filename);

    char committed_path[256];
    snprintf(committed_path, sizeof(committed_path), ".ss/commits/%s", filename); // Simplified

    FILE *f1 = fopen(staged_path, "r");
    FILE *f2 = fopen(committed_path, "r");

    if (!f1 || !f2) {
        printf("File not found in staging or commits.\n");
        return;
    }

    char line1[256], line2[256];
    int line_num = 1;
    while (fgets(line1, sizeof(line1), f1) && fgets(line2, sizeof(line2), f2)) {
        if (strcmp(line1, line2) != 0) {
            printf("Line %d differs:\nStaging: %sCommitted: %s\n", line_num, line1, line2);
        }
        line_num++;
    }

    fclose(f1);
    fclose(f2);
}

