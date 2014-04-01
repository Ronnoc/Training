#include<stdio.h>
#include<math.h>
int main()
{
	double m,n;
	while(scanf("%lf%lf",&n,&m)==2 && !(m==0 && n==0))
	{
		printf("%.0lf things taken %.0lf at a time is ",n,m); 
		double s;
		if(m>n-m)s=m;
		else s=n-m;
		double i,c=1;
		for(i=s+1;i<=n;i++)c*=i;
		for(i=1;i<=n-s;i++)c/=i;
		printf("%.0lf exactly.\n",round(c));
		}
	return 0;
	}
