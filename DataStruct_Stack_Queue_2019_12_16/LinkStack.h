#pragma once
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

Status createNode(pStack& ps);


Status deleteNode(pStack& ps);

Status initStack(pStack& ps);

Status clearStack(pStack& ps);

Status desStack(pStack& ps);

Status judgeEmpty(pStack);

Status popElem(pStack& ps, TYPE& e);

Status pushElem(pStack& ps, TYPE e);

void stackTravel(pStack ps);