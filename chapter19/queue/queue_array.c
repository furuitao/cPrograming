#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 100
struct queue_type{
	Item contents[MAX];
	int head;
	int tail;
	int size;
};

Queue create(){
	printf("使用数组创建队列\n");
	Queue q = malloc(sizeof(struct queue_type));
	q -> head = 0;
	q -> tail = 0;
	q -> size = 0;
	return q;
}

bool add_queue(Queue q, Item v){
	if(q -> size == MAX){
		printf("队列已满.\n");
		return false;
	}
	q -> contents[q -> tail++] = v;
	q -> size++;
	if(q -> tail == MAX){// 位置重置
		q -> tail = 0;
	}
	return true;
}

Item del_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	Item v = q -> contents[q -> head++];
	q -> size--;
	if(q -> head == MAX){
		q -> head = 0;
	}
	return v;
}

Item head_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	return q -> contents[q -> head];
}

Item tail_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	int i = q -> tail == 0 ? MAX - 1 : q -> tail - 1;
	return q -> contents[i];
}

bool is_empty(Queue q){
	return q -> size == 0;
}
