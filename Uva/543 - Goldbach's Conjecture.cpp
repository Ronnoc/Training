#include<stdio.h>
bool p[1000010]={0};
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
	for(i=1;i<=1000000;i++)p[i]=is_prime(i);
	int n;
	while(scanf("%d",&n)==1 && n)
	{
		for(i=1;2*i<=n;i++)
		{
			if(p[i] && p[n-i])break;
			}
		printf("%d = %d + %d\n",n,i,n-i);
		}
	return 0;
	}
