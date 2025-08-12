//
//   main.ss - main file (IMPORTANT) 
//
//
// this is a main file (/main.c), important file.
//
//  license:Apache-2.0    |      author: NopAngel
//


#include <stdio.h>
#include <string.h>
#include "include/main.h"
#include "include/add.h"
#include "include/commit.h"
#include "include/diff.h"
#include "include/clean.h"
#include "include/checkout.h"
#include "include/status.h"
#include "include/remote.h"
#include "include/head.h"
#include "include/end.h"
#include "include/colors.h"
#include "include/help.h"



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ss <command> [options]\n");
        return 1;
    }

    if (strcmp(argv[1], "init") == 0) {
        //
        // inited func
        //
        // ---------------
        // created folder ".ss", root for ss :D
        //
        init_repo();
    } else if (strcmp(argv[1], "add") == 0 && argc == 3) {
        add_file(argv[2]);
    } else if (strcmp(argv[1], "commit") == 0 && argc == 4 && strcmp(argv[2], "-m") == 0) {
        commit_changes(argv[3]);
    } else if (strcmp(argv[1], "diff") == 0 && argc == 3) {
        show_diff(argv[2]);
    } else if (strcmp(argv[1], "clean") == 0) {
        clean_staging();
    } else if (strcmp(argv[1], "checkout") == 0 && argc == 3) {
        checkout_commit(argv[2]);
    } else if (strcmp(argv[1], "status") == 0) {
        show_status();
    } else if (strcmp(argv[1], "remote") == 0 && argc == 3) {
        set_remote(argv[2]);
    } else if (strcmp(argv[1], "head") == 0) {
        show_head();
    } else if (strcmp(argv[1], "end") == 0) {
        end_repo();
    } else {
        printf("Unknown or invalid command.\n");
    }

    return 0;
}

