#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/checkout.h"

void checkout_commit(const char *commit_id) {
    char path[256];
    snprintf(path, sizeof(path), ".ss/commits/%s", commit_id);

    char cmd[512];
    snprintf(cmd, sizeof(cmd), "cp -r %s/* .", path);
    system(cmd);

    printf("Checked out commit: %s\n", commit_id);
}

