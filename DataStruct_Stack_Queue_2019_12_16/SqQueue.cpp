#include "SqQueue.h"
#include <stdio.h>
#include <stdlib.h>
#define N 5

Status initSqQueue(SqQueue& sQ)
{
	sQ.base = (TYPE*)malloc(sizeof(TYPE) * N);
	if (!sQ.base)
	{
		printf("OVERFLOW!\n");
		return ERROR;
	}
	sQ.front = 0;
	sQ.rear = 0;
	sQ.size = MAXSIZE;
	return OK;
}

Status sqQueueFull(SqQueue sQ)
{
	if ((sQ.rear + 1) % sQ.size == sQ.front)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status sqQueueEmpty(SqQueue sQ)
{
	if (sQ.front == sQ.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status sqQueueInsert(SqQueue& sQ,TYPE e)
{
	if (sqQueueFull(sQ))
	{
		return ERROR;
	}
	else
	{
		sQ.base[sQ.rear] = e;
		sQ.rear = (sQ.rear + 1) % sQ.size;
		return OK;
	}
}

Status sqQueueDelete(SqQueue& sQ, TYPE& e)
{
	if (sqQueueEmpty(sQ))
	{
		return ERROR;
	}
	else
	{
		e = sQ.base[sQ.front];
		sQ.front = (sQ.front + 1) % sQ.size;
	}
}

int sqQueueLength(SqQueue sQ)
{
	return (sQ.rear + sQ.size - sQ.front) % sQ.size;
}
