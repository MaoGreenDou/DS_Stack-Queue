// DataStruct_Stack_Queue_2019_12_16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"
//#include "LinkStack.h"


//杂：
//指针存放的是地址，指针的基类型就是地址代表元素的类型
//linkStack可以用作尾插法吗？
//对linkStack的遍历改变节点内容吗？
void basciDemo();
void conversion();
Status check();
int main()
{
	//basiDemo();
	//conversion();
	check();
	return 0;
}

void basicDemo()
{
	SqStack sq;
	TYPE temp;

	initStack(sq);

	for (int i = 0;i < 10;i++)
	{
		printf("Please input 10 elem,this is  no.%d elem\n", i);
		scanf_s("%d", &temp);
		pushElem(sq, temp);
		getchar();
	}

	stackTravel(sq);

	popElem(sq, temp);
	popElem(sq, temp);
	popElem(sq, temp);

	stackTravel(sq);

	popElem(sq, temp);
	popElem(sq, temp);
	popElem(sq, temp);
	popElem(sq, temp);
	popElem(sq, temp);
	popElem(sq, temp);

	stackTravel(sq);

	clearStack(sq);

	pushElem(sq, 99);

	stackTravel(sq);

	clearStack(sq);

	stackTravel(sq);
}


//进制转换
//TYPE 用 int
//void conversion()
//{
//	SqStack stack;
//	int defaultNum;
//	int N = 2;
//
//	initStack(stack);
//	printf("Please input a num code by Oct:\n");
//	scanf_s("%d", &defaultNum);
//	
//	while (defaultNum)
//	{
//		pushElem(stack,defaultNum % N);
//		defaultNum = defaultNum / N;
//
//	}
//
//	printf("the num have turned to another\n");
//	while (!judgeEmpty(stack))
//	{
//		popElem(stack, defaultNum);
//		printf("%d", defaultNum);
//	}
//
//}




//括号检查
//TYPE 用char
Status check()
{
	SqStack stack;
	initStack(stack);
	char temp;
	char temp_2;

	while ((temp = getchar()) != '#')
	{
		switch (temp)
		{
			case '(':
			case '[':
			case '{':
				pushElem(stack, temp);
				break;
			case ')':
				if (judgeEmpty(stack))
				{
					printf("the right char have been left!\n");
					return ERROR;
				}
				else
				{
					popElem(stack, temp_2);
					if ('(' != temp_2)
					{
						printf("the right char is not equal to the left!\n");
						return ERROR;
					}
				}
				break;
			case ']':
				if (judgeEmpty(stack))
				{
					printf("the right char have been left!\n");
				}
				else
				{
					popElem(stack, temp_2);
					if ('[' != temp_2)
					{
						printf("the right char is not equal to the left!\n");
						return ERROR;
					}
				}
				break;
			case '}':
				if (judgeEmpty(stack))
				{
					printf("the right char have been left!\n");
					return ERROR;
				}
				else
				{
					popElem(stack, temp_2);
					if ('{' != temp_2)
					{
						printf("the right char is not equal to the left!\n");
						return ERROR;
					}
				}
				break;
			default:
				break;
		}


	}
	if (!judgeEmpty(stack))
	{
		printf("the left char have been droped!\n");
		return ERROR;
	}

	return OK;
}

//行编辑伪码
/*
void editLine(）
｛
	从输入区接受全部输入，以EOF结束；
	初始化一个栈；
	ch = getchar（）；
	while（ch！=eof）
	｛
		while（ch！=eof || ch ！= \n）
		｛
			switch ch
			｛
				字符就进栈；
				#先判断是否空，若不空则退栈；
				@清空；
			｝
			ch = getchar（）；
		｝
		将栈里的内容输出到输出区域
		清空栈

		if（ch ！=eof）ch = getchar（）    //有可能是换行符，有可能是EOF
		//这里采用两层while的解释：
		从数据输入区接受的是包含换行符和EOF的一段话，如果只有内层循环，当循环终止以后，无法通过判断终止符号来决定是否启动下一行的编辑
	｝
｝
*/

//迷宫问题伪码 
/*
void maze（）
{
    当前位置如果可以落脚；
	那么就把当前位置纳入路径；
	接着把当前位置调整为栈顶元素的某一个方向。

	如果不可以落脚，
	退回上一位置，重新探索（当前位置调整为栈顶元素的下一个方向）
	如果上一位置不可探索，则退栈。
}
*/

//表达式求解问题
//对左括号的处理，入栈的时候可以直接入，入栈后优先级小于所有元素
/*
void mathmtic()
{
    建立符号栈；
	建立操作数栈；

	#入栈至符号栈。

	c = getchar（）；
	while（c！=# || getElem(符号栈)！=#）    //只要c和getElem不全是#就一直运算
	｛
	    if（c是操作数）
		｛
		    入操作数栈，更新c
		｝
		else
		｛
		    判断c和符号栈栈顶元素优先级
			如果c的优先级高
			    c入符号栈，更新c
			如果相等
			   符号栈弹栈，更新c    //仅发生在栈顶元素是(，c是)的情况下
			如果c的优先级小
			   操作数栈弹栈两次，符号栈弹栈一次，进行运算，结果入操作数栈。不更新C
		｝
	｝
	返回运算结果，即操作数栈剩余的唯一元素
}
*/
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
