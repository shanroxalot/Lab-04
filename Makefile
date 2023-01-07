# Makefile for Lab-04

CC = gcc
CFLAGS = -Wall -g
OBJS = lab04.o
EXECS = lab04

build : lab04
	./lab04 file1.txt file2.txt

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

lab04 : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

debug :	lab04
	gdb ./lab04 -tui

clean : 
	rm *.o $(EXECS)