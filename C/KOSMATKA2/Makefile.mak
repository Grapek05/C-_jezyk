CC = gcc
CFLAGS = -Wall -Wextra -std=c11
OBJS = main.o

all: program

program: $(OBJS)
	$(CC) $(CFLAGS) -o program $(OBJS)

main.o: main.c stack.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o program
