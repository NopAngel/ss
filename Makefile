	
build:
	gcc main.c src/init.c src/add.c src/commit.c src/diff.c src/clean.c src/checkout.c src/status.c src/remote.c src/head.c src/end.c -Iinclude -o ss

clean:
	rm -f $(OBJ) $(TARGET)

