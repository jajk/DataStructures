#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	struct link *next;
	int element;
}link;
typedef struct h
{
	link *head;
	link *tail;
	int length;
}h;
void create(h *c,int number)
{
	int count;
	link *p;
	link *q;
	c->length=number;
	for(count=1;count<=number;count++)
	{
		p=(link *)malloc(sizeof(link));
		if(p!=NULL)
		{
			printf("please input a number:\n");
			scanf("%d",&p->element);
			if(count==1)
			{
				c->head=q=p;
			}
			else
			{
				q->next=p;
				q=p;
			}
		}
		else
		{
			printf("the space no enough!!");
			exit(0);
		}
	}
	p->next=c->head;
	c->tail=p;
}
void print(link *h,int number)
{
	int count;
	for(count=1;count<=number;count++)
	{
		printf("%d\t",h->element);
		h=h->next;
	}
}
main()
{
	h c;
	create(&c,3);
	print(c.head,4);
	printf("\n");
	print(c.tail,4);
}