#include<stdio.h>
int main()
{
	int a,h,b;
	int i;
	int town[10010],start=100000,end=0;
	for(i=0;i<=10000;i++)town[i]=0;
	while(scanf("%d%d%d",&a,&h,&b)!=EOF)
	{
		if(a<start)start=a;
		if(b>end)end=b; 
		for(i=a;i<=b-1;i++)if(town[i]<h)town[i]=h;	//记录a+0.5~b-0.5的高度	town[k]对应k.5的高度 
		}
	printf("%d %d",start,town[start]);h=town[start];
	for(i=start+1;i<=end;i++)
	{
		if(town[i]>h)printf(" %d %d",i,town[i]);
		else if(town[i]<h)printf(" %d %d",i,town[i]);
		h=town[i];
		}
	printf("\n");
	//printf(" %d %d\n",end,0);
	return 0;
	}
