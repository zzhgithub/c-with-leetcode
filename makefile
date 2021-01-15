CC = gcc
DIR = 101

test: node.o main.o run

node.o: node.h node.c
	${CC} -c node.c

main.o:
	${CC} -c ${DIR}/main.c

run:
	${CC} main.o node.o -o test -lm
	test

clean:
	rm test *.o