CC = gcc
FLAGS = -Iinclude -o
PATH = main.c src/init.c src/add.c src/commit.c src/diff.c src/clean.c src/checkout.c src/status.c src/remote.c src/head.c src/end.c
OBJ = ./build


build:
	$(CC) $(PATH) $(FLAGS) ./build/ss

clean:
	rm -rf $(OBJ)/*

