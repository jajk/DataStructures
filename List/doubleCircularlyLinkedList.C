#include<stdio.h>
typedef struct link
{
	struct link *next;
	struct link *prior;
	int element;
}link;
typedef struct
{
	link *head;
	link *tail;
	int length;
}h;
void create(h *l,int number)
{
	int count;
	link *p;
	link *q;
	l->length=number;
	for(count=1;count<=number;count++)
	{
		p=(link *)malloc(sizeof(link));
		if(p!=NULL)
		{
			printf("please input a number:\n");
			scanf("%d",&p->element);
			if(count==1)
			{
				l->head=q=p;
			}
			else
			{
				q->next=p;
				p->prior=q;
				q=p;
			}
		}
		else
		{
			printf("the space no enough!!!");
			exit(0);
		}
	}
	l->head->prior=p;
	p->next=l->head;
	l->tail=p;
}
void print(link *p,int number)
{
	int count;
	printf("\n");
	for(count=1;count<=number;count++)
	{
		printf("this number:%d\t",p->element);
		printf("the prior:%d\t",p->prior->element);
		printf("the next :%d\n",p->next->element);
		p=p->next;
	}
}
main()
{
	h l;
	printf("\n");
	create(&l,3);
	print(l.head,3);
}