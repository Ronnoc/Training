#include<stdio.h>
#include<math.h>
int main()
{
	int i;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		unsigned long long s;
		scanf("%llu",&s);
		printf("%llu\n",(unsigned long long)((-1+sqrt(1+8*s))/2.0));
		}
	return 0;
	}
