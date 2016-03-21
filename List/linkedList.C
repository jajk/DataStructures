#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
	struct link *next;
	int element;
	int length;
}link;
void destroy(link *head)
{
	link *q;
	while(head!=NULL)
	{
		q=head->next;
		free(head);
		head=q;
	}
	printf("already delect the link!!");
}
int listempty(link *k)
{
	if(k==NULL)
		return 1;
	else
		return 0;
}
int listlength(link *head)
{
	eturn head->length;
}
int getelem(link *head,int i)
{
	int count;
	for(count=1;count<=i;count++)
	{
		head=head->next;
	}
	if(count<=i)
	{
		printf("the length < i");
		return 0;
	}
	else
		return head->element;
}
int priorelement(link *head,int prior)/*if define link have length will be better*/
{
	int i;
	for(i=1;i<prior;i++)
	{
		head=head->next;
	}
	if(i<prior)
	{
		printf("the length < the assign number!!");
		return 0;
	}
	else
	{
		return head->element;
	}
}
int nextelement(link *head,int next)/*if define link have length will be better!!*/
{
	int i;
	for(i=1;i<=next+1;i++)
	{
		head=head->next;
	}
}
void listinsert(link *head,int i,link *u)
{
	int count;
	link *p;
	link *q;
	p=head;
	for(count=1;count<=i;count++)
	{
		q=p;
		p=p->next;
	}
	q->next=u;
	u->next=p;
}
void listdelect(link *head,int i)
{
	int count;
	link *p;
	link *q;
	p=head;
	for(count=0;count<i;count++)
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	free(p);
}
void creat1(link *head,int number)
{
	int count;
	link *q;
	link *p;
	p=head;
	for(count=0;count<number;count++)
	{
		if(count==0)
		{
			head=p=q=(link *)malloc(sizeof(link));
		}
		else
		{
			p=(link *)malloc(sizeof(link));
			q->next=p;
			q=p;
		}
	}
	p->next=NULL;
}
void create2(link *head,int number)
{
	int count;
	link *p;
	head=NULL;
	for(count=0;count<number;count++)
	{
		p=(link *)malloc(sizeof(link));
		p->next=head;
		head=p;
	}
}
main()
{}