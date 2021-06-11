# CC - compiler
CC=gcc
# OBJ - compiled source files that should be linked
OBJ=Data.o HashTable.o Slot.o util.o
# COPT - compiler flags
COPT=-Wall -Wno-comment -g 
# BIN - binary
BIN_MAIN=hashtable

# # Running "make" with no argument will make the first target in the file
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

test1:
	./$(BIN_MAIN) < tests/test-1-in.txt
test2:
	./$(BIN_MAIN) < tests/test-2-in.txt
test3:
	./$(BIN_MAIN) < tests/test-3-in.txt
test4:
	./$(BIN_MAIN) < tests/test-4-in.txt

test: $(BIN_MAIN) test1 test2 test3 test4 clean

.PHONY: clean
clean:
	rm -rf *.o $(BIN_MAIN) $(BIN_MAIN).exe *.dSYM
