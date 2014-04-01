#include<stdio.h>
#include<math.h>
int main()
{
	long long m,x;
	while(scanf("%lld%lld",&m,&x)==2)
	{
		if(m==0 && x==0)break;
		if(x==100){printf("Not found\n");continue;}
		long long ans=(long long)(100.0*(m-1.0)/(100.0-x));
		if( (100*(m-1)) % (100-x) ==0)ans--;
		if(ans<m)printf("Not found\n");
		else printf("%lld\n",ans);
		}
	return 0;
	}
