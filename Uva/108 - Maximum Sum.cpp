#include<stdio.h>
#define max(a,b) a>b?a:b
	int dp[110][110][110][110];
	int map[110][110];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,p,q;
	//	for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(p=1;p<=n;p++)for(q=1;q<=n;q++)dp[i][j][p][q]=0;
		for(i=1;i<=n;i++)for(j=1;j<=n;j++){scanf("%d",&map[i][j]);dp[i][j][i][j]=map[i][j];}
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(q=j+1;q<=n;q++)dp[i][j][i][q]=dp[i][j][i][q-1]+map[i][q];
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(p=i+1;p<=n;p++)dp[i][j][p][j]=dp[i][j][p-1][j]+map[p][j];
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)for(p=i+1;p<=n;p++)for(q=j+1;q<=n;q++)
		{
		//	printf("%d %d %d %d\n",i,j,p,q);
			dp[i][j][p][q]=dp[i][j][p][q-1]+dp[i][q][p][q];
			}
		int res=dp[1][1][1][1];
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)
		for(p=i;p<=n;p++)for(q=j;q<=n;q++)res=max(res,dp[i][j][p][q]);
		printf("%d\n",res);
		}
	return 0;
	}
