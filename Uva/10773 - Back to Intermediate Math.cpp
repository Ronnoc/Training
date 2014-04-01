#include<stdio.h>
#include<math.h>
int main()
{
	int x,z;
	scanf("%d",&z);
	for(x=1;x<=z;x++)
	{
		double d,v,u;
		scanf("%lf%lf%lf",&d,&v,&u); 
		printf("Case %d: ",x);
		double tax,tin;
		tin=d/u;
		if(u>v)
		{
			double vv=sqrt(u*u-v*v);
			tax=d/vv;
			if(tax>tin)printf("%.3lf\n",tax-tin);
			else printf("can't determine\n");
	 		}
	 	else printf("can't determine\n");
		}
	return 0;
	}
