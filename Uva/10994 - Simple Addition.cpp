#include<stdio.h>
#include<math.h>
long long f(long long s)
{
	while(1)
	{
		if(s==0)return 0;
		if(fmod(s,10)==0)s/=10;
		else return s%10; 
		}
	}
int main()
{
	long long p,q,i,sum;
	while(scanf("%lld%lld",&p,&q)==2)
	{
		if(p<0 && q<0)break;
		sum=0;
		while(q-p>100000000){sum+=499999995+f(q-fmod(q,100000000));q-=100000000;}
		while(q-p>10000000){sum+=49999995+f(q-fmod(q,10000000));q-=10000000;}
		while(q-p>1000000){sum+=4999995+f(q-fmod(q,1000000));q-=1000000;}
		while(q-p>100000){sum+=499995+f(q-fmod(q,100000));q-=100000;}
		while(q-p>10000){sum+=49995+f(q-fmod(q,10000));q-=10000;}
		while(q-p>1000){sum+=4995+f(q-fmod(q,1000));q-=1000;}
		while(q-p>100){sum+=495+f(q-fmod(q,100));q-=100;}
		while(q-p>10){sum+=45+f(q-fmod(q,10));q-=10;}
		for(i=p;i<=q;i++)sum+=f(i);
		printf("%lld\n",sum);
		} 
	return 0;
	}
