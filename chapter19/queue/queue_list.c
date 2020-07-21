#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX 100

struct node{
	Item value;
	struct node *next;
};

struct queue_type{
	struct node *head;
	struct node *tail;	
	int size;
};

Queue create(){
	printf("使用链表创建队列\n");
	Queue q = malloc(sizeof(struct queue_type));
	q -> head = NULL;
	q -> tail = NULL;
	q -> size = 0;
	return q;
}

bool add_queue(Queue q, Item v){
	struct node *new_node = malloc(sizeof(struct node));
	if(new_node == NULL){
		printf("队列已满\n");
		return false;
	}
	new_node -> next = NULL;
	new_node -> value = v;
	if(is_empty(q)) {
		q -> head = new_node;
		q -> tail = new_node;
	}else{
		q -> tail -> next = new_node;
		q -> tail = new_node;	
	}
	
	q -> size ++;
	return true;
}

Item del_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	
	struct node *old_node = q -> head;
	Item v = old_node -> value;
	q -> head = old_node -> next;
	
	free(old_node);
	q -> size --;

	if(is_empty(q)){
		q -> head = NULL;
		q -> tail = NULL;
	}
	return v;
}

Item head_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	return q -> head -> value;
}

Item tail_queue(Queue q){
	if(is_empty(q)){
		printf("队列为空.\n");
		return -1;
	}
	return q -> tail -> value;
}

bool is_empty(Queue q){
	return q -> size == 0;
}
