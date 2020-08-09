# The compiler flags used when compiling
CFLAGS=-Wall -Wno-comment

OUTPUT_FILES=main.o 
HEADER_FILES=Data.h Node.h List.h AdjacencyList.h util.h

test: $(OUTPUT_FILES)
	gcc $(CFLAGS) -o test $(OUTPUT_FILES)

main.o: main.c $(HEADER_FILES)
	gcc $(CFLAGS) -c main.c


# This .PHONY command declares the "clean" and "run" rules as a phony one, 
# i.e., it means that the rules will run instructions but it wont create a
# file called "clean" or "run" like a normal rule would (e.g., the main.o 
# rule results in a file called main.o being created).
.PHONY: run
run:
	./test

.PHONY: clean
clean:
	rm *.o
	rm test