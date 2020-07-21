stack_test: stack_test.o stack.o
	gcc -o stack_test stack_test.o stack.o
stack_test.o: stack_test.c stack.h
	gcc -c stack_test.c
stack.o: stack_array.c stack.h
	gcc -c stack_array.c -o stack.o