CC=g++
CFLAG= -c -Wall

all:assignment4

assignment4:assignment4.o
	$(CC) assignment4.o -o assignment4
	./assignment4 < assignment4input.txt

assignment4.o:assignment4.cc
	$(CC) $(CFLAG) assignment4.cc

clean:
	rm -rf *o assignment4
