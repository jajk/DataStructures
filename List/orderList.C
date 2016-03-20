#include<stdio.h>
//线性表存储空间的初始分配量
#define max 100 
//线性表存储空间的分配增量
#define increment 10 
typedef struct link
{
	//存储空间基址
	int *base; 
	//当前长度
	int length; 
	//当前分配的存储容量
	int sum_length; 
}link;
//初始化顺序表k
void inital(link *k)
{
	k->base=(int *)malloc(max*sizeof(int));
	k->length=0;
	k->sum_length=100;
}
//重置并清空顺序表k
void destroy(link *k)
{
	free(k->base);
	k->length=0;
	k->sum_length=0;
}
//判断顺序表是否为空
int listempty(link *k)
{
	if(k->length==0)
	    return 1;
	else
	    return 0;
}
//返回顺序表的当前长度
int listlength(link k)
{
	return k.length;
}
//得到指定元素
int getelem(link k,int i)
{
	if(i>k.length)
	{
		printf("exceed!!");
		exit(0);
	}
	else {
		return k.base[i-1];
	}
}
int priorelem(link k,int prior)
{
	if(prior==1)
	{
		printf("No prior :because prior=1");
		return 0;
	}
	else if(prior>k.length)
	{
		printf("exceed!!");
		return 0;
	}
	else
		return k.base[prior-2];
}
int nextelem(link k,int next)
{
	if(next==k.length)
	{
		printf("NO next elem:because next=length!");
		return 0;
	}
	else if(next>k.length)
	{
		printf("exceed!!");
		exit(0);
	}
	else
	{
		return k.base[next];
	}
}
void listInsert(link *k,int i,int element)
{
	int *newbase;
	int n;
	if(listempty(k)==0)
	{
		if(k->length>=k->sum_length)
		{
			newbase=(int *)realloc(k->base,(k->sum_length+increment)*sizeof(int));
			if(newbase!=NULL)
			{
				k->base=newbase;
				k->sum_length+=increment;
			}
			else
			{
				printf("No the most space!!");
				exit(0);
			}
		}
		for(i=k->length-1;i>=n;i--)
		{
			k->base[i+1]=k->base[i];
		}
		k->base[i]=element;
		k->length+=1;
	}
	else
	{
		k->base[0]=element;
		k->length=1;
	}
}
void  listdelect(link *k,int n)
{
	int i;
	if(listempty(k))
	{
		printf("the link is empty!!");
		return ;
	}
	else
	{
		for(i=n-1;i<k->length;i++)
		{
			k->base[i]=k->base[i+1];
		}
		k->length-=1;
	}
}
main()
{}
