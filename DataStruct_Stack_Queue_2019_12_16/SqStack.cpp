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

//�βδ��벻���ԣ�Ҫ�ı�stackSize
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

		stack.top = stack.base + stack.stackSize; //����û��ô��
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
		//����Ҫ�Ե���������ʲô������
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
	//������ʽ�洢
}

void stackTravel(SqStack stack)
{
	TYPE* temp;
	for (temp = stack.base;temp < stack.top;temp++)
	{
		printf("Travel elem is %d\n", *temp);
	}
}