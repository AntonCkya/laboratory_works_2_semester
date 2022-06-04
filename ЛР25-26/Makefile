CC = gcc
LD = gcc

CFLAGS = -std=c99 -pedantic -Wall
LDFLAGS =

OBJ = main.o queue.o queue.h

PROG = lab26

.SUFFIXES: .c .o

$(PROG): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(PROG)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
main.c: queue.h

