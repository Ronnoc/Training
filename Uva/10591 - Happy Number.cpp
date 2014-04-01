#include<stdio.h>
int h(int x)
{
	int i,a[20],sum=0;
	for(i=1;i<=10;i++)
	{
		a[i]=x%10;
		sum+=a[i]*a[i];
		x/=10;
		}
	return sum;
	}
int main()
{
	int dp[800];
	bool dd[800];
	int i;
	for(i=1;i<=730;i++){dd[i]=0;}
	for(i=1;i<=730;i++)
	{
		int q=i;
		if(h(i)<i)dp[i]=dp[h(i)]; 
		else
		{
			while(!(h(q)==1||h(q)==i||h(q)==4))
			{
				q=h(q);
				}
			if(h(q)==1)dp[i]=1;else dp[i]=0;
			}
		}
	int n;
	int z,k;
	scanf("%d",&z);
	for(k=1;k<=z;k++)
	{
		scanf("%d",&n);
		if(dp[h(n)])printf("Case #%d: %d is a Happy number.\n",k,n);
		else printf("Case #%d: %d is an Unhappy number.\n",k,n);
		}
	return 0;
	}
