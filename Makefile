C_SOURCE=$(wildcard *.c)
H_SOURCE=$(wildcard *.h)

CC=gcc

all:
	$(CC) -c $(C_SOURCE)
	ar rs clist.a clist.o

    