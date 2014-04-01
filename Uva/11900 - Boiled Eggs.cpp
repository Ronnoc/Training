#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
int *z=(int *)a;int *x=(int *)b;
return *z-*x;
}
int min(int a,int b){if(a>b)return b;return a;}
int main()
{
	int k,z;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		int n,p,q,a[50],i;
		scanf("%d%d%d",&n,&p,&q);
		int sum=0,res=0;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		qsort(&a[1],n,sizeof(int),cmp);
//		for(i=1;i<=n;i++)printf("%4d",a[i]);printf("\n");
		for(i=1;i<=min(p,n);i++)
		{
			sum+=a[i];
		//	printf("%d\n",sum);
			if(sum>q){res=i-1;break;}
			else res=i;
			}
		printf("Case %d: %d\n",k,res);
		sum=0;
		}
	return 0;
	}
