CC=g++
CFLAG= -c -Wall

all:assignment3

assignment3:assignment3.o
	$(CC) assignment3.o -o assignment3

assignment3.o:assignment3.cc
	$(CC) $(CFLAG) assignment3.cc

clean:
	rm -rf *o assignment3
