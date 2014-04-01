#include<stdio.h>
#include<stdlib.h>
int cmp(const void *aa,const void *bb)
{
	int *a=(int *)aa;
	int *b=(int *)bb;
	return *a-*b;
	}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int n;
		scanf("%d",&n);
		int a[130],i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		qsort(&a[1],n,sizeof(int),cmp);
		//for(i=1;i<=n;i++)printf("%d ",a[i]);
		printf("%d\n",(a[n]-a[1])*2);
		}
	return 0;
	}
