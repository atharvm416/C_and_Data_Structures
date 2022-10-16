#include<stdio.h>
#define M 20
typedef struct stack
{
	int top;
	char arr[M];
}CSTK;
void init(CSTK *t)
{
	t->top==-1;
}
void push(CSTK *t,char ch)
{
	if(t->top==M-1)
		printf("\nOverflow");
	else
	{
		t->arr[++t->top]=ch;
	}
}
char stacktop(CSTK *t)
{
	if(t->top==-1)
		return '\0';
	else
		return t->arr[t->top];
}
void pop(CSTK *t)
{
	if(t->top==-1)
		return;
	t->top--;
}

