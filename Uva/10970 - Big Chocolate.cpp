#include<stdio.h>
int min(int a,int b)
{if(a>b)return b;return a;}
int main()
{
	int dp[310][310];
	int i;
	for(i=1;i<=300;i++){dp[i][1]=i-1;dp[1][i]=i-1;}
	int j,s;
	for(i=2;i<=300;i++)
	{
		for(j=2;j<=300;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[1][j]+1;
			for(s=1;s<i;s++)dp[i][j]=min(dp[i][j],dp[s][j]+dp[i-s][j]+1);
			for(s=1;s<j;s++)dp[i][j]=min(dp[i][j],dp[i][s]+dp[i][j-s]+1);
			}
		}
	int m,n;
	while(scanf("%d%d",&m,&n)==2)
	{
		printf("%d\n",dp[m][n]);
		}
	return 0;
	} 
