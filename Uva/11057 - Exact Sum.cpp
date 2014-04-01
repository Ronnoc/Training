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
	int a[10010];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		int aim;
		scanf("%d",&aim);
		qsort(&a[1],n,sizeof(int),cmp);
		int pb=1,pa=1;
		int b[10010];
		for(i=1;i<=n;i++)b[i]=aim-a[i];
		qsort(&b[1],n,sizeof(int),cmp);
		int ra[10010],rb[10010],cm[10010],p=0;
		while(pa<=n)
		{
			if(b[pb]<a[pa])pb++;
			if(b[pb]>a[pa])pa++;
			if(pa+pb==n+1)pa++;
			if(b[pb]==a[pa])
			{
				++p;
				ra[p]=a[pa];
				rb[p]=aim-b[pb];
				cm[p]=abs(ra[p]-rb[p]);
				pa++;
				}
			}
//		for(i=1;i<=p;i++)printf("%d ",ra[i]);printf("\n");
//		for(i=1;i<=p;i++)printf("%d ",rb[i]);printf("\n");
//		for(i=1;i<=p;i++)printf("%d ",cm[i]);printf("\n");
		qsort(&cm[1],p,sizeof(int),cmp);
		int x=(aim-cm[1])/2,y=(aim+cm[1])/2;
		printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
		}
	return 0;
	}
