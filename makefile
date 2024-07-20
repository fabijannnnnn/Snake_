CC=g++
all: output

output: main.cpp window.h
	$(CC) -o main main.cpp -lcurses
