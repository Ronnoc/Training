#include<stdio.h>
int a[100010];
int f(int x,int y)
{
	return a[x+y]+x;
	}
int main()
{
	a[0]=0;int i;
	for(i=1;i<=100000;i++)a[i]=a[i-1]+i;
	int x1,x2,y1,y2;int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("Case %d: %d\n",x,f(x2,y2)-f(x1,y1));
		}
	return 0;
	}
