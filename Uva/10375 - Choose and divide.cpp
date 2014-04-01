#include<stdio.h>
#include<math.h>
double max(double a,double b)
{
	if(a>b)return a;
	return b;
	}
double min(double a,double b)
{
	return a+b-max(a,b);
	}
int main()
{
	double r,s,p,q;
	while(scanf("%lf%lf%lf%lf",&p,&q,&r,&s)==4)
	{
		long double res,zi=0;
		double i;
		s=min(s,r-s);
		q=min(q,p-q);
		
		res=0;
		for(i=min(p,r)+1;i<=max(p,r);i++)res+=log(i);
		if(p>r)zi+=res;else zi-=res;
		
		res=0;
		for(i=min(r-s,p-q)+1;i<=max(r-s,p-q);i++)res+=log(i);
		if(r-s>p-q)zi+=res;else zi-=res;
		
		res=0;
		for(i=min(s,q)+1;i<=max(s,q);i++)res+=log(i);
		if(s>q)zi+=res;else zi-=res;
		
		printf("%.5lf\n",exp(zi));
		}
	return 0;
	}
