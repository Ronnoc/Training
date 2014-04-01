#include<stdio.h>
long long pow(long long k)
{
	long long res=1;
	for(int i=1;i<=k;i++)res*=2;
	return res;
	}
int main()
{
	int z,x;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		long long n,s;
		scanf("%lld%lld",&n,&s);
		long long k=0,r=s,count=0;
		while(s%2==0 && ++count<=n)
		{
			s/=2;k++;
			}
		long long max=1+pow(n)-pow(k);
		long long min=1;s=r;
		while(1)
		{
			if(n==0)break; 
			--n;
			if(s>=pow(n)){min++;s-=pow(n);}
			}
		printf("%lld %lld\n",min,max);
		}
	return 0;
	}
