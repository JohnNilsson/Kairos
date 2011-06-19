CC = gcc -Wall -g#-O3 -flto -march=native

OBJFILES := $(patsubst %.c,%.o,$(wildcard *.c))

all: fclient journal

%.o: %.c zmq.h
	$(CC) -c $< -o $@

journal: journal.o
	$(CC) $< -lzmq -o $@ 

fclient: fclient.o
	$(CC) $< -lzmq -o $@ 

