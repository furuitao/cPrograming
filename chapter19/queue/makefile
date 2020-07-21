queue_test: queue_test.o queue.o
	gcc -o queue_test queue_test.o queue.o
queue_test.o: queue_test.c queue.h
	gcc -c queue_test.c
queue.o: queue_list.c queue.h
	gcc -c queue_list.c -o queue.o
