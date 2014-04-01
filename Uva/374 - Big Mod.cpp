#include<stdio.h>
long long cd(long long a,long long b)
{
	if(a==1) return 1;
	if(b==1) return 1;
	if(a>b) return cd(b,a-b);
	else if(a==b) return a;
	else return cd(a,b-a); 
	}
int f(long long m)
{
	long long i;int res=0;
	for(i=1;i<m;i++)
	{
		if(cd(i,m)==1)res++;
		}
	return res;
	}
int main()
{
	long long b,p,m;
	while(scanf("%lld%lld%lld",&b,&p,&m)==3)
	{
		long long res=1;
		int i;
		int z=f(m);int flag=0;
		for(i=1;i<=z;i++){res*=b;res%=m;}
		if(res==1)flag=1;
		res=1;
		if(flag)while(1)
			{
				if(z!=0 && p>z)p-=z;
				else break;
				}
		b%=m;
		while(p>=2)
		{
			if(p%2==1)res*=b;
			p/=2;
			b*=b;
			b%=m;
			res%=m;
			}
		for(i=1;i<=p;i++)
		{
			res*=b;
			res%=m;	
			}
		res%=m; 
		printf("%lld\n",res);
		}
	return 0;
	} 
 	
