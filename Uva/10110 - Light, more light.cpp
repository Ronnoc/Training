#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		if(n==0)break;
		if (floor(sqrt(n))==ceil(sqrt(n)))printf("yes\n");
		else printf("no\n");
		} 
	return 0;} 
