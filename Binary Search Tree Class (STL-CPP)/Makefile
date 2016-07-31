CC=g++
CFLAG= -c -Wall

all:assignment6

assignment6:assignment5.o assignment6.o assignment6main.o
	$(CC) assignment5.o assignment6.o assignment6main.o -o assignment6
	./assignment6

assignment5.o:assignment5.cc
	$(CC) $(CFLAG) assignment5.cc

assignment6.o:assignment6.cc
	$(CC) $(CFLAG) assignment6.cc

assignment6main.o:assignment6main.cc
	$(CC) $(CFLAG) assignment6main.cc

clean:
	rm -rf *o assignment6
