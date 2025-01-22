SRC=src/*.c
BIN=bin
EXEC=cfuck
CCOMPILER=gcc
CFLAGS=-o $(BIN)/$(EXEC) $(SRC)

compile:
	mkdir -p $(BIN)
	$(CCOMPILER) $(CFLAGS)
	./$(BIN)/$(EXEC)

