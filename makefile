CC = gcc
DIR = 814

test: main.o

main.o:
	${CC} -gdwarf-2 -g3  ${DIR}/main.c node.h -gdwarf-2 -g3 node.c listnode.h -lm --debug

clean:
	rm -rf a.out  *.gch *.dSYM

debug:
	lldb a.out
	b main