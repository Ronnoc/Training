#include<stdio.h>
unsigned long long dp[60];
int main()
{
	int i;
	dp[1]=1;dp[2]=2;
	for(i=3;i<=50;i++)dp[i]=dp[i-1]+dp[i-2];
	int n;
	while(scanf("%d",&n)!=EOF&&n)printf("%llu\n",dp[n]);
	return 0;
	}
