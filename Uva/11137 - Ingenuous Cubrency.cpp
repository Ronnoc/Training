#include<stdio.h>
int main()
{
	long long dp[22][10010];
	long long money[22];
	int i;
	for(i=1;i<=21;i++)
	{
		money[i]=i*i*i;
		dp[i][0]=1;
		dp[i][1]=1;
		}
	int k;
	for(i=1;i<=10000;i++)dp[1][i]=dp[1][i-1];
	for(k=2;k<=21;k++)
	{
		for(i=1;i<=10000;i++)
		{
			dp[k][i]=dp[k-1][i];
			if(i>=money[k])dp[k][i]+=dp[k][i-money[k]];
			}
		}
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%lld\n",dp[21][n]);
		}
	return 0;
	}
