#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(SqStack& stack)
{
	stack.base = (TYPE*)malloc(MAXSIZE * sizeof(TYPE));

	if (!stack.base)
	{
		printf("OVERFLOW!");
		return ERROR;
	}

	stack.top = stack.base;
	stack.stackSize = MAXSIZE;
	return OK;
}

Status judgeFull(SqStack stack)
{
	if (stack.top - stack.base < stack.stackSize)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

Status judgeEmpty(SqStack stack)
{
	if (stack.top - stack.base != 0)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

//形参传入不可以，要改变stackSize
Status pushElem(SqStack& stack, TYPE e)
{
	if (!judgeFull(stack))
	{
		*(stack.top) = e;
		stack.top++;
		return OK;
	}
	else
	{
		stack.base = (TYPE*)realloc(stack.base,(stack.stackSize + INCREMENTSIZE) * sizeof(TYPE));

		if (!stack.base)
		{
			printf("OVERFLOW!\n");
			printf("default data may be droped!\n");
			return ERROR;
		}

		stack.top = stack.base + stack.stackSize; //可以没有么？
		stack.stackSize += INCREMENTSIZE;

		return OK;
	}
}

Status popElem(SqStack& stack, TYPE& e)
{
	if (!judgeEmpty(stack))
	{
		stack.top--;
		e = *stack.top;
		//还需要对弹出来空做什么操作吗？
		return OK;
	}
	else
	{
		printf("The stack have been empty!\n");
		return ERROR;
	}
}

void clearStack(SqStack& stack)
{
	TYPE temp;
	while (!judgeEmpty(stack))
	{
		popElem(stack, temp);
	}
}

Status desStack(SqStack& stack)
{
	clearStack(stack);
	return OK;
	//不是链式存储
}

void stackTravel(SqStack stack)
{
	TYPE* temp;
	for (temp = stack.base;temp < stack.top;temp++)
	{
		printf("Travel elem is %d\n", *temp);
	}
}