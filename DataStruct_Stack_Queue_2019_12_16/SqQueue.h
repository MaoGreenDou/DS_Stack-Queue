#pragma once
#define TYPE int
#define Status int
#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 5

//��һ���սڵ��ѭ������
typedef struct
{
	TYPE* base;
	int rear;
	int front;
	int size;
}SqQueue;

Status initSqQueue(SqQueue&);

Status sqQueueEmpty(SqQueue);

Status sqQueueFull(SqQueue);

Status sqQueueInsert(SqQueue&, TYPE);

Status sqQueueDelete(SqQueue&, TYPE&);

int sqQueueLength(SqQueue);