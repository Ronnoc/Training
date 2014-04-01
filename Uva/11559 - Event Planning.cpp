#include<stdio.h>
#include<stdlib.h>
int cmp_int(const void *_a,const void *_b)
{
	int *a=(int *)_a;
	int *b=(int *)_b;
	return *a-*b;
	}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		{
		int budget;
		scanf("%d",&budget);
		int hotel,week,i,j;
		scanf("%d%d",&hotel,&week);
		int h[20][15];
		for(i=1;i<=hotel;i++)
		{
			for(j=0;j<=week;j++)scanf("%d",&h[i][j]);
			}
		int money[2000];j=1;
		for(i=1;i<=hotel;i++)
		{
			int s;
			for(s=1;s<=week;s++)
			{
			if(h[i][s]>=n)money[j++]=h[i][0]*n;
				}
			}
		j--;
	//	for(i=1;i<=j;i++)printf("%d\t",money[i]);printf("\n");
		qsort(&money[1],j,sizeof(int),cmp_int);
	//	for(i=1;i<=j;i++)printf("%d\t",money[i]);printf("\n");
		if(money[1]>budget || j==0)printf("stay home\n");
		else printf("%d\n",money[1]);
		for(i=1;i<=2000;i++)money[i]=0;
		}
	}
	return 0;
	} 
