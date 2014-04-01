#include<stdio.h>
int dp[110][110];
int f(int n,int k)
{
//	printf("\n调用f(%d,%d)",n,k);
	int res=0;
	if(dp[n][k]>0){/*printf("原有%d\n",dp[n][k]);*/return dp[n][k];}
	if(n==0)res=1;
	else if(n==1)res=k;
	else if(k==1)res=1;
//	else if(k==2)res=n+1;
	else if(k>=2)
	{
		int i;
		int sum=0;
		for(i=0;i<=n;i++)
		{
			sum+=f(n-i,k-1);
			sum%=1000000;
			}
		res=sum;
		}
	dp[n][k]=res;
//	printf("结果");printf("%d\n",res);
	return res;
	}
int main()
{
	int n,k;
	int i,j;
	for(i=0;i<=100;i++)for(j=0;j<=100;j++)dp[i][j]=0;
	for(k=1;k<=100;k++)
	{
		for(n=1;n<=100;n++)
		{
			f(n,k);
		//	printf("n=%d,k=%d,dp(n,k)=%d\n",n,k,dp[n][k]);
			}
		}
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		if(n==0&&k==0)break;
		printf("%d\n",dp[n][k]);
		}
	return 0;
	}
