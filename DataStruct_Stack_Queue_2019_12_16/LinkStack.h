#pragma once
#include <cstddef>
#define Status int
#define OK 0
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define TYPE int

typedef struct stackNode
{
	TYPE data;
	struct stackNode* next;
}sNode,* pStack;

Status createNode(pStack& ps)
{
	ps = (pStack)malloc(sizeof(sNode));
	if (!ps)
	{
		printf("OVERFLOW!\n");
		return ERROR;
	}
	else
	{
		return OK;
	}
}

Status deleteNode(pStack& ps)
{
	free(ps);
	ps = NULL;
	return OK;
	
}

Status initStack(pStack& ps);

Status clearStack(pStack& ps);

Status desStack(pStack& ps);

Status judgeEmpty(pStack);

Status popElem(pStack& ps, TYPE& e);

Status pushElem(pStack& ps, TYPE e);

void stackTravel(pStack ps);