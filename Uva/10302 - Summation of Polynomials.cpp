#include<stdio.h>
long long dp[50010];
int main()
{
	long long i;dp[1]=1;
	for(i=2;i<=50000;i++)dp[i]=dp[i-1]+i*i*i;
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%lld\n",dp[n]);
		}
	return 0;	
	}
