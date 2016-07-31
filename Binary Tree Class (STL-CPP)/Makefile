CC=g++
CFLAG= -c -Wall

all:assignment5

assignment5:assignment5.o
	$(CC) assignment5.o -o assignment5
	./assignment5

assignment5.o:assignment5.cc
	$(CC) $(CFLAG) assignment5.cc
	
clean:
	rm -rf *o assignment5
