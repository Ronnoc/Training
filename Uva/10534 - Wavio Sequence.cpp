#include<stdio.h>
int a[10010],aa[10010];
int qb[10010],qc[10010],res[10010];
int n;
int min(int a,int b){if(a>b)return b;return a;}
int half(int x,int p,int q,int *a)
{
	int i;
//	printf("入栈half(%d,%d,%d):\n\t",x,p,q);
//	for(i=p;i<=q;i++)printf("%d ",a[i]);printf("\n");
	if(p==q)		//1,2,4-->1,2,3
	{
		if(p==1&&x<a[p])a[p]=x;
		else if(p>=2&&a[p-1]<x&&a[p]>x)a[p]=x;
		}
	else if(p+1==q)	//2,5-->1,5 or 2,3
	{
		if(a[p]<x&&a[q]>x)a[q]=x;
		else half(x,p,p,a);
		}
	else if(p+1<q)	//1,2,4,5-->1,2,3,5
	{
		int s=(p+q)/2;
		if(a[s]<x)half(x,s+1,q,a);
		else half(x,p,s,a);
		}
//	printf("出栈half(%d,%d,%d):\n\t",x,p,q);
//	for(i=p;i<=q;i++)printf("%d ",a[i]);printf("\n");
	}
int LIS(int *a,int na,int *res)
{
	int x[10010];
	x[1]=a[1];
	int px=1;
	int i;
	res[1]=1;
//	printf("a[1]=%d未调用half\n",a[1]);
	for(i=2;i<=na;i++)
	{
		if(a[i]>x[px])
		{
			res[i]=res[i-1]+1;
			px++;
			x[px]=a[i]; 
//			printf("a[%d]=%d未调用half\n",i,a[i]);
			}
		else 
		{
//			printf("a[%d]=%d调用half\n",i,a[i]);
			half(a[i],1,px,x);
			res[i]=res[i-1];
			}
		}
	}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			aa[n+1-i]=a[i];
			}
		LIS(a,n,qb);
		LIS(aa,n,qc);
		for(i=1;i<=n;i++)res[i]=min(qb[i],qc[n+1-i]);
		int s=res[1];
		for(i=2;i<=n;i++)if(s<res[i])s=res[i];
		printf("%d\n",2*s-1);
		}
	return 0;
	}
