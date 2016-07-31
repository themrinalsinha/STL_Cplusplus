CC=g++
CFLAG= -c -Wall

all:assignment8

assignment8:assignment8.o
	$(CC) assignment8.o -o assignment8
	./assignment8 assignment8input.txt

assignment8.o:assignment8.cc
	$(CC) $(CFLAG) assignment8.cc

clean:
	rm -rf *o assignment8
