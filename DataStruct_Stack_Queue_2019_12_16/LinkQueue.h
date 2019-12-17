#pragma once
#define TYPE int
#define Status int
#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0

typedef struct node
{
	TYPE data;
	struct node* next;
}queueNode,*pNode;

typedef struct
{
	pNode front;
	pNode rear;
}linkQueue;

Status initLinkQueue(linkQueue&);

Status linkQueueEmpty(linkQueue);

Status linkQueueInsert(linkQueue&);

Status linkQueueDelete(linkQueue&);