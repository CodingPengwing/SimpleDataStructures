
# The compiler flags used when compiling
CFLAGS=-Wall -Wno-comment

OUTPUT_FILES=main.o 
HEADER_FILES=Data.h Node.h List.h util.h

test: $(OUTPUT_FILES)
	gcc $(CFLAGS) -o test $(OUTPUT_FILES)

main.o: main.c $(HEADER_FILES)
	gcc $(CFLAGS) -c main.c


# This .PHONY command declares the "clean" rule as a phony one, i.e., it means
# that the clean rule will run instructions but it wont create a file called
# "clean" like a normal rule would (e.g., the poly_print.o rule results in a file
# called poly_print.o being created).
.PHONY: clean

run:
	./test

clean:
	rm *.o
	rm test