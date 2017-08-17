
LDFLAGS = -lncurses
CC = g++
OUTFILE = Joshua

all:
	$(CC) -c TicTacToe.cpp
	$(CC) -c Chess.cpp
	$(CC) -c GTW.cpp
	$(CC) -c main.cpp
	
	$(CC) -o $(OUTFILE) TicTacToe.o Chess.o GTW.o main.o $(LDFLAGS)

clean:
	rm -f *.o *.gch
