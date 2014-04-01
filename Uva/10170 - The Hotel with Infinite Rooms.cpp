#include<stdio.h>
int main()
{
	long long s,d;
	while(scanf("%lld%lld",&s,&d)!=EOF)
	{
		long long i;i=0;
		while(1)
		{
			if( (i+1)*i/2+(i+1)*s >=(double)d)break;
			i++;
			}
		printf("%lld\n",s+i);
		}
	return 0;
	} 
