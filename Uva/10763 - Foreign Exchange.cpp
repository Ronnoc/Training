#include<stdio.h>
#include<stdlib.h>
int a[500010],b[500010];
bool oa[500010],ob[500010];
int n;
int cmp(const void *a,const void *b)
{
	int *p=(int *)a;
	int *q=(int *)b;
	return *p-*q;
	}
bool hs(int x,int p,int q)
{
	printf("µ÷ÓÃhs(%d,%d,%d):\n",x,p,q);
	int j;
	for(j=1;j<=n;j++)
	{
		printf("\tj=%d,a[j]=%d,oa[j]=%d,b[j]=%d,ob[j]=%d\n",j,a[j],oa[j],b[j],ob[j]);
		} printf("\n");
	if(p==q)
	{
		if(oa[p])return true;
		oa[p]=1;
		if(!ob[p]&&x==b[p]){ob[p]=1;return true;}
		return false;
		}
	else if(p+1==q)
	{
		return hs(x,p,p)||hs(x,q,q);
		}
	else 
	{
		int t=(p+q)/2;
		if(b[t]>x)return hs(x,p,t);
		else return hs(x,t,q);
		}
	return false;
	}
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		int i,j;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			oa[i]=0;
			ob[i]=0;
			}
		qsort(&a[1],n,sizeof(int),cmp);
		qsort(&b[1],n,sizeof(int),cmp);
		int flag=1,l;
		/*
		for(i=1;i<=n;i++)
		{
			printf("i=%d:\n",i);
			for(j=1;j<=n;j++)
			{
				printf("\tj=%d,a[j]=%d,oa[j]=%d,b[j]=%d,ob[j]=%d\n",j,a[j],oa[j],b[j],ob[j]);
				}printf("\n");
			int e=hs(a[i],1,n);
			if(!e){flag=1;break;}
			}*/
		for(i=1;i<=n;i++)
		{
			if(a[i]!=b[i]){flag=0;break;}
			}
		if(n%2==0&&flag)printf("YES\n");
		else printf("NO\n");
		}
	return 0;}
