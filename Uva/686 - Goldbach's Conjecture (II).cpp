#include<stdio.h>
bool p[33000]={0};
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
	int i;
	for(i=1;i<=33000;i++)p[i]=is_prime(i);
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		int count=0;
		for(i=1;2*i<=n;i++)
		{
			if(p[i] && p[n-i])count++;
			}
		printf("%d\n",count);
		}
	return 0;
	}
