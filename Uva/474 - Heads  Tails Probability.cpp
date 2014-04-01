#include<stdio.h>
double dp[1000010];
int ddp[1000010];
int main()
{
	double s=1;
	int n;
	int i;int k;
	dp[0]=1;ddp[0]=0;
	for(i=1;i<=1000000;i++)
	{
		dp[i]=dp[i-1]*5;
		k=i-1-ddp[i-1];
		while(dp[i]>=10){dp[i]/=10;k++;}
		ddp[i]=i-k;
		}
	while(scanf("%d",&n)==1)
	{
		printf("2^-%d = ",n);
		printf("%.3lfe-%d\n",dp[n],ddp[n]);
		}
	return 0;
	} 
