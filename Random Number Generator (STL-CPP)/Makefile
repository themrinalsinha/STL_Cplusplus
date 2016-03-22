CC=g++
CFLAG= -c -Wall

all:assignment1

assignment1:assignment1.o
	$(CC) assignment1.o -o assignment1

assignment1.o:assignment1.cc
	$(CC) $(CFLAG) assignment1.cc

clean:
	rm -rf *o assignment1
