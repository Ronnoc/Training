#include<stdio.h>
#include<stdlib.h>
int abs(int y){if(y>0)return y;return -y;}
int cmp(const void *a,const void *b)
{
	int *p=(int *)a;
	int *q=(int *)b;
	return *p-*q;
	}
int main()
{
	int a[600];
	int n,k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++){
		scanf("%d",&n);
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		qsort(&a[1],n,sizeof(int),cmp);
		int s=(n+1)/2;
		int res=0;
		for(i=1;i<=n;i++)res+=abs(a[s]-a[i]);
		printf("%d\n",res);
		}
	return 0;
	}
