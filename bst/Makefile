test_bst: test_bst.o bst.o
	gcc -o test_bst test_bst.o bst.o
test_bst.o: test_bst.c bst.h
	gcc -Wall -g -std=c11 -c test_bst.c
bst.o: bst.c bst.h
	gcc -Wall -g -std=c11 -c bst.c
clean:
	rm test_bst *.o
