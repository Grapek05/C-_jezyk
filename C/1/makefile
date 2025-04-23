# Makefile

CC = gcc
CFLAGS = -Wall -std=c99
TARGET = plikowiec

SRCS = main.c file.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

%.o: %.c file.h
	$(CC) $(CFLAGS) -c $< -o $@

