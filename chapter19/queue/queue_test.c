#include <stdio.h>
#include "queue.h"

int main(void){
	Queue q = create();

	printf("队列是否为空：%d\n", is_empty(q));
	add_queue(q, 1);
	add_queue(q, 2);

    printf("队列头：%d\n", head_queue(q));
    printf("队列尾：%d\n", tail_queue(q));

	printf("弹出队列%d\n", del_queue(q));
	printf("弹出队列%d\n", del_queue(q));
	printf("弹出队列%d\n", del_queue(q));

	return 0;
}