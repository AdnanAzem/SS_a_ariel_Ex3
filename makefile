CC=gcc
AR=ar
FLAGS= -Wall -g 
OBJECTS_MAIN=main.o

all: Program

Program: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o Program $(OBJECTS_MAIN) 

main.o: main.c  string_func.h
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o *.a *.so Program