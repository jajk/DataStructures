#include<stdio.h>
#define max 100
#define increment 10
typedef struct stack
{
	int *base;
	int *top;
	int length;
}stack;
void inital(stack *l)
{
	l->base=(int *)malloc(max*sizeof(int));
	if(l->base!=NULL)
	{
		l->top=l->base;
		l->length=max;
	}
	else
	{
		printf("the space no enough!!");
		exit(0);
	}
}
int stackempty(stack *l)
{
	if(l->base!=NULL)
		return 0;
	else
		return 1;
}
int stacklength(stack *l)
{
	if(stackempty(l)==0)
		return l->top-l->base;
	else
	{
		printf("the stack is empty");
		return -1;
	}
}
int gettop(stack *l)
{
	if(stackempty(l)==0)
	{
		return *(l->top-1);
	}
	else
	{
		printf("the stack is empty: so no topelement!!");
		exit(0);
	}
}
void push(stack *l,int e)
{
	int *newbase;
	if(l->top-l->base>=l->length)
	{
		newbase=(int *)realloc(l->base,increment*sizeof(int));
		if(newbase!=NULL)
		{
			l->base=newbase;
			l->top=l->base+l->length;
			l->length+=increment;
		}
		else
		{
			printf("the space no enough!!");
			exit(0);
		}
	}
	else
	{
		*(l->top++)=e;
	}
}
int pop(stack *l)
{
	if(stackempty(l)==0)
	{
		return *(--l->top);
	}
	else
	{
		printf("the stack is empty:so no element!!");
		exit(0);
	}
}
void create(stack *l,int number)
{
	int count;
	int e;
	for(count=0;count<number;count++)
	{
		printf("please input a number:\n");
		scanf("%d",&e);
		push(l,e);
	}
}
void print(stack *l)
{
	int count;
	for(count=0;count<l->top-l->base;count++)
	{
		printf("%d\t",l->base[count]);
	}
}
main()
{
	stack l;
	system("cls");
	inital(&l);
	create(&l,3);
	printf("the stack:\n");
	print(&l);
	printf("\n");
	printf("the stack top element :%d\n",gettop(&l));
	printf("already delete :%d\n",pop(&l));
	printf("the stack top element :%d\n",gettop(&l));
	print(&l);
}