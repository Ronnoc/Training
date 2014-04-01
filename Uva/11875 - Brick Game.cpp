#include<stdio.h>
#include<stdlib.h>
int cmp(const void *_a,const void *_b)
{
	int *a=(int *)_a;
	int *b=(int *)_b;
	return *a-*b;
	}
int main()
{
	int i,k;
	scanf("%d",&k);
	for(i=1;i<=k;i++)
	{
		int a[200],b[200];
		int s,j;
		scanf("%d",&s);
		for(j=1;j<=s;j++)scanf("%d",&a[j]);
		qsort(&a[1],s,sizeof(int),cmp);
		int k=(s+1)/2;
		printf("Case %d: %d\n",i,a[k]);
		}
	return 0;
	} 
