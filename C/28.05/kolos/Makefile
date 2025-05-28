CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

all: main

main: main.o dllist.o
	$(CC) $(CFLAGS) -o main main.o dllist.o

main.o: main.c dllist.h
	$(CC) $(CFLAGS) -c main.c

dllist.o: dllist.c dllist.h
	$(CC) $(CFLAGS) -c dllist.c

clean:
	rm -f main *.o
