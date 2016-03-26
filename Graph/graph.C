#include<stdio.h>
#include<string.h>
#define INFI 500
#define MAX 100 /*assume MAX is infinite,using at MIT_prime*/
#define INCREMENT 10 /*using at stack about in case of the space no enough*/
int figure[20];/*using at DFS trave*/
typedef struct/*using critical ve which is the vertex's long path*/
{
	int *base;
}v;
typedef struct sub_node/*using the create link list as the sub node*/
{
	int num;
	int weith;
	char *info;
	struct sub_node *next;
}Sub_node;
typedef struct/*using the create link list as the node*/
{
	char* name;
	Sub_node *next;
}Node;
typedef struct Graph
{
	Node *base;
	int vertex;
	int arc;
	char *kind;
}Graph;
typedef struct V_sign/*using at MIN_prime to deal with the side of min*/
{
	char* name;
	int cost;
}V_sign;
typedef struct Stack
{
	int *base;
	int *top;
	int length;
}Stack;
typedef struct Path/*remenber path at Dijkstra*/
{
	int sign;/*judge the vertex whether involving*/
	int distance;/*the origin go to the vertex's distance*/
	int path[INCREMENT];/*deposit the vertex of num*/
}Path;
void initial_S(Stack *s)
{
	s->base=(int *)malloc(20*sizeof(int));
	s->top=s->base;
	s->length=20;
}
void push(Stack *s,int num)
{
	if(s->top-s->base>=(s->length-1))
	{
		s->base=(int *)realloc(s->base,(INCREMENT+s->length)*sizeof(int));
		if(!s->base)
		{
			printf("the space is no enough");
			exit(0);
		}
		s->length+=INCREMENT;
	}
	*s->top++=num;
}
int pop(Stack *s)
{
	if(s->base==s->top)
	{
		printf("s.base=s.top,so this opration is wrong!\n");
		return -1;
	}
	return *--s->top;
}
int stackEmpty(Stack *s)
{
	if(s->base==s->top)
		return 1;
	return 0;
}
Graph initial_G()/*check over*/
{
	Graph g;
	Node *p;
	int number;/*use at for*/
	printf("Please input you want how many vertex and arc:\n");
	scanf("%d%d",&g.vertex,&g.arc);
	g.base=(Node*)malloc(g.vertex*sizeof(Node));
	printf("Please input these vertex:\n");
	p=g.base;
	for(number=0;number<g.vertex;number++)
	{
		scanf("%s",(p+number)->name);
		(p+number)->next=NULL;
	}
	printf("input the graph name:\n");
	scanf("%s",g.kind);
	return g;
}
void CreateLinkList(Graph *g)/*check over*/
{
	int count;
	int n;
	Sub_node *p;
	Node *fix=g->base;
	printf("input interact with the vertex and info step by step and ");
	printf("end the each vertex ,scanf n<0!\n\n");
	for(count=0;count<g->vertex;count++)
	{
		Node *q=fix+count;
		/*printf("count=%d\n",count);*/
		while(1)
		{
			printf("input the num of node interacting with %s:\n",q->name);
			scanf("%d",&n);
			if(n>=0)
			{
				p=(Sub_node *)malloc(sizeof(Sub_node));
				p->num=n;
				printf("the weith of node:\n");
				scanf("%d",&p->weith);
				printf("the info of node:\n");
				scanf("%s",p->info);
				p->next=q->next;
				q->next=p;
			}
			else
			{
				break;
			}
		}/*while*/
	}/*for*/
}
void D(Graph *g,int count)/*check over*/
{
	Node *p=g->base;
	Sub_node *q;
	figure[count]=1;
	printf("%s ",(p+count)->name);
	for(q=(p+count)->next;q;q=q->next)
	{
		if(!figure[q->num])
			D(g,q->num);
	}
}
void DFS(Graph *g)/*check over*/
{
	int count;
	for(count=0;count<g->vertex;count++)
	{
		figure[count]=0;
	}/*for*/
	for(count=0;count<g->vertex;count++)
	{
		if(!figure[count])
		D(g,count);
	}
}
int searchMin(V_sign *v,int num)/*check over*/
{
	int sign;
	int min=MAX;
	int count;
	for(count=1;count<num;count++)
	{
		if((v+count)->cost)
		{
			if(min>(v+count)->cost)
			{
				min=(v+count)->cost;
				sign=count;
			}/*if*/
		}/*if*/
	}/*for*/
	return sign;
}
void MIT_prime(Graph *g)/*check over*/
{
	V_sign *V;
	int count;
	int sub_count;
	int sign;
	Node *p=g->base;
	Sub_node *q;
	V=(V_sign*)malloc(g->vertex*sizeof(V_sign));
	(V+0)->cost=0;/*I take the first vertex to operation*/
	for(count=1;count<g->vertex;count++)/*initial v*/
	{
		(V+count)->cost=MAX;
	}
	for(q=(p+0)->next;q;q=q->next)/*first opration*/
	{
		(V+q->num)->cost=q->weith;
		(V+q->num)->name=p->name;
	}
	/*check the first opration*/
	/*for(count=1;count<g->vertex;count++)
	{
		printf("%s,%s  ",(V+count)->name,(p+count)->name);
	}*/
	printf("\n");
	for(count=1;count<g->vertex;count++)
	{
		sign=searchMin(V,g->vertex);
		printf("(%s,%s):%d  ",(V+sign)->name,(p+sign)->name,(V+sign)->cost);
		(V+sign)->cost=0;
		for(q=(p+sign)->next;q;q=q->next)
		{
			if(q->weith<(V+q->num)->cost)
			{
				(V+q->num)->cost=q->weith;
				(V+q->num)->name=(p+sign)->name;
			}
		}/*for*/
	}/*for*/
}
void getDegree(Graph *g,int *d)/*check over*/
{
	int count;
	Node *p=g->base;
	Sub_node *q;
	for(count=0;count<g->vertex;count++)
	{
		for(q=(p+count)->next;q;q=q->next)
		{
			d[q->num]++;
			}/*for*/
	}/*for*/
}
int topol(Graph *g,Stack *t,v *ve)/*check over*/
{
	int *degree;
	int count;
	int sign=0;
	int *ve_base;
	Stack u;
	Node *p=g->base;
	Sub_node *q;
	initial_S(&u);
	ve->base=(int *)malloc(g->vertex*sizeof(int));
	degree=(int *)malloc(g->vertex*sizeof(int));
	for(count=0;count<g->vertex;count++)/*initial the degree*/
	{
		degree[count]=0;
	}
	getDegree(g,degree);
	ve_base=ve->base;
	for(count=0;count<g->vertex;count++)/*initial the ve of min path about each vertex*/
	{
		ve_base[count]=0;
	}
	for(count=0;count<g->vertex;count++)
	{
		if(degree[count]==0)
		push(&u,count);
	}/*for*/
	while(!stackEmpty(&u))
	{
		int k=pop(&u);
		push(t,k);
		sign++;
		for(q=(p+k)->next;q;q=q->next)
		{
			if(!--degree[q->num])
				push(&u,q->num);
			if(ve_base[q->num]<ve_base[k]+q->weith)
				ve_base[q->num]=ve_base[k]+q->weith;
		}/*for*/
	}/*while*/
	free(degree);
	if(sign<g->vertex)
	{
		printf("\nsign=%d\n",sign);
		return 0;
	}
	return 1;
}
void criticalPath(Graph *g)/*check over*/
{
	v ve;
	int *ve_base;
	int *vl;/*the long time of a item beginning*/
	int count;
	int e;
	int l;
	Stack t;
	Node *p=g->base;
	initial_S(&t);
	vl=(int *)malloc(g->vertex*sizeof(int));
	if(topol(g,&t,&ve))
	{
		int k;
		Sub_node *q;
		ve_base=ve.base;
		for(count=0;count<g->vertex;count++)/*initial the vl*/
		{
			vl[count]=ve_base[g->vertex-1];
		}
		while(!stackEmpty(&t))/*get answer the vl*/
		{
			k=pop(&t);
			for(q=(p+k)->next;q;q=q->next)
			{
				if(vl[q->num]-q->weith<vl[k])
				{
					vl[k]=vl[q->num]-q->weith;
				}/*if*/
			}/*for*/
		}/*while*/
	}/*if*/

	for(count=0;count<g->vertex;count++)/*print the important activity*/
	{
		Sub_node *q;
		for(q=(p+count)->next;q;q=q->next)
		{
			e=ve_base[count];
			l=vl[q->num]-q->weith;
			if(e==l)
				printf("%s ",q->info);
		}/*for*/
	}/*for*/
}
int serchMintoD(Path *p,int num)/*check over*/
{
	int count;
	int l;
	int min=INFI;
	for(count=0;count<num;count++)
	{
		if(p[count].sign==0&&p[count].distance<=min)
		{
			min=p[count].distance;
			l=count;
		}/*if*/
	}/*for*/
	return l;
}
void Dijkstra(Graph *g,int ver)/*check over*/
{
	Node *p=g->base;
	Path *path;
	Sub_node *q;
	int count;
	printf("\nthe dijkstra:\n");
	path=(Path *)malloc(g->vertex*sizeof(Path));
	for(count=0;count<g->vertex;count++)/*initial the path*/
	{
		int countr;
		path[count].distance=INFI;
		path[count].sign=0;
		for(countr=0;countr<INCREMENT;countr++)/*initial the path.path*/
		{
			path[count].path[countr]=-1;
		}/*end sub_for*/
	}/*end sub*/
	path[ver].sign=1;
	path[ver].distance=0;
	path[ver].path[0]=ver;

	for(q=(p+ver)->next;q;q=q->next)
	{
		path[q->num].path[0]=ver;
		path[q->num].path[1]=q->num;
		path[q->num].distance=q->weith;
	}/*for*/
	for(count=1;count<g->vertex;count++)
	{
		int o=0;/*using have no path*/
		int x;/*using print the path*/
		int i=0;/*using print the path*/
		int min=serchMintoD(path,g->vertex);
		path[min].sign=1;
		x=path[min].path[i];
		printf("%s to %s : ",(p+ver)->name,(p+min)->name);
		do/*print the path*/
		{
			x=path[min].path[i];
			if(x!=-1)
			{
				if(o)
					printf(" ->%s",(p+x)->name);
				else
					printf(" %s",(p+x)->name);
				o++;
			}
			else
				printf("NO PATH");
			i++;
		}while(path[min].path[i]!=-1);
		if(o)
			printf("\n    cost:%d \n\n",path[min].distance);
		else
			printf("\n    cost:endless\n\n");
		for(q=(p+min)->next;q;q=q->next)
		{
			if(q->weith+path[min].distance<path[q->num].distance)
			{
				int i=0;
				int x;
				path[q->num].distance=q->weith+path[min].distance;
				while((x=path[min].path[i])!=-1)
				{
					path[q->num].path[i++]=x;
				}
				path[q->num].path[i]=q->num;
				path[q->num].path[i+1]=-1;
			}/*if*/
		}/*for*/
	}/*for*/
	free(path);
}
void begin()
{
	printf("operation:\t");
	printf("content:\n\n");
	printf("        0:\t");
	printf("exit.\n");
	printf("        1:\t");
	printf("initial a graph.\n");
	printf("        2:\t");
	printf("create a link list.\n");
	printf("        3:\t");
	printf("travel the Graph.\n");
	printf("        4:\t");
	printf("the Graph Minimum spanning tree.\n");
	printf("        5:\t");
	printf("the Graph's critical path.\n");
	printf("        6:\t");
	printf("the Graph's single source shortest path.\n");
}
main()
{
	Graph g;
	int vertex;
	int operation;
	system("cls");
	begin();
	do
	{
		printf("\n\nPlease input the step:\n");
		scanf("%d",&operation);
		switch(operation)
		{
			case 1:{
					g=initial_G();
					printf("initial the graph successfully!\n");
					}
					break;
			case 2:{
					CreateLinkList(&g);
					printf("Create Link List successfully!\n");
					}
					break;
			case 3:{
					printf("the Graph's travel:\n");
					DFS(&g);
					}
					break;
			case 4:{
					printf("the Graph's Minimum spanning tree:\n");
					MIT_prime(&g);
					}
					break;
			case 5:{
					printf("the Graph's critical path :\n");
					criticalPath(&g);
					}
					break;
			case 6:{
					printf("input you want from what vertex to every one\n");
					scanf("%d",&vertex);
					printf("the Graph's single soure shortest path\n");
					Dijkstra(&g,vertex);
					}break;
			default:
					{
					system("pause");
					operation=0;
					}
		}
	}while(operation);
}