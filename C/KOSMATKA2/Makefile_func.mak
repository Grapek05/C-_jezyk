CC = gcc
NASM = nasm
CFLAGS = -Wall -Wextra -std=c11

all: main_func

main_func: main_func.o func.o
	$(CC) -o main_func main_func.o func.o

main_func.o: main_func.c
	$(CC) $(CFLAGS) -c main_func.c

func.o: func.asm
	$(NASM) -f elf64 func.asm

clean:
	rm -f *.o main_func
