SRC=src/*.c
BIN=bin
EXEC=cfuck
CCOMPILER=gcc
CFLAGS=-Wall -Werror -o $(BIN)/$(EXEC) $(SRC)

compile:
	mkdir -p $(BIN)
	$(CCOMPILER) $(CFLAGS)
	./$(BIN)/$(EXEC)

