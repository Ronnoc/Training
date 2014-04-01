#include<stdio.h>
#include<math.h>
int dp[1000010];
int main()
{
	int i;
	dp[0]=1;
	for(i=1;i<=1000000;i++)
	{
		dp[i]=0;
		dp[i]+=dp[(int)floor(i-sqrt(i)+0.00000001)];
		dp[i]+=dp[(int)floor( log(i)+0.00000001 )];
		dp[i]+=dp[(int)floor(i*sin(i)*sin(i)+0.00000001)];
		dp[i]=dp[i]%1000000;
		}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)break;
		printf("%d\n",dp[n]);
		}
	return 0;
	}
