ll_main: ll_main.o ll.o
	gcc -o ll_main ll_main.o ll.o
ll_main.o: ll_main.c ll.h
	gcc -c ll_main.c
ll.o: ll.c ll.h
	gcc -c ll.c
clean:
	rm ll_main *.o
