#include "LinkQueue.h"
#include <stdio.h>
#include <stdlib.h>

Status initLinkQueue(linkQueue& lq)
{
	lq.front = (pNode)malloc(sizeof(queueNode));
	lq.rear = lq.front;
	if (!lq.front)
	{
		printf("OVERFLOW!\n");
		return ERROR;
	}
	lq.front->next = NULL;
	return OK;
}

Status linkQueueEmpty(linkQueue lq)
{
	if (lq.front == lq.rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status linkQueueInsert(linkQueue& lq,TYPE e)
{
	pNode temp = (pNode)malloc(sizeof(queueNode));
	if (!temp)
	{
		printf("OVERFLOW!\n");
		return ERROR;
	}
	temp->next = NULL;
	temp->data = e;
	lq.rear->next = temp;
	lq.rear = temp;
	return OK;
}

Status linkQueueDelete(linkQueue& lq, TYPE& e)
{
	pNode temp = (pNode)malloc(sizeof(queueNode));
	if (linkQueueEmpty(lq))
	{
		return ERROR;
	}
	else
	{
		temp = lq.front->next;
		e = temp->data;
		lq.front->next = temp->next;

		if (lq.rear == temp)    //删除的是队尾元素
		{
			lq.rear = lq.front;
		}

		free(temp);
		temp = NULL;
		return OK;
	}
}