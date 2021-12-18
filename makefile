/*
CC=gcc
AR=ar
FLAGS= -Wall -g 
OBJECTS_MAIN=main.o

all: stringProg

stringProg: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) 

main.o: main.c
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg
	*/
	
.PHONY = all clean
FLAGS = -Wall -Werror -g
CC = gcc
all: stringProg
stringProg: Hw3.c
	$(CC) $(FLAGS) Hw3.c -o stringProg
clean:
	rm -f *.o *.a stringProg

	
