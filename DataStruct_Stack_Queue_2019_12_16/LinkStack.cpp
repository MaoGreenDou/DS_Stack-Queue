#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(pStack& ps)
{

	createNode(ps);

	ps->next = NULL;
}

Status judgeEmpty(pStack ps)
{
	if (ps->next)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}

}

Status pushELem(pStack& ps, TYPE e)    //可用作尾插法吗？
{
	pStack pushTemp = NULL;
	pStack temp = ps;

	createNode(pushTemp);

	pushTemp->data = e;
	pushTemp->next = NULL;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = pushTemp;
}

Status popElem(pStack& ps, TYPE& e)
{
	pStack temp = ps;
	pStack deleteTemp = NULL;

	if (judgeEmpty(temp))
	{
		printf("No elem could be poped!\n");
		return ERROR;
	}
	else
	{
		while (temp->next->next)
		{
			temp = temp->next;
		}
		
		deleteTemp = temp->next;
		e = deleteTemp->data;
		temp->next = deleteTemp->next;
		deleteNode(deleteTemp);
		
		return OK;

	}
}

void stackTravel(pStack ps) //遍历会改变吗
{
	int flag = 0;
	while (ps->next)
	{
		ps = ps->next;
		printf("Elem is %d\n", ps->data);
		flag = 1;
	}
	if (flag)
	{
		printf("Elem is %d\n", ps->data);
	}
}

Status clearStack(pStack& ps)
{
	TYPE temp;
	while (ps->next)
	{
		popElem(ps,temp);
	}
	return OK;
}