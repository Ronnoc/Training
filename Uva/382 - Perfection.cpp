#include<stdio.h>
short a[60010];
int main()
{
	int i,j;
	for(i=1;i<=60000;i++)
	{
		int sum=1;
		for(j=2;j*j<=i;j++)
		{
			if(i%j==0){sum+=j;if(j!=i/j)sum+=i/j;} 
			}
		if(sum==i)a[i]=0;
		else if(sum>i)a[i]=1;
		else a[i]=-1;
		}
	a[1]=-1;
	int n;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		if(a[n]==0)printf("%5d  PERFECT\n",n);
		if(a[n]==-1)printf("%5d  DEFICIENT\n",n);
		if(a[n]==1)printf("%5d  ABUNDANT\n",n);
		}
	printf("END OF OUTPUT\n");
	return 0;
	} 
