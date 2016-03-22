#include<stdio.h>
#include<stdlib.h>
//构建链表数据结构
typedef struct link
{
	struct link *next;
	int element;
	int length;
}link;
//清空并重置链表
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
//判断链表是否为空，为空返回1，否则返回0
int listempty(link *k)
{
	if(k==NULL)
		return 1;
	else
		return 0;
}
//返回链表的长度
int listlength(link *head)
{
	return head->length;
}
//得到指定位置的元素
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
//得到指定元素的前一个元素
int priorelement(link *head,int prior)
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
//得到指定元素的后一个元素
int nextelement(link *head,int next)
{
	int i;
	for(i=1;i<=next+1;i++)
	{
		head=head->next;
	}
}
//在指定位置插入链表元素
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
//删除指定位置的元素
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
//创建一个指定多少个元素的链表
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
//创建一个指定多少个元素的链表
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
