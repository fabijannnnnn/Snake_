CC = g++
CFLAGS = -lcurses

all: snake

snake: main.o
	$(CC) -o snake main.o $(CFLAGS)

main.o: main.cpp window.h
	$(CC) -c main.cpp

clean:
	rm -f snake main.o
