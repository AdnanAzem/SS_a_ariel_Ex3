CC=gcc
AR=ar
FLAGS= -Wall -g 
OBJECTS_MAIN=main.o

all: stringProg

stringProg: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) 

 $(OBJECTS_MAIN): main.c
	$(CC) $(FLAGS) -c main.c 


.PHONY: clean all

clean:
	rm -f *.o *.a *.so stringProg

	
