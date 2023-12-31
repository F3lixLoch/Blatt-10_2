CC=gcc
CFLAGS=-Wall -g
OBJECTS=labyrinth.o main.o dlinkedlist.o

all: pathfinder

labyrinth.o: labyrinth.h

dlinkedlist.o: dlinkedlist.h labyrinth.h
queue.o: queue.h dlinkedlist.h labyrinth.h
stack.o: stack.h dlinkedlist.h labyrinth.h

pathfinder: ${OBJECTS}
	${CC} ${CFLAGS} -o pathfinder ${OBJECTS}

clean:
	rm -f pathfinder
	rm -f ${OBJECTS}

.PHONY: clean all
