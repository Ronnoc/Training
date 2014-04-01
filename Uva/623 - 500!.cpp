#include<stdio.h>
int dp[1010][2610];
int main()
{
	int i,j;
	for(i=1;i<=1000;i++)for(j=1;j<=2600;j++)dp[i][j]=0;
	dp[1][1]=1;
	dp[0][1]=1;
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=2600;j++)dp[i][j]=dp[i-1][j]*i;
		for(j=1;j<=2600;j++)
		{
			dp[i][j+1]+=dp[i][j]/10;
			dp[i][j]%=10; 
			}
		}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d!\n",n);
		int len;
		for(len=2600;len>=1;len--)
		{
			if(dp[n][len]!=0)break;
			}
		for(i=len;i>=1;i--)printf("%d",dp[n][i]);printf("\n");
		}
	return 0;
	}
