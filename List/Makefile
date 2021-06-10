# CC - compiler
CC=gcc
# OBJ - compiled source files that should be linked
OBJ=Data.o List.o Node.o util.o
# COPT - compiler flags
COPT=-Wall -Wpedantic -g 
# BIN - binary
BIN_MAIN=linkedlist

# Running "make" with no argument will make the first target in the file
all: $(BIN_MAIN)

# Rules of the form
#     target_to_be_made : dependencies_to_be_up-to-date_first
#     <tab>commands_to_make_target
# (Note that spaces will not work.)

$(BIN_MAIN): main.c $(OBJ)
	$(CC) -o $(BIN_MAIN) main.c $(OBJ) $(COPT)


# Wildcard rule to make any .o file,
# given a .c and .h file with the same leading filename component
%.o: %.c %.h
	$(CC) -c $< $(COPT) -g

format:
	clang-format -i *.c *.h

.PHONY: clean
clean:
	rm -rf $(BIN_MAIN) $(BIN_MAIN).exe *.o

test:
	./$(BIN_MAIN)
