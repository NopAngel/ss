#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include "../include/commit.h"

void commit_changes(const char *message) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", t);

    char commit_dir[256];
    snprintf(commit_dir, sizeof(commit_dir), ".ss/commits/%s", timestamp);

    if (mkdir(commit_dir, 0755) != 0) {
        perror("Failed to create commit directory");
        return;
    }

    system("cp -r .ss/staging/* .ss/commits/"); // Simplified copy

    char log_path[256];
    snprintf(log_path, sizeof(log_path), ".ss/commits/%s/message.txt", timestamp);
    FILE *log = fopen(log_path, "w");
    if (!log) {
        perror("Failed to write commit message");
        return;
    }

    fprintf(log, "%s\n", message);
    fclose(log);

    printf("Committed: %s\n", timestamp);
}

