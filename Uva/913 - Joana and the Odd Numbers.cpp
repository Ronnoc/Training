#include<stdio.h>
int main()
{
	unsigned long long n,m;
	while(scanf("%lld",&n)==1)
	{
		m=(n+1)*(n+1)*3/2-9;
		printf("%llu\n",m);
		}
	return 0;
	}
