// src/init.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "../include/main.h"

void init_repo(void) {
    const char *dir_name = ".ss";

    struct stat st;
    if (stat(dir_name, &st) == 0) {
        printf("Repository already exists.\n");
        return;
    }

    if (mkdir(dir_name, 0755) != 0) {
        perror("Failed to create repository");
        exit(EXIT_FAILURE);
    }

    char config_path[256];
    snprintf(config_path, sizeof(config_path), "%s/config", dir_name);
    FILE *config = fopen(config_path, "w");
    if (config == NULL) {
        perror("Failed to create config file");
        exit(EXIT_FAILURE);
    }

    fprintf(config, "# ss configuration\n");
    fclose(config);

    printf("Initialized empty ss repository in .ss/\n");
}

