#include<stdio.h>
#include<string.h>
int dp[110][110];
int main()
{
	int count=1;
	char a[110],b[110];
	while(gets(a))
	{
		if(a[0]=='#')break;
		gets(b);
		int j,i,sa=strlen(a),sb=strlen(b);
		for(i=0;i<=110;i++)dp[0][i]=0;
		for(i=0;i<=110;i++)dp[i][0]=0;
		for(i=1;i<=sa;i++)for(j=1;j<=sb;j++)
		{
			if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else if(dp[i-1][j]>=dp[i][j-1])dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i][j-1];
			}
		printf("Case #%d: you can visit at most %d cities.\n",count++,dp[sa][sb]);
		}
	return 0;
	}
