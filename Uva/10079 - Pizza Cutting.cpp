#include<stdio.h>
int main()
{
	long long b;
	while(scanf("%lld",&b)!=EOF)
	{
		if(b<0)break;
		unsigned long long a=b;
		printf("%llu\n",(a+1)*a/2+1);
		}
	return 0;
	}
