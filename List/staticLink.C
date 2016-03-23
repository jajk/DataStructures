#include<stdio.h>
#define max 100
typedef struct static_list
{
	int cur;
	int element;
}list;
void inital(list *l)
{
	int i;
	for(i=0;i<max-1;i++)
	{
		l[i].cur=i+1;
	}
	l[i].cur=0;
}
int malloc_list(list *l)
{
	int c;
	c=l[0].cur;
	if(c!=0)
	l[0].cur=l[c].cur;
	return c;
}
void free(list *l,int n)
{
	l[n].cur=l[0].cur;
	l[0].cur=n;
}
int create(list *l,int number)
{
	int count;
	int s;
	int head=0;
	for(count=0;count<number;count++)
	{
		s=malloc_list(l);
		if(s!=0)
		{
			printf("please input a number:\n");
			scanf("%d",&l[s].element);
			l[s].cur=head;
			head=s;
		}
		else
		{
			printf("the space no enough!!");
			exit(0);
		}
	}
	return head;
}
int create2(list *l,int number)
{
	int count;
	int n;
	int head;
	int p;
	for(count=0;count<number;count++)
	{
		n=malloc_list(l);
		if(n!=0)
		{
			printf("please input a number:\n");
			scanf("%d",&l[n].element);
			if(count==0)
			{
				head=p=n;
			}
			else
			{
				l[p].cur=n;
				p=n;
			}
		}
		else
		{
			printf("the space is lower!!");
			exit(0);
		}
	}
	l[p].cur=0;
	return head;
}
void print(list *l,int head)
{
	while(head!=0)
	{
		printf("%d\t",l[head].element);
		head=l[head].cur;
	}
}
main()
{
	list l[max];
	int head;
	inital(l);
	head=create2(l,3);
	print(l,head);
}

