#include<stdio.h>
int max(int a,int b)
{
	if(a>b)return a;return b;
	}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int s[30];
	for(i=1;i<=n;i++)scanf("%d",&s[i]);
	int std[30];
	for(i=1;i<=n;i++)
	{
		std[s[i]]=i;
		}
	int c[30],ck[30];
	while(scanf("%d",&c[1])!=EOF)
	{
		for(i=2;i<=n;i++)scanf("%d",&c[i]);
		for(i=1;i<=n;i++)ck[c[i]]=i;
		int dp[30][30];
		int j;
		for(i=0;i<=n;i++)for(j=0;j<=n;j++)dp[i][j]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(std[i]==ck[j])dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		printf("%d\n",dp[n][n]);
		}
	return 0;}
