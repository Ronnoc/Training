#include<stdio.h>
int f(long long a,long long b)
{
	if(a==1)return 1;
	long long s;
	if(a%2==0)s=a/2;
	else s=3*a+1;
	if(s>b)return 1; 
	else return 1+f(s,b);
	}
int main()
{
	long long a,b;int ca=1;
	while(scanf("%lld %lld",&a,&b)==2 && !(a==-1,b==-1))
	{
		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n",ca++,a,b,f(a,b));
		}
	return 0;
	} 
