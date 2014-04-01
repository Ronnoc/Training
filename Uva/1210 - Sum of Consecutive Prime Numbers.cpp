#include<stdio.h>
bool is_prime(int x)
{
	int i;
	if(x==1)return false; 
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)return false;
		}
	return true;
	}
int main()
{
	int dp[10010];
	int prime[4000];
	int i,mon=1,j;
	for(i=1;i<=10000;i++)
	{
		dp[i]=0;
		if(is_prime(i))prime[mon++]=i;
		}
	mon--;
	int k;
	for(i=1;i<=mon;i++)
	{
		for(j=i;j<=mon;j++)
		{
			int sum=0;
			for(k=i;k<=j;k++)sum+=prime[k];
			if(sum<=10000)dp[sum]++;
			}
		}
	int n;
	while(scanf("%d",&n)==1 && n!=0)
	{
		printf("%d\n",dp[n]);
		}
	return 0;
	}
