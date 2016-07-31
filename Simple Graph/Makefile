CC=g++
CFLAG= -c -Wall

all:assignment9

assignment9:assignment9.o
	$(CC) assignment9.o -o assignment9
	./assignment9 assignment9input.txt

assignment9.o:assignment9.cc
	$(CC) $(CFLAG) assignment9.cc

clean:
	rm -rf *o assignment9
