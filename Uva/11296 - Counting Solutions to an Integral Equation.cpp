#include<stdio.h>
#include<time.h>
long long dp[1000010];
int main()
{
	int x,y,z;
	int i,j;
	int p[4];p[1]=1;p[2]=2;p[3]=2;
	for(i=0;i<=1000000;i++)dp[i]=0;
	dp[0]=1;dp[1]=1;
	for(j=1;j<=3;j++)
	{
		for(i=2;i<=1000000;i++)dp[i]+=dp[i-p[j]];
		}
	//printf("%.2lf",(double)clock()/CLOCKS_PER_SEC);
	int n;
	while(scanf("%d",&n)==1)
	{
		printf("%lld\n",dp[n]);
		}
	return 0;
	}
