HW3: main.o CreateMGraph.o parsing.o BFSTraverse.o
	gcc main.o CreateMGraph.o parsing.o BFSTraverse.o -o HW3

main.o: main.c BFSTraverse.h CreateMGraph.h input_error.h parsing.h
	gcc -c main.c

CreateMGraph.o: CreateMGraph.c BFSTraverse.h CreateMGraph.h input_error.h parsing.h
	gcc -c CreateMGraph.c

parsing.o: parsing.c BFSTraverse.h CreateMGraph.h input_error.h parsing.h
	gcc -c parsing.c

BFSTraverse.o: BFSTraverse.c BFSTraverse.h CreateMGraph.h input_error.h parsing.h
	gcc -c BFSTraverse.o

clean:
	rm -f *.o HW3
