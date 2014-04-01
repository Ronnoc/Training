#include<stdio.h>
int main()
{
	unsigned long long dp[6][30010];
	unsigned long long money[6]={0,1,5,10,25,50};
	int i;
	for(i=1;i<=5;i++)
	{
		dp[i][0]=1;
		dp[i][1]=1;
		}
	int k;
	for(i=1;i<=30000;i++)dp[1][i]=dp[1][i-1];
	for(k=2;k<=5;k++)
	{
		for(i=1;i<=30000;i++)
		{
			dp[k][i]=dp[k-1][i];
			if(i>=money[k])dp[k][i]+=dp[k][i-money[k]];
			}
		}
	int n;
	while(scanf("%d",&n)==1)
	{
		if(dp[5][n]!=1)
		{
		printf("There are %llu ways to produce",dp[5][n]);
		printf(" %d cents change.\n",n);
			}
		else printf("There is only 1 way to produce %d cents change.\n",n);
		}
	return 0;
	}
