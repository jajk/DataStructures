#include<stdio.h>
typedef struct array
{
	int *base;
	int dim;
	int *bounds;
	int *constants;
}array;
int initalArray(array *a,int dim,int d[])
{
	int i;
	if(dim!=0)
		a->dim=dim;
	else
		return 0;
	a->bounds=(int *)malloc(dim*sizeof(int));
	for(i=0;i<dim;i++)
	{
		a->bounds[i]=d[i];
		printf("bounds[%d]=%d",i,a->bounds[i]);
	}
	a->constants=(int *)malloc(dim*sizeof(int));
	a->constants[dim-1]=a->bounds[dim-1];
	printf("constants[%d]=%d\n",dim-1,a->constants[dim-1]);
	for(i=dim-2;i>=0;i--)
	{
		a->constants[i]=a->constants[i+1]*a->bounds[i];
		printf("constants[%d]=%d\n",i,a->constants[i]);
	}
	printf("constant[0]=%d\n",a->constants[0]);
	a->base=(int *)malloc(a->constants[0]*sizeof(int));
	return 1;
}
int value(array a,int n[])
{
	int dim=a.dim;
	int i;
	int total=n[dim-1];
	for(i=dim-2;i>=0;i--)
	{
		if(n[i]<=(a.bounds[i]))
			total+=a.constants[i+1]*n[i];
		else
		{
			printf("%d bound already go",i);
			return 0;
		}
	}
	return *(a.base+total);
}
void put_value(array *a)
{
	int total=a->constants[0];
	int i;
	for(i=0;i<total;i++)
	{
		printf("please input a number:\n");
		scanf("%d",a->base+i);
	}
	printf("scanf over!!");
}
main()
{
	array a;
	int b[]={2,3};
	int m;
	system("cls");
	printf("hello\n");
	m=initalArray(&a,2,b);
	if(m==1)
	put_value(&a);
}
