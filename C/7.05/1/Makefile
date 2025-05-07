CC = gcc
NASM = nasm
NASMFLAGS = -f elf64  # Dla Linuxa. Dla macOS użyj -f macho64
LDFLAGS = -lm

all: asmpow

asmpow.o: asmpow.asm
	$(NASM) $(NASMFLAGS) asmpow.asm -o asmpow.o

asmpowd.o: asmpowd.asm
	$(NASM) $(NASMFLAGS) asmpowd.asm -o asmpowd.o

asmpow: asmpow.o asmpowd.o main.c
	$(CC) $^ -o $@ $(LDFLAGS)
	
clean:
	rm -f asmpow *.o