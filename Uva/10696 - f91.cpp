#include<stdio.h>
int dp[110];
int f(int n)
{
	if(n<=100)return f(f(n+11));
	return n-10;
	}
int main()
{
	int n;
	int i;
	for(i=1;i<=100;i++)dp[i]=f(i);
	while(scanf("%d",&n)==1)
	{
		if(n==0)break;
		int out;
		if(n>=101)out=n-10;
		else out=dp[n];
		printf("f91(%d) = %d\n",n,out);
		}
	return 0;
	}
