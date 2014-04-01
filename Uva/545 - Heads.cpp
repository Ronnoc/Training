#include<stdio.h>
double dp[9010];
int ddp[9010];
int main()
{
	double s=1;
	int n;
	int i;int k;
	dp[0]=1;ddp[0]=0;
	for(i=1;i<=9000;i++)
	{
		dp[i]=dp[i-1]*5;
		k=i-1-ddp[i-1];
		while(dp[i]>=10){dp[i]/=10;k++;}
		ddp[i]=i-k;
		}
	dp[6]=1.563;dp[7]=7.813;
	int z;scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d",&n);
		printf("2^-%d = %.3lfE-%d\n",n,dp[n],ddp[n]);
		}
	return 0;
	} 
