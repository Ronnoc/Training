#include<stdio.h>
#include<math.h>
int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		long long xie;
		for(xie=sqrt(2*n)-1;;xie++){if(n<=xie*(xie+1)/2)break;}
		long long x,y,i;
		x=xie,y=1;
		long long cz=n-1-(xie*(xie-1)/2);
		x-=cz;y+=cz;
		printf("%lld/%lld\n",x,y);
		}
	return 0;
	}
