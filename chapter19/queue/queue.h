#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
/*
·向队列的末端加入项。
·从队列的开始删除项。
·返回队列第一项（不改变队列）。
·返回队列的末项（不改变队列）。
·检查队列是否为空。
*/
typedef int Item;
typedef struct queue_type *Queue;
Queue create();
bool add_queue(Queue q, Item v);
Item del_queue(Queue q);
Item head_queue(Queue q);
Item tail_queue(Queue q);
bool is_empty(Queue q);
#endif