SRC=src/*.c
BIN=bin/cfuck
CCOMPILER=gcc
CFLAGS=-o $(BIN) $(SRC)

compile:
	$(CCOMPILER) $(CFLAGS)
	./$(BIN)

