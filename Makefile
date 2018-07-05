#This is the executable name
PROGRAMS = LList

CC = gcc
CFLAGS =

all: $(PROGRAMS)

tidy:
	rm -f ,* ., * *~ core. a.out graphics.ps

scratch: tidy
	rm -f *.o *.a $(PROGRAMS)

#change LL.c and LL.o file name to the one you have.
LL.o: LL.c linkedlist.h files.h
	$(CC) $(CFLAGS) -g -c LL.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -g -c linkedlist.c

# creating the executable
LList: LL.o linkedlist.o
	$(CC) $(CFLAGS) -g -c LL.c linkedlist.c
	$(CC) $(CFLAGS) -g -o LList LL.o linkedlist.o
