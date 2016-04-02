all: Ex4.c vetor.o
	clang -g Ex4.c vetor.o
	valgrind --leak-check=full ./a.out
vetor.o: vetor.h vetor.c
	clang -c vetor.c

