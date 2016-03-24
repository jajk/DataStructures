#include<stdio.h>
typedef struct link
{
	struct link *next;
	int element;
}link;
void create(link *head,int number)
{
	int count;
	link *p;
	head->next=NULL;
	for(count=0;count<number;count++)
	{
		p=(link *)malloc(sizeof(link));
		printf("please input a number:\n");
		scanf("%d",&p->element);
		p->next=head->next;
		head->next=p;
	}
}
int pop(link *head)
{
	int e;
	link *q;
	link *p;
	p=head->next;
	if(p!=NULL)
	{
		e=p->element;
		q=p;
		p=p->next;
		free(q);
		head->next=p;
		return e;
	}
	else
	{
		printf("the stack is empty:so don't delete!!");
		exit(0);
	}
}
void push(link *head,int e)
{
	link *p;
	p=(link *)malloc(sizeof(link));
	p->element=e;
	p->next=head->next;
	head->next=p;
}
int gettop(link *head)
{
	link *p;
	p=head->next;
	if(p!=NULL)
	{
		return p->element;
	}
	else
	{
		printf("the head is NULL:so cann't get the top!!");
		exit(0);
	}
}
void print(link *head)
{
	link *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d\t",p->element);
		p=p->next;
	}
	printf("\n");
}
main()
{
	link head;
	system("cls");
	create(&head,3);
	printf("the stack:\n");
	print(&head);
	printf("the stack top is: %d\n",gettop(&head));
	printf("already delect a element:%d\n",pop(&head));
	print(&head);
	push(&head,8);
	printf("already add a element:8\n");
	print(&head);
}
