#include<stdio.h>
#include<string.h>
int dp[1010][1010];
int max(int a,int b)
{
	if(a>b)return a;
	return b;
	}
int main()
{
	char a[1010],b[1010];
	while(gets(a))
	{
		gets(b);
		int m=strlen(a),n=strlen(b);
		int i,j;
		for(i=0;i<=m;i++)for(j=1;j<=n;j++)dp[i][j]=0;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				int z=i-1,x=j-1;
				if(a[z]==b[x])
				{
					dp[i][j]=dp[z][x]+1;
					}
				else dp[i][j]=max(dp[z][j],dp[i][x]); 
				}
			}
		printf("%d\n",dp[m][n]);
		}
	return 0;
	}
