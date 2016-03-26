#include<stdio.h>
#define max 100
typedef struct node
{
	char element;
	int flag;
	struct node *lchild,*rchild;
}node;
typedef struct stack
{
	node **base;
	node **top;
	int length;
}stack;
node *inital()
{
	return NULL;
}
node *create()
{
	char e;
	node *t;
	scanf("%c",&e);
	if(e=='#')
	{
		return NULL;
	}
	else
	{
		t=(node *)malloc(sizeof(node));
		t->element=e;
		t->flag=0;
		t->lchild=create();
		t->rchild=create();
	}
	return t;
}
int Jempty(node *t)
{
	if(t!=NULL)
		return 1;
	return 0;
}
void travel(node *t)
{
	if(t!=NULL)
	{
		printf("%c",t->element);
		travel(t->lchild);
		travel(t->rchild);
	}
}
node *gettop(stack *s)
{
	return *(s->top-1);
}
void push(stack *s,node *t)
{
	*(s->top++)=t;
}
void pop(stack *s)
{
	s->top--;
}
int length(node *t)
{
	int number;
	stack s;
	s.base=(node **)malloc(max*sizeof(node*));
	number=1;
	s.top=s.base;
	s.length=max;
	push(&s,t);
	while(s.base!=s.top)
	{
		t=gettop(&s);
		if(t->flag==0)
		{
			t->flag=1;
			if(t->lchild!=NULL)
			{
				push(&s,t->lchild);
				if(s.top-s.base>number)
					number=s.top-s.base;
			}
		}
		else if(t->rchild!=NULL&&t->flag==1)
		{
			t->flag=2;
			push(&s,t->rchild);
			if(s.top-s.base>number)
				number=s.top-s.base;
		}
		else
		{
			pop(&s);
		}
	}
	return number;
}
int sum(node *t)
{
	int sum=0;
	int flag=0;
	node* child;
	stack s;
	s.base=(node **)malloc(max*sizeof(node*));
	s.top=s.base;
	s.length=max;
	push(&s,t);
	sum=1;
	while(s.base!=s.top)
	{
		child=gettop(&s);
		if(child->lchild!=NULL&&flag==0)
		{
			sum++;
			push(&s,child->lchild);
		}
		else if(child->rchild!=NULL||flag==1)
		{
			pop(&s);
			if(child->rchild!=NULL)
			{
				flag=0;
				sum++;
				push(&s,child->rchild);
			}
			else
			{
				flag=1;
			}
		}
		else
		{
			pop(&s);
			flag=1;
		}
	}
	free(s.base);
	return sum;
}
main()
{
	node *tree;
	int number;
	system("cls");
	printf("order:\t\t");
	printf("content:\n\n");
	printf("    0,\t\t");
	printf("need to exit\n");
	printf("    1,\t\t");
	printf("inital the double tree:\n");
	printf("    2,\t\t");
	printf("use preorder create a double tree:\n");
	printf("    3,\t\t");
	printf("judge the double tree that whether empty:\n");
	printf("    4,\t\t");
	printf("travel the double tree:\n");
	printf("    5,\t\t");
	printf("the double tree's h_lengh:\n");
	printf("    6,\t\t");
	printf("the double tree's sum_number:\n");
	printf("\n");
	do
	{
		printf("\nstep to:");
		scanf("%d",&number);
		switch(number)
		{
			case 1:
			{
				tree=inital();
				printf("the double tree already achivement!\n");
			}
			break;
			case 2:
			{
				tree=create();
			}
			break;
			case 3:
			{
				if(Jempty(tree)==1)
					printf("the double tree no NULL!\n");
				else
					printf("the tree is NULL!\n");
			}
			break;
			case 4:
			{
				travel(tree);
				printf("\n");
			}
			break;
			case 5:
			{
				printf("the double tree h_length:%d\n",length(tree));
			}
			break;
			case 6:
			{
				printf("the double tree sum_number:%d\n",sum(tree));
			}
			break;
		}
	}while(number!=0);
}