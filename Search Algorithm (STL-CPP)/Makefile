CC = g++
CFLAG = -c -Wall

all:assignment2

assignment2: assignment2.o
	$(CC) assignment2.o -o assignment2

assignment2.o:assignment2.cc
	$(CC) $(CFLAG) assignment2.cc

clean:
	rm -rf *o assignment2
