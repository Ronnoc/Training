#include<stdio.h>
#include<math.h>
int main()
{
	long long a,b,c,d,l;
	while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&l)!=EOF)
	{
		if(a==0 && b==0 && c==0 && d==0 && l==0)break;
		long long i,count=0;
		for(i=0;i<=l;i++)
		{
			if(fmod(a*i*i+b*i+c,d)==0)count++;
			}
		printf("%lld\n",count);
		}
	return 0;
	} 
