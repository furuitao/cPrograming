/*
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int value;
	struct node *next;
};

bool add(struct node **list, int n);
void remove_list(struct node **list, int n);
/*其中形式参数list指向一个链表。函数应返回n在该链表中出现的次数。*/
int count_occurrences(struct node *list, int n);
/*函数应返回一个指针，该指针指向最后一个包含n的结点，如果n不存在则返回NULL。*/
struct node *find_last(struct node *list, int n);
/*在有序链表的适当位置插入一个新结点，并返回指向新链表首结点的指针。*/
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

void print_list(struct node *list);

int main(void){
	struct node *list = NULL;
	add(&list, 1);
	add(&list, 1);
	add(&list, 2);
	add(&list, 3);
	add(&list, 1);
	add(&list, 2);

	print_list(list);

	printf("包含1的数量：%d\n", count_occurrences(list, 1));
	printf("包含2的数量：%d\n", count_occurrences(list, 2));
	printf("包含3的数量：%d\n", count_occurrences(list, 3));
	printf("包含4的数量：%d\n", count_occurrences(list, 4));

	struct node *last = find_last(list, 1);
	last -> value = 0;
	print_list(list);


	struct node *sorted_list = NULL;
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {2});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {1});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {3});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {6});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {9});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {5});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {4});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {7});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {8});
	sorted_list = insert_into_ordered_list(sorted_list, &(struct node) {7});
	print_list(sorted_list);
	remove_list(&sorted_list, 7);
	remove_list(&sorted_list, 9);
	remove_list(&sorted_list, 1);
	print_list(sorted_list);
}

int count_occurrences(struct node *list, int n){
	int temp = 0;
	while(list != NULL){
		if(list -> value == n){
			temp ++;
		}
		list = list -> next;
	}
	return temp;
}

struct node *find_last(struct node *list, int n){
	struct node *temp = NULL;
	while(list != NULL){
		if(list -> value == n){
			temp = list;
		}
		list = list -> next;
	}
	return temp;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node){
	struct node *prev = NULL, *curr = list;
	while(curr != NULL && curr -> value < new_node -> value){
		prev = curr;
		curr = curr -> next;
	}

	if(prev == NULL){
		new_node -> next = curr;
		list = new_node;
	}else{
		prev -> next = new_node;
		new_node -> next = curr;
	}
	return list;
}

bool add(struct node **list, int n){
	struct node *p = malloc(sizeof(struct node));
	if(p == NULL){
		printf("分配空间失败\n");
		return false;
	}
	p -> value = n;
	p -> next = *list;
	*list = p;
	return true;
}

void remove_list(struct node **list, int n){
	struct node *prev = NULL, *curr = *list;
	while(curr != NULL){
		if(curr -> value == n){// 值匹配
			if(prev == NULL){//值在头部，删除头部节点，移动curr
				*list = curr -> next;
				// free(curr);
				curr = *list;
			}else{//值不再头部，删除当前节点，移动curr
				prev -> next = curr -> next;
				// free(curr);
				curr = prev -> next;
			}
		}else{// 值不匹配，移动prev、curr
			prev = curr;
			curr = prev -> next;
		}
	}
}

void print_list(struct node *list){
	while(list != NULL){
		printf("%d\t", list -> value);
		list = list -> next;
	}
	printf("\n");
}