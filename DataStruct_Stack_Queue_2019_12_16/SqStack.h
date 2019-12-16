#pragma once
#define MAXSIZE  100
#define INCREMENTSIZE 10
#define TYPE int
#define Status int
#define OK 0
#define ERROR -1 
#define TRUE 1
#define FALSE 0


typedef struct
{
	TYPE* base;
	TYPE* top;
	int stackSize;
}SqStack;

Status initStack(SqStack& stack);
Status desStack(SqStack& stack);
void clearStack(SqStack& stack);

Status judgeFull(SqStack stack);
Status judgeEmpty(SqStack stack);
Status pushElem(SqStack& stack, TYPE e);
Status popElem(SqStack& stack, TYPE& e);
void stackTravel(SqStack stack);
