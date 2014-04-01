#include<stdio.h>
#define max(a,b) a>b?a:b
long long dp[30][30];
int main()
{
	int n;
	int k=1;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		int a[30];
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)for(j=i-1;j<=n;j++)dp[i][j]=1;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				dp[i][j]=dp[i][j-1]*a[j];
				}
			}
		long long res=0;
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)res=max(res,dp[i][j]);
			}
		printf("Case #%d: The maximum product is %lld.\n\n",k,res);
		k++;
		}
	return 0;
	}
