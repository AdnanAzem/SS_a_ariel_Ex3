.PHONY = all clean

FLAGS = -Wall -Werror -g
CC = gcc

all: stringProg

stringProg: main.c
	$(CC) $(FLAGS) main.c -o stringProg
	
clean:
	rm -f *.o *.a stringProg

	
