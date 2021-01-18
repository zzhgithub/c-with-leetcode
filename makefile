CC = gcc
DIR = 226

test: main.o

main.o:
	${CC} -gdwarf-2 -g3  ${DIR}/main.c node.h node.c -lm --debug

clean:
	rm -rf a.out  *.gch *.dSYM

debug:
	lldb a.out
	b main